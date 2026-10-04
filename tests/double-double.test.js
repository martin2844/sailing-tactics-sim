import test from 'node:test';
import assert from 'node:assert/strict';
import {readFile} from 'node:fs/promises';
import {Float80,getX87ControlWord,withX87ControlWord} from '../src/runtime/float80.js';
import {dd,ddAdd,ddSub,ddMul,ddDiv,ddFromFixed,ddToFixed} from '../src/runtime/double-double.js';
import {sinCosX87,sinCosX87Number} from '../src/runtime/transcendentals.js';
import {fpTrig} from '../versions/2010-en/src/render/float-values.js';

const magnitude=value=>value<0n?-value:value;
const hex=value=>Buffer.from(value.toBytes()).toString('hex');
const fixed=value=>{
  const image=Float80.fromNumber(value),shift=image.exponent+512;
  assert.ok(shift>=0,'The bounded transform corpus has no unrepresentable fixed512 component');
  return BigInt(image.sign)*(image.mantissa<<BigInt(shift));
};
const pairFixed=value=>fixed(value[0])+fixed(value[1]);
const scale=1n<<512n;
const absoluteBudget=1n<<416n; // 2^-96, stricter than the candidate's 2^-88 enclosure.

test('bounded double-double arithmetic retains cancellation and division correction beyond binary64',()=>{
  const input=integer=>ddFromFixed(integer,224);
  const unit=1n<<224n;
  const values=[input(unit/5n),input(-unit/3n),input(unit*4n/5n),input(unit/(1n<<112n)),dd(1)];
  for(const a of values)for(const b of values){
    const af=pairFixed(a),bf=pairFixed(b);
    assert.ok(magnitude(pairFixed(ddAdd(a,b))-(af+bf))<absoluteBudget);
    assert.ok(magnitude(pairFixed(ddSub(a,b))-(af-bf))<absoluteBudget);
    assert.ok(magnitude(pairFixed(ddMul(a,b))*scale-af*bf)<absoluteBudget*scale);
  }
  for(const anchor of [1,1+1/64,1.5,2]){
    const denominator=dd(anchor),df=pairFixed(denominator);
    for(const numerator of [input(1n),input(-1n),input(unit/128n),ddSub(input(unit/5n),input(unit/5n+1n))]){
      const quotient=ddDiv(numerator,denominator);
      assert.ok(magnitude(pairFixed(quotient)*df-pairFixed(numerator)*scale)<absoluteBudget*scale,
        'The division residual is bounded absolutely, including near-total cancellation');
    }
  }
  const small=ddFromFixed((1n<<224n)+1n,224);
  assert.equal(small[0],1);
  assert.equal(pairFixed(ddSub(small,dd(1))),1n<<288n);
});

test('fixed conversions preserve the low component and truncate both signs within two units',()=>{
  const unit=1n<<224n;
  for(const integer of [0n,1n,-1n,unit+1n,-unit-1n,unit/5n,-unit/5n,unit*4n/5n,-unit*4n/5n]){
    const value=ddFromFixed(integer,224);
    assert.ok(magnitude(pairFixed(value)-(integer<<288n))<absoluteBudget);
    const stored=ddToFixed(value,112),exact=pairFixed(value)/(1n<<400n);
    assert.ok(magnitude(stored-exact)<=1n);
  }
});

test('exact binary64 ratio correction stays bounded across both large-operand domain edges',()=>{
  const values=[2**-100,2**-100+2**-152,.1,.99,1,1+2**-52,2**100-2**47,2**100];
  for(const numerator of values)for(const denominator of values){
    if(numerator>denominator)continue;
    const af=fixed(numerator),bf=fixed(denominator),quotient=pairFixed(ddDiv(dd(numerator),dd(denominator)));
    const error=magnitude(quotient*bf-af*scale);
    assert.ok((error<<106n)<=8n*af*scale,'Relative ratio error is at most eight u-squared units');
  }
});

test('Number trigonometric cache keeps signs, precision controls, finite validation and immutable images',()=>{
  const before=getX87ControlWord();
  for(const word of [0x007f,0x027f,0x037f])withX87ControlWord(word,()=>{
    for(const value of [0,-0,Number.MIN_VALUE,-Number.MIN_VALUE,2**-101,-(2**-101),.5,-.5,
      Math.PI/4,Math.PI/2,Math.PI,12345.125,1000000.125,-1000000.125,2**20,-(2**20),2**20+2**-32]){
      const actual=sinCosX87Number(value),expected=sinCosX87(Float80.fromNumber(value));
      assert.equal(hex(actual.sine),hex(expected.sine));
      assert.equal(hex(actual.cosine),hex(expected.cosine));
      assert.ok(Object.isFrozen(actual));
      const loaded=fpTrig(Float80.fromNumber(value));
      assert.equal(hex(loaded.sine),hex(expected.sine));assert.equal(hex(loaded.cosine),hex(expected.cosine));
      if(value===0)assert.equal(actual.sine.sign,Object.is(value,-0)?-1:1);
    }
    assert.equal(sinCosX87Number(.5),sinCosX87Number(.5));
    assert.notEqual(sinCosX87Number(-0),sinCosX87Number(-0));
    for(const value of [NaN,Infinity,-Infinity])assert.throws(()=>sinCosX87Number(value),/NaN or infinite/);
    assert.throws(()=>sinCosX87Number('0.5'),TypeError);
    assert.equal(getX87ControlWord(),word);
  });
  assert.equal(getX87ControlWord(),before);
});

test('Number trigonometric retention is bounded and clears when the control word changes',async()=>{
  const location=new URL('../src/runtime/transcendentals.js',import.meta.url);
  const source=(await readFile(location,'utf8')).replace(/from (['"])([^'"]+)\1/g,
    (_all,_quote,path)=>'from '+JSON.stringify(new URL(path,location).href));
  const observed=await import('data:text/javascript;base64,'+Buffer.from(source+'\nexport {numberSinCosCache,SIN_COS_CACHE_LIMIT};').toString('base64'));
  withX87ControlWord(0x027f,()=>{
    const first=observed.sinCosX87Number(.125);
    observed.sinCosX87Number(-0);observed.sinCosX87Number(0);
    assert.equal(observed.numberSinCosCache.size,1);
    assert.equal(observed.sinCosX87Number(.125),first);
    for(let index=1;index<=observed.SIN_COS_CACHE_LIMIT;index++)observed.sinCosX87Number(.125+index/4096);
    assert.equal(observed.numberSinCosCache.size,observed.SIN_COS_CACHE_LIMIT);
    assert.equal(observed.numberSinCosCache.has(.125),false);
    assert.notEqual(observed.sinCosX87Number(.125),first);
    assert.throws(()=>observed.sinCosX87Number(2**63),/outside its reduction range/);
    assert.equal(observed.numberSinCosCache.size,observed.SIN_COS_CACHE_LIMIT);
  });
  withX87ControlWord(0x037f,()=>{
    observed.sinCosX87Number(.125);
    assert.equal(observed.numberSinCosCache.size,1);
  });
});

test('Number drawing trigonometry calls an explicit provider with the original Float80 operand',()=>{
  const provided={sine:Float80.fromInteger(7),cosine:Float80.fromInteger(9)};
  let calls=0,expected=Float80.fromNumber(.5),identity;
  const options={sinCos:value=>{
    calls++;assert.ok(value instanceof Float80);assert.equal(hex(value),hex(expected));
    if(identity)assert.equal(value,identity,'An explicit provider sees the original Float80 object');
    return provided;
  }};
  assert.equal(fpTrig(.5,options),provided);
  expected=Float80.fromNumber(-0);
  identity=expected;
  assert.equal(fpTrig(expected,options),provided);
  assert.equal(calls,2);
  const inherited=Object.create(options);
  assert.equal(fpTrig(expected,inherited),provided);
  assert.equal(calls,3);
  // The original generic C integer conversion canonicalizes an untyped -0.
  expected=Float80.fromInteger(0);
  identity=undefined;
  assert.equal(fpTrig(-0,options),provided);
  assert.equal(calls,4);
});
