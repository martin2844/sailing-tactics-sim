
undefined4 FUN_004a74f0(undefined4 param_1)

{
  int iVar1;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  DAT_00539a84 = DAT_00539a84 + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  if (DAT_00539a84 == 1) {
    FUN_004aa3f0(param_1,1,0);
    FUN_004a7fc0();
  }
  iVar1 = FUN_004a7770();
  if (iVar1 != 0) {
    FUN_004a7620(param_1);
  }
  return DAT_00539a80;
}

