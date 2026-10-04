import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {sinCosX87} from '../../../src/runtime/transcendentals.js';
import {originalDrawing0043ec20} from '../src/render/drawing-functions.js';
import {tryProjectChartPointOutputFast} from '../src/render/chart-output-fast.js';
import {cAdd,cDiv,cI32} from '../src/render/typed-c.js';
import '../src/render/index.js';

const executable=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const originalOptions={numberRendering:false,retainedDrawingStack:{[0x43ec20]:[]}};
const number=Float80.fromNumber;
function originalPoint(memory,x,y,selector,camera,scale,centerX,centerY,clampDistance){
  const angle=originalDrawing0043ec20(memory,null,null,originalOptions,number(x),number(y),selector,camera);
  if(clampDistance&&memory.readF64(0x4ccd88)<memory.readF64(0x4fbb88)){
    memory.writeI32(0x4fbb88,0);memory.writeI32(0x4fbb8c,0x40d86a00);
  }
  const trig=sinCosX87(angle),distance=number(memory.readF64(0x4fbb88));
  let column=trig.sine.multiply(number(scale)).multiply(distance).add(Float80.fromInteger(centerX));
  let row=Float80.fromInteger(centerY).subtract(trig.cosine.multiply(number(scale)).multiply(distance));
  let storedColumn=column.toNumber();
  const upper=number(memory.readF64(0x4ccd78)),lower=number(memory.readF64(0x4ccd80));
  if(upper.compare(column)<0)storedColumn=10000;
  if(storedColumn<lower.toNumber())storedColumn=-10000;
  if(upper.compare(row)<0)row=upper;
  if(row.compare(lower)<0)row=lower;
  return {x:number(storedColumn).truncI32(),y:row.truncI32()};
}

test('chart integer and clamp boundary certificates retain complete output images or untouched fallback',t=>withX87ControlWord(0x027f,()=>{
  const candidate=loadPE32(executable),original=loadPE32(executable);
  let accepted=0,declined=0;
  const x=.125,y=-1000,centerX=333,centerY=277;
  for(const memory of [candidate,original]){
    memory.writeF64(0x4f6b00,0);memory.writeF64(0x4f6c18,0);
    memory.writeI32(0x536410,0);memory.writeI32(0x536414,0);
    memory.writeF64(0x4ccd88,1000);
  }
  for(const selector of [-3,-1,0,1,2,3])for(const heading of [0,359])for(const mode of [0,3]){
    for(const memory of [candidate,original]){
      memory.writeI32(0x4fbb94,heading);memory.writeI32(0x525a7c,mode);
    }
    // This is only input generation. The result oracle below remains the
    // unchanged byte-translated bearing and original m80 coordinate algebra.
    const bearing=Math.atan2(x,-y),headingRadians=heading*candidate.readF64(0x4cc568);
    const angle=selector!==0&&selector<3
      ?selector===-1||((selector===1||selector===2)&&mode===0)?bearing-headingRadians:x
      :bearing;
    for(const clampDistance of [false,true])for(const axis of ['x','y']){
      const distance=clampDistance?25000:Math.sqrt(x*x+y*y);
      const denominator=(axis==='x'?Math.sin(angle):-Math.cos(angle))*distance;
      for(const target of [-10000,-1,0,1,10000])for(const delta of [-(2**-20),0,2**-20]){
        const scale=(target+delta-(axis==='x'?centerX:centerY))/denominator;
        const args=[x,y,selector,1,scale,centerX,centerY,clampDistance];
        const before=Buffer.from(candidate.bytes);
        const actual=tryProjectChartPointOutputFast(candidate,...args);
        if(actual===undefined){
          assert.deepEqual(Buffer.from(candidate.bytes),before,'declined chart windows perform no image writes');
          declined++;continue;
        }
        original.writeBytes(original.base,before);
        assert.deepEqual(actual,originalPoint(original,...args),`chart ${selector}/${heading}/${mode}/${axis}/${target+delta}`);
        assert.deepEqual(Buffer.from(candidate.bytes),Buffer.from(original.bytes),'certified windows preserve the complete global image');
        accepted++;
      }
    }
  }
  assert.ok(accepted>0&&declined>0,'integer boundaries cover accepted certificates and clean declines');
  t.diagnostic(JSON.stringify({cases:accepted+declined,accepted,declined}));
}));

test('reference windows preserve the full FTOL64 coordinate needed before a later division',()=>withX87ControlWord(0x027f,()=>{
  const candidate=loadPE32(executable),original=loadPE32(executable);
  for(const memory of [candidate,original]){
    memory.writeF64(0x4f6b00,0);memory.writeF64(0x4f6c18,0);
    memory.writeF64(0x4ccd78,2**32+1000);memory.writeF64(0x4ccd80,2**32);
  }
  const before=Buffer.from(candidate.bytes),args=[.125,-1,0,1,0,0,0];
  assert.equal(tryProjectChartPointOutputFast(candidate,...args,false),undefined);
  assert.deepEqual(Buffer.from(candidate.bytes),before,'the wide reference coordinate keeps the complete original window');
  // 468440 retains this reference row as TStack_34, later copies it to TVar6,
  // and divides by twenty in the venue102/param7=5 branch before taking I32.
  const originalFullCoordinate=number(original.readF64(0x4ccd80)).truncI64();
  assert.equal(originalFullCoordinate,2n**32n);
  assert.equal(cI32(cDiv(cAdd(originalFullCoordinate,0),20)),214748364);
  assert.equal(cI32(cDiv(cAdd(BigInt(Number(originalFullCoordinate)|0),0),20)),0);
  // The loop window consumes I32 pixels directly, so the same low-DWORD
  // conversion remains valid there even when the distance does not clamp.
  const actual=tryProjectChartPointOutputFast(candidate,...args,true);
  assert.deepEqual(actual,{x:-10000,y:0});
  assert.deepEqual(actual,originalPoint(original,...args,true));
  assert.deepEqual(Buffer.from(candidate.bytes),Buffer.from(original.bytes));
}));
