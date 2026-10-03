import assert from 'node:assert/strict';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { PoseyRng } from '../../../src/engine/integer-core.js';
import { resetOriginalCStringContents,readCString,writeCString } from '../src/render/text.js';

export const sha256=bytes=>createHash('sha256').update(bytes).digest('hex');

export function assertNativeProvenance(source,fixture) {
  assert.equal(fixture.sourceSha256,sha256(source));
  assert.equal(fixture.provenance.sha256,sha256(source));
  assert.equal(fixture.provenance.engine,'Original x86 code under Wine; no text edits');
  assert.equal(fixture.provenance.x87ControlWord,'0x027f');
  assert.equal(fixture.provenance.loadedOriginalTextUnchanged,true);
  assert.equal(fixture.provenance.originalFileUnchanged,true);
  const baseline=Buffer.from(fixture.mutableBaseline,'hex');
  assert.equal(sha256(baseline),fixture.provenance.mutableBaselineSha256);
  assert.equal(baseline.length,fixture.mutableBlock.size);
  return baseline;
}

/** Strict complete mutable-image reference check, including preserved bytes. */
export function createNativeHarness(source,fixture) {
  const memory=loadPE32(source),baseline=assertNativeProvenance(source,fixture);
  const base=fixture.mutableBlock.address,rng=new PoseyRng();
  return {
    memory,rng,
    check(row,index,invoke) {
      if(!row.continue){memory.writeBytes(base,baseline);resetOriginalCStringContents(memory);}
      if('seed' in row||!row.continue)rng.srand(row.seed??1);
      for(const [field,value]of Object.entries(row.inputs??{}))memory.writeI32(fixture.integerInputs[field],value);
      for(const [field,value]of Object.entries(row.doubleInputs??{}))memory.writeF64(fixture.doubleInputs[field],value);
      for(const patch of row.patches??[])memory.writeBytes(patch.address,Buffer.from(patch.bytes,'hex'));
      for(const string of row.strings??[])writeCString(memory,string.address,new TextDecoder('windows-1252').decode(Buffer.from(string.bytes,'hex')));
      const before=memory.readBytes(base,baseline.length),expected=before.slice();
      for(const change of row.expected.imageChanges){
        const offset=change.address-base,width=change.before.length/2;
        assert.equal(Buffer.from(before.subarray(offset,offset+width)).toString('hex'),change.before,`case${index}:native before bytes`);
        expected.set(Buffer.from(change.after,'hex'),offset);
      }
      const prefix=memory.readBytes(memory.base,base-memory.base);
      const suffix=memory.readBytes(base+baseline.length,memory.size-(base-memory.base)-baseline.length);
      const returned=withX87ControlWord(0x027f,()=>invoke(memory,rng,row.arguments??[]));
      const routine=row.routine??fixture.routine;
      if(routine.returnType==='I32'||routine.residualEAX)assert.equal(returned>>>0,row.expected.eax,`case${index}:EAX`);
      if(routine.returnType==='float10'){
        assert.equal(Buffer.from(returned.toBytes()).toString('hex'),row.expected.returnExtendedBits,`case${index}:extended return bits`);
        const bytes=Buffer.alloc(8);bytes.writeDoubleLE(returned.toNumber());
        assert.equal(bytes.toString('hex'),row.expected.returnBits,`case${index}:F64 return bits`);
      }
      assert.equal(rng.state,row.expected.rngState,`case${index}:RNG state`);
      for(const string of row.expected.globalStrings??[]){
        const expectedText=new TextDecoder('windows-1252').decode(Buffer.from(string.bytes,'hex'));
        assert.equal(readCString(memory,string.address),expectedText,`case${index}:original CString ${string.address.toString(16)}`);
      }
      for(const [field,address]of Object.entries(fixture.integerOutputs??{}))assert.equal(memory.readI32(address),row.expected.integers[field],`case${index}: ${field}`);
      for(const [field,address]of Object.entries(fixture.doubleOutputs??{}))assert.equal(Buffer.from(memory.readBytes(address,8)).toString('hex'),row.expected.doubles[field],`case${index}: ${field} bits`);
      const actual=memory.readBytes(base,baseline.length);
      assert.equal(sha256(actual),row.expected.mutableSha256,`case${index}:whole mutable SHA256`);
      assert.deepEqual(actual,expected,`case${index}:all mutable bytes`);
      assert.deepEqual(memory.readBytes(memory.base,prefix.length),prefix,`case${index}:outside mutable prefix`);
      assert.deepEqual(memory.readBytes(base+baseline.length,suffix.length),suffix,`case${index}:outside mutable suffix`);
    },
  };
}
