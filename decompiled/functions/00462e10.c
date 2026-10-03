
undefined4 FUN_00462e10(undefined4 param_1)

{
  int iVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  DAT_004aff44 = DAT_004aff44 + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  if (DAT_004aff44 == 1) {
    FUN_00465d10(param_1,1);
    FUN_004638e0();
  }
  iVar1 = FUN_00463090();
  if (iVar1 != 0) {
    FUN_00462f40(param_1);
  }
  return DAT_004aff40;
}

