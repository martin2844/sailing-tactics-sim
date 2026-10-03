#!/usr/bin/env python3
"""Bounded complete hull/wake/rudder calls with unchanged-code GDI traces."""
import argparse
import hashlib
import json
import math
import random

import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_gdi_fixtures import DrawingMachine, CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, save
from capture_crew_fixtures import argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000
ROUTINES = {
    'drawEllipseMarker': (0x423640, ['I32']*3),
    'drawHullPortSide': (0x415de0, ['F64', 'I32', 'I32']),
    'drawHullStarboardSide': (0x416070, ['F64', 'I32', 'I32']),
    'drawHullStern': (0x416300, ['F64', 'I32', 'I32', 'I32']),
    'drawWakeSegment': (0x417eb0, ['F64']+['I32']*4),
    'drawStarboardInnerPanel': (0x417d30, ['F64', 'I32', 'I32']),
    'drawStarboardOuterPanel': (0x417fb0, ['F64', 'I32', 'I32']),
    'drawPortInnerPanel': (0x418890, ['F64', 'I32', 'I32']),
    'drawPortOuterPanel': (0x418a10, ['F64', 'I32', 'I32']),
    'drawCatamaranCrossbar': (0x418580, ['F64', 'F64']),
    'drawWakeBurst': (0x419ca0, ['I32', 'F64', 'I32', 'I32']),
    'drawSideSpray': (0x419b40, ['I32', 'F64']+['I32']*3),
    'drawRudder': (0x4194b0, ['F64', 'I32', 'I32']),
    'drawCatamaranRudders': (0x419640, ['F64', 'I32']),
    'drawSteeringArc': (0x4198f0, ['F64']+['I32']*4),
    'drawTelltale': (0x417570, ['I32']*6),
}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true')
    args = parser.parse_args()
    vm = DrawingMachine(); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    handles = [row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
    writes = []
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, lambda uc, access, address, size, value, data:
        writes.append((address, size)) if BASE <= address and address+size <= BASE+SIZE else None)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'note': 'Complete original boat hull/wake/rudder routines with synthetic projected integer geometry, explicit CDC virtual/GDI observational bindings and unchanged original .text. Exact ordered trace and mutable-state contracts; Canvas pixel raster identity is not established.',
        'cdcVirtualBindings': {'0x2c': 'selectStockObject', '0x34': 'setBkColor', '0x38': 'setTextColor', '0x64': 'textOut'},
        'initialDC': {'position': [0, 0], 'textColor': 0, 'backgroundColor': 0xffffff, 'backgroundMode': 2}},
        'mutableBlock': {'address': BASE, 'size': SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    prng = random.Random(0x415de0)
    for name, (address, kinds) in ROUTINES.items():
        rows = []
        for index in range(160):
            vm.uc.mem_write(BASE, baseline)
            seed = [0, 1, 2002, 0xffffffff][index % 4]
            vm.write_i32(TLS+0x14, seed)
            for handle in handles: vm.write_i32(handle, handle if index % 13 else 0)
            boat = index % 31
            height = [-0.1, 0.1, 17.3, math.nextafter(17.3, math.inf), 35.5][index % 5]
            screen_y = [149, 150, 151, 199, 200, 201, 300, 600][(index // 5) % 8]
            view = [-180, -151, -90, -15, -14, -1, 0, 1, 14, 15, 90, 150, 180][index % 13]
            integers = {
                0x491188: 1 + index % 10, 0x491140: 1 + index % 2,
                0x4ac92c: (index // 2) % 2, 0x4ac910: (index // 3) % 2,
                0x4ac98c: (index // 5) % 2, 0x4ac928: (index // 7) % 2,
                0x4ac904: (index // 11) % 2, 0x4ac900: (index // 13) % 2,
                0x4a7354: 200, 0x4ac13c: 150, 0x4a5b7c: index % 3 - 1,
                0x4ac980: [499, 500, 501][index % 3],
                0x4a7044: [-2**31, -51, -1, 0, 1, 51, 2**31-1][index % 7],
                0x4a4380: prng.randrange(-3000, 3001), 0x4a6784: prng.randrange(-3000, 3001),
                0x4a4384: prng.randrange(-3000, 3001), 0x4a6788: prng.randrange(-3000, 3001),
                0x4a437c: prng.randrange(-3000, 3001), 0x4a678c: prng.randrange(-3000, 3001),
                0x4ac838: prng.randrange(-3000, 3001), 0x4a3f88: prng.randrange(-3000, 3001),
            }
            for location, value in integers.items(): vm.write_i32(location, value)
            for base in [0x4aa1a0, 0x4aa2a0]:
                for point in range(64):
                    value = prng.randrange(-2**31, 2**31) if index % 16 == 0 else prng.randrange(-3000, 3001)
                    vm.write_i32(base+point*4, value)
            for number in range(31):
                for base, value in [(0x4aa730, -1 if (index+number)%2 else 1),
                    (0x4a6ec8, [7, 8, 9][(index+number)%3]),
                    (0x4a7060, [-1, 0, 8, 16, 39, 40, 41, 80][(index+number)%8]),
                    (0x4a7bc8, [0, 45, 90, 150, 180][(index+number)%5]),
                    (0x4a4e88, 1+(index+number)%3)]: vm.write_i32(base+number*4, value)
            if name == 'drawEllipseMarker': params = [index % 30, 17*index-500, 13*index-200]
            elif name in ['drawHullPortSide', 'drawHullStarboardSide']: params = [height, index % 3, boat]
            elif name == 'drawHullStern': params = [height, boat, index % 3, screen_y]
            elif name == 'drawWakeSegment': params = [height, 17*index-500, 13*index-200, index%32, screen_y]
            elif name == 'drawCatamaranCrossbar': params = [height, [0.4, math.nextafter(0.4, math.inf), 1.3][index%3]]
            elif name == 'drawWakeBurst': params = [boat, height, 17*index-500, 13*index-200]
            elif name == 'drawSideSpray': params = [boat, height, index%3-1, screen_y, view]
            elif name == 'drawCatamaranRudders': params = [height, boat]
            elif name == 'drawSteeringArc': params = [height, boat, index%3-1, view, screen_y]
            elif name == 'drawTelltale': params = [17*index-500, 13*index-200, boat, view, screen_y, index%3]
            else: params = [height, boat, screen_y]
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            writes.clear(); vm.reset_trace()
            vm.call(address, argument_bytes([CDC]+params, ['I32']+kinds), count=1000000)
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original .text changed')
            rows.append({'arguments': params, 'seedAtCall': seed,
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)],
                'imageWrites': [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)],
                'expected': {'rngState': vm.read_u32(TLS+0x14), 'sounds': [], 'imageChanges': changed(before, after),
                    'mutableBlockHash': hashlib.sha256(after).hexdigest(), 'drawingCommands': vm.events.copy()}})
        fixture['routines'][name] = {'address': address, 'argumentTypes': ['CDC']+kinds, 'returnType': 'void', 'cases': rows}
        print(name, len(rows), flush=True)
    save(ROOT/'tests/fixtures/original-boat-panels.json', fixture)

    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'),
            '--fixture', 'original-boat-panels.json', '--report', str(ROOT/'analysis/boat-panels-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__': main()
