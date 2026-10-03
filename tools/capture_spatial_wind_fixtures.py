#!/usr/bin/env python3
"""Original spatial wind cases with independent reset and whole-image write capture."""
import json
import random
import struct
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, arguments, i32, save
from capture_current_fixtures import INPUTS as CURRENT_INPUTS, defaults as current_defaults

INPUTS = {**CURRENT_INPUTS, 'strength': 0x4aa390, 'thermal': 0x4ac568,
    'dailyMinimum': 0x4a609c, 'shelterMode': 0x4ac1e0, 'reversal': 0x4ac998,
    'sectorCount': 0x4ac9f4}

def main():
    vm = OriginalMachine()
    vm.call(0x415a60)
    current = json.loads((ROOT / 'tests/fixtures/original-current.json').read_text())
    baseline_fields = []
    def store(address, bits):
        vm.uc.mem_write(address, bytes.fromhex(bits))
        baseline_fields.append({'address': address, 'bits': bits})
    for spec in current['geometry'].values():
        fmt = '<d' if spec['address'] == 0x4a8028 else '<i'
        for index, value in enumerate(spec['values']):
            store(spec['address'] + index * struct.calcsize(fmt), struct.pack(fmt, value).hex())
    for address, value in [(0x4a6470, 1.25), (0x4abe60, 0.875)]:
        store(address, struct.pack('<d', value).hex())
    for patch in range(5):
        for address, value in [(0x4abd90, [-400.25, 0.25, 0.25, 600.5, -700.75][patch]),
                               (0x4a4730, [-400.75, 0.75, 0.75, 700.5, 900.25][patch])]:
            store(address + patch * 8, struct.pack('<d', value).hex())
        for address, value in [(0x4a4ec4, [150, 80, 50, 200, 300][patch]),
                               (0x4a4e9c, [8, -5, 12, -10, 6][patch])]:
            store(address + patch * 4, struct.pack('<i', value).hex())
        store(0x4ac0a0 + (patch + 1) * 4, struct.pack('<i', [30, 90, 270, 345, 180][patch]).hex())
    # These direction arrays overlap current's fixed three branch directions.
    for sector in range(3):
        for address, value in [(0x4a67bc, [90, 180, 270][sector]),
                               (0x4a7184, [0, 60, 120][sector]),
                               (0x4a5a54, [60, 120, 180][sector])]:
            store(address + sector * 4, struct.pack('<i', value).hex())
    baseline = bytes(vm.uc.mem_read(0x400000, 0x111000))
    records = []
    prng = random.Random(0x426150)
    for weather in range(8):
        for x, y in [(-650,-501),(-649,-501),(649,-801),(650,-801),
                     (-899,501),(499,801),(500,801),(0,0),(1,1),(-400,-400),(601,701),(-701,901)]:
            for wind in [0, 19, 20, 29, 30, 59, 60, 140, 141, 165, 166, 180, 199, 200, 224, 225, 270, 320, 321, 330, 331, 360]:
                n = len(records)
                records.append({'x': x, 'y': y, 'boat': n % 4,
                    'previousDirection': [0,30,89,90,180,270,271,345,360][n % 9],
                    'cachedMetric': [29,30,89,90,91][n % 5],
                    'inputs': {**current_defaults(weather=weather, windDirection=wind, course=[1,6,8,9,10][n%5],
                        islandFlag=(n//4)%2, spatialVariant=n%2), 'strength': [6,10,30,100][n%4],
                        'dailyMinimum': 40, 'thermal': [0,49,50,51,100][n%5],
                        'shelterMode': (n//2)%2, 'reversal': (n//8)%2, 'sectorCount': 3}})
    for _ in range(384):
        records.append({'x': prng.randrange(-1300,1301), 'y': prng.randrange(-1300,1301),
            'boat': prng.randrange(4), 'previousDirection': prng.randrange(361),
            'cachedMetric': prng.uniform(-10,120),
            'inputs': {**current_defaults(weather=prng.randrange(8), windDirection=prng.randrange(361),
                course=prng.randrange(1,12), islandFlag=prng.randrange(2), spatialVariant=prng.randrange(2)),
                'strength': prng.randrange(1,151), 'dailyMinimum': prng.randrange(-50,100),
                'thermal': prng.randrange(-50,151), 'shelterMode': prng.randrange(2),
                'reversal': prng.randrange(2), 'sectorCount': prng.randrange(4)}})
    writes = []
    def record_write(uc, access, address, size, value, data):
        if 0x400000 <= address < 0x511000:
            writes.append((address,size))
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, record_write)
    cases = []
    for record in records:
        vm.uc.mem_write(0x400000, baseline)
        for name,value in record['inputs'].items():
            vm.write_i32(INPUTS[name],value)
        vm.write_i32(0x4aa5b0 + record['boat'] * 4, record['previousDirection'])
        vm.uc.mem_write(0x4a7f28 + record['boat'] * 8, struct.pack('<d',record['cachedMetric']))
        writes.clear()
        result = vm.call(0x426150,arguments(record['x'],record['y'],record['boat']))
        stores = [{'address': address, 'size': size, 'bits': bytes(vm.uc.mem_read(address,size)).hex()}
                  for address,size in sorted(set(writes))]
        cases.append({**record, 'expected': {'returnValue': i32(result), 'stores': stores}})
    save(ROOT / 'tests/fixtures/original-spatial-wind.json', {
        'provenance': {'sha256': EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,
            'x87_control_word':'0x037f', 'note':'Original spatial wind instructions; synthetic coastline, boundary, sector and patch inputs; independent image resets. All image stores captured. Full race parity remains unproven.'},
        'address':0x426150,'inputs':INPUTS,'baseline':baseline_fields,'cases':cases})
    print(f'Captured {len(cases)} spatial wind cases with every image store')

if __name__ == '__main__':
    main()
