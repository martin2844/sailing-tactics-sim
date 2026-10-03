import { loadPE32 } from './runtime/index.js';
import { PoseyRng } from './engine/integer-core.js';
import { WIND_ADDRESSES as addresses, updateGlobalWind } from './engine/wind.js';

const $ = id => document.getElementById(id);

/** Replay actual recorded clock inputs against an isolated native image. */
export function initializeWindPanel({ original, tables, fixtures }) {
  const chain = fixtures.chains[0];
  if (!chain || chain.steps.length < 21) throw new Error('The captured wind sequence is missing.');
  let memory, rng, cursor, history;
  const overrides = {
    weather: 'global-weather', shore: 'global-shore', tidePhaseHour: 'global-tide-phase',
    baseDirection: 'global-base-direction', baseStrength: 'global-base-strength',
  };

  for (let hour = 0; hour <= 23; hour++) $('global-hour').add(new Option(`${String(hour).padStart(2, '0')}:00`, hour));
  for (let weather = 0; weather <= 6; weather++) $('global-weather').add(new Option(`Code ${weather}`, weather));
  for (let shore = 0; shore <= 3; shore++) $('global-shore').add(new Option(`Code ${shore}`, shore));

  function prepare(row) {
    for (const [field, value] of Object.entries(row.inputs ?? {})) memory.writeI32(fixtures.inputs[field], value);
    for (const [field, value] of Object.entries(row.doubleInputs ?? {})) memory.writeF64(fixtures.doubleInputs[field], value);
  }

  function snapshot(returnValue) {
    const value = {};
    for (const [field, address] of Object.entries(fixtures.outputs)) value[field] = memory.readI32(address);
    value.smoothDirection = memory.readF64(addresses.smoothDirection);
    value.smoothDirectionBits = [...memory.readBytes(addresses.smoothDirection, 8)].map(byte => byte.toString(16).padStart(2, '0')).join('');
    value.rngState = rng.state;
    value.returnValue = returnValue;
    return value;
  }

  function updateDisplay(value) {
    $('global-strength-output').textContent = value.strength;
    $('global-direction-output').textContent = value.direction;
    $('global-tide-output').textContent = value.tide;
    $('global-time-output').textContent = memory.readI32(addresses.time);
    $('global-hour-output').textContent = `${String(memory.readI32(addresses.hour)).padStart(2, '0')}:00`;
    $('global-rng-output').textContent = value.rngState;
    $('global-step-output').textContent = `${cursor} / ${chain.steps.length}`;
    $('global-wind-native-state').textContent = JSON.stringify(value, null, 2);
    $('global-drift-clock').textContent = memory.readF64(addresses.driftClock).toString();
    $('global-dt').textContent = memory.readF64(addresses.dt).toString();
    const remaining = chain.steps.length - cursor;
    $('global-next').disabled = remaining === 0;
    $('global-advance').disabled = remaining === 0;
    $('global-advance').textContent = remaining ? `Advance ${Math.min(20, remaining)} updates` : 'Sequence complete';
    $('global-sequence-status').textContent = remaining
      ? `Recorded update ${cursor} of ${chain.steps.length}. Each action uses the next captured clock inputs.`
      : 'The recorded sequence is complete. Reset it to explore another setup.';
    const points = history.map((point, index) => `${40 + index * 460 / (chain.steps.length - 1)},${145 - point.strength * 5}`).join(' ');
    $('global-history-line').setAttribute('points', points);
    $('global-history-dot').setAttribute('cx', 40 + (history.length - 1) * 460 / (chain.steps.length - 1));
    $('global-history-dot').setAttribute('cy', 145 - value.strength * 5);
    $('global-history-caption').textContent = `Actual strength after each recorded update (${history.length} values).`;
  }

  function input(id) {
    const element = $(id);
    if (!element.checkValidity()) throw new Error('Enter values within the displayed input limits.');
    const value = Number(element.value);
    if (!Number.isSafeInteger(value)) throw new Error('Native wind inputs must be whole numbers.');
    return value;
  }

  function advance(count) {
    $('global-wind-error').textContent = '';
    if (!$('global-wind-form').reportValidity()) return;
    try {
      const changes = Object.fromEntries(Object.entries(overrides).map(([field, id]) => [field, input(id)]));
      const hour = $('global-hour').value === 'recorded' ? null : input('global-hour');
      let value;
      const end = Math.min(cursor + count, chain.steps.length);
      while (cursor < end) {
        prepare(chain.steps[cursor]);
        for (const [field, setting] of Object.entries(changes)) memory.writeI32(addresses[field], setting);
        if (hour !== null) memory.writeI32(addresses.hour, hour);
        value = snapshot(updateGlobalWind(memory, rng));
        history.push(value);
        cursor++;
      }
      if (value) updateDisplay(value);
    } catch (error) { $('global-wind-error').textContent = error.message; }
  }

  function reset() {
    memory = loadPE32(original);
    for (const [table, values] of Object.entries({ sine: tables.sine, cosine: tables.cosine, randomTable: fixtures.randomTable })) {
      for (const [index, value] of values.entries()) memory.writeI32(addresses[table] + index * 4, value);
    }
    rng = new PoseyRng(chain.seed);
    cursor = 0;
    history = [];
    prepare(chain);
    $('global-hour').value = 'recorded';
    for (const [field, id] of Object.entries(overrides)) $(id).value = chain.inputs[field];
    advance(1);
  }

  $('global-wind-form').addEventListener('submit', event => { event.preventDefault(); advance(1); });
  $('global-advance').addEventListener('click', () => advance(20));
  $('global-reset').addEventListener('click', reset);
  for (const id of ['global-next', 'global-advance', 'global-reset', 'global-hour', ...Object.values(overrides)]) $(id).disabled = false;
  reset();
}
