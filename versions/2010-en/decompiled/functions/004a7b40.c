
undefined4 FUN_004a7b40(HWND param_1,undefined2 param_2)

{
  HWND hWnd;
  
  if (DAT_00539a80 == 0) {
    return 0;
  }
  for (hWnd = GetWindow(param_1,5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
    FUN_004a8b20(hWnd,param_2,0,0);
  }
  FUN_004a6f90(param_1,FUN_004a8420);
  return 1;
}

