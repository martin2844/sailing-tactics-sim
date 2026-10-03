
void FUN_0049e430(int param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d0a08;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != 0) && (iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 4), iVar1 != 0)) {
    local_8 = 0;
    FUN_0049b0c0(*(undefined4 *)(param_1 + 0x18),iVar1);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}

