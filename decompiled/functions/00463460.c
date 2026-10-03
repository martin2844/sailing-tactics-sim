
undefined4 FUN_00463460(HWND param_1,ushort param_2)

{
  HWND hWnd;
  
  if (DAT_004aff40 == 0) {
    return 0;
  }
  for (hWnd = GetWindow(param_1,5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
    FUN_00464440(hWnd,param_2,0,0);
  }
  FUN_004628b0(param_1,0x463d40);
  return 1;
}

