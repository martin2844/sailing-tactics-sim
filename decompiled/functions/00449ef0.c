
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00449ef0(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  CDC *pCVar3;
  double dVar4;
  CDC *this;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_20;
  int local_1c;
  int local_18;
  LPCSTR pCStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  DAT_004aca3c = DAT_004abb7c;
  DAT_004aca38 = DAT_004abb78;
  DAT_004aca34 = DAT_004abb74;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar4 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_00480128;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004aca48 = DAT_004abb88;
  DAT_004a600c = (int)(longlong)dVar4;
  if (DAT_004a763c < 700) {
    local_18 = 0x10;
    local_1c = 0x16;
    local_20 = 5;
  }
  else {
    local_1c = 0x1b;
    local_18 = 0x14;
    local_20 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___MARK_ROUNDING___0049db88);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,local_20,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = local_18 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xff0000);
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&param_1,s_Rounding_a_mark_with_other_boats_0049db30);
    uStack_4 = 1;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_race_since_the_outside_boat_must_0049daf8);
    uStack_4 = 2;
    (*pcVar1)(this,local_20,iVar5 + local_18,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18 + local_1c;
    FUN_0046bf33(&param_1,s_Roundings_are_especially_importa_0049daa0);
    uStack_4 = 3;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_the_outside_boats_usually_start_t_0049da64);
    uStack_4 = 4;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boats_A__B__C__and_D_are_approac_0049da1c);
    uStack_4 = 5;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_Boats_B_and_C_will_have_to_give_r_0049d9c4);
    uStack_4 = 6;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_inside_overlap_on_both_B_and_C__B_0049d964);
    uStack_4 = 7;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&param_1,s_As_they_go_around__Boat_A_sails_t_0049d918);
    uStack_4 = 8;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boat_D_intentionally_slows_down_a_0049d8c4);
    uStack_4 = 9;
    (*pcVar1)(this,local_20,iVar5 + local_1c,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_1c + local_18;
    FUN_0046bf33(&param_1,s_the_outside_boat__Boat_D_will_no_0049d870);
    uStack_4 = 10;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_avoid_a_sharp__speed_killing_tur_0049d820);
    uStack_4 = 0xb;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    iVar5 = iVar5 + local_1c;
    FUN_0046bf33(&param_1,s_Boat_A_would_like_a_gradual_turn_0049d7cc);
    uStack_4 = 0xc;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_a_leeward__right_of_way__boat__U_0049d778);
    uStack_4 = 0xd;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_rounding_but_not_enough_for_a_ta_0049d738);
    uStack_4 = 0xe;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&param_1,s_Boat_A_has_the_lead__clear_air__a_0049d700);
    uStack_4 = 0xf;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_Boat_B_and_boat_C_have_bad_air_a_0049d6b8);
    uStack_4 = 0x10;
    (*pcVar1)(this,local_20,iVar5 + local_18,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&param_1,s_Boat_D_is_in_bad_air_but_can_tac_0049d660);
    uStack_4 = 0x11;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_18;
    FUN_0046bf33(&param_1,s_pack_rather_than_outside_it_when_0049d614);
    uStack_4 = 0x12;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&param_1,s_If_the_next_were_a_run_or_broad_r_0049d5bc);
    uStack_4 = 0x13;
    (*pcVar1)(this,local_20,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0);
    }
    FUN_0046bf33(&param_1,s_It_almost_never_pays_to_round_in_0049d564);
    uStack_4 = 0x14;
    (*pcVar1)(this,local_20,iVar5 + local_18,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  FUN_0044d830((int)this,local_20,local_18);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0044a595;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0044a595;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0044a595:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 2;
  FUN_0044d6d0((int)this,local_18);
  DAT_004ac994 = 2;
  uStack_10 = DAT_004a4e8c;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 == 0) {
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      DAT_004abb74 = 1;
      DAT_004abb78 = 1;
      DAT_004abb7c = 1;
      DAT_004abb88 = 1;
    }
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004852c0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar5 = DAT_004a763c / 0xf;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 5;
    _DAT_004a77ec = 0x1e;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x82;
    DAT_004a7bcc = 0x78;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x15;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004853e0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar5 = DAT_004a763c / 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 5;
    _DAT_004a77f0 = 0x1e;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x82;
    DAT_004a7bd0 = 0x78;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x16;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    iVar5 = DAT_004a763c / 0xf;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 5;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x82;
    _DAT_004a7bd4 = 0x78;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x17;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar5 = DAT_004a763c / 0x19;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a6ee0 = 5;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x82;
    _DAT_004a7be0 = 0x78;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x18;
    (*pcVar1)(this,(int)param_1 - iVar5,(int)(puVar2 + local_18 + 4),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 1) {
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      DAT_004abb74 = 0;
      DAT_004abb78 = 0;
      DAT_004abb7c = 0;
      DAT_004abb88 = 0;
    }
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),3,1);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar5 = DAT_004a763c / 0xf;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 5;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x78;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_A_004994e4);
    uStack_4 = 0x19;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar5 = DAT_004a763c / 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 5;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 100;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_B_004994ec);
    uStack_4 = 0x1a;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar5 = DAT_004a763c / 0xf;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x14;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 100;
    _DAT_004a7bd4 = 0x6e;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x1b;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar5 = DAT_004a763c / 0x19;
    _DAT_004ac030 = 0x6e;
    _DAT_004a7be0 = 0x6e;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a6ee0 = 5;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    FUN_00411000(this,(int)param_1,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_D_0049ca40);
    uStack_4 = 0x1c;
    (*pcVar1)(this,(int)param_1 - iVar5,(int)(puVar2 + local_18 + 4),pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004a6774 == 2) {
    FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar5 = DAT_004a763c / 0x14;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x2d;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    FUN_00411000(this,(int)param_1,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,&DAT_0049d560);
    uStack_4 = 0x1d;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2 - local_18,pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar5 = DAT_004a763c / 0x14;
    DAT_004aa738 = 0xffffffff;
    DAT_004ac020 = 0x30;
    DAT_004a7bd0 = 0x30;
    _DAT_004a6ed0 = 10;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x32;
    DAT_004a6340 = 0xf;
    FUN_00411000(this,(int)param_1,puVar2,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,&DAT_0049d55c);
    uStack_4 = 0x1e;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2 - local_18,pCStack_14,
              *(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    param_1 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    iVar5 = DAT_004a763c / 0xf;
    _DAT_004ac024 = 0x33;
    _DAT_004a7bd4 = 0x33;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 10;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x28;
    _DAT_004a6344 = 0xf;
    FUN_00411000(this,(int)param_1,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_14,s_Boat_C_0049ca48);
    uStack_4 = 0x1f;
    (*pcVar1)(this,(int)(param_1 + iVar5),(int)puVar2,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    pCVar3 = (CDC *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar5 = DAT_004a763c / 0x19;
    _DAT_004a6ee0 = 0xf;
    _DAT_004a6350 = 0xf;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004ac030 = 0x2d;
    _DAT_004a7be0 = 0x2d;
    param_1 = pCVar3;
    FUN_00411000(this,(int)pCVar3,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_D_0049ca40);
    uStack_4 = 0x20;
    (*pcVar1)(this,(int)pCVar3 - iVar5,(int)(puVar2 + local_18 + 4),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004abb74 = DAT_004aca34;
  DAT_004abb78 = DAT_004aca38;
  DAT_004abb88 = DAT_004aca48;
  DAT_004abb7c = DAT_004aca3c;
  DAT_004ac994 = 0;
  DAT_004a4e8c = uStack_10;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

