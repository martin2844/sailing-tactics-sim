#!/usr/bin/env python3
"""Capture original tutorial pages, drawing dependencies and pause dispatcher."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_hud_fixtures import HudMachine
from capture_gdi_fixtures import CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, save
from capture_crew_fixtures import argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000
PAGES = {
 1:0x432000,2:0x432920,3:0x4330f0,4:0x4337a0,5:0x433ea0,6:0x434470,7:0x434c10,8:0x4354d0,
 101:0x435b50,102:0x436300,103:0x436960,104:0x4372d0,105:0x437950,106:0x438330,107:0x438c30,108:0x439600,109:0x439f20,110:0x43a5d0,
 300:0x43a9b0,501:0x43b910,502:0x43c100,503:0x43ccd0,504:0x43e070,505:0x43f460,506:0x440d20,507:0x442740,508:0x443bf0,
 509:0x445830,510:0x445ee0,511:0x446570,512:0x446a90,513:0x4479e0,514:0x449ef0,
 601:0x44b220,602:0x44b9e0,603:0x44c120,604:0x44c950,701:0x44d140,400:0x41beb0,
}
ROUTINES = {
 'selectBoatTextColor':(0x416990,1,128),
 'drawTutorialAdvanceButton':(0x44d6d0,1,128),
 'drawTutorialAdvanceHint':(0x44d830,2,128),
 **{f'drawTutorial{selector}':(address,0,128) for selector,address in PAGES.items()},
 'drawPauseScreen':(0x41bb40,0,384),
}

def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--emulated-only',action='store_true');parser.add_argument('--callsites-only',action='store_true');args=parser.parse_args()
 vm=HudMachine();vm.call(0x415a60);baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
 prepared=json.loads((ROOT/'tests/fixtures/original-boat-renderer.json').read_text())['routines']['drawBoat']['cases']
 handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
 writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
 fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
  'note':'Complete unchanged original tutorial pages and dispatcher. Prepared original417790 boat-option states come from original-boat-renderer fixtures, followed by explicit finite tutorial/UI data. CDC/GDI and CString byte-copy observations preserve ordered requests; no Windows heap/font/pixel identity claim.'},
  'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
 widths=[640,699,700,701,900,901,1024,1280]
 selectors=list(PAGES)+[-1,0,9,100,111,299,301,500,515,600,605,700,702]
 for name,(address,nargs,count) in ROUTINES.items():
  rows=[]
  actual_count=min(count,32) if args.callsites_only else count
  for index in range(actual_count):
   vm.uc.mem_write(BASE,baseline);vm.reset_strings();seed=[0,1,2002,0xffffffff][index%4];vm.write_i32(TLS+0x14,seed)
   for patch in prepared[(index%15)*96]['imageInputs']:vm.uc.mem_write(patch['address'],bytes.fromhex(patch['bits']))
   for handle in handles:vm.write_i32(handle,handle if index%19 else 0)
   width=widths[(index//16)%8] if not args.callsites_only else widths[index%8]
   height=[460,600,768,1024][(index//8)%4]
   selector=int(name.removeprefix('drawTutorial')) if name.startswith('drawTutorial') and name.removeprefix('drawTutorial').isdigit() else selectors[index%len(selectors)]
   ints={0x4a763c:width,0x4a72d0:height,0x4ac980:selector,0x4ac92c:(index//8)%2,0x4ac98c:0,
    0x4a6774:index%16,0x491184:[0,1,2,7,15][index%5],0x4a600c:height//2,
    0x491140:2,0x49118c:[0,1,2,15,16,30][index%6],0x4a5b80:200,0x4ac960:(index//17)%2,
    0x4ac944:1+index%2,0x4ac9bc:(index//23)%2,0x4ac9d8:index%2,0x4ac9f0:0,
    0x4ac904:0,0x4a4be4:index%25,0x4a8020:0,0x4ac94c:0,0x4ac1dc:20,
    0x4a4168:0,0x4a60a0:0,0x4a4958:0,0x4a864c:0,0x4a5a4c:0,0x4ac928:0,
    0x4aae1c:0,0x4a4eb0:45,0x4a72d8:0,0x4a6470:1,0x4abae8:1500,
    0x4ac950:0,0x4ac840:0,0x4a4760:400,0x4a3fa0:width//2,0x491148:100}
   for a,v in ints.items():vm.write_i32(a,v)
   for a,v in [(0x4aa810,float(width)),(0x4aa7d8,float(height)),(0x4ab0c8,1.),(0x4abef0,0.),(0x4a6470,1.),(0x4abe60,1.)]:vm.uc.mem_write(a,struct.pack('<d',v))
   for boat in range(31):
    for a,v in [(0x4a4e88,2),(0x4a6830,0),(0x4ac018,45),(0x4aa5b0,0),(0x4aa730,1),
     (0x4a6ec8,15),(0x4a7060,60),(0x4a6338,15),(0x4a7bc8,45),(0x4a77e8,2),(0x4a6ba0,1),
     (0x4a72d8,0),(0x4ac208,10),(0x4a4778,0),(0x4a4758,0),(0x4a6338,15)]:vm.write_i32(a+boat*4,v)
    for a,v in [(0x4a49e8,0.),(0x4a4ae0,0.),(0x4a7f28,85.)]:vm.uc.mem_write(a+boat*8,struct.pack('<d',v))
    for race in range(4):vm.write_i32(0x4a6bb0+boat*16+race*4,((boat+race+index)%31)*100)
   if name=='selectBoatTextColor':params=[[-2147483648,-1,*range(31),2147483647][index%34]]
   elif name=='drawTutorialAdvanceButton':params=[[-2147483648,-1,0,1,16,20,2147483647][index%7]]
   elif name=='drawTutorialAdvanceHint':params=[index,[-2147483648,-1,0,1,16,20,2147483647][index%7]]
   else:params=[]
   before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace()
   vm.call(address,argument_bytes([CDC]+params,['I32']*(nargs+1)),count=10000000)
   after=bytes(vm.uc.mem_read(BASE,SIZE))
   if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original .text changed')
   expected={'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}
   rows.append({'arguments':params,'seedAtCall':seed,'imageInputs':[{'address':r['address'],'bits':r['after']} for r in changed(baseline,before)],
    'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],'expected':expected})
  fixture['routines'][name]={'address':address,'argumentTypes':['CDC']+['I32']*nargs,'returnType':'void','cases':rows}
  print(name,len(rows),flush=True)
 evidence={'source_sha256':EXPECTED,'note':'Observed original indirect calls with reviewed CDC/GDI host bindings; original instructions unchanged.',
  'calls':[{'address':a,'vtableOffset':v} for a,v in sorted(vm.virtual_calls.items())],
  'importCalls':[{'address':a,'name':v} for a,v in sorted(vm.import_calls.items())]}
 save(ROOT/'analysis/tutorial-cdc-callsites.json',evidence)
 if args.callsites_only:return
 save(ROOT/'tests/fixtures/original-tutorials.json',fixture)
 if not args.emulated_only:
  command=[sys.executable,str(ROOT/'tools/verify_native_state.py'),'--fixture','original-tutorials.json','--report',str(ROOT/'analysis/tutorials-native-reference-comparison.json')]
  subprocess.run(command+['--update-fixture'],check=True);subprocess.run(command,check=True)

if __name__=='__main__':main()
