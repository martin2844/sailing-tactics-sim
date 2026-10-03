
void __thiscall FUN_004b6a27(int param_1,int param_2)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x18) = 1;
  uVar1 = FUN_004b6669(*(undefined4 *)(param_1 + 8));
  uVar1 = uVar1 & 0xfbffffff;
  if (param_2 == 0) {
    uVar1 = uVar1 | 0x4000000;
  }
  FUN_004b667a(*(undefined4 *)(param_1 + 8),uVar1);
  return;
}

