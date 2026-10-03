#!/usr/bin/env python3
"""Capture isolated x87 arithmetic and original wind's finite FSIN input domain.

The arithmetic probe uses explicit x87 opcodes in scratch memory. It does not
modify the original executable. Wind trigonometry uses its original binary64
degree factor and instruction ordering, including extended multiplication.
"""
from pathlib import Path
import argparse
import json
import random
import struct

import unicorn
from unicorn.x86_const import UC_X86_REG_EDX
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, save

CODE = SCRATCH + 0x4000
LEFT = SCRATCH + 0x5000
RIGHT = SCRATCH + 0x5020
RESULT80 = SCRATCH + 0x6000
RESULT64 = SCRATCH + 0x6020
DEGREE_FACTOR = 0x00484d40


def memory_instruction(opcode, address):
    return bytes.fromhex(opcode) + struct.pack('<I', address)


def write_code(vm, code):
    vm.uc.mem_write(CODE, code)
    # Host-side memory writes are outside emulated store instructions. Explicitly
    # discard translated blocks before reusing this scratch instruction address.
    vm.uc.ctl_remove_cache(CODE, CODE + 0x100)


def encode(sign, mantissa, biased_exponent):
    return struct.pack('<QH', mantissa, biased_exponent | (0x8000 if sign < 0 else 0))


def from_double(value):
    raw = struct.unpack('<Q', struct.pack('<d', value))[0]
    sign = -1 if raw >> 63 else 1
    exp = (raw >> 52) & 0x7ff
    fraction = raw & ((1 << 52) - 1)
    if exp == 0:
        if not fraction:
            return encode(sign, 0, 0)
        shift = 64 - fraction.bit_length()
        return encode(sign, fraction << shift, -1074 - shift + 63 + 16383)
    return encode(sign, ((1 << 52) | fraction) << 11, exp - 1023 + 16383)


def read_result(vm):
    raw80 = bytes(vm.uc.mem_read(RESULT80, 10))
    raw64 = bytes(vm.uc.mem_read(RESULT64, 8))
    exponent = struct.unpack('<H', raw80[8:])[0] & 0x7fff
    if exponent == 0x7fff:
        return None
    return {'extendedBits': raw80.hex(), 'storedDoubleBits': raw64.hex()}


def truncate(vm, raw):
    mantissa, sign_exp = struct.unpack('<QH', raw)
    exp = (sign_exp & 0x7fff) - 16383 - 63 if sign_exp & 0x7fff else -16445
    value = mantissa << exp if exp >= 0 else mantissa >> -exp
    if sign_exp & 0x8000:
        value = -value
    if not -(1 << 63) <= value < (1 << 63):
        return None
    vm.uc.mem_write(LEFT, raw)
    prefix = memory_instruction('db2d', LEFT)
    # Invoke the unmodified CRT's __ftol, which changes then restores FPCW.
    relative = 0x004570b0 - (CODE + len(prefix) + 5)
    write_code(vm, prefix + b'\xe8' + struct.pack('<i', relative) + b'\xc3')
    low = vm.call(CODE)
    high = vm.uc.reg_read(UC_X86_REG_EDX)
    native = struct.unpack('<q', struct.pack('<II', low, high))[0]
    if native != value:
        raise AssertionError(f'Original ftol mismatch: {native} vs {value}')
    return {'integer64': str(native), 'integer32': struct.unpack('<i', struct.pack('<I', low))[0]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--emulated-only', action='store_true', help='Skip native hardware comparison; generated reference values remain emulated-only.')
    arguments = parser.parse_args()
    vm = OriginalMachine()
    prng = random.Random(80387)
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f',
        'note': 'Explicit x87 arithmetic probes in scratch memory; original constants and CRT ftol unchanged. Finite CPU-emulation evidence, not historical CPU equivalence.'}
    values = [from_double(value) for value in [0.0, -0.0, 1.0, -1.0, 0.1, -0.1,
        2.0, 3.0, 15.0, 29.0, 35.0, 5e-324, -5e-324, 1e-300, 1e300]]
    values += [encode(sign, mantissa, exp) for sign in [1, -1]
        for mantissa in [1, (1 << 62) - 1, 1 << 63, (1 << 64) - 1]
        for exp in [0, 1]]
    values += [encode(prng.choice([1, -1]), prng.randrange(1 << 63, 1 << 64),
        prng.choice([2, 15361, 15872, 16382, 16383, 16384, 16446, 16895, 17406, 32763]))
        for _ in range(160)]
    # Explicit halfway cases near one, cancellation, and division before sqrt.
    pairs = [(from_double(1), encode(1, 1 << 63, 16383 - 64)),
        (encode(1, (1 << 63) + 1, 16383), encode(1, 1 << 63, 16383 - 64)),
        (from_double(1), from_double(-1)), (from_double(-0.0), from_double(-0.0))]
    pairs += [(prng.choice(values), prng.choice(values)) for _ in range(240)]
    cases = []
    for operation, opcode in [('add', 'dec1'), ('subtract', 'dee9'),
                              ('multiply', 'dec9'), ('divide', 'def9')]:
        code = memory_instruction('db2d', LEFT) + memory_instruction('db2d', RIGHT)
        code += bytes.fromhex(opcode) + memory_instruction('dd15', RESULT64)
        code += memory_instruction('db3d', RESULT80) + b'\xc3'
        write_code(vm, code)
        for left, right in pairs:
            # Skip unsupported unnormal encodings and zero divisors.
            if operation == 'divide' and struct.unpack('<Q', right[:8])[0] == 0:
                continue
            if any((struct.unpack('<H', v[8:])[0] & 0x7fff) and not (v[7] & 0x80) for v in [left, right]):
                continue
            vm.uc.mem_write(LEFT, left)
            vm.uc.mem_write(RIGHT, right)
            vm.call(CODE)
            result = read_result(vm)
            if result is not None:
                cases.append({'operation': operation, 'leftBits': left.hex(),
                              'rightBits': right.hex(), 'expected': result})
    sqrt_code = memory_instruction('db2d', LEFT) + bytes.fromhex('d9fa')
    sqrt_code += memory_instruction('dd15', RESULT64) + memory_instruction('db3d', RESULT80) + b'\xc3'
    write_code(vm, sqrt_code)
    for raw in values:
        mantissa, sign_exp = struct.unpack('<QH', raw)
        if sign_exp & 0x8000 and mantissa:
            continue
        if sign_exp & 0x7fff and not (raw[7] & 0x80):
            continue
        vm.uc.mem_write(LEFT, raw)
        vm.call(CODE)
        result = read_result(vm)
        if result is not None:
            cases.append({'operation': 'sqrt', 'leftBits': raw.hex(), 'expected': result})
    conversions = []
    for raw in values:
        if struct.unpack('<H', raw[8:])[0] & 0x7fff and not (raw[7] & 0x80):
            continue
        result = truncate(vm, raw)
        if result is not None:
            conversions.append({'inputBits': raw.hex(), 'expected': result})
    save(ROOT / 'tests/fixtures/original-x87.json', {'provenance': provenance,
        'arithmetic': cases, 'truncation': conversions})

    trigonometry = {}
    for operation, opcode in [('sine', 'd9fe'), ('cosine', 'd9ff')]:
        # FILD integer angle; FLD the original degree factor; FMULP; FSIN/FCOS.
        code = memory_instruction('db05', LEFT) + memory_instruction('dd05', DEGREE_FACTOR)
        code += bytes.fromhex('dec9' + opcode) + memory_instruction('db3d', RESULT80) + b'\xc3'
        write_code(vm, code)
        for angle in range(-1080, 1081):
            vm.write_i32(LEFT, angle)
            vm.call(CODE)
            trigonometry.setdefault(str(angle), {})[operation + 'Bits'] = bytes(vm.uc.mem_read(RESULT80, 10)).hex()
    save(ROOT / 'assets/data/x87-trig.json', {'provenance': provenance,
        'degreeFactorAddress': DEGREE_FACTOR,
        'degreeFactorBits': bytes(vm.uc.mem_read(DEGREE_FACTOR, 8)).hex(),
        'inputOrdering': 'FILD signed integer angle; FMUL original binary64 degree factor in precision64; FSIN/FCOS; FSTP m80',
        'angles': trigonometry})
    print(f'Captured {len(cases)} finite x87 arithmetic cases, {len(conversions)} CRT truncations, and {len(trigonometry)} extended sine/cosine pairs')
    if arguments.emulated_only:
        print('Emulated-only capture requested: native comparison and overrides were skipped.')
    else:
        from verify_x87_native import verify
        verify()


if __name__ == '__main__':
    main()
