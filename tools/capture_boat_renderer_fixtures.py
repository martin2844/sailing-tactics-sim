#!/usr/bin/env python3
"""Complete original boat renderer calls with original boat-option preparation with unchanged-code GDI traces."""
import argparse
import hashlib
import json
import struct
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
ROUTINES = {'drawBoat': (0x411000, ['I32'] * 6)}


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
        'note': 'Complete original boat renderer routine with original boat options and hull/sail/crew projection, explicit synthetic simulation-state inputs, explicit CDC virtual/GDI observational bindings and unchanged original .text. Exact ordered trace and mutable-state contracts; Canvas pixel raster identity is not established.',
        'cdcVirtualBindings': {'0x2c': 'selectStockObject', '0x34': 'setBkColor', '0x38': 'setTextColor', '0x64': 'textOut'},
        'initialDC': {'position': [0, 0], 'textColor': 0, 'backgroundColor': 0xffffff, 'backgroundMode': 2}},
        'mutableBlock': {'address': BASE, 'size': SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    prng = random.Random(0x415de0)
    for name, (address, kinds) in ROUTINES.items():
        rows = []
        for index in range(1440):
            vm.uc.mem_write(BASE, baseline)
            seed = [0, 1, 2002, 0xffffffff][index % 4]
            vm.write_i32(TLS+0x14, seed)
            for handle in handles: vm.write_i32(handle, handle if index % 13 else 0)
            boat = [0, 1, 2, 3, 11, 21, 30, 1][index % 8]
            screen_y = [149, 150, 151, 199, 200, 201, 300, 600][(index // 5) % 8]
            integers = {
                0x491188: 1 + index % 10, 0x491140: 1 + index % 2, 0x49118c: 1 + index % 3,
                0x4ac994: [-1, 0, 1, 2][index % 4],
                0x4ac92c: (index // 2) % 2, 0x4ac910: (index // 3) % 2,
                0x4ac98c: (index // 5) % 2, 0x4ac928: (index // 7) % 2,
                0x4ac904: (index // 11) % 2, 0x4ac900: (index // 13) % 2,
                0x4a7354: 200, 0x4ac13c: 150, 0x4a7358: 300,
                0x4ac914: (index // 17) % 2, 0x4ac908: (index // 19) % 2,
                0x4ac90c: (index // 23) % 2, 0x4ac930: (index // 29) % 2,
                0x491150: [99, 100, 101][index % 3], 0x4ac9bc: (index // 31) % 2,
                0x4911d0: [1, 2][index % 2], 0x4911d4: [95, 96, 97][index % 3],
                0x4a5b80: 100, 0x49116c: [1, 2, 4][index % 3], 0x491170: 833,
                0x4a7644: [49, 50, 51][index % 3], 0x4a40c4: (index // 37) % 2,
                0x4a40c8: (index // 41) % 2, 0x4a76c4: 183, 0x4a7760: -247,
                0x4a7640: 483, 0x4a7750: -87, 0x4aa598: 91, 0x4aba64: 32,
                0x4a67a0: -177, 0x4aa6fc: 305, 0x4a5b7c: index % 3 - 1,
                0x4ac980: [499, 500, 501][index % 3],
                0x4a7044: [-1080, -360, -180, -51, -1, 0, 1, 51, 180, 360, 1080][index % 11],
                0x4a4880: prng.randrange(-3000, 3001), 0x4a4950: prng.randrange(-3000, 3001),
                0x4a4884: prng.randrange(-3000, 3001), 0x4a4df0: prng.randrange(-3000, 3001),
                0x4a4380: prng.randrange(-3000, 3001), 0x4a6784: prng.randrange(-3000, 3001),
                0x4a4384: prng.randrange(-3000, 3001), 0x4a6788: prng.randrange(-3000, 3001),
                0x4a437c: prng.randrange(-3000, 3001), 0x4a678c: prng.randrange(-3000, 3001),
                0x4ac838: prng.randrange(-3000, 3001), 0x4a3f88: prng.randrange(-3000, 3001),
            }
            integers.update({0x491148: 16, 0x4a763c: [640,800,1024,1280][index % 4],
                0x4a72d0: [460,600,720,768][index % 4], 0x4ac96c: [0,1,275,276,277][index % 5],
                0x4ac4ec: [0,1,4,23][index % 4], 0x4a633c: [11,12,13,35][index % 4],
                0x4ac994: [0,1,2][index % 3], 0x4ac928: (index // 17) % 2,
                0x4ac9d4: [0,1,10,20][index % 4], 0x4ac918: 30,0x4ac91c: 10,0x4ac920: 10,0x4ac924: 0,
                0x491144: 1+(index // 96) % 15,0x49114c: index % 2,0x491194: 1})
            for location, value in integers.items(): vm.write_i32(location, value)
            vm.uc.mem_write(0x4ab0c8, struct.pack('<d', [0.,0.5,1.,1.3][index % 4]))
            vm.uc.mem_write(0x4abef0, struct.pack('<d', [-2.99,0.,2.,3.99][index % 4]))
            vm.call(0x417790)
            for base in [0x4aa1a0, 0x4aa2a0]:
                for point in range(64):
                    value = prng.randrange(-2**31, 2**31) if index % 16 == 0 else prng.randrange(-3000, 3001)
                    vm.write_i32(base+point*4, value)
            for number in range(31):
                for base, value in [(0x4aa730, -1 if (index+number)%2 else 1),
                    (0x4a6ec8, [0, 1, 4, 5, 6, 7, 8, 9, 12, 23, 49][(index+number)%11]),
                    (0x4a7060, [0, 8, 26, 27, 30, 31, 39, 40, 80][(index+number)%9]),
                    (0x4a7bc8, [0, 59, 60, 89, 90, 91, 180][(index+number)%7]),
                    (0x4a4e88, 1+(index//8+number)%3),
                    (0x4a6830, 0), (0x4ac018, [-180,-171,-170,-169,-91,-90,-89,-16,-15,-14,-1,0,1,14,15,16,89,90,91,169,170,171,180][(index+number) % 23]),
                    (0x4a4608, (index//3+number)%2), (0x4aa5b0, [0,1,59,60,61,89,90,91,179,180][(index+number)%10]),
                    (0x4a8d50, [0,1,10,11,50,100][(index+number)%6]),
                    (0x4a3a18, [95,100,101][(index+number)%3]), (0x4a41f0, [80,99,100][(index+number)%3]), (0x4abb70, (index+number)%2),
                    (0x4a4e78, [0, 1, 3][(index+number)%3]), (0x4a6090, (index+number)%2),
                    (0x4abf18, 50), (0x4a89c0, [9, 10, 11][(index+number)%3]),
                    (0x4a77e8, [0, 5, 40][(index+number)%3]), (0x4a8aa8, [10, 11, 35, 36][(index+number)%4])]: vm.write_i32(base+number*4, value)
            params = [prng.randrange(-100, 1501), screen_y, boat, 1+index%2, 600, 100]
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
    save(ROOT/'tests/fixtures/original-boat-renderer.json', fixture)

    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'),
            '--fixture', 'original-boat-renderer.json', '--report', str(ROOT/'analysis/boat-renderer-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__': main()
