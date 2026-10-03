
void FUN_004a7390(undefined4 param_1,int *param_2,undefined2 param_3)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = *param_2;
  local_c = param_2[1];
  local_8 = param_2[2];
  local_4 = param_2[3];
  uVar1 = (uint)local_8 >> 0x10;
  FUN_004a7250(param_1,&local_10,7,1,CONCAT22((short)((uint)local_4 >> 0x10),param_3) & 0xffff000f);
  local_10 = local_10 + -1;
  local_c = local_c + -1;
  local_8 = local_8 + 1;
  local_4 = local_4 + 1;
  FUN_004a7250(param_1,&local_10,2,0,CONCAT22((short)uVar1,param_3));
  return;
}

