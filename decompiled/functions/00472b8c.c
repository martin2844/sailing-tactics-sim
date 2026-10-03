
undefined4 __thiscall FUN_00472b8c(void *this,WPARAM param_1)

{
  CWnd *pCVar1;
  int iVar2;
  
  pCVar1 = CWnd::GetOwner(this);
  iVar2 = FUN_0047b5c5();
  if (param_1 == 0xffffffff) {
    *(undefined4 *)(iVar2 + 0x108) = 0;
    if ((*(byte *)((int)this + 0x60) & 8) == 0) {
      KillTimer(*(HWND *)((int)this + 0x1c),0xe000);
      return 0;
    }
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x375,0xe001,0);
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) & 0xfffffff7;
  }
  else {
    if (((*(byte *)((int)this + 0x60) & 8) != 0) && (*(WPARAM *)(iVar2 + 0x104) == param_1)) {
      return 0;
    }
    *(void **)(iVar2 + 0x108) = this;
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x362,param_1,0);
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 8;
    CControlBar::ResetTimer(this,0xe001,200);
  }
  return 1;
}

