
CWnd * FUN_0046fd81(CWnd *param_1,int param_2)

{
  CWnd *this;
  int iVar1;
  BOOL BVar2;
  
  GetParent(*(HWND *)(param_1 + 0x1c));
  this = FUN_004680cc();
  iVar1 = FUN_0046cf38(this,0x486bd0);
  if (iVar1 != 0) {
    if (param_2 != 0) {
      return this;
    }
    do {
      GetParent(*(HWND *)(param_1 + 0x1c));
      param_1 = FUN_004680cc();
      if (param_1 == (CWnd *)0x0) {
        return this;
      }
      BVar2 = IsIconic(*(HWND *)(param_1 + 0x1c));
    } while (BVar2 == 0);
  }
  return (CWnd *)0x0;
}

