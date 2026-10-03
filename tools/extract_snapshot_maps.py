#!/usr/bin/env python3
"""Recover the explicit byte-copy tables in original race save/restore C."""
import hashlib
import json
import re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def read(address):
    source=ROOT/'decompiled/functions'/f'{address:08x}.c'
    text=source.read_text()
    pointers=re.findall(r'puVar[35] = &DAT_([0-9a-f]{8});\s+puVar[46] = &DAT_([0-9a-f]{8});',text)
    scalars=re.findall(r'^\s+_?DAT_([0-9a-f]{8}) = _?DAT_([0-9a-f]{8});\s*$',text,re.M)
    return {'routine':address,'sourceSha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'arrays':[{'source':int(src,16),'destination':int(dst,16),'stride':8 if int(src,16) in [0x4a4ae8,0x4a49f0,0x4a71d0,0x4aafd0,0x4aaed8,0x4a6248] else 4} for src,dst in pointers],
        'scalars':[{'source':int(src,16),'destination':int(dst,16)} for dst,src in scalars]}
def main():
    data={name:read(address) for name,address in [('save',0x44dfe0),('restore',0x44dbc0)]}
    (ROOT/'analysis/race-snapshot-maps.json').write_text(json.dumps(data,indent=2)+'\n')
    header='// Explicit original state-copy tables extracted by tools/extract_snapshot_maps.py.\n'
    (ROOT/'src/engine/snapshot-maps.js').write_text(header+'export const SNAPSHOT_MAPS = Object.freeze('+json.dumps(data,indent=2)+');\n')
    print({name:{'arrays':len(table['arrays']),'scalarWords':len(table['scalars'])} for name,table in data.items()})
if __name__=='__main__':main()
