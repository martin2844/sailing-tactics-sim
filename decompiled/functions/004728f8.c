
void FUN_004728f8(void)

{
  undefined4 *puVar1;
  int iVar2;
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_00487774;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047304c((int *)this);
  if (*(void **)(this + 0x6c) != (void *)0x0) {
    FUN_004772f0(*(void **)(this + 0x6c),(int)this);
  }
  puVar1 = *(undefined4 **)(this + 0x74);
  *(undefined4 *)(this + 0x74) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004744e1(puVar1);
    FUN_0046b541((undefined *)puVar1);
  }
  if (*(undefined **)(this + 0x5c) != (undefined *)0x0) {
    FUN_00457710(*(undefined **)(this + 0x5c));
  }
  iVar2 = FUN_0047b5c5();
  if (*(CWnd **)(iVar2 + 0x108) == this) {
    *(undefined4 *)(iVar2 + 0x108) = 0;
    *(undefined4 *)(iVar2 + 0x104) = 0xffffffff;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

