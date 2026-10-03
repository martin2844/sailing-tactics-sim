import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

const edition = new URL('../', import.meta.url);
const inputBytes = await readFile(new URL('analysis/initialized-island-scene-capture-inputs.json', edition));
const input = JSON.parse(inputBytes);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const original = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
if (sha(original) !== input.sourceSha256) throw new Error('Preserved original source differs');
if (input.cases[0].preparation.customCourseEditor !== 0) throw new Error('Normal original initialization recipe required');

const drawChart = { name: 'drawChart', address: 0x407ff0,
  argumentTypes: ['CDC', 'I32', 'I32', 'I32', 'I32', 'I32', 'I32'], returnType: 'void' };
const started = process.argv.includes('--started');
const profile = { ...input.profiles[0], name: 'selector12-course7-initialized-island-charts' + (started ? '-clock-zero' : '') };
const manifest = { ...input, routine: drawChart, profiles: [profile], cases: [
  ...input.cases.slice(0, 2).map(row => ({ ...row, profile: profile.name })),
  ...[
    { phase: 'drawChart-advice-panel', arguments: [0, 0, 361, 341, 723, 1, 2] },
    { phase: 'drawChart-main-panel', arguments: [0, 682, 361, 1024, 723, 1, 1] },
  ].map((row, index) => ({ ...row, profile: profile.name, routine: drawChart, continue: true,
    ...(started && index === 0 ? { patches: [
      { address: 0x4f8cd0, bytes: '00000000' },
      { address: 0x5359f0, bytes: '0000000000000000' },
    ], preparation: { timer: 0, clock: 0,
      scope: 'Explicit bounded post-initialization timer/clock-zero inputs exercise the original layline body. This is an input domain probe, not an elapsed native frame-chain claim; initialized boat geometry, names, flags and RNG remain original.' } } : {}),
    host: { menuHeight: 20, cursor: [64, 72], tickStart: 10000, pixels: [] } })),
], inputEvidence: { ...input.inputEvidence,
  initializedIslandManifest: 'analysis/initialized-island-scene-capture-inputs.json',
  initializedIslandManifestSha256: sha(inputBytes),
  chartCallerSource: 'src/render/paint-lifecycle.js',
  chartCallerSourceSha256: sha(await readFile(new URL('src/render/paint-lifecycle.js', edition))),
  scope: 'Fresh original420c00→41be70→407ff0→407ff0 island initialization and retained chart calls. Both chart argument sets are the original single-player 1024×768 composition panels with calibrated clientHeight723: first advice-panel mode2 (width/3=341), then main-panel mode1 (2*width/3=682). Native initialization determines island flags, boat classes, names and RNG. No original scene, initialized output or retained stack value is supplied. Constructor90 logical GDI objects and positive paint calibration remain the verified original-input recipe.',
  ...(started ? { postInitializationInputs: { '0x4f8cd0': 'I32 timer zero', '0x5359f0': 'F64 clock zero' } } : {}),
} };
await writeFile(new URL(started ? 'analysis/initialized-island-chart-started-capture-inputs.json' : 'analysis/initialized-island-chart-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log('Prepared four genuine original calls with both single-player chart panels');
