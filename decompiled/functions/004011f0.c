
undefined4 * __fastcall FUN_004011f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d0a8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_0047656f();
  local_4 = 0;
  FUN_0047a1c8(param_1 + 0x2f);
  *param_1 = &PTR_FUN_004822e0;
  *unaff_FS_OFFSET = local_c;
  return param_1;
}

