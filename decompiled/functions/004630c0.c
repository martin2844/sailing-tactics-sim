
undefined4 FUN_004630c0(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = 0;
  DVar1 = GetCurrentThreadId();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  if (0 < DAT_004aff9c) {
    do {
      if (((&DAT_004affa4)[iVar3 * 5] == DVar1) &&
         (iVar2 = (&DAT_004affac)[iVar3 * 5], (&DAT_004affac)[iVar3 * 5] = iVar2 + -1,
         iVar2 + -1 == 0)) {
        UnhookWindowsHookEx((HHOOK)(&DAT_004affa8)[iVar3 * 5]);
        DAT_004aff9c = DAT_004aff9c + -1;
        if (iVar3 < DAT_004aff9c) {
          puVar5 = &DAT_004affa0 + iVar3 * 5;
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
          } while (iVar3 < DAT_004aff9c);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_004aff9c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  return 1;
}

