"""Build a staged binary64 kernel from the pinned private water expressions.

Every accepted operation is exactly the existing nearest53 native fast path.
The expression parser preserves its binary tree and left-to-right evaluation;
each result has a certificate before use. No frame, memory or array store occurs
until all results pass. A rejected speculative calculation therefore leaves the
original 208->172 chain as the complete fallback.
"""
import hashlib
import re
from cache_water_float_loads import cache_water_float_loads, NAME, BODY_SHA256
from optimize_static_locals import _calls, _code_mask

ARGUMENTS = ('scalarStack4', 'scalarStack12', 'scalarStack264', 'scalarStack552', 'waterFloat272',
             'dVar1', 'dVar2', 'dVar3', 'dVar5', 'dVar6', 'dVar7', 'dVar8', 'dVar9',
             'dVar10', 'dVar11', 'dVar12', 'dVar13', 'dVar14',
             'scalarArray728[0]', 'scalarArray728[6]', 'scalarArray568[6]')
PARAMETERS = tuple('waterInput' + str(index) for index in range(len(ARGUMENTS)))
CONSTANTS = (0x4cc5c8, 0x4cc7b0, 0x4cc700, 0x4cc618)
IDENTITY = ('fpScalarRead', 'scalarArrayF64Read', 'fpScalarStoreF64', 'scalarArrayF64Store', 'fpLoad', 'fpToNumber')
OPERATIONS = {'fpAdd': '+', 'fpSub': '-', 'fpMul': '*'}


def build_water_number_slab(source):
    report = {'eligible': False, 'privateBodySha256': BODY_SHA256}
    cached, cache = cache_water_float_loads(source, NAME, 0x466330)
    if not cache['eligible']:
        return None, {**report, 'reason': cache['reason']}
    body = re.search(r'function ' + NAME + r'\([^\n]*\) \{[\s\S]*?\n\}', cached)[0]
    cases = {int(row[1]): row[2] for row in re.finditer(r'^    case (\d+): \{ (.*) \}\n', body, re.M)}
    environment = dict(zip(ARGUMENTS, PARAMETERS))
    lines, operations, reads = [], [], []

    def value(expression):
        expression = expression.strip()
        if expression in environment:
            return environment[expression]
        calls = _calls(expression, _code_mask(expression), names=(*IDENTITY, *OPERATIONS, 'r64'))
        if not calls or calls[0]['start'] != 0 or calls[0]['end'] != len(expression):
            raise ValueError('Unreviewed water expression: ' + expression)
        call = calls[0]
        args = [row[2] for row in call['args']]
        if call['kind'] in IDENTITY and len(args) == 1:
            return value(args[0])
        if call['kind'] == 'r64' and len(args) == 1:
            address = int(args[0], 16)
            if address not in CONSTANTS:
                raise ValueError('Unreviewed water memory address')
            reads.append(address)
            return 'waterConstant' + str(CONSTANTS.index(address))
        if call['kind'] not in OPERATIONS or len(args) != 2:
            raise ValueError('Unreviewed water operation')
        # Recurse in original JS argument order. Never distribute, reassociate
        # or reuse repeated arithmetic, even when its operands happen to match.
        left, right = value(args[0]), value(args[1])
        result = 'waterResult' + str(len(operations))
        operation = OPERATIONS[call['kind']]
        lines.append(f'  const {result}={left}{operation}{right};')
        zero = (f'{left}===-{right}' if operation == '+' else f'{left}==={right}' if operation == '-'
                else f'({left}===0||{right}===0)')
        # Strictly above the smallest normal avoids the binary64 underflow
        # boundary, where x87 arithmetic followed by a spill can double round.
        # All remaining nonzero results are normal and within binary64 range;
        # x87 PC53 and JS therefore round the same exact rational once. Zero is
        # accepted only for exact cancellation or an actual zero factor.
        lines.append(f'  if(!(Number.isFinite({result})&&Math.abs({result})>minimumNormal'
                     f'||{result}===0&&{zero}))return undefined;')
        operations.append({'operator': operation, 'left': left, 'right': right, 'result': result})
        return result

    try:
        for index in range(208, 171, -1):
            tail = f' pc = {index - 1}; continue;'
            if not cases[index].endswith(tail):
                raise ValueError('Unreviewed water kernel successor')
            statement = cases[index][:-len(tail)]
            if statement in ('(iVar16 = 0);', '(iVar24 = 0);'):
                continue
            assignment = re.fullmatch(r'(scalarArray(?:568|728)\[\d+\]|scalarStack264)=(.*);', statement)
            if not assignment:
                raise ValueError('Unreviewed water assignment')
            environment[assignment[1]] = value(assignment[2])
        outputs = [environment[f'scalarArray{array}[{index}]'] for array in (568, 728) for index in range(18)]
        outputs.append(environment['scalarStack264'])
    except (ValueError, KeyError) as error:
        return None, {**report, 'reason': str(error)}
    header = [
        '// Generated from the pinned 0x466330 private Number body; see water_number_slab.py.',
        "import {waterNumberMemoryEnabled} from './water-number-domain.js';",
        'const minimumNormal=2**-1022;',
        '// No callback occurs before the caller copies this private scratch.',
        'const waterOutput=new Float64Array(37);',
        'export function tryWaterNumberSlab(memory,' + ','.join(PARAMETERS) + '){',
        '  if(waterOutput[0]===undefined)return undefined;',
        '  if(!waterNumberMemoryEnabled(memory))return undefined;',
        '  if(' + '||'.join('!Number.isFinite(' + parameter + ')' for parameter in PARAMETERS) + ')return undefined;',
    ]
    for index, address in enumerate(CONSTANTS):
        header.append(f'  const waterConstant{index}=memory.readF64({hex(address)});')
    header.append('  if(' + '||'.join(f'!Number.isFinite(waterConstant{index})' for index in range(len(CONSTANTS))) + ')return undefined;')
    commits = [f'  waterOutput[{index}]={output};' for index, output in enumerate(outputs)]
    code = '\n'.join(header + lines + commits + ['  return waterOutput;', '}', ''])
    report.update(eligible=True, entry=208, successor=171, arithmeticOperations=len(operations),
                  originalMemoryReads=len(reads), retainedMemoryReads=len(CONSTANTS), outputs=len(outputs),
                  windowSha256=hashlib.sha256(''.join(cases[index] for index in range(208,171,-1)).encode()).hexdigest(),
                  kernelSha256=hashlib.sha256(code.encode()).hexdigest(),
                  operations=operations)
    return code, report


def install_water_number_slab(original, cached, name, address):
    """Enter the staged kernel only at the original 208 successor boundary."""
    if name != NAME or address != 0x466330:
        return cached, {'eligible': False, 'reason': 'Unreviewed water function'}, None
    expected, cache = cache_water_float_loads(original, name, address)
    if not cache['eligible'] or expected != cached:
        return cached, {'eligible': False, 'reason': 'Reviewed cache pipeline changed'}, None
    kernel, report = build_water_number_slab(original)
    if not report['eligible']:
        return cached, report, None
    begin = cached.index('function ' + NAME + '(')
    end = cached.index('\n}', begin) + 2
    body = cached[begin:end]
    marker = '    case 208: { '
    if body.count(marker) != 1:
        return cached, {'eligible': False, 'reason': 'Reviewed slab entry changed'}, None
    commits = ' '.join(f'scalarArray{array}[{index}]=waterSlab[{base+index}];'
                       for array, base in ((568, 0), (728, 18)) for index in range(18))
    entry = (marker + 'const waterSlab=tryWaterNumberSlab(memory,' + ','.join(ARGUMENTS) + '); '
             'if(waterSlab!==undefined){' + commits +
             ' scalarStack264=waterSlab[36]; iVar16=0; iVar24=0; pc=171; continue;} ')
    body = body.replace(marker, entry, 1)
    return cached[:begin] + body + cached[end:], {key: value for key, value in report.items() if key != 'operations'}, kernel
