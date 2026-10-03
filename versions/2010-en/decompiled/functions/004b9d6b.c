
void __thiscall FUN_004b9d6b(int param_1,int param_2,RECT *param_3)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  HWND pHVar4;
  undefined4 uVar5;
  undefined1 local_128 [260];
  tagRECT local_24;
  undefined1 local_14 [12];
  int local_8;
  
  GetWindowRect(*(HWND *)(param_2 + 0x1c),&local_24);
  if (*(int *)(param_2 + 0x70) == param_1) {
    if (param_3 == (RECT *)0x0) {
      return;
    }
    BVar1 = EqualRect(&local_24,param_3);
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
    FUN_004af4ae(local_128,0x104);
    FUN_004b55a5(*(undefined4 *)(param_1 + 0x1c),local_128);
  }
  uVar5 = *(undefined4 *)(param_2 + 100);
  uVar2 = CONCAT22((short)((uint)uVar5 >> 0x10),
                   CONCAT11(((byte)((uint)*(undefined4 *)(param_2 + 100) >> 8) ^
                            (byte)((uint)*(undefined4 *)(param_1 + 100) >> 8)) & 0xf0 ^
                            (byte)((uint)uVar5 >> 8),(char)uVar5));
  if (*(int *)(param_1 + 0x78) == 0) {
    uVar2 = uVar2 & 0xfffffffe | 0xf00;
  }
  else {
    uVar2 = uVar2 | 0xf01;
  }
  FUN_004c0a0d(uVar2);
  uVar5 = 0xffffffff;
  uVar2 = GetDlgCtrlID(*(HWND *)(param_2 + 0x1c));
  iVar3 = FUN_004ba69e(uVar2 & 0xffff,uVar5);
  if (0 < iVar3) {
    *(int *)(*(int *)(param_1 + 0x80) + iVar3 * 4) = param_2;
  }
  if (param_3 == (RECT *)0x0) {
    if (iVar3 < 1) {
      FUN_004ab49c(*(undefined4 *)(param_1 + 0x84),param_2);
      FUN_004ab49c(*(undefined4 *)(param_1 + 0x84),0);
    }
    uVar5 = 0x115;
    local_8 = 0;
    local_14._4_4_ = -DAT_005381a4;
    iVar3 = 0;
    local_14._0_4_ = -DAT_005381a0;
  }
  else {
    CopyRect((LPRECT)local_14,param_3);
    ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)local_14);
    ScreenToClient(*(HWND *)(param_1 + 0x1c),(LPPOINT)(local_14 + 8));
    if (iVar3 < 1) {
      FUN_004ba729(param_2,local_14._0_4_,local_14._4_4_,local_14._8_4_,local_8,
                   (int)(local_14._8_4_ - local_14._0_4_) / 2 + local_14._0_4_,
                   (local_8 - local_14._4_4_) / 2 + local_14._4_4_);
    }
    uVar5 = 0x114;
    local_8 = local_8 - local_14._4_4_;
    iVar3 = local_14._8_4_ - local_14._0_4_;
  }
  FUN_004af4dd(0,local_14._0_4_,local_14._4_4_,iVar3,local_8,uVar5);
  pHVar4 = GetParent(*(HWND *)(param_2 + 0x1c));
  iVar3 = FUN_004ac7ac(pHVar4);
  if (iVar3 != param_1) {
    if (param_1 == 0) {
      pHVar4 = (HWND)0x0;
    }
    else {
      pHVar4 = *(HWND *)(param_1 + 0x1c);
    }
    pHVar4 = SetParent(*(HWND *)(param_2 + 0x1c),pHVar4);
    FUN_004ac7ac(pHVar4);
  }
  if (*(int *)(param_2 + 0x70) != 0) {
    FUN_004b9fb2(param_2,0xffffffff,0);
  }
  *(int *)(param_2 + 0x70) = param_1;
  iVar3 = FUN_004bcdbe();
  *(uint *)(iVar3 + 0xb8) = *(uint *)(iVar3 + 0xb8) | 0xc;
  return;
}

