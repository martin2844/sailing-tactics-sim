import type {NativePrimitive} from './native-visuals';
export const informationKinds=['forecast','wind','current','coach'] as const;
export type InformationKind=typeof informationKinds[number];
export interface InformationRequest {kind:InformationKind;offset?:number;zoom?:boolean}
export interface InformationContent {kind:InformationKind;title:string;clock:number;paragraphs:string[];history?:string[];primitives:NativePrimitive[];width?:number;height?:number;error?:string}
const titles={forecast:'Weather forecast',wind:'Wind chart',current:'Current chart',coach:'Coach comments'};
/** Original information routines on an independent image, RNG and shore stack.
 * Extract text/plot primitives; never run a simulation paint here. */
export function captureInformation(context:any,request:InformationRequest):InformationContent {
 const {memory,rng,options,objects,ModelMemory,ModelRng,TraceDc,copyStrings,renderer,key}=context;
 if(!request||!informationKinds.includes(request.kind)||!Number.isInteger(request.offset??0)||(request.offset??0)<0||(request.offset??0)>12||request.zoom!==undefined&&typeof request.zoom!=='boolean')throw Error('Invalid information request');
 const image=new ModelMemory(memory.size,memory.base),random=new ModelRng(rng.state);image.bytes.set(memory.bytes);copyStrings(memory,image);
 // A course can finish without any upwind samples (or without a sailed tick).
 // Do not manufacture samples to satisfy the old results coach's divisions.
 if(request.kind==='coach'&&image.readI32(0x5363f4)!==0&&(image.readI32(0x534e94)===0||image.readI32(0x534ea4)===0))return {
  kind:'coach',title:titles.coach,clock:memory.readI32(0x4f8cd0),primitives:[],
  paragraphs:['Race complete. There are not enough upwind sailing samples for a reliable coaching summary.'],
 };
 let ticks=0;
 const o={...options,...renderer.createOriginalRenderer({initialShoreStack:options.shoreStack.snapshot(),smoothGraphics:true}),rng:random,
  getTickCount:()=>ticks++,invalidateRect:()=>{},enforceMinimumPaintDuration:()=>{},closeWindow:()=>{},playSound:()=>1,messageBeep:()=>{},beep:()=>{}};
 const primitives:NativePrimitive[]=[];
 const dc=new TraceDc({objects:new Map(objects),recordEvents:false,sink:(event:any,dc:any)=>{
  if(!['textOut','lineTo','polygon','rectangle','ellipse'].includes(event.op))return;
  primitives.push({...event,points:event.points?.map((p:any)=>({...p})),from:event.op==='lineTo'?{...dc.position}:undefined,pen:{...dc.pen},brush:{...dc.brush},color:dc.textColor});
 }});
 for(const address of[0x536444,0x536448,0x5363f0,0x536434,0x536438,0x536404,0x5233a8,0x53644c])image.writeI32(address,0);
 if(request.kind==='coach'){image.writeI32(0x536444,300);o.drawPauseScreen(image,dc,random,o);}
 else if(request.kind==='forecast')o.drawForecastScreen(image,dc,random,o);
 else{
  image.writeI32(request.kind==='wind'?0x536434:0x536438,1);
  key(image,request.zoom?88:90,o);
  for(let n=0;n<Math.abs(request.offset??0);n++)key(image,(request.offset??0)>0?187:189,o);
  o.drawChart(image,dc,0,0,image.readI32(0x4fe624),image.readI32(0x4fe2a8),0,request.kind==='wind'?4:5,o);
 }
 let text=primitives.filter(p=>p.op==='textOut');
 const optionsIndex=text.findIndex(p=>p.text?.trim()==='Major Options:');if(optionsIndex>=0)text=text.slice(0,optionsIndex);
 text=text.filter(p=>p.text?.trim()&&!/^(press |space|return to|hit |movement suspended| - (wind|tide) chart)/i.test(p.text));
 const group=(text:NativePrimitive[])=>{
  const coordinates=new Map(text.map(p=>[p.x+','+p.y,p]));
  const rows=new Map<number,string[]>();for(const p of [...coordinates.values()].sort((a,b)=>a.y!-b.y!||a.x!-b.x!)){if(!rows.has(p.y!))rows.set(p.y!,[]);rows.get(p.y!)!.push(p.text!.trim());}
  return [...rows.values()].map(v=>v.join(' · '));
 };
 const historyTitle=request.kind==='forecast'?text.find(p=>p.text?.includes('Wind history at the committee boat')):undefined;
 const history=historyTitle?group(text.filter(p=>p.x!>=historyTitle.x!&&p!==historyTitle)):undefined;
 const paragraphs=group(historyTitle?text.filter(p=>p.x!<historyTitle.x!):text);
 return {kind:request.kind,title:titles[request.kind],clock:memory.readI32(0x4f8cd0),paragraphs,history,primitives:request.kind==='wind'||request.kind==='current'?primitives:[],width:image.readI32(0x4fe624),height:image.readI32(0x4fe2a8)};
}
