# Exact preserved 2010 English CString and formatter contracts.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
from java.util import ArrayList
from ghidra.program.model.data import CharDataType, DoubleDataType, IntegerDataType, PointerDataType, StructureDataType, VoidDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.symbol import SourceType

EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
if str(currentProgram.getExecutableSHA256())!=EXPECTED:raise ValueError('Exact preserved 2010 English target required')
args=getScriptArgs()
if len(args)!=1:raise ValueError('Analysis output directory required')
destination=str(args[0])
if not os.path.isdir(destination):os.makedirs(destination)
manager=currentProgram.getFunctionManager()
chars=PointerDataType(CharDataType.dataType,currentProgram.getDataTypeManager())
structure=StructureDataType('Tact2010CString',0)
structure.add(chars,4,'data','Original one-pointer ANSI CString object.')
strings=PointerDataType(structure,currentProgram.getDataTypeManager())
eax=VariableStorage(currentProgram,currentProgram.getRegister('EAX').getAddress(),4)
ecx=VariableStorage(currentProgram,currentProgram.getRegister('ECX').getAddress(),4)
record={'source_sha256':EXPECTED,'scope':'Decompiler metadata only, inferred from original calls/stack accesses/RET cleanup. Target instructions unchanged.','changes':[]}
for address,encoded in [('004710c0','8b0183e80cc3'),('004710d0','8b01c3')]:
 first=toAddr(address).getOffset()
 actual=''.join('%02x'%(currentProgram.getMemory().getByte(toAddr(first+index))&255) for index in range(len(encoded)//2))
 if actual!=encoded:raise ValueError('Original CString accessor instructions differ')
def snapshot(function):
 return {'address':str(function.getEntryPoint()),'signature':str(function.getSignature()),'purge':function.getStackPurgeSize(),
  'parameters':[{'name':str(p.getName()),'type':str(p.getDataType()),'storage':str(p.getVariableStorage())} for p in function.getParameters()]}

specifications=[
 ('004b045a','__thiscall',strings,[], 'Zero constructor receives this in ECX; EAX returns this; RET0.'),
 ('004b046a','__thiscall',strings,[strings], 'Copy constructor receives this ECX and source CString* at entry+4; RET4.'),
 ('004b0613','__thiscall',strings,[chars], 'ANSI constructor receives this ECX and ANSI pointer at entry+4; RET4.'),
 ('004b05a5','__thiscall',VoidDataType.dataType,[], 'Destructor receives this ECX; no stack arguments; RET0.'),
 ('004b069e','__thiscall',strings,[strings], 'CString assignment receives this ECX and CString* source; RET4.'),
 ('004b06ed','__thiscall',strings,[chars], 'ANSI assignment receives this ECX and ANSI source; RET4.'),
 ('004b0755','__stdcall',strings,[strings,strings,strings], 'CString+CString concat: out*,left*,right* at+4/+8/+12; verified RET0x0c at4b07b8.'),
 ('004b07bb','__stdcall',strings,[strings,strings,chars], 'CString+ANSI concat: out*,left*,ANSI right at+4/+8/+12; verified RET0x0c at4b082c.'),
 ('004b082f','__stdcall',strings,[strings,chars,strings], 'ANSI+CString concat: out*,ANSI left,right* at+4/+8/+12; verified RET0x0c at4b08a0.'),
 ('0041bc70','__cdecl',strings,[strings,IntegerDataType.dataType], 'Game integer formatter: out*+4,valueI32+8; EAX out*, caller cleanup.'),
 ('0041bd00','__cdecl',strings,[strings,DoubleDataType.dataType], 'Game fraction formatter: out*+4,valueF64+8 unaligned; EAX out*, caller cleanup.'),
 ('004710c0','__thiscall',chars,[], 'CString header accessor: object ECX; MOV EAX,[ECX], SUB EAX,12; plain RET, no stack parameters.'),
 ('004710d0','__thiscall',chars,[], 'CString data accessor: object ECX; MOV EAX,[ECX]; plain RET, no stack parameters.')]
for address,convention,returns,kinds,reason in specifications:
 function=manager.getFunctionAt(toAddr(address))
 if function is None:raise ValueError('Missing function '+address)
 before=snapshot(function);parameters=ArrayList();offset=4
 if convention=='__thiscall':parameters.add(ParameterImpl('original_this',strings,ecx,currentProgram))
 for index,kind in enumerate(kinds):
  parameters.add(ParameterImpl('param_%d'%(index+1),kind,offset,currentProgram));offset+=kind.getLength()
 result=ReturnParameterImpl(returns,currentProgram) if returns==VoidDataType.dataType else ReturnParameterImpl(returns,eax,currentProgram)
 function.updateFunction(convention,result,parameters,Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
 function.setStackPurgeSize(0 if convention=='__cdecl' else offset-4)
 if address=='0041bd00' and str(function.getParameter(1).getVariableStorage())!='Stack[0x8]:8':raise ValueError('Original unaligned F64 formatter ABI failed')
 record['changes'].append({'before':before,'after':snapshot(function),'reason':reason})
with codecs.open(os.path.join(destination,'cstring-signatures.json'),'w','utf-8') as stream:stream.write(json.dumps(record,indent=2,sort_keys=True)+u'\n')
println('2010_CSTRING_SIGNATURES_CORRECTED '+str(len(record['changes'])))
