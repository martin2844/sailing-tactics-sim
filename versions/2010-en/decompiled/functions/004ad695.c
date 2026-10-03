
undefined4 __thiscall
FUN_004ad695(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *param_1;
  iVar2 = (**(code **)(iVar1 + 0xa4))(param_2,param_3,param_4,&local_8);
  if (iVar2 == 0) {
    local_8 = (**(code **)(iVar1 + 0xa8))(param_2,param_3,param_4);
  }
  return local_8;
}

