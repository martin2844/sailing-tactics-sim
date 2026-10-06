import {readFile, mkdir, writeFile} from 'node:fs/promises';
import {gzipSync} from 'node:zlib';
import {resolve} from 'node:path';
import {fileURLToPath} from 'node:url';
import {openBrowser} from '../../../../tools/browser-session.js';
import {referenceSession, closeReferenceServer} from '../reference-session.mjs';
import {withReferenceBuild} from './reference-build.mjs';
import {withCutoverServer} from './server.mjs';

const app = fileURLToPath(new URL('../../', import.meta.url));
const output = resolve(process.argv[2] ?? '');
if (process.argv.length !== 3) throw new Error('Usage: evaluate.mjs NEW_OUTPUT_DIRECTORY');
await mkdir(output); // Refuse to overwrite previously accepted evidence.
const pin = JSON.parse(await readFile(new URL('../../config/cutover-reference.json', import.meta.url), 'utf8'));
const report = {format: 1, passed: false, reference: pin, pairs: [], frozen2010: [], scope: 'Bounded cutover/observer acceptance; not completed extraction, full feature coverage or graphics performance.'};

async function installClient(browser) {
  await browser.evaluate('(async()=>{globalThis.CutoverClient=(await import("/client.mjs")).CutoverClient;})()');
}

async function runPair(browser, artifacts, settings, fleet, actualRace) {
  const init = JSON.stringify({artifacts, settings, fleet});
  await browser.evaluate(`(async()=>{
    const {artifacts,settings,fleet}=${init};
    globalThis.cutoverClients=[
      new CutoverClient('/reference/'+artifacts.reference.file,1),
      new CutoverClient('/candidate/'+artifacts.candidate.file,2),
      new CutoverClient('/candidate/'+artifacts.candidate.file,3),
    ];
    try {
      await cutoverClients[0].initialize('reference',settings,fleet);
      await cutoverClients[1].initialize('candidate',settings,fleet);
      await cutoverClients[2].initialize('candidate',settings,fleet,true);
    }catch(error){cutoverClients.forEach(c=>c.dispose());throw error;}
    globalThis.compareCutover=async label=>{
      const images=await Promise.all(cutoverClients.map(c=>c.request('image')));
      const boundaries=await Promise.all(cutoverClients.map(c=>c.request('boundary')));
      for(let lane=1;lane<images.length;lane++){
        const a=images[0],b=images[lane];
        if(a.length!==b.length)throw Error('Image length mismatch');
        for(let i=0;i<a.length;i++)if(a[i]!==b[i]){
          globalThis.cutoverFailure={label,lane,address:'0x'+(0x400000+i).toString(16),reference:a[i],candidate:b[i],boundaries};
          throw Error('Cutover differs at '+cutoverFailure.address+' / '+label+' / lane '+lane);
        }
        if(JSON.stringify(boundaries[0])!==JSON.stringify(boundaries[lane])){
          globalThis.cutoverFailure={label,lane,boundaries};throw Error('Cutover context differs: '+label);
        }
      }
      return {label,boundaries,matched:true};
    };
  })()`);
  const boundaries = [], traces = [];
  try {
    boundaries.push(await browser.evaluate('compareCutover("initial")'));
    for (let stage = 0; stage < 4; stage++) {
      if (stage > 0) {
        const command = [32842, 32841, 32846][stage - 1];
        await browser.evaluate(`cutoverClients.forEach(c=>c.send('command',${command}))`);
      }
      await browser.evaluate('Promise.all(cutoverClients.map(c=>c.request("step",8)))');
      boundaries.push(await browser.evaluate(`compareCutover('prestart-${stage}')`));
    }
    if (actualRace) {
      await browser.evaluate('cutoverClients.forEach(c=>{for(let n=0;n<6;n++)c.send("key",33)})');
      for (let stage = 0; stage < 3; stage++) {
        await browser.evaluate('Promise.all(cutoverClients.map(c=>c.request("step",200)))');
        boundaries.push(await browser.evaluate(`compareCutover('accelerated-race-${stage}')`));
      }
      const clock = await browser.evaluate('cutoverClients[0].last.clock');
      if (clock < 0) throw new Error('Actual race coverage did not leave prestart');
    }
    await browser.evaluate('cutoverClients[2].request("trace-start")');
    await browser.evaluate('Promise.all(cutoverClients.map(c=>c.request("step",2)))');
    const trace = await browser.evaluate('cutoverClients[2].request("trace-stop")');
    if (trace.truncated || !trace.records.some(r => r.name === 'drawScene') || !trace.records.some(r => r.name === 'integratePositions')) {
      throw new Error('Incomplete phase ledger');
    }
    traces.push(trace);
    boundaries.push(await browser.evaluate('compareCutover("traced-two-steps")'));
    const phaseTotals = {};
    for (const record of trace.records) {
      const totals = phaseTotals[record.name] ??= {calls: 0, randomCalls: 0, pixelQueries: 0, observedWrites: 0, changedWords: 0};
      totals.calls++;
      totals.randomCalls += record.randomCalls;
      totals.pixelQueries += record.pixels.length;
      totals.observedWrites += record.writes.reduce((count, access) => count + access.count, 0);
      totals.changedWords += record.netChangedWords.length;
    }
    return {settings, fleet, actualRace, boundaries, traces, phaseTotals};
  } finally {
    await browser.evaluate('cutoverClients?.forEach(c=>c.dispose())');
  }
}

async function runFrozenLane(browser, artifact, fleet) {
  const original = await referenceSession({fleet, headless: true});
  try {
    await original.command(32850);
    await browser.evaluate(`(async()=>{
      globalThis.nativeCandidate=new CutoverClient('/candidate/'+${JSON.stringify(artifact.file)},19);
      await nativeCandidate.initialize('candidate',{course:1,wind:2},${fleet},false,false);
    })()`);
    const boundaries = [];
    async function compare(label) {
      const native = {...await original.snapshot(), shore: await original.browser.evaluate('tact.state.options.shoreStack.snapshot()')};
      const candidate = await browser.evaluate('nativeCandidate.request("boundary")');
      const fields = ['frame','time','clock','rngState','memorySha256','shore'];
      for (const field of fields) if (JSON.stringify(native[field]) !== JSON.stringify(candidate[field])) throw new Error('Frozen 2010 differs: ' + fleet + '/' + label + '/' + field);
      boundaries.push({label, native, candidate, matched: true});
    }
    await compare('initial');
    for (let stage = 0; stage < 4; stage++) {
      if (stage > 0) {
        const command = [32842,32841,32846][stage - 1];
        await original.command(command);
        await browser.evaluate(`nativeCandidate.send('command',${command})`);
      }
      for (let step = 0; step < 8; step++) {
        await original.step('cutover frozen lane');
        await browser.evaluate('nativeCandidate.request("step",1)');
      }
      await compare('step-' + ((stage + 1) * 8));
    }
    return {fleet, boundaries, modules: await original.modules(), scope: 'Frozen 2010 initial/32-paint native behavior, geometry contacts disabled; not intentional 2026 policy parity.'};
  } finally {
    await browser.evaluate('globalThis.nativeCandidate?.dispose()').catch(() => {});
    await original.close();
  }
}

try {
  await withReferenceBuild(pin.commit, async reference => {
    report.referenceRevision = reference.revision;
    await withCutoverServer(resolve(app, 'dist'), reference.dist, async ({url, artifacts}) => {
      report.artifacts = artifacts;
      const browser = await openBrowser(url, {headless: true, gpu: true, requestTimeoutMs: 120000});
      try {
        await installClient(browser);
        for (const scenario of [
          {settings: {course:1,wind:2},fleet:5,race:true},
          {settings: {course:1,wind:2},fleet:15,race:false},
          {settings: {boat:11,area:32799,course:1,wind:3},fleet:5,race:true},
          {settings: {boat:1,area:32801,course:1,wind:2,windDirection:270},fleet:5,race:true},
        ]) {
          const result = await runPair(browser, artifacts, scenario.settings, scenario.fleet, scenario.race);
          report.pairs.push(result);
          await writeFile(resolve(output, 'progress.json'), JSON.stringify({...report,pairs:report.pairs.map(({traces,...pair})=>pair)}, null, 2));
          console.log(JSON.stringify({settings: scenario.settings, fleet: scenario.fleet, matched: result.boundaries.length, phases: result.traces[0].records.length}));
        }
        for (const fleet of [5,15]) {
          report.frozen2010.push(await runFrozenLane(browser, artifacts.candidate, fleet));
          console.log(JSON.stringify({frozen2010: fleet, passed: true}));
        }
      } catch (error) {
        report.firstDivergence = await browser.evaluate('globalThis.cutoverFailure ?? null').catch(() => null);
        throw error;
      } finally { await browser.close(); }
    });
  });
  report.passed = true;
} catch (error) {
  report.failure = error.stack;
  process.exitCode = 1;
} finally {
  await closeReferenceServer();
  const ledgers = report.pairs.map(({settings,fleet,traces}) => ({settings,fleet,traces}));
  await writeFile(resolve(output, 'phase-ledgers.json.gz'), gzipSync(JSON.stringify(ledgers)));
  const summary = {...report,pairs: report.pairs.map(({traces,...pair}) => pair)};
  await writeFile(resolve(output, 'verification.json'), JSON.stringify(summary, null, 2));
}
console.log(JSON.stringify({passed: report.passed, failure: report.failure, pairs: report.pairs.length, frozenLanes: report.frozen2010.length}));
