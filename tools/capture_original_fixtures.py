#!/usr/bin/env python3
"""Execute isolated numerical routines from the original PE in Unicorn x86.

This is a bounded local reference harness, not a Windows/game emulator. It
substitutes only the CRT thread-data accessor with one allocated TLS record.
All function instructions and constants come from the unmodified input file.
"""
from pathlib import Path
import hashlib
import json
import random
import struct
import math
import pefile
import unicorn
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FPCW

ROOT = Path(__file__).resolve().parents[1]
EXE = ROOT / 'original/Tact02Demo.exe'
EXPECTED = '881dc85dc7500a5ad09e09091d4dd53f8c091f5630d5fabdcc887cc4b007acea'
STACK = 0x0080F000
SCRATCH = 0x00700000
STOP = SCRATCH + 0x300
TLS = SCRATCH + 0x200

class OriginalMachine:
    def __init__(self, source=EXE, expected=EXPECTED, tls_accessor_address=0x00459ED0):
        raw = Path(source).read_bytes()
        if hashlib.sha256(raw).hexdigest() != expected:
            raise ValueError('Original hash mismatch')
        pe = pefile.PE(data=raw)
        image = pe.get_memory_mapped_image()
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        self.uc.mem_map(pe.OPTIONAL_HEADER.ImageBase, (pe.OPTIONAL_HEADER.SizeOfImage + 4095) & ~4095)
        self.uc.mem_write(pe.OPTIONAL_HEADER.ImageBase, image)
        self.uc.mem_map(SCRATCH, 0x10000)
        self.uc.mem_map(0x00800000, 0x10000)
        # fstp qword [scratch+0x100], then stop before executing next instruction.
        self.uc.mem_write(SCRATCH, b'\xdd\x1d' + struct.pack('<I', SCRATCH + 0x100))
        # Store binary64 without popping, then preserve the unrounded m80 return.
        self.uc.mem_write(SCRATCH + 0x20, b'\xdd\x15' + struct.pack('<I', SCRATCH + 0x100)
                          + b'\xdb\x3d' + struct.pack('<I', SCRATCH + 0x120))
        self.uc.reg_write(UC_X86_REG_FPCW, 0x037F)
        self.baseline = self.uc.context_save()
        self.uc.hook_add(UC_HOOK_CODE, self.tls_accessor, begin=tls_accessor_address, end=tls_accessor_address)

    def tls_accessor(self, uc, address, size, data):
        esp = uc.reg_read(UC_X86_REG_ESP)
        return_address = struct.unpack('<I', uc.mem_read(esp, 4))[0]
        uc.reg_write(UC_X86_REG_EAX, TLS)
        uc.reg_write(UC_X86_REG_ESP, esp + 4)
        uc.reg_write(UC_X86_REG_EIP, return_address)

    def write_i32(self, address, value):
        self.uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def read_u32(self, address):
        return struct.unpack('<I', self.uc.mem_read(address, 4))[0]

    def read_i32(self, address):
        return struct.unpack('<i', self.uc.mem_read(address, 4))[0]

    def call(self, address, args=b'', floating=False, count=200000):
        self.uc.context_restore(self.baseline)
        ret = SCRATCH + 0x20 if floating == 'extended' else SCRATCH if floating else STOP
        end = SCRATCH + 0x2c if floating == 'extended' else SCRATCH + 6 if floating else STOP
        self.uc.mem_write(STACK, struct.pack('<I', ret) + args)
        self.uc.reg_write(UC_X86_REG_ESP, STACK)
        self.uc.emu_start(address, end, count=count)
        if self.uc.reg_read(UC_X86_REG_EIP) != end:
            raise RuntimeError(f'Routine 0x{address:x} exceeded instruction bound')
        if floating:
            data = bytes(self.uc.mem_read(SCRATCH + 0x100, 8))
            result = {'value': struct.unpack('<d', data)[0], 'bits': data.hex()}
            if floating == 'extended':
                result['extendedBits'] = bytes(self.uc.mem_read(SCRATCH + 0x120, 10)).hex()
            return result
        return self.uc.reg_read(UC_X86_REG_EAX)

def i32(value):
    return struct.unpack('<i', struct.pack('<I', value & 0xffffffff))[0]

def arguments(*values):
    return b''.join(struct.pack('<I', v & 0xffffffff) for v in values)

def save(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2, allow_nan=False) + '\n')

def main():
    vm = OriginalMachine()
    provenance = {'sha256': EXPECTED, 'engine': 'Unicorn', 'engine_version': unicorn.__version__,
                  'x87_control_word': '0x037f', 'tls_accessor_stub': '0x459ed0',
                  'note': 'Reference outputs from original instructions under CPU emulation; not a full-game or original-CPU parity proof.'}
    prng = random.Random(2002)
    edges = [-2147483648, -2147483288, -721, -720, -361, -360, -359, -1, 0, 1, 359, 360, 361, 719, 720, 721, 2147483647]
    angles = edges + [prng.randrange(-2147483648, 2147483648) for _ in range(1024)]
    wraps = [{'input': v, 'expected': i32(vm.call(0x413cb0, arguments(v)))} for v in angles]
    speed_cases = []
    for level in [-2147483648, -1, 0, *range(1, 17), 2147483647]:
        for previous in [-123, 171, 123456789]:
            vm.write_i32(0x49116c, level)
            vm.write_i32(0x491170, previous)
            returned = vm.call(0x44e380)
            speed_cases.append({'level': level, 'previous': previous, 'expected': vm.read_i32(0x491170), 'return_value': i32(returned)})
    rng_sequences = []
    for seed in [0, 1, 2002, 0x7fffffff, 0x80000000, 0xffffffff]:
        vm.write_i32(TLS + 0x14, seed)
        sequence = []
        for _ in range(256):
            output = vm.call(0x456ee0)
            sequence.append({'output': output, 'state': vm.read_u32(TLS + 0x14)})
        rng_sequences.append({'seed': seed, 'sequence': sequence})
    ranges = [-2147483648, -32001, -100, -2, -1, 0, 1, 2, 3, 30, 100, 31999, 32000, 32001, 2147483647]
    scaled = []
    for seed in [0, 1, 2002, 0xffffffff]:
        for value in ranges:
            vm.write_i32(TLS + 0x14, seed)
            output = vm.call(0x415a20, arguments(value))
            scaled.append({'seed': seed, 'range': value, 'expected': output, 'state': vm.read_u32(TLS + 0x14)})
    save(ROOT / 'tests/fixtures/original-core.json', {'provenance': provenance, 'wrapDegreesOnce': wraps, 'speedDivisor': speed_cases, 'rng': rng_sequences, 'scaledRandom': scaled})
    # Capture the original startup-generated integer lookup tables rather than
    # substituting browser sin/cos and assuming their rounded outputs agree.
    vm.call(0x415a60)
    sine = [vm.read_i32(0x4a54a0 + i * 4) for i in range(362)]
    cosine = [vm.read_i32(0x4a3450 + i * 4) for i in range(362)]
    save(ROOT / 'assets/data/trig-tables.json', {'provenance': provenance, 'generator': '0x415a60', 'sine_address': '0x4a54a0', 'cosine_address': '0x4a3450', 'sine': sine, 'cosine': cosine})
    winds = []
    cases = [(angle, wind, speed) for angle in range(362) for wind, speed in [(0,0), (17,52), (5,100), (30,0)]]
    cases += [(prng.randrange(362), prng.randrange(41), prng.randrange(200)) for _ in range(512)]
    for n, (angle, wind, speed) in enumerate(cases):
        boat = 1 + n % 30
        vm.write_i32(0x4a7bc8 + boat*4, angle)
        vm.write_i32(0x4a6338 + boat*4, wind)
        pressure = vm.call(0x429df0, arguments(speed, boat), floating=True)
        winds.append({'speedTenths': speed, 'boat': boat, 'angle': angle, 'trueWind': wind,
                      'expected': {'pressure': pressure['value'], 'pressureBits': pressure['bits'],
                                   'apparentWindKnots': vm.read_i32(0x4ab9e8 + boat*4),
                                   'apparentWindAngle': vm.read_i32(0x4a47f8 + boat*4)}})
    save(ROOT / 'tests/fixtures/original-apparent-wind.json', {'provenance': provenance, 'cases': winds})
    sailing = {'provenance': provenance, 'updateTack': [], 'spinnakerAnglePenalty': [],
               'scheduleWindShift': [], 'setClosehauledHeading': []}
    tack_pairs = [(h,w) for h in [-2147483648,-181,-180,-1,0,1,179,180,181,359,360,2147483647]
                        for w in [-2147483648,-180,0,180,359,2147483647]]
    tack_pairs += [(prng.randrange(-2147483648,2147483648),prng.randrange(-2147483648,2147483648)) for _ in range(256)]
    for n,(heading, direction) in enumerate(tack_pairs):
        boat = 1+n%30
        vm.write_i32(0x4ac018+boat*4,heading)
        vm.write_i32(0x4aa5b0+boat*4,direction)
        result = vm.call(0x4255b0,arguments(boat))
        sailing['updateTack'].append({'boat':boat,'heading':heading,'windDirection':direction,
            'expected':{'tack':vm.read_i32(0x4aa730+boat*4),'returnValue':i32(result)}})
    penalty_pairs = [(angle,threshold) for threshold in [-2147483648,-1,0,8,90,150,2147483647]
                     for angle in [-2147483648, i32(threshold-9),i32(threshold-8),i32(threshold-1),threshold,i32(threshold+1),2147483647]]
    penalty_pairs += [(prng.randrange(362),prng.randrange(40,181)) for _ in range(256)]
    for n,(angle,threshold) in enumerate(penalty_pairs):
        boat=1+n%30
        vm.write_i32(0x4a7bc8+boat*4,angle)
        vm.write_i32(0x4ab180,threshold)
        result=vm.call(0x42a280,arguments(boat))
        sailing['spinnakerAnglePenalty'].append({'boat':boat,'angle':angle,'threshold':threshold,
            'expected':{'penalty':vm.read_i32(0x4ac5f0+boat*4),'returnValue':i32(result)}})
    for n in range(320):
        ti=[0,1,299,300,301][n%5]
        pi=[1,300,299,301,0][n%5]
        rt=prng.randrange(-2147483648,2147483648) if n<32 else prng.randrange(101)
        rp=rt if ti==pi else prng.randrange(101)
        center=prng.randrange(-2147483648,2147483648) if n<32 else prng.randrange(-90,91)
        spread=prng.randrange(-2147483648,2147483648) if n<32 else prng.randrange(101)
        period=prng.randrange(-2147483648,2147483648) if n<32 else prng.randrange(301)
        time=prng.randrange(-2147483648,2147483648) if n<32 else prng.randrange(-300,3601)
        vm.write_i32(0x4911c4,ti)
        vm.write_i32(0x4911c8,pi)
        vm.write_i32(0x4a5b80,time)
        vm.write_i32(0x4a9450+ti*4,rt)
        vm.write_i32(0x4a9450+pi*4,rp)
        result=vm.call(0x41ba60,arguments(center,spread,period))
        sailing['scheduleWindShift'].append({'center':center,'range':spread,'period':period,'time':time,
            'targetIndex':ti,'timeIndex':pi,'targetRandom':rt,'timeRandom':rp,
            'expected':{'target':vm.read_i32(0x4ac9e8),'nextTime':vm.read_i32(0x4abae4),
                'targetIndex':vm.read_i32(0x4911c4),'timeIndex':vm.read_i32(0x4911c8),'returnValue':i32(result)}})
    close_inputs=[]
    for boat_class in range(1,16):
        for wind in [-2147483648,-9,-1,0,7,8,10,11,17,2147483647]:
            for catamaran,board,sport in [(0,0,0),(1,0,0),(0,1,0),(0,0,1)]:
                close_inputs.append((boat_class,wind,catamaran,board,sport))
    for n,(boat_class,wind,catamaran,board,sport) in enumerate(close_inputs):
        boat=1+n%3
        offset=prng.randrange(-20,21)
        direction=prng.randrange(360)
        tack=-1 if n%2 else 1
        previous=prng.randrange(-2147483648,2147483648)
        for addr,value in [(0x4a6338+boat*4,wind),(0x4ac1e8+boat*4,offset),(0x4aa5b0+boat*4,direction),
                           (0x4aa730+boat*4,tack),(0x491188,boat_class),(0x4ac900,catamaran),
                           (0x4ac904,board),(0x4ac908,sport),(0x4a52e8,previous)]:
            vm.write_i32(addr,value)
        result=vm.call(0x4269d0,arguments(boat))
        sailing['setClosehauledHeading'].append({'boat':boat,'wind':wind,'offset':offset,'windDirection':direction,
            'tack':tack,'boatClass':boat_class,'twinHullFlag':catamaran,'boardFlag':board,'planingFlag':sport,
            'previousAngle':previous,'expected':{'heading':vm.read_i32(0x4ac018+boat*4),
                'angle':vm.read_i32(0x4a52e8),'returnValue':i32(result)}})
    save(ROOT / 'tests/fixtures/original-sailing-helpers.json',sailing)
    p=struct.unpack('<d',vm.uc.mem_read(0x484ed8,8))[0]
    radians=[0.0,-0.0,p,-p,2*p,-2*p,3*p,-3*p,
             math.nextafter(p,-math.inf),math.nextafter(p,math.inf),
             math.nextafter(-p,-math.inf),math.nextafter(-p,math.inf),
             1e-300,-1e-300,1e300,-1e300]
    radians += [prng.uniform(-100,100) for _ in range(512)]
    radian_cases=[]
    for value in radians:
        raw=struct.pack('<d',value)
        result=vm.call(0x413cd0,raw,floating=True)
        radian_cases.append({'input':value,'inputBits':raw.hex(),'expected':result['value'],'bits':result['bits']})
    points=[(x,y) for x in [-2147483648,-100,-1,0,1,100,2147483647]
                  for y in [-2147483648,-100,-1,0,1,100,2147483647]]
    points += [(prng.randrange(-2147483648,2147483648),prng.randrange(-2147483648,2147483648)) for _ in range(4096)]
    bearings=[{'param1':x,'param2':y,'expected':i32(vm.call(0x41bb10,arguments(x,y)))} for x,y in points]
    save(ROOT / 'tests/fixtures/original-angles.json',{'provenance':provenance,'wrapRadiansOnce':radian_cases,'bearingFromVector':bearings})
    option_inputs={'selector':0x491144,'lengthOverride':0x4ac918,'displacementOverride':0x4ac91c,
        'sailAreaOverride':0x4ac920,'sailPercentOverride':0x4ac924,'boatClass':0x491188,
        'length':0x4a5ba4,'rig':0x49114c,'course':0x491194,'offshoreCourseFlag':0x4ac990}
    option_outputs={'boatClass':0x491188,'length':0x4a5ba4,'rig':0x49114c,'course':0x491194,
        'offshoreCourseFlag':0x4ac990,'displacement':0x4a4eec,'sailArea':0x4a5b90,'sailPercent':0x491150,
        'catamaranFlag':0x4ac900,'boardFlag':0x4ac904,'sportBoatFlag':0x4ac908,'skiffFlag':0x4ac90c,
        'jy15Flag':0x4ac910,'optimistFlag':0x4ac914}
    configurations=[]
    for selector in range(1,16):
        for length_override in [0,19,20,25,40,50,51]:
            for displacement in [-1,8,11,12]:
                configurations.append((selector,6,25,length_override,displacement))
    for selector in [-1,0,16]:
        for boat_class in range(12):
            for old_length in [11,17,37]:
                for length_override in [19,20,50,51]:
                    configurations.append((selector,boat_class,old_length,length_override,10))
    option_cases=[]
    calibration={}
    for n,(selector,boat_class,old_length,length_override,displacement) in enumerate(configurations):
        inputs={'selector':selector,'lengthOverride':length_override,'displacementOverride':displacement,
            'sailAreaOverride':[-1,7,8,9,10,11,12][n%7],'sailPercentOverride':[-2147483648,-1,0,80,123,2147483647][n%6],
            'boatClass':boat_class,'length':old_length,'rig':[-1,0,1,2][n%4],
            'course':[1,8,11][n%3],'offshoreCourseFlag':n%3}
        for key,addr in option_inputs.items():
            vm.write_i32(addr,inputs[key])
        result=vm.call(0x417790)
        expected={key:vm.read_i32(addr) for key,addr in option_outputs.items()}
        factor_raw=bytes(vm.uc.mem_read(0x4ab0c0,8))
        expected.update(timeFactor=struct.unpack('<d',factor_raw)[0],timeFactorBits=factor_raw.hex(),returnValue=i32(result))
        option_cases.append({'inputs':inputs,'expected':expected})
        calibration[str(expected['length'])]={'value':expected['timeFactor'],'bits':expected['timeFactorBits']}
    for length in range(20,51):
        vm.write_i32(0x491144,12)
        vm.write_i32(0x4ac918,length)
        vm.call(0x417790)
        raw=bytes(vm.uc.mem_read(0x4ab0c0,8))
        calibration[str(length)]={'value':struct.unpack('<d',raw)[0],'bits':raw.hex()}
    save(ROOT / 'tests/fixtures/original-boat-options.json',{'provenance':provenance,'inputs':option_inputs,'outputs':option_outputs,'cases':option_cases})
    save(ROOT / 'assets/data/boat-calibration.json',{'provenance':provenance,'routine':'0x417790','formula':'sqrt(15 / integer boat length), x87 intermediate then binary64 store','lengths':calibration})
    print(f'Captured {len(wraps)} angle cases, {len(speed_cases)} speed cases, 1536 RNG outputs, {len(scaled)} scaled random cases, 362 trig pairs, {len(winds)} wind cases')
    print('Captured sailing helpers: '+', '.join(f'{name}={len(values)}' for name,values in sailing.items() if name!='provenance'))
    print(f'Captured {len(radian_cases)} radian cases and {len(bearings)} vector bearings')
    print(f'Captured {len(option_cases)} boat-option cases and {len(calibration)} boat-length calibrations')

if __name__ == '__main__':
    main()
