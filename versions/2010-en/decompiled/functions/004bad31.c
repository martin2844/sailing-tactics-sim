
void FUN_004bad31(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004cde5c;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004badbc();
  if (*(int *)(this + 0xa4) != 0) {
    FUN_004afc21(*(int *)(this + 0xa4));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004b05a5((Tact2010CString *)(this + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004ab191();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

