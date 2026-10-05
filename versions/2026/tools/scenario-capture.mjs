import {readFile,writeFile,mkdir} from 'node:fs/promises';
import {resolve} from 'node:path';
import {createHash} from 'node:crypto';
import {referenceSession,closeReferenceServer} from './reference-session.mjs';
const output=resolve(process.argv[2]??'');if(process.argv.length!==3)throw new Error('Usage: node scenario-capture.mjs NEW_DIRECTORY');await mkdir(output);
const reference=JSON.parse(await readFile(new URL('../analysis/baseline/reference.json',import.meta.url))),runs=[];
try{
  for(const fleet of [5,15])for(let repeat=0;repeat<2;repeat++){
    const s=await referenceSession({fleet});
    try{
      await s.command(32850);
      const snapshot=await s.snapshot();
      const config=await s.browser.evaluate(`(async()=>{const m=tact.state.memory;const {PREFERENCE_FIELDS,serializePreferences}=await import('./src/engine/application.js');return {fields:PREFERENCE_FIELDS.map(f=>({...f,value:f.type==='F64'?m.readF64(f.address):m.readI32(f.address)})),preferences:[...serializePreferences(m)],selector:m.readI32(0x4da144),area:m.readI32(0x4da19c),venue:m.readI32(0x4da1f8),course:m.readI32(0x4da188),fleet:m.readI32(0x4da194),sheet:m.readI32(0x500384),shore:tact.state.options.shoreStack.snapshot()};})()`);
      await writeFile(resolve(output,`capture-${fleet}-${repeat}.json`),JSON.stringify({config,snapshot},null,2)+'\n',{flag:'wx'});
      if(config.selector!==12||config.area!==5||config.venue!==0||config.course!==1||config.fleet!==fleet||config.sheet!==-1||snapshot.mode!==0||snapshot.speed!==10||snapshot.autoSlow!==0)throw new Error('Candidate preset differs: '+JSON.stringify({selector:config.selector,area:config.area,venue:config.venue,course:config.course,fleet:config.fleet,sheet:config.sheet}));
      runs.push({fleet,repeat,setup:s.setup,snapshot,config,modules:await s.modules()});
    }finally{await s.close();}
  }
  const scenarios=[];
  for(const fleet of [5,15]){
    const [a,b]=runs.filter(r=>r.fleet===fleet);
    if(a.snapshot.memorySha256!==b.snapshot.memorySha256||a.snapshot.rngState!==b.snapshot.rngState||JSON.stringify(a.config)!==JSON.stringify(b.config))throw new Error('Preset does not reproduce exactly');
    const scenario={format:1,id:'round-lake-'+fleet,name:'Round Lake · '+fleet+' keelboats',referenceCommit:reference.reference.commit,seedTimeSeconds:1546300800,host:{width:1024,height:768,bitsPixel:24,tickStart:0,cursor:{x:0,y:0},hover:{x:0,y:0},preferences:null},setupCommands:[32799,32816,32789,fleet===5?32806:32808,32909],postSetupCommands:[32850],automaticSlowdown:false,defaultNativePace:10,configuration:{selector:12,area:5,venue:0,course:1,fleet,sheet:-1},initialBoundary:{frame:a.snapshot.frame,time:a.snapshot.time,rngState:a.snapshot.rngState,memorySha256:a.snapshot.memorySha256,shore:a.config.shore},nativePreferenceFields:a.config.fields,nativePreferenceSha256:createHash('sha256').update(Buffer.from(a.config.preferences)).digest('hex'),scope:'Original weather/current/preferences retained verbatim; fixed original handlers/paints, no new climate model or physics. Forecast data is native. Raw canonical image remains authoritative; fields are not a replay checkpoint.'};
    scenarios.push(scenario);await writeFile(resolve(output,scenario.id+'.json'),JSON.stringify(scenario,null,2)+'\n',{flag:'wx'});
  }
  await writeFile(resolve(output,'verification.json'),JSON.stringify({passed:true,runs},null,2)+'\n',{flag:'wx'});
  console.log(JSON.stringify(scenarios.map(s=>({id:s.id,initial:s.initialBoundary}))));
}finally{await closeReferenceServer();}
