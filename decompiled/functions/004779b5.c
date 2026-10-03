
void __thiscall FUN_004779b5(void *this,int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  HMENU pHVar2;
  HMENU pHVar3;
  uint uVar4;
  UINT UVar5;
  int nPos;
  CCmdUI local_30 [4];
  UINT local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_10;
  int local_c;
  int *local_8;
  
  local_8 = this;
  FUN_00470f36(*(HWND *)((int)this + 0x1c));
  if (param_3 == 0) {
    CCmdUI::CCmdUI(local_30);
    local_24 = param_1;
    iVar1 = FUN_0047b5c5();
    if (*(int *)(iVar1 + 0x54) == *(int *)(param_1 + 4)) {
      local_c = param_1;
    }
    else {
      pHVar2 = GetMenu(*(HWND *)((int)this + 0x1c));
      if (((pHVar2 != (HMENU)0x0) && (iVar1 = FUN_0046972b((int)this), iVar1 != 0)) &&
         (pHVar2 = GetMenu(*(HWND *)(iVar1 + 0x1c)), pHVar2 != (HMENU)0x0)) {
        iVar1 = GetMenuItemCount(pHVar2);
        nPos = 0;
        if (0 < iVar1) {
          do {
            pHVar3 = GetSubMenu(pHVar2,nPos);
            if (pHVar3 == *(HMENU *)(param_1 + 4)) {
              local_c = FUN_0046d7e9();
              break;
            }
            nPos = nPos + 1;
          } while (nPos < iVar1);
        }
      }
    }
    local_10 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
    local_28 = 0;
    if (local_10 != 0) {
      do {
        local_2c = GetMenuItemID(*(HMENU *)(param_1 + 4),local_28);
        uVar4 = local_10;
        if (local_2c != 0) {
          if (local_2c == 0xffffffff) {
            GetSubMenu(*(HMENU *)(param_1 + 4),local_28);
            local_20 = FUN_0046d7e9();
            uVar4 = local_10;
            if (((local_20 == 0) ||
                (local_2c = GetMenuItemID(*(HMENU *)(local_20 + 4),0), uVar4 = local_10,
                local_2c == 0)) || (local_2c == 0xffffffff)) goto LAB_00477b04;
            iVar1 = 0;
          }
          else {
            local_20 = 0;
            if ((local_8[0xf] == 0) || (0xefff < local_2c)) {
              iVar1 = 0;
            }
            else {
              iVar1 = 1;
            }
          }
          FUN_0046b482(local_30,local_8,iVar1);
          uVar4 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
          if (uVar4 < local_10) {
            local_28 = local_28 + (uVar4 - local_10);
            while ((local_28 < uVar4 &&
                   (UVar5 = GetMenuItemID(*(HMENU *)(param_1 + 4),local_28), UVar5 == local_2c))) {
              local_28 = local_28 + 1;
            }
          }
        }
LAB_00477b04:
        local_10 = uVar4;
        local_28 = local_28 + 1;
      } while (local_28 < local_10);
    }
  }
  return;
}

