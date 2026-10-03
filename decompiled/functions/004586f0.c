
void FUN_004586f0(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00488bd8;
  pcStack_10 = FUN_0045b408;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_00458768();
  *unaff_FS_OFFSET = local_14;
  return;
}

