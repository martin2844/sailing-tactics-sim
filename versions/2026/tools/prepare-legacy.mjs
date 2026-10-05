// Validate frozen inputs; emit explicit observation/presentation adapters into
// an ignored runtime copy. Preservation sources are never edited.
import {readFile,mkdir,writeFile,rm} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {fileURLToPath} from 'node:url';
const root=new URL('../../../',import.meta.url),out=new URL('../public/legacy/',import.meta.url);
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
    await writeFile(target,observed);
    generated.push({path:f.path,bytes:Buffer.byteLength(observed),sha256:createHash('sha256').update(observed).digest('hex'),adapter:'native-boat-observer-and-private-model-v1',sourceSha256:f.sha256});
  }else {await writeFile(target,bytes);generated.push(f);}}
await writeFile(new URL('manifest.json',out),JSON.stringify({reference:pin.reference.commit,sourceFiles:rows,files:generated},null,2));
console.log(`Prepared ${rows.length} validated legacy modules/assets; one explicit generated boat adapter`);
