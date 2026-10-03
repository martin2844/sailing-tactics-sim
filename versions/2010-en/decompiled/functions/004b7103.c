
void __thiscall FUN_004b7103(int *param_1,int param_2)

{
  POINT Point;
  SHORT SVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  int *piVar5;
  BOOL BVar6;
  HWND pHVar7;
  int iVar8;
  bool bVar9;
  tagPOINT local_18;
  int local_10;
  int local_c;
  int local_8;
  
  SVar1 = GetKeyState(1);
  if (SVar1 < 0) {
    return;
  }
  iVar2 = FUN_004bfca5();
  GetCursorPos(&local_18);
  ScreenToClient((HWND)param_1[7],&local_18);
  local_10 = *param_1;
  iVar8 = 0;
  local_8 = (**(code **)(local_10 + 0x6c))(local_18.x,local_18.y,0);
  if (local_8 < 0) {
    *(undefined4 *)(iVar2 + 0x104) = 0xffffffff;
  }
  else {
    local_c = FUN_004ade0b();
    iVar3 = FUN_004ade7e();
    if ((iVar3 == 0) || (iVar3 = FUN_004af553(), iVar3 == 0)) {
      local_8 = -1;
    }
    if (*(int *)(iVar2 + 0xcc) != 0) {
      iVar8 = *(int *)(*(int *)(iVar2 + 0xcc) + 0x1c);
    }
    pHVar4 = GetCapture();
    piVar5 = (int *)FUN_004ac7ac(pHVar4);
    if (piVar5 != param_1) {
      if (piVar5 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar5[7];
      }
      if ((iVar3 != iVar8) && (iVar8 = FUN_004ade0b(), iVar8 == local_c)) {
        local_8 = -1;
      }
    }
  }
  bVar9 = true;
  if (local_8 < 0) goto LAB_004b7219;
  ClientToScreen((HWND)param_1[7],&local_18);
  Point.y = local_18.y;
  Point.x = local_18.x;
  pHVar4 = WindowFromPoint(Point);
  if (pHVar4 == (HWND)0x0) {
LAB_004b720a:
    local_8 = -1;
    *(undefined4 *)(iVar2 + 0x104) = 0xffffffff;
  }
  else if ((pHVar4 != (HWND)param_1[7]) && (BVar6 = IsChild((HWND)param_1[7],pHVar4), BVar6 == 0)) {
    pHVar7 = (HWND)0x0;
    if (*(int *)(iVar2 + 0xcc) != 0) {
      pHVar7 = *(HWND *)(*(int *)(iVar2 + 0xcc) + 0x1c);
    }
    if (pHVar7 != pHVar4) goto LAB_004b720a;
  }
  bVar9 = local_8 < 0;
LAB_004b7219:
  if (bVar9) {
    if (*(int *)(iVar2 + 0x104) == -1) {
      KillTimer((HWND)param_1[7],0xe001);
    }
    (**(code **)(local_10 + 0xe4))(0xffffffff);
  }
  if ((param_2 == 0xe000) && (KillTimer((HWND)param_1[7],0xe000), -1 < local_8)) {
    (**(code **)(local_10 + 0xe4))(local_8);
  }
  return;
}

