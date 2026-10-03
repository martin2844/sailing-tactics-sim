#!/usr/bin/env python3
"""Capture the fixed original HUD nearest-boat branch without changing prior evidence."""
import argparse
import json
from pathlib import Path
from capture_native import capture

ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prefix', default=str(Path.home()/'.local/share/posey-simulator-2010-en/wineprefix'))
    args = parser.parse_args()
    manifest = json.loads((ROOT/'analysis/tutorial-inputs/hud.json').read_text())
    manifest['routine']['name'] = 'hud-nearest'
    manifest['integerInputs'].update(nearestEnabled=0x536488, nearestMode=0x4da1a8, soundDisabled=0x536484)
    for index, row in enumerate(manifest['cases']):
        row['arguments'][-1] = 1
        row['inputs'].update(humans=1, nearestEnabled=1, nearestMode=1, soundDisabled=1)
        row['seed'] = 2400 + index
    input_path = ROOT/'analysis/tutorial-inputs/hud-nearest.json'
    input_path.write_text(json.dumps(manifest, indent=2)+'\n')
    result = capture(manifest, prefix=args.prefix)
    output = ROOT/'tests/fixtures/original-drawing-hud-nearest.json'
    output.write_text(json.dumps(result, indent=2, allow_nan=False)+'\n')
    print('Captured HUD nearest branch:', len(result['cases']), 'original calls', flush=True)

if __name__ == '__main__':
    main()
