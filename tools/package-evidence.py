#!/usr/bin/env python3
"""Publish exact 2002 evidence bytes in bounded, deterministic gzip archives.

Expanded originals remain untouched. The manifest records both archive and
expanded hashes/sizes so Node can restore the canonical test/analysis paths.
Only direct 2002 fixture files and direct large analysis text files are scanned;
other editions, subdirectories, symlinks and local runtimes are excluded.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import tempfile

ROOT = Path(__file__).resolve().parents[1]
THRESHOLD = 2 * 1024 * 1024
MAX_ARCHIVE_BYTES = 100 * 1024 * 1024
BLOCK = 1024 * 1024
OTHER_EDITION = re.compile(r'(^|[-_])(2008|2010)([-_.]|$)')


def candidates(root):
    result = []
    for directory, suffixes, threshold in (
            ('tests/fixtures', {'.json'}, -1),
            ('analysis', {'.json', '.jsonl', '.txt'}, THRESHOLD)):
        source_directory = root / directory
        if source_directory.is_symlink():
            continue
        for path in source_directory.iterdir():
            if (path.is_symlink() or not path.is_file() or
                    path.suffix not in suffixes or OTHER_EDITION.search(path.name)):
                continue
            if path.stat().st_size > threshold:
                result.append(path)
    return sorted(result, key=lambda path: path.relative_to(root).as_posix())


def workbench_paths(root):
    source = (root / 'src/browser.js').read_text()
    return set(re.findall(r"fetchFile\(['\"]([^'\"]+)['\"]", source))


def digest_file(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def archive_file(root, path, browser_paths):
    relative = path.relative_to(root).as_posix()
    archive = root / 'evidence/archives' / (relative + '.gz')
    archive.parent.mkdir(parents=True, exist_ok=True)
    before = path.stat()
    raw_hash = hashlib.sha256()
    raw_bytes = 0
    descriptor, temporary = tempfile.mkstemp(prefix=archive.name + '.', suffix='.tmp', dir=archive.parent)
    try:
        with os.fdopen(descriptor, 'wb') as output:
            # Empty filename and zero mtime prevent path/time-dependent headers.
            with gzip.GzipFile(filename='', mode='wb', fileobj=output,
                               compresslevel=6, mtime=0) as compressed:
                with path.open('rb') as original:
                    while chunk := original.read(BLOCK):
                        raw_hash.update(chunk)
                        raw_bytes += len(chunk)
                        compressed.write(chunk)
        after = path.stat()
        if (before.st_size, before.st_mtime_ns, before.st_ino) != (after.st_size, after.st_mtime_ns, after.st_ino):
            raise ValueError(f'Expanded evidence changed during packaging: {relative}')
        size = Path(temporary).stat().st_size
        if size >= MAX_ARCHIVE_BYTES:
            raise ValueError(f'Archive reaches GitHub 100 MiB limit: {relative} ({size} bytes)')
        compressed_hash = digest_file(Path(temporary))
        if archive.exists() and digest_file(archive) == compressed_hash:
            Path(temporary).unlink()
        else:
            os.replace(temporary, archive)
        return {'path': relative, 'archive': archive.relative_to(root).as_posix(),
                'bytes': raw_bytes, 'sha256': raw_hash.hexdigest(),
                'compressedBytes': size, 'compressedSha256': compressed_hash,
                'profiles': ['all', 'workbench'] if relative in browser_paths else ['all']}
    finally:
        if Path(temporary).exists():
            Path(temporary).unlink()


def package(root, jobs=2):
    browser_paths = workbench_paths(root)
    paths = candidates(root)
    with ThreadPoolExecutor(max_workers=jobs) as workers:
        rows = list(workers.map(lambda path: archive_file(root, path, browser_paths), paths))
    manifest = {'format': 1, 'compression': 'gzip', 'compressionLevel': 6,
                'scope': 'Exact canonical 2002 evidence bytes; expanded originals are unchanged. Other editions, runtime/cache directories and symlinks are excluded.',
                'files': rows,
                'totals': {'files': len(rows), 'bytes': sum(row['bytes'] for row in rows),
                           'compressedBytes': sum(row['compressedBytes'] for row in rows)}}
    directory = root / 'evidence'
    (directory / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    (directory / 'expanded.gitignore.txt').write_text(
        '# Canonical paths restored from exact hashed archives by restore-evidence.js.\n' +
        ''.join('/' + row['path'] + '\n' for row in rows))
    return manifest


def verify(root):
    manifest = json.loads((root / 'evidence/manifest.json').read_text())
    if manifest['format'] != 1:
        raise ValueError('Unknown evidence archive format')
    for row in manifest['files']:
        relative = row['path']
        if (not relative.startswith(('tests/fixtures/', 'analysis/')) or
                '..' in Path(relative).parts or Path(relative).is_absolute() or
                row['archive'] != 'evidence/archives/' + relative + '.gz'):
            raise ValueError('Evidence manifest path escapes its fixed publication scope')
        path = root / row['path']
        archive = root / row['archive']
        if (path.is_symlink() or archive.is_symlink() or
                not path.resolve().is_relative_to(root) or
                not archive.resolve().is_relative_to(root)):
            raise ValueError('Evidence paths must not be symlinks')
        if not 0 < row['compressedBytes'] < MAX_ARCHIVE_BYTES or row['bytes'] < 0:
            raise ValueError('Evidence manifest size is outside its publication bound')
        if archive.stat().st_size != row['compressedBytes'] or digest_file(archive) != row['compressedSha256']:
            raise ValueError(f'Compressed archive hash/size mismatch: {row["path"]}')
        raw_hash = hashlib.sha256()
        count = 0
        with gzip.open(archive, 'rb') as stream:
            while chunk := stream.read(BLOCK):
                raw_hash.update(chunk)
                count += len(chunk)
                if count > row['bytes']:
                    raise ValueError(f'Expanded archive exceeds declared size: {row["path"]}')
        if count != row['bytes'] or raw_hash.hexdigest() != row['sha256']:
            raise ValueError(f'Expanded archive hash/size mismatch: {row["path"]}')
        if path.stat().st_size != count or digest_file(path) != row['sha256']:
            raise ValueError(f'Canonical original hash/size mismatch: {row["path"]}')
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--jobs', type=int, choices=range(1, 5), default=2)
    parser.add_argument('--verify', action='store_true')
    arguments = parser.parse_args()
    root = arguments.root.resolve()
    manifest = verify(root) if arguments.verify else package(root, arguments.jobs)
    print(json.dumps(manifest['totals']))
    if manifest['files']:
        print(json.dumps(manifest['files'][0]))


if __name__ == '__main__':
    main()
