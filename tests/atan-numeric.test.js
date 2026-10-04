import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord,getX87ControlWord} from '../src/runtime/float80.js';
import {atan2ExtendedNumeric,atan2ExtendedUncached} from '../src/runtime/atan.js';
import {fpAtan,fpArgument} from '../versions/2010-en/src/render/float-values.js';
import {originalAtan} from '../versions/2010-en/src/render/typed-c.js';

const image=value=>Buffer.from(value.toBytes()).toString('hex');
const outcome=call=>{try{const value=call();return {value:value instanceof Float80?image(value):value};}
  catch(error){return {error:{name:error.name,message:error.message}};}};
const originalNumeric=(y,x)=>atan2ExtendedUncached(Float80.fromNumber(y),Float80.fromNumber(x));

test('numeric atan keeps the exact extended image for signs, bounds, axes and exceptional ratios',()=>{
  const before=getX87ControlWord();
  const pairs=[[1,1],[.1,1],[2**-100,2**100],[2**100,2**-100],[2**-100,2**-100],[2**100,2**100],
    [2**100+2**48,1],[2**-101,1],[Number.MIN_VALUE,1],[Number.MAX_VALUE,1],
    [Number.MIN_VALUE,Number.MAX_VALUE],[1,0],[0,1],[0,0]];
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    for(const [y,x]of pairs)for(const sy of [1,-1])for(const sx of [1,-1]){
      assert.equal(image(atan2ExtendedNumeric(y*sy,x*sx)),image(originalNumeric(y*sy,x*sx)));
      assert.equal(getX87ControlWord(),word);
    }
  });
  assert.equal(getX87ControlWord(),before);
});

test('numeric atan retains left-to-right unsupported binary64 load failures',()=>{
  for(const y of [undefined,NaN,Infinity,-Infinity,'1',{},Symbol('y'),1]){
    for(const x of [undefined,NaN,Infinity,'2',1]){
      assert.deepEqual(outcome(()=>atan2ExtendedNumeric(y,x)),outcome(()=>originalNumeric(y,x)));
    }
  }
});

test('numeric drawing atan providers retain boxed signs, identities, coercions and getter/error order',()=>{
  const yImage=Float80.fromNumber(-0),xImage=Float80.fromNumber(1.25),provided=Float80.fromNumber(.25);
  let calls=0;
  const provider=(y,x)=>{calls++;assert.equal(y,yImage);assert.equal(x,xImage);return provided;};
  assert.equal(fpAtan(yImage,xImage,{atan2:provider}),provided);
  assert.equal(fpAtan(yImage,xImage,Object.create({atan2:provider})),provided);assert.equal(calls,2);
  for(const [y,x]of [[1.5,2**63],[-0,-1],[undefined,1],[undefined,NaN],[NaN,1],[1,Infinity],[1n,2n],[true,false]]){
    const invoke=implementation=>{
      const events=[],options={get atan2(){events.push('provider');return (actualY,actualX)=>{
        events.push('callback');assert.ok(actualY instanceof Float80);assert.ok(actualX instanceof Float80);
        return image(actualY)+'/'+image(actualX);
      };}};
      return {outcome:outcome(()=>implementation(y,x,options)),events};
    };
    assert.deepEqual(invoke(fpAtan),invoke((a,b,options)=>originalAtan(fpArgument(a),fpArgument(b),options)));
  }
  const coercion=implementation=>{
    const events=[],make=(name,value)=>({[Symbol.toPrimitive](){events.push(name);return value;}});
    const options={get atan2(){events.push('provider');return ()=>provided;}};
    const result=outcome(()=>implementation(make('y',1n),make('x',2n),options));
    return {result,events};
  };
  assert.deepEqual(coercion(fpAtan),coercion((y,x,options)=>originalAtan(fpArgument(y),fpArgument(x),options)));
  for(const options of [null,{atan2:0},{atan2:null},{get atan2(){throw new Error('provider getter');}}]){
    for(const [y,x]of [[1.5,2],[undefined,1],[NaN,2]]){
      assert.deepEqual(outcome(()=>fpAtan(y,x,options)),outcome(()=>originalAtan(fpArgument(y),fpArgument(x),options)));
    }
  }
});
