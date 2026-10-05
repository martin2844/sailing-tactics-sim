/** Read-only observer of the original boat draw requests. Never samples RNG,
 * writes game memory, overrides drawing decisions or replaces the real sink. */
export interface NativePrimitive {op:string;part?:number;points?:{x:number;y:number}[];x?:number;y?:number;from?:{x:number;y:number};left?:number;top?:number;right?:number;bottom?:number;startX?:number;startY?:number;endX?:number;endY?:number;color?:number;text?:string;pen:{color:number;width:number;null?:boolean};brush:{color:number;null?:boolean}}
export interface NativeBoatDrawing {id:number;primitives:NativePrimitive[];calibration?:{height:number;width:number}}
export interface NativeBoatFrame {width:number;height:number;boats:NativeBoatDrawing[]}
export function createNativeVisualObserver(){
  let current:NativeBoatDrawing|undefined;let boats:NativeBoatDrawing[]=[];let recording=true;
  const supported=new Set(['lineTo','polygon','ellipse','arc','pie','rectangle','roundRect','setPixel','textOut']);
  return {
    begin(_memory:unknown,_dc:unknown,id:number){current={id,primitives:[]};boats.push(current);},
    end(){current=undefined;},
    calibrate(value:{height:number;width:number}){if(current)current.calibration=value;},
    clear(){current=undefined;boats=[];},
    setRecording(value:boolean){recording=value;},
    observe(event:any,dc:any){if(!recording||!current||!supported.has(event.op))return;current.primitives.push({...event,points:event.points?.map((p:{x:number;y:number})=>({...p})),from:event.op==='lineTo'?{...dc.position}:undefined,pen:{...dc.pen},brush:{...dc.brush},...(event.op==='textOut'?{color:dc.textColor}:{} )});},
    frame(width:number,height:number):NativeBoatFrame{return {width,height,boats:boats.filter(b=>b.primitives.length||b.calibration)};}
  };
}

export interface NativeVisualPacket {width:number;height:number;styles:Int32Array;geometry:Int32Array;boats:Int32Array}
const opcodes=['','polygon','lineTo','ellipse','rectangle','setPixel','arc','pie','roundRect','textOut'];
export function packNativeVisuals(frame:NativeBoatFrame):NativeVisualPacket {
 const styles:number[]=[],geometry:number[]=[],boats:number[]=[],styleIds=new Map<string,number>();
 for(const boat of frame.boats){const start=geometry.length;for(const p of boat.primitives){
  const op=opcodes.indexOf(p.op);if(op<1)throw new Error('Unknown original boat primitive: '+p.op);
  const style=[p.pen.color,p.pen.width,p.brush.color,Number(!!p.pen.null)|Number(!!p.brush.null)<<1];const key=style.join(',');let styleId=styleIds.get(key);if(styleId===undefined){styleId=styleIds.size;styleIds.set(key,styleId);styles.push(...style);}
  let data:number[];
  if(p.op==='polygon')data=p.points!.flatMap(point=>[point.x,point.y]);
  else if(p.op==='lineTo')data=[p.from!.x,p.from!.y,p.x!,p.y!];
  else if(p.op==='setPixel')data=[p.x!,p.y!,p.color!];
  else if(p.op==='textOut')data=[p.x!,p.y!,p.color??0,...Array.from(p.text!,c=>c.charCodeAt(0))];
  else {data=[p.left!,p.top!,p.right!,p.bottom!];if(p.op==='arc'||p.op==='pie')data.push(p.startX!,p.startY!,p.endX!,p.endY!);}
  geometry.push(op,styleId,data.length,...data);
 }boats.push(boat.id,start,geometry.length);}
 return {width:frame.width,height:frame.height,styles:Int32Array.from(styles),geometry:Int32Array.from(geometry),boats:Int32Array.from(boats)};
}
export function unpackNativeVisuals(packet:NativeVisualPacket):NativeBoatFrame {
 const boats:NativeBoatDrawing[]=[];
 for(let n=0;n<packet.boats.length;n+=3){const primitives:NativePrimitive[]=[];for(let at=packet.boats[n+1];at<packet.boats[n+2];){const op=opcodes[packet.geometry[at]],style=packet.geometry[at+1]*4,length=packet.geometry[at+2],v=packet.geometry.slice(at+3,at+3+length);at+=3+length;
  const p:NativePrimitive={op,pen:{color:packet.styles[style],width:packet.styles[style+1],null:!!(packet.styles[style+3]&1)},brush:{color:packet.styles[style+2],null:!!(packet.styles[style+3]&2)}};
  if(op==='polygon')p.points=Array.from({length:v.length/2},(_,i)=>({x:v[i*2],y:v[i*2+1]}));
  else if(op==='lineTo'){p.from={x:v[0],y:v[1]};p.x=v[2];p.y=v[3];}
  else if(op==='setPixel'){p.x=v[0];p.y=v[1];p.color=v[2];}
  else if(op==='textOut'){p.x=v[0];p.y=v[1];p.color=v[2];p.text=String.fromCharCode(...v.slice(3));}
  else {p.left=v[0];p.top=v[1];p.right=v[2];p.bottom=v[3];if(op==='arc'||op==='pie'){p.startX=v[4];p.startY=v[5];p.endX=v[6];p.endY=v[7];}}
  primitives.push(p);
 }boats.push({id:packet.boats[n],primitives});}
 return {width:packet.width,height:packet.height,boats};
}
