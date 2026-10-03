
int __cdecl FUN_00456de0(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  FUN_00457d40();
  SVar1 = FUN_00458320((undefined *)DAT_004aff08);
  if (SVar1 < (uint)((int)DAT_004aff04 + (4 - (int)DAT_004aff08))) {
    SVar1 = FUN_00458320((undefined *)DAT_004aff08);
    piVar2 = FUN_0045a070(DAT_004aff08,SVar1 + 0x10);
    if (piVar2 == (int *)0x0) {
      FUN_00457d50();
      return 0;
    }
    DAT_004aff04 = piVar2 + ((int)DAT_004aff04 - (int)DAT_004aff08 >> 2);
    DAT_004aff08 = piVar2;
  }
  *DAT_004aff04 = param_1;
  DAT_004aff04 = DAT_004aff04 + 1;
  FUN_00457d50();
  return param_1;
}

