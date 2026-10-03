
void __thiscall
FUN_00469bc6(void *this,uint param_1,uint param_2,uint param_3,int param_4,LPRECT param_5,
            int *param_6,int param_7)

{
  HWND pHVar1;
  HWND hWnd;
  uint uVar2;
  int iVar3;
  CWnd *pCVar4;
  HDWP local_28;
  tagRECT local_24;
  LONG local_14;
  LONG local_10;
  int local_c;
  HWND local_8;
  
  local_8 = (HWND)0x0;
  local_c = param_7;
  local_10 = 0;
  local_14 = 0;
  if (param_6 == (int *)0x0) {
    GetClientRect(*(HWND *)((int)this + 0x1c),&local_24);
  }
  else {
    local_24.left = *param_6;
    local_24.top = param_6[1];
    local_24.right = param_6[2];
    local_24.bottom = param_6[3];
  }
  if (param_4 == 1) {
    local_28 = (HDWP)0x0;
  }
  else {
    local_28 = BeginDeferWindowPos(8);
  }
  for (hWnd = GetTopWindow(*(HWND *)((int)this + 0x1c)); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)
      ) {
    uVar2 = GetDlgCtrlID(hWnd);
    uVar2 = uVar2 & 0xffff;
    iVar3 = FUN_004680f4((uint)hWnd);
    pHVar1 = hWnd;
    if ((((uVar2 != param_3) && (pHVar1 = local_8, param_1 <= uVar2)) && (uVar2 <= param_2)) &&
       (iVar3 != 0)) {
      SendMessageA(hWnd,0x361,0,(LPARAM)&local_28);
      pHVar1 = local_8;
    }
    local_8 = pHVar1;
  }
  if (param_4 == 1) {
    if (param_7 == 0) {
      param_5->right = local_14;
      param_5->top = 0;
      param_5->left = 0;
      param_5->bottom = local_10;
    }
    else {
      CopyRect(param_5,&local_24);
    }
  }
  else {
    if ((param_3 != 0) && (local_8 != (HWND)0x0)) {
      pCVar4 = FUN_004680cc();
      if (param_4 == 2) {
        local_24.left = local_24.left + param_5->left;
        local_24.top = local_24.top + param_5->top;
        local_24.right = local_24.right - param_5->right;
        local_24.bottom = local_24.bottom - param_5->bottom;
      }
      (**(code **)(*(int *)pCVar4 + 0x68))(&local_24,0);
      FUN_00469d00((int *)&local_28,local_8,&local_24);
    }
    if (local_28 != (HDWP)0x0) {
      EndDeferWindowPos(local_28);
    }
  }
  return;
}

