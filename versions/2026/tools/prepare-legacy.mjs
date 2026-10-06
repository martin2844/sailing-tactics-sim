// Validate frozen inputs; emit explicit observation/presentation adapters into
// an ignored runtime copy. Preservation sources are never edited.
import {readFile,mkdir,writeFile,rm} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {fileURLToPath} from 'node:url';
const root=new URL('../../../',import.meta.url),out=new URL('../public/legacy/',import.meta.url);
const shapeSource=await readFile(new URL('../app/generated/starter-samples.json',import.meta.url));
const shapeCatalog=JSON.parse(await readFile(new URL('../app/generated/contact-shapes.json',import.meta.url),'utf8'));
if(shapeCatalog.sourceSha256!==createHash('sha256').update(shapeSource).digest('hex'))throw Error('Contact shapes are stale; run node tools/generate-contact-shapes.mjs');
const pin=JSON.parse(await readFile(new URL('../analysis/baseline/reference.json',import.meta.url)));
const data=['original-memory.json','original-constants.bin','original-initial-state.bin','original-english-data.bin','trig-tables.json','x87-trig.json','x87-stored-trig.json','initial-shoreline-stack.json'].map(f=>'versions/2010-en/assets/data/'+f);
const required=new Set([...data,'assets/data/system-font.json','assets/images/system-font-glyphs.png']);
const rows=pin.files.filter(f=>(f.path.startsWith('src/')||f.path.startsWith('versions/2010-en/src/'))&&f.path.endsWith('.js')||required.has(f.path));
for(const path of required)if(!rows.some(f=>f.path===path))throw new Error('Unpinned required asset '+path);
// Validate every input before replacing a previously usable generated tree.
const files=await Promise.all(rows.map(async f=>{const bytes=await readFile(new URL(f.path,root));if(bytes.length!==f.bytes||createHash('sha256').update(bytes).digest('hex')!==f.sha256)throw new Error('Frozen input differs: '+f.path);return {f,bytes};}));
await rm(out,{recursive:true,force:true});
const generated=[];
for(const {f,bytes}of files){const target=new URL(f.path,out);await mkdir(fileURLToPath(new URL('./',target)),{recursive:true});if(f.path==='versions/2010-en/src/render/drawing-functions.js'){
    let observed=bytes.toString('utf8');
    // 0x440fd0 FDIV stores a nonfinite slope when projected shore endpoints
    // share an x coordinate. 0x4410f6 multiplies it by zero; masked __ftol
    // (0x49b989 FISTP qword) returns 0x8000000000000000. Its EAX low DWORD
    // is zero. Recover only that conversion, retaining the texture loop,
    // polygons and every nonzero-span expression in their original order.
    const shoreStart=observed.indexOf('export function originalDrawing00440b70(');
    const shoreEnd=observed.indexOf('\nexport function originalDrawing00442270(',shoreStart);
    if(shoreStart<0||shoreEnd<0)throw Error('Native shore routine boundary changed');
    let shoreRepairs=0;
    const shore=observed.slice(shoreStart,shoreEnd).replace(/case 65: \{ \(iVar5 = [^\n]+/g,line=>{
      const read=line.includes('fpScalarRead(')?offset=>'fpScalarRead(scalarStack'+offset+')'
        :line.includes('scalarRead(')?offset=>'scalarRead(scalarStack'+offset+')'
        :offset=>'readLocal(framePointer(localFrame,'+offset+'),4,"int")';
      if(!line.includes('pc = 64; continue;'))throw Error('Native shore conversion source changed');
      shoreRepairs++;
      return line.replace('case 65: {','case 65: { if(cSub('+read(12)+','+read(4)+')===0){iVar5=cSub('+read(8)+',iVar3);pc=64;continue;}');
    });
    if(shoreRepairs!==4)throw Error('Expected all four native shore conversion variants');
    observed=observed.slice(0,shoreStart)+shore+observed.slice(shoreEnd);
    // 0x46cc21 MOV DWORD PTR [esp+0x1c],ecx writes only the low
    // word of Ghidra's overlapping dStack_24. Its invented CONCAT44 read of
    // the uninitialized high word crashes the Block Island chart. The actual
    // subsequent TextOut reads that low coordinate, not a floating value.
    const chartStores=[
      'writeLocal(framePointer(localFrame,260),bitsAsF64(cConcat(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(cAdd(cI32(readLocal(framePointer(localFrame,0),4,"int"),false),5)),4,4)),8,"float")',
      'writeLocalFloatNumber(framePointer(localFrame,260),wordsAsF64Number(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(cAdd(cI32(readLocal(framePointer(localFrame,0),4,"int"),false),5))))',
    ];
    for(const store of chartStores){if(observed.split(store).length!==2)throw Error('Native chart DWORD store source changed');observed=observed.replace(store,'writeLocal(framePointer(localFrame,260),cAdd(cI32(readLocal(framePointer(localFrame,0),4,"int"),false),5),4,"int")');}
    // The Groton lighthouse (0x46f357) and Edgartown coordinate
    // (0x46fa22) are also DWORD stores into that overlapping chart local.
    for(const delta of ['10','cNeg(35)']){const value='cAdd(cI32(readLocal(framePointer(localFrame,0),4,"int"),false),'+delta+')';for(const store of [
      'writeLocal(framePointer(localFrame,260),bitsAsF64(cConcat(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord('+value+'),4,4)),8,"float")',
      'writeLocalFloatNumber(framePointer(localFrame,260),wordsAsF64Number(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord('+value+')))',
    ]){if(observed.split(store).length!==2)throw Error('Native lighthouse DWORD store source changed');observed=observed.replace(store,'writeLocal(framePointer(localFrame,260),'+value+',4,"int")');}}
    // 0x46fe1a stores the TextOut function pointer as a DWORD. The same
    // overlapping Ghidra double invents another unused upper-word read.
    for(const store of [
      'writeLocal(framePointer(localFrame,260),bitsAsF64(cConcat(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(dcMethod(dc,100,memory)),4,4)),8,"float")',
      'writeLocalFloatNumber(framePointer(localFrame,260),wordsAsF64Number(cRawWord(readPointer(memory,pointerAdd(framePointer(localFrame,260),4),4)),cRawWord(dcMethod(dc,100,memory))))',
    ]){if(observed.split(store).length!==2)throw Error('Native chart pointer DWORD source changed');observed=observed.replace(store,'writeLocal(framePointer(localFrame,260),dcMethod(dc,100,memory),4,"int")');}
    // Native signed IMUL/ADD at 0x465f39..41 can wrap below zero for
    // distant scenery. Masked FSQRT + __ftol yields integer indefinite:
    // 0x8000000000000000, whose stored low DWORD is zero. Preserve positive
    // calculations exactly; this scope does not change the Float80 runtime.
    const distanceExpressions=[
      ...['scalarRead(scalarStack0)','readLocal(framePointer(localFrame,0),4,"int")'].map(x=>'cRawWord(cI64(cFloat(cFloat(cAdd(cMul('+x+','+x+'),cMul(iVar3,iVar3)))).sqrt(),false))'),
      ...['fpScalarRead(scalarStack0)','readLocal(framePointer(localFrame,0),4,"int")'].map(x=>'cRawWord(fpI64(fpBox(fpFromInteger(cAdd(cMul('+x+','+x+'),cMul(iVar3,iVar3)))).sqrt(),false))'),
    ];
    for(const expression of distanceExpressions){if(observed.split(expression).length!==2)throw Error('Native distance invalid-conversion source changed');const argument=expression.match(/cAdd\(cMul\((.*),\1\),cMul\(iVar3,iVar3\)\)/)?.[1];if(!argument)throw Error('Distance argument recovery failed');observed=observed.replace(expression,'(cAdd(cMul('+argument+','+argument+'),cMul(iVar3,iVar3))<0?0:'+expression+')');}
    // Native 0x48b813 pushes COLORREF 0 before CDC::SetTextColor; 0x48b854
    // pushes the CString length before TextOut. The old decompilation dropped
    // both arguments and retained fictional CString stack expressions.
    const labelStart=observed.indexOf('export function originalDrawing0048b7e0('),labelEnd=observed.indexOf('\nexport function originalDrawing0048e730(',labelStart);
    if(labelStart<0||labelEnd<0)throw new Error('Native wind label boundary changed');
    observed=observed.slice(0,labelStart)+`export function originalDrawing0048b7e0(memory,dc,rng,options={},...originalArgs){
      dc.setTextColor(0);
      dc.textOut(10,Math.trunc(memory.readI32(0x4fe2a8)/30)+40,cString(memory,0x4ecae0)+formatInteger(memory.readI32(0x51158c)));
    }
    `+observed.slice(labelEnd);
    // A separate presentation entry operates exclusively on a private image.
    // Two projections recover the depth of the original GDI faces, including
    // sail height and crew detail. The authoritative entry never uses these hooks.
    const start=observed.indexOf('function originalDrawBoatNumber(');
    const end=observed.indexOf('\nexport function originalDrawing00419ce0',start);
    if(start<0||end<0)throw new Error('Native boat model source boundary changed');
    let model=observed.slice(start,end).trim();
    model=model.replace('function originalDrawBoatNumber(', 'export function nativeModelDrawBoatNumber(');
    model=model.replaceAll('callNumberDrawingDependencyOwned(', 'modelDependency(');
    model=model.replace('  const r32 =',`  const modelDependency=(...args)=>{
      const projection=options.nativeModelProjection,previous=projection.part;
      projection.part=args[2];
      try { return callNumberDrawingDependencyOwned(...args); }
      finally { projection.part=previous; }
    };
  const r32 =`);
    model=model.replace('case 482: {','case 482: { writeLocalFloatNumber(framePointer(localFrame,296),fpLoad(options.nativeModelProjection.width));');
    model=model.replace('case 405: {','case 405: { uVar8=options.nativeModelProjection.angle;');
    model=model.replace('case 368: {',`case 368: { {
      const factor=options.nativeModelProjection.factor;
      const cx=memory.readF64(0x535c78),cz=memory.readF64(0x4f3a48);
      const count=readLocal(framePointer(localFrame,288),4,"int");
      for(let i=0;i<=count;i++){
        if(i>=27&&i<=38&&memory.readI32(0x5350d8+readLocal(framePointer(localFrame,12),4,"int")*4)!==1)continue;
        if(i>=39&&!(memory.readI32(0x535884)<readLocal(framePointer(localFrame,8),4,"int")))continue;
        memory.writeF64(0x535c68+i*8,cx+(memory.readF64(0x535c68+i*8)-cx)*factor);
        memory.writeF64(0x4f3a38+i*8,cz+(memory.readF64(0x4f3a38+i*8)-cz)*factor);
        memory.writeF64(0x4fea68+i*8,memory.readF64(0x4fea68+i*8)*factor);
      }
      writeLocalFloatNumber(framePointer(localFrame,256),fpMul(readLocalFloatNumber(framePointer(localFrame,256)),fpLoad(factor)));
    }`);
    model=model.replace('case 239: {',`case 239: { {
      const scale=fpToNumber(readLocalFloatNumber(framePointer(localFrame,256)));
      const count=readLocal(framePointer(localFrame,288),4,"int");
      const a=cI32(uVar8,false)*memory.readF64(0x4cc670);
      const cx=memory.readF64(0x535c78),cz=memory.readF64(0x4f3a48);
      const points=[];
      for(let i=0;i<=count;i++){
        if(i>=27&&i<=38&&memory.readI32(0x5350d8+readLocal(framePointer(localFrame,12),4,"int")*4)!==1)continue;
        if(i>=39&&!(memory.readI32(0x535884)<readLocal(framePointer(localFrame,8),4,"int")))continue;
        const x=memory.readF64(0x535c68+i*8)-cx,z=memory.readF64(0x4f3a38+i*8)-cz;
        const depth=-x*Math.sin(a)+z*Math.cos(a);
        const py=memory.readI32(0x5229e0+i*4);
        memory.writeI32(0x5229e0+i*4,py-Math.round(depth*options.nativeModelProjection.shear));
        points.push({i,x:x/scale,z:z/scale});
      }
      options.nativeModelProjection.metadata={scale,angle:a,points};
    }`);
    observed+='\n'+model+'\n';
    // Private course presentation executes the original chart's guide decisions.
    // Drop unrelated chart artwork/tracks/gusts; preserve every guide branch and
    // its original angle calculation. These entries are never registered as
    // authoritative drawing replacements and operate only on a copied image.
    const section=(name,next)=>{
      const a=observed.indexOf('function '+name+'('),b=observed.indexOf(next,a);
      if(a<0||b<0)throw Error('Native guide source boundary changed: '+name);
      return observed.slice(a,b).trim();
    };
    let selector=section('originalDrawing00431ab0Number','\n/** Complete recovered original 0x0041f130');
    selector=selector.replace('function originalDrawing00431ab0Number(', 'export function nativeCourseGuideSelector(')
      .replaceAll('callNumberDrawingDependencyOwned(', 'guideDependency(')
      .replace('  const r32 =',`  const guideDependency=(m,d,address,args,floats,r,o)=>{
        if(address===0x444890)return nativeCourseGuideRay(m,d,r,o,false,...args.slice(1));
        if(address===0x41bc20||address===0x43ec20)return callNumberDrawingDependencyOwned(m,d,address,args,floats,r,o);
        return 0;
      };\n  const r32 =`)
      .replace('case 215: {','case 215: { pc=200; continue;')
      .replace('case 199: {','case 199: { pc=132; continue;');
    let ray=section('originalDrawing00444890Number','\n/** Complete recovered original 0x00444890; static C control-flow translation. */');
    ray=ray.replace('function originalDrawing00444890Number(', 'function nativeCourseGuideRay(');
    for(const [node,bearing]of [[40,'iVar4'],[31,'iVar5'],[17,'fpScalarRead(scalarStack20)'],[2,'fpScalarRead(scalarStack20)']]){
      const anchor='case '+node+': {';
      if(ray.split(anchor).length!==2)throw Error('Native guide emission node changed');
      ray=ray.replace(anchor,anchor+` {
        const owner=numberArg3,orientation=memory.readI32(0x525a78+owner*4);
        const basis=memory.readI32((orientation===2?0x522b90:orientation===1?0x535740:0x4fbb90)+owner*4);
        options.nativeCourseGuideRay?.({point:numberArg5,type:numberArg2,
          x:memory.readF64(0x4f8398+numberArg5*8),y:memory.readF64(0x4fb068+numberArg5*8),
          bearing:(Number(${bearing})+basis+720)%360});
      }`);
    }
    observed+='\n'+selector+'\n'+ray+'\n';
    // Record the actual projection calibration before the painter consumes it.
    for(const name of ['originalDrawBoatOriginal','originalDrawBoatNumber']){
      const from=observed.indexOf('function '+name+'('),to=observed.indexOf('\n}',from)+2;
      let body=observed.slice(from,to);
      body=body.replace('case 239: {',`case 239: { globalThis.tactNativeVisuals?.calibrate({height:readLocalFloatNumber(framePointer(localFrame,256)),width:readLocalFloatNumber(framePointer(localFrame,296))});`);
      observed=observed.slice(0,from)+body+observed.slice(to);
    }
    // Wrap both actual entry paths; numeric child calls use the number registry.
    // Only observe their real GDI stream. Arguments/results/sink are forwarded.
    for(const name of ['originalDrawBoatOriginal','originalDrawBoatNumber']){
      const anchor='function '+name+'(';
      if(observed.split(anchor).length!==2)throw new Error('Boat observer entry differs: '+name);
      const body=name+'ObservedBody';
      observed=observed.replace(anchor,'function '+body+'(');
      const id=name.endsWith('Number')?'args[3]':'args[2]';
      const wrapper='function '+name+'(memory,dc,rng,options,...args){ globalThis.tactNativeVisuals?.begin(memory,dc,'+id+'); try { return '+body+'(memory,dc,rng,options,...args); } finally { globalThis.tactNativeVisuals?.end(); } }\n';
      observed+=wrapper;
    }
    // Route gameplay waypoint placement to the 2026 domain kernel on public
    // and numeric call paths; the frozen player's default remains unchanged.
    for(const [signature,index]of[
      ['export function originalDrawing00465ff0(memory, dc, rng, options = {}, ...originalArgs) {','originalArgs[0]'],
      ['function originalDrawing00465ff0Number(memory, dc, rng, options, numberArgumentImages, numberArg0) {','numberArg0'],
    ]){
      if(observed.split(signature).length!==2)throw Error('Native waypoint entry changed');
      observed=observed.replace(signature,signature+'\n  if(options.respawnWaypoint)return options.respawnWaypoint(memory,'+index+',rng,options);');
    }
    for(const [signature,boat]of[
      ['export function originalDrawing0041e0a0(memory, dc, rng, options = {}, ...originalArgs) {',1],
      ['function originalDrawing0041e0a0Number(memory, dc, rng, options, numberArgumentImages) {',1],
      ['export function originalDrawing0041e220(memory, dc, rng, options = {}, ...originalArgs) {',2],
      ['function originalDrawing0041e220Number(memory, dc, rng, options, numberArgumentImages) {',2],
    ]){
      if(observed.split(signature).length!==2)throw Error('Native camera entry changed');
      observed=observed.replace(signature,signature+'\n  if(options.updateCompatibilityCamera)return options.updateCompatibilityCamera(memory,'+boat+');');
    }
    for(const [name,boat]of[
      ['originalDrawing0041ce80Original','scalarRead(scalarStack12)'],
      ['originalDrawing0041ce80ByteFrame','readLocal(framePointer(localFrame,12),4,"int")'],
      ['originalDrawing0041ce80Number','fpScalarRead(scalarStack12)'],
      ['originalDrawing0041ce80NumberByteFrame','readLocal(framePointer(localFrame,12),4,"int")'],
    ]){
      const start=observed.indexOf('function '+name+'(');
      const ends=[observed.indexOf('\nfunction ',start+10),observed.indexOf('\nexport function ',start+10)].filter(n=>n>=0);
      if(start<0||!ends.length)throw Error('Native slowdown routine changed');
      const end=Math.min(...ends),anchor='case 55: { (iVar8 = r32(0x4da140)); pc = 54; continue; }';
      let body=observed.slice(start,end);
      if(body.split(anchor).length!==2)throw Error('Native slowdown control block changed');
      body=body.replace(anchor,'case 55: { iVar8=r32(0x4da140); if(options.updateFoulSlowdown){const eligible=options.updateFoulSlowdown(memory,'+boat+');iVar4=r32(0x4da1dc);pc=eligible?41:36;continue;} pc = 54; continue; }');
      observed=observed.slice(0,start)+body+observed.slice(end);
    }
    await writeFile(target,observed);
    generated.push({path:f.path,bytes:Buffer.byteLength(observed),sha256:createHash('sha256').update(observed).digest('hex'),adapter:'native-observer-private-model-and-semantic-kernels-v5',repairs:[{address:'0x440fd0',reason:'Masked zero-width shore FDIV/FMUL/__ftol low DWORD recovery'},{address:'0x48b7e0',reason:'Native SetTextColor/CString/TextOut argument recovery'},{address:'0x46f357',reason:'Native Groton lighthouse DWORD coordinate store'},{address:'0x46fa22',reason:'Native Edgartown DWORD coordinate store'},{address:'0x465f49',reason:'Masked invalid FSQRT/__ftol low DWORD recovery for signed distance overflow'},{address:'0x46fe1a',reason:'Native DWORD TextOut pointer store'},{address:'0x46cc21',reason:'Native DWORD label-coordinate store; no fictitious upper double word read'}],sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/penalties.js'){
    let prepared=bytes.toString('utf8');
    const replace=(a,b,count=1)=>{if(prepared.split(a).length!==count+1)throw Error('Native contact policy source changed: '+a);prepared=prepared.replaceAll(a,b);};
    replace('boat=i32(boat);const r=a=>memory.readI32(a),range=idiv32(r(0x523598),6);','if(options.geometryRuleOnly){options.geometryMovement?.("respawn");return;}boat=i32(boat);const r=a=>memory.readI32(a),range=idiv32(r(0x523598),6);');
    replace('boat=i32(boat);const r=a=>memory.readI32(a),rb=a=>r(at(a,boat));\n const tack=', 'if(options.geometryRuleOnly){options.geometryMovement?.("shift");return;}boat=i32(boat);const r=a=>memory.readI32(a),rb=a=>r(at(a,boat));\n const tack=');
    replace('const penaltyMovement=(memory,boat,rng,options)=>{','const penaltyMovement=(memory,boat,rng,options)=>{if(options.geometryRuleOnly){options.geometryMovement?.("phase");return;}');
    replace('if(checkNearRaceMarks(memory,(r(0x4fe624)<901?1:0)+1,boat)===1){','if(!options.geometryContacts&&checkNearRaceMarks(memory,(r(0x4fe624)<901?1:0)+1,boat)===1){');
    replace('if(distance<threshold)collisionPenalty(memory,other,boat,distance,rng,options);','if(!options.geometryContacts&&distance<threshold)collisionPenalty(memory,other,boat,distance,rng,options);');
    replace('blocked=rb(0x4f4208)===1','blocked=options.geometryContact?options.geometryClearAstern===true:rb(0x4f4208)===1');
    replace('if(checkProjection&&same&&','if(checkProjection&&same&&(!options.geometryContact||options.geometryOverlap)&&');
    replace('&&distance<16&&','&&(options.geometryContact||distance<16)&&');
    replace('||distance>15||','||(!options.geometryContact&&distance>15)||');
    replace('&&distance<=add32(r(0x5363b8),5)&&','&&(options.geometryContact||distance<=add32(r(0x5363b8),5))&&');
    replace('if(boat<=humans())wb(0x5116e0,3);','if(boat<=humans())wb(0x5116e0,3);options.geometryDecision?.(3);',3);
    replace('const apply=code=>{','const apply=code=>{options.geometryDecision?.(code);');
    replace('{wb(0x5116e0,6);wb(0x535620,time());','{options.geometryDecision?.(6);wb(0x5116e0,6);wb(0x535620,time());');
    replace('wb(0x535620,time());wb(0x5116e0,7);','options.geometryDecision?.(7);wb(0x535620,time());wb(0x5116e0,7);');
    // Rule-only evaluation must not fall through a room decision after its
    // historical relocation has been suppressed.
    replace('options.geometryDecision?.(3);shiftPenaltyPosition(memory,boat,options);\n  }','options.geometryDecision?.(3);shiftPenaltyPosition(memory,boat,options);if(options.geometryRuleOnly)return;\n  }');
    // Reuse native response routines and preserve branch-specific relocation,
    // human-only status writes, timestamp order and prestart random draws.
    prepared+=`\nexport function applyGeometryPenalty(memory,boat,decision,rng,options={}){
 const code=decision.code,clock=memory.readI32(0x4f8cd0),humans=memory.readI32(0x4da140);
 if(code&&(boat<=humans||code===6))memory.writeI32(at(0x5116e0,boat),code);
 if(code!==1)memory.writeI32(at(0x535620,boat),clock);
 const live={...options,geometryRuleOnly:false};
 if(decision.movement==='shift')shiftPenaltyPosition(memory,boat,live);
 else if(decision.movement==='respawn'){resetBoat(memory,boat);respawnNearStart(memory,boat,rng,live);}
 else penaltyMovement(memory,boat,rng,live);
 if(code===1)memory.writeI32(at(0x535620,boat),clock);
}\n`;
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'geometric-contact-native-response-v2',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/configuration.js'){
    let prepared=bytes.toString('utf8');
    for(const [anchor,replacement]of[
      ['for(const address of[0x4da168,0x5363f8,0x53640c,0x4da1e8,0x53527c])w(address,0);','for(const address of(options.islandCoursesEnabled?[0x53640c,0x4da1e8]:[0x4da168,0x5363f8,0x53640c,0x4da1e8,0x53527c]))w(address,0);'],
      ["if(read('boatClass')<3||read('boatClass')>4)write('boatClass',3);","if(!options.islandCoursesEnabled&&(read('boatClass')<3||read('boatClass')>4))write('boatClass',3);"],
    ]){if(prepared.split(anchor).length!==2)throw Error('Native island course restriction changed');prepared=prepared.replace(anchor,replacement);}
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'island-course-choices-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/initialization.js'){
    const source=bytes.toString('utf8'),anchor='initializeWind(memory,rng);initializeTide(memory,rng);';
    if(source.split(anchor).length!==2)throw Error('Native wind initialization call changed');
    const prepared=source.replace(anchor,'initializeWind(memory,rng,options);initializeTide(memory,rng);');
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'wind-direction-options-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/wind-initialization.js'){
    let prepared=bytes.toString('utf8'),anchor="  w('shiftSide',r('venue')===0?";
    if(prepared.split(anchor).length!==2)throw Error('Native wind sector configuration changed');
    prepared=prepared.replace('export function initializeWind(memory,rng) {','export function initializeWind(memory,rng,options={}) {').replace(anchor,'  options.configureWindDirection?.(memory);\n'+anchor);
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'prevailing-wind-sector-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/wind.js'){
    const source=bytes.toString('utf8'),anchor="  const bearing=wrapDegreesOnce(add32(vectorBearing,drift));";
    if(source.split(anchor).length!==2)throw Error('Native wind bearing branch changed');
    const prepared=source.replace(anchor,"  const nativeBearing=wrapDegreesOnce(add32(vectorBearing,drift));\n  const bearing=options.adjustWindBearing?options.adjustWindBearing(memory,nativeBearing):nativeBearing;");
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'prevailing-wind-bearing-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/course.js'){
    let prepared=bytes.toString('utf8');
    for(const [flag,value]of[['0x5363cc','imul32(idiv32(r(0x525a9c),10),7)'],['0x5364c8','idiv32(r(0x525a9c),2)']]){
      const anchor=`if(r(${flag})===1)w(0x525a9c,${value});`;
      if(prepared.split(anchor).length!==2)throw Error('Native shortened-course branch changed');
      prepared=prepared.replace(anchor,`if(!(options.islandNavigationEnabled&&venue===0&&r(0x4f8b78)===1)&&r(${flag})===1)w(0x525a9c,${value});`);
    }
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'safe-island-course-size-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/ai-functions.js'){
    const source=bytes.toString('utf8'),end=source.indexOf('\nexport function originalChooseDownwindHeading');
    if(end<0)throw Error('Native AI boundary changed');
    let body=source.slice(0,end);const anchor='case 100: { pc = cTruth(';
    if(body.split(anchor).length!==2)throw Error('Native retirement branch changed');
    body=body.replace(anchor,'case 100: { pc = options.finishWindowEnabled ? 96 : cTruth(');
    const prepared=body+source.slice(end);await writeFile(target,prepared);
    generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'full-fleet-retirement-window-v1',sourceSha256:f.sha256});
  }else if(f.path==='versions/2010-en/src/engine/race-targets.js'){
    const source=bytes.toString('utf8'),anchor='export function advanceRaceTarget(memory,boat,options={}){';
    if(source.split(anchor).length!==2)throw Error('Native finish routine boundary changed');
    const prepared=source.replace(anchor,'function originalAdvanceRaceTarget(memory,boat,options={}){')+`
export function advanceRaceTarget(memory,boat,options={}){
  const scoring=memory.readI32(0x536424);
  if(!options.finishWindowEnabled||scoring!==1)return originalAdvanceRaceTarget(memory,boat,options);
  // The 2026 finishing window keeps the entire fleet racing after the player
  // finishes. Suppress only the old single-player immediate result branch.
  memory.writeI32(0x536424,0);
  try{return originalAdvanceRaceTarget(memory,boat,options);}
  finally{memory.writeI32(0x536424,scoring);}
}
`;
    await writeFile(target,prepared);generated.push({path:f.path,bytes:Buffer.byteLength(prepared),sha256:createHash('sha256').update(prepared).digest('hex'),adapter:'full-fleet-finish-window-v1',sourceSha256:f.sha256});
  }else {await writeFile(target,bytes);generated.push(f);}}
await writeFile(new URL('manifest.json',out),JSON.stringify({reference:pin.reference.commit,sourceFiles:rows,files:generated},null,2));
console.log(`Prepared ${rows.length} validated legacy modules/assets; explicit 2026 drawing, race, island and wind adapters`);
