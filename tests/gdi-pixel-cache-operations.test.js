import test from 'node:test';
import assert from 'node:assert/strict';
import {createCanvasGdi} from '../src/render/gdi.js';

function surface(width=19,height=17){
  const pixels=new Uint8ClampedArray(width*height*4),calls=[],reads=[];
  for(let at=0;at<pixels.length;at++)pixels[at]=(at*113+47)&255;
  let generation=0;
  const mutate=()=>{
    generation++;
    for(let at=0;at<pixels.length;at+=4)pixels.set([generation,2*generation,3*generation,255],at);
  };
  const context={canvas:{width,height},reads,calls,
    getImageData(x,y,readWidth,readHeight){
      assert.equal(readWidth,1);
      assert.ok(x>=0&&x<width&&y>=0&&y+readHeight<=height);
      reads.push([x,y,readWidth,readHeight]);
      const data=new Uint8ClampedArray(readHeight*4);
      for(let row=0;row<readHeight;row++)data.set(pixels.subarray(((y+row)*width+x)*4,((y+row)*width+x+1)*4),row*4);
      return {data};
    },
    measureText(text){calls.push(['measureText',text]);return {width:3,fontBoundingBoxAscent:2,fontBoundingBoxDescent:1};},
  };
  for(const method of ['beginPath','moveTo','lineTo','closePath','rect','ellipse','save','clip','restore']){
    context[method]=(...args)=>calls.push([method,...args]);
  }
  for(const method of ['fill','stroke','fillRect','fillText']){
    context[method]=(...args)=>{calls.push([method,...args]);mutate();};
  }
  return context;
}

const states=[
  ['moveTo',dc=>dc.moveTo(5,7)],
  ['selectObject',dc=>dc.selectObject(1)],
  ['selectStockObject',dc=>dc.selectStockObject(7)],
  ['setTextColor',dc=>dc.setTextColor(0x332211)],
  ['setBkColor',dc=>dc.setBkColor(0x665544)],
  ['setBkMode',dc=>dc.setBkMode(1)],
  ['pushClipRect',dc=>dc.pushClipRect(0,0,2,2)],
  ['popClipRect',dc=>dc.popClipRect()],
];
const drawings=[
  ['lineTo',dc=>dc.lineTo(5,7)],
  ['polygon',dc=>dc.polygon([{x:1,y:2},{x:4,y:8},{x:7,y:3}])],
  ['rectangle',dc=>dc.rectangle(1,2,7,8)],
  ['roundRect',dc=>dc.roundRect(1,2,7,8,2,4)],
  ['ellipse',dc=>dc.ellipse(1,2,7,8)],
  ['arc',dc=>dc.arc(1,2,7,8,7,5,1,5)],
  ['pie',dc=>dc.pie(1,2,7,8,7,5,1,5)],
  ['setPixel',dc=>dc.setPixel(2,2,0x332211)],
  ['textOut',dc=>dc.textOut(1,2,'sail')],
  ['messageBeep',dc=>dc.messageBeep(0)],
  ['unknown event',dc=>dc.emit({op:'unknown'})],
];

test('every non-raster GDI state operation preserves visibility cache and exact canvas call order',()=>{
  for(const [name,operation] of states){
    const plain=surface(),cached=surface();
    const baseline=createCanvasGdi(plain,{recordEvents:false});
    const candidate=createCanvasGdi(cached,{recordEvents:false,cachePixelReads:true});
    assert.equal(candidate.getPixel(4,1),baseline.getPixel(4,1),name);
    operation(candidate);operation(baseline);
    assert.equal(candidate.getPixel(4,5),baseline.getPixel(4,5),name);
    assert.equal(cached.reads.length,1,name);
    assert.deepEqual(cached.calls,plain.calls,name);
  }
});

test('every raster primitive, callback beep and unknown event invalidates visibility cache before dispatch',()=>{
  for(const [name,operation] of drawings){
    const plain=surface(),cached=surface();
    const make=(context,cachePixelReads)=>createCanvasGdi(context,{recordEvents:false,cachePixelReads,
      messageBeep(){context.fillRect(0,0,1,1);}});
    const baseline=make(plain,false),candidate=make(cached,true);
    assert.equal(candidate.getPixel(4,1),baseline.getPixel(4,1),name);
    operation(candidate);operation(baseline);
    assert.equal(candidate.getPixel(4,5),baseline.getPixel(4,5),name);
    assert.equal(cached.reads.length,2,name);
    assert.deepEqual(cached.calls,plain.calls,name);
  }
});

test('eight-row visibility tiles cover native y/y+4 pairs, interleaved reverse probes and clipped canvas edges',()=>{
  const plain=surface(),cached=surface();
  const baseline=createCanvasGdi(plain,{recordEvents:false});
  const candidate=createCanvasGdi(cached,{recordEvents:false,cachePixelReads:true});
  const points=[[2,1],[2,5],[3,6],[9,4],[3,5],[9,3],[18,16],[18,16],[-1,0],[19,0],[0,17],[0,-1]];
  for(const point of points)assert.equal(candidate.getPixel(...point),baseline.getPixel(...point));
  assert.deepEqual(cached.reads,[[2,0,1,8],[3,0,1,8],[9,0,1,8],[18,16,1,1]]);
  assert.equal(plain.reads.length,8);
  candidate.pushClipRect(0,0,1,1);
  assert.equal(candidate.getPixel(18,16),baseline.getPixel(18,16));
  candidate.popClipRect();
  assert.equal(candidate.getPixel(18,16),baseline.getPixel(18,16));
  assert.equal(cached.reads.length,4,'getImageData ignores the canvas clip');
});
