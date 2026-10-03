# Original CDC virtual call prototypes and drawing stack contracts.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
import hashlib
from java.util import ArrayList
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.data import FunctionDefinitionDataType, IntegerDataType, UnsignedIntegerDataType, DoubleDataType, VoidDataType, PointerDataType, CharDataType, StructureDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.pcode import HighFunctionDBUtil, PcodeOp
from ghidra.program.model.symbol import SourceType

args = getScriptArgs()
if len(args) not in (1,2):raise ValueError('Output directory and optional --hud-only required')
hud_only=len(args)==2
if hud_only and str(args[1])!='--hud-only':raise ValueError('Unknown drawing metadata mode')
destination = str(args[0]); os.makedirs(destination) if not os.path.isdir(destination) else None
manager = currentProgram.getFunctionManager()
record = {'source_sha256': str(currentProgram.getExecutableSHA256()), 'scope': 'Analyst metadata only; original instructions unchanged.', 'prototypes': [], 'virtualCalls': []}

EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
if str(currentProgram.getExecutableSHA256())!=EXPECTED:raise ValueError('Exact preserved English 2010 target required')
# Original complete caller stack words; packed doubles require explicit four-byte offsets.
drawing_contracts=[('004049f0',['I']),('00405320',['I']*6),('00406590',['I']*7),
    ('00407ff0',['I']*7),('0040f240',['I']*6),('00412d30',['I']*6),
    ('0040bbc0',['I']*7),('0040c980',['I']*7),('0040db60',['I']*7),('00463f50',['I']*7),('0040e6e0',['I']*6),
    ('004118b0',['I']*7),('004243b0',['I','I','D','I','I','I']),
    ('00413bc0',['I']),('00416910',['I']),('00427f10',['I']),
    ('00428b70',['I']),('004298f0',['I']),('00406680',['I']*4),('00406e40',['I']*4),
    ('004148f0',['I']*2),('0048cf50',['I']*2),
    ('0041f3e0',['I']*2),('00463c90',['I']*2),('00463df0',['I']*3),
    ('00445860',['I']),('00446250',['I']),('00446a70',['I']),('004471e0',['I']),('004479f0',['I']),('00448100',['I']),('00448970',['I']),('004495e0',['I']),('00449ee0',['I']),('0044a5d0',['I']),('0044b0e0',['I']),('0044b930',['I']),('0044c0f0',['I']),('0044c750',['I']),('0044d0c0',['I']),('0044d690',['I']),('0044e240',['I']),('0044eb90',['I']),('0044f5c0',['I']),('0044fee0',['I']),('00450590',['I']),('00450970',['I']),('00451e60',['I']),('00452660',['I']),('00453230',['I']),('004545d0',['I']),('004559c0',['I']),('00457280',['I']),('00458ca0',['I']),('0045a150',['I']),('0045bd90',['I']),('0045c440',['I']),('0045cad0',['I']),('0045cff0',['I']),('0045df40',['I']),('00460470',['I']),('004617a0',['I']),('00461f60',['I']),('004626a0',['I']),('00462ed0',['I']),('004636c0',['I']),('004282b0',['I'])]
returns={};conventions={}
record['packedAbiEvidence']=[]
for abi_name in ['boat-renderer','scene-renderer','chart-renderer','geometry-renderer','scene-child','chart-layline','remaining-drawing','rendering-small-helper']:
    abi_path=os.path.join(os.path.dirname(destination),abi_name+'-abi-review.json')
    if not os.path.isfile(abi_path):continue
    with codecs.open(abi_path,'r','utf-8') as stream:abi=json.load(stream)
    if abi['sourceSha256']!=EXPECTED:raise ValueError('Packed renderer ABI review targets another image')
    with open(abi_path,'rb') as stream:abi_sha=hashlib.sha256(stream.read()).hexdigest()
    record['packedAbiEvidence'].append({'path':abi_path,'sha256':abi_sha,'routines':len(abi['routines'])})
    replacements={}
    for row in abi['routines']:
        if 'C' not in row['packedTypes']:continue
        if any(kind not in 'CDIP' for kind in row['packedTypes']):raise ValueError('Unsupported reviewed renderer parameter kind')
        kinds=list(row['packedTypes']);thiscall='thiscall' in row.get('callingConvention','')
        width=sum(8 if kind=='D' else 4 for kind in kinds)-(4 if thiscall else 0)
        if width!=row['stackBytes']:raise ValueError('Reviewed renderer packed byte width differs')
        address='%08x'%int(row['address'],16);replacements[address]=kinds
        conventions[address]='__thiscall' if thiscall else '__cdecl'
        recovered=row.get('currentRecoveredSignature','void').lstrip().split()[0]
        returns[address]=row.get('returnType',recovered if recovered in ['int','uint'] else 'void')
    drawing_contracts=[(address,replacements.pop(address,kinds)) for address,kinds in drawing_contracts]+sorted(replacements.items())
for address,kinds in drawing_contracts:
    function=manager.getFunctionAt(toAddr(address))
    if function is None:raise ValueError('Missing drawing function '+address)
    before=str(function.getSignature());parameters=ArrayList();offset=4
    for index,kind in enumerate(kinds):
        data_type=DoubleDataType.dataType if kind=='D' else IntegerDataType.dataType
        if kind=='C' or index==0 and 'C' not in kinds:data_type=PointerDataType(IntegerDataType.dataType,currentProgram.getDataTypeManager())
        if kind=='P':
            structure=StructureDataType('Tact2010CString',0)
            structure.add(PointerDataType(CharDataType.dataType,currentProgram.getDataTypeManager()),4,'data','Original one-pointer ANSI CString object.')
            data_type=PointerDataType(structure,currentProgram.getDataTypeManager())
        if conventions.get(address)=='__thiscall' and kind=='C':
            storage=VariableStorage(currentProgram,currentProgram.getRegister('ECX').getAddress(),4)
            parameters.add(ParameterImpl('param_%d'%(index+1),data_type,storage,currentProgram))
        else:
            parameters.add(ParameterImpl('param_%d'%(index+1),data_type,offset,currentProgram));offset+=data_type.getLength()
    return_type=returns.get(address,'void')
    result=ReturnParameterImpl(UnsignedIntegerDataType.dataType if return_type=='uint' else IntegerDataType.dataType,VariableStorage(currentProgram,currentProgram.getRegister('EAX').getAddress(),4),currentProgram) if return_type in ['int','uint'] else ReturnParameterImpl(VoidDataType.dataType,currentProgram)
    function.updateFunction(conventions.get(address,'__cdecl'),result,parameters,
        Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
    function.setStackPurgeSize(offset-4 if conventions.get(address)=='__thiscall' else 0)
    record['prototypes'].append({'address':address,'before':before,'after':str(function.getSignature())})

# The CDC vtable begins at 004cecc4. Initial DATABASE function signatures may be
# undefined(void), even when exported C infers args. Establish exact original
# thiscall storage and purge first; copying inferred C text is insufficient.
ecx=VariableStorage(currentProgram,currentProgram.getRegister('ECX').getAddress(),4)
eax=VariableStorage(currentProgram,currentProgram.getRegister('EAX').getAddress(),4)
dc_pointer=PointerDataType(IntegerDataType.dataType,currentProgram.getDataTypeManager())
char_pointer=PointerDataType(CharDataType.dataType,currentProgram.getDataTypeManager())
for address,kinds,returns in [('004b48fc',['I'],IntegerDataType.dataType),('004b4994',['P'],IntegerDataType.dataType),
    ('004b49e7',['I'],IntegerDataType.dataType),('004b4a57',['I'],IntegerDataType.dataType),
    ('0049a534',['I','I','S','I'],IntegerDataType.dataType),('004b4a1f',['I'],IntegerDataType.dataType),
    ('004b4d9d',['P','I','I'],VoidDataType.dataType),('004b4de9',['I','I'],IntegerDataType.dataType)]:
    function=manager.getFunctionAt(toAddr(address));before=str(function.getSignature());parameters=ArrayList();offset=4
    parameters.add(ParameterImpl('original_dc',dc_pointer,ecx,currentProgram))
    for index,kind in enumerate(kinds):
        data_type=char_pointer if kind=='S' else dc_pointer if kind=='P' else IntegerDataType.dataType
        parameters.add(ParameterImpl('param_%d'%(index+1),data_type,offset,currentProgram));offset+=4
    result=ReturnParameterImpl(returns,currentProgram) if returns==VoidDataType.dataType else ReturnParameterImpl(returns,eax,currentProgram)
    function.updateFunction('__thiscall',result,parameters,Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
    function.setStackPurgeSize(offset-4)
    record['prototypes'].append({'address':address,'before':before,'after':str(function.getSignature()),'purge':offset-4,'reason':'Original ECX CDC plus original stack args, verified RET cleanup.'})
virtual = {0x2c:'004b48fc',0x30:'004b4994',0x34:'004b49e7',0x38:'004b4a57',0x64:'0049a534'}
definitions = {offset:FunctionDefinitionDataType(manager.getFunctionAt(toAddr(address)).getSignature()) for offset,address in virtual.items()}
# Assembly-confirmed spills whose dataflow disappears behind the initial
# unknown-call stack cleanup. TextOut pushes four stack words; color one.
explicit_calls={}
explicit_imports={}
# Reviewed original vtable spills can hide the ECX self parameter. These
# contracts come from exact caller and pointer-definition instruction windows,
# independently of the decompiler's inferred local names.
reviewed_calls_path=os.path.join(os.path.dirname(destination),'remaining-drawing-abi-review.json')
if os.path.isfile(reviewed_calls_path):
    with codecs.open(reviewed_calls_path,'r','utf-8') as stream:reviewed_calls=json.load(stream)
    if reviewed_calls['sourceSha256']!=EXPECTED:raise ValueError('Reviewed drawing aliases target another image')
    for warning in reviewed_calls.get('numericLocalWarnings',[]):
        for row in warning.get('pointerDefinitionInstructions',[]):
            address=int(row['address'],16);encoded=row['bytes']
            actual=''.join('%02x'%(currentProgram.getMemory().getByte(toAddr(address+index))&255) for index in range(len(encoded)//2))
            if actual!=encoded:raise ValueError('Original CDC pointer-definition bytes differ')
        for row in warning.get('hiddenCdcSelfCalls',[]):
            address=int(row['callsite'],16);instruction=currentProgram.getListing().getInstructionAt(toAddr(address))
            if row['vtableOffset'] not in virtual or instruction is None or str(instruction.getMnemonicString()).upper()!='CALL':raise ValueError('Reviewed CDC alias is not a known original call')
            for item in row['instructions']:
                first=int(item['address'],16);encoded=item['bytes']
                actual=''.join('%02x'%(currentProgram.getMemory().getByte(toAddr(first+index))&255) for index in range(len(encoded)//2))
                if actual!=encoded:raise ValueError('Original CDC alias instruction bytes differ')
            explicit_calls[address]=int(row['vtableOffset'])
    record['reviewedAliasCalls']=[{'address':'%08x'%address,'vtableOffset':offset} for address,offset in sorted(explicit_calls.items())]
# HUD uses long chains of saved function pointers; unknown earlier cleanup can
# hide the pointer's vtable origin in p-code. These bounded original callsites
# were observed while executing unchanged HUD instructions with an owned CDC.
import_names=set(['MoveToEx','LineTo','Rectangle','Ellipse','Polygon','SelectObject','SetPixel',
    'SetTextColor','SetBkColor','SetBkMode','TextOutA','Arc','CreateRectRgn','DeleteObject','RoundRect','MessageBeep','Pie','GetPixel','GetStockObject','GetSystemMetrics','GetTickCount','GetCursorPos'])
import_definitions={str(function.getName()):FunctionDefinitionDataType(function.getSignature()) for function in manager.getExternalFunctions() if str(function.getName()) in import_names}
for evidence_name in ['static','hud','chart','screens','tutorial','shore','scene','frame','frame-graphics','initialized-screens','tutorial-remaining','initialized-island-chart','initialized-venue-render','normal-retained-controls']:
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
        if evidence_name=='static' and name not in import_definitions:continue
        if name not in import_definitions or instruction is None or str(instruction.getMnemonicString()).upper()!='CALL':raise ValueError('Invalid observed original '+evidence_name+' import callsite')
        explicit_imports[address]=import_definitions[name]
    record[evidence_name+'CallsiteEvidence']['importCount']=len(evidence.get('importCalls',[]))

def offset_of(node, depth=0, trail=None):
    if node is None or depth > 16: return None
    trail=set() if trail is None else trail
    key=str(node)
    if key in trail:return None
    trail=trail.union([key])
    definition=node.getDef()
    if definition is None: return None
    opcode=definition.getOpcode()
    if opcode in [PcodeOp.COPY,PcodeOp.CAST]: return offset_of(definition.getInput(0),depth+1,trail)
    if opcode in [PcodeOp.MULTIEQUAL,PcodeOp.INDIRECT]:
        offsets=set(offset_of(definition.getInput(index),depth+1,trail) for index in range(definition.getNumInputs()))
        offsets.discard(None)
        if len(offsets)==1: return next(iter(offsets))
    if opcode == PcodeOp.LOAD: return offset_of(definition.getInput(1),depth+1,trail)
    if opcode in [PcodeOp.INT_ADD,PcodeOp.PTRSUB]:
        for index in [0,1]:
            node=definition.getInput(index)
            if node.isConstant() and node.getOffset() in virtual: return node.getOffset()
            if node.isConstant() and node.getOffset()==0: return offset_of(definition.getInput(1-index),depth+1,trail)
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
observed_functions=set()
for call_address in set(explicit_calls).union(explicit_imports):
 containing=manager.getFunctionContaining(toAddr(call_address))
 if containing is not None:observed_functions.add(containing.getEntryPoint().getOffset())
prototype_addresses=set(int(row['address'],16) for row in record['prototypes'])
markers=['CDC::','SelectObject(','Rectangle(','TextOut','Ellipse(', 'Polygon(', 'GetPixel(', 'code **)(*param_1 +']
canonical=os.path.join(os.path.dirname(destination),'..','decompiled','functions')
for function in manager.getFunctions(True):
    address=function.getEntryPoint().getOffset()
    if hud_only and address not in [0x40f240,0x412d30,0x40bbc0,0x40c980,0x40db60,0x40e6e0,0x4118b0,0x463f50]:continue
    if not 0x401000 <= address < 0x49b930: continue
    observed=address in observed_functions or address in prototype_addresses
    cached=os.path.join(canonical,'%08x.c'%address)
    # Existing canonical source safely excludes procedures with no drawing
    # marker. Native/explicit addresses always enter, and fresh projects fall
    # back to decompilation. This does not manufacture additional type evidence.
    if not observed and os.path.isfile(cached):
        with codecs.open(cached,'r','utf-8') as stream:previous=stream.read()
        if not any(marker in previous for marker in markers):continue
    result=decompiler.decompileFunction(function,60,monitor)
    if not result.decompileCompleted(): continue
    source=result.getDecompiledFunction().getC()
    if not observed and not any(marker in source for marker in markers): continue
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
            if function.getEntryPoint().getOffset() in [0x405320,0x407ff0,0x413bc0,0x428b70,0x4298f0,0x445860]:missed.append({'call':str(operation.getSeqnum().getTarget()),'tree':tree(operation.getInput(0))})
            continue
        call_address=operation.getSeqnum().getTarget()
        HighFunctionDBUtil.writeOverride(function,call_address,definitions[offset])
        seen.add(str(call_address))
        record['virtualCalls'].append({'function':str(function.getEntryPoint()),'call':str(call_address),'vtableOffset':offset,'originalTarget':virtual[offset],'prototype':str(definitions[offset].getPrototypeString())})
# Earlier missing cleanup can obscure later spilled function-pointer dataflow.
# Re-decompile after the first known prototypes, then resolve additional calls.
for iteration in range(8):
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
    if function.getEntryPoint().getOffset() in [0x405320,0x407ff0,0x413bc0,0x428b70,0x4298f0,0x445860]:
        operations=result.getHighFunction().getPcodeOps()
        while operations.hasNext():
            operation=operations.next()
            if operation.getOpcode()==PcodeOp.CALLIND and str(operation.getSeqnum().getTarget()) not in seen:missed.append({'call':str(operation.getSeqnum().getTarget()),'tree':tree(operation.getInput(0))[:200]})
decompiler.dispose()
record['missedDebug']=missed
record['passScope']='Eight HUD procedures only' if hud_only else 'Complete discovered drawing metadata pass'
with codecs.open(os.path.join(destination,'hud-signatures.json' if hud_only else 'drawing-signatures.json'),'w','utf-8') as output: output.write(json.dumps(record,indent=2,sort_keys=True)+u'\n')
println('2010_DRAWING_SIGNATURES_CORRECTED '+str(len(record['virtualCalls']))+' calls in '+str(len(functions))+' functions')
