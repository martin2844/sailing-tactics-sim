#!/usr/bin/env python3
"""Preserve an independent read-only original chart packed-stack ABI audit."""
import hashlib
import json
from pathlib import Path
import capstone
import pefile

EDITION=Path(__file__).resolve().parents[1]
EXPECTED='d707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787'
# These contracts were checked against caller pushes, cleanup and the original
# callee's scalar/qword loads. Unused parameters remain in their original slots.
CONTRACTS={
    0x40a6c0:'CDII',0x40aab0:'CDII',0x432af0:'CIIDIIII',
    0x4659d0:'CIIDIIII',0x468440:'CIIIIDIIIII',0x469650:'C',
    0x46a890:'CIID',0x489980:'CIIDII',0x431ab0:'CIIDIIIIIIII',
    0x47cea0:'CDII',0x469690:'CIIIIIII',
}

def main():
    source=(EDITION/'runtime/Tactics2010EnglishPreserved.exe').read_bytes()
    if hashlib.sha256(source).hexdigest()!=EXPECTED:raise ValueError('Unexpected original image')
    image=pefile.PE(data=source).get_memory_mapped_image()
    rows={int(row['address'],16):row for row in map(json.loads,(EDITION/'decompiled/functions.jsonl').read_text().splitlines())}
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    def instructions(address):
        output=[]
        for bounds in rows[address]['body_ranges']:
            start,end=int(bounds['start'],16),int(bounds['end'],16)
            output.extend(decoder.disasm(image[start-0x400000:end-0x400000+1],start))
        return output
    def encode(op):return {'address':hex(op.address),'instruction':op.mnemonic+' '+op.op_str}
    callers=[0x407ff0,0x468440]
    caller_ops={address:instructions(address) for address in callers}
    records=[]
    for address,kinds in CONTRACTS.items():
        width=sum(8 if kind=='D' else 4 for kind in kinds)
        evidence=[]
        for caller,ops in caller_ops.items():
            for index,op in enumerate(ops):
                if op.mnemonic!='call' or op.op_str!=hex(address):continue
                after=ops[index+1:index+9]
                cleanup=next((item for item in after if item.mnemonic=='add' and item.op_str.startswith('esp, ')),None)
                if cleanup is None or int(cleanup.op_str.split(', ')[1],0)!=width:
                    raise ValueError(f'Original caller cleanup differs for {hex(address)} at {hex(op.address)}')
                evidence.append({'caller':hex(caller),'callsite':hex(op.address),
                    'before':[encode(item) for item in ops[max(0,index-25):index]],
                    'after':[encode(item) for item in after],
                    'cleanupBytes':width})
        if not evidence:raise ValueError(f'No original chart caller for {hex(address)}')
        ops=instructions(address)
        returns=[op for op in ops if op.mnemonic=='ret']
        if not returns or any(op.op_str for op in returns):raise ValueError('Original callee is not plain-RET cdecl')
        offset=4;parameters=[]
        for kind in kinds:
            size=8 if kind=='D' else 4
            parameters.append({'type':'F64' if kind=='D' else 'CDC' if kind=='C' else 'I32 word','entryEspOffset':offset,'bytes':size})
            offset+=size
        signature=(EDITION/'decompiled/functions'/f'{address:08x}.c').read_text().split('\n{',1)[0]
        signature=signature[signature.rfind('\n\n')+2:].strip()
        records.append({'address':hex(address),'packedTypes':kinds,'stackBytes':width,
            'callingConvention':'cdecl, plain RET; original caller removes packed stack words',
            'parameters':parameters,'currentRecoveredSignature':signature,'callerEvidence':evidence,
            'entryInstructions':[encode(op) for op in ops[:50]],
            'stackF64Instructions':[encode(op) for op in ops if 'qword ptr [esp' in op.op_str or 'qword ptr [ebp' in op.op_str],
            'ebpParameterInstructions':[encode(op) for op in ops if '[ebp +' in op.op_str],
            'returnInstructions':[encode(op) for op in returns]})
    report={'sourceSha256':EXPECTED,'method':'Read-only Capstone32 original instruction audit. Manually checked scalar/qword parameter loads, caller push order, preserved unused slots and exact caller cleanup. No image or Ghidra edits; this is ABI evidence, not a behavior proof.',
        'legend':{'C':'CDC pointer, one DWORD','D':'binary64 packed in two consecutive DWORDs','I':'one original DWORD, established signedness retained'},
        'scope':'Eleven direct packed chart children and its chart-history drawing child469690; other renderer ABIs have separate audits.',
        'routines':records}
    destination=EDITION/'analysis/chart-renderer-abi-review.json'
    destination.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'routines':len(records),'sha256':hashlib.sha256(destination.read_bytes()).hexdigest(),'path':str(destination)}))

if __name__=='__main__':main()
