"""Promote private, disjoint fixed-width C stack slots to JavaScript scalars.

This is deliberately a narrow pass over the drawing emitter's own output. Any
address that escapes a read/write, overlapping view, unusual width, or observed
write result keeps the complete byte frame. Explicit retained-byte inputs also
select that unchanged frame implementation at runtime.
"""
import json
import re


def _code_mask(source):
    """Hide strings/comments without changing offsets or line boundaries."""
    pattern = r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|`(?:\\.|[^`\\])*`|/\*.*?\*/|//[^\n]*'
    return re.sub(pattern, lambda match: ''.join('\n' if char == '\n' else ' ' for char in match[0]), source, flags=re.S)


def _arguments(source, mask, start, end):
    result = []
    depth = 0
    previous = start
    for index in range(start, end):
        char = mask[index]
        if char in '([{':
            depth += 1
        elif char in ')]}':
            depth -= 1
        elif char == ',' and depth == 0:
            result.append((previous, index, source[previous:index].strip()))
            previous = index + 1
    result.append((previous, end, source[previous:end].strip()))
    return result


def _calls(source, mask, names=('readLocalArgument', 'readLocal', 'writeLocal')):
    result = []
    for match in re.finditer(r'\b(' + '|'.join(names) + r')\(', mask):
        at = match.end()
        depth = 1
        while at < len(mask) and depth:
            if mask[at] == '(':
                depth += 1
            elif mask[at] == ')':
                depth -= 1
            at += 1
        if depth:
            return None
        result.append({'start': match.start(), 'end': at, 'kind': match[1],
                       'args': _arguments(source, mask, match.end(), at - 1)})
    return result


def _promote_water_private_locals(source, name, address, frame_size, promote_arrays=True):
    """Promote only the reviewed nonaliased slots of the 0x466330 Number body.

    The point loop's two induction variables start at zero and advance by 8/4.
    Its post-test is iVar16 <137, so accesses occur at 0..136/0..68: eighteen
    F64/I32 cells, irrespective of the decompiler's four-element declarations.
    Check that exact closed CFG before using those ranges. Every other frame
    address must be a reviewed constant-width access. The mixed low-word views
    at 256/272 stay in the original byte frame. Array accesses can use private
    scalar cells after every access width/alignment and induction is proved.
    """
    record = {'address': address, 'function': name, 'frameBytes': frame_size,
              'eligible': False, 'mode': 'partial'}

    def reject(reason):
        return source, {**record, 'reason': reason}

    declaration = f'  const localFrame=createLocalFrame({frame_size},options.retainedDrawingStack?.[{address}]??[]);'
    signature = f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)'
    mask = _code_mask(source)
    if source.count(declaration) != 1 or source.count(signature) != 1:
        return reject('Partial frame declaration/signature changed')
    if re.search(r'\b(?:scalarStack\d+|scalarArray\d+|scalarArrayF64Read|scalarArrayF64Store|scalarFloatWordsNumber|retainedLocalBytes)\b', mask):
        return reject('Generated scalar identifiers would collide')
    cases = {}
    for match in re.finditer(r'^    case (\d+): \{ (.*) \}$', source, re.M):
        index = int(match[1])
        if index in cases:
            return reject('Partial point loop has duplicate control-flow labels')
        cases[index] = match[2]
    if sorted(cases) != list(range(279)):
        return reject('Partial point loop control-flow labels changed')
    if source.count('  let pc = 278;\n  for (;;) { switch (pc) {') != 1:
        return reject('Partial point loop initial entry changed')
    expected = {
        166: 'pc = cTruth(cCompare(iVar16,137,"<")) ? 171 : 165; continue;',
        167: '(iVar24 = cAdd(iVar24,4)); pc = 166; continue;',
        168: '(iVar16 = cAdd(iVar16,8)); pc = 167; continue;',
        169: 'writePointer(memory,cAdd(cI32(framePointer(localFrame,396),false),iVar24),r32(0x523660),4); pc = 168; continue;',
        170: 'writePointer(memory,cAdd(cI32(framePointer(localFrame,476),false),iVar24),r32(0x4fed58),4); pc = 169; continue;',
        189: '(iVar24 = 0); pc = 188; continue;',
        190: '(iVar16 = 0); pc = 189; continue;',
    }
    if any(cases[index] != code for index, code in expected.items()):
        return reject('Partial point loop induction proof changed')
    # No branch may enter after either initialization. No body statement may
    # alter the counters; a called function cannot mutate these JS scalars.
    predecessors = {index: set() for index in cases}
    for index, code in cases.items():
        tail = re.search(r'pc = (?:(\d+)|.* \? (\d+) : (\d+)); continue;$', code)
        if tail:
            if re.search(r'\bpc\b', _code_mask(code[:tail.start()])):
                return reject('Partial point loop has an unknown control transfer')
            for target in (int(value) for value in tail.groups() if value is not None):
                if target not in predecessors:
                    return reject('Partial point loop has an unknown target')
                predecessors[target].add(index)
        elif not re.match(r'^return(?:\s|;)', code) or re.search(r'\bpc\b', _code_mask(code)):
            return reject('Partial point loop has an unknown control transfer')
    required_predecessors = {166: {167}, 167: {168}, 168: {169}, 169: {170},
                             170: {171}, 171: {166, 172}}
    required_predecessors.update({index: {index + 1} for index in range(172, 190)})
    if any(predecessors[index] != previous for index, previous in required_predecessors.items()):
        return reject('Partial point loop can bypass induction initialization')
    for index in range(171, 189):
        if not cases[index].endswith(f'pc = {index - 1}; continue;'):
            return reject('Partial point loop body changed its sequence')
        if re.search(r'\biVar(?:16|24)\s*(?:=(?!=)|\+=|-=|\+\+|--)|(?:\+\+|--)\s*\biVar(?:16|24)\b', _code_mask(cases[index])):
            return reject('Partial point loop body changes an induction variable')

    slots = {0: (4, '"int"'), 4: (8, '"float"'), 12: (8, '"float"'),
             20: (4, '"int"'), 24: (4, '"int"'), 264: (8, '"float"'),
             280: (4, '"int"'), 308: (4, '"int"'), 552: (8, '"float"')}
    arrays = {396: (4, '"int"'), 476: (4, '"int"'),
              568: (8, '"float"'), 728: (8, '"float"')}
    found = _calls(source, mask)
    if not found:
        return reject('No recognized partial local accesses')
    frame_uses = list(mask)
    declaration_at = source.index(declaration)
    frame_uses[declaration_at:declaration_at + len(declaration)] = ' ' * len(declaration)
    selected = []
    seen = set()
    for call in found:
        args = call['args']
        if len(args) != (4 if call['kind'] == 'writeLocal' else 3):
            return reject('Partial access has unsupported width/kind')
        pointer = re.fullmatch(r'framePointer\(localFrame,(\d+)\)', args[0][2])
        size, kind = args[-2][2], args[-1][2]
        if not pointer or (size, kind) not in [('4', '"int"'), ('8', '"float"')]:
            return reject('Partial access is not a fixed I32/F64 scalar')
        offset, width = int(pointer[1]), int(size)
        if offset + width > frame_size:
            return reject('Partial access exceeds the declared frame')
        overlaps = [at for at, (length, _kind) in slots.items()
                    if offset < at + length and at < offset + width]
        array_overlaps = [base for base, (length, _kind) in arrays.items()
                          if offset < base + 18 * length and base < offset + width]
        if overlaps:
            if overlaps != [offset] or slots[offset] != (width, kind):
                return reject('Partial scalar slot has an overlapping byte view')
            if call['kind'] == 'writeLocal':
                line_start = source.rfind('\n', 0, call['start']) + 1
                if not re.fullmatch(r'\s*(?:case \d+: \{\s*)?', mask[line_start:call['start']]) or source[call['end']:call['end'] + 1] != ';':
                    return reject('Partial local write result is observable')
            call['offset'], call['type'] = offset, 'I32' if width == 4 else 'F64'
            selected.append(call)
            seen.add(offset)
        elif promote_arrays and array_overlaps:
            base = array_overlaps[0]
            element_width, element_kind = arrays[base]
            if len(array_overlaps) != 1 or (width, kind) != (element_width, element_kind) or (offset - base) % width or offset + width > base + 18 * width:
                return reject('Partial point array has an overlapping or unaligned view')
            if call['kind'] == 'readLocalArgument':
                return reject('Partial point array gained an unreviewed argument load')
            if call['kind'] == 'writeLocal':
                line_start = source.rfind('\n', 0, call['start']) + 1
                if not re.fullmatch(r'\s*(?:case \d+: \{\s*)?', mask[line_start:call['start']]) or source[call['end']:call['end'] + 1] != ';':
                    return reject('Partial point array write result is observable')
            call['arrayBase'], call['arrayIndex'] = base, str((offset - base) // width)
            call['type'] = 'I32' if width == 4 else 'F64'
            selected.append(call)
        begin, end, _pointer = args[0]
        frame_uses[begin:end] = ' ' * (end - begin)
    if seen != set(slots):
        return reject('Reviewed partial scalar slots changed')

    iterations = (137 + 8 - 1) // 8
    dynamic = {(396, 'iVar24'): (4, (iterations - 1) * 4, 169),
               (476, 'iVar24'): (4, (iterations - 1) * 4, 170),
               (568, 'iVar16'): (8, (iterations - 1) * 8, 171),
               (728, 'iVar16'): (8, (iterations - 1) * 8, 171)}
    dynamic_seen = set()
    for call in _calls(source, mask, ('readPointer', 'writePointer', 'readLocalFloatWordsNumber')) or []:
        args = call['args']
        if len(args) < 2:
            continue
        begin, end, expression = args[1]
        if not re.search(r'\blocalFrame\b', ''.join(frame_uses[begin:end])):
            continue
        width = 8 if call['kind'] == 'readLocalFloatWordsNumber' and len(args) == 2 else (
            4 if call['kind'] == 'readPointer' and len(args) == 3 and args[-1][2] == '4' else (
                4 if call['kind'] == 'writePointer' and len(args) == 4 and args[-1][2] == '4' else None))
        constant = re.fullmatch(r'pointerAdd\(framePointer\(localFrame,(256|272|396|476)\),(0|cMul\(([0-3]),4\))\)', expression)
        moving = re.fullmatch(r'cAdd\(cI32\(framePointer\(localFrame,(396|476|568|728)\),false\),(iVar16|iVar24)\)', expression)
        if constant and width == 4 and call['kind'] != 'readLocalFloatWordsNumber':
            first = int(constant[1]) + (int(constant[3]) * 4 if constant[3] else 0)
            last = first + width
        elif moving:
            key = (int(moving[1]), moving[2])
            entry = dynamic.get(key)
            line = source[source.rfind('\n', 0, call['start']) + 1:call['start']]
            case = re.match(r'\s*case (\d+):', line)
            if not entry or width != entry[0] or not case or int(case[1]) != entry[2] or key in dynamic_seen:
                return reject('Partial point array access exceeds the induction proof')
            if (width == 8) != (call['kind'] == 'readLocalFloatWordsNumber') or (width == 4 and call['kind'] != 'writePointer'):
                return reject('Partial point array changed its access kind')
            dynamic_seen.add(key)
            first, last = key[0], key[0] + entry[1] + width
        else:
            return reject('Partial frame address has an unproved escape')
        if any(first < at + length and at < last for at, (length, _kind) in slots.items()):
            return reject('Partial pointer overlaps a promoted scalar')
        if promote_arrays:
            array_overlaps = [base for base, (length, _kind) in arrays.items()
                              if first < base + 18 * length and base < last]
            if array_overlaps:
                base = array_overlaps[0]
                element_width, _kind = arrays[base]
                if len(array_overlaps) != 1 or width != element_width or first < base or last > base + 18 * width or (first - base) % width:
                    return reject('Partial pointer has an overlapping point array view')
                if constant and call['kind'] != 'readPointer':
                    return reject('Partial point array gained an unproved constant write')
                call['arrayBase'] = base
                call['arrayIndex'] = str((first - base) // width) if constant else f'{moving[2]}>>>{2 if width == 4 else 3}'
                call['type'] = 'I32' if width == 4 else 'F64'
                selected.append(call)
        frame_uses[begin:end] = ' ' * (end - begin)
    if dynamic_seen != set(dynamic) or re.search(r'\blocalFrame\b', ''.join(frame_uses)):
        return reject('Partial frame address escapes reviewed byte accesses')
    selected.sort(key=lambda call: call['start'])

    def render(begin, end):
        output, previous = [], begin
        for call in selected:
            if call['start'] < previous or call['start'] < begin or call['end'] > end:
                continue
            output.append(source[previous:call['start']])
            variable = (f"scalarArray{call['arrayBase']}[{call['arrayIndex']}]"
                        if 'arrayBase' in call else f"scalarStack{call['offset']}")
            if call['kind'] in ('writeLocal', 'writePointer'):
                value_start, value_end, _value = call['args'][2 if call['kind'] == 'writePointer' else 1]
                value = render(value_start, value_end)
                if call['type'] == 'F64' and value.startswith('fpArgument(') and value.endswith(')'):
                    value = value[len('fpArgument('):-1]
                store = 'scalarArrayF64Store' if 'arrayBase' in call and call['type'] == 'F64' else f"scalarStore{call['type']}"
                output.append(f"{variable}={store}({value})")
            elif call['kind'] in ('readLocal', 'readPointer'):
                loader = 'scalarArrayF64Read' if 'arrayBase' in call and call['type'] == 'F64' else 'scalarRead'
                output.append(f'{loader}({variable})')
            elif call['kind'] == 'readLocalFloatWordsNumber':
                output.append(f'scalarFloatWordsNumber({variable})')
            else:
                output.append(f'scalarReadArgument({variable})' if call['type'] == 'F64' else variable)
            previous = call['end']
        output.append(source[previous:end])
        return ''.join(output)

    # A Number prototype carrying a host-pointer field changes the original
    # wrapping arithmetic/dispatch. Preserve that unusual domain in bytes;
    # private scalar induction assumes ordinary small C integer counters.
    guard = "'events' in Number.prototype||'frame' in Number.prototype||'dc' in Number.prototype||'array' in Number.prototype"
    array_bindings = ''
    if promote_arrays:
        # Own undefined entries avoid inherited numeric Array.prototype values
        # replacing an undefined local byte. Strict reads retain its failure.
        array_bindings = '\n  const ' + ','.join(
            f'scalarArray{base}=[' + ','.join(['undefined'] * 18) + ']' for base in arrays) + ';'
        # Match writeLocalFloatNumber: Number already is a floating image;
        # other defined, non-Float80 inputs still undergo the original cFloat
        # conversion before the store (including its semantic-input failures).
        array_bindings += '\n  const scalarArrayF64Store=value=>scalarStoreF64(typeof value==="number"?fpLoad(value):value===undefined||value instanceof Float80?value:cFloat(value));'
        # CONCAT44 observes the byte image. Semantic F64 stores write eight
        # zero bytes, while direct named F64 loads preserve semantic identity.
        # The numeric store unboxes Float80; its general spill fallback can
        # still return a binary64 Float80, which has the same finite byte image.
        array_bindings += '\n  const scalarArrayF64Read=value=>{value=scalarRead(value);return value instanceof Float80?value.toNumber():value;};'
        array_bindings += '\n  const scalarFloatWordsNumber=value=>{value=scalarArrayF64Read(value);return typeof value==="number"?value:0;};'
    promoted = render(0, len(source)).replace(declaration,
        f'  const retainedLocalBytes=options.retainedDrawingStack?.[{address}]??(({guard})?[]:undefined);\n'
        f'  if(retainedLocalBytes!=null)return {name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes);\n'
        f'  const localFrame=createLocalFrame({frame_size},[]);\n'
        '  let ' + ','.join(f'scalarStack{offset}' for offset in sorted(slots)) + ';' + array_bindings)
    byte_frame = source.replace(signature,
        f'function {name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
    byte_frame = byte_frame.replace(declaration,
        f'  const localFrame=createLocalFrame({frame_size},retainedLocalBytes);')
    record.update(eligible=True,
        slots=[{'offset': offset, 'size': size, 'kind': json.loads(kind)} for offset, (size, kind) in sorted(slots.items())],
        retainedByteRanges=([{'start': 256, 'end': 264}, {'start': 272, 'end': 280}] if promote_arrays else
            [{'start': base, 'end': base + maximum + width} for (base, _counter), (width, maximum, _case) in dynamic.items()]),
        induction={'iterations': iterations, 'floatStep': 8, 'intStep': 4, 'postTestLimit': 137},
        scalarAccesses=sum('offset' in call for call in selected))
    if promote_arrays:
        record.update(arrays=[{'offset': base, 'size': width, 'kind': json.loads(kind), 'length': 18}
                             for base, (width, kind) in arrays.items()],
                      arrayAccesses=sum('arrayBase' in call for call in selected))
    return promoted + '\n\n' + byte_frame, record


def promote_static_locals(source, name, address, frame_size, numeric_floats=False):
    """Return (generated source, deterministic eligibility record)."""
    if numeric_floats and address == 0x466330 and name == 'originalDrawing00466330Number' and frame_size == 880:
        return _promote_water_private_locals(source, name, address, frame_size)
    if numeric_floats and address == 0x47ed40 and name == 'originalDrawing0047ed40Number' and frame_size == 920:
        from optimize_shore_private_locals import promote_shore_private_locals
        return promote_shore_private_locals(source, name, address, frame_size)
    record = {'address': address, 'function': name, 'frameBytes': frame_size,
              'eligible': False}

    original_source = source
    from expand_local_points import expand_local_points
    source, point_stores = expand_local_points(source, frame_size)

    def reject(reason):
        return original_source, {**record, 'reason': reason}

    declaration = f'  const localFrame=createLocalFrame({frame_size},options.retainedDrawingStack?.[{address}]??[]);'
    if source.count(declaration) != 1:
        return reject('No single recognized frame declaration')
    if re.search(r'\b(?:scalarStack\d+|retainedLocalBytes)\b', _code_mask(source)):
        return reject('Generated scalar identifiers would collide')
    mask = _code_mask(source)
    found = _calls(source, mask)
    if not found:
        return reject('No fixed local accesses')
    slots = {}
    frame_uses = list(mask)
    declaration_at = source.index(declaration)
    frame_uses[declaration_at:declaration_at + len(declaration)] = ' ' * len(declaration)
    for call in found:
        args = call['args']
        if len(args) != (4 if call['kind'] == 'writeLocal' else 3):
            return reject('Access has implicit or unsupported width/kind')
        pointer = re.fullmatch(r'framePointer\(localFrame,(\d+)\)', args[0][2])
        size, kind = args[-2][2], args[-1][2]
        if not pointer or (size, kind) not in [('4', '"int"'), ('8', '"float"')]:
            return reject('Access is not a fixed I32/F64 scalar')
        offset = int(pointer[1])
        signature = (int(size), kind)
        if offset + signature[0] > frame_size:
            return reject('Access exceeds the declared frame')
        if offset in slots and slots[offset] != signature:
            return reject('One slot has multiple views')
        slots[offset] = signature
        call['offset'] = offset
        call['type'] = 'I32' if size == '4' else 'F64'
        begin, end, _pointer = args[0]
        frame_uses[begin:end] = ' ' * (end - begin)
        if call['kind'] == 'writeLocal':
            # writeLocal returns the original value, not its stored coercion.
            # Only a complete emitted statement may discard that return value.
            line_start = source.rfind('\n', 0, call['start']) + 1
            prefix = mask[line_start:call['start']]
            if not re.fullmatch(r'\s*(?:case \d+: \{\s*)?', prefix) or source[call['end']:call['end'] + 1] != ';':
                return reject('Local write result or expression context is observable')
    if re.search(r'\blocalFrame\b', ''.join(frame_uses)):
        return reject('Frame address escapes scalar accesses')
    offsets = sorted(slots)
    if any(first + slots[first][0] > second for first, second in zip(offsets, offsets[1:])):
        return reject('Scalar slots overlap')

    def render(begin, end):
        output = []
        previous = begin
        for call in found:
            if call['start'] < previous or call['start'] < begin or call['end'] > end:
                continue
            output.append(source[previous:call['start']])
            variable = f"scalarStack{call['offset']}"
            if call['kind'] == 'writeLocal':
                value_start, value_end, _value = call['args'][1]
                value = render(value_start, value_end)
                if numeric_floats and call['type'] == 'F64' and value.startswith('fpArgument(') and value.endswith(')'):
                    # A private numeric scalar has no byte-store boundary. Its
                    # dedicated F64 store preserves the same spill semantics.
                    value = value[len('fpArgument('):-1]
                output.append(f"{variable}=scalarStore{call['type']}({value})")
            elif call['kind'] == 'readLocal':
                output.append(f'scalarRead({variable})')
            else:
                output.append(f'scalarReadArgument({variable})' if call['type'] == 'F64' else variable)
            previous = call['end']
        output.append(source[previous:end])
        return ''.join(output)

    promoted = render(0, len(source))
    promoted = promoted.replace(declaration,
        f'  const retainedLocalBytes=options.retainedDrawingStack?.[{address}];\n'
        f'  if(retainedLocalBytes!=null)return {name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes);\n'
        '  let ' + ','.join(f'scalarStack{offset}' for offset in offsets) + ';')
    signature = f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)'
    if source.count(signature) != 1:
        return reject('No single recognized function signature')
    byte_frame = original_source.replace(signature,
        f'function {name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
    byte_frame = byte_frame.replace(declaration,
        f'  const localFrame=createLocalFrame({frame_size},retainedLocalBytes);')
    record.update(eligible=True, slots=[{'offset': offset, 'size': slots[offset][0],
                  'kind': json.loads(slots[offset][1])} for offset in offsets])
    if point_stores:
        record['expandedPointStores'] = point_stores
    return promoted + '\n\n' + byte_frame, record


def write_optimization_report(root, filename, records):
    path = root / 'analysis/scalar-stack-generation.json'
    report = json.loads(path.read_text()) if path.exists() else {
        'format': 1,
        'scope': 'Static drawing generation only; private nonoverlapping fixed I32/F64 slots. Original control flow and arithmetic remain unchanged. Explicit retained bytes use the complete byte frame.',
        'modules': {}}
    report['modules'][filename] = records
    report['modules'] = dict(sorted(report['modules'].items()))
    report['eligibleFunctions'] = sum(row['eligible'] for rows in report['modules'].values() for row in rows)
    report['functions'] = sum(len(rows) for rows in report['modules'].values())
    path.write_text(json.dumps(report, indent=2) + '\n')
