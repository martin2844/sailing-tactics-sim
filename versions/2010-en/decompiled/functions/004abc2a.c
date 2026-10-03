
/* Library Function - Single Match
    public: virtual __thiscall CDialog::~CDialog(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CDialog::~CDialog(CDialog *this)

{
  CWnd *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWnd **)(unaff_EBP + -0x10) = this_00;
  *(undefined ***)this_00 = &PTR_FUN_004cd2e4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this_00 + 0x1c) != 0) {
    FUN_004ad050();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this_00);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

