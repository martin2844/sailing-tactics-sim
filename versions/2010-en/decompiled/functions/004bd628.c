
void FUN_004bd628(LPRECT param_1)

{
  uint uVar1;
  int iVar2;
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
    iVar2 = GetSystemMetrics(nIndex);
    InflateRect(param_1,-iVar2,nIndex);
    if ((uVar1 & 0xc00000) != 0) {
      param_1->top = param_1->top + DAT_00538434;
    }
  }
  else {
    FUN_004ac701();
  }
  return;
}

