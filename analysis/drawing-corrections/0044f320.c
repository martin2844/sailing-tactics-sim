
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0044f320(int param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  HDC hdc;
  HGDIOBJ h;
  double local_20;
  
  if ((*(int *)(&DAT_004a8660 + param_8 * 4) < 0x11) && (param_7 < 3)) {
    return;
  }
  iVar1 = 0;
  do {
    fVar2 = FUN_0042c400((double)*(int *)((int)&DAT_004a6490 + iVar1),
                         (double)*(int *)((int)&DAT_004a68c8 + iVar1),param_7,param_8);
    if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
      _DAT_004a6828 = 0;
      _DAT_004a682c = 0x40bb5800;
    }
    fVar3 = (float10)fsin(fVar2);
    fVar2 = (float10)fcos(fVar2);
    fVar3 = fVar3 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) +
            (float10)param_2;
    fVar2 = (float10)param_3 -
            fVar2 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828);
    local_20 = (double)fVar3;
    if ((float10)_DAT_004850f0 < fVar3) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004850f8) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004850f0 < fVar2) {
      fVar2 = (float10)_DAT_004850f0;
    }
    if (fVar2 < (float10)_DAT_004850f8) {
      fVar2 = (float10)_DAT_004850f8;
    }
    *(int *)((int)&DAT_004a4f90 + iVar1) = (int)(longlong)local_20;
    *(int *)((int)&DAT_004a5bb0 + iVar1) = (int)(longlong)fVar2;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2cd);
  _DAT_004a5260 = DAT_004a4f90;
  _DAT_004a5e80 = DAT_004a5bb0;
  iVar1 = 0;
  do {
    fVar2 = FUN_0042c400((double)*(int *)((int)&DAT_004a8e90 + iVar1),
                         (double)*(int *)((int)&DAT_004a9168 + iVar1),param_7,param_8);
    if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
      _DAT_004a6828 = 0;
      _DAT_004a682c = 0x40bb5800;
    }
    fVar3 = (float10)fsin(fVar2);
    fVar2 = (float10)fcos(fVar2);
    fVar3 = fVar3 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) +
            (float10)param_2;
    fVar2 = (float10)param_3 -
            fVar2 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828);
    local_20 = (double)fVar3;
    if ((float10)_DAT_004850f0 < fVar3) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004850f8) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004850f0 < fVar2) {
      fVar2 = (float10)_DAT_004850f0;
    }
    if (fVar2 < (float10)_DAT_004850f8) {
      fVar2 = (float10)_DAT_004850f8;
    }
    *(int *)((int)&DAT_004a7360 + iVar1) = (int)(longlong)local_20;
    *(int *)((int)&DAT_004a8b28 + iVar1) = (int)(longlong)fVar2;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2cd);
  _DAT_004a8df8 = DAT_004a8b28;
  _DAT_004a7630 = DAT_004a7360;
  if (DAT_004ac92c == 0) {
    if (DAT_004a621c == (HGDIOBJ)0x0) goto LAB_0044f5f5;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a621c;
  }
  else {
    if (DAT_004a70e4 == (HGDIOBJ)0x0) goto LAB_0044f5f5;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a70e4;
  }
  SelectObject(hdc,h);
LAB_0044f5f5:
  if (DAT_004aa634 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa634);
  }
  FUN_0044f630((int *)param_1);
  return;
}

