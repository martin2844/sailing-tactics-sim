
void __thiscall FUN_00469d9a(void *this,LPRECT param_1,int param_2)

{
  uint dwExStyle;
  DWORD dwStyle;
  BOOL bMenu;
  
  dwExStyle = FUN_0046ad25((int)this);
  if (param_2 == 0) {
    dwExStyle = dwExStyle & 0xfffffdff;
  }
  bMenu = 0;
  dwStyle = FUN_0046ad0b((int)this);
  AdjustWindowRectEx(param_1,dwStyle,bMenu,dwExStyle);
  return;
}

