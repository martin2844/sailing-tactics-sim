
void FUN_004af667(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_004cd944;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[4] != 0) {
    (**(code **)(extraout_ECX[4] + 0x1c))();
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_004cd9a4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

