
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00445ee0(int *param_1)

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
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484dc8;
  pcStack_8 = FUN_0047fce0;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    iVar3 = 5;
    local_1c = 0x10;
    local_18 = 0x16;
    local_14 = 5;
    local_10 = 10;
  }
  else {
    local_18 = 0x1b;
    local_1c = 0x14;
    local_14 = 0x14;
    local_10 = 0x14;
    iVar3 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___WIND_PREDICTION___2_0049c580);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar3,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Sea_Breeze__When_the_land_is_war_0049c520);
  uStack_4 = 1;
  (*pcVar1)(this,iVar3,local_18 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = local_18 + 2 + local_1c;
  FUN_0046bf33(&param_1,s_land_may_develop_in_the_late_mor_0049c4c4);
  iVar3 = iVar3 + local_10;
  uStack_4 = 2;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_Because_of_the_rotation_of_the_E_0049c468);
  uStack_4 = 3;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_veer_as_the_day_progresses__0049c448);
  uStack_4 = 4;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  FUN_0046bf33(&param_1,s_A_sea_breeze_is_actually_a_circu_0049c3e8);
  uStack_4 = 5;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_higher_up__If_the_early_morning_w_0049c38c);
  uStack_4 = 6;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_likely_since_the_return_flow_wil_0049c328);
  uStack_4 = 7;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Weather_Systems__In_the_Northern_0049c2c8);
  uStack_4 = 8;
  (*pcVar1)(this,local_14,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_counterclockwise_around_low_pres_0049c26c);
  uStack_4 = 9;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_to_east__If_either_a_high_or_a_l_0049c20c);
  uStack_4 = 10;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_to_the_south__the_wind_will_back_0049c1ac);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Channeling__If_air_is_flowing_ro_0049c148);
  uStack_4 = 0xc;
  (*pcVar1)(this,local_14,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_to_become_more_parallel_especial_0049c0e4);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Convergence__If_two_air_masses_t_0049c080);
  uStack_4 = 0xe;
  (*pcVar1)(this,local_14,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_the_air_masses_have_similar_temp_0049c040);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  FUN_0046bf33(&param_1,s_If_you_are_sailing_downwind_with_0049bfe8);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_will_be_slowed_and_backed_relati_0049bf88);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_0046bf33(&param_1,s_land_is_to_port__the_slowing_and_0049bf2c);
  uStack_4 = 0x12;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0);
  }
  FUN_0046bf33(&param_1,s_Southern_Hemisphere__Earth_rotat_0049bec8);
  uStack_4 = 0x13;
  (*pcVar1)(this,local_14,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_In_this_simulator__see_the_Wind_C_0049be6c);
  uStack_4 = 0x14;
  (*pcVar1)(this,local_14,iVar4 + local_18,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  DAT_004ac994 = 0;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press___for_next_topic_or___for_p_0049b6c8);
  uStack_4 = 0x15;
  (*pcVar1)(this,local_14,local_1c + DAT_004a600c,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

