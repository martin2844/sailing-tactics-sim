#!/usr/bin/env python3
"""Capture unchanged original chart traversal and projection helper calls."""
import hashlib
import json
import random
import struct
import sys
import unicorn
from unicorn import UC_HOOK_MEM_WRITE, UC_HOOK_MEM_INVALID
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_EDI, UC_X86_REG_EBX, UC_X86_REG_EDX
from capture_gdi_fixtures import DrawingMachine, CDC
from capture_hud_state_fixtures import StringMachine
from capture_hud_fixtures import HudMachine
from capture_original_fixtures import ROOT, EXPECTED, TLS, save
from capture_initialization_fixtures import BASE, SIZE, changed
from capture_encounter_fixtures import merged_ranges

class DrawingStringMachine(DrawingMachine, StringMachine):
    pass

def main():
    wrapper='--wrapper' in sys.argv
    vm=HudMachine() if wrapper else DrawingStringMachine();vm.call(0x415a60)
    baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800))
    handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
    source=random.Random(0x421d90);writes=[]
    vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    def invalid(uc,access,address,size,value,data):
        boat=uc.reg_read(UC_X86_REG_EDI)
        print('Invalid original access',hex(uc.reg_read(UC_X86_REG_EIP)),hex(address),size,'boat',boat,'baseHeading',uc.reg_read(UC_X86_REG_EBX),'angle',uc.reg_read(UC_X86_REG_EDX),'sheet',vm.read_i32(0x4a77e8+boat*4),'tack',vm.read_i32(0x4aa730+boat*4),flush=True)
        return False
    vm.uc.hook_add(UC_HOOK_MEM_INVALID,invalid)
    fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Original game code retained; explicit observational GDI/CDC and CString byte-copy bindings. Ordered drawing requests and complete mutable state; native authority required for x87 vendor outputs; no raster/heap identity claim.'},
        'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
    def put(address,value,kind='I32'):vm.uc.mem_write(address,struct.pack('<d',value) if kind=='F64' else struct.pack('<I',value&0xffffffff))
    routines=[('displacePoint',0x420b20,['I32']*4,512),
        ('drawChartWindPatch',0x431890,['CDC','I32','I32','F64']+['I32']*7,512),
        ('drawLaylines',0x431440,['CDC']+['I32']*6,1024),
        ('drawChartObjects',0x421d90,['CDC','I32','I32','F64']+['I32']*8,240)]
    terrain='--terrain' in sys.argv
    if terrain:routines=[('drawRiverShore',0x422970,['CDC'],128),('drawAlternateShore',0x4232e0,['CDC'],128),
        ('drawSplitShore',0x422cf0,['CDC'],128),('drawAdvancedShore',0x44f630,['CDC'],64),
        ('drawBasicChartTerrain',0x4226c0,['CDC','I32','I32','F64']+['I32']*4,64),
        ('drawAdvancedChartTerrain',0x44f320,['CDC','I32','I32','F64']+['I32']*4,48),
        ('drawArrowSegment',0x430f30,['CDC']+['I32']*4,128),('drawArrow',0x430eb0,['CDC']+['I32']*4,128),
        ('drawChartMarkLabel',0x430570,['CDC']+['I32']*3,160),
        ('drawChartObjects',0x421d90,['CDC','I32','I32','F64']+['I32']*8,240)]
    if wrapper:routines=[('drawChart',0x407e40,['CDC']+['I32']*6,160),
        ('drawWindChartOverlay',0x4094c0,['CDC']+['I32']*3,128),('drawCourseChartOverlay',0x409050,['CDC']+['I32']*3,128),
        ('drawTideChartOverlay',0x408c70,['CDC']+['I32']*3,128)]
    filename='original-chart-wrapper.json' if wrapper else 'original-chart-terrain.json' if terrain else 'original-chart-details.json'
    for name,address,kinds,count in routines:
        if len(sys.argv)>1 and not terrain and not wrapper and name!=sys.argv[1]:continue
        cases=[]
        for index in range(count):
            vm.uc.mem_write(BASE,baseline);seed=index+2002;put(TLS+0x14,seed)
            for handle in handles:put(handle,handle)
            width=[640,800,1024,1280][index%4];height=[460,600,720,768][index%4]
            for location,value in [(0x4a763c,width),(0x4a72d0,height),(0x491148,30),(0x4a3fa0,width//2),(0x4a4760,height//2),
                (0x4ac98c,(index//5)%2),(0x4ac92c,(index//7)%2),(0x4ac958,(index//11)%2),
                (0x49118c,[1,2,15,30][index%4]),(0x491140,1+index%2),(0x4ab9d8,[0,1,4,10][index%4]),
                (0x4a5b80,[-5,-1,0,1,29,30,31,90][index%8]),(0x4ac93c,(index//13)%2),
                (0x491194,[1,8][index%2]),(0x491160,(index//3)%2),(0x49117c,(index//2)%2),
                (0x4ac9a8,(index//17)%2),(0x4aa7e0,1+index%5),(0x4a4eb0,43),(0x4ac910,index%2),
                (0x4ac900,(index//3)%2),(0x491188,1+index%12),(0x4ac928,(index//5)%2),(0x4ac904,(index//7)%2),
                (0x4a40c4,(index//11)%2),(0x4a40c8,(index//13)%2),(0x4ac940,index%2),
                (0x4ac840,(index*13)%361),(0x4a4f8c,(index*17)%361),(0x4aa804,index%5),
                (0x4a4958,index%8),(0x4aa390,5+index%16),(0x4aa800,index-80),(0x4aae1c,(index*31)%361),
                (0x4aa298,index-50),(0x4a864c,index%2),(0x4a5a4c,(index//3)%2),(0x4ac1e0,(index//5)%2),
                (0x4ac970,(index//7)%2 if terrain else 0),(0x4ac974,(index//11)%2 if terrain else 0)]:put(location,value)
            put(0x4ab0c8,1.0,'F64');put(0x4a8670,height*struct.unpack('<d',vm.uc.mem_read(0x484cb0,8))[0],'F64')
            for patch in range(1,6):
                put(0x4a4ec0+patch*4,[5,10,100,1000,10000][(index+patch)%5])
                put(0x4abd90+(patch-1)*8,source.uniform(-5000,5000),'F64');put(0x4a4730+(patch-1)*8,source.uniform(-5000,5000),'F64')
            for slot in range(33):put(0x4a9454+slot*4,(slot*37+index)%103)
            for boat in range(1,31):
                for base,value in [(0x4ac018,(index*29+boat*71)%361),(0x4a6830,(index*7+boat*83)%361),
                    (0x4aa5b0,(index*19+boat*179)%361),(0x4ab160,(index+boat)%3),(0x4a8660,[2,4,8,16,32,64][(index+boat)%6]),
                    (0x4aa730,[-1,1][(index+boat)%2]),(0x4a6ec8,(index+boat)%50),(0x4a77e8,(index*7+boat)%100),
                    (0x4abb70,(index//7+boat)%2),(0x4a7060,(index*13+boat)%100),
                    (0x4a7bc8,[0,43,89,90,91,120,165,180][(index+boat)%8]),(0x4a5f10,[0,15,20,30][(index+boat)%4]),
                    (0x4a6ba0,(index+boat)%4)]:put(base+boat*4,value)
                put(0x4a49e8+boat*8,source.uniform(-3000,3000),'F64');put(0x4a4ae0+boat*8,source.uniform(-3000,3000),'F64')
            # Camera controls are player-only fields, not 31-boat arrays.
            for player in [1,2]:
                put(0x4aa6e0+player*4,2000);put(0x4a4e88+player*4,(index+player)%4)
            put(0x4a8670,height*struct.unpack('<d',vm.uc.mem_read(0x484cb0,8))[0],'F64')
            for object_ in range(1,36):
                put(0x4a52f0+object_*8,source.uniform(-5000,5000),'F64');put(0x4a60b0+object_*8,source.uniform(-5000,5000),'F64')
            for player in [1,2]:
                for step in range(10):put(0x4a9a0c+player*0x25c+step*4,source.randrange(-5000,5001));put(0x4ab1a4+player*0x25c+step*4,source.randrange(-5000,5001))
            if terrain or wrapper:
                for base in [0x4a6490,0x4a68c8,0x4a8e90,0x4a9168]:
                    for point in range(180):put(base+point*4,source.randrange(-30000,30001))
                for base in [0x4a4f90,0x4a5bb0,0x4a7360,0x4a8b28]:
                    for point in range(181):put(base+point*4,source.randrange(-2000,2001))
            if wrapper:
                for location,value in [(0x4ab184,3000),(0x4ac970,0),(0x4ac974,0),(0x4aa980,(index//4)%2),
                    (0x4a774c,25),(0x4aa97c,10+[0,height//56,height//28+2+height//56,height//14+4][(index//2)%4]),
                    (0x4ac94c,[0,1,2,3,6,12][index%6]),(0x4a8020,0),(0x4a4be4,0),(0x4ac1dc,8),
                    (0x4aa294,100),(0x4aa388,-100),(0x4aa38c,-400),(0x4aa588,1000),(0x4aa288,700),(0x4aa384,800)]:put(location,value)
            camera=1+index%2;x=index*7-500;y=index*11-300;scale=[.05,.1,.25,1.,2.][index%5]
            if name=='displacePoint':argv=[x,y,[0,1,20,1000,10000][index%5],(index*29)%361]
            elif name=='drawChartWindPatch':argv=[1+index%5,camera,scale,x,y,0,0,width,height,1+index%3]
            elif name=='drawLaylines':argv=[x,y,1+index%5,camera,index%2,1+index%5]
            elif name in ['drawBasicChartTerrain','drawAdvancedChartTerrain']:argv=[width//2,height//2,scale,73,91,1+index%4,camera]
            elif name in ['drawRiverShore','drawAlternateShore','drawSplitShore','drawAdvancedShore']:argv=[]
            elif name in ['drawArrowSegment','drawArrow']:argv=[x,y,(index*29)%361,1+index%20]
            elif name=='drawChartMarkLabel':argv=[1+index%5,x,y]
            elif name=='drawChart':argv=[20,10,width-20,height-10,camera,1+(index//8)%4]
            elif name in ['drawWindChartOverlay','drawCourseChartOverlay','drawTideChartOverlay']:argv=[20,10,width-20]
            else:argv=[width//2,height//2,scale,73,91,3+index%2 if terrain else 1+index%2,camera,0,0,width,height]
            before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace();vm.reset_strings()
            packed=struct.pack('<I',CDC) if kinds[0]=='CDC' else b''
            for kind,value in zip(kinds[1:] if kinds[0]=='CDC' else kinds,argv):packed+=struct.pack('<d',value) if kind=='F64' else struct.pack('<I',value&0xffffffff)
            try:vm.call(address,packed,count=5000000)
            except Exception:
                print('Failed original call',name,index,argv,flush=True)
                raise
            after=bytes(vm.uc.mem_read(BASE,SIZE))
            if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original game instructions changed')
            cases.append({'arguments':argv,'seedAtCall':seed,'imageInputs':[{'address':row['address'],'bits':row['after']} for row in changed(baseline,before)],
                'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
                'expected':{'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),
                    'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}})
        fixture['routines'][name]={'address':address,'argumentTypes':kinds,'returnType':'void','cases':cases};print(name,len(cases),flush=True)
        save(ROOT/'tests/fixtures'/filename,fixture)
    save(ROOT/'tests/fixtures'/filename,fixture)
    if wrapper:
        save(ROOT/'analysis/chart-cdc-callsites.json',{'source_sha256':EXPECTED,
            'scope':'Original call instructions dynamically observed using explicit observational CDC/GDI/CString host bindings.',
            'calls':[{'address':address,'vtableOffset':offset} for address,offset in sorted(vm.virtual_calls.items())],
            'importCalls':[{'address':address,'name':name} for address,name in sorted(vm.import_calls.items())]})

if __name__=='__main__':main()
