
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004269d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_004ac900 == 0) {
    iVar1 = *(int *)(&DAT_004a6338 + param_1 * 4);
    iVar2 = (int)((ulonglong)((longlong)iVar1 * 0x55555555) >> 0x20) - iVar1;
    iVar4 = *(int *)(&DAT_004ac1e8 + param_1 * 4);
    iVar2 = (((iVar2 >> 1) - (iVar2 >> 0x1f)) - DAT_00491188 / 6) + 0x2d + iVar4;
  }
  else {
    iVar1 = *(int *)(&DAT_004a6338 + param_1 * 4);
    iVar4 = *(int *)(&DAT_004ac1e8 + param_1 * 4);
    iVar2 = (iVar4 - ((int)((iVar1 >> 0x1f & 7U) + iVar1) >> 3)) + 0x2e;
  }
  iVar3 = param_1 * 4;
  if (DAT_00491188 == 3) {
    iVar2 = iVar2 + 3;
  }
  if (DAT_00491188 == 7) {
    iVar2 = iVar2 + -2;
  }
  if (DAT_00491188 == 8) {
    iVar2 = iVar2 + -6;
  }
  if (DAT_004ac904 == 1) {
    iVar2 = iVar4 + 0x37;
  }
  if (((DAT_00491188 < 7) || (DAT_004ac900 == 1)) || (DAT_004ac908 == 1)) {
    if (iVar1 < 0xb) {
      iVar2 = iVar2 + 3;
    }
    if (iVar1 < 8) {
      iVar2 = iVar2 + 3;
    }
  }
  if (param_1 == 1) {
    _DAT_004a52e8 = iVar2;
  }
  iVar2 = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + iVar3) - *(int *)(&DAT_004aa730 + iVar3) * iVar2);
  *(int *)(&DAT_004ac018 + iVar3) = iVar2;
  return;
}

