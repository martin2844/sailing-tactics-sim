
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00449ef0(CDC *param_1)

{
  code *pcVar1;
  double dVar2;
  CDC *pCVar3;
  int unaff_EBP;
  CDC *pCVar4;
  undefined4 unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined4 uVar5;
  undefined4 uVar6;
  CDC *pCVar7;
  CDC *pCVar8;
  CDC *pCVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  HDC hdc;
  HGDIOBJ h;
  int iStack_3c;
  CDC *pCStack_38;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 local_20;
  int local_1c [4];
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pCVar3 = param_1;
  DAT_004aca3c = DAT_004abb7c;
  DAT_004aca38 = DAT_004abb78;
  DAT_004aca34 = DAT_004abb74;
  iStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_00480128;
  *unaff_FS_OFFSET = (int)&iStack_c;
  DAT_004aca48 = DAT_004abb88;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    local_1c[1] = 0x10;
    local_1c[0] = 0x16;
    local_20 = 5;
  }
  else {
    local_1c[0] = 0x1b;
    local_1c[1] = 0x14;
    local_20 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    pCStack_38 = (CDC *)0x449fa2;
    (**(code **)(*(int *)param_1 + 0x38))();
  }
  pCStack_38 = (CDC *)0x449fb0;
  FUN_0046bf33(&param_1,s___MARK_ROUNDING___0049db88);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)pCVar3 + 100);
  iVar13 = *(int *)(param_1 + -8);
  pCStack_38 = param_1;
  iStack_3c = 2;
  (*pcVar1)();
  local_1c[2] = 0xffffffff;
  FUN_0046bec5(&iStack_c);
  pCVar4 = (CDC *)(unaff_EBP + 2);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)pCVar3 + 0x38))();
  }
  if (DAT_004a6774 == 0) {
    FUN_0046bf33(&iStack_c,s_Rounding_a_mark_with_other_boats_0049db30);
    local_1c[2] = 1;
    uVar5 = unaff_EDI;
    pCVar7 = pCVar4;
    (*pcVar1)();
    FUN_0046bec5(local_1c);
    pCVar4 = pCVar4 + (int)pCStack_38;
    FUN_0046bf33(local_1c,s_race_since_the_outside_boat_must_0049daf8);
    uVar6 = local_20;
    pCVar9 = pCVar4;
    iVar15 = local_1c[0];
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    pCVar4 = pCVar4 + (int)pCVar7;
    FUN_0046bf33(&stack0xffffffd4,s_Roundings_are_especially_importa_0049daa0);
    iVar13 = 3;
    pCVar8 = pCVar4;
    (*pcVar1)(uVar5);
    FUN_0046bec5(&iStack_3c);
    pCVar4 = pCVar4 + iVar15;
    FUN_0046bf33(&iStack_3c,s_the_outside_boats_usually_start_t_0049da64);
    iVar15 = iStack_3c;
    (*pcVar1)(uVar6,pCVar4,iStack_3c,*(undefined4 *)(iStack_3c + -8));
    FUN_0046bec5((int *)&stack0xffffffb4);
    pCVar4 = pCVar4 + (int)pCVar8;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))(0x7f0000);
    }
    FUN_0046bf33(&stack0xffffffb4,s_Boats_A__B__C__and_D_are_approac_0049da1c);
    (*pcVar1)(uVar5,pCVar4,pCVar7,*(undefined4 *)(pCVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&stack0xffffffa4,s_Boats_B_and_C_will_have_to_give_r_0049d9c4);
    (*pcVar1)(uVar6,pCVar4 + iVar15,pCVar9,*(undefined4 *)(pCVar9 + -8));
    FUN_0046bec5((int *)&stack0xffffff94);
    pCVar4 = pCVar4 + iVar15 + (int)pCVar7;
    FUN_0046bf33(&stack0xffffff94,s_inside_overlap_on_both_B_and_C__B_0049d964);
    (*pcVar1)(uVar5,pCVar4,pCVar8,*(undefined4 *)(pCVar8 + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 1) {
    FUN_0046bf33(&iStack_c,s_As_they_go_around__Boat_A_sails_t_0049d918);
    local_1c[2] = 8;
    uVar6 = unaff_EDI;
    pCVar8 = pCVar4;
    iVar13 = iStack_c;
    (*pcVar1)();
    FUN_0046bec5(local_1c);
    pCVar4 = pCVar4 + iStack_3c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))();
    }
    FUN_0046bf33(local_1c,s_Boat_D_intentionally_slows_down_a_0049d8c4);
    uVar5 = local_20;
    pCVar7 = pCVar4;
    iVar15 = local_1c[0];
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    pCVar4 = pCVar4 + iVar13;
    FUN_0046bf33(&stack0xffffffd4,s_the_outside_boat__Boat_D_will_no_0049d870);
    iVar13 = 10;
    pCVar9 = pCVar4;
    (*pcVar1)(uVar6);
    FUN_0046bec5(&iStack_3c);
    pCVar4 = pCVar4 + iVar15;
    FUN_0046bf33(&iStack_3c,s_avoid_a_sharp__speed_killing_tur_0049d820);
    iVar15 = iStack_3c;
    (*pcVar1)(uVar5,pCVar4,iStack_3c,*(undefined4 *)(iStack_3c + -8));
    FUN_0046bec5((int *)&stack0xffffffb4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))(0xff0000);
    }
    pCVar4 = pCVar4 + (int)pCVar9;
    FUN_0046bf33(&stack0xffffffb4,s_Boat_A_would_like_a_gradual_turn_0049d7cc);
    (*pcVar1)(uVar6,pCVar4,pCVar8,*(undefined4 *)(pCVar8 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    FUN_0046bf33(&stack0xffffffa4,s_a_leeward__right_of_way__boat__U_0049d778);
    (*pcVar1)(uVar5,pCVar4 + iVar15,pCVar7,*(undefined4 *)(pCVar7 + -8));
    FUN_0046bec5((int *)&stack0xffffff94);
    pCVar4 = pCVar4 + iVar15 + (int)pCVar8;
    FUN_0046bf33(&stack0xffffff94,s_rounding_but_not_enough_for_a_ta_0049d738);
    (*pcVar1)(uVar6,pCVar4,pCVar9,*(undefined4 *)(pCVar9 + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  if (DAT_004a6774 == 2) {
    FUN_0046bf33(&iStack_c,s_Boat_A_has_the_lead__clear_air__a_0049d700);
    local_1c[2] = 0xf;
    uVar6 = unaff_EDI;
    pCVar9 = pCVar4;
    (*pcVar1)();
    FUN_0046bec5(local_1c);
    pCVar4 = pCVar4 + (int)pCStack_38;
    FUN_0046bf33(local_1c,s_Boat_B_and_boat_C_have_bad_air_a_0049d6b8);
    pCVar8 = pCVar4;
    iVar15 = local_1c[0];
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffd4);
    pCVar4 = pCVar4 + (int)pCVar9;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffffd4,s_Boat_D_is_in_bad_air_but_can_tac_0049d660);
    iVar13 = 0x11;
    pCVar7 = pCVar4;
    (*pcVar1)(uVar6);
    FUN_0046bec5(&iStack_3c);
    pCVar4 = pCVar4 + iVar15;
    FUN_0046bf33(&iStack_3c,s_pack_rather_than_outside_it_when_0049d614);
    iVar15 = iStack_3c;
    (*pcVar1)(local_20,pCVar4,iStack_3c,*(undefined4 *)(iStack_3c + -8));
    FUN_0046bec5((int *)&stack0xffffffb4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))(0x7f00);
    }
    FUN_0046bf33(&stack0xffffffb4,s_If_the_next_were_a_run_or_broad_r_0049d5bc);
    (*pcVar1)(uVar6,pCVar4 + (int)pCVar7,pCVar9,*(undefined4 *)(pCVar9 + -8));
    FUN_0046bec5((int *)&stack0xffffffa4);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)pCVar3 + 0x38))(0);
    }
    FUN_0046bf33(&stack0xffffffa4,s_It_almost_never_pays_to_round_in_0049d564);
    (*pcVar1)(local_20,pCVar4 + (int)pCVar7 + iVar15,pCVar8,*(undefined4 *)(pCVar8 + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  FUN_0044d830((int *)pCVar3,unaff_EDI,unaff_EBP);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_0044a595;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_0044a595;
    hdc = *(HDC *)(pCVar3 + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_0044a595:
  Rectangle(*(HDC *)(pCVar3 + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  DAT_00491184 = 2;
  FUN_0044d6d0((int *)pCVar3);
  uVar6 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  if (DAT_004a6774 == 0) {
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      DAT_004abb74 = 1;
      DAT_004abb78 = 1;
      DAT_004abb7c = 1;
      DAT_004abb88 = 1;
    }
    FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_004852c0);
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 5;
    _DAT_004a77ec = 0x1e;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x82;
    DAT_004a7bcc = 0x78;
    FUN_00411000(pCVar3,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    local_1c[2] = 0x15;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffcc);
    local_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_004853e0);
    iStack_3c = DAT_004a763c / 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 5;
    _DAT_004a77f0 = 0x1e;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x82;
    DAT_004a7bd0 = 0x78;
    FUN_00411000(pCVar3,local_1c[0],(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffcc,s_Boat_B_004994ec);
    iVar15 = *(int *)(iVar13 + -8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffbc);
    iVar11 = (int)(longlong)(_DAT_004aa810 * _DAT_00485070);
    iVar12 = DAT_004a763c / 0xf;
    _DAT_004a77f4 = 0x1e;
    _DAT_004a706c = 0x1e;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 5;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x82;
    _DAT_004a7bd4 = 0x78;
    FUN_00411000(pCVar3,iVar11,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484e50),3,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    iVar14 = 0x17;
    (*pcVar1)(iVar12 + iVar11);
    FUN_0046bec5((int *)&stack0xffffffac);
    iStack_3c = (int)(longlong)(_DAT_004aa810 * _DAT_004853c0);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar11 = DAT_004a763c / 0x19;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a6ee0 = 5;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x82;
    _DAT_004a7be0 = 0x78;
    FUN_00411000(pCVar3,iStack_3c,puVar10,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)(iStack_3c - iVar11,puVar10 + iVar13 + 4,iVar15,*(undefined4 *)(iVar15 + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffdc);
    iVar13 = iVar14;
  }
  iVar15 = iVar13;
  if (DAT_004a6774 == 1) {
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      DAT_004abb74 = 0;
      DAT_004abb78 = 0;
      DAT_004abb7c = 0;
      DAT_004abb88 = 0;
    }
    FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484f78),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484da0),3,1);
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    _DAT_004a77ec = 0x14;
    DAT_004a7064 = 0x14;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 5;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x78;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(pCVar3,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,s_Boat_A_004994e4);
    local_1c[2] = 0x19;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffcc);
    local_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    iStack_3c = DAT_004a763c / 0xf;
    DAT_004aa738 = 0xffffffff;
    _DAT_004a6ed0 = 5;
    _DAT_004a77f0 = 0x14;
    DAT_004a7068 = 0x3c;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x5a;
    DAT_004a7bd0 = 100;
    FUN_00411000(pCVar3,local_1c[0],(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffcc,s_Boat_B_004994ec);
    iVar11 = *(int *)(iVar13 + -8);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffbc);
    iVar12 = (int)(longlong)(_DAT_004aa810 * _DAT_00484da8);
    iVar14 = DAT_004a763c / 0xf;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x14;
    _DAT_004a706c = 0x1e;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 100;
    _DAT_004a7bd4 = 0x6e;
    FUN_00411000(pCVar3,iVar12,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    iVar15 = 0x1b;
    (*pcVar1)(iVar14 + iVar12);
    FUN_0046bec5((int *)&stack0xffffffac);
    iStack_3c = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8);
    iVar12 = DAT_004a763c / 0x19;
    _DAT_004ac030 = 0x6e;
    _DAT_004a7be0 = 0x6e;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a6ee0 = 5;
    _DAT_004a7800 = 0x28;
    _DAT_004a7078 = 0x1e;
    _DAT_004a6350 = 0xf;
    FUN_00411000(pCVar3,iStack_3c,puVar10,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffac,s_Boat_D_0049ca40);
    (*pcVar1)(iStack_3c - iVar12,puVar10 + iVar13 + 4,iVar11,*(undefined4 *)(iVar11 + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffdc);
  }
  if (DAT_004a6774 == 2) {
    FUN_0042cd40((int *)pCVar3,(int)(longlong)(_DAT_004aa810 * _DAT_00484f10),
                 (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
    iStack_c = (int)(longlong)(_DAT_004aa810 * _DAT_00484f78);
    DAT_004ac01c = 0x2d;
    DAT_004a7bcc = 0x2d;
    DAT_004aa734 = 0xffffffff;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x3c;
    DAT_004a633c = 0xf;
    FUN_00411000(pCVar3,iStack_c,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffdc,&DAT_0049d560);
    local_1c[2] = 0x1d;
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffcc);
    local_1c[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00484db8);
    iStack_3c = DAT_004a763c / 0x14;
    DAT_004aa738 = 0xffffffff;
    DAT_004ac020 = 0x30;
    DAT_004a7bd0 = 0x30;
    _DAT_004a6ed0 = 10;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x32;
    DAT_004a6340 = 0xf;
    FUN_00411000(pCVar3,local_1c[0],(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffcc,&DAT_0049d55c);
    (*pcVar1)();
    FUN_0046bec5((int *)&stack0xffffffbc);
    iVar13 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    iVar11 = DAT_004a763c / 0xf;
    _DAT_004ac024 = 0x33;
    _DAT_004a7bd4 = 0x33;
    _DAT_004aa73c = 0xffffffff;
    _DAT_004a6ed4 = 10;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x28;
    _DAT_004a6344 = 0xf;
    FUN_00411000(pCVar3,iVar13,(undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de8),3,1,
                 DAT_004a72d0,0);
    FUN_0046bf33(&stack0xffffffbc,s_Boat_C_0049ca48);
    (*pcVar1)(iVar11 + iVar13);
    FUN_0046bec5((int *)&stack0xffffffac);
    iVar13 = (int)(longlong)(_DAT_004aa810 * _DAT_00484f18);
    puVar10 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    iVar11 = DAT_004a763c / 0x19;
    _DAT_004a6ee0 = 0xf;
    _DAT_004a6350 = 0xf;
    _DAT_004aa748 = 0xffffffff;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004ac030 = 0x2d;
    _DAT_004a7be0 = 0x2d;
    iStack_3c = iVar13;
    FUN_00411000(pCVar3,iVar13,puVar10,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&iStack_3c,s_Boat_D_0049ca40);
    (*pcVar1)(iVar13 - iVar11,puVar10 + iVar15 + 4,iStack_3c,*(undefined4 *)(iStack_3c + -8));
    local_1c[2] = 0xffffffff;
    FUN_0046bec5(&iStack_c);
  }
  FUN_0042f0d0(pCVar3,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004abb74 = DAT_004aca34;
  DAT_004abb78 = DAT_004aca38;
  DAT_004abb88 = DAT_004aca48;
  DAT_004abb7c = DAT_004aca3c;
  DAT_004ac994 = 0;
  DAT_004a4e8c = uVar6;
  *unaff_FS_OFFSET = local_1c[0];
  return;
}

