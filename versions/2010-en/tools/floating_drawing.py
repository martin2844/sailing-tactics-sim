"""Emit an explicitly typed floating arithmetic variant of reviewed drawing C.

The original byte/scalar implementation remains the fallback. Floating values
alone use the certified binary64 helpers; integer arithmetic, pointer views,
stores, control flow, and external argument representation keep their existing
semantics. This is a source compiler, not a rewrite of generated expressions.
"""
import re
import json
from pycparser import c_ast
from optimize_static_locals import promote_static_locals, _code_mask, _calls
from fuse_chart_windows import fuse_chart_windows


FLOAT_TYPES = frozenset(('double', 'float10', 'unkbyte10', 'undefined8'))
FLOAT_CONSTANTS = frozenset(('float', 'double', 'long double'))
FLOAT_BUILTINS = frozenset(('SQRT', 'sqrt', 'sin', 'cos', 'fsin', 'fcos', 'fpatan', 'ABS'))
FLOAT_IMPORT = "import { fpDrawingEnabled,fpLoad,fpBox,fpArgument,fpFromInteger,fpStoreF64,fpFormalF64,fpTrig,fpAtan,fpScalarStoreF64,fpScalarRead,fpScalarReadArgument,fpToNumber,fpAdd,fpSub,fpMul,fpDiv,fpNeg,fpAbs,fpCompare,fpTruth,fpI32,fpI64 } from './float-values.js';\nimport { readLocalFloatNumber,wordsAsF64Number,writeLocalFloatNumber,readPointerFloatNumber,readLocalFloatWordsNumber } from './typed-c.js';\nimport { callNumberDrawingDependencyOwned,registerOriginalNumberDrawing } from './dependencies.js';\nimport { tryProjectScenePointOutputFast } from './projection-output-fast.js';\nimport { tryProjectChartPointFast } from './chart-projection-fast.js';\n"
FLOAT_IMPORT += "import {tryProjectChartPointOutputFast} from './chart-output-fast.js';\nimport {originalNumberDrawingIsCurrent} from './dependencies.js';\n"


def ast_identity(node):
    """Structural identity of a C expression, independent of source position."""
    return (type(node).__name__, tuple((name, getattr(node, name)) for name in node.attr_names),
            tuple((name, ast_identity(child)) for name, child in node.children()))


def floating_argument_flags(indices):
    # JavaScript shift counts wrap modulo32; larger future signatures must keep
    # the complete index array instead of aliasing position32 to position0.
    return str(sum(1 << index for index in indices)) if all(index < 32 for index in indices) else json.dumps(indices)


def write_number_report(root, filename, records):
    path = root / 'analysis/floating-drawing-generation.json'
    report = json.loads(path.read_text()) if path.exists() else {
        'format': 1,
        'scope': 'Static C floating type inference with certified Number/Float80 arithmetic. Integer and pointer operations retain original helpers. Full original function bodies remain the guarded fallback; external floating arguments and packed words retain Float80 representation.',
        'modules': {}}
    report['modules'][filename] = records
    report['modules'] = dict(sorted(report['modules'].items()))
    report['eligibleFunctions'] = sum(row['eligible'] for rows in report['modules'].values() for row in rows)
    report['functions'] = sum(len(rows) for rows in report['modules'].values())
    path.write_text(json.dumps(report, indent=2) + '\n')


def replace_number_byte_stores(source):
    """Remove only the generated boxing wrapper at an F64 byte-store boundary."""
    selected=[]
    for call in _calls(source, _code_mask(source)) or []:
        if call['kind']!='writeLocal' or len(call['args'])!=4:
            continue
        pointer,value,size,kind=call['args']
        if size[2]!='8' or kind[2]!='"float"' or not value[2].startswith('fpArgument(') or not value[2].endswith(')'):
            continue
        begin,end= value[0],value[1]
        while source[begin].isspace():begin+=1
        while source[end-1].isspace():end-=1
        call['valueSpan']=(begin+len('fpArgument('),end-1)
        selected.append(call)

    def render(begin,end):
        output=[];previous=begin
        for call in selected:
            if call['start']<previous or call['start']<begin or call['end']>end:
                continue
            output.append(source[previous:call['start']])
            value=render(*call['valueSpan'])
            output.append(f'writeLocalFloatNumber({call["args"][0][2]},{value})')
            previous=call['end']
        output.append(source[previous:end])
        return ''.join(output)
    return render(0,len(source)),len(selected)


def fix_number_parameters(source, name, count, scalar_locals):
    """Remove a private rest array; retained fallback constructs its own lazily."""
    signature = f'function {name}(memory, dc, rng, options, numberArgumentImages, ...originalArgs)'
    if source.count(signature) != 1:
        raise ValueError('Numeric fixed formals require one recognized private signature')
    mask = _code_mask(source)
    start = source.index(signature)
    opening = mask.index('{', start + len(signature))
    end, depth = opening + 1, 1
    while depth:
        if mask[end] == '{':
            depth += 1
        elif mask[end] == '}':
            depth -= 1
        end += 1
    body = source[opening:end]
    body_mask = _code_mask(body)
    if re.search(r'\bnumberArg\d+\b', body_mask):
        raise ValueError('Private numeric formal identifiers would collide')
    names = [f'numberArg{index}' for index in range(count)]
    patches = []
    for match in re.finditer(r'\boriginalArgs\[(\d+)\]', body_mask):
        index = int(match[1])
        if index >= count:
            raise ValueError('Numeric argument access exceeds declared C formals')
        patches.append((match.start(), match.end(), names[index]))
    for begin, finish, replacement in reversed(patches):
        body = body[:begin] + replacement + body[finish:]
    fallback = f'{name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes,numberArgumentImages);'
    if body.count(fallback) != int(scalar_locals):
        raise ValueError('Numeric retained guard has an unrecognized argument contract')
    if scalar_locals:
        body = body.replace(fallback,
            f'{name}ByteFrame(memory,dc,rng,options,[{",".join(names)}],retainedLocalBytes,numberArgumentImages);')
    if re.search(r'\boriginalArgs\b', _code_mask(body)):
        raise ValueError('Numeric rest arguments escape fixed bindings and retained guard')
    fixed = f'function {name}(memory, dc, rng, options, numberArgumentImages'
    fixed += (', ' + ', '.join(names) if names else '') + ')'
    return source[:start] + fixed + ' ' + body + source[end:]


def add_number_variant(original, baseline, name, base_type, symbol_address, f64, root):
    """Append a private Number variant and retain the complete existing fallback."""
    base = type(original)
    return_types = {}

    class NumberTranslator(base):
        def original_return_type(self, address):
            if address not in return_types:
                path = root / f'analysis/drawing-corrections/{address:08x}.c'
                if not path.exists():
                    path = root / f'decompiled/functions/{address:08x}.c'
                source = path.read_text() if path.exists() else ''
                match = re.search(r'^\s*(void|double|float10|unkbyte10|undefined8|int|uint|longlong|ulonglong|undefined4|bool)\s+(?:__\w+\s+)*FUN_[0-9a-fA-F]{8}\s*\(', source, re.M)
                return_types[address] = match[1] if match else 'int'
            return return_types[address]

        def expression_type(self, node):
            if isinstance(node, c_ast.ID):
                address = symbol_address(node.name)
                return 'double' if address in f64 else self.types.get(node.name, 'int')
            if isinstance(node, c_ast.Constant):
                return 'double' if node.type in FLOAT_CONSTANTS else 'int'
            if isinstance(node, c_ast.Cast):
                return base_type(node.to_type)
            if isinstance(node, c_ast.UnaryOp):
                typ = self.expression_type(node.expr)
                if node.op == '&':
                    return typ + '*'
                if node.op == '*':
                    return typ[:-1] if typ.endswith('*') else 'int'
                return 'int' if node.op in ('!', '~') else typ
            if isinstance(node, c_ast.BinaryOp):
                left, right = self.expression_type(node.left), self.expression_type(node.right)
                if node.op in ('+', '-') and left.endswith(('*', '[]')):
                    return left
                if node.op in ('+', '-', '*', '/', '%') and (left in FLOAT_TYPES or right in FLOAT_TYPES):
                    return 'float10'
                return 'int'
            if isinstance(node, c_ast.ArrayRef):
                typ = self.expression_type(node.name)
                return typ[:-2] if typ.endswith('[]') else typ[:-1] if typ.endswith('*') else 'int'
            if isinstance(node, c_ast.TernaryOp):
                left, right = self.expression_type(node.iftrue), self.expression_type(node.iffalse)
                return 'float10' if left in FLOAT_TYPES or right in FLOAT_TYPES else left
            if isinstance(node, c_ast.Assignment):
                return self.expression_type(node.lvalue)
            if isinstance(node, c_ast.ExprList):
                return self.expression_type(node.exprs[-1])
            if isinstance(node, c_ast.FuncCall) and isinstance(node.name, c_ast.ID):
                function = node.name.name
                if function in FLOAT_BUILTINS:
                    return 'float10'
                if re.fullmatch(r'FUN_[0-9a-fA-F]{8}', function):
                    return self.original_return_type(int(function[4:], 16))
            # Packed word views and geometry fields retain integer interpretation.
            return 'char*' if isinstance(node, c_ast.StructRef) and node.field.name == 'data' else 'int'

        def floating(self, node):
            return self.expression_type(node) in FLOAT_TYPES

        def floating_expr(self, node):
            value = self.expr(node)
            return value if self.floating(node) else f'fpFromInteger({value})'

        def storage_expression_type(self, node):
            # Floating inference must not change the reviewed pointer scaling.
            if isinstance(node, c_ast.ID):
                return self.types.get(node.name, 'int')
            if isinstance(node, c_ast.Cast):
                return base_type(node.to_type)
            if isinstance(node, c_ast.UnaryOp) and node.op == '&':
                return self.storage_expression_type(node.expr) + '*'
            if isinstance(node, c_ast.BinaryOp) and node.op in ('+', '-'):
                left = self.storage_expression_type(node.left)
                if left.endswith(('*', '[]')):
                    return left
            return 'char*' if isinstance(node, c_ast.StructRef) else 'int'

        def pointer_scale(self, node):
            if isinstance(node, c_ast.UnaryOp) and node.op == '&' and isinstance(node.expr, c_ast.ID) and symbol_address(node.expr.name):
                return super().pointer_scale(node)
            typ = self.storage_expression_type(node)
            element = typ[:-2] if typ.endswith('[]') else typ[:-1] if typ.endswith('*') else None
            if element is None:
                return 1
            if element.endswith('*'):
                return 4
            if element in ('double', 'undefined8', 'longlong', 'ulonglong', 'tagPOINT', 'POINT'):
                return 8
            if element in ('int', 'uint', 'undefined4', 'LONG', 'DWORD', 'COLORREF', 'HDC', 'HGDIOBJ', 'Tact2010CString'):
                return 4
            if element in ('ushort', 'short', 'undefined2'):
                return 2
            return 10 if element in ('float10', 'unkbyte10') else 1

        def word_expr(self, node):
            while isinstance(node, c_ast.Cast) and base_type(node.to_type) in ('undefined4', 'int', 'uint'):
                node = node.expr
            if isinstance(node, c_ast.ID) and symbol_address(node.name):
                return super().word_expr(node)
            if self.floating(node):
                return f'cRawWord(fpBox({self.expr(node)}))'
            return super().word_expr(node)

        def local_concat_pointer(self, high, low):
            """Prove two pure local DWORD pointers differ by exactly four bytes."""
            def word_pointer(node):
                if (not isinstance(node, c_ast.UnaryOp) or node.op != '*'
                        or not isinstance(node.expr, c_ast.Cast)
                        or base_type(node.expr.to_type) not in ('int*', 'uint*', 'undefined4*')):
                    return None
                return node.expr.expr

            def pure_integer(node):
                if isinstance(node, c_ast.Constant):
                    return node.type in ('int', 'unsigned int', 'long int', 'unsigned long int')
                if isinstance(node, c_ast.ID):
                    return (node.name not in self.stack and not symbol_address(node.name)
                            and self.types.get(node.name) in ('int', 'uint', 'LONG', 'DWORD', 'undefined4'))
                if isinstance(node, c_ast.Cast):
                    return base_type(node.to_type) in ('int', 'uint', 'LONG', 'DWORD', 'undefined4') and pure_integer(node.expr)
                if isinstance(node, c_ast.UnaryOp):
                    return node.op in ('+', '-', '~') and pure_integer(node.expr)
                if isinstance(node, c_ast.BinaryOp):
                    return node.op in ('+', '-', '*', '&', '|', '^', '<<', '>>') and pure_integer(node.left) and pure_integer(node.right)
                return False

            def local_pointer(node, byte_cast=False):
                if isinstance(node, c_ast.Cast):
                    return base_type(node.to_type) in ('int', 'uint', 'LONG', 'DWORD', 'undefined4') and local_pointer(node.expr, True)
                if isinstance(node, c_ast.UnaryOp) and node.op == '&' and isinstance(node.expr, c_ast.ID):
                    return node.expr.name in self.stack and (byte_cast or node.expr.name not in self.arrays)
                if isinstance(node, c_ast.ID):
                    return node.name in self.stack and node.name in self.arrays
                if isinstance(node, c_ast.BinaryOp) and node.op in ('+', '-'):
                    return local_pointer(node.left, byte_cast) and pure_integer(node.right)
                return False

            high_pointer, low_pointer = word_pointer(high), word_pointer(low)
            if (high_pointer is None or low_pointer is None or not local_pointer(low_pointer)
                    or not isinstance(high_pointer, c_ast.BinaryOp) or high_pointer.op != '+'
                    or not isinstance(high_pointer.right, c_ast.Constant)
                    or not pure_integer(high_pointer.right)
                    or int(high_pointer.right.value.rstrip('uUlL'), 0) != 4
                    or self.pointer_scale(high_pointer.left) != 1
                    or ast_identity(high_pointer.left) != ast_identity(low_pointer)):
                return None
            return low_pointer

        def expr(self, node):
            external = getattr(self, '_external_arguments', set())
            if id(node) in external:
                external.remove(id(node))
                try:
                    return f'fpArgument({self.expr(node)})'
                finally:
                    external.add(id(node))
            if isinstance(node, c_ast.Constant) and node.type in FLOAT_CONSTANTS:
                return f'fpLoad({node.value.rstrip("fFlL")})'
            if isinstance(node, c_ast.Cast):
                typ = base_type(node.to_type)
                # This cast represents two original bit writes, not FILD.
                bit_cast = (typ == 'double' and self.routine_address == 0x466330
                            and isinstance(node.expr, c_ast.BinaryOp) and node.expr.op == '<<'
                            and isinstance(node.expr.left, c_ast.ID) and node.expr.left.name == 'lVar15'
                            and isinstance(node.expr.right, c_ast.Constant) and int(node.expr.right.value, 0) == 32)
                concat_cast = (typ == 'double' and isinstance(node.expr, c_ast.FuncCall)
                               and isinstance(node.expr.name, c_ast.ID) and node.expr.name.name.startswith('CONCAT'))
                if concat_cast and node.expr.name.name == 'CONCAT44':
                    high, low = node.expr.args.exprs
                    local_pointer = self.local_concat_pointer(high, low)
                    if local_pointer is not None:
                        self.local_concat_loads += 1
                        return f'readLocalFloatWordsNumber(memory,{self.expr(local_pointer)})'
                    return f'wordsAsF64Number({self.word_expr(high)},{self.word_expr(low)})'
                if typ == 'double' and not bit_cast and not concat_cast:
                    return f'fpLoad(fpToNumber({self.floating_expr(node.expr)}))'
                if typ in ('float10', 'unkbyte10'):
                    return self.floating_expr(node.expr)
                if self.floating(node.expr) and typ in ('longlong', 'ulonglong'):
                    return f'fpI64({self.expr(node.expr)},{str(typ == "ulonglong").lower()})'
                if self.floating(node.expr) and typ in ('int', 'uint', 'LONG'):
                    return f'fpI32({self.expr(node.expr)},{str(typ == "uint").lower()})'
                if (typ in ('int', 'uint', 'LONG') and isinstance(node.expr, c_ast.Cast)
                        and base_type(node.expr.to_type) in ('longlong', 'ulonglong') and self.floating(node.expr.expr)):
                    return f'fpI32({self.expr(node.expr.expr)},{str(typ == "uint").lower()})'
            if isinstance(node, c_ast.BinaryOp):
                floating = self.floating(node.left) or self.floating(node.right)
                if floating and node.op in ('+', '-', '*', '/'):
                    # Retain the independently reviewed roof association.
                    if (self.routine_address == 0x4813f0 and node.op == '*'
                            and isinstance(node.left, c_ast.BinaryOp) and node.left.op == '*'
                            and isinstance(node.left.right, c_ast.ID) and node.left.right.name == 'fVar5'
                            and isinstance(node.right, c_ast.Cast) and base_type(node.right.to_type) == 'float10'
                            and isinstance(node.right.expr, c_ast.ID) and symbol_address(node.right.expr.name) == 0x4ccff0):
                        self.roof_order_rewrites += 1
                        return f'fpMul({self.floating_expr(node.left.left)},fpMul({self.floating_expr(node.left.right)},{self.floating_expr(node.right)}))'
                    helper = {'+': 'fpAdd', '-': 'fpSub', '*': 'fpMul', '/': 'fpDiv'}[node.op]
                    return f'{helper}({self.floating_expr(node.left)},{self.floating_expr(node.right)})'
                if floating and node.op in ('<', '>', '<=', '>=', '==', '!='):
                    return f'fpCompare({self.floating_expr(node.left)},{self.floating_expr(node.right)},"{node.op}")'
            if isinstance(node, c_ast.UnaryOp) and node.op == '*' and self.floating(node):
                # Keep every base-emitter special case. Only its exact eight-
                # byte floating read is eligible for the raw Number loader.
                value = super().expr(node)
                prefix = 'readPointer(memory,'
                if value.startswith(prefix) and value.endswith(',8)'):
                    self.floating_pointer_loads += 1
                    return f'readPointerFloatNumber(memory,{value[len(prefix):-3]})'
                return value
            if isinstance(node, c_ast.UnaryOp) and node.op == '-' and self.floating(node.expr):
                return f'fpNeg({self.expr(node.expr)})'
            if isinstance(node, c_ast.StructRef):
                match = re.fullmatch(r'_([0-9]+)_([0-9]+)_', node.field.name)
                typ = self.expression_type(node.name)
                if (match and isinstance(node.name, c_ast.ID) and not symbol_address(node.name.name)
                        and node.name.name not in self.stack and typ in FLOAT_TYPES):
                    kind = 'integer' if typ == 'undefined8' else 'extended' if typ in ('float10', 'unkbyte10') else 'float'
                    return f'cRawSlice(fpBox({self.expr(node.name)}),{match[1]},{match[2]},"{kind}")'
            return super().expr(node)

        def assign(self, node):
            left = node.lvalue
            value = self.expr(node.rvalue)
            floating = self.floating(left) or self.floating(node.rvalue)
            if node.op != '=' and floating and node.op in ('+=', '-=', '*=', '/='):
                helper = {'+=': 'fpAdd', '-=': 'fpSub', '*=': 'fpMul', '/=': 'fpDiv'}[node.op]
                value = f'{helper}({self.floating_expr(left)},{self.floating_expr(node.rvalue)})'
            elif node.op != '=':
                return super().assign(node)
            if isinstance(left, c_ast.ID):
                address = symbol_address(left.name)
                if address:
                    if address in f64:
                        value = value if self.floating(node.rvalue) else f'fpFromInteger({value})'
                        return f'w64({hex(address)},{value})'
                    return f'w32({hex(address)},{"fpBox(" + value + ")" if self.floating(node.rvalue) else value})'
                if left.name in self.stack:
                    size, kind = self.scalar_kind(left.name)
                    if kind == 'float':
                        value = f'fpArgument({value})' if self.floating(node.rvalue) else value
                    elif self.floating(node.rvalue):
                        value = f'fpBox({value})'
                    return f'writeLocal({self.local_address(left.name)},{value},{size},"{kind}")'
                if self.floating(node.rvalue) and not self.floating(left):
                    value = f'fpBox({value})'
                return f'({left.name} = {value})'
            # Preserve pointer/packed stores exactly. Their existing helpers
            # discriminate Float80 from an integer Number when writing words.
            if self.floating(node.rvalue) or (node.op != '=' and floating):
                value = f'fpBox({value})'
            if isinstance(left, c_ast.StructRef) and left.field.name == 'data':
                if isinstance(left.name, c_ast.ID) and left.name.name in self.stack:
                    return f'writeLocal({self.local_address(left.name.name)},{value},4)'
                return f'({self.expr(left.name)} = {value})'
            if isinstance(left, c_ast.ArrayRef):
                if isinstance(left.name, c_ast.ID) and left.name.name in self.arrays and left.name.name not in self.stack:
                    return f'({self.expr(left)} = {value})'
                return f'writePointer(memory,{self.address(left)},{value},{self.array_scale(left.name)})'
            if isinstance(left, c_ast.StructRef):
                match = re.fullmatch(r'_([0-9]+)_([0-9]+)_', left.field.name)
                if match:
                    return f'writePointer(memory,pointerAdd({self.address(left.name)},{match[1]}),{value},{match[2]})'
                if left.field.name in ('x', 'y'):
                    return f'writePointer(memory,pointerAdd({self.address(left.name)},{4 if left.field.name == "y" else 0}),{value},4)'
            if isinstance(left, c_ast.UnaryOp) and left.op == '*':
                address = self.expr(left.expr.expr) if isinstance(left.expr, c_ast.Cast) else self.expr(left.expr)
                return f'writePointer(memory,{address},{value},{self.pointer_scale(left.expr)})'
            raise ValueError(f'Unsupported numeric assignment {type(left).__name__}')

        def call(self, node):
            args = node.args.exprs if node.args else []
            name = node.name.name if isinstance(node.name, c_ast.ID) else None
            if name in ('SQRT', 'sqrt'):
                return f'fpBox({self.floating_expr(args[0])}).sqrt()'
            if name in ('sin', 'cos', 'fsin', 'fcos'):
                component = 'sine' if name in ('sin', 'fsin') else 'cosine'
                return f'fpTrig({self.floating_expr(args[0])},options).{component}'
            if name == 'fpatan':
                return f'fpAtan({self.floating_expr(args[0])},{self.floating_expr(args[1])},options)'
            if name == 'ABS':
                return f'fpAbs({self.floating_expr(args[0])})'
            if name == 'FUN_0041bd00':
                return self.string_assignment(args[0], f'formatDecimal(memory,fpToNumber({self.floating_expr(args[1])}))')
            if name and re.fullmatch(r'FUN_[0-9a-fA-F]{8}', name) and int(name[4:], 16) in original.dependencies:
                address = int(name[4:], 16)
                self.dependencies.add(address)
                values = ', '.join(super(NumberTranslator, self).argument_expr(arg) for arg in args)
                floating = [index for index, arg in enumerate(args) if self.floating(arg)]
                return f'callNumberDrawingDependencyOwned(memory,dc,{hex(address)},[{values}],{floating_argument_flags(floating)},rng,options)'
            previous = getattr(self, '_external_arguments', set())
            self._external_arguments = {id(arg) for arg in args if self.floating(arg)}
            try:
                return super().call(node)
            finally:
                self._external_arguments = previous

        def argument_expr(self, node):
            value = super().argument_expr(node)
            return f'fpArgument({value})' if self.floating(node) else value

        def parameter_value(self, parameter, value):
            size, kind = self.scalar_kind(parameter.name)
            if (size, kind) == (8, 'float'):
                return f'fpArgument(fpFormalF64({value},numberArgumentImages))'
            return super().parameter_value(parameter, value)

        def compile(self, node, next_node, break_to=None, continue_to=None):
            if isinstance(node, c_ast.Return) and node.expr is not None and self.floating(node.expr):
                return self.node(f'return fpBox({self.expr(node.expr)});')
            return super().compile(node, next_node, break_to, continue_to)

        def generate_raw(self, variant_name=None):
            generated = super().generate_raw(variant_name)
            old_load = 'const r32 = address => memory.readI32(address), r64 = address => Float80.fromNumber(memory.readF64(address));'
            new_load = 'const r32 = address => memory.readI32(address), r64 = address => fpLoad(memory.readF64(address));'
            old_store = 'const w32 = (address,value) => memory.writeI32(address,cI32(value)), w64 = (address,value) => memory.writeF64(address,cFloat(value).toNumber());'
            new_store = 'const w32 = (address,value) => memory.writeI32(address,cI32(value)), w64 = (address,value) => memory.writeF64(address,fpToNumber(value));'
            if generated.count(old_load) != 1 or generated.count(old_store) != 1:
                raise ValueError('Numeric floating variant requires unchanged recognized memory bindings')
            generated = generated.replace(old_load, new_load).replace(old_store, new_store)
            return generated

    variant_name = name + 'Number'
    numeric = NumberTranslator(original.selector, original.routine_address, original.source, original.has_dc)
    numeric.floating_pointer_loads = 0
    numeric.local_concat_loads = 0
    floating_operations = []
    unsupported = []

    def inspect(node):
        if isinstance(node, c_ast.BinaryOp) and (numeric.floating(node.left) or numeric.floating(node.right)):
            if node.op in ('+', '-', '*', '/', '<', '>', '<=', '>=', '==', '!='):
                floating_operations.append(node)
            elif node.op in ('%', '&', '|', '^', '<<', '>>'):
                unsupported.append('Floating operands at integer-only operator')
        if isinstance(node, c_ast.UnaryOp) and node.op in ('p++', 'p--', '++', '--') and numeric.floating(node.expr):
            unsupported.append('Floating increment has no reviewed source lowering')
        if isinstance(node, c_ast.FuncCall) and isinstance(node.name, c_ast.ID) and node.name.name in FLOAT_BUILTINS:
            floating_operations.append(node)
        if isinstance(node, c_ast.Cast) and base_type(node.to_type) in ('double', 'float10', 'unkbyte10'):
            floating_operations.append(node)
        for _label, child in node.children():
            inspect(child)

    inspect(numeric.function.body)
    if any(typ == 'float' or typ.endswith('float*') for typ in numeric.types.values()):
        unsupported.append('Single-precision local storage is outside the reviewed backend')
    parameters = numeric.function.decl.type.args.params if numeric.function.decl.type.args else []
    if any(isinstance(parameter,c_ast.Decl) and numeric.scalar_kind(parameter.name)==(8,'float')
           and base_type(parameter.type)!='double' for parameter in parameters):
        unsupported.append('Non-double floating formals need separate deferred-spill semantics review')
    original.number_optimization = {'address': original.routine_address, 'function': name,
                                    'eligible': bool(floating_operations) and not unsupported,
                                    'floatingOperations': len(floating_operations),
                                    'reasons': sorted(set(unsupported))}
    if not floating_operations or unsupported:
        return baseline
    variant, numeric.scalar_stack_optimization = promote_static_locals(numeric.generate_raw(variant_name), variant_name, numeric.routine_address, numeric.frame_size, numeric_floats=True)
    variant = variant.replace('scalarStoreF64(', 'fpScalarStoreF64(').replace('scalarReadArgument(', 'fpScalarReadArgument(').replace('scalarRead(', 'fpScalarRead(')
    variant, byte_stores = replace_number_byte_stores(variant)
    variant = re.sub(r'readLocal\((framePointer\(localFrame,\d+\)),8,"float"\)', r'readLocalFloatNumber(\1)', variant)
    variant = variant.replace(f'export function {variant_name}(memory, dc, rng, options = {{}}, ...originalArgs)',
                              f'function {variant_name}(memory, dc, rng, options, numberArgumentImages, ...originalArgs)', 1)
    if numeric.scalar_stack_optimization['eligible']:
        variant = variant.replace(f'function {variant_name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes)',
                                  f'function {variant_name}ByteFrame(memory, dc, rng, options, originalArgs, retainedLocalBytes, numberArgumentImages)', 1)
        variant = variant.replace(f'{variant_name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes);',
                                  f'{variant_name}ByteFrame(memory,dc,rng,options,originalArgs,retainedLocalBytes,numberArgumentImages);', 1)
    argument_count = max(0, len([parameter for parameter in parameters if isinstance(parameter,c_ast.Decl)])
                         - int(numeric.dc_index is not None))
    variant = fix_number_parameters(variant, variant_name, argument_count, numeric.scalar_stack_optimization['eligible'])
    if numeric.routine_address == 0x43e730:
        marker = '  scalarStack24=scalarStoreI32(numberArg4);\n'
        if argument_count != 5 or not numeric.scalar_stack_optimization['eligible'] or variant.count(marker) != 1:
            raise ValueError('Certified point output requires the reviewed five scalar formal bindings')
        variant = variant.replace(marker, marker +
            '  if(tryProjectScenePointOutputFast(memory,scalarStack0,scalarStack4,scalarStack12,scalarStack20,scalarStack24,options))return;\n', 1)
    if numeric.routine_address == 0x43ec20:
        marker = '  scalarStack20=scalarStoreI32(numberArg3);\n'
        if argument_count != 4 or not numeric.scalar_stack_optimization['eligible'] or variant.count(marker) != 1:
            raise ValueError('Exact chart projection requires the reviewed four scalar formal bindings')
        variant = variant.replace(marker, marker +
            '  const chartProjection=tryProjectChartPointFast(memory,scalarStack0,scalarStack8,scalarStack16,scalarStack20,options);\n'
            '  if(chartProjection!==undefined)return chartProjection;\n', 1)
    variant, chart_windows = fuse_chart_windows(variant, variant_name, numeric.routine_address)
    if numeric.dependencies != original.dependencies:
        raise ValueError('Numeric floating compiler changed the original dependency graph')
    original.number_optimization['scalarLocals'] = numeric.scalar_stack_optimization['eligible']
    if numeric.scalar_stack_optimization.get('mode') == 'partial':
        original.number_optimization['scalarMode'] = 'partial'
        for key in ('slots', 'retainedByteRanges', 'induction', 'scalarAccesses', 'arrays', 'arrayAccesses', 'pointerCalleeSha256'):
            if key in numeric.scalar_stack_optimization:
                original.number_optimization[key] = numeric.scalar_stack_optimization[key]
    original.number_optimization['floatingByteStoreExpressions'] = byte_stores
    original.number_optimization['floatingPointerLoadExpressions'] = numeric.floating_pointer_loads
    original.number_optimization['localConcatLoadExpressions'] = numeric.local_concat_loads
    original.number_optimization['floatingParameters'] = [index for index, parameter in enumerate(parameters)
        if isinstance(parameter, c_ast.Decl) and numeric.scalar_kind(parameter.name) == (8, 'float')]
    original.number_optimization['fixedNumberArguments'] = argument_count
    original.number_optimization['certifiedProjectionOutput'] = numeric.routine_address == 0x43e730
    original.number_optimization['exactChartProjection'] = numeric.routine_address == 0x43ec20
    if chart_windows['eligible']:
        original.number_optimization['certifiedChartWindows'] = chart_windows
    signature = f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs)'
    if baseline.count(signature) != 1:
        raise ValueError('Numeric variant requires a single public original signature')
    baseline = baseline.replace(signature, f'function {name}Original(memory, dc, rng, options = {{}}, ...originalArgs)', 1)
    dispatch = (f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs) {{\n'
                f'  return fpDrawingEnabled(options) ? {variant_name}(memory,dc,rng,options,false,...originalArgs)\n'
                f'    : {name}Original(memory,dc,rng,options,...originalArgs);\n'
                '}')
    return dispatch + '\n\n' + baseline + '\n\n' + variant
