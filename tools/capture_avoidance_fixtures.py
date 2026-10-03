#!/usr/bin/env python3
"""Capture the four complete original collision-avoidance routines.

Prepared geometry is explicitly synthetic. Every original image byte is reset
between cases, every image store is recorded, and .text is checked unchanged.
The only external substitutes are the isolated CRT record and PlaySoundA
request recorder. Native original-code comparisons establish final authority.
"""
import argparse
import hashlib
import itertools
import json
import math
import random
import struct

import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import GLOBALS as ENCOUNTER_GLOBALS, INDEXED as ENCOUNTER_INDEXED
from native_mutable_state import BLOCK_ADDRESS, BLOCK_SIZE, image_changes

DESTINATION = ROOT / 'tests/fixtures/original-avoidance.json'
MAP = json.loads((ROOT / 'analysis/avoidance-map.json').read_text())
GLOBALS = {**ENCOUNTER_GLOBALS, 'skiffFlag': (0x4ac90c, 'I32'),
           **{name: (entry['address'], entry['type']) for name, entry in MAP['globals'].items()}}
INDEXED = {**ENCOUNTER_INDEXED,
           **{name: (entry['address'], entry['type'], entry['stride']) for name, entry in MAP['indexed'].items()}}
ROUTINES = {
    'updateCollisionAvoidance': (0x427fd0, ['I32']),
    'avoidAiCollision': (0x4280c0, ['I32'] * 4),
    'warnHumanRightOfWay': (0x4286e0, ['I32'] * 3),
    'requestRightOfWaySound': (0x428a30, ['I32']),
}


def defaults(boat=2, other=1, **values):
    globals = {'boatCount': 3, 'humanBoatCount': 1, 'startMode': 3, 'time': 100,
        'endpointAX': -600, 'endpointAY': 0, 'endpointBX': 600, 'endpointBY': 0,
        'endpointCX': 0, 'endpointCY': 1000, 'endpointDX': -600, 'endpointDY': 1000,
        'endpointEX': 600, 'endpointEY': 1000, 'relocationSpan': 600,
        'spawnX': 0, 'spawnY': -300, 'soundDisabled': 0, 'moduleHandle': 0x76543210,
        'course': 1, 'reversePenaltyFlag': 0, 'closehauledAngle': 45,
        'viewportWidth': 900, 'twoPlayerMode': 0, 'catamaranFlag': 0,
        'boardFlag': 0, 'skiffFlag': 0, 'previousInterference': 99,
        'feedbackCode': 91, 'feedbackTime': -1000, 'feedbackDistance': -88,
        'closehauledOverride': 0, 'lastRightOfWaySound': -1000, 'resetTime': -1000}
    globals.update(values)
    boats = {}
    for number in range(1, max(globals['boatCount'], boat, other) + 1):
        boats[number] = {'raceStage': 3, 'targetX': -731, 'targetY': 913,
            'heading': 45, 'tack': 1, 'trueWindDirection': 0, 'angleToWind': 45,
            'downwindLimit': 150, 'positionX': float(number * 300), 'positionY': 0.0,
            'penaltyCode': 9, 'penaltyTime': -1000, 'windInterference': 0,
            'turnMode': 0, 'lastTurnTime': -1000, 'interference': 7, 'leader': 13,
            'overlap': 1, 'trueWindKnots': 10, 'collisionTime': -1000,
            'collisionX': number * 300, 'collisionY': 0, 'startDistance': 300,
            'relativeTargetAngle': 20, 'avoidanceTurnState': 3,
            'rightOfWayWarning': 0, 'spinnakerHoldFlag': 0, 'speedOverride': -87,
            'speedTenths': 37, 'tackSlowFlag': 0}
    boats[boat].update(positionX=0.0, positionY=0.0, collisionX=0, collisionY=0)
    boats[other].update(positionX=4.0, positionY=0.0, collisionX=4, collisionY=0)
    return {'branch': 'default', 'boat': boat, 'other': other, 'distance': 4,
            'turnMultiplier': 2, 'selector': 1, 'seed': 2002, 'globals': globals, 'boats': boats}


def cases(name, prng):
    if name == 'requestRightOfWaySound':
        for selector, disabled, reset, delta in itertools.product(
                [-1, 0, 1, 2, 3], [-1, 0, 1, 2],
                [-2**31, -1000, 0, 2**31 - 11, 2**31 - 10, 2**31 - 1], [9, 10, 11]):
            state = defaults(soundDisabled=disabled, resetTime=reset,
                             time=((reset + delta + 2**31) % 2**32) - 2**31)
            state.update(selector=selector, branch='sound-time-gates')
            yield state
        return
    if name == 'updateCollisionAvoidance':
        for count, boat, humans, delta, elapsed in itertools.product(
                [0, 1, 2, 3, 15, 30], [1, 2], [0, 1, 2],
                [0, 5, 8, 9, 10, -8, -9], [4, 5, 6]):
            state = defaults(boat, 2 if boat == 1 else 1, boatCount=count, humanBoatCount=humans)
            state['branch'] = 'scan-distance-cooldown'
            state['boats'][boat].update(collisionTime=100-elapsed, spinnakerHoldFlag=1, tack=-1)
            state['boats'][state['other']].update(collisionX=delta, collisionY=0, tack=1)
            yield state
        for x, y, angle in itertools.product(
                [-2**31, -2**31+1, 0, 2**31-2, 2**31-1], [-8, 0, 8], [-361, -1, 0, 360, 361]):
            state = defaults(1, 2)
            state['branch'] = 'signed-position-and-heading'
            state['boats'][1].update(collisionX=x, collisionY=y, heading=angle)
            state['boats'][2].update(collisionX=-2**31, collisionY=0)
            yield state
    else:
        for time, mode, two_players, elapsed, reset_delta in itertools.product(
                [-2, 0, 1, 2, 3, 4, 30, 31], [2, 3], [0, 1], [2, 3, 4], [1, 2, 10]):
            state = defaults(time=time, startMode=mode, twoPlayerMode=two_players, resetTime=time-reset_delta)
            state['branch'] = 'entry-time-gates'
            state['boats'][2].update(collisionTime=time-elapsed, tack=-1)
            yield state
        for tack, other_tack, blocked, speed, two_players in itertools.product(
                [-1, 1], [-1, 1], [0, 1], [-2**31, -99, -1, 0, 1, 99, 2**31-1], [0, 1]):
            state = defaults(twoPlayerMode=two_players)
            state['branch'] = 'wind-interference'
            state['boats'][2].update(tack=tack, windInterference=blocked)
            state['boats'][1].update(tack=other_tack, speedTenths=speed)
            yield state
        for point, radius, count, distance, time, reverse in itertools.product(
                ['D', 'E'], [49.99999999999999, 50.0, 50.00000000000001,
                             74.99999999999999, 75.0, 75.00000000000001],
                [2, 3], [21, 22], [30, 31], [0, 1]):
            state = defaults(boatCount=count, time=time, reversePenaltyFlag=reverse, twoPlayerMode=1)
            state.update(distance=distance, branch='mark-radius-steering')
            x, y = state['globals']['endpoint'+point+'X'], state['globals']['endpoint'+point+'Y']
            state['boats'][2].update(positionX=float(x), positionY=y+radius)
            state['boats'][1].update(positionX=float(x), positionY=y+radius-20, heading=180)
            yield state
        for offset, flags, target_angle, start_distance, angle, elapsed, hold in itertools.product(
                [-15, -5, -3, -2, 0, 2, 3, 5, 10, 15, 25],
                ['none', 'board', 'catamaran', 'skiff'], [-15, -14, 14, 15],
                [199, 200], [55, 56], [10, 11], [0, 1]):
            # Pairwise sampling retains every numerical boundary while avoiding
            # a Cartesian duplication of branches with identical geometry.
            if (offset + target_angle + start_distance + angle + elapsed + hold) % 4: continue
            state = defaults(twoPlayerMode=1, closehauledOverride=hold)
            state['branch'] = 'port-projection-turn'
            if flags != 'none': state['globals'][flags+'Flag'] = 1
            state['boats'][2].update(tack=-1, relativeTargetAngle=target_angle,
                startDistance=start_distance, angleToWind=angle, lastTurnTime=100-elapsed,
                spinnakerHoldFlag=hold, trueWindDirection=180)
            state['boats'][1].update(tack=1, positionX=0.0, positionY=float(offset), trueWindDirection=0)
            yield state
        for tack, angle, other_angle, distance, time, course, x, y in itertools.product(
                [-1, 1], [55, 56, 90, 91, 150], [55, 56, 90, 91, 150],
                [4, 5, 9, 10, 14, 15], [29, 30, 99, 100], [1, 8], [0, 4], [-4, 4]):
            if (angle + other_angle + distance + time + x + y) % 16: continue
            state = defaults(time=time, course=course, twoPlayerMode=1)
            state.update(distance=distance, branch='overlap-downwind')
            state['boats'][2].update(tack=tack, angleToWind=angle)
            state['boats'][1].update(tack=tack if x == 0 else -tack,
                angleToWind=other_angle, positionX=float(x), positionY=float(y))
            yield state
    for _ in range(256):
        count = prng.choice([2, 3, 15, 30])
        boat = prng.randrange(1, count + 1)
        other = boat % count + 1
        time = prng.choice([-2, 0, 1, 2, 3, 4, 30, 31, 99, 100])
        state = defaults(boat, other, boatCount=count, humanBoatCount=prng.choice([1, 2]),
            time=time, startMode=prng.randrange(1, 5), twoPlayerMode=prng.randrange(2),
            boardFlag=prng.randrange(2), catamaranFlag=prng.randrange(2), skiffFlag=prng.randrange(2),
            course=prng.choice([1, 8]), closehauledOverride=prng.randrange(2),
            reversePenaltyFlag=prng.randrange(2), resetTime=time-prng.randrange(12),
            soundDisabled=prng.randrange(2))
        state.update(seed=prng.randrange(2**32), distance=prng.randrange(-1, 24),
                     turnMultiplier=prng.choice([-2, -1, 0, 1, 2]), branch='random-connected-state')
        for number in range(1, count + 1):
            state['boats'][number].update(positionX=prng.uniform(-100, 100), positionY=prng.uniform(-100, 100),
                collisionX=prng.randrange(-10, 11), collisionY=prng.randrange(-10, 11),
                heading=prng.randrange(362), tack=prng.choice([-1, 1]),
                trueWindDirection=prng.randrange(362), angleToWind=prng.randrange(181),
                lastTurnTime=time-prng.randrange(15), collisionTime=time-prng.randrange(8),
                startDistance=prng.choice([199, 200, 201]), relativeTargetAngle=prng.choice([-15, -14, 14, 15]),
                windInterference=prng.randrange(2), spinnakerHoldFlag=prng.randrange(2),
                speedTenths=prng.randrange(-100, 101))
        yield state


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit', type=int, help='Exploratory first N cases per routine')
    parser.add_argument('--emulated-only', action='store_true')
    args = parser.parse_args()
    if args.limit is not None and not args.emulated_only:
        raise ValueError('Exploratory limited captures require --emulated-only')
    vm = OriginalMachine()
    vm.call(0x415a60)
    stub = SCRATCH + 0x800
    vm.write_i32(0x4b1c18, stub)
    baseline = bytes(vm.uc.mem_read(0x400000, 0x111000))
    block_offset = BLOCK_ADDRESS - 0x400000
    baseline_block = baseline[block_offset:block_offset + BLOCK_SIZE]
    original_text = baseline[0x1000:0x81800]
    sounds, writes = [], []

    def sound(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<4I', uc.mem_read(esp, 16))
        sounds.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1)
        uc.reg_write(UC_X86_REG_ESP, esp + 16)
        uc.reg_write(UC_X86_REG_EIP, ret)

    def record_write(uc, access, address, size, value, data):
        if 0x400000 <= address and address + size <= 0x511000: writes.append((address, size))

    vm.uc.hook_add(UC_HOOK_CODE, sound, begin=stub, end=stub)
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, record_write)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18', 'sound_return': 1,
        'note': 'Complete original collision-avoidance routines; synthetic geometry is explicit, all mapped stores recorded, and .text is unchanged. Native original-code authority follows this preserved emulation capture.'},
        'mutableBlock': {'address': BLOCK_ADDRESS, 'size': BLOCK_SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    prng = random.Random(0x427fd0)
    for name, (address, kinds) in ROUTINES.items():
        records = []
        for index, state in enumerate(cases(name, prng)):
            if args.limit is not None and index >= args.limit: break
            vm.uc.mem_write(0x400000, baseline)
            for field, value in state['globals'].items(): vm.write_i32(GLOBALS[field][0], value)
            for boat, fields in state['boats'].items():
                for field, value in fields.items():
                    location, kind, stride = INDEXED[field]
                    raw = struct.pack('<d', value) if kind == 'F64' else struct.pack('<I', value & 0xffffffff)
                    vm.uc.mem_write(location + boat * stride, raw)
            argv = ([state['distance'], state['other'], state['boat'], state['turnMultiplier']]
                if name == 'avoidAiCollision' else [state['distance'], state['other'], state['boat']]
                if name == 'warnHumanRightOfWay' else [state['selector']]
                if name == 'requestRightOfWaySound' else [state['boat']])
            before = bytes(vm.uc.mem_read(BLOCK_ADDRESS, BLOCK_SIZE))
            vm.write_i32(TLS + 0x14, state['seed'])
            sounds.clear(); writes.clear()
            vm.call(address, arguments(*argv), count=3000000)
            after = bytes(vm.uc.mem_read(BLOCK_ADDRESS, BLOCK_SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text: raise AssertionError('Original .text changed')
            records.append({'branch': state['branch'], 'arguments': argv, 'seedAtCall': state['seed'],
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline_block, before)],
                'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': sounds.copy(),
                    'imageChanges': image_changes(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()},
                'imageWrites': [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)]})
        fixture['routines'][name] = {'address': address, 'argumentTypes': kinds, 'returnType': 'void', 'cases': records}
        print(name, len(records), flush=True)
    save(DESTINATION, fixture)

    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'),
            '--fixture', 'original-avoidance.json', '--report', str(ROOT/'analysis/avoidance-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__': main()
