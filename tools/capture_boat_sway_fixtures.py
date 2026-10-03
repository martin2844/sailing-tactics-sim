#!/usr/bin/env python3
"""Complete original sway updates with explicit finite phase inputs."""
import argparse
import hashlib
import json
import random
import subprocess
import sys
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, save
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed
BASE, SIZE = 0x491000, 0x1d000

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true')
    args = parser.parse_args()
    vm = OriginalMachine(); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE)); text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    writes = []
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, lambda uc, access, address, size, value, data:
        writes.append((address, size)) if BASE <= address and address + size <= BASE + SIZE else None)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'note': 'Complete original 0x4304d0 updates, finite nonzero phase divisor, including signed overflow and angle/counter/crew/wind boundaries. Original image instructions unchanged.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    rows = []; random_source = random.Random(0x4304d0)
    for index in range(1536):
        vm.uc.mem_write(BASE, baseline)
        divisor = [1, 2, 3, 4, 833, 2919, 2185, 2**31-1, -1, -3, -833, 180][index % 12]
        threshold = int(divisor/3)
        counter = [-2**31, -1, 0, threshold-2, threshold-1, threshold, threshold+1, 2**31-1][(index//12) % 8]
        crew = [-2**31, -1, 0, 1, 4, 23, 49, 2**31-1][(index//3) % 8]
        angle = [-2**31, -1, 0, 59, 60, 61, 89, 90, 91, 180, 2**31-1][index % 11]
        wind = [-2**31, 0, 11, 12, 13, 35, 2**31-1][index % 7]
        seed = index + 2002; vm.write_i32(TLS+0x14, seed)
        for address, value in [(0x491170, divisor), (0x4ac96c, counter), (0x4a7bcc, angle),
                (0x4ac4ec, crew), (0x4a633c, wind), (0x4a5b7c, random_source.randrange(-2**31, 2**31))]: vm.write_i32(address, value)
        before = bytes(vm.uc.mem_read(BASE, SIZE)); writes.clear(); vm.call(0x4304d0)
        after = bytes(vm.uc.mem_read(BASE, SIZE))
        if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original .text changed')
        rows.append({'arguments': [], 'seedAtCall': seed,
            'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)],
            'imageWrites': [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)],
            'expected': {'rngState': vm.read_u32(TLS+0x14), 'sounds': [], 'imageChanges': changed(before, after),
                'mutableBlockHash': hashlib.sha256(after).hexdigest()}})
    fixture['routines']['updateBoatSway'] = {'address': 0x4304d0, 'argumentTypes': [], 'returnType': 'void', 'cases': rows}
    save(ROOT/'tests/fixtures/original-boat-sway.json', fixture)
    print('updateBoatSway', len(rows), flush=True)
    if not args.emulated_only:
        command = [sys.executable, str(ROOT/'tools/verify_native_state.py'), '--fixture', 'original-boat-sway.json',
            '--report', str(ROOT/'analysis/boat-sway-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True); subprocess.run(command, check=True)

if __name__ == '__main__': main()
