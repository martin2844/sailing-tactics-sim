
void FUN_00469d00(int *param_1,HWND param_2,RECT *param_3)

{
  int Y;
  int X;
  HWND hWnd;
  BOOL BVar1;
  HDWP pvVar2;
  undefined1 local_14 [16];
  
  hWnd = GetParent(param_2);
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    GetWindowRect(param_2,(LPRECT)local_14);
    ScreenToClient(hWnd,(LPPOINT)local_14);
    ScreenToClient(hWnd,(LPPOINT)(local_14 + 8));
    BVar1 = EqualRect((RECT *)local_14,param_3);
    if (BVar1 == 0) {
      Y = param_3->top;
      X = param_3->left;
      if (param_1 == (int *)0x0) {
        SetWindowPos(param_2,(HWND)0x0,X,Y,param_3->right - X,param_3->bottom - Y,0x14);
      }
      else {
        pvVar2 = DeferWindowPos((HDWP)*param_1,param_2,(HWND)0x0,X,Y,param_3->right - X,
                                param_3->bottom - Y,0x14);
        *param_1 = (int)pvVar2;
      }
    }
  }
  return;
}

