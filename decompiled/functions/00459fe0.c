
void FUN_00459fe0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00488d88;
  pcStack_10 = FUN_0045b408;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_FUN_0049fe44 != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_FUN_0049fe44)();
  }
  local_8 = 0xffffffff;
  FUN_0045a04e();
  *unaff_FS_OFFSET = local_14;
  return;
}

