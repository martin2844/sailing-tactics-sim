#!/usr/bin/env python3
"""Capture complete original 00428c60 finite physics cases before native audit.

All source instructions are retained. The isolated CRT record and the known
PlaySoundA request recorder are runtime substitutes; synthetic prepared boats
and geometry are explicit. Regeneration applies documented native authority.
"""
import argparse
import hashlib
import itertools
import json
import random
import struct
import subprocess
import sys

import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_encounter_fixtures import merged_ranges
from native_mutable_state import BLOCK_ADDRESS, BLOCK_SIZE, image_changes

DESTINATION = ROOT / 'tests/fixtures/original-boat-dynamics.json'
TIMES = [-151, -150, -149, -31, -30, -29, -2, -1, 0, 1, 3, 4, 10, 19, 20, 30, 50, 51]


def cases():
    for selector, angle in itertools.product(range(1, 16), range(181)):
        yield {'branch': 'all-sailing-angles', 'selector': selector, 'angle': angle}
    for selector, trim, depower in itertools.product(range(1, 16), range(6), [-1, 0, 1, 30, 80, 99, 100]):
        yield {'branch': 'trim-depower', 'selector': selector, 'trim': trim, 'depower': depower}
    for selector, heel in itertools.product(range(1, 16), range(-10, 71, 5)):
        yield {'branch': 'heel', 'selector': selector, 'heel': heel}
    for time, stage in itertools.product(TIMES, range(11)):
        yield {'branch': 'time-stage', 'selector': 1 + (time + stage) % 15, 'time': time, 'stage': stage}
    for n in range(300):
        yield {'branch': 'random-connected-state', 'selector': 1 + n % 15}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true')
    parser.add_argument('--limit', type=int, help='First N exploratory cases; requires --emulated-only')
    args = parser.parse_args()
    if args.limit is not None and not args.emulated_only:
        raise ValueError('Incomplete exploratory captures cannot become native fixtures')
    vm = OriginalMachine()
    vm.call(0x415a60)
    stub = SCRATCH + 0x800
    vm.write_i32(0x4b1c18, stub)
    baseline = bytes(vm.uc.mem_read(0x400000, 0x111000))
    baseline_block = baseline[BLOCK_ADDRESS - 0x400000:BLOCK_ADDRESS - 0x400000 + BLOCK_SIZE]
    geometry = json.loads((ROOT / 'tests/fixtures/original-current.json').read_text())['geometry']
    writes, sounds, executed = [], [], {}
    def record_write(uc, access, address, size, value, data):
        if 0x400000 <= address and address + size <= 0x511000:
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
    prng = random.Random(0x428c60)
    records, all_writes = [], []
    for n, config in enumerate(cases()):
        if args.limit is not None and n >= args.limit:
            break
        vm.uc.mem_write(0x400000, baseline)
        time = config.get('time', prng.choice(TIMES))
        integers = {
            0x49118c: 3, 0x491140: prng.choice([1, 2]), 0x4911cc: prng.choice([1, 2, 3, 4]),
            0x4a5b80: time, 0x491144: config['selector'], 0x491194: 2,
            0x4a864c: n % 2, 0x4a4958: 0, 0x4a5a4c: 0, 0x4abae8: 1000,
            0x4ac284: 0, 0x4a3a08: 0, 0x4ac9c0: n % 2, 0x4ac1d4: 0x76543210,
            0x4a4eb0: prng.choice([40, 45, 50]), 0x4aa594: -600, 0x4aa59c: 0,
            0x4a70f8: 600, 0x4a72c8: 0, 0x4aa294: 0, 0x4aa388: 1000,
            0x4aa38c: -600, 0x4aa588: 1000, 0x4aa288: 600, 0x4aa384: 1000,
            0x4aa998: 600, 0x4a4be0: 0, 0x4a4f84: -300,
            0x4a763c: prng.choice([800, 1000]), 0x4a4388: prng.randrange(2),
            0x4a438c: prng.randrange(2), 0x4ac9ac: prng.randrange(2),
            0x4ac540: prng.randrange(361), 0x4aa390: prng.randrange(1, 31),
        }
        doubles = {0x4a6470: 1.25, 0x4abe60: 0.875,
            0x4aa948: prng.choice([0.1, 0.5, 1.0]),
            0x4ac1f8: float(time) + prng.choice([-0.5, 0, 0.5]), 0x4ab0c0: 1.0}
        for address, value in integers.items():
            vm.write_i32(address, value)
        for address, value in doubles.items():
            vm.uc.mem_write(address, struct.pack('<d', value))
        for spec in geometry.values():
            fmt = '<d' if spec['address'] == 0x4a8028 else '<i'
            for index, value in enumerate(spec['values']):
                vm.uc.mem_write(spec['address'] + index * struct.calcsize(fmt), struct.pack(fmt, value))
        # The original selector initializer supplies all class dimensions/flags.
        vm.call(0x417790)
        boat = 1 + n % 3
        for b in [1, 2, 3]:
            wind = prng.randrange(360)
            angle = config.get('angle', prng.randrange(181)) if b == boat else prng.randrange(181)
            fields = {
                0x4ac018: (wind + angle) % 360, 0x4aa5b0: wind,
                0x4aa730: prng.choice([-1, 1]), 0x4a7bc8: angle,
                0x4a6338: prng.randrange(31),
                0x4a7768: config.get('trim', prng.randrange(6)) if b == boat else prng.randrange(6),
                0x4a4ef8: prng.randrange(4),
                0x4a85d0: config.get('depower', prng.choice([-1, 0, 30, 80, 100])) if b == boat else prng.choice([-1, 0, 30, 80, 100]),
                0x4a6fc8: prng.randrange(75, 116), 0x4a5f90: prng.choice([-1, 40, 100]),
                0x4a7060: prng.randrange(100),
                0x4a6ec8: config.get('heel', prng.randrange(-10, 71)) if b == boat else prng.randrange(-10, 71),
                0x4abf18: time + prng.choice([-100, -11, -10, -9, 0]),
                0x4a5420: config.get('stage', prng.randrange(11)) if b == boat else prng.randrange(11),
                0x4a41f0: time + prng.randrange(-15, 1), 0x4a5f10: 150,
                0x4a3a18: time - 20, 0x4abb70: prng.randrange(2), 0x4a42f0: prng.randrange(4),
                0x4abc00: prng.randrange(181), 0x4a76d0: prng.randrange(2),
                0x4a4170: prng.randrange(4), 0x4ac4e8: prng.randrange(3),
                0x4ac570: prng.randrange(100), 0x4a46a8: prng.randrange(2), 0x4aad20: prng.randrange(2),
            }
            for address, value in fields.items():
                vm.write_i32(address + b * 4, value)
            for address, value in {0x4a49e8: float(100 + (b - 1) * 400),
                    0x4a4ae0: float(100 + (b - 1) * 500),
                    0x4a71c8: prng.randrange(100) + 0.5, 0x4a7f28: 80.0}.items():
                vm.uc.mem_write(address + b * 8, struct.pack('<d', value))
        seed = [0, 1, 2002, 0xffffffff][n % 4]
        vm.write_i32(TLS + 0x14, seed)
        before = bytes(vm.uc.mem_read(0x400000, 0x111000))
        block_offset = BLOCK_ADDRESS - 0x400000
        before_block = before[block_offset:block_offset + BLOCK_SIZE]
        writes.clear()
        sounds.clear()
        vm.call(0x428c60, arguments(boat), count=1000000)
        after = bytes(vm.uc.mem_read(0x400000, 0x111000))
        after_block = after[block_offset:block_offset + BLOCK_SIZE]
        if before[:block_offset] != after[:block_offset] or before[block_offset + BLOCK_SIZE:] != after[block_offset + BLOCK_SIZE:]:
            raise AssertionError('Original call wrote outside the declared data block')
        deltas = image_changes(before_block, after_block)
        prepared = [{'address': row['address'], 'bits': row['after']}
                    for row in image_changes(baseline_block, before_block)]
        ranges = merged_ranges(writes)
        all_writes.extend(writes)
        records.append({'branch': config['branch'], 'selector': config['selector'],
            'arguments': [boat], 'seedAtCall': seed, 'imageInputs': prepared,
            'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': sounds.copy(),
                'imageChanges': deltas, 'mutableBlockHash': hashlib.sha256(after_block).hexdigest()},
            'imageWrites': [{'address': start, 'size': end - start} for start, end in ranges]})
        if n % 250 == 0:
            print(f'Captured {n + 1} complete original physics cases', flush=True)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18', 'sound_return': 1,
        'note': 'Complete unchanged 00428c60 calls with synthetic three-boat states/geometry, all class selectors, angles, trims, depower, heel and timing edges. Whole mutable block and all mapped-image write ranges captured; finite cases do not establish universal/full UI parity.'},
        'mutableBlock': {'address': BLOCK_ADDRESS, 'size': BLOCK_SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60},
        'routines': {'updateBoatDynamics': {'address': 0x428c60,
            'argumentTypes': ['I32'], 'returnType': 'void', 'cases': records,
            'observedWriteRanges': [{'address': start, 'size': end - start} for start, end in merged_ranges(all_writes)],
            'observedInstructionRanges': [{'address': start, 'size': end - start} for start, end in merged_ranges(executed.items())]}}}
    save(DESTINATION, fixture)
    print(f'Captured {len(records)} complete physics calls; original text unchanged', flush=True)
    if not args.emulated_only:
        command = [sys.executable, str(ROOT / 'tools/verify_native_state.py'),
            '--fixture', DESTINATION.name, '--report', str(ROOT / 'analysis/boat-dynamics-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__':
    main()
