
void FUN_0049e630(void)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_004d0a18;
  pcStack_10 = FUN_0049e908;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  iVar1 = FUN_0049e5b0();
  if (*(int *)(iVar1 + 0x60) != 0) {
    local_8 = 1;
    iVar1 = FUN_0049e5b0();
    (**(code **)(iVar1 + 0x60))();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}

