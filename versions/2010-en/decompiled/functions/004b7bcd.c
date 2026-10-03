
void __thiscall FUN_004b7bcd(int param_1,int param_2)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) & 0xfffffffc;
  if (param_2 != 0) {
    uVar1 = FUN_004af3eb();
    if ((uVar1 & 0x10000000) == 0) {
      *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 2;
      return;
    }
    if (param_2 != 0) {
      return;
    }
  }
  uVar1 = FUN_004af3eb();
  if ((uVar1 & 0x10000000) != 0) {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 1;
  }
  return;
}

