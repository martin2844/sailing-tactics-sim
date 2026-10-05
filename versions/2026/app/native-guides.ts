import type {CourseGuide,NativeCourse} from './protocol';
/** Original chart guide decisions, isolated from the authoritative image/RNG.
 * The generated selector retains original mark/gate/finish/heading branches.
 * Length and styling belong to presentation; bearings and anchors do not. */
export function createGuideExtractor(context:any){
 const {memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,guideDraw,originalTargetDraw}=context;
 const image=new ModelMemory(memory.size,memory.base),random=new ModelRng();
 const privateOptions={...options,numberRendering:true,smoothGraphics:true,rng:random,
  getTickCount:()=>0,invalidateRect:()=>{},playSound:()=>1,messageBeep:()=>{}};
 const extract=()=>{
  extractor.navigation=undefined;
  if(memory.readI32(0x4f8cd0)<0||memory.readI32(0x5363f4)>0)return [];
  image.bytes.set(memory.bytes);random.state=rng.state;
  const guides:CourseGuide[]=[];
  privateOptions.nativeCourseGuideRay=(ray:CourseGuide)=>{
   if(!guides.some(g=>g.point===ray.point&&g.bearing===ray.bearing))guides.push(ray);
  };
  const dc=new TraceDc({objects:new Map(objects),recordEvents:false});
  // A chart of unbounded extent admits guides outside the historical viewport.
  // Native conditions choose their types/sides; the free camera clips them later.
  guideDraw(image,dc,random,privateOptions,false,512,384,.05,0,0,1,image.readI32(0x4da140),-1e8,-1e8,1e8,1e8);
  // HUD 0x40f240 calls 0x440350 to select a physical chart object. The AI
  // waypoint is offset around that object and must not identify its label.
  // Run after guide selection so its scratch writes cannot affect those rays.
  const owner=image.readI32(0x4da140),point=originalTargetDraw(image,dc,random,privateOptions,owner);
  const i=(address:number)=>image.readI32(address),d=(address:number)=>image.readF64(address);
  const finalLeg=i(0x4f8538+owner*4)===i(0x4da1e4),kind=i(0x4fbf10+owner*4);
  // Original sailing HUD cases 689 and 686 override the object with the
  // finish midpoint. Preserve their integer division toward zero.
  const finish=finalLeg&&(i(0x53527c)===0&&kind===0||i(0x53527c)===1&&kind>1&&i(0x4da194)<15);
  extractor.navigation={point,finish,
   x:finish?Math.trunc((i(0x536410)+i(0x4fe094))/2):d(0x4f8398+point*8),
   y:finish?Math.trunc((i(0x536414)+i(0x4fe2a0))/2):d(0x4fb068+point*8)};
  return guides;
 };
 const extractor=Object.assign(extract,{navigation:undefined as NativeCourse['navigationTarget']});
 return extractor;
}
