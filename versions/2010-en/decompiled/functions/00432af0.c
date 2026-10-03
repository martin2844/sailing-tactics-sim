
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00432af0(int *param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7
            ,int param_8)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  float10 fVar5;
  HDC hdc;
  HGDIOBJ h;
  undefined4 *local_24;
  double local_20;
  
  if (((*(int *)(&DAT_0050f6d0 + param_8 * 4) < 0x11) &&
      (_DAT_004cc960 < *(double *)(&DAT_004ffcb8 + param_8 * 8))) && (param_7 == 1)) {
    return;
  }
  bVar3 = DAT_0050040c != 1;
  iVar2 = 0;
  local_24 = &DAT_004faa60;
  puVar1 = &DAT_004f8028;
  do {
    fVar4 = FUN_0043ec20((double)(int)(&DAT_004fb6b8)[iVar2],(double)(int)(&DAT_004fbc38)[iVar2],
                         param_7,param_8);
    if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d09a00;
    }
    fVar5 = (float10)fsin(fVar4);
    fVar4 = (float10)fcos(fVar4);
    fVar5 = fVar5 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
            (float10)param_2;
    fVar4 = (float10)param_3 -
            fVar4 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    local_20 = (double)fVar5;
    if ((float10)_DAT_004cc968 < fVar5) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004cc970) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004cc968 < fVar4) {
      fVar4 = (float10)_DAT_004cc968;
    }
    if (fVar4 < (float10)_DAT_004cc970) {
      fVar4 = (float10)_DAT_004cc970;
    }
    *puVar1 = (int)(longlong)local_20;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
    *local_24 = (int)(longlong)fVar4;
    local_24 = local_24 + 1;
  } while (iVar2 <= (int)((-(uint)bVar3 & 2) + 0x28));
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    if (DAT_004fb244 == (HGDIOBJ)0x0) goto LAB_00432ccc;
    hdc = (HDC)param_1[1];
    h = DAT_004fb244;
  }
  else {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00432ccc;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  SelectObject(hdc,h);
LAB_00432ccc:
  if (DAT_005359d8 == 0) {
    if ((DAT_005363e4 == 0) && (DAT_004f40a4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f40a4);
    }
    if (((DAT_005359d8 == 0) && (DAT_005363e4 == 1)) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f7ec4);
    }
  }
  if ((DAT_005359d8 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00522d14);
  }
  if ((DAT_0050040c == 0) && (DAT_004f8b78 == 0)) {
    FUN_00433120(param_1);
  }
  if (DAT_0050040c == 1) {
    FUN_00432da0(param_1);
  }
  if (DAT_004f8b78 == 1) {
    FUN_00433710(param_1);
  }
  return;
}

