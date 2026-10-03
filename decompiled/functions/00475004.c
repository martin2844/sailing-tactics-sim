
uint __fastcall FUN_00475004(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = *(uint *)(param_1 + 0x78) & 0xa000;
  if (*(int *)(param_1 + 0x7c) != 0) {
    uVar2 = (uint)(uVar2 == 0);
  }
  if (((uVar2 != 0) && ((*(uint *)(param_1 + 0x70) & 0xa000) != 0)) ||
     ((*(uint *)(param_1 + 0x70) & 0x5000) != 0)) {
    uVar1 = FUN_00479fb5(*(void **)(param_1 + 0x6c));
  }
  if ((*(int *)(param_1 + 0x7c) == 0) && (uVar1 == 0)) {
    if ((*(uint *)(param_1 + 0x70) & 0xa000) != 0) {
      uVar2 = FUN_00479fb5(*(void **)(param_1 + 0x6c));
      uVar1 = FUN_00479fb5(*(void **)(param_1 + 0x6c));
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
    if ((uVar1 == 0) && ((*(uint *)(param_1 + 0x70) & 0x5000) != 0)) {
      uVar2 = FUN_00479fb5(*(void **)(param_1 + 0x6c));
      uVar1 = FUN_00479fb5(*(void **)(param_1 + 0x6c));
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
  }
  return uVar1;
}

