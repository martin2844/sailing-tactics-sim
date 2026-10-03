#!/usr/bin/env python3
"""Capture fixed original menu commands and CCmdUI requests, without a window.

Original numeric handlers are the oracle. The host substitutes InvalidateRect
and CCmdUI Enable/SetCheck with ordered recorders. Modal/OS host commands are
explicitly outside this numeric fixture; their requests are tested separately.
"""
import hashlib
import re
import struct

import unicorn
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_initialization_fixtures import changed
from translate_menu_handlers import menu_entries, FLOAT_GLOBALS

BASE, SIZE = 0x491000, 0x1d000
WINDOW = 0x76543210
SPECIAL = {0x401760, 0x44ffd0, 0x450db0, 0x46e830, 0x477e8f}


def input_cases(source):
    addresses = sorted({int(value, 16) for value in re.findall(r'_?DAT_([0-9a-f]{8})', source)
                        if BASE <= int(value, 16) < BASE + SIZE})
    seen = set()
    def record(values):
        key = tuple(sorted(values.items()))
        if key in seen: return None
        seen.add(key)
        return [{'address': address, 'type': 'F64' if address in FLOAT_GLOBALS else 'I32', 'value': value}
                for address, value in sorted(values.items())]
    for value in [-0x80000000, -1, 0, 1, 2, 3, 5, 15, 0x7fffffff]:
        row = record({address: float(value) if address in FLOAT_GLOBALS else value for address in addresses})
        if row is not None: yield row
    # Independent predicate boundaries retain all other real PE defaults.
    comparisons = re.findall(r'DAT_([0-9a-f]{8})\s*(?:==|!=|<|>)\s*(-?(?:0x[0-9a-f]+|\d+))', source)
    comparisons += [(address, constant) for constant, address in
                    re.findall(r'(-?(?:0x[0-9a-f]+|\d+))\s*(?:==|!=|<|>)\s*DAT_([0-9a-f]{8})', source)]
    for address, constant in comparisons:
        address, constant = int(address, 16), int(constant, 0)
        if not BASE <= address < BASE + SIZE: continue
        for value in [constant - 1, constant, constant + 1]:
            if not -0x80000000 <= value <= 0x7fffffff: continue
            row = record({address: float(value) if address in FLOAT_GLOBALS else value})
            if row is not None: yield row


def main():
    vm = OriginalMachine(); vm.call(0x415a60)
    obj, ui, vtable = SCRATCH + 0x1000, SCRATCH + 0x1100, SCRATCH + 0x1200
    invalidate_stub, enable_stub, check_stub = SCRATCH + 0x1800, SCRATCH + 0x1810, SCRATCH + 0x1820
    vm.write_i32(obj + 0x1c, WINDOW); vm.write_i32(ui, vtable)
    vm.write_i32(vtable, enable_stub); vm.write_i32(vtable + 4, check_stub)
    vm.write_i32(0x4b1bc4, invalidate_stub)
    vm.uc.reg_write(UC_X86_REG_ECX, obj); vm.baseline = vm.uc.context_save()
    baseline = bytes(vm.uc.mem_read(BASE, SIZE)); text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    events = []
    def host(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', uc.mem_read(esp, 4))[0]
        if address == invalidate_stub:
            window, rectangle, erase = struct.unpack('<3I', uc.mem_read(esp + 4, 12))
            if rectangle != 0: raise AssertionError('Unexpected rectangle pointer')
            events.append({'op': 'invalidateRect', 'windowHandle': window, 'rectangle': None, 'erase': erase})
            pop, result = 16, 1
        else:
            value = struct.unpack('<i', uc.mem_read(esp + 4, 4))[0]
            events.append({'op': 'enable' if address == enable_stub else 'check', 'value': value})
            pop, result = 8, 0
        uc.reg_write(UC_X86_REG_EAX, result); uc.reg_write(UC_X86_REG_ESP, esp + pop); uc.reg_write(UC_X86_REG_EIP, ret)
    vm.uc.hook_add(UC_HOOK_CODE, host, begin=invalidate_stub, end=check_stub)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn',
        'engine_version': unicorn.__version__, 'x87_control_word': '0x037f',
        'invalidateRectImport': '004b1bc4', 'menuMap': 'analysis/message-map-candidates.json',
        'note': 'Unchanged fixed numeric menu handlers. Observational InvalidateRect BOOL1 and CCmdUI Enable/SetCheck stubs; no window or modal/OS lifecycle. Full mutable block and ordered requests recorded independently of JS.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60},
        'windowHandle': WINDOW, 'routines': {}}
    total = 0
    for row in menu_entries():
        if row['address'] in SPECIAL: continue
        source = (ROOT / f'decompiled/functions/{row["address"]:08x}.c').read_text()
        update = row['code'] != 0
        name = ('update' if update else 'command') + str(row['commandId'])
        records = []
        for inputs in input_cases(source):
            vm.uc.mem_write(BASE, baseline); vm.write_i32(TLS + 0x14, 2002)
            for value in inputs:
                vm.uc.mem_write(value['address'], struct.pack('<d', value['value']) if value['type'] == 'F64'
                                else struct.pack('<I', value['value'] & 0xffffffff))
            before = bytes(vm.uc.mem_read(BASE, SIZE)); events.clear()
            vm.call(row['address'], arguments(ui) if update else b'')
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original text changed')
            records.append({'seedAtCall': 2002, 'inputs': inputs,
                'imageInputs': [{'address': value['address'], 'bits': value['after']} for value in changed(baseline, before)],
                'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [], 'hostEvents': events.copy(),
                    'imageChanges': changed(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest()}})
        fixture['routines'][name] = {'address': row['address'], 'commandId': row['commandId'],
            'kind': 'update' if update else 'command', 'label': row['label'],
            'argumentTypes': ['CCmdUI'] if update else [], 'returnType': 'void', 'cases': records}
        total += len(records)
    save(ROOT / 'tests/fixtures/original-menu-controller.json', fixture)
    print(len(fixture['routines']), 'original handlers', total, 'cases', flush=True)


if __name__ == '__main__': main()
