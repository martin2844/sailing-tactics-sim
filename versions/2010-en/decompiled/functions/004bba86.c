
void __thiscall FUN_004bba86(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004bbf0e();
  if (iVar1 != 0) {
    iVar2 = FUN_004ac6cc();
    SendMessageA(*(HWND *)(iVar1 + 0x1c),0x115,*(WPARAM *)(iVar2 + 8),*(LPARAM *)(iVar2 + 0xc));
  }
  return;
}

