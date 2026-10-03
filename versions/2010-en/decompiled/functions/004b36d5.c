
undefined4 FUN_004b36d5(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar4;
  
  FUN_0049bcd8();
  iVar2 = *extraout_ECX;
  *(int *)(unaff_EBP + -0x18) = iVar2;
  iVar2 = (**(code **)(iVar2 + 0x60))();
  if (iVar2 != 0) {
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
    iVar2 = *(int *)(extraout_ECX[8] + -8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 == 0) {
      FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x10),(Tact2010CString *)(extraout_ECX + 7));
      if (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0) {
        FUN_004b1f41(0xf003);
      }
    }
    else {
      FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x10),(Tact2010CString *)(extraout_ECX + 8));
      if (DAT_005381f8 != 0) {
        pcVar1 = ((Tact2010CString *)(extraout_ECX + 8))->data;
        uVar4 = 0x104;
        uVar3 = FUN_004b0956(0x104);
        FUN_004b1562(pcVar1,uVar3,uVar4);
        FUN_004b09a5(0xffffffff);
      }
    }
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b8baa(unaff_EBP + -0x14,0xf103,*(undefined4 *)(unaff_EBP + -0x10));
    iVar2 = FUN_004b6ccb(*(undefined4 *)(unaff_EBP + -0x14),3,0xf103);
    if (iVar2 == 2) {
LAB_004b37c2:
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
      uVar3 = 0;
      goto LAB_004b37db;
    }
    if (iVar2 == 6) {
      iVar2 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xa4))();
      if (iVar2 == 0) goto LAB_004b37c2;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  }
  uVar3 = 1;
LAB_004b37db:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

