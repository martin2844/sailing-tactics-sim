
void FUN_004b4158(void)

{
  int iVar1;
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004ce8c4;
  iVar1 = *(int *)(this + 0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_004b4096(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

