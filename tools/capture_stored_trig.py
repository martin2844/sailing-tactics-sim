#!/usr/bin/env python3
"""Capture original stored-angle and scaled hull angle constructions on x87."""
import hashlib
import json
import platform
import struct
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXPECTED = '881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'

def original_constant(original, address):
    pe = struct.unpack_from('<I', original, 0x3c)[0]
    optional = pe + 24
    base = struct.unpack_from('<I', original, optional + 28)[0]
    table = optional + struct.unpack_from('<H', original, pe + 20)[0]
    for index in range(struct.unpack_from('<H', original, pe + 6)[0]):
        rva, size, offset = struct.unpack_from('<III', original, table + index * 40 + 12)
        if rva <= address - base and address - base + 8 <= rva + size:
            return original[offset + address - base - rva:offset + address - base - rva + 8].hex()
    raise ValueError('Constant is not backed by original file bytes')

def capture():
    original = (ROOT / 'original/Tact02Demo.exe').read_bytes()
    if hashlib.sha256(original).hexdigest() != EXPECTED:
        raise ValueError('Original executable changed')
    source = ROOT / 'tools/capture_stored_trig_native.c'
    factor = original_constant(original, 0x484d40)
    scale = original_constant(original, 0x484dc0)
    one = original_constant(original, 0x484e10)
    angles = range(-1080, 1081)
    commands = [f'stored {angle} {factor} {one}' for angle in angles]
    hull_angles = [29, 58, 87, 116, 145]
    commands += [f'scaled {angle} {factor} {value}' for value in [one, scale] for angle in hull_angles]
    raw_angles = range(-128, 129)
    commands += [f'raw {angle} {factor} {one}' for angle in raw_angles]
    compiler = 'gcc'
    with tempfile.TemporaryDirectory(prefix='tact-stored-trig-') as folder:
        binary = str(Path(folder) / 'capture')
        subprocess.run([compiler, '-std=c11', '-O2', '-Wall', '-Wextra', '-fno-fast-math', str(source), '-o', binary], check=True)
        result = subprocess.run([binary], input='\n'.join(commands) + '\n', text=True, capture_output=True, check=True)
    output = result.stdout.splitlines()
    if len(output) != len(commands):
        raise ValueError('Incomplete capture')
    provenance = {
        'sha256': EXPECTED, 'authoritative_engine': 'native-x87',
        'control_word': '0x037f', 'architecture': platform.machine(),
        'probe_source': 'tools/capture_stored_trig_native.c',
        'probe_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
        'compiler': subprocess.run([compiler, '--version'], capture_output=True, text=True, check=True).stdout.splitlines()[0],
        'note': 'Actual local hardware; this does not establish equivalence to every historical CPU.',
    }
    def pair(line):
        sine, cosine = line.split()
        return {'sineBits': sine, 'cosineBits': cosine, 'referenceEngine': 'native-x87'}
    stored = {
        'provenance': provenance, 'degreeFactorAddress': 0x484d40,
        'degreeFactorBits': factor,
        'construction': 'FILD i32; FMUL original binary64 degree factor; FSTP binary64; FLD binary64; FSIN/FCOS; FSTP m80',
        'angles': {str(angle): pair(output[index]) for index, angle in enumerate(angles)},
    }
    hull = {
        'provenance': provenance, 'degreeFactorAddress': 0x484d40,
        'degreeFactorBits': factor, 'optimistScaleAddress': 0x484dc0,
        'optimistScaleBits': scale, 'optimistScale': struct.unpack('<d', bytes.fromhex(scale))[0],
        'construction': 'FILD i32; FMUL original binary64 hull scale; FMUL original binary64 degree factor; FSIN/FCOS; FSTP m80',
        'variants': {name: {str(angle): pair(output[len(stored['angles']) + variant * 5 + index]) for index, angle in enumerate(hull_angles)} for variant, name in enumerate(['standard', 'optimist'])},
    }
    raw = {'provenance': provenance, 'construction': 'FILD i32; FSIN/FCOS; FSTP m80, without a degree factor',
        'angles': {str(angle): pair(output[len(stored['angles']) + 10 + index]) for index, angle in enumerate(raw_angles)}}
    for filename, document in [('x87-stored-trig.json', stored), ('x87-hull-trig.json', hull), ('x87-raw-trig.json', raw)]:
        (ROOT / 'assets/data' / filename).write_text(json.dumps(document, indent=2) + '\n')
    print(json.dumps({'storedAngles': len(stored['angles']), 'hullAngles': 10, 'rawAngles': len(raw['angles']), 'optimistScale': hull['optimistScale']}))

if __name__ == '__main__':
    capture()
