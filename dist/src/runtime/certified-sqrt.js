// Certify a binary64 square-root candidate using its exact squared residual.
// This helper models nearest/even PC53. Its caller must guard that context.
const image=new DataView(new ArrayBuffer(8));
const splitter=134217729;

export function certifiedSqrtNumber(value){
  if(typeof value!=='number'||!Number.isFinite(value)||value<0)return undefined;
  if(value===0)return value;
  if(value<2**-100||value>2**100)return undefined;
  let candidate;
  try{candidate=Math.sqrt(value);}catch{return undefined;}
  if(!Number.isFinite(candidate)||candidate<=0)return undefined;
  const square=candidate*candidate;
  // This also bounds every Dekker intermediate away from overflow/underflow.
  // Sterbenz then makes value-square exact before subtraction of squareError.
  if(!(square>=value/2&&square<=value*2))return undefined;
  const split=splitter*candidate,high=split-(split-candidate),low=candidate-high;
  const squareError=((high*high-square)+high*low+low*high)+low*low;
  const residual=(value-square)-squareError;
  if(residual===0)return candidate;

  image.setFloat64(0,candidate,true);
  const highWord=image.getUint32(4,true),lowWord=image.getUint32(0,true);
  const exponent=((highWord>>>20)&0x7ff)-1023;
  const upperSpacing=2**(exponent-52);
  const lowerSpacing=(highWord&0xfffff)===0&&lowWord===0?upperSpacing/2:upperSpacing;
  const lowerProduct=candidate*lowerSpacing,upperProduct=candidate*upperSpacing;
  // The true squared midpoint displacements are
  //   -candidate*lowerSpacing + lowerSpacing^2/4
  //   +candidate*upperSpacing + upperSpacing^2/4.
  // Products by these powers of two are exact. Moving both limits inward by
  // 2^-50 of their magnitude dominates their omitted quadratic term (<=2^-54)
  // and rounding of these limit calculations. Residual subtraction has at
  // most u relative error; the additional 4u margin bounds its exact value.
  const lowerLimit=-lowerProduct+lowerProduct*2**-50;
  const upperLimit=upperProduct-upperProduct*2**-50;
  const residualMargin=Math.abs(residual)*2**-51;
  return residual-residualMargin>lowerLimit&&residual+residualMargin<upperLimit
    ?candidate:undefined;
}
