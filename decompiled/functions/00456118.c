
void __thiscall FUN_00456118(void *this,WPARAM param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),0x1108,param_1,0);
  iVar2 = FUN_004562c7(uVar1);
  if (iVar2 != 0) {
    SendMessageA(*(HWND *)((int)this + 0x1c),0x1109,param_1,0);
  }
  return;
}

