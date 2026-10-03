
void FUN_0047c1af(int param_1)

{
  int *piVar1;
  
  if (DAT_004ae6a8 == 0) {
    FUN_0047c161();
  }
  if (DAT_004ae848 == 0) {
    piVar1 = (int *)(&DAT_004ae868 + param_1 * 4);
    if (*(int *)(&DAT_004ae868 + param_1 * 4) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004ae850);
      if (*piVar1 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)(&DAT_004ae6b0 + param_1 * 0x18));
        *piVar1 = *piVar1 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004ae850);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_004ae6b0 + param_1 * 0x18));
  }
  return;
}

