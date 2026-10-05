import {unpackNativeVisuals,type NativeBoatFrame,type NativePrimitive,type NativeVisualPacket} from './native-visuals';
const color=(v:number)=>`rgb(${v&255},${v>>>8&255},${v>>>16&255})`;
/** Preserve original 2.5D boat geometry, detail and draw order. The visible
 * animation interpolates matching native paths; topology changes snap safely. */
export class NativeBoatLayer {
 private current?:NativeBoatFrame;private previous?:NativeBoatFrame;private ctx:CanvasRenderingContext2D;
 constructor(readonly canvas:HTMLCanvasElement){this.ctx=canvas.getContext('2d')!;}
 receive(packet:NativeVisualPacket){this.previous=this.current;this.current=unpackNativeVisuals(packet);}
 reset(){this.current=undefined;this.previous=undefined;this.ctx.clearRect(0,0,this.canvas.width,this.canvas.height);}
 draw(alpha:number,width:number,height:number){
  if(!this.current)return;const ratio=Math.min(devicePixelRatio,1.5),w=Math.round(width*ratio),h=Math.round(height*ratio);if(this.canvas.width!==w||this.canvas.height!==h){this.canvas.width=w;this.canvas.height=h;}
  const ctx=this.ctx,frame=this.current,scale=Math.min(width/frame.width,height/frame.height),offsetX=(width-frame.width*scale)/2,offsetY=(height-frame.height*scale)/2;
  ctx.setTransform(1,0,0,1,0,0);ctx.clearRect(0,0,w,h);ctx.setTransform(scale*ratio,0,0,scale*ratio,offsetX*ratio,offsetY*ratio);
  // Native clip is preserved; reshaping the page cannot stretch boat proportions.
  ctx.save();ctx.beginPath();ctx.rect(0,0,frame.width,frame.height);ctx.clip();
  const previous=this.previous;
  frame.boats.forEach((boat,index)=>{const old=previous?.boats[index]?.id===boat.id?previous.boats[index]:undefined;boat.primitives.forEach((primitive,n)=>{let before=old?.primitives[n];if(before?.op!==primitive.op||before?.points?.length!==primitive.points?.length)before=undefined;this.primitive(primitive,before,alpha);});});
  ctx.restore();
 }
 private primitive(p:NativePrimitive,old:NativePrimitive|undefined,alpha:number){
  const ctx=this.ctx,mix=(v:number,previous:number|undefined)=>previous===undefined?v:previous+(v-previous)*alpha;
  const field=(name:'x'|'y'|'left'|'top'|'right'|'bottom'|'startX'|'startY'|'endX'|'endY')=>mix(p[name]!,old?.[name]);
  ctx.strokeStyle=color(p.pen.color);ctx.lineWidth=Math.max(1,p.pen.width);ctx.fillStyle=color(p.brush.color);ctx.beginPath();
  if(p.op==='polygon'){p.points!.forEach((point,i)=>{const x=mix(point.x,old?.points?.[i]?.x),y=mix(point.y,old?.points?.[i]?.y);if(i===0)ctx.moveTo(x,y);else ctx.lineTo(x,y);});ctx.closePath();}
  else if(p.op==='lineTo'){if(p.pen.null)return;ctx.moveTo(mix(p.from!.x,old?.from?.x),mix(p.from!.y,old?.from?.y));ctx.lineTo(field('x'),field('y'));ctx.stroke();return;}
  else if(p.op==='ellipse'||p.op==='arc'||p.op==='pie'){
   const left=field('left'),top=field('top'),right=field('right'),bottom=field('bottom');if(right<=left||bottom<=top)return;const x=(left+right)/2,y=(top+bottom)/2,rx=(right-left)/2,ry=(bottom-top)/2;
   if(p.op==='ellipse')ctx.ellipse(x,y,rx,ry,0,0,Math.PI*2);
   else {const start=Math.atan2((field('startY')-y)/ry,(field('startX')-x)/rx),end=p.startX===p.endX&&p.startY===p.endY?start-Math.PI*2:Math.atan2((field('endY')-y)/ry,(field('endX')-x)/rx);if(p.op==='pie')ctx.moveTo(x,y);ctx.ellipse(x,y,rx,ry,0,start,end,true);if(p.op==='arc'){if(!p.pen.null)ctx.stroke();return;}ctx.closePath();}
  }else if(p.op==='rectangle'||p.op==='roundRect')ctx.rect(field('left'),field('top'),field('right')-field('left'),field('bottom')-field('top'));
  else if(p.op==='setPixel'){ctx.fillStyle=color(p.color!);ctx.fillRect(field('x'),field('y'),1,1);return;}
  else if(p.op==='textOut'){ctx.font='13px Arial';ctx.textBaseline='top';ctx.fillStyle=color(p.color!);ctx.fillText(p.text!,field('x'),field('y'));return;}
  if(!p.brush.null)ctx.fill('evenodd');if(!p.pen.null)ctx.stroke();
 }
}
