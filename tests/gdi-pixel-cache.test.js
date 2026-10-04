import test from 'node:test';
import assert from 'node:assert/strict';
import {createCanvasGdi} from '../src/render/gdi.js';

function surface(){
  const pixels=new Uint8ClampedArray(7*11*4),reads=[];
  for(let index=0;index<pixels.length;index++)pixels[index]=(index*137+31)%256;
  const context={canvas:{width:7,height:11},pixels,reads,
    getImageData(x,y,width,height){
      assert.equal(width,1);assert.ok(x>=0&&x<7&&y>=0&&y+height<=11);
      reads.push([x,y,width,height]);
      const data=new Uint8ClampedArray(height*4);
      for(let row=0;row<height;row++)data.set(pixels.subarray(((y+row)*7+x)*4,((y+row)*7+x+1)*4),row*4);
      return {data};
    },
    fillRect(x,y){pixels.set([17,34,51,255],(y*7+x)*4);},
  };
  return context;
}

test('exclusive canvas read tiles preserve adjacent and interleaved visibility samples including edges',()=>{
  const plain=surface(),cached=surface();
  const baseline=createCanvasGdi(plain,{recordEvents:false});
  const candidate=createCanvasGdi(cached,{recordEvents:false,cachePixelReads:true});
  for(const [x,y] of [[1,2],[4,6],[1,1],[4,5],[0,0],[6,10],[6,9],[-1,0],[7,0],[0,11]]){
    assert.equal(candidate.getPixel(x,y),baseline.getPixel(x,y));
  }
  assert.equal(plain.reads.length,7);
  assert.equal(cached.reads.length,4);
  assert.deepEqual(cached.reads.at(-1),[6,8,1,3]);
});

test('drawing and other intervening events invalidate read tiles; each DC starts empty',()=>{
  const context=surface(),dc=createCanvasGdi(context,{recordEvents:false,cachePixelReads:true});
  dc.getPixel(2,4);dc.setPixel(2,5,0x332211);
  assert.equal(dc.getPixel(2,5),0x332211);
  assert.equal(context.reads.length,2);
  dc.moveTo(0,0);dc.getPixel(2,5);
  assert.equal(context.reads.length,3);
  const next=createCanvasGdi(context,{recordEvents:false,cachePixelReads:true});
  next.getPixel(2,5);assert.equal(context.reads.length,4);
});

test('custom sinks, samplers and recorded traces retain the unbatched read contract',()=>{
  for(const options of [{},{recordEvents:false,sink(){}},{recordEvents:true}]){
    const context=surface(),dc=createCanvasGdi(context,{cachePixelReads:true,...options});
    dc.getPixel(1,1);dc.getPixel(1,2);
    assert.deepEqual(context.reads,[[1,1,1,1],[1,2,1,1]]);
  }
  const context=surface(),queries=[];
  const dc=createCanvasGdi(context,{recordEvents:false,cachePixelReads:true,
    readPixel(x,y){queries.push([x,y]);return 0xabcdef;}});
  assert.equal(dc.getPixel(1,1),0xabcdef);assert.equal(dc.getPixel(1,2),0xabcdef);
  assert.deepEqual(queries,[[1,1],[1,2]]);assert.equal(context.reads.length,0);
});
