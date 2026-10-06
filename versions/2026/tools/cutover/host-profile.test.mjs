import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {Float80,withX87ControlWord} from '../../../../src/runtime/float80.js';
import {configurePaintDimensions} from '../../../2010-en/src/render/paint-lifecycle.js';
import {configureCanonicalProfile} from '../../app/engine/compatibility/host-profile.ts';
const source=await readFile(new URL('../../../2010-en/runtime/Tactics2010EnglishPreserved.exe',import.meta.url));

test('surface-free canonical host calibration matches native dimension stores and numeric spills',()=>withX87ControlWord(0x027f,()=>{
  for(const width of[600,800,801,1024,1280,1600])for(const height of[600,768,900]){
    const a=loadPE32(source),b=loadPE32(source),profile={width,height,bitsPixel:24,applicationInstance:0xdeadbeef};
    const expected=configurePaintDimensions(a,profile);
    const actual=configureCanonicalProfile(b,{integer:Float80.fromInteger,number:Float80.fromNumber},profile);
    assert.deepEqual(actual,expected);assert.deepEqual(b.bytes,a.bytes);
  }
}));
