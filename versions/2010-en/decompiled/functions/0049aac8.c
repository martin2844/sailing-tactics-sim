
void FUN_0049aac8(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004cfcec;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004ad050();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab91d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

