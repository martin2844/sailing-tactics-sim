
LRESULT __cdecl FUN_00465690(HWND param_1,uint param_2,WPARAM param_3,LONG *param_4,int param_5)

{
  LRESULT LVar1;
  HANDLE pvVar2;
  WNDPROC pWVar3;
  HWND pHVar4;
  LONG *lParam;
  undefined1 local_20 [12];
  int local_14;
  tagRECT local_10;
  
  if (param_2 == 0x82) {
    LVar1 = FUN_00462a90(param_1,0x82,param_3,(LPARAM)param_4,param_5);
    return LVar1;
  }
  pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  if (pvVar2 == (HANDLE)0x0) {
    if (param_2 < 0x19) {
      if (param_2 == 0x18) {
        if ((DAT_004aff60 < 0x30a) && (param_3 == 0)) {
          FUN_00464530(param_1,0);
        }
      }
      else if (param_2 == 0xf) {
        pHVar4 = param_1;
        pWVar3 = FUN_00462860(param_1,param_5);
        LVar1 = CallWindowProcA(pWVar3,pHVar4,param_2,param_3,(LPARAM)param_4);
        FUN_004651d0(param_1,0,param_5);
        return LVar1;
      }
    }
    else if (param_2 < 0x84) {
      if (param_2 == 0x83) {
        if (DAT_004aff60 < 0x30a) {
          GetWindowRect(param_1,&local_10);
          pHVar4 = param_1;
          lParam = param_4;
          pWVar3 = FUN_00462860(param_1,param_5);
          LVar1 = CallWindowProcA(pWVar3,pHVar4,param_2,param_3,(LPARAM)lParam);
          local_20._0_4_ = *param_4;
          local_20._4_4_ = param_4[1];
          local_20._8_4_ = param_4[2];
          local_14 = param_4[3];
          InflateRect((LPRECT)local_20,2,1);
          if (local_14 < local_10.bottom) {
            local_20._4_4_ = local_14 + 1;
            local_14 = local_10.bottom + 1;
            pHVar4 = GetParent(param_1);
            ScreenToClient(pHVar4,(LPPOINT)local_20);
            ScreenToClient(pHVar4,(LPPOINT)(local_20 + 8));
            InvalidateRect(pHVar4,(RECT *)local_20,1);
          }
          return LVar1;
        }
      }
      else if ((param_2 == 0x46) && (0x309 < DAT_004aff60)) {
        FUN_00464530(param_1,(int)param_4);
      }
    }
    else if ((0x1942 < param_2) && (param_2 < 0x1945)) {
      *param_4 = 1;
      return 0x3e9;
    }
    pWVar3 = FUN_00462860(param_1,param_5);
    LVar1 = CallWindowProcA(pWVar3,param_1,param_2,param_3,(LPARAM)param_4);
    return LVar1;
  }
  pWVar3 = FUN_00462860(param_1,param_5);
  LVar1 = CallWindowProcA(pWVar3,param_1,param_2,param_3,(LPARAM)param_4);
  return LVar1;
}

