#!/usr/bin/env python3
"""Original first-person sky, water and wind-patch drawing fixtures."""
import hashlib
import json
import random
import struct
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_gdi_fixtures import DrawingMachine, CDC
from capture_original_fixtures import ROOT, EXPECTED, TLS, arguments, save
from capture_initialization_fixtures import BASE, SIZE, changed
from capture_encounter_fixtures import merged_ranges

def main():
    vm=DrawingMachine();vm.call(0x415a60)
    baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800));source=random.Random(0x42f930)
    handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
    writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Original sky/water/wind code and MFC line helpers retained. Explicit observational CDC and GDI bindings. Finite synthetic drawing states; native x87 authority required; no raster identity claim.'},
        'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
    def put(address,value,floating=False):vm.uc.mem_write(address,struct.pack('<d',value) if floating else struct.pack('<I',value&0xffffffff))
    for name,address,count,cases_count in [('drawSky',0x4060f0,1,512),('drawRippleSegment',0x42fe00,4,256),
        ('drawWaterRipples',0x42f930,5,384),('drawLargeWaves',0x42fe40,5,384),('drawSceneWindPatch',0x431b30,6,512)]:
        cases=[]
        for index in range(cases_count):
            vm.uc.mem_write(BASE,baseline);seed=2002+index;put(TLS+0x14,seed)
            for handle in handles:put(handle,handle)
            width=[640,800,1024,1280][index%4];height=[460,600,720,768][index%4];camera=1+index%2
            for location,value in [(0x4a763c,width),(0x4a72d0,height),(0x491148,[0,30][index%2]),(0x4a3fa0,width//2),(0x4a4760,height*4//5),
                (0x491170,[1,10,30,100][index%4]),(0x4aca18,[-20,0,1,25,100,1000][index%6]),(0x4aca20,[-20,0,1,25,100,1000][(index//3)%6]),
                (0x4ac98c,(index//5)%2),(0x4ac92c,(index//7)%2),(0x4a5b98,index%5),(0x4aaa1c,index%12),
                (0x4aa62c,(index//2)%2),(0x4aa638,(index//3)%2),(0x4ac8f8,index%3),
                (0x4a475c,[-180,-20,-1,0,1,19,20,90,179,180][index%10]),(0x4a4770,[-180,-20,-1,0,1,19,20,90,179,180][(index//3)%10])]:put(location,value)
            put(0x4ab0c8,[.75,1.,1.25,1.5][index%4],True)
            for player in [1,2]:
                for base,value in [(0x4a6830,(index*29+player*73)%361),(0x4a4e88,1+(index+player)%3),
                    (0x4a7bc8,(index*17+player*89)%181),(0x4aa730,[-1,1][(index+player)%2]),
                    (0x4ac4e8,index%5)]:put(base+player*4,value)
                for base,value in [(0x4a49e8,[-500.125,0.,400.375][index%3]),(0x4a4ae0,[-400.125,0.,700.375][(index//3)%3]),
                    (0x4a71c8,[0.,1.2,5.5,20.][index%4])]:put(base+player*8,value,True)
            for cloud in range(10):
                put(0x4a8870+cloud*4,(index*13+cloud*47)%361);put(0x4a44f0+cloud*4,index%30+cloud);put(0x4a4928+cloud*4,10+cloud*3)
                put(0x4a8850+cloud*4,(index*17+cloud*19)%361);put(0x4a44d0+cloud*4,index%20+cloud)
            for point in range(160):put(0x4a9450+point*4,source.randrange(103));put(0x4ac694+point*4,[0,1,3,10][(index+point)%4]);put(0x4aa398+point*4,[0,1,3,10][(index+point)%4])
            for patch in range(1,6):
                put(0x4abd88+patch*8,[-2000.,-100.,0.,100.,2000.][(index+patch)%5],True)
                put(0x4a4728+patch*8,[-2000.,-100.,0.,100.,2000.][(index//3+patch)%5],True)
                put(0x4a4ec0+patch*4,[5,10,100,1000,10000][(index+patch)%5])
            if name=='drawSky':params=[camera]
            elif name=='drawRippleSegment':params=[index*13-500,index*7-200,index%30-15,index%70-35]
            elif name=='drawSceneWindPatch':params=[1+index%5,camera,10,10,width-10,height-10]
            else:params=[camera,10,10,width-10,height-10]
            if len(params)!=count:raise AssertionError('Capture stack contract differs')
            before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace();vm.call(address,arguments(CDC,*params),count=5000000)
            after=bytes(vm.uc.mem_read(BASE,SIZE))
            if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original instructions changed')
            cases.append({'arguments':params,'seedAtCall':seed,'imageInputs':[{'address':row['address'],'bits':row['after']} for row in changed(baseline,before)],
                'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
                'expected':{'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),
                    'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}})
        fixture['routines'][name]={'address':address,'argumentTypes':['CDC']+['I32']*count,'returnType':'void','cases':cases};print(name,len(cases),flush=True)
        save(ROOT/'tests/fixtures/original-scene-surface.json',fixture)

if __name__=='__main__':main()
