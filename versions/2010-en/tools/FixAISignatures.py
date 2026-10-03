# Packed, original x86 stack contracts for the complete 2010 tactical subtree.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
from java.util import ArrayList
from ghidra.program.model.data import IntegerDataType, Float10DataType, LongLongDataType, VoidDataType, DoubleDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.symbol import SourceType

EXPECTED = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
if str(currentProgram.getExecutableSHA256()) != EXPECTED:
    raise ValueError('Exact preserved English 2010 target required')
args = getScriptArgs()
if len(args) != 1:
    raise ValueError('Analysis destination required')
destination = str(args[0])
if not os.path.isdir(destination):
    os.makedirs(destination)
contracts = [
    (0x41e000, ['I32'], 'I32'),
    (0x434f70, ['I32'], 'void'),
    (0x435f90, ['I32'], 'void'),
    (0x435fe0, ['I32', 'I32', 'I32'], 'I32'),
    (0x436400, ['I32', 'I32', 'I32'], 'I32'),
    (0x436ba0, ['I32', 'I32', 'I32'], 'I32'),
    (0x437520, ['I32'], 'void'),
    (0x437d40, ['I32'], 'float10'),
    (0x437e60, ['I32', 'I32'], 'void'),
    (0x439100, ['I32'], 'void'),
    (0x4391f0, ['I32', 'I32', 'I32', 'I32'], 'void'),
    (0x439a30, ['I32', 'I32', 'I32'], 'void'),
    (0x439df0, ['I32'], 'void'),
    (0x439ec0, ['I32', 'I32', 'I32'], 'I64'),
    (0x43ec20, ['F64', 'F64', 'I32', 'I32'], 'float10'),
    (0x464050, ['I32', 'I32'], 'I64'),
    (0x488d70, ['I32', 'I32', 'I32'], 'I32'),
]
record = {'source_sha256': EXPECTED,
    'scope': 'Decompiler metadata only. Original cdecl entry/caller stack operands, RET cleanup, ST0/EDX:EAX returns and integer fleet indexing independently reviewed; original instructions unchanged.',
    'changes': []}
st0 = VariableStorage(currentProgram, currentProgram.getRegister('ST0').getAddress(), 10)
eax = VariableStorage(currentProgram, currentProgram.getRegister('EAX').getAddress(), 4)
for address, kinds, returned in contracts:
    function = currentProgram.getFunctionManager().getFunctionAt(toAddr(address))
    if function is None:
        raise ValueError('Missing original tactical function ' + hex(address))
    before = str(function.getSignature())
    parameters = ArrayList()
    offset = 4
    for index, kind in enumerate(kinds):
        data_type = DoubleDataType.dataType if kind == 'F64' else IntegerDataType.dataType
        parameters.add(ParameterImpl('param_%d' % (index + 1), data_type, offset, currentProgram))
        offset += data_type.getLength()
    if returned == 'float10':
        result = ReturnParameterImpl(Float10DataType.dataType, st0, currentProgram)
    elif returned == 'void':
        result = ReturnParameterImpl(VoidDataType.dataType, currentProgram)
    elif returned == 'I64':
        # Let the Windows x86 compiler specification allocate the joined pair,
        # then preserve that exact EDX:EAX allocation under CUSTOM_STORAGE.
        function.updateFunction('__cdecl', ReturnParameterImpl(LongLongDataType.dataType, currentProgram), ArrayList(),
            Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, True, SourceType.USER_DEFINED)
        result = ReturnParameterImpl(function.getReturn(), currentProgram)
        if str(result.getVariableStorage()) != 'EDX:4,EAX:4':
            raise ValueError('Unexpected original signed64 return allocation')
    else:
        result = ReturnParameterImpl(IntegerDataType.dataType, eax, currentProgram)
    function.updateFunction('__cdecl', result, parameters,
        Function.FunctionUpdateType.CUSTOM_STORAGE, True, SourceType.USER_DEFINED)
    function.setStackPurgeSize(0)
    record['changes'].append({'address': '%08x' % address, 'before': before,
        'after': str(function.getSignature()), 'argumentTypes': kinds, 'returnType': returned,
        'argumentStorage': [str(parameter.getVariableStorage()) for parameter in function.getParameters()],
        'returnStorage': str(function.getReturn().getVariableStorage())})
with codecs.open(os.path.join(destination, 'ai-signatures.json'), 'w', 'utf-8') as stream:
    stream.write(json.dumps(record, indent=2, sort_keys=True) + u'\n')
println('2010_AI_SIGNATURES_CORRECTED_17')
