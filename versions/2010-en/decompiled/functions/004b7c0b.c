
undefined4 __fastcall FUN_004b7c0b(int param_1)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x60) & 1) != 0) {
    return 0;
  }
  if (((*(uint *)(param_1 + 0x60) & 2) == 0) && (uVar1 = FUN_004af3eb(), (uVar1 & 0x10000000) == 0))
  {
    return 0;
  }
  return 1;
}

