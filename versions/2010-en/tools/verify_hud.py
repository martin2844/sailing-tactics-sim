#!/usr/bin/env python3
"""Verify exact original HUD fixtures and publish compact reference metadata."""
import hashlib
import json
import subprocess
import argparse
from pathlib import Path
from capture_native import EXPECTED

ROOT=Path(__file__).resolve().parents[1]

def verify(branches_only=False):
    tests=['hud-branches.test.js'] if branches_only else ['hud.test.js','hud-branches.test.js']
    subprocess.run(['node','--test',*[str(ROOT/'tests'/name) for name in tests]],check=True,cwd=ROOT)
    groups=[]
    for name in (['hud-branches'] if branches_only else ['hud-with-sounds','compact-hud','hud-nearest','hud-branches']):
        path=ROOT/f'tests/fixtures/original-drawing-{name}.json';raw=path.read_bytes()
        fixture=json.loads(raw);provenance=fixture['provenance']
        if fixture['sourceSha256']!=EXPECTED or provenance['x87ControlWord']!='0x027f':raise ValueError('Original edition/precision differs')
        if not provenance['loadedOriginalTextUnchanged'] or not provenance['originalFileUnchanged']:raise ValueError('Original instruction integrity differs')
        groups.append({'routine':fixture['routine'],'fixture':str(path.relative_to(ROOT)),
            'fixtureSha256':hashlib.sha256(raw).hexdigest(),'cases':len(fixture['cases']),
            'orderedDrawingRequests':sum(len(case['expected']['drawingCommands']) for case in fixture['cases']),
            'orderedSoundRequests':sum(len(case['expected'].get('sounds',[])) for case in fixture['cases']),
            'runnerSourceSha256':provenance['runnerSourceSha256'],'runnerSha256':provenance['runnerSha256'],
            'loadedOriginalTextUnchanged':True,'originalFileUnchanged':True})
    report={'format':1,'sourceSha256':EXPECTED,'x87ControlWord':'0x027f','allFixtureCasesMatch':True,
        'cases':sum(row['cases'] for row in groups),'originalRoutines':len({row['routine']['address'] for row in groups}),
        'mutableBlock':{'address':0x4da000,'bytes':394632},
        'comparison':'Independent original data and JS integer trig; every mutable byte/hash, all36 semantic global CStrings, RNG, ordered drawing and recorded sound requests. No tolerances.',
        'scope':'Finite standalone full/compact HUD calls, including nearest-boat branches. Connected frames require separate proof. Original pre-sound HUD fixture remains preserved.',
        'sourceFiles':[{'path':name,'sha256':hashlib.sha256((ROOT/name).read_bytes()).hexdigest()} for name in [
            'src/render/drawing-functions.js','src/render/typed-c.js','src/render/text.js',
            'src/render/dependencies.js','src/render/hud.js']],
        'groups':groups}
    if branches_only:
        report['scope']='Finite standalone original HUD text branches: three sail shapes, lifted/headed/major wind, pointing, closehauled/footing/pinching and three running messages at two viewport widths. Every branch is observed in the original requests; no tolerance or original expectation edits.'
    (ROOT/('analysis/hud-branches-native-reference-comparison.json' if branches_only else 'analysis/hud-native-reference-comparison.json')).write_text(json.dumps(report,indent=2)+'\n')
    print('Verified',report['cases'],'complete original HUD calls')

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--branches-only',action='store_true')
    verify(parser.parse_args().branches_only)
