
undefined4 __thiscall FUN_00469dc5(void *this,uint param_1,int param_2)

{
  HWND hWnd;
  int iVar1;
  HWND hWnd_00;
  BOOL BVar2;
  uint uVar3;
  
  iVar1 = FUN_0046972b((int)this);
  uVar3 = param_1 & 0xfff0;
  if ((uVar3 == 0xf040) || (uVar3 == 0xf050)) {
    if ((short)param_2 != 0x75) {
      return 0;
    }
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0046aeb5(iVar1);
  }
  else {
    if ((uVar3 != 0xf060) && (uVar3 != 0xf100)) {
      return 0;
    }
    if (((uVar3 == 0xf060) || (param_2 != 0)) && (iVar1 != 0)) {
      hWnd = *(HWND *)((int)this + 0x1c);
      hWnd_00 = GetFocus();
      SetActiveWindow(*(HWND *)(iVar1 + 0x1c));
      FUN_004680cc();
      SendMessageA(*(HWND *)(iVar1 + 0x1c),0x112,param_1,param_2);
      BVar2 = IsWindow(hWnd);
      if (BVar2 != 0) {
        SetActiveWindow(hWnd);
      }
      BVar2 = IsWindow(hWnd_00);
      if (BVar2 != 0) {
        SetFocus(hWnd_00);
      }
    }
  }
  return 1;
}

