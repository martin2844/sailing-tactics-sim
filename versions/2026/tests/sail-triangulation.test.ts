import {test} from 'node:test';
import assert from 'node:assert/strict';
import {ShapeUtils,Vector2,Vector3} from 'three';
import {triangulateSail} from '../app/sail-triangulation.ts';

// Original Optimist high-luff contour captured from the private native model.
// The former fixed painter projection emitted five triangles and covered only
// 3.40 of its 20.18 square units in the sail's boom/mast plane.
const contour=[
 [.099609375,.51123046875,-2.0458984375],
 [.43310546875,2.46826171875,-2.1220703125],
 [.72412109375,4.16552734375,-2.197265625],
 [1.015625,5.869140625,-2.27197265625],
 [1.306640625,7.61328125,-1.3447265625],
 [2.345703125,5.6943359375,-.525390625],
 [2.6123046875,3.91455078125,.37646484375],
 [2.45751953125,2.21484375,1.0859375],
 [1.98681640625,.296875,1.4873046875],
].map(p=>new Vector3(...p));

test('curved Optimist sail retains complete surface through orientation changes',()=>{
 for(let degrees=0;degrees<360;degrees+=5){
  const points=contour.map(p=>p.clone().applyAxisAngle(new Vector3(0,1,0),degrees*Math.PI/180));
  const saved=points.map(p=>p.toArray()),faces=triangulateSail(points);
  // Independent cloth coordinates: across the boom and toward the sail head.
  const across=points.at(-1)!.clone().sub(points[0]).normalize();
  const up=points[4].clone().sub(points[0]);up.addScaledVector(across,-up.dot(across)).normalize();
  const plane=points.map(p=>new Vector2(p.clone().sub(points[0]).dot(across),p.clone().sub(points[0]).dot(up)));
  const expected=Math.abs(ShapeUtils.area(plane));
  const filled=faces.reduce((sum,f)=>sum+Math.abs(ShapeUtils.area(f.map(i=>plane[i]))),0);
  assert.equal(faces.length,7,'missing panels at '+degrees+' degrees');
  assert.ok(Math.abs(filled-expected)<1e-9,'surface coverage at '+degrees+' degrees');
  assert.deepEqual(points.map(p=>p.toArray()),saved,'native contour must remain unchanged');
 }
});
