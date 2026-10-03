#!/usr/bin/env python3
"""Capture fixed original 2002 encounter leaves, image stores, sound and RNG.

Only the listed original routines are executed. Independent cases restore a
synthetic image baseline and then supply all documented typed inputs. Original
.text is unchanged; TLS and the known PlaySoundA API use recorded substitutes.
"""
import hashlib
import itertools
import math
import random
import struct

import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, i32, save

IMAGE_BASE, IMAGE_SIZE = 0x400000, 0x111000
GLOBALS = {
    'boatCount': (0x49118c, 'I32'), 'humanBoatCount': (0x491140, 'I32'),
    'startMode': (0x4911cc, 'I32'), 'time': (0x4a5b80, 'I32'),
    'endpointAX': (0x4aa594, 'I32'), 'endpointAY': (0x4aa59c, 'I32'),
    'endpointBX': (0x4a70f8, 'I32'), 'endpointBY': (0x4a72c8, 'I32'),
    'endpointCX': (0x4aa294, 'I32'), 'endpointCY': (0x4aa388, 'I32'),
    'endpointDX': (0x4aa38c, 'I32'), 'endpointDY': (0x4aa588, 'I32'),
    'endpointEX': (0x4aa288, 'I32'), 'endpointEY': (0x4aa384, 'I32'),
    'relocationSpan': (0x4aa998, 'I32'), 'spawnX': (0x4a4be0, 'I32'),
    'spawnY': (0x4a4f84, 'I32'), 'soundDisabled': (0x4ac9c0, 'I32'),
    'moduleHandle': (0x4ac1d4, 'U32'), 'course': (0x491194, 'I32'),
    'reversePenaltyFlag': (0x4ac9a8, 'I32'), 'closehauledAngle': (0x4a4eb0, 'I32'),
}
INDEXED = {
    'raceStage': (0x4a5420, 'I32', 4), 'targetX': (0x4a4888, 'I32', 4),
    'targetY': (0x4a6f48, 'I32', 4), 'heading': (0x4ac018, 'I32', 4),
    'tack': (0x4aa730, 'I32', 4), 'trueWindDirection': (0x4aa5b0, 'I32', 4),
    'angleToWind': (0x4a7bc8, 'I32', 4), 'downwindLimit': (0x4a5f10, 'I32', 4),
    'positionX': (0x4a49e8, 'F64', 8), 'positionY': (0x4a4ae0, 'F64', 8),
}
ROUTINES = {
    'resetBoat': (0x421c40, ['I32'], 'residualEAX'),
    'relativeProjection': (0x428af0, ['I32', 'I32', 'I32'], 'I64'),
    'aheadAstern': (0x44da90, ['I32', 'I32'], 'I64'),
    'respawnNearStart': (0x42a8a0, ['I32'], 'residualEAX'),
    'shiftPenaltyPosition': (0x42a950, ['I32'], 'residualEAX'),
    'checkNearRaceMarks': (0x42abb0, ['I32', 'I32'], 'I32'),
    'signedStartDistance': (0x426f50, ['I32'], 'float10'),
}


def defaults(boat=1, other=2, **globals):
    state = {'boat': boat, 'otherBoat': other, 'seed': 2002,
             'globals': {'boatCount': 3, 'humanBoatCount': 1, 'startMode': 2, 'time': -31,
                         'endpointAX': -600, 'endpointAY': 0, 'endpointBX': 600, 'endpointBY': 0,
                         'endpointCX': 0, 'endpointCY': 1000, 'endpointDX': -600, 'endpointDY': 1000,
                         'endpointEX': 600, 'endpointEY': 1000, 'relocationSpan': 600,
                         'spawnX': 0, 'spawnY': -300, 'soundDisabled': 0, 'moduleHandle': 0x76543210,
                         'course': 1, 'reversePenaltyFlag': 0, 'closehauledAngle': 45},
             'boats': {str(boat): {'raceStage': 3, 'targetX': -731, 'targetY': 913, 'heading': 90,
                                  'tack': 1, 'trueWindDirection': 315, 'angleToWind': 70,
                                  'downwindLimit': 150, 'positionX': 25.25, 'positionY': -10.75},
                       str(other): {'raceStage': 7, 'targetX': 809, 'targetY': -127, 'heading': 270,
                                   'tack': -1, 'trueWindDirection': 90, 'angleToWind': 120,
                                   'downwindLimit': 145, 'positionX': 130.125, 'positionY': 25.75}}}
    state['globals'].update(globals)
    return state


def primary(state, **values):
    state['boats'][str(state['boat'])].update(values)
    return state


def cases_for(name, prng):
    if name == 'resetBoat':
        for count, boat, human, mode, time in itertools.product([1, 2, 3, 30], [0, 1, 2, 30], [0, 1, 2], range(5), [-31, -30, -29]):
            yield defaults(boat, 29 if boat == 30 else 30, boatCount=count, humanBoatCount=human, startMode=mode, time=time)
        for _ in range(128):
            state = defaults(prng.randrange(31), 31, boatCount=prng.randrange(1, 31), startMode=prng.randrange(5), time=prng.randrange(-100, 101))
            for key in ['endpointAX', 'endpointAY', 'endpointBX', 'endpointBY']:
                state['globals'][key] = prng.randrange(-2**31, 2**31)
            state['otherBoat'] = 30 if state['boat'] != 30 else 29
            state['boats'][str(state['otherBoat'])] = state['boats'].pop('31')
            yield state
    elif name == 'respawnNearStart':
        for span, seed, human, time in itertools.product([-601, -6, -1, 0, 1, 5, 6, 7, 60, 600, 6000], [0, 1, 2002, 0xffffffff], [0, 1, 30], [-169, -168, -167]):
            state = defaults(relocationSpan=span, humanBoatCount=human, time=time, soundDisabled=seed % 2, startMode=(span % 5))
            state['seed'] = seed
            yield state
        for _ in range(128):
            state = defaults(prng.randrange(31), 31, relocationSpan=prng.randrange(-10000, 10001), spawnX=prng.randrange(-2**31, 2**31), spawnY=prng.randrange(-2**31, 2**31), startMode=prng.randrange(5), time=prng.randrange(-200, 101), humanBoatCount=prng.randrange(3), soundDisabled=prng.randrange(2))
            state['seed'] = prng.randrange(2**32)
            state['otherBoat'] = 30 if state['boat'] != 30 else 29
            state['boats'][str(state['otherBoat'])] = state['boats'].pop('31')
            yield state
    elif name == 'shiftPenaltyPosition':
        for heading in range(362):
            for tack, reverse in itertools.product([-1, 1], [0, 1]):
                state = defaults(course=8, reversePenaltyFlag=reverse, time=-167)
                yield primary(state, heading=heading, tack=tack, angleToWind=[9, 10, 11][heading % 3])
        for tack, reverse, course, stage, angle, wind in itertools.product([-1, 1], [0, 1], [1, 8, 11], [0, 3, 4, 7, 8], [9, 10, 11], [-1, 0, 359]):
            state = defaults(course=course, reversePenaltyFlag=reverse, time=[-169, -168, -167][stage % 3], soundDisabled=stage % 2)
            yield primary(state, raceStage=stage, tack=tack, angleToWind=angle, trueWindDirection=wind)
    elif name in ('relativeProjection', 'aheadAstern'):
        for angle in range(362):
            for mode in ([0, 1] if name == 'relativeProjection' else [0]):
                state = defaults()
                state['mode'] = mode
                yield primary(state, heading=angle, trueWindDirection=angle, tack=-1 if angle % 2 else 1)
        positions = [0.0, -0.0, 99.99999999999999, 100.0, 100.00000000000001, 1e12, -1e12, float(2**53), -float(2**53)]
        for value in positions:
            for mode in ([0, 1, 2] if name == 'relativeProjection' else [0]):
                state = primary(defaults(), positionX=value, positionY=-value)
                state['mode'] = mode
                state['boats']['2'].update(positionX=value, positionY=-value)
                yield state
        for _ in range(256):
            state = defaults()
            state['mode'] = prng.randrange(3)
            for values in state['boats'].values():
                values.update(positionX=prng.uniform(-10000, 10000), positionY=prng.uniform(-10000, 10000), heading=prng.randrange(362), trueWindDirection=prng.randrange(362), tack=prng.choice([-1, 1]))
            yield state
    elif name == 'checkNearRaceMarks':
        marks = [(-600, 0), (600, 0), (0, 1000), (-600, 1000), (600, 1000)]
        for threshold, (x, y), offset, angle, time in itertools.product([-1, 0, 1, 2, 10, 99, 100, 101, 1000, -2**31, 2**31-1], marks, [-101, -100, -99, 0, 99, 100, 101], [19, 20, 21], [29, 30, 31]):
            state = primary(defaults(time=time), positionX=x + offset + 0.25, positionY=y - 0.25, angleToWind=angle)
            state['threshold'] = threshold
            yield state
        for _ in range(256):
            state = primary(defaults(time=prng.randrange(-30, 100)), positionX=prng.uniform(-10000, 10000), positionY=prng.uniform(-10000, 10000), angleToWind=prng.randrange(362))
            state['threshold'] = prng.randrange(-1000, 1001)
            yield state
    elif name == 'signedStartDistance':
        coordinates = [0.0, -0.0, -1000.0, 1000.0, math.nextafter(1000.0, -math.inf), math.nextafter(1000.0, math.inf), 1e-150, -1e-150, 1e150, -1e150, float(2**53), -float(2**53)]
        for x, y in itertools.product(coordinates, coordinates):
            yield primary(defaults(), positionX=x, positionY=y)
        for _ in range(256):
            state = primary(defaults(), positionX=prng.uniform(-10000, 10000), positionY=prng.uniform(-10000, 10000))
            for key in ['endpointAX', 'endpointAY', 'endpointBX', 'endpointBY', 'endpointCX', 'endpointCY']:
                state['globals'][key] = prng.randrange(-2**31, 2**31)
            yield state


def merged_ranges(writes):
    ranges = []
    for address, size in sorted(set(writes)):
        if ranges and address <= ranges[-1][1]:
            ranges[-1][1] = max(ranges[-1][1], address + size)
        else:
            ranges.append([address, address + size])
    return ranges


def changed_ranges(before, after, ranges):
    changes = []
    for start, end in ranges:
        index = start
        while index < end:
            if before[index - IMAGE_BASE] == after[index - IMAGE_BASE]:
                index += 1
                continue
            first = index
            while index < end and before[index - IMAGE_BASE] != after[index - IMAGE_BASE]:
                index += 1
            changes.append({'address': first, 'before': before[first-IMAGE_BASE:index-IMAGE_BASE].hex(), 'after': after[first-IMAGE_BASE:index-IMAGE_BASE].hex()})
    return changes


def write_native_schema(destination='native_encounter_schema.h', prefix='ENCOUNTER'):
    # Compile-time address tables for this fixed original and reviewed leaves.
    # Protocol clients provide values and routine IDs, never addresses.
    lines = ['/* Generated from capture_encounter_fixtures.py: fixed 2002 leaves. */',
             '#define ENCOUNTER_GLOBAL_COUNT %d' % len(GLOBALS),
             '#define ENCOUNTER_INDEXED_COUNT %d' % len(INDEXED),
             '#define ENCOUNTER_ROUTINE_COUNT %d' % len(ROUTINES),
             'static const uint32_t encounter_globals[ENCOUNTER_GLOBAL_COUNT] = {' + ','.join('0x%x' % value[0] for value in GLOBALS.values()) + '};',
             'static const uint32_t encounter_indexed[ENCOUNTER_INDEXED_COUNT] = {' + ','.join('0x%x' % value[0] for value in INDEXED.values()) + '};',
             'static const uint8_t encounter_widths[ENCOUNTER_INDEXED_COUNT] = {' + ','.join(str(value[2]) for value in INDEXED.values()) + '};',
             'static const uintptr_t encounter_routines[ENCOUNTER_ROUTINE_COUNT] = {' + ','.join('0x%x' % value[0] for value in ROUTINES.values()) + '};',
             'static const uint8_t encounter_argument_counts[ENCOUNTER_ROUTINE_COUNT] = {' + ','.join(str(len(value[1])) for value in ROUTINES.values()) + '};',
             '/* 0=I32/residual EAX, 1=I64 EDX:EAX, 2=ST0 m80, 3=void */',
             'static const uint8_t encounter_return_kinds[ENCOUNTER_ROUTINE_COUNT] = {' + ','.join(str({'I64': 1, 'float10': 2, 'void': 3}.get(value[2], 0)) for value in ROUTINES.values()) + '};']
    contents='\n'.join(lines).replace('ENCOUNTER',prefix).replace('encounter_',prefix.lower()+'_')+'\n'
    (ROOT / 'tools' / destination).write_text(contents)


def main(destination='original-encounter-leaves.json', schema_destination='native_encounter_schema.h', schema_prefix='ENCOUNTER'):
    vm = OriginalMachine()
    vm.call(0x415a60)
    stub = SCRATCH + 0x800
    vm.write_i32(0x4b1c18, stub)
    baseline = bytes(vm.uc.mem_read(IMAGE_BASE, IMAGE_SIZE))
    original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    writes, sounds, executed = [], [], {}

    def record_write(uc, access, address, size, value, data):
        if IMAGE_BASE <= address and address + size <= IMAGE_BASE + IMAGE_SIZE:
            writes.append((address, size))

    def record_sound(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<4I', uc.mem_read(esp, 16))
        sounds.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1)
        uc.reg_write(UC_X86_REG_ESP, esp + 16)
        uc.reg_write(UC_X86_REG_EIP, ret)

    def record_instruction(uc, address, size, data):
        if 0x401000 <= address < 0x481800:
            executed[address] = size

    vm.uc.hook_add(UC_HOOK_MEM_WRITE, record_write)
    vm.uc.hook_add(UC_HOOK_CODE, record_sound, begin=stub, end=stub)
    vm.uc.hook_add(UC_HOOK_CODE, record_instruction)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__, 'x87_control_word': '0x037f', 'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18', 'sound_return': 1, 'note': 'Finite isolated leaf and connected call cases with explicit synthetic course/boat data; not complete race parity. Original .text is checked unchanged for every call.'},
               'globals': {name: {'address': address, 'type': kind} for name, (address, kind) in GLOBALS.items()},
               'indexed': {name: {'address': address, 'type': kind, 'stride': stride} for name, (address, kind, stride) in INDEXED.items()}, 'routines': {}}
    prng = random.Random(0x428af0)
    for name, (address, argument_types, return_type) in ROUTINES.items():
        records = []
        observed = []
        executed.clear()
        for state in cases_for(name, prng):
            vm.uc.mem_write(IMAGE_BASE, baseline)
            for field, value in state['globals'].items():
                vm.write_i32(GLOBALS[field][0], value)
            for boat, values in state['boats'].items():
                for field, value in values.items():
                    base, kind, stride = INDEXED[field]
                    vm.uc.mem_write(base + int(boat) * stride, struct.pack('<d', value)) if kind == 'F64' else vm.write_i32(base + int(boat) * stride, value)
            vm.write_i32(TLS + 0x14, state['seed'])
            argv = [state['boat']]
            if name == 'relativeProjection': argv += [state.get('mode', 0), state['otherBoat']]
            if name == 'aheadAstern': argv += [state['otherBoat']]
            if name == 'checkNearRaceMarks': argv = [state['threshold'], state['boat']]
            if name == 'collisionPenalty': argv = [state['otherBoat'], state['boat'], state['distance']]
            before = bytes(vm.uc.mem_read(IMAGE_BASE, IMAGE_SIZE))
            writes.clear(); sounds.clear()
            returned = vm.call(address, arguments(*argv), floating='extended' if return_type == 'float10' else False)
            ranges = merged_ranges(writes)
            after = bytes(vm.uc.mem_read(IMAGE_BASE, IMAGE_SIZE))
            if after[0x1000:0x81800] != original_text:
                raise AssertionError('Original .text changed in ' + name)
            expected = {'globals': {field: (vm.read_u32(location) if kind == 'U32' else vm.read_i32(location)) for field, (location, kind) in GLOBALS.items()},
                        'boats': {}, 'rngState': vm.read_u32(TLS + 0x14), 'sounds': sounds.copy(), 'imageChanges': changed_ranges(before, after, ranges)}
            for boat in state['boats']:
                result = {}
                for field, (base, kind, stride) in INDEXED.items():
                    raw = bytes(vm.uc.mem_read(base + int(boat) * stride, stride))
                    if kind == 'F64': result[field] = struct.unpack('<d', raw)[0]; result[field + 'Bits'] = raw.hex()
                    else: result[field] = struct.unpack('<i', raw)[0]
                expected['boats'][boat] = result
            if return_type == 'float10':
                expected.update(returnValue=returned['value'], returnBits=returned['bits'], returnExtendedBits=returned['extendedBits'])
            elif return_type != 'void':
                expected['returnValue'] = i32(returned)
                if return_type == 'I64':
                    high = vm.uc.reg_read(UC_X86_REG_EDX)
                    signed64 = (high << 32) | returned
                    if signed64 >= 2**63: signed64 -= 2**64
                    expected.update(returnHigh=i32(high), returnSigned64=str(signed64))
            observed.extend(writes)
            records.append({**state, 'arguments': argv, 'expected': expected, 'imageWrites': [{'address': start, 'size': end-start} for start, end in ranges]})
        fixture['routines'][name] = {'address': address, 'argumentTypes': argument_types, 'returnType': return_type, 'cases': records, 'observedWriteRanges': [{'address': start, 'size': end-start} for start, end in merged_ranges(observed)], 'observedInstructionRanges': [{'address': start, 'size': end-start} for start, end in merged_ranges(executed.items())]}
        print(name + ': ' + str(len(records)) + ' unchanged-code cases', flush=True)
    save(ROOT / 'tests/fixtures' / destination, fixture)
    write_native_schema(schema_destination, schema_prefix)


if __name__ == '__main__':
    main()
