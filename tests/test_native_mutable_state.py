import json
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from native_mutable_state import (BLOCK_ADDRESS, BLOCK_SIZE, TLS_INDEX_OFFSET,
    SOURCE_SHA256, apply_patches, baseline_for_fixture, encode_patches, normalize_tls, prepare_case)


class NativeMutableStateTests(unittest.TestCase):
    def test_integer_tables_are_selected_and_cached_in_declared_arithmetic_context(self):
        for control_word, directory in [('0x027f', 'pc53/'), ('0x037f', ''), ('0x027f', 'pc53/')]:
            fixture = {'provenance': {'sha256': SOURCE_SHA256, 'x87_control_word': control_word}}
            block = baseline_for_fixture(fixture)
            table = json.loads((ROOT / f'assets/data/{directory}trig-tables.json').read_text())
            for address, values in [(0x4a54a0, table['sine']), (0x4a3450, table['cosine'])]:
                expected = b''.join(struct.pack('<i', value) for value in values)
                self.assertEqual(block[address - BLOCK_ADDRESS:address - BLOCK_ADDRESS + len(expected)], expected)
        with self.assertRaises(ValueError):
            baseline_for_fixture({'provenance': {'sha256': SOURCE_SHA256, 'x87_control_word': '0x007f'}})

    def test_protocol_cannot_write_original_text_iat_or_tls_index(self):
        for address in [0x401000, BLOCK_ADDRESS - 1, BLOCK_ADDRESS + BLOCK_SIZE]:
            with self.assertRaises(ValueError): encode_patches([{'address': address, 'bits': '00'}])
        packet = encode_patches([{'address': BLOCK_ADDRESS + TLS_INDEX_OFFSET - 2, 'bits': '0102030405060708'}])
        self.assertEqual(struct.unpack_from('<I', packet)[0], 2)
        cursor = 4
        decoded = []
        for _ in range(2):
            offset, length = struct.unpack_from('<II', packet, cursor); cursor += 8
            decoded.append((offset, packet[cursor:cursor + length])); cursor += length
        self.assertEqual(decoded, [(TLS_INDEX_OFFSET - 2, b'\x01\x02'), (TLS_INDEX_OFFSET + 4, b'\x07\x08')])
        self.assertEqual(cursor, len(packet))

    def test_tls_normalization_is_only_a_comparison_copy(self):
        runtime, captured = bytearray(BLOCK_SIZE), bytearray(BLOCK_SIZE)
        runtime[TLS_INDEX_OFFSET:TLS_INDEX_OFFSET + 4] = b'\x17\x00\x00\x00'
        captured[TLS_INDEX_OFFSET:TLS_INDEX_OFFSET + 4] = b'\x00\x00\x00\x00'
        result = normalize_tls(runtime, captured)
        self.assertEqual(result, captured)
        self.assertEqual(runtime[TLS_INDEX_OFFSET], 0x17)

    def test_every_prepared_original_case_has_consistent_full_image_hash(self):
        fixture = json.loads((ROOT / 'tests/fixtures/original-initialization.json').read_text())
        self.assertEqual(fixture['provenance']['sha256'], SOURCE_SHA256)
        count = 0
        for routine in fixture['routines'].values():
            for case in routine['cases']:
                _, expected = prepare_case(fixture, case)
                self.assertEqual(expected['mutableBlockHash'], case['expected']['mutableBlockHash'])
                self.assertEqual(len(expected['afterBlock']), BLOCK_SIZE)
                count += 1
        self.assertEqual(count, 916)

    def test_inconsistent_expected_or_malformed_bytes_are_rejected(self):
        fixture = json.loads((ROOT / 'tests/fixtures/original-initialization.json').read_text())
        case = fixture['routines']['projectPoint']['cases'][0]
        bad = {**case, 'expected': {**case['expected'], 'mutableBlockHash': '0' * 64}}
        with self.assertRaises(ValueError): prepare_case(fixture, bad)
        for bits in ['0', 'gg', None]:
            with self.assertRaises(ValueError): apply_patches(bytearray(BLOCK_SIZE), [{'address': BLOCK_ADDRESS, 'bits': bits}])


if __name__ == '__main__': unittest.main()
