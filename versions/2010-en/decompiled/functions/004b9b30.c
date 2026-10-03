
void __thiscall FUN_004b9b30(int param_1,int param_2,RECT *param_3)

{
  BOOL BVar1;
  uint uVar2;
  HWND pHVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_130 [260];
  tagRECT local_2c;
  int local_1c;
  undefined4 local_18;
  undefined1 local_14 [12];
  int local_8;
  
  GetWindowRect(*(HWND *)(param_2 + 0x1c),&local_2c);
  if (*(int *)(param_2 + 0x70) == param_1) {
    if (param_3 == (RECT *)0x0) {
      return;
    }
    BVar1 = EqualRect(&local_2c,param_3);
    if (BVar1 != 0) {
      return;
    }
  }
  if ((*(int *)(param_1 + 0x78) != 0) && ((*(byte *)(param_2 + 0x68) & 0x40) != 0)) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 0x40;
  }
  *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) & 0xfffffff9;
  uVar2 = *(uint *)(param_1 + 100);
  *(uint *)(param_1 + 100) = *(uint *)(param_2 + 100) & 6 | uVar2;
  if ((uVar2 & 0x40) == 0) {
    FUN_004af4ae(local_130,0x104);
    FUN_004b55a5(*(undefined4 *)(param_1 + 0x1c),local_130);
  }
  uVar6 = *(undefined4 *)(param_2 + 100);
  uVar2 = CONCAT22((short)((uint)uVar6 >> 0x10),
                   CONCAT11(((byte)((uint)*(undefined4 *)(param_2 + 100) >> 8) ^
                            (byte)((uint)*(undefined4 *)(param_1 + 100) >> 8)) & 0xf0 ^
                            (byte)((uint)uVar6 >> 8),(char)uVar6));
  if (*(int *)(param_1 + 0x78) == 0) {
    uVar2 = uVar2 & 0xfffffffe | 0xf00;
  }
  else {
    uVar2 = uVar2 | 0xf01;
  }
  FUN_004c0a0d(uVar2);
  local_1c = 0;
  if ((*(int *)(param_2 + 0x70) != param_1) &&
     (BVar1 = IsWindowVisible(*(HWND *)(param_2 + 0x1c)), BVar1 != 0)) {
    FUN_004af4dd(0,0,0,0,0,0x97);
    local_1c = 1;
  }
  local_18 = 0xffffffff;
  if (param_3 == (RECT *)0x0) {
    FUN_004ab49c(*(undefined4 *)(param_1 + 0x84),param_2);
    FUN_004ab49c(*(undefined4 *)(param_1 + 0x84),0);
    FUN_004af4dd(0,-DAT_005381a0,-DAT_005381a4,0,0,0x115);
  }
  else {
    CopyRect((LPRECT)local_14,param_3);
    ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)local_14);
    ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)(local_14 + 8));
    local_18 = FUN_004ba729(param_2,local_14._0_4_,local_14._4_4_,local_14._8_4_,local_8,
                            (int)(local_14._8_4_ - local_14._0_4_) / 2 + local_14._0_4_,
                            (local_8 - local_14._4_4_) / 2 + local_14._4_4_);
    FUN_004af4dd(0,local_14._0_4_,local_14._4_4_,local_14._8_4_ - local_14._0_4_,
                 local_8 - local_14._4_4_,0x114);
  }
  pHVar3 = GetParent(*(HWND *)(param_2 + 0x1c));
  iVar4 = FUN_004ac7ac(pHVar3);
  if (iVar4 != param_1) {
    if (param_1 == 0) {
      pHVar3 = (HWND)0x0;
    }
    else {
      pHVar3 = *(HWND *)(param_1 + 0x1c);
    }
    pHVar3 = SetParent(*(HWND *)(param_2 + 0x1c),pHVar3);
    FUN_004ac7ac(pHVar3);
  }
  iVar4 = *(int *)(param_2 + 0x70);
  if (iVar4 == param_1) {
    uVar6 = 0;
    uVar5 = local_18;
  }
  else {
    if (iVar4 == 0) goto LAB_004b9d38;
    if ((*(int *)(param_1 + 0x78) == 0) || (*(int *)(iVar4 + 0x78) != 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    uVar5 = 0xffffffff;
  }
  FUN_004b9fb2(param_2,uVar5,uVar6);
LAB_004b9d38:
  *(int *)(param_2 + 0x70) = param_1;
  if (local_1c != 0) {
    FUN_004af4dd(0,0,0,0,0,0x57);
  }
  FUN_004b9f5b(param_2);
  iVar4 = FUN_004bcdbe();
  *(uint *)(iVar4 + 0xb8) = *(uint *)(iVar4 + 0xb8) | 0xc;
  return;
}

