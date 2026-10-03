
undefined4 __thiscall FUN_0047689f(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_0046ac25((int)this);
    if (iVar1 == 0) {
      param_2 = *(int *)((int)this + 0x8c) + 0x20000;
    }
    else {
      param_2 = *(int *)((int)this + 0x90) + 0x10000;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_0047b918();
  (**(code **)(**(int **)(iVar1 + 4) + 0xa0))(param_2,1);
  return 1;
}

