import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { createRawTrig } from '../src/engine/terrain.js';
import { targetRelativeBearing } from '../src/engine/target-bearing.js';
import { updateBoatWindAndAI } from '../src/engine/ai.js';
import { saveRaceState, restoreRaceState } from '../src/engine/snapshots.js';
import { nearCourseMark, updatePlayer1Camera, updatePlayer2Camera, projectedSize, cameraRelativeBearing, projectDistantPoint, projectScenePoint } from '../src/render/projection.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const [tables, extended, stored, force, hull, raw, ...fixtures] = await Promise.all([
  json('../assets/data/trig-tables.json'), json('../assets/data/x87-trig.json'),
  json('../assets/data/x87-stored-trig.json'), json('../assets/data/x87-force-trig.json'),
  json('../assets/data/x87-hull-trig.json'), json('../assets/data/x87-raw-trig.json'),
  ...['original-target-bearing.json', 'original-snapshots.json', 'original-ai-coordinator.json', 'original-projection.json'].map(name => json(`./fixtures/${name}`)),
]);
const reference = { trig: createCapturedTrig(extended, stored, force), hullTrig: createHullTrig(hull), rawTrig: createRawTrig(raw) };
const routines = { targetRelativeBearing, updateBoatWindAndAI, saveRaceState, restoreRaceState, nearCourseMark, updatePlayer1Camera, updatePlayer2Camera, projectedSize, cameraRelativeBearing, projectDistantPoint, projectScenePoint };
const hash = data => createHash('sha256').update(data).digest('hex');

for (const fixture of fixtures) {
  assert.equal(fixture.provenance.sha256, hash(original));
  for (const [name, group] of Object.entries(fixture.routines)) test(`${name}: original complete state, RNG, sounds and declared return (${group.cases.length} cases)`, () => {
    const memory = loadPE32(original);
    for (const [base, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine]]) values.forEach((value, index) => memory.writeI32(base + index * 4, value));
    const { address: base, size } = fixture.mutableBlock;
    const baseline = memory.readBytes(base, size);
    const failures = [];
    for (const [index, row] of group.cases.entries()) {
      memory.writeBytes(base, baseline);
      for (const patch of row.imageInputs) memory.writeBytes(patch.address, new Uint8Array(Buffer.from(patch.bits, 'hex')));
      const expected = memory.readBytes(base, size);
      for (const change of row.expected.imageChanges) {
        assert.equal(Buffer.from(expected.slice(change.address-base, change.address-base+change.before.length/2)).toString('hex'), change.before);
        expected.set(Buffer.from(change.after, 'hex'), change.address-base);
      }
      assert.equal(hash(expected), row.expected.mutableBlockHash);
      const rng = new PoseyRng(row.seedAtCall), sounds = [];
      const options = { ...reference, rng, playSound: event => { sounds.push(event); return 1; } };
      try {
        const returned = name === 'updateBoatWindAndAI' ? routines[name](memory, ...row.arguments, rng, options) : routines[name](memory, ...row.arguments, options);
        if (group.returnType === 'F64' || group.returnType === 'Float80') {
          const binary64 = Buffer.alloc(8); binary64.writeDoubleLE(returned.toNumber());
          if (binary64.toString('hex') !== row.expected.returnValue.bits) failures.push({ index, returnBits: binary64.toString('hex'), expected: row.expected.returnValue.bits });
          if (Buffer.from(returned.toBytes()).toString('hex') !== row.expected.returnValue.extendedBits) failures.push({ index, extendedReturn: Buffer.from(returned.toBytes()).toString('hex'), expected: row.expected.returnValue.extendedBits });
        }
        if (group.returnType === 'I32' && returned !== row.expected.returnValue) failures.push({ index, returned, expected: row.expected.returnValue });
      } catch (error) { failures.push({ index, error: error.message }); continue; }
      const actual = memory.readBytes(base, size), offset = actual.findIndex((value, at) => value !== expected[at]);
      if (offset >= 0) failures.push({ index, address: `0x${(base+offset).toString(16)}`, actual: Buffer.from(actual.slice(offset,offset+16)).toString('hex'), expected: Buffer.from(expected.slice(offset,offset+16)).toString('hex') });
      if (rng.state !== row.expected.rngState) failures.push({ index, rng: rng.state, expected: row.expected.rngState });
      if (JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) failures.push({ index, sounds, expected: row.expected.sounds });
    }
    assert.equal(failures.length, 0, `${failures.length} mismatches; first: ${JSON.stringify(failures.slice(0, 12))}`);
  });
}
