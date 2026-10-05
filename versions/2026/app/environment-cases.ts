/** Isolated diagnostic inputs. The master image / native RNG are never written.
 * Actual original dynamics and current samplers determine every output. */
export async function evaluateEnvironmentCases(memory:any,rng:any,options:any,Memory:any,Rng:any,updateDynamics:any,sampleCurrent:any,sampleVenueCurrent:any){
 const rows=[];
 for(const depth of [100,50,5,1]){
  const m=new Memory(memory.size,memory.base);m.bytes.set(memory.bytes);const random=new Rng(rng.state);
  m.writeI32(0x5364e8,1);m.writeI32(0x4f8cd0,300);m.writeI32(0x4f42b8,0);m.writeF64(0x4ffcc0,depth);m.writeI32(0x5359d0,10);m.writeI32(0x536404,1);m.writeI32(0x4f6d60,0);m.writeI32(0x4ffdd0,0);
  const privateOptions={...options,rng:random,playSound:()=>1,messageBeep:()=>{},beep:()=>{}};
  const current=(m.readI32(0x4da1f8)?sampleVenueCurrent:sampleCurrent)(m,Math.trunc(m.readF64(0x4f6b00)),Math.trunc(m.readF64(0x4f6c18)),1,privateOptions);
  updateDynamics(m,1,random,privateOptions);
  const hash=new Uint8Array(await crypto.subtle.digest('SHA-256',m.bytes));
  rows.push({depth,speed:m.readI32(0x4fdfec)/10,smoothSpeed:m.readF64(0x4fe188),status:m.readI32(0x5116e4),current,currentDirection:m.readI32(0x522d34),currentEffect:m.readI32(0x522fd8),rngState:random.state,memorySha256:[...hash].map(v=>v.toString(16).padStart(2,'0')).join('')});
 }
 return rows;
}
