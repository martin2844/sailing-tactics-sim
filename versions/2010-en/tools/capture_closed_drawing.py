#!/usr/bin/env python3
"""Fixed finite authority cases for complete English text screens/controls."""
import argparse,json
from pathlib import Path
from capture_native import capture,EXPECTED

ROOT=Path(__file__).resolve().parents[1]
FIELDS={'width':0x4fe624,'height':0x4fe2a8,'suppressColors':0x5363e4,
 'boatCount':0x4da194,'currentPage':0x4fb9b4,'lastPage':0x4da18c,
 'buttonTop':0x4faf7c,'raceTime':0x4f8cd0}
ROUTINES={
 'demo':(0x416910,['CDC']), 'results':(0x428b70,['CDC']),
 'advice':(0x406590,['CDC']+['I32']*6),
 'jibe':(0x406680,['CDC']+['I32']*3),'tack':(0x406e40,['CDC']+['I32']*3),
 'text-color':(0x41f3e0,['CDC','I32']),
 'advance-button':(0x463c90,['CDC','I32']),
 'advance-hint':(0x463df0,['CDC','I32','I32']),
 'depth-sort':(0x43f9f0,['I32']),
 'depth-select':(0x43fa60,['I32','I32','I32']),
}
def inputs(name):
 address,kinds=ROUTINES[name];rows=[]
 for index in range(48):
  width=[640,699,700,899,900,901,1024,1280][index%8]
  values={'width':width,'height':[480,768,900][index//8%3],
   'suppressColors':index//24,'boatCount':5,'currentPage':index%4,
   'lastPage':2,'buttonTop':300,'raceTime':index*7}
  arguments=[0] if kinds[0]=='CDC' else []
  if name=='advice':arguments+=[10,20,width-10,values['height']-20,1,2]
  elif name in ('jibe','tack'):arguments+=[15,20,[12,14,16,24][index%4]]
  elif name=='text-color':arguments+=[index%35-3]
  elif name=='advance-button':arguments+=[[0,12,16,24][index%4]]
  elif name=='advance-hint':arguments+=[20,[0,12,16,24][index%4]]
  elif name=='depth-sort':arguments=[index%2]
  elif name=='depth-select':arguments=[1,index%11,[0,50,19000,20001][index%4]]
  patches=[]
  # Explicit finite object depths include ties and the original strict cutoff.
  for obj in range(1,13):
   value=[0,50,100,19000,20000,-20][(obj+index)%6]
   patches.append({'address':0x4fc160+obj*4,'bytes':(value&0xffffffff).to_bytes(4,'little').hex()})
   patches.append({'address':0x4f4778+obj*4,'bytes':(1).to_bytes(4,'little').hex()})
  rows.append({'arguments':arguments,'inputs':values,'patches':patches,'seed':2002+index})
 return {'sourceSha256':EXPECTED,'routine':{'address':address,'name':name,
  'argumentTypes':kinds,'returnType':'void'},'integerInputs':FIELDS,'cases':rows}

def main():
 parser=argparse.ArgumentParser(description=__doc__)
 parser.add_argument('--only',choices=list(ROUTINES));parser.add_argument('--prefix',default=str(Path.home()/'.local/share/posey-simulator-2010-en/wineprefix'))
 args=parser.parse_args();folder=ROOT/'tests/fixtures';folder.mkdir(parents=True,exist_ok=True)
 for name in ([args.only] if args.only else ROUTINES):
  result=capture(inputs(name),prefix=args.prefix)
  (folder/f'original-drawing-{name}.json').write_text(json.dumps(result,indent=2,allow_nan=False)+'\n')
  print('Captured',name,len(result['cases']),flush=True)

if __name__=='__main__':main()
