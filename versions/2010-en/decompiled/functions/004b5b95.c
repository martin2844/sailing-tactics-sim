
void __fastcall FUN_004b5b95(int param_1)

{
  HWND pHVar1;
  int iVar2;
  LRESULT LVar3;
  undefined1 local_6c [4];
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  tagRECT local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x68) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x68) = 1;
  local_8 = 1;
  pHVar1 = GetParent(*(HWND *)(param_1 + 0x1c));
  iVar2 = FUN_004ac7ac(pHVar1);
  if ((iVar2 != 0) &&
     (LVar3 = SendMessageA(*(HWND *)(iVar2 + 0x1c),0x368,0,(LPARAM)&local_40), LVar3 != 0)) {
    local_8 = 0;
  }
  if (local_8 == 0) {
    FUN_004b5a0a(&local_20);
    local_10 = local_38 - local_40;
    local_c = local_34 - local_3c;
  }
  else {
    iVar2 = FUN_004b5a64(&local_10,&local_20);
    if (iVar2 == 0) {
      GetClientRect(*(HWND *)(param_1 + 0x1c),&local_50);
      if ((0 < local_50.right) && (0 < local_50.bottom)) {
        FUN_004ae159(3,0);
      }
      goto LAB_004b5d03;
    }
  }
  FUN_004b5ad9(local_10,local_c,&local_18,&local_30,&local_28,local_8);
  if (local_18 != 0) {
    local_c = local_c - local_1c;
  }
  if (local_14 != 0) {
    local_10 = local_10 - local_20;
  }
  FUN_004b5990(local_28,local_24);
  local_68 = 3;
  local_64 = 0;
  FUN_004ae159(0,local_18);
  if (local_18 != 0) {
    local_5c = local_10;
    local_60 = *(int *)(param_1 + 0x4c) + -1;
    iVar2 = FUN_004ae19c(0,local_6c,1);
    if (iVar2 == 0) {
      FUN_004ae126(0,0,local_30,1);
    }
  }
  FUN_004ae159(1,local_14);
  if (local_14 != 0) {
    local_5c = local_c;
    local_60 = *(int *)(param_1 + 0x50) + -1;
    iVar2 = FUN_004ae19c(1,local_6c,1);
    if (iVar2 == 0) {
      FUN_004ae126(1,0,local_2c,1);
    }
  }
LAB_004b5d03:
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}

