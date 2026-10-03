
undefined4 FUN_004a7560(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = 0;
  DVar1 = GetCurrentThreadId();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (0 < DAT_00539adc) {
    do {
      if (((&DAT_00539ae4)[iVar3 * 5] == DVar1) &&
         ((iVar2 = (&DAT_00539aec)[iVar3 * 5], (&DAT_00539aec)[iVar3 * 5] = iVar2 + -1,
          iVar2 + -1 == 0 || ((&DAT_00539ae0)[iVar3 * 5] == param_1)))) {
        UnhookWindowsHookEx((HHOOK)(&DAT_00539ae8)[iVar3 * 5]);
        DAT_00539adc = DAT_00539adc + -1;
        if (iVar3 < DAT_00539adc) {
          puVar5 = &DAT_00539ae0 + iVar3 * 5;
          do {
            iVar3 = iVar3 + 1;
            puVar4 = puVar5 + 5;
            puVar6 = puVar5;
            for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar6 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar6 = puVar6 + 1;
            }
            puVar5 = puVar5 + 5;
          } while (iVar3 < DAT_00539adc);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00539adc);
  }
  DAT_00539a84 = DAT_00539a84 + -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (DAT_00539a84 == 0) {
    FUN_004a81b0();
  }
  return 1;
}

