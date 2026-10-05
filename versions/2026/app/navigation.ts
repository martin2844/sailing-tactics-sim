import type {BoatView,NativeCourse,CoursePoint} from './protocol';
const near=(a:CoursePoint,b:CoursePoint)=>Math.hypot(a.x-b.x,a.y-b.y)<2;
const middle=(a:CoursePoint,b:CoursePoint)=>({x:(a.x+b.x)/2,y:(a.y+b.y)/2});
/** Use the original sailing HUD's physical target, preserving AI waypoints.
 * Bearings use the native world convention: north is decreasing map Y. */
export function navigationTarget(course:NativeCourse,boat:BoatView,clock:number){
 if(boat.finished>0)return {label:'Finished',kind:'finished',bearing:undefined};
 const returning=clock<0||boat.status===2,target=returning?course.target:course.navigationTarget??course.target;let label='Target',kind='target';
 if(returning){kind='start';label=clock<0?'Start line':'Return to start';}
 else if(course.navigationTarget?.finish||!course.navigationTarget&&near(target,middle(course.finish.a,course.finish.b))){kind='finish';label='Finish';}
 else if(course.gate?.length&&(course.navigationTarget?.point===5||[...course.gate,middle(course.gate[0],course.gate[1])].some(p=>near(target,p)))){kind='gate';label='Gate';}
 else {const point=course.navigationTarget?.point;const mark=point!==undefined?point>=3&&point<=5?point-3:-1:course.marks.findIndex(p=>near(target,p));if(mark>=0){kind='mark-'+mark;label='Mark '+(mark+1);}}
 const dx=target.x-boat.x,dy=target.y-boat.y;
 const bearing=Math.hypot(dx,dy)<.01?undefined:(Math.atan2(dx,-dy)*180/Math.PI+360)%360;
 return {label,kind,bearing};
}
export const relativeBearing=(bearing:number,heading:number)=>((bearing-heading+540)%360)-180;
