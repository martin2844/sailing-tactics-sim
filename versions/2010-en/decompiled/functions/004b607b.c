
undefined4 * FUN_004b607b(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004af62b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(extraout_ECX + 0x18));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_004cf814;
  extraout_ECX[0xf] = uVar1;
  extraout_ECX[0x13] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x14] = *(undefined4 *)(unaff_EBP + 0x10);
  uVar1 = *(undefined4 *)(unaff_EBP + 0x14);
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x15] = uVar1;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  bVar3 = DAT_004ed5ec == 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (bVar3) {
    extraout_ECX[7] = 1;
    FUN_004b619a();
  }
  else {
    extraout_ECX[7] = 0;
    if (DAT_00537ed4 == 0) {
      iVar2 = FUN_004afbe5(0x1c);
      *(int *)(unaff_EBP + 8) = iVar2;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (iVar2 == 0) {
        DAT_00537ed4 = 0;
      }
      else {
        DAT_00537ed4 = FUN_004ab132(10);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    if (DAT_00537ed0 == 0) {
      iVar2 = FUN_004afbe5(0x20);
      *(int *)(unaff_EBP + 8) = iVar2;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (iVar2 == 0) {
        DAT_00537ed0 = 0;
      }
      else {
        DAT_00537ed0 = FUN_004c0b04();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    AddTail(extraout_ECX);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

