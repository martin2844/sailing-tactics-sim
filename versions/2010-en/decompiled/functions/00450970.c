
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00450970(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  Tact2010CString *pTVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString TStack_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c44e8;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = DAT_004fe2a8 / 3;
  iVar3 = ((699 < DAT_004fe624) - 1 & 0xfffffffc) + 0x14;
  iVar5 = 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b4a1f(original_dc,2);
  iVar6 = *original_dc;
  (**(code **)(iVar6 + 0x34))(original_dc,0xffffff);
  if ((DAT_005363f4 != 1) && (DAT_004fe63c < 1)) {
    if (DAT_004da198 < 0xb) {
      FUN_004b0613((Tact2010CString *)&param_1,s_Sailing_OK__Better_may_be_possib_004e60d4);
      uStack_4 = 0x12;
      pcVar1 = *(code **)(*original_dc + 100);
      (*pcVar1)(original_dc,0x1e,2,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      if ((DAT_004fafa0 == 0) && (DAT_004f8cd0 < 0x14)) {
        FUN_004b0613((Tact2010CString *)&param_1,s_The_Weather_forecast_has_informa_004e609c);
        uStack_4 = 0x13;
        (*pcVar1)(original_dc,0x1e,2,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = 0x16;
      }
      if ((DAT_004fb21c == 1) && (-1 < DAT_00500384)) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Heeling_too_much__004e6068);
        uStack_4 = 0x14;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (DAT_004fb234 == 1) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_taking_the_headed_tack_a_004e602c);
        uStack_4 = 0x15;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (DAT_004fb234 == 2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_probably_approaching_the_004e5ff8);
        uStack_4 = 0x16;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (DAT_004fb234 == 3) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_have_overstood_the_mark__004e5fc4);
        uStack_4 = 0x17;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_00536460 = 1;
      }
      if (DAT_004fb234 == -1) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_taking_the_lifted_jibe_a_004e5f88);
        uStack_4 = 0x18;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (DAT_004fb234 == -2) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_probably_approaching_the_004e5f4c);
        uStack_4 = 0x19;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (DAT_004fb234 == -3) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_passed_the_downwind_layline_t_004e5f20);
        uStack_4 = 0x1a;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_00536464 = 1;
      }
      if (DAT_004fb220 == 1) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_sailing_in_bad_air__004e5eec);
        uStack_4 = 0x1b;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
      }
      if (((DAT_004fe77c == 3) && (DAT_004feccc < 0x3c)) && (DAT_005364c8 == 0)) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Mainsail_too_baggy_for_beating__004e5eb8);
        uStack_4 = 0x1c;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((DAT_004fe77c == 2) && (DAT_004feccc < 0x3c)) &&
         ((0xd < DAT_004fb384 && (DAT_005364c8 == 0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Mainsail_probably_too_baggy_for_b_004e5e7c);
        uStack_4 = 0x1d;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((DAT_004fe77c == 1) && (DAT_004fb384 < 0xd)) &&
         ((DAT_004feccc < 0x51 && (DAT_005364c8 == 0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Mainsail_may_be_too_flat__004e5e48);
        uStack_4 = 0x1e;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if ((((DAT_004fe77c < 3) && (0x50 < DAT_004feccc)) && (DAT_0051227c < 0x14)) &&
         (DAT_005364c8 == 0)) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Mainsail_too_flat__004e5e14);
        uStack_4 = 0x1f;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((((DAT_004f7ee4 == 1) && (6 < DAT_004da190)) &&
           ((DAT_004da190 < 9 && ((0xd < DAT_0051227c && (0 < DAT_004f8cd0)))))) &&
          (DAT_005350dc == 0)) &&
         (((DAT_005364c8 == 0 && (0xf < DAT_004fc2c4)) && (DAT_004feccc < 0x37)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Jib_may_be_too_big__004e5de0);
        uStack_4 = 0x20;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((1 < DAT_004f7ee4) && (6 < DAT_004da190)) &&
         ((((DAT_004da190 < 9 && ((DAT_0051227c == 0 && (0 < DAT_004f8cd0)))) && (DAT_005350dc == 0)
           ) && ((DAT_004fc2c4 < 0x10 && (DAT_005364c8 == 0)))))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Jib_may_be_too_small__004e5dac);
        uStack_4 = 0x21;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if ((((DAT_004da190 == 8) && (100 < DAT_004feccc)) && (DAT_00522ad0 < 0xd)) &&
         ((DAT_004f42c4 < 3 && (0 < DAT_004f8cd0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_You_should_tack_downwind_with_th_004e5d74);
        uStack_4 = 0x22;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((DAT_004f4520 == 1) && (0 < DAT_00535f6c)) &&
         ((2 < DAT_004da190 && ((DAT_004da190 != 9 && (DAT_005364c4 == 0)))))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Spinnaker_is_breaking__004e5d40);
        uStack_4 = 0x23;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if ((((DAT_004fbab4 == 1) && (DAT_004f4520 == 1)) && (2 < DAT_004da190)) &&
         ((DAT_004da190 != 9 && (DAT_005364c4 == 0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Spinnaker_is_stalled__Head_Up__004e5d0c);
        uStack_4 = 0x24;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((DAT_004f4520 == 1) && (0x1e < DAT_00535f6c)) &&
         ((DAT_004da190 == 2 || (DAT_005364c4 == 1)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Jib_is_backing__Don_t_wing_jib__004e5cd8);
        uStack_4 = 0x25;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if ((((0x69 < DAT_004feccc) && (2 < DAT_004da190)) && (DAT_004da190 != 9)) &&
         (((DAT_005364c4 == 0 && (0x14 < DAT_004f8cd0)) && (DAT_004f4520 == 0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Set_spinnaker__004e5ca4);
        uStack_4 = 0x26;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (((0x9b < DAT_004feccc) && ((DAT_004da190 == 2 || (DAT_005364c4 == 1)))) &&
         ((0x14 < DAT_004f8cd0 && (DAT_004f4520 == 0)))) {
        FUN_004b0613((Tact2010CString *)&param_1,s_Wing_jib__004e5c70);
        uStack_4 = 0x27;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (DAT_004da174 == 1) {
        if (DAT_005363e4 == 0) {
          (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
        }
        FUN_004b0613((Tact2010CString *)&param_1,s_Simulation_speed_is_too_fast__004e5c38);
        uStack_4 = 0x28;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar5 = iVar5 + 0x14;
        DAT_004fb210 = 1;
      }
      if (DAT_00534f44 == 1) {
        iVar5 = iVar5 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Your_wind_direction_has_been_cha_004e5bf4);
        uStack_4 = 0x29;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if (DAT_005364ec == 1) {
        iVar5 = iVar5 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_in_stronger_wind_due_to_m_004e5bb0);
        uStack_4 = 0x2a;
        (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      iVar6 = iVar5;
      if (DAT_00522cac == 1) {
        iVar6 = iVar5 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_You_are_in_a_tempory_puff__004e5b78);
        uStack_4 = 0x2b;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
        if ((((DAT_00522cac == 1) && (0x46 < DAT_004feccc)) && (DAT_004feccc < 0xb4 - DAT_004fae64))
           && (0 < DAT_004fb998)) {
          iVar6 = iVar5 + 0x28;
          (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
          FUN_004b0613((Tact2010CString *)&param_1,s_You_probably_should_head_down_in_004e5b30);
          uStack_4 = 0x2c;
          (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_1);
          DAT_004fb210 = 1;
        }
      }
      if (((DAT_004da1f8 == 0xb) || (DAT_004da1f8 == 0x68)) ||
         ((DAT_004da1f8 == 0x69 ||
          ((DAT_004da1f8 == 0x6a || (DAT_004da1f8 == 999 && DAT_00536524 == 1)))))) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Warm_water_causing_mixing_air__S_004e5ad8);
        uStack_4 = 0x2d;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if (DAT_0051158c == 1) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Land_to_windward__Oscillating_wi_004e5a94);
        uStack_4 = 0x2e;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if (DAT_004f8b74 == 1) {
        if (3 < DAT_00535204) {
          iVar6 = iVar6 + 0x14;
          (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
          FUN_004b0613((Tact2010CString *)&param_1,s_Weather_system_passing_to_the_no_004e5a4c);
          uStack_4 = 0x2f;
          (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_1);
          DAT_004fb210 = 1;
        }
        if ((DAT_004f8b74 == 1) && (DAT_00535204 < -3)) {
          iVar6 = iVar6 + 0x14;
          (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
          FUN_004b0613((Tact2010CString *)&param_1,s_Weather_system_passing_to_the_so_004e5a04);
          uStack_4 = 0x30;
          (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_1);
          DAT_004fb210 = 1;
        }
      }
      if ((((4 < DAT_004fea5c) && (DAT_0053645c == 0)) && (10 < DAT_004f6d60)) &&
         (DAT_004f6d60 < 0x12)) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Seabreeze_often_veers_during_the_004e59b8);
        uStack_4 = 0x31;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if (DAT_00536428 == 1) {
        iVar6 = iVar6 + 0x14;
        if (DAT_005363e4 == 0) {
          (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        }
        FUN_004b0613((Tact2010CString *)&param_1,s_There_has_been_a_major_wind_shif_004e5974);
        uStack_4 = 0x32;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if ((((int)DAT_00535a0c < DAT_005230d8) && (DAT_00522fd8 == 1)) && (0 < DAT_005359d0)) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Tidal_current_is_reduced_by_shal_004e5940);
        uStack_4 = 0x33;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if ((((int)DAT_00535a0c < DAT_005230d8) && (DAT_00522fd8 == 2)) && (0 < DAT_005359d0)) {
        iVar6 = iVar6 + 0x14;
        TStack_14.data = *(char **)(*original_dc + 0x38);
        (*(code *)TStack_14.data)(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Tidal_current_is_reduced_by_land_004e590c);
        uStack_4 = 0x34;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
        (*(code *)TStack_14.data)(original_dc,0x7f0000);
      }
      if (((DAT_005230d8 < (int)DAT_00535a0c) && (DAT_00522fd8 == -1)) && (0 < DAT_005359d0)) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Tidal_current_is_increased_due_t_004e58d8);
        uStack_4 = 0x35;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_004fb210 = 1;
      }
      if (((DAT_004f69c4 == 1) &&
          (7 < (int)((DAT_00535a0c ^ (int)DAT_00535a0c >> 0x1f) - ((int)DAT_00535a0c >> 0x1f)))) &&
         (0 < DAT_005359d0)) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_The_water_has_increased_roughnes_004e5894);
        uStack_4 = 0x36;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (((DAT_004f69c4 == -1) &&
          (7 < (int)((DAT_00535a0c ^ (int)DAT_00535a0c >> 0x1f) - ((int)DAT_00535a0c >> 0x1f)))) &&
         (0 < DAT_005359d0)) {
        iVar6 = iVar6 + 0x14;
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_The_water_is_smoother_because_wi_004e5860);
        uStack_4 = 0x37;
        (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004fb384 < DAT_00522ad0 + -1) {
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_There_is_more_wind_away_from_sho_004e5834);
        uStack_4 = 0x38;
        (*pcVar1)(original_dc,0x1e,iVar6 + 0x14,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        iVar6 = iVar6 + 0x28;
        DAT_004fb210 = 1;
      }
      if ((((0 < DAT_004f69b8) && (0 < DAT_0053545c)) &&
          (uVar4 = DAT_00522b94 - DAT_005362d4 >> 0x1f,
          iVar5 = (DAT_00522b94 - DAT_005362d4 ^ uVar4) - uVar4, 5 < iVar5)) && (iVar5 < 0x163)) {
        (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
        FUN_004b0613((Tact2010CString *)&param_1,s_Your_wind_direction_has_been_cha_004e57fc);
        uStack_4 = 0x39;
        (*pcVar1)(original_dc,0x1e,iVar6 + 0x14,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_005363e4 == 0) {
        (**(code **)(*original_dc + 0x38))(original_dc,0xff);
      }
      FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004e60f8);
      uStack_4 = 0x3a;
      (*pcVar1)(original_dc,0x1e,DAT_004faf7c - iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      FUN_004b4a1f(original_dc,1);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_The_coach_is_not_available_while_004e617c);
    pcVar1 = *(code **)(iVar6 + 100);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,0x1e,2,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_greater_than_10__However__the_po_004e613c);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,0x1e,0x16,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar6 + 0x38))(original_dc,0xff);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004e60f8);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,0x1e,DAT_004faf7c - iVar3,(char *)param_1,param_1[-2]);
    goto LAB_00451e3d;
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_____Post_Race_Comments_____004e57e0);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,0x1e,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  param_1 = (int *)(longlong)(((double)DAT_004f6d2c * _DAT_004cc488) / (double)DAT_00534e94);
  pTVar2 = FUN_0041bc70(&TStack_10,(int)param_1);
  uStack_4 = 1;
  pTVar2 = FUN_004b082f(&TStack_14,s_Percent_beating_time_on_lifted_t_004e57b8,pTVar2);
  uStack_4._0_1_ = 2;
  (*pcVar1)(original_dc,0x1e,0x2a,pTVar2->data,*(int *)(pTVar2->data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_004b05a5(&TStack_14);
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar5 = 0x3e;
  if ((int)param_1 < 0x3d) {
LAB_00451b43:
    if (0x4b < (int)param_1) goto LAB_00451b4a;
  }
  else {
    if ((int)param_1 < 0x4c) {
      FUN_004b0613(&TStack_14,s_Fairly_good_use_of_wind_shifts__004e5798);
      uStack_4 = 3;
      (*pcVar1)(original_dc,0x1e,0x3e,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar5 = 0x52;
      goto LAB_00451b43;
    }
LAB_00451b4a:
    FUN_004b0613(&TStack_14,s_Excellent_use_of_wind_shifts__004e5778);
    uStack_4 = 4;
    (*pcVar1)(original_dc,0x1e,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + 0x14;
  }
  if ((0 < DAT_0051158c) && ((int)param_1 < 0x3d)) {
    FUN_004b0613(&TStack_14,s_Wind_from_the_shore__oscillation_004e5748);
    uStack_4 = 5;
    (*pcVar1)(original_dc,0x1e,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + 0x14;
  }
  if (((4 < (int)((DAT_005231b0 ^ (int)DAT_005231b0 >> 0x1f) - ((int)DAT_005231b0 >> 0x1f))) &&
      (DAT_0051158c == 0)) && ((int)param_1 < 0x3d)) {
    FUN_004b0613(&TStack_14,s_Wind_direction_prior_to_the_star_004e5710);
    uStack_4 = 6;
    (*pcVar1)(original_dc,0x1e,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + 0x14;
  }
  if ((3 < DAT_005364f8 + DAT_00535204) && ((int)param_1 < 0x4c)) {
    FUN_004b0613(&TStack_14,s_Based_on_wind_history_before_the_004e56cc);
    uStack_4 = 7;
    (*pcVar1)(original_dc,0x1e,iVar5,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar5 = iVar5 + 0x14;
  }
  if ((DAT_005364f8 + DAT_00535204 < -3) && ((int)param_1 < 0x4c)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_Based_on_wind_history_before_the_004e5688);
    uStack_4 = 8;
    (*pcVar1)(original_dc,0x1e,iVar5,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar5 = iVar5 + 0x14;
  }
  pTVar2 = FUN_0041bc70(&TStack_10,
                        (int)(longlong)
                             (((double)DAT_004fe768 * _DAT_004cc488) / (double)DAT_00534ea4));
  uStack_4 = 9;
  pTVar2 = FUN_004b082f((Tact2010CString *)&param_1,s_Percent_time_in_bad_air__004e566c,pTVar2);
  uStack_4._0_1_ = 10;
  (*pcVar1)(original_dc,0x1e,iVar5,pTVar2->data,*(int *)(pTVar2->data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  FUN_004b05a5((Tact2010CString *)&param_1);
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar6 = iVar5 + 0x14;
  if (DAT_00536460 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_While_beating__you_overstood_the_004e5644);
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar6 = iVar5 + 0x28;
  }
  if (DAT_00536464 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_While_tacking_downwind__you_over_004e5614);
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,0x1e,iVar6,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar6 = iVar6 + 0x14;
  }
  if ((DAT_00536424 < 1) && (DAT_005363f4 == 0)) {
    FUN_004b0613((Tact2010CString *)&param_1,s_You_should_wait_until_the_last_b_004e55d8);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,0x1e,iVar6 + 0x14,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004e60f8);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,0x1e,DAT_004faf7c - iVar3,(char *)param_1,param_1[-2]);
LAB_00451e3d:
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

