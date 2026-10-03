# Correct inferred numeric function signatures without changing executable bytes.
#@category Tact.Preservation
#@runtime Jython

import codecs
import json
import os

from java.util import ArrayList
from ghidra.app.decompiler import DecompInterface
from ghidra.program.database import SpecExtension
from ghidra.program.model.data import DoubleDataType, Float10DataType, IntegerDataType, VoidDataType
from ghidra.program.model.listing import Function, ParameterImpl, ReturnParameterImpl, VariableStorage
from ghidra.program.model.symbol import SourceType


def function_at(address):
    function = currentProgram.getFunctionManager().getFunctionAt(toAddr(address))
    if function is None:
        raise ValueError("No function at " + address)
    return function


def snapshot(function):
    return {"address": str(function.getEntryPoint()), "name": str(function.getName()),
            "signature": str(function.getSignature()), "return_type": str(function.getReturnType()),
            "return_storage": str(function.getReturn().getVariableStorage()),
            "custom_storage": bool(function.hasCustomVariableStorage()),
            "calling_convention": str(function.getCallingConventionName()),
            "call_fixup": str(function.getCallFixup()) if function.getCallFixup() is not None else None,
            "parameters": [{"name": str(parameter.getName()), "type": str(parameter.getDataType()),
                            "storage": str(parameter.getVariableStorage())} for parameter in function.getParameters()]}


args = getScriptArgs()
if len(args) != 1:
    raise ValueError("Output directory required")
destination = str(args[0])
previous_path = os.path.join(destination, "signature-corrections.json")
previous_changes = {}
previous_records = []
if os.path.isfile(previous_path):
    with codecs.open(previous_path, "r", "utf-8") as stream:
        previous = json.load(stream)
        previous_records = previous.get("changes", [])
        previous_changes = {change["before"]["address"]: change["before"] for change in previous.get("changes", [])}


def original_snapshot(function):
    return previous_changes.get(str(function.getEntryPoint()), snapshot(function))


record = {"source_sha256": str(currentProgram.getExecutableSHA256()),
          "scope": "Analyst-supplied decompiler signatures inferred from original x87 instructions and callers; not original source declarations.",
          "changes": [], "registers": {}}
for register_name in ["ST0", "EAX", "EDX"]:
    register = currentProgram.getRegister(register_name)
    if register is None:
        raise ValueError("Register not found: " + register_name)
    record["registers"][register_name] = {"address": str(register.getAddress()),
                                        "bytes": register.getMinimumByteSize()}

# __ftol consumes the 80-bit x87 stack-top value. Its integer return storage is
# already inferred correctly, so retain that storage rather than guess its order.
ftol = function_at("004570b0")
before = original_snapshot(ftol)
parameters = ArrayList()
st0 = currentProgram.getRegister("ST0")
input_storage = VariableStorage(currentProgram, st0.getAddress(), 10)
parameters.add(ParameterImpl("x87_value", Float10DataType.dataType, input_storage, currentProgram))
return_parameter = ReturnParameterImpl(ftol.getReturn(), currentProgram)
ftol.updateFunction(ftol.getCallingConventionName(), return_parameter, parameters,
                    Function.FunctionUpdateType.CUSTOM_STORAGE, True, SourceType.USER_DEFINED)

# A formal ST0 parameter restores caller expressions, but the generic compiler
# convention still treats ST0/ST1 as clobbered. This program-specific callfixup
# represents the original helper's integer conversion AND its one-element x87
# stack pop. The physical helper sets rounding-control to truncate then restores
# it. Ghidra's generic FISTP semantics use round() without consulting that control
# word; directly using trunc() here corrects that modeling limitation for calls.
fixup_xml = """<callfixup name="tact_ftol_x87_pop">
  <pcode>
    <body><![CDATA[
      local converted:8 = trunc(ST0);
      EAX = converted[0,32];
      EDX = converted[32,32];
      ST0 = ST1;
      ST1 = ST2;
      ST2 = ST3;
      ST3 = ST4;
      ST4 = ST5;
      ST5 = ST6;
      ST6 = ST7;
      ESP = ESP + 4;
    ]]></body>
  </pcode>
</callfixup>"""
SpecExtension(currentProgram).addReplaceCompilerSpecExtension(fixup_xml, monitor)
ftol.setCallFixup("tact_ftol_x87_pop")
record["callfixup"] = {"name": "tact_ftol_x87_pop", "xml": fixup_xml,
    "reason": "Model truncate-to-signed-64-bit plus x87 stack pop; preserve the pressure result below the consumed ST0.",
    "limitations": "This models dataflow for finite representable numeric inputs. x87 exception flags, masked invalid conversions and hardware traps require separate reference testing; do not infer them from this simplified p-code."}
with codecs.open(os.path.join(destination, "ftol-callfixup.xml"), "w", "utf-8") as stream:
    stream.write(fixup_xml + u"\n")
record["changes"].append({"before": before, "after": snapshot(ftol),
    "reason": "Runtime body reads ST0, converts with FISTP under truncation rounding, and returns signed 64-bit integer in EDX:EAX; former no-argument prototype discarded caller arithmetic."})

for address, return_type, parameter_types, reason in [
    ("00429df0", DoubleDataType.dataType, [IntegerDataType.dataType, IntegerDataType.dataType],
     "Apparent-wind helper leaves a floating result in ST0 which its caller consumes; void inference omitted the magnitude calculation and return."),
    ("00413cd0", DoubleDataType.dataType, [DoubleDataType.dataType],
     "Angle-normalization helper accepts an IEEE double on the stack and returns an x87 floating value in ST0; lock its floating return for callers."),
    ("0041bb10", IntegerDataType.dataType, [IntegerDataType.dataType, IntegerDataType.dataType],
     "Bearing helper converts the x87 atan2 angle to degrees, calls integer angle wrapping at 00413cb0, then returns its EAX result; former void inference hid that return."),
    ("00420b70", Float10DataType.dataType, [IntegerDataType.dataType] * 3,
     "Shoreline metric returns its unrounded x87 ST0 scalar; optional FST qword cachedMetric does not pop or round the remaining ST0 value consumed by caller __ftol."),
    ("00420c40", Float10DataType.dataType, [IntegerDataType.dataType] * 3,
     "Elliptical metric returns an unrounded x87 ST0 scalar; original x-axis FST qword spill followed by FMUL rounded memory must not erase the preserved extended return."),
    ("00420d10", Float10DataType.dataType, [IntegerDataType.dataType] * 3,
     "Radial metric returns unrounded x87 ST0 and conditionally FST qword cachedMetric without a pop; __ftol caller requires the original extended scalar."),
    ("00428ab0", Float10DataType.dataType, [IntegerDataType.dataType, DoubleDataType.dataType, DoubleDataType.dataType],
     "Distance-to-boat accepts one int followed by two packed stack doubles and returns unrounded x87 sqrt in ST0; full m80 return verified against original native instructions."),
    ("00426f50", Float10DataType.dataType, [IntegerDataType.dataType],
     "Signed-start-distance returns stored binary64 position sqrt minus an unrounded reference sqrt in ST0; original native m80 returns confirm extended result."),
    ("00412f60", VoidDataType.dataType, [DoubleDataType.dataType] * 2,
     "Curved-hull original stack contract is two packed doubles, not four integers; routine writes geometry and callers do not consume a return. Full native geometry verified."),
    ("00413100", VoidDataType.dataType, [DoubleDataType.dataType] * 2,
     "Flat-hull original stack contract is two packed doubles with no observed API return; full native geometry verified."),
    ("004139d0", Float10DataType.dataType, [IntegerDataType.dataType],
     "Crew selector returns the original unrounded x87 scale in ST0; finite original native m80 returns verified."),
    ("00413a20", VoidDataType.dataType, [DoubleDataType.dataType] * 4 + [IntegerDataType.dataType] * 5,
     "Crew geometry writer takes four packed doubles then five ints; verified caller words and original native full-state fixtures establish this stack layout."),
    ("00413370", VoidDataType.dataType, [DoubleDataType.dataType, IntegerDataType.dataType, IntegerDataType.dataType],
     "Full crew geometry takes width double followed by boat/screenY ints; original native full-state fixtures verify the contract."),
    ("00414010", VoidDataType.dataType, [DoubleDataType.dataType] + [IntegerDataType.dataType] * 4 + [DoubleDataType.dataType],
     "Sail geometry takes height double, boat/index/curvature/view-heading ints, then width-scale double; full unchanged native calls verify exact output stores.")]:
    function = function_at(address)
    before = original_snapshot(function)
    parameters = ArrayList()
    extended_return = return_type == Float10DataType.dataType
    stack_offset = 4
    for index, data_type in enumerate(parameter_types):
        if extended_return or address in ["00412f60", "00413100", "00413a20", "00413370", "00414010"]:
            parameters.add(ParameterImpl("param_%d" % (index + 1), data_type, stack_offset, currentProgram))
            stack_offset += data_type.getLength()
        else:
            parameters.add(ParameterImpl("param_%d" % (index + 1), data_type, currentProgram))
    # The generic Windows cdecl model treats float10 as an indirectly returned
    # structure and inserts a hidden pointer. Original instructions instead
    # return ST0 directly and take exactly three stack ints at +4/+8/+12.
    return_parameter = ReturnParameterImpl(return_type, input_storage, currentProgram) if extended_return else ReturnParameterImpl(return_type, currentProgram)
    explicit_storage = extended_return or address in ["00412f60", "00413100", "00413a20", "00413370", "00414010"]
    update_type = Function.FunctionUpdateType.CUSTOM_STORAGE if explicit_storage else Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS
    function.updateFunction("__cdecl", return_parameter, parameters, update_type, True, SourceType.USER_DEFINED)
    if extended_return:
        if str(function.getReturn().getVariableStorage()) != "ST0:10" or function.getParameterCount() != len(parameter_types):
            raise RuntimeError("Incorrect original extended-return ABI at " + address)
    record["changes"].append({"before": before, "after": snapshot(function), "reason": reason})

# Keep unrelated earlier correction records when this script is expanded later.
handled = {change["before"]["address"] for change in record["changes"]}
record["changes"].extend(change for change in previous_records if change["before"]["address"] not in handled)

# Record the original instructions next to the correction and immediately
# decompile the affected callers so semantic restoration can be inspected.
decompiler = DecompInterface()
decompiler.toggleCCode(True)
if not decompiler.openProgram(currentProgram):
    raise RuntimeError(str(decompiler.getLastMessage()))
affected = os.path.join(destination, "numeric-corrections")
if not os.path.isdir(affected):
    os.makedirs(affected)
record["preview_results"] = []
try:
    for address in ["004570b0", "00429df0", "00413cd0", "00428c60", "0041bb10", "00420b70", "00420c40", "00420d10", "00421560"]:
        function = function_at(address)
        with codecs.open(os.path.join(affected, address + ".asm"), "w", "utf-8") as stream:
            instructions = currentProgram.getListing().getInstructions(function.getBody(), True)
            while instructions.hasNext():
                instruction = instructions.next()
                stream.write(unicode(str(instruction.getAddress()) + " " + str(instruction) + "\n"))
        result = decompiler.decompileFunction(function, 60, monitor)
        success = bool(result.decompileCompleted() and result.getDecompiledFunction() is not None)
        record["preview_results"].append({"address": address, "decompiled": success,
                                         "message": str(result.getErrorMessage() or "")})
        if not success:
            raise RuntimeError("Failed to preview " + address + ": " + str(result.getErrorMessage()))
        with codecs.open(os.path.join(affected, address + ".c"), "w", "utf-8") as stream:
            stream.write(unicode(result.getDecompiledFunction().getC()))
finally:
    decompiler.dispose()
with codecs.open(os.path.join(destination, "signature-corrections.json"), "w", "utf-8") as stream:
    stream.write(json.dumps(record, indent=2, sort_keys=True) + u"\n")
println("NUMERIC_SIGNATURES_CORRECTED " + json.dumps(record, sort_keys=True))
