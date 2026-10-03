
LRESULT FUN_00463d40(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  LRESULT LVar1;
  HANDLE pvVar2;
  WNDPROC pWVar3;
  BOOL BVar4;
  uint uVar5;
  int iVar6;
  HWND pHVar7;
  UINT UVar8;
  HDC pHVar9;
  HWND pHVar10;
  int local_18;
  WNDPROC local_14;
  CHAR local_10 [16];
  
  if (param_2 == 0x82) {
    LVar1 = FUN_00462a90(param_1,0x82,(WPARAM)param_3,(LPARAM)param_4,6);
    return LVar1;
  }
  pvVar2 = GetPropA(param_1,(LPCSTR)(uint)DAT_004aff54);
  if (pvVar2 != (HANDLE)0x0) {
    pWVar3 = FUN_00462860(param_1,6);
    LVar1 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
    return LVar1;
  }
  if (param_2 < 0x87) {
    if ((0x84 < param_2) || (param_2 == 0xc)) {
      if ((DAT_004aff60 < 0x35f) && (BVar4 = IsIconic(param_1), BVar4 == 0)) {
        LVar1 = FUN_00463590(param_1,param_2,(WPARAM)param_3,(LPARAM)param_4,0);
        return LVar1;
      }
      pWVar3 = FUN_00462860(param_1,6);
      LVar1 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
      return LVar1;
    }
    goto LAB_00463dd4;
  }
  if (0x138 < param_2) {
    if ((0x1942 < param_2) && (param_2 < 0x1945)) {
      param_4->unused = 1;
      return 0x3ee;
    }
    goto LAB_00463dd4;
  }
  if (param_2 < 0x132) {
    if (param_2 != 0x110) goto LAB_00463dd4;
    local_14 = FUN_00462860(param_1,6);
    if (0x35e < DAT_004aff60) {
      uVar5 = GetWindowLongA(param_1,-0x10);
      local_18 = 0;
      if ((uVar5 & 4) != 0) goto LAB_00463eba;
    }
    local_18 = 1;
LAB_00463eba:
    SendMessageA(param_1,0x11f0,0,(LPARAM)&local_18);
    if (local_18 == 0) {
      FUN_00463190(param_1);
      LVar1 = CallWindowProcA(local_14,param_1,0x110,(WPARAM)param_3,(LPARAM)param_4);
      return LVar1;
    }
    LVar1 = CallWindowProcA(local_14,param_1,0x110,(WPARAM)param_3,(LPARAM)param_4);
    if ((DAT_004aff60 < 0x35f) || (uVar5 = GetWindowLongA(param_1,-0x10), (uVar5 & 4) == 0)) {
      FUN_004633e0(param_1,0xffff);
    }
    return LVar1;
  }
  GetClassNameA(param_1,local_10,0x10);
  iVar6 = lstrcmpA(s__32770_004a3358,local_10);
  if (iVar6 == 0) {
    pWVar3 = (WNDPROC)GetWindowLongA(param_1,4);
    if (pWVar3 != (WNDPROC)0x0) {
      if ((pWVar3 < (WNDPROC)0xffff0001) || (0x30a < DAT_004aff60)) {
        iVar6 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
        if ((iVar6 != 0) && (iVar6 != 1)) goto LAB_00464044;
        UVar8 = param_2 + 0xcbf;
        pHVar7 = param_1;
        pHVar9 = param_3;
        pHVar10 = param_4;
        pWVar3 = FUN_00462860(param_1,6);
        iVar6 = CallWindowProcA(pWVar3,pHVar7,UVar8,(WPARAM)pHVar9,(LPARAM)pHVar10);
      }
      else {
        UVar8 = param_2 + 0xcbf;
        pHVar7 = param_1;
        pHVar9 = param_3;
        pHVar10 = param_4;
        pWVar3 = FUN_00462860(param_1,6);
        iVar6 = CallWindowProcA(pWVar3,pHVar7,UVar8,(WPARAM)pHVar9,(LPARAM)pHVar10);
      }
      if ((iVar6 != 0) && (iVar6 != 1)) goto LAB_00464044;
    }
LAB_0046403d:
    iVar6 = FUN_004634d0(param_2,param_3,param_4);
  }
  else {
    UVar8 = param_2 + 0xcbf;
    pHVar7 = param_1;
    pHVar9 = param_3;
    pHVar10 = param_4;
    pWVar3 = FUN_00462860(param_1,6);
    iVar6 = CallWindowProcA(pWVar3,pHVar7,UVar8,(WPARAM)pHVar9,(LPARAM)pHVar10);
    if ((iVar6 == 0) || (iVar6 == 1)) goto LAB_0046403d;
  }
LAB_00464044:
  if (iVar6 != 0) {
    return iVar6;
  }
LAB_00463dd4:
  pWVar3 = FUN_00462860(param_1,6);
  LVar1 = CallWindowProcA(pWVar3,param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return LVar1;
}

