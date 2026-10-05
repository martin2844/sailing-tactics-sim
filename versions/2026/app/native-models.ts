import type {NativePrimitive} from './native-visuals';
import {createNativeVisualObserver} from './native-visuals';
export const MODEL_QUANTUM=2048;
const hullParts=new Set([0x41e3c0,0x41e750,0x41eaf0,0x421630,0x4223c0,0x421ab0,0x4214e0,0x421f10]);
const crewParts=new Set([0x4225b0,0x423c30]);
const modelParts=new Set([...hullParts,...crewParts,0x419ce0,0x4235a0,0x41ce80,0x41fe70,0x41f520,0x425670,0x4243b0,0x48e730]);
export interface NativeModelPacket {positions:Int16Array;records:Int16Array;colors:Uint32Array;boats:Uint32Array;workMs:number}
export interface ModelProjection {width:number;factor:number;angle:number;shear:number;part?:number;metadata?:{scale:number;angle:number;points:{i:number;x:number;z:number}[]}}
export interface ModelCapture {projection:ModelProjection;primitives:NativePrimitive[]}
export interface ModelContext {memory:any;rng:any;options:any;objects:any;ModelMemory:any;ModelRng:any;TraceDc:any;modelDraw:any}
export function createModelExtractor(context:ModelContext){
 const {memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,modelDraw}=context;
 const privateMemory=new ModelMemory(memory.size,memory.base),privateRng=new ModelRng();
 function capture(id:number,width:number,angle:number,shear:number,factor=8):ModelCapture {
  privateMemory.bytes.set(memory.bytes);privateRng.state=rng.state;
  const projection:ModelProjection={width,factor,angle,shear};
  const captured=createNativeVisualObserver();
  const dc=new TraceDc({objects:new Map(objects),recordEvents:false,sink:(event:any,dc:any)=>captured.observe({...event,part:projection.part},dc),readPixel:()=>{throw new Error('Native model unexpectedly samples a pixel');}});
  const privateOptions={...options,rng:privateRng,nativeModelProjection:projection,getTickCount:()=>0,enforceMinimumPaintDuration:()=>{},invalidateRect:()=>{},closeWindow:()=>{}};
  captured.begin(privateMemory,dc,id);
  modelDraw(privateMemory,dc,privateRng,privateOptions,false,512,65536,id,1,131072,0);
  captured.end();
  const primitives=captured.frame(1024,361).boats[0]?.primitives;
  if(!projection.metadata||!primitives)throw new Error('Missing native model geometry for boat '+id);
  return {projection,primitives};
 }
 function extract(ids:number[],width:number):NativeModelPacket {
  const start=performance.now(),positions:number[]=[],records:number[]=[],boats:number[]=[],colors:number[]=[],vertices=new Map<string,number>(),palette=new Map<number,number>();
  const color=(value:number)=>{let index=palette.get(value);if(index===undefined){index=colors.length;colors.push(value);palette.set(value,index);}return index;};
  const vertex=(value:number[])=>{const v=value.map(n=>Math.round(n*MODEL_QUANTUM));if(v.some(n=>!Number.isFinite(n)||n<-32768||n>32767))throw new Error('Native model exceeds reviewed coordinate range: '+value.join(','));const key=v.join(',');let index=vertices.get(key);if(index===undefined){index=positions.length/3;positions.push(...v);vertices.set(key,index);}return index;};
  for(const id of ids){const begin=records.length;
   let hullColor:number|undefined;
   for(const angle of [35,-145]){
    const a=capture(id,width,angle,0),b=capture(id,width,angle,1);
    const scale=a.projection.metadata!.scale,rotation=a.projection.metadata!.angle,c=Math.cos(rotation),s=Math.sin(rotation);
    if(a.primitives.length!==b.primitives.length)throw new Error('Native model projection changes primitive count');
    const lift=(p:{x:number;y:number},q:{x:number;y:number})=>{if(p.x!==q.x)throw new Error('Native model projection changes horizontal coordinate');const xc=(p.x-512)/scale,zc=(p.y-q.y)/scale,up=(65536-p.y)/scale+.3*zc;return [xc*c-zc*s,up,xc*s+zc*c];};
    for(let n=0;n<a.primitives.length;n++){
     const p=a.primitives[n],q=b.primitives[n];
     if(p.op!==q.op||p.part!==q.part||p.brush.color!==q.brush.color||p.pen.color!==q.pen.color)throw new Error('Native model projection changes drawing topology/style');
     // World projection/wake/tutorial label calls are not boat-local geometry.
     if(p.part===undefined||!modelParts.has(p.part))continue;
     // The red/green human-player wind pointers are screen-space indicators,
     // not stays. A two-boat fleet enables the original second player's green
     // pointer, which otherwise becomes a giant line in private 3D extraction.
     if(p.part===0x41fe70&&p.op==='lineTo'&&(p.pen.color===0xff||p.pen.color===0xff00))continue;
     if(angle!==35&&!hullParts.has(p.part))continue;
     if(angle===35&&hullParts.has(p.part)&&p.op==='polygon'&&hullColor===undefined)hullColor=p.brush.color;
     // The opposite view supplies the hidden sides; the deck is already present.
     if(angle!==35&&(p.op!=='polygon'||p.brush.color!==hullColor||p.points!.length>=9))continue;
     const part=p.part===0x41ce80?5:p.part===0x41fe70?6:p.part===0x419ce0?4:hullParts.has(p.part)?1:crewParts.has(p.part)?2:3;
     const flags=Number(!!p.pen.null)|Number(!!p.brush.null)<<1;
     const fill=color(p.brush.color??0),stroke=color(p.pen.color??0);
     let op:number,indices:number[],extra:number[]=[];
     if(p.op==='polygon'){if(p.points!.length!==q.points!.length)throw new Error('Native model polygon topology changed');op=1;indices=p.points!.map((v,j)=>vertex(lift(v,q.points![j])));}
     else if(p.op==='lineTo'){op=2;indices=[vertex(lift(p.from!,q.from!)),vertex(lift({x:p.x!,y:p.y!},{x:q.x!,y:q.y!}))];}
     else if(p.op==='ellipse'){
      op=3;indices=[vertex(lift({x:(p.left!+p.right!)/2,y:(p.top!+p.bottom!)/2},{x:(q.left!+q.right!)/2,y:(q.top!+q.bottom!)/2}))];
      extra=[Math.round(Math.abs(p.right!-p.left!)/scale/2*MODEL_QUANTUM),Math.round(Math.abs(p.bottom!-p.top!)/scale/2*MODEL_QUANTUM)];
     }else if(p.op==='arc'){
      // GDI arcs are pen contours. Equal radial endpoints request a full
      // ellipse (the offshore crew's head outline). Lift both projections
      // at matching ellipse parameters, retaining their native depth shear.
      const cx=(p.left!+p.right!)/2,cy=(p.top!+p.bottom!)/2,rx=(p.right!-p.left!)/2,ry=(p.bottom!-p.top!)/2;
      if(!rx||!ry)continue;
      const begin=Math.atan2((p.startY!-cy)/ry,(p.startX!-cx)/rx),finish=Math.atan2((p.endY!-cy)/ry,(p.endX!-cx)/rx);
      let sweep=((begin-finish)%(Math.PI*2)+Math.PI*2)%(Math.PI*2);if(sweep<1e-8)sweep=Math.PI*2;
      const steps=Math.max(4,Math.ceil(sweep/(Math.PI/12))),qc=(q.top!+q.bottom!)/2,qr=(q.bottom!-q.top!)/2;
      const curve=Array.from({length:steps+1},(_,i)=>{const t=begin-sweep*i/steps,x=cx+rx*Math.cos(t);return vertex(lift({x,y:cy+ry*Math.sin(t)},{x,y:qc+qr*Math.sin(t)}));});
      const radius=Math.round(Math.max(.003,Math.min(.075,p.pen.width/scale/2))*MODEL_QUANTUM);
      for(let j=1;j<curve.length;j++)records.push(2,part,fill,stroke,flags,radius,2,curve[j-1],curve[j]);
      continue;
     }else throw new Error('Unreviewed native 3D primitive '+p.op);
     const radius=Math.round(Math.max(part===2?.003:.008,Math.min(.075,p.pen.width/scale/2))*MODEL_QUANTUM);
     records.push(op,part,fill,stroke,flags,radius,indices.length,...indices,...extra);
    }
   }
   boats.push(id,begin,records.length);
  }
  if(positions.length/3>32767||records.length>1000000)throw new Error('Native model packet exceeds reviewed index range');
  return {positions:Int16Array.from(positions),records:Int16Array.from(records),colors:Uint32Array.from(colors),boats:Uint32Array.from(boats),workMs:performance.now()-start};
 }
 return {capture,extract};
}
