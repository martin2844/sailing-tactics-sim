
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004479e0(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  double dVar3;
  CDC *this;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_1c;
  int local_18;
  LPCSTR pCStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484d98;
  pcStack_8 = FUN_00480010;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar5 = 0x10;
    local_18 = 0x16;
    local_1c = 5;
  }
  else {
    iVar5 = 0x14;
    local_18 = 0x1b;
    local_1c = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___STARTING___0049d54c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_1c,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  param_1 = (CDC *)(iVar5 + 2);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&pCStack_14,s_Starting_Objectives__in_usual_or_0049d518);
    uStack_4 = 1;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_1__Freedom_to_tack_if_the_wind_i_0049d4bc);
    uStack_4 = 2;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_Start_left_of_the_pack_if_the_le_0049d474);
    uStack_4 = 3;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_2__Clear_air__0049d464);
    uStack_4 = 4;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_3__Start_where_you_are_upwind_of_0049d430);
    uStack_4 = 5;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_4__Start_where_you_can_bail_out_i_0049d3fc);
    uStack_4 = 6;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&pCStack_14,s_If_you_have_really_good_boat_spe_0049d3b8);
    uStack_4 = 7;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0);
    }
    FUN_0046bf33(&pCStack_14,s_If_you_have_poor_boat_speed__obj_0049d35c);
    uStack_4 = 8;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_weather_end_to_have_freedom_to_t_0049d2fc);
    uStack_4 = 9;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
  }
  if (DAT_004a6774 == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_14,s_In_this_start__the_line_is_perpe_0049d2b0);
    uStack_4 = 10;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_the_wind_is_oscillating_or_th_0049d250);
    uStack_4 = 0xb;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_the_left_side_becomes_favored_0049d210);
    uStack_4 = 0xc;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_Boat_C_has_a_sight_from_the_p_0049d1b4);
    uStack_4 = 0xd;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_since_boats_in_the_middle_of_the_0049d16c);
    uStack_4 = 0xe;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_To_have_clear_air__start_close_t_0049d108);
    uStack_4 = 0xf;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 2) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_14,s_Another_start__This_time_the_pin_0049d0d8);
    uStack_4 = 0x10;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_14,s_Another_start__This_time_the_pin_0049d0d8);
    uStack_4 = 0x11;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_Boat_A_has_a_lead__She_may_be_th_0049d084);
    uStack_4 = 0x12;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_pinching_to_avoid_bad_air__0049d068);
    uStack_4 = 0x13;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_the_left_side_of_the_course_b_0049d01c);
    uStack_4 = 0x14;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_the_wind_is_oscillating__Boat_0049cfc0);
    uStack_4 = 0x15;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_Boat_E_tacks_first__and_the_r_0049cf5c);
    uStack_4 = 0x16;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 4) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_14,s_Another_start__This_time_the_Com_0049cf20);
    uStack_4 = 0x17;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 5) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_14,s_Another_start__This_time_the_Com_0049cf20);
    uStack_4 = 0x18;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_Boat_D_has_the_lead__clear_air__a_0049cee0);
    uStack_4 = 0x19;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_If_the_left_side_of_the_course_b_0049ce80);
    uStack_4 = 0x1a;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_favored__A_is_in_a_very_bad_posi_0049ce58);
    uStack_4 = 0x1b;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + local_18;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_Boat_E_is_in_bad_air_but_can_tac_0049ce00);
    uStack_4 = 0x1c;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_14,s_and_an_excellent_position_if_the_0049cdb4);
    uStack_4 = 0x1d;
    (*pcVar1)(this,local_1c,(int)param_1,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  FUN_0044d830((int)this,local_1c,iVar5);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00448468;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00448468;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00448468:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 5;
  FUN_0044d6d0((int)this,iVar5);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 < 2) {
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485398),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  }
  if ((DAT_004a6774 == 2) || (DAT_004a6774 == 3)) {
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_004853a0),3,1);
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485398),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853a8),0,1,DAT_004a72d0,0);
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00485358),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_004853a8),3,1);
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004853b0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853a0),0,1,DAT_004a72d0,0);
  }
  if (DAT_004a6774 == 0) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x1e;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x1f;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x20;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x21;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853b8);
    iVar4 = DAT_004a763c / 0xf;
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 5;
    _DAT_004a7804 = 0x28;
    _DAT_004a707c = 0x14;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    _DAT_004a7be0 = 0x41;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x22;
    (*pcVar1)(this,(int)param_1 - iVar4,(int)(puVar2 + iVar5 + 4),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 1) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x23;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x24;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x25;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x26;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484e50);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x27;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 2) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x28;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x29;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x2a;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853c8);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x2b;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485388);
    iVar4 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 5;
    _DAT_004a7804 = 0x28;
    _DAT_004a707c = 0x14;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    _DAT_004a7be4 = 0x41;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x2c;
    (*pcVar1)(this,(int)param_1 - (iVar4 >> 4),
              (int)puVar2 - (int)(longlong)(_DAT_004aa7d8 * _DAT_00485050),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 3) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853d0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x2d;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x2e;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485328);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x2f;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x30;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484e50);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853b8);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x31;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 4) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x32;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x33;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853c8);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x34;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484e50);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    iVar4 = DAT_004a763c / 0x19;
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x35;
    (*pcVar1)(this,(int)param_1 - iVar4,(int)(puVar2 + iVar5 + 4),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004853d8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485088);
    iVar4 = DAT_004a763c / 0x19;
    _DAT_004a707c = 0x3c;
    _DAT_004a7be4 = 0x3c;
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 10;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x36;
    (*pcVar1)(this,(int)param_1 - iVar4,(int)(puVar2 + iVar5 + 4),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 5) {
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x37;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f10);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x38;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x39;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x3a;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485398);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar2,7,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_E_0049ca38);
    uStack_4 = 0x3b;
    (*pcVar1)(this,(int)param_1,(int)(puVar2 + iVar5 + 4),pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004a4e8c = uStack_10;
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

