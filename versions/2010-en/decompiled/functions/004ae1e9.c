
void __thiscall FUN_004ae1e9(int param_1,int param_2,int param_3,RECT *param_4,RECT *param_5)

{
  BOOL BVar1;
  HWND hWnd;
  undefined1 local_14 [16];
  
  BVar1 = IsWindowVisible(*(HWND *)(param_1 + 0x1c));
  if (((BVar1 == 0) && (param_4 == (RECT *)0x0)) && (param_5 == (RECT *)0x0)) {
    for (hWnd = GetWindow(*(HWND *)(param_1 + 0x1c),5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2))
    {
      GetWindowRect(hWnd,(LPRECT)local_14);
      ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)local_14);
      ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)(local_14 + 8));
      SetWindowPos(hWnd,(HWND)0x0,local_14._0_4_ + param_2,local_14._4_4_ + param_3,0,0,0x15);
    }
  }
  else {
    ScrollWindow(*(HWND *)(param_1 + 0x1c),param_2,param_3,param_4,param_5);
  }
  if ((*(int **)(param_1 + 0x34) != (int *)0x0) && (param_4 == (RECT *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x34) + 0x60))(param_2,param_3);
  }
  return;
}

