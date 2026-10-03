
int __thiscall
FUN_004ba729(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7,int param_8)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 local_24 [12];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_c = 0;
  bVar3 = (*(uint *)(param_1 + 100) & 0xa000) == 0;
  local_14 = 0;
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x84)) {
    do {
      piVar1 = (int *)FUN_004ba70d(local_8);
      if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0xd0))(), iVar2 == 0)) {
        iVar2 = local_c - DAT_005381a4;
        local_c = 0;
        local_14 = local_14 + iVar2;
        iVar2 = param_8;
        if (bVar3) {
          iVar2 = param_7;
        }
        if (iVar2 < local_14) {
          if (local_8 == 0) {
            FUN_004ab4c3(local_10 + 1,0,1);
          }
          iVar2 = local_10 + 1;
          goto LAB_004ba848;
        }
LAB_004ba812:
        local_10 = local_8;
      }
      else {
        GetWindowRect((HWND)piVar1[7],(LPRECT)local_24);
        ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)local_24);
        ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)(local_24 + 8));
        if (bVar3) {
          iVar2 = (local_24._8_4_ - local_24._0_4_) + -1;
        }
        else {
          iVar2 = local_18 - local_24._4_4_;
        }
        if (local_c <= iVar2) {
          if (bVar3) {
            local_c = (local_24._8_4_ - local_24._0_4_) + -1;
          }
          else {
            local_c = local_18 - local_24._4_4_;
          }
        }
        if (bVar3) {
          bVar5 = SBORROW4(param_4,local_24._4_4_);
          iVar2 = param_4 - local_24._4_4_;
          bVar4 = param_4 == local_24._4_4_;
        }
        else {
          bVar5 = SBORROW4(param_3,local_24._0_4_);
          iVar2 = param_3 - local_24._0_4_;
          bVar4 = param_3 == local_24._0_4_;
        }
        if (!bVar4 && bVar5 == iVar2 < 0) goto LAB_004ba812;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(param_1 + 0x84));
  }
  iVar2 = local_10 + 1;
  FUN_004ab4c3(iVar2,0,1);
LAB_004ba848:
  FUN_004ab4c3(iVar2,param_2,1);
  return iVar2;
}

