#!/usr/bin/env python3
"""Verify preserved native screen/control fixtures and publish compact proof metadata."""
import hashlib
import json
import subprocess
from pathlib import Path
from capture_native import EXPECTED
from capture_closed_drawing import ROUTINES

ROOT = Path(__file__).resolve().parents[1]

def verify():
    subprocess.run(['node', '--test', str(ROOT/'tests/closed-drawing.test.js')], check=True, cwd=ROOT)
    groups = []
    for name in ROUTINES:
        path = ROOT/f'tests/fixtures/original-drawing-{name}.json'
        raw = path.read_bytes()
        fixture = json.loads(raw)
        provenance = fixture['provenance']
        if fixture['sourceSha256'] != EXPECTED or provenance['x87ControlWord'] != '0x027f':
            raise ValueError('Original edition/precision differs')
        if not provenance['loadedOriginalTextUnchanged'] or not provenance['originalFileUnchanged']:
            raise ValueError('Original instruction integrity not proven')
        groups.append({'routine':fixture['routine'], 'fixture':str(path.relative_to(ROOT)),
            'fixtureSha256':hashlib.sha256(raw).hexdigest(), 'cases':len(fixture['cases']),
            'orderedDrawingRequests':sum(len(case['expected'].get('drawingCommands', [])) for case in fixture['cases']),
            'runnerSourceSha256':provenance['runnerSourceSha256'],
            'runnerSha256':provenance['runnerSha256'],
            'loadedOriginalTextUnchanged':True, 'originalFileUnchanged':True})
    report = {'format':1, 'sourceSha256':EXPECTED, 'x87ControlWord':'0x027f',
        'allFixtureCasesMatch':True, 'cases':sum(row['cases'] for row in groups),
        'originalRoutines':len(groups), 'mutableBlock':{'address':0x4da000, 'bytes':394632},
        'comparison':'Independent original data and JS integer trig; every mutable byte/hash, all36 semantic global CStrings, RNG and ordered drawing requests. No tolerances.',
        'scope':'Finite standalone cases of these ten routines. Broader scene, chart, HUD and connected-frame behavior requires separate proof.',
        'groups':groups}
    output = ROOT/'analysis/closed-drawing-native-reference-comparison.json'
    output.write_text(json.dumps(report, indent=2)+'\n')
    print('Verified', report['cases'], 'complete original screen/control calls')

if __name__ == '__main__':
    verify()
