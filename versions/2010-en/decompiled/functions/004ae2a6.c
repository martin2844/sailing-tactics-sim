
void __thiscall
FUN_004ae2a6(int param_1,uint param_2,uint param_3,uint param_4,int param_5,LPRECT param_6,
            int *param_7,int param_8)

{
  HWND pHVar1;
  HWND hWnd;
  uint uVar2;
  int iVar3;
  int *piVar4;
  HDWP local_28;
  tagRECT local_24;
  LONG local_14;
  LONG local_10;
  int local_c;
  HWND local_8;
  
  local_8 = (HWND)0x0;
  local_c = param_8;
  local_10 = 0;
  local_14 = 0;
  if (param_7 == (int *)0x0) {
    GetClientRect(*(HWND *)(param_1 + 0x1c),&local_24);
  }
  else {
    local_24.left = *param_7;
    local_24.top = param_7[1];
    local_24.right = param_7[2];
    local_24.bottom = param_7[3];
  }
  if (param_5 == 1) {
    local_28 = (HDWP)0x0;
  }
  else {
    local_28 = BeginDeferWindowPos(8);
  }
  for (hWnd = GetTopWindow(*(HWND *)(param_1 + 0x1c)); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2))
  {
    uVar2 = GetDlgCtrlID(hWnd);
    uVar2 = uVar2 & 0xffff;
    iVar3 = FUN_004ac7d4(hWnd);
    pHVar1 = hWnd;
    if ((((uVar2 != param_4) && (pHVar1 = local_8, param_2 <= uVar2)) && (uVar2 <= param_3)) &&
       (iVar3 != 0)) {
      SendMessageA(hWnd,0x361,0,(LPARAM)&local_28);
      pHVar1 = local_8;
    }
    local_8 = pHVar1;
  }
  if (param_5 == 1) {
    if (param_8 == 0) {
      param_6->right = local_14;
      param_6->top = 0;
      param_6->left = 0;
      param_6->bottom = local_10;
    }
    else {
      CopyRect(param_6,&local_24);
    }
  }
  else {
    if ((param_4 != 0) && (local_8 != (HWND)0x0)) {
      piVar4 = (int *)FUN_004ac7ac(local_8);
      if (param_5 == 2) {
        local_24.left = local_24.left + param_6->left;
        local_24.top = local_24.top + param_6->top;
        local_24.right = local_24.right - param_6->right;
        local_24.bottom = local_24.bottom - param_6->bottom;
      }
      (**(code **)(*piVar4 + 0x68))(&local_24,0);
      FUN_004ae3e0(&local_28,local_8,&local_24);
    }
    if (local_28 != (HDWP)0x0) {
      EndDeferWindowPos(local_28);
    }
  }
  return;
}

