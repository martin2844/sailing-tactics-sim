
void FUN_0049e6c0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d0a30;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_FUN_004ee004 != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_FUN_004ee004)();
  }
  local_8 = 0xffffffff;
  FUN_0049e72e();
  *unaff_FS_OFFSET = local_14;
  return;
}

