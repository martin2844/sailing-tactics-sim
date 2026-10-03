
void FUN_004afe2a(void)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  int iVar3;
  
  iVar1 = FUN_004bfff8();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_004bfca5();
    dwThreadId = GetCurrentThreadId();
    pHVar2 = SetWindowsHookExA(-1,FUN_004b020f,(HINSTANCE)0x0,dwThreadId);
    *(HHOOK *)(iVar1 + 0x30) = pHVar2;
    iVar1 = FUN_004c0587(FUN_0049a382);
    if (*(int *)(iVar1 + 0x14) != 0) {
      iVar3 = FUN_004bfff8();
      (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar3 + 8));
    }
    FUN_004c04f2(FUN_0049a409);
  }
  return;
}

