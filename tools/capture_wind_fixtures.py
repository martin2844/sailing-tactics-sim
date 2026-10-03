#!/usr/bin/env python3
"""Capture complete global wind updates from the unmodified 2002 executable."""
import random
import struct
import unicorn
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, i32, save

INPUTS = {
    'hour': 0x4a4be4, 'dailyMinimum': 0x4a609c, 'dailyMaximum': 0x4a7758,
    'thermalGain': 0x4a79ec, 'weather': 0x4a4958, 'shore': 0x4aa804,
    'reversal': 0x4a4378, 'baseDirection': 0x4a4430, 'baseStrength': 0x4a70dc,
    'driftRate': 0x4abc7c, 'forceCondition': 0x4a5b9c, 'mode': 0x4ac9ac,
    'time': 0x4a5b80, 'resetTime': 0x4a4168, 'tidePhaseHour': 0x4a8020,
    'tideAmplitude': 0x4ac1dc, 'target': 0x4ac9e8, 'nextTime': 0x4abae4,
    'range': 0x4aa590, 'period': 0x4aa978, 'targetIndex': 0x4911c4,
    'timeIndex': 0x4911c8, 'meanDirection': 0x4a4f8c, 'direction': 0x4ac840,
}
DOUBLES = {'driftClock': 0x4ab8b8, 'smoothDirection': 0x4aa6f0, 'dt': 0x4aa948}
OUTPUTS = {'thermal': 0x4ac568, 'strength': 0x4aa390, 'peakStrength': 0x4a70f0,
    'condition1': 0x4a71a4, 'condition2': 0x4a888c, 'meanDirection': 0x4a4f8c,
    'direction': 0x4ac840, 'target': 0x4ac9e8, 'nextTime': 0x4abae4,
    'range': 0x4aa590, 'period': 0x4aa978, 'targetIndex': 0x4911c4,
    'timeIndex': 0x4911c8, 'tide': 0x4aa298}


def defaults(**overrides):
    result = {'hour': 12, 'dailyMinimum': 8, 'dailyMaximum': 22, 'thermalGain': 9,
        'weather': 0, 'shore': 0, 'reversal': 0, 'baseDirection': 270,
        'baseStrength': 17, 'driftRate': 3, 'forceCondition': 0, 'mode': 0,
        'time': 60, 'resetTime': 0, 'tidePhaseHour': 7, 'tideAmplitude': 5,
        'target': 170, 'nextTime': 60, 'range': 33, 'period': 27,
        'targetIndex': 1, 'timeIndex': 299, 'meanDirection': 179, 'direction': 178}
    result.update(overrides)
    return result


def double_defaults(**overrides):
    result = {'driftClock': 1.5, 'smoothDirection': 169.25, 'dt': 0.146}
    result.update(overrides)
    return result


def prepare(vm, integers, doubles, seed=None):
    for field, value in integers.items():
        vm.write_i32(INPUTS[field], value)
    for field, value in doubles.items():
        vm.uc.mem_write(DOUBLES[field], struct.pack('<d', value))
    if seed is not None:
        vm.write_i32(TLS + 0x14, seed)


def capture(vm):
    returned = vm.call(0x41b5d0)
    expected = {field: vm.read_i32(address) for field, address in OUTPUTS.items()}
    raw = bytes(vm.uc.mem_read(DOUBLES['smoothDirection'], 8))
    expected.update(smoothDirection=struct.unpack('<d', raw)[0], smoothDirectionBits=raw.hex(),
        rngState=vm.read_u32(TLS + 0x14), returnValue=i32(returned))
    return expected


def main():
    vm = OriginalMachine()
    vm.call(0x415a60)
    prng = random.Random(200202)
    table = [prng.randrange(101) for _ in range(302)]
    for index, value in enumerate(table):
        vm.write_i32(0x4a9450 + index * 4, value)
    configurations = []
    for hour in range(25):
        for weather in range(7):
            configurations.append((defaults(hour=hour, weather=weather, shore=hour % 4,
                reversal=weather % 2, tidePhaseHour=weather * 4,
                baseStrength=[0, 5, 8, 9, 10, 22, 30][weather]), double_defaults()))
    for mode in [-1, 0, 1, 2]:
        for time in [-1, 0, 9, 10, 19, 20, 21, 60]:
            for next_time in [time - 1, time, time + 1]:
                configurations.append((defaults(mode=mode, time=time, resetTime=10,
                    nextTime=next_time, targetIndex=300, timeIndex=300), double_defaults()))
    for target in [0, 90, 180, 270, 360]:
        for smooth in [-90.00000000000001, -90, -89.99999999999999,
                       89.99999999999999, 90, 90.00000000000001, 270, 360]:
            configurations.append((defaults(target=target), double_defaults(smoothDirection=smooth)))
    # FST qword retains extended ST0: stored smooth direction rounds to 1, but
    # subsequent original __ftol consumes the value slightly below 1 and gives 0.
    configurations.append((defaults(target=0), double_defaults(smoothDirection=1, dt=1e-15)))
    for _ in range(512):
        time = prng.randrange(-20, 3600)
        configurations.append((defaults(hour=prng.randrange(25), weather=prng.randrange(7),
            dailyMinimum=prng.randrange(1, 12), dailyMaximum=prng.randrange(12, 31),
            thermalGain=prng.randrange(15), shore=prng.randrange(4), reversal=prng.randrange(2),
            baseDirection=prng.randrange(362), baseStrength=prng.randrange(31),
            driftRate=prng.randrange(-20, 21), forceCondition=prng.randrange(2),
            mode=prng.randrange(3), time=time, resetTime=prng.randrange(-20, 20),
            tidePhaseHour=prng.randrange(25), tideAmplitude=prng.randrange(-20, 21),
            target=prng.randrange(361), nextTime=time + prng.randrange(-1, 2),
            targetIndex=prng.choice([0, 1, 299, 300, 301]),
            timeIndex=prng.choice([0, 1, 299, 300, 301])),
            double_defaults(driftClock=prng.uniform(-300, 300),
                smoothDirection=prng.uniform(-90, 450), dt=prng.uniform(0, 3))))
    cases = []
    for integers, doubles in configurations:
        seed = prng.randrange(1 << 32)
        prepare(vm, integers, doubles, seed)
        cases.append({'inputs': integers, 'doubleInputs': doubles, 'seed': seed,
            'expected': capture(vm)})
    chains = []
    for mode in [0, 1]:
        inputs = defaults(mode=mode, time=9, resetTime=0, targetIndex=300, timeIndex=300,
            nextTime=9)
        double_inputs = double_defaults()
        seed = 2002
        prepare(vm, inputs, double_inputs, seed)
        steps = []
        for step in range(64):
            changes = {'time': 9 + step, 'hour': (step // 8) + 8}
            double_changes = {'dt': 0.125 + (step % 3) * 0.01, 'driftClock': step * 0.125}
            prepare(vm, changes, double_changes)
            steps.append({'inputs': changes, 'doubleInputs': double_changes, 'expected': capture(vm)})
        chains.append({'inputs': inputs, 'doubleInputs': double_inputs, 'seed': seed, 'steps': steps})
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'tls_accessor_stub': '0x459ed0',
        'note': 'Complete global wind routine executed from original instructions, with isolated CRT thread seed. Finite CPU-emulation evidence, not a whole-race comparison.'}
    save(ROOT / 'tests/fixtures/original-global-wind.json', {'provenance': provenance,
        'inputs': INPUTS, 'doubleInputs': DOUBLES, 'outputs': OUTPUTS,
        'randomTableAddress': 0x4a9450, 'randomTable': table, 'cases': cases, 'chains': chains})
    print(f'Captured {len(cases)} full wind states and {sum(len(chain["steps"]) for chain in chains)} chained updates')


if __name__ == '__main__':
    main()
