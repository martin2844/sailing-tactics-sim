// Supplementary guard checks against the retained extended-exponent implementation.
import {readFileSync,writeFileSync} from 'node:fs';
import {loadPE32} from '../../../../src/runtime/memory.js';
import {withX87ControlWord} from '../../../../src/runtime/float80.js';
import {clampedPointDistance,clampedPointDistanceExtended as diagnosticOriginalClampedPointDistance} from '../../src/engine/waypoints.js';
const memory=loadPE32(readFileSync(new URL('../../runtime/Tactics2010EnglishPreserved.exe',import.meta.url)));
const cases=[];
const powers=[-1074,-1022,-600,-513,-512,-511,-128,-1,0,1,255,510,511,512,1023];
for(const power of powers){const v=2**power;for(const sign of [-1,1])for(const args of [[sign*v,0,0,0],[0,sign*v,0,0],[sign*v,-sign*v,-sign*v,sign*v],[v,v,v,v]])cases.push(args);}
for(const v of [-0,0,1,2,10,100,1000,10000,50000,1e150,1e154,1e155,1e308])for(const other of [-0,0,v,-v])cases.push([v,other,other,v]);
let seed=0x523ade67;const next=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed;};
for(let i=0;i<2000;i++)cases.push(Array.from({length:4},()=>((next()>>>0)/4294967296-.5)*30000));
let checks=0,matchedUnsupported=0;const failures=[];
for(const cw of [0x027f,0x037f])withX87ControlWord(cw,()=>{for(const [index,args]of cases.entries()){const capture=fn=>{try{return {bits:Buffer.from(fn(memory,...args).toBytes()).toString('hex')};}catch(e){return {error:e.constructor.name,message:e.message};}};const a=capture(clampedPointDistance),b=capture(diagnosticOriginalClampedPointDistance);checks++;if(JSON.stringify(a)!==JSON.stringify(b))failures.push({cw,index,args,actual:a,expected:b});else if(a.error)matchedUnsupported++;}});
const report={scope:'Diagnostic generated guard/property inputs compared to original unchanged JavaScript Float80 helper, supplementary to original-native fixtures; these are not additional native captured calls',checks,matchedUnsupported,cases:cases.length,controlWords:['0x027f','0x037f'],failures,exact:failures.length===0};
writeFileSync('/tmp/tact-pc53-distance-guard-check.json',JSON.stringify(report,null,2)+'\n');console.log(JSON.stringify(report,null,2));process.exitCode=failures.length?1:0;
