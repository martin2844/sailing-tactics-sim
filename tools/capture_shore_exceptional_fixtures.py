#!/usr/bin/env python3
"""Capture complete original shore segments at masked x87 zero-slope divisors."""
import argparse
import subprocess
import sys
import hashlib
import json
import struct
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_gdi_fixtures import DrawingMachine, CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, save
from capture_crew_fixtures import argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000

def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--emulated-only',action='store_true');args=parser.parse_args()
 vm=DrawingMachine();vm.call(0x415a60);baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
 templates=json.loads((ROOT/'tests/fixtures/original-shore.json').read_text())['routines']['drawShoreSegment']['cases']
 writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
 rows=[]
 for index in range(128):
  vm.uc.mem_write(BASE,baseline)
  for patch in templates[index]['imageInputs']:vm.uc.mem_write(patch['address'],bytes.fromhex(patch['bits']))
  seed=[0,1,2002,0xffffffff][index%4];vm.write_i32(TLS+0x14,seed)
  for address,value in {0x4a5a4c:0,0x4a864c:1,0x4ac928:0,0x49116c:3,0x491194:1,0x4a5b9c:0,
   0x4ac1e0:index%2,0x4aa804:1,0x4a72d0:[460,600,768,1024][index%4]}.items():vm.write_i32(address,value)
  x=[-2147483648,-100,0,1,300,800,2147483647][index%7]
  y1=200+index%17;y2=y1 if index%4==0 else 250+index%29
  params=[x,y1,x,y2,600,1,-2147483648,0,2147483647,600,100,0]
  pixels=[0xffffff]*4;vm.pixel_sampler=lambda x,y,ordinal:pixels[ordinal]
  before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace()
  vm.call(0x42d8a0,argument_bytes([CDC]+params,['I32']*13),count=1000000)
  after=bytes(vm.uc.mem_read(BASE,SIZE))
  if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original .text changed')
  rows.append({'arguments':params,'seedAtCall':seed,'imageInputs':[{'address':r['address'],'bits':r['after']} for r in changed(baseline,before)],
   'pixelReadValues':pixels[:vm.pixel_read_index],'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
   'expected':{'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}})
 fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
  'note':'Complete unchanged original shore segments with x1=x2. Under masked x87 exceptions, stored slope is Infinity/NaN and 0*slope converts through __ftol to signed-I64 indefinite, whose low I32 is zero. Full drawing requests and mutable state compared; x87 status flags are outside the browser contract.'},
  'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},
  'routines':{'drawShoreSegment':{'address':0x42d8a0,'argumentTypes':['CDC']+['I32']*12,'returnType':'void','cases':rows}}}
 save(ROOT/'tests/fixtures/original-shore-exceptional.json',fixture)
 print('drawShoreSegment masked division',len(rows))
 if not args.emulated_only:
  command=[sys.executable,str(ROOT/'tools/verify_native_state.py'),'--fixture','original-shore-exceptional.json','--report',str(ROOT/'analysis/shore-exceptional-native-reference-comparison.json')]
  subprocess.run(command+['--update-fixture'],check=True);subprocess.run(command,check=True)

if __name__=='__main__':main()
