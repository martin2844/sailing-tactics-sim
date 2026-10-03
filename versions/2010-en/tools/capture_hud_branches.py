#!/usr/bin/env python3
"""Capture fixed original HUD text branches without replacing prior evidence."""
import argparse
import copy
import json
from pathlib import Path
from capture_native import capture, EXPECTED

ROOT = Path(__file__).resolve().parents[1]
FIELDS = {
    'sailShape': 0x4fe77c, 'windDirection': 0x522b94,
    'averageWindDirection': 0x4f7f94, 'tack': 0x522ff4,
    'upwind': 0x511624, 'upwindMode': 0x5359e4,
    'downwind': 0x4f6a6c, 'downwindMode': 0x4f3f64,
    'pointingAngle': 0x4feccc, 'windTextSuppressed': 0x53643c,
    'metricUnits': 0x5364c8, 'soundDisabled': 0x536484,
    'nearestEnabled': 0x536488,
}
BRANCHES = [
    ('sail-flat', {'sailShape': 1}, 0x4db20c),
    ('sail-medium', {'sailShape': 2}, 0x4db1fc),
    ('sail-baggy', {'sailShape': 3}, 0x4db1f0),
    ('lifted', {'windDirection': 20}, 0x4db1e8),
    ('headed', {'windDirection': 340}, 0x4db1d0),
    ('major-wind', {'windDirection': 100}, 0x4db1bc),
    ('pointing', {'metricUnits': 1, 'pointingAngle': 45}, 0x4db17c),
    ('closehauled', {'upwind': 1}, 0x4db160),
    ('footing', {'upwind': 1, 'upwindMode': 5}, 0x4db148),
    ('pinching', {'upwind': 1, 'upwindMode': -5}, 0x4db130),
    ('running', {'downwind': 1}, 0x4db11c),
    ('running-high', {'downwind': 1, 'downwindMode': -7}, 0x4db108),
    ('running-low', {'downwind': 1, 'downwindMode': 7}, 0x4db0f4),
]


def inputs():
    manifest = json.loads((ROOT/'analysis/tutorial-inputs/hud.json').read_text())
    if manifest['sourceSha256'] != EXPECTED or manifest['routine']['address'] != 0x40f240:
        raise ValueError('Fixed original HUD manifest required')
    template = copy.deepcopy(manifest['cases'][0])
    manifest['routine']['name'] = 'hud-branches'
    manifest['integerInputs'].update(FIELDS)
    manifest['doubleInputs'] = {'boatDepth': 0x4ffcc0}
    manifest['cases'] = []
    for width in [640, 1024]:
        for name, settings, literal in BRANCHES:
            row = copy.deepcopy(template)
            row['label'] = name
            row['requiredLiteralAddress'] = literal
            row['arguments'] = [0, 0, 0, width, 768, 1]
            row['inputs'].update(width=width, height=768, boatCount=5,
                                 humans=1, boatClass=6, raceTime=0,
                                 colors=0, view1=0, view2=0)
            row['inputs'].update(sailShape=1, windDirection=0,
                                 averageWindDirection=0, tack=1, upwind=0,
                                 upwindMode=0, downwind=0, downwindMode=0,
                                 pointingAngle=90, windTextSuppressed=0,
                                 metricUnits=0, soundDisabled=1, nearestEnabled=0)
            row['inputs'].update(settings)
            row['doubleInputs'] = {'boatDepth': 100.0}
            row['seed'] = 7200 + len(manifest['cases'])
            manifest['cases'].append(row)
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--prefix', default=str(Path.home()/'.local/share/posey-simulator-2010-en/wineprefix'))
    args = parser.parse_args()
    manifest = inputs()
    (ROOT/'analysis/hud-branches-capture-inputs.json').write_text(json.dumps(manifest, indent=2)+'\n')
    result = capture(manifest, prefix=args.prefix)
    (ROOT/'tests/fixtures/original-drawing-hud-branches.json').write_text(json.dumps(result, indent=2, allow_nan=False)+'\n')
    print('Captured', len(result['cases']), 'complete original HUD branch calls')


if __name__ == '__main__':
    main()
