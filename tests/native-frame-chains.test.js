import test from 'node:test';
import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { loadPE32 } from '../src/runtime/memory.js';
import { withX87ControlWord } from '../src/runtime/float80.js';
import { PoseyRng } from '../src/engine/integer-core.js';
import { createCapturedTrig } from '../src/engine/native-trig.js';
import { createHullTrig } from '../src/engine/hull-geometry.js';
import { createRawTrig } from '../src/engine/terrain.js';
import { initializeBoatOptions } from '../src/engine/boat-options.js';
import { initializeWindRandomTable } from '../src/engine/wind-initialization.js';
import { initializeRace } from '../src/engine/initialization.js';
import { GdiTrace } from '../src/render/gdi.js';
import { drawScene } from '../src/render/scene.js';
import { getHudText } from '../src/render/hud.js';
import { configurePaintDimensions, drawSimulationFrame } from '../src/render/paint-lifecycle.js';

const json = async path => JSON.parse(await readFile(new URL(path, import.meta.url), 'utf8'));
const [original, fixture, tables, extended, stored, force, hull, raw, handles] = await Promise.all([
  readFile(new URL('../original/Tact02Demo.exe', import.meta.url)), json('./fixtures/original-native-frame-chains-p53.json'),
  json('../assets/data/pc53/trig-tables.json'), json('../assets/data/pc53/x87-trig.json'),
  json('../assets/data/pc53/x87-stored-trig.json'), json('../assets/data/pc53/x87-force-trig.json'),
  json('../assets/data/pc53/x87-hull-trig.json'), json('../assets/data/pc53/x87-raw-trig.json'),
  json('../analysis/gdi-object-definitions.json'),
]);
const hash = value => createHash('sha256').update(value).digest('hex');
const bytes = value => Uint8Array.from(Buffer.from(value, 'hex'));
const reference = { trig: createCapturedTrig(extended, stored, force), hullTrig: createHullTrig(hull), rawTrig: createRawTrig(raw) };
const block = fixture.mutableBlock;
function writeTrig(memory) {
  tables.sine.forEach((value,index) => memory.writeI32(0x4a54a0+index*4,value));
  tables.cosine.forEach((value,index) => memory.writeI32(0x4a3450+index*4,value));
}
function prepare(profile) {
  const memory = loadPE32(original);
  writeTrig(memory); // Native runner's declared original415a60 bootstrap.
  const fields = [[0x491144,profile.selector],[0x491194,profile.course],[0x4a4958,0],
    [0x491140,profile.humans],[0x49118c,5],[0x4a4e8c,profile.view],[0x4a4e90,profile.view],
    [0x4a5a4c,0],[0x49116c,8],[0x491170,171],[0x491178,8],[0x491174,171],
    [0x4911cc,profile.startMode],[0x4a763c,1024],[0x4a3f84,1024],[0x4a3f04,768],
    [0x4aaa1c,24],[0x4ac8f8,2],[0x4ac1d4,0x400000]];
  for(const [address,value] of fields) memory.writeI32(address,value);
  for(const definition of handles.objects) memory.writeU32(definition.handleAddress,definition.handleAddress);
  return memory;
}
function updateExpected(state,expected,label) {
  for(const change of expected.imageChanges) {
    const offset=change.address-block.address;
    assert.equal(Buffer.from(state.slice(offset,offset+change.before.length/2)).toString('hex'),change.before,`${label}: retained native beforebytes`);
    state.set(bytes(change.after),offset);
  }
  assert.equal(hash(state),expected.mutableBlockHash,`${label}: recorded complete native state hash`);
}
function assertState(memory,expected,label) {
  const actual=memory.readBytes(block.address,block.size);
  const offset=actual.findIndex((value,index)=>value!==expected[index]);
  assert.equal(offset,-1,`${label}:0x${(block.address+offset).toString(16)} actual=${Buffer.from(actual.slice(offset,offset+16)).toString('hex')} expected=${Buffer.from(expected.slice(offset,offset+16)).toString('hex')}`);
}

test('retained native chains use genuine normalized courses, actual startup precision and unchanged original instructions',async()=>{
  assert.equal(fixture.provenance.sha256,hash(original));
  assert.equal(fixture.provenance.authoritative_engine,'native-original-2002');
  assert.equal(fixture.provenance.x87_control_word,'0x027f');
  assert.match(fixture.provenance.note,/No CPU emulation and no JavaScript output/);
  assert.deepEqual(fixture.initializationCallOrder,[0x415a60,0x42e080,0x417790,0x403c62,0x413f00]);
  assert.deepEqual(fixture.profiles.map(profile=>profile.actualConfiguration.course),[1,8,6]);
  assert.deepEqual(fixture.profiles.map(profile=>profile.actualConfiguration.boatClass),[6,7,6]);
  assert.deepEqual(fixture.profiles.map(profile=>profile.actualConfiguration.weather),[0,0,5]);
  for(const profile of fixture.profiles) {
    assert.equal(profile.frames.length,100);
    assert.equal(profile.frames.filter(frame=>frame.snapshotRequest).length,1);
    assert.equal(profile.actualConfiguration.humans,profile.humans);
  }
  const report=await json('../analysis/native-frame-chains-p53-reference-comparison.json');
  assert.equal(report.capture_complete,true);
  assert.equal(report.comparison_complete,true);assert.equal(report.all_fixture_cases_match,true);
  assert.deepEqual(report.differences,[]);
  assert.equal(report.fixture_sha256['original-native-frame-chains-p53.json'],hash(await readFile(new URL('./fixtures/original-native-frame-chains-p53.json',import.meta.url))));
  assert.equal(report.native_initializations,3);assert.equal(report.retained_native_frames,300);
  assert.equal(report.loaded_original_text_unchanged,true);assert.equal(report.original_file_unchanged,true);
  assert.equal(report.process_exit_code,0);
});

for(const profile of fixture.profiles) test(`${profile.name}: fresh original initialization then100 retained native frames, every game byte/RNG/drawing/sound/HUD/timer`,()=>{
  const memory=prepare(profile),rng=new PoseyRng(profile.seed),expected=bytes(profile.preparedBeforeBlock);
  assertState(memory,expected,`${profile.name} independently reconstructed prepared input`);
  const sounds=[];
  withX87ControlWord(0x027f,()=>{
    writeTrig(memory);
    initializeWindRandomTable(memory,rng);
    initializeBoatOptions(memory);
    configurePaintDimensions(memory,{width:1024,height:768,bitsPixel:24,applicationInstance:0x400000});
    initializeRace(memory,rng,{...reference,playSound:request=>{sounds.push(request);return 1;}});
    memory.writeI32(0x4aa980,0); // Declared normal start-UI event, also applied by native host.
  });
  updateExpected(expected,profile.initialization.expected,`${profile.name} initialization`);
  assertState(memory,expected,`${profile.name} initialization`);
  assert.equal(rng.state,profile.initialization.expected.rngState);
  assert.deepEqual(sounds,profile.initialization.expected.sounds);
  assert.equal(profile.initialization.expected.drawingCommands.length,0);
  for(const frame of profile.frames) {
    const label=`${profile.name} frame${frame.index}`;
    if(frame.snapshotRequest){memory.writeI32(0x4ac9ec,1);new DataView(expected.buffer,expected.byteOffset,expected.byteLength).setInt32(0x4ac9ec-block.address,1,true);}
    updateExpected(expected,frame.expected,label);
    let pixel=0,scene=0,duration=0;sounds.length=0;
    const dc=new GdiTrace({readPixel:()=>{assert.ok(pixel<frame.pixelReadValues.length,`${label} GetPixel bound`);return frame.pixelReadValues[pixel++];}});
    const options={...reference,cursor:frame.cursor,
      messageBeep:type=>dc.emit({op:'messageBeep',type}),
      playSound:request=>{sounds.push(request);return 1;},
      enforceMinimumPaintDuration:value=>{duration=value;},
      drawScene:(sceneMemory,sceneDc,...args)=>{
        const sceneOptions=args.pop(),observed=frame.shorelineStackObservations[scene++];
        assert.ok(observed,`${label} shoreline observations bound`);
        assert.equal(args[args.length-1],observed.camera,`${label} original camera order`);
        drawScene(sceneMemory,sceneDc,...args,{...sceneOptions,shorelineStack:{...observed}});
      },
    };
    withX87ControlWord(0x027f,()=>drawSimulationFrame(memory,dc,rng,options));
    assertState(memory,expected,label);
    assert.equal(rng.state,frame.expected.rngState,`${label} RNG`);
    assert.deepEqual(sounds,frame.expected.sounds,`${label} ordered sounds`);
    assert.deepEqual(dc.events,frame.expected.drawingCommands,`${label} ordered original GDI requests`);
    assert.equal(getHudText(memory),frame.expected.hudText,`${label} native CRT/CString HUD`);
    assert.equal(duration,frame.expected.elapsedPaintTicks,`${label} timer delay`);
    assert.equal(pixel,frame.pixelReadValues.length,`${label} consumed GetPixel count`);
    assert.equal(scene,frame.shorelineStackObservations.length,`${label} consumed shoreline observations`);
  }
});
