#!/usr/bin/env python3
"""Original target bearing, AI coordination and remembered-leg state fixtures.

Only the original CRT thread accessor and PlaySound import are substituted.
Explicit input patches and complete mutable-state hashes let the independent
Wine authority run the same calls without depending on these emulator results.
"""
import hashlib
import itertools
import math
import random
import struct
import sys
import unicorn
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, SCRATCH, TLS, arguments, save
from capture_initialization_fixtures import BASE, SIZE, changed
from capture_encounter_fixtures import merged_ranges


def main():
    vm = OriginalMachine(); vm.call(0x415a60)
    baseline = bytes(vm.uc.mem_read(BASE, SIZE))
    text = bytes(vm.uc.mem_read(0x401000, 0x80800))
    stub = SCRATCH + 0x800; vm.write_i32(0x4b1c18, stub)
    sounds, writes = [], []
    def sound(uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret, resource, module, flags = struct.unpack('<4I', uc.mem_read(esp, 16))
        sounds.append({'resourceId': resource, 'moduleHandle': module, 'flags': flags})
        uc.reg_write(UC_X86_REG_EAX, 1); uc.reg_write(UC_X86_REG_ESP, esp + 16); uc.reg_write(UC_X86_REG_EIP, ret)
    vm.uc.hook_add(UC_HOOK_CODE, sound, begin=stub, end=stub)
    vm.uc.hook_add(UC_HOOK_MEM_WRITE, lambda uc, access, address, size, value, data:
        writes.append((address, size)) if BASE <= address and address + size <= BASE + SIZE else None)
    random_source = random.Random(0x4249a0)
    fixture = {'provenance': {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
        'x87_control_word': '0x037f', 'tls_accessor_stub': '00459ed0', 'sound_import_stub': '004b1c18',
        'note': 'Unchanged local original instructions; synthetic states and connected initialization inputs. Native Wine authority is required for vendor transcendental instruction outputs.'},
        'mutableBlock': {'address': BASE, 'size': SIZE}, 'baseline': {'integerTrigRoutine': 0x415a60}, 'routines': {}}
    def put(address, value, floating=False):
        vm.uc.mem_write(address, struct.pack('<d', value) if floating else struct.pack('<I', value & 0xffffffff))
    def capture(name, address, kinds, argv, seed, floating=False, label=None, integer_return=False):
        before = bytes(vm.uc.mem_read(BASE, SIZE)); writes.clear(); sounds.clear()
        seed_at_call = vm.read_u32(TLS + 0x14)
        packed = b''.join(struct.pack('<d', value) if kind == 'F64' else struct.pack('<I', value & 0xffffffff) for kind, value in zip(kinds, argv))
        result = vm.call(address, packed, floating='extended' if floating else False, count=3000000)
        after = bytes(vm.uc.mem_read(BASE, SIZE))
        if bytes(vm.uc.mem_read(0x401000, 0x80800)) != text: raise AssertionError('Original code changed')
        record = {'arguments': argv, 'seed': seed, 'seedAtCall': seed_at_call,
            'imageInputs': [{'address': row['address'], 'bits': row['after']} for row in changed(baseline, before)],
            'imageWrites': [{'address': start, 'size': end-start} for start, end in merged_ranges(writes)],
            'expected': {'rngState': vm.read_u32(TLS+0x14), 'sounds': sounds.copy(), 'imageChanges': changed(before, after),
                'mutableBlockHash': hashlib.sha256(after).hexdigest()}}
        if label: record['label'] = label
        if floating: record['expected']['returnValue'] = result
        if integer_return: record['expected']['returnValue'] = struct.unpack('<i',struct.pack('<I',result))[0]
        fixture['routines'].setdefault(name, {'address': address, 'argumentTypes': kinds, 'returnType': 'Float80' if floating=='extended' else 'F64' if floating else 'I32' if integer_return else 'void', 'cases': []})['cases'].append(record)

    if '--projection' in sys.argv:
        routines=[('nearCourseMark',0x42ad00,['I32','I32'],False,True),
            ('updatePlayer1Camera',0x415ac0,[],False,False),('updatePlayer2Camera',0x415c40,[],False,False),
            ('projectedSize',0x4060a0,['I32','I32'],'extended',False),
            ('cameraRelativeBearing',0x42c210,['F64','F64','I32'],True,False),
            ('projectDistantPoint',0x42c2e0,['F64','I32','F64','F64','I32'],False,False),
            ('projectScenePoint',0x42bfc0,['I32','F64','F64','I32','I32'],False,False)]
        for name,address,kinds,floating,integer in routines:
            for index in range(512):
                vm.uc.mem_write(BASE,baseline);seed=index+2002;vm.write_i32(TLS+0x14,seed)
                boat=1+index%2
                for address_,value in [(0x4a5b80,[-170,-30,-29,-1,0,14,15,29,30,90][index%10]),
                    (0x491140,1+index%2),(0x4a763c,[640,800,1024,1280][index%4]),(0x4a72d0,[460,600,720,768][index%4]),
                    (0x4a3fa0,400),(0x4a4760,500),(0x491148,30),(0x4ac930,(index//3)%2),
                    (0x4aa294,100),(0x4aa388,-100),(0x4aa38c,-400),(0x4aa588,1000),(0x4aa288,700),(0x4aa384,800)]:put(address_,value)
                put(0x4ab0c8,[0.75,1.0,1.25,1.5][index%4],True)
                for player in [1,2]:
                    for base_,value in [(0x4a4e88,(index+player)%4),(0x4ac018,(index*13+player*43)%361),
                        (0x4aa5b0,(index*17+player*83)%361),(0x4a6830,(index*29+player*173)%361),
                        (0x4a4608,[-180,-90,-1,0,1,90,180,270][index%8]),(0x4aae20,(index//5)%2),
                        (0x4a9440,[-1,0,1,100][index%4]),(0x4aa730,[-1,1][(index+player)%2])]:put(base_+player*4,value)
                    put(0x4a49e8+player*8,[0.0,73.375,-2000.125][(index+player)%3],True)
                    put(0x4a4ae0+player*8,[0.0,-90.25,800.5][(index+player)%3],True)
                x,y=[(0.0,0.0),(100.0,-100.0),(-400.0,1000.0),(700.0,800.0),
                    (random_source.uniform(-10000,10000),random_source.uniform(-10000,10000))][index%5]
                if name=='nearCourseMark':argv=[[0,1,90,100,300,1000][index%6],boat]
                elif name.startswith('updatePlayer'):argv=[]
                elif name=='projectedSize':argv=[index*3-30,boat]
                elif name=='cameraRelativeBearing':argv=[x,y,boat]
                elif name=='projectDistantPoint':argv=[[0.4,0.7][index%2],index%36,x,y,boat]
                else:argv=[index%36,x,y,boat,[0,99][index%2]]
                capture(name,address,kinds,argv,seed,floating,integer_return=integer)
            print(name,512,flush=True)
        filename='original-projection.json'
    elif '--bearing' in sys.argv:
        coordinates = [(0, 0), (1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, 1), (1, -1), (-1, -1),
            (500.125, -90.75), (-0.0, 0.0), (1e-20, -1e-20), (math.nextafter(1.0, math.inf), 1.0)]
        coordinates += [(random_source.uniform(-20000,20000), random_source.uniform(-20000,20000)) for _ in range(96)]
        for index, ((x,y), selector, mode) in enumerate(itertools.product(coordinates, [-2,-1,0,1,2,3,4], range(3))):
            vm.uc.mem_write(BASE, baseline); seed = index + 2002; vm.write_i32(TLS+0x14, seed)
            boat = 1 + index % 3
            # Include absolute axes as well as nonzero translated boat positions.
            px, py = [(0.0,0.0), (73.375,-90.25), (-2000.125,800.5)][(index//3)%3]
            for base, value in [(0x4a49e8, px), (0x4a4ae0, py)]: put(base+boat*8,value,True)
            for base,value in [(0x4ab160,mode),(0x4a6830,(index*29)%361),(0x4ac018,(index*79)%361),(0x4aa5b0,(index*173)%361)]: put(base+boat*4,value)
            put(0x4aa594,[-1000,0,500][index%3]); put(0x4aa59c,[800,0,-1500][index%3])
            capture('targetRelativeBearing',0x42c400,['F64','F64','I32','I32'],[x,y,selector,boat],seed,True)
        filename = 'original-target-bearing.json'
    elif '--snapshots' in sys.argv:
        for name,address in [('saveRaceState',0x44dfe0),('restoreRaceState',0x44dbc0)]:
            for index,count in enumerate([0,1,2,3,15,30]*8):
                vm.uc.mem_write(BASE, baseline); seed=index+2002; vm.write_i32(TLS+0x14, seed)
                # Raw word copying should preserve every bit, including NaN data.
                for start,length in [(0x4a3300,0x8000),(0x4ab300,0x1700)]:
                    vm.uc.mem_write(start, bytes(random_source.randrange(256) for _ in range(length)))
                put(0x49118c,count)
                capture(name,address,[],[],seed)
        filename = 'original-snapshots.json'
    else:
        for index,(course,count,humans,time) in enumerate(itertools.product([1,2,6,7,8,9,10,11,14], [2,15], [1,2], [-170,-160,-20,-3,0,1,20,31,60,601])):
            vm.uc.mem_write(BASE, baseline); seed = index + 2002; vm.write_i32(TLS+0x14,seed)
            for address,value in [(0x491194,course),(0x49118c,count),(0x491140,humans),(0x491144,12 if index%2 else 21),
                (0x491188,7 if course==8 else 6),(0x4911cc,5),(0x4ac9ac,int(count==2 and index%3==0)),(0x4a5a4c,int(course==7))]: put(address,value)
            put(0x4ab0c8,1.0,True)
            vm.call(0x42e080); vm.call(0x417790); vm.call(0x413f00,count=3000000)
            put(0x4a5b80,time);put(0x4ac1f8,time+0.375,True)
            for address,value in [(0x4a8914,(index//2)%2),(0x4a8918,(index//3)%2),(0x4a4970,(index//5)%2),
                (0x4911a0,index%4),(0x491164,index%7 if index%11==0 else 0),(0x4ac95c,index%15),
                (0x4a60a0,index%2),(0x4ab8b4,200 if time==601 else 30000)]: put(address,value)
            boat=1+index%count
            if index%4==0:
                leg=[0,1,4,8][(index//4)%4];put(0x4a5420+boat*4,leg)
                put(0x4a4888+boat*4,vm.read_i32(0x4aa294));put(0x4a6f48+boat*4,vm.read_i32(0x4aa388))
            put(0x4aa660+boat*4,[-1,0,1][index%3]);put(0x4a41f0+boat*4,time-[0,1,2,3,4,6][index%6])
            capture('updateBoatWindAndAI',0x4249a0,['I32'],[boat],seed,label=f'course{course}-boats{count}-humans{humans}-time{time}')
        filename = 'original-ai-coordinator.json'
    save(ROOT/'tests/fixtures'/filename,fixture)
    print(filename, {name:len(group['cases']) for name,group in fixture['routines'].items()},flush=True)

if __name__=='__main__':main()
