
void __cdecl FUN_00448970(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar3 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3a98;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 0x2bd) {
    local_1c = 0xd;
    local_18 = 0xe;
    iVar2 = 5;
    local_14 = 10;
  }
  else {
    local_1c = 0xe;
    local_18 = 0x15;
    iVar2 = 0x12;
    local_14 = 0x14;
    if (iVar3 < 900) {
      local_1c = 0xd;
      local_18 = 0x10;
      iVar2 = 0;
      local_14 = 0xf;
    }
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f);
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "************** LATEST FEATURES ************** (Since the 2008 edition)");
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar2,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_1__Tactics__protest_decisions_an_004e17d4);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,local_1c + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = local_1c + 2 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_2__Three_boat_types_were_added__E_004e1774);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_The_E_Scow_has_a_large_asymmetri_004e1744);
  uStack_4 = 3;
  param_1 = (int *)(iVar2 + local_14);
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_3__After_the_race_you_can_displa_004e16dc);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Tracks__Boat_1_is_red__Player_2_i_004e1674);
  uStack_4 = 5;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Tracks_in_bad_air_are_black__Tra_004e1610);
  uStack_4 = 6;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f00);
  }
  FUN_004b0613(&TStack_10,s_In_a_series__Show_Tracks_in_Top_V_004e159c);
  uStack_4 = 7;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_You_can_hide_tracks__Tracks_begi_004e1528);
  uStack_4 = 8;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_4__Many_graphics_improvements_ha_004e14ec);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s________________NEW_FEATURES______004e14a8);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_5__Create_a_personal_race_area_t_004e1434);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_See_Creating_a_Personal_Race_Are_004e13f4);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_6__Eighteen_real_racing_areas_ad_004e137c);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Newport_RI__Block_Island_RI__Rou_004e1304);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Thurmond_Lake_GA_SC__Biscayne_Ba_004e1290);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  if (DAT_004fe624 < 0x3e9) {
    FUN_004b0613(&TStack_10,s_7__Options_adds_25ft_Sportboat__3_004e10f8);
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    FUN_004b0613(&TStack_10,s_Four_types_were_added__The_sport_004e1084);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)param_1,iVar3 + local_1c,TStack_10.data,*(int *)(TStack_10.data + -8)
             );
  }
  else {
    FUN_004b0613(&TStack_10,s_7__Four_new_types_in_Options__25_004e1200);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    FUN_004b0613(&TStack_10,s_Sportboats_and_the_offshore_cata_004e1174);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,(int)param_1,iVar3 + local_1c,TStack_10.data,*(int *)(TStack_10.data + -8)
             );
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  if (DAT_004fe624 < 0x385) {
    FUN_004b0613(&TStack_10,s_8__Wind_and_currents_are_more_re_004e0f8c);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  }
  else {
    FUN_004b0613(&TStack_10,s_8__Wind_and_current_logic_is_mor_004e1004);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  FUN_004b0613(&TStack_10,s_Current_logic_is_more_detailed_a_004e0f0c);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,(int)param_1,iVar3 + local_1c,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c + local_1c;
  FUN_004b0613(&TStack_10,s_Some_boats_may_be_in_calmer_wate_004e0ec4);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_9__At_higher_difficulty_levels__t_004e0e4c);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_At_higher_levels_speed_differenc_004e0dd0);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_10__Hiding_the_strategic_view_sh_004e0d74);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_or_when_sailing_very_close_to_sh_004e0d14);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  if (DAT_004fe624 < 0x385) {
    FUN_004b0613(&TStack_10,s_11__Color_Mainsails_if_Bad_Air__b_004e0c14);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  }
  else {
    FUN_004b0613(&TStack_10,s_11__Select_Color_Mainsails_if_Ba_004e0c88);
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s________________EARLIER_NEW_FEATU_004e0bc4);
  uStack_4 = 0x1e;
  (*pcVar1)(original_dc,iVar2,iVar3 + local_18,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_12__Boats_have_names__Click_a_hu_004e0b44);
  uStack_4 = 0x1f;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_13__A_gate_can_be_selected_at_th_004e0ad0);
  uStack_4 = 0x20;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Gates_are_selected_automatically_004e0a60);
  uStack_4 = 0x21;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_14__Your_tacking_downwind_course_004e0a08);
  uStack_4 = 0x22;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_Use___and___keys_or_the_High_and_004e09bc);
  uStack_4 = 0x23;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_15__Replay_Leg_in_the_Control_me_004e094c);
  uStack_4 = 0x24;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_16__Your_mainsail_turns_red_when_004e08ec);
  uStack_4 = 0x25;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613(&TStack_10,s_If_Slow_Simulator_if_Foul_Likely_004e0890);
  uStack_4 = 0x26;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  FUN_004b0613(&TStack_10,s_the_simulator_slows_to_its_lowes_004e083c);
  uStack_4 = 0x27;
  (*pcVar1)(original_dc,(int)param_1,iVar3 + local_1c,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x28;
  (*pcVar1)(original_dc,iVar2,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

