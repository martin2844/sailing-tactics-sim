
undefined4 FUN_004bb691(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  HMENU pHVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(uint *)(extraout_ECX + 0x8c) = uVar1;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_004b1f41(uVar1);
  if (iVar2 != 0) {
    FUN_004b1fec(extraout_ECX + 0xac,*(undefined4 *)(unaff_EBP + 8),0,10);
  }
  iVar2 = FUN_004bfff8();
  if ((*(byte *)(iVar2 + 0x18) & 8) == 0) {
    iVar2 = FUN_004af183(8);
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 != 0) {
    uVar3 = GetIconWndClass(*(undefined4 *)(unaff_EBP + 0xc),uVar1);
    iVar2 = FUN_004bb47e(uVar3,*(undefined4 *)(extraout_ECX + 0xac),*(undefined4 *)(unaff_EBP + 0xc)
                         ,&DAT_00537eb8,*(undefined4 *)(unaff_EBP + 0x10),uVar1 & 0xffff,0,
                         *(undefined4 *)(unaff_EBP + 0x14));
    if (iVar2 != 0) {
      pHVar4 = GetMenu(*(HWND *)(extraout_ECX + 0x1c));
      *(HMENU *)(extraout_ECX + 0x44) = pHVar4;
      FUN_004bade0(uVar1 & 0xffff);
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        FUN_004ae04c(*(undefined4 *)(extraout_ECX + 0x1c),0x364,0,0,1,1);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + 8));
      uVar3 = 1;
      goto LAB_004bb76b;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 8));
  uVar3 = 0;
LAB_004bb76b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

