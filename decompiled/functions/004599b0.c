
undefined4 __cdecl
FUN_004599b0(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00488d38;
  pcStack_10 = FUN_0045b408;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  FUN_00459ed0();
  FUN_00459ed0();
  pDVar1 = FUN_00459ed0();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_00459ed0();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_00456a80(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00459aa8();
  *unaff_FS_OFFSET = local_14;
  return uVar2;
}

