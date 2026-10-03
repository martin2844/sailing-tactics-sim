#!/usr/bin/env python3
"""Capture complete original shoreline and waterfront drawing calls."""
import argparse
import hashlib
import json
import math
import random
import struct
import subprocess
import sys
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_hud_fixtures import HudMachine
from capture_gdi_fixtures import CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, STACK, save
from capture_crew_fixtures import argument_bytes
from capture_encounter_fixtures import merged_ranges
from capture_connected_encounter_fixtures import changed

BASE, SIZE = 0x491000, 0x1d000
ROUTINES = {
 'drawProjectedShoreline': (0x42d120, 9, 256), 'drawShoreSegment': (0x42d8a0, 12, 512),
 'drawShoreMarker': (0x42e190, 3, 320), 'drawHarborHouse': (0x42e550, 2, 320),
 'drawHarborBuilding': (0x42e750, 2, 320), 'drawShoreBuilding': (0x42e870, 2, 320),
 'drawShoreHouse': (0x42e970, 3, 320), 'drawLighthouse': (0x42eb40, 3, 320),
 'drawHeadingIndicator': (0x42ede0, 3, 320), 'drawSceneLayline': (0x42f0d0, 5, 320),
}

def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--emulated-only',action='store_true');args=parser.parse_args()
 vm=HudMachine();vm.call(0x415a60);baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
 handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
 writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
 fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
  'note':'Complete unchanged original shoreline/waterfront calls, finite synthetic geometry and simulation data, reviewed CDC/GDI/CString observations. Original local-stack reads are recorded without injection; authority cases use defined center locals and suppress island vegetation requiring a retained first endpoint. Explicit GetPixel input sequences are observations, not raster identity.',
  'pixelReadContract':'case.pixelReadValues is the exact consumed ordered U32 return list; GetPixel coordinates and values remain in ordered drawingCommands.',
  'coverageCaveats':['Island vegetation requiring a retained prior point awaits connected 404880 caller capture.','Variant-one island segments requiring an uninitialized center local await connected caller capture.']},
  'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
 prng=random.Random(0x42d120)
 for name,(address,nargs,count) in ROUTINES.items():
  rows=[]
  for index in range(count):
   vm.uc.mem_write(BASE,baseline);vm.reset_strings();seed=[0,1,2002,0xffffffff][index%4];vm.write_i32(TLS+0x14,seed)
   for handle in handles:vm.write_i32(handle,handle if index%19 else 0)
   camera=1+index%2;island=(index//5)%2;variant=0 if island else (index//7)%2
   integers={0x491148:[0,100,150][index%3],0x491194:[1,2,4,8,11][index%5],0x491140:2,0x491188:1,
    0x49116c:[3,12,13][(index//3)%3],0x491158:index%2,0x49118c:15,
    0x4a4958:index%8,0x4a5a4c:island,0x4a864c:variant,0x4a72d0:[460,600,768,1024][index%4],
    0x4a763c:[640,700,701,900,901,1280][index%6],0x4a4760:400,0x4a3fa0:400,
    0x4ac92c:(index//2)%2,0x4ac98c:(index//3)%2,0x4ac928:1 if island else (index//11)%2,
    0x4ac1e0:index%2,0x4ac840:[0,44,59,60,74,75,89,90,180,270,285,300,301,359][index%14],
    0x4aa804:1+index%4,0x4ac284:0,0x4a3a08:0,0x4a67bc:90,0x4a67c0:180,0x4a67c4:270,
    0x4a5b9c:(index//17)%2,0x4a4378:(index//13)%2,0x4aca10:[9,10,11,300,630,631][index%6],0x4aca14:250,
    0x4ac904:(index//23)%2,0x4ac9d0:(index//29)%2,0x4ac9d8:(index//31)%2,
    0x4ac980:[0,1,2,109,299,300,499,500][index%8],0x4aa7e0:2,
    0x4a475c:[0,1,180,359][index%4],0x4a4770:[0,1,180,359][(index//4)%4],
    0x4a47fc:[0,44,45,180][index%4],0x4a4800:[0,44,45,180][(index//4)%4],
    0x4a7bcc:[0,44,45,180][(index//7)%4],0x4a7bd0:[0,44,45,180][(index//9)%4],
    0x4a5b80:200,0x4a4168:0,0x4a60a0:index%2,0x4a4be4:index%25,0x4a8020:0,0x4ac94c:0,
    0x4ac1dc:[0,1,10,50,-50][index%5],0x4aae1c:[0,90,180,270][index%4],0x4ac85c:1+index%2,
    0x4aa800:0,0x4aa298:0,0x4a5b80:200,0x4aa290:1000,0x4abae8:1000,
    0x4aa594:200,0x4aa59c:300,0x4a6444:10,0x4a6448:20,0x4a644c:30,0x4a645c:100,0x4a6460:200,0x4a6464:300,
    0x4ac950:index%2}
   for a,v in integers.items():vm.write_i32(a,v)
   for a,v in [(0x4ab0c8,[0.5,1.,1.3][index%3]),(0x4abef0,[-2.99,0.,2.,3.99,100.25][index%5]),
    (0x4aa810,[1.,2.,3.5][index%3]),(0x4a6470,1.),(0x4abe60,1.)]:vm.uc.mem_write(a,struct.pack('<d',v))
   for boat in range(3):
    for a,v in [(0x4a4e88,1+(index//5+boat)%3),(0x4a6830,[0,44,90,179,180,270,359][(index+boat)%7]),
     (0x4ac018,[0,1,99,100,359,360][(index+boat)%6]),(0x4aa730,-1 if (index+boat)%2 else 1),
     (0x4ab9e8,index%101),(0x4a6338,index%71),(0x4a6ba0,(index+boat)%4),(0x4a72d8,index%2),
     (0x4ac208,37),(0x4a4778,9)]:vm.write_i32(a+boat*4,v)
    for a,v in [(0x4a49e8,float(100+boat*30)),(0x4a4ae0,float(200+boat*40)),(0x4a7f28,85.)]:vm.uc.mem_write(a+boat*8,struct.pack('<d',v))
   for point in range(181):
    angle=point*2*math.pi/180
    for a,v in [(0x4a6490,round(1500*math.sin(angle))),(0x4a68c8,round(-1500*math.cos(angle))),
     (0x4a9454,[0,1,25,26,50,51,74,75,99][(index+point)%9])]:vm.write_i32(a+point*4,v)
    vm.uc.mem_write(0x4a8028+point*8,struct.pack('<d',1500.))
   for point in range(6):
    vm.uc.mem_write(0x4a52f0+point*8,struct.pack('<d',float(200+point*100)))
    vm.uc.mem_write(0x4a60b0+point*8,struct.pack('<d',float(-300-point*90)))
   horizon=vm.read_i32(0x491148)
   if name=='drawProjectedShoreline':
    first,last=[(0,36),(2,36),(0,180),(35,36),(90,92),(180,180),(1,0),(0,0)][index%8]
    params=[horizon,first,last,camera,0,0,800,600,horizon]
   elif name=='drawShoreSegment':
    x1=[-100,0,1,100,300,799,800,900][index%8];x2=[10,101,799,801,1200][(index//8)%5]
    if x1==x2:x2+=1
    y1=[horizon-1,horizon,horizon+1,horizon+2,250,599,600,601,1000][(index//3)%9]
    y2=[horizon,horizon+1,300,601][(index//11)%4]
    params=[x1,y1,x2,y2,600,[1,2,6,7,11,12,13,14,17,18,19,20,24,25,29,30,35,36,180][index%19],0,0,800,600,horizon,250]
   elif name=='drawHeadingIndicator':params=[camera,[40,100,640,800][index%4],[0,100,150,600][(index//4)%4]]
   elif name=='drawSceneLayline':params=[[-1,0,1,2][index%4],camera,[0,10,100][(index//4)%3],[0,100,150,600][(index//8)%4],800]
   else:
    params=[[-2147483648,-100,0,1,300,800,2147483647][index%7],[horizon-1,horizon,horizon+1,150,300,600,1200,-2147483648,2147483647][(index//7)%9]]
    if nargs==3:params.append([0,1,2,3,100][(index//11)%5])
   # Safe, explicit observation returns. Lists are trimmed to exactly consumed values.
   pattern=[[0],[0x8000],[0,0x8000],[0,0,0x8000],[0xffffffff,0xffffff,0x123456]][index%5]
   pixel_values=[pattern[i%len(pattern)] for i in range(1024)];vm.pixel_sampler=lambda x,y,ordinal:pixel_values[ordinal]
   before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace()
   observed={}
   if name=='drawProjectedShoreline':
    for field,offset in [('centerProjectedY',-0xb6c),('previousX',-0xb54+params[1]*4),('previousTreeY',-0x2d8+params[1]*4)]:observed[field]=vm.read_i32(STACK+offset)
   vm.call(address,argument_bytes([CDC]+params,['I32']*(nargs+1)),count=5000000)
   after=bytes(vm.uc.mem_read(BASE,SIZE))
   if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original .text changed')
   expected={'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}
   row={'arguments':params,'seedAtCall':seed,'imageInputs':[{'address':r['address'],'bits':r['after']} for r in changed(baseline,before)],
    'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],'pixelReadValues':pixel_values[:vm.pixel_read_index],'expected':expected}
   if observed:row['observedRetainedStack']=observed
   rows.append(row)
  fixture['routines'][name]={'address':address,'argumentTypes':['CDC']+['I32']*nargs,'returnType':'void','cases':rows}
  print(name,len(rows),flush=True)
 fixture['provenance']['virtualCalls']={hex(a):hex(v) for a,v in sorted(vm.virtual_calls.items())}
 fixture['provenance']['importCalls']={hex(a):v for a,v in sorted(vm.import_calls.items())}
 save(ROOT/'tests/fixtures/original-shore.json',fixture)
 if not args.emulated_only:
  command=[sys.executable,str(ROOT/'tools/verify_native_state.py'),'--fixture','original-shore.json','--report',str(ROOT/'analysis/shore-native-reference-comparison.json')]
  subprocess.run(command+['--update-fixture'],check=True);subprocess.run(command,check=True)

if __name__=='__main__':main()
