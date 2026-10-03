
undefined4 * FUN_004aab08(void)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004abe98(0,*(undefined4 *)(unaff_EBP + 0x1c));
  *extraout_ECX = &PTR_FUN_004cfef4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 0x2b));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_004cfdfc;
  _memset(extraout_ECX + 0x17,0,0x4c);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  *(undefined1 *)(extraout_ECX + 0x2c) = 0;
  extraout_ECX[0x7d] = 0;
  extraout_ECX[0x2a] = iVar2;
  extraout_ECX[0x17] = 0x4c;
  extraout_ECX[0xf] = 0x7005 - (uint)(iVar2 != 0);
  extraout_ECX[0x26] = *(undefined4 *)(unaff_EBP + 0xc);
  uVar1 = *(uint *)(unaff_EBP + 0x14);
  extraout_ECX[0x1e] = extraout_ECX + 0x3c;
  extraout_ECX[0x24] = extraout_ECX[0x24] | uVar1 | 0x20;
  extraout_ECX[0x1f] = 0x104;
  extraout_ECX[0x20] = extraout_ECX + 0x2c;
  extraout_ECX[0x21] = 0x40;
  if (DAT_005381ec == 0) {
    iVar2 = FUN_004ac17b();
    if (iVar2 != 0) {
      extraout_ECX[0x24] = extraout_ECX[0x24] | 0x10;
    }
    if (DAT_005381ec == 0) goto LAB_004aabf2;
  }
  *(byte *)((int)extraout_ECX + 0x92) = *(byte *)((int)extraout_ECX + 0x92) | 8;
  iVar2 = FUN_004bfff8();
  extraout_ECX[0x19] = *(undefined4 *)(iVar2 + 0xc);
LAB_004aabf2:
  iVar2 = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x28] = FUN_004aafd9;
  if (iVar2 != 0) {
    lstrcpynA((LPSTR)(extraout_ECX + 0x3c),*(LPCSTR *)(unaff_EBP + 0x10),0x104);
  }
  if (*(int *)(unaff_EBP + 0x18) != 0) {
    FUN_004b06ed((Tact2010CString *)(extraout_ECX + 0x2b),*(char **)(unaff_EBP + 0x18));
    puVar3 = (undefined1 *)FUN_004b0956(0);
    while( true ) {
      puVar3 = (undefined1 *)FUN_0049c040(puVar3,0x7c);
      if (puVar3 == (undefined1 *)0x0) break;
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    extraout_ECX[0x1a] = extraout_ECX[0x2b];
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

