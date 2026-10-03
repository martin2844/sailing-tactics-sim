
void FUN_004b4325(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b4fba(extraout_ECX);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 0xe4))(unaff_EBP + -0x60,0);
  (**(code **)(iVar1 + 0xf8))(unaff_EBP + -0x60);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x60));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

