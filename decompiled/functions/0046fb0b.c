
/* Library Function - Multiple Matches With Same Base Name
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTA *)
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTW *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined4 __thiscall OnCreate(void *this,int *param_1)

{
  void *this_00;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00468021(this);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((*param_1 != 0) && (this_00 = *(void **)(*param_1 + 4), this_00 != (void *)0x0)) {
      FUN_0046f996(this_00,(int)this);
    }
    uVar2 = 0;
  }
  return uVar2;
}

