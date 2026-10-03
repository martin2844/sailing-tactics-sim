#!/usr/bin/env python3
"""Hardware precision-control evidence independent of the JavaScript model."""
import hashlib,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def main():
    source=ROOT/'tools/capture_precision_native.c';binary=ROOT/'tools/native-precision-probe'
    subprocess.run(['/home/martin/.nix-profile/bin/gcc','-O0',str(source),'-o',str(binary)],check=True)
    previous=json.loads((ROOT/'tests/fixtures/original-x87.json').read_text())
    rows=[{'controlWord':word,'operation':row['operation'],'leftBits':row['leftBits'],'rightBits':row.get('rightBits','00000000000000000000')}
        for word in [0x007f,0x027f,0x037f] for row in previous['arithmetic']]
    request=''.join('%x %s %s %s\n'%(row['controlWord'],row['operation'],row['leftBits'],row['rightBits']) for row in rows)
    response=subprocess.run([str(binary)],input=request,text=True,capture_output=True,check=True).stdout.splitlines()
    if len(response)!=len(rows):raise AssertionError('Hardware probe record count differs')
    finite=[];nonfinite=[]
    for row,line in zip(rows,response):
        extended,stored=line.split();row['expected']={'extendedBits':extended,'storedDoubleBits':stored}
        (nonfinite if int.from_bytes(bytes.fromhex(extended)[8:10],'little')&0x7fff==0x7fff else finite).append(row)
    output={'provenance':{'engine':'native-x87','rounding':'nearest/even','probeSource':'tools/capture_precision_native.c',
        'probeSha256':hashlib.sha256(source.read_bytes()).hexdigest(),'scope':'Explicit24/53/64-bit precision control; currenthardwareinstructions. Finite results compared; masked nonfinite results retained separately.'},'cases':finite,'nonfiniteCases':nonfinite}
    (ROOT/'tests/fixtures/native-precision.json').write_text(json.dumps(output,indent=2)+'\n')
    print('Native precision',len(finite),'finite',len(nonfinite),'nonfinite')
if __name__=='__main__':main()
