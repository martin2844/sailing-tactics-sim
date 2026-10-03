
undefined4 * __fastcall FUN_004011e0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c1788;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_004bac4f();
  local_4 = 0;
  FUN_004be8a8();
  *param_1 = &PTR_FUN_004c82e0;
  *unaff_FS_OFFSET = local_c;
  return param_1;
}

