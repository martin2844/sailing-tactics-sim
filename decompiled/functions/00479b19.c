
void __thiscall FUN_00479b19(void *this,LPRECT param_1,int param_2)

{
  uint uVar1;
  int dx;
  LPRECT unaff_retaddr;
  int nIndex;
  
  if (DAT_004ae69c == 0) {
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x40600) == 0) {
      GetSystemMetrics(6);
      nIndex = 5;
    }
    else {
      GetSystemMetrics(0x21);
      nIndex = 0x20;
    }
    dx = GetSystemMetrics(nIndex);
    InflateRect(unaff_retaddr,dx,nIndex);
    if ((uVar1 & 0xc00000) != 0) {
      unaff_retaddr->top = unaff_retaddr->top - DAT_004ae8dc;
    }
  }
  else {
    FUN_00469d9a(this,param_1,param_2);
  }
  return;
}

