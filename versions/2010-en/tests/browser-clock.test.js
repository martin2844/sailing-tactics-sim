import test from 'node:test';
import assert from 'node:assert/strict';
import { createPaintClock } from '../src/runtime/browser-clock.js';
import { createDrawingHost, drawingTick } from '../src/render/host.js';

test('one shared paint clock crosses unsigned wrap and retains its epoch between paints', () => {
  const clock = createPaintClock(0xfffffffe);
  clock.beginPaint();
  assert.equal(clock.minimumDuration(), 0);
  const scene = createDrawingHost({ getTickCount: clock.getTickCount });
  const chart = createDrawingHost({ getTickCount: clock.getTickCount });
  assert.equal(drawingTick(scene), 0xfffffffe);
  assert.equal(clock.getTickCount(), 0xffffffff);
  assert.equal(drawingTick(chart), 0);
  assert.equal(clock.minimumDuration(), 2);
  clock.beginPaint();
  assert.equal(clock.minimumDuration(), 0);
  assert.equal(clock.getTickCount(), 1);
  assert.equal(clock.minimumDuration(), 0);
});

test('original 30/60/80ms tick thresholds become scheduler duration with bounded work', () => {
  for (const duration of [30, 60, 80]) {
    const clock = createPaintClock(0xfffffff0);
    clock.beginPaint();
    const start = clock.getTickCount();
    let elapsed;
    do { elapsed = (clock.getTickCount() - start) >>> 0; } while (elapsed < duration);
    assert.equal(clock.minimumDuration(), duration);
    // Rendering has already taken time; the host schedules only the remainder.
    assert.equal(Math.max(0, clock.minimumDuration() - 15), duration - 15);
  }
  const clock = createPaintClock();
  for (let index = 0; index < 100_000; index++) clock.getTickCount();
  assert.throws(() => clock.getTickCount(), /native host bound/);
  clock.beginPaint();
  assert.equal(clock.getTickCount(), 100_000);
});
