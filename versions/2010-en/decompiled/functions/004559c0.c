
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004559c0(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  Tact2010CString local_28 [2];
  int local_20;
  int iStack_1c;
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4970;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  iVar5 = 0x14;
  if (DAT_004fe624 < 700) {
    iVar5 = 0x10;
    local_20 = 0x16;
    local_28[0].data = &DAT_00000005;
  }
  else {
    local_20 = 0x1b;
    local_28[0].data = (char *)0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___DEATH_BY_LAYLINE___004e7570);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,(int)local_28[0].data,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_20 + 2;
  if ((DAT_004fb9b4 == 0) || (DAT_004fb9b4 == 3)) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_With_any_windshift__a_boat_on_a_l_004e7514);
    uStack_4 = 1;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boats_A_and_B_are_initially_even_004e74e0);
    uStack_4 = 2;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + iVar5;
    FUN_004b0613((Tact2010CString *)&param_1,s_However__boat_A_is_actually_clos_004e74b0);
    uStack_4 = 3;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    if (DAT_004fb9b4 == 0) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e7478);
      uStack_4 = 4;
      (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004fb9b4 == 3) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff00ff);
      FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e743c);
      uStack_4 = 5;
      (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
  }
  if ((DAT_004fb9b4 == 1) || (DAT_004fb9b4 == 2)) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_With_this_lift__Boat_A_can_sail_d_004e7404);
    uStack_4 = 6;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_Since_boat_A_is_actually_closer_t_004e73bc);
    uStack_4 = 7;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4 + iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + iVar5 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_B_is_now_overstanding_and_h_004e737c);
    uStack_4 = 8;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 9;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if ((DAT_004fb9b4 == 4) || (DAT_004fb9b4 == 5)) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_With_this_header__Boat_A_can_tac_004e7348);
    uStack_4 = 10;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 6) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_can_tack_back__consolidat_004e7300);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 7) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_can_now_stay_ahead_with_a_004e72d0);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e729c);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 8) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Despite_the_wind_shift_disadvant_004e7240);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_where_it_pays_to_sail_to_or_even_004e71f0);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4 + iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + iVar5 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_1__If_you_are_fairly_near_the_ma_004e7198);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + iVar5;
    FUN_004b0613((Tact2010CString *)&param_1,s_worthwile_to_gamble_that_there_w_004e7160);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = iVar4 + local_20;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_2__In_light_air__the_wind_could_b_004e7108);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_or_beyond_the_layline__However__i_004e70b0);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar5 + iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  FUN_00463df0(original_dc,(int)local_28[0].data,iVar5);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_00456197;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00456197;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00456197:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 8;
  FUN_00463c90(original_dc,iVar5);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  dVar3 = _DAT_004ccc30;
  if ((DAT_004fb9b4 != 2) && (DAT_004fb9b4 != 8)) {
    dVar3 = _DAT_004cc5e0;
  }
  local_20 = (int)(longlong)(_DAT_005230b0 * dVar3);
  iStack_1c = iVar4;
  FUN_0043faa0(original_dc,iVar4,local_20,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + iVar4,local_20,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if ((DAT_004fb9b4 == 0) || (DAT_004fb9b4 == 3)) {
    DAT_005362d4 = 0;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,local_20);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc570);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    CDC::LineTo(original_dc,(int)param_1,iVar4);
    FUN_004b0613(local_28,"LayLine");
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,(int)param_1,iVar4 + iVar5 * -2,local_28[0].data,
              *(int *)(local_28[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(local_28);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,local_20);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc6b0);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    CDC::LineTo(original_dc,iVar4,(int)param_1);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)(param_1 + -iVar5),aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    aTStack_18[0].data = *(char **)(*original_dc + 0x38);
    (*(code *)aTStack_18[0].data)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,(int *)local_28,0,iVar4);
    CDC::LineTo(original_dc,DAT_004fe624,iVar4);
    (*(code *)aTStack_18[0].data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,(int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2,iVar4,
              (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)aTStack_18[0].data)(original_dc,0);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc6b0);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    dVar3 = _DAT_004cc668;
    if (DAT_004fb9b4 == 0) {
      dVar3 = _DAT_004cc738;
    }
    iVar4 = (int)(longlong)(_DAT_005230e8 * dVar3);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0].data = (char *)(DAT_004fe624 / 0xe);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_005362d4 = 0xffffffec;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    iVar4 = local_20;
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,local_20);
    CDC::LineTo(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc8b0),
                (int)(longlong)(_DAT_005230b0 * _DAT_004cc600));
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,iVar4);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    CDC::LineTo(original_dc,iVar4,(int)param_1);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)(param_1 + -iVar5),aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    (**(code **)(*original_dc + 0x38))(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6b0);
    iVar4 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 0xc;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x145;
    DAT_004feccc = 0x41;
    FUN_00417aa0(original_dc,param_1,iVar4,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B:");
    local_28[0].data = (int)param_1 - local_28[0].data;
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b0613((Tact2010CString *)&param_1,"Overstanding");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,(int)local_28[0].data,iVar4 + iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    DAT_00522ff8 = 1;
    local_28[0].data = (char *)(DAT_004fe624 / 0xe);
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x14f;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if ((DAT_004fb9b4 == 2) || (DAT_004fb9b4 == 8)) {
    DAT_005362d4 = 0xffffffec;
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 0xc;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x14a;
    DAT_004feccc = 0x41;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    if (DAT_004fb9b4 == 2) {
      FUN_004b0613(aTStack_18,"Boat B");
      uStack_4 = 0x20;
      (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1,aTStack_18[0].data,
                *(int *)(aTStack_18[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_18);
    }
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc668);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    local_28[0].data = (char *)(DAT_004fe624 / 0xe);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xf;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x14f;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    if (DAT_004fb9b4 == 2) {
      FUN_004b0613(aTStack_18,"Boat A");
      uStack_4 = 0x21;
      (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
                *(int *)(aTStack_18[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_18);
    }
  }
  if ((DAT_004fb9b4 == 4) || (DAT_004fb9b4 == 5)) {
    DAT_005362d4 = 0x1e;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    iVar4 = local_20;
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,local_20);
    CDC::LineTo(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc570),
                (int)(longlong)(_DAT_005230b0 * _DAT_004cc6b0));
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iStack_1c,iVar4);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc6b0);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    CDC::LineTo(original_dc,iVar4,(int)param_1);
    local_28[0].data = (char *)(DAT_004fe624 / 6);
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5 * -5,aTStack_18[0].data
              ,*(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    pcVar2 = *(code **)(*original_dc + 0x38);
    (*pcVar2)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)(longlong)(_DAT_005230e8 * _DAT_004cc6b0),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc668));
    CDC::LineTo(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc668),
                (int)(longlong)(_DAT_005230b0 * _DAT_004cc600));
    (*pcVar2)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 3,(int)(longlong)(_DAT_005230b0 * _DAT_004cc668),
              (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*pcVar2)(original_dc,0);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc6b0);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x127;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc668);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    local_28[0].data = (char *)(DAT_004fe624 / 0xe);
    if (DAT_004fb9b4 == 4) {
      DAT_00522ff8 = 1;
      DAT_00535748 = 0x127;
    }
    else {
      DAT_00522ff8 = 0xffffffff;
      DAT_00535748 = 0x19;
    }
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if ((DAT_004fb9b4 == 6) || (DAT_004fb9b4 == 7)) {
    DAT_005362d4 = 0x1e;
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc738);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    local_28[0].data = (char *)(DAT_004fe624 / 0xe);
    if (DAT_004fb9b4 == 7) {
      DAT_00522ff8 = 1;
      DAT_00535748 = 0x127;
    }
    else {
      DAT_00522ff8 = 0xffffffff;
      DAT_00535748 = 0x19;
    }
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0xf;
    DAT_004fb388 = 0xf;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    iVar4 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    param_1 = (int *)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    local_28[0].data = (char *)(DAT_004fe624 / 10);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xf;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x127;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,iVar4,param_1,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,iVar4 - (int)local_28[0].data,(int)param_1 + iVar5,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_004f71c4 = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

