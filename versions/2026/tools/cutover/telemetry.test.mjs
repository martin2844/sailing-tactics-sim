import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import * as c from '../../../2010-en/src/render/typed-c.js';
import {cStringData} from '../../../2010-en/src/render/text.js';
import {updateSailingTelemetry} from '../../app/engine/telemetry.ts';
const executable=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const drawing=await readFile(new URL('../../../2010-en/src/render/drawing-functions.js',import.meta.url),'utf8');
const a=drawing.indexOf('function originalDrawSailingHudOriginal('),b=drawing.indexOf('function originalDrawSailingHudNumber(',a),section=drawing.slice(a,b);
if(a<0||b<0)throw Error('HUD source boundary moved');
const cases=[...Array.from({length:22},(_,i)=>i+324),396,397,408].map(id=>section.match(new RegExp('    case '+id+': \\{[^\\n]+'))?.[0]);
if(cases.some(v=>!v))throw Error('HUD monitor source moved');
const names=['cI32','cAdd','cSub','cMul','cDiv','cNeg','cBits','cCompare','cTruth','readPointer'];
// Execute the actual recovered warning/sample blocks. Text output between
// these blocks is excluded; numerical branches and stores are unchanged.
const reference=new Function('memory','shift','distance','bearing',...names,'cStringData',`
 const r32=a=>memory.readI32(a),w32=(a,v)=>memory.writeI32(a,cI32(v));
 const framePointer=()=>0,readLocal=()=>1,localFrame=0;
 let TStack_58=shift,TStack_54=Math.abs(shift),local_48=distance,uVar7=bearing>>31,iVar11;
 for(const entry of[408,345]){let pc=entry;
  block:for(;;)switch(pc){case 323:case 395:break block;case 407:pc=397;continue;
   ${cases.join('\n')}
   default:throw Error('Unexpected monitor node '+pc);
  }
 }
`);
test('coach sample/warning gates match actual recovered HUD blocks on both tacks',()=>withX87ControlWord(0x027f,()=>{
 for(const shift of[-20,0,20])for(const tack of[-1,1])for(const angle of[50,55,140,170])for(const bearing of[44,60,80,100,160])for(const distance of[299,500,900]){
  const m=loadPE32(executable);
  for(const[a,v]of[[0x4f8cd0,500],[0x522b94,180+shift],[0x4f7f94,180],[0x522ff4,tack],[0x4feccc,angle],[0x4fe8ac,1],[0x4fae64,35],[0x525a9c,2400],[0x4f853c,1],[0x535744,0],[0x4fb234,0],[0x4f6d2c,0],[0x534e94,0],[0x534ea4,0],[0x4fe768,0],[0x4fb220,0]])m.writeI32(a,v);
  const numeric={number:Float80.fromNumber,distance:()=>Float80.fromNumber(10000),bearing:(image)=>{image.writeI32(0x4f4b40,0);image.writeF64(0x4fbb88,distance);return Float80.fromNumber(bearing).divide(Float80.fromNumber(image.readF64(0x4cc3e8)));}};
  const expected=loadPE32(executable);expected.bytes.set(m.bytes);
  updateSailingTelemetry(m,numeric);
  expected.writeI32(0x535ff4,m.readI32(0x535ff4));
  reference(expected,shift,distance,m.readI32(0x535ff4),...names.map(name=>c[name]),cStringData);
  for(const address of[0x4f6d2c,0x534e94,0x534ea4,0x4fe768,0x4fb220,0x4fb234])assert.equal(m.readI32(address),expected.readI32(address),JSON.stringify({shift,tack,angle,bearing,distance,address}));
 }
}));
