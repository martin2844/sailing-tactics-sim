#!/usr/bin/env python3
"""Capture separate startup precision53 assets; preserve precision64 evidence.

The original fixed-hash 415a60 and417790 instructions supply the integer lookup
tables and boat calibration. A standalone explicit-opcode host probe supplies
the finite unrounded trigonometric domains. No original code/file is patched.
"""
from pathlib import Path
import hashlib
import json
import os
import platform
import struct
import subprocess
import tempfile
from capture_stored_trig import ROOT, EXPECTED, original_constant
from verify_native_reference import compile_runner, DEFAULT_GCC

TARGET=ROOT/'assets/data/pc53'

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(name,value):
    (TARGET/name).write_text(json.dumps(value,indent=2,allow_nan=False)+'\n')
def main():
    original=(ROOT/'original/Tact02Demo.exe').read_bytes()
    if hashlib.sha256(original).hexdigest()!=EXPECTED:raise ValueError('Original changed')
    names=['trig-tables.json','x87-trig.json','x87-stored-trig.json','x87-force-trig.json','x87-hull-trig.json','x87-raw-trig.json','boat-calibration.json']
    preserved={name:sha(ROOT/'assets/data'/name) for name in names}
    TARGET.mkdir(exist_ok=True)
    source=ROOT/'tools/capture_pc53_native.c'
    factor,scale,one,kind=[original_constant(original,a) for a in [0x484d40,0x484dc0,0x484e10,0x484e40]]
    angles=list(range(-1080,1081));hull_angles=[29,58,87,116,145];raw_angles=list(range(-128,129))
    commands=[f'{mode} {angle} {factor} {one}' for mode in ['extended','stored'] for angle in angles]
    commands += [f'scaled {angle} {factor} {value}' for value in [one,scale] for angle in hull_angles]
    commands += [f'raw {angle} {factor} {one}' for angle in raw_angles]
    commands += [f'force {lever} {force} {flag} {boat} {factor} {scale} {kind}'
        for lever in range(101) for force in range(181) for flag in range(2) for boat in range(2)]
    compiler=os.environ.get('CC','gcc')
    with tempfile.TemporaryDirectory(prefix='tact-pc53-trig-') as folder:
        executable=Path(folder)/'capture'
        subprocess.run([compiler,'-std=c11','-O2','-Wall','-Wextra','-Werror','-fno-fast-math',str(source),'-o',str(executable)],check=True)
        payload='\n'.join(commands)+'\n'
        outputs=[subprocess.run([str(executable)],input=payload,text=True,capture_output=True,check=True).stdout for _ in range(2)]
        if outputs[0]!=outputs[1]:raise ValueError('Non-repeatable actual x87 output')
    rows=outputs[0].splitlines()
    if len(rows)!=len(commands):raise ValueError('Incomplete native trig capture')
    cpu={}
    for line in Path('/proc/cpuinfo').read_text().splitlines():
        if ':' in line:
            key,value=map(str.strip,line.split(':',1))
            if key in ['vendor_id','model name','cpu family','model','stepping','microcode'] and key not in cpu:cpu[key]=value
    provenance={'sha256':EXPECTED,'authoritative_engine':'native-x87','engine':'native-x87',
        'control_word':'0x027f','x87_control_word':'0x027f','architecture':platform.machine(),'cpu':cpu,
        'probe_source':'tools/capture_pc53_native.c','probe_sha256':sha(source),
        'compiler':subprocess.run([compiler,'--version'],text=True,capture_output=True,check=True).stdout.splitlines()[0],
        'note':'Separate current-hardware reference for actual startup precision53. Precision64 reference files remain unchanged. No historical CPU equivalence claim.'}
    cursor=0
    def pair(line):
        sine,cosine=line.split();return {'sineBits':sine,'cosineBits':cosine,'referenceEngine':'native-x87'}
    common={'provenance':provenance,'degreeFactorAddress':0x484d40,'degreeFactorBits':factor}
    for mode in ['extended','stored']:
        document={**common,'inputOrdering':f'FILD i32; FMUL original binary64 degree factor in precision53; '+('FSTP/FLD binary64; ' if mode=='stored' else '')+'FSIN/FCOS; FSTP m80',
            'angles':{str(angle):pair(rows[cursor+index]) for index,angle in enumerate(angles)}}
        cursor+=len(angles);save('x87-trig.json' if mode=='extended' else 'x87-stored-trig.json',document)
    hull={**common,'optimistScaleAddress':0x484dc0,'optimistScaleBits':scale,'optimistScale':struct.unpack('<d',bytes.fromhex(scale))[0],
        'construction':'FILD i32; FMUL original binary64 hull scale; FMUL original binary64 degree factor, precision53; FSIN/FCOS; FSTP m80',
        'variants':{name:{str(angle):pair(rows[cursor+variant*5+index]) for index,angle in enumerate(hull_angles)} for variant,name in enumerate(['standard','optimist'])}}
    cursor+=10;save('x87-hull-trig.json',hull)
    save('x87-raw-trig.json',{'provenance':provenance,'construction':'FILD i32; FSIN/FCOS; FSTP m80, CW027f, without degree factor',
        'angles':{str(angle):pair(rows[cursor+index]) for index,angle in enumerate(raw_angles)}})
    cursor+=len(raw_angles);radians={}
    for line in rows[cursor:]:
        bits,sine=line.split()
        if bits in radians and radians[bits]['sineBits']!=sine:raise ValueError('Conflicting native force result')
        radians[bits]={'sineBits':sine}
    save('x87-force-trig.json',{**common,'sportOffsetAddress':0x484dc0,'sportOffsetBits':scale,'classOffsetAddress':0x484e40,'classOffsetBits':kind,
        'construction':'FILD lever; optional FSUB sportOffset/classOffset; FILD force; FADDP; FMUL degreeFactor, precision53; FSIN',
        'domains':{'lever':[0,100],'force':[0,180],'sportFlag':[0,1],'class2or6':[0,1]},'capturedCalls':len(rows)-cursor,'radians':radians})
    runner=ROOT/'analysis/native-runners/pc53-assets.exe';runner.parent.mkdir(exist_ok=True)
    flags=compile_runner(DEFAULT_GCC,runner,ROOT/'tools/native_reference_pc53.c')
    lengths=list(range(1,101));stream=bytearray(struct.pack('<I',17))
    for length in lengths:
        # Selector0/class11 retains supplied positive length; no override.
        stream+=struct.pack('<I10i',3,0,0,10,10,80,11,length,0,1,0)
    stream+=struct.pack('<I',0)
    env={**os.environ,'WINEPREFIX':'/home/martin/.local/share/posey-simulator/wineprefix','WINEDEBUG':'-all'}
    run=subprocess.run([str(ROOT/'tools/wine-runtime/bin/wine'),str(runner),'Z:\\home\\martin\\tact\\original\\Tact02Demo.exe'],input=stream,capture_output=True,env=env,check=True,timeout=120)
    (ROOT/'analysis/pc53-assets-wine.log').write_bytes(run.stderr)
    output=run.stdout
    if output[:8]!=b'TACT2002':raise ValueError('Missing native hello')
    version,base,tls,imports,cw,mapping=struct.unpack('<6I',output[8:32])
    if (version,base,cw,mapping)!=(2,0x400000,0x027f,1):raise ValueError('Wrong original precision/mapping')
    offset=32
    def response(command,width):
        nonlocal offset
        actual,length=struct.unpack_from('<II',output,offset);offset+=8
        if (actual,length)!=(command,width):raise ValueError('Unexpected native response')
        payload=output[offset:offset+length];offset+=length
        if len(payload)!=length:raise ValueError('Truncated native result')
        return payload
    table=struct.unpack('<724i',response(17,362*8))
    original_provenance={**provenance,'probe_source':'tools/native_reference_pc53.c','probe_sha256':sha(ROOT/'tools/native_reference_pc53.c'),
        'original_runner_source_sha256':sha(ROOT/'tools/native_reference_2002.c'),'runner_sha256':sha(runner),'runner_path':str(runner.relative_to(ROOT)),
        'compiler':DEFAULT_GCC,'compiler_flags':flags,'original_text_unchanged':True,
        'mapping':'Fixed SHA-checked preserved image in owned host PE section at original0x400000; actual original instructions, IAT/TLS runtime glue, no original entrypoint.'}
    save('trig-tables.json',{'provenance':original_provenance,'generator':'0x415a60','sine_address':'0x4a54a0','cosine_address':'0x4a3450','sine':list(table[:362]),'cosine':list(table[362:])})
    calibration={}
    for length in lengths:
        data=response(3,68)
        if struct.unpack_from('<i',data,4)[0]!=length:raise ValueError('Original boat routine did not retain requested length')
        bits=data[56:64].hex();calibration[str(length)]={'value':struct.unpack('<d',data[56:64])[0],'bits':bits,'referenceEngine':'native-x87'}
    if struct.unpack('<I',response(0,4))[0]!=1 or offset!=len(output):raise ValueError('Native final unchanged-text proof missing')
    save('boat-calibration.json',{'provenance':original_provenance,'routine':'0x417790','formula':'Original integer length1..100 retained by selector0/class11; original sqrt(15/length) binary64 store underCW027f','lengths':calibration})
    if {name:sha(ROOT/'assets/data'/name) for name in names}!=preserved:raise ValueError('Existing precision64 assets were changed')
    report={'source_sha256':EXPECTED,'x87_control_word':'0x027f','startup_observation':'analysis/startup-precision-live.jsonl',
        'preserved_precision64_asset_sha256':preserved,'precision53_asset_sha256':{name:sha(TARGET/name) for name in names},
        'counts':{'extendedAngles':len(angles),'storedAngles':len(angles),'hullAngles':10,'rawAngles':len(raw_angles),'forceCalls':len(rows)-cursor,'forceDistinctRadians':len(radians),'originalIntegerTablePairs':362,'originalBoatCalibrations':len(lengths)},
        'standalone_probe_repeatable':True,'original_file_unchanged':sha(ROOT/'original/Tact02Demo.exe')==EXPECTED,'native_original_text_unchanged':True,
        'native_initialization':{'protocol_version':version,'base':hex(base),'tlsIndex':tls,'imports':imports,'control_word':hex(cw)}}
    (ROOT/'analysis/pc53-assets-reference.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report['counts']),flush=True)
if __name__=='__main__':main()
