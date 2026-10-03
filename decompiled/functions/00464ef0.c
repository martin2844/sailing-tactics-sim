
LRESULT FUN_00464ef0(HWND param_1,uint param_2,HDC param_3,undefined4 *param_4)

{
  LRESULT LVar1;
  HANDLE pvVar2;
  WNDPROC pWVar3;
  LONG LVar4;
  uint uVar5;
  uint uVar6;
  HDC pHVar7;
  uint uVar8;
  HWND hWnd;
  tagPAINTSTRUCT local_40;
  
  if (param_2 == 0x82) {
    LVar1 = FUN_00462a90(param_1,0x82,(WPARAM)param_3,(LPARAM)param_4,0);
    return LVar1;
  }
  pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  if (pvVar2 != (HANDLE)0x0) {
    pWVar3 = FUN_00462860(param_1,0);
    LVar1 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
    return LVar1;
  }
  if (param_2 < 0xf2) {
    if (param_2 == 0xf1) goto LAB_00465096;
    switch(param_2) {
    case 7:
      uVar8 = 0x16;
      break;
    case 8:
      LVar4 = GetWindowLongA(param_1,-0x10);
      if (((byte)LVar4 & 0x1f) == 9) {
        SendMessageA(param_1,0xf3,0,0);
      }
      uVar8 = 0;
      break;
    default:
      goto switchD_00464f81_caseD_9;
    case 10:
      uVar8 = 6;
      break;
    case 0xc:
      uVar8 = GetWindowLongA(param_1,-0x10);
      if (((uVar8 & 0x10000000) == 0) || (((byte)uVar8 & 0x1f) != 7)) {
        uVar8 = 0x16;
      }
      else {
        uVar8 = 0x22;
      }
      break;
    case 0xf:
      uVar8 = SendMessageA(param_1,0xf2,0,0);
      pHVar7 = param_3;
      if (param_3 == (HDC)0x0) {
        pHVar7 = BeginPaint(param_1,&local_40);
      }
      uVar5 = GetWindowLongA(param_1,-0x10);
      if ((uVar5 & 0x10000000) != 0) {
        FUN_004649a0(param_1,pHVar7,uVar8 & 8 | 6);
      }
      if (param_3 == (HDC)0x0) {
        EndPaint(param_1,&local_40);
      }
      return 0;
    }
  }
  else {
    if (param_2 != 0xf3) {
      if ((0x1942 < param_2) && (param_2 < 0x1945)) {
        *param_4 = 1;
        return 1000;
      }
      goto switchD_00464f81_caseD_9;
    }
LAB_00465096:
    uVar8 = 4;
  }
  uVar5 = SendMessageA(param_1,0xf2,0,0);
  uVar6 = GetWindowLongA(param_1,-0x10);
  if ((uVar6 & 0x10000000) != 0) {
    if (param_2 != 7) {
      SetWindowLongA(param_1,-0x10,uVar6 & 0xefffffff);
    }
    hWnd = param_1;
    uVar6 = param_2;
    pWVar3 = FUN_00462860(param_1,0);
    LVar1 = CallWindowProcA(pWVar3,hWnd,uVar6,(WPARAM)param_3,(LPARAM)param_4);
    if (param_2 != 7) {
      uVar6 = GetWindowLongA(param_1,-0x10);
      SetWindowLongA(param_1,-0x10,uVar6 | 0x10000000);
    }
    uVar6 = SendMessageA(param_1,0xf2,0,0);
    if ((((param_2 != 0xf3) && (param_2 != 0xf1)) || (uVar6 != uVar5)) &&
       (pHVar7 = GetDC(param_1), pHVar7 != (HDC)0x0)) {
      if (((uVar6 ^ uVar5) & 3) != 0) {
        uVar8 = uVar8 | 4;
      }
      ExcludeUpdateRgn(pHVar7,param_1);
      FUN_004649a0(param_1,pHVar7,(uVar6 ^ uVar5) & 8 | uVar8);
      ReleaseDC(param_1,pHVar7);
    }
    return LVar1;
  }
switchD_00464f81_caseD_9:
  pWVar3 = FUN_00462860(param_1,0);
  LVar1 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return LVar1;
}

