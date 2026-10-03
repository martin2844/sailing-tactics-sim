
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043f460(CDC *param_1)

{
  code *pcVar1;
  code *pcVar2;
  undefined *puVar3;
  double dVar4;
  CDC *this;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  CDC *local_28 [2];
  int local_20;
  int iStack_1c;
  code *apcStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f730;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar4;
  iVar6 = 0x14;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
    local_20 = 0x16;
    local_28[0] = (CDC *)&DAT_00000005;
  }
  else {
    local_20 = 0x1b;
    local_28[0] = (CDC *)0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___DEATH_BY_LAYLINE___0049a578);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,(int)local_28[0],2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = local_20 + 2;
  if ((DAT_004a6774 == 0) || (DAT_004a6774 == 3)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&param_1,s_With_any_windshift__a_boat_on_a_l_0049a51c);
    uStack_4 = 1;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boats_A_and_B_are_initially_even_0049a4e8);
    uStack_4 = 2;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_0046bf33(&param_1,s_However__boat_A_is_actually_clos_0049a4b8);
    uStack_4 = 3;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    if (DAT_004a6774 == 0) {
      FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_0049a480);
      uStack_4 = 4;
      (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004a6774 == 3) {
      (**(code **)(*(int *)this + 0x38))(this,0xff00ff);
      FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_0049a444);
      uStack_4 = 5;
      (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
    }
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_With_this_lift__Boat_A_can_sail_d_0049a40c);
    uStack_4 = 6;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_Since_boat_A_is_actually_closer_t_0049a3c4);
    uStack_4 = 7;
    (*pcVar1)(this,(int)local_28[0],iVar5 + iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + iVar6 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&param_1,s_Boat_B_is_now_overstanding_and_h_0049a384);
    uStack_4 = 8;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 9;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_With_this_header__Boat_A_can_tac_0049a350);
    uStack_4 = 10;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xb;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 6) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boat_A_can_tack_back__consolidat_0049a308);
    uStack_4 = 0xc;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xd;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 7) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boat_A_can_now_stay_ahead_with_a_0049a2d8);
    uStack_4 = 0xe;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_0049a2a4);
    uStack_4 = 0xf;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 8) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Despite_the_wind_shift_disadvant_0049a248);
    uStack_4 = 0x10;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_where_it_pays_to_sail_to_or_even_0049a1f8);
    uStack_4 = 0x11;
    (*pcVar1)(this,(int)local_28[0],iVar5 + iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + iVar6 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&param_1,s_1__If_you_are_fairly_near_the_ma_0049a1a0);
    uStack_4 = 0x12;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + iVar6;
    FUN_0046bf33(&param_1,s_worthwile_to_gamble_that_there_w_0049a168);
    uStack_4 = 0x13;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_2__In_light_air__the_wind_could_b_0049a110);
    uStack_4 = 0x14;
    (*pcVar1)(this,(int)local_28[0],iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_or_beyond_the_layline__However__i_0049a0b8);
    uStack_4 = 0x15;
    (*pcVar1)(this,(int)local_28[0],iVar6 + iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  FUN_0044d830((int)this,(int)local_28[0],iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043fc37;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043fc37;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043fc37:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 8;
  FUN_0044d6d0((int)this,iVar6);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  dVar4 = _DAT_00485370;
  if ((DAT_004a6774 != 2) && (DAT_004a6774 != 8)) {
    dVar4 = _DAT_00484d98;
  }
  local_20 = (int)(longlong)(_DAT_004aa7d8 * dVar4);
  iStack_1c = iVar5;
  FUN_0042cd40((int *)this,iVar5,local_20,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x16;
  (*pcVar1)(this,DAT_004a763c / 100 + iVar5,local_20,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if ((DAT_004a6774 == 0) || (DAT_004a6774 == 3)) {
    DAT_004ac840 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,local_20);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d48);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,(int)param_1,iVar5);
    FUN_0046bf33(local_28,s_LayLine_00499508);
    uStack_4 = 0x17;
    (*pcVar1)(this,(int)param_1,iVar5 + iVar6 * -2,(LPCSTR)local_28[0],*(int *)(local_28[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)local_28);
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,local_20);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,iVar5,(int)param_1);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x18;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6 * -4),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    apcStack_18[0] = *(code **)(*(int *)this + 0x38);
    (*apcStack_18[0])(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)local_28,0,iVar5);
    CDC::LineTo(this,DAT_004a763c,iVar5);
    (*apcStack_18[0])(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x19;
    (*pcVar1)(this,(int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2,iVar5,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*apcStack_18[0])(this,0);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x1a;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    dVar4 = _DAT_00484da0;
    if (DAT_004a6774 == 0) {
      dVar4 = _DAT_00484ec8;
    }
    iVar5 = (int)(longlong)(_DAT_004aa810 * dVar4);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = (CDC *)(DAT_004a763c / 0xe);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x1b;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
  }
  if (DAT_004a6774 == 1) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    iVar5 = local_20;
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,local_20);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485060),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,iVar5);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,iVar5,(int)param_1);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x1c;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6 * -4),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0xc;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x145;
    DAT_004a7bcc = 0x41;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B__0049a0b0);
    local_28[0] = param_1 + -(int)local_28[0];
    uStack_4 = 0x1d;
    (*pcVar1)(this,(int)local_28[0],(int)puVar3,(LPCSTR)apcStack_18[0],*(int *)(apcStack_18[0] + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_0046bf33(&param_1,s_Overstanding_004994cc);
    uStack_4 = 0x1e;
    (*pcVar1)(this,(int)local_28[0],(int)(puVar3 + iVar6),(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    DAT_004aa738 = 1;
    local_28[0] = (CDC *)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x1f;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
  }
  if ((DAT_004a6774 == 2) || (DAT_004a6774 == 8)) {
    DAT_004ac840 = 0xffffffec;
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 0xc;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14a;
    DAT_004a7bcc = 0x41;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 2) {
      FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
      uStack_4 = 0x20;
      (*pcVar1)(this,iVar5 - (int)local_28[0],(int)param_1,(LPCSTR)apcStack_18[0],
                *(int *)(apcStack_18[0] + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)apcStack_18);
    }
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    local_28[0] = (CDC *)(DAT_004a763c / 0xe);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 2) {
      FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
      uStack_4 = 0x21;
      (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
                *(int *)(apcStack_18[0] + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)apcStack_18);
    }
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    iVar5 = local_20;
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,local_20);
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d48),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484fe0));
    FUN_004706bd(this,(int *)apcStack_18,iStack_1c,iVar5);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    CDC::LineTo(this,iVar5,(int)param_1);
    local_28[0] = (CDC *)(DAT_004a763c / 6);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x22;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6 * -5),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    pcVar2 = *(code **)(*(int *)this + 0x38);
    (*pcVar2)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apcStack_18,(int)(longlong)(_DAT_004aa810 * _DAT_00484fe0),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    (*pcVar2)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x23;
    (*pcVar1)(this,(DAT_004a763c * 2) / 3,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),
              (LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcVar2)(this,0);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484fe0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x24;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = (CDC *)(DAT_004a763c / 0xe);
    if (DAT_004a6774 == 4) {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x127;
    }
    else {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x19;
    }
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x25;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
  }
  if ((DAT_004a6774 == 6) || (DAT_004a6774 == 7)) {
    DAT_004ac840 = 0x1e;
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    local_28[0] = (CDC *)(DAT_004a763c / 0xe);
    if (DAT_004a6774 == 7) {
      DAT_004aa738 = 1;
      DAT_004ac020 = 0x127;
    }
    else {
      DAT_004aa738 = 0xffffffff;
      DAT_004ac020 = 0x19;
    }
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar5,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x26;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    iVar5 = (int)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    local_28[0] = (CDC *)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar5,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x27;
    (*pcVar1)(this,iVar5 - (int)local_28[0],(int)(param_1 + iVar6),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

