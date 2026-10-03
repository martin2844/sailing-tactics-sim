
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00445830(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *this;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  LPCSTR pCStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484dc8;
  pcStack_8 = FUN_0047fc18;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar3 = 0x10;
    local_18 = 0x16;
    local_1c = 5;
    local_14 = 10;
  }
  else {
    iVar3 = 0x14;
    local_18 = 0x1b;
    local_1c = 0x14;
    local_14 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___WIND_PREDICTION___1_0049be54);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,local_1c,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_The_best_sources_of_wind_predict_0049bdfc);
  uStack_4 = 1;
  (*pcVar1)(this,local_1c,local_18 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = local_18 + 2 + iVar3;
  FUN_0046bf33(&param_1,s_for_dark_puffs_and_lighter__glas_0049bda0);
  uStack_4 = 2;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_the_motion_of_puffs__Pre_race_wi_0049bd44);
  uStack_4 = 3;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_compass_headings_beating_on_each_0049bcec);
  uStack_4 = 4;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_wind_oscillating__How_much_time_b_0049bc94);
  uStack_4 = 5;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_A_couple_of_thousand_feet_up_the_0049bc38);
  uStack_4 = 6;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_low_pressure__As_one_gets_closer_0049bbd8);
  uStack_4 = 7;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_slowing_is_usually_greater_than_o_0049bb78);
  uStack_4 = 8;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_as_it_is_slowed__That_is__the_hi_0049bb18);
  uStack_4 = 9;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Stability_and_Mixing__The_amount_0049babc);
  uStack_4 = 10;
  (*pcVar1)(this,local_1c,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_temperature_of_the_surface_and_t_0049ba80);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 0xb;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&pCStack_10,s_If_the_surface_is_hot_and_the_ai_0049ba24);
  uStack_4 = 0xc;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_air_in_the_process__This_mixing_b_0049b9c8);
  uStack_4 = 0xd;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_called_unstable_air__The_puffs_b_0049b96c);
  uStack_4 = 0xe;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_to_the_lulls__There_will_probabl_0049b910);
  uStack_4 = 0xf;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_cool_water_with_warm_land_to_win_0049b8b4);
  uStack_4 = 0x10;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_near_shore_obstacles_such_as_tre_0049b880);
  uStack_4 = 0x11;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_If_the_surface_is_cool_and_the_a_0049b81c);
  uStack_4 = 0x12;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_slowing__The_wind_will_probably_b_0049b7bc);
  uStack_4 = 0x13;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_air__Wind_reduction_due_to_trees_0049b75c);
  uStack_4 = 0x14;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  FUN_0046bf33(&pCStack_10,s_sky_will_likely_be_all_clear_or_u_0049b728);
  uStack_4 = 0x15;
  (*pcVar1)(this,(int)param_1,iVar3 + iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press___for_next_topic_or___for_p_0049b6c8);
  uStack_4 = 0x16;
  (*pcVar1)(this,local_1c,iVar3 + DAT_004a600c,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  DAT_004ac994 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

