
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_004659d0(int *param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7
            ,int param_8)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  HDC hdc;
  HGDIOBJ h;
  double local_20;
  
  if ((*(int *)(&DAT_0050f6d0 + param_8 * 4) < 0x11) && (param_7 < 2)) {
    return;
  }
  iVar1 = 0;
  do {
    fVar2 = FUN_0043ec20((double)*(int *)((int)&DAT_004fb6b8 + iVar1),
                         (double)*(int *)((int)&DAT_004fbc38 + iVar1),param_7,param_8);
    if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d09a00;
    }
    fVar3 = (float10)fsin(fVar2);
    fVar2 = (float10)fcos(fVar2);
    fVar3 = fVar3 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
            (float10)param_2;
    fVar2 = (float10)param_3 -
            fVar2 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    local_20 = (double)fVar3;
    if ((float10)_DAT_004cc968 < fVar3) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004cc970) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004cc968 < fVar2) {
      fVar2 = (float10)_DAT_004cc968;
    }
    if (fVar2 < (float10)_DAT_004cc970) {
      fVar2 = (float10)_DAT_004cc970;
    }
    *(int *)((int)&DAT_004f8028 + iVar1) = (int)(longlong)local_20;
    *(int *)((int)&DAT_004faa60 + iVar1) = (int)(longlong)fVar2;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2cd);
  _DAT_004f82f8 = DAT_004f8028;
  _DAT_004fad30 = DAT_004faa60;
  iVar1 = 0;
  do {
    fVar2 = FUN_0043ec20((double)*(int *)((int)&DAT_005127a8 + iVar1),
                         (double)*(int *)((int)&DAT_00512a80 + iVar1),param_7,param_8);
    if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d09a00;
    }
    fVar3 = (float10)fsin(fVar2);
    fVar2 = (float10)fcos(fVar2);
    fVar3 = fVar3 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
            (float10)param_2;
    fVar2 = (float10)param_3 -
            fVar2 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    local_20 = (double)fVar3;
    if ((float10)_DAT_004cc968 < fVar3) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004cc970) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004cc968 < fVar2) {
      fVar2 = (float10)_DAT_004cc968;
    }
    if (fVar2 < (float10)_DAT_004cc970) {
      fVar2 = (float10)_DAT_004cc970;
    }
    *(int *)((int)&DAT_004fe348 + iVar1) = (int)(longlong)local_20;
    *(int *)((int)&DAT_00512308 + iVar1) = (int)(longlong)fVar2;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2cd);
  _DAT_005125d8 = DAT_00512308;
  _DAT_004fe618 = DAT_004fe348;
  if (DAT_005363e4 == 0) {
    if (DAT_004fb244 == (HGDIOBJ)0x0) goto LAB_00465ca5;
    hdc = (HDC)param_1[1];
    h = DAT_004fb244;
  }
  else {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00465ca5;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  SelectObject(hdc,h);
LAB_00465ca5:
  if (DAT_00522d14 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_00522d14);
  }
  FUN_00465ce0(param_1,param_7);
  return;
}

