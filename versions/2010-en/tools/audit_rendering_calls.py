#!/usr/bin/env python3
"""Report recovered drawing call argument discrepancies for assembly review.

This does not infer or repair ABI contracts. A difference can be an unused
register parameter, an unmerged packed double, or a genuinely missing argument.
Only original caller/callee instruction evidence can establish which applies.
"""
import hashlib
import json
from pathlib import Path

from translate_drawing import ROOT, Translator, base_type
from pycparser import c_ast


def main():
    entries = {}
    for name in ('rendering-closure', 'drawing-translation-sources',
                 'screen-translation-sources', 'screen-helper-translation-sources'):
        for row in json.loads((ROOT / 'analysis' / (name + '.json')).read_text())['sources']:
            address = row['address']
            address = int(address, 16) if isinstance(address, str) else address
            entries[address] = row
    functions = {}
    sources = []
    for address, row in sorted(entries.items()):
        path = ROOT / row['source']
        source = path.read_text()
        translator = Translator(str(address), address, source, has_dc=row.get('hasDc', True))
        parameters = [base_type(parameter.type) for parameter in
                      (translator.function.decl.type.args.params if translator.function.decl.type.args else [])]
        if parameters == ['void']:
            parameters = []
        functions[address] = (translator, parameters)
        sources.append({'address': hex(address), 'path': row['source'],
                        'sha256': hashlib.sha256(path.read_bytes()).hexdigest()})
    issues = []

    class Visitor(c_ast.NodeVisitor):
        def __init__(self, caller):
            self.caller = caller

        def visit_FuncCall(self, node):
            if isinstance(node.name, c_ast.ID) and node.name.name.startswith('FUN_'):
                address = int(node.name.name[4:], 16)
                if address in functions:
                    parameters = functions[address][1]
                    actual = len(node.args.exprs) if node.args else 0
                    if len(parameters) != actual:
                        issues.append({'caller': hex(self.caller), 'callee': hex(address),
                                       'calleeRecoveredTypes': parameters,
                                       'calleeArgumentCount': len(parameters),
                                       'callerExpressionCount': actual,
                                       'parsedCoordinate': str(node.coord)})
            self.generic_visit(node)

    for address, (translator, _) in sorted(functions.items()):
        Visitor(address).visit(translator.function)
    report = {'format': 1, 'sourceSha256':
              'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787',
              'scope': 'Static source discrepancy triage, not a correctness or ABI proof. '
                       'Review unchanged original instructions before changing contracts.',
              'reviewedFunctions': len(functions), 'sources': sources,
              'discrepantCallsites': len(issues),
              'calleeTargets': sorted(set(row['callee'] for row in issues)), 'calls': issues}
    destination = ROOT / 'analysis' / 'rendering-call-argument-audit.json'
    destination.write_text(json.dumps(report, indent=2) + '\n')
    print(f'{len(issues)} source discrepancies at {len(report["calleeTargets"])} targets; assembly review required')


if __name__ == '__main__':
    main()
