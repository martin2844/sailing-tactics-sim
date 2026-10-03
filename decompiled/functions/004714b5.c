
void __fastcall FUN_004714b5(void *param_1)

{
  CWnd *pCVar1;
  LRESULT LVar2;
  int iVar3;
  SCROLLINFO local_6c;
  tagRECT local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  UINT local_10;
  UINT local_c;
  int local_8;
  
  if (*(int *)((int)param_1 + 0x68) != 0) {
    return;
  }
  *(undefined4 *)((int)param_1 + 0x68) = 1;
  local_8 = 1;
  GetParent(*(HWND *)((int)param_1 + 0x1c));
  pCVar1 = FUN_004680cc();
  if ((pCVar1 != (CWnd *)0x0) &&
     (LVar2 = SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x368,0,(LPARAM)&local_40), LVar2 != 0)) {
    local_8 = 0;
  }
  if (local_8 == 0) {
    FUN_0047132a(param_1,&local_20);
    local_10 = local_38 - local_40;
    local_c = local_34 - local_3c;
  }
  else {
    iVar3 = FUN_00471384(param_1,(int *)&local_10,&local_20);
    if (iVar3 == 0) {
      GetClientRect(*(HWND *)((int)param_1 + 0x1c),&local_50);
      if ((0 < local_50.right) && (0 < local_50.bottom)) {
        FUN_00469a79(param_1,3,0);
      }
      goto LAB_00471623;
    }
  }
  FUN_004713f9(param_1,local_10,local_c,&local_18,&local_30,&local_28,local_8);
  if (local_18 != 0) {
    local_c = local_c - local_1c;
  }
  if (local_14 != 0) {
    local_10 = local_10 - local_20;
  }
  FUN_004712b0(param_1,local_28,local_24);
  local_6c.fMask = 3;
  local_6c.nMin = 0;
  FUN_00469a79(param_1,0,local_18);
  if (local_18 != 0) {
    local_6c.nPage = local_10;
    local_6c.nMax = *(int *)((int)param_1 + 0x4c) + -1;
    iVar3 = FUN_00469abc(param_1,0,&local_6c,1);
    if (iVar3 == 0) {
      FUN_00469a46(param_1,0,0,local_30,1);
    }
  }
  FUN_00469a79(param_1,1,local_14);
  if (local_14 != 0) {
    local_6c.nPage = local_c;
    local_6c.nMax = *(int *)((int)param_1 + 0x50) + -1;
    iVar3 = FUN_00469abc(param_1,1,&local_6c,1);
    if (iVar3 == 0) {
      FUN_00469a46(param_1,1,0,local_2c,1);
    }
  }
LAB_00471623:
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  return;
}

