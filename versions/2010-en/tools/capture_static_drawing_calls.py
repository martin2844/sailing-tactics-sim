#!/usr/bin/env python3
"""Recover CDC/import aliases by bounded original x86 dataflow, without execution.

Only values proved on every predecessor path are retained. This evidence is
analyst metadata for the fixed English target; it neither edits nor runs it.
"""
import collections
import hashlib
import json
from pathlib import Path
import capstone
from capstone import x86_const as x
import pefile

ROOT=Path(__file__).resolve().parents[1]
SHA='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
VIRTUAL={0x2c:4,0x30:4,0x34:4,0x38:4,0x64:16}
IMPORT_ARGS={'MoveToEx':4,'LineTo':3,'Rectangle':5,'Ellipse':5,'Polygon':3,
 'SelectObject':2,'SetPixel':4,'SetTextColor':2,'SetBkColor':2,'SetBkMode':2,
 'TextOutA':5,'Arc':9,'Pie':9,'GetPixel':3,'GetStockObject':1,'GetSystemMetrics':1,
 'CreateRectRgn':4,'DeleteObject':1,'RoundRect':7,'MessageBeep':1,'GetTickCount':0,
 'SetRect':5,'PtInRect':3,'OffsetRect':3,'IntersectRect':3,'FillRect':3,
 'GetDeviceCaps':2,'CreateBitmap':5,'CreateCompatibleDC':1,'CreateCompatibleBitmap':3,
 'BitBlt':9,'InvalidateRect':3,'GetCursorPos':1,'ScreenToClient':2,'SetTimer':4,
 'KillTimer':2,'PlaySoundA':3,'GetLastError':0,'SetLastError':1,'TlsGetValue':1,
 'TlsSetValue':2,'GetCurrentThreadId':0}

def add(value, amount):
    return (value[0],value[1]+amount) if value and value[0] in ('stack','aligned-stack','address') else None

def merge(a,b):
    return ({k:v for k,v in a[0].items() if b[0].get(k)==v},
            {k:v for k,v in a[1].items() if b[1].get(k)==v})

def main():
    raw=(ROOT/'runtime/Tactics2010EnglishPreserved.exe').read_bytes()
    if hashlib.sha256(raw).hexdigest()!=SHA:raise ValueError('Fixed source SHA mismatch')
    pe=pefile.PE(data=raw);image=pe.get_memory_mapped_image();base=pe.OPTIONAL_HEADER.ImageBase
    dis=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);dis.detail=True
    rows=[json.loads(line) for line in (ROOT/'decompiled/functions.jsonl').read_text().splitlines()]
    instructions={};purges={}
    for row in rows:
        code={}
        for span in row['body_ranges']:
            start,end=int(span['start'],16),int(span['end'],16)+1
            code.update((i.address,i) for i in dis.disasm(image[start-base:end-base],start))
        entry=int(row['address'],16);instructions[entry]=code
        cleanup={i.operands[0].imm if i.operands else 0 for i in code.values() if i.mnemonic=='ret'}
        if len(cleanup)==1:purges[entry]=next(iter(cleanup))
    layout=json.loads((ROOT/'assets/data/source-layout.json').read_text())
    imports={b['address']:b.get('name', 'ordinal_'+str(b.get('ordinal',0))) for dll in layout['imports'] for b in dll['bindings']}
    previous=json.loads((ROOT/'analysis/drawing-corrections/drawing-signatures.json').read_text())
    dc_inputs={}
    for path in sorted((ROOT/'analysis').glob('*-abi-review.json')):
        review=json.loads(path.read_text())
        if review['sourceSha256']!=SHA:raise ValueError('CDC argument review belongs to another original')
        for row in review['routines']:
            kinds=row['packedTypes']
            if 'C' not in kinds:continue
            if kinds.count('C')!=1:raise ValueError('Ambiguous reviewed CDC receiver')
            if 'thiscall' in row.get('callingConvention',''):
                dc_inputs[int(row['address'],16)]=('ecx',None)
            else:
                dc_inputs[int(row['address'],16)]=('stack',4+sum(8 if kind=='D' else 4 for kind in kinds[:kinds.index('C')]))
    entries={int(r['function'],16) for r in previous['virtualCalls']}
    entries.update(int(r['address'],16) for r in previous['prototypes'] if int(r['address'],16)<0x49b930)
    calls={};import_calls={};unknown=[]
    for entry in sorted(entries):
        code=instructions[entry]
        receiver,offset=dc_inputs.get(entry,('stack',4))
        registers={'esp':('stack',0)};memory={}
        if receiver=='ecx':registers['ecx']=('dc',0)
        else:memory[('stack',offset)]=('dc',0)
        states={entry:(registers,memory)};queue=collections.deque([entry]);count=0
        local_calls={};local_imports={}
        while queue:
            address=queue.popleft();count+=1
            if count>200000:raise ValueError('Dataflow did not converge at '+hex(entry))
            i=code.get(address)
            if i is None:continue
            regs,mem=map(dict,states[address]);ops=i.operands
            def location(op):
                m=op.mem
                if m.index:return None
                if not m.base:return ('address',m.disp & 0xffffffff)
                return add(regs.get(i.reg_name(m.base)),m.disp)
            def read(op):
                if op.type==x.X86_OP_REG:return regs.get(i.reg_name(op.reg))
                if op.type==x.X86_OP_IMM:return ('address',op.imm & 0xffffffff)
                if op.type!=x.X86_OP_MEM:return None
                loc=location(op)
                if loc and loc[0] in ('stack','aligned-stack'):return mem.get(loc)
                if loc and loc[0]=='address' and loc[1] in imports:return ('import',imports[loc[1]])
                m=op.mem;parent=regs.get(i.reg_name(m.base)) if m.base else None
                if not m.index and parent==('dc',0) and m.disp==0:return ('vtable',0)
                if not m.index and parent==('vtable',0) and m.disp in VIRTUAL:return ('virtual',m.disp)
                return None
            def write(op,value):
                if op.type==x.X86_OP_REG:
                    name=i.reg_name(op.reg)
                    if value is None:regs.pop(name,None)
                    else:regs[name]=value
                elif op.type==x.X86_OP_MEM:
                    loc=location(op)
                    if loc and loc[0] in ('stack','aligned-stack'):
                        for key in list(mem):
                            if key[0]==loc[0] and key[1]<loc[1]+op.size and key[1]+4>loc[1]:mem.pop(key,None)
                        if value is not None and op.size==4:mem[loc]=value
            handled=set()
            if i.mnemonic=='mov' and len(ops)==2:write(ops[0],read(ops[1]));handled.add(i.reg_name(ops[0].reg) if ops[0].type==x.X86_OP_REG else '')
            elif i.mnemonic=='lea' and len(ops)==2:write(ops[0],location(ops[1]));handled.add(i.reg_name(ops[0].reg))
            elif i.mnemonic in ('add','sub') and len(ops)==2 and ops[0].type==x.X86_OP_REG and ops[1].type==x.X86_OP_IMM:
                write(ops[0],add(read(ops[0]),ops[1].imm*(1 if i.mnemonic=='add' else -1)));handled.add(i.reg_name(ops[0].reg))
            elif (i.mnemonic=='and' and len(ops)==2 and ops[0].type==x.X86_OP_REG
                  and i.reg_name(ops[0].reg)=='esp' and ops[1].type==x.X86_OP_IMM
                  and (ops[1].imm&0xffffffff)==0xfffffff8 and regs.get('esp')
                  and regs['esp'][0]=='stack'):
                # The exact aligned address depends on the caller. Keep the
                # newly allocated frame in a separate symbolic namespace; EBP
                # still addresses the known original argument frame. We prove
                # only pointers actually written within this frame, without
                # inventing either its alignment displacement or prior bytes.
                regs['esp']=('aligned-stack',0);handled.add('esp')
            elif i.mnemonic=='push':
                value=read(ops[0]);regs['esp']=add(regs.get('esp'),-4)
                if regs['esp']:
                    mem.pop(regs['esp'],None)
                    if value is not None:mem[regs['esp']]=value
                handled.add('esp')
            elif i.mnemonic=='pop':
                sp=regs.get('esp');write(ops[0],mem.get(sp) if sp else None);regs['esp']=add(sp,4)
                handled.update(['esp',i.reg_name(ops[0].reg)])
            elif i.mnemonic=='call':
                target=read(ops[0]);purge=None
                if target and target[0]=='virtual':
                    local_calls[address]=target[1];purge=VIRTUAL[target[1]]
                elif target and target[0]=='import':
                    local_imports[address]=target[1];purge=0 if target[1]=='wsprintfA' else 4*IMPORT_ARGS[target[1]] if target[1] in IMPORT_ARGS else None
                elif target and target[0]=='address':purge=purges.get(target[1])
                if purge is not None:regs['esp']=add(regs.get('esp'),purge)
                else:regs.pop('esp',None)
                for name in ('eax','ecx','edx'):regs.pop(name,None)
                handled.update(['esp','eax','ecx','edx'])
            elif i.mnemonic=='leave':
                sp=regs.get('ebp');regs['ebp']=mem.get(sp) if sp else None;regs['esp']=add(sp,4);handled.update(['esp','ebp'])
            for register in i.regs_access()[1]:
                name=i.reg_name(register)
                if name not in handled and name not in ('eflags','fpsw'):regs.pop(name,None)
            if i.mnemonic not in ('mov','lea','push','pop'):
                for op in ops:
                    if op.type==x.X86_OP_MEM and op.access & capstone.CS_AC_WRITE:write(op,None)
            successors=[]
            if i.mnemonic.startswith('ret') or i.mnemonic=='int3':pass
            elif i.group(capstone.CS_GRP_JUMP):
                if ops and ops[0].type==x.X86_OP_IMM:successors.append(ops[0].imm)
                if i.mnemonic!='jmp':successors.append(address+i.size)
            else:successors.append(address+i.size)
            for successor in successors:
                if successor not in code:continue
                state=(regs,mem)
                updated=merge(states[successor],state) if successor in states else state
                if successor not in states or updated!=states[successor]:states[successor]=updated;queue.append(successor)
        # Retain only aliases proved at the final fixed-point state, not an early path.
        for address,offset in local_calls.items():
            i=code[address];regs,mem=states[address];op=i.operands[0]
            value=read(op)
            if value==('virtual',offset):calls[address]=(entry,offset)
        for address,name in local_imports.items():
            i=code[address];regs,mem=states[address];op=i.operands[0]
            value=read(op)
            if value==('import',name):import_calls[address]=(entry,name)
    result={'source_sha256':SHA,'method':'Exact original x86 CFG abstract dataflow; intersection at joins; no execution or target mutation.',
      'calls':[{'address':a,'function':f,'vtableOffset':o} for a,(f,o) in sorted(calls.items())],
      'importCalls':[{'address':a,'function':f,'name':n} for a,(f,n) in sorted(import_calls.items())]}
    output=ROOT/'analysis/static-cdc-callsites.json';output.write_text(json.dumps(result,indent=2)+'\n')
    print(len(calls),'virtual aliases;',len(import_calls),'import aliases;',output)

if __name__=='__main__':main()
