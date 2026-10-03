#!/usr/bin/env python3
"""Statically translate the complete recovered English tactical C subtree.

The parser/control-flow builder is shared with the edition-local drawing build
tool. This strict numerical frontend accepts only the fixed reviewed helpers,
preserves typed stores and rejects unknown syntax, callees or packed ABIs. It
does not interpret original instructions or evaluate recovered C at runtime.
Native preserved-code fixtures, rather than this build, establish behavior.
"""
import hashlib
import json
import re
from pathlib import Path
import translate_drawing as drawing
from pycparser import c_ast

EDITION = Path(__file__).resolve().parents[1]
SHA = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
ROUTINES = {
    0x434f70: ('originalUpdateBoatWindAndAI', 1),
    0x435fe0: ('originalChooseDownwindHeading', 3),
    0x436400: ('originalScoreDownwindTurn', 3),
    0x436ba0: ('originalSampleSpatialWind', 3),
    0x437e60: ('originalUpdateUpwindTactics', 2),
    0x439100: ('originalUpdateCollisionAvoidance', 1),
    0x4391f0: ('originalAvoidAiCollision', 4),
    0x439a30: ('originalWarnHumanRightOfWay', 3),
    0x439df0: ('originalRequestRightOfWaySound', 1),
    0x488d70: ('originalSampleVenueWind', 3),
}
# Fixed complete implementations owned by the other engine modules. No caller
# may substitute a numeric helper with a host callback.
SHARED = {
    0x41bc20: ('wrapDegreesOnce', 1, False),
    0x41e000: ('scaledRandom', 1, False),
    0x41e3a0: ('signedDegrees', 1, False),
    0x427ee0: ('bearingFromVector', 2, True),
    0x42f330: ('sampleSpatialMetric', 3, True),
    0x431200: ('shorelineDirections', 2, True),
    0x435f90: ('updateTack', 1, False),
    0x437520: ('setClosehauledHeading', 1, False),
    0x437570: ('advanceRaceTarget', 1, True),
    0x437d40: ('signedStartDistance', 1, False),
    0x439e80: ('distanceToBoat', 3, False),
    0x439ec0: ('relativeProjection', 3, True),
    0x43ec20: ('targetRelativeBearing', 4, False),
    0x464050: ('aheadAstern', 2, True),
    0x47d5f0: ('sampleVenueMetric', 5, True),
    0x47def0: ('pointInXStrip', 8, False),
    0x47dfa0: ('pointInYStrip', 8, False),
    0x488b90: ('sampleAttenuationDistance', 4, True),
}

class NumericTranslator(drawing.Translator):
    def __init__(self, address, source):
        super().__init__(address, address, source, has_dc=False)
        self.parameters = [p for p in self.function.decl.type.args.params if isinstance(p, c_ast.Decl)]
        if len(self.parameters) != ROUTINES[address][1]:
            raise ValueError('Unrepaired original tactical argument count')
        # Tactical contracts contain only complete scalar I32 formals. They do
        # not share drawing's byte-addressable argument cells, which model
        # partial packed-F64 and CDC/CString alias stores. Keep this frontend's
        # direct scalar representation stable when the drawing backend evolves.
        for parameter in self.parameters:
            if drawing.base_type(parameter.type) not in ('int', 'uint', 'undefined4'):
                raise ValueError('Unreviewed non-I32 tactical formal')
            self.stack.pop(parameter.name)
        self.parameter_offsets = {}

    def expression_type(self, node):
        if isinstance(node, c_ast.Constant):
            return 'uint' if node.value.lower().endswith('u') else node.type
        return super().expression_type(node)

    def expr(self, node):
        if isinstance(node, c_ast.Cast):
            typ = drawing.base_type(node.to_type)
            if typ == 'double' and isinstance(node.expr, c_ast.BinaryOp) and node.expr.op == '<<':
                # Only the two exact compiler-generated 50/75 binary64 stack
                # literals in the collision helpers use this decompiler form.
                if self.routine_address not in (0x4391f0, 0x439a30) or not isinstance(node.expr.left, c_ast.ID) or self.types.get(node.expr.left.name) != 'longlong' or not re.search(r'\b' + node.expr.left.name + r'\s*=\s*0x40490000;', self.source) or not re.search(r'\b' + node.expr.left.name + r'\s*=\s*0x4052c000;', self.source) or not isinstance(node.expr.right, c_ast.Constant) or int(node.expr.right.value, 0) != 32:
                    raise ValueError('Unreviewed binary64 bit construction')
                return 'bitsAsF64(' + self.expr(node.expr) + ')'
            if typ in ('char', 'byte', 'undefined1'):
                return f'cI8({self.expr(node.expr)},{str(typ != "char").lower()})'
        if isinstance(node, c_ast.BinaryOp) and node.op == '>>' and self.expression_type(node.left) in ('uint', 'unsigned int'):
            return f'cUnsignedShift({self.expr(node.left)},{self.expr(node.right)})'
        return super().expr(node)

    def assign(self, node):
        left = node.lvalue
        if isinstance(left, c_ast.ID) and not drawing.symbol_address(left.name) and left.name not in self.stack:
            if left.name not in self.types:
                raise ValueError('Unbound tactical local store ' + left.name)
            typ = self.types[left.name]
            value = self.expr(node.rvalue)
            if node.op != '=':
                operation = {'+=': 'cAdd', '-=': 'cSub', '*=': 'cMul', '/=': 'cDiv', '%=': 'cRem'}[node.op]
                value = f'{operation}({self.expr(left)},{value})'
            if typ == 'double':
                value = f'cF64({value})'
            elif typ in ('float10', 'unkbyte10'):
                value = f'cFloat({value})'
            elif typ in ('longlong', 'ulonglong'):
                value = f'cI64({value},{str(typ == "ulonglong").lower()})'
            elif typ in ('char', 'byte', 'undefined1'):
                value = f'cI8({value},{str(typ != "char").lower()})'
            elif typ == 'bool':
                value = f'cTruth({value})'
            else:
                value = f'cI32({value},{str(typ == "uint").lower()})'
            return f'({left.name} = {value})'
        return super().assign(node)

    def call(self, node):
        if not isinstance(node.name, c_ast.ID):
            raise ValueError('No indirect numerical tactical calls accepted')
        name = node.name.name
        args = node.args.exprs if node.args else []
        values = [self.expr(arg) for arg in args]
        if name in ('SQRT', 'sqrt'):
            if len(values) != 1: raise ValueError('Invalid SQRT arity')
            return f'cFloat({values[0]}).sqrt()'
        if name == 'SBORROW4':
            if len(values) != 2: raise ValueError('Invalid signed-borrow arity')
            return 'signedBorrow32(' + ','.join(values) + ')'
        if name == 'PlaySoundA':
            if len(values) != 3: raise ValueError('Invalid original sound ABI')
            return 'aiSound(options,' + ','.join(values) + ')'
        match = re.fullmatch(r'FUN_([0-9a-fA-F]{8})', name)
        if not match:
            raise ValueError('Unreviewed tactical callee ' + name)
        address = int(match[1], 16)
        self.dependencies.add(address)
        if address in ROUTINES:
            function, count = ROUTINES[address]
            if len(values) != count: raise ValueError('Unrepaired tactical call ABI ' + name)
            return f'{function}(memory,rng,options,' + ','.join(values) + ')'
        if address not in SHARED:
            raise ValueError('Unknown numerical tactical dependency ' + name)
        function, count, options_argument = SHARED[address]
        if len(values) != count:
            raise ValueError('Unrepaired shared tactical ABI ' + name + ': ' + str(len(values)))
        if address in (0x41bc20, 0x41e3a0):
            return function + '(' + ','.join(values) + ')'
        if address == 0x41e000:
            return 'scaledRandom(' + values[0] + ',rng)'
        # Original floating call arguments are packed binary64 stores at the
        # call boundary; retained ST0 return values remain Float80 objects.
        if address == 0x439e80:
            values[1:] = [f'cFloat({value}).toNumber()' for value in values[1:]]
        if address == 0x43ec20:
            values[:2] = [f'cFloat({value}).toNumber()' for value in values[:2]]
        return function + '(memory,' + ','.join(values) + (',options' if options_argument else '') + ')'

    def generate(self, name):
        # Keep the numerical emitter explicit: drawing's packed formal-slot
        # bindings are a separate ABI contract and must not silently rewrite
        # this native-verified scalar frontend.
        end = self.node('return;')
        start = self.compile(self.function.body, end)
        for index in self.gotos:
            for label, target in self.labels.items():
                self.nodes[index] = self.nodes[index].replace('LABEL_' + label, str(target))
            if 'LABEL_' in self.nodes[index]:
                raise ValueError('Unresolved tactical goto')
        declarations = []
        for node in self.function.body.block_items:
            if not isinstance(node, c_ast.Decl) or node.name in self.ignored or node.name in self.stack:
                continue
            if isinstance(node.type, c_ast.ArrayDecl):
                declarations.append(f'let {node.name} = new Array({int(node.type.dim.value, 0)});')
            else:
                declarations.append(f'let {node.name};')
        bindings = [f'let {parameter.name} = originalArgs[{index}];' for index, parameter in enumerate(self.parameters)]
        lines = [
            f'/** Complete recovered original 0x{self.routine_address:08x}; static typed C control-flow translation. */',
            f'export function {name}(memory, rng, options = {{}}, ...originalArgs) {{',
            '  const r32 = address => memory.readI32(address), r64 = address => Float80.fromNumber(memory.readF64(address));',
            '  const w32 = (address,value) => memory.writeI32(address,cI32(value)), w64 = (address,value) => memory.writeF64(address,cFloat(value).toNumber());',
            f'  const localFrame=createLocalFrame({self.frame_size},options.retainedDrawingStack?.[{self.routine_address}]??[]);',
            *['  ' + binding for binding in bindings],
            *['  ' + declaration for declaration in declarations],
            f'  let pc = {start};', '  for (;;) { switch (pc) {',
        ]
        for index, code in enumerate(self.nodes):
            lines.append(f'    case {index}: {{ {code} }}')
        lines += ['    default: throw new Error("Unreachable original AI control-flow node");', '  } }', '}']
        return '\n'.join(lines)

IMPORTS = '''// Generated by tools/translate_ai.py from the preserved English 2010 C export.
import { Float80 } from '../../../../src/runtime/float80.js';
import { i8,u8,u32 } from '../../../../src/runtime/c-types.js';
import { wrapDegreesOnce,scaledRandom } from './application.js';
import { bearingFromVector } from './wind.js';
import { sampleSpatialMetric,sampleVenueMetric,sampleAttenuationDistance,pointInXStrip,pointInYStrip } from './spatial-metrics.js';
import { shorelineDirections } from './current.js';
import { advanceRaceTarget } from './race-targets.js';
import { distanceToBoat } from './movement.js';
import { signedDegrees,updateTack,setClosehauledHeading,signedStartDistance,relativeProjection,targetRelativeBearing,aheadAstern } from './ai-geometry.js';
import { cI32,cI64,cFloat,cF64,cAdd,cSub,cMul,cDiv,cRem,cNeg,cBits,cCompare,cTruth,pointerAdd,
  readPointer,writePointer,signedBorrow32,createLocalFrame,framePointer,readLocal,writeLocal,bitsAsF64 } from '../render/typed-c.js';
const cI8=(value,unsigned=false)=>(unsigned?u8:i8)(cI32(value));
const cUnsignedShift=(value,amount)=>u32(value) >>> cI32(amount);
const aiSound=(options,resourceId,moduleHandle,flags)=>options.playSound?.({resourceId:cI32(resourceId),moduleHandle:u32(moduleHandle),flags:u32(flags)})??0;
'''

def main():
    if hashlib.sha256((EDITION/'runtime/Tactics2010EnglishPreserved.exe').read_bytes()).hexdigest() != SHA:
        raise ValueError('Preserved source SHA differs')
    translated = []
    records = []
    for address, (name, count) in ROUTINES.items():
        path = EDITION/'decompiled/functions'/('%08x.c' % address)
        source = path.read_text()
        try:
            translator = NumericTranslator(address, source)
            translated.append(translator.generate(name))
        except Exception as error:
            raise RuntimeError('%08x: %s' % (address, error)) from error
        records.append({'address': address, 'name': name, 'argumentCount': count,
            'source': str(path.relative_to(EDITION)), 'sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
            'dependencies': sorted(translator.dependencies)})
    (EDITION/'src/engine/ai-functions.js').write_text(IMPORTS + '\n' + '\n\n'.join(translated) + '\n')
    (EDITION/'analysis/ai-translation-sources.json').write_text(json.dumps({'format': 1,
        'sourceSha256': SHA, 'tool': 'tools/translate_ai.py', 'parser': 'pycparser2.23', 'routines': records}, indent=2) + '\n')
    print('Translated %d complete original English tactical routines' % len(translated))

if __name__ == '__main__':
    main()
