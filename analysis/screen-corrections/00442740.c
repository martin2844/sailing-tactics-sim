
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00442740(CDC *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  double dVar7;
  CDC *this;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_28;
  int local_24;
  LPCSTR apCStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar7 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f9c0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar7;
  if (DAT_004a763c < 700) {
    iVar8 = 0x10;
    local_24 = 0x16;
    local_28 = 5;
  }
  else {
    iVar8 = 0x14;
    local_24 = 0x1b;
    local_28 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___STRATEGY_for_BEATING_with_ONE_S_0049af40);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_28,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar9 = local_24 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&param_1,s_One_side_could_be_favored_becaus_0049aef4);
    uStack_4 = 1;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_less_adverse_tide_on_one_side__o_0049aea0);
    uStack_4 = 2;
    (*pcVar1)(this,local_28,iVar9 + iVar8,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + iVar8 + iVar8;
    FUN_0046bf33(&param_1,s_shift_is_one_that_does_not_shift_0049ae48);
    uStack_4 = 3;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_The_boats_are_even__Boat_A_expec_0049adf0);
    uStack_4 = 4;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 5;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&param_1,s_After_they_sail_some_distance__t_0049ada8);
    uStack_4 = 6;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + iVar8;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 7;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&param_1,s_Boat_A_has_made_a_significant_ga_0049ad78);
    uStack_4 = 8;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_If_the_wind_goes_farther_right__B_0049ad18);
    uStack_4 = 9;
    (*pcVar1)(this,local_28,iVar9 + local_24,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24 + iVar8;
    FUN_0046bf33(&param_1,s_However__that_would_be_risky__If_0049acbc);
    uStack_4 = 10;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + iVar8;
    FUN_0046bf33(&param_1,s_and_lose_much_distance__Also__if_0049ac60);
    uStack_4 = 0xb;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + iVar8;
    FUN_0046bf33(&param_1,s_be_hopelessly_behind__0049ac48);
    uStack_4 = 0xc;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xd;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(&param_1,s_The_wind_goes_another_10_degrees_0049abe8);
    uStack_4 = 0xe;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&param_1,s_When_one_side_is_favored__the_be_0049ab84);
    uStack_4 = 0xf;
    (*pcVar1)(this,local_28,iVar9 + local_24,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24 + iVar8;
    FUN_0046bf33(&param_1,s_However__one_must_be_careful_not_0049ab20);
    uStack_4 = 0x10;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + iVar8;
    FUN_0046bf33(&param_1,s_oscillating__one_probably_should_0049aabc);
    uStack_4 = 0x11;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar9 = iVar9 + local_24;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0);
    }
    FUN_0046bf33(&param_1,s_If_somewhat_in_doubt_that_one_si_0049aa5c);
    uStack_4 = 0x12;
    (*pcVar1)(this,local_28,iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_Instead__try_to_stay_on_the_favo_0049aa18);
    uStack_4 = 0x13;
    (*pcVar1)(this,local_28,iVar8 + iVar9,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  FUN_0044d830((int)this,local_28,iVar8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00442db8;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00442db8;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00442db8:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 3;
  FUN_0044d6d0((int)this,iVar8);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,iVar9,iVar3,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x14;
  (*pcVar1)(this,DAT_004a763c / 100 + iVar9,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004a6774 == 0) {
    DAT_004ac840 = DAT_004a6774;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iVar4,iVar5);
    param_1 = (CDC *)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x15;
    (*pcVar1)(this,iVar4 - (int)param_1,iVar5 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iVar4,iVar5);
    param_1 = (CDC *)(DAT_004a763c / 10);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x16;
    (*pcVar1)(this,iVar4 - (int)param_1,iVar5 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    pcVar2 = *(code **)(*(int *)this + 0x38);
    (*pcVar2)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar4 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)apCStack_18,0,iVar4);
    CDC::LineTo(this,DAT_004a763c,iVar4);
    (*pcVar2)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x17;
    (*pcVar1)(this,DAT_004a763c / 5,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcVar2)(this,0);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    param_1 = (CDC *)(DAT_004a763c / 0x14);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 0xffffffff;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar4,puVar6,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x18;
    (*pcVar1)(this,(int)(param_1 + iVar4),(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    param_1 = (CDC *)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar4,puVar6,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x19;
    (*pcVar1)(this,iVar4 - (int)param_1,(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    DAT_004ac840 = -10;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    CDC::LineTo(this,iVar4,iVar5);
    param_1 = (CDC *)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1a;
    (*pcVar1)(this,iVar4 - (int)param_1,iVar5 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    CDC::LineTo(this,iVar4,iVar5);
    param_1 = (CDC *)(DAT_004a763c / 10);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1b;
    (*pcVar1)(this,iVar4 - (int)param_1,iVar5 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    pcVar2 = *(code **)(*(int *)this + 0x38);
    (*pcVar2)(this,0);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    param_1 = (CDC *)(DAT_004a763c / 0x14);
    if (DAT_004a6774 == 1) {
      DAT_004aa734 = 0xffffffff;
      DAT_004ac01c = 0x23;
    }
    else {
      DAT_004aa734 = 1;
      DAT_004ac01c = 0x145;
    }
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar4,puVar6,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x1c;
    (*pcVar1)(this,(int)(param_1 + iVar4),(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar4,(int)puVar6);
    CDC::LineTo(this,DAT_004a763c / 5,(int)puVar6 - DAT_004a72d0 / 10);
    (*pcVar2)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x1d;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,(int)puVar6 - DAT_004a72d0 / 0x14,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcVar2)(this,0);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    param_1 = (CDC *)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x145;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar4,puVar6,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x1e;
    (*pcVar1)(this,iVar4 - (int)param_1,(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (DAT_004a6774 == 3) {
    DAT_004ac840 = -0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar4 = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    iVar5 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,iVar4,iVar5);
    param_1 = (CDC *)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1f;
    (*pcVar1)(this,iVar4 - (int)param_1,iVar5 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,iVar9,iVar3);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    iVar3 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,iVar9,iVar3);
    param_1 = (CDC *)(DAT_004a763c / 10);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x20;
    (*pcVar1)(this,iVar9 - (int)param_1,iVar3 + iVar8 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    pcVar2 = *(code **)(*(int *)this + 0x38);
    (*pcVar2)(this,0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    DAT_004aa734 = 1;
    param_1 = (CDC *)(DAT_004a763c / 0x14);
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar9,puVar6,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x21;
    (*pcVar1)(this,(int)(param_1 + iVar9),(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apCStack_18,iVar9,(int)puVar6);
    CDC::LineTo(this,DAT_004a763c / 5,(int)puVar6 - DAT_004a72d0 / 5);
    (*pcVar2)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x22;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,(int)puVar6 - DAT_004a72d0 / 10,(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcVar2)(this,0);
    iVar9 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar6 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    param_1 = (CDC *)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar9,puVar6,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x23;
    (*pcVar1)(this,iVar9 - (int)param_1,(int)(puVar6 + iVar8),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

