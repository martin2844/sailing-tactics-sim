
void __thiscall FUN_004bc095(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  HMENU pHVar2;
  HMENU pHVar3;
  uint uVar4;
  UINT UVar5;
  int nPos;
  undefined4 uVar6;
  CCmdUI local_30 [4];
  UINT local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = param_1;
  FUN_004b5616(*(undefined4 *)(param_1 + 0x1c));
  if (param_4 == 0) {
    CCmdUI::CCmdUI(local_30);
    local_24 = param_2;
    iVar1 = FUN_004bfca5();
    if (*(int *)(iVar1 + 0x54) == *(int *)(param_2 + 4)) {
      local_c = param_2;
    }
    else {
      pHVar3 = GetMenu(*(HWND *)(param_1 + 0x1c));
      if (((pHVar3 != (HMENU)0x0) && (iVar1 = FUN_004ade0b(), iVar1 != 0)) &&
         (pHVar3 = GetMenu(*(HWND *)(iVar1 + 0x1c)), pHVar3 != (HMENU)0x0)) {
        iVar1 = GetMenuItemCount(pHVar3);
        nPos = 0;
        if (0 < iVar1) {
          do {
            pHVar2 = GetSubMenu(pHVar3,nPos);
            if (pHVar2 == *(HMENU *)(param_2 + 4)) {
              local_c = FUN_004b1ec9(pHVar3);
              break;
            }
            nPos = nPos + 1;
          } while (nPos < iVar1);
        }
      }
    }
    local_10 = GetMenuItemCount(*(HMENU *)(param_2 + 4));
    local_28 = 0;
    if (local_10 != 0) {
      do {
        local_2c = GetMenuItemID(*(HMENU *)(param_2 + 4),local_28);
        uVar4 = local_10;
        if (local_2c != 0) {
          if (local_2c == 0xffffffff) {
            pHVar3 = GetSubMenu(*(HMENU *)(param_2 + 4),local_28);
            local_20 = FUN_004b1ec9(pHVar3);
            uVar4 = local_10;
            if (((local_20 == 0) ||
                (local_2c = GetMenuItemID(*(HMENU *)(local_20 + 4),0), uVar4 = local_10,
                local_2c == 0)) || (local_2c == 0xffffffff)) goto LAB_004bc1e4;
            uVar6 = 0;
          }
          else {
            local_20 = 0;
            if ((*(int *)(local_8 + 0x3c) == 0) || (0xefff < local_2c)) {
              uVar6 = 0;
            }
            else {
              uVar6 = 1;
            }
          }
          FUN_004afb62(local_8,uVar6);
          uVar4 = GetMenuItemCount(*(HMENU *)(param_2 + 4));
          if (uVar4 < local_10) {
            local_28 = local_28 + (uVar4 - local_10);
            while ((local_28 < uVar4 &&
                   (UVar5 = GetMenuItemID(*(HMENU *)(param_2 + 4),local_28), UVar5 == local_2c))) {
              local_28 = local_28 + 1;
            }
          }
        }
LAB_004bc1e4:
        local_10 = uVar4;
        local_28 = local_28 + 1;
      } while (local_28 < local_10);
    }
  }
  return;
}

