
undefined4 __fastcall FUN_004ac1d2(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = FUN_004aedea(*(undefined4 *)(param_1 + 0x40));
  }
  else {
    iVar1 = FUN_004aee3a(*(int *)(param_1 + 0x4c));
  }
  if (iVar1 != 0) {
    iVar1 = FUN_004aebb3(0);
    if (iVar1 != 0) {
      iVar1 = FUN_004af38e(0xe146);
      if (iVar1 != 0) {
        iVar1 = FUN_004ac17b();
        FUN_004af52c(-(iVar1 != 0) & 5);
      }
      return 1;
    }
  }
  FUN_004ac0ab(0xffffffff);
  return 0;
}

