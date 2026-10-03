
undefined4 __thiscall FUN_004c0a3e(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if ((0 < param_2) && (iVar1 = FUN_0049cf00(param_2,param_3), iVar1 == 0)) {
    return 0;
  }
  FUN_0049bfd0(*(undefined4 *)(param_1 + 0x5c));
  *(int *)(param_1 + 0x5c) = iVar1;
  *(int *)(param_1 + 0x58) = param_2;
  return 1;
}

