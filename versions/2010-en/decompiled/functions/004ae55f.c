
undefined4 FUN_004ae55f(HWND param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  HWND hWnd;
  
  hWnd = (HWND)*param_2;
  while( true ) {
    if (hWnd == (HWND)0x0) {
      return 0;
    }
    piVar1 = (int *)FUN_004ac7d4(hWnd);
    if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x98))(param_2), iVar2 != 0))
    break;
    if (hWnd == param_1) {
      return 0;
    }
    hWnd = GetParent(hWnd);
  }
  return 1;
}

