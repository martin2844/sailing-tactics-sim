#!/usr/bin/env python3
"""Package exact 2010 fixture/analysis bytes using the shared gzip format."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import importlib.util
import json
from pathlib import Path

EDITION=Path(__file__).resolve().parents[1]
ROOT=EDITION.parents[1]
specification=importlib.util.spec_from_file_location('tact_evidence',ROOT/'tools/package-evidence.py')
shared=importlib.util.module_from_spec(specification)
specification.loader.exec_module(shared)


def package(jobs):
    paths=shared.candidates(EDITION)
    # These two recorded host binaries are provenance evidence, never player
    # inputs. Keep their exact bytes restorable while excluding Wine/cache files.
    source_sets=json.loads((EDITION/'analysis/native-source-sets/manifest.json').read_text())
    binary=next(row['nativeBinarySnapshot'] for row in source_sets['captures'] if 'nativeBinarySnapshot' in row)
    modal=json.loads((EDITION/'tests/fixtures/original-modal-lifecycles.json').read_text())
    observer=next(row for row in modal['provenance']['evidence'] if row['path']=='analysis/native-modal-observer.exe')
    for record in (binary,observer):
        path=EDITION/record['path']
        if path.is_symlink() or not path.is_file() or path.stat().st_size!=record['bytes'] or shared.digest_file(path)!=record['sha256']:
            raise ValueError('Recorded native provenance binary differs')
        paths.append(path)
    with ThreadPoolExecutor(max_workers=jobs) as workers:
        rows=list(workers.map(lambda path:shared.archive_file(EDITION,path,set()),paths))
    manifest={'format':1,'compression':'gzip','compressionLevel':6,
              'scope':'Exact canonical 2010 English native comparison inputs, outputs, analysis and the two recorded host binaries required by provenance checks. Game executables, other editions, caches, Wine state and symlinks are excluded. No proof artifact is loaded by the browser player.',
              'files':rows,'totals':{'files':len(rows),'bytes':sum(row['bytes'] for row in rows),
                                    'compressedBytes':sum(row['compressedBytes'] for row in rows)}}
    (EDITION/'evidence/manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    (EDITION/'evidence/expanded.gitignore.txt').write_text(
        '# Exact expanded bytes restored by node tools/restore-2010-evidence.js.\n'+
        ''.join('/versions/2010-en/'+row['path']+'\n' for row in rows))
    return manifest


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--jobs',type=int,choices=range(1,5),default=2)
    parser.add_argument('--verify',action='store_true')
    arguments=parser.parse_args()
    manifest=shared.verify(EDITION) if arguments.verify else package(arguments.jobs)
    print(json.dumps(manifest['totals']))
