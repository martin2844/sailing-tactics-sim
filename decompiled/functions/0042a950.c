
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042a950(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  double local_8;
  
  if (((param_1 <= DAT_00491140) && (DAT_004ac9c0 == 0)) && (-0xa8 < DAT_004a5b80)) {
    PlaySoundA((LPCSTR)0x89,DAT_004ac1d4,0x40005);
  }
  iVar2 = *(int *)(&DAT_004ac018 + param_1 * 4);
  if ((DAT_00491194 != 8) &&
     ((*(int *)(&DAT_004a5420 + param_1 * 4) < 4 || (*(int *)(&DAT_004a5420 + param_1 * 4) == 8))))
  {
    iVar2 = *(int *)(&DAT_004aa5b0 + param_1 * 4) -
            *(int *)(&DAT_004aa730 + param_1 * 4) * DAT_004a4eb0;
  }
  if (DAT_004ac9a8 == 1) {
    fVar3 = (float10)local_8;
  }
  else {
    if (*(int *)(&DAT_004aa730 + param_1 * 4) == 1) {
      if (*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004a5f10 + param_1 * 4)) {
        iVar1 = FUN_00413cb0(iVar2 + 0xa0);
        fVar3 = (float10)iVar1 * (float10)_DAT_00484d40;
      }
      else {
        iVar1 = FUN_00413cb0(iVar2 + 0xb4);
        fVar3 = (float10)iVar1 * (float10)_DAT_00484d40;
      }
    }
    else {
      fVar3 = (float10)local_8;
    }
    if (*(int *)(&DAT_004aa730 + param_1 * 4) == -1) {
      if (*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004a5f10 + param_1 * 4)) {
        iVar1 = FUN_00413cb0(iVar2 + 0xaa);
        fVar3 = (float10)iVar1 * (float10)_DAT_00484d40;
      }
      else {
        iVar1 = FUN_00413cb0(iVar2 + 0xa0);
        fVar3 = (float10)iVar1 * (float10)_DAT_00484d40;
      }
    }
  }
  if (DAT_004ac9a8 == 1) {
    if (*(int *)(&DAT_004aa730 + param_1 * 4) == 1) {
      if (*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004a5f10 + param_1 * 4)) {
        iVar1 = FUN_00413cb0(iVar2 + 0xb4);
      }
      else {
        iVar1 = FUN_00413cb0(iVar2 + -0xa0);
      }
      fVar3 = (float10)iVar1 * (float10)_DAT_00484d40;
    }
    if (*(int *)(&DAT_004aa730 + param_1 * 4) == -1) {
      if (*(int *)(&DAT_004a7bc8 + param_1 * 4) < 0xa0 - *(int *)(&DAT_004a5f10 + param_1 * 4)) {
        iVar2 = FUN_00413cb0(iVar2 + -0xa0);
      }
      else {
        iVar2 = FUN_00413cb0(iVar2 + 0xb4);
      }
      fVar3 = (float10)iVar2 * (float10)_DAT_00484d40;
    }
  }
  fVar4 = (float10)fsin(fVar3);
  fVar5 = (float10)fcos(fVar3);
  fVar3 = (float10)_DAT_00485200;
  *(double *)(&DAT_004a49e8 + param_1 * 8) =
       (double)(fVar4 * (float10)_DAT_00485200 + (float10)*(double *)(&DAT_004a49e8 + param_1 * 8));
  *(double *)(&DAT_004a4ae0 + param_1 * 8) =
       (double)((float10)*(double *)(&DAT_004a4ae0 + param_1 * 8) - fVar5 * fVar3);
  return;
}

