#!/usr/bin/env python3
"""Validate original MFC message maps and CRuntimeClass create-object records."""
from __future__ import annotations
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path
from extract_resources import PE

EXPECTED_SHA256 = '881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'

def discover(binary: Path, output: Path) -> dict:
    data = binary.read_bytes()
    if hashlib.sha256(data).hexdigest() != EXPECTED_SHA256:
        raise ValueError('Expected the preserved 2002 original executable')
    pe = PE(data)
    base = 0x400000
    sections = pe.sections
    def section_of(address):
        return next((s for s in sections if base+s['virtual_address'] <= address < base+s['virtual_address']+max(s['virtual_size'],s['raw_size'])), None)
    def is_code(address):
        s = section_of(address)
        return s is not None and s['name'] == '.text'
    def is_data(address):
        s = section_of(address)
        return s is not None and s['name'] in ('.rdata', '.data')
    def at(address, count):
        offset = pe.offset(address-base)
        return data[offset:offset+count]
    def string(address):
        if not is_data(address):
            return None
        try:
            raw = at(address, 128).split(b'\0', 1)[0]
        except ValueError:
            return None
        if len(raw) < 2 or not re.fullmatch(rb'C[A-Za-z0-9_]{1,100}', raw):
            return None
        return raw.decode('ascii')
    candidates = {}
    for section in sections:
        if section['name'] not in ('.rdata', '.data'):
            continue
        first = base+section['virtual_address']
        for address in range(first, first+section['raw_size']-23, 4):
            message, code, first_id, last_id, signature, handler = struct.unpack('<6I', at(address,24))
            signature_ok = 0 < signature <= 0x100 or message == 0xc000 and is_data(signature)
            if 0 < message <= 0xffff and first_id <= last_id <= 0xffff and signature_ok and is_code(handler):
                candidates[address] = {'recordVA': f'{address:08x}', 'fileOffset': pe.offset(address-base),
                    'nMessage': message, 'nCode': code, 'nID': first_id, 'nLastID': last_id, 'nSig': signature,
                    'functionVA': f'{handler:08x}', 'menuCaption': None,
                    'signatureKind': 'registered_message_id_pointer' if message == 0xc000 and is_data(signature) else 'AFX signature ordinal'}
    tables = []
    seen = set()
    for address in sorted(candidates):
        if address in seen or address-24 in candidates:
            continue
        cursor, entries = address, []
        while cursor in candidates:
            entries.append(candidates[cursor]); cursor += 24
        if len(entries) >= 2 and is_data(cursor) and at(cursor,24) == bytes(24):
            tables.append({'sourceVA': f'{address:08x}', 'terminatorVA': f'{cursor:08x}', 'entryStride': 24, 'entries': entries})
            seen.update(range(address,cursor,24))
    maps = {'source_sha256': EXPECTED_SHA256, 'format': 'Original AFX_MSGMAP_ENTRY: nMessage,nCode,nID,nLastID,nSig,pfn, six little-endian uint32 fields; all-zero terminator.',
            'registered_message_rule': 'For nMessage 0xc000 nSig is an original pointer to a registered-message ID in data, rather than a signature ordinal.',
            'tables': tables, 'table_count': len(tables), 'entry_count': sum(len(t['entries']) for t in tables)}
    constructors = []
    for section in sections:
        if section['name'] not in ('.rdata', '.data'):
            continue
        first = base+section['virtual_address']
        for address in range(first, first+section['raw_size']-23,4):
            name_address, size, schema, create, parent, following = struct.unpack('<6I', at(address,24))
            name = string(name_address)
            if not name or not 0 < size <= 0x100000 or schema != 0xffff or not is_code(create):
                continue
            if parent and (not is_data(parent) or string(struct.unpack('<I',at(parent,4))[0]) is None):
                continue
            if following and not is_data(following):
                continue
            constructors.append({'recordVA': f'{address:08x}', 'fileOffset': pe.offset(address-base), 'className': name,
                'classNameVA': f'{name_address:08x}', 'objectSize': size, 'schema': schema, 'functionVA': f'{create:08x}',
                'baseClassVA': f'{parent:08x}' if parent else None, 'nextClassVA': f'{following:08x}' if following else None,
                'pointerVA': f'{address+12:08x}', 'recordBytes': at(address,24).hex(' ')})
    classes = {'source_sha256': EXPECTED_SHA256, 'format': 'Original CRuntimeClass six-word records: name pointer, object size, schema, create-object callback, base-class pointer, next-class pointer.', 'entries': constructors}
    output.mkdir(parents=True, exist_ok=True)
    (output/'message-map-candidates.json').write_text(json.dumps(maps,indent=2)+'\n')
    (output/'runtime-class-candidates.json').write_text(json.dumps(classes,indent=2)+'\n')
    return {'message_maps': maps['table_count'], 'message_map_entries': maps['entry_count'], 'runtime_class_callbacks': len(constructors)}

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, default=Path(__file__).resolve().parent.parent/'original/Tact02Demo.exe')
    parser.add_argument('--output', type=Path, default=Path(__file__).resolve().parent.parent/'analysis')
    arguments = parser.parse_args()
    print(json.dumps(discover(arguments.binary, arguments.output),sort_keys=True))
