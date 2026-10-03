
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00404510(int param_1,int param_2)

{
  int iVar1;
  HBITMAP pHVar2;
  HDC pHVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  int local_2c;
  uint local_28;
  RECT RStack_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c18c8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b46e0();
  local_4 = 2;
  DAT_0052362c = GetDeviceCaps(*(HDC *)(param_2 + 8),0xc);
  iVar1 = FUN_004bfff8();
  DAT_005359c8 = *(undefined4 *)(iVar1 + 8);
  _DAT_004f4084 = GetDeviceCaps(*(HDC *)(param_2 + 8),8);
  if (0x500 < _DAT_004f4084) {
    _DAT_004f4084 = 0x500;
  }
  DAT_004fe624 = _DAT_004f4084;
  DAT_004f3ff0 = GetDeviceCaps(*(HDC *)(param_2 + 8),10);
  if (0x300 < DAT_004f3ff0) {
    DAT_004f3ff0 = 0x300;
  }
  if (DAT_004fe624 < 0x321) {
    iVar1 = DAT_004f3ff0 + -0x1e;
  }
  else {
    iVar1 = DAT_004f3ff0 - DAT_004f3ff0 / 0x11;
  }
  _DAT_0050f6e0 = (double)DAT_004f3ff0 * _DAT_004cc3d8;
  _DAT_005259d0 = (double)_DAT_004f4084 * _DAT_004cc3e0;
  DAT_004fe2a8 = iVar1;
  pHVar2 = CreateBitmap(DAT_004fe624,iVar1,1,DAT_0052362c,(void *)0x0);
  FUN_004b510d(pHVar2);
  if (param_2 == 0) {
    pHVar3 = (HDC)0x0;
  }
  else {
    pHVar3 = *(HDC *)(param_2 + 4);
  }
  pHVar3 = CreateCompatibleDC(pHVar3);
  FUN_004b47aa(pHVar3);
  iVar4 = FUN_004b48e5(local_28,0);
  DAT_005364e8 = DAT_005364e8 + 1;
  if (0x3c < DAT_005364e8) {
    DAT_005364e8 = 1;
  }
  if (DAT_005363b0 == 0) {
    FUN_00420c00();
    FUN_0041be70();
    FUN_00413bc0(&local_2c);
  }
  if (DAT_005363b0 == 1) {
    if ((0 < DAT_005363fc) && (DAT_00536424 == 0)) {
      DAT_00536444 = 400;
    }
    FUN_00420c00();
    FUN_0041be70();
    DAT_005363b0 = 2;
  }
  if (0 < DAT_005363f4) {
    if (DAT_005233a8 == 0) {
      FUN_00428b70(&local_2c);
      DAT_005363b4 = 0;
    }
    else {
      FUN_00407ff0(&local_2c,0,0,DAT_004fe624,DAT_004fe2a8,0,3);
    }
    if (DAT_00536444 == 300) {
      FUN_00427f10(&local_2c);
    }
  }
  if (DAT_005363f4 != 0) goto LAB_004048a7;
  if (((DAT_005363f0 == 1) && (DAT_005363b0 == 2)) && (DAT_005233a8 == 0)) {
    FUN_004298f0(&local_2c);
  }
  if (((((DAT_00536444 == 0) || (DAT_00536444 == 2)) || (DAT_00536444 == 300)) &&
      ((1 < DAT_005363b0 && (DAT_005363f0 == 0)))) &&
     ((DAT_005233a8 == 0 && ((DAT_00536434 == 0 && (DAT_00536438 == 0)))))) {
    FUN_004049f0(&local_2c);
  }
  if (((0 < DAT_005363b0) && (DAT_005363f0 == 0)) && (DAT_005233a8 == 1)) {
    FUN_00407ff0(&local_2c,0,0,DAT_004fe624,DAT_004fe2a8,0,3);
  }
  if (((0 < DAT_005363b0) && (DAT_005363f0 == 0)) && ((DAT_00536434 == 1 && (DAT_00536444 == 0)))) {
    FUN_00407ff0(&local_2c,0,0,DAT_004fe624,DAT_004fe2a8,0,4);
  }
  if (((DAT_005363b0 < 1) || (DAT_005363f0 != 0)) || (DAT_00536438 != 1)) {
LAB_00404892:
    bVar6 = DAT_00536444 == 0;
  }
  else {
    bVar6 = false;
    if (DAT_00536444 == 0) {
      FUN_00407ff0(&local_2c,0,0,DAT_004fe624,DAT_004fe2a8,0,5);
      goto LAB_00404892;
    }
  }
  if (!bVar6 && -1 < DAT_00536444) {
    FUN_00427f10(&local_2c);
  }
LAB_004048a7:
  BitBlt(*(HDC *)(param_2 + 4),0,0,DAT_004fe624,iVar1,
         (HDC)(-(uint)(&stack0x00000000 != (undefined1 *)0x2c) & local_28),0,0,0xcc0020);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(iVar4 + 4);
  }
  FUN_004b48e5(local_28,uVar5);
  FUN_004b5164();
  RStack_1c.bottom = DAT_004fe2a8;
  RStack_1c.top = 0;
  RStack_1c.left = 0;
  RStack_1c.right = DAT_004fe624;
  if ((((DAT_005363b4 == 0) && (0 < DAT_005363b0)) && (DAT_005363f0 == 0)) && (DAT_00536440 == 0)) {
    InvalidateRect(*(HWND *)(param_1 + 0x1c),&RStack_1c,0);
  }
  if (DAT_005364fc == 1) {
    InvalidateRect(*(HWND *)(param_1 + 0x1c),(RECT *)0x0,0);
  }
  local_4._0_1_ = 3;
  FUN_004b5164();
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_004b5164();
  local_4 = 0xffffffff;
  FUN_004b4812();
  *unaff_FS_OFFSET = uStack_c;
  return;
}

