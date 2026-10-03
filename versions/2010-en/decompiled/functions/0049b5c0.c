
void FUN_0049b5c0(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d0840;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*param_4)();
  }
  local_8 = 0xffffffff;
  FUN_0049b638();
  *unaff_FS_OFFSET = local_14;
  return;
}

