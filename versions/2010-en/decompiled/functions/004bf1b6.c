
void FUN_004bf1b6(void)

{
  int *piVar1;
  int iVar2;
  CWinThread *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(CWinThread **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004ce294;
  piVar1 = *(int **)(this + 0x80);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(1);
  }
  if (*(int **)(this + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xa8) + 0x14))(1);
  }
  iVar2 = FUN_004bfff8();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    if (DAT_00537ed4 != (int *)0x0) {
      (**(code **)(*DAT_00537ed4 + 4))(1);
      DAT_00537ed4 = (int *)0x0;
    }
    if (DAT_00537ed0 != (int *)0x0) {
      (**(code **)(*DAT_00537ed0 + 4))(1);
      DAT_00537ed0 = (int *)0x0;
    }
  }
  if (*(int *)(this + 0x94) != 0) {
    FUN_004b568d(*(int *)(this + 0x94));
  }
  if (*(int *)(this + 0x98) != 0) {
    FUN_004b568d(*(int *)(this + 0x98));
  }
  if (*(ATOM *)(this + 0xb0) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb0));
  }
  if (*(ATOM *)(this + 0xb2) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb2));
  }
  if (*(int **)(this + 0xac) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xac) + 4))(1);
  }
  iVar2 = FUN_004bfff8();
  if (*(int *)(iVar2 + 0x10) == *(int *)(this + 0x78)) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  if (*(CWinThread **)(iVar2 + 4) == this) {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_0049bfd0(*(undefined4 *)(this + 0x78));
  FUN_0049bfd0(*(undefined4 *)(this + 0x7c));
  FUN_0049bfd0(*(undefined4 *)(this + 0x88));
  FUN_0049bfd0(*(undefined4 *)(this + 0x8c));
  FUN_0049bfd0(*(undefined4 *)(this + 0x90));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWinThread::~CWinThread(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

