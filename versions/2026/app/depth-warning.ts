import type {BoatView} from './protocol';
export function depthWarning(boat:Pick<BoatView,'depth'|'grounded'|'groundingDepth'>){
 const depth=boat.depth,limit=boat.groundingDepth;
 if(depth===undefined||limit===undefined||!Number.isFinite(depth)||!Number.isFinite(limit))return {level:'unknown',label:'',description:'Depth unavailable'};
 const clearance=depth-limit;
 if(boat.grounded)return {level:'grounded',label:'Grounded',description:'Steer toward deeper water'};
 if(clearance<=Math.max(2,limit*.25))return {level:'danger',label:'Shallow water',description:clearance<0?'Below the grounding depth':`${clearance.toFixed(1)} ft above the grounding depth`};
 if(clearance<=Math.max(5,limit*.75))return {level:'caution',label:'Shoaling',description:`${clearance.toFixed(1)} ft above the grounding depth`};
 return {level:'clear',label:'',description:`Grounding depth ${limit.toFixed(1)} ft · clearance ${clearance.toFixed(1)} ft`};
}
