
void FUN_00473c3e(void)

{
  CDialog *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bec5((int *)(this + 0xac));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDialog::~CDialog(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

