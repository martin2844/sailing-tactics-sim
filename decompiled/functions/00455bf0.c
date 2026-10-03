
undefined4 FUN_00455bf0(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;
  
  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    pCVar1 = AfxGetThread();
    uVar2 = (**(code **)(*(int *)pCVar1 + 0x7c))();
    return uVar2;
  }
  return 0;
}

