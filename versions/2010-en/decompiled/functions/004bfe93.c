
void FUN_004bfe93(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cef7c;
  iVar1 = extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (iVar1 != 0) {
    FUN_0049a615();
    FUN_004afc21(iVar1);
  }
  iVar1 = extraout_ECX[6];
  if (iVar1 != 0) {
    FUN_0049a615();
    FUN_004afc21(iVar1);
  }
  iVar1 = extraout_ECX[7];
  if (iVar1 != 0) {
    FUN_0049a615();
    FUN_004afc21(iVar1);
  }
  iVar1 = extraout_ECX[8];
  if (iVar1 != 0) {
    FUN_0049a615();
    FUN_004afc21(iVar1);
  }
  iVar1 = extraout_ECX[9];
  if (iVar1 != 0) {
    FUN_0049a615();
    FUN_004afc21(iVar1);
  }
  iVar1 = extraout_ECX[0x1d];
  while (iVar1 != 0) {
    uVar2 = FUN_004ab25b();
    FUN_004afc21(uVar2);
    iVar1 = extraout_ECX[0x1d];
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004ab191();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004ab643();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab643();
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004ce28c;
  *unaff_FS_OFFSET = uVar2;
  return;
}

