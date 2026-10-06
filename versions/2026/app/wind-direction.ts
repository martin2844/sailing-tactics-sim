/** Configure a prevailing direction while retaining native strength, shifts and gusts. */
export function createWindDirectionHooks(direction:number|undefined){
 if(direction===undefined)return {};
 const offsets=new WeakMap<object,number>(),wrap=(value:number)=>(value%360+360)%360;
 return {
  configureWindDirection(memory:{readI32:(a:number)=>number;writeI32:(a:number,v:number)=>void}){
   offsets.delete(memory);const sector=direction/45+1;
   memory.writeI32(0x4f46a8,direction);memory.writeI32(0x4fad38,sector);
   if(memory.readI32(0x4da1f8)===5){memory.writeI32(0x53646c,Number(sector<4));memory.writeI32(0x4da214,sector<4?-1:1);}
  },
  adjustWindBearing(memory:object,bearing:number){let offset=offsets.get(memory);if(offset===undefined){offset=direction-bearing;offsets.set(memory,offset);}return wrap(bearing+offset);},
 };
}
