
void FUN_004563d8(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_0048804c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00468970((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046723d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

