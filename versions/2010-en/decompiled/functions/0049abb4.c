
HWND FUN_0049abb4(undefined4 param_1,POINT *param_2)

{
  HWND hWnd;
  HWND hWnd_00;
  int iVar1;
  BOOL BVar2;
  tagPOINT local_c;
  
  local_c.x = param_2->x;
  local_c.y = param_2->y;
  hWnd = WindowFromPoint(*param_2);
  hWnd_00 = hWnd;
  if ((hWnd != (HWND)0x0) &&
     ((hWnd_00 = GetParent(hWnd), hWnd_00 == (HWND)0x0 ||
      (iVar1 = FUN_004b54bb(hWnd_00,2), iVar1 == 0)))) {
    ScreenToClient(hWnd,&local_c);
    hWnd_00 = (HWND)FUN_004b5530(hWnd,local_c.x,local_c.y);
    if ((hWnd_00 == (HWND)0x0) || (BVar2 = IsWindowEnabled(hWnd_00), BVar2 != 0)) {
      hWnd_00 = hWnd;
    }
  }
  return hWnd_00;
}

