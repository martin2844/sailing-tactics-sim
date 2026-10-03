import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { STEERING_ADDRESSES } from '../src/engine/steering.js';

const edition = new URL('../', import.meta.url);
const source = await readFile(new URL('../../tests/fixtures/original-steering.json', edition));
const originalInputs = JSON.parse(source);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const target = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
const expected = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
if (sha(target) !== expected) throw new Error('Original 2010 executable differs');
const a = STEERING_ADDRESSES;
const integerInputs = Object.fromEntries(Object.keys(originalInputs.inputs).map(field => [field, a[field]]));
const integerOutputs = Object.fromEntries(Object.keys(originalInputs.outputs).map(field => [field, a[field]]));
if (Object.values(integerInputs).some(value => !Number.isInteger(value))) throw new Error('Unknown 2010 steering input');
for (const name of ['updatePlayer1Rudder', 'updatePlayer1Steering', 'updatePlayer2Steering']) {
  const manifest = {
    source: 'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe', sourceSha256: expected,
    routine: { name, address: a[name], argumentTypes: [], returnType: 'I32' },
    x87ControlWord: '0x027f', mutableBlock: { address: 0x4da000, size: 0x60588 },
    integerInputs, integerOutputs,
    doubleInputs: { smoothHeading: a.smoothHeading, steeringScale: a.steeringScale },
    doubleOutputs: { smoothHeading: a.smoothHeading },
    inputEvidence: { fixture: 'tests/fixtures/original-steering.json', sha256: sha(source),
      scope: 'Only finite synthetic inputs are reused. Every expected byte, RNG state and sound request is captured anew from unchanged 2010 code.' },
    cases: originalInputs.routines[name].cases.map((row, index) => ({
      label: `${name}-${index}`, inputs: row.inputs, doubleInputs: row.doubleInputs, seed: (index * 7919 + 2010) >>> 0,
    })),
  };
  await writeFile(new URL(`analysis/${name}-capture-inputs.json`, edition), `${JSON.stringify(manifest, null, 2)}\n`);
  console.log(`${name}: ${manifest.cases.length} finite original-code cases prepared`);
}
