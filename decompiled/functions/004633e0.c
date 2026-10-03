
undefined4 FUN_004633e0(HWND param_1,ushort param_2)

{
  HWND hWnd;
  HWND hWnd_00;
  
  if (DAT_004aff40 != 0) {
    for (hWnd = GetWindow(param_1,5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
      FUN_00463330(hWnd,param_2,0);
      for (hWnd_00 = GetWindow(hWnd,5); hWnd_00 != (HWND)0x0; hWnd_00 = GetWindow(hWnd_00,2)) {
        FUN_00463330(hWnd_00,param_2,hWnd);
      }
    }
    return 1;
  }
  return 0;
}

