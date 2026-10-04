#!/usr/bin/env python3
"""Reproduce the scalar-slot safety audit and focused native/fallback tests."""
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

EDITION = Path(__file__).resolve().parents[2]
ROOT = EDITION.parents[1]
sys.path.insert(0, str(EDITION / 'tools'))
from optimize_static_locals import _code_mask

REFERENCE = 'fb856db76104e87ce63294aa9f7f71f2f5658b18'


def functions(source):
    mask = _code_mask(source)
    result = {}
    for match in re.finditer(r'(?:export )?function (\w+)\([^\n]+\) \{', mask):
        at = match.end()
        depth = 1
        while depth:
            if mask[at] == '{':
                depth += 1
            elif mask[at] == '}':
                depth -= 1
            at += 1
        result[match[1]] = source[match.start():at]
    return result


def run(command):
    completed = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    output = completed.stdout + completed.stderr
    if completed.returncode:
        sys.stderr.write(output)
        raise SystemExit(completed.returncode)
    return output


def main():
    generation = json.loads((EDITION / 'analysis/scalar-stack-generation.json').read_text())
    numeric = json.loads((EDITION / 'analysis/floating-drawing-generation.json').read_text())
    modules = []
    for filename, rows in generation['modules'].items():
        path = 'versions/2010-en/src/render/' + filename
        original = functions(run(['git', 'show', REFERENCE + ':' + path]))
        source = (ROOT / path).read_text()
        current = functions(source)
        numeric_rows = {row['function']: row for row in numeric['modules'][filename]}
        fallback_names = []
        for row in rows:
            name = row['function']
            expected = original[name]
            if row['eligible']:
                expected = expected.replace(
                    f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)',
                    f'function {name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)', 1)
                expected = expected.replace(
                    f"createLocalFrame({row['frameBytes']},options.retainedDrawingStack?.[{row['address']}]??[])",
                    f"createLocalFrame({row['frameBytes']},retainedLocalBytes)")
                actual = current[name + 'ByteFrame']
            else:
                fallback_name = name + 'Original' if numeric_rows[name]['eligible'] else name
                if fallback_name != name:
                    expected = expected.replace(
                        f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)',
                        f'function {fallback_name}(memory, dc, rng, options = {{}}, ...originalArgs)', 1)
                actual = current[fallback_name]
                fallback_names.append(fallback_name)
            if expected != actual:
                raise AssertionError(f'Byte-frame source changed: {path}:{name}')
        modules.append({'module': filename, 'routines': len(rows),
                        'promoted': sum(row['eligible'] for row in rows),
                        'numberVariants': sum(row['eligible'] for row in numeric_rows.values()),
                        'unpromotedFallbackNames': fallback_names,
                        'sha256': hashlib.sha256(source.encode()).hexdigest()})

    python_command = [sys.executable, 'versions/2010-en/tools/test_optimize_static_locals.py']
    python_output = run(python_command)
    python_tests = int(re.search(r'Ran (\d+) tests', python_output)[1])
    node_command = ['node', '--test', '--test-reporter=tap', '--test-concurrency=1',
                    *['versions/2010-en/tests/' + name for name in [
                        'scalar-stack.test.js', 'scalar-drawing.test.js',
                        'drawing-types.test.js', 'closed-drawing.test.js',
                        'initialized-venue-render.test.js']]]
    node_output = run(node_command)
    node_summary = {field: int(re.search(r'^# ' + field + r' (\d+)$', node_output, re.M)[1])
                    for field in ['tests', 'pass', 'fail']}
    if node_summary['tests'] != node_summary['pass'] or node_summary['fail']:
        raise AssertionError('Some focused scalar checks did not pass')
    elapsed = float(re.search(r'^# duration_ms ([\d.]+)$', node_output, re.M)[1])
    captures = sum(len(json.loads((EDITION / 'tests/fixtures' / name).read_text())['cases'])
                   for name in ['original-tutorial-2.json', 'original-drawing-advice.json'])
    pins = [EDITION / name for name in ['tools/optimize_static_locals.py',
            'src/render/scalar-stack.js', 'tools/translate_drawing.py',
            'tools/translate_drawing_closure.py', 'tools/test_optimize_static_locals.py',
            'tools/diagnostics/check-scalar-stack.py', 'tools/floating_drawing.py', 'tests/scalar-stack.test.js',
            'tests/scalar-drawing.test.js']]
    report = {
        'format': 1,
        'scope': 'Supplementary scalar-stack optimization verification against the committed byte-frame implementation; this does not add new native captures. Existing native expectations and recovered C are unchanged.',
        'referenceCommit': REFERENCE,
        'byteFrameFunctionsExactlyPreserved': sum(row['routines'] for row in modules),
        'eligibleFunctions': generation['eligibleFunctions'], 'modules': modules,
        'numberVariantsWithOriginalByteFallback': numeric['eligibleFunctions'],
        'generatorBoundaryTests': {'command': ' '.join(python_command), 'passed': python_tests,
                                   'explicitRejectedCases': 15},
        'nodeFocusedChecks': {'command': ' '.join(node_command), 'tests': node_summary['tests'],
                              'passed': node_summary['pass'], 'failed': node_summary['fail'],
                              'elapsedMs': elapsed, 'forcedFallbackNativeCaptures': captures,
                              'forcedFallbackAndScalarExecutions': captures * 2},
        'sourcePins': [{'file': path.relative_to(ROOT).as_posix(),
                       'sha256': hashlib.sha256(path.read_bytes()).hexdigest()} for path in pins],
    }
    destination = EDITION / 'analysis/scalar-stack-validation.json'
    destination.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'byteFrameFunctionsExactlyPreserved': report['byteFrameFunctionsExactlyPreserved'],
                      'eligibleFunctions': report['eligibleFunctions'],
                      'generatorTests': python_tests, 'nodeChecks': node_summary,
                      'report': destination.relative_to(ROOT).as_posix()}, indent=2))


if __name__ == '__main__':
    main()
