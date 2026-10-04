import test from 'node:test';
import assert from 'node:assert/strict';
import {Float80,withX87ControlWord} from '../../../src/runtime/float80.js';
import {cF64} from '../src/render/typed-c.js';
import {fpArgument} from '../src/render/float-values.js';
import {registerOriginalDrawing,registerOriginalNumberDrawing,callNumberDrawingDependency,callNumberDrawingDependencyOwned,originalNumberDrawingIsCurrent} from '../src/render/dependencies.js';

const outcome=call=>{try{return {value:call()};}catch(error){return {error:{name:error.name,message:error.message}};}};

test('fused window identity guard declines missing or replaced public registration metadata',()=>{
  const address=0x49b8e0,routine=()=>{};
  assert.equal(originalNumberDrawingIsCurrent(address),false);
  registerOriginalDrawing(address,routine,false,null);
  assert.equal(originalNumberDrawingIsCurrent(address),false);
  registerOriginalNumberDrawing(address,()=>{},[]);
  assert.equal(originalNumberDrawingIsCurrent(address),true);
  registerOriginalDrawing(address,routine,true,0);
  assert.equal(originalNumberDrawingIsCurrent(address),false);
});

test('private numeric calls preserve each stored F64 image and the original DC argument mapping',()=>withX87ControlWord(0x027f,()=>{
  const address=0x49b928,dc={dc:true},floatingParameters=[0,2,3];
  let numericCalls=0;
  const original=(_memory,_dc,_rng,_options,...args)=>floatingParameters.map(index=>{
    const value=args[index-Number(index>1)];return value===undefined?undefined:cF64(value).toNumber();
  });
  registerOriginalDrawing(address,original,true,1);
  registerOriginalNumberDrawing(address,(_memory,_dc,_rng,_options,images,...args)=>{
    assert.equal(images,true);numericCalls++;
    return floatingParameters.map(index=>args[index-Number(index>1)]);
  },floatingParameters);
  for(const removed of [false,true])for(const flags of [[],[0,2],[0,2,3]]){
    for(const values of [[-0,dc,-0,123n],[1.5,dc,2**63,Float80.fromInteger((1n<<53n)+1n)],[undefined,dc,undefined,undefined]]){
      const args=values.slice();if(!removed)args[1]=12;
      const boxed=args.map((value,index)=>flags.includes(index)?fpArgument(value):value);
      const originalArgs=removed?boxed.filter((_arg,index)=>index!==1):boxed;
      assert.deepEqual(outcome(()=>callNumberDrawingDependency(undefined,dc,address,args,flags,undefined)),
        outcome(()=>original(undefined,dc,undefined,{},...originalArgs)));
    }
  }
  assert.ok(numericCalls>0);
}));

test('custom callbacks, original-only callees and non-PC53 calls retain boxed external floating arguments',()=>{
  const dc={dc:true},address=0x49b920;
  const inspect=(_memory,_dc,_rng,_options,...args)=>args;
  registerOriginalDrawing(address,inspect,false,null);
  for(const options of [{},{numberRendering:false},{sinCos:()=>{}}]){
    const args=callNumberDrawingDependency(undefined,dc,address,[-0,2**63,undefined],[0,1,2],undefined,options);
    assert.ok(args[0] instanceof Float80);assert.equal(args[0].sign,-1);
    assert.ok(args[1] instanceof Float80);assert.equal(args[1].toNumber(),2**63);assert.equal(args[2],undefined);
  }
  const callbackAddress=0x49b918;
  const options={drawingDependencies:{[callbackAddress]:(_memory,_dc,args)=>args}};
  const values=callNumberDrawingDependency(undefined,dc,callbackAddress,[-0,3],[0],undefined,options);
  assert.ok(values[0] instanceof Float80);assert.equal(values[0].sign,-1);assert.equal(values[1],3);
  const numericAddress=0x49b910;
  registerOriginalDrawing(numericAddress,inspect,false,null);
  registerOriginalNumberDrawing(numericAddress,()=>{throw new Error('Unexpected numeric target');},[0]);
  withX87ControlWord(0x037f,()=>assert.ok(callNumberDrawingDependency(undefined,dc,numericAddress,[1.5],[0],undefined)[0] instanceof Float80));
});

test('floating actual arguments to integer formals retain the original truncation and raw-word representation',()=>withX87ControlWord(0x027f,()=>{
  const address=0x49b908,dc={dc:true};
  registerOriginalDrawing(address,()=>{throw new Error('Unexpected baseline');},false,null);
  registerOriginalNumberDrawing(address,(_memory,_dc,_rng,_options,images,...args)=>{
    assert.equal(images,true);assert.ok(args[0] instanceof Float80);assert.equal(args[0].toNumber(),1.75);
    assert.ok(args[1] instanceof Float80);assert.equal(args[1].sign,-1);return args[2];
  },[2]);
  assert.equal(callNumberDrawingDependency(undefined,dc,address,[1.75,-0,1.25],[0,1,2],undefined),1.25);
}));

test('changed public DC registration metadata declines the private numeric ABI',()=>withX87ControlWord(0x027f,()=>{
  const address=0x49b900,dc={dc:true};
  const original=(_memory,_dc,_rng,_options,...args)=>args;
  registerOriginalDrawing(address,original,false,null);
  registerOriginalNumberDrawing(address,()=>{throw new Error('Stale numeric ABI metadata');},[0]);
  registerOriginalDrawing(address,original,true,0);
  const args=callNumberDrawingDependency(undefined,dc,address,[dc,-0],[1],undefined);
  assert.equal(args.length,1);assert.ok(args[0] instanceof Float80);assert.equal(args[0].sign,-1);
}));

test('owned compiler arguments remove DC in place while public arrays and fallback callbacks retain their contract',()=>withX87ControlWord(0x027f,()=>{
  const address=0x49b8f8,dc={dc:true},numeric=(_memory,_dc,_rng,_options,images,...args)=>{assert.equal(images,true);return args;};
  registerOriginalDrawing(address,()=>{throw new Error('Unexpected baseline');},true,1);
  registerOriginalNumberDrawing(address,numeric,[0,2]);
  for(const removed of [false,true])for(const flags of [0,1,5]){
    const args=[-0,removed?dc:12,-0,4],owned=args.slice();
    const fromPublic=callNumberDrawingDependency(undefined,dc,address,args,flags,undefined);
    const fromOwned=callNumberDrawingDependencyOwned(undefined,dc,address,owned,flags,undefined);
    assert.deepEqual(fromOwned,fromPublic);assert.deepEqual(args,[-0,removed?dc:12,-0,4]);
    assert.deepEqual(owned,fromOwned);
  }
  const callbackAddress=0x49b8f0,owned=[-0,dc,3];
  const observed=callNumberDrawingDependencyOwned(undefined,dc,callbackAddress,owned,1,undefined,
    {drawingDependencies:{[callbackAddress]:(_memory,_dc,args)=>args}});
  assert.ok(observed[0] instanceof Float80);assert.equal(observed[0].sign,-1);
  assert.deepEqual(owned,[-0,dc,3]);
}));

test('floating masks preserve position31 and array fallback handles position32 without shift-count aliasing',()=>withX87ControlWord(0x027f,()=>{
  const address=0x49b8e8;
  registerOriginalDrawing(address,()=>{throw new Error('Unexpected baseline');},false,null);
  registerOriginalNumberDrawing(address,(_memory,_dc,_rng,_options,_images,...args)=>args,[31,32]);
  const args=Array(33).fill(0);args[31]=-0;args[32]=-0;
  const masked=callNumberDrawingDependencyOwned(undefined,undefined,address,args.slice(),0x80000000,undefined);
  assert.ok(Object.is(masked[31],-0));assert.ok(Object.is(masked[32],0));
  const array=callNumberDrawingDependencyOwned(undefined,undefined,address,args.slice(),[32],undefined);
  assert.ok(Object.is(array[31],0));assert.ok(Object.is(array[32],-0));
  const untouched=callNumberDrawingDependencyOwned(undefined,undefined,address,[-0],0x80000000,undefined);
  assert.equal(typeof untouched[0],'number'); // Position31 never boxes position0.
}));

test('owned floating-mask shortcut matches the complete scan across DC positions and conversion failures',()=>withX87ControlWord(0x027f,()=>{
  const dc={events:[]};let address=0x49b800,cases=0;
  const masks=[0,1,3,5,0x40000000,0x80000000,0xffffffff,NaN];
  const layouts=[[],[0],[1,2],[0,31,32],[31,32]];
  for(const dcIndex of [null,0,1,32])for(const parameters of layouts){
    const at=address--;
    registerOriginalDrawing(at,()=>{throw new Error('Unexpected original call');},dcIndex!==null,dcIndex);
    registerOriginalNumberDrawing(at,(_memory,_dc,_rng,_options,_images,...args)=>args,parameters);
    for(const removed of [false,true])for(const mask of masks)for(const variant of [0,1,2]){
      const run=owned=>{
        const log=[];
        class ObservedFloat extends Float80{
          toNumber(){log.push('number');if(variant===2)throw new Error('F64 conversion failed');return super.toNumber();}
        }
        const observed=new ObservedFloat(1,(1n<<63n)+3n,-63);
        const values=Array.from({length:34},(_,index)=>index%4===0?-0:index%4===1?observed:index%4===2?undefined:variant===1?{}:2n);
        if(dcIndex!==null&&removed)values[dcIndex]=dc;
        const result=outcome(()=>(owned?callNumberDrawingDependencyOwned:callNumberDrawingDependency)(undefined,dc,at,values,mask,undefined));
        if(result.value)result.value=result.value.map(value=>value instanceof Float80?['m80',value.exactKey()]:value);
        return {result,log};
      };
      assert.deepEqual(run(true),run(false),`dc=${dcIndex} floats=${parameters} removed=${removed} mask=${mask} variant=${variant}`);
      cases++;
    }
  }
  assert.equal(cases,960);
}));

test('accepted custom metadata copies cannot alias integer argument masks with invalid indices',()=>withX87ControlWord(0x027f,()=>{
  const copies=[[-1,31],[.5,0],[31.5,31],[-31.5,1]];
  for(const[index,[copiedIndex,argumentIndex]]of copies.entries()){
    const address=0x49b7c0-index;
    registerOriginalDrawing(address,()=>{throw new Error('Unexpected original call');},false,null);
    const parameters=[0];
    parameters.slice=()=>[copiedIndex];
    registerOriginalNumberDrawing(address,(_memory,_dc,_rng,_options,_images,...args)=>args,parameters);
    const values=Array(32).fill(0);values[argumentIndex]=-0;
    const mask=1<<argumentIndex;
    const publicResult=callNumberDrawingDependency(undefined,undefined,address,values,mask,undefined);
    const ownedResult=callNumberDrawingDependencyOwned(undefined,undefined,address,values.slice(),mask,undefined);
    assert.ok(ownedResult[argumentIndex] instanceof Float80);
    assert.equal(ownedResult[argumentIndex].sign,-1);
    assert.deepEqual(ownedResult,publicResult);
  }
}));
