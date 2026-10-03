#!/usr/bin/env python3
"""Capture unchanged original crew geometry with explicit mutable-state inputs.

These are finite geometry/pose cases, with no GDI or original app lifecycle.
Native original-code comparison is required before treating CPU-emulated
floating-point output as authoritative. No expected result comes from JS.
"""
import argparse
import hashlib
import itertools
import math
import struct
import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, i32, save
from capture_encounter_fixtures import merged_ranges
from capture_initialization_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000
ROUTINES = {
    'crewPositionFactor': (0x4139d0, ['I32'], 'Float80'),
    'writeCrewGeometry': (0x413a20, ['F64'] * 4 + ['I32'] * 5, 'void'),
    'initializeCrewGeometry': (0x413370, ['F64', 'I32', 'I32'], 'void'),
}


def integer(address, value):
    return {'address': address, 'type': 'I32', 'value': value}


def number(address, value):
    return {'address': address, 'type': 'F64', 'value': value}


def indexed(base, boat):
    return (base + boat * 4) & 0xffffffff


def cases(name):
    if name == 'crewPositionFactor':
        for pose in range(-2, 3):
            yield {'seed': 2002, 'arguments': [pose], 'inputs': []}
    elif name == 'writeCrewGeometry':
        coordinates = [(0., -0., 0., -0.), (500.125, -70.25, 1.3, 2.7),
            (math.nextafter(500.125, math.inf), math.nextafter(-70.25, -math.inf), 17.3, -2.7),
            (2.**53, -(2.**53), 17.3, 11.25),
            (2.**-500, -(2.**-500), 2.**-500, 2.**-500),
            (-123.125, 999.75, -17.3, math.nextafter(0.6, math.inf))]
        for ordinal, (index, boat_class, pose, tack, board) in enumerate(itertools.product(
                [0, 1, 39, 45, 51], [1, 5, 6, 7], range(-2, 3), [-1, 1], [0, 1])):
            boat = [1, 2, 30, -1, -0x80000000, 0x7fffffff][ordinal % 6]
            screen_y = [99, 100, 101, -0x80000000, 0x7fffffff][ordinal % 5]
            movement = [79, 80, -0x80000000, 0x7fffffff][(ordinal // 3) % 4]
            drift = [-0., 0., 1.99, 2., -2.99, 4294967295.75][(ordinal // 7) % 6]
            if ordinal % 17 == 0:
                tack = -0x80000000
            x, y, height, width = coordinates[(ordinal // 5) % len(coordinates)]
            yield {'seed': 2002, 'arguments': [x, y, height, width, index, boat, 1 + ordinal % 3, screen_y, pose],
                'inputs': [integer(0x491188, boat_class), integer(0x4ac904, board),
                    integer(indexed(0x4aa730, boat), tack), integer(indexed(0x4a8aa8, boat), movement),
                    integer(0x4a7354, 100), number(0x4abef0, drift),
                    number(0x4ac310, [-0., 91.5, 2.**53][ordinal % 3])]}
    else:
        for ordinal, (boat_class, catamaran, boat, tack, phase) in enumerate(itertools.product(
                range(1, 11), [0, 1], [1, 2], [-1, 1], range(4))):
            time, crew_time, last_turn, duration = [(199, 200, 195, 20),
                (200, 200, 199, 10), (209, 200, 199, 10),
                (0x7fffffff, -0x80000000, 0x7fffffff - 9, 20)][phase]
            width = [0., 2.7, -2.7, math.nextafter(17.3, math.inf)][(ordinal // 4) % 4]
            inputs = [integer(0x491188, boat_class), integer(0x4ac900, catamaran),
                integer(0x491140, 1 + phase % 2), integer(0x4ac928, int(phase == 3)),
                integer(0x49114c, ordinal % 2), integer(0x4ac90c, int(boat_class == 6 and phase == 0)),
                integer(0x4ac904, phase % 2), integer(0x4a5b80, time), integer(0x4ac9d4, duration),
                integer(indexed(0x4a3a18, boat), crew_time), integer(indexed(0x4a41f0, boat), last_turn),
                integer(indexed(0x4a6ec8, boat), [0, 4, 5, 6, 7, 10, 22, 23][(ordinal // 2) % 8]),
                integer(indexed(0x4a7bc8, boat), 120 + ordinal % 2),
                integer(indexed(0x4aa730, boat), tack), integer(indexed(0x4a8aa8, boat), 79 + phase % 2),
                integer(0x4a7354, 100), number(0x4abef0, [-2.99, 2., 3.99, 0.][phase]),
                number(0x4a3a38, 200.5), number(0x4ac338, 500.125)]
            yield {'seed': 2002, 'arguments': [width, boat, [99, 100, 101, 500][phase]],
                   'inputs': inputs, 'prepareOriginal': [{'address': 0x413100,
                       'arguments': [17.3, width], 'argumentTypes': ['F64', 'F64']}]}


def argument_bytes(values, kinds):
    return b''.join(struct.pack('<d', value) if kind == 'F64' else
                    struct.pack('<I', value & 0xffffffff) for value, kind in zip(values, kinds))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true', help='Capture CPU-emulated evidence only; skip native authority')
    args = parser.parse_args()
    vm = OriginalMachine(); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    writes = []
    def write(uc, access, address, size, value, data):
        if BASE <= address and address + size <= BASE + SIZE:
            writes.append((address, size))
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, write)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'tls_accessor_stub': '00459ed0',
        'note': 'Finite original crew geometry and valid five-position selector domain. Flat hull original preparation is recorded as raw input. No renderer/GDI/app lifecycle, no JS oracle; pending native original-code authority.'},
        'mutableBlock': {'address': BASE, 'size': SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    def apply(inputs):
        for row in inputs:
            vm.uc.mem_write(row['address'], struct.pack('<d', row['value']) if row['type'] == 'F64'
                            else struct.pack('<I', row['value'] & 0xffffffff))
    for name, (address, kinds, return_type) in ROUTINES.items():
        records = []
        for case in cases(name):
            vm.uc.mem_write(BASE, baseline); apply(case['inputs'])
            vm.write_i32(TLS + 0x14, case['seed'])
            for preparation in case.get('prepareOriginal', []):
                vm.call(preparation['address'], argument_bytes(preparation['arguments'], preparation['argumentTypes']))
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            case['seedAtCall'] = vm.read_u32(TLS + 0x14)
            case['imageInputs'] = [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)]
            writes.clear()
            result = vm.call(address, argument_bytes(case['arguments'], kinds), floating='extended' if return_type == 'Float80' else False)
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text:
                raise AssertionError('Original text changed')
            expected = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [],
                'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()}
            if return_type == 'Float80':
                expected.update(returnValue=result['value'], returnBits=result['bits'], returnExtendedBits=result['extendedBits'])
            else:
                expected['residualEAX'] = i32(result)
            case['expected'] = expected
            case['imageWrites'] = [{'address': start, 'size': end - start} for start, end in merged_ranges(writes)]
            records.append(case)
        fixture['routines'][name] = {'address': address, 'argumentTypes': kinds,
            'returnType': return_type, 'cases': records}
        print(name, len(records), flush=True)
    save(ROOT / 'tests/fixtures/original-crew-geometry.json', fixture)
    if not args.emulated_only:
        subprocess.run([sys.executable, str(ROOT / 'tools/verify_native_state.py'),
            '--fixture', 'original-crew-geometry.json', '--report',
            str(ROOT / 'analysis/crew-geometry-native-reference-comparison.json'), '--update-fixture'], check=True)


if __name__ == '__main__': main()
