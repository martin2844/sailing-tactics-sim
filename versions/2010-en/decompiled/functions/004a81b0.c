
void FUN_004a81b0(void)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  piVar1 = &DAT_0053a4e0;
  do {
    if (*piVar1 != 0) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 6;
  } while (piVar1 < &DAT_0053a570);
  FUN_004a71f0();
  if (DAT_00539a88 != 0) {
    GlobalDeleteAtom(DAT_00539a88);
  }
  if (DAT_00539a8e != 0) {
    GlobalDeleteAtom(DAT_00539a8e);
  }
  if (DAT_00539a8c != 0) {
    GlobalDeleteAtom(DAT_00539a8c);
  }
  if (DAT_00539a8a != 0) {
    GlobalDeleteAtom(DAT_00539a8a);
  }
  if (DAT_00539a92 != 0) {
    GlobalDeleteAtom(DAT_00539a92);
  }
  if (DAT_00539a90 != 0) {
    GlobalDeleteAtom(DAT_00539a90);
  }
  if (DAT_00539a94 != 0) {
    GlobalDeleteAtom(DAT_00539a94);
  }
  DAT_00539a80 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  return;
}

