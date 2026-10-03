
void __cdecl FUN_004330f0(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
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
  pcStack_8 = FUN_0047e8e8;
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
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___VIEW_CONTROL___00494f48);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,iVar2,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_1__All_view_control_commands_can_00494ef0);
  uStack_4 = 1;
  (*pcVar1)(this,iVar2,local_14 + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = local_14 + 2 + local_18;
  FUN_0046bf33(&param_1,s_However__after_you_are_used_to_t_00494e94);
  iVar2 = iVar2 + 10;
  uStack_4 = 2;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_bar_clicks_for_most_view_control_00494e58);
  uStack_4 = 3;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_2__3D_Viewpoint_selection__00494e3c);
  uStack_4 = 4;
  (*pcVar1)(this,local_10,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_The_first_three_items_in_the_3D_V_00494de4);
  uStack_4 = 5;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_You_can_change_these_by_pressing_00494d9c);
  uStack_4 = 6;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_If_you_select_Automatic_View__th_00494d38);
  uStack_4 = 7;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_3__Looking_around_in_3D_views__00494d18);
  uStack_4 = 8;
  (*pcVar1)(this,local_10,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_The_menu_items_beginning_with__l_00494cc0);
  uStack_4 = 9;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_your_view_by_30_degrees_per_sele_00494c68);
  uStack_4 = 10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_Look_Downwind_is_the_opposite__L_00494c0c);
  uStack_4 = 0xb;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_bar_with_the_eyes_at_the_top__If_00494bb4);
  uStack_4 = 0xc;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_made_from_the_number_pad__00494b98);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_4__Top_Views__00494b88);
  uStack_4 = 0xe;
  (*pcVar1)(this,local_10,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_These_views_are_from_above__The_T_00494b2c);
  uStack_4 = 0xf;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_or_by_clicking_on_the_control_bu_00494ad0);
  uStack_4 = 0x10;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_so_that_the_Tactical_and_Strateg_00494a7c);
  uStack_4 = 0x11;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0);
  }
  FUN_0046bf33(&param_1,s_5__There_are_three_informational_00494a28);
  uStack_4 = 0x12;
  (*pcVar1)(this,local_10,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_Movement_is_suspended_while_you_l_004949dc);
  uStack_4 = 0x13;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18;
  FUN_0046bf33(&param_1,s_The_Tide_Chart_advances_1_hour_i_00494984);
  uStack_4 = 0x14;
  (*pcVar1)(this,iVar2,iVar3,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff00ff);
  }
  FUN_0046bf33(&param_1,s_6__When_there_are_two_players__e_00494930);
  uStack_4 = 0x15;
  (*pcVar1)(this,local_10,iVar3 + local_14,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x16;
  (*pcVar1)(this,local_10,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

