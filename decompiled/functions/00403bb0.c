
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00403bb0(void *this,int *param_1)

{
  int iVar1;
  HBITMAP pHVar2;
  HDC pHVar3;
  int iVar4;
  HGDIOBJ pvVar5;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;
  undefined **local_3c;
  uint local_38;
  undefined **local_34;
  undefined4 local_30;
  CDC local_2c [4];
  HDC local_28;
  RECT local_1c;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d1e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_00470000((undefined4 *)local_2c);
  local_38 = 0;
  local_3c = &PTR_FUN_00485520;
  local_30 = 0;
  local_34 = &PTR_FUN_00485520;
  local_4 = 2;
  DAT_004aaa1c = GetDeviceCaps((HDC)param_1[2],0xc);
  iVar1 = FUN_0047b918();
  DAT_004ac1d4 = *(undefined4 *)(iVar1 + 8);
  _DAT_004a3f84 = GetDeviceCaps((HDC)param_1[2],8);
  if (0x410 < _DAT_004a3f84) {
    _DAT_004a3f84 = 0x410;
  }
  DAT_004a763c = _DAT_004a3f84;
  DAT_004a3f04 = GetDeviceCaps((HDC)param_1[2],10);
  if (0x300 < DAT_004a3f04) {
    DAT_004a3f04 = 0x300;
  }
  if (DAT_004a763c < 0x321) {
    iVar1 = DAT_004a3f04 + -0x1e;
  }
  else {
    iVar1 = DAT_004a3f04 - DAT_004a3f04 / 0x14;
  }
  _DAT_004a8670 = (double)DAT_004a3f04 * _DAT_00484cb0;
  _DAT_004ab0c8 = (double)_DAT_004a3f84 * _DAT_00484cb8;
  DAT_004a72d0 = iVar1;
  pHVar2 = CreateBitmap(DAT_004a763c,iVar1,1,DAT_004aaa1c,(void *)0x0);
  FUN_00470a2d(&local_3c,(uint)pHVar2);
  if (param_1 == (int *)0x0) {
    pHVar3 = (HDC)0x0;
  }
  else {
    pHVar3 = (HDC)param_1[1];
  }
  pHVar3 = CreateCompatibleDC(pHVar3);
  FUN_004700ca(local_2c,(uint)pHVar3);
  iVar4 = FUN_00470205(local_28,(HGDIOBJ)(-(uint)(&stack0x00000000 != (undefined1 *)0x3c) & local_38
                                         ));
  if (DAT_004ac8f8 == 0) {
    FUN_00417790();
    FUN_0040f4a0(local_2c);
  }
  if (DAT_004ac8f8 == 1) {
    FUN_00417790();
    FUN_00413f00();
    DAT_004ac8f8 = 2;
  }
  if (0 < DAT_004ac93c) {
    FUN_0041c940((int *)local_2c);
    DAT_004ac97c = 1;
    if (DAT_004ac980 == 300) {
      FUN_0041bb40(local_2c);
    }
  }
  if (DAT_004ac93c != 0) goto LAB_00403ed6;
  if (((DAT_004ac938 == 1) && (DAT_004ac8f8 == 2)) && (DAT_004aa980 == 0)) {
    FUN_0041d890((int *)local_2c);
  }
  if (((((DAT_004ac980 == 0) || (DAT_004ac980 == 2)) || (DAT_004ac980 == 300)) &&
      ((1 < DAT_004ac8f8 && (DAT_004ac938 == 0)))) &&
     ((DAT_004aa980 == 0 && ((DAT_004ac970 == 0 && (DAT_004ac974 == 0)))))) {
    FUN_00404020(local_2c);
  }
  if (((0 < DAT_004ac8f8) && (DAT_004ac938 == 0)) && (DAT_004aa980 == 1)) {
    FUN_00407e40((int)local_2c,0,0,DAT_004a763c,DAT_004a72d0,0,3);
  }
  if (((0 < DAT_004ac8f8) && (DAT_004ac938 == 0)) && ((DAT_004ac970 == 1 && (DAT_004ac980 == 0)))) {
    FUN_00407e40((int)local_2c,0,0,DAT_004a763c,DAT_004a72d0,0,4);
  }
  if (((DAT_004ac8f8 < 1) || (DAT_004ac938 != 0)) || (DAT_004ac974 != 1)) {
LAB_00403ec1:
    bVar6 = DAT_004ac980 == 0;
  }
  else {
    bVar6 = false;
    if (DAT_004ac980 == 0) {
      FUN_00407e40((int)local_2c,0,0,DAT_004a763c,DAT_004a72d0,0,5);
      goto LAB_00403ec1;
    }
  }
  if (!bVar6 && -1 < DAT_004ac980) {
    FUN_0041bb40(local_2c);
  }
LAB_00403ed6:
  BitBlt((HDC)param_1[1],0,0,DAT_004a763c,iVar1,
         (HDC)(-(uint)(&stack0x00000000 != (undefined1 *)0x2c) & (uint)local_28),0,0,0xcc0020);
  if (iVar4 == 0) {
    pvVar5 = (HGDIOBJ)0x0;
  }
  else {
    pvVar5 = *(HGDIOBJ *)(iVar4 + 4);
  }
  FUN_00470205(local_28,pvVar5);
  FUN_00470a84((int)&local_3c);
  local_1c.top = 0;
  local_1c.left = 0;
  local_1c.right = DAT_004a763c;
  local_1c.bottom = DAT_004a72d0;
  if ((((DAT_004ac8fc == 0) && (0 < DAT_004ac8f8)) && (DAT_004ac938 == 0)) && (DAT_004ac97c == 0)) {
    InvalidateRect(*(HWND *)((int)this + 0x1c),&local_1c,0);
  }
  if ((DAT_004ac9a4 == 1) && (0 < DAT_004ac8f8)) {
    iVar1 = DAT_004a5ba0 - DAT_004a3f04 / 0x14;
    (**(code **)(*param_1 + 0x2c))(4);
    FUN_00423640((int)param_1,3,DAT_004a4f80,iVar1);
  }
  local_34 = &PTR_FUN_00487254;
  local_4._0_1_ = 3;
  FUN_00470a84((int)&local_34);
  local_3c = &PTR_FUN_00487254;
  local_34 = &PTR_FUN_00485d04;
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00470a84((int)&local_3c);
  local_3c = &PTR_FUN_00485d04;
  local_4 = 0xffffffff;
  FUN_00470132();
  *unaff_FS_OFFSET = uStack_c;
  return;
}

