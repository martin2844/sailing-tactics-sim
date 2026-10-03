# Apply independently observed CALL contracts after original drawing types exist.
#@category Tact.Preservation
#@runtime Jython
import codecs
import hashlib
import json
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.data import FunctionDefinitionDataType
from ghidra.program.model.pcode import HighFunctionDBUtil

EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
if str(currentProgram.getExecutableSHA256())!=EXPECTED:raise ValueError('Exact preserved English 2010 target required')
args=getScriptArgs()
if len(args)<2:raise ValueError('Drawing output directory and original callsite evidence required')
destination=str(args[0])
if not os.path.isdir(destination):os.makedirs(destination)
manager=currentProgram.getFunctionManager()
virtual={0x2c:'004b48fc',0x30:'004b4994',0x34:'004b49e7',0x38:'004b4a57',0x64:'0049a534'}
definitions={offset:FunctionDefinitionDataType(manager.getFunctionAt(toAddr(address)).getSignature()) for offset,address in virtual.items()}
imports={str(function.getName()):FunctionDefinitionDataType(function.getSignature()) for function in manager.getExternalFunctions()}
record={'source_sha256':EXPECTED,'scope':'Independently established exact original CALL contracts; analyst metadata only, no original instruction edits.','evidence':[],'calls':[]}
affected={}
for name in args[1:]:
 path=str(name)
 with codecs.open(path,'r','utf-8') as stream:evidence=json.load(stream)
 if evidence['source_sha256']!=EXPECTED:raise ValueError('Drawing evidence belongs to another original')
 with open(path,'rb') as stream:digest=hashlib.sha256(stream.read()).hexdigest()
 record['evidence'].append({'path':path,'sha256':digest,'method':evidence.get('method','Unchanged original native CALL observations')})
 for group in ['calls','importCalls']:
  for row in evidence.get(group,[]):
   address=int(row['address']);at=toAddr(address)
   instruction=currentProgram.getListing().getInstructionAt(at)
   function=manager.getFunctionContaining(at)
   if instruction is None or str(instruction.getMnemonicString()).upper()!='CALL' or function is None:raise ValueError('Observed original CALL boundary or containing function absent')
   if group=='calls':
    offset=int(row['vtableOffset'])
    if offset not in definitions:raise ValueError('Unreviewed original virtual service')
    definition=definitions[offset]
   else:
    imported=str(row['name'])
    if imported not in imports:raise ValueError('Observed import has no existing signature')
    definition=imports[imported]
   HighFunctionDBUtil.writeOverride(function,at,definition)
   affected[function.getEntryPoint().getOffset()]=function
   record['calls'].append({'function':str(function.getEntryPoint()),'call':str(at),'prototype':str(definition.getPrototypeString())})
decompiler=DecompInterface();decompiler.toggleCCode(True);decompiler.openProgram(currentProgram)
for address,function in sorted(affected.items()):
 result=decompiler.decompileFunction(function,60,monitor)
 if not result.decompileCompleted():raise RuntimeError(str(result.getErrorMessage()))
 with codecs.open(os.path.join(destination,'%08x.c'%address),'w','utf-8') as stream:stream.write(unicode(result.getDecompiledFunction().getC()))
decompiler.dispose()
with codecs.open(os.path.join(destination,'native-call-contracts.json'),'w','utf-8') as stream:stream.write(json.dumps(record,indent=2,sort_keys=True)+u'\n')
println('2010_NATIVE_DRAWING_CALLS_APPLIED '+str(len(record['calls']))+' calls in '+str(len(affected))+' functions')
