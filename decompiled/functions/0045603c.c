
void __thiscall CDialog::~CDialog(CDialog *this)

{
  CWnd *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWnd **)(unaff_EBP + -0x10) = this_00;
  *(undefined ***)this_00 = &PTR_FUN_00485644;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this_00 + 0x1c) != 0) {
    FUN_00468970((int)this_00);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this_00);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

