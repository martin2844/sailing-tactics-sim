import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { configurePaintDimensions } from '../src/render/paint-lifecycle.js';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const jsonBytes = async path => {
  const bytes = await readFile(new URL(path, edition));
  return { bytes, data: JSON.parse(bytes) };
};
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
if (sha(source) !== sourceSha256) throw new Error('Preserved English target differs');
const initializer = await jsonBytes('analysis/initializeRace-capture-inputs.json');
const application = await jsonBytes('tests/fixtures/original-application.json');
const reference = await jsonBytes('tests/fixtures/original-boat-options.json');
if (initializer.data.sourceSha256 !== sourceSha256 || application.data.sourceSha256 !== sourceSha256
    || reference.data.sourceSha256 !== sourceSha256
    || !application.data.provenance.loadedOriginalTextUnchanged
    || !application.data.provenance.originalFileUnchanged) {
  throw new Error('Original input or constructor authority differs');
}
const graphics = application.data.cases[0].expected.events
  .filter(event => event.type === 'createPen' || event.type === 'createBrush');
if (graphics.length !== 90 || new Set(graphics.map(object => object.handleAddress)).size !== 90)
  throw new Error('Original constructor must supply all 90 distinct pen/brush slots');
const base = reference.data.mutableBlock.address;
const baseline = Buffer.from(reference.data.mutableBaseline, 'hex');
const memory = loadPE32(source);
const differences = bytes => {
  const result = []; let first = -1, last = -1;
  for (let index = 0; index < bytes.length; index++) if (bytes[index] !== baseline[index]) {
    if (first < 0) first = last = index;
    else if (index - last <= 16) last = index;
    else {
      result.push({ address: base + first, bytes: Buffer.from(bytes.subarray(first, last + 1)).toString('hex') });
      first = last = index;
    }
  }
  if (first >= 0) result.push({ address: base + first,
    bytes: Buffer.from(bytes.subarray(first, last + 1)).toString('hex') });
  return result;
};
const routines = {
  initializeBoatOptions: { name: 'initializeBoatOptions', address: 0x420c00, argumentTypes: [], returnType: 'void' },
  initializeRace: { name: 'initializeRace', address: 0x41be70, argumentTypes: [], returnType: 'void' },
  drawStartScreen: { name: 'drawStartScreen', address: 0x413bc0, argumentTypes: ['CDC'], returnType: 'void' },
  drawResultsScreen: { name: 'drawResultsScreen', address: 0x428b70, argumentTypes: ['CDC'], returnType: 'void' },
  drawForecastScreen: { name: 'drawForecastScreen', address: 0x4298f0, argumentTypes: ['CDC'], returnType: 'void' },
};
const profiles = [], cases = [];
const editorProfile = process.argv.includes('--editor');
for (const [profileIndex, selector] of [1, 7, 12, 17, 26, 27].entries()) {
  const inputCase = initializer.data.cases.findIndex(row => row.preparation.selector === selector
    && row.preparation.course === 1 && row.preparation.venue === 0 && row.preparation.boats === 12
    && row.preparation.humans === 1 && row.preparation.stage === 5);
  const input = initializer.data.cases[inputCase];
  if (!input) throw new Error('Missing legitimate original initializer preparation for selector '+selector);
  const profile = { name: 'selector'+selector+'-initialized-screens', selector, inputCase,
    course: 1, venue: 0, stage: 5, humans: 1, boats: 12, width: 1024, height: 768, bitsPixel: 24 };
  profiles.push(profile);
  memory.writeBytes(base, baseline);
  for (const patch of input.patches ?? []) memory.writeBytes(patch.address, Buffer.from(patch.bytes, 'hex'));
  // The original menu speed setter stores three I32 values. The older isolated
  // initializer preparation wrote a harmless F64 here; correct its low word
  // before asking the original coupled screens to use an initialized race.
  memory.writeI32(0x4da174, 8);
  memory.writeI32(0x4da178, 171);
  memory.writeI32(0x4da17c, 171);
  // Configuration boundary fixtures intentionally use the custom-course editor
  // flag. Normal startup keeps the original constructor/default value zero.
  // Keep an explicit optional editor suite rather than confuse the two callers.
  if (!editorProfile) memory.writeI32(0x5364fc, 0);
  for (const object of graphics) memory.writeU32(object.handleAddress, object.handleAddress);
  withX87ControlWord(0x027f, () => configurePaintDimensions(memory,
    { width: profile.width, height: profile.height, bitsPixel: profile.bitsPixel, applicationInstance: 0x400000 }));
  cases.push({ profile: profile.name, phase: 'boat-options', routine: routines.initializeBoatOptions,
    arguments: [], seed: input.seed, patches: differences(memory.readBytes(base, baseline.length)),
    preparation: { inputCase, originalPreparation: input.preparation,
      customCourseEditor: memory.readI32(0x5364fc),
      scope: 'Pre-call input from the legitimate original initialization manifest; the original 420c00 executes before the original 41be70. Normal-start profiles restore the original constructor/default editor flag zero. No captured initialized output or fabricated CString names are supplied.' } });
  cases.push({ profile: profile.name, phase: 'race-initialization', routine: routines.initializeRace,
    continue: true, arguments: [] });
  for (const [screenIndex, name] of ['drawStartScreen', 'drawResultsScreen', 'drawForecastScreen'].entries()) {
    cases.push({ profile: profile.name, phase: name, routine: routines[name], continue: true, arguments: [0],
      host: { menuHeight: 20, cursor: [64 + profileIndex * 11, 72 + screenIndex * 7],
        tickStart: 10000 + profileIndex * 1000 + screenIndex * 100, pixels: [] } });
  }
}
const manifest = {
  source: reference.data.source, sourceSha256, x87ControlWord: '0x027f', mutableBlock: reference.data.mutableBlock,
  routine: routines.drawStartScreen,
  integerInputs: {}, integerOutputs: { selector: 0x4da144, boatClass: 0x4da190,
    course: 0x4da19c, venue: 0x4da1f8, stage: 0x4da1d8, humans: 0x4da140, boats: 0x4da194,
    calibratedWidth: 0x4fe624, calibratedHeight: 0x4fe2a8, menuHeight: 0x4f82fc },
  doubleInputs: {}, doubleOutputs: {}, profiles, cases,
  inputEvidence: {
    initializerManifest: 'analysis/initializeRace-capture-inputs.json', initializerManifestSha256: sha(initializer.bytes),
    baselineFixture: 'tests/fixtures/original-boat-options.json', baselineFixtureSha256: sha(reference.bytes),
    constructorFixture: 'tests/fixtures/original-application.json', constructorFixtureSha256: sha(application.bytes),
    paintCalibrationSource: 'src/render/paint-lifecycle.js',
    paintCalibrationSourceSha256: sha(await readFile(new URL('src/render/paint-lifecycle.js', edition))),
    constructorObjectCount: graphics.length,
    customCourseEditor: editorProfile ? 'Retained original configuration boundary-input flag one' :
      'Original constructor/default value zero at 0x5364fc; the initializer template flag one is a deliberate editor boundary case',
    constructorHandleConvention: 'Each exact original constructor pen/brush uses its own handle-slot address as the declared logical platform handle',
    constructorObjects: graphics.map(({ type, handleAddress, nativeHandle, ...definition }) =>
      ({ type, handleAddress, logicalHandle: handleAddress, ...definition })),
    scope: 'Six genuine original 420c00→41be70→start→results→forecast retained chains with positive 1024×768 original paint calibration. All original calls retain native mutable state, CRT RNG and original semantic CString contents. Initialization populates 30 nonempty original boat names among 35 observed boat-name slots, preserving five original empty spare slots. All active boats have original names. Screen contexts are exactly the retained initialized state, without synthetic finish-order patches. Host tick/cursor/menu and 90 GDI handles are declared platform bindings; no original code bytes are changed.'
  }
};
const destination = editorProfile ? 'analysis/initialized-editor-screens-capture-inputs.json' :
  'analysis/initialized-screens-capture-inputs.json';
await writeFile(new URL(destination, edition), JSON.stringify(manifest, null, 2)+'\n');
console.log(`${profiles.length} original initialization profiles; ${cases.length} original calls; ${graphics.length} constructor GDI bindings`);
