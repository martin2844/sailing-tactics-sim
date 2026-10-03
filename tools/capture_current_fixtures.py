#!/usr/bin/env python3
"""Bounded original-instruction fixtures for spatial depth and tidal currents.

The shoreline/radial arrays below are explicitly synthetic test inputs, not a
claim to have recovered the original course geometry initializer.
"""
import math
import random
import struct
import unicorn
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, arguments, i32, save

INPUTS = {
    'refreshFlag': 0x4a60a0, 'resetTime': 0x4a4168, 'time': 0x4a5b80,
    'spatialVariant': 0x4a864c, 'tidePhaseHour': 0x4a8020, 'tideOffsetHours': 0x4ac94c,
    'hour': 0x4a4be4, 'tideAmplitude': 0x4ac1dc, 'islandFlag': 0x4a5a4c,
    'centerX': 0x4ac284, 'centerY': 0x4a3a08, 'weather': 0x4a4958,
    'currentBaseDirection': 0x4aae1c, 'course': 0x491194, 'shore': 0x4aa804,
    'shoreY': 0x4aa290, 'placementMode': 0x4ac85c, 'branchDirection1': 0x4a67bc,
    'branchDirection2': 0x4a67c4, 'centerDirection': 0x4a67c0,
    'tideCycleFlag': 0x491158, 'reversal': 0x4a4378, 'radius': 0x4abae8,
    'windDirection': 0x4ac840, 'globalTide': 0x4aa298,
    'rawCurrent': 0x4aa800, 'currentEffect': 0x4aa720, 'currentDirection': 0x4aa960,
    'shoreDirection': 0x4aa284, 'oppositeShoreDirection': 0x4a71a8,
}
DOUBLES = {'axisScaleX': 0x4a6470, 'axisScaleY': 0x4abe60}
OUTPUTS = {field: INPUTS[field] for field in
           ['rawCurrent', 'currentEffect', 'currentDirection', 'shoreDirection', 'oppositeShoreDirection']}
INDEXED = {'cachedMetric': 0x4a7f28, 'currentStrength': 0x4ac208, 'previousStrength': 0x4a4778}


def defaults(**overrides):
    result = {'refreshFlag': 1, 'resetTime': 0, 'time': 11, 'spatialVariant': 0,
        'tidePhaseHour': 7, 'tideOffsetHours': 0, 'hour': 12, 'tideAmplitude': 10,
        'islandFlag': 0, 'centerX': 0, 'centerY': 0, 'weather': 0,
        'currentBaseDirection': 270, 'course': 2, 'shore': 1, 'shoreY': 600,
        'placementMode': 1, 'branchDirection1': 90, 'branchDirection2': 270,
        'centerDirection': 180, 'tideCycleFlag': 1, 'reversal': 0, 'radius': 900,
        'windDirection': 315, 'globalTide': 5, 'rawCurrent': -333,
        'currentEffect': 7, 'currentDirection': 123, 'shoreDirection': 234,
        'oppositeShoreDirection': 345}
    result.update(overrides)
    return result


def prepare(vm, record):
    for field, value in record['inputs'].items():
        vm.write_i32(INPUTS[field], value)
    for field, value in record['doubleInputs'].items():
        vm.uc.mem_write(DOUBLES[field], struct.pack('<d', value))
    boat = record['boat']
    vm.uc.mem_write(INDEXED['cachedMetric'] + boat * 8, struct.pack('<d', record['cachedMetric']))
    vm.write_i32(INDEXED['currentStrength'] + boat * 4, record['currentStrength'])
    vm.write_i32(INDEXED['previousStrength'] + boat * 4, record['previousStrength'])


def state(vm, boat):
    result = {field: vm.read_i32(address) for field, address in OUTPUTS.items()}
    for field in ['currentStrength', 'previousStrength']:
        result[field] = vm.read_i32(INDEXED[field] + boat * 4)
    raw = bytes(vm.uc.mem_read(INDEXED['cachedMetric'] + boat * 8, 8))
    result.update(cachedMetric=struct.unpack('<d', raw)[0], cachedMetricBits=raw.hex())
    return result


def main():
    vm = OriginalMachine()
    vm.call(0x415a60)
    prng = random.Random(421560)
    shoreline_x = [-1500 + 250 * index for index in range(64)]
    shoreline_y = [500 + int(120 * math.sin(index / 4)) for index in range(64)]
    radial = [750 + 125 * math.sin(index / 13) for index in range(181)]
    for base, values, fmt in [(0x4a6490, shoreline_x, '<i'), (0x4a68c8, shoreline_y, '<i'),
                              (0x4a8028, radial, '<d')]:
        stride = struct.calcsize(fmt)
        for index, value in enumerate(values):
            vm.uc.mem_write(base + index * stride, struct.pack(fmt, value))
    xs = [-601, -600, -599, -151, -150, -149, 0, 1, 600]
    ys = [-1001, -1000, -999, -601, -600, -599, -401, -400, -399, 0, 600, 601, 1000, 1001]
    configurations = []
    for weather in range(-1, 8):
        for x in xs:
            for y in ys:
                n = len(configurations)
                configurations.append({'x': x, 'y': y, 'boat': n % 3,
                    'inputs': defaults(weather=weather, spatialVariant=n % 2, islandFlag=(n // 2) % 2,
                        course=[1, 2, 4][n % 3], time=[9, 10, 11][n % 3],
                        placementMode=(n % 3) + 1, tideCycleFlag=(n // 3) % 2,
                        globalTide=5 if n % 2 else -5, tideAmplitude=10 if n % 4 else -10),
                    'doubleInputs': {'axisScaleX': 1.25, 'axisScaleY': 0.875},
                    'cachedMetric': [4, 30, 70, 90][n % 4], 'currentStrength': -17, 'previousStrength': 23})
    for depth in [-1, 0, 4.999999999999999, 5, 29.999999999999996, 30,
                  49.99999999999999, 50, 69.99999999999999, 70, 79.99999999999999,
                  80, 80.99999999999999, 81, 89.99999999999999, 90]:
        for weather in range(-1, 8):
            for course in [1, 2, 4]:
                for island in [0, 1]:
                    n = len(configurations)
                    configurations.append({'x': xs[n % len(xs)], 'y': ys[n % len(ys)], 'boat': 1 + n % 3,
                        'inputs': defaults(weather=weather, course=course, islandFlag=island,
                            tidePhaseHour=[0, 12, 24][n % 3], tideAmplitude=[-10, 0, 10][n % 3],
                            tideCycleFlag=n % 2, placementMode=(n % 3) + 1),
                        'doubleInputs': {'axisScaleX': 1.0, 'axisScaleY': 1.0},
                        'cachedMetric': depth, 'currentStrength': -21, 'previousStrength': 21})
    for _ in range(512):
        configurations.append({'x': prng.randrange(-1200, 1201), 'y': prng.randrange(-1200, 1201),
            'boat': prng.randrange(4), 'inputs': defaults(refreshFlag=prng.randrange(2),
                weather=prng.randrange(8), spatialVariant=prng.randrange(2),
                time=prng.choice([9, 10, 11, 60]), islandFlag=prng.randrange(2),
                course=prng.choice([1, 2, 4, 8]), tidePhaseHour=prng.randrange(25),
                hour=prng.randrange(25), tideOffsetHours=prng.randrange(-3, 4),
                tideAmplitude=prng.randrange(-20, 21), currentBaseDirection=prng.randrange(361),
                shore=prng.randrange(4), placementMode=prng.randrange(1, 4),
                tideCycleFlag=prng.randrange(2), reversal=prng.randrange(2),
                radius=prng.randrange(400, 1001), globalTide=prng.randrange(-20, 21)),
            'doubleInputs': {'axisScaleX': prng.uniform(0.5, 2), 'axisScaleY': prng.uniform(0.5, 2)},
            'cachedMetric': prng.uniform(-10, 110), 'currentStrength': prng.randrange(-30, 31),
            'previousStrength': prng.randrange(-30, 31)})
    cases = []
    for record in configurations:
        prepare(vm, record)
        result = vm.call(0x421560, arguments(record['x'], record['y'], record['boat']))
        expected = state(vm, record['boat'])
        expected['returnValue'] = i32(result)
        cases.append({**record, 'expected': expected})
    helpers = {}
    for name, address, floating in [('shorelineMetric', 0x420b70, True),
        ('ellipticalMetric', 0x420c40, True), ('radialMetric', 0x420d10, True),
        ('shoreDirections', 0x421ae0, False), ('attenuationDistance', 0x421b80, False)]:
        records = []
        for n, source in enumerate(configurations[:96] + configurations[-160:]):
            record = {**source, 'inputs': {**source['inputs']}}
            prepare(vm, record)
            if name == 'shoreDirections':
                args = arguments(record['x'], record['y'])
            elif name == 'attenuationDistance':
                record['selector'] = n % 2
                args = arguments(record['selector'], record['x'], record['y'])
            else:
                args = arguments(record['x'], record['y'], record['boat'])
            result = vm.call(address, args, floating='extended' if floating else False)
            expected = state(vm, record['boat'])
            if floating:
                expected.update(returnValue=result['value'], returnBits=result['bits'],
                                returnExtendedBits=result['extendedBits'])
            else:
                expected['returnValue'] = i32(result)
            records.append({**record, 'expected': expected})
        helpers[name] = {'address': address, 'cases': records}
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f',
        'note': 'Original function instructions with explicitly synthetic shoreline/radial test geometry; not a recovered course or full-game parity proof.'}
    save(ROOT / 'tests/fixtures/original-current.json', {'provenance': provenance,
        'inputs': INPUTS, 'doubleInputs': DOUBLES, 'outputs': OUTPUTS, 'indexed': INDEXED,
        'geometry': {'shorelineX': {'address': 0x4a6490, 'values': shoreline_x},
                     'shorelineY': {'address': 0x4a68c8, 'values': shoreline_y},
                     'radialBoundary': {'address': 0x4a8028, 'values': radial}},
        'cases': cases, 'helpers': helpers})
    print(f'Captured {len(cases)} full current cases and {sum(len(value["cases"]) for value in helpers.values())} helper cases')


if __name__ == '__main__':
    main()
