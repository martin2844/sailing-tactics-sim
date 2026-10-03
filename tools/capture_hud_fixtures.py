#!/usr/bin/env python3
"""Capture complete original HUD calls and recover their exact CDC callsites."""
import hashlib
import argparse
import json
import struct
import subprocess
import sys
import capstone
import pefile
import unicorn
from unicorn import x86_const
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP, UC_X86_REG_EAX
from capture_hud_state_fixtures import StringMachine
from capture_gdi_fixtures import DrawingMachine, CDC, VTABLE
from capture_original_fixtures import ROOT, EXPECTED, SCRATCH, TLS, arguments
from capture_initialization_fixtures import BASE, SIZE
from native_mutable_state import image_changes


class HudMachine(StringMachine, DrawingMachine):
    def __init__(self):
        super().__init__()
        self.virtual_calls = {}
        self.import_calls = {}
        self.extra_hooks = []
        self.clip_region = SCRATCH + 0x500
        self.previous_region = SCRATCH + 0x600
        def emit(op, **fields):
            self.events.append({'op': op, **fields})
        def signed(value):
            return struct.unpack('<i', struct.pack('<I', value))[0]
        def bind(callback, count):
            pointer = self.next_stub
            self.next_stub += 16
            def hook(uc, address, size, data):
                esp = uc.reg_read(UC_X86_REG_ESP)
                values = struct.unpack('<' + 'I' * (count + 1), uc.mem_read(esp, (count + 1) * 4))
                result = callback(values[1:])
                uc.reg_write(UC_X86_REG_EAX, 1 if result is None else result)
                uc.reg_write(UC_X86_REG_ESP, esp + 4 * (count + 1))
                uc.reg_write(UC_X86_REG_EIP, values[0])
            self.extra_hooks.append(hook)
            self.uc.hook_add(unicorn.UC_HOOK_CODE, hook, begin=pointer, end=pointer)
            return pointer
        def region(values):
            emit('pushClipRect', **dict(zip(['left', 'top', 'right', 'bottom'], map(signed, values))))
            return self.clip_region
        def select(values):
            handle = values[1]
            if handle == self.clip_region:
                return self.previous_region
            if handle == self.previous_region:
                emit('popClipRect')
                return self.clip_region
            emit('selectObject', handle=handle)
            return 0
        def rounded(values):
            emit('roundRect', **dict(zip(['left', 'top', 'right', 'bottom', 'ellipseWidth', 'ellipseHeight'], map(signed, values[1:]))))
        bindings = {'CreateRectRgn': (4, region), 'SelectObject': (2, select), 'DeleteObject': (1, lambda v: 1),
                    'RoundRect': (7, rounded), 'MessageBeep': (1, lambda v: emit('messageBeep', type=v[0]))}
        pe = pefile.PE(str(ROOT / 'original/Tact02Demo.exe'))
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
            for item in descriptor.imports:
                name = item.name.decode('ascii') if item.name else None
                if name in bindings:
                    count, callback = bindings[name]
                    self.write_i32(item.address, bind(callback, count))
        virtual_targets = {self.read_u32(VTABLE + offset): offset for offset in [0x2c, 0x34, 0x38, 0x64]}
        import_names = {'MoveToEx', 'LineTo', 'Rectangle', 'Ellipse', 'Polygon', 'SelectObject',
                        'SetPixel', 'SetTextColor', 'SetBkColor', 'SetBkMode', 'TextOutA', 'Arc',
                        'CreateRectRgn', 'DeleteObject', 'RoundRect', 'MessageBeep'}
        import_targets = {self.read_u32(item.address): item.name.decode('ascii')
                          for descriptor in pe.DIRECTORY_ENTRY_IMPORT for item in descriptor.imports
                          if item.name and item.name.decode('ascii') in import_names}
        disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        disassembler.detail = True
        calls = {instruction.address: instruction for instruction in disassembler.disasm(bytes(self.uc.mem_read(0x401000, 0x55000)), 0x401000)
                 if instruction.mnemonic == 'call' and instruction.operands[0].type != capstone.x86.X86_OP_IMM}
        def register(uc, instruction, number):
            if not number:
                return 0
            return uc.reg_read(getattr(x86_const, 'UC_X86_REG_' + instruction.reg_name(number).upper()))
        def original_call(uc, address, size, data):
            instruction = calls.get(address)
            if instruction is None:
                return
            operand = instruction.operands[0]
            if operand.type == capstone.x86.X86_OP_REG:
                target = register(uc, instruction, operand.reg)
            else:
                location = (register(uc, instruction, operand.mem.base) + register(uc, instruction, operand.mem.index) * operand.mem.scale + operand.mem.disp) & 0xffffffff
                target = self.read_u32(location)
            if target in virtual_targets:
                offset = virtual_targets[target]
                if address in self.virtual_calls and self.virtual_calls[address] != offset:
                    raise AssertionError('Original CDC callsite changed virtual meaning')
                self.virtual_calls[address] = offset
            elif target in import_targets:
                self.import_calls[address] = import_targets[target]
        self.uc.hook_add(unicorn.UC_HOOK_CODE, original_call, begin=0x401000, end=0x454fff)


ROUTINES = {
    'drawPlayer1Controls': (0x40a360, 6), 'drawPlayer2Controls': (0x40b130, 6),
    'drawSteeringPanel': (0x409760, 6), 'drawSecondPlayerControls': (0x40b990, 6),
    'drawTacticalPanel': (0x40db30, 6), 'drawSailingHud': (0x40c3b0, 5), 'drawCompactHud': (0x40e9a0, 5),
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--emulated-only', action='store_true', help='Capture CPU-emulated evidence only; skip native authority')
    args = parser.parse_args()
    vm = HudMachine()
    vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    handles = [row['handleAddress'] for row in json.loads((ROOT / 'analysis/gdi-object-definitions.json').read_text())['objects']]
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'note': 'Unchanged original HUD instructions, explicit observational CDC/GDI and CString byte-copy bindings. Region requests use bounded semantic clip commands; CString heap identity is not claimed.',
        'normalizations': [{'address': 0x4a7048, 'size': 4, 'type': 'CString data pointer',
                            'reason': 'Host allocation identity; prepared bytes retained for numeric-state hashes, actual string bytes compared separately as hudText.'}]},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    for name, (address, count) in ROUTINES.items():
        cases = []
        for index in range(320):
            vm.uc.mem_write(BASE, baseline)
            vm.reset_trace(); vm.reset_strings(); vm.write_i32(TLS + 0x14, 2002 + index)
            for handle in handles:
                vm.write_i32(handle, handle)
            width, height = [640, 800, 1024, 1280][index % 4], [460, 600, 720, 768][index % 4]
            for location, value in [(0x4a763c, width), (0x4a72d0, height), (0x4a5b80, [-170, 0, 1, 60][index % 4]),
                (0x4ac92c, index % 2), (0x491140, 1 + index % 2), (0x491188, 1 + index % 10),
                (0x4a5264, index % 2), (0x4ac9c8, index % 2), (0x4ac978, (index // 2) % 2),
                (0x4ac9c0, (index // 3) % 2), (0x4a4f8c, 180), (0x4a7bcc, [30, 54, 55, 89, 90, 91, 150, 179][index % 8]),
                (0x4a4dfc, [-1, 0, 1, 2, 3, 4][index % 6]), (0x4aa7e0, 2),
                (0x4a774c, 60 + index * 9), (0x4aa97c, 1 + index * 7),
                (0x4ac9e0, 20 + index * 11), (0x4ac9e4, 1 + index * 9),
                (0x4a460c, [-30, 0, 30, 180][index % 4]), (0x4a4610, [-30, 0, 30, 180][(index // 2) % 4]),
                (0x4a9444, index % 2), (0x4a9448, (index // 2) % 2), (0x4a6778, -30), (0x4a5e84, -2)]:
                vm.write_i32(location, value)
            for boat in range(1, 3):
                for base, value in [(0x4a4e88, 1 + index % 3), (0x4a6ba0, index % 4), (0x4ac018, (index * 19) % 360),
                    (0x4aa5b0, 180 + [-45, -20, 0, 20, 45][index % 5]), (0x4aa730, [-1, 1][index % 2]),
                    (0x4a7768, 1 + index % 3), (0x4a8aa8, index * 2), (0x4a7868, [0, 2, 3, 12][index % 4]),
                    (0x4a8910, index % 2), (0x4ac1e8, [-5, 0, 5][index % 3]), (0x4a4968, index % 2),
                    (0x4a72d8, 1 + index % 3)]:
                    vm.write_i32(base + boat * 4, value)
                for base, value in [(0x4a49e8, boat * 100.), (0x4a4ae0, boat * 300.), (0x4a71c8, 1.2),
                                    (0x4a7f28, [1., 10., 300.][index % 3]), (0x4a4510, 400.)]:
                    vm.uc.mem_write(base + boat * 8, struct.pack('<d', value))
            for mark in range(2, 6):
                vm.uc.mem_write(0x4a52f0 + mark * 8, struct.pack('<d', mark * 900.))
                vm.uc.mem_write(0x4a60b0 + mark * 8, struct.pack('<d', mark * 700.))
            boat = 1 + index % 2
            left, top, right, bottom = 20, 10, width - 20, height - 10
            if 64 <= index < 192:
                line = height // 30
                column = (index // 3) % 3
                control_x = [left + 8, (right + 2 * left) // 3 + 8, (left + 2 * right) // 3 + 8][column]
                control_y = top - 2 + (line * 7) // 2 + (index % 3) * (line + 1) + 2
                if name not in ['drawPlayer1Controls', 'drawPlayer2Controls']:
                    control_y += line * 7
                    vm.write_i32(0x491140, 2)
                for location, value in [(0x4a774c, control_x), (0x4aa97c, control_y), (0x4ac9e0, control_x), (0x4ac9e4, control_y),
                    (0x4a4388, (index // 3) % 2), (0x4a438c, (index // 3) % 2),
                    (0x4a85d4, [-1, 49, 50, 90][(index // 9) % 4]), (0x4a85d8, [-1, 49, 50, 90][(index // 9) % 4]),
                    (0x4a776c, 1 + (index // 27) % 3), (0x4a7770, 1 + (index // 27) % 3),
                    (0x4a4e8c, 1 + (index // 7) % 3), (0x4a4e90, 1 + (index // 7) % 3),
                    (0x4abb74, (index // 5) % 2), (0x4abb78, (index // 5) % 2)]:
                    vm.write_i32(location, value)
            if index >= 192:
                profile = index - 192
                line = height // 30
                for location, value in [(0x4911a4, 1), (0x4ac9c4, int(profile % 3 == 0)),
                    (0x49118c, 3), (0x4ac8fc, profile % 2), (0x49116c, 1 + profile % 15),
                    (0x4a4388, (profile // 7) % 2), (0x4a85d4, [-1, 49, 50, 90][(profile // 7) % 4]),
                    (0x4abb74, profile % 2), (0x4a776c, 1 + profile % 3),
                    (0x4a5424, 1), (0x4a5f14, 30), (0x4a4bd8, 0x7fffffff), (0x4ab9c4, 0x7fffffff),
                    (0x4ab9d4, 0x7fffffff), (0x4a7754, 0x7fffffff)]:
                    vm.write_i32(location, value)
                for location, value in [(0x4a49e8 + 24, 190.), (0x4a4ae0 + 24, 350.),
                                        (0x4a71c8 + 24, 2.9999999999999996)]:
                    vm.uc.mem_write(location, struct.pack('<d', value))
                for vessel in range(1, 3):
                    vm.write_i32(0x4aa5b0 + vessel * 4, 180 + [0, 70, 71, -71, 120, 180, -180][profile % 7])
                if name in ['drawTacticalPanel', 'drawSailingHud']:
                    control_x = left + 8
                    control_y = top + 1 + (profile % 7) * line + 2
                else:
                    column = (profile // 3) % 3
                    control_x = [left + 8, (right + 2 * left) // 3 + 8, (left + 2 * right) // 3 + 8][column]
                    control_y = top - 2 + (line * 7) // 2 + (profile % 3) * (line + 1) + 2
                    if name not in ['drawPlayer1Controls', 'drawPlayer2Controls']:
                        control_y += line * 7
                        vm.write_i32(0x491140, 2)
                for location, value in [(0x4a774c, control_x), (0x4aa97c, control_y),
                    (0x4ac9e0, control_x), (0x4ac9e4, control_y)]:
                    vm.write_i32(location, value)
                if profile % 2 == 1:
                    vm.write_i32(0x4aa97c, 0)
                if profile % 4 >= 2:
                    vm.write_i32(0x4a5ba0, 100000)
                    vm.write_i32(0x4a3f04, 0)
                    vm.write_i32(0x4a4f80, 50)
                    vm.write_i32(0x4aa808, 50)
                    vm.write_i32(0x4ab150, 50)
            params = [left, top, right, bottom, boat]
            if count == 6:
                if name == 'drawTacticalPanel':
                    params[3] = 120
                params.append(height // 30)
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            try:
                vm.call(address, arguments(CDC, *params), count=500000)
            except Exception:
                print(name, index, hex(vm.uc.reg_read(UC_X86_REG_EIP)), flush=True)
                raise
            after = bytearray(vm.uc.mem_read(BASE, SIZE))
            pointer_offset = 0x4a7048 - BASE
            original_pointer = struct.unpack('<I', after[pointer_offset:pointer_offset + 4])[0]
            after[pointer_offset:pointer_offset + 4] = before[pointer_offset:pointer_offset + 4]
            expected = {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [], 'imageChanges': image_changes(before, after),
                        'mutableBlockHash': hashlib.sha256(after).hexdigest(), 'drawingCommands': vm.events.copy()}
            if name in ['drawSteeringPanel', 'drawSecondPlayerControls', 'drawTacticalPanel', 'drawSailingHud']:
                pointer = vm.read_u32(0x4a7048)
                expected['hudText'] = vm.bytes_at(pointer).decode('cp1252') if pointer else ''
            cases.append({'arguments': params, 'seedAtCall': 2002 + index,
                          'originalCStringOutputPointer': original_pointer,
                          'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline, before)], 'expected': expected})
        fixture['routines'][name] = {'address': address, 'argumentTypes': ['CDC'] + ['I32'] * count, 'returnType': 'void', 'cases': cases}
        print(name, len(cases), 'CDC callsites', len(vm.virtual_calls), flush=True)
    if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text:
        raise AssertionError('Original game code changed')
    (ROOT / 'tests/fixtures/original-hud.json').write_text(json.dumps(fixture, indent=2, allow_nan=False) + '\n')
    (ROOT / 'analysis/hud-cdc-callsites.json').write_text(json.dumps({'source_sha256': EXPECTED,
        'scope': 'Dynamically observed unchanged original call instructions with explicitly owned CDC virtual bindings.',
        'calls': [{'address': address, 'vtableOffset': offset} for address, offset in sorted(vm.virtual_calls.items())],
        'importCalls': [{'address': address, 'name': name} for address, name in sorted(vm.import_calls.items())]}, indent=2) + '\n')
    if not args.emulated_only:
        command = [sys.executable, str(ROOT / 'tools/verify_native_state.py'), '--fixture', 'original-hud.json',
                   '--report', str(ROOT / 'analysis/hud-native-reference-comparison.json')]
        subprocess.run(command + ['--update-fixture'], check=True)
        subprocess.run(command, check=True)


if __name__ == '__main__':
    main()
