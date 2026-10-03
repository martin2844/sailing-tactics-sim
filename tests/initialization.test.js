import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { initializeRace, initializeBoats, placeStartingBoats, initializeCourseConfiguration, createHullTrig, createRawTrig, initializeCurvedHull, initializeFlatHull } from '../src/engine/initialization.js';
import { initializeCourse } from '../src/engine/course.js';
import { initializeShoreline, initializeEllipse, initializeAdvancedTerrain } from '../src/engine/terrain.js';
import { initializeWind, initializeTide, initializeWindSources, respawnWindPatch } from '../src/engine/wind-initialization.js';
import { integratePositions } from '../src/engine/integration.js';
import { recordTrails } from '../src/engine/trails.js';
import { advanceRaceTarget, projectPoint } from '../src/engine/race-targets.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [fixtures, tables, trigAsset, storedAsset, hullAsset, rawAsset] = await Promise.all([
  json('./fixtures/original-initialization.json'), json('../assets/data/trig-tables.json'), json('../assets/data/x87-trig.json'), json('../assets/data/x87-stored-trig.json'), json('../assets/data/x87-hull-trig.json'), json('../assets/data/x87-raw-trig.json'),
]);
const reference = { trig: createCapturedTrig(trigAsset, storedAsset), hullTrig: createHullTrig(hullAsset), rawTrig: createRawTrig(rawAsset) };
const functions = { initializeRace, initializeBoats, placeStartingBoats, initializeCourseConfiguration, initializeCurvedHull, initializeFlatHull, initializeCourse, initializeShoreline, initializeEllipse, initializeAdvancedTerrain, initializeWind, initializeTide, initializeWindSources, respawnWindPatch, integratePositions, recordTrails, advanceRaceTarget, projectPoint };
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
const bytes = bits => Uint8Array.from(Buffer.from(bits, 'hex'));

function originalMemory() {
  const memory = loadPE32(original);
  for (const [address, values] of [[0x4a54a0, tables.sine], [0x4a3450, tables.cosine], [fixtures.baseline.randomTableAddress, fixtures.baseline.randomTable]]) values.forEach((value, index) => memory.writeI32(address + index * 4, value));
  return memory;
}

test('race initialization references identify unchanged original instructions and bounded state inputs', () => {
  assert.equal(fixtures.provenance.sha256, hash(original));
  assert.match(fixtures.provenance.engine, /Unicorn/);
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.mutableBlock.address, 0x491000);
  assert.equal(fixtures.mutableBlock.size, 0x1d000);
  for (const asset of [tables, trigAsset, storedAsset, hullAsset, rawAsset]) assert.equal(asset.provenance.sha256, fixtures.provenance.sha256);
  assert.ok(Object.values(fixtures.routines).every(routine => routine.cases.length > 0));
});

for (const [name, routine] of Object.entries(fixtures.routines)) test(`${name}: complete original mutable image, RNG, ordered sounds${routine.returnType === 'void' ? '' : ', EAX'} (${routine.cases.length} cases)`, () => {
  const memory = originalMemory();
  const baseline = memory.readBytes(fixtures.mutableBlock.address, fixtures.mutableBlock.size);
  const failures = [];
  for (const [index, row] of routine.cases.entries()) {
    memory.writeBytes(fixtures.mutableBlock.address, baseline);
    for (const input of row.imageInputs) memory.writeBytes(input.address, bytes(input.bits));
    const before = memory.readBytes(fixtures.mutableBlock.address, fixtures.mutableBlock.size);
    const expected = before.slice();
    for (const change of row.expected.imageChanges) {
      assert.equal(Buffer.from(before.slice(change.address - fixtures.mutableBlock.address, change.address - fixtures.mutableBlock.address + change.before.length / 2)).toString('hex'), change.before, `${name} case ${index} recorded input`);
      expected.set(bytes(change.after), change.address - fixtures.mutableBlock.address);
    }
    assert.equal(hash(expected), row.expected.mutableBlockHash, `${name} case ${index} fixture complete-image consistency`);
    const rng = new PoseyRng(row.seedAtCall);
    const sounds = [];
    const options = { ...reference, rng, playSound: event => { sounds.push(event); return 1; } };
    let returned;
    try {
      if (['initializeCurvedHull', 'initializeFlatHull'].includes(name)) returned = functions[name](memory, ...row.arguments, options);
      else if (['initializeCourse', 'respawnWindPatch'].includes(name)) returned = functions[name](memory, row.arguments[0], rng, options);
      else if (['advanceRaceTarget', 'projectPoint'].includes(name)) returned = functions[name](memory, ...row.arguments, options);
      else if (name === 'recordTrails') returned = recordTrails(memory);
      else returned = functions[name](memory, rng, options);
    } catch (error) { failures.push({ index, error: error.message }); continue; }
    const actual = memory.readBytes(fixtures.mutableBlock.address, fixtures.mutableBlock.size);
    const mismatch = actual.findIndex((value, offset) => value !== expected[offset]);
    if (mismatch >= 0) failures.push({ index, address: `0x${(fixtures.mutableBlock.address + mismatch).toString(16)}`, expected: Buffer.from(expected.slice(mismatch, mismatch + 16)).toString('hex'), actual: Buffer.from(actual.slice(mismatch, mismatch + 16)).toString('hex') });
    if (rng.state !== row.expected.rngState) failures.push({ index, rng: rng.state, expectedRng: row.expected.rngState });
    if (JSON.stringify(sounds) !== JSON.stringify(row.expected.sounds)) failures.push({ index, sounds, expectedSounds: row.expected.sounds });
    if (routine.returnType !== 'void' && returned !== row.expected.residualEAX) failures.push({ index, returned, expectedEAX: row.expected.residualEAX });
  }
  assert.equal(failures.length, 0, `${name}: ${failures.length} mismatches; first: ${JSON.stringify(failures.slice(0, 12))}`);
});
