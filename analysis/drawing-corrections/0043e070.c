
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043e070(CDC *param_1)

{
  code *pcVar1;
  code *pcVar2;
  undefined *puVar3;
  int iVar4;
  double dVar5;
  CDC *this;
  int iVar6;
  LPCSTR pCVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_30;
  int local_2c [2];
  int local_24;
  code *apcStack_20 [2];
  LPCSTR apCStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar5 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f5e0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar5;
  if (DAT_004a763c < 700) {
    iVar8 = 0x10;
    local_30 = 0x16;
    local_2c[0] = 5;
    local_24 = 10;
  }
  else {
    iVar8 = 0x14;
    local_30 = 0x1b;
    local_2c[0] = 0x14;
    local_24 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___HEADERS_WHILE_BEATING___0049a094);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_2c[0],2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar6 = local_30 + 2;
  if (DAT_004a6774 == 0) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&param_1,s_A_header_is_a_windshift_that_for_0049a038);
    uStack_4 = 1;
    (*pcVar1)(this,local_2c[0],iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boats_A_and_B_are_initially_even_00499bc4);
    uStack_4 = 2;
    (*pcVar1)(this,local_2c[0],iVar6 + local_30,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + local_30 + local_30;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&param_1,s_Click_the_Advance_Position_Butto_00499ffc);
    uStack_4 = 3;
    (*pcVar1)(this,local_2c[0],iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(apcStack_20,s_Boat_A_has_gained_30___of_the_se_00499f98);
    param_1 = (CDC *)(local_24 + local_2c[0]);
    uStack_4 = 4;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_0046bf33(apcStack_20,s_boat_lengths__If_the_boats_had_b_00499f34);
    uStack_4 = 5;
    (*pcVar1)(this,(int)param_1,iVar6 + iVar8,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = iVar6 + iVar8 + iVar8;
    FUN_0046bf33(apcStack_20,s_gained_30___of_a_mile___If_the_s_00499ed4);
    uStack_4 = 6;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = iVar6 + local_30;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(apcStack_20,s_Problem__If_the_wind_shifts_back_00499e7c);
    uStack_4 = 7;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = iVar6 + iVar8;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(apcStack_20,s_To_consolidate_the_gain__A_tacks_00499e58);
    uStack_4 = 8;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    iVar6 = iVar6 + local_30;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(apcStack_20,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 9;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(apcStack_20,s_If_Boat_A_can_get_between_the_ma_00499de0);
    param_1 = (CDC *)(local_24 + local_2c[0]);
    uStack_4 = 10;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_0046bf33(apcStack_20,s_will_not_be_lost_by_a_wind_shift_00499dbc);
    uStack_4 = 0xb;
    (*pcVar1)(this,(int)param_1,iVar6 + iVar8,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = iVar6 + iVar8 + local_30;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(apcStack_20,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xc;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(apcStack_20,s_Boat_A_is_now_between_the_mark_a_00499d6c);
    param_1 = (CDC *)(local_24 + local_2c[0]);
    uStack_4 = 0xd;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_0046bf33(apcStack_20,s_In_order_to_stay_in_this_safe_po_00499d28);
    uStack_4 = 0xe;
    (*pcVar1)(this,(int)param_1,iVar6 + iVar8,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = iVar6 + iVar8 + local_30;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(apcStack_20,s_Click_the_Advance_Position_Butto_00499e34);
    uStack_4 = 0xf;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
  }
  if (DAT_004a6774 == 4) {
    FUN_0046bf33(apcStack_20,s_Boat_A_s_position_between_Boat_B_00499cd8);
    param_1 = (CDC *)(local_24 + local_2c[0]);
    uStack_4 = 0x10;
    (*pcVar1)(this,(int)param_1,iVar6,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_0046bf33(apcStack_20,s_Boat_A_s_lead_will_not_be_lost_b_00499ca8);
    uStack_4 = 0x11;
    (*pcVar1)(this,(int)param_1,iVar6 + iVar8,(LPCSTR)apcStack_20[0],*(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_0046bf33(apcStack_20,s_In_order_to_keep_this_position__B_00499c58);
    uStack_4 = 0x12;
    (*pcVar1)(this,(int)param_1,iVar6 + iVar8 + local_30,(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
  }
  FUN_0044d830((int)this,local_2c[0],iVar8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043e700;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043e700;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043e700:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 4;
  FUN_0044d6d0((int)this,iVar8);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  pCVar7 = (LPCSTR)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  local_24 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  apCStack_18[0] = pCVar7;
  FUN_0042cd40((int *)this,(int)pCVar7,local_24,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x13;
  (*pcVar1)(this,(int)(pCVar7 + DAT_004a763c / 100),local_24,(LPCSTR)param_1,*(int *)(param_1 + -8))
  ;
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
    FUN_004706bd(this,(int *)apcStack_20,(int)pCVar7,local_24);
    local_2c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,local_2c[0],(int)param_1);
    FUN_0046bf33(apcStack_20,s_LayLine_00499508);
    uStack_4 = 0x14;
    (*pcVar1)(this,local_2c[0],(int)(param_1 + iVar8 * -2),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_004706bd(this,(int *)apcStack_20,(int)pCVar7,local_24);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,iVar6,(int)param_1);
    iVar4 = DAT_004a763c / 0xe;
    FUN_0046bf33(apcStack_20,s_LayLine_00499508);
    uStack_4 = 0x15;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8 * -2),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    apcStack_20[0] = *(code **)(*(int *)this + 0x38);
    (*apcStack_20[0])(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar6 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,local_2c,0,iVar6);
    CDC::LineTo(this,DAT_004a763c,iVar6);
    (*apcStack_20[0])(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x16;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,iVar6,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*apcStack_20[0])(this,0);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar4 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar6,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_20,s_Boat_B_004994ec);
    uStack_4 = 0x17;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar4 = DAT_004a763c / 0xe;
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,iVar6,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_20,s_Boat_A_004994e4);
    uStack_4 = 0x18;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    pCVar7 = apCStack_18[0];
  }
  if ((DAT_004a6774 == 1) || (DAT_004a6774 == 2)) {
    DAT_004ac840 = 0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apcStack_20,(int)pCVar7,local_24);
    local_2c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,local_2c[0],(int)param_1);
    FUN_0046bf33(apcStack_20,s_LayLine_00499508);
    uStack_4 = 0x19;
    (*pcVar1)(this,local_2c[0],(int)(param_1 + iVar8 * -2),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    FUN_004706bd(this,(int *)apcStack_20,(int)pCVar7,local_24);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,iVar6,(int)param_1);
    iVar4 = DAT_004a763c / 0xe;
    FUN_0046bf33(apcStack_20,s_LayLine_00499508);
    uStack_4 = 0x1a;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8 * -2),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    pcVar2 = *(code **)(*(int *)this + 0x38);
    (*pcVar2)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apcStack_20,(int)(longlong)(_DAT_004aa810 * _DAT_00484de8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00485368));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    (*pcVar2)(this,0x7f00);
    FUN_0046bf33(&param_1,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x1b;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),
              (LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    (*pcVar2)(this,0);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar4 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar6,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_20,s_Boat_B_004994ec);
    uStack_4 = 0x1c;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar4 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 1) {
      DAT_004aa738 = DAT_004a6774;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x127;
      DAT_004a7bd0 = 0x2d;
    }
    if (DAT_004a6774 == 2) {
      DAT_004aa738 = -1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = DAT_004a6774;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x19;
      DAT_004a7bd0 = 0x2d;
    }
    FUN_00411000(this,iVar6,param_1,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apcStack_20,s_Boat_A_004994e4);
    uStack_4 = 0x1d;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8),(LPCSTR)apcStack_20[0],
              *(int *)(apcStack_20[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apcStack_20);
    pCVar7 = apCStack_18[0];
  }
  if ((DAT_004a6774 == 3) || (DAT_004a6774 == 4)) {
    DAT_004ac840 = 0x14;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,(int)pCVar7,local_24);
    local_2c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00485358);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,local_2c[0],(int)param_1);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1e;
    (*pcVar1)(this,local_2c[0],(int)(param_1 + iVar8 * -2),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,(int)pCVar7,local_24);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00485360);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,iVar6,(int)param_1);
    iVar4 = DAT_004a763c / 0xe;
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1f;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8 * -2),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    local_2c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iVar6 = DAT_004a763c / 0xe;
    if (DAT_004a6774 == 3) {
      DAT_004aa738 = -1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x19;
      DAT_004a7bd0 = 0x2d;
    }
    if (DAT_004a6774 == 4) {
      DAT_004aa738 = 1;
      _DAT_004a6ed0 = 0xf;
      _DAT_004a77f0 = 2;
      DAT_004a7068 = 0x3c;
      DAT_004a6340 = 0xf;
      DAT_004ac020 = 0x127;
      DAT_004a7bd0 = 0x2d;
    }
    FUN_00411000(this,local_2c[0],puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_A_004994e4);
    uStack_4 = 0x20;
    (*pcVar1)(this,iVar6 + local_2c[0],(int)puVar3 - iVar8,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    param_1 = (CDC *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar4 = DAT_004a763c / 10;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x127;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,iVar6,param_1,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x21;
    (*pcVar1)(this,iVar6 - iVar4,(int)(param_1 + iVar8),apCStack_18[0],*(int *)(apCStack_18[0] + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

