#!/usr/bin/env python3
"""Extract literal definition heads, not generated geometry or final states."""
import hashlib,json,re,sys
from pathlib import Path

EDITION=Path(__file__).resolve().parents[1]
ROOT=EDITION.parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from compare_2010_core import inventory

ROUTINES={1:0x4676f0,2:0x4711b0,3:0x471f40,4:0x4729d0,6:0x4732c0,
  7:0x473ed0,10:0x474b60,9:0x4756c0,12:0x4762a0,11:0x476db0,
  103:0x47c240,105:0x47b5d0,104:0x47aa70,100:0x479e00,
  101:0x479120,102:0x477b00,106:0x478760}

def number(expression,index):
    if expression=='param_1':return index
    if expression.startswith('&DAT_'):return int(expression[5:],16)
    if not re.fullmatch(r'-?(?:0x[0-9a-f]+|[0-9]+)',expression):raise ValueError('Nonliteral definition: '+expression)
    return int(expression,0)

def main():
    rows,source_hash=inventory('2010');lookup={int(row['address'],16):row for row in rows}
    definitions={};audits={}
    for venue,address in ROUTINES.items():
        path=EDITION/f'decompiled/functions/{address:08x}.c';source=path.read_text()
        match=re.search(r'\bfVar\d+ = \(float10\)fcos\(',source)
        if not match:raise ValueError('Expected orientation boundary missing')
        head=source[:match.start()]
        blocks=list(re.finditer(r'  if \(param_1 == (-?(?:0x[0-9a-f]+|[0-9]+))\) \{\n(.*?)\n  \}',head,re.S))
        if not blocks:raise ValueError('No literal point definitions')
        default_gap='indexEquals1' if 'local_b80 = (uint)(param_1 == 1);' in head else 0
        points={}
        for block in blocks:
            index=int(block.group(1),0);writes=[];gap=None
            for statement in block.group(2).splitlines():
                statement=statement.strip()
                if not statement:continue
                assignment=re.fullmatch(r'([_A-Za-z0-9.]+) = (.*?);',statement)
                if not assignment:raise ValueError(f'Unsupported definition statement {address:x}: '+statement)
                name,expression=assignment.groups();value=number(expression,index)
                if name=='local_b80':gap=value;continue
                field=re.fullmatch(r'_?DAT_([0-9a-f]{8})(?:\._([04])_4_)?',name)
                if not field:raise ValueError('Unexpected definition field '+name)
                target=int(field.group(1),16)+int(field.group(2) or 0)
                if not -0x80000000<=value<=0xffffffff:raise ValueError('Expected literal DWORD definition')
                writes.append([target,value&0xffffffff])
            points[str(index)]={'writes':writes,'gap':gap}
        instructions=lookup[address]['instructions']
        sine_positions=[i for i,row in enumerate(instructions)if row['mnemonic']=='fsin']
        if len(sine_positions)!=2:raise ValueError('Unexpected native geometry trigonometry')
        products=[row for row in instructions[sine_positions[-1]+1:]if row['mnemonic']=='fmul']
        aspect_first='0x4fb5e0' in products[0]['operands']
        definitions[str(venue)]={'routine':address,'defaultGap':default_gap,'aspectFirst':aspect_first,
                                'copyTargets':'dat_004f83c8' in source.lower(),'points':points}
        audits[str(venue)]={'routine':address,'sourceFile':str(path.relative_to(ROOT)),
          'sourceFileSha256':hashlib.sha256(source.encode()).hexdigest(),
          'definitionIndices':list(map(int,points)),'firstVertexProduct':products[0],
          'floatingInstructions':[row for row in instructions if row['mnemonic'].startswith('f') or(row['mnemonic']=='call'and row['operands']=='0x49b970')],
          'scope':'Literal head assignments and original floating instruction audit. No execution-output or final-state tables.'}
    result={'provenance':{'sourceSha256':source_hash,'source':'versions/2010-en/runtime/Tactics2010EnglishPreserved.exe',
      'method':'Validated restricted literal-head extraction plus native opcode product-order audit'},'definitions':definitions,'audits':audits}
    (EDITION/'analysis/venue-definition-evidence.json').write_text(json.dumps(result,indent=2)+'\n')
    module='// Source-derived literal definitions. Regenerate with tools/extract-venue-definitions.py.\n'
    module+='const freeze=value=>{if(value&&typeof value===\'object\'){for(const child of Object.values(value))freeze(child);Object.freeze(value);}return value;};\n'
    module+='export const VENUE_POINT_DEFINITIONS=freeze('+json.dumps(definitions,indent=2)+');\n'
    (EDITION/'src/engine/venue-definitions.js').write_text(module)
    print(f'Extracted {sum(len(row["points"])for row in definitions.values())} literal definitions from17 complete original point constructors.')

if __name__=='__main__':main()
