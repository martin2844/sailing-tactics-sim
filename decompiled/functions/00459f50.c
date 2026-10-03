
void FUN_00459f50(void)

{
  DWORD *pDVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00488d70;
  pcStack_10 = FUN_0045b408;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  pDVar1 = FUN_00459ed0();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_00459ed0();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}

