
void FUN_004b831e(void)

{
  CDialog *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(this + 0xac));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDialog::~CDialog(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

