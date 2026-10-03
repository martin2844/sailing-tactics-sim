
void __fastcall FUN_0046fb3b(int *param_1)

{
  CWnd *this;
  int *piVar1;
  
  this = FUN_004696a2((int)param_1);
  if (this != (CWnd *)0x0) {
    piVar1 = (int *)FUN_0047782e((int)this);
    if (piVar1 == param_1) {
      CFrameWnd::SetActiveView((CFrameWnd *)this,(CView *)0x0,1);
    }
  }
  FUN_00468829(param_1);
  return;
}

