
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00443bf0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *this;
  code *pcVar3;
  int iVar4;
  undefined4 unaff_EBX;
  code *pcVar5;
  code *pcVar6;
  int iVar7;
  code *unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  int iVar8;
  undefined *puVar9;
  CDC *pCVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined1 *puVar15;
  HDC hdc;
  HGDIOBJ h;
  undefined *puStack_4c;
  int iStack_48;
  CDC *pCStack_44;
  undefined *local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int aiStack_1c [2];
  undefined4 uStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047fb50;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar7 = 0x10;
    local_28 = 0x16;
    local_2c = &DAT_00000005;
  }
  else {
    iVar7 = 0x14;
    local_28 = 0x1b;
    local_2c = (undefined1 *)0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_44 = (CDC *)0x443c6f;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_44 = (CDC *)0x443c7d;
  FUN_0046bf33(&param_1,s___STRATEGY_for_DOWNWIND_LEGS___0049b6a8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  pcVar11 = *(code **)(param_1 + -8);
  pCStack_44 = param_1;
  iStack_48 = 2;
  puStack_4c = local_2c;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  pcVar6 = unaff_ESI + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&iStack_c,s_Reaching_legs_are_generally_not_s_0049b64c);
    uStack_14 = 1;
    iVar8 = unaff_EDI;
    pcVar5 = pcVar6;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_off_in_the_puffs__head_up_in_the_0049b5f8);
    uStack_24 = 2;
    puVar9 = puStack_4c;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    pcVar5 = pcVar6 + iVar7 * 3 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_Strategy_on_runs_depends_on_the_b_0049b59c);
    iVar14 = iVar8;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    FUN_0046bf33(&stack0xffffffc4,s_or_single_sail_boats_make_best_d_0049b548);
    pCStack_44 = (CDC *)0x4;
    puVar15 = puVar9;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_4c);
    FUN_0046bf33(&puStack_4c,s_Even_so__course_diversions_of_15_0049b4f4);
    pcVar6 = pcVar5;
    (*pcVar1)(iVar8,pcVar5,puStack_4c,*(undefined4 *)(puStack_4c + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&stack0xffffffa4,s_steer_to_get_stronger_wind__avoi_0049b4ac);
    (*pcVar1)(puVar9,pcVar5 + iVar7,iVar14,*(undefined4 *)(iVar14 + -8));
    FUN_0046bec5((int *)&stack0xffffff94);
    pcVar6 = pcVar5 + iVar7 + (int)pcVar6;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0xff);
    }
    FUN_0046bf33(&stack0xffffff94,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)(iVar8,pcVar6,puVar15,*(undefined4 *)(puVar15 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&iStack_c,s_High_performance_boats_such_as_c_0049b44c);
    uStack_14 = 8;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_spinnakers_make_best_progress_do_0049b3f0);
    uStack_24 = 9;
    pcVar5 = pcVar6 + iVar7;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    FUN_0046bf33(&local_2c,s_shifty_winds__these_boats_can_si_0049b388);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    pcVar6 = pcVar6 + iVar7 + iVar7 * 2 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    pCStack_44 = (CDC *)0xb;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&iStack_c,s_The_boats_sail_for_some_distance_0049b324);
    uStack_14 = 0xc;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_The_Laylines_and_the_Equal_Posit_0049b2e4);
    uStack_24 = 0xd;
    pcVar5 = pcVar6 + iVar7;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    FUN_0046bf33(&local_2c,s_Boat_A_has_made_a_significant_ga_0049b284);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    pcVar6 = pcVar6 + iVar7 + iVar7 * 2 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    pCStack_44 = (CDC *)0xf;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 3) {
    FUN_0046bf33(&iStack_c,s_Both_boats_jibe__0049b270);
    uStack_14 = 0x10;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_If_Boat_A_can_get_between_Boat_B_0049b21c);
    uStack_24 = 0x11;
    pcVar5 = pcVar6 + iVar7;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    FUN_0046bf33(&local_2c,s_not_be_lost_by_a_wind_shift__0049b1fc);
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    pcVar6 = pcVar6 + iVar7 + iVar7 * 2 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_Click_the_Advance_Position_Butto_00499e34);
    pCStack_44 = (CDC *)0x13;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 4) {
    FUN_0046bf33(&iStack_c,s_Both_boats_sail_some_distance__B_0049b1b4);
    uStack_14 = 0x14;
    pcVar5 = pcVar6;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    FUN_0046bf33(aiStack_1c,s_by_being_farther_downwind_when_t_0049b180);
    uStack_24 = 0x15;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    pcVar6 = pcVar6 + iVar7 * 2 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&local_2c,s_Click_the_Advance_Position_Butto_00499e34);
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 5) {
    FUN_0046bf33(&iStack_c,s_Principles_for_using_wind_shifts_0049b148);
    uStack_14 = 0x17;
    iVar8 = unaff_EDI;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_1c);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(aiStack_1c,s_If_a_persistent_shift_is_expecte_0049b0e8);
    uStack_24 = 0x18;
    puVar9 = puStack_4c;
    pcVar5 = pcVar6 + iVar7;
    (*pcVar1)();
    FUN_0046bec5((int *)&local_2c);
    FUN_0046bf33(&local_2c,s_after_the_shift__If_the_wind_wil_0049b09c);
    iVar14 = iVar8;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
    pcVar5 = pcVar6 + iVar7 + iVar7 + (int)pcVar5;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffc4,s_If_an_oscillating_wind_is_expect_0049b03c);
    pCStack_44 = (CDC *)0x1a;
    pcVar6 = pcVar5;
    puVar15 = puVar9;
    (*pcVar1)();
    FUN_0046bec5((int *)&puStack_4c);
    pcVar5 = pcVar5 + iVar7;
    FUN_0046bf33(&puStack_4c,s_the_tack_that_points_closer_to_t_0049b010);
    (*pcVar1)(iVar8,pcVar5,puStack_4c,*(undefined4 *)(puStack_4c + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0);
    }
    FUN_0046bf33(&stack0xffffffa4,s_Caution__Sailing_downwind__wind_s_0049afb4);
    (*pcVar1)(puVar9,pcVar5 + (int)pcVar6,iVar14,*(undefined4 *)(iVar14 + -8));
    FUN_0046bec5((int *)&stack0xffffff94);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(0);
    }
    FUN_0046bf33(&stack0xffffff94,s_If_other_boats_have_a_lot_more_w_0049af70);
    (*pcVar1)(iVar8,pcVar5 + (int)pcVar6 + iVar7,puVar15,*(undefined4 *)(puVar15 + -8));
    uStack_14 = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  FUN_0044d830((int *)this,unaff_EDI,iVar7);
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
  FUN_0044d6d0((int *)this);
  DAT_004ac994 = 2;
  uStack_20 = DAT_004a4e8c;
  DAT_004a4e8c = 2;
  _DAT_004a6834 = 0;
  local_2c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484d98);
  FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484da8),(int)local_2c,4,1);
  FUN_0046bf33(&iStack_c,&DAT_00493460);
  uStack_14 = 0x1e;
  pcVar6 = *(code **)(iStack_c + -8);
  iVar8 = iStack_c;
  (*pcVar1)();
  uStack_24 = 0xffffffff;
  FUN_0046bec5(aiStack_1c);
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
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iStack_48 = DAT_004a763c / 0x14;
    _DAT_004a77ec = 0x3c;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0xf;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    DAT_004a7bcc = 0xb4;
    FUN_00411000(this,aiStack_1c[0],puStack_4c,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffc0,s_Boat_A_004994e4);
    uStack_24 = 0x1f;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffb0);
    local_2c = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    _DAT_004a77f0 = 0x3c;
    DAT_004a7068 = 0x3c;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x159;
    DAT_004a7bd0 = 0xb4;
    FUN_00411000(this,(int)local_2c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffb0,s_Boat_B_004994ec);
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
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
    pcVar5 = pcVar6;
    if (DAT_004ac854 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004ac854);
      pcVar5 = pcVar6;
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_44,unaff_EDI);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,aiStack_1c[0],(int)puStack_4c);
    iStack_48 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc0,s_LayLine_00499508);
    uStack_24 = 0x21;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffb0);
    FUN_004706bd(this,&iStack_48,iVar8,(int)puStack_4c);
    local_2c = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar14 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484de8);
    CDC::LineTo(this,(int)local_2c,iVar14);
    iVar4 = DAT_004a763c / 10;
    FUN_0046bf33(&stack0xffffffb0,s_LayLine_00499508);
    pcVar3 = (code *)(iVar14 + iVar7 * -2);
    iVar4 = (int)local_2c - iVar4;
    pcVar6 = pcVar5;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa0);
    (**(code **)(*(int *)this + 0x38))();
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    iVar14 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    FUN_004706bd(this,(int *)&stack0xffffffa4,0,iVar14);
    CDC::LineTo(this,DAT_004a763c,iVar14);
    (*pcVar11)();
    FUN_0046bf33(&pCStack_44,s_Equal_Position_Line_004994f4);
    puStack_4c = (undefined1 *)0x23;
    pCVar10 = pCStack_44;
    (*pcVar1)(DAT_004a763c / 6,pcVar5);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar3)(0);
    iVar14 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar9 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar13 = DAT_004a763c / 0x14;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x87;
    FUN_00411000(this,iVar14,puVar9,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff84,s_Boat_A_004994e4);
    (*pcVar1)(iVar13 + iVar14,puVar9 + iVar7,iVar4,*(undefined4 *)(iVar4 + -8));
    FUN_0046bec5((int *)&stack0xffffff74);
    iVar14 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar9 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0);
    iVar4 = DAT_004a763c / 0xe;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 0;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x87;
    FUN_00411000(this,iVar14,puVar9,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff74,s_Boat_B_004994ec);
    (*pcVar1)(iVar14 - iVar4,puVar9 + iVar7,pCVar10,*(undefined4 *)(pCVar10 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc0);
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
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_44,unaff_EDI);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,aiStack_1c[0],(int)puStack_4c);
    iStack_48 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc0,s_LayLine_00499508);
    uStack_24 = 0x26;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffb0);
    FUN_004706bd(this,&iStack_48,iVar8,(int)puStack_4c);
    local_2c = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    pcVar11 = (code *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)local_2c,(int)pcVar11);
    FUN_0046bf33(&stack0xffffffb0,s_LayLine_00499508);
    pcVar5 = pcVar6;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa0);
    iVar13 = 0;
    (**(code **)(*(int *)this + 0x38))();
    iVar14 = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    iVar4 = DAT_004a763c / 0x14;
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
    FUN_00411000(this,iVar14,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,DAT_004a72d0
                 ,0);
    FUN_0046bf33(&stack0xffffffa4,s_Boat_A_004994e4);
    iStack_48 = 0x28;
    iVar12 = *(int *)(pcVar11 + -8);
    (*pcVar1)(iVar4 + iVar14);
    FUN_0046bec5((int *)&stack0xffffff94);
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffff94,(int)pcVar5,iVar13);
    CDC::LineTo(this,DAT_004a763c / 10,iVar13 - DAT_004a72d0 / 10);
    (*pcVar6)(0x7f00);
    FUN_0046bf33(&stack0xffffffac,s_Equal_Position_Line_004994f4);
    (*pcVar1)((DAT_004a763c * 2) / 5,iVar12 - DAT_004a72d0 / 0x1e,iVar8,*(undefined4 *)(iVar8 + -8))
    ;
    FUN_0046bec5((int *)&stack0xffffff9c);
    (*pcVar11)(0);
    iVar14 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    puVar9 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar4 = DAT_004a763c / 0xe;
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
    FUN_00411000(this,iVar14,puVar9,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff7c,s_Boat_B_004994ec);
    (*pcVar1)(iVar14 - iVar4,puVar9 + iVar7,iVar12,*(undefined4 *)(iVar12 + -8));
    uStack_24 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc8);
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
      (**(code **)(*(int *)this + 0x38))();
    }
    FUN_004706bd(this,(int *)&stack0xffffffc8,(int)pCStack_44,unaff_EDI);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484dd8);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    CDC::LineTo(this,aiStack_1c[0],(int)puStack_4c);
    iStack_48 = DAT_004a763c / 0x32;
    FUN_0046bf33(&stack0xffffffc8,s_LayLine_00499508);
    uStack_24 = 0x2b;
    (*pcVar1)();
    FUN_0046bec5(&iStack_48);
    FUN_004706bd(this,&iStack_48,iVar8,(int)puStack_4c);
    local_2c = (undefined *)(longlong)(_DAT_004aa810 * _DAT_00484d70);
    iVar8 = (int)(longlong)(_DAT_004aa7d8 * _DAT_00484e50);
    CDC::LineTo(this,(int)local_2c,iVar8);
    FUN_0046bf33(&iStack_48,s_LayLine_00499508);
    pcVar6 = (code *)(iVar8 + iVar7 * -2);
    iVar14 = iStack_48;
    (*pcVar1)();
    pCStack_44 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffa8);
    (**(code **)(*(int *)this + 0x38))();
    iVar7 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    puVar9 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484da0);
    iVar8 = DAT_004a763c / 0x14;
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
    FUN_00411000(this,iVar7,puVar9,1,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 4) {
      FUN_0046bf33(&stack0xffffffa4,s_Boat_A_004994e4);
      iStack_48 = 0x2d;
      (*pcVar1)(iVar8 + iVar7);
      iStack_48 = -1;
      FUN_0046bec5((int *)&stack0xffffffa4);
    }
    if (DAT_004a3c0c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3c0c);
    }
    FUN_004706bd(this,(int *)&stack0xffffffa4,iVar7,(int)puVar9);
    CDC::LineTo(this,DAT_004a763c / 10,(int)puVar9 - DAT_004a72d0 / 10);
    (*unaff_ESI)();
    FUN_0046bf33(&pCStack_44,s_Equal_Position_Line_004994f4);
    puStack_4c = (undefined *)0x2e;
    (*pcVar1)(DAT_004a763c / 6,iVar14 - DAT_004a72d0 / 0x1e);
    FUN_0046bec5((int *)&stack0xffffffac);
    (*pcVar6)(0);
    aiStack_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puStack_4c = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iStack_48 = DAT_004a763c / 0xe;
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
    FUN_00411000(this,aiStack_1c[0],puStack_4c,2,1,DAT_004a72d0,0);
    if (DAT_004a6774 == 4) {
      FUN_0046bf33(&stack0xffffffc8,s_Boat_B_004994ec);
      uStack_24 = 0x2f;
      (*pcVar1)();
      uStack_24 = 0xffffffff;
      FUN_0046bec5((int *)&stack0xffffffc8);
    }
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004ac900 = DAT_004a3a0c;
  DAT_004abb74 = 0;
  DAT_004abb78 = 0;
  DAT_00491188 = DAT_004a6488;
  DAT_004ac908 = DAT_004a4bdc;
  DAT_004ac904 = DAT_004a6488;
  DAT_004a4e8c = unaff_EBX;
  *unaff_FS_OFFSET = (int)local_2c;
  return;
}

