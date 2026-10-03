
void __fastcall FUN_0046ec40(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  BOOL BVar4;
  CWnd *pCVar5;
  int local_14;
  int local_10;
  int local_8;
  
  iVar3 = *param_1;
  pcVar1 = *(code **)(iVar3 + 0x68);
  local_8 = (*pcVar1)();
  if (local_8 != 0) {
    pcVar2 = *(code **)(iVar3 + 0x6c);
    do {
      iVar3 = (*pcVar2)(&local_8);
      BVar4 = IsWindowVisible(*(HWND *)(iVar3 + 0x1c));
      if (BVar4 != 0) {
        pCVar5 = FUN_004696a2(iVar3);
        if (pCVar5 != (CWnd *)0x0) {
          *(undefined4 *)(pCVar5 + 0x40) = 0xffffffff;
        }
      }
    } while (local_8 != 0);
  }
  local_10 = 0;
  local_8 = (*pcVar1)();
  if (local_8 != 0) {
    pcVar2 = *(code **)(*param_1 + 0x6c);
    do {
      iVar3 = (*pcVar2)(&local_8);
      BVar4 = IsWindowVisible(*(HWND *)(iVar3 + 0x1c));
      if (BVar4 != 0) {
        pCVar5 = FUN_004696a2(iVar3);
        if ((pCVar5 != (CWnd *)0x0) && (*(int *)(pCVar5 + 0x40) == -1)) {
          local_10 = local_10 + 1;
          *(int *)(pCVar5 + 0x40) = local_10;
        }
      }
    } while (local_8 != 0);
  }
  local_14 = 1;
  local_8 = (*pcVar1)();
  if (local_8 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x6c);
    do {
      iVar3 = (*pcVar1)(&local_8);
      BVar4 = IsWindowVisible(*(HWND *)(iVar3 + 0x1c));
      if (BVar4 != 0) {
        pCVar5 = FUN_004696a2(iVar3);
        if ((pCVar5 != (CWnd *)0x0) && (*(int *)(pCVar5 + 0x40) == local_14)) {
          if (local_10 == 1) {
            *(undefined4 *)(pCVar5 + 0x40) = 0;
          }
          (**(code **)(*(int *)pCVar5 + 0xe8))(1);
          local_14 = local_14 + 1;
        }
      }
    } while (local_8 != 0);
  }
  return;
}

