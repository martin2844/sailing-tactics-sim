#!/usr/bin/env python3
"""Compare complete fixed mutable state after reviewed original 2002 calls.

Only native_reference_2002.c's fixed dispatch is used. Protocol patches are
limited to original .data/BSS; code, IAT, the host and the runtime TLS index
cannot be supplied as inputs. Native results are evidence, with no tolerance.
"""
from __future__ import annotations
import argparse
import gzip
import hashlib
import json
import itertools
import os
import platform
import struct
import subprocess
import time
from pathlib import Path

from native_mutable_state import (ROOT, SOURCE_SHA256, BLOCK_ADDRESS, BLOCK_SIZE,
    TLS_INDEX_OFFSET, apply_patches, baseline_for_fixture, encode_patches,
    image_changes, original_baseline)
from verify_native_reference import compile_runner, DEFAULT_GCC, file_hash

COMMAND_LIMIT = 131072
DEFAULT_FIXTURES = ['original-spatial-wind.json', 'original-ai-tactics.json',
    'original-upwind-tactics.json', 'original-initialization.json',
    'original-connected-encounters.json', 'original-boat-dynamics.json',
    'original-crew-geometry.json', 'original-target-bearing.json',
    'original-snapshots.json', 'original-ai-coordinator.json',
    'original-sail-geometry.json', 'original-avoidance.json',
    'original-gdi-primitives.json', 'original-boat-panels.json',
    'original-projection.json', 'original-hud-state.json',
    'original-boat-details.json', 'original-headsails.json',
    'original-crew-drawing.json', 'original-boat-rigging.json',
    'original-boat-sway.json', 'original-chart-details.json',
    'original-boat-renderer.json', 'original-chart-terrain.json',
    'original-chart-wrapper.json', 'original-scene-objects.json',
    'original-hud.json', 'original-scene-surface.json',
    'original-shore.json','original-shore-exceptional.json',
    'original-screens.json','original-tutorials.json','original-scene-composition.json']


def complete_case(fixture, inputs, stores):
    before = baseline_for_fixture(fixture)
    apply_patches(before, inputs)
    after = bytearray(before)
    apply_patches(after, stores)
    patches = [{'address': row['address'], 'bits': row['after']}
               for row in image_changes(original_baseline(), before)]
    return encode_patches(patches), {
        'imageChanges': image_changes(before, after),
        'mutableBlockHash': hashlib.sha256(after).hexdigest()}


def spatial_cases(fixture):
    baseline_fixture = {**fixture, 'baseline': {'patches': fixture['baseline']}}
    for index, case in enumerate(fixture['cases']):
        inputs = [{'address': fixture['inputs'][name],
                   'bits': struct.pack('<I', value & 0xffffffff).hex()}
                  for name, value in case['inputs'].items()]
        inputs += [
            {'address': 0x4aa5b0 + case['boat'] * 4,
             'bits': struct.pack('<i', case['previousDirection']).hex()},
            {'address': 0x4a7f28 + case['boat'] * 8,
             'bits': struct.pack('<d', case['cachedMetric']).hex()}]
        patches, expected = complete_case(baseline_fixture, inputs, case['expected']['stores'])
        yield {'group': 'sampleSpatialWind', 'routine': 3, 'index': index,
            'integers': [case['x'], case['y'], case['boat'], 0], 'doubles': [0., 0.],
            'seed': 2002, 'patches': patches,
            'expected': {**expected, 'returnValue': case['expected']['returnValue'],
                         'rngState': 2002, 'sounds': []}}


def ai_cases(fixture):
    ids = {0x425600: 7, 0x425910: 8, 0x427030: 9, 0x4249a0: 6}
    for name, data in fixture['groups'].items():
        if data['address'] not in ids:
            raise ValueError('AI fixture address is not in fixed original dispatch')
        for index, case in enumerate(data['cases']):
            patches, expected = complete_case(fixture, case['inputs'], case['expected']['stores'])
            expected.update(rngState=case['expected']['rngState'],
                            sounds=case['expected'].get('sounds', []))
            if data.get('returnKind') != 'void' and 'returnValue' in case['expected']:
                expected['returnValue'] = case['expected']['returnValue']
            yield {'group': name, 'routine': ids[data['address']], 'index': index,
                'integers': case['arguments'] + [0] * (4 - len(case['arguments'])),
                'doubles': [0., 0.], 'seed': case['seed'], 'patches': patches,
                'expected': expected}


def fixture_cases(fixture):
    if fixture.get('address') == 0x426150:
        return spatial_cases(fixture)
    if 'groups' in fixture:
        return ai_cases(fixture)
    if any(group.get('argumentTypes', [])[:1] == ['CDC'] for group in fixture.get('routines', {}).values()):
        from native_fixture_adapter import gdi_cases
        return gdi_cases(fixture)
    from native_fixture_adapter import initialization_cases
    if 'integerFormatting' in fixture:
        return itertools.chain(initialization_cases(fixture), pure_hud_cases(fixture))
    return initialization_cases(fixture)


def pure_hud_cases(fixture):
    for name, identifier in [('signedDegrees', 0), ('integerFormatting', 1), ('decimalFormatting', 2)]:
        for index, row in enumerate(fixture[name]):
            expected = {'imageUnchanged': True}
            expected['returnValue' if identifier == 0 else 'text'] = row['expected']
            if identifier:
                expected['outputPointerReturned'] = True
            yield {'command': 16, 'group': name, 'routine': identifier, 'index': index,
                   'integers': [row['input'] if identifier != 2 else 0],
                   'doubles': [row['input'] if identifier == 2 else 0.],
                   'patches': b'', 'expected': expected}


def encode_case(case):
    if case.get('command') == 16:
        if case['routine'] not in (0, 1, 2) or len(case['integers']) != 1 or len(case['doubles']) != 1:
            raise ValueError('Unknown fixed original numeric-text request')
        return struct.pack('<IIid', 16, case['routine'], case['integers'][0], case['doubles'][0])
    if case.get('command') in (15,19):
        if len(case['integers']) > 16 or len(case.get('doubles', [])) > 4:
            raise ValueError('Fixed drawing argument vector exceeds original ABI bound')
        integers = case['integers'] + [0] * (16 - len(case['integers']))
        doubles = case.get('doubles', []) + [0.] * (4 - len(case.get('doubles', [])))
        pixels = case.get('pixelReadValues', [])
        if len(pixels) > 1024 or any(not isinstance(value, int) or isinstance(value, bool)
                                    or not 0 <= value <= 0xffffffff for value in pixels):
            raise ValueError('Synthetic pixel-read inputs exceed the fixed native bounds')
        menu=case.get('menuHeight',20);cursor=case.get('cursor',{'x':0,'y':0})
        tick_start=case.get('tickStart',0);tick_step=case.get('tickStep',1)
        if (not isinstance(menu,int) or isinstance(menu,bool) or not 0<=menu<=128 or
            not isinstance(tick_start,int) or isinstance(tick_start,bool) or not 0<=tick_start<=0xffffffff or
            tick_step!=1 or any(not isinstance(cursor.get(key),int) or isinstance(cursor.get(key),bool) or
                               not -16384<=cursor[key]<=16384 for key in ('x','y'))):
            raise ValueError('Owned cursor/menu/timer inputs exceed fixed native bounds')
        return (struct.pack('<II16i4dI', case.get('command',15), case['routine'], *integers,
                            *doubles, case['seed']) + case['patches'] +
                struct.pack('<I', len(pixels)) + b''.join(struct.pack('<I', value) for value in pixels)+
                struct.pack('<iiiII',menu,cursor['x'],cursor['y'],tick_start,tick_step))
    if len(case['integers']) > 8 or len(case['doubles']) > 4:
        raise ValueError('Fixed argument vector has wrong size')
    integers = case['integers'] + [0] * (8 - len(case['integers']))
    doubles = case['doubles'] + [0.] * (4 - len(case['doubles']))
    return struct.pack('<II8i4dI', 14, case['routine'], *integers,
                       *doubles, case['seed']) + case['patches']


def decode_state(payload, case):
    offset = 0
    def take(count):
        nonlocal offset
        if count < 0 or offset + count > len(payload):
            raise ValueError('Truncated native mutable-state evidence')
        result = payload[offset:offset + count]
        offset += count
        return result
    if case.get('command') == 16:
        routine, returned, pointer_returned, unchanged, pointer, width = struct.unpack('<Ii4I', take(24))
        if routine != case['routine'] or routine not in (0, 1, 2) or pointer_returned > 1 or unchanged > 1 or width > 4095:
            raise ValueError('Invalid fixed original numeric-text response')
        result = {'imageUnchanged': bool(unchanged), 'outputPointerReturned': bool(pointer_returned)}
        if not routine:
            if pointer or width:
                raise ValueError('Unexpected signed-angle CString evidence')
            result['returnValue'] = returned
        else:
            if not pointer:
                raise ValueError('Original formatter returned no native CString data')
            result.update(text=take(width).decode('cp1252'), nativeCStringDataPointer=pointer)
        active, changes = struct.unpack('<II', take(8))
        if active != bool(routine) or changes > 16384:
            raise ValueError('Invalid numeric-text CRT lifecycle evidence')
        result['cstringRuntimeInitialized'] = bool(active)
        result['libraryRuntimeChanges'] = []
        for _ in range(changes):
            address, length = struct.unpack('<II', take(8))
            if not any(first <= address and 0 < length <= first + width - address
                       for first, width in [(0x49ffa0, 0x80), (0x4a0060, 0x2024),
                                            (0x4aebc8, 0x60), (0x4afdec, 4), (0x4aec34, 4)]):
                raise ValueError('Numeric-text bookkeeping escaped declared CRT ranges')
            result['libraryRuntimeChanges'].append({'address': address,
                'before': take(length).hex(), 'after': take(length).hex()})
        if offset != len(payload):
            raise ValueError('Trailing original numeric-text bytes')
        return result
    routine, kind, residual = struct.unpack('<IIi', take(12))
    if routine != case['routine'] or kind not in (0, 2, 3):
        raise ValueError('Unexpected fixed original routine response')
    result = {'residualEAX': residual}
    if kind == 0:
        result['returnValue'] = residual
    if kind == 2:
        raw = take(8)
        result.update(returnValue=struct.unpack('<d', raw)[0], returnBits=raw.hex(),
                      returnExtendedBits=take(10).hex())
    result['rngState'], sounds = struct.unpack('<II', take(8))
    if sounds > 16:
        raise ValueError('Known sound recorder limit exceeded')
    result['sounds'] = [dict(zip(('resourceId', 'moduleHandle', 'flags'),
                          struct.unpack('<3I', take(12)))) for _ in range(sounds)]
    result['mutableBlockHash'] = take(32).hex()
    changes = struct.unpack('<I', take(4))[0]
    if changes > 16384:
        raise ValueError('Image delta count exceeds bounded original data evidence')
    result['imageChanges'] = []
    for _ in range(changes):
        address, length = struct.unpack('<II', take(8))
        if not (BLOCK_ADDRESS <= address and 0 < length <= BLOCK_ADDRESS + BLOCK_SIZE - address):
            raise ValueError(f'Original {case["group"]} case {case["index"]} changed bytes '
                             f'0x{address:x}+0x{length:x} outside fixed mutable state')
        if address < 0x49fe44 and address + length > 0x49fe40:
            raise ValueError('Original routine changed the runtime TLS index')
        result['imageChanges'].append({'address': address, 'before': take(length).hex(),
                                      'after': take(length).hex()})
    if case.get('command') in (15,19):
        result['drawingCommands'] = decode_gdi_events(take(struct.unpack('<I', take(4))[0]))
        active, changes = struct.unpack('<II', take(8))
        if active > 1 or changes > 16384:
            raise ValueError('Invalid original CString runtime evidence')
        result['cstringRuntimeInitialized'] = bool(active)
        result['libraryRuntimeChanges'] = []
        ranges = [(0x49ffa0, 0x80), (0x4a0060, 0x2024),
                  (0x4aebc8, 0x60), (0x4afdec, 4), (0x4aec34, 4)]
        for _ in range(changes):
            address, length = struct.unpack('<II', take(8))
            if not active or not any(first <= address and 0 < length <= first + width - address
                                     for first, width in ranges):
                raise ValueError('CString bookkeeping escaped its declared runtime ranges')
            result['libraryRuntimeChanges'].append({'address': address,
                'before': take(length).hex(), 'after': take(length).hex()})
        active, pointer, width = struct.unpack('<III', take(12))
        if active > 1 or width > 4095 or (not active and (pointer or width)):
            raise ValueError('Invalid original HUD CString evidence')
        result['hudCStringInitialized'] = bool(active)
        if active:
            if case['routine'] not in (*range(56, 63),129) or not pointer:
                raise ValueError('Unexpected fixed HUD object normalization')
            result['hudCStringDataPointer'] = pointer
            result['hudText'] = take(width).decode('cp1252')
        result['elapsedPaintTicks'] = struct.unpack('<I',take(4))[0]
    if case.get('command')==19:
        count=struct.unpack('<I',take(4))[0]
        if count>32:raise ValueError('Retained shoreline observations exceed fixed bounds')
        result['nativeShorelineStackObservations']=[]
        for _ in range(count):
            values=struct.unpack('<4I3i',take(28))
            result['nativeShorelineStackObservations'].append(dict(zip(('entryEsp','first','last','camera','centerProjectedY','previousX','previousTreeY'),values)))
    if offset != len(payload):
        raise ValueError('Trailing native mutable-state bytes')
    return result


def decode_gdi_events(data):
    events, cursor = [], 0
    while cursor < len(data):
        if cursor + 8 > len(data):
            raise ValueError('Truncated native drawing event')
        op, size = struct.unpack_from('<II', data, cursor)
        cursor += 8
        if size > len(data) - cursor:
            raise ValueError('Truncated native drawing payload')
        value = data[cursor:cursor + size]
        cursor += size
        if op in (1, 2, 9, 10, 11):
            if size != 4:
                raise ValueError('Wrong scalar drawing event size')
            names = {1: ('selectStockObject', 'index', '<i'), 2: ('selectObject', 'handle', '<I'),
                9: ('setTextColor', 'color', '<I'), 10: ('setBkColor', 'color', '<I'), 11: ('setBkMode', 'mode', '<i')}
            name, field, fmt = names[op]
            events.append({'op': name, field: struct.unpack(fmt, value)[0]})
        elif op in (3, 4):
            if size != 8:
                raise ValueError('Wrong point drawing event size')
            x, y = struct.unpack('<2i', value)
            events.append({'op': 'moveTo' if op == 3 else 'lineTo', 'x': x, 'y': y})
        elif op == 5:
            if size < 4 or size != 4 + 8 * struct.unpack_from('<I', value)[0]:
                raise ValueError('Wrong polygon drawing event size')
            events.append({'op': 'polygon', 'points': [dict(zip(('x', 'y'), point)) for point in struct.iter_unpack('<2i', value[4:])]})
        elif op in (6, 7):
            if size != 16:
                raise ValueError('Wrong shape drawing event size')
            events.append({'op': 'ellipse' if op == 6 else 'rectangle', **dict(zip(('left', 'top', 'right', 'bottom'), struct.unpack('<4i', value)))})
        elif op == 8:
            if size != 12:
                raise ValueError('Wrong pixel drawing event size')
            x, y, color = struct.unpack('<iiI', value)
            events.append({'op': 'setPixel', 'x': x, 'y': y, 'color': color})
        elif op == 12:
            if size < 12 or struct.unpack_from('<I', value, 8)[0] != size - 12:
                raise ValueError('Wrong text drawing event size')
            x, y = struct.unpack('<2i', value[:8])
            events.append({'op': 'textOut', 'x': x, 'y': y, 'text': value[12:].decode('cp1252')})
        elif op in (13, 14):
            if size != 32:
                raise ValueError('Wrong arc drawing event size')
            events.append({'op': 'arc' if op == 13 else 'pie', **dict(zip(('left', 'top', 'right', 'bottom', 'startX', 'startY', 'endX', 'endY'), struct.unpack('<8i', value)))})
        elif op == 15:
            if size != 16:
                raise ValueError('Wrong clip rectangle event size')
            events.append({'op': 'pushClipRect', **dict(zip(('left', 'top', 'right', 'bottom'), struct.unpack('<4i', value)))})
        elif op == 16:
            if size:
                raise ValueError('Wrong clip restore event size')
            events.append({'op': 'popClipRect'})
        elif op == 17:
            if size != 24:
                raise ValueError('Wrong rounded rectangle event size')
            events.append({'op': 'roundRect', **dict(zip(('left', 'top', 'right', 'bottom', 'ellipseWidth', 'ellipseHeight'), struct.unpack('<6i', value)))})
        elif op == 18:
            if size != 4:
                raise ValueError('Wrong message beep event size')
            events.append({'op': 'messageBeep', 'type': struct.unpack('<I', value)[0]})
        elif op == 19:
            if size != 12:
                raise ValueError('Wrong synthetic pixel-read event size')
            x,y,color=struct.unpack('<iiI',value)
            events.append({'op': 'getPixel', 'x': x, 'y': y, 'color': color})
        else:
            raise ValueError('Unknown original drawing event')
    return events


def correct_full_state_fixture(path, report, report_path):
    """Preserve initial evidence before applying measured native output bytes."""
    fixture = json.loads(path.read_text())
    if not report['comparison_complete'] or not report['loaded_original_text_unchanged']:
        raise ValueError('Incomplete native evidence cannot correct expectations')
    if file_hash(path) != report['fixture_sha256'][path.name]:
        raise ValueError('Fixture changed during native comparison')
    differences = [row for row in report['differences'] if row['fixture'] == path.name]
    stack_evidence=[row for row in report.get('shoreline_stack_evidence',[]) if row['fixture']==path.name]
    if not differences and not stack_evidence:
        return
    if 'routines' not in fixture:
        raise ValueError('Automatic native correction requires full-state routine fixture')
    allowed = {'imageChanges', 'mutableBlockHash', 'rngState', 'sounds', 'residualEAX',
               'returnValue', 'returnBits', 'returnExtendedBits', 'drawingCommands', 'hudText'}
    for row in differences:
        if not set(row['fields']) <= allowed:
            raise ValueError('Unexpected native output field needs separate review')
        case = fixture['routines'][row['group']]['cases'][row['index']]
        for field, values in row['fields'].items():
            captured = case['expected'].get(field)
            if isinstance(case['expected'].get('returnValue'), dict) and field in ('returnValue', 'returnBits', 'returnExtendedBits'):
                captured = case['expected']['returnValue'][{'returnValue': 'value', 'returnBits': 'bits', 'returnExtendedBits': 'extendedBits'}[field]]
            if captured != values['fixture']:
                raise ValueError('Native correction baseline does not match fixture')
    stem = path.stem.removeprefix('original-')
    baseline = ROOT / f'analysis/{stem}-emulation-baseline.json.gz'
    historical = ROOT / f'analysis/{stem}-native-before-correction.json'
    raw = path.read_bytes()
    raw_hash = hashlib.sha256(raw).hexdigest()
    if baseline.exists() and hashlib.sha256(gzip.decompress(baseline.read_bytes())).hexdigest() != raw_hash:
        # Keep the first published evidence and use immutable hash-named files
        # for later input generations rather than overwriting old comparisons.
        baseline = ROOT / f'analysis/{stem}-emulation-{raw_hash[:16]}.json.gz'
        historical = ROOT / f'analysis/{stem}-native-{raw_hash[:16]}-before-correction.json'
    if baseline.exists():
        if gzip.decompress(baseline.read_bytes()) != raw:
            raise ValueError('Preserved emulation baseline content mismatch')
    else:
        baseline.write_bytes(gzip.compress(raw, mtime=0))
    if historical.exists():
        previous = json.loads(historical.read_text())
        if previous['fixture_sha256'].get(path.name) != raw_hash:
            raise ValueError('Preserved native discrepancy report uses different inputs')
    else:
        historical.write_bytes(report_path.read_bytes())
    for row in differences:
        case = fixture['routines'][row['group']]['cases'][row['index']]
        for field, values in row['fields'].items():
            if isinstance(case['expected'].get('returnValue'), dict) and field in ('returnValue', 'returnBits', 'returnExtendedBits'):
                case['expected']['returnValue'][{'returnValue': 'value', 'returnBits': 'bits', 'returnExtendedBits': 'extendedBits'}[field]] = values['native']
            else:
                case['expected'][field] = values['native']
    for row in stack_evidence:
        fixture['routines'][row['group']]['cases'][row['index']]['nativeShorelineStackObservations']=row['observations']
    if stack_evidence:
        fixture['provenance']['native_shoreline_stack_scope']='Read-only hardware observations of the actual bounded native caller stack at unchanged42d120 entry; these are concrete per-call inputs, not a universal initial value.'
    fixture['provenance']['native_corrections'] = {
        'original_sha256': SOURCE_SHA256, 'corrected_cases': len(differences),
        'reason': 'Exact observed original instructions on host x87 under Wine; emulator output retained for audit. No tolerance or original executable edits.',
        'runner_source_sha256': report['runner_source_sha256'],
        'emulation_fixture_sha256': hashlib.sha256(raw).hexdigest(),
        'preserved_emulation_fixture': str(baseline.relative_to(ROOT)),
        'comparison_before_correction': str(historical.relative_to(ROOT)),
        'comparison_before_correction_sha256': file_hash(historical)}
    fixture['provenance']['engine'] = 'Unicorn with documented native original-code corrections'
    path.write_text(json.dumps(fixture, indent=2, allow_nan=False) + '\n')
    (ROOT / f'analysis/{stem}-native-corrections.json').write_text(json.dumps({
        'original_sha256': SOURCE_SHA256,
        'emulation_fixture_sha256': hashlib.sha256(raw).hexdigest(),
        'corrected_fixture_sha256': file_hash(path), 'corrected_cases': len(differences),
        'comparison_before_correction_sha256': file_hash(historical)}, indent=2) + '\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture', action='append', help='Checked-in fixture filename; may repeat')
    parser.add_argument('--report', type=Path, default=ROOT / 'analysis/native-state-reference-comparison.json')
    parser.add_argument('--compiler', default=os.environ.get('TACT_MINGW_CC', DEFAULT_GCC))
    parser.add_argument('--wine', default=str(ROOT / 'tools/wine-runtime/bin/wine'))
    parser.add_argument('--prefix', type=Path, default=Path('/home/martin/.local/share/posey-simulator/wineprefix'))
    parser.add_argument('--timeout', type=float, default=180)
    parser.add_argument('--update-fixture', action='store_true', help='Retain emulator baseline and explicitly apply measured native full-state outputs')
    parser.add_argument('--observe-shore',action='store_true',help='Read-only hardware observations for fixed full scene128')
    parser.add_argument('--limit', type=int, help='First N cases per fixture for smoke checks')
    args = parser.parse_args()
    names = args.fixture or DEFAULT_FIXTURES
    if args.update_fixture and (len(names) != 1 or args.limit is not None):
        raise ValueError('Expectation correction requires one complete fixture')
    paths = [ROOT / 'tests/fixtures' / name for name in names]
    if any(path.parent != ROOT / 'tests/fixtures' for path in paths):
        raise ValueError('Fixture must be a checked-in filename')
    if file_hash(ROOT / 'original/Tact02Demo.exe') != SOURCE_SHA256:
        raise ValueError('Preserved original source SHA mismatch')
    cases, hashes, stream = [], {}, bytearray(struct.pack('<I', 11))
    control_words=set()
    for path in paths:
        fixture = json.loads(path.read_text())
        declared_control=int(fixture.get('provenance',{}).get('x87_control_word','0x037f'),0)
        if declared_control not in (0x027f,0x037f):raise ValueError('Unsupported original arithmetic context')
        control_words.add(declared_control)
        hashes[path.name] = file_hash(path)
        for number, case in enumerate(fixture_cases(fixture)):
            if args.limit is not None and number >= args.limit:
                break
            if 'drawingCommands' in case['expected']:
                case.setdefault('command', 15)
            if args.observe_shore:
                if case.get('command')!=15 or case['routine']!=128:raise ValueError('Only fixed complete scene128 admits shoreline stack observations')
                case['command']=19
            stream += encode_case(case)
            cases.append({key: value for key, value in case.items() if key != 'patches'} | {'fixture': path.name})
    if len(control_words)!=1:raise ValueError('Separate arithmetic precision contexts require separate native runs')
    control_word=next(iter(control_words))
    if len(cases) + 2 > COMMAND_LIMIT:
        raise ValueError('Known fixture cases exceed fixed command limit')
    stream += struct.pack('<I', 0)
    # Independent group comparisons may overlap; never overwrite a runner
    # which another fixed reference process is currently executing.
    executable_directory = ROOT / 'analysis/native-runners'
    executable_directory.mkdir(exist_ok=True)
    executable = executable_directory / (args.report.stem + '.exe')
    started = time.monotonic()
    flags = compile_runner(args.compiler, executable,ROOT/'tools/native_reference_pc53.c' if control_word==0x027f else None)
    version = subprocess.run([args.wine, '--version'], check=True, capture_output=True, text=True).stdout.strip()
    report = {'source_sha256': SOURCE_SHA256, 'fixture_sha256': hashes,
        'runner_source_sha256': file_hash(ROOT / 'tools/native_reference_2002.c'),
        'runner_sha256': file_hash(executable), 'compiler_flags': flags, 'wine_version': version,
        'host_machine': platform.machine(), 'scope': 'Fixed reviewed original routines, finite synthetic prepared states, complete mutable block bytes/hash plus RNG and ordered sound requests. No whole Windows lifecycle or full UI claim.',
        'mapping': 'Unchanged original instructions at preferred base in dedicated host-owned PE section. IAT runtime glue and isolated CRT TLS data initialized; original entrypoint is not run.',
        'tls_hash_normalization': 'Only 0x49fe40..0x49fe43 uses original on-disk TLS-index bytes when hashing/comparing; actual runtime keeps its allocated slot.',
        'x87_control_word': f'0x{control_word:04x}', 'protocol_command_limit': COMMAND_LIMIT,
        'groups': {}, 'differences': [], 'comparison_complete': False,
        'drawing_requests_compared': 0, 'sound_requests_compared': 0,
        'cstring_runtime_cases': 0, 'library_runtime_evidence': [],
        'hud_cstring_pointer_evidence': []}
    report['runner_path'] = str(executable.relative_to(ROOT))
    report['verifier_source_sha256'] = file_hash(Path(__file__))
    cpu_info = Path('/proc/cpuinfo')
    if cpu_info.exists():
        report['host_cpu_model'] = next((line.partition(':')[2].strip()
            for line in cpu_info.read_text().splitlines() if line.startswith('model name')), None)
    report['runtime_header_sha256'] = {name: file_hash(ROOT / 'tools' / name)
        for name in ('native_encounter_schema.h', 'native_gdi_trace.h', 'native_cstring_runtime.h')}
    report['cstring_runtime_normalizations'] = [
        {'address': 0x49ffa0, 'size': 0x80, 'purpose': 'Original CRT lock-pointer table'},
        {'address': 0x4a0060, 'size': 0x2024, 'purpose': 'Original CRT small-block-heap root/descriptors'},
        {'address': 0x4aebc8, 'size': 0x60, 'purpose': 'Four original CRT critical sections'},
        {'address': 0x4afdec, 'size': 4, 'purpose': 'Original CRT heap handle'},
        {'address': 0x4aec34, 'size': 4, 'purpose': 'Original SBH free-page counter; writes in 0045bc60/0045bb30'}]
    report['cstring_runtime_scope'] = ('For fixed drawing calls requiring strings, original CRT startup leaves '
        '0x45b700 and 0x45b3c0 initialize locks/heap; original CString and formatter instructions execute. '
        'Only these declared allocator bookkeeping ranges are normalized to prepared comparison bytes. '
        'Their raw before/after differences are retained separately; game state and text remain exact.')
    report['hud_cstring_pointer_normalization'] = {
        'address': 0x4a7048, 'size': 4,
        'scope': 'Only fixed HUD routines56–62 and complete frame129. Original constructor46bd7a initializes the object '
                 'before the call; original destructor46bec5 releases it after recording evidence. '
                 'The host allocation pointer is normalized to prepared bytes for state comparisons; '
                 'actual pointer and complete cp1252 text are recorded, and fixture hudText is strict.'}
    from native_fixture_adapter import ROUTINE_IDS
    addresses = {identifier: address for address, identifier in ROUTINE_IDS.items()}
    addresses.update({3: 0x426150, 7: 0x425600, 8: 0x425910, 9: 0x427030})
    from native_fixture_adapter import GDI_ROUTINE_IDS
    gdi_addresses = {identifier: address for address, identifier in GDI_ROUTINE_IDS.items()}
    pure_addresses = {0: 0x415dc0, 1: 0x413d00, 2: 0x413d90}
    report['original_routine_addresses'] = sorted({f'{(gdi_addresses if case.get("command") in (15,19) else pure_addresses if case.get("command") == 16 else addresses)[case["routine"]]:08x}' for case in cases})
    try:
        environment = {**os.environ, 'WINEPREFIX': str(args.prefix), 'WINEDEBUG': '-all'}
        source_windows = 'Z:' + str(ROOT / 'original/Tact02Demo.exe').replace('/', '\\')
        process = subprocess.run([args.wine, str(executable), source_windows], input=stream,
                                 capture_output=True, env=environment, timeout=args.timeout)
        (ROOT / 'analysis/native-state-reference-wine.log').write_bytes(process.stderr)
        report['process_exit_code'] = process.returncode
        if process.returncode:
            raise ValueError('Native state runner failed: ' + process.stderr.decode(errors='replace')[-2000:])
        output = process.stdout
        if len(output) < 32 or output[:8] != b'TACT2002':
            raise ValueError('Missing native original-code initialization')
        version_id, base, tls, imports, cw, mapping = struct.unpack('<6I', output[8:32])
        if (version_id, base, cw, mapping) != (2, 0x400000, control_word, 1):
            raise ValueError('Unexpected native original-code metadata')
        report['native_initialization'] = {'base': hex(base), 'runtime_tls_index': tls,
                                           'imports_resolved': imports}
        offset = 32
        def response(expected_command):
            nonlocal offset
            if offset + 8 > len(output):
                raise ValueError('Missing native state response')
            command, length = struct.unpack_from('<II', output, offset)
            offset += 8
            if command != expected_command or length > 262144 or offset + length > len(output):
                raise ValueError('Invalid native state framing/order')
            payload = output[offset:offset + length]
            offset += length
            return payload
        if response(11) != struct.pack('<I', 1):
            raise ValueError('Known sound recorder was not initialized')
        report['shoreline_stack_evidence']=[]
        for case in cases:
            actual = decode_state(response(case.get('command', 14)), case)
            if 'nativeShorelineStackObservations' in actual:
                report['shoreline_stack_evidence'].append({**{key:case[key] for key in ('fixture','group','index','routine')},'observations':actual['nativeShorelineStackObservations']})
            report['drawing_requests_compared'] += len(actual.get('drawingCommands', []))
            report['sound_requests_compared'] += len(actual.get('sounds', []))
            if actual.get('cstringRuntimeInitialized'):
                report['cstring_runtime_cases'] += 1
                report['library_runtime_evidence'].append({
                    **{key: case[key] for key in ('fixture', 'group', 'index', 'routine')},
                    'changes': actual['libraryRuntimeChanges']})
            if actual.get('hudCStringInitialized'):
                report['hud_cstring_pointer_evidence'].append({
                    **{key: case[key] for key in ('fixture', 'group', 'index', 'routine')},
                    'actual_data_pointer': actual['hudCStringDataPointer'],
                    'actual_text': actual['hudText']})
            group = report['groups'].setdefault(case['group'], {'cases': 0, 'exact_matches': 0, 'different_cases': 0, 'different_fields': {}})
            group['cases'] += 1
            differences = {field: {'fixture': expected, 'native': actual.get(field)}
                for field, expected in case['expected'].items() if actual.get(field) != expected}
            if differences:
                group['different_cases'] += 1
                for field in differences:
                    group['different_fields'][field] = group['different_fields'].get(field, 0) + 1
                report['differences'].append({key: case[key] for key in ('fixture', 'group', 'index', 'routine')} | {'fields': differences})
            else:
                group['exact_matches'] += 1
        if response(0) != struct.pack('<I', 1) or offset != len(output):
            raise ValueError('Original .text integrity acknowledgement failed')
        report.update(comparison_complete=True, loaded_original_text_unchanged=True,
            function_cases=len(cases), exact_function_cases=sum(group['exact_matches'] for group in report['groups'].values()),
            all_fixture_cases_match=not report['differences'])
    except Exception as error:
        report['error'] = str(error)
        if 'output' in locals():
            (ROOT / 'analysis/native-state-reference-output-failed.bin').write_bytes(output)
        raise
    finally:
        report['original_file_unchanged'] = file_hash(ROOT / 'original/Tact02Demo.exe') == SOURCE_SHA256
        report['elapsed_seconds'] = time.monotonic() - started
        from compact_native_reports import externalize_runtime_evidence
        externalize_runtime_evidence(report,args.report)
        args.report.write_text(json.dumps(report, indent=2, allow_nan=False) + '\n')
    if args.update_fixture:
        correct_full_state_fixture(paths[0], report, args.report)
    print(json.dumps({key: report[key] for key in ('comparison_complete', 'function_cases', 'exact_function_cases', 'groups', 'loaded_original_text_unchanged', 'original_file_unchanged')}, indent=2))


if __name__ == '__main__':
    main()
