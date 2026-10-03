#!/usr/bin/env python3
"""Capture unchanged original startup, results, forecast and advice screens.

GetTickCount and GetSystemMetrics are explicitly owned host inputs. GDI and
CString calls record semantic observations; original scene/boat children run.
"""
import hashlib
import argparse
import json
import re
import struct
import subprocess
import sys
import pefile
import unicorn
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from capture_hud_fixtures import HudMachine
from capture_gdi_fixtures import CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, arguments
from capture_initialization_fixtures import BASE, SIZE
from native_mutable_state import image_changes


class ScreensMachine(HudMachine):
    def __init__(self, control_word=0x037f):
        super().__init__()
        self.tick = 0
        self.menu_height = 20
        def bind(count, callback):
            address = self.next_stub
            self.next_stub += 16
            def hook(uc, address, size, data):
                esp = uc.reg_read(UC_X86_REG_ESP)
                values = struct.unpack('<' + 'I' * (count + 1), uc.mem_read(esp, (count + 1) * 4))
                result = callback(values[1:])
                uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
                uc.reg_write(UC_X86_REG_ESP, esp + (count + 1) * 4)
                uc.reg_write(UC_X86_REG_EIP, values[0])
            self.extra_hooks.append(hook)
            self.uc.hook_add(unicorn.UC_HOOK_CODE, hook, begin=address, end=address)
            return address
        def tick(_):
            self.tick += 1
            return self.tick - 1
        pe = pefile.PE(str(ROOT / 'original/Tact02Demo.exe'))
        def formatted(uc, address, size, data):
            esp = uc.reg_read(UC_X86_REG_ESP)
            ret, output, format_pointer = struct.unpack('<3I', uc.mem_read(esp, 12))
            format_text = self.bytes_at(format_pointer).decode('cp1252')
            if re.sub(r'%d', '', format_text).find('%') >= 0:
                raise ValueError('Unsupported original bounded wsprintfA format')
            count = format_text.count('%d')
            values = struct.unpack('<' + 'i' * count, uc.mem_read(esp + 12, count * 4)) if count else ()
            result = (format_text % values).encode('cp1252')
            if len(result) > 1023: raise ValueError('Original wsprintfA exceeds bounded buffer')
            uc.mem_write(output, result + b'\0'); uc.reg_write(UC_X86_REG_EAX, len(result))
            uc.reg_write(UC_X86_REG_ESP, esp + 4); uc.reg_write(UC_X86_REG_EIP, ret)
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
            for item in descriptor.imports:
                if item.name == b'GetTickCount': self.write_i32(item.address, bind(0, tick))
                elif item.name == b'GetSystemMetrics': self.write_i32(item.address, bind(1, lambda v: self.menu_height if v[0] == 15 else 0))
                elif item.name == b'wsprintfA':
                    address = self.next_stub; self.next_stub += 16
                    self.extra_hooks.append(formatted)
                    self.uc.hook_add(unicorn.UC_HOOK_CODE, formatted, begin=address, end=address)
                    self.write_i32(item.address, address)
        if control_word not in (0x027f, 0x037f): raise ValueError('Unsupported original arithmetic context')
        self.uc.reg_write(UC_X86_REG_FPCW, control_word); self.baseline = self.uc.context_save()


ROUTINES = {
    'drawDemoNotice': (0x410090, 0, 216),
    'drawTackingAdvice': (0x406c90, 3, 96),
    'drawJibingAdvice': (0x4064d0, 3, 96),
    'drawAdvice': (0x4063e0, 6, 96),
    'drawForecastScreen': (0x41d890, 0, 192),
    'drawResultsScreen': (0x41c940, 0, 144),
    'drawStartScreen': (0x40f4a0, 0, 96),
}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--control-word', type=lambda value: int(value, 0), choices=[0x027f, 0x037f], default=0x037f)
    parser.add_argument('--emulated-only', action='store_true', help='Explicitly omit native original-code correction and confirmation')
    args = parser.parse_args()
    vm = ScreensMachine(args.control_word)
    uninitialized = bytes(vm.uc.mem_read(BASE, SIZE)); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    handles = [row['handleAddress'] for row in json.loads((ROOT / 'analysis/gdi-object-definitions.json').read_text())['objects']]
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': f'0x{args.control_word:04x}', 'note': 'Unchanged original screen instructions including drawing children. Explicit observational GDI/CString host bindings; bounded GetTickCount sequence and GetSystemMetrics(15) input, no font or Windows lifecycle raster identity claim.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60,
            'patches': [{'address': row['address'], 'bits': row['after']} for row in image_changes(uninitialized, baseline)]}, 'routines': {}}
    for name, (address, count, length) in ROUTINES.items():
        cases = []
        for index in range(length):
            vm.uc.mem_write(BASE, baseline); vm.reset_trace(); vm.reset_strings(); vm.tick = 0
            vm.menu_height = [20, 21, 24][index % 3]
            seed = 2002 + index; vm.write_i32(TLS + 0x14, seed)
            for handle in handles: vm.write_i32(handle, handle)
            width, height = [640, 700, 800, 899, 901, 1024][index % 6], [460, 570, 600, 720][(index // 6) % 4]
            for location, value in [(0x4a763c, width), (0x4a72d0, height), (0x4ac92c, (index // 6) % 2),
                (0x491164, [1, 2, 3, 4, 12, 0][(index // 12) % 6]), (0x4ac93c, [0, 1, 10][(index // 48) % 3]),
                (0x4ac95c, (index // 3) % 3), (0x4ac9ac, (index // 2) % 2), (0x4ac9bc, index % 2),
                (0x4ac9cc, index % 2), (0x491140, 1 + index % 2), (0x49118c, [2, 3, 8, 15, 16, 30][(index // 2) % 6]),
                (0x491188, 1 + index % 10), (0x491190, 1 + index % 13), (0x4ac944, 1 + index % 3),
                (0x4ac960, (index // 3) % 2), (0x4aa6f8, 1 + index % 15), (0x4ac858, 10 + index * 3),
                (0x4ac948, [-7, -4, -2, 0, 2, 4, 7][index % 7]), (0x4ac908, (index // 3) % 2),
                (0x4a5ba4, 10 + index), (0x4a4eec, [7, 9, 10, 11][index % 4]), (0x4a5b90, [7, 10, 13][index % 3]),
                (0x491150, [80, 100][index % 2]), (0x4a5b98, 1 + index % 3), (0x4a5bac, 6 + index % 10),
                (0x4a4f8c, (index * 29) % 360), (0x4aa804, [0, 1, 5][index % 3]),
                (0x4a70f0, 1 + index % 4), (0x4a9458, (index // 3) % 2), (0x4aa590, (index // 2) % 2),
                (0x4ac998, index % 2), (0x4a5e88, 1 + index % 8), (0x49115c, (index // 2) % 2),
                (0x4a888c, [0, 1, 3][index % 3]), (0x4aa8bc, (index // 4) % 2),
                (0x4ac1dc, [0, 1, 4][index % 3]), (0x4ac1e0, [0, 1, 3][(index // 2) % 3]),
                (0x4abc7c, index % 4), (0x4a79ec, [0, 10, 30, 60][index % 4]),
                (0x4a8a78, 1 + index % 3), (0x4a8990, 1 + (index // 2) % 8), (0x4aa838, index % 4),
                (0x4a7bd0, [20, 140, 169, 170, 180][index % 5]), (0x4a5f18, [0, 30][index % 2]),
                (0x4a4eb0, [0, 45, 90, 200][(index // 3) % 4]), (0x4aa668, (index // 3) % 2)]: vm.write_i32(location, value)
            for start, finish in [(0x4a4bf0, 0x4a4c70), (0x4a67d0, 0x4a6820)]:
                for offset, location in enumerate(range(start, finish, 4)):
                    vm.write_i32(location, [-10, 0, 1, 10][(index + offset) % 4])
            vm.write_i32(0x4a4c8c, index % 2)
            vm.write_i32(0x4a4bf0, [-10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10][index % 12])
            if name == 'drawTackingAdvice' and 32 <= index < 64:
                vm.write_i32(0x4a4bf0, 0); vm.write_i32(0x4a4eb0, 200)
            if name == 'drawDemoNotice':
                vm.write_i32(0x491164, [0, 1, 2, 3, 4, 12][(index // 6) % 6])
                vm.write_i32(0x4ac93c, [0, 1, 10][(index // 36) % 3])
                vm.write_i32(0x4ac92c, (index // 108) % 2)
            if name == 'drawStartScreen' and index >= 24:
                vm.write_i32(0x4ac9cc, 1)
            for boat in range(1, 31):
                vm.write_i32(0x4a764c + (boat - 1) * 4, 1 + (boat + index - 1) % 30)
                for race in range(3): vm.write_i32(0x4a6bb4 + boat * 16 + race * 4, [0, 100, 202, 505, 1515][(index + boat + race) % 5])
            factor = struct.unpack('<d', vm.uc.mem_read(0x484cb0, 8))[0]
            vm.uc.mem_write(0x4a8670, struct.pack('<d', height * factor))
            vm.uc.mem_write(0x4ab0c8, struct.pack('<d', width / 640))
            params = [10, 20, 30] if count == 3 else ([10, 20, width - 10, height - 10, 1, 2] if count else [])
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            try: vm.call(address, arguments(CDC, *params), count=1000000)
            except Exception:
                print(name, index, hex(vm.uc.reg_read(UC_X86_REG_EIP)), flush=True); raise
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            cases.append({'arguments': params, 'seedAtCall': seed, 'menuHeight': vm.menu_height,
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline, before)],
                'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': [], 'imageChanges': image_changes(before, after),
                    'mutableBlockHash': hashlib.sha256(after).hexdigest(), 'drawingCommands': vm.events.copy(), 'elapsedPaintTicks': max(0, vm.tick - 1)}})
        fixture['routines'][name] = {'address': address, 'argumentTypes': ['CDC'] + ['I32'] * count, 'returnType': 'void', 'cases': cases}
        print(name, len(cases), 'CDC callsites', len(vm.virtual_calls), flush=True)
    if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original game instructions changed')
    filename = 'original-screens-p53.json' if args.control_word == 0x027f else 'original-screens.json'
    (ROOT / 'tests/fixtures' / filename).write_text(json.dumps(fixture, indent=2, allow_nan=False) + '\n')
    (ROOT / 'analysis/screens-cdc-callsites.json').write_text(json.dumps({'source_sha256': EXPECTED,
        'scope': 'Dynamically observed unchanged original screen call instructions with owned CDC virtual bindings.',
        'calls': [{'address': address, 'vtableOffset': offset} for address, offset in sorted(vm.virtual_calls.items())],
        'importCalls': [{'address': address, 'name': name} for address, name in sorted(vm.import_calls.items())]}, indent=2) + '\n')
    if not args.emulated_only:
        report = 'analysis/screens-p53-native-reference-comparison.json' if args.control_word == 0x027f else 'analysis/screens-native-reference-comparison.json'
        command = [sys.executable, str(ROOT / 'tools/verify_native_state.py'), '--fixture', filename, '--report', report]
        subprocess.run(command + ['--update-fixture'], cwd=ROOT, check=True)
        subprocess.run(command, cwd=ROOT, check=True)


if __name__ == '__main__': main()
