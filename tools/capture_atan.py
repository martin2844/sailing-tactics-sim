#!/usr/bin/env python3
"""Independent actual FPATAN reference; no emulation or C libm in expected outputs."""
import hashlib
import json
import math
import random
import struct
import subprocess
import tempfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def extended(value):
    raw=struct.unpack('<Q',struct.pack('<d',value))[0]
    sign=(raw>>63)<<15
    power=(raw>>52)&0x7ff
    fraction=raw&((1<<52)-1)
    if power: mantissa=((1<<52)|fraction)<<11; exponent=power-1023+16383
    elif fraction:
        leading=fraction.bit_length()-1
        mantissa=fraction<<(63-leading);exponent=leading-1074+16383
    else:mantissa=0;exponent=0
    return struct.pack('<QH',mantissa,exponent|sign).hex()

def main():
    source=ROOT/'tools/capture_atan_native.c'
    prng=random.Random(0x42c400)
    values=[0.0,-0.0,1.0,-1.0,2.0,-2.0,1e-150,-1e-150,1e150,-1e150,math.nextafter(1,2),math.nextafter(1,0)]
    pairs=[(y,x) for y in values for x in values]
    pairs += [(math.ldexp(prng.uniform(-1,1),prng.randrange(-500,501)),math.ldexp(prng.uniform(-1,1),prng.randrange(-500,501))) for _ in range(1024)]
    pairs += [(float(prng.randrange(-2147483648,2147483648)),float(prng.randrange(-2147483648,2147483648))) for _ in range(512)]
    commands=[f'{extended(y)} {extended(x)}' for y,x in pairs]
    with tempfile.TemporaryDirectory(prefix='tact-atan-') as folder:
        binary=str(Path(folder)/'capture')
        subprocess.run(['gcc','-std=c11','-O2','-Wall','-Wextra',str(source),'-o',binary],check=True)
        output=subprocess.run([binary],input='\n'.join(commands)+'\n',capture_output=True,text=True,check=True).stdout.splitlines()
    if len(output)!=len(pairs):raise ValueError('Incomplete capture')
    cases=[]
    for pair,command,line in zip(pairs,commands,output):
        y,x=command.split();result,stored=line.split()
        cases.append({'yBits':y,'xBits':x,'expected':{'extendedBits':result,'storedDoubleBits':stored}})
    data={'provenance':{'engine':'native-x87','control_word':'0x037f',
        'probe_source':'tools/capture_atan_native.c','probe_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'note':'Actual local hardware FPATAN output. A mathematical atan model is an approximation to the vendor instruction; assess m80 and binary64 differences independently.'},'cases':cases}
    (ROOT/'tests/fixtures/native-atan.json').write_text(json.dumps(data,indent=2)+'\n')
    print(f'Captured {len(cases)} native FPATAN pairs')

if __name__=='__main__':main()
