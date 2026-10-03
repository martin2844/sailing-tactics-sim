
undefined4 __thiscall FUN_004ae4a5(int param_1,uint param_2,int param_3)

{
  HWND hWnd;
  int iVar1;
  HWND hWnd_00;
  HWND pHVar2;
  BOOL BVar3;
  uint uVar4;
  
  iVar1 = FUN_004ade0b();
  uVar4 = param_2 & 0xfff0;
  if ((uVar4 == 0xf040) || (uVar4 == 0xf050)) {
    if ((short)param_3 != 0x75) {
      return 0;
    }
    if (iVar1 == 0) {
      return 0;
    }
    FUN_004af595();
  }
  else {
    if ((uVar4 != 0xf060) && (uVar4 != 0xf100)) {
      return 0;
    }
    if (((uVar4 == 0xf060) || (param_3 != 0)) && (iVar1 != 0)) {
      hWnd = *(HWND *)(param_1 + 0x1c);
      hWnd_00 = GetFocus();
      pHVar2 = SetActiveWindow(*(HWND *)(iVar1 + 0x1c));
      FUN_004ac7ac(pHVar2);
      SendMessageA(*(HWND *)(iVar1 + 0x1c),0x112,param_2,param_3);
      BVar3 = IsWindow(hWnd);
      if (BVar3 != 0) {
        SetActiveWindow(hWnd);
      }
      BVar3 = IsWindow(hWnd_00);
      if (BVar3 != 0) {
        SetFocus(hWnd_00);
      }
    }
  }
  return 1;
}

