
void __thiscall FUN_0047865f(void *this,int param_1)

{
  BOOL BVar1;
  
  if (param_1 == -1) {
    BVar1 = IsWindowVisible(*(HWND *)((int)this + 0x1c));
    if (BVar1 == 0) {
      param_1 = 1;
    }
    else {
      BVar1 = IsIconic(*(HWND *)((int)this + 0x1c));
      if (BVar1 != 0) {
        param_1 = 9;
      }
    }
  }
  CFrameWnd::BringToTop(this,param_1);
  if (param_1 != -1) {
    FUN_0046ae4c(this,param_1);
    CFrameWnd::BringToTop(this,param_1);
  }
  return;
}

