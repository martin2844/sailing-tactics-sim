
void __cdecl FUN_00448100(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar2 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3938;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 900) {
    iVar2 = 0x10;
    local_18 = 0x19;
    local_1c = 5;
    local_14 = 10;
  }
  else {
    iVar2 = 0x13;
    local_18 = 0x1b;
    local_1c = 0x14;
    local_14 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___KEY_COMMAND_SUMMARY___004e0820);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_1c,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = local_18 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f7f);
  }
  if (DAT_004da140 == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,s_All_key_commands_are_single_key__004e07c8);
    uStack_4 = 1;
    (*pcVar1)(original_dc,local_1c,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar3 = iVar3 + iVar2;
    FUN_004b0613((Tact2010CString *)&param_1,s_optional_with_one_player__They_c_004e0778);
    uStack_4 = 2;
    (*pcVar1)(original_dc,local_1c,iVar3,(char *)param_1,param_1[-2]);
  }
  else {
    FUN_004b0613((Tact2010CString *)&param_1,s_All_key_commands_are_single_key__004e0720);
    uStack_4 = 3;
    (*pcVar1)(original_dc,local_1c,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,s_key_commands__Player_1_must_use_c_004e06d4);
    uStack_4 = 4;
    (*pcVar1)(original_dc,local_1c,iVar3 + iVar2,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    iVar3 = iVar3 + iVar2 + iVar2;
    if (DAT_005363e4 == 0) {
      (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
    }
    FUN_004b0613((Tact2010CString *)&param_1,s_Frequently_used_key_commands_are_004e0678);
    uStack_4 = 5;
    (*pcVar1)(original_dc,local_1c,iVar3,(char *)param_1,param_1[-2]);
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f7f7f);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_There_are_additional_key_command_004e0614);
  uStack_4 = 6;
  (*pcVar1)(original_dc,local_1c,iVar3 + iVar2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + iVar2 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_3D_View_Selection__004e0600);
  uStack_4 = 7;
  (*pcVar1)(original_dc,local_1c,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Close_in_View__1_Wide_View__2_Hi_004e059c);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 8;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_Looking_Around_in_3D_Views__004e0580);
  uStack_4 = 9;
  (*pcVar1)(original_dc,local_1c,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Look_Ahead__up_arrow_Look_Right__004e051c);
  uStack_4 = 10;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Look_Upwind__5_Look_to_Leeward__7_004e04c0);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613(&TStack_10,s_Top__from_above__Views__004e04a8);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,local_1c,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Zoom_in_Tactical_View__Z_Zoom_ou_004e0454);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Race_Course__R_Wind_Chart____Tid_004e03f4);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_Steering_Key_Commands__004e03dc);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,local_1c,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_10_Deg_to_Port__<_or___10_Deg_to_004e0374);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Tack__T_Reach__H_Jibe__J_Run_Dow_004e0330);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Higher_Downwind_Angle____Lower_D_004e02f8);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_Sail_Controls__004e02e8);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,local_1c,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Luff_a_Lot__S_Automatic_Sheet__m_004e028c);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Luff_5__Less__Esc_Luff_5__More____004e024c);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Flat__F1_Medium_Draft__F2_Baggy__004e01ec);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0);
  }
  FUN_004b0613(&TStack_10,s_Simulator_Commands__004e01d8);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,local_1c,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Start_or_Resume_Movement__spaceb_004e0178);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Slow_Simulator_a_Lot__spacebar_R_004e0118);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_004b0613(&TStack_10,s_Simulate_Faster__page_up__Num_Lo_004e00b4);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,(int)param_1,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  FUN_004b0613(&TStack_10,s_Slow_Simulator_if_Foul_Likely__b_004e006c);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,(int)param_1,iVar2 + iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x1c;
  (*pcVar1)(original_dc,local_1c,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

