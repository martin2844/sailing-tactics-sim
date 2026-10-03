// Diagnostic-only loader: substitutes one in-memory helper; never writes source or fixtures.
export async function load(url,context,nextLoad){
 const result=await nextLoad(url,context);
 if(url!==new URL('../../src/engine/waypoints.js',import.meta.url).href)return result;
 let source=String(result.source);
 if(source.includes('export function clampedPointDistanceExtended(')){
  return {...result,source:source+'\nexport {clampedPointDistanceExtended as diagnosticOriginalClampedPointDistance};\n'};
 }
 if(source.includes("const diagnosticDistanceStats="))return result;
 if(!source.includes('export function clampedPointDistance(memory,x0,y0,x1,y1)'))throw new Error('Diagnostic exact source marker missing');
 source=source.replace('export function clampedPointDistance(memory,x0,y0,x1,y1)','function originalClampedPointDistance(memory,x0,y0,x1,y1)');
 source += '\nexport {originalClampedPointDistance as diagnosticOriginalClampedPointDistance};\n';
 return {...result,source:source+"\nimport {getX87ControlWord} from '../../../../src/runtime/float80.js';\nimport {writeFileSync as diagnosticWriteFile} from 'node:fs';\nconst diagnosticDistanceStats={fast:0,fallback:0,contextFallback:0,operandFallback:0,subtractFallback:0,productFallback:0,sumFallback:0};\nconst diagnosticNormal=value=>Number.isFinite(value)&&(value===0||Math.abs(value)>=2.2250738585072014e-308);\nexport function clampedPointDistance(memory,x0,y0,x1,y1){\n const fallback=reason=>{diagnosticDistanceStats.fallback++;diagnosticDistanceStats[reason]++;return originalClampedPointDistance(memory,x0,y0,x1,y1);};\n if(getX87ControlWord()!==0x027f)return fallback('contextFallback');\n if(![x0,y0,x1,y1].every(value=>typeof value==='number'&&Number.isFinite(value)))return fallback('operandFallback');\n const dx=x0-x1,dy=y1-y0;\n if(!diagnosticNormal(dx)||!diagnosticNormal(dy))return fallback('subtractFallback');\n const xx=dx*dx,yy=dy*dy;\n if(!diagnosticNormal(xx)||!diagnosticNormal(yy)||(xx===0&&dx!==0)||(yy===0&&dy!==0))return fallback('productFallback');\n const square=yy+xx;\n if(!diagnosticNormal(square))return fallback('sumFallback');\n diagnosticDistanceStats.fast++;\n const floor=memory.readF64(0x4cc658);\n if(square<=floor)return Float80.fromNumber(floor);\n if(square<memory.readF64(0x4cccc8))return Float80.fromNumber(Math.sqrt(square));\n return Float80.fromNumber(memory.readF64(0x4cccc0));\n}\nprocess.on('exit',()=>diagnosticWriteFile('/tmp/tact-pc53-distance-stats-'+process.pid+'.json',JSON.stringify({kind:'Diagnostic-only guarded PC53 binary64 distance; original Float80 on every unsupported intermediate',...diagnosticDistanceStats},null,2)+'\\n'));\n"};
}
