
void FUN_004c16aa(void)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  LPCSTR lpClassName;
  
  iVar2 = FUN_004bfff8();
  FUN_004c088f(1);
  lpClassName = (LPCSTR)(iVar2 + 0x34);
  while (*lpClassName != '\0') {
    puVar3 = (undefined1 *)FUN_0049c040(lpClassName,10);
    *puVar3 = 0;
    iVar4 = FUN_004bfff8();
    UnregisterClassA(lpClassName,*(HINSTANCE *)(iVar4 + 8));
    lpClassName = puVar3 + 1;
  }
  *(LPCSTR)(iVar2 + 0x34) = '\0';
  FUN_004c08ff(1);
  iVar2 = FUN_004bfff8();
  if ((*(int *)(iVar2 + 4) != 0) &&
     (pcVar1 = *(code **)(*(int *)(iVar2 + 4) + 0x54), pcVar1 != (code *)0x0)) {
    (*pcVar1)(1,0);
  }
  iVar2 = FUN_004bfca5();
  if (*(int *)(iVar2 + 0xcc) != 0) {
    iVar4 = FUN_0049ab0f();
    if (iVar4 != 0) {
      *(undefined4 *)(iVar2 + 0xcc) = 0;
    }
  }
  iVar4 = FUN_004bfff8();
  if (*(char *)(iVar4 + 0x14) == '\0') {
    if (*(HHOOK *)(iVar2 + 0x30) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x30));
      *(undefined4 *)(iVar2 + 0x30) = 0;
    }
    if (*(HHOOK *)(iVar2 + 0x2c) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x2c));
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
  }
  return;
}

