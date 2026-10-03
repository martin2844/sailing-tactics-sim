
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045a150(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  int *original_dc;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_2c;
  int local_28;
  Tact2010CString TStack_20;
  int iStack_1c;
  Tact2010CString aTStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_005230b0 * _DAT_004cc770;
  pcStack_8 = FUN_004c4d90;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar4;
  if (DAT_004fe624 < 700) {
    iVar6 = 0x10;
    local_28 = 0x16;
    local_2c = 5;
  }
  else {
    iVar6 = 0x14;
    local_28 = 0x1b;
    local_2c = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___STRATEGY_for_DOWNWIND_LEGS___004e86a0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_2c,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar5 = local_28 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fb9b4 == 0) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Reaching_legs_are_generally_not_s_004e8644);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_off_in_the_puffs__head_up_in_the_004e85f0);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + local_28;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Strategy_on_runs_depends_on_the_b_004e8594);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_or_single_sail_boats_make_best_d_004e8540);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_Even_so__course_diversions_of_15_004e84ec);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_steer_to_get_stronger_wind__avoi_004e84a4);
    uStack_4 = 6;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 7;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_High_performance_boats_such_as_c_004e8444);
    uStack_4 = 8;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_spinnakers_make_best_progress_do_004e83e8);
    uStack_4 = 9;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_shifty_winds__these_boats_can_si_004e8380);
    uStack_4 = 10;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28 + iVar6;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 2) {
    FUN_004b0613((Tact2010CString *)&param_1,s_The_boats_sail_for_some_distance_004e831c);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_The_Laylines_and_the_Equal_Posit_004e82dc);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_Boat_A_has_made_a_significant_ga_004e827c);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28 + iVar6;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 3) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Both_boats_jibe__004e8268);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_If_Boat_A_can_get_between_Boat_B_004e8214);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_not_be_lost_by_a_wind_shift__004e81f4);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28 + iVar6;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 4) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Both_boats_sail_some_distance__B_004e81ac);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_by_being_farther_downwind_when_t_004e8178);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + local_28 + iVar6;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Click_the_Advance_Position_Butto_004e6e2c);
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004fb9b4 == 5) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Principles_for_using_wind_shifts_004e8140);
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_a_persistent_shift_is_expecte_004e80e0);
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_after_the_shift__If_the_wind_wil_004e8094);
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_an_oscillating_wind_is_expect_004e8034);
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_004b0613((Tact2010CString *)&param_1,s_the_tack_that_points_closer_to_t_004e8008);
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + local_28;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Caution__Sailing_downwind__wind_s_004e7fac);
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,local_2c,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_If_other_boats_have_a_lot_more_w_004e7f68);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,local_2c,iVar5 + iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  FUN_00463df0(original_dc,local_2c,iVar6);
  if (DAT_005363e4 == 0) {
    if (DAT_004fc15c == (HGDIOBJ)0x0) goto LAB_0045aa85;
    hdc = (HDC)original_dc[1];
    h = DAT_004fc15c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_0045aa85;
    hdc = (HDC)original_dc[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_0045aa85:
  Rectangle((HDC)original_dc[1],0,DAT_004faf7c,DAT_004fe624,DAT_004fe2a8);
  DAT_004da18c = 5;
  FUN_00463c90(original_dc,iVar6);
  DAT_00536458 = 2;
  uStack_10 = DAT_004f71c4;
  DAT_004f71c4 = 2;
  DAT_004fbb94 = 0;
  iVar5 = (int)(longlong)(_DAT_005230e8 * _DAT_004cc4f8);
  iStack_1c = (int)(longlong)(_DAT_005230b0 * _DAT_004cc5e0);
  FUN_0043faa0(original_dc,iVar5,iStack_1c,4,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004dd748);
  uStack_4 = 0x1e;
  (*pcVar1)(original_dc,DAT_004fe624 / 100 + iVar5,iStack_1c,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_004fb9b4 == 0) {
    DAT_004f385c = DAT_005363b8;
    DAT_004fb6b0 = DAT_004da190;
    _DAT_005359dc = DAT_005363bc;
    DAT_005362d4 = 0xb4;
    DAT_004f6d30 = DAT_005363c0;
    DAT_004da190 = 6;
    DAT_005363b8 = 0;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0x14;
    _DAT_004fe81c = 0x3c;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0xf;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0;
    DAT_004feccc = 0xb4;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_20,"Boat A");
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar2 + iVar6,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0xe;
    _DAT_004fe820 = 0x3c;
    DAT_004fdff0 = 0x3c;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x159;
    DAT_004fecd0 = 0xb4;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_20,"Boat B");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
  }
  if (DAT_004fb9b4 == 1) {
    DAT_004fb6b0 = DAT_004da190;
    DAT_004f385c = DAT_005363b8;
    DAT_004f6d30 = DAT_005363c0;
    _DAT_005359dc = DAT_005363bc;
    DAT_005363b8 = 1;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    DAT_005362d4 = 0xb4;
    DAT_004da190 = 10;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    iVar3 = DAT_004fe624 / 0x32;
    FUN_004b0613(&TStack_20,"LayLine");
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6 * -2,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc508);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    iVar3 = DAT_004fe624 / 10;
    FUN_004b0613(&TStack_20,"LayLine");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6 * -2,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    TStack_20.data = *(char **)(*original_dc + 0x38);
    (*(code *)TStack_20.data)(original_dc,0);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,0,iVar2);
    CDC::LineTo(original_dc,DAT_004fe624,iVar2);
    (*(code *)TStack_20.data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x23;
    (*pcVar1)(original_dc,DAT_004fe624 / 6,iVar2,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)TStack_20.data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0x14;
    DAT_00522ff4 = 1;
    DAT_004fc2c4 = 0;
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_004fb384 = 0xf;
    DAT_00535744 = 0x2d;
    DAT_004feccc = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_20,"Boat A");
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar2 + iVar6,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc600);
    iVar3 = DAT_004fe624 / 0xe;
    DAT_00522ff8 = 0xffffffff;
    _DAT_004fc2c8 = 0;
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    DAT_004fb388 = 0xf;
    DAT_00535748 = 0x13b;
    DAT_004fecd0 = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(&TStack_20,"Boat B");
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
  }
  if ((DAT_004fb9b4 == 2) || (DAT_004fb9b4 == 3)) {
    DAT_004fb6b0 = DAT_004da190;
    DAT_004f385c = DAT_005363b8;
    DAT_004f6d30 = DAT_005363c0;
    _DAT_005359dc = DAT_005363bc;
    DAT_005363b8 = 1;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    DAT_005362d4 = 0xa0;
    DAT_004da190 = 10;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    iVar3 = DAT_004fe624 / 0x32;
    FUN_004b0613(&TStack_20,"LayLine");
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6 * -2,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    iVar3 = DAT_004fe624 / 10;
    FUN_004b0613(&TStack_20,"LayLine");
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6 * -2,TStack_20.data,
              *(int *)(TStack_20.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_20);
    TStack_20.data = *(char **)(*original_dc + 0x38);
    (*(code *)TStack_20.data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc820);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0x14;
    if (DAT_004fb9b4 == 2) {
      DAT_00522ff4 = 1;
      DAT_00535744 = 0x41;
    }
    else {
      DAT_00522ff4 = 0xffffffff;
      DAT_00535744 = 0x14f;
    }
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_004fc2c4 = 0;
    DAT_004fb384 = 0xf;
    DAT_004feccc = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar2,1,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat A");
    uStack_4 = 0x28;
    (*pcVar1)(original_dc,iVar3 + (int)param_1,iVar2 + iVar6,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)param_1,iVar2);
    CDC::LineTo(original_dc,DAT_004fe624 / 10,iVar2 - DAT_004fe2a8 / 10);
    (*(code *)TStack_20.data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x29;
    (*pcVar1)(original_dc,(DAT_004fe624 * 2) / 5,iVar2 - DAT_004fe2a8 / 0x1e,(char *)param_1,
              param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)TStack_20.data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc8c0);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc738);
    iVar3 = DAT_004fe624 / 0xe;
    if (DAT_004fb9b4 == 2) {
      DAT_00522ff8 = 0xffffffff;
      DAT_00535748 = 0x14f;
    }
    else {
      DAT_00522ff8 = 1;
      DAT_00535748 = 0x41;
    }
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0;
    DAT_004fb388 = 0xf;
    DAT_004fecd0 = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar2,2,1,DAT_004fe2a8,0);
    FUN_004b0613(aTStack_18,"Boat B");
    uStack_4 = 0x2a;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
  }
  if (3 < DAT_004fb9b4) {
    DAT_004f385c = DAT_005363b8;
    DAT_004fb6b0 = DAT_004da190;
    _DAT_005359dc = DAT_005363bc;
    DAT_004f6d30 = DAT_005363c0;
    DAT_005363b8 = 1;
    DAT_005350dc = 1;
    DAT_005350e0 = 1;
    DAT_005362d4 = 0xa0;
    DAT_004da190 = 10;
    DAT_005363c0 = 0;
    DAT_005363bc = 0;
    if (DAT_005362ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_005362ec);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc618);
    iVar2 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    CDC::LineTo(original_dc,(int)param_1,iVar2);
    iVar3 = DAT_004fe624 / 0x32;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x2b;
    (*pcVar1)(original_dc,(int)param_1 - iVar3,iVar2 + iVar6 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    FUN_004b4d9d(original_dc,(int *)aTStack_18,iVar5,iStack_1c);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7b8);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc6c0);
    CDC::LineTo(original_dc,(int)param_1,iVar5);
    iVar2 = DAT_004fe624 / 10;
    FUN_004b0613(aTStack_18,"LayLine");
    uStack_4 = 0x2c;
    (*pcVar1)(original_dc,(int)param_1 - iVar2,iVar5 + iVar6 * -2,aTStack_18[0].data,
              *(int *)(aTStack_18[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_18);
    TStack_20.data = *(char **)(*original_dc + 0x38);
    (*(code *)TStack_20.data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc7d0);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc668);
    iVar2 = DAT_004fe624 / 0x14;
    if (DAT_004fb9b4 == 2) {
      DAT_00522ff4 = 1;
      DAT_00535744 = 0x41;
    }
    else {
      DAT_00522ff4 = 0xffffffff;
      DAT_00535744 = 0x14f;
    }
    _DAT_004fe81c = 0x14;
    DAT_004fdfec = 0x3c;
    DAT_004fc2c4 = 0;
    DAT_004fb384 = 0xf;
    DAT_004feccc = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar5,1,1,DAT_004fe2a8,0);
    if (DAT_004fb9b4 == 4) {
      FUN_004b0613(aTStack_18,"Boat A");
      uStack_4 = 0x2d;
      (*pcVar1)(original_dc,iVar2 + (int)param_1,iVar5 + iVar6,aTStack_18[0].data,
                *(int *)(aTStack_18[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_18);
    }
    if (DAT_004f3c0c != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_004f3c0c);
    }
    FUN_004b4d9d(original_dc,(int *)aTStack_18,(int)param_1,iVar5);
    CDC::LineTo(original_dc,DAT_004fe624 / 10,iVar5 - DAT_004fe2a8 / 10);
    (*(code *)TStack_20.data)(original_dc,0x7f00);
    FUN_004b0613((Tact2010CString *)&param_1,"Equal Position Line");
    uStack_4 = 0x2e;
    (*pcVar1)(original_dc,DAT_004fe624 / 6,iVar5 - DAT_004fe2a8 / 0x1e,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)TStack_20.data)(original_dc,0);
    param_1 = (int *)(longlong)(_DAT_005230e8 * _DAT_004cc778);
    iVar5 = (int)(longlong)(_DAT_005230b0 * _DAT_004cc820);
    iVar2 = DAT_004fe624 / 0xe;
    if (DAT_004fb9b4 == 2) {
      DAT_00522ff8 = 0xffffffff;
      DAT_00535748 = 0x14f;
    }
    else {
      DAT_00522ff8 = 1;
      DAT_00535748 = 0x41;
    }
    _DAT_004fe820 = 0x14;
    DAT_004fdff0 = 0x3c;
    _DAT_004fc2c8 = 0;
    DAT_004fb388 = 0xf;
    DAT_004fecd0 = 0x87;
    FUN_00417aa0(original_dc,param_1,iVar5,2,1,DAT_004fe2a8,0);
    if (DAT_004fb9b4 == 4) {
      FUN_004b0613(aTStack_18,"Boat B");
      uStack_4 = 0x2f;
      (*pcVar1)(original_dc,(int)param_1 - iVar2,iVar5 + iVar6,aTStack_18[0].data,
                *(int *)(aTStack_18[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_18);
    }
  }
  FUN_00442560(original_dc,0,1,0,DAT_004faf7c,DAT_004fe624);
  DAT_00536458 = 0;
  DAT_004f71c4 = uStack_10;
  DAT_005363b8 = DAT_004f385c;
  DAT_005350dc = 0;
  DAT_005350e0 = 0;
  DAT_004da190 = DAT_004fb6b0;
  DAT_005363c0 = DAT_004f6d30;
  DAT_005363bc = DAT_004fb6b0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

