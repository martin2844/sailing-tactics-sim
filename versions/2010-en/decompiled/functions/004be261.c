
void FUN_004be261(LPRECT param_1,uint param_2)

{
  int dx;
  int nIndex;
  
  if (DAT_005381f4 == 0) {
    if ((param_2 & 0x40600) == 0) {
      GetSystemMetrics(6);
      nIndex = 5;
    }
    else {
      GetSystemMetrics(0x21);
      nIndex = 0x20;
    }
    dx = GetSystemMetrics(nIndex);
    InflateRect(param_1,dx,nIndex);
    if ((param_2 & 0xc00000) != 0) {
      FUN_004bd2af();
      param_1->top = param_1->top - DAT_00538434;
    }
  }
  else {
    AdjustWindowRectEx(param_1,param_2,0,0x188);
  }
  return;
}

