# Export Ghidra references to the exact text addresses being localized.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json

args = getScriptArgs()
if len(args) != 2:
    raise ValueError("Translation map and output path required")
with codecs.open(str(args[0]), "r", "utf-8") as stream:
    translations = json.load(stream)
if str(currentProgram.getExecutableSHA256()) != translations["source_sha256"]:
    raise ValueError("Wrong program for translation map")
result = []
listing = currentProgram.getListing()
manager = currentProgram.getReferenceManager()
for item in translations["embedded"]:
    address = toAddr(long(item["va"]))
    refs = []
    for ref in manager.getReferencesTo(address):
        source = ref.getFromAddress()
        instruction = listing.getInstructionAt(source)
        entry = {"from_va": long(source.getOffset()), "operand_index": ref.getOperandIndex(),
                 "reference_type": str(ref.getReferenceType())}
        if instruction is not None:
            entry["instruction_hex"] = "".join(chr(b & 255) for b in instruction.getBytes()).encode("hex")
            entry["instruction"] = unicode(str(instruction))
        refs.append(entry)
    result.append({"va": long(item["va"]), "references": refs})
with codecs.open(str(args[1]), "w", "utf-8") as stream:
    stream.write(json.dumps({"source_sha256": translations["source_sha256"], "strings": result}, ensure_ascii=True, indent=2) + u"\n")
println("EXPORTED_TEXT_REFERENCES strings=%d references=%d" % (len(result), sum(len(x["references"]) for x in result)))
