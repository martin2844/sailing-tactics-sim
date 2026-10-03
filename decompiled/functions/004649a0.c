
void __cdecl FUN_004649a0(HWND param_1,HDC param_2,uint param_3)

{
  uint uVar1;
  HWND hWnd;
  DWORD DVar2;
  HGDIOBJ pvVar3;
  HDC hdc;
  int x;
  HGDIOBJ local_154;
  int local_150;
  int local_14c;
  uint local_144;
  int local_140;
  int local_13c;
  HGDIOBJ local_138;
  uint local_134;
  tagRECT local_130;
  tagRECT local_120;
  undefined1 local_110 [12];
  int local_104;
  CHAR local_100 [256];
  
  uVar1 = GetWindowLongA(param_1,-0x10);
  local_144 = uVar1 & 0x20;
  uVar1 = uVar1 & 0x1f;
  hWnd = GetParent(param_1);
  SetBkMode(param_2,2);
  GetClientRect(param_1,&local_120);
  local_130.left = local_120.left;
  local_130.top = local_120.top;
  local_130.right = local_120.right;
  local_130.bottom = local_120.bottom;
  local_154 = (HGDIOBJ)SendMessageA(param_1,0x31,0,0);
  if (local_154 != (HGDIOBJ)0x0) {
    local_154 = SelectObject(param_2,local_154);
  }
  DVar2 = GetSysColor(0xf);
  SetBkColor(param_2,DVar2);
  DVar2 = GetSysColor(0x12);
  SetTextColor(param_2,DVar2);
  pvVar3 = (HGDIOBJ)SendMessageA(hWnd,0x135,(WPARAM)param_2,(LPARAM)param_1);
  local_138 = SelectObject(param_2,pvVar3);
  IntersectClipRect(param_2,local_130.left,local_130.top,local_130.right,local_130.bottom);
  if (((param_3 & 0x10) != 0) && (uVar1 != 7)) {
    PatBlt(param_2,local_130.left,local_130.top,local_130.right - local_130.left,
           local_130.bottom - local_130.top,0xf00021);
  }
  local_13c = IsWindowEnabled(param_1);
  local_110._0_4_ = SendMessageA(param_1,0xf2,0,0);
  local_14c = 0;
  local_134 = local_110._0_4_ & 3;
  local_110._0_4_ = local_110._0_4_ & 4;
  local_150 = ((int)local_110._0_4_ >> 1 | -(uint)(local_134 == 0) + 1) * 0xe;
  if (local_13c == 0) {
    local_150 = local_150 + (-(uint)(local_134 == 0) + 3) * 0xe;
  }
  if ((((param_3 & 10) != 0) || (uVar1 == 0)) || (uVar1 == 1)) {
    local_140 = GetWindowTextA(param_1,local_100,0x100);
  }
  switch(uVar1) {
  case 0:
  case 1:
    FUN_00464660(param_1,param_2,&local_120,local_100,local_140,(short)uVar1,local_110._0_4_);
    goto switchD_00464b5c_caseD_8;
  case 2:
  case 3:
    break;
  case 4:
  case 9:
    local_14c = 0xd;
    break;
  case 5:
  case 6:
    if (local_134 == 2) {
      local_14c = 0x1a;
    }
    break;
  case 7:
    if ((param_3 & 6) != 0) {
      FUN_00462d60(param_2,local_100,(LONG *)&local_134,(LONG *)&local_144);
      if (local_144 == 0) {
        FUN_00462d60(param_2,&DAT_004a3360,(LONG *)local_110,(LONG *)&local_144);
      }
      local_130.left = local_130.left + 4;
      local_130.right = local_134 + local_130.left + 4;
      local_130.bottom = local_144 + local_130.top;
      if ((param_3 & 0x20) != 0) {
        local_110._4_4_ = local_130.top;
        local_110._8_4_ = local_120.right;
        local_110._0_4_ = local_130.left;
        local_104 = local_130.bottom;
        ClientToScreen(param_1,(LPPOINT)local_110);
        ClientToScreen(param_1,(LPPOINT)(local_110 + 8));
        ScreenToClient(hWnd,(LPPOINT)local_110);
        ScreenToClient(hWnd,(LPPOINT)(local_110 + 8));
        InvalidateRect(hWnd,(RECT *)local_110,1);
        return;
      }
      local_120.right = local_120.right + -1;
      local_120.bottom = local_120.bottom + -1;
      local_120.top = local_120.top + (int)local_144 / 2;
      FUN_00462b70(param_2,&local_120.left,2,2,0xf);
      OffsetRect(&local_120,1,1);
      FUN_00462b70(param_2,&local_120.left,0,0,0xf);
      if (local_13c == 0) {
        SetTextColor(param_2,DAT_004aff7c);
      }
      DrawTextA(param_2,local_100,local_140,&local_130,0x20);
    }
  default:
    goto switchD_00464b5c_caseD_8;
  }
  if (((param_3 & 4) != 0) && (hdc = CreateCompatibleDC(param_2), hdc != (HDC)0x0)) {
    pvVar3 = SelectObject(hdc,DAT_004aff90);
    if (pvVar3 != (HGDIOBJ)0x0) {
      x = local_130.left;
      if (local_144 != 0) {
        x = local_130.right + -0xe;
      }
      BitBlt(param_2,x,local_130.top + ((local_130.bottom - local_130.top) + -0xd) / 2,0xe,0xd,hdc,
             local_150,local_14c,0xcc0020);
      SelectObject(hdc,pvVar3);
    }
    DeleteDC(hdc);
  }
  if ((param_3 & 2) != 0) {
    if (local_144 == 0) {
      local_130.left = local_120.left + 0x12;
    }
    else {
      local_130.right = local_120.right + -0x12;
    }
    if (local_13c == 0) {
      SetTextColor(param_2,DAT_004aff7c);
    }
    DrawTextA(param_2,local_100,local_140,&local_130,0x24);
  }
  if ((param_3 & 8) != 0) {
    FUN_00462d60(param_2,local_100,(LONG *)local_110,(LONG *)&local_134);
    local_130.top = (int)((local_130.bottom - local_130.top) - local_134) / 2;
    local_130.bottom = local_134 + local_130.top;
    if (local_144 == 0) {
      local_130.left = local_120.left + 0x12;
    }
    else {
      local_120.right = local_120.right + -0x12;
      local_130.left = local_120.left;
    }
    local_130.right = local_110._0_4_ + local_130.left;
    InflateRect(&local_130,1,1);
    IntersectRect(&local_130,&local_130,&local_120);
    DrawFocusRect(param_2,&local_130);
  }
switchD_00464b5c_caseD_8:
  SelectObject(param_2,local_138);
  if (local_154 != (HGDIOBJ)0x0) {
    SelectObject(param_2,local_154);
  }
  return;
}

