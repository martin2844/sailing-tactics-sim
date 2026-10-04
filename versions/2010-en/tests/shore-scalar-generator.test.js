import test from 'node:test';
import assert from 'node:assert/strict';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {pythonCommand} from '../../../tools/python-command.js';
import {createLocalFrame,framePointer,writeLocalPoint,readLocal,readLocalArgument} from '../src/render/typed-c.js';

test('shore private scalar generation proves array induction and actual callee alias contracts',()=>{
  const root=fileURLToPath(new URL('../../../',import.meta.url));
  execFileSync(pythonCommand,[
    fileURLToPath(new URL('shore-scalar-generator.py',import.meta.url)),
  ],{cwd:root,encoding:'utf8',stdio:'pipe'});
});

test('the actual POINT output callee writes exactly eight bytes and preserves its aliased cells',()=>{
  const frame=createLocalFrame(920),point={x:0xffffffff,y:-0x80000001};
  assert.equal(writeLocalPoint(framePointer(frame,328),point),point);
  assert.equal(readLocal(framePointer(frame,328),4,'int'),-1);
  assert.equal(readLocal(framePointer(frame,332),4,'int'),0x7fffffff);
  for(const offset of [0,4,8,256,260,264,268,272,276,280,324,336]){
    assert.equal(readLocalArgument(framePointer(frame,offset),4,'int'),undefined);
  }
});
