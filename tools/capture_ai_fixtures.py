#!/usr/bin/env python3
"""Bounded original AI helper runs; explicit typed inputs and all image stores."""
import random
import sys
import struct
import unicorn
from unicorn import UC_HOOK_MEM_WRITE
from capture_original_fixtures import OriginalMachine, ROOT, EXPECTED, TLS, arguments, i32, save

GLOBALS = {'boatCount':0x49118c,'time':0x4a5b80,'secondBoatDelay':0x491168,
    'course':0x491194,'difficulty':0x491190,'weather':0x4a4958,'matchMode':0x4ac9ac,
    'reverseCourse':0x4ac9a8,'islandFlag':0x4a5a4c,'shortenedCourse':0x491160,
    'windTactics':0x4ac9b0,'windStrength':0x4aa390,'baseWindDirection':0x4a4f8c,
    'windShiftType':0x4a71a4,'driftRate':0x4abc7c,'oscillationFlag':0x4a5a48,
    'downwindRandomRange':0x4911b4,'startPointX':0x4aa294,'startPointY':0x4aa388}
BOATS = {'heading':(0x4ac018,'I32'),'tack':(0x4aa730,'I32'),'trueWindDirection':(0x4aa5b0,'I32'),
    'targetDistance':(0x4a5268,'I32'),'downwindLimit':(0x4a5f10,'I32'),'sailAngle':(0x4a5e90,'I32'),
    'interference':(0x4a7868,'I32'),'starboardObstruction':(0x4aada0,'I32'),
    'turnStarted':(0x4a7970,'I32'),'trueWindAngle':(0x4a7bc8,'I32'),'overlap':(0x4a6010,'I32'),
    'turnFlag':(0x4a4398,'I32'),'turning':(0x4aa660,'I32'),'legStarted':(0x4a41f0,'I32'),
    'boatWindStrength':(0x4a6338,'I32'),'priorTargetAngle':(0x4aba68,'I32'),
    'metric':(0x4a7f28,'F64'),'priorMetric':(0x4a4510,'F64'),
    'positionX':(0x4a49e8,'F64'),'positionY':(0x4a4ae0,'F64')}

def main(upwind_only=False):
    vm=OriginalMachine();vm.call(0x415a60)
    baseline=bytes(vm.uc.mem_read(0x400000,0x111000))
    prng=random.Random(0x425910)
    writes=[]
    vm.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,access,address,size,value,data: writes.append((address,size)) if 0x400000<=address<0x511000 else None)
    groups={}
    routines = [('updateUpwindTactics',0x427030)] if upwind_only else [('scoreDownwindTurn',0x425910),('chooseDownwindHeading',0x425600)]
    global_addresses = dict(GLOBALS)
    boat_specs = dict(BOATS)
    if upwind_only:
        global_addresses.update({'matchTurnDelay':0x4911b8,'recentLegDelay':0x4911bc,'closehauled':0x4a4eb0,
            'boatClass':0x491188,'kiteFlag':0x4ac904,'catamaranFlag':0x4ac900,'skiffFlag':0x4ac90c,
            'player1Shore':0x4a4ee8,'globalTide':0x4aa298,'randomRange':0x4911b0})
        boat_specs.update({'targetX':(0x4a4888,'I32'),'targetY':(0x4a6f48,'I32'),'leg':(0x4a5420,'I32'),
            'rateCoefficient':(0x4a6e48,'I32'),'speed':(0x4a7060,'I32'),'current':(0x4ac208,'I32'),
            'previousCurrent':(0x4a4778,'I32'),'collisionFlag':(0x4a40d0,'I32'),
            'smoothSpeed':(0x4a71c8,'F64'),'penaltyAmount':(0x4a6ec8,'I32'),
            'apparentInterference':(0x4aa82c,'I32')})
    for name,address in routines:
        cases=[]
        for index in range(1536):
            boat=1+index%3
            globals={'boatCount':[2,3,12][index%3],'time':[-1,0,9,10,11,60,100][index%7],
                'secondBoatDelay':[0,20,60][index%3],'course':[1,8][index%2],'difficulty':[1,6,7,10,12][index%5],
                'weather':[0,2,6][index%3],'matchMode':(index//3)%2,'reverseCourse':(index//5)%2,
                'islandFlag':(index//7)%2,'shortenedCourse':(index//11)%2,'windTactics':(index//13)%2,
                'windStrength':20,'baseWindDirection':[0,180,300,360][index%4],
                'windShiftType':(index//17)%2,'driftRate':[-5,0,5][index%3],
                'oscillationFlag':(index//19)%2,'downwindRandomRange':[1,30,1000][index%3],
                'startPointX':100,'startPointY':-100}
            selected={'heading':prng.randrange(361),'tack':[-1,1][index%2],
                'trueWindDirection':[0,180,270,300,360][index%5],'targetDistance':[0,99,100,199,200,201,399,400,401,799,800,801,1000][index%13],
                'downwindLimit':[5,12,20,33,40][index%5],'sailAngle':[0,10,20,40][index%4],
                'interference':[0,2,3,12][index%4],'starboardObstruction':(index//3)%2,
                'turnStarted':[-20,0,8,56,59,60][index%6],'trueWindAngle':[0,30,60,69,70,90,150][index%7],
                'overlap':(index//7)%2,'turnFlag':(index//11)%2,'turning':[0,-1,1][index%3],
                'legStarted':[-20,0,7,50,55,60][index%6],'boatWindStrength':[10,20,30][index%3],
                'priorTargetAngle':[-90,0,60,61,180][index%5],
                'metric':[4,15,29.999999999999996,30,40,60,100][index%7],
                'priorMetric':[4,15,30,40,60,100][index%6],
                'positionX':prng.uniform(-1000,1000),'positionY':prng.uniform(-1000,1000)}
            if upwind_only:
                globals.update({'matchTurnDelay':[0,5,10][index%3],'recentLegDelay':[0,20,60][index%3],
                    'closehauled':[35,40,45,50][index%4],'boatClass':1+index%12,
                    'kiteFlag':(index//5)%2,'catamaranFlag':(index//7)%2,'skiffFlag':(index//11)%2,
                    'player1Shore':(index//13)%2,'globalTide':[-10,0,10][index%3],'randomRange':[1,100,1000][index%3]})
                selected.update({'targetX':prng.randrange(-1000,1001),'targetY':prng.randrange(-1000,1001),
                    'leg':[1,4,8][index%3],'rateCoefficient':[10,20,30][index%3],'speed':[10,20,30][(index//3)%3],
                    'current':[-10,0,10][(index//5)%3],'previousCurrent':[-10,0,10][index%3],
                    'collisionFlag':(index//17)%2,'smoothSpeed':prng.uniform(0,100),'penaltyAmount':prng.randrange(100),
                    'apparentInterference':[0,2,3,12][(index//7)%4]})
            inputs=[]
            def put(address,value,kind='I32'):
                bits=struct.pack('<d' if kind=='F64' else '<i',value).hex()
                vm.uc.mem_write(address,bytes.fromhex(bits));inputs.append({'address':address,'type':kind,'bits':bits})
            vm.uc.mem_write(0x400000,baseline)
            for field,value in globals.items():put(global_addresses[field],value)
            put(0x4aa948,[0.01,0.1,0.25,0.5,1,2][index%6],'F64')
            for other in range(1,4):
                for field,(base,kind) in boat_specs.items():
                    value=selected[field] if other==boat else {'tack':[-1,1][(index+other)%2],
                        'positionX':other*40.5,'positionY':other*-20.25,'trueWindDirection':300,
                        'trueWindAngle':60,'metric':50,'priorMetric':60,'downwindLimit':20}.get(field,0)
                    put(base+other*(8 if kind=='F64' else 4),value,kind)
            seed=prng.randrange(2**32);vm.write_i32(TLS+0x14,seed)
            if upwind_only: params=(prng.randrange(361),boat)
            else: params=([70,71,90,135,140,145,159,160,170,180][index%10],prng.randrange(361),boat) if name=='scoreDownwindTurn' else (prng.randrange(361),[35,40,45,50][index%4],boat)
            writes.clear();result=vm.call(address,arguments(*params))
            stores=[{'address':addr,'size':size,'bits':bytes(vm.uc.mem_read(addr,size)).hex()} for addr,size in sorted(set(writes))]
            cases.append({'arguments':list(params),'boat':boat,'seed':seed,'inputs':inputs,
                'expected':{'returnValue':i32(result),'rngState':vm.read_u32(TLS+0x14),'stores':stores}})
        groups[name]={'address':address,'returnKind':'void' if upwind_only else 'I32','cases':cases}
    filename='original-upwind-tactics.json' if upwind_only else 'original-ai-tactics.json'
    save(ROOT/'tests/fixtures'/filename,{'provenance':{'sha256':EXPECTED,'engine':'Unicorn',
        'engine_version':unicorn.__version__,'x87_control_word':'0x037f',
        'note':'Independent resets; synthetic typed tactical/boat states, all image stores; complete frame parity remains unproven.'},
        'globals':global_addresses,'boats':{name:{'address':base,'type':kind,'stride':8 if kind=='F64' else 4} for name,(base,kind) in boat_specs.items()},'groups':groups})
    print(f'Captured {sum(len(group["cases"]) for group in groups.values())} complete AI helper calls')

if __name__=='__main__':main('--upwind-only' in sys.argv[1:])
