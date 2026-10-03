#!/usr/bin/env python3
"""Strict parser checks using measured retained original-controller reply bytes."""
import copy
import hashlib
import json
import struct
import unittest
from pathlib import Path
from capture_retained_frames import decode_controller, DATA_BASE

EDITION = Path(__file__).resolve().parents[1]
FIXTURE_PATH = EDITION / 'tests/fixtures/original-retained-controller-protocol.json'
FIXTURE = json.loads(FIXTURE_PATH.read_text())
WIRE = json.loads((EDITION / 'tests/fixtures/original-retained-controller-wire.json').read_text())
assert hashlib.sha256(FIXTURE_PATH.read_bytes()).hexdigest() == WIRE['sourceFixtureSha256']
assert FIXTURE['sourceSha256'] == WIRE['sourceSha256']
BASELINE = bytes.fromhex(FIXTURE['mutableBaseline'])
RESPONSES = {row['case']: bytes.fromhex(row['bytes']) for row in WIRE['responses']}
BEFORE = {}
state = bytearray(BASELINE)
for index, case in enumerate(FIXTURE['cases']):
    if not case.get('continue'):
        state[:] = BASELINE
    for patch in case.get('patches', []):
        offset, data = patch['address'] - DATA_BASE, bytes.fromhex(patch['bytes'])
        state[offset:offset + len(data)] = data
    BEFORE[index] = bytes(state)
    for change in case['expected']['imageChanges']:
        offset, before, after = change['address'] - DATA_BASE, bytes.fromhex(change['before']), bytes.fromhex(change['after'])
        assert state[offset:offset + len(before)] == before
        state[offset:offset + len(after)] = after


def string_trailer(raw):
    offset = 72
    for _ in range(struct.unpack_from('<I', raw, 68)[0]):
        width = struct.unpack_from('<I', raw, offset + 4)[0]
        offset += 8 + width * 2
    return offset + 4 + struct.unpack_from('<I', raw, offset)[0] + 32


class RetainedTransport(unittest.TestCase):
    def decode(self, raw, index=1):
        return decode_controller(raw, FIXTURE, FIXTURE['cases'][index], bytearray(BEFORE[index]), BASELINE)

    def test_all_actual_controller_replies_preserve_state_rng_strings_and_event_order(self):
        for row in WIRE['responses']:
            index, raw = row['case'], RESPONSES[row['case']]
            self.assertEqual(hashlib.sha256(raw).hexdigest(), row['sha256'])
            self.assertEqual(self.decode(raw, index), FIXTURE['cases'][index]['expected'])
            self.assertEqual(len(self.decode(raw, index)['globalStrings']), 36)

    def test_truncated_and_surplus_bytes_are_rejected(self):
        raw = RESPONSES[1]
        for broken in [raw[:71], raw[:string_trailer(raw)], raw[:-1], raw + b'\0']:
            with self.assertRaises(ValueError):
                self.decode(broken)

    def test_wrong_marker_count_pointer_and_length_are_rejected(self):
        raw = RESPONSES[1]
        trailer = string_trailer(raw)
        for offset, value in [(trailer, 0), (trailer + 4, 35), (trailer + 8, 0),
                              (trailer + 12, 0), (trailer + 16, 4096)]:
            broken = bytearray(raw)
            struct.pack_into('<I', broken, offset, value)
            with self.assertRaises(ValueError):
                self.decode(broken)

    def test_invalid_native_full_state_hash_and_precision_are_rejected(self):
        for offset in [34, 36]:
            broken = bytearray(RESPONSES[1])
            broken[offset] ^= 1
            with self.assertRaises(ValueError):
                self.decode(broken)


if __name__ == '__main__':
    unittest.main()
