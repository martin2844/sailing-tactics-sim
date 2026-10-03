
void thunk_FUN_0047aad6(void)

{
  int *piVar1;
  int iVar2;
  CWinThread *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(CWinThread **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_FUN_004865f4;
  piVar1 = *(int **)(this + 0x80);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(1);
  }
  if (*(int **)(this + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xa8) + 0x14))(1);
  }
  iVar2 = FUN_0047b918();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    if (DAT_004ae37c != (int *)0x0) {
      (**(code **)(*DAT_004ae37c + 4))(1);
      DAT_004ae37c = (int *)0x0;
    }
    if (DAT_004ae378 != (int *)0x0) {
      (**(code **)(*DAT_004ae378 + 4))(1);
      DAT_004ae378 = (int *)0x0;
    }
  }
  if (*(HGLOBAL *)(this + 0x94) != (HGLOBAL)0x0) {
    FUN_00470fad(*(HGLOBAL *)(this + 0x94));
  }
  if (*(HGLOBAL *)(this + 0x98) != (HGLOBAL)0x0) {
    FUN_00470fad(*(HGLOBAL *)(this + 0x98));
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
  iVar2 = FUN_0047b918();
  if (*(int *)(iVar2 + 0x10) == *(int *)(this + 0x78)) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  if (*(CWinThread **)(iVar2 + 4) == this) {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_00457710(*(undefined **)(this + 0x78));
  FUN_00457710(*(undefined **)(this + 0x7c));
  FUN_00457710(*(undefined **)(this + 0x88));
  FUN_00457710(*(undefined **)(this + 0x8c));
  FUN_00457710(*(undefined **)(this + 0x90));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWinThread::~CWinThread(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

