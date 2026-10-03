
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00410090(undefined *param_1)

{
  int iVar1;
  undefined *this;
  TactCString *pTVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  TactCString local_18;
  TactCString TStack_14;
  TactCString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar1 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e068;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 2;
  if (iVar1 < 700) {
    uVar3 = 0xe;
    iVar4 = 3;
    local_1c = 0x15;
  }
  else {
    uVar3 = 0x13;
    iVar4 = 0x14;
    local_1c = 0x1e;
    if (iVar1 < 900) {
      uVar3 = 0x12;
      iVar4 = 0x14;
      local_1c = 0x1b;
    }
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f0000);
  }
  if (DAT_004ac93c == 0) {
    FUN_0046bf33(&local_18,s_This_is_a_demo_version_of_Sailin_00492fb4);
    uStack_4 = 0;
    param_1 = *(undefined **)(*(int *)this + 100);
    (*(code *)param_1)(this,iVar4,2,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    FUN_0046bf33(&local_18,s_simulator_except_that_the_race_w_00492f58);
    uStack_4 = 1;
    (*(code *)param_1)(this,iVar4,uVar3 + 2,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = uVar3 + 2 + uVar3;
    if ((((DAT_00491164 == 1) || (DAT_00491164 == 3)) || (DAT_00491164 == 4)) || (DAT_00491164 == 2)
       ) {
      FUN_0046bf33(&local_18,s_tutorial_are_available__This_dem_00492f18);
      uStack_4 = 2;
      (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
    }
    if (DAT_00491164 == 0xc) {
      FUN_0046bf33(&local_18,s_tutorial_are_available__00492f00);
      uStack_4 = 3;
      (*(code *)param_1)(iVar4,iVar5,local_18.data,*(undefined4 *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
    }
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&local_18,s_The_complete_software_package_in_00492ea8);
    uStack_4 = 4;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (((DAT_00491164 == 1) || (DAT_00491164 == 3)) || (DAT_00491164 == 4)) {
      iVar5 = iVar5 + uVar3;
      FUN_0046bf33(&local_18,s_Since_you_will_not_have_a_manual_00492e54);
      uStack_4 = 5;
      (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
    }
    if (DAT_00491164 == 2) {
      iVar5 = iVar5 + uVar3;
      FUN_0046bf33(&local_18,s_You_should_browse_the_Help_Menu__00492e30);
      uStack_4 = 6;
      (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&local_18,s_The_best_screen_resolution__desk_00492ddc);
    uStack_4 = 7;
    (*(code *)param_1)(this,iVar4,iVar5 + local_1c,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_0046bf33(&local_18,s_distortion__although_800x600__sm_00492d7c);
    uStack_4 = 8;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_can_cause_problems_such_as_curso_00492d20);
    uStack_4 = 9;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_be_changed_with_the_Windows_Cont_00492cd4);
    uStack_4 = 10;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&local_18,s_You_can_reduce_clutter_by_hiding_00492c80);
    uStack_4 = 0xb;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_Select_the_Windows_START_menu__S_00492c28);
    uStack_4 = 0xc;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&local_18,s_When_boat_movement_is_suspended__00492bf0);
    uStack_4 = 0xd;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f7f00);
    }
    FUN_0046bf33(&local_18,s_If_you_move_the_pointer_to_a_men_00492b94);
    uStack_4 = 0xe;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c;
  }
  if (DAT_004ac93c == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&local_18,s_Demonstration_of_this_race_has_b_00492b64);
    uStack_4 = 0xf;
    param_1 = *(undefined **)(*(int *)this + 100);
    (*(code *)param_1)(this,iVar4,iVar5 + uVar3,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3 + local_1c;
    FUN_0046bf33(&local_18,s_If_you_want_to_run_it_again__pre_00492b10);
    uStack_4 = 0x10;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c;
    if (((DAT_00491164 == 1) || (DAT_00491164 == 4)) || (DAT_00491164 == 2)) {
      if ((DAT_004ac95c < 2) && (DAT_004ac95c != 0)) {
        pTVar2 = FUN_00413d00(&TStack_10,DAT_004ac95c);
        uStack_4 = 0x14;
        pTVar2 = FUN_0046c14f(&TStack_14,s_This_simulator_has_been_used_for_00492aec,pTVar2);
        uStack_4._0_1_ = 0x15;
        pTVar2 = FUN_0046c0db(&local_18,pTVar2,s_session__00492ae0);
        uStack_4._0_1_ = 0x16;
        (*(code *)param_1)(this,iVar4,iVar5,pTVar2->data,*(int *)(pTVar2->data + -8));
        uStack_4._0_1_ = 0x15;
        FUN_0046bec5((int *)&local_18);
        uStack_4 = CONCAT31(uStack_4._1_3_,0x14);
        FUN_0046bec5((int *)&TStack_14);
        pTVar2 = &TStack_10;
      }
      else {
        pTVar2 = FUN_00413d00(&local_18,DAT_004ac95c);
        uStack_4 = 0x11;
        pTVar2 = FUN_0046c14f(&TStack_14,s_This_simulator_has_been_used_for_00492aec,pTVar2);
        uStack_4._0_1_ = 0x12;
        pTVar2 = FUN_0046c0db(&TStack_10,pTVar2,s_sessions__00492ad4);
        uStack_4._0_1_ = 0x13;
        (*(code *)param_1)(this,iVar4,iVar5,pTVar2->data,*(int *)(pTVar2->data + -8));
        uStack_4._0_1_ = 0x12;
        FUN_0046bec5((int *)&TStack_10);
        uStack_4 = CONCAT31(uStack_4._1_3_,0x11);
        FUN_0046bec5((int *)&TStack_14);
        pTVar2 = &local_18;
      }
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)pTVar2);
    }
    iVar5 = iVar5 + local_1c * 6;
  }
  if (DAT_004ac93c == 10) {
    FUN_0046bf33(&param_1,s_This_simulator_has_been_used_for_00492a84);
    uStack_4 = 0x17;
    (**(code **)(*(int *)this + 100))(this,iVar4,iVar5 + local_1c,param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar5 = local_1c * 9 + iVar5 + local_1c;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  if (DAT_00491164 == 1) {
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
    }
    FUN_0046bf33(&local_18,s_You_can_order_from__Posey_Yacht_D_00492a30);
    uStack_4 = 0x18;
    param_1 = *(undefined **)(*(int *)this + 100);
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    FUN_0046bf33(&local_18,s_Web_site__www_poseysail_com_24_h_004929f0);
    uStack_4 = 0x19;
    (*(code *)param_1)(this,iVar4,iVar5 + uVar3,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3 + uVar3;
    FUN_0046bf33(&local_18,s_Fax__508_861_0138_e_mail__poseys_004929b0);
    uStack_4 = 0x1a;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&local_18,s_We_need__1__Your_name__address_a_00492950);
    uStack_4 = 0x1b;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_4__VISA__AMEX_or_MasterCard_numb_004928f4);
    uStack_4 = 0x1c;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&local_18,s_Sailing_Tactics_Simulator_2002_004928d4);
    uStack_4 = 0x1d;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f007f);
    }
    FUN_0046bf33(&local_18,s_Advanced_Racing_Simulator_2002_004928b4);
    uStack_4 = 0x1e;
    (*(code *)param_1)(this,DAT_004a763c / 2 + -10,iVar5,local_18.data,*(int *)(local_18.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&local_18,s_Coastal_Cruising_Simulator_2002_00492894);
    uStack_4 = 0x1f;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f00);
    }
    FUN_0046bf33(&local_18,s_Sailing_Dynamics_Instructor_2002_00492870);
    uStack_4 = 0x20;
    (*(code *)param_1)(this,DAT_004a763c / 2 + -10,iVar5,local_18.data,*(int *)(local_18.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0x7f7f00);
    }
    FUN_0046bf33(&local_18,s_Price___54_95__US__each____5_shi_00492810);
    uStack_4 = 0x21;
    (*(code *)param_1)(this,iVar4,iVar5 + local_1c,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_0046bf33(&local_18,s_30___discount_on_additional_simu_004927b0);
    uStack_4 = 0x22;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
  }
  if ((DAT_00491164 == 2) || (DAT_00491164 == 4)) {
    iVar5 = iVar5 + uVar3 / 2;
    FUN_0046bf33(&local_18,s_This_software_was_created_by__00492790);
    uStack_4 = 0x23;
    param_1 = *(undefined **)(*(int *)this + 100);
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_Posey_Yacht_Design__101_Parmelee_00492750);
    uStack_4 = 0x24;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_TEL__860_345_2685_FAX__508_861_0_00492700);
    uStack_4 = 0x25;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (DAT_00491164 == 4) {
      if (DAT_004ac92c == 0) {
        (**(code **)(*(int *)this + 0x38))(this,0x7f7f00);
      }
      FUN_0046bf33(&local_18,s_You_can_purchase_it_at_our_secur_004926c4);
      uStack_4 = 0x26;
      (*(code *)param_1)(this,iVar4,iVar5 + local_1c,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
      iVar5 = iVar5 + local_1c + uVar3;
      FUN_0046bf33(&local_18,s_The_price_is_about__50__A_little_00492674);
      uStack_4 = 0x27;
      (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
      iVar5 = iVar5 + uVar3;
      FUN_0046bf33(&local_18,s_A_little_less_if_you_download__00492654);
      uStack_4 = 0x28;
      (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_18);
    }
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    FUN_0046bf33(&local_18,s_Other_simulators_by_Posey_Yacht_D_0049262c);
    uStack_4 = 0x29;
    (*(code *)param_1)(this,iVar4,iVar5 + local_1c,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_0046bf33(&local_18,s_Advanced_Racing_Simulator_2002__C_004925e0);
    uStack_4 = 0x2a;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_Sailing_Dynamics_Instructor_2002_004925bc);
    uStack_4 = 0x2b;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
  }
  if (DAT_00491164 == 3) {
    iVar5 = iVar5 + uVar3 / 2;
    FUN_0046bf33(&local_18,s_This_software_was_created_by__00492790);
    uStack_4 = 0x2c;
    param_1 = *(undefined **)(*(int *)this + 100);
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_Posey_Yacht_Design__101_Parmelee_00492750);
    uStack_4 = 0x2d;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    if (DAT_004ac92c == 0) {
      (**(code **)(*(int *)this + 0x38))(this,0xff0000);
    }
    iVar5 = iVar5 + uVar3 + (uVar3 * 3) / 2;
    FUN_0046bf33(&local_18,s_In_Australia__it_can_be_purchase_00492594);
    uStack_4 = 0x2e;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_Integrated_Marine_Systems_00492578);
    uStack_4 = 0x2f;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    iVar5 = iVar5 + uVar3;
    FUN_0046bf33(&local_18,s_1007_Stanley_Street__East_Brisba_0049253c);
    uStack_4 = 0x30;
    (*(code *)param_1)(this,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
    FUN_0046bf33(&local_18,s_Tel__617_3217_3137_Fax__617_3217_00492510);
    uStack_4 = 0x31;
    (*(code *)param_1)(this,iVar4,iVar5 + uVar3,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_18);
  }
  if (DAT_004ac92c == 0) {
    iVar5 = *(int *)this;
    (**(code **)(iVar5 + 0x38))(this,0xff);
    (**(code **)(iVar5 + 0x34))(this,0);
  }
  if (DAT_004ac93c == 0) {
    FUN_0046bf33(&param_1,s_PRESS_SPACEBAR_TO_CONTINUE__004924f0);
    uStack_4 = 0x32;
    (**(code **)(*(int *)this + 100))
              (this,iVar4,(int)(longlong)((double)DAT_004a72d0 * _DAT_00484dc8),param_1,
               *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if ((0 < DAT_004ac93c) && (DAT_004ac93c < 10)) {
    FUN_0046bf33(&param_1,s_Press_N_for_another_race__Select_004924ac);
    uStack_4 = 0x33;
    (**(code **)(*(int *)this + 100))
              (this,iVar4,(int)(longlong)((double)DAT_004a72d0 * _DAT_00484dc8),param_1,
               *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004ac93c == 10) {
    FUN_0046bf33(&param_1,s_Select_Exit_from_Control_Menu_to_00492484);
    uStack_4 = 0x34;
    (**(code **)(*(int *)this + 100))
              (this,iVar4,(int)(longlong)((double)DAT_004a72d0 * _DAT_00484dc8),param_1,
               *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  (**(code **)(*(int *)this + 0x34))(this,0xffffff);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

