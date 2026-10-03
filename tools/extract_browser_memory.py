#!/usr/bin/env python3
"""Extract original constants/initial data for the native JavaScript browser host."""
import hashlib
import json
from pathlib import Path
import pefile

ROOT=Path(__file__).resolve().parent.parent
EXPECTED='881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'

def main():
    source=(ROOT/'original/Tact02Demo.exe').read_bytes()
    if hashlib.sha256(source).hexdigest()!=EXPECTED:raise ValueError('Original source hash changed')
    pe=pefile.PE(data=source);image=pe.get_memory_mapped_image();output=ROOT/'assets/data'
    manifest={'sourceSha256':EXPECTED,'imageBase':pe.OPTIONAL_HEADER.ImageBase,'imageSize':pe.OPTIONAL_HEADER.SizeOfImage,
        'scope':'Original read-only constants and initial mutable data. Executable sections and import code are excluded; all game routines execute as native JavaScript.',
        'segments':[]}
    for section in pe.sections:
        name=section.Name.rstrip(b'\0').decode('ascii')
        if name not in ['.rdata','.data']:continue
        if section.Characteristics&0x20000000:raise ValueError('Requested data section is executable')
        offset=section.VirtualAddress;size=max(section.Misc_VirtualSize,section.SizeOfRawData)
        data=image[offset:offset+section.SizeOfRawData]+bytes(size-section.SizeOfRawData)
        filename='original-constants.bin' if name=='.rdata' else 'original-initial-state.bin'
        (output/filename).write_bytes(data)
        manifest['segments'].append({'section':name,'file':filename,'address':pe.OPTIONAL_HEADER.ImageBase+offset,
            'size':size,'sha256':hashlib.sha256(data).hexdigest()})
    if len(manifest['segments'])!=2:raise ValueError('Expected the original two data sections')
    (output/'original-memory.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({'segments':manifest['segments'],'totalBytes':sum(row['size'] for row in manifest['segments'])}))

if __name__=='__main__':main()
