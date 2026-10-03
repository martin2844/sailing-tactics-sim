
void __thiscall FUN_004b694c(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 100);
  *(uint *)(param_1 + 100) = uVar1 & 0xfffff0ff;
  FUN_004b75ab(param_2);
  *(uint *)(param_1 + 100) = uVar1;
  return;
}

