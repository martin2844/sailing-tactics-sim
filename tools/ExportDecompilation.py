# Export every function recovered by Ghidra, with explicit completeness metadata.
#@category Tact.Preservation
#@runtime Jython
# Jython 2.7 script executed inside Ghidra's headless analyzer.

import codecs
import hashlib
import json
import os
import time

from ghidra.app.decompiler import DecompInterface
from ghidra.framework import Application
from java.lang import Exception as JavaException


def write_json_line(stream, value):
    stream.write(json.dumps(value, ensure_ascii=True, sort_keys=True) + u"\n")


args = getScriptArgs()
if len(args) != 1:
    raise ValueError("Output directory required")
destination = str(args[0])
functions_dir = os.path.join(destination, "functions")
if not os.path.isdir(functions_dir):
    os.makedirs(functions_dir)

manager = currentProgram.getFunctionManager()
expected = []
iterator = manager.getFunctions(True)
while iterator.hasNext():
    function = iterator.next()
    if not function.isExternal():
        expected.append(function)
externals = []
iterator = manager.getExternalFunctions()
while iterator.hasNext():
    function = iterator.next()
    externals.append({"address": str(function.getEntryPoint()),
                      "name": str(function.getName(True)),
                      "signature": str(function.getSignature())})
with codecs.open(os.path.join(destination, "external-functions.json"), "w", "utf-8") as stream:
    stream.write(json.dumps(externals, indent=2, ensure_ascii=True, sort_keys=True) + u"\n")

decompiler = DecompInterface()
decompiler.toggleCCode(True)
decompiler.toggleSyntaxTree(True)
if not decompiler.openProgram(currentProgram):
    raise RuntimeError(str(decompiler.getLastMessage()))

started = time.time()
complete, failed, total, defined_data_count = 0, 0, 0, 0
failures = []
try:
    with codecs.open(os.path.join(destination, "recovered.c"), "w", "utf-8") as combined:
        with codecs.open(os.path.join(destination, "functions.jsonl"), "w", "utf-8") as index:
            combined.write(u"/* Mechanically decompiled from %s. Inferred types/names; not original source. */\n\n" % unicode(currentProgram.getName()))
            if os.path.isfile(os.path.join(destination, "signature-corrections.json")):
                combined.write(u"/* Analyst-supplied numeric signatures and callfixup: see signature-corrections.json and ftol-callfixup.xml. */\n\n")
            for function in expected:
                if monitor.isCancelled():
                    break
                total += 1
                address = str(function.getEntryPoint())
                name = str(function.getName())
                monitor.setMessage("Decompiling " + address + " " + name)
                try:
                    result = decompiler.decompileFunction(function, 60, monitor)
                    success = bool(result.decompileCompleted() and result.getDecompiledFunction() is not None)
                    error = str(result.getErrorMessage() or "")
                except (Exception, JavaException) as exception:
                    result, success, error = None, False, str(exception)
                if success:
                    c_code = unicode(result.getDecompiledFunction().getC())
                    complete += 1
                else:
                    c_code = u"/* %s decompilation failed: %s */\n" % (address, error.replace("*/", "* /"))
                    failed += 1
                    failures.append({"address": address, "name": name, "error": error})
                filename = address + ".c"
                with codecs.open(os.path.join(functions_dir, filename), "w", "utf-8") as stream:
                    stream.write(c_code)
                combined.write(u"/* Address: %s; symbol: %s */\n%s\n\n" % (address, name, c_code))
                calls = sorted([{"address": str(called.getEntryPoint()), "name": str(called.getName())}
                                for called in function.getCalledFunctions(monitor)], key=lambda item: item["address"])
                body_ranges = []
                ranges = function.getBody().getAddressRanges()
                while ranges.hasNext():
                    extent = ranges.next()
                    body_ranges.append({"start": str(extent.getMinAddress()), "end": str(extent.getMaxAddress())})
                write_json_line(index, {"address": address, "name": name,
                    "signature": str(function.getSignature()), "body_bytes": long(function.getBody().getNumAddresses()),
                    "body_ranges": body_ranges, "decompiled": success, "error": error, "calls": calls,
                    "file": "functions/" + filename, "c_sha256": hashlib.sha256(c_code.encode("utf-8")).hexdigest()})
                if total % 100 == 0:
                    combined.flush()
                    index.flush()
                    println("EXPORT_PROGRESS functions=%d complete=%d failed=%d" % (total, complete, failed))
    with codecs.open(os.path.join(destination, "defined-data.jsonl"), "w", "utf-8") as globals_index:
        iterator = currentProgram.getListing().getDefinedData(True)
        while iterator.hasNext() and not monitor.isCancelled():
            data = iterator.next()
            defined_data_count += 1
            write_json_line(globals_index, {"address": str(data.getAddress()), "type": str(data.getDataType().getName()),
                            "size": data.getLength(), "label": str(data.getLabel()) if data.getLabel() is not None else None,
                            "value": unicode(data.getValue())})
finally:
    decompiler.dispose()

summary = {"program": str(currentProgram.getName()), "image_base": str(currentProgram.getImageBase()),
           "language": str(currentProgram.getLanguageID()), "ghidra_version": str(Application.getApplicationVersion()),
           "source_sha256": str(currentProgram.getExecutableSHA256()), "expected_functions": len(expected),
           "functions": total, "decompiled": complete, "failed": failed, "failures": failures,
           "external_functions": len(externals), "defined_data": defined_data_count,
           "cancelled": bool(monitor.isCancelled()), "elapsed_seconds": time.time() - started,
           "export_complete": total == len(expected) and failed == 0 and not monitor.isCancelled(),
           "scope": "Functions recovered by Ghidra analysis; undiscovered code and inferred semantics still require review."}
corrections_path = os.path.join(destination, "signature-corrections.json")
if os.path.isfile(corrections_path):
    with open(corrections_path, "rb") as stream:
        corrections_data = stream.read()
    summary["signature_corrections"] = {"file": "signature-corrections.json", "sha256": hashlib.sha256(corrections_data).hexdigest()}
for name in ['function-recovery.json', 'catch-continuation-repairs.json', 'decompilation-coverage.json']:
    provenance_path = os.path.join(destination, '..', 'analysis', name)
    if os.path.isfile(provenance_path):
        with open(provenance_path, 'rb') as stream:
            provenance_data = stream.read()
        summary.setdefault('recovery_evidence', []).append({'file': '../analysis/'+name, 'sha256': hashlib.sha256(provenance_data).hexdigest()})
with codecs.open(os.path.join(destination, "summary.json"), "w", "utf-8") as stream:
    stream.write(json.dumps(summary, indent=2, ensure_ascii=True, sort_keys=True) + u"\n")
println("EXPORT_COMPLETE " + json.dumps(summary, ensure_ascii=True, sort_keys=True))
if not summary["export_complete"]:
    raise RuntimeError("Decompilation export was incomplete; inspect summary.json")
