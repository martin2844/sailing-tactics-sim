"""Fuse reviewed, closed 468440 Number CFG windows with integer certificates.

The untouched states are retained as the decline path. A case-table pin makes
the def/use and entry-edge proof fail closed if the recovered function changes.
"""
from __future__ import annotations

import hashlib
import re

CASE_TABLE_SHA256 = '697bfce630b29a4aca69903158e73712f1da33a9ed22745666b3b12fa25675c4'
PREFIX_SHA256 = '625a80c189b5aecd83053d048ba0b696056d2e8f9e76a0775fb5dd8c4292efc2'
NAME = 'originalDrawing00468440Number'
SCALE_STORE = '  writeLocalFloatNumber(framePointer(localFrame,20),fpFormalF64(numberArg4,numberArgumentImages));\n'


def fuse_chart_windows(source: str, name: str, address: int):
    unchanged = source
    report = {'eligible': False, 'address': address}
    if name != NAME or address != 0x468440:
        return source, report
    start = source.find(f'function {NAME}(')
    stop = source.find('    case 0:', start)
    if start < 0 or stop < 0 or hashlib.sha256(source[start:stop].encode()).hexdigest() != PREFIX_SHA256:
        return source, {**report, 'reason': 'Reviewed chart prefix/formal bindings changed'}
    cases = {int(match.group(1)): match.group(0) for match in
             re.finditer(r'^    case (\d+): \{ .* \}\n', source, re.M)}
    lines = ''.join(cases.values())
    if len(cases) != 302 or hashlib.sha256(lines.encode()).hexdigest() != CASE_TABLE_SHA256:
        return source, {**report, 'reason': 'Reviewed chart case-table changed'}
    if source.count(SCALE_STORE) != 1 or 'createLocalFrame(320,options.retainedDrawingStack?.[4621376]??[])' not in source:
        return source, {**report, 'reason': 'Reviewed chart formal/frame layout changed'}
    if 'numberArg9)' not in source or source.count('  let pc = 301;\n') != 1:
        return source, {**report, 'reason': 'Reviewed chart signature/entry changed'}

    edges = {}
    for state, line in cases.items():
        branch = re.search(r'pc = .* \? (\d+) : (\d+); continue;', line)
        jump = re.search(r'pc = (\d+); continue;', line)
        if branch:
            edges[state] = [int(branch.group(1)), int(branch.group(2))]
        elif jump:
            edges[state] = [int(jump.group(1))]
        elif 'return;' in line:
            edges[state] = []
        else:
            return source, {**report, 'reason': 'Unsupported chart CFG edge'}
    windows = [(set(range(267, 285)), 284, 266), (set(range(245, 264)), 263, 244)]
    for states, entry, successor in windows:
        incoming = {(state, target) for state, targets in edges.items() if state not in states
                    for target in targets if target in states}
        outgoing = {target for state in states for target in edges[state] if target not in states}
        if {target for _, target in incoming} != {entry} or outgoing != {successor}:
            return source, {**report, 'reason': 'Chart projection window is not closed'}
    states = windows[0][0] | windows[1][0]
    outside_fp = {state for state, line in cases.items() if state not in states
                  and re.search(r'\bfVar[89]\b', line)}
    outside_slot = {state for state, line in cases.items() if state not in states
                    and re.search(r'framePointer\(localFrame,27[26]\)', line)}
    if outside_fp != {242, 243} or outside_slot != {63, 68}:
        return source, {**report, 'reason': 'Chart floating temporary gained an observer'}

    source = source.replace(SCALE_STORE,
        '  const chartScaleImage=fpFormalF64(numberArg4,numberArgumentImages);\n'
        '  writeLocalFloatNumber(framePointer(localFrame,20),chartScaleImage);\n'
        '  let chartColumnHighAbsent=false;\n', 1)
    common = ('chartArguments[0],chartArguments[1],chartArguments[2],chartArguments[3],'
              'chartScaleImage,numberArg2===0?0:numberArg2,numberArg3===0?0:numberArg3')
    for entry, successor, clamped in [(284, 266, False), (263, 244, True)]:
        original = cases[entry]
        call = re.fullmatch(r'    case \d+: \{ \(fVar8 = callNumberDrawingDependencyOwned\(memory,dc,0x43ec20,(\[.*\]),3,rng,options\)\); pc = (\d+); continue; \}\n', original)
        if call is None:
            return unchanged, {**report, 'reason': 'Chart projection dependency call changed'}
        first_stores = (
            'writeLocalFloatNumber(framePointer(localFrame,280),numberArg2===0?0:numberArg2);'
            'writeLocalFloatNumber(framePointer(localFrame,288),numberArg3===0?0:numberArg3);'
            'TStack_38=BigInt(chartPoint.x);TStack_34=BigInt(chartPoint.y);'
        )
        loop_stores = (
            'iVar3=chartPoint.x;fVar8=chartPoint.y;chartColumnHighAbsent=true;'
            'writeLocal(framePointer(localFrame,272),iVar3,4,"int");'
        )
        replacement = (
            f'    case {entry}: {{ const chartArguments={call.group(1)}; '
            'const chartPoint=originalNumberDrawingIsCurrent(0x43ec20)?'
            f'tryProjectChartPointOutputFast(memory,{common},{str(clamped).lower()},options):undefined; '
            f'if(chartPoint!==undefined){{{loop_stores if clamped else first_stores}pc={successor};continue;}} '
            + ('chartColumnHighAbsent=false; ' if clamped else '')
            + f'(fVar8 = callNumberDrawingDependencyOwned(memory,dc,0x43ec20,chartArguments,3,rng,options)); '
            + f'pc = {call.group(2)}; continue; }}\n'
        )
        source = source.replace(original, replacement, 1)
    later = cases[68]
    original_store = later[len('    case 68: { '):].split('; pc = 67; continue; }')[0]
    source = source.replace(later,
        '    case 68: { if(chartColumnHighAbsent){writeLocal(framePointer(localFrame,272),r32(0x4fca90),4,"int");}'
        f'else{{{original_store};}} pc = 67; continue; }}\n', 1)
    report.update(eligible=True, caseTableSha256=CASE_TABLE_SHA256, prefixSha256=PREFIX_SHA256,
                  windows=[{'entry': 284, 'successor': 266}, {'entry': 263, 'successor': 244}],
                  deadFloatingTemporary={'offset': 272, 'bytes': 8, 'remainingLowWordConsumer': 63,
                                         'conditionalLowWordReplacement': 68},
                  safeFormalCapture={'floatScaleArgument': 4, 'integerCenters': [2, 3]},
                  dependencyIdentityGuard='0x43ec20')
    return source, report
