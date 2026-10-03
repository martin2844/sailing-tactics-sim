import { readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { MENU_COMMAND_ROUTINES } from '../src/engine/menu-controller.js';
import { KEYBOARD_ROUTINES } from '../src/engine/keyboard.js';

const edition = new URL('../', import.meta.url);
const sourceBytes = await readFile(new URL('analysis/retained-controller-start-frames-capture-inputs.json', edition));
const template = JSON.parse(sourceBytes);
const profile = 'original-board-menu-and-completed-turns';
const integer = (address, value) => { const bytes = Buffer.alloc(4); bytes.writeInt32LE(value); return { address, bytes: bytes.toString('hex') }; };
const double = (address, value) => { const bytes = Buffer.alloc(8); bytes.writeDoubleLE(value); return { address, bytes: bytes.toString('hex') }; };
const clone = row => ({ ...row, profile });
const cases = [clone(template.cases[0]),
  { profile, phase: 'controller', kind: 2, identifier: 32881, arguments: [], continue: true, patches: [],
    label: 'Actual Board preset menu command', routine: { name: 'handleMenuCommand', address: MENU_COMMAND_ROUTINES[32881], argumentTypes: [], returnType: 'void' } },
  ...Array.from({ length: 2 }, (_, index) => ({ profile, phase: 'controller', kind: 1, identifier: 0,
    arguments: [32, 1, 0], continue: true, patches: [], label: `Original startup Space ${index + 1}`,
    routine: { name: 'handleKeyDown', address: KEYBOARD_ROUTINES.handleKeyDown, argumentTypes: ['I32', 'I32', 'I32'], returnType: 'void' } })),
  ...template.cases.filter(row => row.phase.startsWith('start-')).map(clone)];
const frameTemplate = template.cases.find(row => row.phase === 'frame');
const boundary = [integer(0x4f8cd0, 100), double(0x5359f0, 100), integer(0x534d64, 100)];
for (const [boat, turnMode] of [[2, 1], [3, -1]]) {
  boundary.push(...[[0x4fb380, 10], [0x522e68, turnMode], [0x4f4350, 94], [0x4fad40, 100],
    [0x4fe638, 0], [0x4fe6d0, 0], [0x4f8538, 0], [0x4f4d78, 20000], [0x4fc350, 20000]]
    .map(([address, value]) => integer(address + boat * 4, value)));
}
for (let frame = 0; frame < 3; frame++) cases.push({ ...frameTemplate, profile, label: `Actual original full board frame ${frame}`,
  frame, patches: [...(frame === 0 ? [integer(0x5363b0, 2), ...boundary] : []), integer(0x5364e8, frame + 1)],
  callerInput: { routine: 0x404510, paintCounter: frame + 1,
    scope: frame === 0 ? 'Original stage2 and phase stores, plus one explicitly declared finite completed-turn starting boundary after real native Board initialization.' : 'Only original paint phase counter supplied; state and RNG retained.' },
  host: { menuHeight: 20, cursor: [100, 100], tickStart: 45000 + frame * 100, pixels: Array(1024).fill(0xffffff) } });
const manifest = { ...template, cases, profiles: [{ name: profile, constructorGraphics: true, frames: 3, boardMenuCommand: 32881 }],
  integerOutputs: { ...template.integerOutputs, boardFlag: 0x5363bc, turn2: 0x522e70, turn3: 0x522e74,
    windSpeed2: 0x4fb388, windSpeed3: 0x4fb38c, desiredHeading2: 0x535748, desiredHeading3: 0x53574c },
  inputEvidence: { ...template.inputEvidence, template: 'analysis/retained-controller-start-frames-capture-inputs.json',
    templateSha256: createHash('sha256').update(sourceBytes).digest('hex'),
    scope: 'Real native Board menu and Space/start initializers; three complete original frames with all actual children and 90 constructor objects. The first frame explicitly starts at time100 with two speed10 AI turns at lastTurn94; later only original caller phase changes. This is a finite turn-boundary proof, not a claim that UI events alone fast-forward the race.' } };
await writeFile(new URL('analysis/retained-board-frames-capture-inputs.json', edition), JSON.stringify(manifest, null, 2) + '\n');
console.log(`Prepared ${cases.length} retained original calls with real Board menu/start and three full completed-turn frames`);
