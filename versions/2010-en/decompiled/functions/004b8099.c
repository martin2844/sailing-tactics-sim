
bool FUN_004b8099(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004aab08(*(undefined4 *)(unaff_EBP + 0x14),0,0,6,0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b1f41(*(undefined4 *)(unaff_EBP + 0xc));
  *(uint *)(unaff_EBP + -0x180) = *(uint *)(unaff_EBP + -0x180) | *(uint *)(unaff_EBP + 0x10);
  FUN_004b045a((Tact2010CString *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int *)(unaff_EBP + 0x18) == 0) {
    bVar2 = 1;
    puVar5 = *(undefined4 **)(extraout_ECX + 8);
    while (puVar5 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar5;
      FUN_004b8245(unaff_EBP + 0x14,unaff_EBP + -0x1b4,puVar5[2],-(uint)bVar2 & unaff_EBP - 0x10U);
      bVar2 = 0;
      puVar5 = puVar1;
    }
  }
  else {
    FUN_004b8245(unaff_EBP + 0x14,unaff_EBP + -0x1b4,*(undefined4 *)(unaff_EBP + 0x18),
                 unaff_EBP + -0x10);
  }
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004b1f41(0xf002);
  FUN_004b093e(unaff_EBP + -0x18);
  FUN_004b0929(0);
  FUN_004b0902(&DAT_004cf6e0);
  FUN_004b0929(0);
  *(int *)(unaff_EBP + -0x1a0) = *(int *)(unaff_EBP + -0x1a0) + 1;
  *(undefined4 *)(unaff_EBP + -0x1a8) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x184) = *(undefined4 *)(unaff_EBP + -0x14);
  uVar3 = FUN_004b0956(0x104);
  *(undefined4 *)(unaff_EBP + -0x198) = uVar3;
  iVar4 = FUN_004aac7a();
  FUN_004b09a5(0xffffffff);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x164));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0x210));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar4 == 1;
}

