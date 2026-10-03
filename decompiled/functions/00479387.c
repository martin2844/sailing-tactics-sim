
void __thiscall FUN_00479387(void *this,undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (*(int *)((int)this + 0xbc) == 0) {
    FUN_00468021(this);
  }
  else {
    ReleaseCapture();
    *(undefined4 *)((int)this + 0xbc) = 0;
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    uVar1 = FUN_00478fae(this,param_2,param_3);
    if (uVar1 == 3) {
      FUN_004793e7();
      SendMessageA(*(HWND *)((int)this + 0x1c),0x10,0,0);
    }
  }
  return;
}

