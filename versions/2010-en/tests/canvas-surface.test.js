import test from 'node:test';
import assert from 'node:assert/strict';
import {resetBitmapSurface} from '../src/runtime/canvas-surface.js';

function surface({reset=true}={}){
  const changes=[];
  let width=1024,height=722;
  const canvas={get width(){return width;},set width(value){changes.push(['width',value]);width=value;},
    get height(){return height;},set height(value){changes.push(['height',value]);height=value;}};
  const context={font:'22px serif'};
  if(reset)context.reset=function(){assert.equal(this,context);changes.push(['reset']);};
  return {canvas,context,changes};
}

test('an unchanged surface uses one complete context reset and restores the original font',()=>{
  const {canvas,context,changes}=surface();
  resetBitmapSurface(canvas,context,1024,722);
  assert.deepEqual(changes,[['reset']]);
  assert.equal(context.font,'13px Arial');
});

test('older contexts receive one complete width reset and resized surfaces keep both dimensions',()=>{
  const {canvas,context,changes}=surface({reset:false});
  resetBitmapSurface(canvas,context,1024,722);
  assert.deepEqual(changes,[['width',1024]]);
  changes.length=0;
  resetBitmapSurface(canvas,context,1280,720);
  assert.deepEqual(changes,[['width',1280],['height',720]]);
  assert.equal(canvas.width,1280);assert.equal(canvas.height,720);
  assert.equal(context.font,'13px Arial');
});
