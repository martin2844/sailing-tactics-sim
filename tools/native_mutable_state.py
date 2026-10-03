"""Materialize fixed Posey 2002 mutable state for bounded native comparisons.

Only the preserved PE data interval 0x491000..0x4ae000 is accepted. Original
.text, IAT and host state are outside this patch interface. The real CRT TLS
index at 0x49fe40 is never overwritten by protocol patches, and is normalized
to the recorded prepared input solely when comparing/hash-normalizing output.
"""
from pathlib import Path
import hashlib
import json
import re
import struct
import pefile

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'original/Tact02Demo.exe'
SOURCE_SHA256 = '881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'
BLOCK_ADDRESS, BLOCK_SIZE = 0x491000, 0x1d000
TLS_INDEX_ADDRESS, TLS_INDEX_SIZE = 0x49fe40, 4
TLS_INDEX_OFFSET = TLS_INDEX_ADDRESS - BLOCK_ADDRESS
_original = None
_integer_trig = {}


def original_baseline():
    """Return a fresh original mapped .data/BSS block after SHA verification."""
    global _original
    if _original is None:
        raw = SOURCE.read_bytes()
        if hashlib.sha256(raw).hexdigest() != SOURCE_SHA256:
            raise ValueError('Preserved Posey 2002 source SHA-256 mismatch')
        pe = pefile.PE(data=raw)
        if pe.OPTIONAL_HEADER.ImageBase != 0x400000 or pe.OPTIONAL_HEADER.SizeOfImage != 0x111000:
            raise ValueError('Unexpected original PE layout')
        mapped = bytearray(pe.OPTIONAL_HEADER.SizeOfImage)
        image = pe.get_memory_mapped_image()
        mapped[:len(image)] = image
        offset = BLOCK_ADDRESS - pe.OPTIONAL_HEADER.ImageBase
        _original = bytes(mapped[offset:offset + BLOCK_SIZE])
    return bytearray(_original)


def _spec(row):
    address = row.get('address')
    bits = row.get('bits', row.get('after'))
    if not isinstance(address, int) or isinstance(address, bool):
        raise TypeError('Patch address must be an integer')
    if not isinstance(bits, str) or len(bits) % 2 or any(character not in '0123456789abcdefABCDEF' for character in bits):
        raise ValueError('Patch bits must be complete hexadecimal bytes')
    data = bytes.fromhex(bits)
    if address < BLOCK_ADDRESS or address + len(data) > BLOCK_ADDRESS + BLOCK_SIZE:
        raise ValueError(f'Patch 0x{address:x}+{len(data)} exceeds fixed mutable block')
    return address - BLOCK_ADDRESS, data


def apply_patches(block, patches):
    """Apply validated captured bytes to an in-memory comparison block."""
    if len(block) != BLOCK_SIZE:
        raise ValueError('Mutable block has unexpected size')
    for row in patches:
        offset, data = _spec(row)
        block[offset:offset + len(data)] = data
    return block


def _i32_table(block, address, values):
    if not isinstance(values, list):
        raise TypeError('Recorded integer table must be a list')
    data = b''.join(struct.pack('<I', value & 0xffffffff) for value in values)
    apply_patches(block, [{'address': address, 'bits': data.hex()}])


def baseline_for_fixture(fixture):
    """Original mapped PE block, integer trig tables, and declared baseline data."""
    if fixture.get('provenance', {}).get('sha256') != SOURCE_SHA256:
        raise ValueError('Fixture source SHA-256 does not match fixed original')
    declared_block = fixture.get('mutableBlock')
    if declared_block and declared_block != {'address': BLOCK_ADDRESS, 'size': BLOCK_SIZE}:
        raise ValueError('Fixture declares a different mutable block')
    block = original_baseline()
    control_word = fixture.get('provenance', {}).get('x87_control_word', '0x037f')
    if control_word not in ('0x027f', '0x037f'):
        raise ValueError('Fixture declares unsupported native arithmetic context')
    if control_word not in _integer_trig:
        table_path = 'assets/data/pc53/trig-tables.json' if control_word == '0x027f' else 'assets/data/trig-tables.json'
        tables = json.loads((ROOT / table_path).read_text())
        if tables.get('provenance', {}).get('sha256') != SOURCE_SHA256:
            raise ValueError('Integer trig capture source SHA mismatch')
        declared_precision = tables.get('provenance', {}).get('x87_control_word', '0x037f')
        if declared_precision != control_word:
            raise ValueError('Integer trig capture arithmetic context mismatch')
        _integer_trig[control_word] = tuple((address, b''.join(struct.pack('<I', value & 0xffffffff) for value in values))
            for address, values in ((0x4a54a0, tables['sine']), (0x4a3450, tables['cosine'])))
    for address, data in _integer_trig[control_word]:
        offset = address - BLOCK_ADDRESS
        block[offset:offset + len(data)] = data
    baseline = fixture.get('baseline', {})
    random_table = baseline.get('randomTable', fixture.get('randomTable'))
    random_address = baseline.get('randomTableAddress', fixture.get('randomTableAddress', 0x4a9450))
    if random_table is not None:
        if random_address != 0x4a9450 or len(random_table) > 302:
            raise ValueError('Unexpected fixed wind random-table layout')
        _i32_table(block, random_address, random_table)
    for name in ['patches', 'imagePatches', 'imageInputs']:
        apply_patches(block, baseline.get(name, []))
    apply_patches(block, fixture.get('baselinePatches', []))
    return block


def image_changes(before, after):
    """Minimal contiguous changed-byte spans across the complete fixed block."""
    if len(before) != BLOCK_SIZE or len(after) != BLOCK_SIZE:
        raise ValueError('Mutable block has unexpected size')
    # CPython performs the complete byte comparison in compiled big-integer
    # operations. Nonzero XOR bytes identify precisely the same minimal runs
    # as the previous byte-by-byte loop, including adjacent differing bytes.
    difference = (int.from_bytes(before, 'little') ^ int.from_bytes(after, 'little')).to_bytes(BLOCK_SIZE, 'little')
    return [{'address': BLOCK_ADDRESS + match.start(),
             'before': bytes(before[match.start():match.end()]).hex(),
             'after': bytes(after[match.start():match.end()]).hex()}
            for match in re.finditer(rb'[^\x00]+', difference)]


def encode_patches(patches):
    """Little-endian u32 count then [relative u32 offset,u32 length,bytes].

    TLS-index overlaps are split out so the native host keeps its real index.
    Ordered patches preserve intentional captured overlap semantics.
    """
    segments = []
    tls_start, tls_end = TLS_INDEX_OFFSET, TLS_INDEX_OFFSET + TLS_INDEX_SIZE
    for row in patches:
        offset, data = _spec(row)
        end = offset + len(data)
        if end <= tls_start or offset >= tls_end:
            if data:
                segments.append((offset, data))
        else:
            if offset < tls_start:
                segments.append((offset, data[:tls_start - offset]))
            if end > tls_end:
                segments.append((tls_end, data[tls_end - offset:]))
    return struct.pack('<I', len(segments)) + b''.join(struct.pack('<II', offset, len(data)) + data for offset, data in segments)


def normalize_tls(block, prepared):
    """Comparison-only TLS normalization; never use the result as runtime input."""
    if len(block) != BLOCK_SIZE or len(prepared) != BLOCK_SIZE:
        raise ValueError('Mutable block has unexpected size')
    normalized = bytearray(block)
    normalized[TLS_INDEX_OFFSET:TLS_INDEX_OFFSET + TLS_INDEX_SIZE] = prepared[TLS_INDEX_OFFSET:TLS_INDEX_OFFSET + TLS_INDEX_SIZE]
    return normalized


def prepare_case(fixture, case):
    """Return (encoded original-PE input patches, expected complete state).

    The expected dictionary has beforeBlock, afterBlock, imageChanges and
    mutableBlockHash. Supplied before bytes/hash are checked, so inconsistent
    captures cannot silently become native comparison inputs.
    """
    before = baseline_for_fixture(fixture)
    apply_patches(before, case.get('imageInputs', []))
    expected = case.get('expected', {})
    after = bytearray(before)
    for row in expected.get('imageChanges', []):
        offset, data = _spec(row)
        recorded = row.get('before')
        if recorded is not None and bytes(after[offset:offset + len(data)]).hex() != recorded.lower():
            raise ValueError(f'Recorded original input does not match change at 0x{row["address"]:x}')
        after[offset:offset + len(data)] = data
    after = normalize_tls(after, before)
    digest = hashlib.sha256(after).hexdigest()
    recorded_hash = expected.get('mutableBlockHash')
    if recorded_hash is not None and digest != recorded_hash:
        raise ValueError('Recorded complete mutable-block hash does not match expected changes')
    native_patches = [{'address': row['address'], 'bits': row['after']} for row in image_changes(original_baseline(), before)]
    return encode_patches(native_patches), {'beforeBlock': before, 'afterBlock': after,
        'imageChanges': image_changes(before, after), 'mutableBlockHash': digest}
