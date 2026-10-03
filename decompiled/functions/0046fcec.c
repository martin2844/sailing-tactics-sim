
int __fastcall FUN_0046fcec(CView *param_1)

{
  int iVar1;
  CWnd *this;
  CView *pCVar2;
  HWND hWnd;
  BOOL BVar3;
  
  iVar1 = FUN_00468021(param_1);
  if (((iVar1 != 3) && (iVar1 != 4)) && (this = FUN_004696a2((int)param_1), this != (CWnd *)0x0)) {
    pCVar2 = (CView *)FUN_0047782e((int)this);
    hWnd = GetFocus();
    if (((pCVar2 == param_1) && (*(HWND *)(param_1 + 0x1c) != hWnd)) &&
       (BVar3 = IsChild(*(HWND *)(param_1 + 0x1c),hWnd), BVar3 == 0)) {
      (**(code **)(*(int *)param_1 + 0xec))(1,param_1,param_1);
      return iVar1;
    }
    CFrameWnd::SetActiveView((CFrameWnd *)this,param_1,1);
  }
  return iVar1;
}

