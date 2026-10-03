
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044f5c0(int *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_18;
  int local_14;
  Tact2010CString local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4258;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    iVar5 = 0x10;
    local_14 = 0x16;
    local_18 = 0x10;
    local_10.data = &DAT_00000005;
  }
  else {
    local_14 = 0x1b;
    local_18 = 0x14;
    local_10.data = (char *)0x14;
    iVar5 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Same_tack__starting__A_windward_b_004e51a0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,5,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_L_and_L2_may_turn_toward_the_win_004e5140);
  uStack_4 = 1;
  (*pcVar1)(original_dc,5,local_14 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_14 + 2 + iVar5;
  FUN_004b0613((Tact2010CString *)&param_1,s_room_and_time_to_keep_clear__Rul_004e50e4);
  uStack_4 = 2;
  (*pcVar1)(original_dc,5,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar5;
  FUN_004b0613((Tact2010CString *)&param_1,s__004e50d8);
  uStack_4 = 3;
  (*pcVar1)(original_dc,5,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "Before the starting signal there is no proper course, so a leeward boat may luff to head to wind."
              );
  uStack_4 = 4;
  (*pcVar1)(original_dc,5,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar5;
  FUN_004b0613((Tact2010CString *)&param_1,s_After_the_starting_signal__a_lee_004e501c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,5,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_sail_above_her_proper_course__Ru_004e4fec);
  uStack_4 = 6;
  (*pcVar1)(original_dc,5,iVar5 + iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_00463df0(original_dc,(int)local_10.data,iVar5);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0044f862;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0044f862;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0044f862:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  uVar3 = DAT_004f71c4;
  DAT_00536458 = 2;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  DAT_004da18c = 1;
  FUN_00463c90(original_dc,iVar5);
  FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc618),
               (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),3,1);
  FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc7b8),
               (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),0,1,DAT_004fe2a8,0);
  if (DAT_004fb9b4 == 0) {
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    param_1 = (int *)(DAT_004fe624 / 0x14);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 9;
    _DAT_004fe81c = 0x28;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x10e;
    DAT_004feccc = 0x5a;
    FUN_00417aa0(original_dc,iVar5,iVar4,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_10,s_Boat_W_004e4d04);
    uStack_4 = 7;
    (*pcVar1)(original_dc,(int)param_1 + iVar5,iVar4 - local_18,local_10.data,
              *(int *)(local_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_10);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    local_10.data = (char *)(longlong)(_DAT_005230b0 * _DAT_004cc620);
    iVar4 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 0xfU);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 9;
    _DAT_004fe820 = 0x28;
    DAT_004fdff0 = 0x14;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x10e;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,iVar5,local_10.data,2,1,DAT_004fe2a8,0);
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_L_004e4fe4);
    uStack_4 = 8;
    (*pcVar1)(original_dc,iVar5 - (iVar4 >> 4),(int)(local_10.data + local_18 + 4),(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    param_1 = (int *)(DAT_004fe624 / 7);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 5;
    _DAT_004fe824 = 0x32;
    _DAT_004fdff4 = 0x14;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x10e;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,iVar5,iVar4,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_10,s_Boat_W2_004e4fdc);
    uStack_4 = 9;
    (*pcVar1)(original_dc,iVar5 - (int)param_1,(iVar4 - local_18) + -4,local_10.data,
              *(int *)(local_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_10);
    iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc620);
    _DAT_00523008 = 1;
    param_1 = (int *)(DAT_004fe624 / 0x19);
    _DAT_004fc2d8 = 0xf;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x10e;
    _DAT_004fece0 = 0x2d;
    FUN_00417aa0(original_dc,iVar5,iVar4,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&local_10,s_Boat_L2_004e4fd4);
    uStack_4 = 10;
    (*pcVar1)(original_dc,(int)param_1 + iVar5,DAT_004fe2a8 / 0x46 + iVar4,local_10.data,
              *(int *)(local_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_10);
  }
  else {
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x32;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x145;
    DAT_004feccc = 0x23;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc518),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc820),1,1,DAT_004fe2a8,0);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x32;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc5f0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),2,1,DAT_004fe2a8,0);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xf;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x14;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x145;
    _DAT_004fecd4 = 0x23;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc738),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc820),3,1,DAT_004fe2a8,0);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 0xf;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x13b;
    _DAT_004fece0 = 0x2d;
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc20),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc820),6,1,DAT_004fe2a8,0);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_005350dc = 0;
  DAT_004f71c4 = uVar3;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

