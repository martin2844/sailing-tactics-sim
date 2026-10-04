// Error-free binary64 transforms for the bounded transcendental candidates.
// Callers prove bounded, normal intermediates; these are not general x87
// operations and do not replace the extended-precision fallback.
const splitter=134217729;
export const dd=value=>[value,0];
export function ddAdd(a,b){
  const sum=a[0]+b[0],v=sum-a[0];
  const error=(a[0]-(sum-v))+(b[0]-v)+a[1]+b[1];
  const high=sum+error;
  return [high,error-(high-sum)];
}
export const ddNeg=a=>[-a[0],-a[1]];
export const ddSub=(a,b)=>ddAdd(a,ddNeg(b));
export function ddMul(a,b){
  const product=a[0]*b[0];
  const ca=splitter*a[0],ah=ca-(ca-a[0]),al=a[0]-ah;
  const cb=splitter*b[0],bh=cb-(cb-b[0]),bl=b[0]-bh;
  const error=((ah*bh-product)+ah*bl+al*bh)+al*bl+a[0]*b[1]+a[1]*b[0]+a[1]*b[1];
  const high=product+error;
  return [high,error-(high-product)];
}
export function ddDiv(a,b){
  const first=a[0]/b[0];
  const remainder=ddSub(a,ddMul(b,dd(first)));
  return ddAdd(dd(first),dd((remainder[0]+remainder[1])/b[0]));
}
export function ddFromFixed(integer,precision){
  const scale=2**precision;
  const high=Number(integer)/scale;
  const residual=integer-BigInt(high*scale);
  return [high,Number(residual)/scale];
}
export function ddToFixed(value,precision){
  const scale=2**precision;
  return BigInt(Math.trunc(value[0]*scale))+BigInt(Math.trunc(value[1]*scale));
}
