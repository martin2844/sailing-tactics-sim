
void __cdecl FUN_004337a0(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_20;
  int local_1c;
  int local_14;
  LPCSTR pCStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  iVar3 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e9c0;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 700) {
    iVar3 = 0x10;
    local_1c = 0x16;
    local_20 = 5;
    local_14 = 10;
  }
  else {
    iVar3 = 0x14;
    local_1c = 0x1b;
    local_20 = 0x14;
    local_14 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&param_1,s___STEERING___00495584);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,local_20,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&param_1,s_1__One_player_steering__0049556c);
  uStack_4 = 1;
  (*pcVar1)(this,local_20,local_1c + 2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = local_1c + 2 + iVar3;
  FUN_0046bf33(&param_1,s_You_can_steer_by_selections_from_00495514);
  iVar2 = local_14 + local_20;
  uStack_4 = 2;
  (*pcVar1)(this,iVar2,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_by_Control_Button_clicks__by_mov_004954c0);
  uStack_4 = 3;
  (*pcVar1)(this,iVar2,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&param_1,s_clicking_near_your_boat_in_the_3_00495498);
  uStack_4 = 4;
  (*pcVar1)(this,iVar2,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_A__Steering_Zone__00495484);
  uStack_4 = 5;
  (*pcVar1)(this,iVar2,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_If_you_move_the_mouse_pointer_in_00495430);
  uStack_4 = 6;
  param_1 = (int *)(local_20 + local_14 * 2);
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_your_boat_will_turn__Don_t_click_004953d8);
  uStack_4 = 7;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_the_turn__Move_the_pointer_out_o_00495388);
  uStack_4 = 8;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_B__Click_Steering__00495374);
  uStack_4 = 9;
  (*pcVar1)(this,iVar2,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Move_the_mouse_pointer_near_your_00495324);
  uStack_4 = 10;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_is_close_enough__Each_click_of_t_004952d4);
  uStack_4 = 0xb;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_port__Clicking_the_right_button_t_00495294);
  uStack_4 = 0xc;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&pCStack_10,s_C__Steer_Menu__associated_Key_Co_00495254);
  uStack_4 = 0xd;
  (*pcVar1)(this,iVar2,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_>_and_<_keys:_You_don_t_have_to_h_00495204);
  uStack_4 = 0xe;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Closehauled__beat___Your_boat_be_004951a4);
  uStack_4 = 0xf;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Pinch__Your_boat_beats_5_deg_clo_00495144);
  uStack_4 = 0x10;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Tack__Your_boat_tacks_and_assume_004950e8);
  uStack_4 = 0x11;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff0000);
  }
  FUN_0046bf33(&pCStack_10,s_Reach__Your_boat_turns_to_a_beam_0049508c);
  uStack_4 = 0x12;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Jibe__Your_boat_jibes_and_assume_00495030);
  uStack_4 = 0x13;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + iVar3;
  FUN_0046bf33(&pCStack_10,s_Run_Downwind__Your_boat_turns_to_00494fd4);
  uStack_4 = 0x14;
  (*pcVar1)(this,(int)param_1,iVar4,pCStack_10,*(int *)(pCStack_10 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_10);
  iVar4 = iVar4 + local_1c;
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_2__Two_player_steering__00494fbc);
  uStack_4 = 0x15;
  (*pcVar1)(this,local_20,iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_Player_2_uses_Key_Commands__Play_00494f5c);
  uStack_4 = 0x16;
  (*pcVar1)(this,local_20,iVar3 + iVar4,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x17;
  (*pcVar1)(this,local_20,(DAT_004a72d0 * 9) / 10 + -2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

