#!/usr/bin/env python3
"""Actual x87 force-trigonometry, preserving the original offset/spill order."""
import hashlib
import json
import subprocess
import tempfile
from pathlib import Path
from capture_stored_trig import ROOT, EXPECTED, original_constant

def main():
    original=(ROOT/'original/Tact02Demo.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=EXPECTED: raise ValueError('Original changed')
    source=ROOT/'tools/capture_force_trig_native.c'
    factor,sport,kind=[original_constant(original,address) for address in [0x484d40,0x484dc0,0x484e40]]
    # Slightly broader than observed normal lever5..87/force0..100 domains.
    commands=[f'{lever} {force} {flag} {boat} {factor} {sport} {kind}'
              for lever in range(0,101) for force in range(0,181)
              for flag in range(2) for boat in range(2)]
    with tempfile.TemporaryDirectory(prefix='tact-force-trig-') as folder:
        binary=str(Path(folder)/'capture')
        subprocess.run(['gcc','-std=c11','-O2','-Wall','-Wextra','-fno-fast-math',str(source),'-o',binary],check=True)
        run=subprocess.run([binary],input='\n'.join(commands)+'\n',text=True,capture_output=True,check=True)
    lines=run.stdout.splitlines()
    if len(lines)!=len(commands): raise ValueError('Incomplete native capture')
    radians={}
    for line in lines:
        input_bits,sine_bits=line.split()
        if input_bits in radians and radians[input_bits]['sineBits']!=sine_bits: raise ValueError('Non-repeatable hardware output')
        radians[input_bits]={'sineBits':sine_bits}
    output={'provenance':{'sha256':EXPECTED,'authoritative_engine':'native-x87','control_word':'0x037f',
        'probe_source':'tools/capture_force_trig_native.c','probe_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'note':'Local hardware reference; no historical CPU equivalence claim.'},
        'degreeFactorAddress':0x484d40,'degreeFactorBits':factor,
        'sportOffsetAddress':0x484dc0,'sportOffsetBits':sport,
        'classOffsetAddress':0x484e40,'classOffsetBits':kind,
        'construction':'FILD lever; optionally FSUB sportOffset; optionally FSUB classOffset; FILD force; FADDP; FMUL degreeFactor; FSIN',
        'domains':{'lever':[0,100],'force':[0,180],'sportFlag':[0,1],'class2or6':[0,1]},
        'capturedCalls':len(lines),'radians':radians}
    (ROOT/'assets/data/x87-force-trig.json').write_text(json.dumps(output,indent=2)+'\n')
    print(json.dumps({'calls':len(lines),'distinctRadians':len(radians)}))

if __name__=='__main__': main()
