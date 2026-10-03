
void __cdecl FUN_00446a70(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
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
  pcStack_8 = FUN_004c3680;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 700) {
    iVar2 = 1;
    local_18 = 0x10;
    local_14 = 0x16;
    local_10 = 1;
  }
  else {
    local_10 = 0x14;
    local_18 = 0x13;
    iVar2 = 0x14;
    local_14 = 0x1a;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s___VIEW_CONTROL___004df288);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar2,2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_1__All_view_control_commands_can_004df230);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,local_14 + 2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = local_14 + 2 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_However__after_you_are_used_to_t_004df1d4);
  iVar2 = iVar2 + 10;
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Button_clicks_for_most_view_cont_004df194);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_2__3D_Viewpoint_selection__004df178);
  uStack_4 = 4;
  (*pcVar1)(original_dc,local_10,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_The_first_three_items_in_the_3D_V_004df120);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_You_can_change_these_by_pressing_004df0dc);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_If_you_select_Automatic_View__th_004df078);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_3__Looking_around_in_3D_views__004df058);
  uStack_4 = 8;
  (*pcVar1)(original_dc,local_10,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,
               "The Look menu items rotate the view. Look Right and Look Left turn it 30 degrees per selection."
              );
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Look_to_Windward_faces_upwind__L_004defa8);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Look_around_commands_can_also_be_004def48);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_With_Num_Lock_off__the_look_arou_004deef0);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s__004deed4);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f00);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_4__Top_Views__004deec4);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,local_10,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,
               "These views look down from above. With Z/X keys or the Control Buttons in the view, the Tactical View can"
              );
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,
               "be zoomed quickly. Menu options to rotate Tactical and Strategic Views independently of the 3D View"
              );
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_are_available_in_the_menu__004dedb8);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff00);
  }
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Track_colors__Boat_1_is_red__Wit_004ded50);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Upwind_tracks_are_solid__downwin_004decec);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_On_a_twice_around_course__the_se_004deca0);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_5__Three_information_charts_are_a_004dec4c);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,local_10,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_These_charts_freeze_the_simulati_004dec00);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_004b0613((Tact2010CString *)&param_1,s_Each_Tide_Chart__1_Hour_selectio_004deba8);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff00ff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_6__In_two_player_mode__each_play_004deb50);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,local_10,iVar3 + local_14,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,local_10,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

