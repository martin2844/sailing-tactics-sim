
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045c440(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *original_dc;
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
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc608;
  pcStack_8 = FUN_004c4f20;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
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
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___WIND_PREDICTION___2_004e9578);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar3,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Sea_Breeze__When_the_land_is_war_004e9518);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar3,local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_18 + 2 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_land_may_develop_in_the_late_mor_004e94bc);
  iVar3 = iVar3 + local_10;
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_Because_of_Earth_rotation__the_N_004e9460);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s__004e9440);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_A_sea_breeze_is_actually_a_circu_004e93e0);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_higher_up__If_the_early_morning_w_004e9384);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_likely_since_the_return_flow_wil_004e9320);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Weather_Systems__In_the_Northern_004e92c0);
  uStack_4 = 8;
  (*pcVar1)(original_dc,local_14,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_counterclockwise_around_low_pres_004e9264);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_east__If_either_a_high_or_a_l_004e9204);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_the_south__the_wind_will_back_004e91a4);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Channeling__If_air_is_flowing_ro_004e9140);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,local_14,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_become_more_parallel_especial_004e90dc);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Convergence__If_two_air_masses_t_004e9078);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,local_14,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_the_air_masses_have_similar_temp_004e9038);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_you_are_sailing_downwind_with_004e8fe0);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_will_be_slowed_and_backed_relati_004e8f80);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_land_is_to_port__the_slowing_and_004e8f24);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Southern_Hemisphere__Earth_rotat_004e8ec0);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,local_14,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_In_this_simulator__see_the_Wind_C_004e8e64);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,local_14,iVar4 + local_18,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  DAT_00536458 = 0;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press___for_next_topic_or___for_p_004e86c0);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,local_14,local_1c + DAT_004faf7c,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

