import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {loadPE32} from '../../../src/runtime/memory.js';
import {originalDrawing00482ae0} from '../src/render/drawing-functions.js';
import {GdiTrace} from '../src/render/gdi.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const generated=await readFile(new URL('../src/render/drawing-functions.js',import.meta.url),'utf8');
const corrected=await readFile(new URL('../analysis/drawing-corrections/00482ae0.c',import.meta.url),'utf8');
const evidence=JSON.parse(await readFile(new URL('../analysis/sail-graphic-word-store-review.json',import.meta.url)));
const hash=bytes=>createHash('sha256').update(bytes).digest('hex');

test('all five sail graphic partial assignments retain the original DWORD storage operation',()=>{
  assert.equal(hash(source),evidence.sourceSha256);
  assert.equal(hash(corrected),evidence.sourcePins['analysis/drawing-corrections/00482ae0.c']);
  assert.equal(evidence.instructions.length,5);
  const original=loadPE32(source);
  for(const row of evidence.instructions){
    assert.equal(row.storeBytes,4);
    assert.match(row.instruction,/^mov dword ptr \[esp \+ 0x[0-9a-f]+\], [a-z]+$/);
    assert.equal(Buffer.from(original.readBytes(Number(row.address),row.bytes.length/2)).toString('hex'),row.bytes);
  }
  assert.equal((corrected.match(/local_(?:180|190|1a8)\._0_4_\s*=/g)||[]).length,5);
  assert.doesNotMatch(corrected,/CONCAT44\(local_(?:180|190|1a8)\._4_4_/);
  // This aliased frame stays byte-addressable in both generated variants;
  // retained stack images route through the complete Original body.
  for(const suffix of ['Original','Number']){
    const marker=`function originalDrawing00482ae0${suffix}(`;
    const start=generated.indexOf(marker);
    assert.ok(start>=0,marker);
    const end=generated.indexOf('\n}\n',start);
    const body=generated.slice(start,end);
    for(const pc of [10,11,71,75,95]){
      const statement=body.match(new RegExp(`case ${pc}: \\{ ([^\\n]+)`))?.[1];
      assert.ok(statement,`${suffix} case ${pc}`);
      assert.match(statement,/^writePointer\(memory,pointerAdd\(framePointer\(localFrame,(?:256|280|296)\),0\),/);
      assert.match(statement,/,4\); pc = /);
      assert.doesNotMatch(statement,/wordsAsF64Number|bitsAsF64|writeLocalFloatNumber/);
    }
    assert.match(body,/writeLocal(?:FloatNumber)?\(framePointer\(localFrame,256\),/,
      'initial real floating arithmetic remains a floating store');
  }
});

test('sail graphic correction retains strict invalid floating argument failures',()=>{
  for(const options of [{},{numberRendering:false},{smoothGraphics:true},
    {retainedDrawingStack:{[0x482ae0]:[]}}])for(const size of [NaN,Infinity,-Infinity]){
    const dc=new GdiTrace(),memory=loadPE32(source);
    assert.throws(()=>originalDrawing00482ae0(memory,dc,null,options,0,-2000,size,90,.5,25,.8,1),
      /Float80 does not support NaN or infinite inputs/);
    assert.deepEqual(dc.events,[]);
  }
});
