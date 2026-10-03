
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043ca40(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  double local_8;
  
  if (((param_1 <= DAT_004da140) && (DAT_00536484 == 0)) && (-0xa8 < DAT_004f8cd0)) {
    PlaySoundA((LPCSTR)0x89,DAT_005359c8,0x40005);
  }
  if (DAT_0053527c == 1) {
    iVar2 = DAT_00525a9c / 0x14;
  }
  else {
    iVar2 = DAT_00525a9c / 10;
  }
  local_8 = (double)iVar2;
  if (DAT_004da19c == 8) {
    local_8 = 125.0;
  }
  iVar2 = *(int *)(&DAT_00535740 + param_1 * 4);
  if ((DAT_004da19c != 8) &&
     ((*(int *)(&DAT_004f8538 + param_1 * 4) < 4 || (*(int *)(&DAT_004f8538 + param_1 * 4) == 8))))
  {
    iVar2 = (&DAT_00522b90)[param_1] - *(int *)(&DAT_00522ff0 + param_1 * 4) * DAT_004f7200;
  }
  if (DAT_0053646c == 1) {
    fVar3 = (float10)local_8;
  }
  else {
    if (*(int *)(&DAT_00522ff0 + param_1 * 4) == 1) {
      if (*(int *)(&DAT_004fecc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004fae60 + param_1 * 4)) {
        iVar1 = FUN_0041bc20(iVar2 + 0xa0);
        fVar3 = (float10)iVar1 * (float10)_DAT_004cc568;
      }
      else {
        iVar1 = FUN_0041bc20(iVar2 + 0xb4);
        fVar3 = (float10)iVar1 * (float10)_DAT_004cc568;
      }
    }
    else {
      fVar3 = (float10)local_8;
    }
    if (*(int *)(&DAT_00522ff0 + param_1 * 4) == -1) {
      if (*(int *)(&DAT_004fecc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004fae60 + param_1 * 4)) {
        iVar1 = FUN_0041bc20(iVar2 + 0xaa);
        fVar3 = (float10)iVar1 * (float10)_DAT_004cc568;
      }
      else {
        iVar1 = FUN_0041bc20(iVar2 + 0xa0);
        fVar3 = (float10)iVar1 * (float10)_DAT_004cc568;
      }
    }
  }
  if (DAT_0053646c == 1) {
    if (*(int *)(&DAT_00522ff0 + param_1 * 4) == 1) {
      if (*(int *)(&DAT_004fecc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004fae60 + param_1 * 4)) {
        iVar1 = FUN_0041bc20(iVar2 + 0xb4);
      }
      else {
        iVar1 = FUN_0041bc20(iVar2 + -0xa0);
      }
      fVar3 = (float10)iVar1 * (float10)_DAT_004cc568;
    }
    if (*(int *)(&DAT_00522ff0 + param_1 * 4) == -1) {
      if (*(int *)(&DAT_004fecc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004fae60 + param_1 * 4)) {
        iVar2 = FUN_0041bc20(iVar2 + -0xa0);
      }
      else {
        iVar2 = FUN_0041bc20(iVar2 + 0xb4);
      }
      fVar3 = (float10)iVar2 * (float10)_DAT_004cc568;
    }
  }
  fVar4 = (float10)fsin(fVar3);
  fVar3 = (float10)fcos(fVar3);
  *(double *)(&DAT_004f6af8 + param_1 * 8) =
       (double)(fVar4 * (float10)local_8 + (float10)*(double *)(&DAT_004f6af8 + param_1 * 8));
  *(double *)(&DAT_004f6c10 + param_1 * 8) =
       (double)((float10)*(double *)(&DAT_004f6c10 + param_1 * 8) - fVar3 * (float10)local_8);
  return;
}

