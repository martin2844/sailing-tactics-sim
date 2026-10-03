
int __fastcall FUN_004b43cc(CView *param_1)

{
  int iVar1;
  CFrameWnd *this;
  CView *pCVar2;
  HWND hWnd;
  BOOL BVar3;
  
  iVar1 = FUN_004ac701();
  if (((iVar1 != 3) && (iVar1 != 4)) &&
     (this = (CFrameWnd *)FUN_004add82(), this != (CFrameWnd *)0x0)) {
    pCVar2 = (CView *)FUN_004bbf0e();
    hWnd = GetFocus();
    if (((pCVar2 == param_1) && (*(HWND *)(param_1 + 0x1c) != hWnd)) &&
       (BVar3 = IsChild(*(HWND *)(param_1 + 0x1c),hWnd), BVar3 == 0)) {
      (**(code **)(*(int *)param_1 + 0xec))(1,param_1,param_1);
      return iVar1;
    }
    CFrameWnd::SetActiveView(this,param_1,1);
  }
  return iVar1;
}

