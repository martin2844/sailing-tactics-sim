
void FUN_004685dd(int param_1)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  
  iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  if (*(int *)(iVar1 + 0x14) != param_1) {
    if (*(int *)(iVar1 + 0x2c) == 0) {
      dwThreadId = GetCurrentThreadId();
      pHVar2 = SetWindowsHookExA(5,FUN_0046844f,(HINSTANCE)0x0,dwThreadId);
      *(HHOOK *)(iVar1 + 0x2c) = pHVar2;
      if (pHVar2 == (HHOOK)0x0) {
        FUN_00466060();
      }
    }
    *(int *)(iVar1 + 0x14) = param_1;
  }
  return;
}

