
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00443bf0(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  CDC *this;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_2c;
  int local_28;
  code *pcStack_20;
  int iStack_1c;
  LPCSTR apCStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar5 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047fb50;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar5;
  if (DAT_004a763c < 700) {
    iVar7 = 0x10;
    local_28 = 0x16;
    local_2c = 5;
  }
  else {
    iVar7 = 0x14;
    local_28 = 0x1b;
    local_2c = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___STRATEGY_for_DOWNWIND_LEGS___0049b6a8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_2c,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = local_28 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&param_1,s_Reaching_legs_are_generally_not_s_0049b64c);
    uStack_4 = 1;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_off_in_the_puffs__head_up_in_the_0049b5f8);
    uStack_4 = 2;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + local_28;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Strategy_on_runs_depends_on_the_b_0049b59c);
    uStack_4 = 3;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7;
    FUN_0046bf33(&param_1,s_or_single_sail_boats_make_best_d_0049b548);
    uStack_4 = 4;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7;
    FUN_0046bf33(&param_1,s_Even_so__course_diversions_of_15_0049b4f4);
    uStack_4 = 5;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7;
    FUN_0046bf33(&param_1,s_steer_to_get_stronger_wind__avoi_0049b4ac);
    uStack_4 = 6;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 7;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&param_1,s_High_performance_boats_such_as_c_0049b44c);
    uStack_4 = 8;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_spinnakers_make_best_progress_do_0049b3f0);
    uStack_4 = 9;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + iVar7;
    FUN_0046bf33(&param_1,s_shifty_winds__these_boats_can_si_0049b388);
    uStack_4 = 10;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xb;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&param_1,s_The_boats_sail_for_some_distance_0049b324);
    uStack_4 = 0xc;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_The_Laylines_and_the_Equal_Posit_0049b2e4);
    uStack_4 = 0xd;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + iVar7;
    FUN_0046bf33(&param_1,s_Boat_A_has_made_a_significant_ga_0049b284);
    uStack_4 = 0xe;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xf;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(&param_1,s_Both_boats_jibe__0049b270);
    uStack_4 = 0x10;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_If_Boat_A_can_get_between_Boat_B_0049b21c);
    uStack_4 = 0x11;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + iVar7;
    FUN_0046bf33(&param_1,s_not_be_lost_by_a_wind_shift__0049b1fc);
    uStack_4 = 0x12;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0x13;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 4) {
    FUN_0046bf33(&param_1,s_Both_boats_sail_some_distance__B_0049b1b4);
    uStack_4 = 0x14;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_by_being_farther_downwind_when_t_0049b180);
    uStack_4 = 0x15;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + local_28 + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0x16;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 5) {
    FUN_0046bf33(&param_1,s_Principles_for_using_wind_shifts_0049b148);
    uStack_4 = 0x17;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&param_1,s_If_a_persistent_shift_is_expecte_0049b0e8);
    uStack_4 = 0x18;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7 + iVar7;
    FUN_0046bf33(&param_1,s_after_the_shift__If_the_wind_wil_0049b09c);
    uStack_4 = 0x19;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_If_an_oscillating_wind_is_expect_0049b03c);
    uStack_4 = 0x1a;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + iVar7;
    FUN_0046bf33(&param_1,s_the_tack_that_points_closer_to_t_0049b010);
    uStack_4 = 0x1b;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_28;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0);
    }
    FUN_0046bf33(&param_1,s_Caution__Sailing_downwind__wind_s_0049afb4);
    uStack_4 = 0x1c;
    (*pcVar1)(this,local_2c,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0);
    }
    FUN_0046bf33(&param_1,s_If_other_boats_have_a_lot_more_w_0049af70);
    uStack_4 = 0x1d;
    (*pcVar1)(this,local_2c,iVar6 + iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  FUN_0044d830((int)this,local_2c,iVar7);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00444525;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00444525;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00444525:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 5;
  FUN_0044d6d0((int)this,iVar7);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iStack_1c = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iVar6,iStack_1c,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x1e;
  (*pcVar1)(this,DAT_004a763c / 100 + iVar6,iStack_1c,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004a6774 == 0) {
    DAT_004a3a0c = DAT_004ac900;
    DAT_004a6488 = DAT_00491188;
    _DAT_004ac1e4 = DAT_004ac904;
    DAT_004ac840 = 0xb4;
    DAT_004a4bdc = DAT_004ac908;
    DAT_00491188 = 6;
    DAT_004ac900 = 0;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar3 = DAT_004a763c / 0x14;
    _DAT_004a77ec = 0x3c;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0xf;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    DAT_004a7bcc = 0xb4;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pcStack_20,s_Boat_A_004994e4);
    uStack_4 = 0x1f;
    (*pcVar1)(this,(int)(param_1 + iVar3),(int)(puVar2 + iVar7),(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar3 = DAT_004a763c / 0xe;
    _DAT_004a77f0 = 0x3c;
    DAT_004a7068 = 0x3c;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x159;
    DAT_004a7bd0 = 0xb4;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pcStack_20,s_Boat_B_004994ec);
    uStack_4 = 0x20;
    (*pcVar1)(this,(int)param_1 - iVar3,(int)(puVar2 + iVar7),(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
  }
  if (DAT_004a6774 == 1) {
    DAT_004a6488 = DAT_00491188;
    DAT_004a3a0c = DAT_004ac900;
    DAT_004a4bdc = DAT_004ac908;
    _DAT_004ac1e4 = DAT_004ac904;
    DAT_004ac900 = 1;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    DAT_004ac840 = 0xb4;
    DAT_00491188 = 10;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar3);
    iVar4 = DAT_004a763c / 0x32;
    FUN_0046bf33(&pcStack_20,s_LayLine_00499508);
    uStack_4 = 0x21;
    (*pcVar1)(this,(int)param_1 - iVar4,iVar3 + iVar7 * -2,(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar3);
    iVar4 = DAT_004a763c / 10;
    FUN_0046bf33(&pcStack_20,s_LayLine_00499508);
    uStack_4 = 0x22;
    (*pcVar1)(this,(int)param_1 - iVar4,iVar3 + iVar7 * -2,(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    pcStack_20 = *(code **)(*(int *)this + 0x38);
    (*pcStack_20)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)apCStack_18,0,iVar3);
    CDC::LineTo(this,DAT_004a763c,iVar3);
    (*pcStack_20)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x23;
    (*pcVar1)(this,DAT_004a763c / 6,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcStack_20)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar3 = DAT_004a763c / 0x14;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pcStack_20,s_Boat_A_004994e4);
    uStack_4 = 0x24;
    (*pcVar1)(this,(int)(param_1 + iVar3),(int)(puVar2 + iVar7),(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar3 = DAT_004a763c / 0xe;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pcStack_20,s_Boat_B_004994ec);
    uStack_4 = 0x25;
    (*pcVar1)(this,(int)param_1 - iVar3,(int)(puVar2 + iVar7),(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
  }
  if ((DAT_004a6774 == 2) || (DAT_004a6774 == 3)) {
    DAT_004a6488 = DAT_00491188;
    DAT_004a3a0c = DAT_004ac900;
    DAT_004a4bdc = DAT_004ac908;
    _DAT_004ac1e4 = DAT_004ac904;
    DAT_004ac900 = 1;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    DAT_004ac840 = 0xa0;
    DAT_00491188 = 10;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar3);
    iVar4 = DAT_004a763c / 0x32;
    FUN_0046bf33(&pcStack_20,s_LayLine_00499508);
    uStack_4 = 0x26;
    (*pcVar1)(this,(int)param_1 - iVar4,iVar3 + iVar7 * -2,(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar3);
    iVar4 = DAT_004a763c / 10;
    FUN_0046bf33(&pcStack_20,s_LayLine_00499508);
    uStack_4 = 0x27;
    (*pcVar1)(this,(int)param_1 - iVar4,iVar3 + iVar7 * -2,(LPCSTR)pcStack_20,
              *(int *)(pcStack_20 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pcStack_20);
    pcStack_20 = *(code **)(*(int *)this + 0x38);
    (*pcStack_20)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar3 = DAT_004a763c / 0x14;
    if (DAT_004a6774 == 2) {
      DAT_004aa734 = 1;
      DAT_004ac01c = 0x41;
    }
    else {
      DAT_004aa734 = 0xffffffff;
      DAT_004ac01c = 0x14f;
    }
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a6ecc = 0;
    DAT_004a633c = 0xf;
    DAT_004a7bcc = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x28;
    (*pcVar1)(this,(int)(param_1 + iVar3),(int)(puVar2 + iVar7),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apCStack_18,(int)param_1,(int)puVar2);
    CDC::LineTo(this,DAT_004a763c / 10,(int)puVar2 - DAT_004a72d0 / 10);
    (*pcStack_20)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x29;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,(int)puVar2 - DAT_004a72d0 / 0x1e,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcStack_20)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar3 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 2) {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x14f;
    }
    else {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x41;
    }
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x2a;
    (*pcVar1)(this,(int)param_1 - iVar3,(int)(puVar2 + iVar7),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (3 < DAT_004a6774) {
    DAT_004a3a0c = DAT_004ac900;
    DAT_004a6488 = DAT_00491188;
    _DAT_004ac1e4 = DAT_004ac904;
    DAT_004a4bdc = DAT_004ac908;
    DAT_004ac900 = 1;
    DAT_004abb74 = 1;
    DAT_004abb78 = 1;
    DAT_004ac840 = 0xa0;
    DAT_00491188 = 10;
    DAT_004ac908 = 0;
    DAT_004ac904 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar3);
    iVar4 = DAT_004a763c / 0x32;
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x2b;
    (*pcVar1)(this,(int)param_1 - iVar4,iVar3 + iVar7 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,iVar6,iStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar6 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar6);
    iVar3 = DAT_004a763c / 10;
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x2c;
    (*pcVar1)(this,(int)param_1 - iVar3,iVar6 + iVar7 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    pcStack_20 = *(code **)(*(int *)this + 0x38);
    (*pcStack_20)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iVar6 = DAT_004a763c / 0x14;
    if (DAT_004a6774 == 2) {
      DAT_004aa734 = 1;
      DAT_004ac01c = 0x41;
    }
    else {
      DAT_004aa734 = 0xffffffff;
      DAT_004ac01c = 0x14f;
    }
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a6ecc = 0;
    DAT_004a633c = 0xf;
    DAT_004a7bcc = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 4) {
      FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
      uStack_4 = 0x2d;
      (*pcVar1)(this,(int)(param_1 + iVar6),(int)(puVar2 + iVar7),apCStack_18[0],
                *(int *)(apCStack_18[0] + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)apCStack_18);
    }
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apCStack_18,(int)param_1,(int)puVar2);
    CDC::LineTo(this,DAT_004a763c / 10,(int)puVar2 - DAT_004a72d0 / 10);
    (*pcStack_20)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x2e;
    (*pcVar1)(this,DAT_004a763c / 6,(int)puVar2 - DAT_004a72d0 / 0x1e,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcStack_20)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar6 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 2) {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x14f;
    }
    else {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x41;
    }
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x87;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 4) {
      FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
      uStack_4 = 0x2f;
      (*pcVar1)(this,(int)param_1 - iVar6,(int)(puVar2 + iVar7),apCStack_18[0],
                *(int *)(apCStack_18[0] + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)apCStack_18);
    }
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uStack_10;
  DAT_004ac900 = DAT_004a3a0c;
  DAT_004abb74 = 0;
  DAT_004abb78 = 0;
  DAT_00491188 = DAT_004a6488;
  DAT_004ac908 = DAT_004a4bdc;
  DAT_004ac904 = DAT_004a6488;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

