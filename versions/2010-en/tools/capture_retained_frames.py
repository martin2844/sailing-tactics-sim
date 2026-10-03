#!/usr/bin/env python3
"""Retain one original data/RNG/CString lifetime across fixed frame and controller calls."""
from __future__ import annotations
import argparse
import hashlib
import importlib.util
import json
import os
import struct
import subprocess
import tempfile
from pathlib import Path
import capture_native as numerical
import capture_controllers as controllers

EDITION, ROOT = numerical.EDITION, numerical.ROOT
DATA_BASE, DATA_BYTES = numerical.DATA_BASE, numerical.DATA_BYTES
STRING_MARKER = 0x52545343
STRING_ADDRESSES = [0x4fdfd4, *range(0x4fec30, 0x4fec30 + 35 * 4, 4)]


def controller_manifest(manifest, case):
    # Each retained row carries its own declared patches. Original initialization
    # owns the starting state; controller profile inputs are never reapplied.
    return {**manifest, 'profiles': {case['profile']: {'patches': []}}}


def encode_case(manifest, case):
    if 'kind' not in case:
        return numerical.encode_case(manifest, case)
    if not case.get('continue') or 'seed' in case:
        raise ValueError('Retained controllers require previous native state and RNG')
    return controllers.encode(controller_manifest(manifest, case), case)


def decode_controller(raw, manifest, case, state, baseline):
    # Locate the unchanged legacy envelope without interpreting optional bytes as
    # host events or silently dropping a malformed new trailer.
    if len(raw) < 108:
        raise ValueError('Truncated retained controller response')
    offset = 72
    changes = struct.unpack_from('<I', raw, 68)[0]
    if changes > DATA_BYTES:
        raise ValueError('Controller delta count exceeds data extent')
    for _ in range(changes):
        if offset + 8 > len(raw):
            raise ValueError('Truncated retained controller delta')
        address, width = struct.unpack_from('<II', raw, offset)
        offset += 8
        if not DATA_BASE <= address < DATA_BASE + DATA_BYTES or not width or width > DATA_BASE + DATA_BYTES - address:
            raise ValueError('Retained controller delta exceeds data extent')
        offset += width * 2
        if offset > len(raw):
            raise ValueError('Truncated retained controller delta bytes')
    if offset + 4 > len(raw):
        raise ValueError('Missing retained controller events')
    event_bytes = struct.unpack_from('<I', raw, offset)[0]
    if event_bytes > 65536:
        raise ValueError('Retained controller events exceed native bound')
    legacy_end = offset + 4 + event_bytes + 32
    if legacy_end > len(raw):
        raise ValueError('Truncated retained controller bindings')
    expected = controllers.decode(raw[:legacy_end], controller_manifest(manifest, case), case, state, baseline)
    offset = legacy_end
    if offset + 8 > len(raw):
        raise ValueError('Retained controller lacks live original CString evidence')
    marker, count = struct.unpack_from('<II', raw, offset)
    offset += 8
    if marker != STRING_MARKER or count != 36:
        raise ValueError('Retained controller CString identity/count differs')
    strings = []
    for address in STRING_ADDRESSES:
        if offset + 12 > len(raw):
            raise ValueError('Truncated retained controller CString cell')
        actual_address, pointer, width = struct.unpack_from('<III', raw, offset)
        offset += 12
        if actual_address != address or not pointer or width >= 4096 or offset + width > len(raw):
            raise ValueError('Retained controller CString exceeds fixed cell/text bound')
        text = raw[offset:offset + width]
        offset += width
        if b'\0' in text:
            raise ValueError('Retained controller CString contains an embedded terminator')
        strings.append({'address': address, 'nativePointer': pointer, 'bytes': text.hex()})
    if offset != len(raw):
        raise ValueError('Surplus retained controller response bytes')
    expected['globalStrings'] = strings
    expected['integers'] = {name: struct.unpack_from('<i', state, address - DATA_BASE)[0]
                            for name, address in manifest.get('integerOutputs', {}).items()}
    expected['doubles'] = {name: state[address - DATA_BASE:address - DATA_BASE + 8].hex()
                          for name, address in manifest.get('doubleOutputs', {}).items()}
    return expected


def capture(manifest, *, compiler=None, wine=None, prefix=None, observe_shore=False):
    original = EDITION / 'runtime/Tactics2010EnglishPreserved.exe'
    if manifest['sourceSha256'] != numerical.EXPECTED or numerical.digest(original) != numerical.EXPECTED:
        raise ValueError('Original English source identity differs')
    if not manifest['cases'] or len(manifest['cases']) > 10000:
        raise ValueError('Retained batch exceeds bounded case count')
    directory = EDITION / 'analysis/native-runners'
    directory.mkdir(parents=True, exist_ok=True)
    owned = Path(tempfile.mkdtemp(prefix='mixed-capture-', dir=directory))
    source_records = []
    for name in ['native_reference.c', 'native_gdi_trace.h', 'native_controller_trace.h', 'native_controller_table.h']:
        raw = (EDITION / 'tools' / name).read_bytes()
        (owned / name).write_bytes(raw)
    if observe_shore:
        name = 'native_retained_shore_reads.h'
        raw = (EDITION / 'tools' / name).read_bytes()
        (owned / name).write_bytes(raw)
        source = owned / 'native_reference.c'
        code = source.read_text()
        replacements = {
            'static void run_case(uint32_t command) {': '#include "native_retained_shore_reads.h"\nstatic void run_case(uint32_t command) {',
            'write_exact("TACT2010",8);': 'initialize_retained_shore_reads();\n  write_exact("TACT2010",8);',
            'if (command==1 || command==3) run_case(command);': 'retained_shore_case=operations-1;\n    if (command==1 || command==3) run_case(command);',
        }
        for before, after in replacements.items():
            if code.count(before) != 1:
                raise ValueError('Reviewed fixed host structure changed before shore observation')
            code = code.replace(before, after)
        source.write_text(code)
    # Record the actual compilation inputs after the optional fixed observer
    # insertion. The canonical original host remains unchanged on disk.
    names = ['native_reference.c', 'native_gdi_trace.h', 'native_controller_trace.h', 'native_controller_table.h']
    if observe_shore:
        names.append('native_retained_shore_reads.h')
    for name in names:
        record = {'path': f'versions/2010-en/tools/{name}', 'sha256': numerical.digest(owned / name)}
        if observe_shore and name == 'native_reference.c':
            record['canonicalSourceSha256'] = numerical.digest(EDITION / 'tools' / name)
            record['fixedObserverInsertedIntoPrivateCopy'] = True
        source_records.append(record)
    specification = importlib.util.spec_from_file_location('tact_native_build_helper', ROOT / 'tools/verify_native_reference.py')
    helper = importlib.util.module_from_spec(specification)
    specification.loader.exec_module(helper)
    executable = owned / 'native-reference-2010.exe'
    flags = helper.compile_runner(compiler or helper.DEFAULT_GCC, executable, owned / 'native_reference.c')
    environment = os.environ.copy()
    environment.update(WINEDEBUG=os.environ.get('TACT_REFERENCE_WINEDEBUG', '-all'),
                       WINEPREFIX=prefix or str(Path.home() / '.local/share/posey-simulator-2010-en/wineprefix'))
    requests = b''.join(encode_case(manifest, case) for case in manifest['cases']) + struct.pack('<I', 0)
    completed = subprocess.run([wine or str(ROOT / 'tools/wine-runtime/bin/wine'), str(executable), str(original)],
                               input=requests, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                               env=environment, timeout=300)
    (owned / 'native-output.bin').write_bytes(completed.stdout)
    (owned / 'native-stderr.log').write_bytes(completed.stderr)
    if completed.returncode:
        raise RuntimeError(f'Original retained oracle failed {completed.returncode}; evidence at {owned}: '
                           + completed.stderr.decode(errors='replace'))
    observations = []
    if observe_shore:
        observations = [json.loads(line) for line in completed.stderr.decode().splitlines()]
        if any(row.get('event') != 'original-retained-shore-read'
               or row.get('controlWord') != 0x027f
               or not 0 <= row.get('case', -1) < len(manifest['cases'])
               or row.get('index') != row.get('first')
               or row.get('first') != 0
               or row.get('last') != 36
               or row.get('camera') != 1 for row in observations):
            raise ValueError('Unexpected retained hardware observation or caller domain')
        if not observations:
            raise ValueError('Original retained tree predecessor consumption was not observed')
    output = completed.stdout
    if output[:8] != b'TACT2010' or len(output) < 36 + DATA_BYTES:
        raise ValueError('Original retained oracle handshake missing')
    if struct.unpack_from('<7I', output, 8) != (1, 0x400000, 0x21c000, 0x027f, 358, DATA_BASE, DATA_BYTES):
        raise ValueError('Original retained oracle layout/precision differs')
    baseline = output[36:36 + DATA_BYTES]
    state, offset, cases = bytearray(baseline), 36 + DATA_BYTES, []
    for index, case in enumerate(manifest['cases']):
        if offset + 8 > len(output):
            raise ValueError('Missing retained case envelope')
        command, length = struct.unpack_from('<II', output, offset)
        offset += 8
        wanted = 2 if 'kind' in case else 3 if case.get('strings') else 1
        if command != wanted or length > DATA_BYTES * 6 + 2097152 + 65536 or offset + length > len(output):
            raise ValueError('Retained case envelope exceeds fixed protocol')
        raw = output[offset:offset + length]
        offset += length
        try:
            expected = (decode_controller(raw, manifest, case, state, baseline) if command == 2
                        else numerical.decode_case(raw, manifest, case, state, baseline))
        except Exception as error:
            raise ValueError(f'Retained case{index} {case.get("label", case.get("phase"))}: {error}') from error
        captured = {**case, 'expected': expected}
        if observe_shore:
            captured['shoreReads'] = [row for row in observations if row['case'] == index]
        cases.append(captured)
    if output[offset:] != struct.pack('<3I', 0, 4, 1) or numerical.digest(original) != numerical.EXPECTED:
        raise ValueError('Final unchanged original file/text evidence missing')
    provenance = {'engine': 'Original x86 code under Wine; no text edits', 'sha256': numerical.EXPECTED,
                  'x87ControlWord': '0x027f', 'runnerSourceSha256': numerical.digest(owned / 'native_reference.c'),
                  'runnerSourceFiles': source_records, 'runnerSha256': numerical.digest(executable),
                  'compilerFlags': flags, 'loadedOriginalTextUnchanged': True, 'originalFileUnchanged': True,
                  'mutableBaselineSha256': hashlib.sha256(baseline).hexdigest(),
                  'hostBindings': 'One retained original data/RNG/CRT/global-CString lifetime. Fixed original controller handlers use owned window/vtable/MFC TLS bindings restored before state hashing. Full frames execute actual numerical and rendering children with declared unit tick/cursor/menu/pixel inputs.',
                  'limitations': 'Finite retained profiles; explicitly recorded original paint-caller phase. Full Windows paint allocation/window lifetime is outside this bounded host.'}
    if observe_shore:
        provenance['shoreObserver'] = {
            'targetGameMemoryWrites': 0, 'stackInputsSupplied': False,
            'scope': 'Actual consumed predecessor X/Y bytes inside the already allocated original440400 frame; fixed hardware execution points and owned VEH. No trap at entry can overwrite the future original local frame. Bounded oracle caller context is distinct from the intact application caller.',
            'rawObservations': str((owned / 'native-stderr.log').relative_to(EDITION)),
            'rawObservationsSha256': numerical.digest(owned / 'native-stderr.log'),
            'consumedPairs': len(observations),
        }
    (owned / 'provenance.json').write_text(json.dumps(provenance, indent=2) + '\n')
    return {**manifest, 'mutableBlock': {'address': DATA_BASE, 'size': DATA_BYTES},
            'mutableBaseline': baseline.hex(), 'provenance': provenance, 'cases': cases}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--compiler')
    parser.add_argument('--wine')
    parser.add_argument('--prefix')
    parser.add_argument('--observe-shore', action='store_true', help='Record actual retained original tree predecessor reads using fixed hardware points')
    args = parser.parse_args()
    if args.observe_shore and args.output.exists():
        raise ValueError('Preserve existing native expectations: choose a new --output for observed caller evidence')
    result = capture(json.loads(args.manifest.read_text()), compiler=args.compiler, wine=args.wine, prefix=args.prefix,
                     observe_shore=args.observe_shore)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, allow_nan=False) + '\n')
    print(f'Captured {len(result["cases"])} retained original frame/controller calls with strict state hashes')


if __name__ == '__main__':
    main()
