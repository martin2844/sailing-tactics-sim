
uint __thiscall FUN_00478fae(void *this,int param_1,int param_2)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  SHORT SVar1;
  int iVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  RECT local_70 [3];
  tagRECT local_3c;
  tagRECT local_2c;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = FUN_0046ad0b((int)this);
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_2c);
  iVar2 = GetSystemMetrics(0x21);
  local_10 = iVar2;
  local_c = GetSystemMetrics(0x20);
  if (DAT_004ae69c != 0) {
    uVar3 = FUN_00468021(this);
    if ((DAT_004ae694 != 0) && ((local_8 & 0x1000) != 0)) {
      if (uVar3 == 3) {
        uVar3 = 2;
      }
      SVar1 = GetKeyState(2);
      if (SVar1 < 0) {
        return 0;
      }
    }
    if (((uVar3 < 10) || (0x11 < uVar3)) && (uVar3 != 4)) {
      return uVar3;
    }
    if ((local_8 & 0x800) != 0) {
      return 2;
    }
    InflateRect(&local_2c,-local_c,-iVar2);
    if ((local_8 & 0x200) == 0) {
      return uVar3;
    }
    if (uVar3 != 4) {
      if (uVar3 == 0xd) {
        uVar3 = (local_2c.top <= param_2) - 1 & 2;
LAB_004790a1:
        return uVar3 + 10;
      }
      if (uVar3 == 0xe) {
        uVar3 = (uint)(param_2 < local_2c.top);
        goto LAB_004790b8;
      }
      if (uVar3 == 0x10) {
        uVar3 = (param_2 <= local_2c.bottom) - 1 & 5;
        goto LAB_004790a1;
      }
      if (uVar3 != 0x11) {
        return uVar3;
      }
    }
    uVar3 = (param_2 <= local_2c.bottom) - 1 & 4;
LAB_004790b8:
    return uVar3 + 0xb;
  }
  pt.y = param_2;
  pt.x = param_1;
  BVar4 = PtInRect(&local_2c,pt);
  if (BVar4 == 0) {
    return 0;
  }
  local_14 = GetSystemMetrics(6);
  iVar2 = GetSystemMetrics(5);
  local_70[0].top = local_2c.top;
  local_70[0].left = local_2c.left;
  local_70[0].bottom = local_2c.bottom;
  local_70[0].right = local_2c.right;
  FUN_00478f48(this,(LPRECT)0x0);
  CopyRect(&local_3c,local_70);
  pt_00.y = param_2;
  pt_00.x = param_1;
  BVar4 = PtInRect(&local_3c,pt_00);
  if (BVar4 != 0) {
    return 1;
  }
  if ((local_8 & 0x40600) == 0) goto LAB_00479273;
  local_1c = 0;
  iVar2 = local_c + iVar2 * -3 + DAT_004ae8d8;
  iVar5 = local_10 + local_14 * -2 + DAT_004ae8dc;
  if (param_2 < local_10 + local_2c.top) {
    if ((local_8 & 0x200) == 0) {
      if (local_2c.left + iVar2 < param_1) {
        uVar3 = ((param_1 < local_2c.right - iVar2) - 1 & 2) + 0xc;
      }
      else {
LAB_00479204:
        uVar3 = 0xd;
      }
    }
    else {
      uVar3 = 0xc;
    }
  }
  else {
    local_18 = local_2c.bottom - local_10;
    if (param_2 < local_18) {
      if (param_1 < local_2c.left + local_c) {
        if ((local_8 & 0x200) == 0) {
          if (param_2 <= iVar5 + local_2c.top) goto LAB_00479204;
          uVar3 = ((param_2 < local_2c.bottom - iVar5) - 1 & 6) + 10;
        }
        else {
          uVar3 = 10;
        }
      }
      else if (param_1 < local_2c.right - local_c) {
        uVar3 = 0;
      }
      else if ((local_8 & 0x200) == 0) {
        if (iVar5 + local_2c.top < param_2) {
          uVar3 = ((param_2 < local_2c.bottom - iVar5) - 1 & 6) + 0xb;
        }
        else {
          uVar3 = 0xe;
        }
      }
      else {
        uVar3 = 0xb;
      }
    }
    else if ((local_8 & 0x200) == 0) {
      if (local_2c.left + iVar2 < param_1) {
        uVar3 = ((param_1 < local_2c.right - iVar2) - 1 & 2) + 0xf;
      }
      else {
        uVar3 = 0x10;
      }
    }
    else {
      uVar3 = 0xf;
    }
  }
  if (uVar3 != 0) {
    if ((local_8 & 0x800) != 0) {
      return 2;
    }
    return uVar3;
  }
  InflateRect(&local_2c,-local_c,-local_10);
LAB_00479273:
  local_2c.bottom = local_14 + local_2c.top + DAT_004ae8dc;
  pt_01.y = param_2;
  pt_01.x = param_1;
  BVar4 = PtInRect(&local_2c,pt_01);
  if (BVar4 == 0) {
    return 0xfffffffe;
  }
  if ((param_1 < local_2c.left + -2 + DAT_004ae8d8) && ((local_8 & 0x80000) != 0)) {
    return 3;
  }
  return 2;
}

