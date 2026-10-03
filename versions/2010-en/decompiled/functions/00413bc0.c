
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00413bc0(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  double dVar3;
  int *original_dc;
  DWORD DVar4;
  Tact2010CString *pTVar5;
  DWORD DVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  int iVar10;
  HGDIOBJ h;
  Tact2010CString TStack_20;
  Tact2010CString TStack_1c;
  Tact2010CString TStack_18;
  code *pcStack_14;
  DWORD DStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar8 = DAT_0053646c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c27f0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004da214 = (-(uint)(iVar8 != 1) & 2) - 1;
  if (DAT_005364fc == 1) {
    DAT_004da1f8 = 999;
    DAT_00536410 = 0;
    DAT_00536414 = 0;
    DAT_00536438 = 0;
    DAT_00536434 = 0;
    FUN_0042c060();
    FUN_00407ff0(param_1,0,0,DAT_004fe624,DAT_004fe2a8,1,3);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  iVar8 = *param_1;
  (**(code **)(iVar8 + 0x34))(param_1,0xffffff);
  DStack_10 = GetTickCount();
  if (DAT_004da1f8 == 5) {
    DAT_004da188 = 3;
  }
  FUN_0041e000(100);
  _DAT_005230e8 = (double)DAT_004fe624;
  _DAT_005230b0 = (double)DAT_004fe2a8;
  param_1 = (int *)(DAT_004fe624 / 10);
  pcVar1 = *(code **)(iVar8 + 0x2c);
  uVar7 = (699 < DAT_004fe624) - 1 & 0xfffffff6;
  pcStack_14 = pcVar1;
  (*pcVar1)(original_dc,7);
  (*pcVar1)(original_dc,0);
  Rectangle((HDC)original_dc[1],0,0,DAT_004fe624,DAT_004fe2a8);
  if ((0 < DAT_004da16c) && (DAT_0053648c == 0)) {
    FUN_00416910(original_dc);
    *unaff_FS_OFFSET = uStack_c;
    return;
  }
  pcVar1 = *(code **)(iVar8 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar10 = 0xff;
  }
  else {
    iVar10 = 0;
  }
  (*pcVar1)(original_dc,iVar10);
  FUN_004b0613(&TStack_20,s_Select_Options__Then_select__Sta_004db828);
  pcVar2 = *(code **)(iVar8 + 100);
  uStack_4 = 0;
  (*pcVar2)(original_dc,5,1,TStack_20.data,*(int *)(TStack_20.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_20);
  iVar8 = uVar7 + 0x28;
  if (DAT_005363e4 == 0) {
    (*pcVar1)(original_dc,0x7f0000);
  }
  iVar10 = GetSystemMetrics(0xf);
  DAT_004f82fc = iVar10;
  FUN_004b0613(&TStack_18,s_SAILING_TACTICS_SIMULATOR_004db80c);
  uStack_4 = 1;
  (*pcVar2)(original_dc,(int)param_1,iVar8,TStack_18.data,*(int *)(TStack_18.data + -8));
  if (DAT_004fe624 < 0x385) {
    if (699 < DAT_004fe624) {
      if (iVar10 < 0x15) {
        TStack_20.data = (char *)((int)param_1 + 0xd2);
      }
      else {
        TStack_20.data = (char *)((int)param_1 + 0x10e);
      }
    }
    if (900 < DAT_004fe624) goto LAB_00413e16;
  }
  else {
LAB_00413e16:
    if (iVar10 < 0x15) {
      TStack_20.data = (char *)(param_1 + 0x32);
    }
    else {
      TStack_20.data = (char *)(param_1 + 0x41);
    }
  }
  if (DAT_004fe624 < 700) {
    TStack_20.data = (char *)((int)param_1 + 0xe6);
  }
  FUN_004b0613(&TStack_1c,&DAT_004db808);
  uStack_4._0_1_ = 2;
  (*pcVar2)(original_dc,(int)(TStack_20.data + 2),iVar8 - DAT_004fe2a8 / 100,TStack_1c.data,
            *(int *)(TStack_1c.data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5(&TStack_1c);
  if (DAT_005363e4 == 0) {
    (*pcVar1)(original_dc,0x7f0000);
  }
  if (DAT_004da16c == 0) {
    FUN_004b0613(&TStack_1c,s_2010_Rel__7J__Japanese__Yokota__004db7e4);
    uStack_4._0_1_ = 3;
    (*pcVar2)(original_dc,(int)param_1,uVar7 + 0x37,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  }
  else {
    FUN_004b0613(&TStack_1c,s_2010_Edition_Rel_7J_Demo__Japane_004db7b8);
    uStack_4._0_1_ = 4;
    (*pcVar2)(original_dc,(int)param_1,uVar7 + 0x37,TStack_1c.data,*(int *)(TStack_1c.data + -8));
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5(&TStack_1c);
  if (DAT_005363e4 == 0) {
    (*pcVar1)(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Copyright_C__1998_2009_by_C__Den_004db78c);
  uStack_4._0_1_ = 5;
  (*pcVar2)(original_dc,(DAT_004fe624 * 9) / 0x14,iVar8,(char *)param_1,param_1[-2]);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5((Tact2010CString *)&param_1);
  param_1 = (int *)(DAT_004fe2a8 / 0xe);
  piVar9 = param_1;
  if (DAT_004fe624 < 900) {
    piVar9 = (int *)(DAT_004fe2a8 / 0xd);
  }
  if (DAT_004fc15c != (HGDIOBJ)0x0) {
    SelectObject((HDC)original_dc[1],DAT_004fc15c);
  }
  if (DAT_004fb994 != (HGDIOBJ)0x0) {
    SelectObject((HDC)original_dc[1],DAT_004fb994);
  }
  FUN_00433a70(original_dc,piVar9,((int)piVar9 / 10 - ((int)piVar9 * 3) / 2) + DAT_004fe624,
               ((int)((int)piVar9 + ((int)piVar9 >> 0x1f & 3U)) >> 2) + iVar8);
  (*pcVar1)(original_dc,0xffff00);
  FUN_004b4a1f(original_dc,1);
  if (DAT_004fe624 < 900) {
    FUN_004b0613(&TStack_1c,s_Distortion___004db77c);
    uStack_4._0_1_ = 6;
    (*pcVar2)(original_dc,((int)piVar9 / 5 - ((int)piVar9 * 5) / 2) + DAT_004fe624,iVar8,
              TStack_1c.data,*(int *)(TStack_1c.data + -8));
  }
  else {
    FUN_004b0613(&TStack_1c,s_Distortion___004db77c);
    uStack_4._0_1_ = 7;
    (*pcVar2)(original_dc,((int)piVar9 / 3 - ((int)piVar9 * 5) / 2) + DAT_004fe624,iVar8,
              TStack_1c.data,*(int *)(TStack_1c.data + -8));
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5(&TStack_1c);
  FUN_004b4a1f(original_dc,2);
  if (DAT_004da1f0 == 1) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Apollo_004db774);
  }
  if (DAT_004da1f0 == 2) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Apple_004db76c);
  }
  if (DAT_004da1f0 == 3) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db764);
  }
  if (DAT_004da1f0 == 4) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db75c);
  }
  if (DAT_004da1f0 == 5) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Flame_004db754);
  }
  if (DAT_004da1f0 == 6) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db750);
  }
  if (DAT_004da1f0 == 7) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Hot_Flash_004db744);
  }
  if (DAT_004da1f0 == 8) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Hotrod_004db73c);
  }
  if (DAT_004da1f0 == 9) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Red_Dog_004db734);
  }
  if (DAT_004da1f0 == 10) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Robin_004db72c);
  }
  if (DAT_004da1f0 == 0xb) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db724);
  }
  if (DAT_004da1f0 == 0xc) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Rover_004db71c);
  }
  if (DAT_004da1f0 == 0xe) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Sunrise_004db714);
  }
  if (DAT_004da1f0 == 0xf) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Thunder_004db70c);
  }
  if (DAT_004da1f0 == 0xd) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Scarlett_004db700);
  }
  iVar8 = DAT_004fe2a8 * 3;
  (*pcVar1)(original_dc,0);
  if (DAT_00536534 == 1) {
    FUN_004b0613(&TStack_1c,s_1_SLOW_004db6f4);
    uStack_4._0_1_ = 8;
    (*pcVar2)(original_dc,5,((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + -100,TStack_1c.data,
              *(int *)(TStack_1c.data + -8));
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    FUN_004b05a5(&TStack_1c);
  }
  iVar8 = ((int)(DAT_004fe2a8 * 3 + (DAT_004fe2a8 * 3 >> 0x1f & 3U)) >> 2) + -0x14;
  if (DAT_005363e4 == 0) {
    iVar10 = 0xff;
  }
  else {
    iVar10 = 0;
  }
  (*pcVar1)(original_dc,iVar10);
  if (DAT_004da140 == 1) {
    pTVar5 = FUN_004b082f(&TStack_1c,s_Your_boat_name__004db6e0,(Tact2010CString *)&DAT_004fec34);
    piVar9 = param_1;
    uStack_4._0_1_ = 9;
    (*pcVar2)(original_dc,5,(iVar8 - (int)param_1) + -5,pTVar5->data,*(int *)(pTVar5->data + -8));
    pTVar5 = &TStack_1c;
  }
  else {
    pTVar5 = FUN_004b082f(&TStack_1c,s_Player_1_boat_name__004db6c8,(Tact2010CString *)&DAT_004fec34
                         );
    piVar9 = param_1;
    uStack_4._0_1_ = 10;
    iVar8 = (iVar8 - (int)param_1) + -5;
    (*pcVar2)(original_dc,5,iVar8,pTVar5->data,*(int *)(pTVar5->data + -8));
    uStack_4._0_1_ = 1;
    FUN_004b05a5(&TStack_1c);
    (*pcVar1)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,s_Player_Two_Boat_Name__Bear_004db6ac);
    uStack_4._0_1_ = 0xb;
    (*pcVar2)(original_dc,DAT_004fe624 / 3,iVar8,(char *)param_1,param_1[-2]);
    pTVar5 = (Tact2010CString *)&param_1;
  }
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5(pTVar5);
  if ((DAT_004da190 == 7) && (DAT_005364c8 == 0)) {
    DAT_004da1fc = (DAT_004faa48 + -0x14) / 10 + 6;
  }
  else {
    DAT_004da1fc = 6;
  }
  if ((DAT_004da190 < 6) || (DAT_005363b8 == 1)) {
    DAT_004da1fc = 4;
  }
  if (DAT_004da190 == 8) {
    DAT_004da1fc = 10;
  }
  if (DAT_00513478 == 1) {
    DAT_004da1fc = 5;
  }
  if (DAT_005363c0 == 2) {
    DAT_004da1fc = 6;
  }
  if (DAT_005363c0 == 3) {
    DAT_004da1fc = 7;
  }
  if ((DAT_004fb410 == 1) || (DAT_00536528 == 1)) {
    DAT_004da1fc = 4;
  }
  FUN_004148f0(original_dc,((DAT_004fe2a8 * 4) / 5 - (int)piVar9) + -0x28);
  dVar3 = _DAT_0050f6e0 * _DAT_004cc5d0;
  iVar8 = DAT_004fe2a8 * 3;
  iVar10 = DAT_004fe624 * 9;
  if ((DAT_005363e4 == 0) && (DAT_00536454 == 0)) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00414545;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00414545;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00414545:
  RoundRect((HDC)original_dc[1],DAT_004fe624 / 10,DAT_004fe2a8 / 5 - (int)piVar9,iVar10 / 10,
            (((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) - (int)(longlong)dVar3) - (int)piVar9,0x50,
            0x50);
  if (DAT_004fe624 < 1000) {
    iVar8 = (DAT_004fe2a8 * 4) / 5 + -0xf;
  }
  else {
    iVar8 = (DAT_004fe2a8 * 4) / 5 + 10;
  }
  if (DAT_004da1f8 == 999) {
    if (DAT_005363e4 == 0) {
      (*pcStack_14)(original_dc,7);
      if (DAT_004fc15c != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004fc15c);
      }
      Rectangle((HDC)original_dc[1],0,iVar8 + -5,DAT_004fe624,DAT_004fe2a8);
    }
    FUN_004b4a1f(original_dc,1);
    FUN_0048cf50(original_dc,iVar8);
    FUN_004b4a1f(original_dc,2);
  }
  DAT_00536458 = 1;
  pcStack_14 = (code *)DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  iVar8 = -(int)piVar9;
  FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5e0),
               iVar8 - (int)(longlong)(_DAT_005230b0 * _DAT_004cc5d8),4,1);
  DAT_00522ff4 = 1;
  DAT_004fc2c4 = 0xf;
  _DAT_004fe81c = 2;
  DAT_004fdfec = 0x3c;
  DAT_004fb384 = 0xf;
  DAT_00535744 = 0x13b;
  DAT_004feccc = 0x2d;
  DAT_005350dc = 0;
  DAT_00535624 = 0xfffffc18;
  if (DAT_0053652c == 1) {
    DAT_004fc2c4 = 8;
  }
  FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8),
               iVar8 - (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e8),1,1,DAT_004fe2a8,0);
  DAT_00522ff8 = 0xffffffff;
  _DAT_004fc2c8 = 0xf;
  _DAT_004fe820 = 2;
  DAT_004fdff0 = 0x3c;
  DAT_004fb388 = 0xf;
  DAT_00535748 = 0x2d;
  DAT_004fecd0 = 0x2d;
  DAT_005350e0 = 0;
  DAT_00535628 = 0xfffffc18;
  if (DAT_0053652c == 1) {
    _DAT_004fc2c8 = 8;
  }
  FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0),
               iVar8 - (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e8),2,1,DAT_004fe2a8,0);
  if (2 < DAT_004da194) {
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    DAT_005350e4 = 0;
    _DAT_0053562c = 0xfffffc18;
    if (DAT_0053652c == 1) {
      _DAT_004fc2cc = 8;
    }
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc600),
                 iVar8 - (int)(longlong)(_DAT_005230b0 * _DAT_004cc5f8),3,1,DAT_004fe2a8,0);
  }
  DAT_00536458 = 0;
  DAT_004f71c4 = pcStack_14;
  DVar6 = GetTickCount();
  DVar4 = DStack_10;
  uVar7 = DVar6 - DStack_10;
  while (uVar7 < 0x50) {
    DVar6 = GetTickCount();
    uVar7 = DVar6 - DVar4;
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_18);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

