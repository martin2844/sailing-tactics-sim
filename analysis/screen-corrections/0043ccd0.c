
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043ccd0(CDC *param_1)

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
  int local_28;
  LPCSTR pCStack_24;
  int local_20;
  int local_1c;
  LPCSTR apCStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f4c0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar4;
  if (DAT_004a763c < 700) {
    iVar5 = 0x10;
    local_20 = 0x16;
    local_28 = 5;
    local_1c = 10;
  }
  else {
    iVar5 = 0x14;
    local_20 = 0x1b;
    local_28 = 0x14;
    local_1c = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___LIFTS_WHILE_BEATING___00499c3c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_28,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  param_1 = (CDC *)(local_20 + 2);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  param_1 = param_1 + iVar5;
  if (DAT_004a6774 == 0) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&pCStack_24,s_A_lift_is_a_windshift_that_lets_a_00499be8);
    uStack_4 = 1;
    (*pcVar1)(this,local_28,(int)param_1,pCStack_24,*(int *)(pCStack_24 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_24);
    param_1 = param_1 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&pCStack_24,s_Boats_A_and_B_are_initially_even_00499bc4);
    uStack_4 = 2;
    (*pcVar1)(this,local_28,(int)param_1,pCStack_24,*(int *)(pCStack_24 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_24);
    param_1 = param_1 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(&pCStack_24,s_Click_the_Advance_Position_Butto_00499b8c);
    uStack_4 = 3;
    (*pcVar1)(this,local_28,(int)param_1,pCStack_24,*(int *)(pCStack_24 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_24);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(apCStack_18,s_Boat_A_has_just_gained_a_lot__00499b6c);
    pCStack_24 = (LPCSTR)(local_28 + local_1c);
    uStack_4 = 4;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + local_20;
    FUN_0046bf33(apCStack_18,s_Notice_that_the_laylines_and_the_00499b24);
    uStack_4 = 5;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(apCStack_18,s_Click_the_Advance_Position_Butto_00499ae4);
    uStack_4 = 6;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(apCStack_18,s_Boat_A_has_gained_30___of_the_se_00499a8c);
    pCStack_24 = (LPCSTR)(local_28 + local_1c);
    uStack_4 = 7;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(apCStack_18,s_about_two_boat_lengths__If_the_b_00499a38);
    uStack_4 = 8;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(apCStack_18,s_occurred__Boat_A_would_have_gain_00499a04);
    uStack_4 = 9;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(apCStack_18,s_If_the_shift_was_only_10_degrees_004999bc);
    uStack_4 = 10;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + local_20;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff);
    }
    FUN_0046bf33(apCStack_18,s_Click_the_Advance_Position_Butto_00499984);
    uStack_4 = 0xb;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(apCStack_18,s_Using_the_compass_to_detect_a_wi_00499958);
    pCStack_24 = (LPCSTR)(local_28 + local_1c);
    uStack_4 = 0xc;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(apCStack_18,s_If_a_closehauled_boat_is_being_s_004998fc);
    uStack_4 = 0xd;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(apCStack_18,s_true_wind_changes_20_degrees_pro_004998a0);
    uStack_4 = 0xe;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = param_1 + iVar5;
    FUN_0046bf33(apCStack_18,s_crew_compares_the_compass_course_00499844);
    uStack_4 = 0xf;
    (*pcVar1)(this,(int)pCStack_24,(int)param_1,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_0046bf33(apCStack_18,s_much_the_wind_has_shifted__00499828);
    uStack_4 = 0x10;
    (*pcVar1)(this,(int)pCStack_24,(int)(param_1 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  FUN_0044d830((int)this,local_28,iVar5);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0043d323;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0043d323;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0043d323:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 3;
  FUN_0044d6d0((int)this,iVar5);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  local_20 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
  local_1c = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,local_20,local_1c,4,1);
  FUN_0046bf33(&param_1,&DAT_00493460);
  uStack_4 = 0x11;
  (*pcVar1)(this,DAT_004a763c / 100 + local_20,local_1c,(LPCSTR)param_1,*(int *)(param_1 + -8));
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
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x12;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x19);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x13;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = *(CDC **)(*(int *)this + 0x38);
    (*(code *)param_1)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)apCStack_18,0,iVar2);
    CDC::LineTo(this,DAT_004a763c,iVar2);
    (*(code *)param_1)(this,0x7f00);
    FUN_0046bf33(apCStack_18,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x14;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,iVar2,apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    (*(code *)param_1)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 10);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x15;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x16;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (DAT_004a6774 == 1) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x17;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x19);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x18;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = *(CDC **)(*(int *)this + 0x38);
    (*(code *)param_1)(this,0);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)apCStack_18,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0));
    CDC::LineTo(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8));
    (*(code *)param_1)(this,0x7f00);
    FUN_0046bf33(apCStack_18,s_Equal_Position_Line_004994f4);
    uStack_4 = 0x19;
    (*pcVar1)(this,(DAT_004a763c * 2) / 5,(int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),
              apCStack_18[0],*(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    (*(code *)param_1)(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dc0);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 10);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x1a;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 1;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x14f;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x1b;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
  }
  if (1 < DAT_004a6774) {
    DAT_004ac840 = 0xffffffec;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x32);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1c;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    FUN_004706bd(this,(int *)apCStack_18,local_20,local_1c);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar2 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)param_1,iVar2);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0x19);
    FUN_0046bf33(apCStack_18,s_LayLine_00499508);
    uStack_4 = 0x1d;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,iVar2 + iVar5 * -2,apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    (**(code **)(*(int *)this + 0x38))(this,0);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 10);
    DAT_004a6ecc = 0xf;
    DAT_004a633c = 0xf;
    DAT_004aa734 = 1;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004ac01c = 0x14f;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,1,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_A_004994e4);
    uStack_4 = 0x1e;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
              *(int *)(apCStack_18[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_18);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar3 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    pCStack_24 = (LPCSTR)(DAT_004a763c / 0xe);
    _DAT_004a6ed0 = 0xf;
    DAT_004a6340 = 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004ac020 = 0x41;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)param_1,puVar3,2,1,DAT_004a72d0,0);
    FUN_0046bf33(apCStack_18,s_Boat_B_004994ec);
    uStack_4 = 0x1f;
    (*pcVar1)(this,(int)param_1 - (int)pCStack_24,(int)(puVar3 + iVar5),apCStack_18[0],
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

