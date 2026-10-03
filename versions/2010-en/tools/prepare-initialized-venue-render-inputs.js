import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../../../src/runtime/memory.js';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const inputBytes = await readFile(new URL('analysis/initialized-screens-capture-inputs.json', edition));
const input = JSON.parse(inputBytes);
const baselineBytes = await readFile(new URL('tests/fixtures/original-boat-options.json', edition));
const reference = JSON.parse(baselineBytes);
const original = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
if (sha(original) !== input.sourceSha256 || reference.sourceSha256 !== input.sourceSha256)
  throw new Error('Preserved source or native baseline differs');
const recipe = input.cases.find(row => row.phase === 'boat-options' && row.profile === 'selector12-initialized-screens');
if (!recipe || recipe.preparation.customCourseEditor !== 0) throw new Error('Normal original startup input required');
const base = reference.mutableBlock.address, baseline = Buffer.from(reference.mutableBaseline, 'hex');
const memory = loadPE32(original), profiles = [], cases = [];
const scene = { name: 'drawScene', address: 0x405320,
  argumentTypes: ['CDC', 'I32', 'I32', 'I32', 'I32', 'I32'], returnType: 'void' };
const chart = { name: 'drawChart', address: 0x407ff0,
  argumentTypes: ['CDC', 'I32', 'I32', 'I32', 'I32', 'I32', 'I32'], returnType: 'void' };
for (const venue of [2, 6, 9, 106]) {
  memory.writeBytes(base, baseline);
  for (const patch of recipe.patches) memory.writeBytes(patch.address, Buffer.from(patch.bytes, 'hex'));
  memory.writeI32(0x4da1f8, venue);
  const prepared = memory.readBytes(base, baseline.length), patches = [];
  let first = -1, last = -1;
  for (let index = 0; index < prepared.length; index++) if (prepared[index] !== baseline[index]) {
    if (first < 0) first = last = index;
    else if (index - last <= 16) last = index;
    else { patches.push({ address: base + first, bytes: Buffer.from(prepared.subarray(first, last + 1)).toString('hex') }); first = last = index; }
  }
  if (first >= 0) patches.push({ address: base + first, bytes: Buffer.from(prepared.subarray(first, last + 1)).toString('hex') });
  const profile = { name: `selector12-venue${venue}-initialized-render`, selector: 12, venue,
    course: 1, boats: 12, humans: 1, stage: 5, width: 1024, height: 768, bitsPixel: 24 };
  profiles.push(profile);
  cases.push({ ...recipe, profile: profile.name, patches,
    preparation: { ...recipe.preparation, requestedVenue: venue,
      scope: 'Verified selector12 normal initialized-screen recipe, with only the supported pre-initialization venue selection changed. Original options/race initializer computes venue geometry, flags, names and RNG; no final native output or stack data is supplied.' } });
  cases.push({ profile: profile.name, phase: 'race-initialization',
    routine: { name: 'initializeRace', address: 0x41be70, argumentTypes: [], returnType: 'void' }, continue: true, arguments: [] });
  cases.push({ profile: profile.name, phase: 'drawScene', routine: scene, continue: true,
    arguments: [0, 0, 0, 1024, 361, 1],
    host: { menuHeight: 20, cursor: [64, 72], tickStart: 10000, pixels: Array(1024).fill(0xffffff) } });
  cases.push({ profile: profile.name, phase: 'drawChart', routine: chart, continue: true,
    arguments: [0, 682, 361, 1024, 723, 1, 1], host: { menuHeight: 20, cursor: [64, 72], tickStart: 10000, pixels: [] } });
}
const manifest = { ...input, routine: scene, profiles, cases,
  integerOutputs: { ...input.integerOutputs, island: 0x4f8b78, flag4fb5d4: 0x4fb5d4 },
  inputEvidence: { ...input.inputEvidence,
    initializedScreensManifest: 'analysis/initialized-screens-capture-inputs.json', initializedScreensManifestSha256: sha(inputBytes),
    baselineFixtureSha256: sha(baselineBytes),
    scope: 'Four fresh original options→race→scene→chart retained chains across supported venues2/6/9/106. All geometry and names come from the unchanged original initializer. Positive original1024×768 paint calibration and all90 constructor object handles are declared platform inputs. GetPixel white values are explicit synthetic observations, not raster equivalence. No retained stack inputs or captured output substitutions.',
  } };
await writeFile(new URL('analysis/initialized-venue-render-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`${profiles.length} initialized venues; ${cases.length} original calls`);
