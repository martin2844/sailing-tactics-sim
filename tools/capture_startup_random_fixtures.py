#!/usr/bin/env python3
"""Capture the unchanged original startup RNG-table routine (no JS oracle)."""
import hashlib
import struct
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, i32, save

def main():
    vm = OriginalMachine()
    baseline = bytes(vm.uc.mem_read(0x400000, 0x111000))
    cases = []
    seeds = [0, 1, 2002, 0xffffffff] + [((index * 2654435761) ^ 0x2002) & 0xffffffff for index in range(64)]
    for seed in seeds:
        vm.uc.mem_write(0x400000, baseline); vm.write_i32(TLS + 0x14, seed)
        returned = vm.call(0x42e080)
        after = bytes(vm.uc.mem_read(0x400000, 0x111000))
        if after[:0xa9450] != baseline[:0xa9450] or after[0xa9904:] != baseline[0xa9904:]: raise AssertionError('Unexpected image write')
        cases.append({'seed': seed, 'expected': {'table': list(struct.unpack('<301i', vm.uc.mem_read(0x4a9450, 1204))), 'rngState': vm.read_u32(TLS + 0x14), 'residualEAX': i32(returned), 'imageHash': hashlib.sha256(after).hexdigest()}})
    save(ROOT / 'tests/fixtures/original-startup-random.json', {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'routine': '0042e080', 'tls_accessor_stub': '00459ed0', 'note': 'Unchanged original integer-only startup routine. Exactly301calls to original scaledRandom100; table values can exceed99.'}, 'tableAddress': 0x4a9450, 'tableLength': 301, 'cases': cases})

if __name__ == '__main__': main()
