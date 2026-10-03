
undefined4 FUN_004a7770(void)

{
  DWORD DVar1;
  DWORD *pDVar2;
  int iVar3;
  
  DVar1 = GetCurrentThreadId();
  iVar3 = 0;
  if (0 < DAT_00539adc) {
    pDVar2 = &DAT_00539ae4;
    do {
      if (*pDVar2 == DVar1) {
        return 1;
      }
      pDVar2 = pDVar2 + 5;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00539adc);
  }
  return 0;
}

