
void FUN_004c088f(int param_1)

{
  int *piVar1;
  
  if (DAT_00538200 == 0) {
    FUN_004c0841();
  }
  if (DAT_005383a0 == 0) {
    piVar1 = (int *)(&DAT_005383c0 + param_1 * 4);
    if (*(int *)(&DAT_005383c0 + param_1 * 4) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_005383a8);
      if (*piVar1 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)(&DAT_00538208 + param_1 * 0x18));
        *piVar1 = *piVar1 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_005383a8);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_00538208 + param_1 * 0x18));
  }
  return;
}

