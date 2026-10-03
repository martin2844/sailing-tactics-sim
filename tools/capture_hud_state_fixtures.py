#!/usr/bin/env python3
"""Capture original HUD progress, signed-degree and numeric-text helpers.

CString host bindings copy/concatenate the bytes requested by the original
game helpers. Original x87 operations, truncations and CRT integer formatting
execute unchanged. The binding does not model Windows CString heap identity.
"""
import hashlib
import argparse
import json
import math
import random
import struct
import subprocess
import sys
import unicorn
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save, i32
from capture_initialization_fixtures import BASE, SIZE
from native_mutable_state import image_changes


class StringMachine(OriginalMachine):
    def __init__(self):
        super().__init__()
        # Read/write-only SEH chain cell used by the original CString callers.
        self.uc.mem_map(0, 4096)
        self.string_cursor = SCRATCH + 0x7000
        self.callbacks = []
        self.uc.mem_write(SCRATCH + 0x6000, bytes(32))
        def bind(address, words, callback, cdecl=False):
            def hook(uc, address, size, data):
                esp = uc.reg_read(UC_X86_REG_ESP)
                values = struct.unpack('<' + 'I' * (words + 1), uc.mem_read(esp, (words + 1) * 4))
                result = callback(uc.reg_read(UC_X86_REG_ECX), values[1:])
                uc.reg_write(UC_X86_REG_EAX, 0 if result is None else result)
                uc.reg_write(UC_X86_REG_ESP, esp + 4 + (0 if cdecl else words * 4))
                uc.reg_write(UC_X86_REG_EIP, values[0])
            self.callbacks.append(hook)
            self.uc.hook_add(unicorn.UC_HOOK_CODE, hook, begin=address, end=address)
        bind(0x46bd7a, 0, lambda this, v: self.assign(this, b''))
        bind(0x46bec5, 0, lambda this, v: None)
        bind(0x46c00d, 1, lambda this, v: self.assign(this, self.bytes_at(v[0])))
        bind(0x46bf33, 1, lambda this, v: self.assign(this, self.bytes_at(v[0])))
        bind(0x46bd8a, 1, lambda this, v: self.assign(this, self.object_bytes(v[0])))
        bind(0x46bfbe, 1, lambda this, v: self.assign(this, self.object_bytes(v[0])))
        bind(0x46c0db, 3, lambda this, v: self.assign(v[0], self.object_bytes(v[1]) + self.bytes_at(v[2])))
        bind(0x46c075, 3, lambda this, v: self.assign(v[0], self.object_bytes(v[1]) + self.object_bytes(v[2])))
        bind(0x46c14f, 3, lambda this, v: self.assign(v[0], self.bytes_at(v[1]) + self.object_bytes(v[2])))

    def bytes_at(self, pointer):
        result = bytearray()
        if pointer == 0:
            return bytes(result)
        for offset in range(65536):
            value = bytes(self.uc.mem_read(pointer + offset, 1))[0]
            if not value:
                return bytes(result)
            result.append(value)
        raise ValueError('Unterminated original string')

    def object_bytes(self, pointer):
        return self.bytes_at(self.read_u32(pointer))

    def assign(self, pointer, data):
        block = self.string_cursor
        self.string_cursor += ((len(data) + 13 + 15) // 16) * 16
        if self.string_cursor > SCRATCH + 0xff00:
            raise ValueError('Bounded CString scratch exhausted')
        self.uc.mem_write(block, struct.pack('<iii', 1, len(data), len(data)) + data + b'\0')
        self.write_i32(pointer, block + 12)
        return pointer

    def reset_strings(self):
        self.string_cursor = SCRATCH + 0x7000


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--emulated-only', action='store_true', help='Capture CPU-emulated evidence only; skip native authority')
    args = parser.parse_args()
    vm = StringMachine()
    vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'note': 'Original helpers and CRT _itoa execute unchanged; explicit CString byte-copy/concat host bindings, finite numeric cases, no CString heap identity claim.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60},
        'routines': {}, 'signedDegrees': [], 'integerFormatting': [], 'decimalFormatting': []}
    random_source = random.Random(0x42cf70)
    angles = [-2147483648, -721, -720, -361, -360, -359, -1, 0, 1, 179, 180, 181, 359, 360, 361, 719, 720, 721, 2147483647]
    angles += [random_source.randrange(-2147483648, 2147483648) for _ in range(1024)]
    for value in angles:
        fixture['signedDegrees'].append({'input': value, 'expected': i32(vm.call(0x415dc0, arguments(value)))})
    for value in angles:
        vm.reset_strings()
        result = vm.call(0x413d00, arguments(SCRATCH + 0x6100, value))
        if result != SCRATCH + 0x6100:
            raise AssertionError('Original formatter did not return output object')
        fixture['integerFormatting'].append({'input': value, 'expected': vm.object_bytes(result).decode('cp1252')})
    decimals = [0., -0., .1, -.1, 1.2, -1.2, 1000000000.25, -1000000000.25]
    for value in [-100.9, -2., -1.9, -1.2, -1., -.9, -.1, 0., .1, .9, 1., 1.2, 1.9, 2., 100.9]:
        decimals += [math.nextafter(value, -math.inf), value, math.nextafter(value, math.inf)]
    decimals += [random_source.uniform(-2e6, 2e6) for _ in range(512)]
    for value in decimals:
        vm.reset_strings()
        result = vm.call(0x413d90, arguments(SCRATCH + 0x6100) + struct.pack('<d', value))
        fixture['decimalFormatting'].append({'input': value, 'inputBits': struct.pack('<d', value).hex(),
                                             'expected': vm.object_bytes(result).decode('cp1252')})
    for name, address, return_type in [('updateDisplayedLeg', 0x42cf70, 'void'), ('displayedTargetMark', 0x42d0c0, 'residualEAX')]:
        cases = []
        for index in range(432):
            vm.uc.mem_write(BASE, baseline)
            boat = 1 + index % 2
            time = [-1, 0, 1, 29, 30, 31, 120, 2147483647, -2147483648][index % 9]
            for location, value in [(0x4a5b80, time), (0x4a6ba0 + boat * 4, [-1, 0, 1, 2, 3, 4, 5, 2147483647][index % 8]),
                                    (0x4ac950, (index // 3) % 2), (0x4a72d8 + boat * 4, (index // 5) % 2),
                                    (0x4aa7e0, 17), (0x4aa594, 0), (0x4aa59c, 0)]:
                vm.write_i32(location, value)
            position = [(0., 100.), (0., -100.), (100., 0.), (-100., 0.), (1., 1.), (-3., 4.)][(index // 9) % 6]
            for location, value in [(0x4a49e8 + boat * 8, position[0]), (0x4a4ae0 + boat * 8, position[1])]:
                vm.uc.mem_write(location, struct.pack('<d', value))
            # Independently record the original bearing, then arrange course
            # input headings around its explicit integer comparison boundary.
            vm.call(0x42c400, struct.pack('<ddii', 0., 0., 0, boat))
            bearing = i32(vm.call(0x413cb0, arguments(vm.read_i32(0x4a4758) + 180)))
            for leg in range(3):
                vm.write_i32(0x4a6444 + leg * 4, bearing + [-2, -1, 0, 1, 2, 359][(index + leg) % 6])
                vm.write_i32(0x4a645c + leg * 4, [0, 20, 119, 120, 121, 2147483647][(index // 6 + leg) % 6])
            vm.write_i32(TLS + 0x14, index + 2002)
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            result = vm.call(address, arguments(boat))
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            expected = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [],
                        'imageChanges': image_changes(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()}
            if return_type == 'residualEAX':
                expected['residualEAX'] = i32(result)
            cases.append({'arguments': [boat], 'seedAtCall': index + 2002,
                          'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline, before)],
                          'expected': expected})
        fixture['routines'][name] = {'address': address, 'argumentTypes': ['I32'], 'returnType': return_type, 'cases': cases}
    if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text:
        raise AssertionError('Original code changed')
    save(ROOT / 'tests/fixtures/original-hud-state.json', fixture)
    print('Captured 864 progress, %d signed-angle, %d integer-text, %d decimal-text original calls' %
          (len(fixture['signedDegrees']), len(fixture['integerFormatting']), len(fixture['decimalFormatting'])))
    if not args.emulated_only:
        command = [sys.executable, str(ROOT / 'tools/verify_native_state.py'), '--fixture', 'original-hud-state.json',
                   '--report', str(ROOT / 'analysis/hud-state-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__':
    main()
