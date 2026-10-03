"""Declared, finite inputs for original initialized native frame chains.

The profiles are caller-selected settings, not expected results. In particular,
417790 maps selector14 to class7; original initialization preserves course8
only for that class. Actual normalized values must be recorded from native
memory and checked separately. No frame position, clock or RNG output is fed
back from JavaScript into the native continuation.
"""
import json
import struct
from native_mutable_state import ROOT


PROFILES = (
    {'name': 'coastal-prestart', 'seed': 2002, 'selector': 12, 'course': 1,
     'humans': 1, 'view': 2, 'startMode': 5},
    {'name': 'offshore-two-players', 'seed': 2003, 'selector': 14, 'course': 8,
     'humans': 2, 'view': 2, 'startMode': 1},
    {'name': 'advanced-harbor-race', 'seed': 2004, 'selector': 12, 'course': 6,
     'humans': 1, 'view': 1, 'startMode': 1},
)


def configuration(profile):
    """The reviewed command18 setting vector; slots7/8 are speed/divisor."""
    return [profile['selector'], profile['course'], 0, profile['humans'], 5,
            profile['view'], 0, 8, 171, profile['startMode'], 1024, 768, 24, 0, 0, 0]


def encode_initialization(profile):
    return struct.pack('<III16i', 18, 0, profile['seed'], *configuration(profile))


def encode_frame(frame):
    if frame['tickStep'] != 1 or frame['pixelSampler'] != {'mode': 'white', 'budget': 1024}:
        raise ValueError('Retained frames require the declared fixed timer/pixel host')
    return struct.pack('<IIIiiiI', 18, 1, int(frame['snapshotRequest']),
                       frame['menuHeight'], frame['cursor']['x'], frame['cursor']['y'],
                       frame['tickStart'])


def initialization_inputs(profile):
    """Settings and host-owned logical GDI handles before original startup calls.

The preserved original defaults supply all other globals. The declared speed
and its saved copy agree with original level8 (divisor171). Pixel dimensions
are inputs to the separately executed original viewport calibration prefix.
"""
    settings = {
        0x491144: profile['selector'], 0x491194: profile['course'],
        0x49118c: 5, 0x491140: profile['humans'], 0x4911cc: profile['startMode'],
        0x49116c: 8, 0x491170: 171, 0x491178: 8, 0x491174: 171,
        0x4ac8f8: 2,
        0x4a4958: 0, 0x4a5a4c: 0, 0x4a763c: 1024,
        0x4a3f84: 1024, 0x4a3f04: 768, 0x4aaa1c: 24, 0x4ac1d4: 0x400000,
    }
    for boat in (1, 2): settings[0x4a4e88 + boat * 4] = profile['view']
    graphics = json.loads((ROOT / 'analysis/gdi-object-definitions.json').read_text())['objects']
    for definition in graphics:
        address = definition['handleAddress']; settings[address] = address
    return [{'address': address, 'bits': struct.pack('<I', value & 0xffffffff).hex()}
            for address, value in sorted(settings.items())]


def frame_inputs(profile_index, count=100):
    if not 1 <= count <= 100: raise ValueError('Native frame-chain length exceeds the fixed100-frame bound')
    return [{'index': index, 'cursor': {'x': 40 + (index % 80) * 9, 'y': 40 + profile_index * 35},
             'menuHeight': 20, 'tickStart': index * 100, 'tickStep': 1,
             'pixelSampler': {'mode': 'white', 'budget': 1024},
             'snapshotRequest': index == 40}
            for index in range(count)]
