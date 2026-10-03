"""Integrity of the fixed native-reference protocol and declared exclusions."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from verify_native_state import decode_gdi_events, decode_state, encode_case


class NativeProtocolTests(unittest.TestCase):
    def test_pixel_reads_are_explicit_unsigned_bounded_data(self):
        case = {'command': 15, 'routine': 55, 'integers': [], 'doubles': [],
                'seed': 2002, 'patches': struct.pack('<I', 0),
                'pixelReadValues': [0, 0xffffffff]}
        encoded = encode_case(case)
        self.assertEqual(encoded[-32:-20], struct.pack('<3I', 2, 0, 0xffffffff))
        self.assertEqual(encoded[-20:],struct.pack('<iiiII',20,0,0,0,1))
        for invalid in [[-1], [0x100000000], [True], [0] * 1025]:
            with self.assertRaises(ValueError):
                encode_case({**case, 'pixelReadValues': invalid})

    def test_raw_allocator_evidence_cannot_hide_game_state(self):
        case = {'command': 15, 'routine': 48, 'group': 'label', 'index': 0}
        prefix = (struct.pack('<IIiII', 48, 3, 0, 2002, 0) + bytes(32) +
                  struct.pack('<2I', 0, 0))
        def payload(address):
            return (prefix + struct.pack('<4I', 1, 1, address, 4) + bytes(4) +
                    struct.pack('<I', 2) + struct.pack('<4I', 0, 0, 0,0))
        valid = decode_state(payload(0x4aec34), case)
        self.assertEqual(valid['imageChanges'], [])
        self.assertEqual(valid['libraryRuntimeChanges'][0]['address'], 0x4aec34)
        with self.assertRaises(ValueError):
            decode_state(payload(0x4a5b80), case)

    def test_drawing_decoder_keeps_signed_coordinates_and_unsigned_colors(self):
        raw = struct.pack('<IIiiI', 19, 12, -2147483648, 2147483647, 0xffffffff)
        self.assertEqual(decode_gdi_events(raw),
                         [{'op': 'getPixel', 'x': -2147483648, 'y': 2147483647, 'color': 0xffffffff}])
        with self.assertRaises(ValueError):
            decode_gdi_events(raw[:-1])
        with self.assertRaises(ValueError):
            decode_gdi_events(struct.pack('<II', 0xffffffff, 0))

    def test_numeric_text_reply_requires_original_output_object_return(self):
        case = {'command': 16, 'routine': 1}
        raw = (struct.pack('<Ii4I', 1, 0, 1, 1, 0x12345678, 3) + b'-12' +
               struct.pack('<2I', 1, 0))
        result = decode_state(raw, case)
        self.assertTrue(result['outputPointerReturned'])
        self.assertTrue(result['imageUnchanged'])
        self.assertEqual(result['text'], '-12')
        with self.assertRaises(ValueError):
            decode_state(raw + b'\0', case)


if __name__ == '__main__':
    unittest.main()
