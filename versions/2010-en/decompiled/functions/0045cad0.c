
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0045cad0(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *original_dc;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_005230b0 * _DAT_004cc608;
  pcStack_8 = FUN_004c4fb8;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004faf7c = (int)(longlong)dVar2;
  if (DAT_004fe624 < 700) {
    local_14 = 0x10;
    local_10 = 0x16;
    iVar3 = 5;
  }
  else {
    iVar3 = 0x14;
    local_10 = 0x1b;
    local_14 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___CURRENTS___004e9a20);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar3,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Especially_in_light_winds__curre_004e99c8);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar3,local_10 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_10 + 2 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_vary_in_direction_and_strength_o_004e9990);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Adverse_currents_have_more_impac_004e9944);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_With_no_current__your_speed_made_004e98f0);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_adverse_current__your_speed_made_004e989c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_goes_from_1_hour_to_2_hours__How_004e9848);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_go_from_1_hour_to_half_an_hour__T_004e97fc);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Currents_are_fairly_predictable__004e97a4);
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_For_many_areas__the_government_p_004e974c);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_Similar_information_is_available_004e96fc);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Currents_tend_to_parallel_shorel_004e96a8);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_Currents_flow_in_and_out_of_rive_004e9654);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_even_if_the_point_is_a_shoal_sli_004e9620);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Currents_are_usually_slowed_by_f_004e95c4);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar3,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Currents_are_partially_blocked_b_004e9590);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar3,local_14 + iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  DAT_00536458 = 0;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press___for_next_topic_or___for_p_004e86c0);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar3,local_14 + DAT_004faf7c,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

