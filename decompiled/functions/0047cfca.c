
void FUN_0047cfca(void)

{
  code *pcVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *lpClassName;
  
  iVar2 = FUN_0047b918();
  FUN_0047c1af(1);
  lpClassName = (byte *)(iVar2 + 0x34);
  while (*lpClassName != 0) {
    pbVar3 = FUN_00457780(lpClassName,10);
    *pbVar3 = 0;
    iVar4 = FUN_0047b918();
    UnregisterClassA((LPCSTR)lpClassName,*(HINSTANCE *)(iVar4 + 8));
    lpClassName = pbVar3 + 1;
  }
  *(byte *)(iVar2 + 0x34) = 0;
  FUN_0047c21f(1);
  iVar2 = FUN_0047b918();
  if ((*(int *)(iVar2 + 4) != 0) &&
     (pcVar1 = *(code **)(*(int *)(iVar2 + 4) + 0x54), pcVar1 != (code *)0x0)) {
    (*pcVar1)(1,0);
  }
  iVar2 = FUN_0047b5c5();
  if (*(int **)(iVar2 + 0xcc) != (int *)0x0) {
    iVar4 = FUN_0045641f(*(int **)(iVar2 + 0xcc));
    if (iVar4 != 0) {
      *(undefined4 *)(iVar2 + 0xcc) = 0;
    }
  }
  iVar4 = FUN_0047b918();
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

