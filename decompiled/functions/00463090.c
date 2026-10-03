
undefined4 FUN_00463090(void)

{
  DWORD DVar1;
  DWORD *pDVar2;
  int iVar3;
  
  DVar1 = GetCurrentThreadId();
  iVar3 = 0;
  if (0 < DAT_004aff9c) {
    pDVar2 = &DAT_004affa4;
    do {
      if (*pDVar2 == DVar1) {
        return 1;
      }
      pDVar2 = pDVar2 + 5;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_004aff9c);
  }
  return 0;
}

