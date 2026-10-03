
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00440d20(CDC *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  double dVar4;
  CDC *this;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_2c;
  int local_28 [2];
  int iStack_20;
  LPCSTR pCStack_1c;
  code *apcStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f888;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar4;
  if (DAT_004a763c < 700) {
    iVar5 = 0x10;
    local_2c = 0x16;
    local_28[0] = 5;
  }
  else {
    iVar5 = 0x14;
    local_2c = 0x1b;
    local_28[0] = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___STRATEGY_for_BEATING_IN_AN_OSC_0049a9e4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_28[0],2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  param_1 = (CDC *)(local_2c + 2);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&pCStack_1c,s_An_oscillating_wind_is_one_which_0049a988);
    uStack_4 = 1;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_1c,s_of_the_race__In_an_oscillating_w_0049a92c);
    uStack_4 = 2;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_by_tacking_at_the_right_times__0049a90c);
    uStack_4 = 3;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_1c,s_Boat_A_and_Boat_B_are_even__The_w_0049a8c8);
    uStack_4 = 4;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&pCStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 5;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
  }
  if (DAT_004a6774 == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_1c,s_The_wind_swings_20_degrees_to_th_0049a884);
    uStack_4 = 6;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_Both_boats_are_headed_20_degrees_0049a854);
    uStack_4 = 7;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_Boat_A_and_Boat_B_are_almost_eve_0049a810);
    uStack_4 = 8;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&pCStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 9;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
  }
  if (DAT_004a6774 == 2) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_1c,s_They_sail_some_distance__0049a7f4);
    uStack_4 = 10;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&pCStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xb;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_1c,s_The_wind_swings_20_degrees_to_th_0049a7ac);
    uStack_4 = 0xc;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&pCStack_1c,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xd;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
  }
  if (DAT_004a6774 == 4) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_1c,s_By_tacking_when_headed_relative_t_0049a754);
    uStack_4 = 0xe;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_Boat_A_will_finish_the_leg_saili_0049a704);
    uStack_4 = 0xf;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_even_though_the_wind_shifts_were_0049a6b4);
    uStack_4 = 0x10;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&pCStack_1c,s_When_the_wind_is_near_the_averag_0049a660);
    uStack_4 = 0x11;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(&pCStack_1c,s_from_the_nearest_layline_since_a_0049a610);
    uStack_4 = 0x12;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    param_1 = param_1 + local_2c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&pCStack_1c,s_Boats_which_lose_significant_dis_0049a5c0);
    uStack_4 = 0x13;
    (*pcVar1)(this,local_28[0],(int)param_1,pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
    FUN_0046bf33(&pCStack_1c,s_will_not_gain_by_tacking_on_very_0049a590);
    uStack_4 = 0x14;
    (*pcVar1)(this,local_28[0],(int)(param_1 + iVar5),pCStack_1c,*(int *)(pCStack_1c + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_1c);
  }
  FUN_0044d830((int)this,local_28[0],iVar5);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_004414c3;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004414c3;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_004414c3:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 4;
  FUN_0044d6d0((int)this,iVar5);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iStack_20 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  pCStack_1c = (LPCSTR)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iStack_20,(int)pCStack_1c,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x15;
  (*pcVar1)(this,DAT_004a763c / 100 + iStack_20,(int)pCStack_1c,(LPCSTR)param_1,
            *(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = 0;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar2);
    local_28[0] = DAT_004a763c / 0x32;
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x16;
    (*pcVar1)(this,(int)param_1 - local_28[0],iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar2);
    local_28[0] = DAT_004a763c / 0xf;
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x17;
    (*pcVar1)(this,(int)param_1 - local_28[0],iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    apcStack_18[0] = *(code **)(*(int *)this + 0x38);
    (*apcStack_18[0])(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,local_28,0,iVar2);
    CDC::LineTo(this,DAT_004a763c,iVar2);
    (*apcStack_18[0])(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x18;
    (*pcVar1)(this,DAT_004a763c / 5,iVar2,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*apcStack_18[0])(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x19;
    (*pcVar1)(this,(int)(param_1 + local_28[0]),(int)(puVar3 + iVar5),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x1a;
    (*pcVar1)(this,(int)param_1 - local_28[0],(int)(puVar3 + iVar5),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
  }
  if (DAT_004a6774 == 1) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar2);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x1b;
    (*pcVar1)(this,(int)param_1,iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar2);
    local_28[0] = DAT_004a763c / 0xe;
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x1c;
    (*pcVar1)(this,(int)param_1 - local_28[0],iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    DAT_004a8e88 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    DAT_004a4eb8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x19;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004a8e88,DAT_004a4eb8,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_A_004994e4);
    uStack_4 = 0x1d;
    (*pcVar1)(this,DAT_004a8e88 + local_28[0],(int)(DAT_004a4eb8 + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    DAT_004a7638 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    DAT_004a6224 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    local_28[0] = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x127;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004a7638,DAT_004a6224,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_B_004994ec);
    uStack_4 = 0x1e;
    (*pcVar1)(this,DAT_004a7638 - local_28[0],(int)(DAT_004a6224 + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 2) {
    DAT_004ac840 = 0x1e;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar2);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x1f;
    (*pcVar1)(this,(int)param_1,iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar2);
    local_28[0] = DAT_004a763c / 0xe;
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x20;
    (*pcVar1)(this,(int)param_1 - local_28[0],iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    DAT_004abefc = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    DAT_004abdd8 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    local_28[0] = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x19;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004abefc,DAT_004abdd8,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_A_004994e4);
    uStack_4 = 0x21;
    (*pcVar1)(this,DAT_004abefc + local_28[0],(int)(DAT_004abdd8 + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    DAT_004a4030 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    DAT_004abdd0 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    local_28[0] = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x127;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004a4030,DAT_004abdd0,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_B_004994ec);
    uStack_4 = 0x22;
    (*pcVar1)(this,DAT_004a4030 - local_28[0],(int)(DAT_004abdd0 + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 3) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar2);
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x23;
    (*pcVar1)(this,(int)param_1,iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    FUN_004706bd(this,(int *)apcStack_18,iStack_20,(int)pCStack_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar2);
    local_28[0] = DAT_004a763c / 0xe;
    FUN_0046bf33(apcStack_18,s_LayLine_00499508);
    uStack_4 = 0x24;
    (*pcVar1)(this,(int)param_1 - local_28[0],iVar2 + iVar5 * -2,(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    DAT_004aa968 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    DAT_004aaa40 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    local_28[0] = DAT_004a763c / 0x14;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,DAT_004aa968,DAT_004aaa40,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_A_004994e4);
    uStack_4 = 0x25;
    (*pcVar1)(this,DAT_004aa968 + local_28[0],(int)(DAT_004aaa40 + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    DAT_004ac098 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    DAT_004a679c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    local_28[0] = DAT_004a763c / 0xe;
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,DAT_004ac098,DAT_004a679c,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_B_004994ec);
    uStack_4 = 0x26;
    (*pcVar1)(this,DAT_004ac098 - local_28[0],(int)(DAT_004a679c + iVar5),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 4) {
    DAT_004ac840 = 0xffffffec;
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    local_28[0] = DAT_004a763c / 0x14;
    if ((DAT_004ac92c == 0) && (DAT_004ac854 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    FUN_004706bd(this,(int *)apcStack_18,(int)param_1,(int)puVar3);
    CDC::LineTo(this,DAT_004aa968,(int)DAT_004aaa40);
    CDC::LineTo(this,DAT_004abefc,(int)DAT_004abdd8);
    CDC::LineTo(this,DAT_004a8e88,(int)DAT_004a4eb8);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x27;
    (*pcVar1)(this,(int)(param_1 + local_28[0]),(int)(puVar3 + iVar5),(LPCSTR)apcStack_18[0],
              *(int *)(apcStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_18);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    local_28[0] = DAT_004a763c / 0xe;
    if ((DAT_004ac92c == 0) && (DAT_004a3c0c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apcStack_18,(int)param_1,(int)puVar3);
    CDC::LineTo(this,DAT_004ac098,(int)DAT_004a679c);
    CDC::LineTo(this,DAT_004a4030,(int)DAT_004abdd0);
    CDC::LineTo(this,DAT_004a7638,(int)DAT_004a6224);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x28;
    (*pcVar1)(this,(int)param_1 - local_28[0],(int)(puVar3 + iVar5),(LPCSTR)apcStack_18[0],
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

