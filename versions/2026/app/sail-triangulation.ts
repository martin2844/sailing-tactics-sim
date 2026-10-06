import {ShapeUtils,Vector2,Vector3} from 'three';

/** Triangulate cloth in its own foot/head plane. The historical painter view
 * can turn a curved sail into a self-intersecting contour when it swings;
 * using that contour for a 3D fill silently leaves panels unmeshed. */
export function triangulateSail(points:readonly Vector3[]):number[][] {
 if(points.length<3)return [];
 // Native main contours run from the tack up to the head and back to the
 // clew. Cloth coordinates follow those anchors as the boom moves. Keeping
 // that basis also avoids changing diagonals when world axes exchange roles.
 const origin=points[0],across=points.at(-1)!.clone().sub(origin);
 const up=points.reduce((a,b)=>a.y>b.y?a:b).clone().sub(origin);
 if(across.lengthSq()<1e-12)return [];
 across.normalize();up.addScaledVector(across,-up.dot(across));
 if(up.lengthSq()<1e-12)return [];
 up.normalize();
 const offset=new Vector3();
 const plane=points.map(p=>{offset.copy(p).sub(origin);return new Vector2(offset.dot(across),offset.dot(up));});
 return ShapeUtils.triangulateShape(plane,[]);
}
