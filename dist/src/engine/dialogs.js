import { i32 } from '../runtime/c-types.js';

/** Exact BN_CLICKED mappings from the original MFC dialog message tables. */
export const DIALOG_CONTROLS=Object.freeze({
  132:Object.freeze({1008:[0x401050,0x4ac918,20],1009:[0x401060,0x4ac918,25],1010:[0x401070,0x4ac918,30],1011:[0x401080,0x4ac918,35],
    1012:[0x401090,0x4ac918,40],1013:[0x4010a0,0x4ac918,50],1021:[0x4010b0,0x4ac920,10],1024:[0x4010c0,0x4ac924,80],
    1015:[0x4010d0,0x4ac91c,11],1022:[0x4010e0,0x4ac920,9],1017:[0x4010f0,0x4ac91c,9],1020:[0x401100,0x4ac920,11],
    1025:[0x401110,0x4ac924,100],1016:[0x401120,0x4ac91c,10],1018:[0x401130,0x4ac91c,8]}),
  131:Object.freeze({1006:[0x4013a0,0x4ac948,-7],1005:[0x4013d0,0x4ac948,-4],1004:[0x401400,0x4ac948,-2],
    1000:[0x401430,0x4ac948,7],1001:[0x401460,0x4ac948,4],1002:[0x401490,0x4ac948,2],1003:[0x4014c0,0x4ac948,0]}),
});

/** Selections write immediately in the original; Cancel does not undo them. */
export function handleDialogControl(memory,resourceId,controlId,options={}){
  const row=DIALOG_CONTROLS[i32(resourceId)]?.[i32(controlId)];
  if(!row)return false;
  memory.writeI32(row[1],row[2]);
  if(resourceId===131){options.invalidateRect?.({windowHandle:options.windowHandle??0,rectangle:null,erase:0});memory.writeI32(0x4ac8fc,0);}
  return true;
}
export function closeOriginalDialog(memory,resourceId,accepted,options={}){
  if(resourceId===131){memory.writeI32(0x4ac8fc,0);options.invalidateRect?.({windowHandle:options.windowHandle??0,rectangle:null,erase:0});}
  return accepted?1:2;
}
