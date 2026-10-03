import { loadPE32 } from './runtime/index.js';
import { PoseyRng, scaledRandom, speedDivisor, updateSpeedDivisor, wrapDegreesOnce, ORIGINAL_ADDRESSES } from './engine/integer-core.js';
import { apparentWind, APPARENT_WIND_ADDRESSES as windAddresses } from './engine/apparent-wind.js';
import { updateTack, spinnakerAnglePenalty, scheduleWindShift, setClosehauledHeading, SAILING_HELPER_ADDRESSES as helperAddresses } from './engine/helpers.js';
import { wrapRadiansOnce, bearingFromVector } from './engine/angles.js';
import { initializeBoatOptions, BOAT_OPTION_ADDRESSES as boatAddresses, BOAT_SELECTORS, BOAT_TIME_FACTORS } from './engine/boat-options.js';
import { updateGlobalWind, WIND_ADDRESSES as globalWindAddresses } from './engine/wind.js';
import {
  CURRENT_ADDRESSES as currentAddresses, sampleCurrent, sampleShorelineMetric,
  sampleSpatialMetric, sampleBoundaryMetric, updateShoreDirections, sampleUpstreamDistance,
} from './engine/current.js';
import {
  STEERING_ADDRESSES as steeringAddresses, updatePlayer1Rudder, updatePlayer1Steering, updatePlayer2Steering,
} from './engine/steering.js';
import { MOVEMENT_HELPER_ADDRESSES as movementAddresses, distanceToBoat, prestartSpeedPercent } from './engine/movement-helpers.js';
import { Float80 } from './runtime/float80.js';
import { initializeWindPanel } from './wind-panel.js';

const $ = id => document.getElementById(id);
const state = { memory: null, boatMemory: null, original: null, rng: new PoseyRng(), functions: [], selected: null, sourceRequest: 0, counts: {} };
const loadErrors = [];

async function fetchFile(path, kind = 'json') {
  const response = await fetch(path);
  if (!response.ok) throw new Error(`${path}: HTTP ${response.status}`);
  if (kind === 'bytes') return new Uint8Array(await response.arrayBuffer());
  if (kind === 'text') return response.text();
  return response.json();
}

function reportError(scope, error) {
  const message = `${scope}: ${error.message}`;
  loadErrors.push(message);
  const paragraph = document.createElement('p');
  paragraph.textContent = message;
  $('load-error').append(paragraph);
  $('load-error').hidden = false;
}

function integerInput(id) {
  const input = $(id);
  if (!input.checkValidity()) throw new Error(`Check the value for ${input.labels[0].textContent.trim()}.`);
  const value = Number(input.value);
  if (!Number.isSafeInteger(value)) throw new Error('Enter a whole number.');
  return value;
}

function format(value) { return Number(value).toLocaleString('en-US', { maximumFractionDigits: 6 }); }

function runWind(memory, { speedTenths, boat, angle, trueWind }) {
  memory.writeI32(windAddresses.angleToTrueWind + boat * 4, angle);
  memory.writeI32(windAddresses.trueWindKnots + boat * 4, trueWind);
  const pressure = apparentWind(memory, speedTenths, boat);
  return {
    pressure,
    apparentWindKnots: memory.readI32(windAddresses.apparentWindKnots + boat * 4),
    apparentWindAngle: memory.readI32(windAddresses.apparentWindAngle + boat * 4),
  };
}

function updateVector(id, degrees) {
  const radians = degrees * Math.PI / 180;
  $(id).setAttribute('x2', 120 + Math.sin(radians) * 77);
  $(id).setAttribute('y2', 108 - Math.cos(radians) * 77);
}

function calculateWind() {
  $('wind-error').textContent = '';
  if (!state.memory || !$('wind-form').checkValidity()) return;
  try {
    const speedTenths = Math.round(Number($('boat-speed').value) * 10);
    const angle = integerInput('wind-angle');
    const result = runWind(state.memory, { speedTenths, angle, trueWind: integerInput('true-wind'), boat: 1 });
    $('apparent-knots').textContent = result.apparentWindKnots;
    $('apparent-angle').textContent = result.apparentWindAngle;
    $('wind-pressure').textContent = format(result.pressure);
    updateVector('true-vector', angle);
    updateVector('apparent-vector', result.apparentWindAngle);
    $('wind-diagram-title').textContent = `True angle ${angle} degrees; apparent angle ${result.apparentWindAngle} degrees, relative to the boat`;
  } catch (error) { $('wind-error').textContent = error.message; }
}

$('wind-form').addEventListener('submit', event => { event.preventDefault(); calculateWind(); });
$('wind-form').addEventListener('input', calculateWind);
$('heading-form').addEventListener('submit', event => {
  event.preventDefault();
  if ($('heading-form').reportValidity()) $('heading-output').textContent = wrapDegreesOnce(integerInput('heading-input'));
});
for (let level = 1; level <= 15; level++) {
  const option = new Option(`Level ${level}`, level);
  option.selected = level === 7;
  $('speed-level').add(option);
}
$('speed-form').addEventListener('submit', event => event.preventDefault());
$('speed-level').addEventListener('change', () => { $('speed-output').textContent = speedDivisor(Number($('speed-level').value), 256); });
$('rng-form').addEventListener('submit', event => {
  event.preventDefault();
  if (!$('rng-form').reportValidity()) return;
  state.rng.srand(integerInput('rng-seed'));
  $('rng-output').textContent = '—';
  $('rng-state').textContent = state.rng.state;
});
$('next-random').addEventListener('click', () => {
  $('rng-output').textContent = state.rng.rand();
  $('rng-state').textContent = state.rng.state;
});

const boatOverrideInputs = {
  lengthOverride: 'boat-length-override',
  displacementOverride: 'boat-displacement-override',
  sailAreaOverride: 'boat-sail-area-override',
  sailPercentOverride: 'boat-sail-percent-override',
};
const boatOutputFields = {
  boatClass: 'boat-class', length: 'boat-length', displacement: 'boat-displacement',
  sailArea: 'boat-sail-area', sailPercent: 'boat-sail-percent', rig: 'boat-rig',
  course: 'boat-course', offshoreCourseFlag: 'boat-offshore-flag',
};
const boatFlagLabels = {
  catamaranFlag: 'Catamaran', boardFlag: 'Board', sportBoatFlag: 'Sport Boat',
  skiffFlag: 'Skiff', jy15Flag: 'JY15', optimistFlag: 'Optimist',
};

function applyBoatSetup() {
  $('boat-error').textContent = '';
  if (!state.boatMemory || !$('boat-form').checkValidity()) return;
  try {
    const memory = state.boatMemory;
    memory.writeI32(boatAddresses.selector, Number($('boat-selector').value));
    for (const [field, id] of Object.entries(boatOverrideInputs)) memory.writeI32(boatAddresses[field], integerInput(id));
    const returnValue = initializeBoatOptions(memory);
    for (const [field, id] of Object.entries(boatOutputFields)) $(id).textContent = memory.readI32(boatAddresses[field]);
    $('boat-time-factor').textContent = memory.readF64(boatAddresses.timeFactor).toString();
    $('boat-return-value').textContent = returnValue;
    $('boat-flags').replaceChildren();
    for (const [field, label] of Object.entries(boatFlagLabels)) {
      const name = document.createElement('dt');
      const value = document.createElement('dd');
      name.textContent = label;
      value.textContent = memory.readI32(boatAddresses[field]);
      $('boat-flags').append(name, value);
    }
    const boatClass = memory.readI32(boatAddresses.boatClass);
    $('boat-retained').textContent = boatClass === 7
      ? `Class 7 retained rig ${memory.readI32(boatAddresses.rig)}, course ${memory.readI32(boatAddresses.course)}, and offshore course flag ${memory.readI32(boatAddresses.offshoreCourseFlag)} from the prior setup.`
      : 'Changing boat choice reuses the prior globals; this preset applies the original class rules.';
  } catch (error) { $('boat-error').textContent = error.message; }
}

function resetBoatSetup() {
  state.boatMemory = loadPE32(state.original);
  $('boat-selector').value = state.boatMemory.readI32(boatAddresses.selector);
  for (const [field, id] of Object.entries(boatOverrideInputs)) $(id).value = state.boatMemory.readI32(boatAddresses[field]);
  applyBoatSetup();
}

function initializeBoatSetup() {
  $('boat-selector').replaceChildren();
  for (const [selector, name] of Object.entries(BOAT_SELECTORS)) $('boat-selector').add(new Option(name, selector));
  $('boat-selector').disabled = false;
  $('apply-boat').disabled = false;
  $('reset-boat').disabled = false;
  resetBoatSetup();
}

$('boat-form').addEventListener('submit', event => { event.preventDefault(); if ($('boat-form').reportValidity()) applyBoatSetup(); });
$('boat-selector').addEventListener('change', applyBoatSetup);
$('reset-boat').addEventListener('click', resetBoatSetup);

async function initializeNumericalTools() {
  const [bytes, tables] = await Promise.all([fetchFile('original/Tact02Demo.exe', 'bytes'), fetchFile('assets/data/trig-tables.json')]);
  if (tables.sine.length !== 362 || tables.cosine.length !== 362) throw new Error('Original trig table size differs from 362 entries.');
  const memory = loadPE32(bytes);
  for (let index = 0; index < tables.sine.length; index++) {
    memory.writeI32(windAddresses.sine + index * 4, tables.sine[index]);
    memory.writeI32(windAddresses.cosine + index * 4, tables.cosine[index]);
  }
  state.memory = memory;
  state.original = bytes;
  state.tables = tables;
  initializeBoatSetup();
  $('calculate-wind').disabled = false;
  calculateWind();
  return memory;
}

function cleanMenuLabel(text) { return text.replace(/&&/g, '\u0000').replace(/&/g, '').replace(/\u0000/g, '&').trim(); }

function menuNodes(items) {
  const list = document.createElement('ul');
  for (const item of items) {
    const li = document.createElement('li');
    if (item.separator) { li.className = 'separator'; li.setAttribute('role', 'separator'); }
    else if (item.items) {
      const details = document.createElement('details');
      const summary = document.createElement('summary');
      summary.textContent = cleanMenuLabel(item.text);
      details.append(summary, menuNodes(item.items));
      li.append(details);
    } else {
      const label = document.createElement('span');
      label.textContent = cleanMenuLabel(item.text);
      li.append(label);
      const command = document.createElement('span');
      command.className = 'command-id';
      command.textContent = `Command ${item.command_id}`;
      li.append(command);
    }
    list.append(li);
  }
  return list;
}

async function initializeResources() {
  const [manifest, menus] = await Promise.all([fetchFile('assets/manifest.json'), fetchFile('assets/ui/menus.json')]);
  state.counts.resources = manifest.resources.length;
  $('asset-select').replaceChildren();
  for (const [index, asset] of manifest.resources.entries()) {
    const suffix = asset.image ? ` · ${asset.image.width} × ${asset.image.height}` : asset.audio ? ` · ${asset.audio.duration_seconds.toFixed(2)} seconds` : '';
    $('asset-select').add(new Option(`${asset.type_name} ${asset.id}${suffix}`, index));
  }
  function preview() {
    const asset = manifest.resources[Number($('asset-select').value)];
    $('asset-preview').replaceChildren();
    if (asset.png_path) {
      const image = document.createElement('img');
      image.src = `assets/${asset.png_path}`;
      image.alt = `Original ${asset.type_name} resource ${asset.id}`;
      image.addEventListener('error', () => { $('asset-preview').textContent = 'This extracted image could not be loaded.'; });
      if (asset.image) {
        const scale = Math.min(3, 200 / asset.image.width, 100 / asset.image.height);
        image.width = Math.round(asset.image.width * scale);
        image.height = Math.round(asset.image.height * scale);
      } else { image.width = 64; }
      $('asset-preview').append(image);
    } else if (asset.wav_path) {
      const audio = document.createElement('audio');
      audio.controls = true;
      audio.preload = 'metadata';
      audio.src = `assets/${asset.wav_path}`;
      audio.setAttribute('aria-label', `Original sound resource ${asset.id}`);
      $('asset-preview').append(audio);
    } else {
      const label = document.createElement('p');
      label.textContent = `${asset.type_name} resource ${asset.id}. Original bytes are available below.`;
      $('asset-preview').append(label);
    }
    $('asset-description').textContent = `${format(asset.size)} original bytes. Extracted from Tact02Demo.exe; language ${asset.language}.`;
    $('asset-download').href = `assets/${asset.raw_path}`;
    $('asset-download').hidden = false;
  }
  $('asset-select').value = Math.max(0, manifest.resources.findIndex(asset => asset.type_name === 'icon' && asset.id === 1));
  $('asset-select').disabled = false;
  $('asset-select').addEventListener('change', preview);
  preview();
  $('menu-tree').replaceChildren();
  for (const menu of menus) $('menu-tree').append(menuNodes(menu.items));
  $('menu-tree').querySelector('details')?.setAttribute('open', '');
}

async function selectFunction(fn) {
  state.selected = fn.address;
  const request = ++state.sourceRequest;
  for (const button of $('function-list').children) button.setAttribute('aria-current', String(button.dataset.address === fn.address));
  $('function-title').textContent = `0x${fn.address} · ${fn.name} · ${format(fn.body_bytes)} bytes`;
  $('function-code').textContent = 'Loading decompiler output…';
  try {
    const code = await fetchFile(`decompiled/${fn.file}`, 'text');
    if (request === state.sourceRequest) $('function-code').textContent = code;
  } catch (error) {
    if (request === state.sourceRequest) $('function-code').textContent = `Unable to load this function: ${error.message}`;
  }
}

function filterFunctions() {
  const query = $('function-search').value.trim().toLowerCase();
  const matches = state.functions.filter(fn => `${fn.address} ${fn.name} ${fn.signature}`.toLowerCase().includes(query));
  $('function-count').textContent = `${format(matches.length)} matching functions${matches.length > 100 ? '; showing the first 100. Refine your search.' : '.'}`;
  $('function-list').replaceChildren();
  for (const fn of matches.slice(0, 100)) {
    const button = document.createElement('button');
    button.type = 'button';
    button.textContent = `${fn.address} ${fn.name}`;
    button.dataset.address = fn.address;
    button.setAttribute('aria-current', String(state.selected === fn.address));
    button.addEventListener('click', () => { void selectFunction(fn); });
    $('function-list').append(button);
  }
}

async function initializeSource() {
  const [index, summary] = await Promise.all([fetchFile('decompiled/functions.jsonl', 'text'), fetchFile('decompiled/summary.json')]);
  state.functions = index.trim().split(/\r?\n/).filter(Boolean).map(line => JSON.parse(line));
  state.counts.functions = summary.decompiled;
  $('function-search').disabled = false;
  $('function-search').addEventListener('input', filterFunctions);
  filterFunctions();
  const initial = state.functions.find(fn => fn.address === '00429df0') || state.functions[0];
  if (initial) await selectFunction(initial);
}

function pressureBits(value) {
  const buffer = new ArrayBuffer(8);
  new DataView(buffer).setFloat64(0, value, true);
  return [...new Uint8Array(buffer)].map(byte => byte.toString(16).padStart(2, '0')).join('');
}

function numberFromBits(bits) {
  const bytes = Uint8Array.from(bits.match(/../g), byte => parseInt(byte, 16));
  return new DataView(bytes.buffer).getFloat64(0, true);
}

function compare(actual, expected, context) {
  if (!Object.is(actual, expected)) throw new Error(`${context}: expected ${expected}, received ${actual}`);
}

async function initializeVerification(memoryPromise) {
  const [memory, core, wind, helpers, angles, boatOptions, calibration, globalWind, x87, trig, current, steering, movement] = await Promise.all([
    memoryPromise,
    fetchFile('tests/fixtures/original-core.json'),
    fetchFile('tests/fixtures/original-apparent-wind.json'),
    fetchFile('tests/fixtures/original-sailing-helpers.json'),
    fetchFile('tests/fixtures/original-angles.json'),
    fetchFile('tests/fixtures/original-boat-options.json'),
    fetchFile('assets/data/boat-calibration.json'),
    fetchFile('tests/fixtures/original-global-wind.json'),
    fetchFile('tests/fixtures/original-x87.json'),
    fetchFile('assets/data/trig-tables.json'),
    fetchFile('tests/fixtures/original-current.json'),
    fetchFile('tests/fixtures/original-steering.json'),
    fetchFile('tests/fixtures/original-movement-helpers.json'),
  ]);
  if (!globalThis.crypto?.subtle) throw new Error('Source integrity verification needs localhost or HTTPS.');
  const digest = await crypto.subtle.digest('SHA-256', state.original);
  const hash = [...new Uint8Array(digest)].map(byte => byte.toString(16).padStart(2, '0')).join('');
  compare(hash, core.provenance.sha256, 'Integer fixture executable hash');
  compare(hash, wind.provenance.sha256, 'Wind fixture executable hash');
  compare(hash, helpers.provenance.sha256, 'Sailing helper fixture executable hash');
  compare(hash, angles.provenance.sha256, 'Angle helper fixture executable hash');
  compare(hash, boatOptions.provenance.sha256, 'Boat option fixture executable hash');
  compare(hash, calibration.provenance.sha256, 'Boat calibration executable hash');
  compare(hash, globalWind.provenance.sha256, 'Global wind executable hash');
  compare(hash, x87.provenance.sha256, 'Extended arithmetic executable hash');
  compare(hash, trig.provenance.sha256, 'Trigonometry executable hash');
  compare(hash, current.provenance.sha256, 'Current fixture executable hash');
  compare(hash, steering.provenance.sha256, 'Steering fixture executable hash');
  compare(hash, movement.provenance.sha256, 'Movement helper fixture executable hash');
  const groups = [];
  let totalCases = 0;
  function addGroup(name, count, detail = 'cases') {
    groups.push(`${name}: ${format(count)} ${detail}`);
    totalCases += count;
  }
  for (const row of core.wrapDegreesOnce) compare(wrapDegreesOnce(row.input), row.expected, 'Heading wrap');
  addGroup('wrapDegreesOnce', core.wrapDegreesOnce.length);
  for (const row of core.speedDivisor) {
    memory.writeI32(ORIGINAL_ADDRESSES.speedLevel, row.level);
    memory.writeI32(ORIGINAL_ADDRESSES.speedDivisor, row.previous);
    compare(updateSpeedDivisor(memory), row.return_value, 'Speed return value');
    compare(memory.readI32(ORIGINAL_ADDRESSES.speedDivisor), row.expected, 'Speed global');
  }
  addGroup('updateSpeedDivisor', core.speedDivisor.length);
  let rngCount = 0;
  for (const row of core.rng) {
    const rng = new PoseyRng(row.seed);
    for (const step of row.sequence) {
      compare(rng.rand(), step.output, 'RNG output');
      compare(rng.state, step.state, 'RNG state');
      rngCount++;
    }
  }
  addGroup('rand', rngCount, 'outputs and states');
  for (const row of core.scaledRandom) {
    const rng = new PoseyRng(row.seed);
    compare(scaledRandom(row.range, rng), row.expected, 'Scaled random output');
    compare(rng.state, row.state, 'Scaled random state');
  }
  addGroup('scaledRandom', core.scaledRandom.length);
  for (const row of wind.cases) {
    const result = runWind(memory, row);
    compare(result.apparentWindKnots, row.expected.apparentWindKnots, 'Apparent wind speed');
    compare(result.apparentWindAngle, row.expected.apparentWindAngle, 'Apparent wind angle');
    compare(pressureBits(result.pressure), row.expected.pressureBits, 'Returned pressure bits');
  }
  addGroup('apparentWind', wind.cases.length);

  // Isolate helper fixture writes from the live apparent-wind calculator.
  const helperMemory = loadPE32(state.original);
  const h = helperAddresses;
  const write = (address, value) => helperMemory.writeI32(address, value);
  const helperRoutines = {
    updateTack: {
      prepare(row) {
        write(h.heading + row.boat * 4, row.heading);
        write(h.trueWindDirection + row.boat * 4, row.windDirection);
      },
      run: row => updateTack(helperMemory, row.boat),
      fields: row => ({ tack: h.tack + row.boat * 4 }),
    },
    spinnakerAnglePenalty: {
      prepare(row) {
        write(h.angleToTrueWind + row.boat * 4, row.angle);
        write(h.spinnakerThreshold, row.threshold);
      },
      run: row => spinnakerAnglePenalty(helperMemory, row.boat),
      fields: row => ({ penalty: h.spinnakerPenalty + row.boat * 4 }),
    },
    scheduleWindShift: {
      prepare(row) {
        write(h.targetRandomIndex, row.targetIndex);
        write(h.timeRandomIndex, row.timeIndex);
        write(h.windRandomTable + row.targetIndex * 4, row.targetRandom);
        write(h.windRandomTable + row.timeIndex * 4, row.timeRandom);
        write(h.integerSeconds, row.time);
      },
      run: row => scheduleWindShift(helperMemory, row.center, row.range, row.period),
      fields: () => ({ target: h.nextWindTarget, nextTime: h.nextWindTime, targetIndex: h.targetRandomIndex, timeIndex: h.timeRandomIndex }),
    },
    setClosehauledHeading: {
      prepare(row) {
        write(h.boatClass, row.boatClass);
        write(h.catamaranFlag, row.twinHullFlag);
        write(h.boardFlag, row.boardFlag);
        write(h.sportBoatFlag, row.planingFlag);
        write(h.player1ClosehauledAngle, row.previousAngle);
        write(h.trueWindKnots + row.boat * 4, row.wind);
        write(h.closehauledOffset + row.boat * 4, row.offset);
        write(h.trueWindDirection + row.boat * 4, row.windDirection);
        write(h.tack + row.boat * 4, row.tack);
      },
      run: row => setClosehauledHeading(helperMemory, row.boat),
      fields: row => ({ heading: h.heading + row.boat * 4, angle: h.player1ClosehauledAngle }),
    },
  };
  for (const [name, routine] of Object.entries(helperRoutines)) {
    for (const [index, row] of helpers[name].entries()) {
      routine.prepare(row);
      compare(routine.run(row), row.expected.returnValue, `${name} return ${index}`);
      for (const [field, address] of Object.entries(routine.fields(row))) {
        compare(helperMemory.readI32(address), row.expected[field], `${name} ${field} ${index}`);
      }
    }
    addGroup(name, helpers[name].length);
  }
  for (const [index, row] of angles.wrapRadiansOnce.entries()) {
    // Decode original input bits so negative zero is not lost in JSON numbers.
    compare(pressureBits(wrapRadiansOnce(numberFromBits(row.inputBits))), row.bits, `Radian return bits ${index}`);
  }
  addGroup('wrapRadiansOnce', angles.wrapRadiansOnce.length);
  for (const [index, row] of angles.bearingFromVector.entries()) {
    compare(bearingFromVector(row.param1, row.param2), row.expected, `Vector bearing ${index}`);
  }
  addGroup('bearingFromVector', angles.bearingFromVector.length);

  const boatMemory = loadPE32(state.original);
  for (const [index, row] of boatOptions.cases.entries()) {
    for (const [field, value] of Object.entries(row.inputs)) boatMemory.writeI32(boatOptions.inputs[field], value);
    compare(initializeBoatOptions(boatMemory), row.expected.returnValue, `Boat option return ${index}`);
    for (const [field, address] of Object.entries(boatOptions.outputs)) {
      compare(boatMemory.readI32(address), row.expected[field], `Boat option ${field} ${index}`);
    }
    compare(boatMemory.readF64(boatAddresses.timeFactor), row.expected.timeFactor, `Boat time factor ${index}`);
    compare(pressureBits(boatMemory.readF64(boatAddresses.timeFactor)), row.expected.timeFactorBits, `Boat time factor bits ${index}`);
  }
  addGroup('initializeBoatOptions', boatOptions.cases.length);
  for (const [length, row] of Object.entries(calibration.lengths)) {
    compare(BOAT_TIME_FACTORS[length], row.value, `Captured factor length ${length}`);
    compare(pressureBits(BOAT_TIME_FACTORS[length]), row.bits, `Captured factor bits length ${length}`);
    boatMemory.writeI32(boatAddresses.selector, 0);
    boatMemory.writeI32(boatAddresses.boatClass, 0);
    boatMemory.writeI32(boatAddresses.length, Number(length));
    initializeBoatOptions(boatMemory);
    compare(pressureBits(boatMemory.readF64(boatAddresses.timeFactor)), row.bits, `Initialized factor bits length ${length}`);
  }
  addGroup('Boat time factors', Object.keys(calibration.lengths).length, 'captured lengths');

  const globalWindMemory = loadPE32(state.original);
  for (const [table, values] of Object.entries({ sine: trig.sine, cosine: trig.cosine, randomTable: globalWind.randomTable })) {
    values.forEach((value, index) => globalWindMemory.writeI32(globalWindAddresses[table] + index * 4, value));
  }
  function prepareGlobalWind(row) {
    for (const [field, value] of Object.entries(row.inputs ?? {})) globalWindMemory.writeI32(globalWind.inputs[field], value);
    for (const [field, value] of Object.entries(row.doubleInputs ?? {})) globalWindMemory.writeF64(globalWind.doubleInputs[field], value);
  }
  function compareGlobalWind(row, rng, context) {
    compare(updateGlobalWind(globalWindMemory, rng), row.expected.returnValue, `${context} return`);
    for (const [field, address] of Object.entries(globalWind.outputs)) {
      compare(globalWindMemory.readI32(address), row.expected[field], `${context} ${field}`);
    }
    compare(pressureBits(globalWindMemory.readF64(globalWindAddresses.smoothDirection)), row.expected.smoothDirectionBits, `${context} smooth bits`);
    compare(rng.state, row.expected.rngState, `${context} RNG state`);
  }
  for (const [index, row] of globalWind.cases.entries()) {
    prepareGlobalWind(row);
    compareGlobalWind(row, new PoseyRng(row.seed), `Global wind ${index}`);
  }
  addGroup('updateGlobalWind', globalWind.cases.length, 'complete state cases');
  let chainedCount = 0;
  for (const [index, chain] of globalWind.chains.entries()) {
    prepareGlobalWind(chain);
    const rng = new PoseyRng(chain.seed);
    for (const [stepIndex, row] of chain.steps.entries()) {
      prepareGlobalWind(row);
      compareGlobalWind(row, rng, `Wind chain ${index} step ${stepIndex}`);
      chainedCount++;
    }
  }
  addGroup('Wind state continuity', chainedCount, 'chained updates');

  const bytesFromHex = value => Uint8Array.from(value.match(/../g), pair => parseInt(pair, 16));
  const hexFromBytes = value => [...value].map(byte => byte.toString(16).padStart(2, '0')).join('');
  // These arrays deliberately reproduce the synthetic fixture geometry. Course
  // generation is still unported; this verifies the recovered sampling routines.
  function currentFixtureMemory() {
    const isolated = loadPE32(state.original);
    for (const table of ['sine', 'cosine']) {
      trig[table].forEach((value, index) => isolated.writeI32(currentAddresses[table] + index * 4, value));
    }
    for (const [field, { address, values }] of Object.entries(current.geometry)) {
      values.forEach((value, index) => {
        if (field === 'radialBoundary') isolated.writeF64(address + index * 8, value);
        else isolated.writeI32(address + index * 4, value);
      });
    }
    return isolated;
  }
  function prepareCurrent(isolated, row) {
    for (const [field, value] of Object.entries(row.inputs)) isolated.writeI32(current.inputs[field], value);
    for (const [field, value] of Object.entries(row.doubleInputs)) isolated.writeF64(current.doubleInputs[field], value);
    isolated.writeF64(currentAddresses.cachedMetric + row.boat * 8, row.cachedMetric);
    isolated.writeI32(currentAddresses.currentStrength + row.boat * 4, row.currentStrength);
    isolated.writeI32(currentAddresses.previousStrength + row.boat * 4, row.previousStrength);
  }
  function compareCurrentState(isolated, row, context) {
    for (const [field, address] of Object.entries(current.outputs)) {
      compare(isolated.readI32(address), row.expected[field], `${context} ${field}`);
    }
    for (const field of ['currentStrength', 'previousStrength']) {
      compare(isolated.readI32(currentAddresses[field] + row.boat * 4), row.expected[field], `${context} ${field}`);
    }
    compare(isolated.readF64(currentAddresses.cachedMetric + row.boat * 8), row.expected.cachedMetric, `${context} cache`);
    compare(hexFromBytes(isolated.readBytes(currentAddresses.cachedMetric + row.boat * 8, 8)), row.expected.cachedMetricBits, `${context} cache bits`);
  }
  const currentMemory = currentFixtureMemory();
  for (const [index, row] of current.cases.entries()) {
    prepareCurrent(currentMemory, row);
    compare(sampleCurrent(currentMemory, row.x, row.y, row.boat), row.expected.returnValue, `sampleCurrent ${index} EAX`);
    compareCurrentState(currentMemory, row, `sampleCurrent ${index}`);
  }
  addGroup('sampleCurrent', current.cases.length, 'complete states with synthetic geometry');
  const currentHelpers = {
    shorelineMetric: { name: 'sampleShorelineMetric', run: sampleShorelineMetric, floating: true },
    ellipticalMetric: { name: 'sampleSpatialMetric', run: sampleSpatialMetric, floating: true },
    radialMetric: { name: 'sampleBoundaryMetric', run: sampleBoundaryMetric, floating: true },
    shoreDirections: { name: 'updateShoreDirections', run: updateShoreDirections },
    attenuationDistance: { name: 'sampleUpstreamDistance', run: sampleUpstreamDistance, selector: true },
  };
  for (const [field, routine] of Object.entries(currentHelpers)) {
    const isolated = currentFixtureMemory();
    for (const [index, row] of current.helpers[field].cases.entries()) {
      prepareCurrent(isolated, row);
      const result = routine.selector
        ? routine.run(isolated, row.selector, row.x, row.y)
        : routine.run(isolated, row.x, row.y, row.boat);
      const context = `${routine.name} ${index}`;
      compareCurrentState(isolated, row, context);
      if (routine.floating) {
        compare(result.toNumber(), row.expected.returnValue, `${context} return`);
        compare(pressureBits(result.toNumber()), row.expected.returnBits, `${context} return store bits`);
        compare(hexFromBytes(result.toBytes()), row.expected.returnExtendedBits, `${context} ST0 bits`);
      } else compare(result, row.expected.returnValue, `${context} EAX`);
    }
    addGroup(routine.name, current.helpers[field].cases.length, 'states and returns with synthetic geometry');
  }

  const steeringRoutines = { updatePlayer1Rudder, updatePlayer1Steering, updatePlayer2Steering };
  function prepareSteering(isolated, row) {
    for (const [field, value] of Object.entries(row.inputs ?? {})) isolated.writeI32(steering.inputs[field], value);
    for (const [field, value] of Object.entries(row.doubleInputs ?? {})) isolated.writeF64(steering.doubleInputs[field], value);
  }
  function compareSteering(isolated, routine, row, context) {
    const sounds = [];
    compare(routine(isolated, { playSound: request => sounds.push(request) }), row.expected.returnValue, `${context} EAX`);
    for (const [field, address] of Object.entries(steering.outputs)) {
      compare(isolated.readI32(address), row.expected[field], `${context} ${field}`);
    }
    compare(isolated.readF64(steeringAddresses.smoothHeading), row.expected.smoothHeading, `${context} smooth heading`);
    compare(hexFromBytes(isolated.readBytes(steeringAddresses.smoothHeading, 8)), row.expected.smoothHeadingBits, `${context} heading bits`);
    compare(sounds.length, row.expected.sounds.length, `${context} sound count`);
    for (const [index, sound] of sounds.entries()) {
      for (const field of ['resourceId', 'moduleHandle', 'flags']) {
        compare(sound[field], row.expected.sounds[index][field], `${context} sound ${index} ${field}`);
      }
    }
  }
  for (const [name, routine] of Object.entries(steeringRoutines)) {
    const isolated = loadPE32(state.original);
    for (const [index, row] of steering.routines[name].cases.entries()) {
      prepareSteering(isolated, row);
      compareSteering(isolated, routine, row, `${name} ${index}`);
    }
    addGroup(name, steering.routines[name].cases.length, 'complete states, heading bits and ordered sounds');
  }
  let steeringChainCount = 0;
  for (const [index, chain] of steering.chains.entries()) {
    const isolated = loadPE32(state.original);
    prepareSteering(isolated, chain);
    for (const [stepIndex, row] of chain.steps.entries()) {
      prepareSteering(isolated, row);
      compareSteering(isolated, steeringRoutines[chain.routine], row, `Steering chain ${index} step ${stepIndex}`);
      steeringChainCount++;
    }
  }
  addGroup('Steering state continuity', steeringChainCount, 'chained controls and ordered sounds');

  function compareUnchangedImage(isolated, before, context) {
    const oldWords = new Uint32Array(before.buffer);
    const newWords = new Uint32Array(isolated.bytes.buffer);
    for (let index = 0; index < oldWords.length; index++) {
      if (oldWords[index] !== newWords[index]) throw new Error(`${context}: image changed at 0x${(isolated.base + index * 4).toString(16)}`);
    }
  }
  const distanceMemory = loadPE32(state.original);
  for (const [index, row] of movement.distanceToBoat.cases.entries()) {
    for (const field of ['positionX', 'positionY']) distanceMemory.writeF64(movementAddresses[field] + row.boat * 8, numberFromBits(row.inputBits[field]));
    const before = distanceMemory.bytes.slice();
    const result = distanceToBoat(distanceMemory, row.boat, numberFromBits(row.inputBits.x), numberFromBits(row.inputBits.y));
    const context = `distanceToBoat ${index}`;
    compare(hexFromBytes(result.toBytes()), row.expected.returnExtendedBits, `${context} ST0 bits`);
    compare(pressureBits(result.toNumber()), row.expected.returnBits, `${context} stored return bits`);
    compare(result.toNumber(), row.expected.returnValue, `${context} return`);
    compare(row.expected.imageUnchanged, true, `${context} reference image`);
    compareUnchangedImage(distanceMemory, before, context);
  }
  addGroup('distanceToBoat', movement.distanceToBoat.cases.length, 'extended returns and unchanged image');
  const prestartMemory = loadPE32(state.original);
  for (const [index, row] of movement.prestartSpeedPercent.cases.entries()) {
    for (const [field, value] of Object.entries(row.inputs)) prestartMemory.writeI32(movement.inputs[field], value);
    for (const [field, bits] of Object.entries(row.doubleInputBits)) prestartMemory.writeF64(movement.doubleInputs[field], numberFromBits(bits));
    for (const [field, value] of Object.entries(row.indexedInputs)) {
      const { address, stride, type } = movement.indexed[field];
      if (type === 'F64') prestartMemory.writeF64(address + row.boat * stride, numberFromBits(row.indexedInputBits[field]));
      else prestartMemory.writeI32(address + row.boat * stride, value);
    }
    const before = prestartMemory.bytes.slice();
    const rng = new PoseyRng(row.seed);
    const context = `prestartSpeedPercent ${index}`;
    compare(prestartSpeedPercent(prestartMemory, row.boat, rng), row.expected.returnValue, `${context} EAX`);
    compare(rng.state, row.expected.rngState, `${context} RNG state`);
    compare(row.expected.imageUnchanged, true, `${context} reference image`);
    compareUnchangedImage(prestartMemory, before, context);
  }
  addGroup('prestartSpeedPercent', movement.prestartSpeedPercent.cases.length, 'EAX, RNG state and unchanged image');

  for (const [index, row] of x87.arithmetic.entries()) {
    const left = Float80.fromBytes(bytesFromHex(row.leftBits));
    const result = row.operation === 'sqrt' ? left.sqrt() : left[row.operation](Float80.fromBytes(bytesFromHex(row.rightBits)));
    compare(hexFromBytes(result.toBytes()), row.expected.extendedBits, `Extended ${row.operation} ${index}`);
    compare(pressureBits(result.toNumber()), row.expected.storedDoubleBits, `Extended store ${index}`);
  }
  addGroup('Extended arithmetic', x87.arithmetic.length, 'register and store cases');
  for (const [index, row] of x87.truncation.entries()) {
    const value = Float80.fromBytes(bytesFromHex(row.inputBits));
    compare(value.truncI64().toString(), row.expected.integer64, `Original CRT wide truncation ${index}`);
    compare(value.truncI32(), row.expected.integer32, `Original CRT truncation ${index}`);
  }
  addGroup('Extended integer conversion', x87.truncation.length, 'CRT cases');
  for (const description of groups) {
    const item = document.createElement('li');
    item.textContent = description;
    $('verification-results').append(item);
  }
  $('verification-status').textContent = `All recorded cases match in this browser (${format(totalCases)} cases).`;
  calculateWind();
}

async function initialize() {
  const numerical = initializeNumericalTools();
  const changingWind = Promise.all([numerical, fetchFile('tests/fixtures/original-global-wind.json')])
    .then(([, fixtures]) => initializeWindPanel({ original: state.original, tables: state.tables, fixtures }));
  const jobs = [
    { name: 'Numerical tools', promise: numerical },
    { name: 'Resources', promise: initializeResources() },
    { name: 'Decompiled source', promise: initializeSource() },
    { name: 'Verification', promise: initializeVerification(numerical) },
    { name: 'Changing wind', promise: changingWind },
  ];
  const results = await Promise.allSettled(jobs.map(job => job.promise));
  for (const [index, result] of results.entries()) {
    if (result.status === 'rejected') {
      reportError(jobs[index].name, result.reason);
      if (jobs[index].name === 'Verification') $('verification-status').textContent = 'Verification did not complete. See the load error above.';
    }
  }
  const counts = [];
  if (state.counts.functions != null) counts.push(`${format(state.counts.functions)} decompiled functions`);
  if (state.counts.resources != null) counts.push(`${format(state.counts.resources)} extracted resources`);
  $('load-status').textContent = `${loadErrors.length ? 'Loaded with errors' : 'Ready'}${counts.length ? ` · ${counts.join(' · ')}` : ''}`;
}

void initialize().catch(error => reportError('Workbench', error));
