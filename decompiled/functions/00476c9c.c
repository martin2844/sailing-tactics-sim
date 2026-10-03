
void __thiscall FUN_00476c9c(void *this,uint param_1)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  HWND hWnd;
  UINT uCmd;
  
  uVar1 = FUN_0046ad0b((int)this);
  pCVar2 = this;
  if ((uVar1 & 0x40000000) == 0) {
    pCVar2 = FUN_0046980f(this);
  }
  if ((param_1 & 0xc) != 0) {
    iVar3 = FUN_0046ae73((int)pCVar2);
    if ((((~param_1 & 8) == 0) || (iVar3 == 0)) || (pCVar2 == this)) {
      SendMessageA(*(HWND *)(pCVar2 + 0x1c),0x86,0,0);
    }
    else {
      *(byte *)((int)this + 0x25) = *(byte *)((int)this + 0x25) | 2;
      SendMessageA(*(HWND *)(pCVar2 + 0x1c),0x86,1,0);
      *(byte *)((int)this + 0x25) = *(byte *)((int)this + 0x25) & 0xfd;
    }
  }
  uCmd = 5;
  hWnd = GetDesktopWindow();
  while (hWnd = GetWindow(hWnd,uCmd), hWnd != (HWND)0x0) {
    iVar3 = FUN_00476980(*(HWND__ **)(pCVar2 + 0x1c),hWnd);
    if (iVar3 != 0) {
      SendMessageA(hWnd,0x36d,param_1,0);
    }
    uCmd = 2;
  }
  return;
}

