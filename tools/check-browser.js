import { spawn } from 'node:child_process';
import { mkdir, readFile, writeFile } from 'node:fs/promises';
import { dirname, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';
import assert from 'node:assert/strict';
import { setTimeout as pause } from 'node:timers/promises';

const root = resolve(dirname(fileURLToPath(import.meta.url)), '..');
const output = resolve(root, 'analysis/browser-check');
await mkdir(output, { recursive: true });
const url = process.env.TACT_URL || 'http://127.0.0.1:8765';
const checks = [];
const exceptions = [];
const readJSON = async path => JSON.parse(await readFile(resolve(root, path), 'utf8'));
const [core, wind, helpers, angles, boatOptions, calibration, globalWind, x87, current, steering, movement] = await Promise.all([
  'tests/fixtures/original-core.json', 'tests/fixtures/original-apparent-wind.json',
  'tests/fixtures/original-sailing-helpers.json', 'tests/fixtures/original-angles.json',
  'tests/fixtures/original-boat-options.json', 'assets/data/boat-calibration.json',
  'tests/fixtures/original-global-wind.json', 'tests/fixtures/original-x87.json',
  'tests/fixtures/original-current.json',
  'tests/fixtures/original-steering.json', 'tests/fixtures/original-movement-helpers.json',
].map(readJSON));
const expectedCases = core.wrapDegreesOnce.length + core.speedDivisor.length
  + core.rng.reduce((sum, row) => sum + row.sequence.length, 0) + core.scaledRandom.length
  + wind.cases.length + Object.entries(helpers).filter(([name]) => name !== 'provenance').reduce((sum, [, cases]) => sum + cases.length, 0)
  + angles.wrapRadiansOnce.length + angles.bearingFromVector.length + boatOptions.cases.length
  + Object.keys(calibration.lengths).length + globalWind.cases.length
  + globalWind.chains.reduce((sum, chain) => sum + chain.steps.length, 0)
  + x87.arithmetic.length + x87.truncation.length + current.cases.length
  + Object.values(current.helpers).reduce((sum, helper) => sum + helper.cases.length, 0)
  + Object.values(steering.routines).reduce((sum, routine) => sum + routine.cases.length, 0)
  + steering.chains.reduce((sum, chain) => sum + chain.steps.length, 0)
  + movement.distanceToBoat.cases.length + movement.prestartSpeedPercent.cases.length;
const chrome = spawn(process.env.TACT_CHROME || 'google-chrome', [
  '--headless=new', '--disable-gpu', '--no-sandbox', '--remote-debugging-port=0',
  '--no-first-run', '--no-default-browser-check',
  `--user-data-dir=${output}/profile-${process.pid}`, url,
], { stdio: ['ignore', 'ignore', 'pipe'] });
let stderr = '';
let socket;
try {
  const devtools = await new Promise((resolveReady, reject) => {
    const timeout = setTimeout(() => reject(new Error('Chrome did not start DevTools within 20 seconds')), 20000);
    chrome.once('error', reject);
    chrome.once('exit', code => reject(new Error(`Chrome exited ${code}: ${stderr.slice(-1000)}`)));
    chrome.stderr.on('data', chunk => {
      stderr += chunk.toString();
      const match = stderr.match(/DevTools listening on (ws:\/\/\S+)/);
      if (match) { clearTimeout(timeout); resolveReady(match[1]); }
    });
  });
  const debuggerURL = new URL(devtools);
  const pages = await (await fetch(`http://${debuggerURL.host}/json/list`)).json();
  const page = pages.find(item => item.type === 'page' && item.url.startsWith(url));
  if (!page) throw new Error('Workbench page was not opened');
  socket = new WebSocket(page.webSocketDebuggerUrl);
  await new Promise((yes, no) => { socket.addEventListener('open', yes, { once: true }); socket.addEventListener('error', no, { once: true }); });
  let nextId = 0;
  const pending = new Map();
  socket.addEventListener('message', event => {
    const message = JSON.parse(event.data);
    if (message.method === 'Runtime.exceptionThrown') exceptions.push(message.params.exceptionDetails);
    if (message.id) {
      const job = pending.get(message.id);
      pending.delete(message.id);
      if (message.error) job?.reject(new Error(JSON.stringify(message.error)));
      else job?.resolve(message.result);
    }
  });
  const call = (method, params = {}) => new Promise((resolveCall, reject) => {
    const id = ++nextId;
    pending.set(id, { resolve: resolveCall, reject });
    socket.send(JSON.stringify({ id, method, params }));
  });
  const evaluate = async expression => {
    const result = await call('Runtime.evaluate', { expression, returnByValue: true, awaitPromise: true });
    if (result.exceptionDetails) throw new Error(JSON.stringify(result.exceptionDetails));
    return result.result.value;
  };
  const waitFor = async expression => {
    for (let n = 0; n < 100; n++) {
      if (await evaluate(expression)) return;
      await pause(100);
    }
    throw new Error(`Browser condition did not become true: ${expression}`);
  };
  const text = id => evaluate(`document.getElementById(${JSON.stringify(id)}).textContent`);
  const captureElement = async (id, filename) => {
    const bounds = await evaluate(`(()=>{const r=document.getElementById(${JSON.stringify(id)}).getBoundingClientRect();return{x:r.x+scrollX-4,y:r.y+scrollY-12,width:r.width+8,height:r.height+20,scale:1}})()`);
    const screenshot = await call('Page.captureScreenshot', { format: 'png', captureBeyondViewport: true, clip: bounds });
    await writeFile(resolve(output, filename), Buffer.from(screenshot.data, 'base64'));
  };
  await call('Runtime.enable');
  await call('Page.enable');
  await call('Emulation.setDeviceMetricsOverride', { width: 1440, height: 1300, deviceScaleFactor: 1, mobile: false });
  await waitFor(`document.getElementById('verification-status')?.textContent.includes('All recorded cases match') && document.getElementById('function-code')?.textContent.includes('FUN_00429df0')`);
  assert.equal(await evaluate(`document.getElementById('load-error').hidden`), true);
  assert.ok((await text('verification-status')).includes(`${expectedCases.toLocaleString('en-US')} cases`));
  checks.push({ name: 'browser reference comparisons', result: await text('verification-status') });
  const currentGroups = await evaluate(`Array.from(document.querySelectorAll('#verification-results li'),item=>item.textContent)`);
  const currentRoutines = ['sampleCurrent', 'sampleShorelineMetric', 'sampleSpatialMetric', 'sampleBoundaryMetric', 'updateShoreDirections', 'sampleUpstreamDistance'];
  for (const name of currentRoutines) assert.ok(currentGroups.some(group => group.startsWith(`${name}:`) && group.includes('synthetic geometry')), `Current verification group ${name}`);
  checks.push({ name: 'all six current routines verify globals, cached binary64 bits, EAX and extended returns on explicit synthetic geometry', passed: true });
  for (const name of Object.keys(steering.routines)) assert.ok(currentGroups.some(group => group.startsWith(`${name}:`) && group.includes('ordered sounds')), `Steering verification group ${name}`);
  assert.ok(currentGroups.some(group => group.startsWith('Steering state continuity:') && group.includes('chained controls')));
  checks.push({ name: 'three steering routines and chained controls verify every mutable global, heading bits, EAX and ordered sound requests', passed: true });
  for (const name of ['distanceToBoat', 'prestartSpeedPercent']) assert.ok(currentGroups.some(group => group.startsWith(`${name}:`) && group.includes('unchanged image')), `Movement verification group ${name}`);
  checks.push({ name: 'movement helpers verify exact extended and stored returns, EAX, RNG state and the full unchanged image', passed: true });
  const reportLinks = await evaluate(`Array.from(document.querySelectorAll('.verification-group .footnote a'),link=>link.getAttribute('href'))`);
  for (const path of ['analysis/native-reference-comparison.json', 'analysis/x87-reference-comparison.json']) {
    assert.ok(reportLinks.includes(path));
    const response = await fetch(new URL(path, url));
    assert.equal(response.ok, true, `Evidence report loads: ${path}`);
    const report = await response.json();
    if (path.includes('native-reference')) assert.equal(report.all_fixture_cases_match, true);
  }
  checks.push({ name: 'native Wine and hardware x87 evidence reports are linked and load', passed: true });
  assert.equal(await text('apparent-knots'), '17');
  assert.equal(await text('apparent-angle'), '72');
  assert.equal(await text('wind-pressure'), '371.136');
  checks.push({ name: 'initial apparent wind', passed: true });
  await evaluate(`for (const [id,value] of [['boat-speed','0'],['true-wind','0'],['wind-angle','361']]) document.getElementById(id).value=value; document.getElementById('wind-angle').dispatchEvent(new Event('input',{bubbles:true}));`);
  assert.equal(await text('apparent-knots'), '0');
  assert.equal(await text('apparent-angle'), '90');
  assert.equal(await text('wind-pressure'), '0');
  checks.push({ name: 'zero-vector early return from original routine', passed: true });
  await evaluate(`for (const [id,value] of [['boat-speed','5.2'],['true-wind','17'],['wind-angle','90']]) document.getElementById(id).value=value; document.getElementById('wind-angle').dispatchEvent(new Event('input',{bubbles:true}));`);
  await evaluate(`document.getElementById('rng-seed').value='1';document.getElementById('rng-form').requestSubmit();document.getElementById('next-random').click();`);
  assert.equal(await text('rng-output'), '41');
  assert.equal(await text('rng-state'), '2745024');
  await evaluate(`document.getElementById('next-random').click()`);
  assert.equal(await text('rng-output'), '18467');
  assert.equal(await text('rng-state'), '3357800067');
  checks.push({ name: 'seed and chained RNG controls', passed: true });
  await evaluate(`document.getElementById('heading-input').value='-361';document.getElementById('heading-form').requestSubmit();`);
  assert.equal(await text('heading-output'), '-1');
  await evaluate(`document.getElementById('speed-level').value='15';document.getElementById('speed-level').dispatchEvent(new Event('change',{bubbles:true}));`);
  assert.equal(await text('speed-output'), '10');
  checks.push({ name: 'heading and speed controls preserve original quirks', passed: true });
  const windSnapshot = async () => JSON.parse(await text('global-wind-native-state'));
  const recordedWind = globalWind.chains[0];
  await waitFor(`document.getElementById('global-wind-native-state')?.textContent.includes('rngState')`);
  assert.deepEqual(await windSnapshot(), recordedWind.steps[0].expected);
  assert.equal(await text('global-step-output'), `1 / ${recordedWind.steps.length}`);
  await evaluate(`document.getElementById('global-wind-form').requestSubmit()`);
  assert.deepEqual(await windSnapshot(), recordedWind.steps[1].expected);
  await evaluate(`document.getElementById('global-advance').click()`);
  assert.deepEqual(await windSnapshot(), recordedWind.steps[21].expected);
  assert.equal(await text('global-time-output'), String(recordedWind.steps[21].inputs.time));
  assert.equal(await text('global-drift-clock'), String(recordedWind.steps[21].doubleInputs.driftClock));
  assert.equal(await text('global-dt'), String(recordedWind.steps[21].doubleInputs.dt));
  assert.equal(await text('global-step-output'), `22 / ${recordedWind.steps.length}`);
  assert.equal(await evaluate(`document.getElementById('global-history-line').getAttribute('points').split(' ').length`), 22);
  await captureElement('changing-wind', 'wind-desktop.png');
  checks.push({ name: 'single and 20 recorded wind updates match every fixture field, binary64 bits and RNG state', passed: true });
  await evaluate(`for(const [id,value] of [['global-hour','23'],['global-weather','4'],['global-shore','3'],['global-tide-phase','22'],['global-base-direction','45'],['global-base-strength','22']])document.getElementById(id).value=value;document.getElementById('global-wind-form').requestSubmit()`);
  assert.equal(await text('global-hour-output'), '23:00');
  assert.equal(await text('global-wind-error'), '');
  await evaluate(`document.getElementById('global-reset').click()`);
  assert.deepEqual(await windSnapshot(), recordedWind.steps[0].expected);
  assert.equal(await evaluate(`document.getElementById('global-hour').value`), 'recorded');
  assert.equal(await evaluate(`document.getElementById('global-base-strength').value`), String(recordedWind.inputs.baseStrength));
  checks.push({ name: 'bounded wind controls and reset restore captured globals, clock and seed', passed: true });
  assert.equal(await evaluate(`document.getElementById('boat-selector').options.length`), 15);
  assert.equal(await text('boat-class'), '6');
  assert.equal(await text('boat-length'), '25');
  await evaluate(`document.getElementById('boat-selector').value='15';document.getElementById('boat-selector').dispatchEvent(new Event('change',{bubbles:true}));`);
  assert.equal(await text('boat-class'), '8');
  assert.equal(await text('boat-length'), '61');
  assert.equal(await text('boat-rig'), '1');
  await evaluate(`document.getElementById('boat-selector').value='14';document.getElementById('boat-selector').dispatchEvent(new Event('change',{bubbles:true}));`);
  assert.equal(await text('boat-class'), '7');
  assert.equal(await text('boat-rig'), '1');
  assert.equal(await text('boat-course'), '1');
  assert.ok((await text('boat-retained')).includes('retained rig 1, course 1'));
  await evaluate(`document.getElementById('boat-length-override').value='35';document.getElementById('boat-form').requestSubmit();`);
  assert.equal(await text('boat-length'), '35');
  assert.equal(await text('boat-time-factor'), '0.6546536707079772');
  await evaluate(`document.getElementById('reset-boat').click()`);
  assert.equal(await evaluate(`document.getElementById('boat-selector').value`), '12');
  assert.equal(await text('boat-class'), '6');
  assert.equal(await text('boat-length'), '25');
  assert.equal(await text('boat-rig'), '-1');
  checks.push({ name: 'all 15 native boat selectors, retained rig/course, calibrated length override and reset', passed: true });
  await evaluate(`document.getElementById('function-search').value='0041bb10';document.getElementById('function-search').dispatchEvent(new Event('input',{bubbles:true}));document.querySelector('#function-list button').click();`);
  await waitFor(`document.getElementById('function-code').textContent.includes('FUN_0041bb10') && document.getElementById('function-code').textContent.includes('return')`);
  assert.equal(await evaluate(`document.querySelectorAll('#function-list button').length`), 1);
  checks.push({ name: 'function search loads corrected bearing C', passed: true });
  await waitFor(`document.querySelector('#asset-preview img')?.complete && document.querySelector('#asset-preview img')?.naturalWidth===32`);
  assert.equal(await evaluate(`document.querySelectorAll('#menu-tree .command-id').length`), 192);
  checks.push({ name: 'original image and all 192 menu commands load', passed: true });
  const desktop = await call('Page.captureScreenshot', { format: 'png', captureBeyondViewport: false });
  await writeFile(resolve(output, 'desktop.png'), Buffer.from(desktop.data, 'base64'));
  await call('Emulation.setDeviceMetricsOverride', { width: 390, height: 1100, deviceScaleFactor: 1, mobile: true });
  await pause(100);
  const layout = await evaluate(`({width:innerWidth,scrollWidth:document.documentElement.scrollWidth})`);
  assert.ok(layout.scrollWidth <= layout.width, `Mobile overflow: ${JSON.stringify(layout)}`);
  const mobile = await call('Page.captureScreenshot', { format: 'png', captureBeyondViewport: false });
  await writeFile(resolve(output, 'mobile.png'), Buffer.from(mobile.data, 'base64'));
  checks.push({ name: 'mobile viewport has no horizontal overflow', passed: true });
  await captureElement('changing-wind', 'wind-mobile.png');
  assert.equal(exceptions.length, 0);
  const report = { url, passed: true, checks, exceptions,
    scope: 'Preservation workbench numerical tools, resource previews and source browser',
    playableSimulatorEntry: 'play.html' };
  await writeFile(resolve(output, 'report.json'), JSON.stringify(report, null, 2) + '\n');
  console.log(JSON.stringify(report, null, 2));
} finally {
  socket?.close();
  chrome.kill('SIGTERM');
}
