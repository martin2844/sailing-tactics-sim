#!/usr/bin/env python3
"""Bounded unchanged-code references for complete encounter and penalty calls.

Every prepared byte is explicit relative to the original image after its integer
trig initialization. The only import substitute records PlaySoundA requests.
Hardware FSIN differences require subsequent native original-code authority.
"""
import argparse
import hashlib
import itertools
import random
import re
import struct

import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_encounter_fixtures import GLOBALS as LEAF_GLOBALS, INDEXED as LEAF_INDEXED, merged_ranges

BASE, SIZE = 0x491000, 0x1d000
GLOBALS = {**LEAF_GLOBALS, 'viewportWidth': (0x4a763c, 'I32'),
           'twoPlayerMode': (0x4ac9ac, 'I32'), 'catamaranFlag': (0x4ac900, 'I32'),
           'boardFlag': (0x4ac904, 'I32'), 'previousInterference': (0x4aa830, 'I32')}
INDEXED = {**LEAF_INDEXED, 'penaltyCode': (0x4a89c0, 'I32', 4),
           'penaltyTime': (0x4abf18, 'I32', 4), 'windInterference': (0x4a40d0, 'I32', 4),
           'turnMode': (0x4a4df8, 'I32', 4), 'lastTurnTime': (0x4a41f0, 'I32', 4),
           'interference': (0x4a7868, 'I32', 4), 'leader': (0x4a6010, 'I32', 4),
           'overlap': (0x4aada0, 'I32', 4), 'trueWindKnots': (0x4a6338, 'I32', 4)}
ROUTINES = {
    'collisionPenalty': (0x42a530, ['I32'] * 3),
    'updateMarkStartPenalties': (0x42a2d0, ['I32']),
    'updateInterference': (0x429f40, ['I32']),
}


def changed(before, after):
    """Exact contiguous byte deltas, with comparison done in compiled operations."""
    difference = (int.from_bytes(before, 'little') ^ int.from_bytes(after, 'little')).to_bytes(len(before), 'little')
    return [{'address': BASE + match.start(), 'before': before[match.start():match.end()].hex(),
             'after': after[match.start():match.end()].hex()}
            for match in re.finditer(rb'[^\x00]+', difference)]


def defaults(boat=1, other=2, **values):
    globals = {'boatCount': 3, 'humanBoatCount': 1, 'startMode': 3, 'time': 100,
               'endpointAX': -600, 'endpointAY': 0, 'endpointBX': 600, 'endpointBY': 0,
               'endpointCX': 0, 'endpointCY': 1000, 'endpointDX': -600, 'endpointDY': 1000,
               'endpointEX': 600, 'endpointEY': 1000, 'relocationSpan': 600,
               'spawnX': 0, 'spawnY': -300, 'soundDisabled': 0, 'moduleHandle': 0x76543210,
               'course': 1, 'reversePenaltyFlag': 0, 'closehauledAngle': 45,
               'viewportWidth': 900, 'twoPlayerMode': 0, 'catamaranFlag': 0,
               'boardFlag': 0, 'previousInterference': 99}
    globals.update(values)
    boats = {}
    for number in range(1, max(globals['boatCount'], boat, other)+1):
        boats[number] = {'raceStage': 3, 'targetX': -731, 'targetY': 913,
                         'heading': 45, 'tack': 1, 'trueWindDirection': 0,
                         'angleToWind': 45, 'downwindLimit': 150,
                         'positionX': 100.25 + number * 300,
                         'positionY': 100.75 + number * 250,
                         'penaltyCode': 9, 'penaltyTime': -1000, 'windInterference': 0,
                         'turnMode': 0, 'lastTurnTime': -1000,
                         'interference': 7, 'leader': 13, 'overlap': 1,
                         'trueWindKnots': 10}
    boats[boat].update(positionX=100.25, positionY=100.75)
    boats[other].update(positionX=104.25, positionY=101.75)
    return {'boat': boat, 'other': other, 'distance': 5,
            'seed': 2002, 'globals': globals, 'boats': boats}


def cases(name, prng):
    if name == 'collisionPenalty':
        for time, tack, other_tack, blocked, boat, count in itertools.product(
            [-169, -168, -167, -3, -2, -1, 0, 1, 3, 4, 19, 20, 49, 50, 51, 100],
            [-1, 1], [-1, 1], [0, 1], [1, 3], [2, 3]):
            other = 2 if boat == 1 else 1
            state = defaults(boat, other, time=time, boatCount=count,
                             soundDisabled=(time % 3 == 0), course=8 if time % 5 == 0 else 1,
                             reversePenaltyFlag=time % 2)
            state['boats'][boat].update(tack=tack, windInterference=blocked)
            state['boats'][other]['tack'] = other_tack
            yield state
        for cooldown, stage, distance, catamaran in itertools.product([49, 50, 51], [8, 9], [5, 6, 7], [0, 1]):
            state = defaults(catamaranFlag=catamaran)
            state['boats'][1].update(tack=-1, raceStage=stage)
            state['boats'][2].update(tack=1, penaltyTime=100-cooldown)
            state['distance'] = distance
            yield state
        for point, offset, count, angle, nearer in itertools.product(
            ['D', 'E'], [0.0, 29.999999999999996, 30.0, 39.99999999999999, 40.0],
            [2, 3], [55, 56, 57], [False, True]):
            state = defaults(boatCount=count)
            x, y = state['globals']['endpoint'+point+'X'], state['globals']['endpoint'+point+'Y']
            state['boats'][1].update(positionX=x, positionY=y+offset, angleToWind=angle, raceStage=7)
            state['boats'][2].update(positionX=x + (200 if nearer else -200), positionY=y-200, raceStage=7)
            yield state
        for turn, angle, elapsed, radius in itertools.product([0, 1], [54, 55, 56], [4, 5, 6], [19.999999999999996, 20.0, 20.000000000000004]):
            state = defaults()
            state['boats'][1].update(positionX=0, positionY=1000-radius, tack=1,
                                     turnMode=turn, angleToWind=angle, lastTurnTime=100-elapsed)
            state['boats'][2]['tack'] = -1
            yield state
    elif name == 'updateMarkStartPenalties':
        for point, delta, time, width, boat in itertools.product(
            ['A', 'B', 'C', 'D', 'E'], [-4, -3, -2, -1, 0, 1, 2, 3, 4],
            [19, 20], [900, 901], [1, 2]):
            state = defaults(boat, 2 if boat == 1 else 1, time=time, viewportWidth=width,
                             course=8 if delta % 2 else 1, reversePenaltyFlag=delta % 2)
            state['boats'][boat].update(positionX=state['globals']['endpoint'+point+'X']+delta+0.25,
                                        positionY=state['globals']['endpoint'+point+'Y']-0.25)
            yield state
        for y, time, mode, two_players, boat in itertools.product(
            [-1.0000000000000002, -1.0, -0.0, 0.0, 1.0, 1.0000000000000002],
            [-4, -3, -2, -1, 0, 1, 50, 51], [1, 2, 3, 4], [0, 1], [1, 2]):
            state = defaults(boat, 2 if boat == 1 else 1, time=time, startMode=mode, twoPlayerMode=two_players)
            state['boats'][boat].update(positionX=0.0, positionY=y)
            yield state
    elif name == 'updateInterference':
        for distance, tack, other_tack, heading, wind, count, boat in itertools.product(
            [0, 5, 6, 7, 8, 9, 19, 20, 29, 30, 59, 60, 64, 65, 74, 75],
            [-1, 1], [-1, 1], [0, 29, 30, 180], [0, 10, 11, 12], [2, 3], [1, 2]):
            other = 2 if boat == 1 else 1
            state = defaults(boat, other, boatCount=count, catamaranFlag=heading % 2,
                             boardFlag=wind % 2, viewportWidth=900+(distance % 2))
            state['boats'][boat].update(tack=tack, heading=heading, trueWindKnots=wind,
                                        positionX=100.25, positionY=100.75)
            state['boats'][other].update(tack=other_tack, heading=(heading+180)%360,
                                         positionX=100.25+distance, positionY=100.75)
            yield state
    # Random configurations also exercise descending scans after a relocation,
    # several simultaneous overlaps, and all normal course/stage branches.
    for _ in range(256):
        count = prng.choice([2, 3, 15, 30])
        boat = prng.randrange(1, count+1)
        other = boat % count + 1
        state = defaults(boat, other, boatCount=count, humanBoatCount=prng.choice([1, 2]),
                         time=prng.choice([-170, -168, -167, -2, 0, 3, 19, 20, 30, 51, 100]),
                         startMode=prng.randrange(1, 5), course=prng.choice([1, 8, 11]),
                         reversePenaltyFlag=prng.randrange(2), boardFlag=prng.randrange(2),
                         catamaranFlag=prng.randrange(2), viewportWidth=prng.choice([800, 900, 901, 1200]),
                         soundDisabled=prng.randrange(2), twoPlayerMode=prng.randrange(2))
        state['seed'] = prng.randrange(2**32)
        state['distance'] = prng.randrange(-1, 11)
        for number in range(1, count+1):
            state['boats'][number].update(
                positionX=prng.uniform(-50, 50), positionY=prng.uniform(-50, 50),
                tack=prng.choice([-1, 1]), heading=prng.randrange(362),
                trueWindDirection=prng.randrange(362), angleToWind=prng.randrange(181),
                trueWindKnots=prng.randrange(31), raceStage=prng.randrange(11),
                penaltyTime=prng.choice([-1000, state['globals']['time']-50]),
                windInterference=prng.randrange(2), turnMode=prng.randrange(4),
                lastTurnTime=state['globals']['time']-prng.randrange(11))
        yield state


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true')
    args = parser.parse_args()
    vm = OriginalMachine()
    vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    stub = SCRATCH + 0x800
    vm.write_i32(0x4b1c18, stub)
    sounds, writes = [], []

    def sound(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<4I', uc.mem_read(esp, 16))
        sounds.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1)
        uc.reg_write(UC_X86_REG_ESP, esp + 16)
        uc.reg_write(UC_X86_REG_EIP, ret)

    def write(uc, access, address, size, value, data):
        if BASE <= address and address + size <= BASE + SIZE: writes.append((address, size))

    vm.uc.hook_add(UC_HOOK_CODE, sound, begin=stub, end=stub)
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, write)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18', 'sound_return': 1,
        'note': 'Complete connected routine captures with explicit synthetic boat/course inputs and unchanged original .text. Native original-code authority is required for final FSIN-dependent positions; this emulator record is preserved separately when corrected.'},
        'mutableBlock': {'address': BASE, 'size': SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    prng = random.Random(0x42a530)
    for name, (address, kinds) in ROUTINES.items():
        records = []
        for state in cases(name, prng):
            vm.uc.mem_write(BASE, baseline)
            for field, value in state['globals'].items(): vm.write_i32(GLOBALS[field][0], value)
            for boat, fields in state['boats'].items():
                for field, value in fields.items():
                    location, kind, stride = INDEXED[field]
                    raw = struct.pack('<d', value) if kind == 'F64' else struct.pack('<I', value & 0xffffffff)
                    vm.uc.mem_write(location + boat * stride, raw)
            argv = [state['other'], state['boat'], state['distance']] if name == 'collisionPenalty' else [state['boat']]
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            vm.write_i32(TLS + 0x14, state['seed'])
            sounds.clear(); writes.clear()
            vm.call(address, arguments(*argv), count=3000000)
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text: raise AssertionError('Original .text changed')
            records.append({'arguments': argv, 'seedAtCall': state['seed'],
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)],
                'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': sounds.copy(),
                             'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()},
                'imageWrites': [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)]})
        fixture['routines'][name] = {'address': address, 'argumentTypes': kinds,
                                    'returnType': 'void', 'cases': records}
        print(name, len(records), flush=True)
    save(ROOT / 'tests/fixtures/original-connected-encounters.json', fixture)

    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'),
            '--fixture', 'original-connected-encounters.json', '--report', str(ROOT/'analysis/connected-encounters-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__': main()
