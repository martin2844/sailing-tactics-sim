
undefined4 __thiscall FUN_00467c08(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (*(int *)((int)this + 0x3c) != 0) {
      param_2 = *(int *)((int)this + 0x3c) + 0x20000;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_0047b918();
  (**(code **)(**(int **)(iVar1 + 4) + 0xa0))(param_2,1);
  return 1;
}

