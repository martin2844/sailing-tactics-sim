
uint __cdecl FUN_00465510(HWND param_1,uint param_2,WPARAM param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  HANDLE pvVar2;
  WNDPROC pWVar3;
  uint uVar4;
  HWND hWnd;
  WPARAM wParam;
  undefined4 *lParam;
  
  if (param_2 == 0x82) {
    uVar1 = FUN_00462a90(param_1,0x82,param_3,(LPARAM)param_4,param_5);
    return uVar1;
  }
  pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  if (pvVar2 == (HANDLE)0x0) {
    hWnd = param_1;
    uVar1 = param_2;
    wParam = param_3;
    lParam = param_4;
    pWVar3 = FUN_00462860(param_1,param_5);
    uVar4 = CallWindowProcA(pWVar3,hWnd,uVar1,wParam,(LPARAM)lParam);
    uVar1 = uVar4;
    if ((param_5 == 3) && (uVar1 = GetWindowLongA(param_1,-0x10), ((byte)uVar1 & 3) == 2)) {
      return uVar4;
    }
    if (param_2 < 0x19) {
      if (param_2 == 0x18) {
        if ((DAT_004aff60 < 0x30a) && (param_3 == 0)) {
          FUN_00464530(param_1,0);
        }
      }
      else if ((param_2 == 0xf) && (((param_5 != 3 || ((uVar1 & 3) == 2)) || ((uVar1 & 3) == 3)))) {
        FUN_004651d0(param_1,1,param_5);
      }
    }
    else if (param_2 == 0x46) {
      if (0x309 < DAT_004aff60) {
        FUN_00464530(param_1,(int)param_4);
      }
    }
    else if ((0x1942 < param_2) && (param_2 < 0x1945)) {
      *param_4 = 1;
      return 0x3ea;
    }
    return uVar4;
  }
  pWVar3 = FUN_00462860(param_1,param_5);
  uVar1 = CallWindowProcA(pWVar3,param_1,param_2,param_3,(LPARAM)param_4);
  return uVar1;
}

