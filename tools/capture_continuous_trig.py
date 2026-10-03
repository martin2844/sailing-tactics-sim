#!/usr/bin/env python3
"""Independent hardware evidence for mathematical continuous-render sin/cos."""
import hashlib
import json
import math
import random
import subprocess
import tempfile
from pathlib import Path
from capture_atan import ROOT, extended

def main():
    source=ROOT/'tools/capture_continuous_trig_native.c'
    prng=random.Random(0x411000)
    values=[0.0,-0.0,1e-150,-1e-150,math.pi,-math.pi,math.pi/2,-math.pi/2]
    values += [index/100 for index in range(-628,629)]
    values += [prng.uniform(-math.tau,math.tau) for _ in range(1024)]
    inputs=[extended(value) for value in values]
    with tempfile.TemporaryDirectory(prefix='tact-continuous-trig-') as folder:
        binary=str(Path(folder)/'capture')
        subprocess.run(['gcc','-std=c11','-O2','-Wall','-Wextra',str(source),'-o',binary],check=True)
        lines=subprocess.run([binary],input='\n'.join(inputs)+'\n',capture_output=True,text=True,check=True).stdout.splitlines()
    if len(lines)!=len(inputs):raise ValueError('Incomplete capture')
    cases=[]
    for bits,line in zip(inputs,lines):
        sine,cosine,sine_double,cosine_double=line.split()
        cases.append({'inputBits':bits,'expected':{'sineBits':sine,'cosineBits':cosine,
            'sineDoubleBits':sine_double,'cosineDoubleBits':cosine_double}})
    data={'provenance':{'engine':'native-x87','control_word':'0x037f',
        'probe_source':'tools/capture_continuous_trig_native.c','probe_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'note':'Actual FSIN/FCOS for finite continuous radian inputs. Mathematical sin/cos does not reproduce vendor polynomial error; this is not universal instruction parity.'},'cases':cases}
    (ROOT/'tests/fixtures/native-continuous-trig.json').write_text(json.dumps(data,indent=2)+'\n')
    print(f'Captured {len(cases)} continuous native sine/cosine pairs')
if __name__=='__main__':main()
