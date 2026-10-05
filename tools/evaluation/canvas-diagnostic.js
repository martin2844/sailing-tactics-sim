import {mkdir,writeFile,readFile} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {resolve,join} from 'node:path';
import {runScenario} from './run-scenario.js';
import {getScenario} from './scenarios.js';
import {summarizeRun} from './metrics.js';

const modes=['original','front-software','flush-one','pixel-copy','software-atlas'];
const selected=process.argv[2]?process.argv[2].split(','):modes;
if(selected.some(mode=>!modes.includes(mode)))throw new Error('Unknown Canvas diagnostic mode');
const directory=resolve(process.argv[3]??`versions/2010-en/analysis/evaluation/canvas-diagnostic-${new Date().toISOString().replace(/[:.]/g,'-')}`);
await mkdir(directory,{recursive:true});
const scenario=getScenario('matched-round-lake-15');
const median=values=>{const sorted=values.slice().sort((a,b)=>a-b);return sorted[Math.floor(sorted.length/2)];};
const report={scope:'Instrumented Canvas investigation; excluded from performance acceptance. pixel-copy replaces alpha rather than compositing and is an experiment only.',runs:[]};
report.playerSha256=createHash('sha256').update(await readFile('versions/2010-en/src/play.js')).digest('hex');
for(const mode of selected){
  console.log(`Canvas diagnostic: ${mode}`);
  const script=`(()=>{
    const mode=${JSON.stringify(mode)};
    globalThis.canvasDiagnostics={mode,rows:[],contextAttributes:{}};
    const getContext=HTMLCanvasElement.prototype.getContext;
    HTMLCanvasElement.prototype.getContext=function(type,options){
      if(type==='2d'&&this.id==='race'&&mode==='front-software')options={...options,willReadFrequently:true};
      if(type==='2d'&&this.id!=='race'&&mode==='software-atlas')options={...options,willReadFrequently:true};
      const context=getContext.call(this,type,options);
      if(type==='2d'&&context)canvasDiagnostics.contextAttributes[this.id==='race'?'front':'buffer']=context.getContextAttributes();
      return context;
    };
    const draw=CanvasRenderingContext2D.prototype.drawImage;
    CanvasRenderingContext2D.prototype.drawImage=function(source,...args){
      if(this.canvas.id!=='race')return draw.call(this,source,...args);
      canvasDiagnostics.contextAttributes.actualBuffer=source.getContext('2d').getContextAttributes();
      const start=performance.now();let readMs=0,copyMs=0,transparent;
      if(mode==='flush-one'){
        source.getContext('2d').getImageData(0,0,1,1);readMs=performance.now()-start;
      }else if(mode==='pixel-copy'){
        const pixels=source.getContext('2d').getImageData(0,0,source.width,source.height);
        readMs=performance.now()-start;
        const copied=performance.now();this.putImageData(pixels,0,0);copyMs=performance.now()-copied;
        if(evaluationMeasuring){transparent=0;for(let i=3;i<pixels.data.length;i+=4)if(pixels.data[i]!==255)transparent++;}
      }
      if(mode!=='pixel-copy'){const copied=performance.now();draw.call(this,source,...args);copyMs=performance.now()-copied;}
      if(evaluationMeasuring)canvasDiagnostics.rows.push({frame:tact.state.frames+1,readMs,copyMs,totalMs:readMs+copyMs,nonOpaquePixels:transparent});
    };
  })();`;
  const run=await runScenario({edition:'2010',scenario,frames:40,warmup:20,outputDir:join(directory,mode),diagnostic:{label:mode,script}});
  const observations=run.diagnostic.observations;
  const summary=summarizeRun({samples:run.samples,presentation:run.presentation,expected:run.expected,controlled:scenario.controlled});
  const row={mode,raw:run.reportPath,validation:run.validation,summary,host:run.host,
    contextAttributes:observations.contextAttributes,canvas:run.actual.canvas,
    stageMedian:Object.fromEntries(['readMs','copyMs','totalMs'].map(key=>[key,median(observations.rows.map(row=>row[key]))])),
    nonOpaquePixels:observations.rows.map(row=>row.nonOpaquePixels).filter(value=>value!==undefined)};
  report.runs.push(row);await writeFile(join(directory,'report.json'),JSON.stringify(report,null,2)+'\n');
  console.log(JSON.stringify({mode,paintP95:summary.paintDuration?.p95,...row.stageMedian}));
}
console.log(`Canvas diagnostic report: ${directory}/report.json`);
