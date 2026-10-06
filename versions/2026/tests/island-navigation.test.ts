import{test}from'node:test';import assert from'node:assert/strict';
import{IslandNavigator}from'../app/island-navigation.ts';
import{insidePolygon,clearWaterSegment}from'../app/coast-geometry.ts';
const coast=Array.from({length:36},(_,i)=>({x:500+210*Math.cos(i*Math.PI/18),y:460*Math.sin(i*Math.PI/18)}));
const depth=(p:{x:number;y:number})=>Math.max(0,100*(Math.hypot((p.x-500)/210,p.y/460)-1));
test('a shore route keeps every leg in buffered water while preserving its destination',()=>{
 const nav=new IslandNavigator({area:7,venue:0,polygons:[{landInside:true,points:coast}]},depth,3),start={x:0,y:0},goal={x:1000,y:0};
 assert.equal(clearWaterSegment(start,goal,[coast]),false);const route=nav.route(start,goal);assert.ok(route.length>1);assert.deepEqual(route.at(-1),goal);
 let previous=start;for(const p of route){assert.ok(nav.clear(previous,p));assert.equal(insidePolygon(p,coast),false);previous=p;}
 assert.deepEqual(nav.route({x:0,y:-1000},{x:1000,y:-1000}),[],'clear offshore legs need no intervention');
});
test('an unsafe mark can be moved into sufficiently deep water',()=>{
 const nav=new IslandNavigator({area:7,venue:0,polygons:[{landInside:true,points:coast}]},depth,8),p=nav.nearestWater({x:699,y:0});assert.ok(nav.safe(p));assert.ok(depth(p)>12);
});
