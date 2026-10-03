
undefined4 FUN_00468629(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  iVar2 = FUN_0047b918();
  if ((*(char *)(iVar2 + 0x14) != '\0') && (*(HHOOK *)(iVar1 + 0x2c) != (HHOOK)0x0)) {
    UnhookWindowsHookEx(*(HHOOK *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  if (*(int *)(iVar1 + 0x14) != 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    return 0;
  }
  return 1;
}

