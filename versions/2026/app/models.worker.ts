import {createModelExtractor} from './native-models';
let memory:any,rng:any,extractor:ReturnType<typeof createModelExtractor>;
let mutableOffset=0,mutableSize=0;
async function initialize(data:any){
 const base=new URL(data.legacyBase),edition='versions/2010-en/';
 const load=(path:string)=>import(/* @vite-ignore */new URL(path,base).href);
 const json=async(path:string)=>{const response=await fetch(new URL(path,base));if(!response.ok)throw new Error('Model asset failed: '+path);return response.json();};
 const [original,integer,space,drawing,gdi,trig,bindings,renderer,extended,stored,shore,float]=await Promise.all([
  load(edition+'src/runtime/original-data.js'),load('src/engine/integer-core.js'),load('src/runtime/memory.js'),load(edition+'src/render/drawing-functions.js'),load(edition+'src/render/gdi.js'),load(edition+'src/engine/native-trig.js'),load(edition+'src/engine/port.js'),load(edition+'src/render/index.js'),json(edition+'assets/data/x87-trig.json'),json(edition+'assets/data/x87-stored-trig.json'),json(edition+'assets/data/initial-shoreline-stack.json'),load('src/runtime/float80.js')]);
 memory=await original.fetchOriginalData();rng=new integer.PoseyRng();float.setX87ControlWord(0x027f);
 mutableOffset=original.MUTABLE_BASE-memory.base;mutableSize=original.MUTABLE_SIZE;
 const options={trig:trig.createCapturedTrig(extended,stored),...bindings.createEngineBindings(),...renderer.createOriginalRenderer({initialShoreStack:shore,smoothGraphics:true}),rng,playSound:()=>1,messageBeep:()=>{},beep:()=>{},getTickCount:()=>0};
 extractor=createModelExtractor({memory,rng,options,objects:new Map(data.objects),ModelMemory:space.AddressSpaceMemory,ModelRng:integer.PoseyRng,TraceDc:gdi.GdiTrace,modelDraw:drawing.nativeModelDrawBoatNumber});
 self.postMessage({type:'ready'});
}
let chain=Promise.resolve();self.onmessage=event=>{chain=chain.then(async()=>{
 const {type,data}=event.data;if(type==='init'){await initialize(data);return;}
 if(type==='frame'){
  if(data.image.byteLength!==mutableSize)throw new Error('Private graphics state has the wrong size');
  memory.bytes.set(new Uint8Array(data.image),mutableOffset);rng.state=data.rngState;
  const packet=extractor.extract(data.ids,data.width);
  self.postMessage({type:'models',data:{generation:data.generation,sequence:data.sequence,packet}}, {transfer:[packet.positions.buffer,packet.records.buffer,packet.colors.buffer,packet.boats.buffer]});
 }
}).catch(error=>self.postMessage({type:'error',data:error instanceof Error?error.stack:String(error)}));};
