
void __cdecl FUN_004354d0(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar2 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047ed10;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 700) {
    local_14 = 0x10;
    local_10 = 0x16;
    iVar2 = 5;
  }
  else {
    iVar2 = 0x14;
    local_10 = 0x1b;
    local_14 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___SUGGESTIONS_FOR_FIRST_TIME_USE_00497010);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar2,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_1__Use_a_low_enough_Simulate_Spe_00496fb8);
  uStack_4 = 1;
  (*pcVar1)(this,iVar2,local_10 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = local_10 + 2 + local_14;
  FUN_0046bf33(&param_1,s_If_you_need_more_time__such_as_a_00496f60);
  uStack_4 = 2;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_simulation__Press_the_Spacebar_a_00496f10);
  uStack_4 = 3;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_Simulation_halts_if_you_open_a_m_00496ec4);
  uStack_4 = 4;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_2__Before_the_start__press_S__ma_00496e70);
  uStack_4 = 5;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_boat_by_turning_toward_the_wind__00496e1c);
  uStack_4 = 6;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_press_C__closehauled_course___00496dfc);
  uStack_4 = 7;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_3__After_the_start__use_automati_00496dac);
  uStack_4 = 8;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_for_a_closehauled_course_which_f_00496d5c);
  uStack_4 = 9;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_D_for_a_fast_course_which_follow_00496d20);
  uStack_4 = 10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_4__Rounding_a_mark__press_the_Sp_00496ccc);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_to_the_next_mark__Mouse_click_st_00496c7c);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_pressing_H_to_reach__D_to_run__a_00496c2c);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_will_speed_and_slow_the_simulato_00496bec);
  uStack_4 = 0xe;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_5__Select_Coach__Y_key__often_fo_00496b98);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_more_detailed_advice_see_the_Tut_00496b5c);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_6__If_your_boat_starts_wild_turn_00496b00);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_7__Use_the_option_to_have_warnin_00496aa8);
  uStack_4 = 0x12;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  FUN_0046bf33(&param_1,s_menu___If_your_mainsail_turns_re_00496a50);
  uStack_4 = 0x13;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_8__Mainsail_shape_is_important__I_00496a0c);
  uStack_4 = 0x14;
  (*pcVar1)(this,iVar2,iVar3 + local_10,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x15;
  (*pcVar1)(this,iVar2,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

