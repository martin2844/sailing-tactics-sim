import { i32 } from '../../../../src/runtime/c-types.js';

/** Exact BN_CLICKED records from the two original 2010 dialog message maps. */
export const DIALOG_CONTROLS = Object.freeze({
  132: Object.freeze({
    1008:[0x401040,0x5363d0,20],1009:[0x401050,0x5363d0,25],1010:[0x401060,0x5363d0,30],
    1011:[0x401070,0x5363d0,35],1012:[0x401080,0x5363d0,40],1013:[0x401090,0x5363d0,50],
    1021:[0x4010a0,0x5363d8,10],1024:[0x4010b0,0x5363dc,80],1015:[0x4010c0,0x5363d4,11],
    1022:[0x4010d0,0x5363d8,9],1017:[0x4010e0,0x5363d4,9],1020:[0x4010f0,0x5363d8,11],
    1025:[0x401100,0x5363dc,100],1016:[0x401110,0x5363d4,10],1018:[0x401120,0x5363d4,8],
  }),
  131: Object.freeze({
    1006:[0x4013a0,0x536400,-7],1005:[0x4013d0,0x536400,-4],1004:[0x401400,0x536400,-2],
    1000:[0x401430,0x536400,7],1001:[0x401460,0x536400,4],1002:[0x401490,0x536400,2],
    1003:[0x4014c0,0x536400,0],
  }),
});

/** Selections are immediate original writes. Cancel retains them. */
export function handleDialogControl(memory, resourceId, controlId, options = {}) {
  resourceId = i32(resourceId);controlId = i32(controlId);
  const row = DIALOG_CONTROLS[resourceId]?.[controlId];
  if (!row) return false;
  memory.writeI32(row[1],row[2]);
  if (resourceId === 131) {
    options.invalidateRect?.({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:0});
    memory.writeI32(0x5363b4,0);
  }
  return true;
}

/** Original EndDialog precedes Helm's close tail; menu tails follow DoModal. */
export function closeOriginalDialog(memory, resourceId, accepted, options = {}) {
  const result = accepted ? 1 : 2;
  options.endDialog?.(result);
  if (i32(resourceId) === 131) {
    memory.writeI32(0x5363b4,0);
    options.invalidateRect?.({windowHandle:options.windowHandle ?? 0,rectangle:null,erase:0});
  }
  return result;
}
