import {execFileSync} from 'node:child_process';
import {readFile, writeFile, mkdir} from 'node:fs/promises';
import {dirname, resolve} from 'node:path';
import {openBrowser} from '../../../tools/browser-session.js';

if (process.argv.length !== 3) throw new Error('Usage: node versions/2026/tools/device-profile.mjs NEW_REPORT.json');
const output = resolve(process.argv[2]);
const browser = await openBrowser('about:blank', {headless: false, gpu: true, width: 1280, height: 1051});
try {
  await browser.call('Emulation.setDeviceMetricsOverride', {width: 1280, height: 1050, deviceScaleFactor: 1, mobile: false});
  const capabilities = await browser.evaluate(`(() => {
    const canvas = document.createElement('canvas'), gl = canvas.getContext('webgl2');
    const debug = gl?.getExtension('WEBGL_debug_renderer_info');
    return {userAgent: navigator.userAgent, logicalViewport: {width: innerWidth, height: innerHeight},
      pixelRatio: devicePixelRatio, visibility: document.visibilityState,
      webgl2: Boolean(gl), renderer: debug ? gl.getParameter(debug.UNMASKED_RENDERER_WEBGL) : null,
      timerQuery: Boolean(gl?.getExtension('EXT_disjoint_timer_query_webgl2'))};
  })()`);
  const cpu = JSON.parse(execFileSync('lscpu', ['-J']).toString()).lscpu;
  const cpuField = name => cpu.find(row => row.field === name)?.data;
  const os = await readFile('/etc/os-release', 'utf8');
  const report = {task: 'BASE-07', capturedAt: new Date().toISOString(),
    scope: 'Device identity and WebGL capability only; no 2026 performance or touch pass.',
    cpu: {model: cpuField('Model name:'), logicalProcessors: Number(cpuField('CPU(s):'))},
    os: {name: os.match(/^PRETTY_NAME="?(.*?)"?$/m)?.[1], architecture: cpuField('Architecture:')},
    chrome: browser.metadata.version,
    gpu: browser.metadata.systemInfo?.gpu.devices,
    launch: {headless: false, gpu: true, physicalWindow: browser.metadata.window?.bounds,
      sizing: browser.metadata.windowSizing?.status},
    capabilities,
    passed: capabilities.webgl2 && capabilities.logicalViewport.width === 1280 && capabilities.logicalViewport.height === 1050
      && browser.metadata.windowSizing?.status === 'matched',
  };
  await mkdir(dirname(output), {recursive: true});
  await writeFile(output, JSON.stringify(report, null, 2) + '\n', {flag: 'wx'});
  console.log(JSON.stringify(report, null, 2));
  if (!report.passed) process.exitCode = 1;
} finally { await browser.close(); }
