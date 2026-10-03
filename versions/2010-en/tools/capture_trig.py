#!/usr/bin/env python3
"""Capture the 2010 degree construction on native x87 at observed CW027f."""
import hashlib
import importlib.util
import json
import os
import platform
import subprocess
import tempfile
from pathlib import Path

EDITION=Path(__file__).resolve().parents[1]
ROOT=EDITION.parents[1]
EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'

def main():
    original=EDITION/'runtime/Tactics2010EnglishPreserved.exe'
    raw=original.read_bytes()
    if hashlib.sha256(raw).hexdigest()!=EXPECTED:raise ValueError('Original 2010 edition differs')
    specification=importlib.util.spec_from_file_location('stored_trig_helper',ROOT/'tools/capture_stored_trig.py')
    helper=importlib.util.module_from_spec(specification);specification.loader.exec_module(helper)
    factor=helper.original_constant(raw,0x4cc568)
    if factor!='3152cb9156df913f':raise ValueError('Original 2010 degree factor differs')
    source=ROOT/'tools/capture_pc53_native.c'
    angles=list(range(-1080,1081));raw_angles=list(range(-128,129))
    commands=[f'{mode} {angle} {factor} 000000000000f03f' for mode in ('extended','stored') for angle in angles]
    commands += [f'raw {angle} {factor} 000000000000f03f' for angle in raw_angles]
    compiler=os.environ.get('CC',str(Path.home()/'.nix-profile/bin/gcc'))
    with tempfile.TemporaryDirectory(prefix='tact-2010-trig-') as directory:
        executable=Path(directory)/'capture'
        subprocess.run([compiler,'-std=c11','-O2','-Wall','-Wextra','-Werror','-fno-fast-math',str(source),'-o',str(executable)],check=True)
        runs=[subprocess.run([str(executable)],input='\n'.join(commands)+'\n',text=True,capture_output=True,check=True).stdout for _ in range(2)]
    if runs[0]!=runs[1]:raise ValueError('Native x87 captures are not repeatable')
    rows=runs[0].splitlines()
    if len(rows)!=len(commands):raise ValueError('Native x87 capture is incomplete')
    provenance={'sha256':EXPECTED,'authoritative_engine':'native-x87','control_word':'0x027f',
                'architecture':platform.machine(),'probe_source':'tools/capture_pc53_native.c',
                'probe_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
                'compiler':subprocess.run([compiler,'--version'],text=True,capture_output=True,check=True).stdout.splitlines()[0],
                'note':'Exact original constant and opcode construction on current hardware; no historical CPU equivalence claim.'}
    cursor=0
    for mode,name,domain in [('extended','x87-trig.json',angles),('stored','x87-stored-trig.json',angles),('raw','x87-raw-trig.json',raw_angles)]:
        pairs={}
        for index,angle in enumerate(domain):
            sine,cosine=rows[cursor+index].split();pairs[str(angle)]={'sineBits':sine,'cosineBits':cosine}
        cursor+=len(domain)
        document={'provenance':provenance,'degreeFactorAddress':0x4cc568,'degreeFactorBits':factor,
                  'construction':mode,'angles':pairs}
        (EDITION/'assets/data'/name).write_text(json.dumps(document,indent=2)+'\n')
    if hashlib.sha256(original.read_bytes()).hexdigest()!=EXPECTED:raise ValueError('Original changed during capture')
    print(json.dumps({'extendedAngles':len(angles),'storedAngles':len(angles),'rawAngles':len(raw_angles),'repeatable':True}))

if __name__=='__main__':main()
