
undefined4 __thiscall FUN_004ac2e8(void *this,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    if (*(int *)((int)this + 0x3c) != 0) {
      param_3 = *(int *)((int)this + 0x3c) + 0x20000;
    }
    if (param_3 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_004bfff8();
  (**(code **)(**(int **)(iVar1 + 4) + 0xa0))(param_3,1);
  return 1;
}

