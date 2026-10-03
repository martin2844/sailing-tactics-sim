#!/usr/bin/env python3
"""Capture complete unchanged 404020 frames after original race initialization.

Every numerical and rendering child runs. The only bindings are CString/GDI
observations, owned cursor/timer inputs, PlaySound recording and original CRT
TLS access. GetPixel returns and consumed retained shoreline stack words are
explicit evidence, not inferred from JavaScript. 027f startup evidence remains
separate from the earlier 037f isolated-routine evidence.
"""
import argparse
import hashlib
import itertools
import json
import struct
import subprocess
import sys
import pefile
import unicorn
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW
from capture_screens_fixtures import ScreensMachine
from capture_gdi_fixtures import CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, arguments, save
from capture_initialization_fixtures import BASE, SIZE
from capture_encounter_fixtures import merged_ranges
from native_mutable_state import image_changes


class ConnectedFrameMachine(ScreensMachine):
    def __init__(self, control_word):
        super().__init__()
        self.cursor = (12, 34)
        self.sounds = []
        self.shore_observations = []
        self.shore_entry = 0
        self.shore_first = 0
        self.pixels = []
        def bind(count, callback):
            pointer = self.next_stub; self.next_stub += 16
            def hook(uc, address, size, data):
                esp = uc.reg_read(UC_X86_REG_ESP)
                values = struct.unpack('<' + 'I' * (count + 1), uc.mem_read(esp, (count + 1) * 4))
                result = callback(values[1:])
                uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
                uc.reg_write(UC_X86_REG_ESP, esp + (count + 1) * 4); uc.reg_write(UC_X86_REG_EIP, values[0])
            self.extra_hooks.append(hook); self.uc.hook_add(unicorn.UC_HOOK_CODE, hook, begin=pointer, end=pointer)
            return pointer
        def cursor(values): self.uc.mem_write(values[0], struct.pack('<2i', *self.cursor)); return 1
        def sound(values):
            self.sounds.append(dict(zip(['resourceId', 'moduleHandle', 'flags'], values))); return 1
        pe = pefile.PE(str(ROOT / 'original/Tact02Demo.exe'))
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
            for item in descriptor.imports:
                if item.name == b'GetCursorPos': self.write_i32(item.address, bind(1, cursor))
                elif item.name == b'PlaySoundA': self.write_i32(item.address, bind(3, sound))
        def inspect(uc, address, size, data):
            if address == 0x42d120:
                esp = uc.reg_read(UC_X86_REG_ESP); self.shore_entry = esp; self.shore_first = self.read_i32(esp + 12)
                self.shore_observations.append({'entryArguments': list(struct.unpack('<11I', uc.mem_read(esp + 4, 44))),
                    'centerProjectedY': self.read_i32(esp - 0xb6c), 'previousX': self.read_i32(esp - 0xb54 + self.shore_first * 4),
                    'previousTreeY': self.read_i32(esp - 0x2d8 + self.shore_first * 4), 'consumed': {}})
            if address in [0x42d668, 0x42d6c5]: self.shore_observations[-1]['consumed']['previousX'] = self.read_i32(self.shore_entry - 0xb54 + self.shore_first * 4)
            if address in [0x42d67d, 0x42d6dd]: self.shore_observations[-1]['consumed']['previousTreeY'] = self.read_i32(self.shore_entry - 0x2d8 + self.shore_first * 4)
        for address in [0x42d120, 0x42d668, 0x42d6c5, 0x42d67d, 0x42d6dd]: self.uc.hook_add(unicorn.UC_HOOK_CODE, inspect, begin=address, end=address)
        def pixel(x, y, index): self.pixels.append(0xffffff); return 0xffffff
        self.pixel_sampler = pixel
        self.uc.reg_write(UC_X86_REG_FPCW, control_word); self.baseline = self.uc.context_save()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--control-word', type=lambda value: int(value, 0), choices=[0x027f, 0x037f], default=0x027f)
    parser.add_argument('--frames', type=int, default=3)
    parser.add_argument('--limit', type=int, default=0)
    parser.add_argument('--emulated-only', action='store_true', help='Explicitly omit native original-code correction and confirmation')
    args = parser.parse_args()
    if not 1 <= args.frames <= 20 or not 0 <= args.limit <= 256: raise ValueError('Frame/profile bound exceeded')
    vm = ConnectedFrameMachine(args.control_word)
    uninitialized = bytes(vm.uc.mem_read(BASE, SIZE)); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE)); original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    handles = [row['handleAddress'] for row in json.loads((ROOT / 'analysis/gdi-object-definitions.json').read_text())['objects']]
    writes = []
    vm.uc.hook_add(unicorn.UC_HOOK_MEM_WRITE, lambda uc, access, address, size, value, data: writes.append((address, size)) if BASE <= address and address + size <= BASE + SIZE else None)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': f'0x{args.control_word:04x}', 'tls_accessor_stub': '00459ed0',
        'note': 'Complete original404020 numerical/rendering instructions after original42e080/417790/413f00 race preparation. Every game child executes; explicit CString/GDI observations, GetCursorPos inputs, white GetPixel returns and unit-increment GetTickCount. Finite prepared states; native x87 and retained-stack authority required before parity claims.',
        'normalizations': [{'address': 0x4a7048, 'size': 4, 'type': 'CString data pointer', 'reason': 'Host allocation identity; original pointer retained separately and text bytes compared as hudText.'}]},
        'mutableBlock': {'address': BASE, 'size': SIZE},
        'baseline': {'integerTrigRoutine': 0x415a60, 'patches': [{'address': row['address'], 'bits': row['after']} for row in image_changes(uninitialized, baseline)]},
        'routines': {'drawSimulationFrame': {'address': 0x404020, 'argumentTypes': ['CDC'], 'returnType': 'void', 'cases': []}}}
    filename = f'original-connected-frames-{"p53" if args.control_word == 0x027f else "p64"}.json'
    profiles = list(itertools.product([1, 2, 4, 6, 8], [1, 2], [1, 2, 3], [0, 1]))
    if args.limit: profiles = profiles[:args.limit]
    for profile_index, (course, humans, view, island) in enumerate(profiles):
        vm.uc.mem_write(BASE, baseline); vm.write_i32(TLS + 0x14, 2002 + profile_index)
        for address, value in [(0x491144, 12), (0x491188, 6), (0x491194, course), (0x49116c, 8), (0x491170, 171),
            (0x491140, humans), (0x49118c, 5), (0x4911cc, 5), (0x4a5a4c, island), (0x4ac9ac, 0),
            (0x4ac8f8, 2), (0x4a763c, 1024), (0x4a72d0, 730), (0x4aaa1c, 24), (0x4ac9c0, 0)]: vm.write_i32(address, value)
        vm.uc.mem_write(0x4ab0c8, struct.pack('<d', 1.024)); vm.uc.mem_write(0x4a8670, struct.pack('<d', .768))
        vm.call(0x42e080); vm.call(0x417790); vm.call(0x413f00, count=5000000)
        phase = [-150., -1., 0., 60., 3599.9][profile_index % 5]
        vm.uc.mem_write(0x4ac1f8, struct.pack('<d', phase)); vm.write_i32(0x4a5b80, int(phase))
        vm.call(0x44dfe0)
        if profile_index % 10 in [1, 2]: vm.write_i32(0x4ac9ec, profile_index % 10)
        for handle in handles: vm.write_i32(handle, handle)
        for boat in [1, 2]: vm.write_i32(0x4a4e88 + boat * 4, view)
        vm.write_i32(0x4ac980, 0); vm.write_i32(0x4ac9c8, profile_index % 2)
        for frame in range(args.frames):
            before = bytes(vm.uc.mem_read(BASE, SIZE)); seed = vm.read_u32(TLS + 0x14)
            vm.cursor = (12 + frame * 7, 34 + profile_index * 3); vm.reset_trace(); vm.reset_strings(); vm.tick = 0
            vm.sounds.clear(); vm.shore_observations.clear(); vm.pixels.clear(); writes.clear()
            try: vm.call(0x404020, arguments(CDC), count=20000000)
            except Exception:
                print('drawSimulationFrame failed', profile_index, frame, hex(vm.uc.reg_read(UC_X86_REG_EIP)), flush=True); raise
            after = bytearray(vm.uc.mem_read(BASE, SIZE)); pointer = vm.read_u32(0x4a7048)
            hud_text = vm.bytes_at(pointer).decode('cp1252') if pointer else ''
            pointer_offset = 0x4a7048 - BASE; after[pointer_offset:pointer_offset + 4] = before[pointer_offset:pointer_offset + 4]
            if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text: raise AssertionError('Original game text changed')
            fixture['routines']['drawSimulationFrame']['cases'].append({'arguments': [], 'seedAtCall': seed,
                'configuration': {'course': course, 'humans': humans, 'view': view, 'island': island, 'phase': phase},
                'profileIndex': profile_index, 'frameIndex': frame, 'cursor': {'x': vm.cursor[0], 'y': vm.cursor[1]},
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline, before)],
                'pixelReadValues': vm.pixels.copy(), 'shorelineStackObservations': json.loads(json.dumps(vm.shore_observations)),
                'originalCStringOutputPointer': pointer, 'imageWrites': [{'address': start, 'size': end - start} for start, end in merged_ranges(writes)],
                'expected': {'rngState': vm.read_u32(TLS + 0x14), 'sounds': vm.sounds.copy(), 'imageChanges': image_changes(before, after),
                    'mutableBlockHash': hashlib.sha256(after).hexdigest(), 'drawingCommands': vm.events.copy(), 'hudText': hud_text,
                    'elapsedPaintTicks': max(0, vm.tick - 1)}})
            print('drawSimulationFrame', len(fixture['routines']['drawSimulationFrame']['cases']), course, humans, view, island, len(vm.events), flush=True)
        save(ROOT / 'tests/fixtures' / filename, fixture)
    save(ROOT / 'analysis/frame-cdc-callsites.json', {'source_sha256': EXPECTED,
        'calls': [{'address': address, 'vtableOffset': offset} for address, offset in sorted(vm.virtual_calls.items())],
        'importCalls': [{'address': address, 'name': name} for address, name in sorted(vm.import_calls.items())]})
    if not args.emulated_only:
        report = f'analysis/connected-frames-{"p53" if args.control_word == 0x027f else "p64"}-native-reference-comparison.json'
        command = [sys.executable, str(ROOT / 'tools/verify_native_state.py'), '--fixture', filename, '--report', report]
        subprocess.run(command + ['--update-fixture'], cwd=ROOT, check=True)
        subprocess.run(command, cwd=ROOT, check=True)


if __name__ == '__main__': main()
