#!/usr/bin/env python3
"""Bounded unchanged-original captures for race setup and position integration.

The synthetic RNG table is shared with existing global-wind fixtures. Connected
preparation calls are recorded, and their complete image state becomes explicit
input to each isolated tested routine. No expected value comes from JavaScript.
"""
import argparse
import hashlib
import itertools
import json
import math
import struct
import subprocess
import sys
import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, i32, save
from capture_encounter_fixtures import merged_ranges

BASE, SIZE = 0x491000, 0x1d000
ROUTINES = {
    'initializeCurvedHull': (0x412f60, ['F64', 'F64']),
    'initializeFlatHull': (0x413100, ['F64', 'F64']),
    'initializeWind': (0x41b170, []), 'initializeTide': (0x41b510, []),
    'initializeWindSources': (0x42e0a0, []), 'respawnWindPatch': (0x41e9c0, ['I32']),
    'initializeShoreline': (0x41fd90, []), 'initializeEllipse': (0x41f5b0, []),
    'initializeAdvancedTerrain': (0x44e470, []),
    'initializeCourseConfiguration': (0x41f0b0, []),
    'initializeCourse': (0x4201a0, ['I32']), 'initializeBoats': (0x41eb80, []),
    'placeStartingBoats': (0x420dd0, []), 'initializeRace': (0x413f00, []),
    'integratePositions': (0x42adb0, []), 'recordTrails': (0x4313a0, []),
    'advanceRaceTarget': (0x426ad0, ['I32']), 'projectPoint': (0x420b20, ['I32'] * 4),
}
CONFIG = {'course': 0x491194, 'boatClass': 0x491188, 'boatCount': 0x49118c,
          'humans': 0x491140, 'difficulty': 0x491190, 'startMode': 0x4911cc,
          'twoBoatMode': 0x4ac9ac, 'island': 0x4a5a4c, 'shortened': 0x491160,
          'repeat': 0x4ac950, 'regenerate': 0x4ac940, 'reduction': 0x4ac954,
          'reverse': 0x4ac9a8, 'soundDisabled': 0x4ac9c0, 'weather': 0x4a4958,
          'shore': 0x4aa804, 'tideMode': 0x491158, 'night': 0x4ac990,
          'windLevel': 0x491154, 'clockRate': 0x49115c, 'speedLevel': 0x49116c,
          'speedDivisor': 0x491170, 'optimist': 0x4ac914, 'catamaran': 0x4ac900,
          'skiff': 0x4ac90c, 'sportBoat': 0x4ac908, 'board': 0x4ac904}

def integer_inputs(**values):
    return [{'address': CONFIG[name], 'type': 'I32', 'value': value} for name, value in values.items()]

def changed(before, after):
    records = []
    cursor = 0
    while cursor < len(before):
        if before[cursor] == after[cursor]: cursor += 1; continue
        start = cursor
        while cursor < len(before) and before[cursor] != after[cursor]: cursor += 1
        records.append({'address': BASE + start, 'before': before[start:cursor].hex(), 'after': after[start:cursor].hex()})
    return records

def cases(name):
    if name in ['initializeCurvedHull', 'initializeFlatHull']:
        for length, width, optimist in itertools.product([0.0, -0.0, 1.0, 17.3, math.nextafter(17.3, math.inf), 35.0, 65.5], [0.0, 2.7, -2.7, 11.25], [0, 1]):
            yield {'seed': 2002, 'arguments': [length, width], 'inputs': integer_inputs(optimist=optimist) + [{'address': a, 'type': 'F64', 'value': v} for a, v in [(0x4a3a48, 500.125), (0x4ac320, -70.25), (0x4ac338, 91.5)]]}
    elif name == 'projectPoint':
        for angle, distance in itertools.product(range(0, 360, 15), [-500, 0, 1, 1000]):
            yield {'seed': 2002, 'arguments': [-123, 456, distance, angle], 'inputs': []}
    elif name in ['initializeWind', 'initializeTide', 'initializeWindSources']:
        for seed, course, weather in itertools.product([0, 1, 2002, 0xffffffff], [1, 8, 9, 10], [0, 1, 4, 7]):
            yield {'seed': seed, 'arguments': [], 'inputs': integer_inputs(course=course, weather=weather, shore=(course % 4) + 1, island=course % 2, humans=1 + seed % 2, night=seed % 2, windLevel=seed % 4, tideMode=seed % 2)}
    elif name == 'initializeShoreline':
        for seed, course, shore in itertools.product([0, 1, 2002, 0xffffffff], [1, 3, 9, 10], [1, 3]):
            yield {'seed': seed, 'arguments': [], 'inputs': integer_inputs(course=course, shore=shore) + integer_inputs() + [{'address': 0x4aa290, 'type': 'I32', 'value': -900 if shore == 1 else 900}, {'address': 0x4a8e8c, 'type': 'I32', 'value': 1 if shore == 1 else -1}]}
    elif name == 'initializeEllipse':
        for seed, course, weather, island, shore in itertools.product([1, 2002], [2, 4, 8, 11], [0, 1], [0, 1], [2, 4]):
            yield {'seed': seed, 'arguments': [], 'inputs': integer_inputs(course=course, weather=weather, island=island, shore=shore) + [{'address': 0x4a6470, 'type': 'F64', 'value': 0.65}, {'address': 0x4abe60, 'type': 'F64', 'value': 1.5}, {'address': 0x4a4378, 'type': 'I32', 'value': int(course == 11)}, {'address': 0x4a5b9c, 'type': 'I32', 'value': int(course == 8 and island == 0)}]}
    elif name == 'initializeAdvancedTerrain':
        for seed, weather in itertools.product([0, 1, 19, 2002, 0xffffffff], range(2, 8)):
            yield {'seed': seed, 'arguments': [], 'inputs': integer_inputs(weather=weather)}
    elif name in ['initializeRace', 'initializeCourseConfiguration']:
        for course, seed in itertools.product(range(15), [1, 2002, 0xffffffff]):
            yield {'seed': seed, 'arguments': [], 'inputs': integer_inputs(course=course, boatClass=7 if course == 8 else 6, boatCount=[2, 3, 15, 30][course % 4], humans=1 + seed % 2, difficulty=[1, 7, 14][seed % 3], startMode=[2, 5, 10][seed % 3], island=int(course == 7 or (course == 8 and seed % 2)), shortened=0, repeat=0, regenerate=0, reduction=0, reverse=seed % 2, soundDisabled=0)}
        for start, human, count, mode in itertools.product([2, 5, 10], [1, 2], [2, 15], [0, 1]):
            yield {'seed': 9000 + start * 100 + human * 10 + count + mode, 'arguments': [], 'inputs': integer_inputs(course=1, boatClass=7 if mode else 6, startMode=start, humans=human, boatCount=count, twoBoatMode=mode, shortened=1, reduction=1, repeat=1, regenerate=1)}
    else:
        for course, seed, count in itertools.product([1, 2, 6, 7, 8, 9, 10, 11, 14], [1, 2002], [2, 15]):
            state = {'seed': seed, 'arguments': [1] if name == 'advanceRaceTarget' else [10] if name == 'initializeCourse' else [3] if name == 'respawnWindPatch' else [],
                'inputs': integer_inputs(course=course, boatClass=7 if course == 8 else 6, boatCount=count, humans=1, island=int(course == 7), shortened=0, reduction=0, repeat=0, regenerate=0, reverse=seed % 2), 'prepareOriginal': [0x413f00]}
            if name == 'advanceRaceTarget': state['afterPreparation'] = [{'address': 0x4a5424, 'type': 'I32', 'value': [0, 6, 7, 8][course % 4]}]
            if name == 'recordTrails': state['afterPreparation'] = [{'address': 0x4ab9d8, 'type': 'I32', 'value': [0, 1, 2, 149][course % 4]}]
            if name == 'integratePositions':
                state['afterPreparation'] = [{'address': 0x4ac1f8, 'type': 'F64', 'value': [-170, -30, -0.1, 0, 29.99, 60.0, 3599.9, 3600.0, 18000.0][[1,2,6,7,8,9,10,11,14].index(course)]}, {'address': 0x4aa948, 'type': 'F64', 'value': 25 / 171}, {'address': 0x4ab0c0, 'type': 'F64', 'value': 1.25}, {'address': 0x4a5ba4, 'type': 'I32', 'value': 30}]
                for boat in range(1, count + 1):
                    state['afterPreparation'] += [{'address': 0x4a7060 + boat * 4, 'type': 'I32', 'value': boat * 7 + 20}, {'address': 0x4ac018 + boat * 4, 'type': 'I32', 'value': (boat * 39) % 360}, {'address': 0x4a6e48 + boat * 4, 'type': 'I32', 'value': 95}, {'address': 0x4aa5b0 + boat * 4, 'type': 'I32', 'value': 230}]
            yield state

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true', help='Capture CPU-emulated evidence only; skip native authority and do not claim native parity')
    args = parser.parse_args()
    vm = OriginalMachine(); vm.call(0x415a60)
    wind = json.loads((ROOT / 'tests/fixtures/original-global-wind.json').read_text())
    for index, value in enumerate(wind['randomTable']): vm.write_i32(0x4a9450 + index * 4, value)
    stub = SCRATCH + 0x800; vm.write_i32(0x4b1c18, stub)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE)); text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    sounds, writes = [], []
    def sound(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<4I', uc.mem_read(esp, 16))
        sounds.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1); uc.reg_write(UC_X86_REG_ESP, esp + 16); uc.reg_write(UC_X86_REG_EIP, ret)
    def write(uc, access, address, size, value, data):
        if BASE <= address and address + size <= BASE + SIZE: writes.append((address, size))
    vm.uc.hook_add(UC_HOOK_CODE, sound, begin=stub, end=stub); vm.uc.hook_add(UC_HOOK_MEM_WRITE, write)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__, 'x87_control_word': '0x037f', 'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18', 'sound_return': 1, 'note': 'Finite unchanged-code initialization and connected setup cases; synthetic precomputed wind RNG table; no full app lifecycle. Native x87 outputs require subsequent original-code Wine authority comparison.'}, 'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60, 'randomTableAddress': 0x4a9450, 'randomTable': wind['randomTable']}, 'routines': {}}
    def apply(inputs):
        for row in inputs:
            if row['type'] == 'F64': vm.uc.mem_write(row['address'], struct.pack('<d', row['value']))
            else: vm.write_i32(row['address'], row['value'])
    for name, (address, kinds) in ROUTINES.items():
        records = []
        for case in cases(name):
            vm.uc.mem_write(BASE, baseline); apply(case['inputs']); vm.write_i32(TLS + 0x14, case['seed'])
            for routine in case.get('prepareOriginal', []): vm.call(routine, count=3000000)
            apply(case.get('afterPreparation', []))
            case['seedAtCall'] = vm.read_u32(TLS + 0x14)
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            case['imageInputs'] = [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)]
            sounds.clear(); writes.clear()
            argv = b''.join(struct.pack('<d', value) if kind == 'F64' else struct.pack('<I', value & 0xffffffff) for value, kind in zip(case['arguments'], kinds))
            try: returned = vm.call(address, argv, count=3000000)
            except Exception as error: raise RuntimeError(f'{name} case {len(records)} {case}') from error
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original text changed')
            case['expected'] = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': sounds.copy(), 'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest(), 'residualEAX': i32(returned)}
            case['imageWrites'] = [{'address': start, 'size': end - start} for start, end in merged_ranges(writes)]
            records.append(case)
        fixture['routines'][name] = {'address': address, 'argumentTypes': kinds, 'returnType': 'residualEAX' if name in ['integratePositions', 'initializeCourse', 'recordTrails'] else 'void', 'cases': records}
        print(name, len(records), flush=True)
    save(ROOT / 'tests/fixtures/original-initialization.json', fixture)
    if not args.emulated_only:
        subprocess.run([sys.executable, str(ROOT / 'tools/verify_native_state.py'),
            '--fixture', 'original-initialization.json', '--report',
            str(ROOT / 'analysis/initialization-native-reference-comparison.json'), '--update-fixture'], check=True)

if __name__ == '__main__': main()
