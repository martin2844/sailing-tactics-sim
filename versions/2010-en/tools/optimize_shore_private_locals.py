"""Promote reviewed private I32 fields beside the aliased 0x47ed40 buffers.

The complete byte function remains the fallback. This pass does not restructure
control flow, promote slot264, or promote any point/callback/array byte image.
"""
import hashlib
import re
from pathlib import Path
from optimize_static_locals import _calls, _code_mask


# These are the actual helpers called by the emitted body. In particular,
# writeLocalPoint writes exactly two I32 cells and does not expose destination.
# A changed helper requires another alias review before regeneration may use
# this proof; unrelated code in typed-c.js does not invalidate the receipt.
CALLEE_SHA256 = {
    'cI32': '4945bf329b40ed09201c3fa21715c841332f779f9af6e9adbb9a1678fe47817d',
    'pointerAdd': 'e96b44a00909aedecc8ab99415f3daf5094e226c152cb16179560fb463304a3a',
    'cAdd': 'bfe75acd8a09a6ea7122a8aefd4257d4fca5159a8e9943f6e5b4ee69659e9f43',
    'readPointer': '8ad9a3edfbd091ed525db01a6a4c1be58da192eccb7851b5234fccbb0d8e7d88',
    'writePointer': '42df05c07af66352861d80502c7c42efde3b65d46703be0a4b3f74411756e4bf',
    'writeLocalPoint': '525c13dadfd6bc58b16771af21d749ef8503a83809a0dc02d4abc4be1e48da99',
}


def callee_contracts_match(source):
    mask = _code_mask(source)
    for name, expected in CALLEE_SHA256.items():
        matches = list(re.finditer(r'\bexport function ' + name + r'\(', mask))
        if len(matches) != 1:
            return False
        match = matches[0]
        opening = mask.find('{', match.end())
        if opening < 0:
            return False
        end, depth = opening + 1, 1
        while end < len(mask) and depth:
            depth += (mask[end] == '{') - (mask[end] == '}')
            end += 1
        if depth or hashlib.sha256(source[match.start():end].encode()).hexdigest() != expected:
            return False
    return source.count('export const framePointer=(frame,offset)=>({frame,offset});') == 1


def promote_shore_private_locals(source, name, address, frame_size):
    record = {'address': address, 'function': name, 'frameBytes': frame_size,
              'eligible': False, 'mode': 'partial'}

    def reject(reason):
        return source, {**record, 'reason': reason}

    if name != 'originalDrawing0047ed40Number' or address != 0x47ed40 or frame_size != 920:
        return reject('Unreviewed shoreline function/frame')
    runtime = Path(__file__).resolve().parents[1] / 'src/render/typed-c.js'
    if not callee_contracts_match(runtime.read_text()):
        return reject('Shoreline pointer callee contract changed')
    declaration = f'  const localFrame=createLocalFrame({frame_size},options.retainedDrawingStack?.[{address}]??[]);'
    signature = f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)'
    mask = _code_mask(source)
    if source.count(declaration) != 1 or source.count(signature) != 1:
        return reject('Shoreline frame declaration/signature changed')
    if re.search(r'\b(?:scalarStack\d+|retainedLocalBytes)\b', mask):
        return reject('Generated scalar identifiers would collide')
    cases = {}
    for match in re.finditer(r'^    case (\d+): \{ (.*) \}$', source, re.M):
        index = int(match[1])
        if index in cases:
            return reject('Shoreline has duplicate control-flow labels')
        cases[index] = match[2]
    if sorted(cases) != list(range(472)) or source.count('  let pc = 471;\n  for (;;) { switch (pc) {') != 1:
        return reject('Shoreline control-flow entry/labels changed')
    edges, previous = {}, {index: set() for index in cases}
    for index, code in cases.items():
        tail = re.search(r'pc = (?:(\d+)|.* \? (\d+) : (\d+)); continue;$', code)
        if tail:
            if re.search(r'\bpc\b', _code_mask(code[:tail.start()])):
                return reject('Shoreline has an unknown control transfer')
            targets = [int(value) for value in tail.groups() if value is not None]
        elif re.match(r'^return(?:\s|;)', code) and not re.search(r'\bpc\b', _code_mask(code)):
            targets = []
        else:
            return reject('Shoreline has an unknown control transfer')
        if any(target not in previous for target in targets):
            return reject('Shoreline has an unknown control-flow target')
        edges[index] = targets
        for target in targets:
            previous[target].add(index)

    expected = {
        160: 'pc = cTruth(cCompare(cI32(readLocal(framePointer(localFrame,264),4,"int"),false),71,"<")) ? 259 : 159; continue;',
        161: 'writeLocal(framePointer(localFrame,264),cAdd(readLocal(framePointer(localFrame,264),4,"int"),readLocal(framePointer(localFrame,276),4,"int")),4,"int"); pc = 160; continue;',
        262: 'writeLocal(framePointer(localFrame,264),1,4,"int"); pc = 261; continue;',
        264: 'writeLocal(framePointer(localFrame,276),1,4,"int"); pc = 263; continue;',
        266: 'writeLocal(framePointer(localFrame,276),2,4,"int"); pc = 265; continue;',
        267: 'writeLocal(framePointer(localFrame,276),1,4,"int"); pc = 265; continue;',
        370: 'pc = cTruth(cCompare(cI32(readLocal(framePointer(localFrame,268),4,"int"),false),5462965,"<")) ? 424 : 369; continue;',
        374: 'writeLocal(framePointer(localFrame,260),cAdd(readLocal(framePointer(localFrame,260),4,"int"),1),4,"int"); pc = 373; continue;',
        375: 'writeLocal(framePointer(localFrame,268),cAdd(readLocal(framePointer(localFrame,268),4,"int"),cMul(1,4)),4,"int"); pc = 374; continue;',
        429: 'writeLocal(framePointer(localFrame,268),0x535a98,4,"int"); pc = 428; continue;',
        430: 'writeLocal(framePointer(localFrame,260),0,4,"int"); pc = 429; continue;',
    }
    if any(cases[index] != code for index, code in expected.items()):
        return reject('Shoreline array induction proof changed')
    required = {160: {161}, 259: {160, 260}, 260: {261}, 261: {262}, 262: {263},
                263: {264, 265}, 264: {265}, 265: {266, 267}, 266: {268}, 267: {268},
                370: {371}, 371: {372}, 372: {373}, 373: {374}, 374: {375},
                424: {370, 425}, 425: {426}, 426: {427}, 427: {428}, 428: {429}, 429: {430}}
    if any(previous[index] != incoming for index, incoming in required.items()):
        return reject('Shoreline array loop can bypass initialization/update')

    def closed_body(entry, stop, expected_nodes, entrances):
        body, pending = set(), [entry]
        while pending:
            index = pending.pop()
            if index == stop or index in body:
                continue
            body.add(index)
            pending.extend(edges[index])
        actual_entrances = {(origin, target) for origin, targets in edges.items()
                            for target in targets if target in body and origin not in body}
        return body == expected_nodes and actual_entrances == entrances

    if not closed_body(424, 370, set(range(371, 425)), {(370, 424), (425, 424)}):
        return reject('Shoreline first array loop is not closed')
    if any(target >= index for index in range(371, 425) for target in edges[index]):
        return reject('Shoreline first array loop can repeat an update')
    if not closed_body(259, 160, set(range(161, 260)), {(160, 259), (260, 259)}):
        return reject('Shoreline second array loop is not closed')

    # First loop: pointer268 =0x535a98+4*k and counter260=k at its
    # accesses. The post-test pointer<0x535bb5 gives k=0..71, and writes
    # use k+1=1..72. Second loop: counter264 starts1, step276 is1/2,
    # and post-test counter264<71 bounds reads to1..70 (plus1<=71).
    # The predecessor chains force each relevant update exactly once. Inner
    # second-loop cycles leave264/276 unchanged. Both ranges fit signed I32.
    slots = {offset: (4, '"int"') for offset in [0, 4, 8, 256, 260, 268, 272, 276, 280]}
    selected, found = [], _calls(source, mask)
    if not found:
        return reject('No recognized shoreline fixed local accesses')
    frame_uses = list(mask)
    at = source.index(declaration)
    frame_uses[at:at + len(declaration)] = ' ' * len(declaration)
    seen, induction_stores = set(), []
    for call in found:
        args = call['args']
        if len(args) != (4 if call['kind'] == 'writeLocal' else 3):
            return reject('Shoreline local access has an unsupported width')
        pointer = re.fullmatch(r'framePointer\(localFrame,(\d+)\)', args[0][2])
        if not pointer or args[-2][2] != '4' or args[-1][2] != '"int"':
            return reject('Shoreline local access is not a fixed I32 view')
        offset = int(pointer[1])
        if offset + 4 > frame_size:
            return reject('Shoreline local exceeds the declared frame')
        overlap = [other for other in slots if offset < other + 4 and other < offset + 4]
        if overlap and overlap != [offset]:
            return reject('Shoreline scalar has an overlapping byte view')
        line_start = source.rfind('\n', 0, call['start']) + 1
        prefix = mask[line_start:call['start']]
        case = re.match(r'\s*case (\d+):', prefix)
        if call['kind'] == 'writeLocal' and offset in [260, 264, 268, 276]:
            induction_stores.append((int(case[1]) if case else None, offset))
        if offset in slots:
            if call['kind'] == 'writeLocal':
                statement = re.fullmatch(r'\s*(?:case \d+: \{\s*)?', prefix) and source[call['end']:call['end'] + 1] == ';'
                # The emitter uses an extra grouping pair around a comma
                # expression. Its first operand's returned value is discarded;
                # replacing the store with assignment preserves that sequence.
                comma = re.search(r'\(\s*\(\s*$', prefix) and source[call['end']:].startswith(', cCompare(')
                if not statement and not comma:
                    return reject('Shoreline scalar write return is observable')
            call['offset'] = offset
            selected.append(call)
            seen.add(offset)
        begin, end, _expression = args[0]
        frame_uses[begin:end] = ' ' * (end - begin)
    if seen != set(slots):
        return reject('Reviewed shoreline private slots changed')
    # Cover the complete lifetime, including preheaders. A store between the
    # pinned initialization and loop entry could invalidate a nonnegative
    # index even though the loop body itself contains only reviewed updates.
    # The other listed stores belong to disjoint earlier/later uses of these
    # stack fields; closed entries reset each counter before its array loop.
    known_induction_stores = [(161, 264), (262, 264), (264, 276), (266, 276),
        (267, 276), (273, 268), (274, 268), (275, 268), (291, 260),
        (311, 260), (374, 260), (375, 268), (429, 268), (430, 260),
        (431, 264), (432, 264), (433, 264)]
    if induction_stores != known_induction_stores:
        return reject('Shoreline has an unreviewed induction counter/step store')
    if [row for row in induction_stores if 371 <= (row[0] or -1) <= 424] != [(374, 260), (375, 268)]:
        return reject('Shoreline first loop changes an induction counter')
    if [row for row in induction_stores if 161 <= (row[0] or -1) <= 259] != [(161, 264)]:
        return reject('Shoreline second loop changes an induction counter/step')

    for call in _calls(source, mask, ('readPointer', 'writePointer', 'writeLocalPoint')) or []:
        args = call['args']
        pointer_index = 0 if call['kind'] == 'writeLocalPoint' else 1
        if len(args) <= pointer_index:
            continue
        begin, end, expression = args[pointer_index]
        if not re.search(r'\blocalFrame\b', ''.join(frame_uses[begin:end])):
            continue
        expression = re.sub(r'\s+', '', expression)
        prefix = source[source.rfind('\n', 0, call['start']) + 1:call['start']]
        case = re.match(r'\s*case (\d+):', prefix)
        index = int(case[1]) if case else None
        point = re.fullmatch(r'framePointer\(localFrame,(304|312|320|328)\)', expression)
        constant = re.fullmatch(r'pointerAdd\(framePointer\(localFrame,(304|312|624)\),cMul\(0,4\)\)', expression)
        moving = re.fullmatch(r'pointerAdd\(framePointer\(localFrame,(332|624)\),cMul\((readLocal\(framePointer\(localFrame,(264)\),4,"int"\)|cAdd\(readLocal\(framePointer\(localFrame,(260|264)\),4,"int"\),1\)),4\)\)', expression)
        if point and call['kind'] == 'writeLocalPoint' and len(args) == 2:
            first, last = int(point[1]), int(point[1]) + 8
        elif constant and ((call['kind'] == 'readPointer' and len(args) == 3) or (call['kind'] == 'writePointer' and len(args) == 4)) and args[-1][2] == '4':
            first, last = int(constant[1]), int(constant[1]) + 4
        elif moving and args[-1][2] == '4':
            counter = int(moving[3] or moving[4])
            if counter == 260 and call['kind'] == 'writePointer' and len(args) == 4 and index in [393, 394]:
                minimum, maximum = 1, 72
            elif counter == 264 and call['kind'] == 'readPointer' and len(args) == 3 and index in range(161, 260):
                minimum, maximum = (2, 71) if moving[4] else (1, 70)
            else:
                return reject('Shoreline pointer lies outside its proved array loop')
            first, last = int(moving[1]) + minimum * 4, int(moving[1]) + maximum * 4 + 4
        else:
            return reject('Shoreline frame pointer has an unproved escape')
        if first < 300 or last > frame_size or any(first < offset + 4 and offset < last for offset in slots):
            return reject('Shoreline pointer can overlap a promoted scalar')
        frame_uses[begin:end] = ' ' * (end - begin)
    if re.search(r'\blocalFrame\b', ''.join(frame_uses)):
        return reject('Shoreline frame address escapes reviewed callees')

    def render(begin, end):
        output, previous_at = [], begin
        for call in selected:
            if call['start'] < previous_at or call['start'] < begin or call['end'] > end:
                continue
            output.append(source[previous_at:call['start']])
            variable = f"scalarStack{call['offset']}"
            if call['kind'] == 'writeLocal':
                value_start, value_end, _value = call['args'][1]
                output.append(f'{variable}=scalarStoreI32({render(value_start,value_end)})')
            elif call['kind'] == 'readLocal':
                output.append(f'scalarRead({variable})')
            else:
                output.append(variable)
            previous_at = call['end']
        output.append(source[previous_at:end])
        return ''.join(output)

    guard = "'events' in Number.prototype||'frame' in Number.prototype||'dc' in Number.prototype||'array' in Number.prototype"
    promoted = render(0, len(source)).replace(declaration,
        f'  const retainedLocalBytes=options.retainedDrawingStack?.[{address}]??(({guard})?[]:undefined);\n'
        f'  if(retainedLocalBytes!=null)return {name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes);\n'
        f'  const localFrame=createLocalFrame({frame_size},[]);\n'
        '  let ' + ','.join(f'scalarStack{offset}' for offset in slots) + ';')
    byte_frame = source.replace(signature,
        f'function {name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
    byte_frame = byte_frame.replace(declaration, f'  const localFrame=createLocalFrame({frame_size},retainedLocalBytes);')
    record.update(eligible=True,
        slots=[{'offset': offset, 'size': 4, 'kind': 'int'} for offset in slots],
        retainedByteRanges=[{'start': 264, 'end': 268}, {'start': 300, 'end': 920}],
        scalarAccesses=len(selected),
        induction={'writeIndices': [1, 72], 'readIndices': [1, 71], 'readSteps': [1, 2]},
        pointerCalleeSha256=CALLEE_SHA256)
    return promoted + '\n\n' + byte_frame, record
