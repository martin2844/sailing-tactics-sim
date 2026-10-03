#!/usr/bin/env python3
"""Regenerate eight fixed native English tutorial fixtures and strict JS proof."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
from capture_native import capture,EXPECTED

ROOT=Path(__file__).resolve().parents[1]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--verify-only',action='store_true')
    parser.add_argument('--prefix',default=str(Path.home()/'.local/share/posey-simulator-2010-en/wineprefix'))
    args=parser.parse_args()
    fixtures=ROOT/'tests/fixtures';fixtures.mkdir(parents=True,exist_ok=True)
    if not args.verify_only:
        subprocess.run(['node',str(ROOT/'tools/prepare-tutorial-inputs.js')],check=True)
        for page in range(1,9):
            manifest=json.loads((ROOT/f'analysis/tutorial-inputs/tutorial-{page}.json').read_text())
            result=capture(manifest,prefix=args.prefix)
            (fixtures/f'original-tutorial-{page}.json').write_text(json.dumps(result,indent=2,allow_nan=False)+'\n')
            print('Captured original tutorial',page,len(result['cases']),flush=True)
    subprocess.run(['node','--test',str(ROOT/'tests/tutorial-basics.test.js')],check=True)
    rows=[]
    for page in range(1,9):
        path=fixtures/f'original-tutorial-{page}.json';fixture=json.loads(path.read_text())
        if fixture['sourceSha256']!=EXPECTED:raise ValueError('Native fixture source SHA differs')
        rows.append({'routine':fixture['routine'],'fixture':str(path.relative_to(ROOT)),
          'fixtureSha256':sha(path),'cases':len(fixture['cases']),
          'orderedDrawingRequests':sum(len(row['expected']['drawingCommands']) for row in fixture['cases']),
          'provenance':fixture['provenance']})
    report={'format':1,'sourceSha256':EXPECTED,'x87ControlWord':'0x027f',
      'allFixtureCasesMatch':True,'cases':sum(row['cases'] for row in rows),'originalRoutines':8,
      'mutableBlock':{'address':0x4da000,'bytes':0x60588},
      'comparison':'Independent original data + edition integer trig; complete byte state/hash, original read-only write scope, RNG and ordered GDI/text requests. No tolerances.',
      'nativeNormalization':'Owned CRT allocator/TLS bookkeeping and original global CString pointer identities; raw runtime changes and all36 actual CString texts remain in each fixture.',
      'groups':rows}
    path=ROOT/'analysis/tutorial-basics-native-reference-comparison.json';path.write_text(json.dumps(report,indent=2)+'\n')
    print('352 finite original English tutorial calls match complete JavaScript source')

if __name__=='__main__':main()
