
/* Library Function - Single Match
    public: void __thiscall CFrameWnd::SetActiveView(class CView *,int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall CFrameWnd::SetActiveView(CFrameWnd *this,CView *param_1,int param_2)

{
  CView *pCVar1;
  
  pCVar1 = *(CView **)(this + 0x98);
  if (param_1 != pCVar1) {
    *(undefined4 *)(this + 0x98) = 0;
    if (pCVar1 != (CView *)0x0) {
      (**(code **)(*(int *)pCVar1 + 0xec))(0,param_1,pCVar1);
    }
    if (((*(int *)(this + 0x98) == 0) &&
        (*(CView **)(this + 0x98) = param_1, param_1 != (CView *)0x0)) && (param_2 != 0)) {
      (**(code **)(*(int *)param_1 + 0xec))(1,param_1,pCVar1);
    }
  }
  return;
}

