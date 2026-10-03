
void FUN_0046bb2f(int param_1,WPARAM param_2,LPARAM param_3)

{
  int iVar1;
  CWinThread *pCVar2;
  
  iVar1 = FUN_0047b918();
  if ((*(char *)(iVar1 + 0x14) == '\0') &&
     (((-1 < param_1 || (param_1 == 0x8001)) &&
      (pCVar2 = AfxGetThread(), pCVar2 != (CWinThread *)0x0)))) {
    (**(code **)(*(int *)pCVar2 + 0x78))(param_1,param_3);
    return;
  }
  iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  CallNextHookEx(*(HHOOK *)(iVar1 + 0x30),param_1,param_2,param_3);
  return;
}

