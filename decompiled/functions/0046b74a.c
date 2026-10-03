
void FUN_0046b74a(void)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  int iVar3;
  
  iVar1 = FUN_0047b918();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_0047b5c5();
    dwThreadId = GetCurrentThreadId();
    pHVar2 = SetWindowsHookExA(-1,FUN_0046bb2f,(HINSTANCE)0x0,dwThreadId);
    *(HHOOK *)(iVar1 + 0x30) = pHVar2;
    iVar1 = FUN_0047bea7();
    if (*(int *)(iVar1 + 0x14) != 0) {
      iVar3 = FUN_0047b918();
      (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar3 + 8));
    }
    FUN_0047be12(&DAT_004ae634,FUN_00455d19);
  }
  return;
}

