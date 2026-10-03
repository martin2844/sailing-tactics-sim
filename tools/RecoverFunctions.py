# Recover functions supported by original call targets, code pointers, or leaf boundaries.
#@category Tact.Preservation
#@runtime Jython

import codecs
import json
import os

from ghidra.program.model.address import Address
from ghidra.app.cmd.data.exceptionhandling import EHFunctionInfoModel
from ghidra.app.util.datatype.microsoft import DataValidationOptions
from ghidra.app.util.opinion.PeLoader.CompilerOpinion import CompilerEnum
from java.lang import Exception as JavaException


args = getScriptArgs()
if len(args) not in (2, 3):
    raise ValueError("Validated MFC candidates JSON, recovery report output, and optional CRuntimeClass JSON required")
candidate_path, report_path = str(args[0]), str(args[1])
memory = currentProgram.getMemory()
listing = currentProgram.getListing()
manager = currentProgram.getFunctionManager()
initial_addresses = set(str(function.getEntryPoint()) for function in manager.getFunctions(True))
report = {"source_sha256": str(currentProgram.getExecutableSHA256()),
          "scope": "Function discovery supported by original code/data references; executable bytes unchanged. Remaining unknown bytes are preserved.",
          "initial_functions": len(initial_addresses), "created": [], "rejected": [], "passes": []}
attempted = set()
previous_report = None
if os.path.isfile(report_path):
    with codecs.open(report_path, "r", "utf-8") as stream:
        previous_report = json.load(stream)
    if previous_report.get("source_sha256") != report["source_sha256"]:
        raise ValueError("Previous recovery evidence refers to another executable")
    # A fresh imported project must rebuild the evidence, not duplicate rows
    # from the prior project whose functions are not present yet.
    if all(entry['address'] in initial_addresses for entry in previous_report.get('created', [])):
        report["run_initial_functions"] = len(initial_addresses)
        report["initial_functions"] = previous_report["initial_functions"]
        report["created"] = previous_report.get("created", [])
        report["rejected"] = previous_report.get("rejected", [])
        report["passes"] = previous_report.get("passes", [])
    else:
        previous_report = None


def checkpoint():
    with codecs.open(report_path, "w", "utf-8") as stream:
        stream.write(json.dumps(report, indent=2, sort_keys=True) + u"\n")


def executable(address):
    block = memory.getBlock(address)
    return block is not None and block.isExecute() and block.isInitialized()


def original_bytes(address, length):
    return " ".join("%02x" % (value & 255) for value in getBytes(address, length))


def evidence_address(evidence):
    return str(evidence["target"])


def attempt(address, evidence):
    key = str(address)
    if key in attempted or manager.getFunctionContaining(address) is not None:
        return False
    attempted.add(key)
    issue = None
    if not executable(address):
        issue = "target_is_not_initialized_executable_memory"
    else:
        instruction = listing.getInstructionContaining(address)
        if instruction is not None and instruction.getAddress() != address:
            issue = "target_is_inside_an_existing_instruction"
        data = listing.getDefinedDataContaining(address)
        if data is not None:
            issue = "target_is_defined_data_not_code"
    if issue is None:
        if listing.getInstructionAt(address) is None and not disassemble(address):
            issue = "disassembly_failed"
        if listing.getInstructionAt(address) is None:
            issue = "no_instruction_at_supported_target"
    if issue is not None:
        report["rejected"].append({"address": key, "reason": issue, "evidence": evidence})
        return False
    function = createFunction(address, None)
    if function is None:
        report["rejected"].append({"address": key, "reason": "createFunction_returned_null", "evidence": evidence})
        return False
    # A valid MFC map target is a member-function pointer dispatched with this in
    # ECX. Keep return/argument types for analysis rather than inventing them.
    if evidence["kind"] == "validated_mfc_message_map":
        function.setCallingConvention("__thiscall")
    ranges = []
    iterator = function.getBody().getAddressRanges()
    while iterator.hasNext():
        extent = iterator.next()
        ranges.append({"start": str(extent.getMinAddress()), "end": str(extent.getMaxAddress())})
    report["created"].append({"address": key, "name": str(function.getName()),
                              "initial_body_bytes": long(function.getBody().getNumAddresses()),
                              "initial_body_ranges": ranges, "evidence": evidence})
    if len(report["created"]) % 50 == 0:
        println("RECOVERY_PROGRESS new_functions=%d last=%s" % (len(report["created"]), key))
    return True


def call_candidates():
    result = []
    iterator = listing.getInstructions(True)
    while iterator.hasNext():
        instruction = iterator.next()
        flow = instruction.getFlowType()
        if not flow.isCall() or flow.isComputed():
            continue
        for target in instruction.getFlows():
            if executable(target) and manager.getFunctionContaining(target) is None:
                result.append((target, {"kind": "original_direct_call_target", "target": str(target),
                    "source": str(instruction.getAddress()), "instruction": str(instruction),
                    "instruction_bytes": original_bytes(instruction.getAddress(), instruction.getLength())}))
    return result


def pointer_candidates():
    result = []

    def inspect(data, depth=0):
        if data.isPointer():
            value = data.getValue()
            if isinstance(value, Address) and executable(value) and manager.getFunctionContaining(value) is None:
                result.append((value, {"kind": "defined_code_pointer", "target": str(value),
                    "source": str(data.getAddress()), "data_type": str(data.getDataType().getName()),
                    "pointer_bytes": original_bytes(data.getAddress(), data.getLength())}))
            return
        if depth < 8 and data.getNumComponents() > 0:
            for index in range(data.getNumComponents()):
                component = data.getComponent(index)
                if component is not None:
                    inspect(component, depth + 1)
    iterator = listing.getDefinedData(True)
    while iterator.hasNext():
        inspect(iterator.next())
    return result


def immediate_code_pointer_candidates():
    """Original PUSH/MOV scalar operands pointing at already-decoded orphan code."""
    result = []
    iterator = listing.getInstructions(True)
    while iterator.hasNext():
        instruction = iterator.next()
        if instruction.getMnemonicString() not in ("PUSH", "MOV"):
            continue
        for reference in instruction.getReferencesFrom():
            target = reference.getToAddress()
            operand = reference.getOperandIndex()
            if not reference.getReferenceType().isData() or operand < 0:
                continue
            # Require an immediate scalar rather than a read/write of memory
            # residing in .text. Never manufacture starts from a numeric scan.
            rendered = str(instruction.getDefaultOperandRepresentation(operand))
            scalar = instruction.getScalar(operand)
            if "[" in rendered or scalar is None or scalar.getUnsignedValue() != target.getOffset():
                continue
            if not executable(target) or manager.getFunctionContaining(target) is not None:
                continue
            target_instruction = listing.getInstructionAt(target)
            if target_instruction is None:
                continue
            result.append((target, {"kind": "original_immediate_code_pointer", "target": str(target),
                "source": str(instruction.getAddress()), "instruction": str(instruction),
                "instruction_bytes": original_bytes(instruction.getAddress(), instruction.getLength()),
                "target_instruction": str(target_instruction),
                "target_instruction_bytes": original_bytes(target, target_instruction.getLength())}))
    return result


def exception_metadata_candidates():
    """Use Ghidra's ehdata.h models to validate FuncInfo/unwind/catch pointers."""
    result = []
    report["exception_metadata"] = {"validated": [], "rejected": [],
        "layout_source": "Ghidra 12.0.4 MicrosoftCodeAnalyzer EHFunctionInfoModel/EHUnwindModel/EHTryBlockModel/EHCatchHandlerModel, based on Microsoft ehdata.h."}
    options = DataValidationOptions()
    for block in memory.getBlocks():
        if not block.isInitialized() or block.isExecute() or block.getName() not in (".rdata", ".data"):
            continue
        start = block.getStart().getOffset()
        end = block.getEnd().getOffset()
        for offset in range(start, end - 28 + 1, 4):
            address = toAddr(offset)
            if (getInt(address) & 0x1FFFFFFF) not in (0x19930520, 0x19930521, 0x19930522):
                continue
            try:
                info = EHFunctionInfoModel(currentProgram, address, options)
                info.validate()
                unwind_count = info.getUnwindCount()
                try_count = info.getTryBlockCount()
                if unwind_count > 4096 or try_count > 4096:
                    raise ValueError("Implausibly large exception table")
                metadata = {"address": str(address), "magic": info.getMagicNumber(),
                    "unwind_count": unwind_count, "try_count": try_count,
                    "record_bytes": original_bytes(address, info.getDataType().getLength())}
                report["exception_metadata"]["validated"].append(metadata)
                if unwind_count:
                    unwind = info.getUnwindModel()
                    unwind.validate()
                    for index in range(unwind_count):
                        target = unwind.getActionAddress(index)
                        if target is None or not executable(target):
                            continue
                        pointer = unwind.getComponentAddressOfActionAddress(index)
                        result.append((target, {"kind": "validated_cpp_unwind_action", "target": str(target),
                            "func_info": metadata, "source": str(pointer), "entry_index": index,
                            "to_state": unwind.getToState(index), "pointer_bytes": original_bytes(pointer, 4)}))
                if try_count:
                    tries = info.getTryBlockModel()
                    tries.validate()
                    for try_index in range(try_count):
                        catches = tries.getCatchHandlerModel(try_index)
                        catches.validate()
                        for catch_index in range(tries.getCatchHandlerCount(try_index)):
                            target = catches.getCatchHandlerAddress(catch_index)
                            if target is None or not executable(target):
                                continue
                            pointer = catches.getComponentAddressOfCatchHandlerAddress(catch_index)
                            result.append((target, {"kind": "validated_cpp_catch_handler", "target": str(target),
                                "func_info": metadata, "source": str(pointer), "try_index": try_index,
                                "catch_index": catch_index, "pointer_bytes": original_bytes(pointer, 4)}))
            except (Exception, JavaException) as error:
                report["exception_metadata"]["rejected"].append({"address": str(address), "error": str(error)})
    return result


def seh3_scope_candidates():
    """Original SEH3 prologs establish the scope-table layout and owner."""
    result = []
    report['seh3_metadata'] = {'validated': [], 'rejected': []}
    for instruction in listing.getInstructions(True):
        if instruction.getMnemonicString() != 'PUSH' or instruction.getScalar(0) is None:
            continue
        address = instruction.getAddress()
        previous = listing.getInstructionBefore(address)
        following = listing.getInstructionAfter(address)
        if previous is None or previous.getMnemonicString() != 'PUSH' or previous.getScalar(0) is None or (previous.getScalar(0).getUnsignedValue() & 0xffffffff) != 0xffffffff:
            continue
        if following is None or following.getMnemonicString() != 'PUSH' or following.getScalar(0) is None or following.getScalar(0).getUnsignedValue() != 0x45b408:
            continue
        fs_read = listing.getInstructionAfter(following.getAddress())
        if fs_read is None or str(fs_read).upper() != 'MOV EAX,FS:[0X0]':
            # Compare original bytes as Ghidra renderer varies across versions.
            if fs_read is None or original_bytes(fs_read.getAddress(), fs_read.getLength()) != '64 a1 00 00 00 00':
                continue
        owner = manager.getFunctionContaining(address)
        table = toAddr(instruction.getScalar(0).getUnsignedValue())
        table_block = memory.getBlock(table)
        if owner is None or table_block is None or table_block.isExecute() or not table_block.isInitialized():
            continue
        # The preceding PUSH -1 creates the try-level slot at [EBP-4]. The
        # greatest original nonnegative store supplies the required table size.
        states = []
        for store in listing.getInstructions(owner.getBody(), True):
            if store.getMnemonicString() != 'MOV' or store.getNumOperands() != 2:
                continue
            scalar = store.getScalar(1)
            operand = str(store.getDefaultOperandRepresentation(0)).upper()
            if scalar is not None and '[EBP + -0X4]' in operand and 0 <= scalar.getSignedValue() < 64:
                states.append(scalar.getSignedValue())
        if not states:
            continue
        count = max(states)+1
        metadata = {'table': str(table), 'owner': str(owner.getEntryPoint()), 'scope_count': count,
            'prolog_push': {'address': str(address), 'instruction': str(instruction), 'bytes': original_bytes(address,instruction.getLength())},
            'handler_push': {'address': str(following.getAddress()), 'instruction': str(following), 'bytes': original_bytes(following.getAddress(),following.getLength())},
            'fs_chain_read_bytes': original_bytes(fs_read.getAddress(),fs_read.getLength())}
        entries = []
        valid = True
        for index in range(count):
            scope = table.add(index*12)
            to_state, filter_offset, handler_offset = getInt(scope), getInt(scope.add(4)) & 0xffffffff, getInt(scope.add(8)) & 0xffffffff
            if not -1 <= to_state < index or not executable(toAddr(handler_offset)) or (filter_offset != 0 and not executable(toAddr(filter_offset))):
                valid = False
                break
            entries.append((index, scope, to_state, filter_offset, handler_offset))
        if not valid:
            report['seh3_metadata']['rejected'].append(metadata)
            continue
        report['seh3_metadata']['validated'].append(metadata)
        for index, scope, to_state, filter_offset, handler_offset in entries:
            for component, offset, kind in [(4,filter_offset,'validated_seh3_filter'),(8,handler_offset,'validated_seh3_handler')]:
                if offset:
                    result.append((toAddr(offset), {'kind': kind, 'target': str(toAddr(offset)), 'source': str(scope.add(component)),
                        'pointer_bytes': original_bytes(scope.add(component),4), 'scope_record_bytes': original_bytes(scope,12),
                        'entry_index': index, 'to_state': to_state, 'association': metadata}))
    return result


def padded_leaf_candidates():
    """Only existing straight-line instructions ending in RET after raw padding."""
    result = []
    iterator = listing.getInstructions(True)
    while iterator.hasNext():
        first = iterator.next()
        start = first.getAddress()
        if not executable(start) or manager.getFunctionContaining(start) is not None:
            continue
        if start.getOffset() % 16 != 0:
            continue
        block = memory.getBlock(start)
        if start.getOffset() - block.getStart().getOffset() < 4:
            continue
        padding_length = 0
        for distance in range(1, 17):
            before = start.subtract(distance)
            if not block.contains(before):
                break
            if (getByte(before) & 255) not in (0x90, 0xCC):
                break
            padding_length += 1
        if padding_length < 2:
            continue
        # Reject a preceding decoded instruction which falls through into this
        # boundary. Padding bytes must not be the tail of an earlier instruction.
        previous = listing.getInstructionContaining(start.subtract(1))
        if previous is not None and previous.getMnemonicString() not in ("NOP", "INT3"):
            continue
        cursor, instruction_count, valid = start, 0, False
        while cursor.getOffset() - start.getOffset() < 128:
            instruction = listing.getInstructionAt(cursor)
            if instruction is None or manager.getFunctionContaining(cursor) is not None:
                break
            instruction_count += 1
            if instruction.getMnemonicString() == "RET":
                valid = True
                break
            flow = instruction.getFlowType()
            if flow.isCall() or flow.isJump() or flow.isTerminal():
                break
            if instruction.getFallThrough() != instruction.getMaxAddress().add(1):
                break
            cursor = instruction.getFallThrough()
        if valid:
            result.append((start, {"kind": "padding_bounded_straight_line_ret_leaf", "target": str(start),
                "padding_start": str(start.subtract(padding_length)), "padding_bytes": original_bytes(start.subtract(padding_length), padding_length),
                "instruction_count": instruction_count, "ret_address": str(cursor),
                "instruction_bytes": original_bytes(start, int(cursor.getOffset() - start.getOffset() + instruction.getLength()))}))
    return result


with codecs.open(candidate_path, "r", "utf-8") as stream:
    mfc_document = json.load(stream)
records = mfc_document.get("records", mfc_document.get("entries", []))
if not records and "tables" in mfc_document:
    records = [record for table in mfc_document["tables"] for record in table["entries"]]
if not records:
    raise ValueError("Validated MFC candidate document has no records")
for record in records:
    source = toAddr(str(record.get("recordVA", record.get("entryAddress"))))
    target = toAddr(str(record.get("functionVA", record.get("handlerAddress"))))
    fields = [getInt(source.add(index * 4)) & 0xFFFFFFFF for index in range(6)]
    if fields[5] != target.getOffset():
        raise ValueError("MFC pointer does not match original bytes at " + str(source))
    evidence = {"kind": "validated_mfc_message_map", "target": str(target), "record_address": str(source),
                "original_record_words": fields, "original_record_bytes": original_bytes(source, 24),
                "record": record}
    attempt(target, evidence)
if len(args) == 3:
    with codecs.open(str(args[2]), 'r', 'utf-8') as stream:
        class_document = json.load(stream)
    if class_document['source_sha256'] != report['source_sha256']:
        raise ValueError('CRuntimeClass candidate evidence refers to another executable')
    for record in class_document['entries']:
        source = toAddr(record['recordVA'])
        target = toAddr(record['functionVA'])
        if (getInt(source.add(12)) & 0xffffffff) != target.getOffset():
            raise ValueError('CRuntimeClass callback does not match original bytes')
        attempt(target, {'kind': 'validated_cruntime_class_create_object', 'target': str(target),
            'source': str(source.add(12)), 'pointer_bytes': original_bytes(source.add(12),4),
            'record': record, 'record_bytes': original_bytes(source,24)})
compiler_label = str(currentProgram.getCompiler())
try:
    # The old PE has no modern compiler stamp. Ghidra's EH model otherwise
    # rejects it before examining bytes. Temporarily select its Visual Studio
    # validator; restore the imported metadata immediately after validation.
    currentProgram.setCompiler(str(CompilerEnum.VisualStudio))
    exception_candidates = exception_metadata_candidates()
finally:
    currentProgram.setCompiler(compiler_label)
report["exception_metadata"]["compiler_validation_label"] = str(CompilerEnum.VisualStudio)
report["exception_metadata"]["imported_compiler_label_restored"] = compiler_label
for target, evidence in exception_candidates:
    attempt(target, evidence)
for target, evidence in seh3_scope_candidates():
    attempt(target, evidence)
checkpoint()

for pass_number in range(1, 6):
    before = len(report["created"])
    for target, evidence in call_candidates() + pointer_candidates() + immediate_code_pointer_candidates():
        attempt(target, evidence)
    if pass_number == 1:
        for target, evidence in padded_leaf_candidates():
            attempt(target, evidence)
    created = len(report["created"]) - before
    report["passes"].append({"number": pass_number, "created": created})
    checkpoint()
    println("RECOVERY_PASS %d created=%d total=%d" % (pass_number, created, len(report["created"])))
    if created == 0:
        break

# Analysis may introduce original scalar references to newly decoded callback
# stubs. Close that discovery loop before the final export/coverage audit.
for analysis_round in range(1, 4):
    analyzeChanges(currentProgram)
    before = len(report['created'])
    for target, evidence in call_candidates() + pointer_candidates() + immediate_code_pointer_candidates():
        attempt(target, evidence)
    created = len(report['created'])-before
    report['passes'].append({'analysis_round': analysis_round, 'created': created})
    if created == 0:
        break
for entry in report["created"]:
    function = manager.getFunctionAt(toAddr(entry["address"]))
    entry["final_signature"] = str(function.getSignature())
    entry["final_body_bytes"] = long(function.getBody().getNumAddresses())
    entry["entry_bytes"] = original_bytes(function.getEntryPoint(), min(16, int(function.getBody().getNumAddresses())))
final_addresses = set(str(function.getEntryPoint()) for function in manager.getFunctions(True))
report["final_functions"] = len(final_addresses)
report["new_function_addresses"] = sorted(((final_addresses - initial_addresses) | set(previous_report.get("new_function_addresses", []) if previous_report else [])) & final_addresses)
automatic_addresses = ((final_addresses - initial_addresses) - set(entry["address"] for entry in report["created"]))
automatic_addresses.update(previous_report.get("analysis_created_functions", []) if previous_report else [])
report["analysis_created_functions"] = sorted(automatic_addresses & final_addresses)
report["analysis_created_details"] = []
for address in report["analysis_created_functions"]:
    function = manager.getFunctionAt(toAddr(address))
    references = []
    iterator = currentProgram.getReferenceManager().getReferencesTo(function.getEntryPoint())
    while iterator.hasNext():
        reference = iterator.next()
        source = reference.getFromAddress()
        instruction = listing.getInstructionContaining(source)
        references.append({"source": str(source), "type": str(reference.getReferenceType()),
                           "instruction": str(instruction) if instruction is not None else None,
                           "source_bytes": original_bytes(source, instruction.getLength() if instruction is not None else 4)})
    report["analysis_created_details"].append({"address": address, "signature": str(function.getSignature()),
        "body_bytes": long(function.getBody().getNumAddresses()), "references": references,
        "evidence": "Created by Ghidra analysis after supported code discovery; listed original references permit review."})
report["remaining_orphan_data_references"] = []
iterator = listing.getInstructions(True)
while iterator.hasNext():
    instruction = iterator.next()
    target = instruction.getAddress()
    if manager.getFunctionContaining(target) is not None or not executable(target):
        continue
    references = []
    incoming = currentProgram.getReferenceManager().getReferencesTo(target)
    while incoming.hasNext():
        reference = incoming.next()
        if not reference.getReferenceType().isData():
            continue
        source = reference.getFromAddress()
        source_instruction = listing.getInstructionContaining(source)
        references.append({"source": str(source), "type": str(reference.getReferenceType()),
            "instruction": str(source_instruction) if source_instruction is not None else None,
            "source_bytes": original_bytes(source_instruction.getAddress(), source_instruction.getLength()) if source_instruction is not None else original_bytes(source, 4)})
    if references:
        report["remaining_orphan_data_references"].append({"target": str(target), "instruction": str(instruction),
                                                          "references": references})
report["complete"] = True
checkpoint()
println("RECOVERY_COMPLETE initial=%d final=%d documented_created=%d rejected=%d" %
        (report["initial_functions"], report["final_functions"], len(report["created"]), len(report["rejected"])))
