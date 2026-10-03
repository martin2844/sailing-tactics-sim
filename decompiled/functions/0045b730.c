
void __cdecl FUN_0045b730(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (*(int *)(&DAT_0049ffa0 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_00457640(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_0045b730(0x11);
    if (*(int *)(&DAT_0049ffa0 + param_1 * 4) == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *(LPCRITICAL_SECTION *)(&DAT_0049ffa0 + param_1 * 4) = lpCriticalSection;
    }
    else {
      FUN_00457710((undefined *)lpCriticalSection);
    }
    FUN_0045b7b0(0x11);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0049ffa0 + param_1 * 4));
  return;
}

