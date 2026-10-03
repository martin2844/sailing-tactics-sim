
void __cdecl FUN_00434c10(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar3 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047ec48;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 0x2bd) {
    iVar2 = 5;
    local_1c = 0xd;
    local_18 = 0x10;
    local_14 = 5;
    local_10 = 10;
  }
  else {
    local_14 = 0x12;
    iVar2 = 0x12;
    local_1c = 0x14;
    local_18 = 0x1a;
    local_10 = 0x14;
    if (iVar3 < 900) {
      local_14 = 0x12;
      local_1c = 0x10;
      iVar2 = 0x12;
      local_18 = 0x15;
      local_10 = 0xf;
    }
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___NEW_FEATURES___004969f8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar2,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_1__An_option_to_suppress_the_Str_0049699c);
  uStack_4 = 1;
  (*pcVar1)(this,iVar2,local_18 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = local_18 + 2 + local_1c;
  FUN_0046bf33(&param_1,s_this_item_enlarges_the_text_wind_00496940);
  iVar2 = iVar2 + local_10;
  uStack_4 = 2;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_run_somewhat_faster__Select_this_004968f4);
  uStack_4 = 3;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_2__An_option_to_show_true_wind_i_00496894);
  uStack_4 = 4;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_to_the_Control_menu__0049687c);
  uStack_4 = 5;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_3__Control_Button_explanations_h_0049681c);
  uStack_4 = 6;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_click__An_explanation_of_it_s_ac_004967c0);
  uStack_4 = 7;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_frequently_with_your_situation_e_00496774);
  uStack_4 = 8;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_These_explanations_can_be_turned_00496734);
  uStack_4 = 9;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s___________________________VERY_N_004966ec);
  uStack_4 = 10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s_4__Changes_in_the_Racing_Rules_e_0049668c);
  uStack_4 = 0xb;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_Tutorial__in_behavior_of_the_com_0049663c);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_5__You_can_now_replay_a_leg_in_p_004965e4);
  uStack_4 = 0xd;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_Select_Replay_Leg_from_the_Contr_004965a0);
  uStack_4 = 0xe;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s_6__An_option_to_have_a_warning_o_00496544);
  uStack_4 = 0xf;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_to_the_Control_menu__Your_mainsa_004964f4);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_If_you_also_select_Slow_Simulato_00496494);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_are_likely_to_foul__Press_spaceb_0049643c);
  uStack_4 = 0x12;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_7__New_racing_areas_catagories__B_004963e0);
  uStack_4 = 0x13;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_been_added_to_the_Racing_Area_Su_00496388);
  uStack_4 = 0x14;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_channeled_by_shores_and_the_rive_00496328);
  uStack_4 = 0x15;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_8__The_racing_areas__Sound__Rive_004962cc);
  uStack_4 = 0x16;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_upgraded_for_more_challenging_wi_00496280);
  uStack_4 = 0x17;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&param_1,s_9__From_the_Options_Menu__you_ca_00496224);
  uStack_4 = 0x18;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_also_select_to_have_no_pre_start_004961c4);
  uStack_4 = 0x19;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_With_a_perfect_start__you_can_re_00496160);
  uStack_4 = 0x1a;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f7f);
  }
  FUN_0046bf33(&param_1,s_10__The_Simulate_Speed_Menu_has_b_00496100);
  uStack_4 = 0x1b;
  (*pcVar1)(this,local_14,iVar3 + local_18,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x1c;
  (*pcVar1)(this,local_14,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

