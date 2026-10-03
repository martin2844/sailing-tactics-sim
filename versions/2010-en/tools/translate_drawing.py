#!/usr/bin/env python3
"""Emit bounded, static JavaScript for reviewed original tutorial C.

This build tool parses the recovered C; it does not execute the PE or emit an
instruction interpreter. Unsupported syntax/callees stop generation. The
generated functions are subsequently checked against complete original calls.
Requires pycparser 2.23 (tools/python-libs is the locally verified wheel).
"""
import hashlib
import ast
import json
import re
from pathlib import Path
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[3]/"tools/python-libs"))
from pycparser import c_parser, c_ast

ROOT = Path(__file__).resolve().parent.parent
PAGES = {1:0x445860,2:0x446250,3:0x446a70,4:0x4471e0,5:0x4479f0,6:0x448100,7:0x448970,8:0x4495e0,
10:0x449ee0,11:0x44a5d0,12:0x44b0e0,101:0x44b930,102:0x44c0f0,103:0x44c750,104:0x44d0c0,
105:0x44d690,106:0x44e240,107:0x44eb90,108:0x44f5c0,109:0x44fee0,110:0x450590,300:0x450970,
501:0x451e60,502:0x452660,503:0x453230,504:0x4545d0,505:0x4559c0,506:0x457280,507:0x458ca0,
508:0x45a150,509:0x45bd90,510:0x45c440,511:0x45cad0,512:0x45cff0,513:0x45df40,514:0x460470,
601:0x4617a0,602:0x461f60,603:0x4626a0,604:0x462ed0,701:0x4636c0,400:0x4282b0}
PREFIX = '''typedef int code,CDC,HDC,HGDIOBJ,HBRUSH,HPEN,HRGN,COLORREF,DWORD,BOOL,undefined,undefined1,undefined2,undefined3,undefined4,undefined8,uint,LPCSTR,LONG,POINT,LPPOINT,bool,byte,ushort;
typedef long long longlong; typedef unsigned long long ulonglong;
typedef long double float10,unkbyte10; typedef struct {char *data;} Tact2010CString;
typedef struct {int x;int y;} tagPOINT;
'''
IGNORED = {'unaff_FS_OFFSET'}
REVIEWED_DC_INDICES={}
for abi_path in sorted((ROOT/'analysis').glob('*-abi-review.json')):
    abi=json.loads(abi_path.read_text())
    if abi['sourceSha256']!='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787':raise ValueError('Drawing ABI report source differs')
    for row in abi['routines']:
        packed=row['packedTypes']
        if 'C' in packed:
            if packed.count('C')!=1:raise ValueError('Drawing ABI must have exactly one CDC object')
            REVIEWED_DC_INDICES[int(row['address'],16)]=packed.index('C')
F64 = set()
GLOBAL_POINTER_SIZES={}
for row in map(json.loads,(ROOT/'decompiled/defined-data.jsonl').read_text().splitlines()):
    typ=row['type'];base=re.sub(r'\[[^]]*\]','',typ)
    size=8 if base in ('double','undefined8','longlong','ulonglong') else 4 if base in ('int','uint','undefined4','long','ulong','float','pointer') or base.endswith(' *') else 2 if base in ('short','ushort','undefined2','wchar_t') else 1
    GLOBAL_POINTER_SIZES[int(row['address'],16)]=size
# Exact original floating loads/stores distinguish floating doubles from qword integers.
import capstone, pefile
binary=ROOT/'runtime/Tactics2010EnglishPreserved.exe'
raw=binary.read_bytes()
if hashlib.sha256(raw).hexdigest()!='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787':raise ValueError('Fixed source SHA mismatch')
pe=pefile.PE(data=raw);dis=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);dis.detail=True
FORECAST_LITERALS={}
literal_path=ROOT/'analysis/forecast-literal-pointers.json'
if literal_path.exists():
    evidence=json.loads(literal_path.read_text())
    if evidence['sourceSha256']!=hashlib.sha256(raw).hexdigest() or evidence['routineAddress']!=0x4298f0:raise ValueError('Forecast literal evidence targets another original')
    for item in evidence['pointers']+[evidence['emptyLiteralEvidence']]:
        address=item['address'];instruction=item['instruction'];encoded=item['string'].encode('windows-1252')+b'\0'
        if pe.get_data(instruction-0x400000,len(bytes.fromhex(item['bytes'])))!=bytes.fromhex(item['bytes']):raise ValueError('Forecast literal instruction evidence differs')
        if pe.get_data(address-0x400000,len(encoded))!=encoded:raise ValueError('Forecast literal data evidence differs')
        previous=FORECAST_LITERALS.get(item['string'])
        if previous is not None and previous!=address:raise ValueError('Forecast literal has ambiguous original addresses')
        FORECAST_LITERALS[item['string']]=address
# This one recovered numeric cast is an original pair of DWORD bit writes,
# followed by FLD QWORD, rather than an integer-to-double conversion. Keep the
# repair bound to independently reviewed original instructions and source.
binary64_evidence=json.loads((ROOT/'analysis/scene-binary64-constant-construction.json').read_text())
if binary64_evidence['sourceSha256']!=hashlib.sha256(raw).hexdigest() or int(binary64_evidence['routine'],16)!=0x466330:raise ValueError('Scene binary64 evidence targets another original')
for item in binary64_evidence['constructionInstructions']+binary64_evidence['floatingReadInstructions']:
    address=int(item['address'],16);encoded=bytes.fromhex(item['bytes'])
    if pe.get_data(address-0x400000,len(encoded))!=encoded:raise ValueError('Scene binary64 instruction evidence differs')
scene_source=ROOT/'analysis/drawing-corrections/00466330.c'
if not scene_source.exists():scene_source=ROOT/'decompiled/functions/00466330.c'
if hashlib.sha256(scene_source.read_bytes()).hexdigest()!=binary64_evidence['recoveredSourceSha256']:raise ValueError('Scene binary64 recovered expression must be reviewed again')
# This recovered product was reassociated by the decompiler. At PC53, the
# original scale*factor rounding precedes width multiplication and can change
# the subsequent integer truncation. Validate the exact original instructions
# and recovered source before restoring that association in the AST emitter.
roof_order_evidence=json.loads((ROOT/'analysis/venue-roof-multiplication-order-review.json').read_text())
if roof_order_evidence['sourceSha256']!=hashlib.sha256(raw).hexdigest() or int(roof_order_evidence['routineAddress'],16)!=0x4813f0:raise ValueError('Roof product evidence targets another original')
for item in roof_order_evidence['originalNumericalInstructions']:
    address=int(item['address'],16);encoded=bytes.fromhex(item['bytes'])
    if pe.get_data(address-0x400000,len(encoded))!=encoded:raise ValueError('Roof product instruction evidence differs')
text=pe.sections[0]
for row in map(json.loads,(ROOT/'decompiled/functions.jsonl').read_text().splitlines()):
    for span in row['body_ranges']:
        first,last=int(span['start'],16),int(span['end'],16)
        if first<0x401000 or last>=0x4c7316:continue
        for instruction in dis.disasm(pe.get_data(first-0x400000,last-first+1),first):
            if instruction.mnemonic in ('fld','fst','fstp','fadd','fsub','fsubr','fmul','fdiv','fdivr','fcom','fcomp'):
                for operand in instruction.operands:
                    if operand.type==capstone.x86_const.X86_OP_MEM and operand.size==8 and 0x4c8000<=(operand.mem.disp&0xffffffff)<0x600000:F64.add(operand.mem.disp & 0xffffffff)

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

def skip(node,ignored=IGNORED):
    if isinstance(node,c_ast.Assignment):
        # SEH registration reads/writes host FS. A same-named stack slot in a
        # function without SEH can be real geometry and must remain translated.
        def has_fs(value):
            if isinstance(value,c_ast.ID) and value.name=='unaff_FS_OFFSET':return True
            return any(has_fs(child) for _name,child in value.children())
        if has_fs(node.lvalue) or has_fs(node.rvalue):return True
        target=node.lvalue
        if isinstance(target,c_ast.StructRef):target=target.name
        return isinstance(target,c_ast.ID) and target.name in ignored or (
            isinstance(target,c_ast.UnaryOp) and target.op=='*' and isinstance(target.expr,c_ast.ID) and target.expr.name=='unaff_FS_OFFSET')
    return False

class Translator:
    def __init__(self,selector,address,source,has_dc=True):
        if address==0x4813f0 and hashlib.sha256(source.encode()).hexdigest()!=roof_order_evidence['sourceHashes']['analysis/drawing-corrections/004813f0.c']:
            raise ValueError('Roof product recovered expression must be reviewed again')
        self.roof_order_rewrites=0
        self.selector,self.routine_address,self.source=selector,address,source
        self.has_dc=has_dc or address in REVIEWED_DC_INDICES
        self.dc_index=REVIEWED_DC_INDICES.get(address,0) if self.has_dc else None
        self.dependencies=set()
        self.ignored=set(IGNORED)
        seh=re.search(r'\*unaff_FS_OFFSET\s*=',source)
        setup=source[:seh.start()] if seh else ''
        self.seh_handlers=set(re.findall(r'\b(FUN_004c[0-9a-f]+)\s*;',setup))
        def sanitize_code(text):
            text=text.replace('__cdecl','').replace('__thiscall','').replace('__stdcall','').replace('__fastcall','')
            text=re.sub(r'(?<![A-Za-z_0-9])s_[^\s(),;]*_([0-9a-fA-F]{8})',lambda m:'s_literal_'+m.group(1),text)
            for ignored in self.ignored:text=re.sub(r'\b'+re.escape(ignored)+r'\._[0-9]_[0-9]_',ignored,text)
            text=re.sub(r'([A-Za-z_][A-Za-z_0-9]*)::',r'\1_',text)
            return re.sub(r'\bthis\b','originalDc',text)
        # Preserve literal contents exactly. Renaming C++ identifiers inside a
        # quoted English sentence would silently change the original drawing.
        pieces=[];cursor=0
        literal_pattern=r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/'
        for match in re.finditer(literal_pattern,source,re.S):
            pieces.append(sanitize_code(source[cursor:match.start()]))
            pieces.append('' if match.group().startswith('/*') else match.group());cursor=match.end()
        pieces.append(sanitize_code(source[cursor:]));text=''.join(pieces)
        self.function=c_parser.CParser().parse(PREFIX+text).ext[-1]
        self.types={};self.arrays=set();self.methods=set();self.nodes=[];self.labels={};self.gotos=[]
        for node in self.function.body.block_items:
            if isinstance(node,c_ast.Decl):
                self.types[node.name]=base_type(node.type)
                if isinstance(node.type,c_ast.ArrayDecl):self.arrays.add(node.name)
        for p in self.function.decl.type.args.params if self.function.decl.type.args else []:
            if isinstance(p,c_ast.Decl):self.types[p.name]=base_type(p.type)
        if self.has_dc:self.types['param_%d'%(self.dc_index+1)]='int*'
        self.stack={}
        for name,typ in self.types.items():
            match=re.fullmatch(r'(?:local|[A-Za-z]+Stack)_([0-9a-f]+)',name)
            if match and name not in self.ignored and (not typ.startswith('Tact2010CString') or address==0x4298f0):
                self.stack[name]=int(match[1],16)
        self.frame_size=max(self.stack.values(),default=0)+256
        # C can overwrite only the low DWORD of a packed double argument, or
        # reuse an argument slot for a saved CDC/CString pointer. Keep argument
        # storage byte-addressable instead of treating scalar values as pointers.
        self.parameter_offsets={};offset=0
        for parameter in self.function.decl.type.args.params if self.function.decl.type.args else []:
            if not isinstance(parameter,c_ast.Decl):continue
            size,_kind=self.scalar_kind(parameter.name)
            if offset+size>256:raise ValueError('Reviewed C argument frame exceeds fixed bound')
            self.parameter_offsets[parameter.name]=offset
            self.stack[parameter.name]=self.frame_size-offset;offset+=size

    def local_address(self,name):return f'framePointer(localFrame,{self.frame_size-self.stack[name]})'
    def scalar_kind(self,name):
        typ=self.types[name]
        return (8,'float') if typ in ('double','float10','unkbyte10','undefined8') else (8,'int') if typ in ('longlong','ulonglong') else (1,'int') if typ in ('char','byte','undefined1') else (2,'int') if typ in ('ushort','undefined2') else (4,'int')

    def expression_type(self,node):
        if isinstance(node,c_ast.ID):return self.types.get(node.name,'int')
        if isinstance(node,c_ast.Cast):return base_type(node.to_type)
        if isinstance(node,c_ast.UnaryOp) and node.op=='&':return self.expression_type(node.expr)+'*'
        if isinstance(node,c_ast.BinaryOp) and node.op in ('+','-'):
            left=self.expression_type(node.left)
            if left.endswith(('*','[]')):return left
        if isinstance(node,c_ast.StructRef):return 'char*'
        return 'int'

    def pointer_scale(self,node):
        if isinstance(node,c_ast.UnaryOp) and node.op=='&' and isinstance(node.expr,c_ast.ID) and symbol_address(node.expr.name):return GLOBAL_POINTER_SIZES.get(symbol_address(node.expr.name),1)
        typ=self.expression_type(node)
        if typ.endswith('[]'):base=typ[:-2]
        elif typ.endswith('*'):base=typ[:-1]
        else:return 1
        if base.endswith('*'):return 4
        if base in ('double','undefined8','longlong','ulonglong','tagPOINT','POINT'):return 8
        if base in ('int','uint','undefined4','LONG','DWORD','COLORREF','HDC','HGDIOBJ','Tact2010CString'):return 4
        if base in ('ushort','short','undefined2'):return 2
        if base in ('float10','unkbyte10'):return 10
        return 1

    def array_scale(self,node):
        if isinstance(node,c_ast.UnaryOp) and node.op=='&' and isinstance(node.expr,c_ast.ID) and symbol_address(node.expr.name):
            return GLOBAL_POINTER_SIZES.get(symbol_address(node.expr.name),4)
        return self.pointer_scale(node)

    def method_offset(self,node):
        # Every virtual method in this subtree is reviewed against callsite evidence.
        while isinstance(node,(c_ast.Cast,c_ast.UnaryOp)):
            node=node.expr
        if isinstance(node,c_ast.BinaryOp) and node.op=='+' and isinstance(node.right,c_ast.Constant):
            offset=int(node.right.value,0)
            if offset in (0x2c,0x30,0x34,0x38,0x64):return offset
        return None

    def address(self,node):
        if isinstance(node,c_ast.ID):
            address=symbol_address(node.name)
            if address:return hex(address)
            if node.name in self.stack:return self.local_address(node.name)
            if node.name in self.arrays:return f'localPointer({node.name})'
            return node.name
        if isinstance(node,c_ast.StructRef):return self.address(node.name)
        if isinstance(node,c_ast.Cast):return self.address(node.expr)
        if isinstance(node,c_ast.UnaryOp) and node.op=='&':return self.address(node.expr)
        if isinstance(node,c_ast.ArrayRef):
            base=self.address(node.name) if isinstance(node.name,c_ast.ID) and node.name.name in self.arrays else self.expr(node.name)
            return f'pointerAdd({base}, cMul({self.expr(node.subscript)}, {self.array_scale(node.name)}))'
        return self.expr(node)

    def string_assignment(self,node,value):
        while isinstance(node,(c_ast.Cast,c_ast.UnaryOp)):node=node.expr
        if isinstance(node,c_ast.ID) and symbol_address(node.name):return f'writeCString(memory,{hex(symbol_address(node.name))},{value})'
        if isinstance(node,c_ast.ID) and node.name in self.stack:return f'writeLocal({self.local_address(node.name)},{value},4)'
        return f'({self.string_target(node)} = {value})'

    def string_target(self,node):
        while isinstance(node,(c_ast.Cast,c_ast.UnaryOp)):
            node=node.expr
        if isinstance(node,c_ast.ID) and node.name in self.arrays:return node.name+'[0]'
        return self.address(node)

    def header_base(self,node):
        while isinstance(node,c_ast.Cast):node=node.expr
        if not isinstance(node,c_ast.BinaryOp) or node.op not in ('+','-'):return None
        right=node.right
        if isinstance(right,c_ast.Constant):amount=int(right.value,0)
        elif isinstance(right,c_ast.UnaryOp) and right.op=='-' and isinstance(right.expr,c_ast.Constant):amount=-int(right.expr.value,0)
        else:return None
        return node.left if amount*(1 if node.op=='+' else -1)==-8 else None

    def word_expr(self,node):
        while isinstance(node,c_ast.Cast) and base_type(node.to_type) in ('undefined4','int','uint'):node=node.expr
        if isinstance(node,c_ast.ID) and symbol_address(node.name):return f'r32({hex(symbol_address(node.name))})'
        return f'cRawWord({self.expr(node)})'

    def expr(self,node):
        if isinstance(node,c_ast.ID):
            if node.name in ('Ellipse_exref','Polygon_exref','SelectObject_exref','TextOutA_exref'):
                return f'importDrawingMethod(dc,memory,{json.dumps(node.name[:-6])})'
            address=symbol_address(node.name)
            if address:
                # A literal is still an address when strlen/copy code reads
                # bytes or DWORDs and advances char*. CString/TextOut bindings
                # explicitly decode this actual localized data address.
                if node.name.startswith('s_'):return hex(address)
                if node.name.startswith(('_DAT_','DAT_')):
                    if address==0x4fdfd4 or 0x4fec30<=address<0x4fecbc and address%4==0:return f'readCString(memory,{hex(address)})'
                    return f'r{64 if address in F64 else 32}({hex(address)})'
                if node.name.startswith('FUN_'):raise ValueError(f'Unbound function value {node.name}')
            if node.name in self.stack:
                if node.name in self.arrays:return self.local_address(node.name)
                size,kind=self.scalar_kind(node.name)
                return f'readLocal({self.local_address(node.name)},{size},{json.dumps(kind)})'
            if node.name in self.arrays:return f'localPointer({node.name})'
            if node.name=='SelectObject_exref':return 'selectGdiObject.bind(null,dc)'
            return node.name
        if isinstance(node,c_ast.Constant):
            if node.type=='string':
                value=ast.literal_eval(node.value)
                if self.routine_address==0x4298f0:
                    if value not in FORECAST_LITERALS:raise ValueError('Forecast quoted literal lacks original pointer evidence: '+repr(value))
                    return hex(FORECAST_LITERALS[value])
                return json.dumps(value,ensure_ascii=False)
            if node.type=='char':return str(ord(ast.literal_eval(node.value)))
            if node.type in ('float','double','long double'):return f'Float80.fromNumber({node.value.rstrip("fFlL")})'
            return str(int(re.sub(r'[uUlL]+$','',node.value),0))
        if isinstance(node,c_ast.Cast):
            typ=base_type(node.to_type)
            if typ=='HDC':return 'dc'
            if (typ=='double' and self.routine_address==0x466330 and isinstance(node.expr,c_ast.BinaryOp)
                and node.expr.op=='<<' and isinstance(node.expr.left,c_ast.ID) and node.expr.left.name=='lVar15'
                and isinstance(node.expr.right,c_ast.Constant) and int(node.expr.right.value,0)==32):
                return f'bitsAsF64(cBits(cI64({self.expr(node.expr.left)}),32,"<<"))'
            value=self.expr(node.expr)
            if typ in ('longlong','ulonglong'):return f'cI64({value},{str(typ=="ulonglong").lower()})'
            if typ=='double':return f'bitsAsF64({value})' if isinstance(node.expr,c_ast.FuncCall) and isinstance(node.expr.name,c_ast.ID) and node.expr.name.name.startswith('CONCAT') else f'cF64({value})'
            if typ in ('float10','unkbyte10'):return f'cFloat({value})'
            if typ=='undefined4':return self.word_expr(node.expr)
            if typ in ('int','uint','LONG'):return f'cI32({value},{str(typ=="uint").lower()})'
            return value
        if isinstance(node,c_ast.BinaryOp):
            if (self.routine_address==0x4813f0 and node.op=='*'
                and isinstance(node.left,c_ast.BinaryOp) and node.left.op=='*'
                and isinstance(node.left.right,c_ast.ID) and node.left.right.name=='fVar5'
                and isinstance(node.right,c_ast.Cast) and base_type(node.right.to_type)=='float10'
                and isinstance(node.right.expr,c_ast.ID) and symbol_address(node.right.expr.name)==0x4ccff0):
                self.roof_order_rewrites+=1
                return f'cMul({self.expr(node.left.left)},cMul({self.expr(node.left.right)},{self.expr(node.right)}))'
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
                if offset is not None:return f'dcMethod(dc,{offset},memory)'
                if isinstance(node.expr,c_ast.Cast) and isinstance(node.expr.expr,c_ast.BinaryOp) and node.expr.expr.op in ('+','-'):
                    offset=node.expr.expr.right
                    amount=int(offset.value,0) if isinstance(offset,c_ast.Constant) else -int(offset.expr.value,0) if isinstance(offset,c_ast.UnaryOp) and offset.op=='-' and isinstance(offset.expr,c_ast.Constant) else None
                    if amount is not None and amount * (1 if node.expr.expr.op=='+' else -1)==-8:
                        return f'cStringHeaderLength(memory,{self.expr(node.expr.expr.left)})'
                if isinstance(node.expr,c_ast.Cast):
                    typ=base_type(node.expr.to_type)
                    if typ=='code*':return self.expr(node.expr.expr)
                    address=self.expr(node.expr.expr)
                    if typ in ('double*','float10*'):return f'readPointer(memory,{address},8)'
                    if typ in ('HDC*',):return 'dc'
                    return f'readPointer(memory,{address},{self.pointer_scale(node.expr)})'
                return f'readPointer(memory,{self.expr(node.expr)},{self.pointer_scale(node.expr)})'
            if node.op=='-':return f'cNeg({self.expr(node.expr)})'
            if node.op=='+':return self.expr(node.expr)
            if node.op=='!':return f'(!cTruth({self.expr(node.expr)}))'
            if node.op=='~':return f'cBits({self.expr(node.expr)},0,"~")'
            if node.op in ('p++','p--','++','--'):
                target=self.expr(node.expr);step=self.pointer_scale(node.expr);op='cAdd' if '+' in node.op else 'cSub'
                return f'({target} = {op}({target},{step}))'
            raise ValueError(f'Unsupported unary {node.op}')
        if isinstance(node,c_ast.StructRef):
            match=re.fullmatch(r'_([0-9]+)_([0-9]+)_',node.field.name)
            if match:
                typ=self.expression_type(node.name)
                if isinstance(node.name,c_ast.ID) and not symbol_address(node.name.name) and node.name.name not in self.stack and typ in ('double','float10','unkbyte10','undefined8','longlong','ulonglong'):
                    kind='integer' if typ in ('longlong','ulonglong','undefined8') else 'extended' if typ in ('float10','unkbyte10') else 'float'
                    return f'cRawSlice({self.expr(node.name)},{match[1]},{match[2]},{json.dumps(kind)})'
                return f'readPointer(memory,pointerAdd({self.address(node.name)},{match[1]}),{match[2]})'
            if node.field.name in ('x','y'):return f'readPointer(memory,pointerAdd({self.address(node.name)},{4 if node.field.name=="y" else 0}),4)'
            if node.type=='->':
                header=self.header_base(node.name)
                if header is not None:return f'cStringHeaderLength(memory,{self.expr(header)})'
                return f'readPointer(memory,{self.expr(node.name)},4)'
            return f'cStringData(memory,{self.expr(node.name)})' if node.field.name=='data' else f'{self.expr(node.name)}.{node.field.name}'
        if isinstance(node,c_ast.ArrayRef):
            if isinstance(node.subscript,c_ast.UnaryOp) and node.subscript.op=='-' and isinstance(node.subscript.expr,c_ast.Constant) and int(node.subscript.expr.value,0)==2 and self.pointer_scale(node.name)==4:
                return f'cStringHeaderLength(memory,{self.expr(node.name)})'
            if isinstance(node.name,c_ast.ID) and node.name.name in self.arrays and node.name.name not in self.stack:return f'{node.name.name}[cI32({self.expr(node.subscript)})]'
            size=self.array_scale(node.name)
            base=self.address(node.name) if isinstance(node.name,c_ast.ID) and node.name.name in self.arrays else self.expr(node.name)
            return f'readPointer(memory,pointerAdd({base},cMul({self.expr(node.subscript)},{size})),{size})'
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
            if left.name in self.stack:
                size,kind=self.scalar_kind(left.name)
                return f'writeLocal({self.local_address(left.name)},{value},{size},{json.dumps(kind)})'
            return f'({left.name} = {value})'
        if isinstance(left,c_ast.StructRef) and left.field.name=='data':
            if isinstance(left.name,c_ast.ID) and left.name.name in self.stack:return f'writeLocal({self.local_address(left.name.name)},{value},4)'
            return f'({self.expr(left.name)} = {value})'
        if isinstance(left,c_ast.ArrayRef):
            if isinstance(left.name,c_ast.ID) and left.name.name in self.arrays and left.name.name not in self.stack:return f'({self.expr(left)} = {value})'
            return f'writePointer(memory,{self.address(left)},{value},{self.array_scale(left.name)})'
        if isinstance(left,c_ast.StructRef):
            match=re.fullmatch(r'_([0-9]+)_([0-9]+)_',left.field.name)
            if match:return f'writePointer(memory,pointerAdd({self.address(left.name)},{match[1]}),{value},{match[2]})'
            if left.field.name in ('x','y'):return f'writePointer(memory,pointerAdd({self.address(left.name)},{4 if left.field.name=="y" else 0}),{value},4)'
        if isinstance(left,c_ast.UnaryOp) and left.op=='*':
            addr=self.expr(left.expr.expr) if isinstance(left.expr,c_ast.Cast) else self.expr(left.expr)
            return f'writePointer(memory,{addr},{value},{self.pointer_scale(left.expr)})'
        raise ValueError(f'Unsupported assignment {type(left).__name__}')

    def call(self,node):
        args=node.args.exprs if node.args else []
        name=node.name.name if isinstance(node.name,c_ast.ID) else None
        if name in ('FUN_004b05a5',):return 'undefined'
        if name in ('SQRT','sqrt'):return f'cFloat({self.expr(args[0])}).sqrt()'
        if name in ('sin','cos','fsin','fcos'):return f'originalTrig({self.expr(args[0])},options).'+('sine' if name in ('sin','fsin') else 'cosine')
        if name=='fpatan':return f'originalAtan({self.expr(args[0])},{self.expr(args[1])},options)'
        if name=='ABS':return f'cAbs({self.expr(args[0])})'
        if name and re.fullmatch(r'CONCAT[1-8][1-8]',name):
            values=[self.word_expr(arg) if int(width)<=4 else self.expr(arg) for arg,width in zip(args,name[-2:])]
            return f'cConcat({values[0]},{values[1]},{name[-2]},{name[-1]})'
        if name in ('FUN_004b0613','FUN_004b06ed','FUN_004b046a','FUN_004b069e'):
            return self.string_assignment(args[0],f'cString(memory,{self.expr(args[1])})')
        if name=='FUN_004b045a':return self.string_assignment(args[0],'""')
        if name=='FUN_0041bc70':return self.string_assignment(args[0],f'formatInteger(cI32({self.expr(args[1])}))')
        if name in ('FUN_004b0755','FUN_004b07bb','FUN_004b082f'):
            a=self.expr(args[1]);b=self.expr(args[2]);return self.string_assignment(args[0],f'cString(memory,{a}) + cString(memory,{b})')
        if name=='FUN_0041bd00':return self.string_assignment(args[0],f'formatDecimal(memory,cFloat({self.expr(args[1])}).toNumber())')
        if name=='FUN_004b4d9d':return f'writeLocalPoint({self.address(args[1])},dc.moveTo({self.expr(args[2])},{self.expr(args[3])}))'
        if name=='FUN_004b4994':return f'selectOriginalGdiObject(dc,memory,{self.expr(args[1])})'
        dc_calls={'FUN_004b4a1f':'setBkMode','FUN_004b4de9':'lineTo','FUN_004b49e7':'setBkColor','FUN_004b4a57':'setTextColor','FUN_004b48fc':'selectStockObject'}
        if name in dc_calls:return f'dc.{dc_calls[name]}('+','.join(self.expr(arg) for arg in args[1:])+')'
        if name and re.fullmatch(r'FUN_[0-9a-fA-F]{8}',name):
            address=int(name[4:],16)
            self.dependencies.add(address)
            values=', '.join(self.argument_expr(arg) for arg in args)
            return f'callDrawingDependency(memory,dc,{hex(address)},[{values}],rng,options)'
        imported={'SelectObject':'selectObject','Rectangle':'rectangle','Ellipse':'ellipse','LineTo':'lineTo','SetTextColor':'setTextColor','SetBkColor':'setBkColor','SetBkMode':'setBkMode','RoundRect':'roundRect','Arc':'arc','Pie':'pie','CDC_LineTo':'lineTo'}
        if name=='CreateRectRgn':return 'clipRegion('+','.join(self.expr(arg) for arg in args)+')'
        if name=='DeleteObject':return 'undefined'
        if name=='SelectObject':return f'selectGdiObject(dc,{self.expr(args[1])})'
        if name in imported:return f'dc.{imported[name]}('+','.join(self.expr(arg) for arg in args[1:])+')'
        if name=='Polygon':return f'dc.polygon(originalPoints(memory,{self.address(args[1])},{self.expr(args[2])}))'
        if name in ('SetPixel','GetPixel'):return f'dc.{"setPixel" if name=="SetPixel" else "getPixel"}('+','.join(self.expr(arg) for arg in args[1:])+')'
        if name=='MessageBeep':return f'dc.messageBeep({self.expr(args[0])})'
        if name=='PlaySoundA':return f'drawingSound(options,{self.expr(args[0])},{self.expr(args[1])},{self.expr(args[2])})'
        if name=='SBORROW4':return 'signedBorrow32('+','.join(self.expr(arg) for arg in args)+')'
        if name=='GetTickCount':return 'drawingTick(options)'
        if name=='GetSystemMetrics':return f'drawingSystemMetric({self.expr(args[0])},options)'
        if name=='GetCursorPos':return f'writeLocalPoint({self.address(args[0])},drawingCursor(options))'
        if name=='wsprintfA':return 'drawingPrintf(memory,'+self.address(args[0])+','+','.join(self.expr(arg) for arg in args[1:])+')'
        if name=='GetStockObject':return f'stockObject({self.expr(args[0])})'
        if name=='TextOutA':return 'textOutCount(dc,memory,'+','.join(self.expr(arg) for arg in args[1:5])+')'
        offset=self.method_offset(node.name)
        if offset is not None:
            return f'invokeDrawingPointer(dcMethod(dc,{offset},memory),dc,['+','.join(self.expr(arg) for arg in args)+'])'
        if isinstance(node.name,c_ast.UnaryOp) and node.name.op=='*':
            # Original function pointer aliases are only reviewed CDC methods.
            if isinstance(node.name.expr,c_ast.ID):self.methods.add(node.name.expr.name)
            return f'invokeDrawingPointer({self.expr(node.name.expr)},dc,['+','.join(self.expr(arg) for arg in args)+'])'
        if name:raise ValueError(f'Unsupported callee {name}')
        raise ValueError('Unsupported indirect call')

    def argument_expr(self,node):
        # The original PUSH can transfer an ambient stack word into an unused
        # parameter. Keep that word unknown until the callee actually reads it.
        if isinstance(node,c_ast.ID) and node.name in self.stack and node.name not in self.arrays:
            size,kind=self.scalar_kind(node.name)
            return f'readLocalArgument({self.local_address(node.name)},{size},{json.dumps(kind)})'
        if isinstance(node,c_ast.Cast) and base_type(node.to_type) in ('int','uint','LONG','undefined4') and isinstance(node.expr,c_ast.ID) and node.expr.name in self.stack:
            size,kind=self.scalar_kind(node.expr.name)
            if size==4:
                unsigned=base_type(node.to_type)=='uint'
                return f'cWordArgument(readLocalArgument({self.local_address(node.expr.name)},4,{json.dumps(kind)}),{str(unsigned).lower()})'
        return self.expr(node)

    def node(self,code):
        number=len(self.nodes);self.nodes.append(code);return number
    def compile(self,node,next_node,break_to=None,continue_to=None):
        if node is None:return next_node
        if isinstance(node,c_ast.Compound):
            for item in reversed(node.block_items or []):next_node=self.compile(item,next_node,break_to,continue_to)
            return next_node
        if isinstance(node,c_ast.Decl) or skip(node,self.ignored):return next_node
        if isinstance(node,c_ast.Assignment):
            value=node.rvalue
            while isinstance(value,c_ast.Cast):value=value.expr
            if isinstance(value,c_ast.ID) and value.name in self.seh_handlers:return next_node
        if isinstance(node,c_ast.Return):return self.node('return '+self.expr(node.expr)+';' if node.expr is not None else 'return;')
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

    def generate(self,name=None):
        end=self.node('return;');start=self.compile(self.function.body,end)
        if self.routine_address==0x4813f0 and self.roof_order_rewrites!=1:
            raise ValueError('Expected exactly one original roof multiplication-order repair')
        for i in self.gotos:
            for label_name,target in self.labels.items():self.nodes[i]=self.nodes[i].replace('LABEL_'+label_name,str(target))
            if 'LABEL_' in self.nodes[i]:raise ValueError('Unresolved goto')
        declarations=[]
        for node in self.function.body.block_items:
            if isinstance(node,c_ast.Decl) and node.name not in self.ignored:
                if node.name in self.stack:continue
                if isinstance(node.type,c_ast.ArrayDecl):declarations.append(f'let {node.name} = new Array({int(node.type.dim.value,0)});')
                else:declarations.append(f'let {node.name};')
        name=name or f'drawTutorial{self.selector}'
        original_params=self.function.decl.type.args.params if self.function.decl.type.args else []
        parameters=[p for p in original_params if isinstance(p,c_ast.Decl)]
        bindings=[]
        for index,p in enumerate(parameters):
            value='dc' if index==self.dc_index else f'originalArgs[{index-int(self.dc_index is not None and index>self.dc_index)}]'
            if base_type(p.type)=='double':value=f'({value}===undefined?undefined:cF64({value}))'
            size,kind=self.scalar_kind(p.name)
            bindings.append(f'writeLocal({self.local_address(p.name)},{value},{size},{json.dumps(kind)});')
        shore_frame=self.routine_address==0x440400
        lines=[f'/** Complete recovered original 0x{self.routine_address:08x}; static C control-flow translation. */',f'export function {name}(memory, dc, rng, options = {{}}, ...originalArgs) {{',
          '  const r32 = address => memory.readI32(address), r64 = address => Float80.fromNumber(memory.readF64(address));',
          '  const w32 = (address,value) => memory.writeI32(address,cI32(value)), w64 = (address,value) => memory.writeF64(address,cFloat(value).toNumber());',
          f'  const localFrame=createLocalFrame({self.frame_size},options.retainedDrawingStack?.[{self.routine_address}]??[]);',
          *(['  restoreShoreStackFrame(localFrame,options.shoreStack);'] if shore_frame else []),
          *['  '+binding for binding in bindings],*['  '+d for d in declarations],f'  let pc = {start};','  for (;;) { switch (pc) {']
        for i,code in enumerate(self.nodes):
            if shore_frame and code=='return;':code='saveShoreStackFrame(localFrame,options.shoreStack); return;'
            lines.append(f'    case {i}: {{ {code} }}')
        lines+=['    default: throw new Error("Unreachable tutorial control-flow node");','  } }','}']
        return '\n'.join(lines)

def main():
    output=[];records=[]
    screen_mode='--screens' in sys.argv
    helper_mode='--helpers' in sys.argv
    selected={'originalDrawMajorOptions':0x4148f0,'originalDrawVenueOptions':0x48cf50,'originalDrawCircle':0x433a70} if helper_mode else {'originalDrawStartScreen':0x413bc0,'originalDrawResultsScreen':0x428b70,'originalDrawForecastScreen':0x4298f0,'originalDrawAdvice':0x406590,'originalDrawPauseScreen':0x427f10,'originalDrawDemoScreen':0x416910,'originalDrawJibeAdvice':0x406680,'originalDrawTackAdvice':0x406e40} if screen_mode else {k:v for k,v in PAGES.items() if k<=8} if '--basic' in sys.argv else PAGES
    for selector,address in selected.items():
        path=ROOT/f'analysis/drawing-corrections/{address:08x}.c'
        if not path.exists():path=ROOT/f'decompiled/functions/{address:08x}.c'
        source=path.read_text()
        try:
            translator=Translator(selector,address,source);translated=translator.generate(selector if screen_mode or helper_mode else None)
        except Exception as error:raise RuntimeError(f'{selector} {address:08x}: {error}') from error
        output.append(translated);records.append({'selector':selector,'address':address,'source':str(path.relative_to(ROOT)),'sha256':hashlib.sha256(source.encode()).hexdigest(),'dependencies':sorted(translator.dependencies)})
    imports='''// Generated by tools/translate_drawing.py; behavior requires unchanged 2010 native comparison.
import { Float80 } from '../../../../src/runtime/float80.js';
import { formatInteger, formatDecimal, readAnsiString, readAnsiBytes,readCString,writeCString,cStringData } from './text.js';
import { drawingTick,drawingSystemMetric,drawingPrintf,drawingSound,drawingCursor } from './host.js';
import { callDrawingDependency, registerOriginalDrawing } from './dependencies.js';
import { restoreShoreStackFrame,saveShoreStackFrame } from './shore-stack.js';
import { cI32,cI64,cFloat,cAdd,cSub,cMul,cDiv,cRem,cNeg,cBits,cCompare,cTruth,cString,
  pointerAdd,localPointer,readPointer,writePointer,writeLocalPoint,stockObject,dcMethod,selectGdiObject,selectOriginalGdiObject,importDrawingMethod,originalPoints,clipRegion,textOutCount,originalTrig,cStringHeaderLength,signedBorrow32,
  cF64,cAbs,createLocalFrame,framePointer,readLocal,readLocalArgument,cWordArgument,writeLocal,originalAtan,cConcat,bitsAsF64,cRawWord,cRawSlice,invokeDrawingPointer } from './typed-c.js';
'''
    filename='screen-helper-functions.js' if helper_mode else 'render-functions.js' if screen_mode else 'tutorial-pages.js'
    names={k if screen_mode or helper_mode else f'drawTutorial{k}':v for k,v in selected.items()}
    (ROOT/('src/render/'+filename)).write_text(imports+'\nexport const '+('SCREEN_HELPER_ROUTINES' if helper_mode else 'SCREEN_ROUTINES' if screen_mode else 'TUTORIAL_PAGE_ROUTINES')+' = Object.freeze('+json.dumps(names)+');\n\n'+'\n\n'.join(output)+'\n'+''.join(f'registerOriginalDrawing({hex(address)},{name});\n' for name,address in names.items()))
    (ROOT/('analysis/screen-helper-translation-sources.json' if helper_mode else 'analysis/screen-translation-sources.json' if screen_mode else 'analysis/drawing-translation-sources.json')).write_text(json.dumps({'tool':'translate_drawing.py','parser':'pycparser2.23','sources':records},indent=2)+'\n')
    print('Translated',len(output),'complete original pages')

if __name__=='__main__':main()
