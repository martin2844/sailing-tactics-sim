#!/usr/bin/env python3
"""Capture original constructor and real CFile/CArchive round trips in private hosts."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path
from capture_native import EDITION, ROOT, EXPECTED, DATA_BASE, DATA_BYTES, digest, patch


def build(compiler):
    sys.path.insert(0,str(ROOT/'tools'))
    from verify_native_reference import compile_runner
    directory=EDITION/'analysis/application-runners'
    directory.mkdir(exist_ok=True)
    for name in ['native_reference.c','native_controller_trace.h','native_controller_table.h','native_gdi_trace.h','native_application_trace.h']:
        (directory/name).write_bytes((EDITION/'tools'/name).read_bytes())
    source=directory/'native_reference.c'
    text=source.read_text().replace('#include "native_controller_trace.h"','#include "native_controller_trace.h"\n#include "native_application_trace.h"')
    text=text.replace('else if (command==2) run_controller_case();','else if (command==2) run_controller_case();\n    else if (command==3) run_application_case();')
    text=text.replace('if (argc!=2)','if (argc!=3)').replace('load_and_hash(argv[1]);','if (!SetCurrentDirectoryA(argv[2])) fail("private application directory unavailable");\n  load_and_hash(argv[1]);')
    source.write_text(text)
    runner=directory/'application-reference-2010.exe'
    compile_runner(compiler,runner,source)
    return runner


def differences(before,after):
    rows=[];offset=0
    while offset<len(before):
        if before[offset]==after[offset]:offset+=1;continue
        start=offset
        while offset<len(before) and before[offset]!=after[offset]:offset+=1
        rows.append({'address':DATA_BASE+start,'before':before[start:offset].hex(),'after':after[start:offset].hex()})
    return rows


def state_record(raw,offset,state):
    if offset+36>len(raw):raise ValueError('Truncated state record')
    expected_hash=raw[offset:offset+32].hex();count=struct.unpack_from('<I',raw,offset+32)[0];offset+=36
    rows=[]
    for _ in range(count):
        if offset+8>len(raw):raise ValueError('Truncated native delta')
        address,width=struct.unpack_from('<II',raw,offset);offset+=8
        if not DATA_BASE<=address<DATA_BASE+DATA_BYTES or not width or width>DATA_BASE+DATA_BYTES-address or offset+width*2>len(raw):raise ValueError('Delta outside original mutable data')
        old,new=raw[offset:offset+width],raw[offset+width:offset+2*width];offset+=2*width;target=address-DATA_BASE
        if state[target:target+width]!=old:raise ValueError('Native before-image differs')
        state[target:target+width]=new;rows.append({'address':address,'before':old.hex(),'after':new.hex()})
    if hashlib.sha256(state).hexdigest()!=expected_hash:raise ValueError('Entire original mutable image hash differs')
    return {'mutableSha256':expected_hash,'imageChanges':rows},offset


def decode(output,case):
    if output[:8]!=b'TACT2010' or len(output)<36+DATA_BYTES:raise ValueError('Missing native handshake')
    if struct.unpack_from('<7I',output,8)!=(1,0x400000,0x21c000,0x027f,358,DATA_BASE,DATA_BYTES):raise ValueError('Native edition layout differs')
    baseline=output[36:36+DATA_BYTES];offset=36+DATA_BYTES
    command,width=struct.unpack_from('<2I',output,offset);offset+=8
    if command!=3 or offset+width+12!=len(output):raise ValueError('Constructor envelope differs')
    raw=output[offset:offset+width]
    seed,rng,cw,size=struct.unpack_from('<4I',raw)
    if seed!=case['timeSeed'] or cw!=0x027f or size!=DATA_BYTES:raise ValueError('Original constructor seed or precision differs')
    prepared=raw[16:16+size];cursor=16+size;state=bytearray(prepared)
    constructor,cursor=state_record(raw,cursor,state);saved,cursor=state_record(raw,cursor,state)
    archive=raw[cursor:cursor+636];cursor+=636;event_count=struct.unpack_from('<I',raw,cursor)[0];cursor+=4;events=[]
    for _ in range(event_count):
        kind,a,b,c,d,e=struct.unpack_from('<6I',raw,cursor);cursor+=24
        if kind==1:events.append({'type':'openArchive','name':'p.tac','access':a,'share':b,'disposition':c,'attributes':d})
        elif kind==2:events.append({'type':'systemMetrics','index':a,'value':b})
        elif kind==3:events.append({'type':'createPen','style':a if a<0x80000000 else a-0x100000000,'width':b if b<0x80000000 else b-0x100000000,'color':c,'nativeHandle':d,'handleAddress':e})
        elif kind==4:events.append({'type':'createBrush','color':a,'nativeHandle':b,'handleAddress':e})
        else:raise ValueError('Unrecognized original host request')
    if sum(e['type'].startswith('create') for e in events)!=90:raise ValueError('Expected all90 original GDI object requests')
    raw_state=bytearray(prepared);runtime_before,cursor=state_record(raw,cursor,raw_state)
    runtime_constructor,cursor=state_record(raw,cursor,raw_state);runtime_save,cursor=state_record(raw,cursor,raw_state)
    if cursor!=len(raw) or output[offset+width:]!=struct.pack('<3I',0,4,1):raise ValueError('Original final text integrity is missing')
    return baseline,{'preparedSha256':hashlib.sha256(prepared).hexdigest(),'preparedChanges':differences(baseline,prepared),
        'constructor':{**constructor,'rngState':rng},'save':saved,'savedArchive':archive.hex(),'events':events,
        'rawRuntime':{'prepared':runtime_before,'constructor':runtime_constructor,'save':runtime_save}}


def capture(manifest,runner,prefix):
    original=EDITION/'runtime/Tactics2010EnglishPreserved.exe'
    if digest(original)!=EXPECTED or manifest['sourceSha256']!=EXPECTED:raise ValueError('Exact original source differs')
    environment=dict(os.environ,WINEPREFIX=str(prefix),WINEDEBUG='-all',WINEARCH='win64')
    baseline=None;cases=[]
    for index,case in enumerate(manifest['cases']):
        archive=bytes.fromhex(case['preferences']) if case['preferences'] is not None else b''
        if len(archive) not in (0,636):raise ValueError('Original archive must be absent or exactly636 bytes')
        patches=[patch(row['address'],bytes.fromhex(row['bytes'])) for row in case['patches']]
        request=struct.pack('<4I',3,case['timeSeed'],case['screenHeight'],len(archive))+archive+struct.pack('<I',len(patches))+b''.join(patches)+struct.pack('<I',0)
        with tempfile.TemporaryDirectory(prefix='tact-2010-archive-') as directory:
            win='Z:'+directory.replace('/','\\')
            completed=subprocess.run([str(ROOT/'tools/wine-runtime/bin/wine'),str(runner),str(original),win],input=request,
                stdout=subprocess.PIPE,stderr=subprocess.PIPE,env=environment,timeout=90)
        if completed.returncode:raise RuntimeError(f'Application case{index} {case["label"]}: '+completed.stderr.decode(errors='replace'))
        try:base,expected=decode(completed.stdout,case)
        except Exception as error:raise ValueError(f'Application case{index} {case["label"]}: {error}') from error
        if baseline is None:baseline=base
        elif baseline!=base:raise ValueError('Fresh original data+trig baseline differs across cases')
        cases.append({**case,'expected':expected})
        print(f'Captured {index+1}/{len(manifest["cases"])}: {case["label"]}',flush=True)
    if digest(original)!=EXPECTED:raise ValueError('Preserved original file changed')
    source_hashes={name:digest(runner.parent/name) for name in ['native_reference.c','native_application_trace.h','native_controller_trace.h','native_controller_table.h','native_gdi_trace.h']}
    return {**manifest,'mutableBlock':{'address':DATA_BASE,'size':DATA_BYTES},'mutableBaseline':baseline.hex(),'cases':cases,
        'provenance':{'sha256':EXPECTED,'engine':'Original x86 code under Wine; actual original CFile/CArchive, RNG/trig and GDI attachment instructions',
        'x87ControlWord':'0x027f','loadedOriginalTextUnchanged':True,'originalFileUnchanged':True,'runnerSha256':digest(runner),'runnerSources':source_hashes,
        'hostBindings':'Private actual p.tac file; owned CDocument and real MFC TLS slot/module objects; actual Windows GDI handles recorded separately and normalized only at their unique original handle slots. UTC OS clock and screen-height inputs are explicit. CRT heap/lock bookkeeping normalized by declared ranges with complete raw pre/post evidence.',
        'normalizationRanges':[[0x4ee000,4],[0x4ee160,0x80],[0x4ee220,0x2024],[0x538720,0x60],[0x53992c,4],[0x53878c,4]],
        'limitations':'Finite prepared data/archives and explicit UTC/screen-height domains. This executes complete constructor and destructor routines; original WinMain, normal document/window lifecycle and Windows GDI rasterization are outside this isolated host proof.'}}


def main():
    sys.path.insert(0,str(ROOT/'tools'))
    from verify_native_reference import DEFAULT_GCC
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--compiler',default=os.environ.get('TACT_MINGW_CC',DEFAULT_GCC))
    parser.add_argument('--runner',type=Path)
    parser.add_argument('--report-only',action='store_true',help='Rebuild metadata from an already complete captured fixture')
    parser.add_argument('--prefix',type=Path,default=Path.home()/'.local/share/posey-simulator-2010-en/wineprefix')
    args=parser.parse_args();args.output=args.output.resolve()
    if args.report_only:
        fixture=json.loads(args.output.read_text())
        if digest(EDITION/'runtime/Tactics2010EnglishPreserved.exe')!=EXPECTED or fixture['provenance']['sha256']!=EXPECTED or not fixture['provenance']['loadedOriginalTextUnchanged']:
            raise ValueError('Existing original-code authority is invalid')
    else:
        runner=args.runner or build(args.compiler)
        fixture=capture(json.loads(args.manifest.read_text()),runner,args.prefix)
        args.output.parent.mkdir(exist_ok=True,parents=True);args.output.write_text(json.dumps(fixture,indent=2,allow_nan=False)+'\n')
    report={'format':1,'sourceSha256':EXPECTED,'originalFileUnchanged':True,'loadedOriginalTextUnchanged':True,
      'constructorCalls':len(fixture['cases']),'archiveSaveCalls':len(fixture['cases']),'nativeGdiObjectRequests':90*len(fixture['cases']),
      'fixture':{'path':args.output.relative_to(EDITION).as_posix(),'bytes':args.output.stat().st_size,'sha256':digest(args.output)},
      'scope':fixture['scope'],'limitations':fixture['provenance']['limitations']}
    (EDITION/'analysis/application-native-reference-comparison.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({key:report[key] for key in ['constructorCalls','archiveSaveCalls','nativeGdiObjectRequests']}))


if __name__=='__main__':main()
