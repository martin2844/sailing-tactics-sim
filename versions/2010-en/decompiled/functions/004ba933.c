
undefined4 FUN_004ba933(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  HMENU pHVar4;
  int iVar5;
  HWND pHVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  uVar2 = 0x80c83b00;
  *(undefined4 *)(extraout_ECX + 0xb0) = 1;
  if ((uVar1 & 4) != 0) {
    uVar2 = 0x80c83300;
  }
  iVar3 = FUN_004bd454(0,0,&DAT_00537ed8,uVar2,&DAT_00537eb8,*(undefined4 *)(unaff_EBP + 8),0);
  if (iVar3 == 0) {
    *(undefined4 *)(extraout_ECX + 0xb0) = 0;
  }
  else {
    pHVar4 = GetSystemMenu(*(HWND *)(extraout_ECX + 0x1c),0);
    iVar3 = FUN_004b1ec9(pHVar4);
    DeleteMenu(*(HMENU *)(iVar3 + 4),0xf000,0);
    FUN_004b045a((Tact2010CString *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar5 = FUN_004b1f41(0xf011);
    if (iVar5 != 0) {
      DeleteMenu(*(HMENU *)(iVar3 + 4),0xf060,0);
      AppendMenuA(*(HMENU *)(iVar3 + 4),0,0xf060,*(LPCSTR *)(unaff_EBP + 0xc));
    }
    iVar3 = FUN_004b9a68(*(undefined4 *)(unaff_EBP + 8),
                         (-(uint)((uVar1 & 0x5000) != 0) & 0xfffff000) + 0x2000 | uVar1 & 0x40 |
                         0x50000000,0xe81f);
    if (iVar3 != 0) {
      if (extraout_ECX == 0) {
        pHVar6 = (HWND)0x0;
      }
      else {
        pHVar6 = *(HWND *)(extraout_ECX + 0x1c);
      }
      pHVar6 = SetParent(*(HWND *)(extraout_ECX + 0xe8),pHVar6);
      FUN_004ac7ac(pHVar6);
      *(undefined4 *)(extraout_ECX + 0xb0) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0xc));
      uVar2 = 1;
      goto LAB_004baa6e;
    }
    *(undefined4 *)(extraout_ECX + 0xb0) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + 0xc));
  }
  uVar2 = 0;
LAB_004baa6e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

