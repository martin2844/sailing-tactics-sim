
void __cdecl FUN_004471e0(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_20;
  int local_1c;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  iVar3 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c3770;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 900) {
    iVar3 = 0x10;
    local_1c = 0x15;
    local_20 = 5;
    local_14 = 10;
  }
  else {
    iVar3 = 0x14;
    local_1c = 0x1b;
    local_20 = 0x14;
    local_14 = 0x14;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___STEERING___004dfa40);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,local_20,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_1__One_player_steering__004dfa28);
  uStack_4 = 1;
  (*pcVar1)(original_dc,local_20,local_1c + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = local_1c + 2 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_steer_by_selections_from_004df9d0);
  iVar2 = local_14 + local_20;
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s_by_Control_Button_clicks__by_mov_004df97c);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar2,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613((Tact2010CString *)&param_1,s__004df954);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar2,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_A__Steering_Zone__004df940);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar2,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_If_you_move_the_mouse_pointer_in_004df8ec);
  uStack_4 = 6;
  param_1 = (int *)(local_20 + local_14 * 2);
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_your_boat_will_turn__Don_t_click_004df894);
  uStack_4 = 7;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_the_turn__Move_the_pointer_out_o_004df83c);
  uStack_4 = 8;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_turns_opposite_of_the_wheel__004df81c);
  uStack_4 = 9;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_B__Click_Steering__004df808);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,
               "Move the pointer within an inch of the hull in the 3D View. Each left-button click turns the boat 10 degrees"
              );
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_to_port__each_right_button_click_004df768);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__004df720);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_C__Steer_Menu__associated_Key_Co_004df6e0);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar2,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_>_and_<_keys:_Your_boat_turns_10_004df67c);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__Closehauled___Beat_Button___You_004df610);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__Pinch___Your_boat_beats_5_deg_c_004df5ac);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s_If_you_want_to_sail_a_normal_clo_004df540);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,local_20 + local_14 * 3,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__Tack___Your_boat_tacks_and_assu_004df4e0);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s__Reach___Your_boat_turns_to_a_be_004df480);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__Jibe___Your_boat_jibes_and_assu_004df420);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,
               "Run Downwind: Sail the best angle for downwind progress. Manual steering ends this command."
              );
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_004b0613(&TStack_10,s__High_7_Deg___Tack_downwind_7_de_004df37c);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_All_these_steering_commands_end_i_004df314);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,(int)param_1,iVar4,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_2__Two_player_steering__004df2fc);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,local_20,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b0613((Tact2010CString *)&param_1,s_Player_2_uses_Key_Commands__Play_004df29c);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,local_20,iVar3 + iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,local_20,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

