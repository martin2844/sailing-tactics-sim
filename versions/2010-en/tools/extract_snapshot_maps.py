#!/usr/bin/env python3
"""Recover the original 2010 snapshot copy order and word counts from its C."""
import hashlib
import json
import re
from pathlib import Path

EDITION=Path(__file__).resolve().parents[1]
SHA='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'

def read(address):
    source=EDITION/'decompiled/functions'/f'{address:08x}.c'
    text=source.read_text()
    pairs=re.findall(r'puVar\d+ = &DAT_([0-9a-f]{8});\s+puVar\d+ = &DAT_([0-9a-f]{8});\s+for \(([^\n]+)',text)
    if len(pairs)!=25:raise ValueError('Original snapshot array count changed')
    arrays=[{'source':int(src,16),'destination':int(dst,16),'stride':8 if '>> 2' in condition else 4} for src,dst,condition in pairs]
    scalars=[{'source':int(src,16),'destination':int(dst,16)} for dst,src in re.findall(r'^\s+_?DAT_([0-9a-f]{8}) = _?DAT_([0-9a-f]{8});\s*$',text,re.M)]
    return {'routine':address,'sourceSha256':hashlib.sha256(source.read_bytes()).hexdigest(),'arrays':arrays,'scalars':scalars}

def main():
    if hashlib.sha256((EDITION/'runtime/Tactics2010EnglishPreserved.exe').read_bytes()).hexdigest()!=SHA:raise ValueError('Original English executable changed')
    data={name:read(address) for name,address in [('save',0x4645a0),('restore',0x464180)]}
    (EDITION/'analysis/race-snapshot-maps.json').write_text(json.dumps({'sourceSha256':SHA,**data},indent=2)+'\n')
    (EDITION/'src/engine/snapshot-maps.js').write_text('// Explicit original 2010 word-copy tables; tools/extract_snapshot_maps.py.\nexport const SNAPSHOT_MAPS=Object.freeze('+json.dumps(data,indent=2)+');\n')
    print({name:{'arrays':len(table['arrays']),'scalarWords':len(table['scalars'])} for name,table in data.items()})

if __name__=='__main__':main()
