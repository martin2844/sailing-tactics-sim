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


def _calls(source, mask):
    result = []
    for match in re.finditer(r'\b(readLocalArgument|readLocal|writeLocal)\(', mask):
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


def promote_static_locals(source, name, address, frame_size):
    """Return (generated source, deterministic eligibility record)."""
    record = {'address': address, 'function': name, 'frameBytes': frame_size,
              'eligible': False}

    def reject(reason):
        return source, {**record, 'reason': reason}

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
    byte_frame = source.replace(signature,
        f'function {name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
    byte_frame = byte_frame.replace(declaration,
        f'  const localFrame=createLocalFrame({frame_size},retainedLocalBytes);')
    record.update(eligible=True, slots=[{'offset': offset, 'size': slots[offset][0],
                  'kind': json.loads(slots[offset][1])} for offset in offsets])
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
