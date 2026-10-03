
undefined4 FUN_004a7630(undefined4 param_1,uint param_2)

{
  DWORD dwThreadId;
  int iVar1;
  HHOOK pHVar2;
  DWORD *pDVar3;
  uint uVar4;
  
  if (DAT_00539aa0 < 0x30a) {
    return 0;
  }
  if (DAT_00539a80 == 0) {
    return 0;
  }
  uVar4 = param_2 | 1;
  if ((param_2 & 2) != 0) {
    uVar4 = param_2 & 0xfffffffc;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (DAT_00539adc != 0x80) {
    dwThreadId = GetCurrentThreadId();
    iVar1 = 0;
    if (0 < DAT_00539adc) {
      pDVar3 = &DAT_00539ae4;
      do {
        if (*pDVar3 == dwThreadId) {
          (&DAT_00539aec)[iVar1 * 5] = (&DAT_00539aec)[iVar1 * 5] + 1;
          goto LAB_004a7736;
        }
        pDVar3 = pDVar3 + 5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_00539adc);
    }
    pHVar2 = SetWindowsHookExA(5,FUN_004a8790,DAT_00539a9c,dwThreadId);
    if (pHVar2 != (HHOOK)0x0) {
      (&DAT_00539ae0)[DAT_00539adc * 5] = param_1;
      (&DAT_00539ae4)[DAT_00539adc * 5] = dwThreadId;
      (&DAT_00539ae8)[DAT_00539adc * 5] = pHVar2;
      (&DAT_00539aec)[DAT_00539adc * 5] = 1;
      *(uint *)(&DAT_00539af0 + DAT_00539adc * 0x14) = uVar4;
      DAT_00539ad8 = DAT_00539adc;
      DAT_00539adc = DAT_00539adc + 1;
      DAT_00539ad4 = dwThreadId;
LAB_004a7736:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
      return 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  return 0;
}

