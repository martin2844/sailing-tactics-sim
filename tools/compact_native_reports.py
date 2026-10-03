"""Keep exact CRT bookkeeping evidence in a hashed gzip JSON artifact.

Only storage changes: comparison results, fixture hashes and all recorded raw
bytes remain present. Immutable before-correction reports are not rewritten.
"""
import argparse
import gzip
import hashlib
import json
from pathlib import Path


def externalize_runtime_evidence(report, path):
    rows = report.get('library_runtime_evidence')
    if not isinstance(rows, list) or not rows:
        return False
    artifact = path.with_name(path.stem + '-runtime-evidence.json.gz')
    with gzip.GzipFile(filename=str(artifact), mode='wb', mtime=0) as stream:
        stream.write(b'[')
        for number, row in enumerate(rows):
            if number:
                stream.write(b',\n')
            stream.write(json.dumps(row, separators=(',', ':')).encode())
        stream.write(b']\n')
    with artifact.open('rb') as stream:
        digest = hashlib.file_digest(stream, 'sha256').hexdigest()
    root = Path(__file__).resolve().parents[1]
    report['library_runtime_evidence'] = {
        'artifact': str(artifact.resolve().relative_to(root)), 'sha256': digest,
        'encoding': 'gzip JSON array', 'records': len(rows),
        'scope': 'Exact raw original CRT allocator bookkeeping before/after bytes; comparison-only normalizations are declared in this report.'}
    return True


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('report', nargs='+', type=Path)
    for path in parser.parse_args().report:
        report = json.loads(path.read_text())
        if externalize_runtime_evidence(report, path):
            path.write_text(json.dumps(report, indent=2, allow_nan=False) + '\n')
        print(path, path.stat().st_size)


if __name__ == '__main__':
    main()
