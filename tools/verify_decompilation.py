#!/usr/bin/env python3
"""Independently verify the fixed 2002 export and original discovery evidence."""
import gzip
import hashlib
import json
import re
from pathlib import Path

from extract_resources import PE

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = '881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'


def digest(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads((ROOT / path).read_text())


def main():
    original = (ROOT / 'original/Tact02Demo.exe').read_bytes()
    assert digest(original) == EXPECTED, 'Original hash mismatch'
    pe = PE(original)

    def original_bytes(address, expected):
        data = bytes.fromhex(expected)
        offset = pe.offset(int(address, 16) - 0x400000)
        assert original[offset:offset + len(data)] == data, 'Original evidence mismatch at ' + address

    summary = load('decompiled/summary.json')
    rows = [json.loads(line) for line in (ROOT / 'decompiled/functions.jsonl').read_text().splitlines()]
    by_address = {row['address']: row for row in rows}
    assert len(by_address) == len(rows) == summary['functions'] == summary['expected_functions']
    assert summary['export_complete'] and summary['failed'] == 0 and summary['decompiled'] == len(rows)
    assert set(row['file'] for row in rows) == set('functions/' + path.name for path in (ROOT / 'decompiled/functions').glob('*.c'))
    combined = (ROOT / 'decompiled/recovered.c').read_bytes()
    bodies = {}
    for row in rows:
        body = (ROOT / 'decompiled' / row['file']).read_bytes()
        assert row['decompiled'] and digest(body) == row['c_sha256']
        assert body in combined
        bodies[row['address']] = body.decode()
    for record in summary['recovery_evidence'] + [summary['signature_corrections']]:
        assert digest((ROOT / 'decompiled' / record['file']).read_bytes()) == record['sha256']
    externals = load('decompiled/external-functions.json')
    data_lines = (ROOT / 'decompiled/defined-data.jsonl').read_text().splitlines()
    assert len(externals) == summary['external_functions']
    assert len(data_lines) == summary['defined_data']
    for line in data_lines:
        json.loads(line)
    recovery = load('analysis/function-recovery.json')
    for item in recovery['created']:
        assert item['address'] in by_address
        original_bytes(item['address'], item['entry_bytes'])
        evidence = item['evidence']
        kind = evidence['kind']
        if 'instruction_bytes' in evidence:
            original_bytes(evidence['source'], evidence['instruction_bytes'])
        if 'pointer_bytes' in evidence:
            original_bytes(evidence['source'], evidence['pointer_bytes'])
        if 'original_record_bytes' in evidence:
            original_bytes(evidence['record_address'], evidence['original_record_bytes'])
        if 'func_info' in evidence:
            original_bytes(evidence['func_info']['address'], evidence['func_info']['record_bytes'])
        if kind == 'validated_cruntime_class_create_object':
            original_bytes(evidence['record']['recordVA'], evidence['record_bytes'])
        if kind in ('validated_seh3_filter', 'validated_seh3_handler'):
            start = int(evidence['source'], 16) - (4 if kind.endswith('filter') else 8)
            original_bytes('%08x' % start, evidence['scope_record_bytes'])
            for key in ('handler_push', 'prolog_push'):
                original_bytes(evidence['association'][key]['address'], evidence['association'][key]['bytes'])
    for item in recovery['analysis_created_details']:
        assert item['address'] in by_address and item['references']
        for reference in item['references']:
            original_bytes(reference['source'], reference['source_bytes'])
    baseline_path = ROOT / 'analysis/recovery-baseline/functions.jsonl.gz'
    baseline = {row['address']: row for row in map(json.loads, gzip.decompress(baseline_path.read_bytes()).decode().splitlines())}
    changed = [address for address in baseline if by_address[address]['c_sha256'] != baseline[address]['c_sha256']]
    patterns = {'unaff_': r'unaff_', 'extraout_': r'extraout_',
                'unknown_x87': r'(?:extraout|unaff|in)_ST\d+',
                'no_argument_ftol': r'__ftol\(\s*\)',
                'unresolved_jumptable': r'WARNING: Could not recover jumptable',
                'indirect_jump_as_call': r'WARNING: Treating indirect jump as call',
                'overlapping_globals': r'WARNING: Globals starting'}
    audit = {}
    for name, pattern in patterns.items():
        counts = {address: len(re.findall(pattern, body)) for address, body in bodies.items()}
        audit[name] = {'functions': sum(count > 0 for count in counts.values()), 'occurrences': sum(counts.values()),
                       'addresses': [address for address, count in counts.items() if count]}
    fpatan = [{'address': address, 'line': line.strip(), 'result_assigned': '=' in line.split('fpatan')[0]}
              for address, body in bodies.items() for line in body.splitlines() if 'fpatan(' in line]
    corrections = load('decompiled/signature-corrections.json')
    for change in corrections['changes']:
        after = change['after']
        if after['address'] in ('00420b70', '00420c40', '00420d10'):
            assert after['custom_storage'] and after['return_storage'] == 'ST0:10'
            assert after['return_type'] == 'float10' and len(after['parameters']) == 3
            assert [param['storage'] for param in after['parameters']] == ['Stack[0x4]:4', 'Stack[0x8]:4', 'Stack[0xc]:4']
    report = {'verified_functions': len(rows), 'verified_function_sha256': True,
              'combined_contains_all_function_bodies': True, 'unique_addresses': True,
              'no_missing_or_extra_files': True, 'verified_external_functions': len(externals),
              'verified_defined_data_entries': len(data_lines), 'failed': 0, 'source_sha256': EXPECTED,
              'recovered_c_bytes': len(combined), 'recovered_c_sha256': digest(combined),
              'added_functions_since_recovery_baseline': len(set(by_address) - set(baseline)),
              'changed_baseline_function_count': len(changed), 'changed_baseline_function_addresses': changed,
              'original_bytes_verified_for_every_recovery_record': True,
              'explicit_recovery_functions': len(recovery['created']),
              'automatic_recovery_functions_with_original_references': len(recovery['analysis_created_details']),
              'coverage': load('analysis/decompilation-coverage.json')['totals'],
              'numeric_artifact_audit': audit, 'fpatan': fpatan, 'recovery_evidence_hashes_match': True}
    (ROOT / 'analysis/decompilation-export-verification.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: report[key] for key in ('verified_functions', 'failed', 'recovered_c_bytes', 'recovered_c_sha256')}))


if __name__ == '__main__':
    main()
