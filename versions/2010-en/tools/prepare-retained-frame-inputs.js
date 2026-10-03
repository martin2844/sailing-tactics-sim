import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';
import { withX87ControlWord } from '../../../src/runtime/float80.js';
import { configurePaintDimensions } from '../src/render/paint-lifecycle.js';

const edition = new URL('../', import.meta.url);
const json = async path => JSON.parse(await readFile(new URL(path, edition), 'utf8'));
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const sourceSha256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (sha(source) !== sourceSha256) throw new Error('Preserved English target differs');
const initializerBytes = await readFile(new URL('analysis/initializeRace-capture-inputs.json', edition));
const initializer = JSON.parse(initializerBytes);
const graphicsProfile = process.argv.includes('--graphics-profile');
const applicationBytes = graphicsProfile ? await readFile(new URL('tests/fixtures/original-application.json', edition)) : undefined;
const application = applicationBytes ? JSON.parse(applicationBytes) : undefined;
if (application && (application.sourceSha256 !== sourceSha256 || !application.provenance.loadedOriginalTextUnchanged))
  throw new Error('Original constructor authority differs');
const graphics = application?.cases[0].expected.events.filter(event => ['createPen', 'createBrush'].includes(event.type)) ?? [];
if (graphicsProfile && graphics.length !== 90) throw new Error('Original constructor object count differs');
const reference = await json('tests/fixtures/original-boat-options.json');
const baseline = Buffer.from(reference.mutableBaseline, 'hex');
const base = reference.mutableBlock.address;
const memory = loadPE32(source);
const patchI32 = (address, value) => {
  const bytes = Buffer.alloc(4); bytes.writeInt32LE(value | 0);
  return { address, bytes: bytes.toString('hex') };
};
const differences = bytes => {
  const result = []; let first = -1, last = -1;
  for (let index = 0; index < bytes.length; index++) if (bytes[index] !== baseline[index]) {
    if (first < 0) first = last = index;
    else if (index - last <= 16) last = index;
    else { result.push({ address: base + first, bytes: Buffer.from(bytes.subarray(first, last + 1)).toString('hex') }); first = last = index; }
  }
  if (first >= 0) result.push({ address: base + first, bytes: Buffer.from(bytes.subarray(first, last + 1)).toString('hex') });
  return result;
};
let profiles = [
  { name: 'standard-course1-prestart', inputCase: 11, stage: 5, humans: 1, boats: 12, view: 2,
    required: { selector: 12, boatClass: 6, course: 1, venue: 0, humans: 1, boats: 12 } },
  { name: 'offshore-course8-started', inputCase: 97, stage: 1, humans: 1, boats: 15, view: 3,
    required: { selector: 14, boatClass: 7, course: 8, venue: 0, humans: 1, boats: 15 } },
  { name: 'coastal-venue5-two-human-started', inputCase: 43, stage: 1, humans: 2, boats: 2, view: 2,
    required: { selector: 12, boatClass: 6, course: 0, venue: 5, humans: 2, boats: 2 } },
];
if (graphicsProfile) profiles = [{ ...profiles[0], name: 'standard-course1-constructor-graphics', constructorGraphics: true }];
const frameRoutine = { name: 'drawSimulationFrame', address: 0x4049f0, argumentTypes: ['CDC'], returnType: 'void' };
const cases = [];
for (const [profileIndex, profile] of profiles.entries()) {
  const input = initializer.cases[profile.inputCase];
  if (!input || input.preparation.selector !== profile.required.selector || input.preparation.venue !== profile.required.venue
      || (profile.required.course !== 0 && input.preparation.course !== profile.required.course)) {
    throw new Error('Explicit original initializer preparation profile differs');
  }
  memory.writeBytes(base, baseline);
  for (const patch of input.patches ?? []) memory.writeBytes(patch.address, Buffer.from(patch.bytes, 'hex'));
  for (const [address, value] of [[0x4da1d8, profile.stage], [0x4da140, profile.humans], [0x4da194, profile.boats],
    [0x4f71c4, profile.view], [0x4da174, 8], [0x4da178, 171], [0x5364e8, 0]]) memory.writeI32(address, value);
  for (const object of graphics) memory.writeU32(object.handleAddress, object.handleAddress);
  withX87ControlWord(0x027f, () => configurePaintDimensions(memory,
    { width: 1024, height: 768, bitsPixel: 24, applicationInstance: 0x400000 }));
  cases.push({ profile: profile.name, phase: 'initialize', routine: initializer.routine,
    arguments: [], seed: input.seed, patches: differences(memory.readBytes(base, baseline.length)),
    preparation: { inputCase: profile.inputCase, source: 'Original initializer input preparation; no captured initialized output substituted',
      requested: { ...profile.required, stage: profile.stage, view: profile.view, speedLevel: 8, speedDivisor: 171,
        width: 1024, height: 768, bitsPixel: 24 } } });
  for (let frame = 0; frame < 100; frame++) cases.push({
    profile: profile.name, phase: 'frame', frame, routine: frameRoutine, continue: true, arguments: [0],
    patches: [patchI32(0x5364e8, frame % 60 + 1)],
    callerInput: { routine: 0x404510, address: 0x5364e8, value: frame % 60 + 1,
      scope: 'Exact original paint caller counter increment/wrap; this is the sole gameplay store supplied between retained original frames' },
    host: { menuHeight: 20, cursor: [64 + frame % 37 + profileIndex * 11, 72 + frame % 29],
      tickStart: 10000 + frame * 100, pixels: Array(1024).fill(0xffffff) },
  });
}
const manifest = {
  source: reference.source, sourceSha256, x87ControlWord: '0x027f', routine: frameRoutine,
  integerInputs: {}, integerOutputs: { time: 0x4f8cd0, selector: 0x4da144, boatClass: 0x4da190,
    course: 0x4da19c, venue: 0x4da1f8, humans: 0x4da140, boats: 0x4da194, paintCounter: 0x5364e8 },
  doubleInputs: {}, doubleOutputs: { preciseTime: 0x5359f0, boat1X: 0x4f6b00, boat1Y: 0x4f6c18 },
  inputEvidence: { initializerManifest: 'analysis/initializeRace-capture-inputs.json', initializerManifestSha256: sha(initializerBytes),
    ...(applicationBytes ? { constructorFixture: 'tests/fixtures/original-application.json', constructorFixtureSha256: sha(applicationBytes),
      constructorObjectCount: graphics.length, constructorHandleConvention: 'Each exact original constructor pen/brush uses its own handle-slot address as the declared logical platform handle' } : {}),
    scope: 'Three original native initializations followed by 100 retained full original frames each. Only the explicitly recorded original paint-caller counter changes between frames. RNG, original data and global CString contents remain native-owned throughout each profile. Tick/cursor/menu/pixel inputs are declared platform bindings; all original numerical and drawing children execute.' },
  profiles, cases,
};
const destination = graphicsProfile ? 'analysis/retained-graphics-frames-capture-inputs.json' : 'analysis/retained-frames-capture-inputs.json';
await writeFile(new URL(destination, edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`${profiles.length} original initialization profiles and ${cases.length - profiles.length} retained complete frames`);
