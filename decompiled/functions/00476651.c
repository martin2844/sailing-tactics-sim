
void FUN_00476651(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004861bc;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004766dc((int)this);
  if (*(undefined **)(this + 0xa4) != (undefined *)0x0) {
    FUN_0046b541(*(undefined **)(this + 0xa4));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046bec5((int *)(this + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00466ab1();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

