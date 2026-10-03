
void FUN_004be1f9(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int dx;
  LPRECT unaff_retaddr;
  int nIndex;
  
  if (DAT_005381f4 == 0) {
    uVar1 = FUN_004af3eb();
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
      unaff_retaddr->top = unaff_retaddr->top - DAT_00538434;
    }
  }
  else {
    FUN_004ae47a(param_1,param_2);
  }
  return;
}

