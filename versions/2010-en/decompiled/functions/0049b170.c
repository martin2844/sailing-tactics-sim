
undefined4
FUN_0049b170(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int *unaff_FS_OFFSET;
  int local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = param_4 + 1;
  local_14 = FUN_0049b1d0;
  local_10 = param_2;
  local_c = param_1;
  local_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_18;
  return uVar1;
}

