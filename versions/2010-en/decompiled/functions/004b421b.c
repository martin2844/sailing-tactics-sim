
void __fastcall FUN_004b421b(int param_1)

{
  CFrameWnd *this;
  int iVar1;
  
  this = (CFrameWnd *)FUN_004add82();
  if (this != (CFrameWnd *)0x0) {
    iVar1 = FUN_004bbf0e();
    if (iVar1 == param_1) {
      CFrameWnd::SetActiveView(this,(CView *)0x0,1);
    }
  }
  FUN_004acf09();
  return;
}

