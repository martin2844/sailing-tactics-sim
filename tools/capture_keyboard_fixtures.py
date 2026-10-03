#!/usr/bin/env python3
"""Capture original WM_KEYDOWN state and ordered observable host requests.

Only InvalidateRect and the final MFC default-window operation are substituted
by observational callbacks. The original handler bytes stay unchanged.
"""
import hashlib
import itertools
import math
import struct

import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_initialization_fixtures import changed
from capture_encounter_fixtures import merged_ranges

BASE, SIZE = 0x491000, 0x1d000
WINDOW = 0x76543210
KEYS = [8, 12, 27, 32, 33, 34, 36, 37, 38, 39, 40, 48, 49, 50, 51, 52,
        53, 55, 57, 65, 66, 67, 68, 69, 70, 72, 73, 74, 76, 78, 79, 80,
        82, 83, 84, 85, 86, 87, 88, 89, 90, 112, 113, 114, 123, 186,
        187, 188, 189, 190, 191, 192, 219, 220, 221]
FLAGS = [0x4911d0, 0x4ac9ec, 0x4ac9b4, 0x4ac9c8, 0x4ac9c4, 0x4ac95c,
    0x4ac938, 0x4aa980, 0x4ac970, 0x4ac974, 0x4ac988, 0x4ac968,
    0x4ac94c, 0x4ac97c, 0x4ac93c, 0x4ac9cc, 0x4ac944, 0x4ac958,
    0x4ac9a4, 0x4ac9d0]
INDEXED = [0x4a8660, 0x4ab160, 0x4a4e88, 0x4aae20, 0x4a40c0,
    0x4a8910, 0x4a4968, 0x4a6848, 0x4a4df8, 0x4abf98, 0x4ac1e8,
    0x4a41f0, 0x4a46a8, 0x4a7bc8, 0x4a85d0, 0x4a7768, 0x4a9440, 0x4a4608]


def setup(human, profile=0, **overrides):
    state = {0x491140: human, 0x491188: [6, 1, 9, 7, 2, 6][profile],
        0x49118c: [15, 2, 3, 2, 15, 30][profile],
        0x491164: profile % 2, 0x49116c: [8, 1, 15, 0, 16, -0x80000000][profile],
        0x491170: 171, 0x491178: 8, 0x491174: 171,
        0x4ac8f8: [2, 0, 1, -1, 2, 2][profile],
        0x4ac980: [0, 101, 300, 502, 603, 6][profile],
        0x4ac984: [0, 101, 300, 502, 603, 6][profile],
        0x4a5b80: 100, 0x4a4168: -170, 0x4a4958: [0, 1, 2, 7, -1, 2][profile],
        0x491184: 3, 0x4a6774: [0, 2, 3, 4, -1, 0x7fffffff][profile],
        0x4ac020: [-1, 0, 359, 360, -0x80000000, 0x7fffffff][profile]}
    for address in FLAGS:
        state[address] = [0, 1, 2, -1, 0x7fffffff, -0x80000000][profile]
    for boat in [1, 2]:
        for address in INDEXED:
            state[address + boat * 4] = [1, 0, 90, -1, 0x7fffffff, -0x80000000][profile]
        state[0x4a7bc8 + boat * 4] = [89, 90, 91, -1, 0x7fffffff, -0x80000000][profile]
        state[0x4a4608 + boat * 4] = [-361, -360, 360, 361, 0x7fffffff, -0x80000000][profile]
    state.update({int(key): value for key, value in overrides.items()})
    return [{'address': address, 'type': 'I32', 'value': value} for address, value in state.items()] + [
        {'address': 0x4a78e8, 'type': 'F64', 'value': [-0., 17.3, math.nextafter(17.3, math.inf), 2.**53, -(2.**53), -17.3][profile]}]


def cases():
    for key, human in itertools.product(range(256), [1, 2]):
        yield {'arguments': [key, 1, 0], 'inputs': setup(human), 'seed': 2002}
    for key, human, profile in itertools.product(KEYS, [1, 2], range(1, 6)):
        yield {'arguments': [key, 3, 0x4000], 'inputs': setup(human, profile), 'seed': 2002}
    views = list(range(100, 112)) + list(range(500, 516)) + list(range(600, 606))
    for key, human, demo, view in itertools.product([0xbb, 0xbd], [1, 2], [0, 1], views):
        values = setup(human)
        values += [{'address': address, 'type': 'I32', 'value': value}
                   for address, value in [(0x491164, demo), (0x4ac980, view), (0x4ac984, view)]]
        yield {'arguments': [key, 1, 0], 'inputs': values, 'seed': 2002}
    # Space has several independent gates, including the preserved demo notice.
    for app, view, demo, notice, level in itertools.product([0, 1, 2], [0, 6], [0, 1], [0, 1], [1, 8]):
        values = setup(1) + [{'address': address, 'type': 'I32', 'value': value}
            for address, value in [(0x4ac8f8, app), (0x4ac980, view), (0x491164, demo), (0x4ac9cc, notice), (0x49116c, level)]]
        yield {'arguments': [32, 1, 0], 'inputs': values, 'seed': 2002}


def main():
    vm = OriginalMachine(); vm.call(0x415a60)
    obj, stub = SCRATCH + 0x1000, SCRATCH + 0x1800
    vm.write_i32(obj + 0x1c, WINDOW); vm.write_i32(0x4b1bc4, stub)
    vm.uc.reg_write(UC_X86_REG_ECX, obj); vm.baseline = vm.uc.context_save()
    baseline = bytes(vm.uc.mem_read(BASE, SIZE)); text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    events, writes = [], []
    def invalidate(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, window, rectangle, erase = struct.unpack('<4I', uc.mem_read(esp, 16))
        if rectangle != 0: raise AssertionError('Unexpected original rectangle pointer')
        events.append({'op': 'invalidateRect', 'windowHandle': window, 'rectangle': None, 'erase': erase})
        uc.reg_write(UC_X86_REG_EAX, 1); uc.reg_write(UC_X86_REG_ESP, esp + 16); uc.reg_write(UC_X86_REG_EIP, ret)
    def default(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', uc.mem_read(esp, 4))[0]
        events.append({'op': 'defaultKeyHandler'})
        uc.reg_write(UC_X86_REG_EAX, 0); uc.reg_write(UC_X86_REG_ESP, esp + 4); uc.reg_write(UC_X86_REG_EIP, ret)
    def write(uc, access, address, size, value, data):
        if BASE <= address and address + size <= BASE + SIZE: writes.append((address, size))
    vm.uc.hook_add(UC_HOOK_CODE, invalidate, begin=stub, end=stub)
    vm.uc.hook_add(UC_HOOK_CODE, default, begin=0x468021, end=0x468021)
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, write)
    records = []
    for case in cases():
        vm.uc.mem_write(BASE, baseline); vm.write_i32(TLS + 0x14, case['seed'])
        for row in case['inputs']:
            vm.uc.mem_write(row['address'], struct.pack('<d', row['value']) if row['type'] == 'F64'
                            else struct.pack('<I', row['value'] & 0xffffffff))
        before = bytes(vm.uc.mem_read(BASE, SIZE)); case['seedAtCall'] = case['seed']
        case['imageInputs'] = [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)]
        events.clear(); writes.clear(); vm.call(0x4517c0, arguments(*case['arguments']))
        after = bytes(vm.uc.mem_read(BASE, SIZE))
        if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original text changed')
        case['expected'] = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [], 'hostEvents': events.copy(),
            'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()}
        case['imageWrites'] = [{'address': start, 'size': end - start} for start, end in merged_ranges(writes)]
        records.append(case)
    save(ROOT / 'tests/fixtures/original-keyboard.json', {'provenance': {'sha256': EXPECTED,
        'engine': 'Unicorn', 'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'invalidateRectImport': '004b1bc4', 'defaultWindowRoutine': '00468021',
        'note': 'Original full WM_KEYDOWN bytes; explicit observational InvalidateRect BOOL1 and MFC default-call stubs. Finite mutable-state inputs include preserved demo/menu gates. No application/window lifecycle.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60},
        'windowHandle': WINDOW, 'routines': {'handleKeyDown': {'address': 0x4517c0,
            'argumentTypes': ['I32'] * 3, 'returnType': 'void', 'cases': records}}})
    print('handleKeyDown', len(records), flush=True)


if __name__ == '__main__': main()
