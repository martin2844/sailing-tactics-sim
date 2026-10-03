
undefined4 __thiscall FUN_004b7303(CWnd *param_1,int param_2)

{
  int iVar1;
  SHORT SVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_48;
  byte local_41;
  int local_24;
  tagPOINT local_1c;
  CWnd *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = param_2;
  iVar3 = FUN_004ad0e8(param_2);
  if (iVar3 != 0) {
    return 1;
  }
  uVar5 = *(uint *)(param_2 + 4);
  local_8 = uVar5;
  local_14 = CWnd::GetOwner(param_1);
  if ((((((byte)param_1[100] & 0x20) == 0) && (uVar5 != 0x201)) && (uVar5 != 0x202)) ||
     (((uVar5 < 0x200 || (0x209 < uVar5)) && ((uVar5 < 0xa0 || (0xa9 < uVar5))))))
  goto LAB_004b74a8;
  local_10 = FUN_004bfca5();
  local_1c.x = *(LONG *)(param_2 + 0x14);
  local_1c.y = *(LONG *)(param_2 + 0x18);
  ScreenToClient(*(HWND *)(param_1 + 0x1c),&local_1c);
  _memset(&local_48,0,0x2c);
  local_48 = 0x2c;
  iVar3 = *(int *)param_1;
  param_2 = (**(code **)(iVar3 + 0x6c))(local_1c.x,local_1c.y,&local_48);
  if (local_24 != -1) {
    FUN_0049bfd0(local_24);
  }
  if ((local_8 == 0x201) && ((local_41 & 0x80) != 0)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  if ((local_8 != 0x201) && (SVar2 = GetKeyState(1), SVar2 < 0)) {
    param_2 = *(int *)(local_10 + 0x104);
  }
  if ((param_2 < 0) || (local_c != 0)) {
    SVar2 = GetKeyState(1);
    if ((-1 < SVar2) || (local_c != 0)) {
      (**(code **)(iVar3 + 0xe4))(0xffffffff);
      KillTimer(*(HWND *)(param_1 + 0x1c),0xe001);
    }
  }
  else if (local_8 == 0x202) {
    (**(code **)(iVar3 + 0xe4))(0xffffffff);
    uVar6 = 200;
    uVar5 = 0xe001;
LAB_004b745b:
    CControlBar::ResetTimer((CControlBar *)param_1,uVar5,uVar6);
  }
  else if ((((byte)param_1[0x60] & 8) == 0) && (SVar2 = GetKeyState(1), -1 < SVar2)) {
    if (param_2 != *(int *)(local_10 + 0x104)) {
      uVar6 = 300;
      uVar5 = 0xe000;
      goto LAB_004b745b;
    }
  }
  else {
    (**(code **)(iVar3 + 0xe4))(param_2);
  }
  *(int *)(local_10 + 0x104) = param_2;
LAB_004b74a8:
  iVar3 = FUN_004adeef();
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x50) == 0)) {
    while (local_14 != (CWnd *)0x0) {
      iVar3 = (**(code **)(*(int *)local_14 + 0x98))(iVar1);
      if (iVar3 != 0) {
        return 1;
      }
      local_14 = (CWnd *)FUN_004add82();
    }
    uVar4 = FUN_004aefc9(iVar1);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

