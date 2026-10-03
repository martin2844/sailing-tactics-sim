
void __cdecl FUN_00432000(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *this;
  int iVar3;
  int iVar4;
  LPCSTR pCVar5;
  undefined4 *unaff_FS_OFFSET;
  LPCSTR local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar2 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e730;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = 5;
  if (iVar2 < 700) {
    local_14 = (LPCSTR)0xd;
    local_10 = 0x12;
    iVar3 = 1;
    iVar4 = 2;
  }
  else {
    local_14 = (LPCSTR)0x10;
    local_10 = 0x16;
    iVar3 = 0x14;
  }
  if (900 < iVar2) {
    iVar3 = 0x14;
    local_10 = 0x1c;
    local_14 = (LPCSTR)0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___SIMULATOR_OPERATION___0049406c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_1__The_best_screen_resolution__d_00494014);
  uStack_4 = 1;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = local_14 + iVar4;
  FUN_0046bf33(&param_1,s_distortion__However__800x600__sm_00493fb0);
  uStack_4 = 2;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_cause_problems__Resolution_and_a_00493f54);
  uStack_4 = 3;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_16_bit_color_is_a_good_choice__H_00493ef0);
  uStack_4 = 4;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xffff);
    (**(code **)(*this + 0x34))(this,0);
  }
  FUN_0046bf33(&param_1,s_2__You_should_unselect_Always_on_00493e94);
  uStack_4 = 5;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_clutter__This_is_necessary_to_se_00493e3c);
  uStack_4 = 6;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
    (**(code **)(*this + 0x34))(this,0xffffff);
  }
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_3__If_you_want_to_change_Options_00493df0);
  uStack_4 = 7;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_you_will_have_to_select__Another_00493da4);
  uStack_4 = 8;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s_4__Important__Choose_a_good_simu_00493d48);
  uStack_4 = 9;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Your_primary_control_of_simulato_00493cec);
  uStack_4 = 10;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_as_when_adjusting_sails__press_t_00493c94);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Other_factors_affect_simulator_s_00493c38);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_A__Reduce_Fleet_Size_B__Select_S_00493bd4);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar3 + 8,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_C__Select_Shoreline_to_East_or_W_00493b78);
  uStack_4 = 0xe;
  (*pcVar1)(this,iVar3 + 8,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_5__If_movement_is_stopped__a_red_00493b18);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_6__You_can_control_your_boat_s__a_00493ab8);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s__Num_Lock_off___by_clicks_on_Con_00493a58);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_Zone__The_menus_have_all_command_004939fc);
  uStack_4 = 0x12;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_Move_the_pointer_to_a_menu_item_a_00493998);
  uStack_4 = 0x13;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_7__Control_Buttons_have_frequent_0049393c);
  uStack_4 = 0x14;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  FUN_0046bf33(&param_1,s_player__move_the_pointer_to_a_Co_004938d8);
  uStack_4 = 0x15;
  (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  pCVar5 = pCVar5 + (int)local_14;
  if (DAT_004a763c < 0x2bd) {
    FUN_0046bf33(&param_1,s_above_the_Steering_Zone__00493858);
    uStack_4 = 0x17;
    (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  }
  else {
    FUN_0046bf33(&param_1,s_above_the_Steering_Zone__These_a_00493874);
    uStack_4 = 0x16;
    (*pcVar1)(this,iVar3,(int)pCVar5,(LPCSTR)param_1,param_1[-2]);
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  param_1 = *(int **)(*this + 0x38);
  (*(code *)param_1)(this,0);
  if (DAT_004a763c < 700) {
    FUN_0046bf33(&local_14,s_A_selected_Control_Button_has_bl_0049382c);
    uStack_4 = 0x18;
    (*pcVar1)(this,DAT_004a763c / 3,(int)pCVar5,local_14,*(int *)(local_14 + -8));
  }
  else {
    pCVar5 = pCVar5 + (int)local_14;
    FUN_0046bf33(&local_14,s_A_selected_Control_Button_has_bl_0049382c);
    uStack_4 = 0x19;
    (*pcVar1)(this,iVar3,(int)pCVar5,local_14,*(int *)(local_14 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_14);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0xff0000);
  }
  pCVar5 = pCVar5 + local_10;
  FUN_0046bf33(&local_14,s_8__Many_commands_reverse_effect_w_004937d0);
  uStack_4 = 0x1a;
  (*pcVar1)(this,iVar3,(int)pCVar5,local_14,*(int *)(local_14 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_14);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0x7f00);
  }
  pCVar5 = pCVar5 + local_10;
  FUN_0046bf33(&local_14,s_9__When_there_are_2_players__pla_00493778);
  uStack_4 = 0x1b;
  (*pcVar1)(this,iVar3,(int)pCVar5,local_14,*(int *)(local_14 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_14);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0xff00ff);
  }
  FUN_0046bf33(&local_14,s_10__To_quit_the_simulator__selec_0049371c);
  uStack_4 = 0x1c;
  (*pcVar1)(this,iVar3,(int)(pCVar5 + local_10),local_14,*(int *)(local_14 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_14);
  if (DAT_004ac92c == 0) {
    (*(code *)param_1)(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x1d;
  (*pcVar1)(this,iVar3,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

