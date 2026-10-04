"""Cache one private, unchanged F64 view in the closed water arithmetic slab.

The first read stays at its original expression/evaluation point. The complete
212->172 single-entry chain has no other frame access and cannot change the
view. The complete reviewed private body is pinned: the prefix alone would not
rule out a later frame escape before entry to the chain. Any statement change,
including a callback without an explicit frame argument, requires a new review.
"""
import hashlib
import re
from optimize_static_locals import _calls, _code_mask

NAME = 'originalDrawing00466330Number'
PREFIX_SHA256 = '4df3ae5b2ef13f139f423596582c8fb0b4c9bf0a4b3c86b65c5ddf6d03553b85'
BODY_SHA256 = '52473853aedeb9a49cf2c0de9d3ffb232447888f95274301f392cb0f1759f52f'
LOAD = 'readLocalFloatNumber(framePointer(localFrame,272))'


def cache_water_float_loads(source, name, address):
    report = {'eligible': False, 'address': address}
    def decline(reason):
        return source, {**report, 'reason': reason}
    if name != NAME or address != 0x466330:
        return decline('Unreviewed water function')
    mask = _code_mask(source)
    start = mask.find(f'function {NAME}(')
    opening = mask.find('{', start)
    if start < 0 or opening < 0:
        return decline('Private water function missing')
    end, depth = opening + 1, 1
    while end < len(mask) and depth:
        depth += (mask[end] == '{') - (mask[end] == '}')
        end += 1
    if depth:
        return decline('Unbalanced water function')
    body = source[start:end]
    if hashlib.sha256(body.encode()).hexdigest() != BODY_SHA256:
        return decline('Reviewed complete private water body changed')
    marker = body.find('  let pc = 278;\n')
    if marker < 0 or hashlib.sha256(body[:marker].encode()).hexdigest() != PREFIX_SHA256:
        return decline('Reviewed private-frame prefix changed')
    if re.search(r'\b(?:waterFloat272|eval|with)\b', _code_mask(body)):
        return decline('Private cache identifier or lexical scope changed')
    rows = list(re.finditer(r'^    case (\d+): \{ (.*) \}\n', body, re.M))
    cases = {int(row[1]): row for row in rows}
    if len(rows) != 279 or sorted(cases) != list(range(279)):
        return decline('Water case labels changed')
    window = set(range(172, 213))
    for index in window:
        code = cases[index][2]
        tail = f'pc = {index - 1}; continue;'
        if not code.endswith(tail) or re.search(r'\b(?:pc|return|throw|break|continue)\b', _code_mask(code[:-len(tail)])):
            return decline('Water slab is not an uninterrupted chain')
    incoming = set()
    for index, row in cases.items():
        code = _code_mask(row[2])
        branch = re.search(r'pc = .* \? (\d+) : (\d+); continue;$', code)
        jump = re.search(r'pc = (\d+); continue;$', code)
        if branch:
            targets = [int(branch[1]), int(branch[2])]
        elif jump:
            targets = [int(jump[1])]
        elif re.match(r'^return(?:\s|;)', code):
            targets = []
        else:
            return decline('Unreviewed water control transfer')
        incoming.update((index, target) for target in targets if index not in window and target in window)
    if incoming != {(213, 212)}:
        return decline('Water slab can bypass its first load')
    selected = []
    for index in sorted(window, reverse=True):
        row = cases[index]
        code = row[2]
        code_mask = _code_mask(code)
        frame_uses = list(code_mask)
        calls = _calls(code, code_mask, names=('readLocalFloatNumber',))
        if calls is None:
            return decline('Unrecognized water floating read')
        for call in calls:
            if len(call['args']) != 1 or call['args'][0][2] != 'framePointer(localFrame,272)':
                return decline('Water slab gained another floating frame view')
            begin, finish, _pointer = call['args'][0]
            frame_uses[begin:finish] = ' ' * (finish - begin)
            selected.append((row.start(2) + call['start'], row.start(2) + call['end'], index))
        if re.search(r'\blocalFrame\b', ''.join(frame_uses)):
            return decline('Water slab can change or expose its frame')
    if len(selected) != 22 or sum(index == 212 for _, _, index in selected) != 1:
        return decline('Reviewed water load count/first read changed')
    replacements = [(begin, finish, f'(waterFloat272={LOAD})' if index == 212 else 'waterFloat272')
                    for begin, finish, index in selected]
    candidate = body
    for begin, finish, replacement in sorted(replacements, reverse=True):
        candidate = candidate[:begin] + replacement + candidate[finish:]
    candidate = candidate.replace('  let pc = 278;\n', '  let waterFloat272;\n  let pc = 278;\n', 1)
    report.update(eligible=True, entry=212, successor=171, offset=272, bytes=8,
                  originalLoads=22, retainedLoads=1,
                  prefixSha256=PREFIX_SHA256,
                  privateBodySha256=BODY_SHA256,
                  windowSha256=hashlib.sha256(''.join(cases[index][0] for index in sorted(window)).encode()).hexdigest())
    return source[:start] + candidate + source[end:], report
