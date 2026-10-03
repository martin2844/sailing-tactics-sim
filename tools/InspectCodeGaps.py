# Inspect original references around uncovered executable bytes.
#@category Tact.Preservation
#@runtime Jython
import codecs
import json

args = getScriptArgs()
with codecs.open(str(args[0]), 'r', 'utf-8') as stream:
    coverage = json.load(stream)
listing = currentProgram.getListing()
manager = currentProgram.getFunctionManager()
refs = currentProgram.getReferenceManager()

def instruction_record(instruction):
    if instruction is None:
        return None
    function = manager.getFunctionContaining(instruction.getAddress())
    return {'address': str(instruction.getAddress()), 'instruction': str(instruction),
            'bytes': ' '.join('%02x' % (b & 255) for b in instruction.getBytes()),
            'fallthrough': str(instruction.getFallThrough()) if instruction.getFallThrough() else None,
            'flows': [str(a) for a in instruction.getFlows()],
            'flow_type': str(instruction.getFlowType()),
            'function': str(function.getEntryPoint()) if function else None}

def incoming(address):
    result = []
    for reference in refs.getReferencesTo(address):
        result.append({'source': str(reference.getFromAddress()), 'type': str(reference.getReferenceType()),
                       'instruction': instruction_record(listing.getInstructionContaining(reference.getFromAddress()))})
    return result

result = {'gaps': [], 'unassigned': [], 'functions': []}
result['eh_references'] = []
for address in ['0048ee18', '00480ae4', '0048e4d8', '0047d3b4']:
    result['eh_references'].append({'address': address, 'incoming': incoming(toAddr(address))})
for block in coverage['blocks']:
    for extent in block['undefined_ranges']:
        address = toAddr(extent['start'])
        payload = getBytes(address, int(extent['bytes']))
        if all((b & 255) in (0x90, 0xcc, 0) for b in payload):
            continue
        result['gaps'].append({'range': extent, 'bytes': ' '.join('%02x' % (b & 255) for b in payload),
            'previous': instruction_record(listing.getInstructionBefore(address)), 'incoming': incoming(address)})
    for extent in block['unassigned_instruction_ranges']:
        address = toAddr(extent['start'])
        result['unassigned'].append({'range': extent, 'incoming': incoming(address),
                                    'previous': instruction_record(listing.getInstructionBefore(address))})
for address in ['0046ee6b', '0046ef7f', '0046ef8f']:
    function = manager.getFunctionAt(toAddr(address))
    if function:
        record = {'address': address, 'signature': str(function.getSignature()), 'no_return': function.hasNoReturn(),
                  'incoming': incoming(toAddr(address)), 'ranges': [], 'instructions': []}
        for extent in function.getBody().getAddressRanges():
            record['ranges'].append({'start': str(extent.getMinAddress()), 'end': str(extent.getMaxAddress())})
        for instruction in listing.getInstructions(function.getBody(), True):
            record['instructions'].append(instruction_record(instruction))
        result['functions'].append(record)
with codecs.open(str(args[1]), 'w', 'utf-8') as stream:
    stream.write(json.dumps(result, sort_keys=True, indent=2) + u'\n')
println('GAPS_INSPECTED nonpadding=%d' % len(result['gaps']))
