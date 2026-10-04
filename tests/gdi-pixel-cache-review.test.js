import test from 'node:test';
import assert from 'node:assert/strict';
import {createCanvasGdi} from '../src/render/gdi.js';

function surface(width=96,height=9){
  const pixels=new Uint8ClampedArray(width*height*4),reads=[];
  for(let at=0;at<pixels.length;at++)pixels[at]=(at*173+91)&255;
  const context={canvas:{width,height},reads,
    getImageData(x,y,readWidth,readHeight){
      assert.equal(readWidth,1);assert.ok(Number.isInteger(x)&&Number.isInteger(y));
      assert.ok(x>=0&&x<width&&y>=0&&y+readHeight<=height);
      reads.push([x,y,readWidth,readHeight]);
      const data=new Uint8ClampedArray(readHeight*4);
      for(let row=0;row<readHeight;row++)data.set(pixels.subarray(((y+row)*width+x)*4,((y+row)*width+x+1)*4),row*4);
      return {data};
    },
  };
  return context;
}

test('cached pixel reads normalize signed C coordinates before tile lookup',()=>{
  const plain=surface(),cached=surface();
  const baseline=createCanvasGdi(plain,{recordEvents:false});
  const candidate=createCanvasGdi(cached,{recordEvents:false,cachePixelReads:true});
  const queries=[[1,1],[2**32+1,1],[1,2],[1,3],[-0,-0],[0,0],[-1,0],[0,-1],[96,0],[0,9]];
  for(const args of queries)assert.equal(candidate.getPixel(...args),baseline.getPixel(...args));
  assert.deepEqual(cached.reads,[[1,0,1,4],[0,0,1,4]]);
  assert.equal(plain.reads.length,6);
  for(const args of [[1.9,1],[-.9,0],[0,NaN],[Infinity,0],[2**53,0]]){
    assert.throws(()=>baseline.getPixel(...args),{name:'TypeError'});
    assert.throws(()=>candidate.getPixel(...args),{name:'TypeError'});
  }
  assert.equal(cached.reads.length,2,'invalid arguments fail before the sampler');
});

test('bounded tile eviction and later GDI invalidation preserve colors',()=>{
  const plain=surface(),cached=surface();
  const baseline=createCanvasGdi(plain,{recordEvents:false});
  const candidate=createCanvasGdi(cached,{recordEvents:false,cachePixelReads:true});
  for(let x=0;x<70;x++)assert.equal(candidate.getPixel(x,4),baseline.getPixel(x,4));
  assert.equal(cached.reads.length,70);
  assert.equal(candidate.getPixel(65,6),baseline.getPixel(65,6));
  assert.equal(cached.reads.length,70,'recent tiles survive the sixty-four-entry reset');
  assert.equal(candidate.getPixel(0,6),baseline.getPixel(0,6));
  assert.equal(cached.reads.length,71,'old tiles are reread after eviction');
  candidate.setBkMode(1);
  assert.equal(candidate.getPixel(65,6),baseline.getPixel(65,6));
  assert.equal(cached.reads.length,72);
});
