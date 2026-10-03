
void FUN_00469853(int param_1,undefined4 *param_2)

{
  HWND hWnd;
  int iVar1;
  uint uVar2;
  HWND pHVar3;
  HWND hWnd_00;
  BOOL BVar4;
  HWND hWnd_01;
  bool bVar5;
  
  if (param_1 == 0) {
    hWnd_01 = (HWND)0x0;
  }
  else {
    hWnd_01 = *(HWND *)(param_1 + 0x1c);
  }
  bVar5 = false;
  if (hWnd_01 == (HWND)0x0) {
    iVar1 = FUN_00455bf0();
    if (iVar1 != 0) {
      hWnd_01 = *(HWND *)(iVar1 + 0x1c);
    }
    bVar5 = hWnd_01 == (HWND)0x0;
  }
  pHVar3 = hWnd_01;
  hWnd_00 = hWnd_01;
  if (!bVar5) {
    do {
      uVar2 = GetWindowLongA(hWnd_01,-0x10);
      pHVar3 = hWnd_01;
      hWnd_00 = hWnd_01;
      if ((uVar2 & 0x40000000) == 0) break;
      hWnd_01 = GetParent(hWnd_01);
      pHVar3 = hWnd_01;
      hWnd_00 = hWnd_01;
    } while (hWnd_01 != (HWND)0x0);
  }
  while (hWnd = pHVar3, hWnd != (HWND)0x0) {
    pHVar3 = GetParent(hWnd);
    hWnd_01 = hWnd;
  }
  if ((param_1 == 0) && (hWnd_00 != (HWND)0x0)) {
    hWnd_00 = GetLastActivePopup(hWnd_00);
  }
  if (param_2 != (undefined4 *)0x0) {
    if (((hWnd_01 == (HWND)0x0) || (BVar4 = IsWindowEnabled(hWnd_01), BVar4 == 0)) ||
       (hWnd_01 == hWnd_00)) {
      *param_2 = 0;
    }
    else {
      *param_2 = hWnd_01;
      EnableWindow(hWnd_01,0);
    }
  }
  FUN_004680cc();
  return;
}

