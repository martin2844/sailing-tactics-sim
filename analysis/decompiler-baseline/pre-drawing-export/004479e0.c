
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004479e0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  undefined4 uVar3;
  CDC *pCVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  int iVar10;
  int iStack_a4;
  CDC *pCVar11;
  HDC hdc;
  HGDIOBJ h;
  CDC *pCStack_34;
  int local_1c;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar4 = param_1;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484d98;
  pcStack_8 = FUN_00480010;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar9 = 0x10;
    local_1c = 5;
  }
  else {
    iVar9 = 0x14;
    local_1c = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_34 = (CDC *)0x447a5f;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_34 = (CDC *)0x447a6d;
  FUN_0046bf33(&param_1,s___STARTING___0049d54c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar4 + 100);
  pCStack_34 = param_1;
  (*pcVar1)();
  FUN_0046bec5(&iStack_c);
  iStack_c = iVar9 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar4 + 0x38))();
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&stack0xffffffdc,s_Starting_Objectives__in_usual_or_0049d518);
    iVar10 = unaff_EDI;
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    iVar5 = local_1c + iVar9;
    FUN_0046bf33(&pCStack_34,s_1__Freedom_to_tack_if_the_wind_i_0049d4bc);
    pCVar11 = pCStack_34;
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    unaff_EDI = unaff_EDI + iVar9;
    FUN_0046bf33(&stack0xffffffbc,s_Start_left_of_the_pack_if_the_le_0049d474);
    pCStack_34 = (CDC *)0x3;
    iVar6 = iVar10;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    FUN_0046bf33(&stack0xffffffac,s_2__Clear_air__0049d464);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    iVar6 = iVar6 + iVar9;
    FUN_0046bf33(&stack0xffffff9c,s_3__Start_where_you_are_upwind_of_0049d430);
    iVar8 = iVar10;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff8c);
    FUN_0046bf33(&stack0xffffff8c,s_4__Start_where_you_can_bail_out_i_0049d3fc);
    iVar7 = local_1c;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff7c);
    iVar8 = iVar8 + iVar6;
    if (DAT_004ac92c == 0) {
      iStack_a4 = 0x447c78;
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    iStack_a4 = 0x447c86;
    FUN_0046bf33(&stack0xffffff7c,s_If_you_have_really_good_boat_spe_0049d3b8);
    iStack_a4 = unaff_EBP;
    iVar6 = iVar10;
    (*pcVar1)(iVar10,iVar8);
    FUN_0046bec5((int *)&stack0xffffff6c);
    iVar7 = iVar7 + iVar9;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))(0);
    }
    FUN_0046bf33(&stack0xffffff6c,s_If_you_have_poor_boat_speed__obj_0049d35c);
    (*pcVar1)(local_1c,iVar7,pCVar11,*(undefined4 *)(pCVar11 + -8));
    FUN_0046bec5(&iStack_a4);
    iVar6 = iVar6 + iVar9;
    FUN_0046bf33(&iStack_a4,s_weather_end_to_have_freedom_to_t_0049d2fc);
    (*pcVar1)(iVar10,iVar6,iStack_a4,*(undefined4 *)(iStack_a4 + -8));
    FUN_0046bec5((int *)&stack0xffffffdc);
    iStack_c = iStack_c + iVar9;
    local_1c = iVar5;
  }
  if (DAT_004a6774 == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffdc,s_In_this_start__the_line_is_perpe_0049d2b0);
    iVar7 = iStack_c;
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = local_1c + 2;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&pCStack_34,s_If_the_wind_is_oscillating_or_th_0049d250);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    unaff_EDI = unaff_EDI + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffbc,s_If_the_left_side_becomes_favored_0049d210);
    pCStack_34 = (CDC *)0xc;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffac,s_If_Boat_C_has_a_sight_from_the_p_0049d1b4);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    FUN_0046bf33(&stack0xffffff9c,s_since_boats_in_the_middle_of_the_0049d16c);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff8c);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffff8c,s_To_have_clear_air__start_close_t_0049d108);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 2) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffdc,s_Another_start__This_time_the_pin_0049d0d8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 3) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffdc,s_Another_start__This_time_the_pin_0049d0d8);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = local_1c + 2;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&pCStack_34,s_Boat_A_has_a_lead__She_may_be_th_0049d084);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    unaff_EDI = unaff_EDI + iVar9;
    FUN_0046bf33(&stack0xffffffbc,s_pinching_to_avoid_bad_air__0049d068);
    pCStack_34 = (CDC *)0x13;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffac,s_If_the_left_side_of_the_course_b_0049d01c);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffff9c,s_If_the_wind_is_oscillating__Boat_0049cfc0);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff8c);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffff8c,s_If_Boat_E_tacks_first__and_the_r_0049cf5c);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 4) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffdc,s_Another_start__This_time_the_Com_0049cf20);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 5) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffdc,s_Another_start__This_time_the_Com_0049cf20);
    iVar7 = iStack_c;
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = local_1c + 2;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&pCStack_34,s_Boat_D_has_the_lead__clear_air__a_0049cee0);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    unaff_EDI = unaff_EDI + iVar7;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffbc,s_If_the_left_side_of_the_course_b_0049ce80);
    pCStack_34 = (CDC *)0x1a;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    FUN_0046bf33(&stack0xffffffac,s_favored__A_is_in_a_very_bad_posi_0049ce58);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar4 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_is_in_bad_air_but_can_tac_0049ce00);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff8c);
    FUN_0046bf33(&stack0xffffff8c,s_and_an_excellent_position_if_the_0049cdb4);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  FUN_0044d830((int *)pCVar4,unaff_EDI,iVar9);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_00448468;
    hdc = *(HDC *)(pCVar4 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_00448468;
    hdc = *(HDC *)(pCVar4 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_00448468:
  Rectangle(*(HDC *)(pCVar4 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 5;
  FUN_0044d6d0((int *)pCVar4);
  uVar3 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 < 2) {
    FUN_0042cd40((int *)pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00485398),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  }
  if ((DAT_004a6774 == 2) || (DAT_004a6774 == 3)) {
    FUN_0042cd40((int *)pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_004853a0),3,1);
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00485398),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853a8),0,1,DAT_004a72d0,0);
  }
  if ((DAT_004a6774 == 4) || (DAT_004a6774 == 5)) {
    FUN_0042cd40((int *)pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00485358),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_004853a8),3,1);
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_004853b0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853a0),0,1,DAT_004a72d0,0);
  }
  if (DAT_004a6774 == 0) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x20;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 5;
    _DAT_004a7804 = 0x28;
    _DAT_004a707c = 0x14;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    _DAT_004a7be0 = 0x41;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484d70),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853b8),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 1) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x25;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484de8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 2) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_00484db0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x2a;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853c8),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 5;
    _DAT_004a7804 = 0x28;
    _DAT_004a707c = 0x14;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    _DAT_004a7be4 = 0x41;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484d70),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485388),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 3) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853d0),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485328),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x2f;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484de8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853b8),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 4) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 300;
    _DAT_004a7bd4 = 0x3c;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484db8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004853c8),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x34;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 10;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x122;
    _DAT_004a7be0 = 0x46;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484e50),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004a707c = 0x3c;
    _DAT_004a7be4 = 0x3c;
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 10;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 300;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_004853d8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485088),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 5) {
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xc;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x13b;
    DAT_004a7bcc = 0x2d;
    FUN_00411000(pCVar4,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484dc0),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    (*pcVar1)();
    FUN_0046bec5((int *)&pCStack_34);
    local_1c = (int)(longlong)(_DAT_004aa810 * _DAT_00484f10);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xc;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(pCVar4,local_1c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_004852f0),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&pCStack_34,s_Boat_B_004994ec);
    (*pcVar1)();
    pCStack_34 = (CDC *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffbc);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xc;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x3c;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x13b;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484da0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    pCStack_34 = (CDC *)0x39;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffac);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xc;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00484dc0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00485300),6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffff9c);
    _DAT_004aa74c = 1;
    _DAT_004a6ee4 = 0xc;
    _DAT_004a7804 = 2;
    _DAT_004a707c = 0x3c;
    _DAT_004a6354 = 0xf;
    _DAT_004ac034 = 0x13b;
    _DAT_004a7be4 = 0x2d;
    FUN_00411000(pCVar4,(int)(longlong)(_DAT_004aa810 * _DAT_00485398),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),7,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffff9c,s_Boat_E_0049ca38);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  FUN_0042f0d0(pCVar4,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004a4e8c = uVar3;
  *unaff_FS_OFFSET = local_1c;
  return;
}

