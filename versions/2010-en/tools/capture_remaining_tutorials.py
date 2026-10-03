#!/usr/bin/env python3
"""Capture unchanged original routines for the 34 later English tutorial pages."""
import ast
import json
from pathlib import Path
from capture_native import capture,EXPECTED,ROUTINES

EDITION=Path(__file__).resolve().parents[1]


def page_addresses():
    tree=ast.parse((EDITION/'tools/translate_drawing.py').read_text())
    for node in tree.body:
        if isinstance(node,ast.Assign) and any(isinstance(target,ast.Name) and target.id=='PAGES' for target in node.targets):
            return ast.literal_eval(node.value)
    raise ValueError('Fixed tutorial address declaration is missing')


def main():
    inputs=EDITION/'analysis/tutorial-inputs'
    inputs.mkdir(exist_ok=True)
    summaries=[]
    for page,address in page_addresses().items():
        if page<=8:
            continue
        if address not in ROUTINES:
            raise ValueError('Tutorial is outside the closed native routine table')
        cases=[]
        for width in [640,699,700,899,900,901,1000,1001,1024,1280,1680]:
            for height in [480,724]:
                for suppress in [0,1]:
                    cases.append({'group':'original-width-and-color-boundaries','arguments':[0],
                                  'seed':2010+len(cases),'inputs':{'width':width,'height':height,'suppressColors':suppress},
                                  'host':{'menuHeight':20,'cursor':[64,72],'tickStart':10000,
                                          'pixels':[0xffffff]*1024}})
        manifest={'sourceSha256':EXPECTED,'routine':{'name':f'tutorial-{page}','address':address,
                 'argumentTypes':['CDC'],'returnType':'void'},
                 'integerInputs':{'width':0x4fe624,'height':0x4fe2a8,'suppressColors':0x5363e4},
                 'integerOutputs':{},'doubleInputs':{},'doubleOutputs':{},
                 'hostEvidence':'Explicit menu height, cursor, unit tick counter and bounded white pixel plane. All original drawing/numerical children execute unchanged.',
                 'cases':cases}
        (inputs/f'tutorial-{page}.json').write_text(json.dumps(manifest,indent=2)+'\n')
        result=capture(manifest)
        path=EDITION/f'tests/fixtures/original-tutorial-{page}.json'
        path.write_text(json.dumps(result,indent=2,allow_nan=False)+'\n')
        summaries.append({'page':page,'routine':address,'cases':len(cases),
                          'drawingRequests':sum(len(row['expected']['drawingCommands']) for row in result['cases'])})
        print(f'Captured tutorial {page}: {len(cases)} unchanged-original calls',flush=True)
    (EDITION/'analysis/remaining-tutorial-native-capture.json').write_text(json.dumps(
        {'format':1,'sourceSha256':EXPECTED,'comparisonStatus':'Captured; JavaScript replay is a separate required check',
         'pages':summaries,'cases':sum(row['cases'] for row in summaries)},indent=2)+'\n')


if __name__=='__main__':
    main()
