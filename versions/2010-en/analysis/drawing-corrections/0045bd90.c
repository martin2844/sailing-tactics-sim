
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045bd90(int *param_1)

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
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc608;
  pcStack_8 = FUN_004c4e58;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
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
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___WIND_PREDICTION___1_004e8e4c);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_1c,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_The_best_sources_of_wind_predict_004e8df4);
  uStack_4 = 1;
  (*pcVar1)(original_dc,local_1c,local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_18 + 2 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_for_dark_puffs_and_lighter__glas_004e8d98);
  uStack_4 = 2;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_the_motion_of_puffs__Pre_race_wi_004e8d3c);
  uStack_4 = 3;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_compass_headings_beating_on_each_004e8ce4);
  uStack_4 = 4;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_wind_oscillating__How_much_time_b_004e8c8c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_A_couple_of_thousand_feet_up_the_004e8c30);
  uStack_4 = 6;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_low_pressure__As_one_gets_closer_004e8bd0);
  uStack_4 = 7;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_slowing_is_usually_greater_than_o_004e8b70);
  uStack_4 = 8;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_as_it_is_slowed__That_is__the_hi_004e8b10);
  uStack_4 = 9;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Stability_and_Mixing__The_amount_004e8ab4);
  uStack_4 = 10;
  (*pcVar1)(original_dc,local_1c,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_temperature_of_the_surface_and_t_004e8a78);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_If_the_surface_is_hot_and_the_ai_004e8a1c);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_air_in_the_process__This_mixing_b_004e89c0);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_called_unstable_air__The_puffs_b_004e8964);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_to_the_lulls__There_will_probabl_004e8908);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_cool_water_with_warm_land_to_win_004e88ac);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_near_shore_obstacles_such_as_tre_004e8878);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_If_the_surface_is_cool_and_the_a_004e8814);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_slowing__The_wind_will_probably_b_004e87b4);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_air__Wind_reduction_due_to_trees_004e8754);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  FUN_004b0613(&TStack_10,s_sky_will_likely_be_all_clear_or_u_004e8720);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,(int)param_1,iVar3 + iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press___for_next_topic_or___for_p_004e86c0);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,local_1c,iVar3 + DAT_004faf7c,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  DAT_00536458 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

