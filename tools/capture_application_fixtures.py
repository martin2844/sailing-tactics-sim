#!/usr/bin/env python3
"""Run the unchanged 402180 constructor with explicit archive/OS bindings.

The real 406060 archive reads, sanitization, trig generation, srand/rand and
graphics definitions execute. MFC window/file ownership is observational;
graphics handles are normalized to their original object handle slot.
"""
import argparse,hashlib,json,struct
import pefile,unicorn
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_FPCW
from capture_original_fixtures import OriginalMachine,ROOT,EXPECTED,SCRATCH,TLS,save
from capture_initialization_fixtures import BASE,SIZE,changed
from capture_encounter_fixtures import merged_ranges

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--control-word',type=lambda value:int(value,0),default=0x037f)
    parser.add_argument('--output',default='tests/fixtures/original-application.json')
    args=parser.parse_args()
    vm=OriginalMachine();vm.uc.mem_map(0,0x1000)
    obj=SCRATCH+0x1000;archive_data=SCRATCH+0x2000
    vm.uc.reg_write(UC_X86_REG_FPCW,args.control_word);vm.uc.reg_write(UC_X86_REG_ECX,obj);vm.baseline=vm.uc.context_save()
    baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
    fields=[0x491194,0x491144,0x49116c,0x49118c,0x491190,0x4ac9c0,0x4ac9a4,0x49114c,0x491154,0x491140,
        0x4ac948,0x491180,0x4a5a4c,0x4ac9a8,0x4ac960,0x4ac954,0x491158,0x49114c,0x4ac9d8,0x4ac978,
        0x4ac990,0x4ac998,0x4aae24,0x4aae28,0x4ac9bc,0x4ac92c,0x4ac944,0x4ac9c8,0x4ac95c,0x4911a0,
        0x4911cc,0x4ac9c8,0x4ac928,0x4ac9c0,0x4ab164,0x4ab168,0x4911d0,
        *[0x4a6bc4+i*16 for i in range(30)],*[0x4a6bc8+i*16 for i in range(30)],*[0x4a461c+i*4 for i in range(30)]]
    settings={};events=[];writes=[]
    def finish(uc,result=0,pop=0):
        esp=uc.reg_read(UC_X86_REG_ESP);ret=struct.unpack('<I',uc.mem_read(esp,4))[0]
        uc.reg_write(UC_X86_REG_EAX,result);uc.reg_write(UC_X86_REG_ESP,esp+4+pop);uc.reg_write(UC_X86_REG_EIP,ret)
    def hook(uc,address,size,data):
        esp=uc.reg_read(UC_X86_REG_ESP);this=uc.reg_read(UC_X86_REG_ECX)
        if address in [0x46fa46,0x46c3ab,0x470b91,0x46c44b]:finish(uc,this)
        elif address==0x46c52a:finish(uc,int(settings['preferences'] is not None),12)
        elif address==0x470ab5:
            vm.write_i32(this+0x14,1);vm.write_i32(this+0x24,archive_data);vm.write_i32(this+0x28,archive_data+len(settings['preferences']))
            finish(uc,this,16)
        elif address==0x470a2d:
            vm.write_i32(this+4,this+4);finish(uc,1,4)
        elif address==0x456f10:finish(uc,settings['timeSeed'])
        elif address==stubs['GetSystemMetrics']:
            index=struct.unpack('<i',uc.mem_read(esp+4,4))[0]
            if index!=1:raise AssertionError('Unexpected system metric')
            finish(uc,settings['screenHeight'],4)
        elif address==stubs['CreatePen']:
            style,width,color=struct.unpack('<iiI',uc.mem_read(esp+4,12));events.append({'kind':'pen','style':style,'width':width,'color':color});finish(uc,1,12)
        elif address==stubs['CreateSolidBrush']:
            color=struct.unpack('<I',uc.mem_read(esp+4,4))[0];events.append({'kind':'brush','color':color});finish(uc,1,4)
    pe=pefile.PE(str(ROOT/'original/Tact02Demo.exe'));imports={entry.name.decode():entry.address for group in pe.DIRECTORY_ENTRY_IMPORT for entry in group.imports if entry.name}
    stubs={name:SCRATCH+0x1800+i*16 for i,name in enumerate(['GetSystemMetrics','CreatePen','CreateSolidBrush'])}
    for name,stub in stubs.items():vm.write_i32(imports[name],stub)
    for address in [0x46fa46,0x46c3ab,0x46c52a,0x470ab5,0x470b91,0x46c44b,0x470a2d,0x456f10,*stubs.values()]:vm.uc.hook_add(unicorn.UC_HOOK_CODE,hook,begin=address,end=address)
    vm.uc.hook_add(unicorn.UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    cases=[]
    for index in range(64):
        vm.uc.mem_write(BASE,baseline);vm.write_i32(TLS+0x14,999);settings.clear();events.clear();writes.clear()
        preferences=None
        if index>=8:
            values=[struct.unpack('<i',baseline[address-BASE:address-BASE+4])[0] for address in fields]
            override={0x4911d0:[-1,0,1,2][index%4],0x4ab164:[-1,0,2,3][index%4],0x4ab168:[3,2,1,-1][index%4],
                0x4911cc:[0,1,5,6,10,11,2][index%7],0x49118c:2 if index%3==0 else 15,0x4ac944:[-1,0,2,3][index%4],
                0x491180:index%7,0x491194:index%15,0x491188:index%10,0x49116c:index%17,0x49114c:1}
            values=[override.get(address,value) for address,value in zip(fields,values)]
            preferences=b''.join(struct.pack('<i',value) for value in values);vm.uc.mem_write(archive_data,preferences)
        settings.update(preferences=preferences,timeSeed=[0,1,2002,0xffffffff][index%4],screenHeight=[600,768,1080,200][index%4])
        before=bytes(vm.uc.mem_read(BASE,SIZE));vm.call(0x402180,count=1000000);after=bytes(vm.uc.mem_read(BASE,SIZE))
        if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original code changed')
        cases.append({'preferences':None if preferences is None else preferences.hex(),'timeSeed':settings['timeSeed'],'screenHeight':settings['screenHeight'],
            'seedAtCall':999,'imageInputs':[], 'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
            'expected':{'rngState':vm.read_u32(TLS+0x14),'graphicsDefinitions':events.copy(),'sounds':[],
                'imageChanges':changed(before,after),'mutableBlockHash':hashlib.sha256(after).hexdigest()}})
    save(ROOT/args.output,{'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':f'0x{args.control_word:04x}',
        'note':'Full unchanged402180 constructor with explicit archive/file/window ownership, time/system metrics and graphics handle normalization. Original archive reads and game logic execute; not OS ownership parity.'},
        'mutableBlock':{'address':BASE,'size':SIZE},'preferenceFields':fields,'routines':{'initializeApplication':{'address':0x402180,'cases':cases}}})
    print('initializeApplication',len(cases),flush=True)
if __name__=='__main__':main()
