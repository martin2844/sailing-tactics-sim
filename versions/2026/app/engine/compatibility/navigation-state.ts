import type {EngineMemory,NumericalEngine} from '../ports.ts';
const wrap = (angle:number) => angle<0?(angle+360)|0:angle>359?(angle-360)|0:angle;

/** Navigation classification recovered from0x43fef0 and0x440350. It uses
 * physical course bearings/distances; no camera, drawing, pixels or RNG. */
export function updateNavigationState(m:EngineMemory,n:NumericalEngine,boat:number):number {
  const r=(address:number)=>m.readI32(address),w=(address:number,value:number)=>m.writeI32(address,value);
  const field=0x4fbf10+boat*4,clock=r(0x4f8cd0);
  if(clock<0)w(field,0);
  else {
    if(clock<30)w(field,1);
    n.bearing(m,r(0x536410),r(0x536414),boat);
    for(let index=0;index<3;index++) {
      const bearing=wrap((r(0x4f4b40)+180)|0),course=wrap(r(0x4fb51c+index*4));
      w(0x522fe8,r(0x4fb51c));w(0x52307c,r(0x4fb520));w(0x5230a0,r(0x4fb524));
      const difference=Math.abs((bearing-course)|0);
      const rounding=r(0x53527c),match=bearing===course||difference===360||bearing===course-1||bearing===course+1||(rounding===0&&difference===359);
      w(0x522fe4,bearing);
      const threshold=r(0x4fb534+index*4)-(rounding===0?60:30);
      if(index+1===r(field)&&match&&threshold<=Math.trunc(m.readF64(0x4fbb88)))w(field,(r(field)+1)|0);
    }
    const gate=r(0x536408),count=r(0x4da194),passed=r(0x4fe2b0+boat*4),nearLeeward=()=>n.distance(m,boat,r(0x5229c8),r(0x522ac4)).compare(n.number(m.readF64(0x4cc488)))<0;
    if(r(field)===4&&gate===1&&passed===1)w(field,1);
    if((r(field)===3||r(field)===2&&count<11)&&passed===1&&r(0x53527c)===1&&r(0x4f853c)===1)w(field,1);
    if(r(field)===4)w(field,0);
    if((r(field)===3||r(field)===2&&count<11)&&r(0x4da1e8)===1&&gate===0&&nearLeeward())w(field,0);
    if(r(0x4da188)<3&&(r(field)===3||r(field)===2&&count<11)&&r(0x4da1e8)===1&&nearLeeward())w(field,Number(r(0x4da1cc)<5));
    if(r(0x53527c)===1&&passed===1&&nearLeeward())w(field,1);
    if(r(0x5363f8)===1&&r(0x4da1cc)>5&&nearLeeward())w(field,0);
    if(r(0x4da1f8)===5)for(const [x,y,kind]of[[0x5117b0,0x511d30,2],[0x5117bc,0x511d3c,3],[0x5117c4,0x511d44,0]]) {
      if(n.distance(m,boat,r(x),r(y)).compare(n.number(m.readF64(0x4cc490)))<0)w(field,kind);
    }
  }
  const point=selectNavigationPoint(m,boat);
  w(0x5230b8,point);return point;
}

/** Read-only physical object selection from0x440350, after classification.
 * Separating these operations prevents presentation from advancing that state. */
export function selectNavigationPoint(m:Pick<EngineMemory,'readI32'>,boat:number):number {
  const r=(address:number)=>m.readI32(address),kind=r(0x4fbf10+boat*4);
  let point=kind===0?2:kind===1?3:kind===2?4:kind===3?5:r(0x5230b8);
  if(r(0x4f8538+boat*4)===r(0x4da1e4)&&kind>2&&r(0x53527c)===1)point=5;
  return point;
}
