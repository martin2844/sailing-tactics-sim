# Restore original CString concatenation and game-formatting stack contracts.
# Analyst metadata only; no executable bytes are changed.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
from java.util import ArrayList
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.data import CharDataType, DoubleDataType, IntegerDataType, PointerDataType, StructureDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.symbol import SourceType

args = getScriptArgs()
if len(args) != 1:
    raise ValueError('Output directory required')
destination = str(args[0])
if not os.path.isdir(destination):
    os.makedirs(destination)
manager = currentProgram.getFunctionManager()
char_pointer = PointerDataType(CharDataType.dataType, currentProgram.getDataTypeManager())
cstring = StructureDataType('TactCString', 0)
cstring.add(char_pointer, 4, 'data', 'Original CString object stores one ANSI data pointer.')
cstring_pointer = PointerDataType(cstring, currentProgram.getDataTypeManager())
eax = currentProgram.getRegister('EAX')
return_storage = VariableStorage(currentProgram, eax.getAddress(), 4)
record = {'source_sha256': str(currentProgram.getExecutableSHA256()),
          'scope': 'Analyst signatures from original stack accesses/callers; CString layout is opaque except its four-byte data pointer. No original source declaration or executable patch.',
          'changes': [], 'previews': []}

def snapshot(function):
    return {'address': str(function.getEntryPoint()), 'signature': str(function.getSignature()),
            'customStorage': bool(function.hasCustomVariableStorage()),
            'returnStorage': str(function.getReturn().getVariableStorage()),
            'parameters': [{'name': str(parameter.getName()), 'type': str(parameter.getDataType()),
                            'storage': str(parameter.getVariableStorage())} for parameter in function.getParameters()]}

specifications = [
    ('0046c0db', [cstring_pointer, cstring_pointer, char_pointer],
     'Original concat reads out*, CString* left, ANSI right at entry stack +4/+8/+12 and returns out* in EAX.'),
    ('0046c075', [cstring_pointer, cstring_pointer, cstring_pointer],
     'Original concat reads out*, CString* left, CString* right at entry stack +4/+8/+12 and returns out* in EAX.'),
    ('0046c14f', [cstring_pointer, char_pointer, cstring_pointer],
     'Original concat reads out*, ANSI left, CString* right at entry stack +4/+8/+12 and returns out* in EAX.'),
    ('00413d00', [cstring_pointer, IntegerDataType.dataType],
     'Game decimal integer formatter receives out* and signed I32; original _itoa base ten supplies the string and out* is returned in EAX.'),
    ('00413d90', [cstring_pointer, DoubleDataType.dataType],
     'Game fractional formatter receives out* at entry +4 and unaligned IEEE F64 at +8; original x87 truncation/concatenation formats the value, then returns out* in EAX.'),
]
for address, kinds, reason in specifications:
    function = manager.getFunctionAt(toAddr(address))
    if function is None:
        raise ValueError('Missing original function ' + address)
    before = snapshot(function)
    parameters = ArrayList()
    offset = 4
    for index, data_type in enumerate(kinds):
        parameters.add(ParameterImpl('param_%d' % (index + 1), data_type, offset, currentProgram))
        offset += data_type.getLength()
    convention = '__stdcall' if address.startswith('0046') else '__cdecl'
    function.updateFunction(convention, ReturnParameterImpl(cstring_pointer, return_storage, currentProgram),
                            parameters, Function.FunctionUpdateType.CUSTOM_STORAGE, True, SourceType.USER_DEFINED)
    function.setStackPurgeSize(offset - 4 if convention == '__stdcall' else 0)
    if function.getParameterCount() != len(kinds) or str(function.getReturn().getVariableStorage()) != 'EAX:4':
        raise RuntimeError('Incorrect original CString ABI at ' + address)
    if address == '00413d90' and str(function.getParameter(1).getVariableStorage()) != 'Stack[0x8]:8':
        raise RuntimeError('Game formatter double must remain at original unaligned stack +8')
    record['changes'].append({'before': before, 'after': snapshot(function), 'reason': reason})

decompiler = DecompInterface()
decompiler.toggleCCode(True)
if not decompiler.openProgram(currentProgram):
    raise RuntimeError(str(decompiler.getLastMessage()))
try:
    # Drawing signatures must already have been installed in this same session.
    for address in ['00413d00', '00413d90', '00409760', '0040db30', '0040c3b0', '0040e9a0']:
        function = manager.getFunctionAt(toAddr(address))
        result = decompiler.decompileFunction(function, 60, monitor)
        if not result.decompileCompleted() or result.getDecompiledFunction() is None:
            raise RuntimeError('CString preview failed at ' + address + ': ' + str(result.getErrorMessage()))
        with codecs.open(os.path.join(destination, address + '.c'), 'w', 'utf-8') as output:
            output.write(unicode(result.getDecompiledFunction().getC()))
        record['previews'].append({'address': address, 'decompiled': True})
finally:
    decompiler.dispose()
with codecs.open(os.path.join(destination, 'cstring-signatures.json'), 'w', 'utf-8') as output:
    output.write(json.dumps(record, indent=2, sort_keys=True) + u'\n')
println('CSTRING_SIGNATURES_CORRECTED ' + str(len(record['changes'])) + ' original stack contracts')
