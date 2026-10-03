#!/usr/bin/env python3
"""Capture complete steering/control routines and their original sound requests."""
import math
import random
import struct
import unicorn
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, i32, save

INPUTS = {
    'mouseGateY': 0x4aa824, 'viewportHeight': 0x4a72d0, 'mouseGateLimit': 0x4a5ba0,
    'gateDimension': 0x4a3f04, 'mouseMinX': 0x4aa808, 'mouseMaxX': 0x4ab150,
    'mouseX': 0x4a4f80, 'mouseCenterX': 0x4a70ec, 'viewportWidth': 0x4a763c,
    'humanBoatCount': 0x491140, 'rig': 0x49114c, 'boatClass': 0x491188,
    'speedDivisor': 0x491170, 'rudder': 0x4a7044, 'speed1': 0x4a7064, 'speed2': 0x4a7068,
    'tack1': 0x4aa734, 'tack2': 0x4aa738, 'previousTack1': 0x4abe74, 'previousTack2': 0x4abe78,
    'turnMode1': 0x4a4dfc, 'turnMode2': 0x4a4e00, 'gybeMode1': 0x4abf9c, 'gybeMode2': 0x4abfa0,
    'lockMode1': 0x4a496c, 'lockMode2': 0x4a4970, 'sailingMode1': 0x4a684c, 'sailingMode2': 0x4a6850,
    'autopilot1': 0x4a8914, 'autopilot2': 0x4a8918, 'angle1': 0x4a7bcc, 'angle2': 0x4a7bd0,
    'trueWindDirection1': 0x4aa5b4, 'downwindLimit1': 0x4a5f14, 'downwindLimit2': 0x4a5f18,
    'heading1': 0x4ac01c, 'heading2': 0x4ac020, 'tackStart1': 0x4a3a1c, 'tackStart2': 0x4a3a20,
    'time': 0x4a5b80, 'soundDisabled': 0x4ac9c0, 'moduleHandle': 0x4ac1d4,
    'firstButtonX': 0x4a774c, 'firstButtonY': 0x4aa97c, 'secondButtonX': 0x4ab188,
    'secondButtonY': 0x4a4414, 'buttonCenterX': 0x4a67b0, 'buttonCenterY': 0x4a6840,
    'uiMode': 0x4a4e8c, 'buttonLock': 0x4ac8fc,
}
DOUBLES = {'smoothHeading': 0x4a78e8, 'steeringScale': 0x4ab0c8}
OUTPUTS = {name: INPUTS[name] for name in ['rudder', 'turnMode1', 'turnMode2', 'gybeMode1',
    'gybeMode2', 'lockMode1', 'lockMode2', 'sailingMode1', 'sailingMode2', 'autopilot1',
    'autopilot2', 'heading1', 'heading2', 'tackStart1', 'tackStart2',
    'firstButtonX', 'firstButtonY', 'secondButtonX', 'secondButtonY']}


def defaults(**overrides):
    data = {'mouseGateY': 900, 'viewportHeight': 600, 'mouseGateLimit': 500, 'gateDimension': 900,
        'mouseMinX': 0, 'mouseMaxX': 720, 'mouseX': 360, 'mouseCenterX': 360, 'viewportWidth': 720,
        'humanBoatCount': 1, 'rig': -1, 'boatClass': 6, 'speedDivisor': 256, 'rudder': 33,
        'speed1': 52, 'speed2': 52, 'tack1': 1, 'tack2': -1, 'previousTack1': 1,
        'previousTack2': -1, 'turnMode1': 0, 'turnMode2': 0, 'gybeMode1': 0, 'gybeMode2': 0,
        'lockMode1': 0, 'lockMode2': 0, 'sailingMode1': 0, 'sailingMode2': 0,
        'autopilot1': 1, 'autopilot2': 1, 'angle1': 90, 'angle2': 90,
        'trueWindDirection1': 270, 'downwindLimit1': 150, 'downwindLimit2': 150,
        'heading1': 180, 'heading2': 180, 'tackStart1': -99, 'tackStart2': -88,
        'time': 123, 'soundDisabled': 0, 'moduleHandle': 0x76543210,
        'firstButtonX': 0, 'firstButtonY': 0, 'secondButtonX': 0, 'secondButtonY': 0,
        'buttonCenterX': 360, 'buttonCenterY': 200, 'uiMode': 0, 'buttonLock': 0}
    data.update(overrides)
    return data


def prepare(vm, record):
    for name, value in record['inputs'].items():
        vm.write_i32(INPUTS[name], value)
    for name, value in record['doubleInputs'].items():
        vm.uc.mem_write(DOUBLES[name], struct.pack('<d', value))


def main():
    vm = OriginalMachine()
    prng = random.Random(42_000)
    sound_calls = []
    stub = SCRATCH + 0x800
    vm.write_i32(0x4b1c18, stub)

    def play_sound(uc, address, size, user_data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<IIII', uc.mem_read(esp, 16))
        sound_calls.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1)
        uc.reg_write(UC_X86_REG_ESP, esp + 16)
        uc.reg_write(UC_X86_REG_EIP, ret)

    vm.uc.hook_add(UC_HOOK_CODE, play_sound, begin=stub, end=stub)

    def capture(address):
        sound_calls.clear()
        returned = vm.call(address)
        output = {name: vm.read_i32(location) for name, location in OUTPUTS.items()}
        raw = bytes(vm.uc.mem_read(DOUBLES['smoothHeading'], 8))
        output.update(smoothHeading=struct.unpack('<d', raw)[0], smoothHeadingBits=raw.hex(),
            returnValue=i32(returned), sounds=sound_calls.copy())
        return output

    configs = []
    for speed in [-1, 0, 20, 21, 100]:
        for rig in [-1, 1, 2]:
            for tack in [-1, 1]:
                for angle in [69, 70, 89, 90, 91, 160, 179, 180]:
                    for sailing in range(4):
                        n = len(configs)
                        configs.append({'inputs': defaults(speed1=speed, speed2=speed, rig=rig,
                            tack1=tack, tack2=tack, previousTack1=-tack if n % 2 else tack,
                            previousTack2=tack if n % 3 else -tack, angle1=angle, angle2=angle,
                            sailingMode1=sailing, sailingMode2=sailing, boatClass=1 + n % 10,
                            turnMode1=[-1, 0, 1, 2][n % 4], turnMode2=[-1, 0, 1, 2][(n // 2) % 4],
                            gybeMode1=n % 2, gybeMode2=n % 3, lockMode1=(n // 2) % 2,
                            lockMode2=(n // 3) % 2, soundDisabled=n % 2),
                            'doubleInputs': {'smoothHeading': 180.125, 'steeringScale': 0.8}})
    for mouse_y in [451, 452, 453, 900]:
        for mouse_x in [-20, -19, 299, 300, 301, 359, 360, 361, 419, 420, 421, 739, 740]:
            for human in [0, 1, 2]:
                configs.append({'inputs': defaults(mouseGateY=mouse_y, mouseX=mouse_x, humanBoatCount=human),
                    'doubleInputs': {'smoothHeading': 359.99999999999994, 'steeringScale': 0.8}})
    for heading in [-721, -360, -1, -0.0, 0, 1, math.nextafter(360, 0), 360,
                    math.nextafter(360, math.inf), 720, 721]:
        for dx in [-81, -80, -79, 0, 79, 80, 81]:
            for button in [1, 2]:
                data = defaults()
                data[f'{"first" if button == 1 else "second"}ButtonX'] = 360 + dx
                data[f'{"first" if button == 1 else "second"}ButtonY'] = 200
                configs.append({'inputs': data, 'doubleInputs': {'smoothHeading': heading, 'steeringScale': 1}})
    for _ in range(512):
        data = defaults(boatClass=prng.randrange(1, 11), speed1=prng.randrange(150),
            speed2=prng.randrange(150), speedDivisor=prng.choice([10, 15, 76, 256, 2919]),
            rig=prng.choice([-1, 1, 2]), mouseGateY=prng.randrange(601), mouseX=prng.randrange(-20, 741),
            humanBoatCount=prng.randrange(3), buttonLock=prng.randrange(2), uiMode=prng.randrange(4),
            soundDisabled=prng.randrange(2), angle1=prng.randrange(362), angle2=prng.randrange(362))
        for player in [1, 2]:
            for prefix, options in [('tack', [-1, 1]), ('previousTack', [-1, 1]),
                ('turnMode', [-1, 0, 1, 2]), ('gybeMode', [0, 1, 2]), ('lockMode', [0, 1]),
                ('sailingMode', [0, 1, 2, 3]), ('autopilot', [0, 1])]:
                data[prefix + str(player)] = prng.choice(options)
        configs.append({'inputs': data, 'doubleInputs': {'smoothHeading': prng.uniform(-720, 720),
            'steeringScale': prng.uniform(0.1, 3)}})
    routines = {}
    addresses = {'updatePlayer1Rudder': 0x42ba00, 'updatePlayer1Steering': 0x42b7f0,
                 'updatePlayer2Steering': 0x42bda0}
    for name, address in addresses.items():
        cases = []
        for record in configs:
            prepare(vm, record)
            cases.append({**record, 'expected': capture(address)})
        routines[name] = {'address': address, 'cases': cases}
    chains = []
    for name, address in addresses.items():
        initial = {'inputs': defaults(turnMode1=1, turnMode2=1),
                   'doubleInputs': {'smoothHeading': 179.99999999999997, 'steeringScale': 0.8}}
        prepare(vm, initial)
        steps = []
        for step in range(48):
            changes = {'time': step, 'angle1': 69 + step, 'angle2': 69 + step,
                       'mouseX': 360 + (step % 5 - 2) * 30}
            if step == 12:
                changes.update(tack1=-1, tack2=1)
            if step == 24:
                changes.update(gybeMode1=1, gybeMode2=1, previousTack1=-1, previousTack2=1)
            if step == 36:
                changes.update(tack1=1, tack2=-1)
            record = {'inputs': changes, 'doubleInputs': {}}
            prepare(vm, record)
            steps.append({**record, 'expected': capture(address)})
        chains.append({'routine': name, **initial, 'steps': steps})
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'sound_import_stub': '0x4b1c18', 'sound_return': 1,
        'note': 'Unmodified steering instructions; PlaySoundA stub records ordered arguments and returns BOOL1. Actual sound playback/Windows lifecycle are outside this comparison.'}
    save(ROOT / 'tests/fixtures/original-steering.json', {'provenance': provenance,
        'inputs': INPUTS, 'doubleInputs': DOUBLES, 'outputs': OUTPUTS, 'routines': routines, 'chains': chains})
    print(f'Captured {sum(len(r["cases"]) for r in routines.values())} full steering cases and {sum(len(c["steps"]) for c in chains)} chained controls')


if __name__ == '__main__':
    main()
