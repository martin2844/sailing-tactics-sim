#!/usr/bin/env python3
"""Replay all native English tutorial fixtures and publish bounded proof metadata."""
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SOURCE_SHA = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'


def verify():
    subprocess.run(['node', '--test', str(ROOT/'tests/tutorial-basics.test.js'),
                    str(ROOT/'tests/tutorial-remaining.test.js')], cwd=ROOT, check=True)
    translated = json.loads((ROOT/'analysis/drawing-translation-sources.json').read_text())
    groups = []
    for row in translated['sources']:
        path = ROOT/f"tests/fixtures/original-tutorial-{row['selector']}.json"
        raw = path.read_bytes()
        fixture = json.loads(raw)
        proof = fixture['provenance']
        if fixture['sourceSha256'] != SOURCE_SHA or fixture['routine']['address'] != row['address']:
            raise ValueError('Tutorial native source/address differs')
        if proof['x87ControlWord'] != '0x027f' or not proof['loadedOriginalTextUnchanged'] or not proof['originalFileUnchanged']:
            raise ValueError('Tutorial native precision/instruction integrity differs')
        source_path = ROOT/row['source']
        if hashlib.sha256(source_path.read_bytes()).hexdigest() != row['sha256']:
            raise ValueError('Tutorial recovered source changed since generation')
        groups.append({'routine': fixture['routine'], 'selector': row['selector'],
            'fixture': str(path.relative_to(ROOT)), 'fixtureSha256': hashlib.sha256(raw).hexdigest(),
            'cases': len(fixture['cases']),
            'orderedDrawingRequests': sum(len(case['expected']['drawingCommands']) for case in fixture['cases']),
            'runnerSourceSha256': proof['runnerSourceSha256'], 'runnerSha256': proof['runnerSha256'],
            'loadedOriginalTextUnchanged': True, 'originalFileUnchanged': True,
            'recoveredSource': row['source'], 'recoveredSourceSha256': row['sha256']})
    if len(groups) != 42:
        raise ValueError('All 42 original tutorial pages are required')
    outputs = ['src/render/tutorial-pages.js', 'src/render/drawing-functions.js',
               'src/render/typed-c.js', 'src/render/text.js', 'src/render/dependencies.js']
    report = {'format': 1, 'sourceSha256': SOURCE_SHA, 'x87ControlWord': '0x027f',
        'allFixtureCasesMatch': True, 'cases': sum(row['cases'] for row in groups),
        'originalRoutines': len(groups), 'mutableBlock': {'address': 0x4da000, 'bytes': 394632},
        'comparison': 'Independent original data and JS integer trig; complete mutable bytes/hash, all36 semantic CStrings, RNG, ordered GDI/text and sound requests. No tolerances.',
        'scope': 'Finite standalone calls to all 42 original tutorial pages; initialized screens and continuous full frames have separate proofs.',
        'sourceFiles': [{'path': name, 'sha256': hashlib.sha256((ROOT/name).read_bytes()).hexdigest()} for name in outputs],
        'groups': groups}
    (ROOT/'analysis/tutorials-native-reference-comparison.json').write_text(json.dumps(report, indent=2)+'\n')
    print('Verified', report['cases'], 'unchanged original tutorial calls across', len(groups), 'pages')


if __name__ == '__main__':
    verify()
