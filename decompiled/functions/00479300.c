
void __thiscall FUN_00479300(void *this,undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  CWnd *pCVar2;
  uint uVar3;
  
  if (*(int *)((int)this + 0xbc) == 0) {
    FUN_00468021(this);
  }
  else {
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    GetCapture();
    pCVar2 = FUN_004680cc();
    if (pCVar2 == this) {
      uVar1 = *(uint *)((int)this + 0xc0);
      uVar3 = FUN_00478fae(this,param_2,param_3);
      if ((uVar3 == 3) != uVar1) {
        *(uint *)((int)this + 0xc0) = (uint)(uVar1 == 0);
        FUN_004793e7();
      }
    }
    else {
      *(undefined4 *)((int)this + 0xbc) = 0;
      SendMessageA(*(HWND *)((int)this + 0x1c),0x85,0,0);
    }
  }
  return;
}

