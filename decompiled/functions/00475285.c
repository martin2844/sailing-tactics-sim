
undefined4 * FUN_00475285(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0047c246(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00466c2f(extraout_ECX + 0x1f);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_004885cc;
  extraout_ECX[0x1e] = uVar1;
  extraout_ECX[0xf] = 1;
  iVar2 = extraout_ECX[0x21];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00466dbc(extraout_ECX + 0x1f,iVar2,0);
  extraout_ECX[0x24] = 0;
  SetRectEmpty((LPRECT)(extraout_ECX + 0x25));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x10] = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

