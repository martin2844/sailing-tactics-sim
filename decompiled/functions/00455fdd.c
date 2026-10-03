
void FUN_00455fdd(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0048744c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046d845((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00485d04;
  *unaff_FS_OFFSET = uVar1;
  return;
}

