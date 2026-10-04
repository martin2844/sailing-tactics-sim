import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {originalDrawing0043e730} from '../src/render/drawing-functions.js';
import {tryProjectionGeometry} from '../src/render/projection-fast.js';
import {tryProjectScenePointOutputFast} from '../src/render/projection-output-fast.js';
import '../src/render/index.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const originalOptions={numberRendering:false,retainedDrawingStack:{[0x43e730]:[],[0x43ea10]:[],[0x43eb00]:[]}};
const image=memory=>Buffer.from(memory.bytes);

function setup(memory,heading,mode){
  for(const [address,value]of [[0x4f71c4,mode],[0x4fbb94,heading],[0x4da148,200],[0x4f4b48,240],
    [0x4fe2a8,734],[0x4f40a8,512]])memory.writeI32(address,value);
  for(const address of [0x4f6b00,0x4f6c18])memory.writeF64(address,0);
  memory.writeF64(0x5259d0,1);
}

test('output certificates preserve whole-memory images around angular, clamp and perspective boundaries',t=>withX87ControlWord(0x027f,()=>{
  const actual=loadPE32(source),original=loadPE32(source);
  let accepted=0,declined=0;
  const directions=[-180,-131,-130,-129,-90,-89,-1,0,1,89,90,129,130,131,180];
  const offsets=[-(2**-36),0,2**-36];
  for(const heading of [0,179,359])for(const mode of [1,2])for(const selector of [0,5]){
    setup(actual,heading,mode);setup(original,heading,mode);
    const geometry=tryProjectionGeometry(actual,0,0,1);
    assert.ok(geometry);
    const selectedDirections=selector===0?directions:[-91,-90,-89,-81,-80,-79,-71,-70,-69,69,70,71,79,80,81,89,90,91];
    for(const direction of selectedDirections)for(const offset of offsets)for(const radius of [9.999999999,10,50,1534.375]){
      const radians=(heading+direction+offset)*Math.PI/180;
      const x=geometry.origin.x+Math.sin(radians)*radius;
      const y=geometry.origin.y-Math.cos(radians)*radius;
      const before=image(actual);
      if(tryProjectScenePointOutputFast(actual,0,x,y,1,selector)!==true){
        assert.deepEqual(image(actual),before,'a declined certificate leaves every image byte unchanged');
        declined++;
        continue;
      }
      // Align earlier accepted output cells before the independent complete
      // original call; this call must then produce the same entire image.
      original.writeBytes(original.base,before);
      originalDrawing0043e730(original,null,null,originalOptions,0,Float80.fromNumber(x),Float80.fromNumber(y),1,selector);
      assert.deepEqual(image(actual),image(original),`heading=${heading}, mode=${mode}, selector=${selector}, direction=${direction+offset}, radius=${radius}`);
      accepted++;
    }
  }
  assert.ok(accepted>0,'the boundary corpus exercises accepted certificates');
  assert.ok(declined>0,'the boundary corpus exercises untouched fallbacks');
  t.diagnostic(JSON.stringify({cases:accepted+declined,accepted,declined}));
}));
