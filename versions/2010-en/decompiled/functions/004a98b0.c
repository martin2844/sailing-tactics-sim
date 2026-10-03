
void FUN_004a98b0(HWND param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  LRESULT LVar3;
  HWND pHVar4;
  HDC hDC;
  LONG LVar5;
  int iVar6;
  HWND hWndTo;
  uint uVar7;
  uint uVar8;
  int local_3c;
  uint local_38;
  uint local_34;
  undefined1 local_30 [12];
  int local_24;
  tagRECT local_20;
  int local_10 [4];
  
  uVar2 = GetWindowLongA(param_1,-0x10);
  if (((uVar2 & 0x10000000) != 0) &&
     (((param_3 != 3 || (((byte)uVar2 & 3) != 3)) ||
      (LVar3 = SendMessageA(param_1,0x157,0,0), LVar3 == 0)))) {
    if (param_2 != 0) {
      HideCaret(param_1);
    }
    GetWindowRect(param_1,(LPRECT)local_30);
    pHVar4 = GetParent(param_1);
    ScreenToClient(pHVar4,(LPPOINT)local_30);
    uVar8 = 0xf;
    ScreenToClient(pHVar4,(LPPOINT)(local_30 + 8));
    hDC = GetDC(pHVar4);
    local_38 = uVar2 & 0x100000;
    if (local_38 != 0) {
      uVar8 = 7;
    }
    local_34 = uVar2 & 0x200000;
    if (local_34 != 0) {
      uVar8 = uVar8 & 0xfffffffb;
    }
    LVar5 = GetWindowLongA(param_1,-0xc);
    hWndTo = pHVar4;
    if (param_2 - LVar5 == -1000) {
      local_3c = 0x29a;
      local_20.left = SendMessageA(pHVar4,0x1944,0,(LPARAM)&local_3c);
      if (local_3c == 0x29a) {
        local_20.left = SendMessageA(pHVar4,0x1943,0,(LPARAM)&local_3c);
      }
      GetClassNameA(pHVar4,(LPSTR)local_10,0x10);
      iVar6 = lstrcmpA((LPCSTR)local_10,"ComboBox");
      if ((iVar6 == 0) || ((local_3c == 1 && (local_20.left == 0x3eb)))) {
        hWndTo = GetParent(pHVar4);
        MapWindowPoints(pHVar4,hWndTo,(LPPOINT)local_30,2);
        ReleaseDC(pHVar4,hDC);
        hDC = GetDC(hWndTo);
        if (param_2 == 0) {
          uVar8 = uVar8 & 0xfffffffd;
          local_30._4_4_ = local_30._4_4_ + 1;
        }
        else {
          uVar7 = GetWindowLongA(pHVar4,-0x10);
          if (((uVar7 & 3) == 2) || ((uVar7 & 3) == 3)) {
            LVar3 = SendMessageA(pHVar4,0x157,0,0);
            if (LVar3 != 0) {
              ReleaseDC(hWndTo,hDC);
              ShowCaret(param_1);
              return;
            }
          }
          else {
            uVar8 = uVar8 & 0xfffffff7;
            pHVar4 = GetWindow(pHVar4,5);
            GetWindowRect(pHVar4,&local_20);
            local_30._8_4_ = local_30._8_4_ + (local_20.left - local_20.right);
            FUN_004a7390(hDC,local_30,0x1008);
            local_30._8_4_ = local_30._8_4_ + (local_20.right - local_20.left);
          }
        }
      }
    }
    FUN_004a7390(hDC,local_30,uVar8);
    uVar1 = local_30._8_4_;
    if ((param_3 == 3) && (((byte)uVar2 & 3) == 3)) {
      local_30._0_4_ = GetSystemMetrics(2);
      local_30._0_4_ = uVar1 - local_30._0_4_;
      FUN_004a7250(hDC,local_30,7,7,0xc);
      FUN_004a8cd0(param_1);
    }
    else {
      if (local_34 != 0) {
        local_30._8_4_ = local_30._8_4_ + 1;
        FUN_004a7250(hDC,local_30,0,0,4);
        iVar6 = local_30._8_4_ + -1;
        local_10[0] = local_30._0_4_;
        local_30._8_4_ = iVar6;
        local_30._0_4_ = GetSystemMetrics(2);
        local_30._0_4_ = iVar6 - local_30._0_4_;
        FUN_004a7250(hDC,local_30,7,7,8);
        local_30._0_4_ = local_10[0];
      }
      if (local_38 != 0) {
        local_24 = local_24 + 1;
        FUN_004a7250(hDC,local_30,0,0,8);
        iVar6 = local_24 + -1;
        local_24 = iVar6;
        local_30._4_4_ = GetSystemMetrics(0x15);
        local_30._4_4_ = iVar6 - local_30._4_4_;
        FUN_004a7250(hDC,local_30,7,7,4);
      }
    }
    ReleaseDC(hWndTo,hDC);
    if (param_2 != 0) {
      ShowCaret(param_1);
    }
  }
  return;
}

