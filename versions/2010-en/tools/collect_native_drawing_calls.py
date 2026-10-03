#!/usr/bin/env python3
"""Verify CALL bytes behind fixed original native callback observations."""
import argparse,hashlib,json
from pathlib import Path
import capstone,pefile
from capture_native import EXPECTED

ROOT=Path(__file__).resolve().parents[1]
NAMES={2:'SelectObject',3:'MoveToEx',4:'LineTo',5:'Polygon',6:'Ellipse',7:'Rectangle',
 8:'SetPixel',9:'SetTextColor',10:'SetBkColor',11:'SetBkMode',12:'TextOutA',13:'Arc',
 14:'Pie',15:'CreateRectRgn',17:'RoundRect',18:'MessageBeep',19:'GetPixel',20:'DeleteObject',
 21:'GetSystemMetrics',22:'GetCursorPos',23:'GetTickCount'}

def main():
 parser=argparse.ArgumentParser(description=__doc__)
 parser.add_argument('fixtures',nargs='+',type=Path)
 parser.add_argument('--output',type=Path,required=True)
 args=parser.parse_args();original=ROOT/'runtime/Tactics2010EnglishPreserved.exe';raw=original.read_bytes()
 if hashlib.sha256(raw).hexdigest()!=EXPECTED:raise ValueError('Fixed original source differs')
 pe=pefile.PE(data=raw);dis=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
 # Exact Ghidra instruction boundaries avoid choosing an x86 opcode inside operands.
 calls={}
 for line in (ROOT/'decompiled/functions.jsonl').read_text().splitlines():
  row=json.loads(line)
  for span in row['body_ranges']:
   start,end=int(span['start'],16),int(span['end'],16)
   if start<0x401000 or end>=0x49b930:continue
   for instruction in dis.disasm(pe.get_data(start-0x400000,end-start+1),start):
    if instruction.mnemonic=='call':calls[instruction.address+instruction.size]=instruction.address
 virtual={};imports={};provenance=[]
 for path in args.fixtures:
  path=path.resolve()
  fixture=json.loads(path.read_text())
  if fixture['sourceSha256']!=EXPECTED or not fixture['provenance']['loadedOriginalTextUnchanged']:raise ValueError('Unverified native fixture')
  provenance.append({'fixture':str(path.relative_to(ROOT)),'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'cases':len(fixture['cases'])})
  for case in fixture['cases']:
   for row in case['expected'].get('callObservations',[]):
    returned=row['returnAddress']
    # Framework observations are retained in the native fixture, but game metadata
    # uses only the exact application CALL instructions recovered here.
    if not 0x401000<=returned<0x49b930:continue
    address=calls.get(returned)
    if address is None:raise ValueError('Native return is not at a recovered original CALL boundary: '+hex(returned))
    service=row['service']
    if service&0x10000:
     slot=service&0xffff
     if slot not in (0x2c,0x30,0x34,0x38,0x64):raise ValueError('Unknown observed CDC virtual service')
     expected_pop=16 if slot==0x64 else 4
     if row['stackArgumentBytes']!=expected_pop:raise ValueError('CDC native argument cleanup differs')
     if address in virtual and virtual[address]!=slot:raise ValueError('Conflicting actual native virtual callsites')
     virtual[address]=slot
    else:
     name=NAMES.get(service)
     if name is None:raise ValueError('Unknown observed native import service')
     if address in imports and imports[address]!=name:raise ValueError('Conflicting actual native import callsites')
     imports[address]=name
 for address in virtual:
  if address in imports:raise ValueError('One application return observed through both virtual and API callbacks; inspect callback inlining')
 output={'source_sha256':EXPECTED,'engine':'actual-original-native-observations',
  'scope':'Original .text unchanged; original CALL boundaries verified against canonical instruction bytes.',
  'fixtures':provenance,'calls':[{'address':a,'vtableOffset':s} for a,s in sorted(virtual.items())],
  'importCalls':[{'address':a,'name':s} for a,s in sorted(imports.items())]}
 args.output.write_text(json.dumps(output,indent=2)+'\n')
 print('Verified',len(virtual),'CDC and',len(imports),'import callsites')

if __name__=='__main__':main()
