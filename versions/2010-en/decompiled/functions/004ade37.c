
void __fastcall FUN_004ade37(int param_1)

{
  int iVar1;
  uint uVar2;
  HWND hWnd;
  HWND hWnd_00;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    hWnd_00 = *(HWND *)(param_1 + 0x1c);
    uVar2 = GetWindowLongA(hWnd_00,-0x10);
    while ((uVar2 & 0x40000000) != 0) {
      hWnd = GetParent(hWnd_00);
      if (hWnd == (HWND)0x0) break;
      uVar2 = GetWindowLongA(hWnd,-0x10);
      hWnd_00 = hWnd;
    }
    FUN_004ac7ac(hWnd_00);
  }
  return;
}

