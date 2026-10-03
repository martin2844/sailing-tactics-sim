
void FUN_0046eb71(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0048692c;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_0046ebe5((int)extraout_ECX);
  if ((int *)extraout_ECX[9] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[9] + 0x68))(extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00466ab1();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bec5(extraout_ECX + 8);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5(extraout_ECX + 7);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046af87();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

