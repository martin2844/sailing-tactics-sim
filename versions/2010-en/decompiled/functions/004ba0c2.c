
void __thiscall FUN_004ba0c2(int param_1,int *param_2,int param_3,int param_4)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HDWP local_88 [8];
  tagRECT local_68;
  undefined1 local_58 [12];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  FUN_004b7075(&local_14,param_3,param_4);
  BVar2 = IsRectEmpty((RECT *)(param_1 + 0x94));
  if (BVar2 == 0) {
    local_3c = *(int *)(param_1 + 0x9c) - ((RECT *)(param_1 + 0x94))->left;
    local_38 = *(int *)(param_1 + 0xa0) - *(int *)(param_1 + 0x98);
  }
  else {
    iVar5 = FUN_004add82();
    GetClientRect(*(HWND *)(iVar5 + 0x1c),(LPRECT)local_58);
    local_3c = local_58._8_4_ - local_58._0_4_;
    local_38 = local_4c - local_58._4_4_;
  }
  if (*(int *)(param_1 + 0x90) == 0) {
    local_88[0] = BeginDeferWindowPos(*(int *)(param_1 + 0x84));
  }
  else {
    local_88[0] = (HDWP)0x0;
  }
  iVar5 = -DAT_005381a0;
  local_30 = -DAT_005381a4;
  local_2c = 0;
  local_c = 0;
  local_18 = 0;
  local_34 = iVar5;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      local_8 = (int *)FUN_004ba70d(local_18);
      local_40 = *(int *)(*(int *)(param_1 + 0x80) + local_18 * 4);
      if (local_8 != (int *)0x0) {
        iVar4 = *local_8;
        iVar3 = (**(code **)(iVar4 + 0xd0))();
        if (iVar3 != 0) {
          uVar1 = local_8[0x19];
          if (((uVar1 & 4) == 0) || ((uVar1 & 1) == 0)) {
            iVar3 = (-(uint)((uVar1 & 0xa000) != 0) & 0xfffffffa) + 0x10;
          }
          else {
            iVar3 = 6;
          }
          (**(code **)(iVar4 + 0xc4))(&local_48,0xffffffff,iVar3);
          local_28.right = local_48 + iVar5;
          local_28.top = local_30;
          local_28.bottom = local_44 + local_30;
          local_28.left = iVar5;
          GetWindowRect((HWND)local_8[7],(LPRECT)local_58);
          ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)local_58);
          ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)(local_58 + 8));
          if (param_4 == 0) {
            if ((local_28.top < (int)local_58._4_4_) && (*(int *)(param_1 + 0x78) == 0)) {
              OffsetRect(&local_28,0,local_58._4_4_ - local_28.top);
            }
            if ((local_38 < local_28.bottom) && (*(int *)(param_1 + 0x78) == 0)) {
              iVar3 = local_38 - ((local_28.bottom - DAT_005381a4) - local_28.top);
              iVar4 = local_30;
              if (local_30 < iVar3) {
                iVar4 = iVar3;
              }
              OffsetRect(&local_28,0,iVar4 - local_28.top);
            }
            if (local_c == 0) {
              if (((local_38 - DAT_005381a4 <= local_28.top) && (0 < local_18)) &&
                 (*(int *)(*(int *)(param_1 + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_004ab4c3(local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,0,-(DAT_005381a4 + local_28.top));
            }
            if (local_c != 0) goto LAB_004ba473;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)(param_1 + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar5 = local_8[0x1d];
                *(LONG *)(iVar5 + 0x94) = local_28.left;
                *(LONG *)(iVar5 + 0x98) = local_28.top;
                *(LONG *)(iVar5 + 0x9c) = local_28.right;
                *(LONG *)(iVar5 + 0xa0) = local_28.bottom;
                iVar5 = local_34;
              }
              FUN_004ae3e0(local_88,local_8[7],&local_28);
            }
            local_30 = (local_28.top - DAT_005381a4) + local_44;
            iVar4 = local_48;
          }
          else {
            if ((local_28.left < (int)local_58._0_4_) && (*(int *)(param_1 + 0x78) == 0)) {
              OffsetRect(&local_28,local_58._0_4_ - local_28.left,0);
            }
            if ((local_3c < local_28.right) && (*(int *)(param_1 + 0x78) == 0)) {
              iVar4 = local_3c - ((local_28.right - DAT_005381a0) - local_28.left);
              if (iVar4 <= iVar5) {
                iVar4 = iVar5;
              }
              OffsetRect(&local_28,iVar4 - local_28.left,0);
            }
            if (local_c == 0) {
              if (((local_3c - DAT_005381a0 <= local_28.left) && (0 < local_18)) &&
                 (*(int *)(*(int *)(param_1 + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_004ab4c3(local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,-(DAT_005381a0 + local_28.left),0);
            }
            if (local_c != 0) goto LAB_004ba45b;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)(param_1 + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar5 = local_8[0x1d];
                *(LONG *)(iVar5 + 0x94) = local_28.left;
                *(LONG *)(iVar5 + 0x98) = local_28.top;
                *(LONG *)(iVar5 + 0x9c) = local_28.right;
                *(LONG *)(iVar5 + 0xa0) = local_28.bottom;
              }
              FUN_004ae3e0(local_88,local_8[7],&local_28);
            }
            iVar5 = (local_28.left - DAT_005381a0) + local_48;
            iVar4 = local_44;
            local_34 = iVar5;
          }
          if (local_2c <= iVar4) {
            local_2c = iVar4;
          }
        }
LAB_004ba45b:
        if (local_c == 0) {
          (**(code **)(*local_8 + 0xd4))(local_88);
        }
      }
LAB_004ba473:
      if (((local_8 == (int *)0x0) && (local_40 == 0)) && (local_2c != 0)) {
        if (param_4 == 0) {
          iVar5 = iVar5 + (local_2c - DAT_005381a0);
          if (local_14 <= iVar5) {
            local_14 = iVar5;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          local_30 = -DAT_005381a4;
        }
        else {
          local_30 = local_30 + (local_2c - DAT_005381a4);
          if (local_14 <= iVar5) {
            local_14 = iVar5;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          iVar5 = -DAT_005381a0;
        }
        local_2c = 0;
        local_34 = iVar5;
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(int *)(param_1 + 0x84));
  }
  if ((*(int *)(param_1 + 0x90) == 0) && (local_88[0] != (HDWP)0x0)) {
    EndDeferWindowPos(local_88[0]);
  }
  SetRectEmpty(&local_68);
  FUN_004b7e00(&local_68,param_4);
  if (((param_3 == 0) || (param_4 == 0)) && (local_14 != 0)) {
    local_14 = local_14 + (local_68.left - local_68.right);
  }
  if (((param_3 == 0) || (param_4 != 0)) && (local_10 != 0)) {
    local_10 = local_10 + (local_68.top - local_68.bottom);
  }
  *param_2 = local_14;
  param_2[1] = local_10;
  return;
}

