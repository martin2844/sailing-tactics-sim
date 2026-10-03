#!/usr/bin/env python3
"""Connected original race setup and complete 404880 scene observations.

All scene code stays original. CString/GDI operations are observable host
bindings; GetPixel returns are declared finite inputs. Retained shoreline stack
slots are captured at the exact instructions consuming them, never inferred
from JavaScript output.
"""
import argparse,hashlib,itertools,json,struct
import unicorn
from unicorn.x86_const import UC_X86_REG_ESP
from capture_hud_fixtures import HudMachine
from capture_gdi_fixtures import CDC
from capture_original_fixtures import ROOT,EXPECTED,TLS,arguments,save
from capture_initialization_fixtures import BASE,SIZE,changed
from capture_encounter_fixtures import merged_ranges

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',default='tests/fixtures/original-scene-composition.json')
    args=parser.parse_args()
    vm=HudMachine();vm.call(0x415a60);baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
    handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
    writes=[];shore=[];entry=[0];first=[0];pixels=[]
    vm.uc.hook_add(unicorn.UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    def read_i32(address):return struct.unpack('<i',vm.uc.mem_read(address,4))[0]
    def inspect(uc,address,size,data):
        if address==0x42d120:
            esp=uc.reg_read(UC_X86_REG_ESP);entry[0]=esp;first[0]=read_i32(esp+12)
            shore.append({'entryArguments':list(struct.unpack('<11I',uc.mem_read(esp+4,44))),
                'centerProjectedY':read_i32(esp-0xb6c),'previousX':read_i32(esp-0xb54+first[0]*4),
                'previousTreeY':read_i32(esp-0x2d8+first[0]*4),'consumed':{},'orderedReads':[]})
        x_reads=[0x42d668,0x42d6c5,0x42d711,0x42d74b]
        y_reads=[0x42d67d,0x42d6dd,0x42d72a,0x42d773]
        if address in x_reads+y_reads:
            index=read_i32(entry[0]-0xb74)
            field='previousX' if address in x_reads else 'previousTreeY'
            offset=-0xb54 if address in x_reads else -0x2d8
            value=read_i32(entry[0]+offset+index*4)
            retained=index==first[0]
            shore[-1]['orderedReads'].append({'instruction':address,'index':index,'field':field,'value':value,'retained':retained})
            if retained:shore[-1]['consumed'][field]=value
    for address in [0x42d120,0x42d668,0x42d6c5,0x42d711,0x42d74b,0x42d67d,0x42d6dd,0x42d72a,0x42d773]:vm.uc.hook_add(unicorn.UC_HOOK_CODE,inspect,begin=address,end=address)
    def pixel(x,y,index):pixels.append(0xffffff);return 0xffffff
    vm.pixel_sampler=pixel
    fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Original417790/413f00 preparation, then complete404880 unchanged drawing code. ExplicitCString/GDI observations and GetPixel white input sequence. Retained shoreline slots consumed by original are recorded. Native authority remains required.'},
        'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
    cases=[]
    for index,(course,view,camera,island) in enumerate(itertools.product([1,2,4,6,8],[1,2,3],[1,2],[0,1])):
        vm.uc.mem_write(BASE,baseline);vm.write_i32(TLS+0x14,2002+index)
        for address,value in [(0x491144,12),(0x491188,6),(0x491194,course),(0x49116c,8),(0x491170,171),
            (0x491140,camera),(0x49118c,5),(0x4911cc,5),(0x4a5a4c,island),
            (0x4ac9ac,0),(0x4ac8f8,2),(0x4a763c,1024),(0x4a72d0,730),(0x4aaa1c,24)]:vm.write_i32(address,value)
        vm.uc.mem_write(0x4ab0c8,struct.pack('<d',1.024));vm.uc.mem_write(0x4a8670,struct.pack('<d',.768))
        vm.call(0x42e080);vm.call(0x417790);vm.call(0x413f00,count=5000000)
        for handle in handles:vm.write_i32(handle,handle)
        vm.write_i32(0x4a4e88+camera*4,view)
        argv=[0,0,1024,365,camera]
        before=bytes(vm.uc.mem_read(BASE,SIZE));seed=vm.read_u32(TLS+0x14)
        vm.reset_trace();vm.reset_strings();writes.clear();shore.clear();pixels.clear()
        try:vm.call(0x404880,arguments(CDC,*argv),count=12000000)
        except Exception:
            print('Failed scene',index,course,view,camera,island,flush=True);raise
        after=bytes(vm.uc.mem_read(BASE,SIZE))
        if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original code changed')
        cases.append({'arguments':argv,'configuration':{'course':course,'view':view,'camera':camera,'island':island},'seedAtCall':seed,
            'imageInputs':[{'address':row['address'],'bits':row['after']} for row in changed(baseline,before)],'pixelReadValues':pixels.copy(),
            'shorelineStackObservations':json.loads(json.dumps(shore)),
            'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
            'expected':{'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}})
        print('drawScene',index+1,course,view,camera,island,len(vm.events),flush=True)
        fixture['routines']['drawScene']={'address':0x404880,'argumentTypes':['CDC']+['I32']*5,'returnType':'void','cases':cases}
        save(ROOT/args.output,fixture)
    save(ROOT/'analysis/scene-cdc-callsites.json',{'source_sha256':EXPECTED,'calls':[{'address':address,'vtableOffset':offset} for address,offset in sorted(vm.virtual_calls.items())],
        'importCalls':[{'address':address,'name':name} for address,name in sorted(vm.import_calls.items())]})

if __name__=='__main__':main()
