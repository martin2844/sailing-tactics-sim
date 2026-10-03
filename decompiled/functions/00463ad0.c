
void FUN_00463ad0(void)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  piVar1 = &DAT_004b09a0;
  do {
    if (*piVar1 != 0) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 6;
  } while (piVar1 < &DAT_004b0a30);
  FUN_00462b10();
  if (DAT_004aff48 != 0) {
    GlobalDeleteAtom(DAT_004aff48);
  }
  if (DAT_004aff4e != 0) {
    GlobalDeleteAtom(DAT_004aff4e);
  }
  if (DAT_004aff4c != 0) {
    GlobalDeleteAtom(DAT_004aff4c);
  }
  if (DAT_004aff4a != 0) {
    GlobalDeleteAtom(DAT_004aff4a);
  }
  if (DAT_004aff52 != 0) {
    GlobalDeleteAtom(DAT_004aff52);
  }
  if (DAT_004aff50 != 0) {
    GlobalDeleteAtom(DAT_004aff50);
  }
  if (DAT_004aff54 != 0) {
    GlobalDeleteAtom(DAT_004aff54);
  }
  DAT_004aff40 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  return;
}

