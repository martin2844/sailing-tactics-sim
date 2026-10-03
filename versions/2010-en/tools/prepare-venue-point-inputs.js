import { readFile,writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { VENUE_POINT_DEFINITIONS } from '../src/engine/venue-definitions.js';
import { VENUE_GEOMETRY_ADDRESSES as a } from '../src/engine/venue-geometry.js';

const source=await readFile(new URL('../runtime/Tactics2010EnglishPreserved.exe',import.meta.url));
const sourceSha256=createHash('sha256').update(source).digest('hex');
const manifests=[];
for(const [venue,definition]of Object.entries(VENUE_POINT_DEFINITIONS)){
  const cases=[];
  const defined=Object.keys(definition.points).map(Number).sort((left,right)=>left-right);
  for(const index of defined)for(const placementMode of [0,1])for(const seed of [1,0x20102002]){
    cases.push({group:'literal-definition-and-placement',arguments:[index],seed,
      inputs:{pointCount:Math.max(...defined),boatCount:2,placementMode}});
  }
  for(const boatCount of [0,1,30])for(const placementMode of [-1,0,1,2]){
    cases.push({group:'target-copy-and-retention',arguments:[defined[0]],seed:0xffffffff,
      inputs:{pointCount:Math.max(...defined),boatCount,placementMode}});
  }
  const manifest={source:'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',sourceSha256,
    routine:{name:`initializeVenuePoint${venue}`,address:definition.routine,argumentTypes:['I32'],returnType:'void'},
    venue:Number(venue),x87ControlWord:'0x027f',mutableBlock:{address:0x4da000,size:0x60588},
    integerInputs:{pointCount:a.pointCount,boatCount:a.boatCount,placementMode:a.placementMode},
    integerOutputs:{pointCount:a.pointCount,boatCount:a.boatCount,placementMode:a.placementMode},
    scope:'Complete named-venue point constructor. Literal definition writes, all72 original random draws, generated/closing polygon vertices and target placement are covered by full mutable-state hashes. Prepared finite supported indices.',cases};
  const file=`venue-${venue}-point-capture-inputs.json`;
  await writeFile(new URL(`../analysis/${file}`,import.meta.url),JSON.stringify(manifest,null,2)+'\n');
  manifests.push({venue:Number(venue),address:definition.routine,file,cases:cases.length});
}
await writeFile(new URL('../analysis/venue-point-capture-index.json',import.meta.url),JSON.stringify(manifests,null,2)+'\n');
console.log(`${manifests.length} complete point constructors, ${manifests.reduce((sum,row)=>sum+row.cases,0)} calls prepared.`);
