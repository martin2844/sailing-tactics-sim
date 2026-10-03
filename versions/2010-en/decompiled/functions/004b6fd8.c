
void FUN_004b6fd8(void)

{
  int iVar1;
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004cf414;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b772c();
  if (*(int *)(this + 0x6c) != 0) {
    FUN_004bb9d0(this);
  }
  iVar1 = *(int *)(this + 0x74);
  *(undefined4 *)(this + 0x74) = 0;
  if (iVar1 != 0) {
    FUN_004b8bc1();
    FUN_004afc21(iVar1);
  }
  if (*(int *)(this + 0x5c) != 0) {
    FUN_0049bfd0(*(int *)(this + 0x5c));
  }
  iVar1 = FUN_004bfca5();
  if (*(CWnd **)(iVar1 + 0x108) == this) {
    *(undefined4 *)(iVar1 + 0x108) = 0;
    *(undefined4 *)(iVar1 + 0x104) = 0xffffffff;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

