
undefined4
FUN_0049b200(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *unaff_FS_OFFSET;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_0049b2d0;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x49b29c;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  iVar1 = FUN_0049e5b0(*param_1,&local_34);
  (**(code **)(iVar1 + 0x68))();
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}

