
undefined4 __thiscall FUN_00472c23(void *this,LPMSG param_1)

{
  LPMSG ptVar1;
  SHORT SVar2;
  int iVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  CWnd *pCVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_48;
  byte local_41;
  undefined *local_24;
  tagPOINT local_1c;
  CWnd *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  ptVar1 = param_1;
  iVar3 = FUN_00468a08(this,param_1);
  if (iVar3 != 0) {
    return 1;
  }
  uVar7 = param_1->message;
  local_8 = uVar7;
  local_14 = CWnd::GetOwner(this);
  if (((((*(byte *)((int)this + 100) & 0x20) == 0) && (uVar7 != 0x201)) && (uVar7 != 0x202)) ||
     (((uVar7 < 0x200 || (0x209 < uVar7)) && ((uVar7 < 0xa0 || (0xa9 < uVar7))))))
  goto LAB_00472dc8;
  local_10 = FUN_0047b5c5();
  local_1c.x = (param_1->pt).x;
  local_1c.y = (param_1->pt).y;
  ScreenToClient(*(HWND *)((int)this + 0x1c),&local_1c);
  _memset(&local_48,0,0x2c);
  local_48 = 0x2c;
  iVar3 = *(int *)this;
  param_1 = (LPMSG)(**(code **)(iVar3 + 0x6c))(local_1c.x,local_1c.y,&local_48);
  if (local_24 != (undefined *)0xffffffff) {
    FUN_00457710(local_24);
  }
  if ((local_8 == 0x201) && ((local_41 & 0x80) != 0)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  if ((local_8 != 0x201) && (SVar2 = GetKeyState(1), SVar2 < 0)) {
    param_1 = *(LPMSG *)(local_10 + 0x104);
  }
  if (((int)param_1 < 0) || (local_c != 0)) {
    SVar2 = GetKeyState(1);
    if ((-1 < SVar2) || (local_c != 0)) {
      (**(code **)(iVar3 + 0xe4))(0xffffffff);
      KillTimer(*(HWND *)((int)this + 0x1c),0xe001);
    }
  }
  else if (local_8 == 0x202) {
    (**(code **)(iVar3 + 0xe4))(0xffffffff);
    uVar8 = 200;
    uVar7 = 0xe001;
LAB_00472d7b:
    CControlBar::ResetTimer(this,uVar7,uVar8);
  }
  else if (((*(byte *)((int)this + 0x60) & 8) == 0) && (SVar2 = GetKeyState(1), -1 < SVar2)) {
    if (param_1 != *(LPMSG *)(local_10 + 0x104)) {
      uVar8 = 300;
      uVar7 = 0xe000;
      goto LAB_00472d7b;
    }
  }
  else {
    (**(code **)(iVar3 + 0xe4))(param_1);
  }
  *(LPMSG *)(local_10 + 0x104) = param_1;
LAB_00472dc8:
  pCVar4 = FUN_0046980f(this);
  pCVar6 = local_14;
  if ((pCVar4 == (CWnd *)0x0) || (*(int *)(pCVar4 + 0x50) == 0)) {
    for (; local_14 = pCVar6, pCVar6 != (CWnd *)0x0; pCVar6 = FUN_004696a2((int)pCVar6)) {
      iVar3 = (**(code **)(*(int *)pCVar6 + 0x98))(ptVar1);
      if (iVar3 != 0) {
        return 1;
      }
    }
    uVar5 = FUN_0046a8e9(this,ptVar1);
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

