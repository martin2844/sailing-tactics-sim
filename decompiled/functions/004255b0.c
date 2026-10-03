
void __cdecl FUN_004255b0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_004ac018 + param_1 * 4) - *(int *)(&DAT_004aa5b0 + param_1 * 4);
  *(undefined4 *)(&DAT_004aa730 + param_1 * 4) = 1;
  if ((0 < iVar1) && (iVar1 < 0xb4)) {
    *(undefined4 *)(&DAT_004aa730 + param_1 * 4) = 0xffffffff;
  }
  if (iVar1 < -0xb4) {
    *(undefined4 *)(&DAT_004aa730 + param_1 * 4) = 0xffffffff;
  }
  return;
}

