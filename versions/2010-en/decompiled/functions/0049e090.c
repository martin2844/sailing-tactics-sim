
undefined4
FUN_0049e090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004d09e0;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  FUN_0049e5b0();
  FUN_0049e5b0();
  iVar1 = FUN_0049e5b0();
  *(undefined4 *)(iVar1 + 0x6c) = param_1;
  iVar1 = FUN_0049e5b0();
  *(undefined4 *)(iVar1 + 0x70) = param_3;
  local_8 = 1;
  uVar2 = FUN_0049b170(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_0049e188();
  *unaff_FS_OFFSET = local_14;
  return uVar2;
}

