
void FUN_004b99fc(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004d026c;
  iVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (0 < (int)extraout_ECX[0x21]) {
    do {
      iVar1 = FUN_004ba70d(iVar2);
      if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 0x70) == extraout_ECX)) {
        *(undefined4 *)(iVar1 + 0x70) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)extraout_ECX[0x21]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab342();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b6fd8();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

