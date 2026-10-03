
void __thiscall FUN_004aec6c(int param_1,int param_2)

{
  HWND hWnd;
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  tagRECT local_3c;
  tagRECT local_2c;
  tagRECT local_1c;
  int local_c;
  uint local_8;
  
  local_c = param_1;
  local_8 = FUN_004af3eb();
  if (param_2 == 0) {
    if ((local_8 & 0x40000000) == 0) {
      hWnd = GetWindow(*(HWND *)(param_1 + 0x1c),4);
    }
    else {
      hWnd = GetParent(*(HWND *)(param_1 + 0x1c));
    }
    if ((hWnd != (HWND)0x0) && (pHVar1 = (HWND)SendMessageA(hWnd,0x36b,0,0), pHVar1 != (HWND)0x0)) {
      hWnd = pHVar1;
    }
  }
  else {
    hWnd = *(HWND *)(param_2 + 0x1c);
  }
  GetWindowRect(*(HWND *)(param_1 + 0x1c),&local_3c);
  if ((local_8 & 0x40000000) == 0) {
    if ((hWnd != (HWND)0x0) &&
       ((uVar2 = GetWindowLongA(hWnd,-0x10), (uVar2 & 0x10000000) == 0 ||
        ((uVar2 & 0x20000000) != 0)))) {
      hWnd = (HWND)0x0;
    }
    SystemParametersInfoA(0x30,0,&local_1c,0);
    if (hWnd == (HWND)0x0) {
      local_2c.left = local_1c.left;
      local_2c.top = local_1c.top;
      local_2c.right = local_1c.right;
      local_2c.bottom = local_1c.bottom;
    }
    else {
      GetWindowRect(hWnd,&local_2c);
    }
  }
  else {
    pHVar1 = GetParent(*(HWND *)(param_1 + 0x1c));
    GetClientRect(pHVar1,&local_1c);
    GetClientRect(hWnd,&local_2c);
    MapWindowPoints(hWnd,pHVar1,(LPPOINT)&local_2c,2);
  }
  iVar3 = (local_2c.left + local_2c.right) / 2 - (local_3c.right - local_3c.left) / 2;
  iVar4 = (local_2c.top + local_2c.bottom) / 2 - (local_3c.bottom - local_3c.top) / 2;
  if ((local_1c.left <= iVar3) &&
     (local_1c.left = iVar3, local_1c.right < iVar3 + (local_3c.right - local_3c.left))) {
    local_1c.left = (local_3c.left - local_3c.right) + local_1c.right;
  }
  if ((local_1c.top <= iVar4) &&
     (local_1c.top = iVar4, local_1c.bottom < (local_3c.bottom - local_3c.top) + iVar4)) {
    local_1c.top = (local_3c.top - local_3c.bottom) + local_1c.bottom;
  }
  FUN_004af4dd(0,local_1c.left,local_1c.top,0xffffffff,0xffffffff,0x15);
  return;
}

