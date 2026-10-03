
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045df40(int *param_1)

{
  code *pcVar1;
  int iVar2;
  double dVar3;
  int *original_dc;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_1c;
  int local_18;
  Tact2010CString TStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_005230b0 * _DAT_004cc5e0;
  pcStack_8 = FUN_004c5250;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar3;
  if (DAT_004fe624 < 700) {
    iVar5 = 0x10;
    local_18 = 0x16;
    local_1c = 5;
  }
  else {
    iVar5 = 0x14;
    local_18 = 0x1b;
    local_1c = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___STARTING___004ea544);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_1c,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  param_1 = (int *)(iVar5 + 2);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fb9b4 == 0) {
    FUN_004b0613(&TStack_14,s_Starting_Objectives__in_usual_or_004ea510);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_1__Freedom_to_tack_if_the_wind_i_004ea4b4);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_Start_left_of_the_pack_if_the_le_004ea46c);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_2__Clear_air__004ea45c);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_3__Start_where_you_are_upwind_of_004ea428);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_4__Start_where_you_can_bail_out_i_004ea3f4);
    uStack_4 = 6;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(&TStack_14,s_If_you_have_really_good_boat_spe_004ea3b0);
    uStack_4 = 7;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0);
    }
    FUN_004b0613(&TStack_14,s_If_you_have_poor_boat_speed__obj_004ea354);
    uStack_4 = 8;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_weather_end_to_have_freedom_to_t_004ea2f4);
    uStack_4 = 9;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
  }
  if (DAT_004fb9b4 == 1) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_In_this_start__the_line_is_perpe_004ea2a8);
    uStack_4 = 10;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_If_the_wind_is_oscillating_or_th_004ea248);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_If_the_left_side_becomes_favored_004ea208);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_If_Boat_C_has_a_sight_from_the_p_004ea1ac);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_since_boats_in_the_middle_of_the_004ea164);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_To_have_clear_air__start_close_t_004ea100);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 2) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_Another_start__This_time_the_pin_004ea0d0);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 3) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_Another_start__This_time_the_pin_004ea0d0);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Boat_A_has_a_lead__She_may_be_th_004ea07c);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_pinching_to_avoid_bad_air__004ea060);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_If_the_left_side_of_the_course_b_004ea014);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_If_the_wind_is_oscillating__Boat_004e9fb8);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_If_Boat_E_tacks_first__and_the_r_004e9f54);
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 4) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_Another_start__This_time_the_Com_004e9f18);
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 5) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_Another_start__This_time_the_Com_004e9f18);
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Boat_D_has_the_lead__clear_air__a_004e9ed8);
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_If_the_left_side_of_the_course_b_004e9e78);
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_favored__A_is_in_a_very_bad_posi_004e9e50);
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + local_18);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Boat_E_is_in_bad_air_but_can_tac_004e9df8);
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)((int)param_1 + iVar5);
    FUN_004b0613(&TStack_14,s_and_an_excellent_position_if_the_004e9dac);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,local_1c,(int)param_1,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  FUN_00463df0(original_dc,local_1c,iVar5);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0045e9c8;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0045e9c8;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0045e9c8:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 5;
  FUN_00463c90(original_dc,iVar5);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 3;
  DAT_004fbb94 = 0;
  if (DAT_004fb9b4 < 2) {
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc618),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),3,1);
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc48),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004cc738),0,1,DAT_004fe2a8,0);
  }
  if ((DAT_004fb9b4 == 2) || (DAT_004fb9b4 == 3)) {
    DAT_005362d4 = 0x14;
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc618),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc50),3,1);
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc48),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc58),0,1,DAT_004fe2a8,0);
  }
  if ((DAT_004fb9b4 == 4) || (DAT_004fb9b4 == 5)) {
    DAT_005362d4 = 0x14a;
    FUN_0043faa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004cc958),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc58),3,1);
    FUN_00417aa0(original_dc,(int)(longlong)(_DAT_005230e8 * _DAT_004ccc60),
                 (int)(longlong)(_DAT_005230b0 * _DAT_004ccc50),0,1,DAT_004fe2a8,0);
  }
  if (DAT_004fb9b4 == 0) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x14;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x10e;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc668);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 5;
    _DAT_004fe824 = 0x1e;
    _DAT_004fdff4 = 0x1e;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 300;
    _DAT_004fecd4 = 0x3c;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 10;
    _DAT_004fe830 = 0x28;
    _DAT_004fe000 = 0x1e;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x122;
    _DAT_004fece0 = 0x46;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc68);
    iVar4 = DAT_004fe624 / 0xf;
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 5;
    _DAT_004fe834 = 0x28;
    _DAT_004fe004 = 0x14;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 300;
    _DAT_004fece0 = 0x41;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,(int)param_1 - iVar4,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 1) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6d8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xc;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 0xc;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x13b;
    _DAT_004fece0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 0xc;
    _DAT_004fe834 = 2;
    _DAT_004fe004 = 0x3c;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 0x13b;
    _DAT_004fece4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 2) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc5f0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbe0);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x28;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x10e;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x29;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc668);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 5;
    _DAT_004fe824 = 0x1e;
    _DAT_004fdff4 = 0x1e;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 300;
    _DAT_004fecd4 = 0x3c;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x2a;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc70);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 10;
    _DAT_004fe830 = 0x28;
    _DAT_004fe000 = 0x1e;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x122;
    _DAT_004fece0 = 0x46;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x2b;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc40);
    iVar4 = DAT_004fe624 + (DAT_004fe624 >> 0x1f & 0xfU);
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 5;
    _DAT_004fe834 = 0x28;
    _DAT_004fe004 = 0x14;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 300;
    _DAT_004fece4 = 0x41;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x2c;
    (*pcVar1)(original_dc,(int)param_1 - (iVar4 >> 4),
              iVar2 - (int)(longlong)(_DAT_005230b0 * _DAT_004cc8a0),TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 3) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6d8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc78);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x2d;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x2e;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc00);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xc;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x2f;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc508);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc620);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 0xc;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x13b;
    _DAT_004fece0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x30;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc68);
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 0xc;
    _DAT_004fe834 = 2;
    _DAT_004fe004 = 0x3c;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 0x13b;
    _DAT_004fece4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x31;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 4) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc518);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x32;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc608);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x10e;
    DAT_004fecd0 = 0x5a;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x33;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccc70);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 5;
    _DAT_004fe824 = 0x1e;
    _DAT_004fdff4 = 0x1e;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 300;
    _DAT_004fecd4 = 0x3c;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x34;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc6c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc620);
    iVar4 = DAT_004fe624 / 0x19;
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 10;
    _DAT_004fe830 = 0x28;
    _DAT_004fe000 = 0x1e;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x122;
    _DAT_004fece0 = 0x46;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x35;
    (*pcVar1)(original_dc,(int)param_1 - iVar4,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc940);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc7e0);
    iVar4 = DAT_004fe624 / 0x19;
    _DAT_004fe004 = 0x3c;
    _DAT_004fece4 = 0x3c;
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 0xc;
    _DAT_004fe834 = 10;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 300;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x36;
    (*pcVar1)(original_dc,(int)param_1 - iVar4,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004fb9b4 == 5) {
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc660);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0xc;
    _DAT_004fe81c = 2;
    DAT_004fdfec = 0x14;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x13b;
    DAT_004feccc = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat A");
    uStack_4 = 0x37;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc770);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbd0);
    DAT_00522ff8 = 1;
    _DAT_004fc2c8 = 0xc;
    _DAT_004fe820 = 2;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat B");
    uStack_4 = 0x38;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc668);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    _DAT_00522ffc = 1;
    _DAT_004fc2cc = 0xc;
    _DAT_004fe824 = 2;
    _DAT_004fdff4 = 0x3c;
    _DAT_004fb38c = 0xf;
    _DAT_0053574c = 0x13b;
    _DAT_004fecd4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,3,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat C");
    uStack_4 = 0x39;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc600);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004ccbe0);
    _DAT_00523008 = 1;
    _DAT_004fc2d8 = 0xc;
    _DAT_004fe830 = 2;
    _DAT_004fe000 = 0x3c;
    _DAT_004fb398 = 0xf;
    _DAT_00535758 = 0x13b;
    _DAT_004fece0 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,6,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat D");
    uStack_4 = 0x3a;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004ccc48);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    _DAT_0052300c = 1;
    _DAT_004fc2dc = 0xc;
    _DAT_004fe834 = 2;
    _DAT_004fe004 = 0x3c;
    _DAT_004fb39c = 0xf;
    _DAT_0053575c = 0x13b;
    _DAT_004fece4 = 0x2d;
    FUN_00417aa0(original_dc,param_1,iVar2,7,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_14,"Boat E");
    uStack_4 = 0x3b;
    (*pcVar1)(original_dc,(int)param_1,iVar2 + 4 + iVar5,TStack_14.data,
              *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_004f71c4 = uStack_10;
  DAT_00536458 = 0;
  DAT_005362d4 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

