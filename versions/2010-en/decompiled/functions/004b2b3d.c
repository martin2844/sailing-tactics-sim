
undefined4 FUN_004b2b3d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar2;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_004b2c70(unaff_EBP + -300);
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  uVar2 = 0x100;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  uVar1 = FUN_004b0956(0x100);
  FUN_004c1464(unaff_EBP + -0x11a,uVar1,uVar2);
  FUN_004b09a5(0xffffffff);
  FUN_004b046a(*(Tact2010CString **)(unaff_EBP + 8),(Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

