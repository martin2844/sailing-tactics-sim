#!/usr/bin/env python3
"""Compare every captured x87 probe with actual local x86 hardware.

Native results become authoritative expected values. Every differing emulated
value is preserved with both sources in the comparison report and per-case
overrides. This does not execute the Windows application or modify its binary.
"""
from pathlib import Path
import hashlib
import json
import os
import platform
import struct
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def load(path):
    return json.loads(path.read_text())


def save(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2) + '\n')


def verify():
    source = ROOT / 'tools/capture_x87_native.c'
    arithmetic_path = ROOT / 'tests/fixtures/original-x87.json'
    trig_path = ROOT / 'assets/data/x87-trig.json'
    calibration_path = ROOT / 'assets/data/boat-calibration.json'
    fixtures, trig, calibration = [load(path) for path in [arithmetic_path, trig_path, calibration_path]]
    original = (ROOT / 'original/Tact02Demo.exe').read_bytes()
    original_hash = hashlib.sha256(original).hexdigest()
    for document in [fixtures, trig, calibration]:
        if document['provenance']['sha256'] != original_hash:
            raise RuntimeError('Reference document does not identify the unchanged original executable')
    # Confirm the native trigonometry probe consumes the original stored degree
    # factor, not a freshly computed pi/180 or an unverified reference constant.
    pe = struct.unpack_from('<I', original, 0x3c)[0]
    optional = pe + 24
    image_base = struct.unpack_from('<I', original, optional + 28)[0]
    section_count = struct.unpack_from('<H', original, pe + 6)[0]
    section_table = optional + struct.unpack_from('<H', original, pe + 20)[0]
    factor_rva = trig['degreeFactorAddress'] - image_base
    factor_bits = None
    for index in range(section_count):
        offset = section_table + index * 40
        rva, raw_size, file_offset = struct.unpack_from('<III', original, offset + 12)
        if rva <= factor_rva and factor_rva + 8 <= rva + raw_size:
            factor_bits = original[file_offset + factor_rva - rva:file_offset + factor_rva - rva + 8].hex()
            break
    if factor_bits != trig['degreeFactorBits']:
        raise RuntimeError('Trigonometric degree factor differs from the original executable bytes')
    compiler = os.environ.get('CC', 'gcc')
    cpu = {}
    cpu_info = Path('/proc/cpuinfo')
    if cpu_info.exists():
        for line in cpu_info.read_text().splitlines():
            if ':' in line:
                key, value = [part.strip() for part in line.split(':', 1)]
                if key in ['vendor_id', 'model name', 'cpu family', 'model', 'stepping', 'microcode'] and key not in cpu:
                    cpu[key] = value
    native_provenance = {
        'engine': 'native-x87', 'architecture': platform.machine(),
        'cpu': cpu,
        'control_word': '0x037f',
        'probe_source': 'tools/capture_x87_native.c',
        'probe_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
        'compiler': subprocess.run([compiler, '--version'], check=True, capture_output=True, text=True).stdout.splitlines()[0],
        'note': 'Actual local x87 instructions; current-hardware evidence, not historical CPU equivalence.',
    }
    commands = []
    for case in fixtures['arithmetic']:
        commands.append(' '.join([case['operation'], case['leftBits']] + ([case['rightBits']] if 'rightBits' in case else [])))
    for case in fixtures['truncation']:
        commands.append('ftol ' + case['inputBits'])
    for angle in trig['angles']:
        commands.append(f"trig {angle} {trig['degreeFactorBits']}")
    for length in calibration['lengths']:
        commands.append('calibration ' + length)
    with tempfile.TemporaryDirectory(prefix='tact-native-x87-') as directory:
        binary = Path(directory) / 'capture'
        subprocess.run([compiler, '-std=c11', '-O2', '-Wall', '-Wextra', '-fno-fast-math', str(source), '-o', str(binary)], check=True)
        run = subprocess.run([str(binary)], input='\n'.join(commands) + '\n', text=True, capture_output=True, check=True)
    results = iter(run.stdout.splitlines())
    if len(run.stdout.splitlines()) != len(commands):
        raise RuntimeError('Native probe result count differs from input count')
    report = {'native_provenance': native_provenance, 'source_sha256': fixtures['provenance']['sha256'],
        'arithmetic': {'count': len(fixtures['arithmetic']), 'mismatches': []},
        'truncation': {'count': len(fixtures['truncation']), 'mismatches': []},
        'trigonometry': {'angles': len(trig['angles']), 'values': len(trig['angles']) * 2, 'mismatches': []},
        'boat_calibration': {'count': len(calibration['lengths']), 'mismatches': []}}

    for index, case in enumerate(fixtures['arithmetic']):
        extended, stored = next(results).split()
        native = {'extendedBits': extended, 'storedDoubleBits': stored}
        emulated = case.get('emulatedExpected', case['expected'])
        if native != emulated:
            report['arithmetic']['mismatches'].append({'index': index, 'operation': case['operation'],
                'leftBits': case['leftBits'], 'rightBits': case.get('rightBits'), 'emulated': emulated, 'native': native})
            case['emulatedExpected'] = emulated
            case['nativeOverride'] = native_provenance
        case['expected'] = native
        case['referenceEngine'] = 'native-x87'
    for index, case in enumerate(fixtures['truncation']):
        signed64, signed32 = next(results).split()
        native = {'integer64': signed64, 'integer32': int(signed32)}
        emulated = case.get('emulatedExpected', case['expected'])
        if native != emulated:
            report['truncation']['mismatches'].append({'index': index, 'inputBits': case['inputBits'], 'emulated': emulated, 'native': native})
            case['emulatedExpected'] = emulated
            case['nativeOverride'] = native_provenance
        case['expected'] = native
        case['referenceEngine'] = 'native-x87'
    for angle, case in trig['angles'].items():
        sine, cosine = next(results).split()
        for name, native in [('sineBits', sine), ('cosineBits', cosine)]:
            emulated_key = 'emulated' + name[0].upper() + name[1:]
            emulated = case.get(emulated_key, case[name])
            if native != emulated:
                report['trigonometry']['mismatches'].append({'angle': int(angle), 'function': name, 'emulated': emulated, 'native': native})
                case[emulated_key] = emulated
            case[name] = native
        case['referenceEngine'] = 'native-x87'
    for length, case in calibration['lengths'].items():
        extended, stored = next(results).split()
        native_value = struct.unpack('<d', bytes.fromhex(stored))[0]
        emulated = case.get('emulatedBits', case['bits'])
        if stored != emulated:
            report['boat_calibration']['mismatches'].append({'length': int(length), 'emulated': emulated, 'native': stored})
            case['emulatedBits'] = emulated
        case['bits'], case['value'] = stored, native_value
        case['extendedBits'] = extended
        case['referenceEngine'] = 'native-x87'
    for document in [fixtures, trig, calibration]:
        document['provenance']['authoritative_engine'] = 'native-x87'
        document['provenance']['native_verification'] = native_provenance
    report['summary'] = {name: len(report[name]['mismatches']) for name in ['arithmetic', 'truncation', 'trigonometry', 'boat_calibration']}
    save(arithmetic_path, fixtures)
    save(trig_path, trig)
    save(calibration_path, calibration)
    save(ROOT / 'analysis/x87-reference-comparison.json', report)
    print(json.dumps({'native_verified': True, 'mismatch_counts': report['summary'],
        'arithmetic': len(fixtures['arithmetic']), 'truncations': len(fixtures['truncation']),
        'trig_angles': len(trig['angles']), 'calibration_lengths': len(calibration['lengths'])}, indent=2))
    return report


if __name__ == '__main__':
    verify()
