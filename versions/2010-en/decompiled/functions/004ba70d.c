
uint __thiscall FUN_004ba70d(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x80) + param_2 * 4);
  return uVar1 & -(uint)((short)(uVar1 >> 0x10) != 0);
}

