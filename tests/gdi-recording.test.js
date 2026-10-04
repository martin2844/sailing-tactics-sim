import test from 'node:test';
import assert from 'node:assert/strict';
import { GdiTrace } from '../src/render/gdi.js';

test('disabling diagnostic recording preserves drawing delivery, DC state and pixel returns',()=>{
  const render=recordEvents=>{
    const delivered=[],objects=new Map([[9,{kind:'pen',color:0x123456,width:2}]]);
    let pixelReads=0;
    const dc=new GdiTrace({objects,recordEvents,sink:event=>delivered.push(event),readPixel:()=>{pixelReads++;return 0xabcdef;}});
    dc.selectObject(9);dc.moveTo(3,4);dc.lineTo(5,6);
    dc.setTextColor(0x123456);dc.setBkColor(0x654321);dc.setBkMode(1);
    dc.pushClipRect(0,0,40,50);dc.polygon([{x:1,y:2},{x:3,y:4},{x:5,y:6}]);dc.popClipRect();
    dc.textOut(4,5,'Original text');const pixel=dc.getPixel(2,3);dc.messageBeep(0);
    return {delivered,pixel,pixelReads,recorded:dc.events,state:{position:dc.position,pen:dc.pen,
      textColor:dc.textColor,backgroundColor:dc.backgroundColor,backgroundMode:dc.backgroundMode}};
  };
  const traced=render(true),player=render(false);
  assert.deepEqual(player.delivered,traced.delivered);
  assert.deepEqual(player.state,traced.state);
  assert.equal(player.pixel,0xabcdef);assert.equal(player.pixelReads,1);
  assert.deepEqual(player.recorded,[]);assert.deepEqual(traced.recorded,traced.delivered);
});
