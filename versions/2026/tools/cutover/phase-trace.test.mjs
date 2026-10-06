import assert from 'node:assert/strict';
import {test} from 'node:test';
import {PhaseTracer} from '../../app/engine/diagnostics/phase-trace.ts';
import {AddressSpaceMemory} from '../../../../src/runtime/memory.js';
import {PoseyRng} from '../../../../src/engine/integer-core.js';

const field = 0x4da100;
function fixture() {
  return {memory: new AddressSpaceMemory(0x21c000), random: new PoseyRng(17)};
}

test('tracing preserves full state/RNG and observes restored writes and nested draws', () => {
  function execute(traced) {
    const {memory, random} = fixture();
    const options = {
      updateBoatDynamics(image, boat) {
        const held = image.readI32(field);
        image.writeI32(field, random.rand());
        image.writeI32(field, held); // Zero net change is still an observed write.
        return boat;
      },
      drawScene(image) {
        options.updateBoatDynamics(image, 1);
        image.view.setInt32(field + 4 - image.base, random.rand(), true); // Bypasses method hooks.
        return 42;
      },
    };
    const observer = new PhaseTracer(memory, random);
    if (traced) { observer.install(options); observer.start(); }
    const value = observer.paint(3, () => options.drawScene(memory));
    const trace = observer.stop();
    observer.dispose();
    return {memory, random, trace, value};
  }
  const plain = execute(false), traced = execute(true);
  assert.deepEqual(traced.memory.bytes, plain.memory.bytes);
  assert.equal(traced.random.state, plain.random.state);
  assert.equal(traced.value, plain.value);
  const dynamics = traced.trace.records.find(r => r.name === 'updateBoatDynamics');
  assert.equal(dynamics.boat, 1);
  assert.equal(dynamics.writes.find(w => w.address === field).count, 2);
  assert.deepEqual(dynamics.netChangedWords, []);
  const scene = traced.trace.records.find(r => r.name === 'drawScene');
  assert.deepEqual(scene.netChangedWords, [field + 4]);
  assert.equal(scene.randomCalls, 2);
  assert.equal(dynamics.randomCalls, 1);
  assert.equal(dynamics.parent, scene.id);
  assert.equal(traced.trace.records.find(r => r.name === 'paint').randomCalls, 2);
  assert.equal(Object.hasOwn(traced.memory, 'readI32'), false);
  assert.equal(Object.hasOwn(traced.random, 'rand'), false);
});

test('a native failure propagates and trace hooks can be restored', () => {
  const {memory, random} = fixture();
  const failure = new RangeError('native failure');
  const options = {drawScene() { throw failure; }};
  const original = options.drawScene;
  const observer = new PhaseTracer(memory, random);
  observer.install(options); observer.start();
  assert.throws(() => observer.paint(0, () => options.drawScene()), e => e === failure);
  assert.equal(observer.stop().records[0].failed, true);
  observer.dispose();
  assert.equal(options.drawScene, original);
  assert.equal(Object.hasOwn(memory, 'writeF64'), false);
});

test('partial installation failure rolls back every installed hook', () => {
  const {memory, random} = fixture();
  const options = {};
  Object.defineProperty(options, 'drawScene', {value() {}, enumerable: true});
  const observer = new PhaseTracer(memory, random);
  assert.throws(() => observer.install(options), TypeError);
  assert.equal(Object.hasOwn(memory, 'readI32'), false);
  assert.equal(Object.hasOwn(random, 'rand'), false);
});

test('pixel capture is bounded and explicitly reports truncation', () => {
  const {memory, random} = fixture();
  const observer = new PhaseTracer(memory, random);
  observer.start();
  observer.paint(0, () => {
    for (let i = 0; i < 2001; i++) observer.pixel(i, 1, 0xffffff);
  });
  const trace = observer.stop();
  assert.equal(trace.truncated, true);
  assert.equal(trace.records[0].pixels.length, 2000);
});

test('borrowed native methods retain their receiver and do not enter the master ledger', () => {
  const {memory, random} = fixture();
  const other = fixture();
  const observer = new PhaseTracer(memory, random);
  observer.install({}); observer.start();
  observer.paint(0, () => {
    memory.writeI32.call(other.memory, field, 71);
    random.rand.call(other.random);
  });
  const record = observer.stop().records[0];
  assert.equal(other.memory.readI32(field), 71);
  assert.equal(memory.readI32(field), 0);
  assert.equal(random.state, 17);
  assert.equal(record.randomCalls, 0);
  assert.deepEqual(record.writes, []);
  observer.dispose();
});
