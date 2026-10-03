# Preserve exact original x87 conversion dataflow for the fixed English 2010 image.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
import hashlib
import re
from java.util import ArrayList
from ghidra.program.database import SpecExtension
from ghidra.program.model.data import Float10DataType, LongLongDataType, IntegerDataType, UnsignedIntegerDataType, DoubleDataType, VoidDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.symbol import SourceType
EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
if str(currentProgram.getExecutableSHA256())!=EXPECTED:raise ValueError('Exact English 2010 target required')
args=getScriptArgs()
if len(args)!=1:raise ValueError('Analysis output required')
destination=str(args[0])
if not os.path.isdir(destination):os.makedirs(destination)
function=currentProgram.getFunctionManager().getFunctionAt(toAddr('0049b970'))
if function is None:raise ValueError('Missing original __ftol at49b970')
before=str(function.getSignature());st0=VariableStorage(currentProgram,currentProgram.getRegister('ST0').getAddress(),10)
# Initial recovered database entries can still be undefined(void), although the
# exported C infers a return. Allocate the original Windows cdecl signed64
# register pair explicitly before retaining it with the custom ST0 argument.
function.updateFunction('__cdecl',ReturnParameterImpl(LongLongDataType.dataType,currentProgram),ArrayList(),
 Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,True,SourceType.USER_DEFINED)
parameters=ArrayList();parameters.add(ParameterImpl('x87_value',Float10DataType.dataType,st0,currentProgram))
# Native assembly returns full signed64 in EDX:EAX. The compiler model already
# selects the correct joined register ordering for LongLongDataType.
function.updateFunction('__cdecl',ReturnParameterImpl(function.getReturn(),currentProgram),parameters,
 Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
xml='''<callfixup name="tact2010_ftol_x87_pop"><pcode><body><![CDATA[
local converted:8 = trunc(ST0);
EAX = converted[0,32]; EDX = converted[32,32];
ST0 = ST1; ST1 = ST2; ST2 = ST3; ST3 = ST4;
ST4 = ST5; ST5 = ST6; ST6 = ST7;
ESP = ESP + 4;
]]></body></pcode></callfixup>'''
SpecExtension(currentProgram).addReplaceCompilerSpecExtension(xml,monitor)
function.setCallFixup('tact2010_ftol_x87_pop')
if str(function.getReturn().getVariableStorage())!='EDX:4,EAX:4':raise ValueError('Original FTOL EDX:EAX allocation failed: '+str(function.getReturn().getVariableStorage()))
record={'source_sha256':EXPECTED,'scope':'Decompiler metadata only; original instructions unchanged. Finite representable conversion model; flags/traps require separate native reference.',
 'changes':[{'address':'0049b970','before':before,'after':str(function.getSignature()),'inputStorage':str(function.getParameter(0).getVariableStorage()),
 'returnStorage':str(function.getReturn().getVariableStorage()),'callFixup':function.getCallFixup()}],'callfixupXml':xml}
# Integration at0043d777 pushes boat, y, x and cleans twelve stack bytes.
# The standalone native authority confirms the original signed32 return.
current=currentProgram.getFunctionManager().getFunctionAt(toAddr('0042fca0'))
if current is None:raise ValueError('Missing original basic-current routine')
before=str(current.getSignature());parameters=ArrayList()
for index,name in enumerate(['x','y','boat']):
 parameters.add(ParameterImpl(name,IntegerDataType.dataType,4+index*4,currentProgram))
current.updateFunction('__cdecl',ReturnParameterImpl(IntegerDataType.dataType,currentProgram),parameters,
 Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
current.setStackPurgeSize(0)
record['changes'].append({'address':'0042fca0','before':before,'after':str(current.getSignature()),
 'reason':'Original integration caller pushes three I32 arguments and cleans twelve bytes; native finite authority confirms I32 return.'})
# Single-routine numeric oracle manifests are the edition-local, independently
# ABI-reviewed fixed calls. Controllers/MFC/CDC contracts are deliberately out
# of this list. Packed F64 arguments start at +4 with no synthetic alignment.
contracts={}
def file_sha256(path):
 digest=hashlib.sha256()
 with open(path,'rb') as stream:
  while True:
   block=stream.read(1048576)
   if not block:break
   digest.update(block)
 return digest.hexdigest()
def numeric_header(path):
 # Native case bodies can exceed200MiB. Only the small original ABI header is
 # required here; parsing every prepared memory state in Jython wastes heap.
 with codecs.open(path,'r','utf-8') as stream:prefix=stream.read(65536)
 source=re.search(r'"sourceSha256"\s*:\s*"([0-9a-f]{64})"',prefix)
 routine=re.search(r'"routine"\s*:',prefix)
 if source is None or routine is None:return None
 specification=json.JSONDecoder().raw_decode(prefix[routine.end():].lstrip())[0]
 return {'sourceSha256':source.group(1),'routine':specification}
for name in sorted(os.listdir(destination)):
 if not name.endswith('-capture-inputs.json'):continue
 path=os.path.join(destination,name)
 specification=numeric_header(path)
 if specification is None:continue
 routine=specification.get('routine')
 if routine is None or specification.get('sourceSha256')!=EXPECTED:continue
 kinds=routine.get('argumentTypes',[]);returns=routine.get('returnType')
 if any(kind not in ['I32','U32','F64'] for kind in kinds):continue
 if returns not in ['I32','U32','F64','float10','void']:continue
 address=int(routine['address']);key=(tuple(kinds),returns)
 if address in contracts and contracts[address]['key']!=key:raise ValueError('Conflicting verified numeric ABI for '+hex(address))
 contracts[address]={'key':key,'path':path,'sha256':file_sha256(path)}
# Additional exact caller/entry assembly contracts uncovered by HUD recovery.
for address,kinds,returns in [(0x43ec20,['F64','F64','I32','I32'],'float10'),(0x440350,['I32'],'I32'),(0x41e3a0,['I32'],'I32'),(0x41bc20,['I32'],'I32'),(0x41bc40,['F64'],'float10'),(0x41e000,['I32'],'I32'),(0x43eb00,['F64','I32','F64','F64','I32'],'void'),(0x481350,['I32','I32','I32','I32'],'float10')]:
 contracts[address]={'key':(tuple(kinds),returns),'path':'original caller/entry assembly','sha256':None}
# Original packed parameter slots, confirmed by caller PUSH/cleanup and leaf loads.
for address,kinds,returns in [(0x43ea10,['F64','F64','I32'],'float10'),
 (0x43e730,['I32','F64','F64','I32','I32'],'void'),
 (0x41bfb0,['F64','I32','I32','I32','I32','F64'],'void')]:
 contracts[address]={'key':(tuple(kinds),returns),'path':'original packed caller/leaf assembly','sha256':None}
for abi_name in ['boat-renderer','scene-renderer','chart-renderer','geometry-renderer','scene-child']:
 abi_path=os.path.join(destination,abi_name+'-abi-review.json')
 if not os.path.isfile(abi_path):continue
 with codecs.open(abi_path,'r','utf-8') as stream:abi=json.load(stream)
 if abi['sourceSha256']!=EXPECTED:raise ValueError('Packed ABI review targets another original image')
 for row in abi['routines']:
  if 'C' in row['packedTypes']:continue
  if any(kind not in 'DI' for kind in row['packedTypes']):raise ValueError('Unsupported reviewed numeric parameter kind')
  kinds=tuple('F64' if kind=='D' else 'I32' for kind in row['packedTypes'])
  if sum(8 if kind=='F64' else 4 for kind in kinds)!=row['stackBytes']:raise ValueError('Packed numeric ABI width differs')
  contracts[int(row['address'],16)]={'key':(kinds,'void'),'path':abi_path,'sha256':file_sha256(abi_path)}
for address,row in sorted(contracts.items()):
 function=currentProgram.getFunctionManager().getFunctionAt(toAddr(address))
 if function is None:raise ValueError('Missing verified original numeric routine '+hex(address))
 before=str(function.getSignature());parameters=ArrayList();offset=4
 kinds,returns=row['key']
 for index,kind in enumerate(kinds):
  data_type=DoubleDataType.dataType if kind=='F64' else UnsignedIntegerDataType.dataType if kind=='U32' else IntegerDataType.dataType
  parameters.add(ParameterImpl('param_%d'%(index+1),data_type,offset,currentProgram));offset+=data_type.getLength()
 if returns in ['F64','float10']:result=ReturnParameterImpl(Float10DataType.dataType,st0,currentProgram)
 elif returns=='void':result=ReturnParameterImpl(VoidDataType.dataType,currentProgram)
 else:
  eax=VariableStorage(currentProgram,currentProgram.getRegister('EAX').getAddress(),4)
  result=ReturnParameterImpl(UnsignedIntegerDataType.dataType if returns=='U32' else IntegerDataType.dataType,eax,currentProgram)
 function.updateFunction('__cdecl',result,parameters,Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
 function.setStackPurgeSize(0)
 record['changes'].append({'address':'%08x'%address,'before':before,'after':str(function.getSignature()),
  'evidence':row['path'],'evidenceSha256':row['sha256'],'argumentTypes':kinds,'returnType':returns})
with codecs.open(os.path.join(destination,'numeric-signatures.json'),'w','utf-8') as stream:stream.write(json.dumps(record,indent=2,sort_keys=True)+u'\n')
println('2010_FTOL_SIGNATURE_CORRECTED')
