"""Remove identity truth conversions only from private Boolean expressions.

This pass knows the fixed return contracts of the imported comparison/truth
helpers. It never infers a Boolean from a C integer, a callback or a local's
name/type. Parentheses remain in place, so operator precedence and every
short-circuit/effect prefix are unchanged. Original and byte bodies stay intact.
"""
import re
from optimize_static_locals import _code_mask, _calls

BOOLEAN_HELPERS = ('cCompare', 'fpCompare', 'cTruth', 'fpTruth')


def _top_level_parts(expression, operator):
    stack, positions = [], []
    pairs = {')': '(', ']': '[', '}': '{'}
    at = 0
    while at < len(expression):
        char = expression[at]
        if char in '([{':
            stack.append(char)
        elif char in ')]}':
            if not stack or stack.pop() != pairs[char]:
                return None
        elif not stack and expression.startswith(operator, at):
            positions.append(at)
            at += len(operator) - 1
        at += 1
    if stack:
        return None
    if not positions:
        return [expression]
    parts, previous = [], 0
    for position in positions:
        parts.append(expression[previous:position])
        previous = position + len(operator)
    parts.append(expression[previous:])
    return parts


def is_boolean_expression(expression):
    """Prove a complete, already valid generated JS expression returns bool."""
    expression = _code_mask(expression).strip()
    if not expression:
        return False
    # The comma operator has the lowest precedence. Earlier expressions retain
    # all their effects; only the last result controls the Boolean proof.
    parts = _top_level_parts(expression, ',')
    if parts is None:
        return False
    if len(parts) > 1:
        return all(part.strip() for part in parts) and is_boolean_expression(parts[-1])
    for operator in ('||', '&&'):
        parts = _top_level_parts(expression, operator)
        if parts is None:
            return False
        if len(parts) > 1:
            return all(is_boolean_expression(part) for part in parts)
    if expression.startswith('('):
        depth, closing = 0, None
        for index, char in enumerate(expression):
            depth += (char == '(') - (char == ')')
            if depth == 0:
                closing = index
                break
        if closing == len(expression) - 1:
            return is_boolean_expression(expression[1:-1])
    if expression in ('true', 'false'):
        return True
    if expression.startswith('!') and not expression.startswith('!='):
        return is_boolean_expression(expression[1:])
    calls = _calls(expression, expression, names=BOOLEAN_HELPERS)
    return bool(calls and calls[0]['start'] == 0 and calls[0]['end'] == len(expression))


def eliminate_number_boolean_truth(source, name, address):
    record = {'address': address, 'function': name, 'eligible': False,
              'removedConversions': 0}

    def decline(reason):
        return source, {**record, 'reason': reason}

    mask = _code_mask(source)
    signature = re.compile(r'\bfunction ' + re.escape(name) + r'\([^\n]*\) \{')
    matches = list(signature.finditer(mask))
    if not name.endswith('Number') or len(matches) != 1:
        return decline('One private Number function is required')
    opening, depth = matches[0].end() - 1, 1
    end = opening + 1
    while end < len(mask) and depth:
        depth += (mask[end] == '{') - (mask[end] == '}')
        end += 1
    if depth:
        return decline('Unbalanced private function body')
    private_mask = mask[matches[0].start():end]
    if re.search(r'\b(?:eval|with)\b', private_mask):
        return decline('Dynamic lexical scope is unsupported')
    # Only the imported bare helper bindings are covered. A declaration,
    # parameter, assignment, value reference or property method is not proof of
    # the imported helper's return contract.
    for match in re.finditer(r'\b(?:' + '|'.join(BOOLEAN_HELPERS) + r')\b', private_mask):
        before, after = private_mask[:match.start()].rstrip(), private_mask[match.end():].lstrip()
        if (not after.startswith('(') or before.endswith('.')
                or re.search(r'\b(?:function|class|const|let|var)\s*$', before)):
            return decline('Boolean helper binding is not the fixed imported call')
    body = source[opening + 1:end - 1]
    body_mask = mask[opening + 1:end - 1]
    calls = _calls(body, body_mask, names=('cTruth',))
    if calls is None:
        return decline('Unbalanced truth conversion')
    offsets = [opening + 1 + call['start'] for call in calls
               if len(call['args']) == 1 and is_boolean_expression(call['args'][0][2])]
    for offset in reversed(offsets):
        source = source[:offset] + source[offset + len('cTruth'):]
    record.update(eligible=bool(offsets), removedConversions=len(offsets))
    return source, record
