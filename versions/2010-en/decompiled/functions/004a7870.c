
undefined4 FUN_004a7870(HWND param_1)

{
  code *pcVar1;
  LONG LVar2;
  HANDLE pvVar3;
  HWND hWnd;
  int iVar4;
  
  if (DAT_00539a80 != 0) {
    pcVar1 = (code *)GetWindowLongA(param_1,-4);
    iVar4 = 0;
    do {
      if ((code *)(&DAT_0053a4e0)[iVar4 * 6] == pcVar1) {
        LVar2 = FUN_004a6f40(param_1,iVar4);
        RemovePropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
        SetWindowLongA(param_1,-4,LVar2);
        pcVar1 = (code *)0x0;
        iVar4 = 0x10;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    if (iVar4 == 6) {
      if (pcVar1 == FUN_004a8420) {
        LVar2 = FUN_004a6f40(param_1,6);
        RemovePropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
        SetWindowLongA(param_1,-4,LVar2);
      }
      else {
        pvVar3 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a8e);
        if (((pvVar3 != (HANDLE)0x0) ||
            (pvVar3 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a92), pvVar3 != (HANDLE)0x0)) ||
           (pvVar3 = GetPropA(param_1,(LPCSTR)(uint)DAT_00539a90), pvVar3 != (HANDLE)0x0)) {
          SetPropA(param_1,(LPCSTR)(uint)DAT_00539a94,(HANDLE)0x1);
        }
      }
    }
    for (hWnd = GetWindow(param_1,5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
      FUN_004a7870(hWnd);
    }
    return 1;
  }
  return 0;
}

