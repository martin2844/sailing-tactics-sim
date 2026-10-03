#!/usr/bin/env python3
"""Emit bounded, static JavaScript for reviewed original tutorial C.

This build tool parses the recovered C; it does not execute the PE or emit an
instruction interpreter. Unsupported syntax/callees stop generation. The
generated functions are subsequently checked against complete original calls.
Requires pycparser 2.23 (tools/python-libs is the locally verified wheel).
"""
import hashlib
import json
import re
from pathlib import Path
from pycparser import c_parser, c_ast

ROOT = Path(__file__).resolve().parent.parent
PAGES = {101:0x435b50,102:0x436300,103:0x436960,104:0x4372d0,105:0x437950,
106:0x438330,107:0x438c30,108:0x439600,109:0x439f20,110:0x43a5d0,300:0x43a9b0,
501:0x43b910,502:0x43c100,503:0x43ccd0,504:0x43e070,505:0x43f460,506:0x440d20,
507:0x442740,508:0x443bf0,509:0x445830,510:0x445ee0,511:0x446570,512:0x446a90,
513:0x4479e0,514:0x449ef0,601:0x44b220,602:0x44b9e0,603:0x44c120,604:0x44c950,
701:0x44d140,400:0x41beb0}
PREFIX = '''typedef int code,CDC,HDC,HGDIOBJ,undefined,undefined1,undefined2,undefined4,uint,LPCSTR,LONG,POINT,LPPOINT,bool,byte,ushort;
typedef long long longlong; typedef unsigned long long ulonglong;
typedef long double float10; typedef struct {char *data;} TactCString;
'''
IGNORED = {'uStack_4','pcStack_8','uStack_c','unaff_FS_OFFSET'}
F64 = set()
for line in (ROOT/'analysis/original-disassembly.txt').read_text().splitlines():
    if 'QWORD PTR' in line:
        match = re.search(r'QWORD PTR[^\n]*0x([0-9a-f]{6})',line)
        if match: F64.add(int(match[1],16))

def base_type(node):
    if isinstance(node,c_ast.IdentifierType):return ' '.join(node.names)
    if isinstance(node,c_ast.TypeDecl):return base_type(node.type)
    if isinstance(node,c_ast.PtrDecl):return base_type(node.type)+'*'
    if isinstance(node,c_ast.ArrayDecl):return base_type(node.type)+'[]'
    if isinstance(node,c_ast.Typename):return base_type(node.type)
    if isinstance(node,c_ast.Struct):return node.name
    raise TypeError(type(node).__name__)

def symbol_address(name):
    match=re.search(r'_([0-9a-fA-F]{8})$',name)
    return int(match[1],16) if match else None

def skip(node):
    if isinstance(node,c_ast.Assignment):
        target=node.lvalue
        if isinstance(target,c_ast.StructRef):target=target.name
        return isinstance(target,c_ast.ID) and target.name in IGNORED or (
            isinstance(target,c_ast.UnaryOp) and target.op=='*' and isinstance(target.expr,c_ast.ID) and target.expr.name=='unaff_FS_OFFSET')
    return False

class Translator:
    def __init__(self,selector,address,source):
        self.selector,self.routine_address,self.source=selector,address,source
        text=re.sub(r'/\*.*?\*/','',source,flags=re.S).replace('__cdecl','').replace('__thiscall','')
        text=re.sub(r'uStack_4\._[0-9]_[0-9]_','uStack_4',text)
        text=re.sub(r'([A-Za-z_][A-Za-z_0-9]*)::',r'\1_',text)
        text=re.sub(r'\bthis\b','originalDc',text)
        self.function=c_parser.CParser().parse(PREFIX+text).ext[-1]
        self.types={};self.arrays=set();self.methods=set();self.nodes=[];self.labels={};self.gotos=[]
        for node in self.function.body.block_items:
            if isinstance(node,c_ast.Decl):
                self.types[node.name]=base_type(node.type)
                if isinstance(node.type,c_ast.ArrayDecl):self.arrays.add(node.name)
        self.types['param_1']='CDC*'

    def expression_type(self,node):
        if isinstance(node,c_ast.ID):return self.types.get(node.name,'int')
        if isinstance(node,c_ast.Cast):return base_type(node.to_type)
        if isinstance(node,c_ast.UnaryOp) and node.op=='&':return self.expression_type(node.expr)+'*'
        if isinstance(node,c_ast.StructRef):return 'char*'
        return 'int'

    def pointer_scale(self,node):
        if isinstance(node,c_ast.UnaryOp) and node.op=='&' and isinstance(node.expr,c_ast.ID) and symbol_address(node.expr.name):return 1
        typ=self.expression_type(node)
        return 8 if typ in ('double*','float10*') else 4 if typ in ('int*','uint*','undefined4*','longlong*','int[]') else 1

    def method_offset(self,node):
        # Every virtual method in this subtree is reviewed against callsite evidence.
        while isinstance(node,(c_ast.Cast,c_ast.UnaryOp)):
            node=node.expr
        if isinstance(node,c_ast.BinaryOp) and node.op=='+' and isinstance(node.right,c_ast.Constant):
            offset=int(node.right.value,0)
            if offset in (0x2c,0x34,0x38,0x64):return offset
        return None

    def address(self,node):
        if isinstance(node,c_ast.ID):
            address=symbol_address(node.name)
            if address:return hex(address)
            if node.name in self.arrays:return f'localPointer({node.name})'
            return node.name
        if isinstance(node,c_ast.StructRef):return self.address(node.name)
        if isinstance(node,c_ast.Cast):return self.address(node.expr)
        if isinstance(node,c_ast.UnaryOp) and node.op=='&':return self.address(node.expr)
        if isinstance(node,c_ast.ArrayRef):return f'pointerAdd({self.address(node.name)}, cMul({self.expr(node.subscript)}, 4))'
        return self.expr(node)

    def string_target(self,node):
        while isinstance(node,(c_ast.Cast,c_ast.UnaryOp)):
            node=node.expr
        if isinstance(node,c_ast.ID) and node.name in self.arrays:return node.name+'[0]'
        return self.address(node)

    def expr(self,node):
        if isinstance(node,c_ast.ID):
            address=symbol_address(node.name)
            if address:
                if node.name.startswith('s_'):return f'readAnsiString(memory,{hex(address)})'
                if node.name.startswith(('_DAT_','DAT_')):return f'r{64 if address in F64 else 32}({hex(address)})'
                if node.name.startswith('FUN_'):raise ValueError(f'Unbound function value {node.name}')
            if node.name in self.arrays:return f'localPointer({node.name})'
            if node.name=='SelectObject_exref':return 'selectGdiObject.bind(null,dc)'
            return node.name
        if isinstance(node,c_ast.Constant):
            if node.type in ('float','double','long double'):return f'Float80.fromNumber({node.value.rstrip("fFlL")})'
            return str(int(re.sub(r'[uUlL]+$','',node.value),0))
        if isinstance(node,c_ast.Cast):
            value=self.expr(node.expr);typ=base_type(node.to_type)
            if typ in ('longlong','ulonglong'):return f'cI64({value},{str(typ=="ulonglong").lower()})'
            if typ in ('double','float10'):return f'cFloat({value})'
            if typ in ('int','uint','undefined4','LONG'):return f'cI32({value},{str(typ=="uint").lower()})'
            return value
        if isinstance(node,c_ast.BinaryOp):
            a,b=self.expr(node.left),self.expr(node.right)
            if node.op in ('+','-'):
                scale=self.pointer_scale(node.left)
                if scale!=1:b=f'cMul({b},{scale})'
                return f'{"cAdd" if node.op=="+" else "cSub"}({a},{b})'
            if node.op in ('*','/','%'):return f'{dict(zip(("*","/","%"),("cMul","cDiv","cRem")))[node.op]}({a},{b})'
            if node.op in ('<','>','<=','>=','==','!='):return f'cCompare({a},{b},{json.dumps(node.op)})'
            if node.op in ('&&','||'):return f'(cTruth({a}) {node.op} cTruth({b}))'
            if node.op in ('&','|','^','<<','>>'):return f'cBits({a},{b},{json.dumps(node.op)})'
            raise ValueError(f'Unsupported binary {node.op}')
        if isinstance(node,c_ast.UnaryOp):
            if node.op=='&':return self.address(node.expr)
            if node.op=='*':
                offset=self.method_offset(node)
                if offset is not None:return f'dcMethod(dc,{offset})'
                if isinstance(node.expr,c_ast.Cast):
                    typ=base_type(node.expr.to_type)
                    if typ=='code*':return self.expr(node.expr.expr)
                    address=self.expr(node.expr.expr)
                    if typ in ('double*','float10*'):return f'readPointer(memory,{address},8)'
                    if typ in ('HDC*',):return 'dc'
                    return f'readPointer(memory,{address},4)'
                return f'readPointer(memory,{self.expr(node.expr)},4)'
            if node.op=='-':return f'cNeg({self.expr(node.expr)})'
            if node.op=='+':return self.expr(node.expr)
            if node.op=='!':return f'(!cTruth({self.expr(node.expr)}))'
            if node.op=='~':return f'cBits({self.expr(node.expr)},0,"~")'
            if node.op in ('p++','p--','++','--'):
                target=self.expr(node.expr);step=self.pointer_scale(node.expr);op='cAdd' if '+' in node.op else 'cSub'
                return f'({target} = {op}({target},{step}))'
            raise ValueError(f'Unsupported unary {node.op}')
        if isinstance(node,c_ast.StructRef):return self.expr(node.name) if node.field.name=='data' else f'{self.expr(node.name)}.{node.field.name}'
        if isinstance(node,c_ast.ArrayRef):
            if isinstance(node.name,c_ast.ID) and node.name.name in self.arrays:return f'{node.name.name}[cI32({self.expr(node.subscript)})]'
            return f'readPointer(memory,pointerAdd({self.expr(node.name)},cMul({self.expr(node.subscript)},{self.pointer_scale(node.name)})),4)'
        if isinstance(node,c_ast.FuncCall):return self.call(node)
        if isinstance(node,c_ast.Assignment):return self.assign(node)
        if isinstance(node,c_ast.TernaryOp):return f'(cTruth({self.expr(node.cond)}) ? {self.expr(node.iftrue)} : {self.expr(node.iffalse)})'
        if isinstance(node,c_ast.ExprList):return '('+', '.join(self.expr(n) for n in node.exprs)+')'
        raise ValueError(f'Unsupported expression {type(node).__name__}')

    def assign(self,node):
        left=node.lvalue;value=self.expr(node.rvalue)
        if node.op!='=':value=f'{dict(zip(("+=","-=","*=","/=","%="),("cAdd","cSub","cMul","cDiv","cRem")))[node.op]}({self.expr(left)},{value})'
        if isinstance(left,c_ast.ID):
            address=symbol_address(left.name)
            if address:return f'w{64 if address in F64 else 32}({hex(address)},{value})'
            return f'({left.name} = {value})'
        if isinstance(left,c_ast.StructRef) and left.field.name=='data':return f'({self.expr(left.name)} = {value})'
        if isinstance(left,c_ast.ArrayRef):return f'({self.expr(left)} = {value})'
        if isinstance(left,c_ast.UnaryOp) and left.op=='*':
            typ=base_type(left.expr.to_type) if isinstance(left.expr,c_ast.Cast) else 'int*'
            addr=self.expr(left.expr.expr) if isinstance(left.expr,c_ast.Cast) else self.expr(left.expr)
            return f'writePointer(memory,{addr},{value},{8 if typ in ("double*","float10*") else 4})'
        raise ValueError(f'Unsupported assignment {type(left).__name__}')

    def call(self,node):
        args=node.args.exprs if node.args else []
        name=node.name.name if isinstance(node.name,c_ast.ID) else None
        if name in ('FUN_0046bec5',):return 'undefined'
        if name in ('FUN_0046bf33','FUN_0046c00d','FUN_0046bd8a','FUN_0046bfbe'):
            target=self.string_target(args[0]);return f'({target} = cString(memory,{self.expr(args[1])}))'
        if name=='FUN_0046bd7a':return f'({self.string_target(args[0])} = "")'
        if name=='FUN_00413d00':return f'({self.string_target(args[0])} = formatInteger(cI32({self.expr(args[1])})))'
        if name in ('FUN_0046c0db','FUN_0046c075','FUN_0046c14f'):
            a=self.expr(args[1]);b=self.expr(args[2]);return f'({self.string_target(args[0])} = cString(memory,{a}) + cString(memory,{b}))'
        calls={'FUN_00411000':'drawBoat','FUN_0042cd40':'drawSceneMark','FUN_0042f0d0':'drawSceneLayline',
          'FUN_0044d830':'drawTutorialAdvanceHint','FUN_0044d6d0':'drawTutorialAdvanceButton',
          'FUN_00416990':'selectBoatTextColor','FUN_0042cca0':'sortSceneDepths'}
        if name in calls:
            rest=args if name=='FUN_0042cca0' else args[1:]
            values=', '.join(self.expr(arg) for arg in rest)
            suffix=', rng, options' if name=='FUN_00411000' else ', options' if name=='FUN_0042f0d0' else ''
            return f'{calls[name]}(memory,{" " if name=="FUN_0042cca0" else " dc,"} {values}{suffix})'
        if name=='FUN_004706bd':return f'writeLocalPoint({self.address(args[1])},dc.moveTo({self.expr(args[2])},{self.expr(args[3])}))'
        imported={'SelectObject':'selectObject','Rectangle':'rectangle','Ellipse':'ellipse','LineTo':'lineTo','SetTextColor':'setTextColor','SetBkColor':'setBkColor','SetBkMode':'setBkMode','RoundRect':'roundRect','Arc':'arc','Pie':'pie','CDC_LineTo':'lineTo'}
        if name=='SelectObject':return f'selectGdiObject(dc,{self.expr(args[1])})'
        if name in imported:return f'dc.{imported[name]}('+','.join(self.expr(arg) for arg in args[1:])+')'
        if name=='Polygon':return f'dc.polygon(originalPoints(memory,{self.address(args[1])},{self.expr(args[2])}))'
        if name=='GetStockObject':return f'stockObject({self.expr(args[0])})'
        if name=='TextOutA':return f'dc.textOut({self.expr(args[1])},{self.expr(args[2])},{self.expr(args[3])})'
        offset=self.method_offset(node.name)
        if offset is not None:
            methods={0x2c:'selectStockObject',0x34:'setBkColor',0x38:'setTextColor',0x64:'textOut'}
            used=args[1:4] if offset==0x64 else args[1:2]
            return f'dc.{methods[offset]}('+','.join(self.expr(arg) for arg in used)+')'
        if isinstance(node.name,c_ast.UnaryOp) and node.name.op=='*':
            # Original function pointer aliases are only reviewed CDC methods.
            if isinstance(node.name.expr,c_ast.ID):self.methods.add(node.name.expr.name)
            used=args[1:4] if len(args)==5 else args[1:]
            return f'{self.expr(node.name.expr)}('+','.join(self.expr(arg) for arg in used)+')'
        if name:raise ValueError(f'Unsupported callee {name}')
        raise ValueError('Unsupported indirect call')

    def node(self,code):
        number=len(self.nodes);self.nodes.append(code);return number
    def compile(self,node,next_node,break_to=None,continue_to=None):
        if node is None:return next_node
        if isinstance(node,c_ast.Compound):
            for item in reversed(node.block_items or []):next_node=self.compile(item,next_node,break_to,continue_to)
            return next_node
        if isinstance(node,c_ast.Decl) or skip(node):return next_node
        if isinstance(node,c_ast.Return):return self.node('return;')
        if isinstance(node,c_ast.Label):
            target=self.compile(node.stmt,next_node,break_to,continue_to);self.labels[node.name]=target;return target
        if isinstance(node,c_ast.Goto):
            index=self.node(f'pc = LABEL_{node.name}; continue;');self.gotos.append(index);return index
        if isinstance(node,c_ast.If):
            yes=self.compile(node.iftrue,next_node,break_to,continue_to);no=self.compile(node.iffalse,next_node,break_to,continue_to)
            return self.node(f'pc = cTruth({self.expr(node.cond)}) ? {yes} : {no}; continue;')
        if isinstance(node,(c_ast.While,c_ast.DoWhile,c_ast.For)):
            condition=self.node('');inc=condition
            if isinstance(node,c_ast.For) and node.next:inc=self.compile(node.next,condition,next_node,condition)
            body=self.compile(node.stmt,inc,next_node,inc)
            cond=self.expr(node.cond) if node.cond else 'true'
            self.nodes[condition]=f'pc = cTruth({cond}) ? {body} : {next_node}; continue;'
            if isinstance(node,c_ast.For):return self.compile(node.init,condition,break_to,continue_to)
            return body if isinstance(node,c_ast.DoWhile) else condition
        if isinstance(node,c_ast.Break):return self.node(f'pc = {break_to}; continue;')
        if isinstance(node,c_ast.Continue):return self.node(f'pc = {continue_to}; continue;')
        if isinstance(node,c_ast.EmptyStatement):return next_node
        return self.node(f'{self.expr(node)}; pc = {next_node}; continue;')

    def generate(self):
        end=self.node('return;');start=self.compile(self.function.body,end)
        for i in self.gotos:
            for name,target in self.labels.items():self.nodes[i]=self.nodes[i].replace('LABEL_'+name,str(target))
            if 'LABEL_' in self.nodes[i]:raise ValueError('Unresolved goto')
        declarations=[]
        for node in self.function.body.block_items:
            if isinstance(node,c_ast.Decl) and node.name not in IGNORED:
                if isinstance(node.type,c_ast.ArrayDecl):declarations.append(f'let {node.name} = new Array({int(node.type.dim.value,0)});')
                else:declarations.append(f'let {node.name};')
        lines=[f'/** Complete recovered original 0x{self.routine_address:08x}; static C control-flow translation. */',f'export function drawTutorial{self.selector}(memory, dc, rng, options = {{}}) {{',
          '  const r32 = address => memory.readI32(address), r64 = address => Float80.fromNumber(memory.readF64(address));',
          '  const w32 = (address,value) => memory.writeI32(address,cI32(value)), w64 = (address,value) => memory.writeF64(address,cFloat(value).toNumber());',
          '  let param_1 = dc;',*['  '+d for d in declarations],f'  let pc = {start};','  for (;;) { switch (pc) {']
        for i,code in enumerate(self.nodes):lines.append(f'    case {i}: {{ {code} }}')
        lines+=['    default: throw new Error("Unreachable tutorial control-flow node");','  } }','}']
        return '\n'.join(lines)

def main():
    output=[];records=[]
    for selector,address in PAGES.items():
        path=ROOT/f'analysis/screen-corrections/{address:08x}.c'
        source=path.read_text()
        try:translated=Translator(selector,address,source).generate()
        except Exception as error:raise RuntimeError(f'{selector} {address:08x}: {error}') from error
        output.append(translated);records.append({'selector':selector,'address':address,'source':str(path.relative_to(ROOT)),'sha256':hashlib.sha256(source.encode()).hexdigest()})
    imports='''// Generated by tools/translate_tutorial_sources.py from reviewed recovered C.
// Validate complete functions against original-tutorials.json before changing source.
import { Float80 } from '../runtime/float80.js';
import { formatInteger, readAnsiString } from '../engine/hud-state.js';
import { drawBoat } from './boat.js';
import { drawSceneMark, sortSceneDepths } from './scene-objects.js';
import { drawSceneLayline } from './shore.js';
import { selectBoatTextColor, drawTutorialAdvanceButton, drawTutorialAdvanceHint } from './tutorial-controls.js';
import { cI32,cI64,cFloat,cAdd,cSub,cMul,cDiv,cRem,cNeg,cBits,cCompare,cTruth,cString,
  pointerAdd,localPointer,readPointer,writePointer,writeLocalPoint,stockObject,dcMethod,selectGdiObject,originalPoints } from './tutorial-source.js';
'''
    (ROOT/'src/render/tutorial-pages.js').write_text(imports+'\nexport const TUTORIAL_PAGE_ROUTINES = Object.freeze('+json.dumps({f'drawTutorial{k}':v for k,v in PAGES.items()})+');\n\n'+'\n\n'.join(output)+'\n')
    (ROOT/'analysis/tutorial-translation-sources.json').write_text(json.dumps({'tool':'translate_tutorial_sources.py','parser':'pycparser2.23','sources':records},indent=2)+'\n')
    print('Translated',len(output),'complete original pages')

if __name__=='__main__':main()
