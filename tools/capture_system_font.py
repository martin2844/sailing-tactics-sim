#!/usr/bin/env python3
"""Export the default Wine GDI System font as a lossless browser bitmap atlas."""
import hashlib,json,os,struct,subprocess,zlib
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def main():
    source=ROOT/'tools/capture_system_font.c';runner=ROOT/'analysis/native-runners/capture-system-font.exe'
    raw_path=ROOT/'analysis/gdi-font-atlas.bgra';wine=ROOT/'tools/wine-runtime/bin/wine'
    environment={**os.environ,'WINEPREFIX':'/home/martin/.local/share/posey-simulator/wineprefix','WINEDEBUG':'-all'}
    result=subprocess.run([str(wine),str(runner),'Z:'+str(raw_path).replace('/','\\')],env=environment,check=True,capture_output=True,text=True,timeout=30)
    lines=result.stdout.splitlines();height,ascent,descent,internal,external,average=map(int,lines[1].split());widths=list(map(int,lines[2].split()))
    if len(widths)!=256 or height>16 or max(widths)>16 or lines[3]!='kerning 0':raise AssertionError('Font is outside the reviewed atlas layout')
    raw=raw_path.read_bytes();rows=[];colors=set()
    for y in range(256):
        row=bytearray()
        for x in range(256):
            original_x=(x//16)*64+x%16;original_y=(y//16)*64+y%16
            offset=(original_y*1024+original_x)*4;b,g,r=raw[offset:offset+3]
            colors.add((r,g,b))
            if r!=g or r!=b:raise AssertionError('Font mask is not grayscale')
            row.extend([0,0,0,255-r])
        rows.append(bytes(row))
    # Confirm no ink was cropped from any original 64x64 glyph cell.
    for code in range(256):
        for y in range(64):
            for x in range(64):
                offset=(((code//16)*64+y)*1024+(code%16)*64+x)*4
                if (x>=16 or y>=16) and raw[offset:offset+3]!=b'\xff\xff\xff':raise AssertionError('Glyph ink exceeds 16x16')
    def chunk(kind,data):return struct.pack('>I',len(data))+kind+data+struct.pack('>I',zlib.crc32(kind+data)&0xffffffff)
    png=b'\x89PNG\r\n\x1a\n'+chunk(b'IHDR',struct.pack('>IIBBBBB',256,256,8,6,0,0,0))+chunk(b'IDAT',zlib.compress(b''.join(b'\0'+row for row in rows),9))+chunk(b'IEND',b'')
    atlas_path=ROOT/'assets/images/system-font-glyphs.png';atlas_path.write_bytes(png)
    metadata={'provenance':{'host':'Wine GDI','wineVersion':subprocess.check_output([str(wine),'--version'],text=True).strip(),
        'probeSource':'tools/capture_system_font.c','probeSha256':hashlib.sha256(source.read_bytes()).hexdigest(),
        'rawBgraSha256':hashlib.sha256(raw).hexdigest(),'atlasSha256':hashlib.sha256(png).hexdigest(),
        'scope':'Default font from newly created compatible DC, matching the original absence of font selections. Host font capture; Windows versions may choose a different System font.'},
        'face':lines[0],'height':height,'ascent':ascent,'descent':descent,'internalLeading':internal,'externalLeading':external,'averageWidth':average,
        'cellWidth':16,'cellHeight':16,'columns':16,'advances':widths,'kerningPairs':0,'maskRgbValues':sorted(colors),'atlas':'assets/images/system-font-glyphs.png'}
    (ROOT/'assets/data/system-font.json').write_text(json.dumps(metadata,indent=2)+'\n')
    print('Captured',metadata['face'],'font:',height,'pixels,256 glyphs,',len(png),'PNG bytes',flush=True)
if __name__=='__main__':main()
