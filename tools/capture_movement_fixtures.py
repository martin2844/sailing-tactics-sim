#!/usr/bin/env python3
"""Capture two unchanged Posey movement helpers, using finite bounded inputs.

The numerical reference executes original .text and original constants. The
only substituted function is the original CRT TLS accessor, as documented by
OriginalMachine. These cases do not execute the movement coordinator or race.
"""
import math
import random
import struct
import hashlib

import unicorn
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
from capture_original_fixtures import (
    OriginalMachine, ROOT, EXPECTED, TLS, arguments, i32, save,
)

IMAGE_BASE = 0x400000
IMAGE_SIZE = 0x111000
INPUTS = {
    'boatCount': 0x49118c, 'secondBoatDelay': 0x491168, 'time': 0x4a5b80,
    'difficulty': 0x491190, 'course': 0x491194, 'islandFlag': 0x4a5a4c,
}
DOUBLES = {'raceTime': 0x4ac1f8, 'timeFactor': 0x4ab0c0}
INDEXED = {
    'positionX': {'address': 0x4a49e8, 'type': 'F64', 'stride': 8},
    'positionY': {'address': 0x4a4ae0, 'type': 'F64', 'stride': 8},
    'targetX': {'address': 0x4a4888, 'type': 'I32', 'stride': 4},
    'targetY': {'address': 0x4a6f48, 'type': 'I32', 'stride': 4},
    'rateCoefficient': {'address': 0x4a6e48, 'type': 'I32', 'stride': 4},
    'interference': {'address': 0x4a7868, 'type': 'I32', 'stride': 4},
}


def f64_bits(value):
    return struct.pack('<d', value).hex()


def image_digest(vm):
    return hashlib.sha256(vm.uc.mem_read(IMAGE_BASE, IMAGE_SIZE)).hexdigest()


def write_indexed(vm, boat, fields):
    for field, value in fields.items():
        spec = INDEXED[field]
        address = spec['address'] + boat * spec['stride']
        if spec['type'] == 'F64':
            vm.uc.mem_write(address, struct.pack('<d', value))
        else:
            vm.write_i32(address, value)


def defaults(**overrides):
    result = {'boat': 1, 'seed': 2002,
        'inputs': {'boatCount': 3, 'secondBoatDelay': 20, 'time': 20,
                   'difficulty': 7, 'course': 1, 'islandFlag': 0},
        'doubleInputs': {'raceTime': -30.0, 'timeFactor': 0.8},
        'indexedInputs': {'positionX': 25.25, 'positionY': -10.75,
                          'targetX': 200, 'targetY': -80,
                          'rateCoefficient': 100, 'interference': 0}}
    for key, value in overrides.items():
        if key in ['inputs', 'doubleInputs', 'indexedInputs']:
            result[key].update(value)
        else:
            result[key] = value
    return result


def main():
    vm = OriginalMachine()
    snapshots = {}

    def capture_spill(uc, address, size, user_data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        name = {0x428ad2: 'deltaXStoredBits', 0x42a415: 'deltaXStoredBits',
                0x42a427: 'squaredTotalStoredBits'}[address]
        snapshots[name] = bytes(uc.mem_read(esp + 8, 8)).hex()

    for address in [0x428ad2, 0x42a415, 0x42a427]:
        vm.uc.hook_add(UC_HOOK_CODE, capture_spill, begin=address, end=address)
    prng = random.Random(0x428ab0)
    distances = []
    values = [0.0, -0.0, 1.0, -1.0, math.nextafter(1.0, 0.0),
              math.nextafter(1.0, math.inf), 1e-150, -1e-150,
              1e150, -1e150, 2.0 ** 53, -(2.0 ** 53),
              math.nextafter(2.0 ** 53, math.inf)]
    for position_x in values:
        for x in values:
            n = len(distances)
            distances.append({'boat': n % 31, 'x': x, 'y': values[(n + 3) % len(values)],
                              'positionX': position_x, 'positionY': values[(n + 7) % len(values)]})
    for x, y in [(0.0, -0.0), (1.0, -1.0), (math.nextafter(1.0, math.inf), 1e-150),
                 (1e150, -1e150), (2.0 ** 53, -2.0 ** 53)]:
        distances.append({'boat': 2, 'x': x, 'y': y, 'positionX': x, 'positionY': y})
    for _ in range(512):
        exponent = prng.choice([-490, -100, -1, 0, 10, 52, 100, 490])
        x = math.ldexp(prng.uniform(-1, 1), exponent)
        y = math.ldexp(prng.uniform(-1, 1), exponent)
        distances.append({'boat': prng.randrange(31), 'x': x, 'y': y,
            'positionX': math.nextafter(x, prng.choice([-math.inf, math.inf])) if prng.randrange(2) else -x / 2,
            'positionY': math.nextafter(y, prng.choice([-math.inf, math.inf])) if prng.randrange(2) else -y / 3})
    distance_cases = []
    for record in distances:
        write_indexed(vm, record['boat'], {field: record[field] for field in ['positionX', 'positionY']})
        before = image_digest(vm)
        snapshots.clear()
        args = arguments(record['boat']) + struct.pack('<dd', record['x'], record['y'])
        result = vm.call(0x428ab0, args, floating='extended')
        unchanged = image_digest(vm) == before
        if not unchanged:
            raise AssertionError('Original distance helper wrote image bytes')
        distance_cases.append({**record,
            'inputBits': {field: f64_bits(record[field]) for field in ['x', 'y', 'positionX', 'positionY']},
            'nativeSpills': dict(snapshots),
            'expected': {'returnValue': result['value'], 'returnBits': result['bits'],
                         'returnExtendedBits': result['extendedBits'], 'imageUnchanged': unchanged}})

    configurations = []
    for count in [1, 2, 3, 4]:
        for boat in [0, 1, 2, 30]:
            for time in [19, 20, 21]:
                for difficulty in [1, 2, 12, 13]:
                    configurations.append(defaults(boat=boat,
                        inputs={'boatCount': count, 'time': time, 'difficulty': difficulty}))
    for difficulty in [-2147483648, -2147483647, -100, -10, -1, 0, 1, 2, 3, 12, 13, 2147483647]:
        for course, island in [(1, 0), (8, 0), (8, 1)]:
            for seed in [0, 1, 2002, 0xffffffff]:
                configurations.append(defaults(seed=seed,
                    inputs={'difficulty': difficulty, 'course': course, 'islandFlag': island}))
    for coefficient in [-2147483648, -1, 0, 59, 60, 61, 100, 2147483647]:
        for interference in [-1, 0, 1, 2]:
            for race_time in [-100.0, -1.0, -0.0, 0.0, 1.0, 100.0]:
                configurations.append(defaults(indexedInputs={'rateCoefficient': coefficient, 'interference': interference},
                                              doubleInputs={'raceTime': race_time}))
    for target in [0, 1, -1, 200, 2147483647, -2147483648]:
        for x in [float(target), math.nextafter(float(target), -math.inf),
                  math.nextafter(float(target), math.inf), float(target) + 40,
                  float(target) + 60, float(target) + 100, 2.0 ** 53, -(2.0 ** 53)]:
            for count in [1, 3]:
                configurations.append(defaults(inputs={'boatCount': count},
                    indexedInputs={'targetX': target, 'targetY': target, 'positionX': x, 'positionY': float(target)}))
    for factor in [math.nextafter(0.8, 0.0), 0.8, math.nextafter(0.8, math.inf), 0.25, 2.0, -0.25]:
        for position_x in [0.0, -0.0, 9.999999999999998, 10.0, 10.000000000000002, 99.99999999999999, 100.0]:
            configurations.append(defaults(doubleInputs={'timeFactor': factor},
                indexedInputs={'targetX': 100, 'targetY': 0, 'positionX': position_x, 'positionY': 0.0}))
    for _ in range(512):
        configurations.append(defaults(boat=prng.randrange(31), seed=prng.randrange(2 ** 32),
            inputs={'boatCount': prng.randrange(1, 5), 'time': prng.randrange(-30, 31),
                    'secondBoatDelay': prng.randrange(-30, 31),
                    'difficulty': prng.choice([-2147483648, -50, -1, 0, 1, 2, 3, 12, 13, 30, 2147483647]),
                    'course': prng.choice([1, 8, 11]), 'islandFlag': prng.randrange(2)},
            doubleInputs={'raceTime': prng.uniform(-120, 120), 'timeFactor': prng.uniform(0.2, 2)},
            indexedInputs={'targetX': prng.randrange(-10000, 10001), 'targetY': prng.randrange(-10000, 10001),
                           'positionX': prng.uniform(-10000, 10000), 'positionY': prng.uniform(-10000, 10000),
                           'rateCoefficient': prng.randrange(-10, 251), 'interference': prng.randrange(-1, 3)}))
    prestart_cases = []
    for record in configurations:
        for field, value in record['inputs'].items():
            vm.write_i32(INPUTS[field], value)
        for field, value in record['doubleInputs'].items():
            vm.uc.mem_write(DOUBLES[field], struct.pack('<d', value))
        write_indexed(vm, record['boat'], record['indexedInputs'])
        vm.write_i32(TLS + 0x14, record['seed'])
        before = image_digest(vm)
        snapshots.clear()
        result = vm.call(0x42a3b0, arguments(record['boat']))
        unchanged = image_digest(vm) == before
        if not unchanged:
            raise AssertionError('Original prestart helper wrote image bytes')
        prestart_cases.append({**record,
            'doubleInputBits': {field: f64_bits(value) for field, value in record['doubleInputs'].items()},
            'indexedInputBits': {field: f64_bits(record['indexedInputs'][field]) for field in ['positionX', 'positionY']},
            'nativeSpills': dict(snapshots),
            'expected': {'returnValue': i32(result), 'rngState': vm.read_u32(TLS + 0x14), 'imageUnchanged': unchanged}})
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'tls_accessor_stub': '0x459ed0',
        'note': 'Finite targeted outputs from unchanged original instructions; synthetic position/target inputs, not a complete movement or full-game parity proof. Every original call leaves all mapped image bytes unchanged.',
        'floating_spills': {'distanceToBoat': ['0x428ace X binary64 spill without pop'],
                            'prestartSpeedPercent': ['0x42a411 X binary64 spill without pop', '0x42a423 squared total binary64 spill before sqrt']}}
    data = {'provenance': provenance, 'inputs': INPUTS, 'doubleInputs': DOUBLES, 'indexed': INDEXED,
        'distanceToBoat': {'address': 0x428ab0, 'cases': distance_cases},
        'prestartSpeedPercent': {'address': 0x42a3b0, 'cases': prestart_cases}}
    save(ROOT / 'tests/fixtures/original-movement-helpers.json', data)
    print(f'Captured {len(distance_cases)} distances with m80/F64 returns and {len(prestart_cases)} prestart EAX/RNG cases; all mapped image bytes unchanged')


if __name__ == '__main__':
    main()
