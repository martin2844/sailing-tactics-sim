
void __cdecl
FUN_00415590(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int local_38 [3];
  int local_2c;
  int local_28 [5];
  int local_14;
  int local_10 [4];
  
  local_10[1] = (param_8 + param_6) / 2;
  iVar1 = (param_7 + param_9) / 2;
  local_38[0] = (local_10[1] + param_8) / 2;
  local_10[0] = (local_10[1] + param_6) / 2;
  if (param_4 == 0) {
    param_5 = -param_5;
  }
  local_14 = param_6;
  local_2c = param_7;
  local_28[0] = (iVar1 + param_7) / 2 -
                ((param_10 / 2 + 3 + param_11 * 2) * param_5 * param_2) / 300;
  local_28[1] = iVar1 - ((param_11 + 7 + param_10) * param_5 * param_3) / 300;
  local_10[3] = param_8;
  local_28[2] = (iVar1 + param_9) / 2 - (((param_10 / 2 - param_11) + 0xb) * param_5) / 0x1e;
  local_28[3] = param_9;
  local_10[2] = local_38[0];
  FUN_004706bd(param_1,local_38,param_6,param_7);
  iVar1 = 0;
  do {
    CDC::LineTo(param_1,*(int *)((int)local_10 + iVar1),*(int *)((int)local_28 + iVar1));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x10);
  return;
}

