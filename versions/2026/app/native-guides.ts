import type {CourseGuide} from './protocol';
/** Original chart guide decisions, isolated from the authoritative image/RNG.
 * The generated selector retains original mark/gate/finish/heading branches.
 * Length and styling belong to presentation; bearings and anchors do not. */
export function createGuideExtractor(context:any){
 const {memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,guideDraw}=context;
 const image=new ModelMemory(memory.size,memory.base),random=new ModelRng();
 const privateOptions={...options,numberRendering:true,smoothGraphics:true,rng:random,
  getTickCount:()=>0,invalidateRect:()=>{},playSound:()=>1,messageBeep:()=>{}};
 return ()=>{
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
  return guides;
 };
}
