
void __cdecl FUN_00433ea0(int *param_1)

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
  iVar2 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047ea68;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 700) {
    iVar2 = 5;
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
    iVar2 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___SAIL_CONTROL___00495a24);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar2,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_Sail_controls_are_in_the_Sail_Me_004959d4);
  uStack_4 = 1;
  (*pcVar1)(this,iVar2,local_18 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = local_18 + 2 + local_1c;
  FUN_0046bf33(&param_1,s_and_in_the_left_group_of_Control_004959a8);
  uStack_4 = 2;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_1__Sheet_Commands__00495994);
  uStack_4 = 3;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_The_purpose_of_the_Sheet_command_00495944);
  iVar2 = iVar2 + local_10;
  uStack_4 = 4;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_the_pre_start_period_and_when_av_004958f4);
  uStack_4 = 5;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_using_Automatic_Sheet_for_maximu_004958a4);
  uStack_4 = 6;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_when_necessary_to_prevent_excess_00495874);
  uStack_4 = 7;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_You_can_control_speed_with_the_A_00495828);
  uStack_4 = 8;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_You_can_control_speed_more_gradu_004957ec);
  uStack_4 = 9;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_Alternative__you_can_kill_speed_b_00495794);
  uStack_4 = 10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_When_you_do_so_the_button_name_w_00495740);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_will_be_trimmed_for_max_speed_an_004956f4);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_2__Sail_Commands__004956e0);
  uStack_4 = 0xd;
  (*pcVar1)(this,local_14,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_From_the_Sail_Menu_you_can_selec_00495690);
  uStack_4 = 0xe;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_0046bf33(&param_1,s_You_can_switch_among_these_choic_00495634);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_You_can_set_and_drop_a_spinnaker_004955e0);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s__spin__button_in_the_left_button_00495594);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar2,local_1c + iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x12;
  (*pcVar1)(this,local_14,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

