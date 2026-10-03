#!/usr/bin/env python3
"""Capture complete unchanged-original sail geometry, including every store.

Prepared flat-hull bytes and finite synthetic sail states are explicit inputs.
Unicorn FSIN results are provisional until unchanged native-code verification.
"""
import argparse
import hashlib
import itertools
import math

import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, save
from capture_crew_fixtures import integer, number, indexed, argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000
KINDS = ['F64', 'I32', 'I32', 'I32', 'I32', 'F64']


def cases():
    for ordinal, (boat_class, boat, tack, curvature, heading, board) in enumerate(itertools.product(
            range(1, 11), [1, 2], [-1, 1], [0, 15, 31], [-180, -10, 11, 180], [0, 1])):
        height = [0.1, 17.3, math.nextafter(17.3, math.inf), 35.5][ordinal % 4]
        width_scale = [0.01, 0.4, math.nextafter(0.4, math.inf), 1.3][(ordinal // 4) % 4]
        inputs = [integer(0x491188, boat_class), integer(0x491140, 1 + ordinal % 2),
            integer(0x4ac900, int(boat_class >= 9)), integer(0x4ac904, board),
            integer(0x4ac914, int(boat_class == 1 and ordinal % 3 == 0)),
            integer(0x4ac908, int(boat_class == 3)), integer(0x4ac90c, int(boat_class == 6)),
            integer(0x4aa390, [11, 12, 13][ordinal % 3]), number(0x4a3a48, 200.5),
            number(0x4ac320, 500.125), number(0x4ac338, 501.375),
            number(0x4a3ef0, [-2.7, 0.0, 3.25][ordinal % 3]),
            number(0x4abef0, [-3.99, 0.0, 2.99, 3.99][ordinal % 4])]
        for address, value in {
            0x4a7768: ordinal % 6, 0x4a4ef8: ordinal % 4, 0x4a4170: ordinal % 4,
            0x4ac5f0: 99, 0x4a6ec8: [-1, 0, 10, 70][ordinal % 4], 0x4aa730: tack,
            0x4a77e8: [0, 5, 20, 40][(ordinal // 3) % 4],
            0x4a8aa8: [19, 20, 21, 69, 70, 71, 79, 80][(ordinal // 5) % 8],
            0x4a85d0: [0, 25, 100][ordinal % 3],
            0x4a7bc8: [29, 30, 31, 59, 90, 120, 131, 132, 133, 180][(ordinal // 7) % 10],
            0x4abb70: (ordinal // 6) % 2,
        }.items(): inputs.append(integer(indexed(address, boat), value))
        yield {'seed': 2002, 'arguments': [height, boat, 3 + ordinal % 2, curvature, heading, width_scale],
               'inputs': inputs, 'prepareOriginal': [{'address': 0x413100,
                   'arguments': [height, height * 0.3], 'argumentTypes': ['F64', 'F64']}]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true')
    args = parser.parse_args()
    vm = OriginalMachine(); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    writes = []
    def write(uc, access, address, size, value, data):
        if BASE <= address and address + size <= BASE + SIZE: writes.append((address, size))
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, write)
    records = []
    for case in cases():
        vm.uc.mem_write(BASE, baseline)
        for input in case['inputs']:
            vm.uc.mem_write(input['address'], argument_bytes([input['value']], [input['type']]))
        vm.write_i32(TLS + 0x14, case['seed'])
        for preparation in case['prepareOriginal']:
            vm.call(preparation['address'], argument_bytes(preparation['arguments'], preparation['argumentTypes']))
        before = bytes(vm.uc.mem_read(BASE, SIZE))
        case['seedAtCall'] = vm.read_u32(TLS + 0x14)
        case['imageInputs'] = [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)]
        writes.clear()
        vm.call(0x414010, argument_bytes(case['arguments'], KINDS))
        after = bytes(vm.uc.mem_read(BASE, SIZE))
        if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original text changed')
        case['expected'] = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [],
            'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()}
        case['imageWrites'] = [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)]
        records.append(case)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'tls_accessor_stub': '00459ed0',
        'note': 'Full 0x414010 finite geometry calls with original flat-hull preparation as explicit raw input. Original .text checked unchanged for every call. Hardware FSIN authority comparison is pending; no JS result is used as an oracle.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60},
        'routines': {'initializeSailGeometry': {'address': 0x414010, 'argumentTypes': KINDS,
                                              'returnType': 'void', 'cases': records}}}
    save(ROOT / 'tests/fixtures/original-sail-geometry.json', fixture)
    print('initializeSailGeometry', len(records), flush=True)

    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'),
            '--fixture', 'original-sail-geometry.json', '--report', str(ROOT/'analysis/sail-geometry-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__': main()
