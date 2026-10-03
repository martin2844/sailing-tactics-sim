#!/usr/bin/env python3
"""Capture fixed command2 controller cases from the unchanged native 2010 code."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
import struct
import subprocess
from pathlib import Path
from capture_native import EDITION, ROOT, EXPECTED, DATA_BASE, DATA_BYTES, digest, patch

def patches(manifest,case):
    return manifest['profiles'][case['profile']]['patches']+case.get('patches',[])

def encode(manifest,case):
    kind=case['kind'];arguments=case.get('arguments',[])
    arities={1:3,2:0,3:0,4:3,5:3,6:3,7:4,8:0,9:0,10:0}
    if kind not in arities or len(arguments)!=arities[kind]:raise ValueError('Unsupported controller signature')
    rows=[patch(row['address'],bytes.fromhex(row['bytes'])) for row in patches(manifest,case)]
    if len(rows)>1024:raise ValueError('Too many controller input patches')
    flags=(0 if case.get('continue') else 1)|(2 if 'seed' in case else 0)
    words=struct.pack('<'+'I'*len(arguments),*(int(value)&0xffffffff for value in arguments))
    return struct.pack('<6I',2,kind,case['identifier'],flags,case.get('seed',1),len(arguments))+words+struct.pack('<I',len(rows))+b''.join(rows)

def decode(raw,manifest,case,state,baseline):
    if len(raw)<108:raise ValueError('Truncated original controller response')
    kind,eax,edx,rng=struct.unpack_from('<4I',raw)
    if kind!=case['kind'] or struct.unpack_from('<H',raw,34)[0]!=0x027f:raise ValueError('Controller identity or precision differs')
    if not case.get('continue'):state[:]=baseline
    for row in patches(manifest,case):
        offset=row['address']-DATA_BASE;data=bytes.fromhex(row['bytes']);state[offset:offset+len(data)]=data
    offset=72;changes=[]
    for _ in range(struct.unpack_from('<I',raw,68)[0]):
        if offset+8>len(raw):raise ValueError('Truncated controller delta')
        address,width=struct.unpack_from('<II',raw,offset);offset+=8
        if not DATA_BASE<=address<DATA_BASE+DATA_BYTES or width>DATA_BASE+DATA_BYTES-address or offset+2*width>len(raw):raise ValueError('Controller delta outside exact data')
        before,after=raw[offset:offset+width],raw[offset+width:offset+width*2];offset+=width*2
        target=address-DATA_BASE
        if state[target:target+width]!=before:raise ValueError('Controller before-state differs')
        state[target:target+width]=after;changes.append({'address':address,'before':before.hex(),'after':after.hex()})
    if hashlib.sha256(state).digest()!=raw[36:68]:raise ValueError('Controller complete-state hash differs')
    event_bytes=struct.unpack_from('<I',raw,offset)[0];offset+=4;end=offset+event_bytes;events=[]
    if end+32!=len(raw):raise ValueError('Controller evidence extent differs')
    while offset<end:
        op,width=struct.unpack_from('<II',raw,offset);offset+=8
        if offset+width>end or width%4:raise ValueError('Invalid controller callback extent')
        values=struct.unpack_from('<'+'I'*(width//4),raw,offset);offset+=width
        signed=lambda value:value if value<0x80000000 else value-0x100000000
        if op==1 and width==28:
            rect=None if not values[1] else dict(zip(('left','top','right','bottom'),map(signed,values[2:6])))
            events.append({'type':'invalidateRect','windowHandle':values[0],'rectangle':rect,'erase':signed(values[6])})
        elif op==2 and width==16:events.append({'type':'default','message':values[0],'wparam':values[1],'lparam':values[2],'result':values[3]})
        elif op in (3,4) and width==4:events.append({'type':'enable' if op==3 else 'check','value':signed(values[0])})
        else:raise ValueError('Unknown controller callback')
    bindings=[]
    for index in range(2):
        address,original,bound,retained=struct.unpack_from('<4I',raw,end+index*16)
        if address not in (0x538010,0x538148) or retained!=bound:raise ValueError('Original controller changed host MFC binding')
        if struct.unpack_from('<I',state,address-DATA_BASE)[0]!=original:raise ValueError('MFC binding restoration differs')
        bindings.append({'address':address,'original':original,'bound':bound,'retained':retained})
    return {'eax':eax,'edx':edx,'rngState':rng,'mutableSha256':raw[36:68].hex(),'imageChanges':changes,'events':events,'runtimeBindings':bindings}

def capture(manifest,runner,prefix):
    original=EDITION/'runtime/Tactics2010EnglishPreserved.exe'
    if manifest['sourceSha256']!=EXPECTED or digest(original)!=EXPECTED:raise ValueError('Original source SHA differs')
    source_directory=runner.parent if (runner.parent/'native_reference.c').exists() else EDITION/'tools'
    source_hashes={key:digest(source_directory/file) for key,file in (
      ('runnerSourceSha256','native_reference.c'),('controllerSourceSha256','native_controller_trace.h'),('controllerTableSha256','native_controller_table.h'))}
    environment=os.environ.copy();environment.update(WINEDEBUG='-all',WINEPREFIX=str(prefix))
    requests=b''.join(encode(manifest,case) for case in manifest['cases'])+struct.pack('<I',0)
    completed=subprocess.run([str(ROOT/'tools/wine-runtime/bin/wine'),str(runner),str(original)],input=requests,
                             stdout=subprocess.PIPE,stderr=subprocess.PIPE,env=environment,timeout=300)
    if completed.returncode:raise RuntimeError(f'Original controller runner failed {completed.returncode}: '+completed.stderr.decode(errors='replace'))
    output=completed.stdout
    if output[:8]!=b'TACT2010' or len(output)<36+DATA_BYTES:raise ValueError('Missing original runner handshake')
    if struct.unpack_from('<7I',output,8)!=(1,0x400000,0x21c000,0x027f,358,DATA_BASE,DATA_BYTES):raise ValueError('Native original layout differs')
    baseline=output[36:36+DATA_BYTES];state=bytearray(baseline);offset=36+DATA_BYTES;cases=[]
    for index,case in enumerate(manifest['cases']):
        command,length=struct.unpack_from('<2I',output,offset);offset+=8
        if command!=2 or length>DATA_BYTES*6+65536 or offset+length>len(output):raise ValueError('Invalid native controller envelope')
        try:expected=decode(output[offset:offset+length],manifest,case,state,baseline)
        except Exception as error:raise ValueError(f'Controller case{index} {case["label"]}: {error}') from error
        offset+=length;cases.append({**case,'expected':expected})
    if output[offset:]!=struct.pack('<3I',0,4,1) or digest(original)!=EXPECTED:raise ValueError('Original final file/text integrity missing')
    snapshots_only=all(case['kind'] in (9,10) for case in cases)
    return {**manifest,'mutableBlock':{'address':DATA_BASE,'size':DATA_BYTES},'mutableBaseline':baseline.hex(),'cases':cases,
      'provenance':{'engine':'Original x86 code under Wine; no text edits','sha256':EXPECTED,'x87ControlWord':'0x027f',
       **source_hashes,'runnerSha256':digest(runner),
       'loadedOriginalTextUnchanged':True,'originalFileUnchanged':True,'mutableBaselineSha256':hashlib.sha256(baseline).hexdigest(),
       'hostBindings':('Snapshots have no OS/MFC callbacks. Unused temporary538010/538148 framework bindings are restored before complete state SHA and retained as raw evidence.' if snapshots_only else 'Owned CTACTView/CCmdUI vtables and real MFC TLS slot; original 4ac701/4c04f2 execute. Temporary538010/538148 restored before complete state SHA and retained as raw evidence.'),
       'limitations':('Finite fleet counts up to30; nonpositive signed edges, opaque word patterns and retained save/restore calls.' if snapshots_only else 'Finite synthetic data profiles. Actual modal-window entry/lifetime handlers4901d0/4911c0 are excluded.')}}

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--runner',type=Path,default=EDITION/'analysis/native-runners/native-reference-2010.exe')
    parser.add_argument('--prefix',type=Path,default=Path.home()/'.local/share/posey-simulator/wineprefix')
    args=parser.parse_args();result=capture(json.loads(args.manifest.read_text()),args.runner,args.prefix)
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(result,indent=2,allow_nan=False)+'\n')
    print(f'Captured {len(result["cases"])} strict original controller calls; entire mutable image, RNG and ordered callbacks retained')

if __name__=='__main__':main()
