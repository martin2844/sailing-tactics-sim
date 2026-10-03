
void __thiscall FUN_00473253(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)((int)this + 0x70) != 0) &&
     (iVar1 = (**(code **)(*(int *)this + 0x6c))(param_2,param_3,0), iVar1 == -1)) {
    (**(code **)(**(int **)((int)this + 0x74) + 8))();
    return;
  }
  FUN_00468021(this);
  return;
}

