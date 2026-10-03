
undefined4 FUN_00462f50(undefined4 param_1,uint param_2)

{
  DWORD dwThreadId;
  int iVar1;
  HHOOK pHVar2;
  DWORD *pDVar3;
  uint uVar4;
  
  if (DAT_004aff60 < 0x30a) {
    return 0;
  }
  if (DAT_004aff40 == 0) {
    return 0;
  }
  uVar4 = param_2 | 1;
  if ((param_2 & 2) != 0) {
    uVar4 = param_2 & 0xfffffffc;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  if (DAT_004aff9c != 0x80) {
    dwThreadId = GetCurrentThreadId();
    iVar1 = 0;
    if (0 < DAT_004aff9c) {
      pDVar3 = &DAT_004affa4;
      do {
        if (*pDVar3 == dwThreadId) {
          (&DAT_004affac)[iVar1 * 5] = (&DAT_004affac)[iVar1 * 5] + 1;
          goto LAB_00463056;
        }
        pDVar3 = pDVar3 + 5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_004aff9c);
    }
    pHVar2 = SetWindowsHookExA(5,FUN_004640b0,DAT_004aff5c,dwThreadId);
    if (pHVar2 != (HHOOK)0x0) {
      (&DAT_004affa0)[DAT_004aff9c * 5] = param_1;
      (&DAT_004affa4)[DAT_004aff9c * 5] = dwThreadId;
      (&DAT_004affa8)[DAT_004aff9c * 5] = pHVar2;
      (&DAT_004affac)[DAT_004aff9c * 5] = 1;
      *(uint *)(&DAT_004affb0 + DAT_004aff9c * 0x14) = uVar4;
      DAT_004aff98 = DAT_004aff9c;
      DAT_004aff9c = DAT_004aff9c + 1;
      DAT_004aff94 = dwThreadId;
LAB_00463056:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
      return 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  return 0;
}

