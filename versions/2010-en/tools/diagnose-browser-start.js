import { openBrowser } from '../../../tools/browser-session.js';
import { writeFile } from 'node:fs/promises';
import { setTimeout as pause } from 'node:timers/promises';

const browser = await openBrowser(process.env.TACT_2010_URL ?? 'http://127.0.0.1:8765/versions/2010-en/play.html');
const snapshots = [];
try {
  await browser.waitFor('globalThis.tact?.state.ready&&tact.state.frames>0||globalThis.tact?.state.error', 60000);
  const inspect = async label => {
    const value = await browser.evaluate(`(()=>{const m=tact.state.memory;return{
      frames:tact.state.frames,error:tact.state.error,app:m.readI32(0x5363b0),
      mode:m.readI32(0x4da16c),notice:m.readI32(0x53648c),paused:m.readI32(0x536444),
      frozen:m.readI32(0x53642c),forecast:m.readI32(0x5363f0),result:m.readI32(0x5363f4),
      chart:m.readI32(0x5233a8),current:m.readI32(0x536434),tide:m.readI32(0x536438),
      speed:m.readI32(0x4da174),preciseTime:m.readF64(0x5359f0),clock:m.readI32(0x4f8cd0)}})()`);
    snapshots.push({ label, ...value });
    console.log(JSON.stringify(snapshots.at(-1)));
    return value;
  };
  const space = async () => {
    await browser.evaluate('document.getElementById("race").focus()');
    await browser.call('Input.dispatchKeyEvent', { type: 'keyDown', code: 'Space', key: ' ', windowsVirtualKeyCode: 32, nativeVirtualKeyCode: 32 });
    await browser.call('Input.dispatchKeyEvent', { type: 'keyUp', code: 'Space', key: ' ', windowsVirtualKeyCode: 32, nativeVirtualKeyCode: 32 });
  };
  await inspect('initial');
  await space();
  await browser.waitFor('tact.state.memory.readI32(0x5363b0)===2||tact.state.memory.readI32(0x53648c)===1||tact.state.error', 60000);
  const value = await inspect('after-first-space');
  if (value.paused > 0 || value.forecast === 1 || value.app === 0 && value.notice === 1) {
    await space();
    await pause(1000);
    await inspect('after-required-dismissal');
  }
  await pause(2000);
  await inspect('later');
  await writeFile(new URL('../analysis/browser-start-probe.json', import.meta.url), JSON.stringify({
    snapshots, exceptions: browser.events.filter(event => event.method === 'Runtime.exceptionThrown'),
  }, null, 2) + '\n');
} finally { await browser.close(); }
