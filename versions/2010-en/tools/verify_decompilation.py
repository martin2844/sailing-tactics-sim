#!/usr/bin/env python3
"""Independently verify the complete exact-target 2010 export and discovery bytes."""
import hashlib
import json
from pathlib import Path
import pefile

EDITION=Path(__file__).resolve().parents[1]
EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'

def digest(data):return hashlib.sha256(data).hexdigest()

def main():
    original=(EDITION/'runtime/Tactics2010EnglishPreserved.exe').read_bytes()
    assert digest(original)==EXPECTED,'Unexpected preserved original image'
    pe=pefile.PE(data=original)
    def original_bytes(address,hex_bytes):
        expected=bytes.fromhex(hex_bytes)
        offset=pe.get_offset_from_rva(int(address,16)-0x400000)
        assert original[offset:offset+len(expected)]==expected,f'Original evidence differs at {address}'
    decompiled=EDITION/'decompiled'
    summary=json.loads((decompiled/'summary.json').read_text())
    rows=[json.loads(line) for line in (decompiled/'functions.jsonl').read_text().splitlines()]
    by_address={row['address']:row for row in rows}
    assert len(by_address)==len(rows)==summary['functions']==summary['expected_functions']
    assert summary['source_sha256']==EXPECTED
    assert summary['export_complete'] and not summary['cancelled'] and summary['failed']==0 and summary['decompiled']==len(rows)
    assert set(row['file'] for row in rows)==set('functions/'+path.name for path in (decompiled/'functions').glob('*.c'))
    combined=(decompiled/'recovered.c').read_bytes()
    for row in rows:
        body=(decompiled/row['file']).read_bytes()
        assert row['decompiled'] and not row['error'] and digest(body)==row['c_sha256']
        assert body in combined,f'Combined export omits {row["file"]}'
    for record in summary['recovery_evidence']:
        assert digest((decompiled/record['file']).read_bytes())==record['sha256']
    externals=json.loads((decompiled/'external-functions.json').read_text())
    data_rows=[json.loads(line) for line in (decompiled/'defined-data.jsonl').read_text().splitlines()]
    assert len(externals)==summary['external_functions']
    assert len(data_rows)==summary['defined_data']
    recovery=json.loads((EDITION/'analysis/function-recovery.json').read_text())
    for item in recovery['created']:
        assert item['address'] in by_address
        original_bytes(item['address'],item['entry_bytes'])
        evidence=item['evidence'];kind=evidence['kind']
        for key,address_key in [('instruction_bytes','source'),('pointer_bytes','source'),('original_record_bytes','record_address')]:
            if key in evidence:original_bytes(evidence[address_key],evidence[key])
        if 'func_info' in evidence:original_bytes(evidence['func_info']['address'],evidence['func_info']['record_bytes'])
        if kind=='validated_cruntime_class_create_object':original_bytes(evidence['record']['recordVA'],evidence['record_bytes'])
        if kind in ('validated_seh3_filter','validated_seh3_handler'):
            start=int(evidence['source'],16)-(4 if kind.endswith('filter') else 8)
            original_bytes(f'{start:08x}',evidence['scope_record_bytes'])
            for key in ['handler_push','prolog_push']:original_bytes(evidence['association'][key]['address'],evidence['association'][key]['bytes'])
    for item in recovery['analysis_created_details']:
        assert item['address'] in by_address and item['references']
        for reference in item['references']:original_bytes(reference['source'],reference['source_bytes'])
    coverage=json.loads((EDITION/'analysis/decompilation-coverage.json').read_text())
    report={'sourceSha256':EXPECTED,'verifiedFunctions':len(rows),'failed':0,
        'verifiedFunctionHashes':True,'combinedContainsEveryBody':True,'uniqueAddresses':True,
        'noMissingOrExtraFiles':True,'recoveryEvidenceHashesMatch':True,
        'originalBytesVerifiedForEveryRecoveryRecord':True,
        'explicitRecoveryFunctions':len(recovery['created']),
        'automaticRecoveryFunctionsWithOriginalReferences':len(recovery['analysis_created_details']),
        'externalFunctions':len(externals),'definedDataEntries':len(data_rows),
        'recoveredCBytes':len(combined),'recoveredCSha256':digest(combined),'coverage':coverage['totals']}
    (EDITION/'analysis/decompilation-export-verification.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({key:report[key] for key in ['verifiedFunctions','failed','recoveredCBytes','recoveredCSha256']}))

if __name__=='__main__':main()
