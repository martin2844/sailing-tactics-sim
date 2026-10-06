import type {CoursePoint as Point,CourseLine} from './protocol';
import type {CourseSample} from './starter-samples';
import type {RaceSettings} from './race-settings';
import {PreviewWater} from './preview-water.ts';
import {distance} from './coast-geometry.ts';
export const previewRoutes:Record<number,string[]>={1:['W','L'],2:['W','L','W','L'],3:['W','R','L'],4:['W','R','L','W','R','L'],5:['W','R','L','W','L'],6:['W','L'],7:['W','L','W','L']};
export interface PreviewLabel {text:string;x:number;y:number;width:number;height:number;anchor:Point;leader:Point}
const middle=(line:CourseLine)=>({x:(line.a.x+line.b.x)/2,y:(line.a.y+line.b.y)/2});
export function buildPreviewLayout(sample:CourseSample,settings:RaceSettings,water=new PreviewWater(sample.terrain),measure=(text:string)=>text.length*6.8){
 const startLine=water.line(sample.course.start),finishLine=water.line(sample.course.finish),start=middle(startLine),finish=middle(finishLine),sequence=previewRoutes[settings.course],roundings=[...new Set(sequence)];
 const marks=sample.course.marks.map(p=>water.nearest(settings.short?{x:start.x+(p.x-start.x)*.7,y:start.y+(p.y-start.y)*.7}:p,12)),anchors:Record<string,Point>={W:marks[0],R:marks[1],L:marks[2]};
 const wind=sample.wind*Math.PI/180,gatePoints=settings.gate?[-85,85].map(offset=>{const angle=wind+offset*Math.PI/180;return water.nearest({x:anchors.L.x+Math.sin(angle)*90,y:anchors.L.y-Math.cos(angle)*90},12);}):[];
 const targets=[start,...sequence.map(key=>anchors[key]),finish],segments:{a:Point;b:Point}[]=[];let missingLinks=0;
 for(let i=1;i<targets.length;i++){let from=targets[i-1];const hint=sample.routeHints?.find(h=>distance(h.from,from)<.01&&distance(h.to,targets[i])<.01);let previous=from;const valid=hint?.points.every(p=>{const clear=water.clear(previous,p,.1);previous=p;return clear;});const route=valid?hint!.points:water.route(from,targets[i]);if(!route.length&&distance(from,targets[i])>1)missingLinks++;for(const to of route){segments.push({a:from,b:to});from=to;}}
 const points=[startLine.a,startLine.b,finishLine.a,finishLine.b,...roundings.map(key=>anchors[key]),...segments.flatMap(s=>[s.a,s.b])],bearing=(settings.windDirection===undefined?sample.wind:0)*Math.PI/180,cos=Math.cos(bearing),sin=Math.sin(bearing),rotate=(p:Point)=>({x:p.x*cos+p.y*sin,y:-p.x*sin+p.y*cos}),rotated=points.map(rotate),xs=rotated.map(p=>p.x),ys=rotated.map(p=>p.y),cx=(Math.min(...xs)+Math.max(...xs))/2,cy=(Math.min(...ys)+Math.max(...ys))/2,scale=Math.min(290/Math.max(150,Math.max(...xs)-Math.min(...xs)),100/Math.max(150,Math.max(...ys)-Math.min(...ys)));
 const project=(p:Point)=>{const q=rotate(p);return{x:240+(q.x-cx)*scale,y:95+(q.y-cy)*scale};},unproject=(p:Point)=>{const x=(p.x-240)/scale+cx,y=(p.y-95)/scale+cy;return{x:x*cos-y*sin,y:x*sin+y*cos};};
 const labels:PreviewLabel[]=[],reserved=[{x:12,y:8,width:130,height:40},{x:421,y:8,width:48,height:22},{x:365,y:160,width:105,height:22}];
 const symbol=(point:Point,key:string)=>({point,radius:Math.max(.05,Math.min(3.3,water.clearance(point)*scale*.65)),key});
 const symbols=[...roundings.filter(key=>!settings.gate||key!=='L').map(key=>symbol(anchors[key],key)),...gatePoints.map((p,i)=>symbol(p,'gate-'+i)),{point:start,radius:2,key:'S'},{point:finish,radius:2,key:'F'}];
 const overlaps=(a:{x:number;y:number;width:number;height:number},b:{x:number;y:number;width:number;height:number})=>a.x<b.x+b.width+3&&a.x+a.width+3>b.x&&a.y<b.y+b.height+3&&a.y+a.height+3>b.y;
 const place=(text:string,anchor:Point)=>{const p=project(anchor),width=measure(text)+6,height=15;for(const gap of[9,16,26,40,60,85])for(const [x,y]of[[p.x+gap,p.y-height/2],[p.x-gap-width,p.y-height/2],[p.x-width/2,p.y-gap-height],[p.x-width/2,p.y+gap],[p.x+gap,p.y-gap-height],[p.x-gap-width,p.y+gap]]){const rect={x,y,width,height};if(x<8||y<9||x+width>472||y+height>160||[...reserved,...labels].some(r=>overlaps(rect,r)))continue;const corners=[{x,y},{x:x+width,y},{x:x+width,y:y+height},{x,y:y+height}];if(!water.rectangle(corners.map(unproject)))continue;if(symbols.some(s=>{const q=project(s.point);return q.x+s.radius>x&&q.x-s.radius<x+width&&q.y+s.radius>y&&q.y-s.radius<y+height}))continue;const leader={x:Math.max(x,Math.min(x+width,p.x)),y:Math.max(y,Math.min(y+height,p.y))};if(!water.clear(anchor,unproject(leader),.1))continue;labels.push({text,...rect,anchor,leader});return;} }; 
 const shared=distance(start,finish)*scale<8;
 place(shared?'Start / finish':'Start',start);if(!shared)place('Finish',finish);for(const key of roundings)place(key==='W'?'1 Windward':key==='R'?'2 Reach':settings.gate?'3 Gate':'3 Leeward',anchors[key]);
 return{water,startLine,finishLine,start,finish,anchors,sequence,roundings,segments,missingLinks,project,unproject,scale,labels,symbols,shared,gatePoints};
}
