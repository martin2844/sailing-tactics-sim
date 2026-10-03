
void FUN_00466c62(void)

{
  undefined *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00488b8c;
  puVar1 = (undefined *)extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046b541(puVar1);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

