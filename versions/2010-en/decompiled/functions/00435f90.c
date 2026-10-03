
void __cdecl FUN_00435f90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_00535740 + param_1 * 4) - (&DAT_00522b90)[param_1];
  *(undefined4 *)(&DAT_00522ff0 + param_1 * 4) = 1;
  if ((0 < iVar1) && (iVar1 < 0xb4)) {
    *(undefined4 *)(&DAT_00522ff0 + param_1 * 4) = 0xffffffff;
  }
  if (iVar1 < -0xb4) {
    *(undefined4 *)(&DAT_00522ff0 + param_1 * 4) = 0xffffffff;
  }
  return;
}

