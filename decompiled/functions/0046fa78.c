
void FUN_0046fa78(void)

{
  void *this;
  CWnd *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWnd **)(unaff_EBP + -0x10) = this_00;
  *(undefined ***)this_00 = &PTR_FUN_00486c24;
  this = *(void **)(this_00 + 0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (this != (void *)0x0) {
    FUN_0046f9b6(this,(int)this_00);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this_00);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

