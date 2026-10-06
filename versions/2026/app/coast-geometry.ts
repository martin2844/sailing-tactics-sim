import type {CoursePoint as Point} from './protocol';
export const distance=(a:Point,b:Point)=>Math.hypot(a.x-b.x,a.y-b.y);
export function insidePolygon(p:Point,polygon:readonly Point[]){
 let inside=false;
 for(let i=0,j=polygon.length-1;i<polygon.length;j=i++){
  const a=polygon[i],b=polygon[j];
  if((a.y>p.y)!==(b.y>p.y)&&p.x<(b.x-a.x)*(p.y-a.y)/(b.y-a.y)+a.x)inside=!inside;
 }
 return inside;
}
export function pointSegmentDistance(p:Point,a:Point,b:Point){
 const x=b.x-a.x,y=b.y-a.y,l=x*x+y*y,t=l?Math.max(0,Math.min(1,((p.x-a.x)*x+(p.y-a.y)*y)/l)):0;
 return Math.hypot(p.x-a.x-t*x,p.y-a.y-t*y);
}
const cross=(a:Point,b:Point,c:Point)=>(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
export function segmentDistance(a:Point,b:Point,c:Point,d:Point){
 if(cross(a,b,c)*cross(a,b,d)<0&&cross(c,d,a)*cross(c,d,b)<0)return 0;
 return Math.min(pointSegmentDistance(a,c,d),pointSegmentDistance(b,c,d),pointSegmentDistance(c,a,b),pointSegmentDistance(d,a,b));
}
export function coastDistance(p:Point,polygons:readonly (readonly Point[])[]){
 let nearest=Infinity;for(const polygon of polygons)for(let i=0;i<polygon.length;i++)nearest=Math.min(nearest,pointSegmentDistance(p,polygon[i],polygon[(i+1)%polygon.length]));return nearest;
}
export function clearWaterSegment(a:Point,b:Point,polygons:readonly (readonly Point[])[],margin=0){
 for(const polygon of polygons){
  if(insidePolygon(a,polygon)||insidePolygon(b,polygon))return false;
  for(let i=0;i<polygon.length;i++)if(segmentDistance(a,b,polygon[i],polygon[(i+1)%polygon.length])<=margin)return false;
 }
 return true;
}
