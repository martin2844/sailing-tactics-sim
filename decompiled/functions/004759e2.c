
void __thiscall FUN_004759e2(void *this,int *param_1,int param_2,int param_3)

{
  uint uVar1;
  BOOL BVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
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
  
  FUN_00472995(&local_14,param_2,param_3);
  BVar2 = IsRectEmpty((RECT *)((int)this + 0x94));
  if (BVar2 == 0) {
    local_3c = *(int *)((int)this + 0x9c) - ((RECT *)((int)this + 0x94))->left;
    local_38 = *(int *)((int)this + 0xa0) - *(int *)((int)this + 0x98);
  }
  else {
    pCVar3 = FUN_004696a2((int)this);
    GetClientRect(*(HWND *)(pCVar3 + 0x1c),(LPRECT)local_58);
    local_3c = local_58._8_4_ - local_58._0_4_;
    local_38 = local_4c - local_58._4_4_;
  }
  if (*(int *)((int)this + 0x90) == 0) {
    local_88[0] = BeginDeferWindowPos(*(int *)((int)this + 0x84));
  }
  else {
    local_88[0] = (HDWP)0x0;
  }
  iVar6 = -DAT_004ae648;
  local_30 = -DAT_004ae64c;
  local_2c = 0;
  local_c = 0;
  local_18 = 0;
  local_34 = iVar6;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      local_8 = (int *)FUN_0047602d(this,local_18);
      local_40 = *(int *)(*(int *)((int)this + 0x80) + local_18 * 4);
      if (local_8 != (int *)0x0) {
        iVar5 = *local_8;
        iVar4 = (**(code **)(iVar5 + 0xd0))();
        if (iVar4 != 0) {
          uVar1 = local_8[0x19];
          if (((uVar1 & 4) == 0) || ((uVar1 & 1) == 0)) {
            iVar4 = (-(uint)((uVar1 & 0xa000) != 0) & 0xfffffffa) + 0x10;
          }
          else {
            iVar4 = 6;
          }
          (**(code **)(iVar5 + 0xc4))(&local_48,0xffffffff,iVar4);
          local_28.right = local_48 + iVar6;
          local_28.top = local_30;
          local_28.bottom = local_44 + local_30;
          local_28.left = iVar6;
          GetWindowRect((HWND)local_8[7],(LPRECT)local_58);
          ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_58);
          ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_58 + 8));
          if (param_3 == 0) {
            if ((local_28.top < (int)local_58._4_4_) && (*(int *)((int)this + 0x78) == 0)) {
              OffsetRect(&local_28,0,local_58._4_4_ - local_28.top);
            }
            if ((local_38 < local_28.bottom) && (*(int *)((int)this + 0x78) == 0)) {
              iVar4 = local_38 - ((local_28.bottom - DAT_004ae64c) - local_28.top);
              iVar5 = local_30;
              if (local_30 < iVar4) {
                iVar5 = iVar4;
              }
              OffsetRect(&local_28,0,iVar5 - local_28.top);
            }
            if (local_c == 0) {
              if (((local_38 - DAT_004ae64c <= local_28.top) && (0 < local_18)) &&
                 (*(int *)(*(int *)((int)this + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_00466de3((void *)((int)this + 0x7c),local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,0,-(DAT_004ae64c + local_28.top));
            }
            if (local_c != 0) goto LAB_00475d93;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)((int)this + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar6 = local_8[0x1d];
                *(LONG *)(iVar6 + 0x94) = local_28.left;
                *(LONG *)(iVar6 + 0x98) = local_28.top;
                *(LONG *)(iVar6 + 0x9c) = local_28.right;
                *(LONG *)(iVar6 + 0xa0) = local_28.bottom;
                iVar6 = local_34;
              }
              FUN_00469d00((int *)local_88,(HWND)local_8[7],&local_28);
            }
            local_30 = (local_28.top - DAT_004ae64c) + local_44;
            iVar5 = local_48;
          }
          else {
            if ((local_28.left < (int)local_58._0_4_) && (*(int *)((int)this + 0x78) == 0)) {
              OffsetRect(&local_28,local_58._0_4_ - local_28.left,0);
            }
            if ((local_3c < local_28.right) && (*(int *)((int)this + 0x78) == 0)) {
              iVar5 = local_3c - ((local_28.right - DAT_004ae648) - local_28.left);
              if (iVar5 <= iVar6) {
                iVar5 = iVar6;
              }
              OffsetRect(&local_28,iVar5 - local_28.left,0);
            }
            if (local_c == 0) {
              if (((local_3c - DAT_004ae648 <= local_28.left) && (0 < local_18)) &&
                 (*(int *)(*(int *)((int)this + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_00466de3((void *)((int)this + 0x7c),local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,-(DAT_004ae648 + local_28.left),0);
            }
            if (local_c != 0) goto LAB_00475d7b;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)((int)this + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar6 = local_8[0x1d];
                *(LONG *)(iVar6 + 0x94) = local_28.left;
                *(LONG *)(iVar6 + 0x98) = local_28.top;
                *(LONG *)(iVar6 + 0x9c) = local_28.right;
                *(LONG *)(iVar6 + 0xa0) = local_28.bottom;
              }
              FUN_00469d00((int *)local_88,(HWND)local_8[7],&local_28);
            }
            iVar6 = (local_28.left - DAT_004ae648) + local_48;
            iVar5 = local_44;
            local_34 = iVar6;
          }
          if (local_2c <= iVar5) {
            local_2c = iVar5;
          }
        }
LAB_00475d7b:
        if (local_c == 0) {
          (**(code **)(*local_8 + 0xd4))(local_88);
        }
      }
LAB_00475d93:
      if (((local_8 == (int *)0x0) && (local_40 == 0)) && (local_2c != 0)) {
        if (param_3 == 0) {
          iVar6 = iVar6 + (local_2c - DAT_004ae648);
          if (local_14 <= iVar6) {
            local_14 = iVar6;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          local_30 = -DAT_004ae64c;
        }
        else {
          local_30 = local_30 + (local_2c - DAT_004ae64c);
          if (local_14 <= iVar6) {
            local_14 = iVar6;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          iVar6 = -DAT_004ae648;
        }
        local_2c = 0;
        local_34 = iVar6;
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(int *)((int)this + 0x84));
  }
  if ((*(int *)((int)this + 0x90) == 0) && (local_88[0] != (HDWP)0x0)) {
    EndDeferWindowPos(local_88[0]);
  }
  SetRectEmpty(&local_68);
  FUN_00473720(this,&local_68.left,param_3);
  if (((param_2 == 0) || (param_3 == 0)) && (local_14 != 0)) {
    local_14 = local_14 + (local_68.left - local_68.right);
  }
  if (((param_2 == 0) || (param_3 != 0)) && (local_10 != 0)) {
    local_10 = local_10 + (local_68.top - local_68.bottom);
  }
  *param_1 = local_14;
  param_1[1] = local_10;
  return;
}

