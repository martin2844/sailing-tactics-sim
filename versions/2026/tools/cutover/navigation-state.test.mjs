import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {targetRelativeBearing} from '../../../2010-en/src/engine/ai-geometry.js';
import {distanceToBoat} from '../../../2010-en/src/engine/movement.js';
import {createEngineBindings} from '../../../2010-en/src/engine/port.js';
import {createOriginalRenderer} from '../../../2010-en/src/render/index.js';
import {originalDrawing00440350} from '../../../2010-en/src/render/drawing-functions.js';
import {GdiTrace} from '../../../2010-en/src/render/gdi.js';
import {updateNavigationState} from '../../app/engine/compatibility/navigation-state.ts';
const source=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const shore=JSON.parse(await readFile(new URL('../../../2010-en/assets/data/initial-shoreline-stack.json',import.meta.url)));
const numeric={number:Float80.fromNumber,distance:distanceToBoat,bearing:(m,x,y,boat)=>targetRelativeBearing(m,x,y,0,boat)};
const options={...createEngineBindings(),...createOriginalRenderer({initialShoreStack:shore})};
function image(clock,kind,gate,rounding,fleet,venue){const m=loadPE32(source);
 for(const[a,v]of[[0x4f8cd0,clock],[0x4fbf14,kind],[0x536408,gate],[0x53527c,rounding],[0x4da194,fleet],[0x4da1f8,venue],[0x536410,0],[0x536414,0],[0x4fb51c,45],[0x4fb520,135],[0x4fb524,225],[0x4fb534,900],[0x4fb538,600],[0x4fb53c,300],[0x4da1cc,6],[0x4da1e4,9],[0x4f853c,9],[0x4fe2b4,1],[0x4da188,1],[0x4da1e8,gate],[0x5363f8,1],[0x5229c8,100],[0x522ac4,200],[0x5117b0,900],[0x511d30,900],[0x5117bc,800],[0x511d3c,800],[0x5117c4,700],[0x511d44,700]])m.writeI32(a,v);
 m.writeF64(0x4f6b00,-100);m.writeF64(0x4f6c18,-100);return m;}
test('navigation selector matches recovered target classification and all image stores across course gates',()=>withX87ControlWord(0x027f,()=>{
 for(const clock of[-10,0,29,30,100])for(const kind of[0,1,2,3,4])for(const gate of[0,1])for(const rounding of[0,1])for(const fleet of[5,20])for(const venue of[0,5]){
  const a=image(clock,kind,gate,rounding,fleet,venue),b=image(clock,kind,gate,rounding,fleet,venue);
  const expected=originalDrawing00440350(a,new GdiTrace(),undefined,options,1),actual=updateNavigationState(b,numeric,1);
  assert.equal(actual,expected);assert.deepEqual(b.bytes,a.bytes);
 }
 // Deliberately cross bearing-advance and near-mark/island thresholds.
 for(const bearing of[45,135,225])for(const radius of[1,59,99,100,101,299,600,900])for(const gate of[0,1])for(const rounding of[0,1])for(const venue of[0,5]){
  const a=image(100,1,gate,rounding,5,venue),b=image(100,1,gate,rounding,5,venue);
  for(const m of[a,b]){m.writeF64(0x4f6b00,Math.sin(bearing*Math.PI/180)*radius);m.writeF64(0x4f6c18,-Math.cos(bearing*Math.PI/180)*radius);
   m.writeI32(0x5229c8,Math.round(m.readF64(0x4f6b00)+radius));m.writeI32(0x522ac4,Math.round(m.readF64(0x4f6c18)));
   m.writeI32(0x5117b0,Math.round(m.readF64(0x4f6b00)));m.writeI32(0x511d30,Math.round(m.readF64(0x4f6c18)));
  }
  assert.equal(updateNavigationState(b,numeric,1),originalDrawing00440350(a,new GdiTrace(),undefined,options,1));assert.deepEqual(b.bytes,a.bytes);
 }
}));
