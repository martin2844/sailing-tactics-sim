import assert from 'node:assert/strict';
import test from 'node:test';
import { readFile } from 'node:fs/promises';
import { createNativeHarness } from './native-state.js';
import { updatePlayer1Rudder,updatePlayer1Steering,updatePlayer2Steering } from '../src/engine/steering.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
for(const [file,translate] of [
  ['player1-rudder',updatePlayer1Rudder],['player1-steering',updatePlayer1Steering],['player2-steering',updatePlayer2Steering],
  ['steering-lock-offset',updatePlayer1Rudder],
]){
  const fixture=JSON.parse(await readFile(new URL(`fixtures/original-${file}.json`,import.meta.url),'utf8'));
  test(`${translate.name}: entire original state, RNG, return and ordered sounds`,()=>{
    const harness=createNativeHarness(source,fixture);
    for(const [index,row]of fixture.cases.entries()){
      const sounds=[];
      harness.check(row,index,memory=>translate(memory,{playSound:event=>sounds.push(event)}));
      assert.deepEqual(sounds,row.expected.sounds,`case${index}:ordered original sound requests`);
    }
  });
}
