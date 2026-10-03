#!/usr/bin/env python3
"""Capture original paint dispatch/layout with explicit child/Win32 bindings.

The child routines are separate verified translations. This fixture measures
their original caller's argument order, screen branches, state re-reads, caps,
surface requests and timing, rather than asserting a complete Windows session.
"""
import hashlib
import itertools
import json
import struct
import pefile
import unicorn
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_hud_fixtures import HudMachine
from capture_gdi_fixtures import CDC, VTABLE
from capture_original_fixtures import ROOT, EXPECTED, SCRATCH, TLS, arguments
from capture_initialization_fixtures import BASE, SIZE
from native_mutable_state import image_changes

CHILDREN = {
    0x417790: ('initializeBoatOptions', 0), 0x413f00: ('initializeRace', 0),
    0x40f4a0: ('drawStartScreen', 1), 0x41c940: ('drawResultsScreen', 1),
    0x41bb40: ('drawPauseScreen', 1), 0x41d890: ('drawForecastScreen', 1),
    0x407e40: ('drawChart', 7), 0x423640: ('drawCircle', 4),
    0x404880: ('drawScene', 6), 0x40c3b0: ('drawSailingHud', 6),
    0x40e9a0: ('drawCompactHud', 6), 0x4063e0: ('drawAdvice', 7),
}


class PaintMachine(HudMachine):
    def __init__(self, frame=False):
        super().__init__()
        self.calls = []
        self.ticks = 0
        self.buffer = 0
        self.caps = {12: 32, 8: 800, 10: 600}
        self.callbacks = []
        self.app = SCRATCH + 0x900
        self.previous = SCRATCH + 0xa00
        self.write_i32(self.app + 8, 0x2002)
        self.write_i32(self.previous + 4, 0x42)
        self.write_i32(CDC + 8, 1)
        def emit(name, values=None):
            row = {'name': name}
            if values is not None: row['arguments'] = values
            self.calls.append(row)
        def bind(address, count, callback, cdecl=False):
            def hook(uc, addr, size, data):
                esp = uc.reg_read(UC_X86_REG_ESP)
                values = struct.unpack('<' + 'I' * (count + 1), uc.mem_read(esp, 4 * (count + 1)))
                result = callback(uc.reg_read(UC_X86_REG_ECX), values[1:])
                uc.reg_write(UC_X86_REG_EAX, 0 if result is None else result & 0xffffffff)
                uc.reg_write(UC_X86_REG_ESP, esp + 4 + (0 if cdecl else 4 * count))
                uc.reg_write(UC_X86_REG_EIP, values[0])
            self.callbacks.append(hook)
            self.uc.hook_add(unicorn.UC_HOOK_CODE, hook, begin=address, end=address)
        def signed(value): return struct.unpack('<i', struct.pack('<I', value))[0]
        def construct(this, values):
            self.buffer = this
            self.uc.mem_write(this, struct.pack('<4I', VTABLE, 2, 2, 0))
            emit('constructBufferedDC')
        bind(0x470000, 0, construct)
        bind(0x47b918, 0, lambda this, values: (emit('applicationInstance'), self.app)[1])
        bind(0x470a2d, 1, lambda this, values: (self.write_i32(this + 4, values[0]), emit('attachBitmap'), 1)[2])
        bind(0x4700ca, 1, lambda this, values: (self.write_i32(this + 4, values[0]), emit('attachCompatibleDC'), 1)[2])
        bind(0x470205, 2, lambda this, values: (emit('selectBitmap', [values[1]]), self.previous)[1])
        def destroy_object(this, values):
            if self.read_u32(this + 4):
                emit('deleteBitmap')
                self.write_i32(this + 4, 0)
            return 1
        bind(0x470a84, 0, destroy_object)
        bind(0x470132, 0, lambda this, values: emit('destroyBufferedDC'))
        for address, (name, count) in CHILDREN.items():
            bind(address, count, lambda this, values, name=name, count=count: emit(name, list(map(signed, values[1:])) if count else []), cdecl=True)
        if not frame:
            bind(0x404020, 1, lambda this, values: emit('drawSimulationFrame', []), cdecl=True)
        else:
            # Numerical prefix is independently translated in engine/frame.js.
            # Fixed original calls are observational here, with no child writes.
            for address in [0x41b5d0, 0x42b7f0, 0x42bda0, 0x42adb0, 0x44dfe0, 0x44dbc0]:
                bind(address, 0, lambda this, values: None, cdecl=True)
        def caps(this, values): emit('getDeviceCaps', [values[1]]); return self.caps[values[1]]
        def tick(this, values): result = self.ticks; self.ticks += 1; return result
        def cursor(this, values): self.uc.mem_write(values[0], struct.pack('<ii', 12, 34)); return 1
        def bitmap(this, values): emit('createBitmap', list(map(signed, values))); return 0x41
        def compatible(this, values): emit('createCompatibleDC'); return 2
        def blit(this, values): emit('bitBlt', list(map(signed, [*values[1:5], *values[6:9]]))); return 1
        def invalidate(this, values):
            rectangle = None if values[1] == 0 else list(struct.unpack('<4i', self.uc.mem_read(values[1], 16)))
            emit('invalidateRect', [values[0], rectangle, values[2]]); return 1
        imports = {'GetDeviceCaps': (2, caps), 'CreateBitmap': (5, bitmap), 'CreateCompatibleDC': (1, compatible),
                   'BitBlt': (9, blit), 'InvalidateRect': (3, invalidate), 'GetTickCount': (0, tick), 'GetCursorPos': (1, cursor)}
        pe = pefile.PE(str(ROOT / 'original/Tact02Demo.exe'))
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
            for item in descriptor.imports:
                name = item.name.decode('ascii') if item.name else None
                if name in imports:
                    count, callback = imports[name]
                    stub = self.next_stub; self.next_stub += 16
                    bind(stub, count, callback)
                    self.write_i32(item.address, stub)


def main():
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'scope': 'Complete original paint lifecycle and frame rendering caller control flow. Explicit child routines and surface/window/timer bindings; numerical frame children independently validated elsewhere. No Windows surface identity or pixels claim.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    for frame in [False, True]:
        vm = PaintMachine(frame); vm.call(0x415a60)
        baseline = bytes(vm.uc.mem_read(BASE, SIZE)); original_text = bytes(vm.uc.mem_read(0x401000, 0x80800))
        cases = []
        profiles = list(itertools.product(range(3), [0, 1, -1], [0, 2, 300, 6, -1], range(5))) if not frame else list(itertools.product([1, 2, 0], [1, 2, 3, 4], [0, 1], [0, 1], [0, 2, 300]))
        for index, profile in enumerate(profiles):
            vm.uc.mem_write(BASE, baseline); vm.calls.clear(); vm.events.clear(); vm.ticks = 0
            vm.write_i32(TLS + 0x14, 2002)
            width, height = [(640, 480), (800, 600), (801, 600), (1040, 768), (1920, 1080)][index % 5]
            vm.caps = {12: [1, 8, 16, 24, 32][index % 5], 8: width, 10: height}
            vm.write_i32(0x4a763c, width); vm.write_i32(0x4a72d0, height)
            for location, value in [(0x4a4f80, 12), (0x4a5ba0, 34), (0x4a4e7c, 17), (0x4a4e80, 19),
                                    (0x49118c, 0), (0x4911c0, 0), (0x4a76c8, 12345), (0x4a4168, 54321), (0x4a5b80, 0)]:
                vm.write_i32(location, value)
            if not frame:
                state, finished, overlay, view = profile
                for location, value in [(0x4ac8f8, state), (0x4ac93c, finished), (0x4ac980, overlay),
                    (0x4ac938, int(view == 1)), (0x4aa980, int(view == 2)), (0x4ac970, int(view == 3)), (0x4ac974, int(view == 4)),
                    (0x4ac8fc, index % 2), (0x4ac97c, (index // 2) % 2), (0x4ac9a4, (index // 3) % 2)]:
                    vm.write_i32(location, value)
                original_arguments = arguments(CDC)
                this = SCRATCH + 0xc00; vm.write_i32(this + 0x1c, 0x2002)
                register = {'ecx': this}; routine = 0x403bb0; name = 'paintLifecycle'
            else:
                humans, view, clutter, advice, pause = profile
                for location, value in [(0x491140, humans), (0x4a4e8c, view), (0x4ac9c8, clutter),
                    (0x4ac9b4, advice), (0x4ac980, pause), (0x49116c, 1 + index % 15), (0x4ac9a4, index % 2)]:
                    vm.write_i32(location, value)
                original_arguments = arguments(CDC); register = {}; routine = 0x404020; name = 'drawSimulationFrame'
            before = bytes(vm.uc.mem_read(BASE, SIZE))
            saved_context = vm.baseline
            if register:
                vm.uc.context_restore(saved_context)
                vm.uc.reg_write(UC_X86_REG_ECX, register['ecx'])
                vm.baseline = vm.uc.context_save()
            vm.call(routine, original_arguments, count=1000000)
            vm.baseline = saved_context
            after = bytes(vm.uc.mem_read(BASE, SIZE))
            cases.append({'caps': vm.caps, 'applicationInstance': 0x2002, 'windowHandle': 0x2002,
                'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in image_changes(baseline, before)],
                'expected': {'imageChanges': image_changes(before, after), 'mutableBlockHash': hashlib.sha256(after).hexdigest(),
                    'calls': vm.calls.copy(), 'drawingCommands': vm.events.copy(), 'elapsedPaintTicks': max(0, vm.ticks - 1)}})
        if bytes(vm.uc.mem_read(0x401000, 0x80800)) != original_text: raise AssertionError('Original code changed')
        fixture['routines'][name] = {'address': routine, 'cases': cases}
        print(name, len(cases), flush=True)
    (ROOT / 'tests/fixtures/original-paint-lifecycle.json').write_text(json.dumps(fixture, indent=2) + '\n')


if __name__ == '__main__': main()
