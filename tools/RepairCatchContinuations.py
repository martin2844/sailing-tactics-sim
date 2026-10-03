# Restore original catch continuation control flow and shared method tails.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json
import os
from ghidra.program.model.address import AddressSet
from ghidra.program.model.listing import FlowOverride

args = getScriptArgs()
with codecs.open(str(args[0]), 'r', 'utf-8') as stream:
    recovery = json.load(stream)
manager = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
references = currentProgram.getReferenceManager()
automatic = set(recovery['analysis_created_functions'])
report = {'source_sha256': str(currentProgram.getExecutableSHA256()), 'restored': [], 'removed_automatic_function_starts': []}
if os.path.isfile(str(args[1])):
    with codecs.open(str(args[1]), 'r', 'utf-8') as stream:
        previous = json.load(stream)
    if previous['source_sha256'] != report['source_sha256']:
        raise ValueError('Previous continuation evidence refers to another executable')
    report['restored'] = previous['restored']
    report['removed_automatic_function_starts'] = previous['removed_automatic_function_starts']

def record(instruction):
    return {'address': str(instruction.getAddress()), 'instruction': str(instruction),
            'bytes': ' '.join('%02x' % (b & 255) for b in instruction.getBytes())}

def immediate_mov_eax(instruction, target):
    return instruction is not None and instruction.getMnemonicString() == 'MOV' and str(instruction.getDefaultOperandRepresentation(0)) == 'EAX' and instruction.getScalar(1) is not None and instruction.getScalar(1).getUnsignedValue() == target.getOffset()

def find_owners(info_address):
    owners = []
    # The original handler stub loads its FuncInfo; the method prolog loads
    # that stub before calling the shared SEH prolog. Both references must be
    # original immediate MOV EAX values, not guessed address proximity.
    for reference in references.getReferencesTo(info_address):
        stub_instruction = listing.getInstructionAt(reference.getFromAddress())
        if not immediate_mov_eax(stub_instruction, info_address):
            continue
        stub = stub_instruction.getAddress()
        for owner_reference in references.getReferencesTo(stub):
            prolog = listing.getInstructionAt(owner_reference.getFromAddress())
            owner = manager.getFunctionContaining(owner_reference.getFromAddress())
            if owner is None or owner.getEntryPoint() != prolog.getAddress() or not immediate_mov_eax(prolog, stub):
                continue
            next_instruction = listing.getInstructionAfter(prolog.getAddress())
            if next_instruction is None or next_instruction.getMnemonicString() != 'CALL':
                continue
            owners.append((owner, {'func_info': str(info_address), 'handler_stub': record(stub_instruction), 'owner_prolog': record(prolog), 'seh_prolog_call': record(next_instruction)}))
    return owners

def restore(owner, target, evidence):
    if target.getOffset() < owner.getEntryPoint().getOffset() or target.getOffset() - owner.getEntryPoint().getOffset() > 0x2000:
        return
    if listing.getInstructionAt(target) is None:
        disassemble(target)
    body = AddressSet(owner.getBody())
    pending = [target]
    seen = set()
    merged = []
    fixed = []
    added = []
    while pending:
        address = pending.pop()
        key = str(address)
        if key in seen:
            continue
        seen.add(key)
        if abs(address.getOffset() - owner.getEntryPoint().getOffset()) > 0x2000:
            continue
        instruction = listing.getInstructionAt(address)
        if instruction is None:
            disassemble(address)
            instruction = listing.getInstructionAt(address)
        if instruction is None:
            continue
        other = manager.getFunctionContaining(address)
        if other is not None and other != owner:
            entry = other.getEntryPoint()
            if str(entry) not in automatic:
                continue
            incoming = list(references.getReferencesTo(entry))
            if not incoming or any(listing.getInstructionAt(r.getFromAddress()) is None or listing.getInstructionAt(r.getFromAddress()).getMnemonicString() != 'JMP' or (manager.getFunctionContaining(r.getFromAddress()) not in (owner, other)) for r in incoming):
                continue
            old_body = AddressSet(other.getBody())
            merged.append({'address': str(entry), 'signature': str(other.getSignature()), 'bytes': long(old_body.getNumAddresses()), 'original_incoming': [record(listing.getInstructionAt(r.getFromAddress())) for r in incoming]})
            manager.removeFunction(entry)
            if str(entry) not in report['removed_automatic_function_starts']:
                report['removed_automatic_function_starts'].append(str(entry))
        if not body.contains(address):
            body.add(instruction.getMinAddress(), instruction.getMaxAddress())
            added.append(record(instruction))
        mnemonic = str(instruction.getMnemonicString())
        # Ghidra had converted some original intra-method JMPs to call-return
        # references after inventing a shared-return function. Restore JMP
        # interpretation; no machine instruction is changed.
        if mnemonic == 'JMP' and instruction.getFlowOverride() != FlowOverride.NONE:
            fixed.append(record(instruction))
            instruction.setFlowOverride(FlowOverride.NONE)
        fallthrough = instruction.getFallThrough()
        if fallthrough is not None:
            pending.append(fallthrough)
        if mnemonic.startswith('J') and not instruction.getFlowType().isComputed():
            pending.extend(instruction.getFlows())
    owner.setBody(body)
    # Include other original conditional branches from the method into
    # previously orphaned blocks, which may converge with this continuation.
    for instruction in list(listing.getInstructions(owner.getBody(), True)):
        if str(instruction.getMnemonicString()).startswith('J') and not instruction.getFlowType().isComputed():
            for branch_target in instruction.getFlows():
                if manager.getFunctionContaining(branch_target) is None and str(branch_target) not in seen:
                    restore(owner, branch_target, {'kind': 'original_method_branch', 'source': record(instruction), 'parent_continuation': str(target)})
    if added or merged or fixed:
        row = {'owner': str(owner.getEntryPoint()), 'continuation': str(target), 'evidence': evidence, 'newly_owned_instructions': added, 'merged_automatic_tails': merged, 'restored_jumps': fixed}
        if not any(previous['owner'] == row['owner'] and previous['continuation'] == row['continuation'] for previous in report['restored']):
            report['restored'].append(row)

for entry in recovery['created']:
    evidence = entry['evidence']
    if evidence['kind'] != 'validated_cpp_catch_handler':
        continue
    function = manager.getFunctionAt(toAddr(entry['address']))
    if function is None:
        continue
    for instruction in list(listing.getInstructions(function.getBody(), True)):
        scalar = instruction.getScalar(1) if instruction.getNumOperands() > 1 else None
        if scalar is None:
            continue
        target = toAddr(scalar.getUnsignedValue())
        following = listing.getInstructionAfter(instruction.getAddress())
        if not immediate_mov_eax(instruction, target) or following is None or following.getMnemonicString() != 'RET':
            continue
        for owner, owner_evidence in find_owners(toAddr(evidence['func_info']['address'])):
            restore(owner, target, {'kind': 'original_cpp_catch_return_continuation', 'catch_handler': str(function.getEntryPoint()), 'return_instruction': record(instruction), 'ret_instruction': record(following), 'association': owner_evidence})
analyzeChanges(currentProgram)
with codecs.open(str(args[1]), 'w', 'utf-8') as stream:
    stream.write(json.dumps(report, sort_keys=True, indent=2) + u'\n')
println('CATCH_CONTINUATIONS_RESTORED %d merged=%d' % (len(report['restored']), len(report['removed_automatic_function_starts'])))
