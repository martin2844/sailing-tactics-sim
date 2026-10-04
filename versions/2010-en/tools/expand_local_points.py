"""Expose the two ordered DWORD stores of a fixed private POINT assignment.

Only a complete writeLocalPoint statement with an in-bounds constant frame
offset is expanded. The existing scalar pass must still prove that every frame
address is private and every slot is disjoint; otherwise it returns the complete
original byte implementation. The discarded helper return is never substituted
in an expression. Its point expression and x/y getters retain their order.
"""
import re
from optimize_static_locals import _code_mask, _calls


def expand_local_points(source, frame_size):
    mask = _code_mask(source)
    if re.search(r'\bscalarPointValue\d+\b', mask):
        return source, 0
    calls = _calls(source, mask, names=('writeLocalPoint',))
    if calls is None:
        return source, 0
    replacements = []
    for call in calls:
        if len(call['args']) != 2:
            continue
        pointer, value = call['args']
        match = re.fullmatch(r'framePointer\(localFrame,(\d+)\)', pointer[2])
        if not match or int(match[1]) + 8 > frame_size:
            continue
        start = source.rfind('\n', 0, call['start']) + 1
        prefix = mask[start:call['start']]
        if (not re.fullmatch(r'\s*(?:case \d+: \{\s*)?', prefix)
                or source[call['end']:call['end'] + 1] != ';'):
            continue
        offset = int(match[1])
        temporary = f'scalarPointValue{len(replacements)}'
        replacement = ('{\n'
            f'      const {temporary}={value[2]};\n'
            f'      writeLocal(framePointer(localFrame,{offset}),{temporary}.x,4,"int");\n'
            f'      writeLocal(framePointer(localFrame,{offset + 4}),{temporary}.y,4,"int");\n'
            '    }')
        replacements.append((call['start'], call['end'] + 1, replacement))
    for start, end, replacement in reversed(replacements):
        source = source[:start] + replacement + source[end:]
    return source, len(replacements)
