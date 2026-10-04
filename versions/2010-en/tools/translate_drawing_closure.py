#!/usr/bin/env python3
"""Build static English rendering dependencies; report every unresolved source.

This produces ordinary JavaScript from recovered C, never executable-byte or
p-code execution. Generated code requires strict unchanged-native comparison.
"""
import hashlib,json,re
from translate_drawing import ROOT,PAGES,Translator,write_generated_module
from optimize_static_locals import write_optimization_report
from floating_drawing import FLOAT_IMPORT,write_number_report

ROOTS={0x407ff0:'originalDrawChart',0x405320:'originalDrawScene',
 0x40f240:'originalDrawSailingHud',0x412d30:'originalDrawCompactHud',
 0x417aa0:'originalDrawBoat',0x43faa0:'originalDrawSceneMark',0x442560:'originalDrawShoreline'}
BUILTINS={0x49b970,0x420c00,0x41bc20,0x41e000,0x464940,0x42c060,0x41bc70,0x41bd00,
 0x4b045a,0x4b05a5,0x4b0613,0x4b069e,0x4b06ed,0x4b0755,0x4b07bb,0x4b082f,0x4b4a1f,0x4b4d9d,
 0x41f3e0,0x463c90,0x463df0,0x43f9f0,0x43fa60,0x4148f0,0x48cf50,0x433a70,
 0x413bc0,0x428b70,0x4298f0,0x406590,0x427f10,0x416910,0x406680,0x406e40,0x4432b0,0x41bfb0,0x466230,0x4662d0,0x430260,0x47d5f0,0x4710c0,0x4710d0,
 *PAGES.values()}
IMPORTS='''// Generated static C source. See analysis/rendering-closure.json for unresolved/native scope.
import { Float80 } from '../../../../src/runtime/float80.js';
import { formatInteger,formatDecimal,readAnsiString,readAnsiBytes,readCString,writeCString,cStringData } from './text.js';
import { drawingTick,drawingSystemMetric,drawingPrintf,drawingSound,drawingCursor } from './host.js';
import { callDrawingDependency,registerOriginalDrawing } from './dependencies.js';
import { restoreShoreStackFrame,saveShoreStackFrame } from './shore-stack.js';
import { scalarRead,scalarReadArgument,scalarStoreI32,scalarStoreF64 } from './scalar-stack.js';
import { tryProjectPointFast } from './projection-fast.js';
import { cI32,cI64,cFloat,cAdd,cSub,cMul,cDiv,cRem,cNeg,cBits,cCompare,cTruth,cString,
 pointerAdd,localPointer,readPointer,writePointer,writeLocalPoint,stockObject,dcMethod,selectGdiObject,selectOriginalGdiObject,importDrawingMethod,originalPoints,clipRegion,textOutCount,originalTrig,cStringHeaderLength,signedBorrow32,
 cF64,cAbs,createLocalFrame,framePointer,readLocal,readLocalArgument,cWordArgument,writeLocal,originalAtan,cConcat,bitsAsF64,cRawWord,cRawSlice,invokeDrawingPointer } from './typed-c.js';
'''

def main():
 pending=set(ROOTS);seen=set();sources=[];translated=[];failures=[];optimizations=[];number_optimizations=[];water_kernels=[]
 # Pages call into the same original geometry graph.
 for source in json.loads((ROOT/'analysis/drawing-translation-sources.json').read_text())['sources']:
  pending.update(source['dependencies'])
 while pending:
  address=min(pending);pending.remove(address)
  if address in seen or address in BUILTINS:continue
  seen.add(address)
  if not 0x401000<=address<0x49b930:
   failures.append({'address':address,'reason':'Outside reviewed original application drawing range'});continue
  path=ROOT/f'analysis/drawing-corrections/{address:08x}.c'
  if not path.exists():path=ROOT/f'decompiled/functions/{address:08x}.c'
  source=path.read_text();name=ROOTS.get(address,f'originalDrawing{address:08x}')
  dc=any(token in source for token in ('CDC::','SelectObject(','TextOut','Rectangle(','Ellipse(','Polygon(','GetPixel(','SetPixel(','code **)(*param_1 +'))
  dc=dc or address in ROOTS
  try:
   translator=Translator(name,address,source,has_dc=dc);code=translator.generate(name)
   if address==0x43ea10:
    guard=f'  if(retainedLocalBytes!=null)return {name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes);'
    if code.count(guard)!=1:raise ValueError('Expected exactly one reviewed camera-projection fallback guard')
    code=code.replace(guard,guard+'\n  const fastProjection=tryProjectPointFast(memory,originalArgs,options);\n  if(fastProjection!==undefined)return fastProjection;')
  except Exception as error:
   failures.append({'address':address,'source':str(path.relative_to(ROOT)),
    'sourceSha256':hashlib.sha256(source.encode()).hexdigest(),'reason':str(error)})
   # Discover further C application calls even while this source needs repair.
   pending.update(int(m,16) for m in re.findall(r'\bFUN_([0-9a-fA-F]{8})\s*\(',source))
   continue
  dc=translator.has_dc
  optimizations.append(translator.scalar_stack_optimization)
  number_optimizations.append(getattr(translator,'number_optimization',{'address':address,'function':name,'eligible':False,'floatingOperations':0,'reasons':['Separate reviewed camera projection implementation']}))
  if hasattr(translator,'water_number_slab_kernel'):water_kernels.append(translator.water_number_slab_kernel)
  translated.append((address,name,code,dc,translator.dc_index))
  sources.append({'address':address,'name':name,'hasDc':dc,'dcIndex':translator.dc_index,'source':str(path.relative_to(ROOT)),
   'sourceSha256':hashlib.sha256(source.encode()).hexdigest(),'dependencies':sorted(translator.dependencies)})
  pending.update(translator.dependencies)
 numeric_registration=''.join(f'registerOriginalNumberDrawing({hex(row["address"])},{row["function"]}Number,{json.dumps(row["floatingParameters"])});\n' for row in number_optimizations if row['eligible'])
 if len(water_kernels)>1:raise ValueError('Multiple reviewed water kernels')
 if water_kernels:write_generated_module(ROOT/'src/render/water-number-slab.js',water_kernels[0])
 write_generated_module(ROOT/'src/render/drawing-functions.js',IMPORTS+FLOAT_IMPORT+'\n\n'.join(row[2] for row in translated)+'\n'+''.join(f'registerOriginalDrawing({hex(a)},{name},{str(dc).lower()},{json.dumps(dc_index)});\n' for a,name,_,dc,dc_index in translated)+numeric_registration)
 write_optimization_report(ROOT,'drawing-functions.js',optimizations)
 write_number_report(ROOT,'drawing-functions.js',number_optimizations)
 report={'format':1,'sourceSha256':'d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787',
  'scope':'Static source generation only. Each complete routine still requires original native drawing/state/RNG proof.',
  'roots':ROOTS,'generated':len(translated),'unresolved':len(failures),'sources':sources,'failures':failures}
 (ROOT/'analysis/rendering-closure.json').write_text(json.dumps(report,indent=2)+'\n')
 print('Generated',len(translated),'static functions;',len(failures),'explicit unresolved functions')

if __name__=='__main__':main()
