
void __cdecl FUN_004495e0(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar2 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3ba8;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 900) {
    local_14 = 0xe;
    local_10 = 0x12;
    iVar2 = 5;
  }
  else {
    local_14 = 0x11;
    local_10 = 0x19;
    iVar2 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___SUGGESTIONS_FOR_SIMULATOR_RACI_004e216c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar2,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_1__Use_a_low_enough_Simulate_Spe_004e2114);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,local_10 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = local_10 + 2 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_you_need_more_time__such_as_a_004e20bc);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_simulation__Press_the_Spacebar_a_004e206c);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_Simulation_halts_if_you_open_a_m_004e2020);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_2__Before_the_start__press_S_for_004e1fcc);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,
               "slow her by heading towards the wind. Press A for Automatic Sheet and C for Closehauled to accelerate."
              );
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s__004e1f58);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "3. After the start, use automatic steering as much as possible. Upwind, press C or the Beat button to sail"
              );
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_a_closehauled_course_following_s_004e1e98);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_On_a_run__press_D_or_the_Run_but_004e1e30);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "4. At mark roundings, press the Spacebar to gain time for adjustments. The gray line leads to the next"
              );
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_the_next_mark__004e1dc8);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_It_switches_to_the_next_mark_sho_004e1d88);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Mouse_click_steering_is_an_easy_w_004e1d34);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_D_to_run__and_C_to_beat__Repeate_004e1ce4);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_the_simulator_as_you_work_around_004e1cb8);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_5__Select_Coach__Y_key__often_fo_004e1c64);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_more_detailed_advice_see_the_Tut_004e1c0c);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_Not_all_computer_controlled_boat_004e1bb4);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,
               "6. If your boat starts turning on its own or leaves a closehauled course, the mouse pointer"
              );
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_is_in_the_Steering_Zone__004e1b20);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_7__Use_Slow_Simulator_if_Foul_Li_004e1ac8);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,
               "This gives you more time to keep clear of a right-of-way boat. Press the Spacebar or a Control Button"
              );
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Faster_repeatedly_to_resto_004e1a34);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_8__Mainsail_shape_matters__Ask_t_004e19f0);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_9__After_you_finish__increase_si_004e1998);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_10__In_two_player_mode__the_othe_004e1958);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_11__If_your_main_is_red_and_spee_004e18f4);
  uStack_4 = 0x1c;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Change_course_to_avoid_a_foul__o_004e1888);
  uStack_4 = 0x1d;
  (*pcVar1)(original_dc,iVar2,local_14 + iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x1e;
  (*pcVar1)(original_dc,iVar2,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

