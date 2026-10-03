#!/usr/bin/env python3
"""Build static controller ESM from the exact preserved 2010 English export.

Only the reviewed scalar keyboard/menu subtree is accepted. Unsupported C
syntax, global types, pointer operations and calls stop generation. There is no
runtime source evaluation, PE instruction interpreter or old-edition fallback.
"""
import hashlib
import json
import re
import sys
from pathlib import Path

EDITION = Path(__file__).resolve().parent.parent
ROOT = EDITION.parents[1]
sys.path.insert(0, str(ROOT/'tools/python-libs'))
from pycparser import c_parser, c_ast

SHA = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
F64 = {0x4cc580,0x4cc588,0x4cc650,0x4cc658,0x4cc700,0x4da230,0x4fe938}
PREFIX = 'typedef int undefined4,uint,bool,HWND,RECT,code; typedef long double float10;\n'
COMMON = '''import { i32 } from '../../../../src/runtime/c-types.js';
import { Float80 } from '../../../../src/runtime/float80.js';
import { wrapDegreesOnce, updateSpeedDivisor, scaledRandom } from './application.js';
import { controllerMemory, cI32, cFloat, cAdd, cSub, cMul, cDiv, cRem, cNeg, cBits, cCompare, cTruth } from './controller-values.js';
'''

def base_type(node):
    if isinstance(node,c_ast.IdentifierType): return ' '.join(node.names)
    if isinstance(node,(c_ast.TypeDecl,c_ast.Typename)): return base_type(node.type)
    if isinstance(node,c_ast.PtrDecl): return base_type(node.type)+'*'
    raise TypeError(type(node).__name__)

def address(name):
    match = re.fullmatch(r'_?DAT_([0-9a-fA-F]{8})',name)
    return int(match[1],16) if match else None

class Translator:
    def __init__(self,source,kind):
        text = re.sub(r'/\*.*?\*/','',source,flags=re.S)
        text = re.sub(r'__(?:cdecl|stdcall|thiscall|fastcall)\b','',text)
        text = re.sub(r'\bthis\b','originalThis',text)
        # Exactly the original HWND field; the host supplies this opaque handle.
        text = re.sub(r'\*\(HWND \*\)\(\(int\)originalThis \+ 0x1c\)','windowHandle',text)
        if kind == 'update':
            text = re.sub(r'\(\*\*\(code \*\*\)\*param_2\)\(', 'enable(', text)
            text = re.sub(r'\(\*\(code \*\)\*puVar1\)\(', 'enable(', text)
            text = re.sub(r'\(\*\(code \*\)puVar1\[1\]\)\(', 'check(', text)
            text = re.sub(r'\s*undefined4 \*puVar1;', '', text)
            text = re.sub(r'\s*puVar1 = \(undefined4 \*\)\*param_2;', '', text)
        self.function = c_parser.CParser().parse(PREFIX+text).ext[-1]
        self.types={item.name:base_type(item.type) for item in self.function.body.block_items if isinstance(item,c_ast.Decl)}
        self.kind=kind

    def pointer_scale(self,node):
        if isinstance(node,c_ast.UnaryOp) and node.op=='&' and isinstance(node.expr,c_ast.ID) and address(node.expr.name):return 1
        if isinstance(node,c_ast.Cast):
            typ=base_type(node.to_type)
            return 8 if typ=='double*' else 4 if typ in ('int*','uint*','undefined4*') else 1
        return 1

    def pointer(self,node):
        if isinstance(node,c_ast.UnaryOp) and node.op=='&' and isinstance(node.expr,c_ast.ID):
            target=address(node.expr.name)
            if target:return hex(target)
        raise ValueError(f'Unsupported controller address-of {type(node).__name__}')

    def expr(self,node):
        if isinstance(node,c_ast.ID):
            target=address(node.name)
            if target:return f'r{64 if target in F64 else 32}({hex(target)})'
            if node.name not in {*self.types,'param_2','param_3','param_4','originalThis','windowHandle'}:
                raise ValueError(f'Unbound controller ID {node.name}')
            return node.name
        if isinstance(node,c_ast.Constant):
            if node.type in ('float','double','long double'):return f'Float80.fromNumber({node.value.rstrip("fFlL")})'
            return str(int(re.sub(r'[uUlL]+$','',node.value),0))
        if isinstance(node,c_ast.Cast):
            typ=base_type(node.to_type);value=self.expr(node.expr)
            if typ in ('double','float10'):return f'cFloat({value})'
            if typ in ('uint','unsigned int'):return f'cI32({value},true)'
            if typ in ('int','undefined4','HWND','bool'):return f'cI32({value})'
            if typ.endswith('*'):return value
            raise ValueError(f'Unsupported cast {typ}')
        if isinstance(node,c_ast.BinaryOp):
            a,b=self.expr(node.left),self.expr(node.right)
            if node.op in ('+','-'):
                scale=self.pointer_scale(node.left)
                if scale!=1:b=f'cMul({b},{scale})'
                return f'{"cAdd" if node.op=="+" else "cSub"}({a},{b})'
            if node.op in ('*','/','%'):return f'{ {"*":"cMul","/":"cDiv","%":"cRem"}[node.op]}({a},{b})'
            if node.op in ('<','>','<=','>=','==','!='):return f'cCompare({a},{b},{json.dumps(node.op)})'
            if node.op in ('&&','||'):return f'(cTruth({a}) {node.op} cTruth({b}))'
            if node.op in ('&','|','^','<<','>>'):return f'cBits({a},{b},{json.dumps(node.op)})'
            raise ValueError(f'Unsupported binary {node.op}')
        if isinstance(node,c_ast.UnaryOp):
            if node.op=='&':return self.pointer(node)
            if node.op=='*':
                if not isinstance(node.expr,c_ast.Cast):raise ValueError('Unreviewed controller dereference')
                typ=base_type(node.expr.to_type)
                if typ not in ('int*','uint*','undefined4*','double*'):raise ValueError(f'Unsupported pointer {typ}')
                value=f'r{64 if typ=="double*" else 32}({self.expr(node.expr.expr)})'
                return f'cI32({value},true)' if typ=='uint*' else value
            if node.op=='-':return f'cNeg({self.expr(node.expr)})'
            if node.op=='+':return self.expr(node.expr)
            if node.op=='!':return f'!cTruth({self.expr(node.expr)})'
            if node.op=='~':return f'cBits({self.expr(node.expr)},0,"~")'
            raise ValueError(f'Unsupported unary {node.op}')
        if isinstance(node,c_ast.ArrayRef):return f'r32(cAdd({self.expr(node.name)},cMul({self.expr(node.subscript)},4)))'
        if isinstance(node,c_ast.Assignment):return self.assign(node)
        if isinstance(node,c_ast.ExprList):return '('+', '.join(self.expr(x) for x in node.exprs)+')'
        if isinstance(node,c_ast.TernaryOp):return f'(cTruth({self.expr(node.cond)}) ? {self.expr(node.iftrue)} : {self.expr(node.iffalse)})'
        if isinstance(node,c_ast.FuncCall):
            if not isinstance(node.name,c_ast.ID):raise ValueError('Unreviewed indirect controller call')
            args=node.args.exprs if node.args else [];name=node.name.name
            if name=='InvalidateRect':return 'invalidate('+self.expr(args[2])+')'
            if name=='FUN_00464940':return 'updateSpeedDivisor(memory)'
            if name=='FUN_0041bc20':return 'wrapDegreesOnce('+self.expr(args[0])+')'
            if name=='FUN_0041e000':return 'scaledRandom('+self.expr(args[0])+',options.rng)'
            if name=='FUN_004ac701':return 'options.defaultKeyHandler?.({key:param_2,repeat:param_3,flags:param_4})'
            if name in ('enable','check'):return name+'('+self.expr(args[0])+')'
            raise ValueError(f'Unreviewed controller call {name}')
        raise ValueError(f'Unsupported expression {type(node).__name__}')

    def assign(self,node):
        if node.op!='=':raise ValueError(f'Unsupported assignment {node.op}')
        left=node.lvalue;value=self.expr(node.rvalue)
        if isinstance(left,c_ast.ID):
            target=address(left.name)
            if target:return f'w{64 if target in F64 else 32}({hex(target)},{value})'
            typ=self.types.get(left.name)
            if typ is None:raise ValueError(f'Unbound local store {left.name}')
            return f'({left.name} = '+(f'cFloat({value})' if typ in ('double','float10') else f'cI32({value},true)' if typ=='uint' else f'cI32({value})')+')'
        if isinstance(left,c_ast.UnaryOp) and left.op=='*' and isinstance(left.expr,c_ast.Cast):
            typ=base_type(left.expr.to_type)
            if typ not in ('int*','uint*','undefined4*','double*'):raise ValueError(f'Unsupported store pointer {typ}')
            return f'w{64 if typ=="double*" else 32}({self.expr(left.expr.expr)},{value})'
        if isinstance(left,c_ast.ArrayRef):return f'w32(cAdd({self.expr(left.name)},cMul({self.expr(left.subscript)},4)),{value})'
        raise ValueError(f'Unsupported controller lvalue {type(left).__name__}')

    def statements(self,node,indent=2):
        pad=' '*indent
        if isinstance(node,c_ast.Compound):return '\n'.join(self.statements(x,indent) for x in node.block_items or [] if not isinstance(x,c_ast.Decl))
        if isinstance(node,c_ast.Return):return pad+'return'+(' '+self.expr(node.expr) if node.expr else '')+';'
        if isinstance(node,c_ast.If):
            value=pad+'if (cTruth('+self.expr(node.cond)+')) {\n'+self.statements(node.iftrue,indent+2)+'\n'+pad+'}'
            if node.iffalse:value+=' else {\n'+self.statements(node.iffalse,indent+2)+'\n'+pad+'}'
            return value
        if isinstance(node,(c_ast.Assignment,c_ast.FuncCall,c_ast.ExprList)):return pad+self.expr(node)+';'
        if isinstance(node,c_ast.EmptyStatement):return ''
        raise ValueError(f'Unsupported controller statement {type(node).__name__}')

    def generate(self,name):
        out=[f'function {name}(memory,options = {{}}) {{', '  const {r32,r64,w32,w64}=controllerMemory(memory);',
             '  const windowHandle=options.windowHandle ?? 0;',
             '  const invalidate=erase => options.invalidateRect?.({windowHandle,rectangle:null,erase:cI32(erase)});']
        if self.kind=='keyboard':out+=['  const param_2=i32(options.key),param_3=i32(options.repeat ?? 1),param_4=i32(options.flags ?? 0);']
        if self.kind=='update':out+=['  const enable=value=>options.enable(cI32(value));','  const check=value=>options.check(cI32(value));']
        if self.types:out+=['  let '+','.join(self.types)+';']
        out+=[self.statements(self.function.body),'}']
        return '\n'.join(out)

def main():
    source=EDITION/'runtime/Tactics2010EnglishPreserved.exe'
    if hashlib.sha256(source.read_bytes()).hexdigest()!=SHA:raise SystemExit('Preserved English executable SHA mismatch')
    maps=json.loads((EDITION/'analysis/message-map-candidates.json').read_text())
    if maps['source_sha256']!=SHA:raise SystemExit('Message-map source mismatch')
    main=max(maps['tables'],key=lambda x:len(x['entries']))
    directory=EDITION/'decompiled/functions';records=[]
    def build(va,kind,name):
        file=directory/f'{va:08x}.c';text=file.read_text()
        records.append({'address':f'{va:08x}','kind':kind,'source_sha256':hashlib.sha256(file.read_bytes()).hexdigest()})
        try:return Translator(text,kind).generate(name)
        except Exception as error:raise RuntimeError(f'{va:08x} {kind}: {error}') from error
    keyboard=COMMON+'\n'+build(0x491db0,'keyboard','originalKeyDown')+'\n\nexport const KEYBOARD_ROUTINES=Object.freeze({handleKeyDown:0x491db0});\nexport function handleKeyDown(memory,key,options={}) { return originalKeyDown(memory,{...options,key}); }\n'
    (EDITION/'src/engine/keyboard.js').write_text(keyboard)
    commands={};updates={};functions=[]
    for entry in main['entries']:
        if entry['nMessage']!=0x111:continue
        va=int(entry['functionVA'],16);key=entry['nID']
        if entry['nCode']==0:
            commands[key]=va
            if key in (32823,32779):continue
            functions.append(build(va,'command',f'command{key}'))
        elif entry['nCode']==0xffffffff:
            updates[key]=va;functions.append(build(va,'update',f'update{key}'))
        else:raise ValueError('Unreviewed command notification')
    output=COMMON+'\n'+'\n\n'.join(functions)+'\n\n'
    output+='export const MENU_COMMAND_ROUTINES=Object.freeze('+json.dumps(commands,separators=(',',':'))+');\n'
    output+='export const MENU_UPDATE_ROUTINES=Object.freeze('+json.dumps(updates,separators=(',',':'))+');\n'
    output+='const commands=Object.freeze({'+','.join(f'{key}:command{key}' for key in commands if key not in (32823,32779))+'});\n'
    output+='const updates=Object.freeze({'+','.join(f'{key}:update{key}' for key in updates)+'});\n'
    output+='''
export function handleMenuCommand(memory,command,options={}) {
  command=i32(command);
  if (command===57664 || command===32823 || command===32779) {
    if (!options.dialogHandler) throw new TypeError('The original modal command requires a dialog host');
    const resourceId=command===57664 ? 100 : command===32823 ? 132 : 131;
    const tail=()=>{
      if (command!==57664) {
        memory.writeI32(0x5363b4,0);
        options.invalidateRect?.({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:command===32823 ? 1 : 0});
        if (command===32779) memory.writeI32(0x4da140,2);
      }
      return true;
    };
    const result=options.dialogHandler(resourceId,memory,options);
    return result && typeof result.then==='function' ? Promise.resolve(result).then(tail) : tail();
  }
  if (command===57665) { options.closeWindow?.();return true; }
  if (command===59393) { options.contextHelp?.();return true; }
  const handler=commands[command];
  if (!handler) return false;
  handler(memory,options);
  return true;
}

export function menuCommandState(memory,command,previous={enabled:true,checked:0}) {
  command=i32(command);
  const result={...previous,events:[]};
  const handler=updates[command];
  if (handler) handler(memory,{
    enable:value=>{result.enabled=value!==0;result.events.push({type:'enable',value});},
    check:value=>{result.checked=value;result.events.push({type:'check',value});},
  });
  return result;
}
'''
    (EDITION/'src/engine/menu-controller.js').write_text(output)
    table=['/* Fixed exact-English MFC table; source SHA '+SHA+'. */',
           'static const struct controller_entry controller_entries[] = {']
    for key,va in commands.items():
        table.append(f'  {{{key},0x{0 if key in (32823,32779) else va:08x},0x{updates[key]:08x}}},')
    table+=['};','static const uint32_t controller_dialog_entries[][2] = {']
    for message_map in maps['tables']:
        resource={'004c8008':132,'004c83e8':131}.get(message_map['sourceVA'])
        if resource:
            for entry in message_map['entries']:
                if entry['nMessage']!=0x111 or entry['nCode']!=0:raise ValueError('Unexpected radio ABI')
                table.append(f'  {{0x{resource<<16|entry["nID"]:08x},0x{int(entry["functionVA"],16):08x}}},')
    table+=['};','']
    (EDITION/'tools/native_controller_table.h').write_text('\n'.join(table))
    evidence={'source_sha256':SHA,'method':'Static typed translation of the exact edition-local C; unknown syntax/calls rejected; original target-code fixtures still required.','functions':records}
    (EDITION/'analysis/controller-source-translation.json').write_text(json.dumps(evidence,indent=2)+'\n')
    print(f'Generated keyboard, {len(commands)} commands and {len(updates)} update handlers; {len(records)} reviewed C bodies.')

if __name__=='__main__':main()
