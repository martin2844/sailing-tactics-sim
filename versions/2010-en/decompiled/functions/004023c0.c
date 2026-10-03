
undefined4 __fastcall FUN_004023c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c182a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar1 = FUN_004afbe5(0x40,param_1);
  local_4 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_00402440(iVar1);
    *unaff_FS_OFFSET = local_c;
    return uVar2;
  }
  *unaff_FS_OFFSET = local_c;
  return 0;
}

