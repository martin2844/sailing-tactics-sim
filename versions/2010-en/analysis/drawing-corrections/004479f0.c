
void __cdecl FUN_004479f0(int *param_1)

{
  code *pcVar1;
  int *original_dc;
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
  
  original_dc = param_1;
  iVar2 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3840;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 900) {
    iVar2 = 5;
    local_1c = 0x11;
    local_18 = 0x18;
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
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___SAIL_CONTROL___004e0058);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar2,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Sail_controls_are_in_the_Sail_Me_004e0008);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,local_18 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = local_18 + 2 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_and_in_the_left_group_of_Control_004dffdc);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_1__Sheet_Commands__004dffc8);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,
               "Sheet commands let you control boatspeed before the start and when avoiding a collision."
              );
  iVar2 = iVar2 + local_10;
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_At_other_times__choose_Automatic_004dff24);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_The_computer_eases_the_sheet_if_t_004dfed4);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s__004dfea4);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s__004dfe50);
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_for_fine_control__Alternatively__004dfdf4);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_luffing__Rotate_it_away_from_you_004dfd9c);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_These_commnds_control_luffing__Y_004dfd40);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_Switch_to_Automatic_Sheet_contro_004dfce4);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_control_speed_with_the_A_004dfc98);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_control_speed_more_gradu_004dfc54);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Alternative__you_can_control_spe_004dfc08);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_to_toggle_between_Automatic_Shee_004dfbb8);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_useful_for_pre_start_speed_contr_004dfb94);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_2__Sail_Commands__004dfb80);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,local_14,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_From_the_Sail_Menu_you_can_selec_004dfb30);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_1c;
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_switch_among_these_choic_004dfad4);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_set_and_drop_a_spinnaker_004dfa80);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Spin_Button__Winging_and_Unwingi_004dfa50);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,iVar2,local_1c + iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,local_14,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

