#!/usr/bin/env python3
"""Preserve successful oracle compiler-input snapshots without local binaries."""
import hashlib
import json
from pathlib import Path

EDITION=Path(__file__).resolve().parents[1]
NAMES={'native_reference.c','native_gdi_trace.h','native_controller_trace.h','native_controller_table.h'}
SHORE_NAME='native_retained_shore_reads.h'
APPLICATION_NAME='native_application_trace.h'


def sha256(raw):
    return hashlib.sha256(raw).hexdigest()


def collect():
    destination=EDITION/'analysis/native-source-sets'
    destination.mkdir(parents=True,exist_ok=True)
    bundles={}
    captures={}
    annotation_path=EDITION/'analysis/retained-shore-capture-source-provenance-annotation.json'
    annotation=json.loads(annotation_path.read_text()) if annotation_path.is_file() else None
    runner_root=EDITION/'analysis/native-runners'
    owned_paths=list(runner_root.glob('capture-*'))+list(runner_root.glob('mixed-capture-*'))
    application_root=EDITION/'analysis/application-runners'
    if application_root.is_dir():
        owned_paths.append(application_root)
    for owned in sorted(owned_paths):
        if owned.is_symlink() or not owned.is_dir():
            continue
        application=owned==application_root
        if application:
            fixture_path=EDITION/'tests/fixtures/original-application.json'
            provenance=json.loads(fixture_path.read_text())['provenance']
            records=[{'path':name,'sha256':value} for name,value in provenance['runnerSources'].items()]
        else:
            provenance_path=owned/'provenance.json'
            if not provenance_path.is_file() or provenance_path.is_symlink():
                continue
            provenance=json.loads(provenance_path.read_text())
            records=provenance['runnerSourceFiles']
        names={Path(row['path']).name for row in records}
        allowed=(NAMES|{APPLICATION_NAME},) if application else (NAMES,NAMES|{SHORE_NAME})
        if names not in allowed or len(records)!=len(names):
            raise ValueError('Successful compiler snapshot has an unexpected source set')
        rows=[]
        contents={}
        corrections=[]
        for row in records:
            name=Path(row['path']).name
            source=owned/name
            if source.is_symlink() or not source.is_file():
                raise ValueError('Compiler snapshot source must be a regular file')
            raw=source.read_bytes()
            actual_hash=sha256(raw)
            if actual_hash!=row['sha256']:
                # Preserve the frozen fixture's metadata; only admit the separately
                # documented historical pre-insertion main-source hash.
                if not (annotation and name=='native_reference.c'
                        and provenance['runnerSha256']==annotation['actualRunnerSha256']
                        and row['sha256']==annotation['recordedPreInsertionSha256']
                        and actual_hash==annotation['actualCompiledSourceSha256']
                        and actual_hash==provenance['runnerSourceSha256']):
                    raise ValueError(f'Compiler snapshot hash differs: {source}')
                corrections.append({'name':name,'recordedSha256':row['sha256'],
                                    'actualCompiledSha256':actual_hash,
                                    'annotation':'analysis/retained-shore-capture-source-provenance-annotation.json'})
            contents[name]=raw
            rows.append({'name':name,'bytes':len(raw),'sha256':actual_hash})
        rows.sort(key=lambda row:row['name'])
        bundle=sha256(json.dumps(rows,sort_keys=True,separators=(',',':')).encode())
        directory=destination/bundle
        directory.mkdir(exist_ok=True)
        for name,raw in contents.items():
            target=directory/name
            if target.exists():
                if target.is_symlink() or target.read_bytes()!=raw:
                    raise ValueError('Existing published source snapshot differs')
            else:
                with target.open('xb') as stream:
                    stream.write(raw)
        main_hash=provenance['runnerSources']['native_reference.c'] if application else provenance['runnerSourceSha256']
        if main_hash!=sha256(contents['native_reference.c']):
            raise ValueError('Main compiler-source hash differs from provenance')
        executable=owned/('application-reference-2010.exe' if application else 'native-reference-2010.exe')
        if executable.is_symlink() or sha256(executable.read_bytes())!=provenance['runnerSha256']:
            raise ValueError('Owned compiled runner differs from successful provenance')
        bundles[bundle]={'sha256':bundle,'path':'analysis/native-source-sets/'+bundle,'files':rows}
        capture={'sourceBundleSha256':bundle,'provenance':provenance}
        if application:
            capture['provenanceFixture']={'path':'tests/fixtures/original-application.json',
                                          'sha256':sha256(fixture_path.read_bytes())}
            binary_bytes=executable.read_bytes()
            binary_directory=EDITION/'analysis/native-proof-binaries'
            binary_directory.mkdir(exist_ok=True)
            binary_name=sha256(binary_bytes)+'.exe'
            binary_path=binary_directory/binary_name
            if binary_path.exists():
                if binary_path.is_symlink() or binary_path.read_bytes()!=binary_bytes:
                    raise ValueError('Existing application binary snapshot differs')
            else:
                with binary_path.open('xb') as stream:
                    stream.write(binary_bytes)
            capture['nativeBinarySnapshot']={'path':'analysis/native-proof-binaries/'+binary_name,
                                             'bytes':len(binary_bytes),'sha256':sha256(binary_bytes)}
        if corrections:
            capture['sourceRecordCorrections']=corrections
        captures[provenance['runnerSha256']]=capture
    manifest={'format':1,'scope':'Successful immutable original-code oracle source sets. The exact recorded application host binary is separately archived for its provenance check; other compiled runners and Wine caches remain local.',
              'bundles':[bundles[key] for key in sorted(bundles)],
              'captures':[captures[key] for key in sorted(captures)]}
    (destination/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    return manifest


if __name__=='__main__':
    manifest=collect()
    print(f"Preserved {len(manifest['bundles'])} compiler source sets for {len(manifest['captures'])} native capture runners")
