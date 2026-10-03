
int FUN_004b0f8d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = FUN_004b0fcf(param_1,&DAT_004ce9d8,&local_8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,param_2,param_3,param_4);
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}

