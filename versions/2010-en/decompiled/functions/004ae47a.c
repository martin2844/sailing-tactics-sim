
void FUN_004ae47a(LPRECT param_1,int param_2)

{
  uint dwExStyle;
  DWORD dwStyle;
  BOOL bMenu;
  
  dwExStyle = FUN_004af405();
  if (param_2 == 0) {
    dwExStyle = dwExStyle & 0xfffffdff;
  }
  bMenu = 0;
  dwStyle = FUN_004af3eb();
  AdjustWindowRectEx(param_1,dwStyle,bMenu,dwExStyle);
  return;
}

