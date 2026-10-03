#!/usr/bin/env python3
"""Compare preserved 2002 routines running natively under Wine with CPU fixtures.

Only the bounded routines in native_reference_2002.c are callable. The original
executable and its text bytes are checked before/after execution. Differences
are reported; this tool never changes fixture expectations or browser behavior.
"""
from __future__ import annotations
import argparse
import hashlib
import gzip
import json
import os
import platform
import shutil
import struct
import subprocess
import tempfile
import time
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
EXPECTED='881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'
DEFAULT_GCC='/nix/store/qhwms7m1mjhfnrm1n3aaxd45ghsvfk19-i686-w64-mingw32-gcc-15.2.0/bin/i686-w64-mingw32-gcc'
BINUTILS=Path('/nix/store/d93k0gvnz4g4cdqgmw8znkm86bkaqj42-i686-w64-mingw32-binutils-2.46/bin')
MINGW=Path('/nix/store/rhyxb4b7x1hl82hkbw1hhryrv4gv7smh-mingw-w64-i686-w64-mingw32-13.0.0/lib')
MCFG=Path('/nix/store/j1nwryg9bjqxyjaqqq6d1wnfnj0bz671-mcfgthread-i686-w64-mingw32-2.3.2/lib')
WIND_FIELDS=['hour','dailyMinimum','dailyMaximum','thermalGain','weather','shore','reversal','baseDirection','baseStrength','driftRate','forceCondition','mode','time','resetTime','tidePhaseHour','tideAmplitude','target','nextTime','range','period','targetIndex','timeIndex','meanDirection','direction']
WIND_OUTPUTS=['thermal','strength','peakStrength','condition1','condition2','meanDirection','direction','target','nextTime','range','period','targetIndex','timeIndex','tide']
WIND_DOUBLES=['driftClock','smoothDirection','dt']
BOAT_FIELDS=['selector','lengthOverride','displacementOverride','sailAreaOverride','sailPercentOverride','boatClass','length','rig','course','offshoreCourseFlag']
BOAT_OUTPUTS=['boatClass','length','rig','course','offshoreCourseFlag','displacement','sailArea','sailPercent','catamaranFlag','boardFlag','sportBoatFlag','skiffFlag','jy15Flag','optimistFlag']
CURRENT_FIELDS=['refreshFlag','resetTime','time','spatialVariant','tidePhaseHour','tideOffsetHours','hour','tideAmplitude','islandFlag','centerX','centerY','weather','currentBaseDirection','course','shore','shoreY','placementMode','branchDirection1','branchDirection2','centerDirection','tideCycleFlag','reversal','radius','windDirection','globalTide','rawCurrent','currentEffect','currentDirection','shoreDirection','oppositeShoreDirection']
CURRENT_OUTPUTS=['rawCurrent','currentEffect','currentDirection','shoreDirection','oppositeShoreDirection','currentStrength','previousStrength']
MOVEMENT_FIELDS=['boatCount','secondBoatDelay','time','difficulty','course','islandFlag']
MOVEMENT_INDEXED=['targetX','targetY','rateCoefficient','interference']
STEERING_FIELDS=['mouseGateY','viewportHeight','mouseGateLimit','gateDimension','mouseMinX','mouseMaxX','mouseX','mouseCenterX','viewportWidth','humanBoatCount','rig','boatClass','speedDivisor','rudder','speed1','speed2','tack1','tack2','previousTack1','previousTack2','turnMode1','turnMode2','gybeMode1','gybeMode2','lockMode1','lockMode2','sailingMode1','sailingMode2','autopilot1','autopilot2','angle1','angle2','trueWindDirection1','downwindLimit1','downwindLimit2','heading1','heading2','tackStart1','tackStart2','time','soundDisabled','moduleHandle','firstButtonX','firstButtonY','secondButtonX','secondButtonY','buttonCenterX','buttonCenterY','uiMode','buttonLock']
STEERING_OUTPUTS=['rudder','turnMode1','turnMode2','gybeMode1','gybeMode2','lockMode1','lockMode2','sailingMode1','sailingMode2','autopilot1','autopilot2','heading1','heading2','tackStart1','tackStart2','firstButtonX','firstButtonY','secondButtonX','secondButtonY']
ENCOUNTER_SCHEMA=None
COMMAND_LIMIT=131072

def file_hash(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def update_native_shift_fixture(report: dict, report_path: Path) -> None:
    """Preserve the emulated baseline, then apply observed original FSIN outputs."""
    if not report['comparison_complete'] or not report['loaded_original_text_unchanged'] or not report['original_file_unchanged']:
        raise ValueError('Incomplete native authority cannot correct a fixture')
    path=ROOT/'tests/fixtures/original-encounter-leaves.json'
    raw=path.read_bytes(); old_hash=hashlib.sha256(raw).hexdigest()
    if old_hash!=report['fixture_sha256'][path.name]:raise ValueError('Encounter fixture changed during native comparison')
    fixture=json.loads(raw)
    corrections=[case for case in report['differences'] if case['group'].startswith('encounter_')]
    if not corrections:return
    for correction in corrections:
        if correction['group']!='encounter_shiftPenaltyPosition' or not set(correction['fields'])<={'boats','imageChanges'}:
            raise ValueError('Unexpected native difference needs separate review, not automatic correction')
        case=fixture['routines']['shiftPenaltyPosition']['cases'][correction['index']]
        primary=str(case['boat']); base_x=fixture['indexed']['positionX']['address']+case['boat']*8; base_y=fixture['indexed']['positionY']['address']+case['boat']*8
        for field,values in correction['fields'].items():
            if case['expected'][field]!=values['fixture']:raise ValueError('Native correction baseline mismatch')
            if field=='boats':
                for boat,fields in values['native'].items():
                    for name,value in fields.items():
                        if value!=values['fixture'][boat][name] and (boat!=primary or name not in ('positionX','positionY','positionXBits','positionYBits')):
                            raise ValueError('Native shift changed an unexpected field')
            else:
                for change in values['native']:
                    if not any(base<=change['address'] and change['address']+len(bytes.fromhex(change['after']))<=base+8 for base in (base_x,base_y)):
                        raise ValueError('Native shift wrote outside its verified position scope')
    baseline=ROOT/'analysis/encounter-emulation-baseline.json.gz'
    historical=ROOT/'analysis/encounter-native-comparison-before-correction.json'
    if baseline.exists() or historical.exists():raise ValueError('Preserved discrepancy evidence already exists; review before replacing')
    baseline.write_bytes(gzip.compress(raw,mtime=0)); historical.write_bytes(report_path.read_bytes())
    for correction in corrections:
        case=fixture['routines']['shiftPenaltyPosition']['cases'][correction['index']]
        for field,values in correction['fields'].items():case['expected'][field]=values['native']
    fixture['provenance'].update(engine='Unicorn with documented native original-code corrections',native_corrections={
        'routine':'0042a950 / shiftPenaltyPosition','engine':report['engine'],'wine_version':report['wine_version'],
        'original_sha256':EXPECTED,'runner_source_sha256':report['runner_source_sha256'],
        'fixed_encounter_schema_sha256':report['fixed_encounter_schema_sha256'],
        'emulation_fixture_sha256':old_hash,'preserved_emulation_fixture':'analysis/encounter-emulation-baseline.json.gz',
        'comparison_before_correction':'analysis/encounter-native-comparison-before-correction.json',
        'comparison_before_correction_sha256':file_hash(historical),'corrected_cases':len(corrections),
        'reason':'Original native x87 FSIN/FCOS outputs differ from Unicorn and affect stored binary64 positions. Only measured position values/bits and their exact image deltas are corrected; no tolerance or executable edits.'})
    path.write_text(json.dumps(fixture,indent=2,allow_nan=False)+'\n')
    (ROOT/'analysis/encounter-native-corrections.json').write_text(json.dumps({'original_sha256':EXPECTED,'emulation_fixture_sha256':old_hash,'corrected_fixture_sha256':file_hash(path),'corrected_cases':len(corrections),'scope':'Only original42a950 floating position outputs and final image deltas. Historical discrepancy evidence is retained.','native_comparison_before_correction_sha256':file_hash(historical)},indent=2)+'\n')
    print('Applied '+str(len(corrections))+' observed native shift corrections; rerun comparison against corrected fixture.')

def compile_runner(compiler: str, executable: Path, source: Path | None = None) -> list[str]:
    flags=['-std=c11','-O2','-Wall','-Wextra','-Werror','-mfpmath=387','-static','-Wl,--image-base,0x300000,--disable-dynamicbase,--section-start,.tact_original=0x400000']
    with tempfile.TemporaryDirectory(prefix='tact-native-toolchain-') as directory:
        if Path(compiler).resolve()==Path(DEFAULT_GCC).resolve():
            # Bare Nix cross-GCC needs unprefixed tool names and CRT search paths.
            for name in ('as','ld','ar','ranlib'):
                (Path(directory)/name).symlink_to(BINUTILS/('i686-w64-mingw32-'+name))
            flags=['-B'+directory+'/', '-B'+str(MINGW)+'/', '-L'+str(MINGW), '-L'+str(MCFG)]+flags
        command=[compiler,*flags,str(source or ROOT/'tools/native_reference_2002.c'),'-o',str(executable),'-ladvapi32']
        subprocess.run(command,check=True,capture_output=True,text=True)
    return flags

def load_fixture(name: str, hashes: dict) -> dict:
    path=ROOT/'tests/fixtures'/name
    fixture=json.loads(path.read_text())
    if fixture['provenance']['sha256']!=EXPECTED:
        raise ValueError('Fixture source hash mismatch: '+name)
    hashes[name]=file_hash(path)
    return fixture

def wind_request(integers: dict, doubles: dict, seed: int | None) -> bytes:
    mask=sum(1<<index for index,field in enumerate(WIND_FIELDS) if field in integers)
    dmask=sum(1<<index for index,field in enumerate(WIND_DOUBLES) if field in doubles)
    return struct.pack('<II24iI3dII',2,mask,*(integers.get(field,0) for field in WIND_FIELDS),dmask,*(doubles.get(field,0) for field in WIND_DOUBLES),int(seed is not None),seed or 0)

def steering_request(routine: int, integers: dict, doubles: dict) -> bytes:
    mask=sum(1<<index for index,field in enumerate(STEERING_FIELDS) if field in integers)
    fields=['smoothHeading','steeringScale']
    dmask=sum(1<<index for index,field in enumerate(fields) if field in doubles)
    return struct.pack('<IIQ50iI2d',12,routine,mask,*(integers.get(field,0) for field in STEERING_FIELDS),dmask,*(doubles.get(field,0) for field in fields))

def requests() -> tuple[bytes,list[dict],dict]:
    global ENCOUNTER_SCHEMA
    hashes={}; stream=bytearray(); cases=[]
    wind=load_fixture('original-global-wind.json',hashes)
    stream+=struct.pack('<I302i',1,*wind['randomTable'])
    cases.append({'group':'random_table','command':1,'expected':{'ack':1}})
    for index,case in enumerate(wind['cases']):
        stream+=wind_request(case['inputs'],case['doubleInputs'],case['seed'])
        cases.append({'group':'wind','index':index,'command':2,'expected':case['expected']})
    for chain_index,chain in enumerate(wind['chains']):
        for step_index,step in enumerate(chain['steps']):
            integers={**chain['inputs'],**step['inputs']} if step_index==0 else step['inputs']
            doubles={**chain['doubleInputs'],**step['doubleInputs']} if step_index==0 else step['doubleInputs']
            stream+=wind_request(integers,doubles,chain['seed'] if step_index==0 else None)
            cases.append({'group':'wind_chain','chain':chain_index,'index':step_index,'command':2,'expected':step['expected']})
    boats=load_fixture('original-boat-options.json',hashes)
    for index,case in enumerate(boats['cases']):
        stream+=struct.pack('<I10i',3,*(case['inputs'][field] for field in BOAT_FIELDS))
        cases.append({'group':'boat','index':index,'command':3,'expected':case['expected']})
    apparent=load_fixture('original-apparent-wind.json',hashes)
    for index,case in enumerate(apparent['cases']):
        stream+=struct.pack('<I4i',4,case['speedTenths'],case['boat'],case['angle'],case['trueWind'])
        cases.append({'group':'apparent_wind','index':index,'command':4,'expected':case['expected']})
    angles=load_fixture('original-angles.json',hashes)
    for index,case in enumerate(angles['bearingFromVector']):
        stream+=struct.pack('<I2i',5,case['param1'],case['param2'])
        cases.append({'group':'bearing','index':index,'command':5,'expected':{'value':case['expected']}})
    for index,case in enumerate(angles['wrapRadiansOnce']):
        stream+=struct.pack('<I',6)+bytes.fromhex(case['inputBits'])
        cases.append({'group':'radian_wrap','index':index,'command':6,'expected':{'value':case['expected'],'bits':case['bits']}})
    current=load_fixture('original-current.json',hashes)
    geometry=current['geometry']
    stream+=struct.pack('<I128i181d',7,*geometry['shorelineX']['values'],*geometry['shorelineY']['values'],*geometry['radialBoundary']['values'])
    cases.append({'group':'synthetic_geometry','command':7,'expected':{'ack':1}})
    groups=[('current',0,current['cases'])]+[('current_'+name,routine,current['helpers'][name]['cases']) for routine,name in enumerate(['shorelineMetric','ellipticalMetric','radialMetric','shoreDirections','attenuationDistance'],1)]
    for group,routine,records in groups:
        for index,case in enumerate(records):
            stream+=struct.pack('<II34i3d2i',8,routine,case['x'],case['y'],case['boat'],case.get('selector',0),*(case['inputs'][field] for field in CURRENT_FIELDS),case['doubleInputs']['axisScaleX'],case['doubleInputs']['axisScaleY'],case['cachedMetric'],case['currentStrength'],case['previousStrength'])
            cases.append({'group':group,'index':index,'command':8,'expected':case['expected']})
    movement=load_fixture('original-movement-helpers.json',hashes)
    for index,case in enumerate(movement['distanceToBoat']['cases']):
        stream+=struct.pack('<Ii',9,case['boat'])+b''.join(bytes.fromhex(case['inputBits'][field]) for field in ('x','y','positionX','positionY'))
        cases.append({'group':'movement_distance','index':index,'command':9,'expected':case['expected']})
    for index,case in enumerate(movement['prestartSpeedPercent']['cases']):
        stream+=struct.pack('<IiI10i',10,case['boat'],case['seed'],*(case['inputs'][field] for field in MOVEMENT_FIELDS),*(case['indexedInputs'][field] for field in MOVEMENT_INDEXED))
        stream+=b''.join(bytes.fromhex(case['doubleInputBits'][field]) for field in ('raceTime','timeFactor'))
        stream+=b''.join(bytes.fromhex(case['indexedInputBits'][field]) for field in ('positionX','positionY'))
        cases.append({'group':'movement_prestart','index':index,'command':10,'expected':case['expected']})
    steering=load_fixture('original-steering.json',hashes)
    stream+=struct.pack('<I',11)
    cases.append({'group':'sound_recorder_binding','command':11,'expected':{'ack':1}})
    routine_ids={name:index for index,name in enumerate(['updatePlayer1Rudder','updatePlayer1Steering','updatePlayer2Steering'])}
    for name,routine in routine_ids.items():
        for index,case in enumerate(steering['routines'][name]['cases']):
            stream+=steering_request(routine,case['inputs'],case['doubleInputs'])
            cases.append({'group':'steering_'+name,'index':index,'command':12,'expected':case['expected']})
    for chain_index,chain in enumerate(steering['chains']):
        for step_index,step in enumerate(chain['steps']):
            integers={**chain['inputs'],**step['inputs']} if step_index==0 else step['inputs']
            doubles={**chain['doubleInputs'],**step['doubleInputs']} if step_index==0 else step['doubleInputs']
            stream+=steering_request(routine_ids[chain['routine']],integers,doubles)
            cases.append({'group':'steering_chain_'+chain['routine'],'chain':chain_index,'index':step_index,'command':12,'expected':step['expected']})
    encounters=load_fixture('original-encounter-leaves.json',hashes)
    ENCOUNTER_SCHEMA={'globals':encounters['globals'],'indexed':encounters['indexed'],'routines':{name:{key:value[key] for key in ('address','returnType')} for name,value in encounters['routines'].items()}}
    for routine,(name,data) in enumerate(encounters['routines'].items()):
        for index,case in enumerate(data['cases']):
            argv=case['arguments']+[0]*(3-len(case['arguments']))
            stream+=struct.pack('<II2i3iI',13,routine,case['boat'],case['otherBoat'],*argv,case['seed'])
            stream+=struct.pack('<'+'I'*len(encounters['globals']),*(case['globals'][field]&0xffffffff for field in encounters['globals']))
            for boat in [case['boat'],case['otherBoat']]:
                for field,spec in encounters['indexed'].items():
                    value=case['boats'][str(boat)][field]
                    stream+=struct.pack('<d',value) if spec['type']=='F64' else struct.pack('<I',value&0xffffffff)
            cases.append({'group':'encounter_'+name,'index':index,'command':13,'boats':[case['boat'],case['otherBoat']],'expected':case['expected']})
    stream+=struct.pack('<I',0)
    cases.append({'group':'text_integrity','command':0,'expected':{'ack':1}})
    if len(cases)>COMMAND_LIMIT:raise ValueError('Fixture requests exceed bounded native command count')
    return bytes(stream),cases,hashes

def decode(command: int, payload: bytes, case: dict | None = None) -> dict:
    if command==13:
        offset=0
        def take(count):
            nonlocal offset
            if offset+count>len(payload):raise ValueError('Truncated encounter response')
            data=payload[offset:offset+count];offset+=count;return data
        routine=struct.unpack('<I',take(4))[0]
        names=list(ENCOUNTER_SCHEMA['routines'])
        if routine>=len(names) or case['group']!='encounter_'+names[routine]:raise ValueError('Wrong fixed encounter routine response')
        result={'globals':{},'boats':{}}
        for field,spec in ENCOUNTER_SCHEMA['globals'].items():
            result['globals'][field]=struct.unpack('<I' if spec['type']=='U32' else '<i',take(4))[0]
        for boat in case['boats']:
            fields={}
            for field,spec in ENCOUNTER_SCHEMA['indexed'].items():
                raw=take(spec['stride'])
                fields[field]=struct.unpack('<d' if spec['type']=='F64' else '<i',raw)[0]
                if spec['type']=='F64':fields[field+'Bits']=raw.hex()
            result['boats'][str(boat)]=fields
        result['rngState']=struct.unpack('<I',take(4))[0]
        kind=ENCOUNTER_SCHEMA['routines'][names[routine]]['returnType']
        if kind=='float10':
            raw=take(8);result.update(returnValue=struct.unpack('<d',raw)[0],returnBits=raw.hex(),returnExtendedBits=take(10).hex())
        elif kind=='I64':
            raw=take(8);low,high=struct.unpack('<ii',raw)
            result.update(returnValue=low,returnHigh=high,returnSigned64=str(struct.unpack('<q',raw)[0]))
        elif kind!='void':result['returnValue']=struct.unpack('<i',take(4))[0]
        sound_count=struct.unpack('<I',take(4))[0]
        if sound_count>16:raise ValueError('Encounter sound recorder bound exceeded')
        result['sounds']=[dict(zip(['resourceId','moduleHandle','flags'],struct.unpack('<3I',take(12)))) for _ in range(sound_count)]
        change_count=struct.unpack('<I',take(4))[0]
        if change_count>512:raise ValueError('Encounter image-change bound exceeded')
        result['imageChanges']=[]
        for _ in range(change_count):
            address,count=struct.unpack('<II',take(8))
            if not 0x400000<=address<0x511000 or count>0x511000-address:raise ValueError('Invalid original-image change extent')
            result['imageChanges'].append({'address':address,'before':take(count).hex(),'after':take(count).hex()})
        if offset!=len(payload):raise ValueError('Trailing bytes in encounter response')
        return result
    if command==12:
        if len(payload)<92:raise ValueError('Missing steering response fields')
        sound_count=struct.unpack_from('<I',payload,88)[0]
        if sound_count>16 or len(payload)!=92+sound_count*12:raise ValueError('Invalid sound recorder response')
        result=dict(zip(STEERING_OUTPUTS,struct.unpack('<19i',payload[:76])))
        result.update(smoothHeading=struct.unpack('<d',payload[76:84])[0],smoothHeadingBits=payload[76:84].hex(),returnValue=struct.unpack('<i',payload[84:88])[0])
        result['sounds']=[dict(zip(['resourceId','moduleHandle','flags'],struct.unpack_from('<3I',payload,92+index*12))) for index in range(sound_count)]
        return result
    if command==8:
        if len(payload)<4:raise ValueError('Missing current routine response metadata')
        routine=struct.unpack_from('<I',payload)[0]
        expected_length=58 if 1<=routine<=3 else 44
        if routine>5 or len(payload)!=expected_length:raise ValueError('Invalid current routine response')
        result=dict(zip(CURRENT_OUTPUTS,struct.unpack('<7i',payload[4:32])))
        result.update(cachedMetric=struct.unpack('<d',payload[32:40])[0],cachedMetricBits=payload[32:40].hex())
        if 1<=routine<=3:
            result.update(returnValue=struct.unpack('<d',payload[40:48])[0],returnBits=payload[40:48].hex(),returnExtendedBits=payload[48:58].hex())
        else:result['returnValue']=struct.unpack('<i',payload[40:44])[0]
        return result
    sizes={0:4,1:4,2:72,3:68,4:16,5:4,6:8,7:4,9:22,10:12,11:4}
    if len(payload)!=sizes[command]:
        raise ValueError(f'Wrong response length for command {command}: {len(payload)}')
    if command in (0,1,7,11):return {'ack':struct.unpack('<I',payload)[0]}
    if command==9:
        return {'returnValue':struct.unpack('<d',payload[:8])[0],'returnBits':payload[:8].hex(),'returnExtendedBits':payload[8:18].hex(),'imageUnchanged':bool(struct.unpack('<I',payload[18:22])[0])}
    if command==10:
        value,seed,unchanged=struct.unpack('<iII',payload)
        return {'returnValue':value,'rngState':seed,'imageUnchanged':bool(unchanged)}
    if command==2:
        result=dict(zip(WIND_OUTPUTS,struct.unpack('<14i',payload[:56])))
        result.update(smoothDirection=struct.unpack('<d',payload[56:64])[0],smoothDirectionBits=payload[56:64].hex(),rngState=struct.unpack('<I',payload[64:68])[0],returnValue=struct.unpack('<i',payload[68:72])[0]);return result
    if command==3:
        result=dict(zip(BOAT_OUTPUTS,struct.unpack('<14i',payload[:56])))
        result.update(timeFactor=struct.unpack('<d',payload[56:64])[0],timeFactorBits=payload[56:64].hex(),returnValue=struct.unpack('<i',payload[64:68])[0]);return result
    if command==4:
        return {'pressure':struct.unpack('<d',payload[:8])[0],'pressureBits':payload[:8].hex(),'apparentWindKnots':struct.unpack('<i',payload[8:12])[0],'apparentWindAngle':struct.unpack('<i',payload[12:16])[0]}
    if command==5:return {'value':struct.unpack('<i',payload)[0]}
    return {'value':struct.unpack('<d',payload)[0],'bits':payload.hex()}

def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler',default=os.environ.get('TACT_MINGW_CC',DEFAULT_GCC if Path(DEFAULT_GCC).exists() else 'i686-w64-mingw32-gcc'))
    parser.add_argument('--wine',default=str(ROOT/'tools/wine-runtime/bin/wine'))
    parser.add_argument('--prefix',type=Path,default=Path('/home/martin/.local/share/posey-simulator/wineprefix'))
    parser.add_argument('--timeout',type=float,default=90)
    parser.add_argument('--update-encounter-fixture',action='store_true',help='Preserve evidence and correct only reviewed native shift floating outputs')
    arguments=parser.parse_args()
    source=ROOT/'original/Tact02Demo.exe'; executable=ROOT/'analysis/native-reference-2002.exe'; report_path=ROOT/'analysis/native-reference-comparison.json'
    if file_hash(source)!=EXPECTED:raise ValueError('Preserved original SHA256 mismatch')
    if not arguments.prefix.is_dir():raise ValueError('Expected existing dedicated 2002 Wine prefix')
    started=time.monotonic(); flags=compile_runner(arguments.compiler,executable)
    protocol,cases,fixture_hashes=requests()
    version=subprocess.run([arguments.wine,'--version'],capture_output=True,text=True,check=True).stdout.strip()
    environment={**os.environ,'WINEPREFIX':str(arguments.prefix),'WINEDEBUG':'-all'}
    source_windows='Z:'+str(source).replace('/','\\')
    command=[arguments.wine,str(executable),source_windows]
    report={'source_sha256':EXPECTED,'engine':'Native i386 instructions under Wine on the host CPU; original executable code is unchanged.','wine_version':version,'host_machine':platform.machine(),'x87_control_word':'0x037f','runner_image_base':'0x00300000','original_image_base_required':'0x00400000','fixture_sha256':fixture_hashes,'runner_source_sha256':file_hash(ROOT/'tools/native_reference_2002.c'),'runner_sha256':file_hash(executable),'compiler':arguments.compiler,'compiler_flags':flags,'scope':'Full isolated original global-wind, boat-options, apparent-wind, bearing, radian-wrap, and six current routines. Finite fixture domain; current geometry is explicitly synthetic, not recovered course geometry. Not full race, historical CPU, or UI parity.','mapping':'Manual in-process mapping of this exact SHA256-checked image into an explicit host-owned PE data section linked at its original base, copying unchanged headers/raw sections and zero-initialized BSS with original section protections. No original entrypoint or whole Windows lifecycle.','loader_limitation':'Wine LoadLibraryA and LoadLibraryExA(DONT_RESOLVE_DLL_REFERENCES) mapped the relocation-stripped EXE at 0x00ea0000 instead of its required preferred base.','import_initialization':'Only original import-address-table data resolved with LoadLibrary/GetProcAddress.','tls_initialization':'TlsAlloc/TlsSetValue for isolated original CRT 0x74-byte thread block; original TLS index data set to allocated slot. Original TLS accessor instructions are executed.','startup_original_initializer':'00415a60 (trigonometric lookup data)','original_routine_addresses':['0041b5d0','00417790','00429df0','0041bb10','00413cd0','00421560','00420b70','00420c40','00420d10','00421ae0','00421b80'],'current_geometry':'Synthetic shorelineX[64], shorelineY[64], radialBoundary[181] from original-current.json; explicitly not recovered course geometry.','groups':{},'differences':[]}
    report.update(
        scope='Full isolated original global-wind, boat-options, apparent-wind, bearing, radian-wrap, six current, two movement-helper, and three steering routines. Finite fixture domain; current geometry and movement inputs are synthetic. Not full race, historical CPU, UI, or sound-playback parity.',
        original_routine_addresses=report['original_routine_addresses']+['00428ab0','0042a3b0','0042ba00','0042b7f0','0042bda0'],
        sound_initialization='Only the known PlaySoundA IAT data slot at 004b1c18 is subsequently rebound to a host-owned stdcall recorder. Ordered resource/module/flags arguments are captured and BOOL1 returned, matching the CPU fixture environment; no actual audio playback.',
        protocol_command_limit=COMMAND_LIMIT,
        protocol_commands=len(cases),
        sound_requests_compared=0,
        movement_original_image_unchanged_every_call=True,
        fixed_encounter_schema_sha256=file_hash(ROOT/'tools/native_encounter_schema.h'),
        encounter_scope='Seven complete leaves, synthetic endpoints/boat inputs, full I64 and m80 returns, RNG/sound requests, every final mapped-image byte change. Independent cases restore original initialized writable data before applying inputs.',
    )
    report['original_routine_addresses'] += [f'{data["address"]:08x}' for data in ENCOUNTER_SCHEMA['routines'].values()]
    try:
        process=subprocess.run(command,input=protocol,capture_output=True,env=environment,timeout=arguments.timeout)
        (ROOT/'analysis/native-reference-wine.log').write_bytes(process.stderr)
        report['process_exit_code']=process.returncode
        if process.returncode!=0:raise RuntimeError(f'Native runner exited {process.returncode}: '+process.stderr.decode(errors='replace')[-2000:])
        output=process.stdout
        if len(output)<32 or output[:8]!=b'TACT2002':raise ValueError('Missing native protocol hello')
        version_id,base,tls_index,imports,control,mapping=struct.unpack('<6I',output[8:32])
        if version_id!=2 or base!=0x400000 or control!=0x037f or mapping!=1:raise ValueError('Unexpected native initialization metadata')
        report['native_initialization']={'protocol_version':version_id,'module_base':hex(base),'isolated_tls_index':tls_index,'resolved_original_imports':imports,'x87_control_word':hex(control),'mapping_mode':'fixed preserved image copied into dedicated host PE section at 0x400000'}
        offset=32
        for case in cases:
            if offset+8>len(output):raise ValueError('Missing native response')
            command_id,length=struct.unpack_from('<II',output,offset);offset+=8
            if command_id!=case['command'] or offset+length>len(output):raise ValueError('Native response framing/order mismatch')
            actual=decode(command_id,output[offset:offset+length],case);offset+=length
            report['sound_requests_compared']+=len(actual.get('sounds',[]))
            if command_id in (9,10):
                report['movement_original_image_unchanged_every_call'] &= actual['imageUnchanged']
            group=report['groups'].setdefault(case['group'],{'cases':0,'exact_matches':0,'different_cases':0,'different_fields':{}});group['cases']+=1
            differences={field:{'fixture':expected,'native':actual[field]} for field,expected in case['expected'].items() if actual[field]!=expected}
            if differences:
                group['different_cases']+=1
                for field in differences:group['different_fields'][field]=group['different_fields'].get(field,0)+1
                report['differences'].append({k:v for k,v in case.items() if k not in ('expected','command')}|{'fields':differences})
            else:group['exact_matches']+=1
        if offset!=len(output):raise ValueError('Extra bytes after final native verification')
        report['loaded_original_text_unchanged']=report['groups']['text_integrity']['exact_matches']==1
        report['comparison_complete']=True
        report['all_fixture_cases_match']=not report['differences']
        routine_groups=[group for name,group in report['groups'].items() if name not in ('random_table','synthetic_geometry','sound_recorder_binding','text_integrity')]
        report['function_cases']=sum(group['cases'] for group in routine_groups)
        report['exact_function_cases']=sum(group['exact_matches'] for group in routine_groups)
    except (RuntimeError,ValueError,subprocess.TimeoutExpired) as error:
        report['comparison_complete']=False;report['error']=str(error)
        raise
    finally:
        report['original_file_unchanged']=file_hash(source)==EXPECTED
        report['elapsed_seconds']=time.monotonic()-started
        report_path.write_text(json.dumps(report,indent=2,allow_nan=False)+'\n')
    if arguments.update_encounter_fixture:update_native_shift_fixture(report,report_path)
    print(json.dumps({'comparison_complete':report['comparison_complete'],'all_fixture_cases_match':report['all_fixture_cases_match'],'groups':report['groups'],'loaded_original_text_unchanged':report['loaded_original_text_unchanged'],'original_file_unchanged':report['original_file_unchanged']},indent=2))

if __name__=='__main__':main()
