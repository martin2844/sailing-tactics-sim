#!/usr/bin/env python3
"""Unchanged original mouse handlers, complete state and ordered host requests."""
import hashlib,itertools,struct
import unicorn
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine,ROOT,EXPECTED,SCRATCH,TLS,arguments,save
from capture_initialization_fixtures import BASE,SIZE,changed
from capture_encounter_fixtures import merged_ranges
WINDOW=0x76543210
def main():
    vm=OriginalMachine();vm.call(0x415a60);obj=SCRATCH+0x1000;stub=SCRATCH+0x1800
    vm.write_i32(obj+0x1c,WINDOW);vm.write_i32(0x4b1bc4,stub);vm.uc.reg_write(UC_X86_REG_ECX,obj);vm.baseline=vm.uc.context_save()
    baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800));events=[];writes=[]
    def invalidate(uc,address,size,data):
        esp=uc.reg_read(UC_X86_REG_ESP);ret,window,rect,erase=struct.unpack('<4I',uc.mem_read(esp,16))
        events.append({'op':'invalidateRect','windowHandle':window,'rectangle':None,'erase':erase})
        uc.reg_write(UC_X86_REG_EAX,1);uc.reg_write(UC_X86_REG_ESP,esp+16);uc.reg_write(UC_X86_REG_EIP,ret)
    def default(uc,address,size,data):
        esp=uc.reg_read(UC_X86_REG_ESP);ret=struct.unpack('<I',uc.mem_read(esp,4))[0];events.append({'op':'defaultMouseHandler'})
        uc.reg_write(UC_X86_REG_ESP,esp+4);uc.reg_write(UC_X86_REG_EIP,ret)
    vm.uc.hook_add(unicorn.UC_HOOK_CODE,invalidate,begin=stub,end=stub);vm.uc.hook_add(unicorn.UC_HOOK_CODE,default,begin=0x468021,end=0x468021)
    vm.uc.hook_add(unicorn.UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Unchanged original mouse handlers. Explicit observational InvalidateRect and MFCDefault bindings; no raster/window behavior claim.'},'windowHandle':WINDOW,'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
    for name,address in [('handleLeftButtonDown',0x452790),('handleRightButtonDown',0x4528d0),('handleMouseMove',0x455730)]:
        cases=[]
        for index,(x,y,profile) in enumerate(itertools.product([-0x80000000,-1,0,1,333,334,335,600,0x7fffffff],[-1,0,1,99,100,101,119,120,121,0x7fffffff],range(4))):
            vm.uc.mem_write(BASE,baseline);vm.write_i32(TLS+0x14,2002)
            for location,value in [(0x4a763c,1000),(0x4a600c,100),(0x4ac980,[0,1,300,-1][profile]),(0x4ac8fc,profile%2),
                (0x4a6774,[0,2,3,0x7fffffff][profile]),(0x491184,3)]:vm.write_i32(location,value)
            for location in [0x4ac988,0x4ac984,0x4ac974,0x4ac970,0x4ac968,0x4aa980,0x4ac938]:vm.write_i32(location,[0,0,1,0x7fffffff][profile])
            before=bytes(vm.uc.mem_read(BASE,SIZE));argv=[index%32,x,y];events.clear();writes.clear();vm.call(address,arguments(*argv));after=bytes(vm.uc.mem_read(BASE,SIZE))
            if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original code changed')
            cases.append({'arguments':argv,'seedAtCall':2002,'imageInputs':[{'address':row['address'],'bits':row['after']} for row in changed(baseline,before)],
                'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
                'expected':{'rngState':vm.read_u32(TLS+0x14),'hostEvents':events.copy(),'sounds':[],'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest()}})
        fixture['routines'][name]={'address':address,'argumentTypes':['I32']*3,'returnType':'void','cases':cases};print(name,len(cases),flush=True)
    save(ROOT/'tests/fixtures/original-mouse.json',fixture)
if __name__=='__main__':main()
