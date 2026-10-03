
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00437520(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    _DAT_004f8390 = DAT_004f7200 + *(int *)(&DAT_005359e0 + param_1 * 4);
  }
  iVar1 = FUN_0041bc20((&DAT_00522b90)[param_1] -
                       *(int *)(&DAT_00522ff0 + param_1 * 4) *
                       (DAT_004f7200 + *(int *)(&DAT_005359e0 + param_1 * 4)));
  *(int *)(&DAT_00535740 + param_1 * 4) = iVar1;
  return;
}

