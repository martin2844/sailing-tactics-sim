# Measure the analyzed instruction/function coverage of executable memory.
#@category Tact.Preservation
#@runtime Jython

import codecs
import json
import os

from ghidra.program.model.address import AddressSet


def ranges(addresses):
    result = []
    iterator = addresses.getAddressRanges()
    while iterator.hasNext():
        extent = iterator.next()
        result.append({"start": str(extent.getMinAddress()), "end": str(extent.getMaxAddress()),
                       "bytes": long(extent.getLength())})
    return result


args = getScriptArgs()
if len(args) != 2:
    raise ValueError("Decompiled directory and coverage JSON output required")
output_directory, metadata_path = str(args[0]), str(args[1])
listing = currentProgram.getListing()
manager = currentProgram.getFunctionManager()
report = {"source_sha256": str(currentProgram.getExecutableSHA256()),
          "scope": "Coverage of Ghidra's current analysis, not a proof of intended instruction boundaries, reachability, or original semantics.",
          "blocks": []}
with codecs.open(os.path.join(output_directory, "unassigned-instructions.asm"), "w", "utf-8") as unassigned:
    unassigned.write(u"; Analyzed instructions outside every recovered function body. Padding and unreachable code may be included.\n")
    for block in currentProgram.getMemory().getBlocks():
        if not block.isExecute():
            continue
        memory_region = AddressSet(block.getStart(), block.getEnd())
        instruction_region, data_region, function_region = AddressSet(), AddressSet(), AddressSet()
        instruction_count, unassigned_count, function_count, data_count = 0, 0, 0, 0
        iterator = manager.getFunctions(True)
        while iterator.hasNext():
            function = iterator.next()
            intersection = function.getBody().intersect(memory_region)
            if not intersection.isEmpty():
                function_count += 1
                function_region.add(intersection)
        iterator = listing.getInstructions(memory_region, True)
        while iterator.hasNext():
            instruction = iterator.next()
            instruction_count += 1
            instruction_region.add(instruction.getMinAddress(), instruction.getMaxAddress())
            if manager.getFunctionContaining(instruction.getAddress()) is None:
                unassigned_count += 1
                payload = " ".join("%02x" % (value & 255) for value in instruction.getBytes())
                unassigned.write(unicode("%s  %-24s  %s\n" % (instruction.getAddress(), payload, instruction)))
        iterator = listing.getDefinedData(memory_region, True)
        while iterator.hasNext():
            data = iterator.next()
            data_count += 1
            data_region.add(data.getMinAddress(), data.getMaxAddress())
        undefined = listing.getUndefinedRanges(memory_region, True, monitor)
        unassigned_region = instruction_region.subtract(function_region)
        undefined_ranges = ranges(undefined)
        fill_only_bytes, fill_only_range_count = 0, 0
        for extent in undefined_ranges:
            payload = getBytes(toAddr(extent["start"]), int(extent["bytes"]))
            counts = {}
            for byte in payload:
                byte = byte & 255
                counts[byte] = counts.get(byte, 0) + 1
            extent["common_bytes"] = [{"hex": "%02x" % byte, "count": count}
                                      for byte, count in sorted(counts.items(), key=lambda item: (-item[1], item[0]))[:8]]
            extent['all_bytes_are_00_90_or_cc'] = all(byte in (0, 0x90, 0xcc) for byte in counts)
            if extent['all_bytes_are_00_90_or_cc']:
                fill_only_bytes += extent['bytes']
                fill_only_range_count += 1
        entry = {"name": str(block.getName()), "start": str(block.getStart()), "end": str(block.getEnd()),
                 "memory_bytes": long(block.getSize()), "initialized": bool(block.isInitialized()),
                 "function_count": function_count, "function_body_bytes": long(function_region.getNumAddresses()),
                 "instruction_count": instruction_count, "instruction_bytes": long(instruction_region.getNumAddresses()),
                 "instruction_bytes_inside_functions": long(instruction_region.intersect(function_region).getNumAddresses()),
                 "unassigned_instruction_count": unassigned_count,
                 "unassigned_instruction_bytes": long(unassigned_region.getNumAddresses()),
                 "unassigned_instruction_ranges": ranges(unassigned_region),
                 "defined_data_count": data_count, "defined_data_bytes": long(data_region.getNumAddresses()),
                 "undefined_bytes": long(undefined.getNumAddresses()), "undefined_ranges": undefined_ranges,
                 "undefined_fill_only_range_bytes": fill_only_bytes, "undefined_fill_only_range_count": fill_only_range_count,
                 "undefined_other_range_bytes": long(undefined.getNumAddresses())-fill_only_bytes,
                 "function_body_coverage_fraction": float(function_region.getNumAddresses()) / block.getSize(),
                 "instruction_coverage_fraction": float(instruction_region.getNumAddresses()) / block.getSize()}
        report["blocks"].append(entry)
report["totals"] = {key: sum(block[key] for block in report["blocks"]) for key in
    ["memory_bytes", "function_count", "function_body_bytes", "instruction_count", "instruction_bytes",
     "instruction_bytes_inside_functions", "unassigned_instruction_count", "unassigned_instruction_bytes",
     "defined_data_count", "defined_data_bytes", "undefined_bytes"]}
with codecs.open(metadata_path, "w", "utf-8") as stream:
    stream.write(json.dumps(report, indent=2, sort_keys=True) + u"\n")
println("COVERAGE_AUDIT " + json.dumps(report["totals"], sort_keys=True))
