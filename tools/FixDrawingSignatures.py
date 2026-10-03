# Original CDC virtual call prototypes and drawing stack contracts.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
from java.util import ArrayList
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.data import FunctionDefinitionDataType, IntegerDataType, DoubleDataType, VoidDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl
from ghidra.program.model.pcode import HighFunctionDBUtil, PcodeOp
from ghidra.program.model.symbol import SourceType

args = getScriptArgs()
if len(args) != 1: raise ValueError('Output directory required')
destination = str(args[0]); os.makedirs(destination) if not os.path.isdir(destination) else None
manager = currentProgram.getFunctionManager()
record = {'source_sha256': str(currentProgram.getExecutableSHA256()), 'scope': 'Analyst metadata only; original instructions unchanged.', 'prototypes': [], 'virtualCalls': []}

for address, kinds in [('00407e40', ['I']*7), ('004063e0', ['I']*7), ('00404880', ['I']*6),
    ('00421d90', ['I','I','I','D']+['I']*8), ('00431890', ['I','I','I','D']+['I']*7),
    ('00424890',['I']*6), ('0044d990',['I']*7), ('0040b990',['I']*7),
    ('00409760',['I']*7), ('0040db30',['I']*7), ('004060f0',['I']*2), ('00416300',['I','D','I','I','I']),
    ('00431440',['I']*7), ('004226c0',['I','I','I','D']+['I']*4),
    ('0044f320',['I','I','I','D']+['I']*4),
    ('00408860',['I','D','I','I']), ('00408b00',['I','D','I','I']),
    ('00408c70',['I']*4), ('00409050',['I']*4), ('004094c0',['I']*4), ('0044db20',['I']*4),
    ('0044d6d0',['I']*2), ('0044d830',['I']*3)]:
    function = manager.getFunctionAt(toAddr(address)); before = str(function.getSignature()); parameters = ArrayList()
    offset=4
    for index, kind in enumerate(kinds):
        data_type=DoubleDataType.dataType if kind == 'D' else IntegerDataType.dataType
        parameters.add(ParameterImpl('param_%d'%(index+1),data_type,offset,currentProgram));offset+=data_type.getLength()
    function.updateFunction('__cdecl',ReturnParameterImpl(VoidDataType.dataType,currentProgram),parameters,
        Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
    record['prototypes'].append({'address':address,'before':before,'after':str(function.getSignature())})

# The CDC vtable begins at 00487024. Its original entries and their already
# recovered thiscall functions provide stack cleanup and ECX this storage.
virtual = {0x2c:'0047021c',0x30:'004702b4',0x34:'00470307',0x38:'00470377',0x64:'00455e28'}
definitions = {offset:FunctionDefinitionDataType(manager.getFunctionAt(toAddr(address)).getSignature()) for offset,address in virtual.items()}
# Assembly-confirmed spills whose dataflow disappears behind the initial
# unknown-call stack cleanup. TextOut pushes four stack words; color one.
explicit_calls={0x405fae:0x38,0x408528:0x64,0x40859a:0x64,0x408632:0x38,0x40865c:0x64,0x408780:0x64,
    0x4084fb:0x38,0x408570:0x38,0x408756:0x38}
explicit_imports={}
# HUD uses long chains of saved function pointers; unknown earlier cleanup can
# hide the pointer's vtable origin in p-code. These bounded original callsites
# were observed while executing unchanged HUD instructions with an owned CDC.
import_names=set(['MoveToEx','LineTo','Rectangle','Ellipse','Polygon','SelectObject','SetPixel',
    'SetTextColor','SetBkColor','SetBkMode','TextOutA','Arc','CreateRectRgn','DeleteObject','RoundRect','MessageBeep'])
import_definitions={str(function.getName()):FunctionDefinitionDataType(function.getSignature()) for function in manager.getExternalFunctions() if str(function.getName()) in import_names}
for evidence_name in ['hud','chart','screens','tutorial','shore','scene','frame']:
    evidence_path=os.path.join(os.path.dirname(destination),evidence_name+'-cdc-callsites.json')
    if not os.path.isfile(evidence_path): continue
    with codecs.open(evidence_path,'r','utf-8') as evidence_stream: evidence=json.load(evidence_stream)
    if evidence['source_sha256']!=str(currentProgram.getExecutableSHA256()):raise ValueError(evidence_name+' CDC evidence source hash mismatch')
    for row in evidence['calls']:
        address=int(row['address']);offset=int(row['vtableOffset'])
        instruction=currentProgram.getListing().getInstructionAt(toAddr(address))
        if offset not in virtual or instruction is None or str(instruction.getMnemonicString()).upper()!='CALL':raise ValueError('Invalid observed original '+evidence_name+' CDC callsite')
        explicit_calls[address]=offset
    record[evidence_name+'CallsiteEvidence']={'path':evidence_path,'source_sha256':evidence['source_sha256'],'count':len(evidence['calls'])}
    for row in evidence.get('importCalls',[]):
        address=int(row['address']);name=str(row['name'])
        instruction=currentProgram.getListing().getInstructionAt(toAddr(address))
        if name not in import_definitions or instruction is None or str(instruction.getMnemonicString()).upper()!='CALL':raise ValueError('Invalid observed original '+evidence_name+' import callsite')
        explicit_imports[address]=import_definitions[name]
    record[evidence_name+'CallsiteEvidence']['importCount']=len(evidence.get('importCalls',[]))

def offset_of(node, depth=0):
    if node is None or depth > 8: return None
    definition=node.getDef()
    if definition is None: return None
    opcode=definition.getOpcode()
    if opcode in [PcodeOp.COPY,PcodeOp.CAST]: return offset_of(definition.getInput(0),depth+1)
    if opcode in [PcodeOp.MULTIEQUAL,PcodeOp.INDIRECT]:
        offsets=set(offset_of(definition.getInput(index),depth+1) for index in range(definition.getNumInputs()))
        offsets.discard(None)
        if len(offsets)==1: return next(iter(offsets))
    if opcode == PcodeOp.LOAD: return offset_of(definition.getInput(1),depth+1)
    if opcode in [PcodeOp.INT_ADD,PcodeOp.PTRSUB]:
        for index in [0,1]:
            node=definition.getInput(index)
            if node.isConstant() and node.getOffset() in virtual: return node.getOffset()
            if node.isConstant() and node.getOffset()==0: return offset_of(definition.getInput(1-index),depth+1)
    if opcode == PcodeOp.PTRADD:
        index=definition.getInput(1); size=definition.getInput(2)
        if index.isConstant() and size.isConstant() and index.getOffset()*size.getOffset() in virtual: return index.getOffset()*size.getOffset()
    return None

def tree(node,depth=0):
    if node is None:return 'none'
    definition=node.getDef()
    if definition is None or depth>7:return str(node)
    return str(definition.getMnemonic())+'('+','.join(tree(definition.getInput(index),depth+1) for index in range(definition.getNumInputs()))+')'

decompiler=DecompInterface(); decompiler.toggleCCode(True); decompiler.openProgram(currentProgram)
functions=[];missed=[];seen=set()
for function in manager.getFunctions(True):
    address=function.getEntryPoint().getOffset()
    if not 0x401000 <= address < 0x455000: continue
    result=decompiler.decompileFunction(function,60,monitor)
    if not result.decompileCompleted(): continue
    source=result.getDecompiledFunction().getC()
    observed = any(function.getBody().contains(toAddr(call_address)) for call_address in set(explicit_calls).union(explicit_imports))
    if not observed and not any(marker in source for marker in ['CDC::','SelectObject(','Rectangle(','TextOut','Ellipse(']): continue
    functions.append(function)
    operations=result.getHighFunction().getPcodeOps()
    while operations.hasNext():
        operation=operations.next()
        if operation.getOpcode()!=PcodeOp.CALLIND: continue
        if operation.getSeqnum().getTarget().getOffset() in explicit_imports:
            HighFunctionDBUtil.writeOverride(function,operation.getSeqnum().getTarget(),explicit_imports[operation.getSeqnum().getTarget().getOffset()])
            seen.add(str(operation.getSeqnum().getTarget()))
            continue
        offset=explicit_calls.get(operation.getSeqnum().getTarget().getOffset(),offset_of(operation.getInput(0)))
        if offset not in virtual:
            if function.getEntryPoint().getOffset() in [0x404880,0x407e40]:missed.append({'call':str(operation.getSeqnum().getTarget()),'tree':tree(operation.getInput(0))})
            continue
        call_address=operation.getSeqnum().getTarget()
        HighFunctionDBUtil.writeOverride(function,call_address,definitions[offset])
        seen.add(str(call_address))
        record['virtualCalls'].append({'function':str(function.getEntryPoint()),'call':str(call_address),'vtableOffset':offset,'originalTarget':virtual[offset],'prototype':str(definitions[offset].getPrototypeString())})
# Earlier missing cleanup can obscure later spilled function-pointer dataflow.
# Re-decompile after the first known prototypes, then resolve additional calls.
for iteration in range(4):
    decompiler.flushCache();added=0
    for function in functions:
        result=decompiler.decompileFunction(function,60,monitor)
        if not result.decompileCompleted():raise RuntimeError(str(result.getErrorMessage()))
        operations=result.getHighFunction().getPcodeOps()
        while operations.hasNext():
            operation=operations.next()
            if operation.getOpcode()!=PcodeOp.CALLIND:continue
            call_address=operation.getSeqnum().getTarget()
            if str(call_address) in seen:continue
            if call_address.getOffset() in explicit_imports:
                HighFunctionDBUtil.writeOverride(function,call_address,explicit_imports[call_address.getOffset()]);seen.add(str(call_address));added+=1
                continue
            offset=explicit_calls.get(call_address.getOffset(),offset_of(operation.getInput(0)))
            if offset not in virtual:continue
            HighFunctionDBUtil.writeOverride(function,call_address,definitions[offset]);seen.add(str(call_address));added+=1
            record['virtualCalls'].append({'function':str(function.getEntryPoint()),'call':str(call_address),'vtableOffset':offset,'originalTarget':virtual[offset],'prototype':str(definitions[offset].getPrototypeString()),'iteration':iteration+1})
    if added==0:break
decompiler.flushCache();missed=[]
for function in functions:
    result=decompiler.decompileFunction(function,60,monitor)
    if not result.decompileCompleted(): raise RuntimeError(str(result.getErrorMessage()))
    with codecs.open(os.path.join(destination,str(function.getEntryPoint())+'.c'),'w','utf-8') as output: output.write(unicode(result.getDecompiledFunction().getC()))
    if function.getEntryPoint().getOffset() in [0x404880,0x407e40]:
        operations=result.getHighFunction().getPcodeOps()
        while operations.hasNext():
            operation=operations.next()
            if operation.getOpcode()==PcodeOp.CALLIND and str(operation.getSeqnum().getTarget()) not in seen:missed.append({'call':str(operation.getSeqnum().getTarget()),'tree':tree(operation.getInput(0))[:200]})
decompiler.dispose()
record['missedDebug']=missed
with codecs.open(os.path.join(destination,'drawing-signatures.json'),'w','utf-8') as output: output.write(json.dumps(record,indent=2,sort_keys=True)+u'\n')
println('DRAWING_SIGNATURES_CORRECTED '+str(len(record['virtualCalls']))+' calls in '+str(len(functions))+' functions')
