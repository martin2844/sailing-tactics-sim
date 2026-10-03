import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/index.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { Float80 } from '../src/runtime/float80.js';
import { createCapturedTrig, nativeTrig, nativeSineRadians, installNativeTrigReference } from '../src/engine/native-trig.js';
import {
  PENALTY_ADDRESSES, resetBoat, respawnNearStart, shiftPenaltyPosition,
  checkNearRaceMarks, signedStartDistance,
} from '../src/engine/penalties.js';
import {
  ENCOUNTER_GEOMETRY_ADDRESSES, relativeProjection, aheadAstern,
} from '../src/engine/encounter-geometry.js';

const original = await readFile(new URL('../original/Tact02Demo.exe', import.meta.url));
const fixtures = JSON.parse(await readFile(new URL('./fixtures/original-encounter-leaves.json', import.meta.url), 'utf8'));
const captures = JSON.parse(await readFile(new URL('../assets/data/x87-trig.json', import.meta.url), 'utf8'));
const storedCaptures = JSON.parse(await readFile(new URL('../assets/data/x87-stored-trig.json', import.meta.url), 'utf8'));
const forceCaptures = JSON.parse(await readFile(new URL('../assets/data/x87-force-trig.json', import.meta.url), 'utf8'));
const trig = createCapturedTrig(captures);
const addresses = { ...PENALTY_ADDRESSES, ...ENCOUNTER_GEOMETRY_ADDRESSES };
const routines = { resetBoat, respawnNearStart, shiftPenaltyPosition, checkNearRaceMarks, signedStartDistance, relativeProjection, aheadAstern };
const bits = value => { const buffer = Buffer.alloc(8); buffer.writeDoubleLE(value); return buffer.toString('hex'); };

function prepare(memory, row) {
  for (const [field, value] of Object.entries(row.globals)) {
    const spec = fixtures.globals[field];
    memory[spec.type === 'U32' ? 'writeU32' : 'writeI32'](spec.address, value);
  }
  for (const [boat, values] of Object.entries(row.boats)) for (const [field, value] of Object.entries(values)) {
    const spec = fixtures.indexed[field];
    memory[spec.type === 'F64' ? 'writeF64' : 'writeI32'](spec.address + Number(boat) * spec.stride, value);
  }
}

test('encounter leaf references identify original code, typed memory and supported input scope', () => {
  assert.equal(fixtures.provenance.sha256, createHash('sha256').update(original).digest('hex'));
  assert.equal(captures.provenance.sha256, fixtures.provenance.sha256);
  assert.equal(captures.provenance.authoritative_engine, 'native-x87');
  assert.equal(fixtures.provenance.engine, 'Unicorn with documented native original-code corrections');
  const correction = fixtures.provenance.native_corrections;
  assert.equal(correction.routine, '0042a950 / shiftPenaltyPosition');
  assert.equal(correction.original_sha256, fixtures.provenance.sha256);
  assert.equal(correction.corrected_cases, 1738);
  assert.match(correction.engine, /Native i386 instructions under Wine/);
  assert.match(correction.reason, /no tolerance or executable edits/);
  assert.equal(fixtures.provenance.x87_control_word, '0x037f');
  assert.equal(fixtures.provenance.tls_accessor_stub, '00459ed0');
  assert.equal(fixtures.provenance.sound_import_stub, '004b1c18');
  assert.match(fixtures.provenance.note, /not complete race parity/);
  for (const [name, routine] of Object.entries(fixtures.routines)) assert.equal(routine.address, addresses[name]);
  for (const [name, spec] of Object.entries({ ...fixtures.globals, ...fixtures.indexed })) assert.equal(spec.address, addresses[name]);
  assert.equal(Object.values(fixtures.routines).reduce((sum, routine) => sum + routine.cases.length, 0), 9115);
});

for (const [name, routine] of Object.entries(fixtures.routines)) test(`complete ${name} matches ${routine.cases.length} original returns, state, stores, RNG and sounds`, () => {
  const memory = loadPE32(original);
  const initial = memory.bytes.slice();
  const methods = Object.fromEntries(['writeI32', 'writeU32', 'writeF64'].map(method => [method, memory[method].bind(memory)]));
  let writes;
  for (const [method, originalMethod] of Object.entries(methods)) memory[method] = (address, value) => {
    if (writes) writes.set(`${address}:${method === 'writeF64' ? 8 : 4}`, { address, size: method === 'writeF64' ? 8 : 4 });
    return originalMethod(address, value);
  };
  for (const [index, row] of routine.cases.entries()) {
    memory.bytes.set(initial);
    prepare(memory, row);
    const expectedImage = Buffer.from(memory.bytes);
    const rng = new PoseyRng(row.seed);
    const sounds = [];
    const options = { trig, playSound: event => sounds.push(event) };
    writes = new Map();
    let result;
    if (name === 'respawnNearStart') result = respawnNearStart(memory, row.boat, rng, options);
    else if (name === 'shiftPenaltyPosition') result = shiftPenaltyPosition(memory, row.boat, options);
    else if (name === 'relativeProjection') result = relativeProjection(memory, ...row.arguments, options);
    else if (name === 'aheadAstern') result = aheadAstern(memory, ...row.arguments, options);
    else result = routines[name](memory, ...row.arguments);
    const nativeWrites = [...writes.values()].sort((left, right) => left.address - right.address || left.size - right.size);
    writes = undefined;
    const context = `${name} native case ${index}`;
    if (routine.returnType === 'I64') {
      assert.equal(result.toString(), row.expected.returnSigned64, `${context} signed64`);
      assert.equal(Number(BigInt.asIntN(32, result)), row.expected.returnValue, `${context} EAX`);
      assert.equal(Number(BigInt.asIntN(32, result >> 32n)), row.expected.returnHigh, `${context} EDX`);
    } else if (routine.returnType === 'float10') {
      assert.equal(Buffer.from(result.toBytes()).toString('hex'), row.expected.returnExtendedBits, `${context} ST0`);
      assert.equal(bits(result.toNumber()), row.expected.returnBits, `${context} binary64`);
    } else assert.equal(result, row.expected.returnValue, `${context} EAX`);
    assert.equal(rng.state, row.expected.rngState, `${context} RNG`);
    assert.deepEqual(sounds, row.expected.sounds, `${context} ordered sounds`);
    assert.deepEqual(nativeWrites, row.imageWrites, `${context} complete original store ranges`);
    for (const [field, value] of Object.entries(row.expected.globals)) {
      const spec = fixtures.globals[field];
      assert.equal(memory[spec.type === 'U32' ? 'readU32' : 'readI32'](spec.address), value, `${context} ${field}`);
    }
    for (const [boat, values] of Object.entries(row.expected.boats)) for (const [field, spec] of Object.entries(fixtures.indexed)) {
      const address = spec.address + Number(boat) * spec.stride;
      if (spec.type === 'F64') assert.equal(bits(memory.readF64(address)), values[`${field}Bits`], `${context} boat${boat}.${field} bits`);
      else assert.equal(memory.readI32(address), values[field], `${context} boat${boat}.${field}`);
    }
    for (const change of row.expected.imageChanges) {
      const offset = change.address - memory.base;
      assert.equal(expectedImage.subarray(offset, offset + change.before.length / 2).toString('hex'), change.before, `${context} native change initial bytes`);
      Buffer.from(change.after, 'hex').copy(expectedImage, offset);
    }
    assert.equal(Buffer.from(memory.bytes).equals(expectedImage), true, `${context} exact full mapped-image changes`);
  }
});

test('shared native trigonometry preserves all hardware result bits and explicit domain limits', () => {
  installNativeTrigReference(trig);
  for (const [angle, pair] of Object.entries(captures.angles)) {
    const result = nativeTrig(Number(angle));
    assert.equal(Buffer.from(result.sine.toBytes()).toString('hex'), pair.sineBits);
    assert.equal(Buffer.from(result.cosine.toBytes()).toString('hex'), pair.cosineBits);
  }
  assert.throws(() => nativeTrig(1081), /No original native/);
  assert.throws(() => nativeTrig(1.5), /signed 32-bit/);
  assert.throws(() => nativeTrig(0, { stored: true }), /x87-stored-trig/);
  const memory = loadPE32(original);
  memory.writeI32(PENALTY_ADDRESSES.tack + 4, 0);
  const before = memory.bytes.slice();
  assert.throws(() => shiftPenaltyPosition(memory, 1, { trig }), /uninitialized stack/);
  assert.deepEqual(memory.bytes, before);
});

test('stored and fractional angle references preserve separate native input construction', () => {
  const reference = createCapturedTrig(captures, storedCaptures, forceCaptures);
  assert.equal(storedCaptures.provenance.sha256, fixtures.provenance.sha256);
  assert.equal(forceCaptures.provenance.sha256, fixtures.provenance.sha256);
  assert.equal(forceCaptures.capturedCalls, 73124);
  for (const [angle, pair] of Object.entries(storedCaptures.angles)) {
    const result = nativeTrig(Number(angle), { stored: true, trig: reference });
    assert.equal(Buffer.from(result.sine.toBytes()).toString('hex'), pair.sineBits);
    assert.equal(Buffer.from(result.cosine.toBytes()).toString('hex'), pair.cosineBits);
  }
  const memory = loadPE32(original);
  const factor = Float80.fromNumber(memory.readF64(forceCaptures.degreeFactorAddress));
  const sport = Float80.fromNumber(memory.readF64(forceCaptures.sportOffsetAddress));
  const classOffset = Float80.fromNumber(memory.readF64(forceCaptures.classOffsetAddress));
  for (const lever of [0, 1, 5, 63, 64, 87, 100]) for (const force of [0, 1, 40, 100, 180]) for (const sportFlag of [0, 1]) for (const classFlag of [0, 1]) {
    let radians = Float80.fromInteger(lever);
    if (sportFlag) radians = radians.subtract(sport);
    if (classFlag) radians = radians.subtract(classOffset);
    radians = radians.add(Float80.fromInteger(force)).multiply(factor);
    const key = Buffer.from(radians.toBytes()).toString('hex');
    assert.ok(forceCaptures.radians[key], `native radian construction ${lever}/${force}/${sportFlag}/${classFlag}`);
    assert.equal(Buffer.from(nativeSineRadians(radians, { trig: reference }).toBytes()).toString('hex'), forceCaptures.radians[key].sineBits);
  }
  assert.notEqual(storedCaptures.angles['170'].sineBits, captures.angles['170'].sineBits);
  assert.throws(() => nativeSineRadians(Float80.fromInteger(1000), { trig: reference }), /No original native/);
});
