#!/usr/bin/env python3
"""Capture retained original native initialization and three100-frame chains.

No CPU emulator or JavaScript result supplies native expected values. Command18
executes only its fixed reviewed original prefix/frame addresses in an owned
Wine host, with real CRT/CString and data/RNG retained between calls. Windows
pixel/cursor/timer/GDI bindings and indeterminate original stack observations
are explicit evidence, not a claim of identical Canvas/Windows rasterization.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
import platform
import struct
import subprocess
import time
from native_mutable_state import ROOT, SOURCE, SOURCE_SHA256, BLOCK_ADDRESS, BLOCK_SIZE
from native_frame_chain_scenarios import PROFILES, configuration, initialization_inputs, frame_inputs, encode_initialization, encode_frame
from verify_native_reference import DEFAULT_GCC, compile_runner, file_hash
from verify_native_state import decode_state

FIXTURE = ROOT / 'tests/fixtures/original-native-frame-chains-p53.json'
REPORT = ROOT / 'analysis/native-frame-chains-p53-reference-comparison.json'
COMPARISON_FIELDS = ('rngState', 'sounds', 'mutableBlockHash', 'imageChanges',
                     'drawingCommands', 'hudText', 'elapsedPaintTicks')


def decode_chain(payload, operation, index):
    cursor = 0
    def take(count):
        nonlocal cursor
        if count < 0 or cursor + count > len(payload): raise ValueError('Truncated retained native chain')
        result = payload[cursor:cursor+count]; cursor += count; return result
    if struct.unpack('<I', take(4))[0] != operation: raise ValueError('Unexpected retained-chain operation')
    prepared = None
    if operation == 0:
        if struct.unpack('<I', take(4))[0] != BLOCK_SIZE: raise ValueError('Unexpected original prepared-block extent')
        prepared = take(BLOCK_SIZE)
    expected = decode_state(take(struct.unpack('<I', take(4))[0]),
                            {'command': 15, 'routine': 129, 'group': 'retainedFrame', 'index': index})
    count = struct.unpack('<I', take(4))[0]
    if count > 32: raise ValueError('Too many original shoreline observations')
    shore = []
    for _ in range(count):
        esp, first, last, camera, center, previous_x, previous_y = struct.unpack('<7I', take(28))
        signed = lambda value: value if value < 0x80000000 else value - 0x100000000
        shore.append({'entryEsp': esp, 'first': signed(first), 'last': signed(last),
                      'camera': signed(camera), 'centerProjectedY': signed(center),
                      'previousX': signed(previous_x), 'previousTreeY': signed(previous_y)})
    before_cw, after_cw = struct.unpack('<2I', take(8))
    if (before_cw, after_cw) != (0x027f, 0x027f) or cursor != len(payload):
        raise ValueError('Original retained-chain precision/framing mismatch')
    return prepared, expected, shore


def apply_changes(block, expected):
    for change in expected['imageChanges']:
        offset = change['address'] - BLOCK_ADDRESS
        before, after = bytes.fromhex(change['before']), bytes.fromhex(change['after'])
        if block[offset:offset+len(before)] != before:
            raise ValueError(f'Native retained state lost continuity at0x{change["address"]:x}')
        block[offset:offset+len(after)] = after
    if hashlib.sha256(block).hexdigest() != expected['mutableBlockHash']:
        raise ValueError('Native complete normalized mutable-block digest mismatch')


def actual_configuration(block):
    read = lambda address: struct.unpack_from('<i', block, address-BLOCK_ADDRESS)[0]
    return {name: read(address) for name, address in {
        'selector': 0x491144, 'boatClass': 0x491188, 'course': 0x491194,
        'weather': 0x4a4958, 'island': 0x4a5a4c, 'humans': 0x491140,
        'boats': 0x49118c, 'speedLevel': 0x49116c, 'speedDivisor': 0x491170,
        'view1': 0x4a4e8c, 'view2': 0x4a4e90, 'startMode': 0x4911cc}.items()}


def compare_captures(recorded, repeated):
    """Strict repeated native evidence, excluding declared host identity only.

Raw CString pointer/allocator bookkeeping and entry ESP remain in the fixture.
Void EAX is likewise retained observationally; callers do not consume it. Game
state, ordered graphics, sounds, text, timing and RNG have no normalization or
tolerance beyond the documented original runtime identity byte ranges.
"""
    differences = []
    if len(recorded) != len(repeated): raise ValueError('Native profile count differs')
    for profile_index, (before, after) in enumerate(zip(recorded, repeated)):
        for name in ('name', 'seed', 'selector', 'course', 'humans', 'view', 'startMode',
                     'nativeConfiguration', 'preparedBeforeBlock', 'actualConfiguration', 'finalConfiguration'):
            if before[name] != after[name]: differences.append({'profile': profile_index, 'field': name})
        rows = [before['initialization']] + before['frames']
        repeated_rows = [after['initialization']] + after['frames']
        if len(rows) != len(repeated_rows): raise ValueError('Retained native frame count differs')
        for frame, (left, right) in enumerate(zip(rows, repeated_rows)):
            for field in COMPARISON_FIELDS:
                if left['expected'][field] != right['expected'][field]:
                    differences.append({'profile': profile_index, 'frame': frame-1, 'field': field})
    return differences


def run_capture(executable, wine, prefix):
    stream = [struct.pack('<I', 11)]
    for index, profile in enumerate(PROFILES):
        stream.append(encode_initialization(profile))
        stream.extend(encode_frame(frame) for frame in frame_inputs(index))
    stream.append(struct.pack('<I', 0))
    if file_hash(SOURCE) != SOURCE_SHA256: raise ValueError('Original executable SHA mismatch')
    started = time.monotonic()
    process = subprocess.run([str(wine), str(executable), 'Z:'+str(SOURCE).replace('/', '\\')],
        input=b''.join(stream), capture_output=True, timeout=240,
        env={**os.environ, 'WINEPREFIX': str(prefix), 'WINEDEBUG': '-all'})
    if process.returncode: raise RuntimeError(f'Native chain exited{process.returncode}: {process.stderr.decode(errors="replace")[-4000:]}')
    data, offset = process.stdout, 32
    if len(data) < 32 or data[:8] != b'TACT2002': raise ValueError('Missing fixed native header')
    hello = struct.unpack_from('<6I', data, 8)
    if hello[0] != 2 or hello[1] != 0x400000 or hello[4:] != (0x027f, 1):
        raise ValueError('Unexpected native host/precision header')
    def packet(command):
        nonlocal offset
        if offset + 8 > len(data): raise ValueError('Missing native packet')
        returned, size = struct.unpack_from('<2I', data, offset); offset += 8
        if returned != command or size > 262144 or offset+size > len(data): raise ValueError('Invalid bounded native response')
        payload = data[offset:offset+size]; offset += size; return payload
    if packet(11) != struct.pack('<I', 1): raise ValueError('Sound host binding failed')
    profiles = []
    for index, profile in enumerate(PROFILES):
        prepared, expected, shore = decode_chain(packet(18), 0, index)
        state = bytearray(prepared); apply_changes(state, expected)
        actual = actual_configuration(state)
        if actual['course'] != profile['course'] or actual['boatClass'] != (7 if profile['selector'] == 14 else 6):
            raise ValueError(f'Requested course/class did not survive original normalization: {actual}')
        row = {**profile, 'nativeConfiguration': configuration(profile),
               'imageInputs': initialization_inputs(profile), 'preparedBeforeBlock': prepared.hex(),
               'actualConfiguration': actual, 'initialization': {'expected': expected,
                  'shorelineStackObservations': shore}, 'frames': []}
        for frame in frame_inputs(index):
            if frame['snapshotRequest']: struct.pack_into('<i', state, 0x4ac9ec-BLOCK_ADDRESS, 1)
            _, result, shore = decode_chain(packet(18), 1, frame['index'])
            apply_changes(state, result)
            pixels = [event['color'] for event in result['drawingCommands'] if event['op'] == 'getPixel']
            if len(pixels) > 1024 or any(color != 0xffffff for color in pixels):
                raise ValueError('Original pixel requests escaped declared white host')
            row['frames'].append({**frame, 'pixelReadValues': pixels,
                'shorelineStackObservations': shore, 'expected': result})
        row['finalConfiguration'] = actual_configuration(state)
        profiles.append(row)
    if packet(0) != struct.pack('<I', 1) or offset != len(data): raise ValueError('Original text final integrity/framing failed')
    if file_hash(SOURCE) != SOURCE_SHA256: raise ValueError('Original file changed during native capture')
    return profiles, {'native_header': list(hello), 'elapsed_seconds': time.monotonic()-started,
        'process_exit_code': process.returncode, 'loaded_original_text_unchanged': True,
        'original_file_unchanged': True, 'stderr': process.stderr.decode(errors='replace')}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--wine', default=str(ROOT/'tools/wine-runtime/bin/wine'))
    parser.add_argument('--prefix', default='/home/martin/.local/share/posey-simulator/wineprefix')
    parser.add_argument('--executable', default=str(ROOT/'analysis/native-runners/continuous-frames-p53.exe'))
    parser.add_argument('--compile', action='store_true')
    parser.add_argument('--verify-only', action='store_true', help='Rerun native chains against the existing unchanged native fixture')
    arguments = parser.parse_args()
    executable = __import__('pathlib').Path(arguments.executable)
    if arguments.compile: compile_runner(DEFAULT_GCC, executable, ROOT/'tools/native_reference_pc53.c')
    captured, evidence = run_capture(executable, arguments.wine, arguments.prefix)
    fixture = {'provenance': {'sha256': SOURCE_SHA256, 'authoritative_engine': 'native-original-2002',
        'x87_control_word': '0x027f', 'native_runner_sha256': file_hash(executable),
        'note': 'Three original-initialized retained native chains. No CPU emulation and no JavaScript output supplies expected values or next-frame input. Original CRT/CString, game globals and RNG remain live for100frames perprofile. Fixed reviewed calibration prefix and owned GDI/timer/cursor/whitepixel host; original indeterminate shoreline stack observations remain explicit. Original entrypoint/MFC window lifetime and Canvas raster are separate host concerns.'},
        'mutableBlock': {'address': BLOCK_ADDRESS, 'size': BLOCK_SIZE},
        'initializationCallOrder': [0x415a60, 0x42e080, 0x417790, 0x403c62, 0x413f00],
        'profiles': captured}
    if arguments.verify_only:
        fixture = json.loads(FIXTURE.read_text())
        profiles = fixture['profiles']
        repeated = captured
        confirmation = evidence
    else:
        profiles = captured
        FIXTURE.write_text(json.dumps(fixture, indent=2)+'\n')
        repeated, confirmation = run_capture(executable, arguments.wine, arguments.prefix)
    differences = compare_captures(profiles, repeated)
    report = {'source_sha256': SOURCE_SHA256, 'fixture_sha256': {FIXTURE.name: file_hash(FIXTURE)},
        'x87_control_word': '0x027f', 'capture_complete': True, 'comparison_complete': True,
        'all_fixture_cases_match': not differences,
        'native_initializations': len(profiles), 'retained_native_frames': sum(len(row['frames']) for row in profiles),
        'original_routine_addresses': ['00415a60','0042e080','00417790','00403c62','00413f00','00404020'],
        'actual_normalized_configurations': [row['actualConfiguration'] for row in profiles],
        'groups': {'initializeNativeFrameChain': {'cases': len(profiles),
            'exact_matches': len(profiles)-len({row['profile'] for row in differences if row.get('frame',-1)==-1}),
            'different_cases': len({row['profile'] for row in differences if row.get('frame',-1)==-1})},
            'drawSimulationFrame': {'cases': sum(len(row['frames']) for row in profiles),
                'exact_matches': sum(len(row['frames']) for row in profiles)-len({(row['profile'],row['frame']) for row in differences if row.get('frame',-1)>=0}),
                'different_cases': len({(row['profile'],row['frame']) for row in differences if row.get('frame',-1)>=0})}},
        'differences': differences,
        'comparison_fields': list(COMPARISON_FIELDS),
        'raw_observations_retained': ['residualEAX','hudCStringDataPointer','libraryRuntimeChanges','entryEsp'],
        'confirmation': confirmation,
        'native_runner_sha256': file_hash(executable), 'platform': platform.platform(),
        'scope': fixture['provenance']['note'], **evidence}
    REPORT.write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps({'fixture': str(FIXTURE), 'profiles': len(profiles),
                      'frames': report['retained_native_frames'], 'differences': len(differences),
                      'seconds': evidence['elapsed_seconds']}))
    if differences: raise SystemExit(1)


if __name__ == '__main__': main()
