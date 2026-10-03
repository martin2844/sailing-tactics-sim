
void FUN_0049fe10(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (*(int *)(&DAT_004ee160 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_0049bf00(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_0049fe10(0x11);
    if (*(int *)(&DAT_004ee160 + param_1 * 4) == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *(LPCRITICAL_SECTION *)(&DAT_004ee160 + param_1 * 4) = lpCriticalSection;
    }
    else {
      FUN_0049bfd0();
    }
    FUN_0049fe90(0x11);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_004ee160 + param_1 * 4));
  return;
}

