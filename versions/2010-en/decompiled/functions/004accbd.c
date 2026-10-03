
void FUN_004accbd(int param_1)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  
  iVar1 = FUN_004c04f2(FUN_0049a32a);
  if (*(int *)(iVar1 + 0x14) != param_1) {
    if (*(int *)(iVar1 + 0x2c) == 0) {
      dwThreadId = GetCurrentThreadId();
      pHVar2 = SetWindowsHookExA(5,FUN_004acb2f,(HINSTANCE)0x0,dwThreadId);
      *(HHOOK *)(iVar1 + 0x2c) = pHVar2;
      if (pHVar2 == (HHOOK)0x0) {
        FUN_004aa740();
      }
    }
    *(int *)(iVar1 + 0x14) = param_1;
  }
  return;
}

