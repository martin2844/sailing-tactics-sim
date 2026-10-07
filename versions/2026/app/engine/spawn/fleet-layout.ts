import {distance,separation,type Body,type Pose} from '../../contact-geometry.ts';
export interface FleetLayout {boats:Body[];obstacles:Body[];safe(body:Body):boolean}
/** Keep original proposed positions when safe. Move conflicting boats through a
 * bounded deterministic search; circle clearance also allows a hull to rotate.
 * No rendering input or gameplay random draw participates in placement. */
export function clearFleetLayout(layout:FleetLayout):Body[] {
 const placed:Body[]=[],margin=4;
 for(const boat of layout.boats){
  const valid=(pose:Pose)=>{
   const candidate={...boat,pose};
   return placed.every(other=>distance(pose,other.pose)>=boat.radius+other.radius+margin)
    &&layout.obstacles.every(other=>separation(candidate,other).gap>=margin)
    &&layout.safe(candidate);
  };
  let pose:Pose|undefined=valid(boat.pose)?{...boat.pose}:undefined;
  const step=Math.max(8,boat.radius*1.5);
  for(let ring=1;ring<=80&&!pose;ring++){
   const radius=ring*step,count=Math.min(96,Math.max(16,Math.ceil(radius/step)*8));
   for(let index=0;index<count;index++){
    const angle=index/count*Math.PI*2;
    const candidate={...boat.pose,x:boat.pose.x+Math.cos(angle)*radius,y:boat.pose.y+Math.sin(angle)*radius};
    if(valid(candidate)){pose=candidate;break;}
   }
  }
  if(!pose)throw new Error('No clear starting position for '+boat.key);
  placed.push({...boat,pose});
 }
 return placed;
}
