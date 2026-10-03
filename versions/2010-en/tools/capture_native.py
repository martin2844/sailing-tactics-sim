#!/usr/bin/env python3
"""Capture finite cases from the fixed 2010 English original-code oracle."""
from __future__ import annotations
import argparse
import hashlib
import importlib.util
import json
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

EDITION = Path(__file__).resolve().parents[1]
ROOT = EDITION.parents[1]
EXPECTED = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
DATA_BASE, DATA_BYTES = 0x4da000, 0x60588
ROUTINES = {0x420c00:1, 0x41bc20:2, 0x41bc40:3, 0x41e000:4, 0x464940:5,
            0x41e040:6, 0x4413e0:7, 0x49b7b0:8, 0x49b7a0:9,
            0x427540:10, 0x427e30:11, 0x427ee0:12,
            0x413bc0:13, 0x428b70:14, 0x4298f0:15, 0x406590:16,
            0x427f10:17, 0x416910:18, 0x426ab0:19, 0x427090:20,
            0x441400:21, 0x42b0b0:22, 0x445860:23}
ROUTINES[0x446250]=24
ROUTINES[0x446a70]=25
ROUTINES[0x4471e0]=26
ROUTINES[0x4479f0]=27
ROUTINES[0x448100]=28
ROUTINES[0x448970]=29
ROUTINES[0x4495e0]=30
ROUTINES[0x4676f0]=31
ROUTINES[0x4711b0]=32
ROUTINES[0x471f40]=33
ROUTINES[0x4729d0]=34
ROUTINES[0x4732c0]=35
ROUTINES[0x473ed0]=36
ROUTINES[0x4756c0]=37
ROUTINES[0x474b60]=38
ROUTINES[0x476db0]=39
ROUTINES[0x4762a0]=40
ROUTINES[0x479e00]=41
ROUTINES[0x479120]=42
ROUTINES[0x477b00]=43
ROUTINES[0x47c240]=44
ROUTINES[0x47aa70]=45
ROUTINES[0x47b5d0]=46
ROUTINES[0x478760]=47
ROUTINES[0x42da80]=48
ROUTINES[0x42d280]=49
ROUTINES[0x464a30]=50
ROUTINES[0x48b8a0]=51
ROUTINES[0x42c060]=52
ROUTINES[0x43e160]=53
ROUTINES[0x43df50]=54
ROUTINES[0x43e510]=55
ROUTINES[0x439e80]=56
ROUTINES[0x431960]=57
ROUTINES[0x444760]=58
ROUTINES[0x465e10]=59
ROUTINES[0x42f220]=60
ROUTINES[0x42f270]=61
ROUTINES[0x42f330]=62
ROUTINES[0x42f480]=63
ROUTINES[0x47d5f0]=64
ROUTINES[0x47def0]=65
ROUTINES[0x47dfa0]=66
ROUTINES[0x437570]=67
ROUTINES[0x4662d0]=68
ROUTINES[0x466230]=69
ROUTINES[0x465ff0]=70
ROUTINES[0x43cf60]=71
ROUTINES[0x406680]=72
ROUTINES[0x406e40]=73
ROUTINES[0x41f3e0]=74
ROUTINES[0x463c90]=75
ROUTINES[0x463df0]=76
ROUTINES[0x43f9f0]=77
ROUTINES[0x43fa60]=78
ROUTINES[0x488b90]=79
ROUTINES[0x431200]=80
ROUTINES[0x42fca0]=81
ROUTINES[0x40f240]=82
ROUTINES[0x412d30]=83
ROUTINES[0x430260]=84
ROUTINES[0x42dea0]=85
ROUTINES[0x42f530]=86
ROUTINES[0x42b2e0]=87
ROUTINES[0x41be70]=88
ROUTINES[0x43bb70]=89
ROUTINES[0x41e3a0]=90
ROUTINES[0x435f90]=91
ROUTINES[0x437520]=92
ROUTINES[0x437d40]=93
ROUTINES[0x439ec0]=94
ROUTINES[0x43ec20]=95
ROUTINES[0x464050]=96
ROUTINES[0x43c980]=97
ROUTINES[0x43ca40]=98
ROUTINES[0x43ccf0]=99
ROUTINES[0x43c440]=100
ROUTINES[0x43c1e0]=101
ROUTINES[0x43be00]=102
ROUTINES[0x43c140]=103
ROUTINES[0x43c2c0]=104
ROUTINES[0x434f70]=105
ROUTINES[0x435fe0]=106
ROUTINES[0x436400]=107
ROUTINES[0x436ba0]=108
ROUTINES[0x437e60]=109
ROUTINES[0x439100]=110
ROUTINES[0x4391f0]=111
ROUTINES[0x439a30]=112
ROUTINES[0x439df0]=113
ROUTINES[0x488d70]=114
ROUTINES[0x43a030]=115
ROUTINES[0x417aa0]=116
ROUTINES[0x405320]=117
ROUTINES[0x407ff0]=118
ROUTINES[0x449ee0]=119
ROUTINES[0x44a5d0]=120
ROUTINES[0x44b0e0]=121
ROUTINES[0x44b930]=122
ROUTINES[0x44c0f0]=123
ROUTINES[0x44c750]=124
ROUTINES[0x44d0c0]=125
ROUTINES[0x44d690]=126
ROUTINES[0x44e240]=127
ROUTINES[0x44eb90]=128
ROUTINES[0x44f5c0]=129
ROUTINES[0x44fee0]=130
ROUTINES[0x450590]=131
ROUTINES[0x450970]=132
ROUTINES[0x451e60]=133
ROUTINES[0x452660]=134
ROUTINES[0x453230]=135
ROUTINES[0x4545d0]=136
ROUTINES[0x4559c0]=137
ROUTINES[0x457280]=138
ROUTINES[0x458ca0]=139
ROUTINES[0x45a150]=140
ROUTINES[0x45bd90]=141
ROUTINES[0x45c440]=142
ROUTINES[0x45cad0]=143
ROUTINES[0x45cff0]=144
ROUTINES[0x45df40]=145
ROUTINES[0x460470]=146
ROUTINES[0x4617a0]=147
ROUTINES[0x461f60]=148
ROUTINES[0x4626a0]=149
ROUTINES[0x462ed0]=150
ROUTINES[0x4636c0]=151
ROUTINES[0x4282b0]=152
ROUTINES[0x4049f0]=153
ROUTINES[0x4432b0]=154
ROUTINES[0x41bfb0]=155
SOUND_ROUTINES={0x43e160,0x43df50,0x43e510,0x437570,0x43cf60,0x42f530,0x42b2e0,0x41be70}
SOUND_ROUTINES.update({0x43c980,0x43ca40,0x43ccf0,0x43c440,0x43c1e0,0x43be00,0x43c140,0x43c2c0})
CSTRING_ROUTINES={0x42b2e0,0x41be70,0x43cf60}
GDI_ROUTINES = {0x413bc0,0x428b70,0x4298f0,0x406590,0x427f10,0x416910,0x445860,0x446250,0x446a70,0x4471e0,0x4479f0,0x448100,0x448970,0x4495e0}
GDI_ROUTINES.update({0x406680,0x406e40,0x41f3e0,0x463c90,0x463df0})
GDI_ROUTINES.update({0x40f240,0x412d30})

SOUND_ROUTINES.update({0x434f70,0x435fe0,0x436400,0x436ba0,0x437e60,0x439100,0x4391f0,0x439a30,0x439df0,0x488d70,0x43a030,0x417aa0,0x405320,0x407ff0,0x449ee0,0x44a5d0,0x44b0e0,0x44b930,0x44c0f0,0x44c750,0x44d0c0,0x44d690,0x44e240,0x44eb90,0x44f5c0,0x44fee0,0x450590,0x450970,0x451e60,0x452660,0x453230,0x4545d0,0x4559c0,0x457280,0x458ca0,0x45a150,0x45bd90,0x45c440,0x45cad0,0x45cff0,0x45df40,0x460470,0x4617a0,0x461f60,0x4626a0,0x462ed0,0x4636c0,0x4282b0})
GDI_ROUTINES.update({0x417aa0,0x405320,0x407ff0,0x449ee0,0x44a5d0,0x44b0e0,0x44b930,0x44c0f0,0x44c750,0x44d0c0,0x44d690,0x44e240,0x44eb90,0x44f5c0,0x44fee0,0x450590,0x450970,0x451e60,0x452660,0x453230,0x4545d0,0x4559c0,0x457280,0x458ca0,0x45a150,0x45bd90,0x45c440,0x45cad0,0x45cff0,0x45df40,0x460470,0x4617a0,0x461f60,0x4626a0,0x462ed0,0x4636c0,0x4282b0})
GDI_ROUTINES.add(0x4049f0)
SOUND_ROUTINES.add(0x4049f0)
SOUND_ROUTINES.add(0x4432b0)

def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def patch(address: int, raw: bytes) -> bytes:
    if not DATA_BASE <= address < DATA_BASE + DATA_BYTES or not raw or len(raw)>DATA_BASE+DATA_BYTES-address:
        raise ValueError('Patch outside exact mutable data')
    if address < 0x4ee004 and address + len(raw) > 0x4ee000:
        raise ValueError('Patch overlaps host TLS binding')
    return struct.pack('<II', address, len(raw)) + raw

def encode_case(manifest: dict, case: dict) -> bytes:
    manifest={**manifest,'routine':case.get('routine',manifest['routine'])}
    routine = ROUTINES[manifest['routine']['address']]
    arguments = case.get('arguments', [])
    words = bytearray()
    for kind, value in zip(manifest['routine'].get('argumentTypes', []), arguments, strict=True):
        if kind == 'CDC':
            if value not in (0, None):raise ValueError('CDC is supplied only by the owned host')
            words += struct.pack('<I',0)
        elif kind in ('I32', 'U32'):
            words += struct.pack('<I', int(value) & 0xffffffff)
        elif kind == 'F64':
            words += bytes.fromhex(value) if isinstance(value,str) else struct.pack('<d', value)
        else:
            raise ValueError('Unsupported explicit argument type '+kind)
    encoded = []
    for field, value in case.get('inputs', {}).items():
        encoded.append(patch(manifest['integerInputs'][field],struct.pack('<I',int(value)&0xffffffff)))
    for field, value in case.get('doubleInputs', {}).items():
        encoded.append(patch(manifest['doubleInputs'][field],struct.pack('<d',value)))
    for row in case.get('patches', []):
        encoded.append(patch(row['address'],bytes.fromhex(row['bytes'])))
    if len(encoded)>4096 or len(words)>64:
        raise ValueError('Case exceeds original host bounds')
    flags=(0 if case.get('continue',False) else 1) | (2 if 'seed' in case or not case.get('continue',False) else 0)
    strings=case.get('strings',[])
    command=3 if strings else 1
    request = (struct.pack('<5I',command,routine,flags,
                        case.get('seed',1),len(words)//4) + words +
            struct.pack('<I',len(encoded)) + b''.join(encoded))
    if manifest['routine']['address'] in GDI_ROUTINES:
        host=case.get('host',{});cursor=host.get('cursor',[0,0]);pixels=host.get('pixels',[])
        request += struct.pack('<5iI',host.get('menuHeight',20),*cursor,host.get('tickStart',0),1,len(pixels))
        request += struct.pack('<'+'I'*len(pixels),*pixels)
    if strings:
        if manifest['routine']['address'] not in GDI_ROUTINES|CSTRING_ROUTINES:
            raise ValueError('Routine has no semantic CString contract')
        addresses={0x4fdfd4,*range(0x4fec30,0x4fec30+35*4,4)}
        seen=set();encoded_strings=[]
        for row in strings:
            address=row['address'];raw=bytes.fromhex(row['bytes'])
            if address not in addresses or address in seen or len(raw)>4095 or b'\0' in raw:
                raise ValueError('Semantic CString input exceeds fixed cell/text contract')
            seen.add(address)
            encoded_strings.append(struct.pack('<II',address,len(raw))+raw)
        request += struct.pack('<I',len(encoded_strings))+b''.join(encoded_strings)
    return request

def decode_case(raw: bytes, manifest: dict, case: dict, state: bytearray, baseline: bytes) -> dict:
    manifest={**manifest,'routine':case.get('routine',manifest['routine'])}
    if len(raw)<72:
        raise ValueError('Truncated native case')
    routine,eax,edx,rng=struct.unpack_from('<4I',raw)
    if routine!=ROUTINES[manifest['routine']['address']]:
        raise ValueError('Fixed routine response differs')
    if not case.get('continue',False):
        state[:]=baseline
    for field,value in case.get('inputs',{}).items():
        struct.pack_into('<I',state,manifest['integerInputs'][field]-DATA_BASE,int(value)&0xffffffff)
    for field,value in case.get('doubleInputs',{}).items():
        struct.pack_into('<d',state,manifest['doubleInputs'][field]-DATA_BASE,value)
    for row in case.get('patches',[]):
        offset=row['address']-DATA_BASE;data=bytes.fromhex(row['bytes']);state[offset:offset+len(data)]=data
    control=struct.unpack_from('<H',raw,34)[0]
    if control!=0x027f:
        raise ValueError('Original routine changed observed precision')
    count=struct.unpack_from('<I',raw,68)[0];offset=72;changes=[]
    for _ in range(count):
        if offset+8>len(raw):raise ValueError('Truncated native delta')
        address,width=struct.unpack_from('<II',raw,offset);offset+=8
        if not DATA_BASE<=address<DATA_BASE+DATA_BYTES or width>DATA_BASE+DATA_BYTES-address or offset+2*width>len(raw):
            raise ValueError('Native delta outside mutable scope')
        before,after=raw[offset:offset+width],raw[offset+width:offset+2*width];offset+=2*width
        target=address-DATA_BASE
        if state[target:target+width]!=before:raise ValueError('Native delta baseline differs')
        state[target:target+width]=after
        changes.append({'address':address,'before':before.hex(),'after':after.hex()})
    drawing = manifest['routine']['address'] in GDI_ROUTINES
    strings_active=drawing or manifest['routine']['address'] in CSTRING_ROUTINES
    sound=drawing or manifest['routine']['address'] in SOUND_ROUTINES
    if hashlib.sha256(state).digest()!=raw[36:68]:
        raise ValueError('Native entire mutable state integrity differs')
    result={'eax':eax,'edx':edx,'rngState':rng,'mutableSha256':raw[36:68].hex(),'imageChanges':changes}
    if drawing:
        from native_events import decode_gdi_events
        if offset+4>len(raw):raise ValueError('Missing native drawing evidence')
        width=struct.unpack_from('<I',raw,offset)[0];offset+=4
        if width>2097152 or width>len(raw)-offset:raise ValueError('Drawing evidence outside bounds')
        result['drawingCommands']=decode_gdi_events(raw[offset:offset+width]);offset+=width
    if strings_active:
        if offset+4>len(raw):raise ValueError('Missing raw native runtime evidence')
        count=struct.unpack_from('<I',raw,offset)[0];offset+=4;runtime=[]
        ranges=[(0x4ee160,0x80),(0x4ee220,0x2024),(0x538720,0x60),(0x53992c,4),(0x53878c,4)]
        for _ in range(count):
            if offset+8>len(raw):raise ValueError('Truncated native runtime evidence')
            address,width=struct.unpack_from('<II',raw,offset);offset+=8
            if not any(start<=address and address+width<=start+extent for start,extent in ranges) or offset+2*width>len(raw):
                raise ValueError('Native runtime evidence exceeds normalized scope')
            runtime.append({'address':address,'before':raw[offset:offset+width].hex(),
                            'after':raw[offset+width:offset+2*width].hex()});offset+=2*width
        result['nativeRuntimeChanges']=runtime
        if offset+4>len(raw):raise ValueError('Missing original global CString evidence')
        count=struct.unpack_from('<I',raw,offset)[0];offset+=4;strings=[]
        if count!=36:raise ValueError('Original global CString count differs')
        for index in range(count):
            if offset+12>len(raw):raise ValueError('Truncated original global CString evidence')
            address,pointer,width=struct.unpack_from('<3I',raw,offset);offset+=12
            expected_address=0x4fdfd4 if index==0 else 0x4fec30+(index-1)*4
            if address!=expected_address or not pointer or width>4096 or width>len(raw)-offset:
                raise ValueError('Original global CString evidence outside contract')
            strings.append({'address':address,'nativePointer':pointer,'bytes':raw[offset:offset+width].hex()});offset+=width
        result['globalStrings']=strings
    if drawing:
        if offset+4>len(raw):raise ValueError('Missing native ABI call observations')
        count=struct.unpack_from('<I',raw,offset)[0];offset+=4
        if count>4096 or count*12>len(raw)-offset:raise ValueError('Native ABI observations exceed bounds')
        calls=[]
        for _ in range(count):
            address,service,pop=struct.unpack_from('<3I',raw,offset);offset+=12
            if not 0x401000<=address<0x4c7316:raise ValueError('Observed ABI call is outside original code')
            calls.append({'returnAddress':address,'service':service,'stackArgumentBytes':pop})
        result['callObservations']=calls
    if sound:
        if offset+4>len(raw):raise ValueError('Missing ordered sound evidence')
        count=struct.unpack_from('<I',raw,offset)[0];offset+=4
        if count>256 or count*12>len(raw)-offset:raise ValueError('Sound evidence exceeds fixed bounds')
        result['sounds']=[]
        for _ in range(count):
            resource,module,flags=struct.unpack_from('<3I',raw,offset);offset+=12
            if resource>65535:raise ValueError('Sound resource exceeds fixed ID bounds')
            result['sounds'].append({'resourceId':resource,'moduleHandle':module,'flags':flags})
    if offset!=len(raw):raise ValueError('Trailing native response bytes')
    if manifest['routine']['returnType'] in ('F64','float10'):
        result['returnBits']=raw[16:24].hex();result['returnExtendedBits']=raw[24:34].hex()
    result['integers']={field:struct.unpack_from('<i',state,address-DATA_BASE)[0]
                        for field,address in manifest.get('integerOutputs',{}).items()}
    result['doubles']={field:state[address-DATA_BASE:address-DATA_BASE+8].hex()
                       for field,address in manifest.get('doubleOutputs',{}).items()}
    return result

def capture(manifest: dict, *, compiler: str|None=None, wine: str|None=None, prefix: str|None=None) -> dict:
    original=EDITION/'runtime/Tactics2010EnglishPreserved.exe'
    if str(EDITION/'tools') not in sys.path:sys.path.insert(0,str(EDITION/'tools'))
    if manifest['sourceSha256']!=EXPECTED or digest(original)!=EXPECTED:
        raise ValueError('Original edition SHA256 differs')
    specification=importlib.util.spec_from_file_location('tact2002_build_helper',ROOT/'tools/verify_native_reference.py')
    helper=importlib.util.module_from_spec(specification);specification.loader.exec_module(helper)
    directory=EDITION/'analysis/native-runners';directory.mkdir(parents=True,exist_ok=True)
    # A capture owns its compiler inputs and executable, even when other agents
    # extend the canonical closed table or run independent capture batches.
    owned=Path(tempfile.mkdtemp(prefix='capture-',dir=directory))
    source_files=['native_reference.c','native_gdi_trace.h','native_controller_trace.h','native_controller_table.h']
    source_records=[]
    for name in source_files:
        raw=(EDITION/'tools'/name).read_bytes()
        (owned/name).write_bytes(raw)
        source_records.append({'path':f'versions/2010-en/tools/{name}','sha256':hashlib.sha256(raw).hexdigest()})
    executable=owned/'native-reference-2010.exe';source=owned/'native_reference.c'
    try:
        flags=helper.compile_runner(compiler or helper.DEFAULT_GCC,executable,source)
    except subprocess.CalledProcessError as error:
        raise RuntimeError(error.stderr) from error
    wine=wine or str(ROOT/'tools/wine-runtime/bin/wine')
    environment=os.environ.copy();environment['WINEDEBUG']=os.environ.get('TACT_REFERENCE_WINEDEBUG','-all')
    environment['WINEPREFIX']=prefix or os.environ.get('TACT_REFERENCE_WINEPREFIX') or str(Path.home()/'.local/share/posey-simulator-2010-en/wineprefix')
    requests=b''.join(encode_case(manifest,case) for case in manifest['cases'])+struct.pack('<I',0)
    completed=subprocess.run([wine,str(executable),str(original)],input=requests,stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE,env=environment,timeout=300)
    if completed.returncode:
        (owned/'failed-output.bin').write_bytes(completed.stdout)
        (owned/'failed-stderr.log').write_bytes(completed.stderr)
        raise RuntimeError(f'Original oracle exited {completed.returncode}; evidence at {owned}: '+completed.stderr.decode(errors='replace'))
    output=completed.stdout
    if output[:8]!=b'TACT2010' or len(output)<36+DATA_BYTES:
        raise ValueError('Original oracle handshake missing')
    hello=struct.unpack_from('<7I',output,8)
    if hello!=(1,0x400000,0x21c000,0x027f,358,DATA_BASE,DATA_BYTES):
        raise ValueError('Original oracle edition/layout differs')
    baseline=output[36:36+DATA_BYTES];state=bytearray(baseline);offset=36+DATA_BYTES;cases=[]
    for case in manifest['cases']:
        if offset+8>len(output):raise ValueError('Missing native response')
        command,length=struct.unpack_from('<2I',output,offset);offset+=8
        if command!=(3 if case.get('strings') else 1) or length>DATA_BYTES*6+2097152+65536 or offset+length>len(output):
            raise ValueError('Invalid native response extent')
        expected=decode_case(output[offset:offset+length],manifest,case,state,baseline);offset+=length
        cases.append({**case,'expected':expected})
    if output[offset:]!=struct.pack('<3I',0,4,1) or digest(original)!=EXPECTED:
        raise ValueError('Final original-code/file integrity check missing')
    provenance={'engine':'Original x86 code under Wine; no text edits',
             'sha256':EXPECTED,'x87ControlWord':'0x027f','runnerSourceSha256':digest(source),
             'runnerSourceFiles':source_records,
             'runnerSha256':digest(executable),'compilerFlags':flags,
             'loadedOriginalTextUnchanged':True,'originalFileUnchanged':True,
             'mutableBaselineSha256':hashlib.sha256(baseline).hexdigest()}
    (owned/'provenance.json').write_text(json.dumps(provenance,indent=2)+'\n')
    return {**manifest,'mutableBlock':{'address':DATA_BASE,'size':DATA_BYTES},
            'provenance':provenance,
            'mutableBaseline':baseline.hex(),'cases':cases}

def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest',type=Path);parser.add_argument('output',type=Path)
    parser.add_argument('--compiler');parser.add_argument('--wine');parser.add_argument('--prefix')
    args=parser.parse_args();manifest=json.loads(args.manifest.read_text())
    result=capture(manifest,compiler=args.compiler,wine=args.wine,prefix=args.prefix)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2,allow_nan=False)+'\n')
    print(f"Captured {len(result['cases'])} original {manifest['routine']['name']} cases; exact mutable hashes verified")

if __name__=='__main__':
    main()
