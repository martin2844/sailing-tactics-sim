
void FUN_004c067e(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004ce444;
  iVar3 = DAT_00538188;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar3 != 0) && (pcVar1 = *(code **)(iVar3 + 0x18), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004ce28c;
  *unaff_FS_OFFSET = uVar2;
  return;
}

