
void __thiscall FUN_004773a6(void *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0047782e((int)this);
  if (iVar1 != 0) {
    iVar2 = FUN_00467fec();
    SendMessageA(*(HWND *)(iVar1 + 0x1c),0x115,*(WPARAM *)(iVar2 + 8),*(LPARAM *)(iVar2 + 0xc));
  }
  return;
}

