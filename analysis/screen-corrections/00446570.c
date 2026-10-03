
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00446570(int *param_1)

{
  code *pcVar1;
  double dVar2;
  int *this;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar2 = _DAT_004aa7d8 * _DAT_00484dc8;
  pcStack_8 = FUN_0047fd78;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar2;
  if (DAT_004a763c < 700) {
    local_14 = 0x10;
    local_10 = 0x16;
    iVar3 = 5;
  }
  else {
    iVar3 = 0x14;
    local_10 = 0x1b;
    local_14 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___CURRENTS___0049ca28);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar3,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Especially_in_light_winds__curre_0049c9d0);
  uStack_4 = 1;
  (*pcVar1)(this,iVar3,local_10 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = local_10 + 2 + local_14;
  FUN_0046bf33(&param_1,s_vary_in_direction_and_strength_o_0049c998);
  uStack_4 = 2;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Adverse_currents_have_more_impac_0049c94c);
  uStack_4 = 3;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_With_no_current__your_speed_made_0049c8f8);
  uStack_4 = 4;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_adverse_current__your_speed_made_0049c8a4);
  uStack_4 = 5;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_goes_from_1_hour_to_2_hours__How_0049c850);
  uStack_4 = 6;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_go_from_1_hour_to_half_an_hour__T_0049c804);
  uStack_4 = 7;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Currents_are_fairly_predictable__0049c7ac);
  uStack_4 = 8;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_For_many_areas__the_government_p_0049c754);
  uStack_4 = 9;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_Similar_information_is_available_0049c704);
  uStack_4 = 10;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_Currents_tend_to_parallel_shorel_0049c6b0);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_Currents_flow_in_and_out_of_rive_0049c65c);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_14;
  FUN_0046bf33(&param_1,s_even_if_the_point_is_a_shoal_sli_0049c628);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_10;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Currents_are_usually_slowed_by_f_0049c5cc);
  uStack_4 = 0xe;
  (*pcVar1)(this,iVar3,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_Currents_are_partially_blocked_b_0049c598);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar3,local_14 + iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  DAT_004ac994 = 0;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press___for_next_topic_or___for_p_0049b6c8);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar3,local_14 + DAT_004a600c,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

