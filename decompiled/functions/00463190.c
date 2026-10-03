
undefined4 FUN_00463190(HWND param_1)

{
  code *pcVar1;
  HANDLE pvVar2;
  HWND hWnd;
  int iVar3;
  
  if (DAT_004aff40 != 0) {
    pcVar1 = (code *)GetWindowLongA(param_1,-4);
    iVar3 = 0;
    do {
      if ((code *)(&DAT_004b09a0)[iVar3 * 6] == pcVar1) {
        pvVar2 = FUN_00462860(param_1,iVar3);
        RemovePropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
        SetWindowLongA(param_1,-4,(LONG)pvVar2);
        pcVar1 = (code *)0x0;
        iVar3 = 0x10;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    if (iVar3 == 6) {
      if (pcVar1 == FUN_00463d40) {
        pvVar2 = FUN_00462860(param_1,6);
        RemovePropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
        SetWindowLongA(param_1,-4,(LONG)pvVar2);
      }
      else {
        pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff4e);
        if (((pvVar2 != (HANDLE)0x0) ||
            (pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff52), pvVar2 != (HANDLE)0x0)) ||
           (pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff50), pvVar2 != (HANDLE)0x0)) {
          SetPropA(param_1,(LPCSTR)(uint)DAT_004aff54,(HANDLE)0x1);
        }
      }
    }
    for (hWnd = GetWindow(param_1,5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
      FUN_00463190(hWnd);
    }
    return 1;
  }
  return 0;
}

