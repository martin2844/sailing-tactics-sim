import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { KEYBOARD_ROUTINES } from '../src/engine/keyboard.js';
import { MENU_COMMAND_ROUTINES, MENU_UPDATE_ROUTINES } from '../src/engine/menu-controller.js';
import { loadPE32 } from '../../../src/runtime/memory.js';

const edition = new URL('../', import.meta.url);
const sha = bytes => createHash('sha256').update(bytes).digest('hex');
const inputBytes = await readFile(new URL('analysis/retained-graphics-frames-capture-inputs.json', edition));
const input = JSON.parse(inputBytes);
const source = await readFile(new URL('runtime/Tactics2010EnglishPreserved.exe', edition));
if (sha(source) !== input.sourceSha256) throw new Error('Preserved English original differs');
const boatOptions = JSON.parse(await readFile(new URL('analysis/boat-options-capture-inputs.json', edition), 'utf8')).routine;
const profile = input.profiles[0];
const island = process.argv.includes('--island');
const constructorDefaults = process.argv.includes('--constructor-defaults');
const frameCount = island ? 10 : 25;
if (island) {
  profile.name = 'course1-to-round-island-constructor-graphics';
  profile.transition = { command: 32801, initialCourse: 1, startedCourse: 7, startedBoatClass: 6,
    originalConfigurationControl: { address: 0x4da188, value: 3 }, island: 1 };
}
if (constructorDefaults) profile.name += '-normal-start';
const initialize = input.cases.find(row => row.phase === 'initialize');
initialize.profile = profile.name;
const frameRoutine = input.routine;
const cases = [{ ...initialize, label: 'Original initialized start-screen state with 90 constructor objects' }];
const patchI32 = (address, value) => {
  const bytes = Buffer.alloc(4); bytes.writeInt32LE(value);
  return { address, bytes: bytes.toString('hex') };
};
if (constructorDefaults) {
  if (loadPE32(source).readI32(0x5364fc) !== 0) throw new Error('Original custom-editor default differs');
  cases[0].patches = [...cases[0].patches, patchI32(0x5364fc, 0)];
}
const controller = (kind, identifier, args, label) => cases.push({
  profile: profile.name, phase: 'controller', label, kind, identifier, arguments: args,
  continue: true, patches: [],
  routine: { name: kind === 1 ? 'handleKeyDown' : kind === 2 ? 'handleMenuCommand' : 'menuCommandState',
    address: kind === 1 ? KEYBOARD_ROUTINES.handleKeyDown : (kind === 2 ? MENU_COMMAND_ROUTINES : MENU_UPDATE_ROUTINES)[identifier],
    argumentTypes: args.map(() => 'I32'), returnType: 'void' },
});
const key = (value, label) => controller(1, 0, [value, 1, 0], label);
const command = (value, label) => controller(2, value, [], label);
const state = value => controller(3, value, [], `Original menu enable/check state for command ${value}`);

// These are genuine original handlers. The following original paint prefix
// invokes both initializers before its single stage=2 store and first frame.
if (island) { command(32801, 'Original Round the Island course command while the startup menu is enabled'); state(32801); }
key(32, 'Space: dismiss/start through the original keyboard handler');
key(32, 'Space: original start request');
cases.push({ profile: profile.name, phase: 'start-options', label: 'Original 404510 start branch: 420c00',
  routine: boatOptions, arguments: [], continue: true, patches: [] });
cases.push({ profile: profile.name, phase: 'start-initialize', label: 'Original 404510 start branch: 41be70',
  routine: initialize.routine, arguments: [], continue: true, patches: [] });

for (let frame = 0; frame < frameCount; frame++) {
  if (frame === 2) key(37, 'Player 1 turns left through the original handler');
  if (frame === 5) key(39, 'Player 1 turns right through the original handler');
  if (frame === 8) { command(32825, 'Original view 1 menu command'); state(32825); }
  if (frame === 10) { command(32827, 'Original view 3 menu command'); state(32827); }
  if (frame === 12) { command(32826, 'Original view 2 menu command'); state(32826); }
  if (frame === 13) {
    key(70, 'Freeze repaint requests through the original F handler');
    key(70, 'Resume through the original F handler; no frame is called while frozen');
  }
  if (frame === 16) key(8, 'Backspace requests the original saved-state restore');
  if (frame === 18) key(70, 'Resume after the original restored-state notification freezes repainting');
  const stage = frame === 0 ? [patchI32(0x5363b0, 2)] : [];
  cases.push({ profile: profile.name, phase: 'frame', label: `Original full frame ${frame}`, frame,
    routine: frameRoutine, arguments: [0], continue: true,
    patches: [...stage, patchI32(0x5364e8, frame + 1)],
    callerInput: {
      routine: 0x404510,
      stores: [...(frame === 0 ? [{ address: 0x5363b0, value: 2,
        scope: 'Original start branch store after the actual 420c00 and 41be70 calls' }] : []),
      { address: 0x5364e8, value: frame + 1, scope: 'Original paint-caller counter increment' }],
    },
    host: { menuHeight: 20, cursor: [80 + frame, 96 + frame % 17],
      tickStart: 30000 + frame * 100, pixels: Array(1024).fill(0xffffff) },
  });
}
const manifest = { ...input, cases,
  integerOutputs: { ...input.integerOutputs, stage: 0x5363b0, frozen: 0x53642c,
    view: 0x4f71c4, steering1: 0x4f49a4, snapshotRequest: 0x5364ac, heading1: 0x4fbb94,
    island: 0x4f8b78, shorelineVariant: 0x50040c, configurationControl4da188: 0x4da188 },
  inputEvidence: { ...input.inputEvidence,
    sourceManifest: 'analysis/retained-graphics-frames-capture-inputs.json', sourceManifestSha256: sha(inputBytes),
    customCourseEditor: constructorDefaults ? 'Original preserved image/constructor default0 at5364fc; initializer template1 is an explicit custom-editor boundary.' : 'Initializer template custom-editor boundary1 at5364fc.',
    transport: 'Fixed command2 controllers interleaved with unchanged original initializer/frame calls; original CString and RNG lifetimes remain retained.',
    scope: 'Original initialized startup, actual Space handlers, actual 420c00→41be70 start prefix, and one explicitly supplied original 404510 stage=2 caller store before the first frame. Later frames receive only the original phase counter. Genuine keyboard/menu/CCmdUI handlers change retained game state; all frames execute actual AI/dynamics/integration/render children.',
  },
};
const destination = island ? (constructorDefaults ? 'analysis/retained-island-controller-start-frames-capture-inputs.json'
  : 'analysis/retained-island-controller-frames-capture-inputs.json') : (constructorDefaults
  ? 'analysis/retained-controller-start-frames-capture-inputs.json' : 'analysis/retained-controller-frames-capture-inputs.json');
await writeFile(new URL(destination, edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`${cases.length} original retained calls: ${cases.filter(row => row.phase === 'frame').length} frames and ${cases.filter(row => row.kind).length} real controller handlers`);
