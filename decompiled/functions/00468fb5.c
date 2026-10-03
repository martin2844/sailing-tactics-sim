
undefined4 __thiscall
FUN_00468fb5(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *(int *)this;
  iVar2 = (**(code **)(iVar1 + 0xa4))(param_1,param_2,param_3,&local_8);
  if (iVar2 == 0) {
    local_8 = (**(code **)(iVar1 + 0xa8))(param_1,param_2,param_3);
  }
  return local_8;
}

