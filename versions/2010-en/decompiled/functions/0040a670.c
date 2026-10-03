
void __fastcall FUN_0040a670(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_004c1e48;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *param_1 = &PTR_FUN_004ceef4;
  local_4 = 0;
  FUN_004b5164();
  *param_1 = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = local_c;
  return;
}

