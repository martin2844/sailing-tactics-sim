import {mkdtemp,writeFile,mkdir,rm} from 'node:fs/promises';import {execFileSync} from 'node:child_process';import {join,resolve} from 'node:path';import {tmpdir} from 'node:os';import {pathToFileURL} from 'node:url';import assert from 'node:assert/strict';
import {shapeSeparation} from '../app/contact-geometry.ts';import {sweep,createSweepQuery} from '../app/contact-solver.ts';import {ContactNavigator} from '../app/contact-navigation.ts';import {boatShapes,radius} from '../app/contact-shapes.ts';import {makeRuntime} from './independent/fixtures.mjs';import {prepareFleetSpawns} from '../app/engine/compatibility/spawn-state.ts';
const output=resolve(process.argv[2]);await mkdir(output,{recursive:true});const temporary=await mkdtemp(join(tmpdir(),'tact-contact-reference-'));const reference='c9bdd70',checks=[];
try{
 for(const name of['contact-geometry','contact-solver','contact-navigation']){
  let source=execFileSync('git',['show',reference+':versions/2026/app/'+name+'.ts'],{encoding:'utf8'});
  if(name==='contact-navigation')source=source.replaceAll("'./contact-shapes.ts'",JSON.stringify(pathToFileURL(resolve('app/contact-shapes.ts')).href)).replaceAll("'./contact-world.ts'",JSON.stringify(pathToFileURL(resolve('app/contact-world.ts')).href));
  await writeFile(join(temporary,name+'.ts'),source);
 }
 const geometry=await import(pathToFileURL(join(temporary,'contact-geometry.ts'))),solver=await import(pathToFileURL(join(temporary,'contact-solver.ts'))),navigation=await import(pathToFileURL(join(temporary,'contact-navigation.ts')));
 let separations=0,sweeps=0;
 for(let selector=1;selector<=27;selector++)for(const heading of[0,3,45,181,359])for(const offset of[0,.04,3,15,100]){
  const parts=boatShapes(selector),circle={kind:'circle',radius:1.5},a={x:10000,y:-1000,heading},b={x:10000+offset,y:-1000+offset/2,heading:heading+13};
  for(const part of parts)for(const other of[...parts,circle]){assert.deepEqual(shapeSeparation(part,a,other,b),geometry.shapeSeparation(part,a,other,b));separations++;}
  const first={key:'a',parts,radius:radius(parts),pose:a,to:{x:a.x+10,y:a.y-4,heading:heading+9}},second={key:'b',parts,radius:radius(parts),pose:b,to:{x:b.x-5,y:b.y+2,heading:b.heading}};
  for(const rotation of[0,9]){first.to.heading=heading+rotation;const expected=solver.sweep(first,second),query=createSweepQuery();assert.deepEqual(sweep(first,second),expected);assert.deepEqual(query(first,second),expected);const result=query(first,second);assert.deepEqual(result,expected);if(result)result.normal.x=123;assert.deepEqual(query(first,second),expected);sweeps++;}
 }
 let seed=18451;const random=()=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed/2**32;};
 for(let n=0;n<6000;n++){
  const pa=boatShapes(n%27+1),pb=n%3===0?[{kind:'circle',radius:1.5}]:boatShapes((n*7)%27+1),base=[0,10000,1e8,1e8+1][n%4],ar=radius(pa),br=radius(pb),reach=(ar+br+1)*4;
  const ap={x:base+(random()-.5)*reach,y:base+(random()-.5)*reach,heading:random()*360},bp={x:base+(random()-.5)*reach,y:base+(random()-.5)*reach,heading:random()*360};
  const a={key:'a',parts:pa,radius:ar,pose:ap,to:{x:ap.x+(random()-.5)*60,y:ap.y+(random()-.5)*60,heading:ap.heading}},b={key:'b',parts:pb,radius:br,pose:bp,to:{x:bp.x+(random()-.5)*60,y:bp.y+(random()-.5)*60,heading:bp.heading}};
  assert.deepEqual(createSweepQuery()(a,b),solver.sweep(a,b),JSON.stringify({n,a,b}));sweeps++;
 }
 checks.push({name:'Exact geometry and swept time/normal equality across all27 hull classes',separations,sweeps});
 const runs=[];
 for(const fleet of[5,15,30]){
  const configuration={speed:6,setupCommands:[32799,32816,32789,fleet===5?32806:fleet===15?32808:32811,32909]},a=makeRuntime(configuration),b=makeRuntime(configuration);
  const navA=new navigation.ContactNavigator(()=>true),navB=new ContactNavigator(()=>true);
  for(const [runtime,nav]of[[a,navA],[b,navB]]){prepareFleetSpawns(runtime.memory,{depth:()=>200});const original=runtime.engine.options.updateBoatWindAndAI;runtime.engine.options.updateBoatWindAndAI=(m,id,rng,options)=>{const result=original(m,id,rng,options);nav.steer(m,id);return result}}
  let oldMs=0,newMs=0;
  for(let n=0;n<100;n++){let start=performance.now();a.engine.step();oldMs+=performance.now()-start;start=performance.now();b.engine.step();newMs+=performance.now()-start;assert.deepEqual(b.memory.bytes,a.memory.bytes,JSON.stringify({fleet,n}));assert.deepEqual(b.engine.random.snapshot(),a.engine.random.snapshot());assert.deepEqual([...navB.active],[...navA.active]);}
  runs.push({fleet,steps:100,oldMs,newMs,speedup:oldMs/newMs});
 }
 checks.push({name:'Complete numerical image, RNG and navigation activity remain exact after every decision/step',runs});
 await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,reference,checks,scope:'Comparison against preserved pre-optimization TypeScript contact geometry/solver/navigator sources at c9bdd70. Query caching uses immutable prediction motions; actual contact resolution remains uncached. Full fixed-step image/RNG comparisons include navigation decisions on5/15/30-Keelboat fleets. Node cost observations are separate from Chrome rates.'},null,2));console.log(JSON.stringify({passed:true,separations,sweeps,runs}));
}finally{await rm(temporary,{recursive:true,force:true})}
