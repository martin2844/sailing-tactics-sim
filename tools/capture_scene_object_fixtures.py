#!/usr/bin/env python3
"""Complete original scene projection/traversal with explicit synthetic pixel reads."""
import argparse
import hashlib
import json
import random
import struct
import subprocess
import sys
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_gdi_fixtures import DrawingMachine, CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, save
from capture_crew_fixtures import argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed
BASE, SIZE = 0x491000, 0x1d000
ROUTINES = {
 'selectNearestSceneObject': (0x42cd00, ['I32']*3, 512, False),
 'sortSceneDepths': (0x42cca0, ['I32'], 512, False),
 'prepareStartBuoy': (0x42cf50, [], 128, False),
 'drawSceneMark': (0x42cd40, ['I32']*4, 512, True),
 'drawSceneStartLine': (0x42c550, ['I32']*4, 320, True),
 'drawSceneObjects': (0x42c7b0, ['I32']*6, 480, True),
}

def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--emulated-only',action='store_true');args=parser.parse_args()
 vm=DrawingMachine();vm.call(0x415a60);baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
 handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
 writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
 fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
  'note':'Complete unchanged original scene helpers and object traversal. Original417790 preparation, explicit finite synthetic simulation/viewport inputs, reviewed CDC/GDI observations; pixel reads use the recorded U32 input sequence, independent of rasterization. No Canvas/GDI pixel identity claim.',
  'pixelReadContract':'case.pixelReadValues is the exact consumed ordered U32 return list; GetPixel coordinates and values remain in ordered drawingCommands.'},
  'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
 prng=random.Random(0x42c7b0)
 for name,(address,kinds,count,drawing) in ROUTINES.items():
  rows=[]
  for index in range(count):
   vm.uc.mem_write(BASE,baseline);seed=[0,1,2002,0xffffffff][index%4];vm.write_i32(TLS+0x14,seed)
   camera=1+index%2;boat_count=[0,1,2,5,15,30][(index//2)%6]
   for handle in handles:vm.write_i32(handle,handle if index%17 else 0)
   integers={0x491188:1,0x491144:1+index%15,0x491140:1+index%2,0x49118c:boat_count,
    0x491148:100,0x49114c:index%2,0x491194:[1,8][(index//3)%2],0x491160:(index//5)%2,
    0x49117c:(index//7)%2,0x4ac98c:(index//11)%2,0x4ac92c:(index//13)%2,
    0x4ac994:[0,1,2][index%3],0x4ac980:[0,109,499,500,501][index%5],0x4ac928:(index//17)%2,
    0x4a763c:[640,800,1024,1280][index%4],0x4a72d0:[460,600,720,768][index%4],
    0x4a4760:400,0x4a3fa0:400,0x4a5b80:[-1,0,1,14,15,200][index%6],0x4ac9d4:[0,1,10,20][index%4],
    0x4a4eb0:[44,45,46][index%3],0x4ac9a8:(index//19)%2,0x49116c:3,0x491170:833,
    0x4ac96c:index%277,0x4ac4ec:index%24,0x4a633c:12+index%2,0x4a7044:index%361,
    0x4ac918:30,0x4ac91c:10,0x4ac920:10,0x4ac924:0,
    0x4aa7e0:1+index%max(1,boat_count+5),0x4a70f8:-1200,0x4a72c8:300,0x4aa594:1200,0x4aa59c:-300,
    0x4a7c4c:300,0x4a7c50:500,0x4aaa4c:[299,300,301][index%3],0x4aaa50:300}
   for a,v in integers.items():vm.write_i32(a,v)
   for a,v in [(0x4ab0c8,[0.5,1.,1.3][index%3]),(0x4abef0,[-2.99,0.,2.,3.99][index%4])]:vm.uc.mem_write(a,struct.pack('<d',v))
   vm.call(0x417790)
   for boat in range(36):
    for base,value in [(0x4aa730,-1 if (index+boat)%2 else 1),(0x4a6ec8,[0,4,5,7,8,10,23][(index+boat)%7]),
     (0x4a7060,[0,26,27,30,31,80][(index+boat)%6]),(0x4a7bc8,[0,44,45,55,89,90,120,121,150,180][(index+boat)%10]),
     (0x4a6830,[0,1,44,90,179,180,270,359,360][(index+boat)%9]),(0x4ac018,(index*13+boat*17)%361),
     (0x4aa5b0,(index*7+boat*19)%361),(0x4a4608,(index+boat)%2),(0x4a4e88,1+(index//5+boat)%3),
     (0x4a5f10,[19,20,35,75][(index+boat)%4]),(0x4a6ba0,(index+boat)%4),
     (0x4aa6e0,[0,10,90,200,1000][(index+boat)%5]),(0x4a3a18,100),(0x4a41f0,99),
     (0x4a8aa8,79+(index+boat)%2),(0x4a77e8,[0,5,40][(index+boat)%3]),(0x4a8d50,[0,1,10,11,100][(index+boat)%5]),
     (0x4abb70,(index+boat)%2),(0x4a4e78,(index+boat)%2),(0x4a6090,(index+boat)%2),
     (0x4abf18,0),(0x4a89c0,10),
     (0x4a6db0,[19000,20000,18999,-1,0,-2**31,2**31-1,300][(index+boat)%8]),
     (0x4a4438,1+(index+boat)%35)]:vm.write_i32(base+boat*4,value)
    for base,value in [(0x4a49e8,0.),(0x4a4ae0,0.),(0x4a52f0,float(prng.randrange(-1800,1801))),
     (0x4a60b0,float(prng.randrange(-1800,1801)))]:vm.uc.mem_write(base+boat*8,struct.pack('<d',value))
   pattern=[[0],[0x8000],[0,0x8000],[0x8000,0,0],[0,0,0x8000,0],[0xffffffff,0xffffff,0x123456]][index%6]
   pixel_values=[pattern[i%len(pattern)] for i in range(80)] if name=='drawSceneObjects' else []
   vm.pixel_sampler=lambda x,y,ordinal:pixel_values[ordinal]
   if name=='selectNearestSceneObject':params=[1+index%35,[-1,0,1,2,5,15,35][index%7],[-2**31,-1,0,1,19000,20000,2**31-1][index%7]]
   elif name=='sortSceneDepths':params=[index%3-1]
   elif name=='prepareStartBuoy':params=[]
   elif name=='drawSceneMark':params=[[-2**31,-100,0,300,2**31-1][index%5],[-2**31,99,100,149,150,199,200,201,300,600,2**31-1][index%11],index%6,camera]
   elif name=='drawSceneStartLine':params=[0,800,[299,300,301,600][index%4],camera]
   else:params=[camera,0,0,800,600,100]
   before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace()
   vm.call(address,argument_bytes(([CDC]+params) if drawing else params,(['I32']+kinds) if drawing else kinds),count=5000000)
   after=bytes(vm.uc.mem_read(BASE,SIZE))
   if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original .text changed')
   expected={'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest()}
   if drawing:expected['drawingCommands']=vm.events.copy()
   row={'arguments':params,'seedAtCall':seed,'imageInputs':[{'address':r['address'],'bits':r['after']} for r in changed(baseline,before)],
    'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],'expected':expected}
   if pixel_values:row['pixelReadValues']=pixel_values[:vm.pixel_read_index]
   rows.append(row)
  fixture['routines'][name]={'address':address,'argumentTypes':(['CDC'] if drawing else [])+kinds,'returnType':'void','cases':rows}
  print(name,len(rows),flush=True)
 save(ROOT/'tests/fixtures/original-scene-objects.json',fixture)
 if not args.emulated_only:
  command=[sys.executable,str(ROOT/'tools/verify_native_state.py'),'--fixture','original-scene-objects.json','--report',str(ROOT/'analysis/scene-objects-native-reference-comparison.json')]
  subprocess.run(command+['--update-fixture'],check=True);subprocess.run(command,check=True)

if __name__=='__main__':main()
