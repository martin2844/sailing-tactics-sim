#!/usr/bin/env python3
"""Trace original game drawing calls with explicit observational GDI bindings.

The original game instruction bytes are retained. A test CDC vtable substitutes
framework virtual methods; imported GDI primitives record ordered commands.
This validates geometry and state effects, not Windows font/pixel rasterization.
"""
import hashlib
import json
import random
import struct
import unicorn
import pefile
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_initialization_fixtures import BASE, SIZE, changed
from capture_encounter_fixtures import merged_ranges

CDC = SCRATCH + 0x5000
VTABLE = SCRATCH + 0x4000

class DrawingMachine(OriginalMachine):
    def __init__(self):
        super().__init__()
        self.events=[];self.position=(0,0);self.colors={'text':0,'background':0xffffff,'mode':2}
        self.pixel_sampler=None;self.pixel_read_index=0
        self.uc.mem_write(VTABLE,bytes(self.uc.mem_read(0x487024,0x80)))
        self.uc.mem_write(CDC,struct.pack('<4I',VTABLE,1,0,0))
        self.hooks=[];self.next_stub=SCRATCH+0x6000
        def bind(callback,words):
            stub=self.next_stub;self.next_stub+=0x10
            def hook(uc,address,size,data):
                esp=uc.reg_read(UC_X86_REG_ESP)
                values=struct.unpack('<'+'I'*(words+1),uc.mem_read(esp,(words+1)*4))
                result=callback(values[1:])
                uc.reg_write(UC_X86_REG_EAX,0 if result is None else result&0xffffffff)
                uc.reg_write(UC_X86_REG_ESP,esp+(words+1)*4);uc.reg_write(UC_X86_REG_EIP,values[0])
            self.hooks.append(hook);self.uc.hook_add(UC_HOOK_CODE,hook,begin=stub,end=stub)
            return stub
        signed=lambda value:struct.unpack('<i',struct.pack('<I',value))[0]
        def emit(op,**values):self.events.append({'op':op,**values})
        def stock(values):emit('selectStockObject',index=signed(values[0]));return 0
        def color(values,name,op):
            previous=self.colors[name];self.colors[name]=values[-1];emit(op,**{'mode' if name=='mode' else 'color':signed(values[-1]) if name=='mode' else values[-1]});return previous
        def text(values):
            x,y,pointer,length=values[-4:]
            emit('textOut',x=signed(x),y=signed(y),text=bytes(self.uc.mem_read(pointer,length)).decode('cp1252'));return 1
        for offset,words,callback in [(0x2c,1,stock),(0x34,1,lambda v:color(v,'background','setBkColor')),
            (0x38,1,lambda v:color(v,'text','setTextColor')),(0x64,4,text)]:self.write_i32(VTABLE+offset,bind(callback,words))
        def move(values):
            _,x,y,previous=values;old=self.position;self.position=(signed(x),signed(y));emit('moveTo',x=self.position[0],y=self.position[1])
            if previous:self.uc.mem_write(previous,struct.pack('<2i',*old))
            return 1
        def line(values):
            _,x,y=values;self.position=(signed(x),signed(y));emit('lineTo',x=self.position[0],y=self.position[1]);return 1
        def shape(values,op):
            _,left,top,right,bottom=values;emit(op,left=signed(left),top=signed(top),right=signed(right),bottom=signed(bottom));return 1
        def polygon(values):
            _,pointer,count=values
            points=[{'x':x,'y':y} for x,y in struct.iter_unpack('<2i',self.uc.mem_read(pointer,count*8))]
            emit('polygon',points=points);return 1
        def select(values):emit('selectObject',handle=values[1]);return 0
        def pixel(values):_,x,y,value=values;emit('setPixel',x=signed(x),y=signed(y),color=value);return value
        def arc(values):
            emit('arc',**dict(zip(['left','top','right','bottom','startX','startY','endX','endY'],map(signed,values[1:]))));return 1
        def pie(values):
            emit('pie',**dict(zip(['left','top','right','bottom','startX','startY','endX','endY'],map(signed,values[1:]))));return 1
        def get_pixel(values):
            _,x,y=values;x,y=signed(x),signed(y)
            if self.pixel_sampler is None:raise ValueError('Original GetPixel requires an explicit synthetic sampler')
            value=self.pixel_sampler(x,y,self.pixel_read_index)&0xffffffff;self.pixel_read_index+=1
            emit('getPixel',x=x,y=y,color=value);return value
        def round_rect(values):
            emit('roundRect',**dict(zip(['left','top','right','bottom','ellipseWidth','ellipseHeight'],map(signed,values[1:]))));return 1
        callbacks={'MoveToEx':(4,move),'LineTo':(3,line),'Rectangle':(5,lambda v:shape(v,'rectangle')),
            'Ellipse':(5,lambda v:shape(v,'ellipse')),'Polygon':(3,polygon),'SelectObject':(2,select),
            'SetPixel':(4,pixel),'SetTextColor':(2,lambda v:color(v,'text','setTextColor')),
            'SetBkColor':(2,lambda v:color(v,'background','setBkColor')),'SetBkMode':(2,lambda v:color(v,'mode','setBkMode')),
            'TextOutA':(5,text),'Arc':(9,arc),'Pie':(9,pie),'GetPixel':(3,get_pixel),'RoundRect':(7,round_rect)}
        pe=pefile.PE(str(ROOT/'original/Tact02Demo.exe'))
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT:
            for item in descriptor.imports:
                name=item.name.decode('ascii') if item.name else None
                if name in callbacks:
                    words,callback=callbacks[name];self.write_i32(item.address,bind(callback,words))

    def reset_trace(self):
        self.events.clear();self.position=(0,0);self.colors={'text':0,'background':0xffffff,'mode':2}
        self.pixel_read_index=0

ROUTINES={
    'selectBoatColor':(0x416420,1),'drawCatamaranPanels':(0x417be0,0),'drawInteriorPanel':(0x41a450,1),
    'selectSailColor':(0x41af70,1),'drawWakePoint':(0x419d50,3),'drawSailCurve':(0x415590,10),
    'selectHeadingColor':(0x4166e0,1),'drawHeadingIndicator':(0x423670,5),'drawCircle':(0x423640,3),
    'drawCourseMark':(0x424890,5),
    'drawChartBoat':(0x423aa0,4),'drawChartCatamaran':(0x423830,4),
}

def main():
    vm=DrawingMachine();vm.call(0x415a60)
    baseline=bytes(vm.uc.mem_read(BASE,SIZE));text=bytes(vm.uc.mem_read(0x401000,0x80800));random_source=random.Random(0x416420)
    writes=[];vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data:writes.append((address,size)) if BASE<=address and address+size<=BASE+SIZE else None)
    handles=[row['handleAddress'] for row in json.loads((ROOT/'analysis/gdi-object-definitions.json').read_text())['objects']]
    fixture={'provenance':{'sha256':EXPECTED,'engine':'Unicorn','engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Original game instructions with explicit CDC framework virtual methods and GDI import observational bindings. Ordered commands and complete mutable state; no raster identity claim.',
        'cdcVirtualBindings':{'0x2c':'selectStockObject','0x34':'setBkColor','0x38':'setTextColor','0x64':'textOut'},'initialDC':{'position':[0,0],'textColor':0,'backgroundColor':0xffffff,'backgroundMode':2}},
        'mutableBlock':{'address':BASE,'size':SIZE},'baseline':{'integerTrigRoutine':0x415a60},'routines':{}}
    for name,(address,count) in ROUTINES.items():
        cases=[]
        for index in range(448 if name=='drawChartBoat' else 128):
            vm.uc.mem_write(BASE,baseline);vm.write_i32(TLS+0x14,index+2002)
            for handle in handles:vm.write_i32(handle,handle)
            for location,value in [(0x4ac92c,index%2),(0x4ac910,(index//2)%2),(0x4ac98c,(index//3)%2),
                (0x491140,1+index%2),(0x491188,1+index%12),(0x4ac928,(index//5)%2),
                (0x4ac904,(index//7)%2),(0x4a40c4,(index//11)%2),(0x4a40c8,(index//13)%2)]:vm.write_i32(location,value)
            vm.write_i32(0x4ac900,(index//3)%2)
            width=[640,800,1024,1280][index%4];height=[460,600,720,768][index%4]
            vm.write_i32(0x4a763c,width);vm.write_i32(0x4a72d0,height)
            factor=struct.unpack('<d',vm.uc.mem_read(0x484cb0,8))[0]
            vm.uc.mem_write(0x4a8670,struct.pack('<d',height*factor))
            for base in [0x4aa1a0,0x4aa2a0]:
                for i in range(32):vm.write_i32(base+i*4,random_source.randrange(-3000,3001))
            for boat in range(1,31):
                for base,value in [(0x4ac018,(index*29+boat*71)%361),(0x4a6830,(index*7+boat*83)%361),
                    (0x4aa5b0,(index*19+boat*179)%361),(0x4ab160,(index+boat)%3),(0x4a8660,[2,4,8,16,32,64][(index+boat)%6]),
                    (0x4aa730,[-1,1][(index+boat)%2]),(0x4a6ec8,(index+boat)%50),(0x4a77e8,(index*7+boat)%100),
                    (0x4abb70,(index//7+boat)%2),(0x4a7060,(index*13+boat)%100)]:vm.write_i32(base+boat*4,value)
            boat=index%31
            if name in ['selectBoatColor','selectHeadingColor','selectSailColor','drawInteriorPanel']:params=[boat]
            elif name=='drawWakePoint':params=[index*13-500,index*7-200,index%2]
            elif name=='drawSailCurve':params=[random_source.randrange(-100,101),random_source.randrange(-100,101),index%2,random_source.randrange(-30,31),0,20,100,120,random_source.randrange(-20,21),random_source.randrange(-5,6)]
            elif name=='drawHeadingIndicator':params=[index*13-500,index*7-200,1+index%30,1+index%2,1+index%3]
            elif name=='drawCircle':params=[index%30,index*13-500,index*7-200]
            elif name=='drawCourseMark':params=[index*13-500,index*7-200,1+index%5,1+index%3,1+index%2]
            elif name in ['drawChartBoat','drawChartCatamaran']:params=[index*3-500,index*7-200,index%31,1+index%2]
            else:params=[]
            assert len(params)==count
            before=bytes(vm.uc.mem_read(BASE,SIZE));writes.clear();vm.reset_trace()
            vm.call(address,arguments(CDC,*params))
            after=bytes(vm.uc.mem_read(BASE,SIZE))
            if bytes(vm.uc.mem_read(0x401000,0x80800))!=text:raise AssertionError('Original game code changed')
            cases.append({'arguments':params,'seedAtCall':index+2002,
                'imageInputs':[{'address':row['address'],'bits':row['after']} for row in changed(baseline,before)],
                'imageWrites':[{'address':start,'size':end-start} for start,end in merged_ranges(writes)],
                'expected':{'rngState':vm.read_u32(TLS+0x14),'sounds':[],'imageChanges':changed(before,after),
                    'mutableBlockHash':hashlib.sha256(after).hexdigest(),'drawingCommands':vm.events.copy()}})
        fixture['routines'][name]={'address':address,'argumentTypes':['CDC']+['I32']*count,'returnType':'void','cases':cases}
        print(name,len(cases),flush=True)
    save(ROOT/'tests/fixtures/original-gdi-primitives.json',fixture)

if __name__=='__main__':main()
