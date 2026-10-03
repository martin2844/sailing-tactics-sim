
void __thiscall FUN_004ab4c3(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 < iVar1) {
    FUN_004ab379(iVar1 + param_4,0xffffffff);
    FUN_0049c740(*(int *)(param_1 + 4) + (param_4 + param_2) * 4,*(int *)(param_1 + 4) + param_2 * 4
                 ,(param_2 * 0x3fffffff + iVar1) * 4);
    _memset((void *)(*(int *)(param_1 + 4) + param_2 * 4),0,param_4 << 2);
  }
  else {
    FUN_004ab379(param_4 + param_2,0xffffffff);
  }
  if (param_4 != 0) {
    param_2 = param_2 << 2;
    do {
      *(undefined4 *)(*(int *)(param_1 + 4) + param_2) = param_3;
      param_2 = param_2 + 4;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

