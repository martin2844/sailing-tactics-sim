#!/usr/bin/env python3
"""Translate the small recovered original menu handlers into static ES modules.

This deliberately accepts only the audited expression/statement subset used by
these handlers. An unfamiliar statement fails generation. Outputs are ordinary
JS functions; there is no runtime C evaluation or JavaScript eval.
"""
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FLOAT_GLOBALS = {0x4a78e8, 0x484d58, 0x484d60}


def menu_entries():
    menus = json.loads((ROOT / 'assets/ui/menus.json').read_text())
    def flatten(items):
        for item in items:
            if item.get('items'): yield from flatten(item['items'])
            elif item.get('command_id'): yield item['command_id'], item['text']
    labels = dict(flatten(menus[0]['items']))
    maps = json.loads((ROOT / 'analysis/message-map-candidates.json').read_text())
    entries = {}
    for table in maps['tables']:
        for row in table['entries']:
            command, code = row['nID'], row['nCode']
            if row['nMessage'] != 273 or command not in labels or code not in (0, 0xffffffff): continue
            entries.setdefault((command, code), {'commandId': command, 'code': code,
                'address': int(row['functionVA'], 16), 'label': labels[command]})
    return list(entries.values())


class Expressions:
    priority = {',': 0, '=': 1, '||': 2, '&&': 3, '|': 4, '^': 5, '&': 6, '==': 7, '!=': 7,
        '<': 8, '>': 8, '<=': 8, '>=': 8, '+': 9, '-': 9, '*': 10, '/': 10}
    def __init__(self, text):
        text = re.sub(r'\((?:uint|int|undefined4)\)', '', text)
        self.tokens = re.findall(r'_?DAT_[0-9a-f]{8}|0x[0-9a-f]+|\d+|[A-Za-z_]\w*|==|!=|<=|>=|&&|\|\||[^\s]', text)
        self.at = 0
    def take(self):
        token = self.tokens[self.at]; self.at += 1; return token
    def expression(self, minimum=0):
        token = self.take()
        if token == '(':
            result, floating = self.expression()
            if self.take() != ')': raise ValueError('Unclosed expression')
        elif token in ('-', '!'):
            value, floating = self.expression(11)
            result = f'{value}.negate()' if token == '-' and floating else f'sub32(0, {value})' if token == '-' else f'Number(!({value}))'
            if token == '!': floating = False
        elif re.fullmatch(r'_?DAT_[0-9a-f]{8}', token):
            address = int(token[-8:], 16); floating = address in FLOAT_GLOBALS
            result = f'f(0x{address:x})' if floating else f'r(0x{address:x})'
        elif re.fullmatch(r'0x[0-9a-f]+|\d+', token):
            result, floating = f'i32({token})', False
        elif token in ('bVar1', 'uVar1', 'uVar2', 'hWnd'):
            result, floating = token, False
        elif token == 'windowHandle': result, floating = 'options.windowHandle ?? 0', False
        else: raise ValueError(f'Unknown expression atom {token}')
        while self.at < len(self.tokens) and self.priority.get(self.tokens[self.at], -1) >= minimum:
            operator = self.take(); right, right_float = self.expression(self.priority[operator] + (0 if operator == '=' else 1))
            if operator == '=':
                if result not in ('uVar1', 'uVar2', 'bVar1'): raise ValueError('Only local assignment expressions are supported')
                result = f'({result} = {right})'; floating = right_float
            elif operator == ',':
                result = f'({result}, {right})'; floating = right_float
            elif operator in ('+', '-', '*', '/'):
                if floating or right_float:
                    if not floating: result = f'Float80.fromInteger({result})'
                    if not right_float: right = f'Float80.fromInteger({right})'
                    method = {'+': 'add', '-': 'subtract', '*': 'multiply', '/': 'divide'}[operator]
                    result = f'{result}.{method}({right})'; floating = True
                else:
                    helper = {'+': 'add32', '-': 'sub32', '*': 'imul32', '/': 'idiv32'}[operator]
                    result = f'{helper}({result}, {right})'
            elif operator in ('&&', '||'):
                result = f'Number(Boolean({result}) {operator} Boolean({right}))'; floating = False
            elif operator in ('&', '|', '^'):
                result = f'({result} {operator} {right})'; floating = False
            else:
                if floating or right_float: raise ValueError('Unexpected float comparison in small menu handler')
                result = f'Number({result} {operator} {right})'; floating = False
        return result, floating
    def all(self):
        result = self.expression()
        if self.at != len(self.tokens): raise ValueError(f'Unparsed expression {self.tokens[self.at:]}')
        return result


def convert_body(source):
    body = source[source.index('{') + 1:source.rindex('}')]
    body = re.sub(r'/\*.*?\*/', '', body, flags=re.S)
    body = re.sub(r'  undefined4 \*puVar1;\s*', '', body)
    body = re.sub(r'  puVar1 = \(undefined4 \*\)\*param_1;\s*', '', body)
    body = re.sub(r'\(\*\(code \*\)puVar1\[1\]\)\((.*?)\);', r'check(\1);', body, flags=re.S)
    body = re.sub(r'\(\*\(code \*\)\*puVar1\)\((.*?)\);', r'enable(\1);', body, flags=re.S)
    body = re.sub(r'\(\*\*\(code \*\*\)\*param_1\)\((.*?)\);', r'enable(\1);', body, flags=re.S)
    body = re.sub(r'\*\(HWND \*\)\(\(int\)this \+ 0x1c\)', 'windowHandle', body)
    body = re.sub(r'\*\(HWND \*\)\(param_1 \+ 0x1c\)', 'windowHandle', body)
    body = re.sub(r'InvalidateRect\((?:windowHandle|hWnd),\(RECT \*\)0x0,([01])\);', r'invalidate(\1);', body)
    lines = []
    for raw in body.splitlines():
        line = raw.strip()
        if not line: continue
        if line in ('undefined4 *puVar1;', 'puVar1 = (undefined4 *)*param_1;'): continue
        if line in ('{', '}', 'else {'): lines.append(line); continue
        if line in ('return;',): lines.append(line); continue
        if line.startswith(('bool ', 'HWND ', 'undefined4 ')):
            variable = line.split()[1].rstrip(';')
            if variable not in ('bVar1', 'hWnd', 'uVar1', 'uVar2'): raise ValueError(f'Unknown local {line}')
            lines.append(f'let {variable};'); continue
        if line.startswith('if (') and line.endswith(') {'):
            value, _ = Expressions(line[4:-3]).all(); lines.append(f'if ({value}) {{'); continue
        if line == 'FUN_0044e380();': lines.append('updateSpeedDivisor(memory);'); continue
        match = re.fullmatch(r'(invalidate|enable|check)\((.*)\);', line)
        if match:
            value, _ = Expressions(match[2]).all(); lines.append(f'{match[1]}({value});'); continue
        match = re.fullmatch(r'(_?DAT_[0-9a-f]{8}|bVar1|uVar1|uVar2|hWnd) = (.*);', line)
        if match:
            dest, expression = match.groups(); value, floating = Expressions(expression).all()
            if 'DAT_' in dest:
                address = int(dest[-8:], 16)
                if address in FLOAT_GLOBALS:
                    if not floating: value = f'Float80.fromInteger({value})'
                    lines.append(f'memory.writeF64(0x{address:x}, {value}.toNumber());')
                else:
                    if floating: raise ValueError('Unexpected float-to-int menu assignment')
                    lines.append(f'w(0x{address:x}, {value});')
            else: lines.append(f'{dest} = {value};')
            continue
        raise ValueError(f'Unknown menu statement {line}')
    return lines


def main():
    entries = menu_entries(); commands, updates = [], []
    special = {0x401760, 0x44ffd0, 0x450db0, 0x46e830, 0x477e8f}
    for row in entries:
        if row['address'] in special: continue
        source = (ROOT / f'decompiled/functions/{row["address"]:08x}.c').read_text()
        try: lines = convert_body(source)
        except ValueError as error: raise ValueError(f'{row["address"]:08x} {row["label"]}: {error}') from error
        row['lines'] = lines
        (commands if row['code'] == 0 else updates).append(row)
    output = ["// Generated from original menu message maps and recovered C by tools/translate_menu_handlers.py.",
        "// Supported statements are checked strictly; captured original instructions remain the oracle.",
        "import { i32, add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';",
        "import { Float80 } from '../runtime/float80.js';",
        "import { updateSpeedDivisor } from './integer-core.js';", '',
        'const commandHandlers = new Map([']
    for row in commands:
        output += [f'  // 0x{row["address"]:08x}: {row["label"]}', f'  [{row["commandId"]}, (memory, options, r, w, f, invalidate) => {{']
        output += ['    ' + line for line in row['lines']]
        output += ['  }],']
    output += [']);', '', 'const updateHandlers = new Map([']
    for row in updates:
        output += [f'  // 0x{row["address"]:08x}: {row["label"]}', f'  [{row["commandId"]}, (r, enable, check) => {{']
        output += ['    ' + line for line in row['lines']]
        output += ['  }],']
    output += [']);', '',
        '/** Run the exact recovered numeric command; GUI dialogs remain explicit host requests. */',
        'export function handleMenuCommand(memory, command, options = {}) {',
        '  command = i32(command);',
        '  const invalidate = erase => options.invalidateRect?.({windowHandle: options.windowHandle ?? 0, rectangle: null, erase});',
        '  const dialog = (resourceId, originalAddress) => {',
        "    if (!options.dialogHandler) throw new RangeError('This original command requires its modal dialog host');",
        '    return options.dialogHandler({resourceId, originalAddress});',
        '  };',
        "  const afterDialog = (result, tail) => result && typeof result.then === 'function' ? Promise.resolve(result).then(tail) : tail();",
        '  if (command === 57664) return afterDialog(dialog(100, 0x401760), () => true);',
        '  if (command === 32823) return afterDialog(dialog(132, 0x44ffd0), () => { memory.writeI32(0x4ac8fc,0); invalidate(1); return true; });',
        '  if (command === 32779) return afterDialog(dialog(131, 0x450db0), () => { memory.writeI32(0x4ac8fc,0); invalidate(0); memory.writeI32(0x491140,2); return true; });',
        '  if (command === 57665) { options.closeWindow?.({message:0x10,wParam:0,lParam:0}); return true; }',
        '  if (command === 59393) { options.toggleMenuItemHelp?.(); return true; }',
        '  const handler = commandHandlers.get(command);',
        '  if (!handler) return false;',
        '  handler(memory, options, address => memory.readI32(address), (address,value) => memory.writeI32(address,value),',
        '    address => Float80.fromNumber(memory.readF64(address)), invalidate);',
        '  return true;',
        '}', '',
        '/** Exact original CCmdUI Enable/SetCheck requests; untouched properties remain unspecified. */',
        'export function menuCommandState(memory, command, previous = {}) {',
        '  const state = {...previous};',
        '  const events = [];',
        '  updateHandlers.get(i32(command))?.(address => memory.readI32(address),',
        "    value => {state.enabled=Boolean(value);events.push({op:'enable',value:i32(value)});},",
        "    value => {state.checked=i32(value);events.push({op:'check',value:i32(value)});});",
        '  return {...state,events};',
        '}', '',
        'export const MENU_COMMAND_ROUTINES = Object.freeze(' + json.dumps({str(row['commandId']): row['address'] for row in entries if row['code'] == 0}, separators=(',', ':')) + ');',
        'export const MENU_UPDATE_ROUTINES = Object.freeze(' + json.dumps({str(row['commandId']): row['address'] for row in entries if row['code'] != 0}, separators=(',', ':')) + ');', '']
    (ROOT / 'src/engine/menu-controller.js').write_text('\n'.join(output))
    print('menu handlers', len(commands), 'numeric commands,', len(updates), 'update handlers,', len(special), 'host commands')


if __name__ == '__main__': main()
