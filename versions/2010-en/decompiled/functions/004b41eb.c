
/* Library Function - Multiple Matches With Same Base Name
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTA *)
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTW *)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined4 __thiscall OnCreate(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004ac701();
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((*param_2 != 0) && (*(int *)(*param_2 + 4) != 0)) {
      FUN_004b4076(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

