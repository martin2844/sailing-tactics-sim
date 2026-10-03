
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00416910(int *param_1)

{
  int iVar1;
  int *original_dc;
  Tact2010CString *pTVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  Tact2010CString local_18;
  Tact2010CString TStack_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar1 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2d78;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = 2;
  if (iVar1 < 700) {
    uVar3 = 0xd;
    iVar4 = 3;
    local_1c = 0x14;
  }
  else {
    uVar3 = 0x10;
    iVar4 = 0x14;
    local_1c = 0x1a;
    if (iVar1 < 900) {
      uVar3 = 0xe;
      iVar4 = 0x14;
      local_1c = 0x15;
    }
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  if (DAT_005363f4 == 0) {
    FUN_004b0613(&local_18,s_This_is_a_demo_version_of_Sailin_004dd000);
    uStack_4 = 0;
    param_1 = *(int **)(*original_dc + 100);
    (*(code *)param_1)(original_dc,iVar4,2,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    FUN_004b0613(&local_18,s_simulator_except_that_the_race_w_004dcfa4);
    uStack_4 = 1;
    (*(code *)param_1)(original_dc,iVar4,uVar3 + 2,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    iVar5 = uVar3 + 2 + uVar3;
    if (DAT_004da16c == 1) {
      FUN_004b0613(&local_18,s_tutorial_are_available__This_dem_004dcf44);
      uStack_4 = 2;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
    }
    if (DAT_004da16c == 2) {
      FUN_004b0613(&local_18,s__004dcf2c);
      uStack_4 = 3;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(&local_18,s_The_complete_software_package_in_004dced8);
    uStack_4 = 4;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + local_1c,local_18.data,*(int *)(local_18.data + -8)
                      );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    iVar5 = iVar5 + local_1c + uVar3;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(&local_18,s_and_an_e_book_of_Racing_Suggesti_004dce80);
    uStack_4 = 5;
    (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_18);
    if ((DAT_004da16c == 1) || (DAT_004da16c == 4)) {
      FUN_004b0613(&local_18,s_you_should_browse_the_Help_Menu__004dce2c);
      uStack_4 = 6;
      (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,local_18.data,*(int *)(local_18.data + -8))
      ;
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
      if (DAT_005363e4 == 0) {
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
      }
      iVar5 = iVar5 + uVar3 + uVar3;
      FUN_004b0613(&local_18,s_If_you_have_an_earlier_version_o_004dcddc);
      uStack_4 = 7;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
      iVar5 = iVar5 + uVar3;
      FUN_004b0613(&local_18,s_If_you_have_an_earlier_version_o_004dcd84);
      uStack_4 = 8;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
      iVar5 = iVar5 + uVar3;
      if (DAT_005363e4 == 0) {
        (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
      }
      FUN_004b0613(&local_18,s_If_the_simulator_runs_too_fast__s_004dcd2c);
      uStack_4 = 9;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
    }
    if (DAT_004da16c == 2) {
      iVar5 = iVar5 + uVar3;
      FUN_004b0613(&local_18,s_You_should_browse_the_Help_Menu__004dcd08);
      uStack_4 = 10;
      (*(code *)param_1)(original_dc,iVar4,iVar5,local_18.data,*(int *)(local_18.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_18);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    local_18.data = *(char **)(*original_dc + 0x38);
    (*(code *)local_18.data)(original_dc,0x7f0000);
    FUN_004b0613(&TStack_14,s_A_good_choice_for_screen_resolut_004dcc98);
    uStack_4 = 0xb;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + local_1c,TStack_14.data,
                       *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_004b0613(&TStack_14,s_work_well_1280x768_or_1680x1050_w_004dcc28);
    uStack_4 = 0xc;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    if (1000 < DAT_004fe624) {
      (*(code *)local_18.data)(original_dc,0xff0000);
      FUN_004b0613(&TStack_14,s_However__resolution_selection_ma_004dcbb4);
      uStack_4 = 0xd;
      (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      FUN_004b0613(&TStack_14,s_circle_in_the_upper_right_corner_004dcb3c);
      uStack_4 = 0xe;
      (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,TStack_14.data,
                         *(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar5 = iVar5 + uVar3 + uVar3;
      FUN_004b0613(&TStack_14,s_want_a_different_screen_resoluti_004dcae4);
      uStack_4 = 0xf;
      (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar5 = iVar5 + uVar3;
    }
    (*(code *)local_18.data)(original_dc,0x7f0000);
    FUN_004b0613(&TStack_14,s_In_rare_cases__Graphics_Accelera_004dca6c);
    uStack_4 = 0x10;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    FUN_004b0613(&TStack_14,s_changed_with_the_Windows_Control_004dca00);
    uStack_4 = 0x11;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,TStack_14.data,*(int *)(TStack_14.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3 + local_1c;
    (*(code *)local_18.data)(original_dc,0x7f7f00);
    FUN_004b0613(&TStack_14,s_With_large_fonts_or_an_800x600_s_004dc9a0);
    uStack_4 = 0x12;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_explanations_unless_you_unselect_004dc938);
    uStack_4 = 0x13;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_Then_click_Properties_and_unsele_004dc8dc);
    uStack_4 = 0x14;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    (*(code *)local_18.data)(original_dc,0x7f0000);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_You_can_also_increase_viewing_ar_004dc884);
    uStack_4 = 0x15;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c;
    if (DAT_005363e4 == 0) {
      (*(code *)local_18.data)(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,
                 "Move the mouse pointer to a menu item or button to see its explanation at the bottom of the screen."
                );
    uStack_4 = 0x16;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,
                 "When boat movement is suspended, a red warning appears at the bottom of the screen."
                );
    uStack_4 = 0x17;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c;
  }
  if (DAT_005363f4 == 1) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_Demonstration_of_this_race_has_b_004dc7b0);
    uStack_4 = 0x18;
    param_1 = *(int **)(*original_dc + 100);
    (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,TStack_14.data,*(int *)(TStack_14.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3 + local_1c;
    FUN_004b0613(&TStack_14,
                 "Press N or select Next Sailing in the Control Menu to sail again. Select Exit to quit."
                );
    uStack_4 = 0x19;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c;
    if (DAT_004da16c == 1) {
      if ((DAT_00536420 < 2) && (DAT_00536420 != 0)) {
        pTVar2 = FUN_0041bc70(&TStack_10,DAT_00536420);
        uStack_4 = 0x1d;
        pTVar2 = FUN_004b082f(&local_18,s_This_simulator_has_been_used_for_004dc738,pTVar2);
        uStack_4._0_1_ = 0x1e;
        pTVar2 = FUN_004b07bb(&TStack_14,pTVar2,s_session__004dc72c);
        uStack_4._0_1_ = 0x1f;
        (*(code *)param_1)(original_dc,iVar4,iVar5,pTVar2->data,*(int *)(pTVar2->data + -8));
        uStack_4._0_1_ = 0x1e;
        FUN_004b05a5(&TStack_14);
        uStack_4 = CONCAT31(uStack_4._1_3_,0x1d);
        FUN_004b05a5(&local_18);
        pTVar2 = &TStack_10;
      }
      else {
        pTVar2 = FUN_0041bc70(&local_18,DAT_00536420);
        uStack_4 = 0x1a;
        pTVar2 = FUN_004b082f(&TStack_14,s_This_simulator_has_been_used_for_004dc738,pTVar2);
        uStack_4._0_1_ = 0x1b;
        pTVar2 = FUN_004b07bb(&TStack_10,pTVar2,s_sessions__004dc720);
        uStack_4._0_1_ = 0x1c;
        (*(code *)param_1)(original_dc,iVar4,iVar5,pTVar2->data,*(int *)(pTVar2->data + -8));
        uStack_4._0_1_ = 0x1b;
        FUN_004b05a5(&TStack_10);
        uStack_4 = CONCAT31(uStack_4._1_3_,0x1a);
        FUN_004b05a5(&TStack_14);
        pTVar2 = &local_18;
      }
      uStack_4 = 0xffffffff;
      FUN_004b05a5(pTVar2);
    }
    iVar5 = iVar5 + local_1c * 6;
  }
  if ((DAT_005363f4 == 10) && (DAT_004da16c == 1)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_This_simulator_has_been_used_for_004dc6d0);
    uStack_4 = 0x20;
    (**(code **)(*original_dc + 100))
              (original_dc,iVar4,iVar5 + local_1c,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = local_1c * 9 + iVar5 + local_1c;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  if (DAT_004da16c == 1) {
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_You_can_order_from__Posey_Yacht_D_004dc67c);
    uStack_4 = 0x21;
    param_1 = *(int **)(*original_dc + 100);
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_www_poseysail_com_004dc668);
    uStack_4 = 0x22;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    FUN_004b0613(&TStack_14,s_Web_site__www_poseysail_com_24_h_004dc628);
    uStack_4 = 0x23;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    FUN_004b0613(&TStack_14,s_Fax__508_861_0138_e_mail__poseys_004dc5e8);
    uStack_4 = 0x24;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,TStack_14.data,*(int *)(TStack_14.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3 + local_1c;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_We_need__1__Your_name__address_a_004dc5a4);
    uStack_4 = 0x25;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_3__VISA__AMEX_or_MasterCard_numb_004dc548);
    uStack_4 = 0x26;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613(&TStack_14,s_Sailing_Tactics_Simulator_004dc52c);
    uStack_4 = 0x27;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_Advanced_Racing_Simulator_004dc510);
    uStack_4 = 0x28;
    (*(code *)param_1)(original_dc,((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x14,
                       iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f007f);
    }
    FUN_004b0613(&TStack_14,s_Distance_Race_Sailing_Challenge_004dc4f0);
    uStack_4 = 0x29;
    (*(code *)param_1)(original_dc,
                       ((int)(DAT_004fe624 * 2 + (DAT_004fe624 * 2 >> 0x1f & 3U)) >> 2) + 0x28,iVar5
                       ,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Coastal_Cruising_Simulator_004dc4d4);
    uStack_4 = 0x2a;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
    }
    FUN_004b0613(&TStack_14,s_Sailing_Dynamics_Instructor_004dc4b8);
    uStack_4 = 0x2b;
    (*(code *)param_1)(original_dc,((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x28,
                       iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f00);
    }
    FUN_004b0613(&TStack_14,s_Price__Download_US_44_95__CD_ROM_004dc448);
    uStack_4 = 0x2c;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + local_1c,TStack_14.data,
                       *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_004b0613(&TStack_14,s_Connecticut_residents_add_6__tax_004dc424);
    uStack_4 = 0x2d;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_30___discount_on_additional_simu_004dc3c4);
    uStack_4 = 0x2e;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if ((DAT_004da16c == 2) || (DAT_004da16c == 4)) {
    iVar5 = iVar5 + uVar3 / 2;
    FUN_004b0613(&TStack_14,s_This_software_was_created_by__004dc3a4);
    uStack_4 = 0x2f;
    param_1 = *(int **)(*original_dc + 100);
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_Posey_Yacht_Design__101_Parmelee_004dc364);
    uStack_4 = 0x30;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_TEL__860_345_2685_FAX__508_861_0_004dc314);
    uStack_4 = 0x31;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_004da16c == 4) {
      if (DAT_005363e4 == 0) {
        (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f00);
      }
      FUN_004b0613(&TStack_14,s_You_can_purchase_it_at_our_secur_004dc2d8);
      uStack_4 = 0x32;
      (*(code *)param_1)(original_dc,iVar4,iVar5 + local_1c,TStack_14.data,
                         *(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar5 = iVar5 + local_1c + uVar3;
      FUN_004b0613(&TStack_14,s_The_price_is_about__50__A_little_004dc288);
      uStack_4 = 0x33;
      (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar5 = iVar5 + uVar3;
      FUN_004b0613(&TStack_14,s_A_little_less_if_you_download__004dc268);
      uStack_4 = 0x34;
      (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
    }
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Other_simulators_by_Posey_Yacht_D_004dc240);
    uStack_4 = 0x35;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + local_1c,TStack_14.data,
                       *(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + local_1c + uVar3;
    FUN_004b0613(&TStack_14,s_Advanced_Racing_Simulator__Coast_004dc1fc);
    uStack_4 = 0x36;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + uVar3;
    FUN_004b0613(&TStack_14,s_Sailing_Dynamics_Instructor___Di_004dc1b4);
    uStack_4 = 0x37;
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_004da16c == 3) {
    iVar5 = iVar5 + uVar3 / 2;
    FUN_004b0613(&TStack_14,s_This_software_was_created_by__004dc3a4);
    uStack_4 = 0x38;
    param_1 = *(int **)(*original_dc + 100);
    (*(code *)param_1)(original_dc,iVar4,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    FUN_004b0613(&TStack_14,s_Posey_Yacht_Design__101_Parmelee_004dc364);
    uStack_4 = 0x39;
    (*(code *)param_1)(original_dc,iVar4,iVar5 + uVar3,TStack_14.data,*(int *)(TStack_14.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_005363e4 == 0) {
    iVar5 = *original_dc;
    (**(code **)(iVar5 + 0x38))(original_dc,0xff);
    (**(code **)(iVar5 + 0x34))(original_dc,0);
  }
  if (DAT_005363f4 == 0) {
    FUN_004b0613((Tact2010CString *)&param_1,s_PRESS_SPACEBAR_TO_CONTINUE__004dc194);
    uStack_4 = 0x3a;
    (**(code **)(*original_dc + 100))
              (original_dc,iVar4,(int)(longlong)((double)DAT_004fe2a8 * _DAT_004cc608),
               (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if ((0 < DAT_005363f4) && (DAT_005363f4 < 10)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Press_N_for_another_race__Select_004dc150);
    uStack_4 = 0x3b;
    (**(code **)(*original_dc + 100))
              (original_dc,iVar4,(int)(longlong)((double)DAT_004fe2a8 * _DAT_004cc608),
               (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_005363f4 == 10) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Select_Exit_from_Control_Menu_to_004dc128);
    uStack_4 = 0x3c;
    (**(code **)(*original_dc + 100))
              (original_dc,iVar4,(int)(longlong)((double)DAT_004fe2a8 * _DAT_004cc608),
               (char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  (**(code **)(*original_dc + 0x34))(original_dc,0xffffff);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

