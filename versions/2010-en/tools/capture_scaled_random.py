#!/usr/bin/env python3
"""Capture signed boundaries from the fixed original 0x41e000 helper."""
import argparse
import json
from pathlib import Path
from capture_native import capture, EXPECTED

EDITION = Path(__file__).resolve().parents[1]
RANGES = [-2147483648, -2147483647, -32001, -32000, -100, -2, -1,
          0, 1, 2, 100, 32000, 32001, 2147483646, 2147483647]
SEEDS = [1, 2002, 0xffffffff]


def inputs():
    return {
        'sourceSha256': EXPECTED,
        'routine': {'name': 'scaledRandom', 'address': 0x41e000,
                    'argumentTypes': ['I32'], 'returnType': 'I32'},
        'integerInputs': {}, 'integerOutputs': {},
        'doubleInputs': {}, 'doubleOutputs': {},
        'inputEvidence': {
            'scope': 'Signed helper API boundaries; ordinary race callers use positive ranges.',
            'ranges': RANGES, 'seeds': SEEDS,
        },
        'cases': [{'label': f'range{value}-seed{seed}', 'seed': seed,
                   'arguments': [value]}
                  for seed in SEEDS for value in RANGES],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prefix')
    args = parser.parse_args()
    manifest = inputs()
    (EDITION/'analysis/scaled-random-capture-inputs.json').write_text(json.dumps(manifest, indent=2)+'\n')
    result = capture(manifest, prefix=args.prefix)
    (EDITION/'tests/fixtures/original-scaled-random.json').write_text(json.dumps(result, indent=2, allow_nan=False)+'\n')
    print('Captured', len(result['cases']), 'unchanged original signed-range helper calls')


if __name__ == '__main__':
    main()
