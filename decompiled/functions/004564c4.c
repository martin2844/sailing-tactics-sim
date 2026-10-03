
HWND FUN_004564c4(undefined4 param_1,POINT *param_2)

{
  bool bVar1;
  HWND hWnd;
  HWND hWnd_00;
  undefined3 extraout_var;
  BOOL BVar2;
  tagPOINT local_c;
  
  local_c.x = param_2->x;
  local_c.y = param_2->y;
  hWnd = WindowFromPoint(*param_2);
  hWnd_00 = hWnd;
  if ((hWnd != (HWND)0x0) &&
     ((hWnd_00 = GetParent(hWnd), hWnd_00 == (HWND)0x0 ||
      (bVar1 = FUN_00470ddb(hWnd_00,2), CONCAT31(extraout_var,bVar1) == 0)))) {
    ScreenToClient(hWnd,&local_c);
    hWnd_00 = FUN_00470e50(hWnd,local_c.x,local_c.y);
    if ((hWnd_00 == (HWND)0x0) || (BVar2 = IsWindowEnabled(hWnd_00), BVar2 != 0)) {
      hWnd_00 = hWnd;
    }
  }
  return hWnd_00;
}

