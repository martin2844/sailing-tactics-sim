
void __cdecl FUN_00434470(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int local_1c;
  int local_18;
  int local_14;
  LPCSTR pCStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar2 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047eb50;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 700) {
    iVar2 = 0x10;
    local_18 = 0x16;
    local_1c = 5;
    local_14 = 10;
  }
  else {
    iVar2 = 0x14;
    local_18 = 0x1b;
    local_1c = 0x14;
    local_14 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___KEY_COMMAND_SUMMARY___004960e4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,local_1c,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = local_18 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f7f7f);
  }
  if (DAT_00491140 == 1) {
    FUN_0046bf33(&param_1,s_All_key_commands_are_single_key__0049608c);
    uStack_4 = 1;
    (*pcVar1)(this,local_1c,iVar3,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar3 = iVar3 + iVar2;
    FUN_0046bf33(&param_1,s_optional_with_one_player__They_c_0049603c);
    uStack_4 = 2;
    (*pcVar1)(this,local_1c,iVar3,(LPCSTR)param_1,param_1[-2]);
  }
  else {
    FUN_0046bf33(&param_1,s_All_key_commands_are_single_key__00495fe4);
    uStack_4 = 3;
    (*pcVar1)(this,local_1c,iVar3,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    FUN_0046bf33(&param_1,s_key_commands__Player_1_must_use_c_00495f98);
    uStack_4 = 4;
    (*pcVar1)(this,local_1c,iVar3 + iVar2,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar3 = iVar3 + iVar2 + iVar2;
    if (DAT_004ac92c == 0) {
      (**(code **)(*this + 0x38))(this,0x7f);
    }
    FUN_0046bf33(&param_1,s_Frequently_used_key_commands_are_00495f3c);
    uStack_4 = 5;
    (*pcVar1)(this,local_1c,iVar3,(LPCSTR)param_1,param_1[-2]);
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_3D_View_Selection__00495f28);
  uStack_4 = 6;
  (*pcVar1)(this,local_1c,iVar3 + local_18,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar3 = iVar3 + local_18 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Close_in_View__1_Wide_View__2_Hi_00495ec4);
  param_1 = (int *)(local_14 + local_1c);
  uStack_4 = 7;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_Looking_Around_in_3D_Views__00495ea8);
  uStack_4 = 8;
  (*pcVar1)(this,local_1c,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Look_Ahead__up_arrow_Look_Right__00495e44);
  uStack_4 = 9;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Look_Upwind__5_Look_to_Leeward__7_00495de8);
  uStack_4 = 10;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&pCStack_10,s_Top__from_above__Views__00495dd0);
  uStack_4 = 0xb;
  (*pcVar1)(this,local_1c,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Zoom_in_Tactical_View__Z_Raise_T_00495d80);
  uStack_4 = 0xc;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Race_Course__R_Wind_Chart____Tid_00495d20);
  uStack_4 = 0xd;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f);
  }
  FUN_0046bf33(&pCStack_10,s_Steering_Key_Commands__00495d08);
  uStack_4 = 0xe;
  (*pcVar1)(this,local_1c,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_10_Deg_to_Port__<_10_Deg_to_Star_00495cac);
  uStack_4 = 0xf;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Tack__T_Reach__H_Jibe__J_Run_Dow_00495c68);
  uStack_4 = 0x10;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_Sail_Controls__00495c58);
  uStack_4 = 0x11;
  (*pcVar1)(this,local_1c,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Luff_a_Lot__S_Automatic_Sheet__m_00495bfc);
  uStack_4 = 0x12;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Flat__F1_Medium_Draft__F2_Baggy__00495b9c);
  uStack_4 = 0x13;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + local_18;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0);
  }
  FUN_0046bf33(&pCStack_10,s_Simulator_Commands__00495b88);
  uStack_4 = 0x14;
  (*pcVar1)(this,local_1c,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Start_or_Resume_Movement__spaceb_00495b28);
  uStack_4 = 0x15;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Slow_Simulator_a_Lot__spacebar_R_00495ac8);
  uStack_4 = 0x16;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar3 = iVar3 + iVar2;
  FUN_0046bf33(&pCStack_10,s_Simulate_Faster__page_up__Num_Lo_00495a64);
  uStack_4 = 0x17;
  (*pcVar1)(this,(int)param_1,iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  FUN_0046bf33(&pCStack_10,s_Slow_Simulator_if_Foul_Likely__b_00495a38);
  uStack_4 = 0x18;
  (*pcVar1)(this,(int)param_1,iVar2 + iVar3,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x19;
  (*pcVar1)(this,local_1c,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

