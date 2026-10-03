
void __thiscall FUN_00472a23(void *this,int param_1)

{
  POINT Point;
  bool bVar1;
  SHORT SVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  CWnd *pCVar5;
  HWND hWnd;
  BOOL BVar6;
  HWND pHVar7;
  int iVar8;
  tagPOINT local_18;
  int local_10;
  int local_c;
  int local_8;
  
  SVar2 = GetKeyState(1);
  if (SVar2 < 0) {
    return;
  }
  iVar3 = FUN_0047b5c5();
  GetCursorPos(&local_18);
  ScreenToClient(*(HWND *)((int)this + 0x1c),&local_18);
  local_10 = *(int *)this;
  iVar8 = 0;
  local_8 = (**(code **)(local_10 + 0x6c))(local_18.x,local_18.y,0);
  if (local_8 < 0) {
    *(undefined4 *)(iVar3 + 0x104) = 0xffffffff;
  }
  else {
    local_c = FUN_0046972b((int)this);
    bVar1 = FUN_0046979e((int)this);
    if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar4 = FUN_0046ae73(local_c), iVar4 == 0)) {
      local_8 = -1;
    }
    if (*(int *)(iVar3 + 0xcc) != 0) {
      iVar8 = *(int *)(*(int *)(iVar3 + 0xcc) + 0x1c);
    }
    GetCapture();
    pCVar5 = FUN_004680cc();
    if (pCVar5 != this) {
      if (pCVar5 == (CWnd *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(pCVar5 + 0x1c);
      }
      if ((iVar4 != iVar8) && (iVar8 = FUN_0046972b((int)pCVar5), iVar8 == local_c)) {
        local_8 = -1;
      }
    }
  }
  bVar1 = true;
  if (local_8 < 0) goto LAB_00472b39;
  ClientToScreen(*(HWND *)((int)this + 0x1c),&local_18);
  Point.y = local_18.y;
  Point.x = local_18.x;
  hWnd = WindowFromPoint(Point);
  if (hWnd == (HWND)0x0) {
LAB_00472b2a:
    local_8 = -1;
    *(undefined4 *)(iVar3 + 0x104) = 0xffffffff;
  }
  else if ((hWnd != *(HWND *)((int)this + 0x1c)) &&
          (BVar6 = IsChild(*(HWND *)((int)this + 0x1c),hWnd), BVar6 == 0)) {
    pHVar7 = (HWND)0x0;
    if (*(int *)(iVar3 + 0xcc) != 0) {
      pHVar7 = *(HWND *)(*(int *)(iVar3 + 0xcc) + 0x1c);
    }
    if (pHVar7 != hWnd) goto LAB_00472b2a;
  }
  bVar1 = local_8 < 0;
LAB_00472b39:
  if (bVar1) {
    if (*(int *)(iVar3 + 0x104) == -1) {
      KillTimer(*(HWND *)((int)this + 0x1c),0xe001);
    }
    (**(code **)(local_10 + 0xe4))(0xffffffff);
  }
  if ((param_1 == 0xe000) && (KillTimer(*(HWND *)((int)this + 0x1c),0xe000), -1 < local_8)) {
    (**(code **)(local_10 + 0xe4))(local_8);
  }
  return;
}

