
void __cdecl FUN_00432920(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_18;
  LPCSTR pCStack_14;
  code *local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e818;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 700) {
    iVar3 = 0x10;
    local_18 = 0x16;
  }
  else {
    iVar3 = 0x14;
    local_18 = 0x1e;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  iVar1 = *param_1;
  local_10 = *(code **)(iVar1 + 0x34);
  (*local_10)(param_1,0xffffff);
  FUN_0046bf33(&pCStack_14,s___WHAT_YOU_SEE___Note__This_scre_004948d4);
  pcVar2 = *(code **)(iVar1 + 100);
  uStack_4 = 0;
  (*pcVar2)(param_1,0x14,2,pCStack_14,*(int *)(pCStack_14 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_14);
  iVar4 = local_18 + 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar1 + 0x38))(param_1,0xff0000);
  }
  if (DAT_00491140 == 1) {
    if (DAT_004a4e8c < 3) {
      FUN_0046bf33(&pCStack_14,s_The_3D_Sailing_view_fills_the_to_00494874);
      uStack_4 = 1;
      (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
      if (DAT_004ac9d8 == 0) {
        FUN_0046bf33(&pCStack_14,s_Apparent_wind__tidal_current__ma_00494818);
        uStack_4 = 2;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      else {
        FUN_0046bf33(&pCStack_14,s_True_wind__tidal_current__mark_d_004947c0);
        uStack_4 = 3;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + local_18;
      if (DAT_004ac92c == 0) {
        (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
      }
      if (DAT_004ac9c8 == 0) {
        FUN_0046bf33(&pCStack_14,s_Top_views_are_in_the_bottom_half_00494760);
        uStack_4 = 4;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        FUN_0046bf33(&pCStack_14,s_a_Strategic_view_is_on_the_left__00494700);
        uStack_4 = 5;
        (*pcVar2)(param_1,0x14,iVar4 + iVar3,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        iVar4 = iVar4 + iVar3 + iVar3;
        FUN_0046bf33(&pCStack_14,s_is_a_text_window_with_performanc_004946ac);
        uStack_4 = 6;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        iVar4 = iVar4 + iVar3;
        FUN_0046bf33(&pCStack_14,s_background__and_the_Steering_Zon_00494650);
        uStack_4 = 7;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      else {
        FUN_0046bf33(&pCStack_14,s_A_zoomable__tactical_Top_view_is_004945f4);
        uStack_4 = 8;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        FUN_0046bf33(&pCStack_14,s_or_boat_shape__On_the_left_is_a_t_0049459c);
        uStack_4 = 9;
        (*pcVar2)(param_1,0x14,iVar4 + iVar3,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        iVar4 = iVar4 + iVar3 + iVar3;
        FUN_0046bf33(&pCStack_14,s_control_buttons__gray_background_0049453c);
        uStack_4 = 10;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_14);
        iVar4 = iVar4 + iVar3;
        FUN_0046bf33(&pCStack_14,s_the_pointer_in_it__To_show_a_str_004944dc);
        uStack_4 = 0xb;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
    }
    if ((DAT_00491140 == 1) && (DAT_004a4e8c == 3)) {
      if (DAT_004ac92c == 0) {
        (*local_10)(param_1,0xffffff);
      }
      FUN_0046bf33(&pCStack_14,s_The_3D_Sailing_view_fills_the_ri_00494478);
      uStack_4 = 0xc;
      (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
      if (DAT_004ac9d8 == 0) {
        FUN_0046bf33(&pCStack_14,s_Apparent_wind__tidal_current__ma_00494420);
        uStack_4 = 0xd;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      else {
        FUN_0046bf33(&pCStack_14,s_True_wind__tidal_current__mark_d_004943cc);
        uStack_4 = 0xe;
        (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      if (DAT_004ac92c == 0) {
        (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
      }
      FUN_0046bf33(&pCStack_14,s_A_zoomable_Tactical_view_is_on_t_00494378);
      uStack_4 = 0xf;
      (*pcVar2)(param_1,0x14,iVar4 + local_18,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + local_18 + iVar3;
      FUN_0046bf33(&pCStack_14,s_Also_on_the_left_is_a_text_windo_00494328);
      uStack_4 = 0x10;
      (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
      FUN_0046bf33(&pCStack_14,s_control_buttons__gray_background_004942dc);
      uStack_4 = 0x11;
      (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
      FUN_0046bf33(&pCStack_14,s_if_you_steer_by_putting_the_mous_004942a8);
      uStack_4 = 0x12;
      (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_14);
      iVar4 = iVar4 + iVar3;
    }
  }
  if (DAT_00491140 == 2) {
    FUN_0046bf33(&pCStack_14,s_The_screen_is_split_with_Player_1_00494250);
    uStack_4 = 0x13;
    (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_3D_Sailing_views_fill_the_top_pa_004941fc);
    uStack_4 = 0x14;
    (*pcVar2)(param_1,0x14,iVar4 + iVar3,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    iVar4 = iVar4 + iVar3 + iVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0xff0000);
    }
    FUN_0046bf33(&pCStack_14,s_Zoomable_Tactical_views_are_on_t_004941a8);
    uStack_4 = 0x15;
    (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    iVar4 = iVar4 + iVar3;
    FUN_0046bf33(&pCStack_14,s_red_cross_or_boat_shape__Player_2_0049415c);
    uStack_4 = 0x16;
    (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    iVar4 = iVar4 + iVar3;
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
    }
    FUN_0046bf33(&pCStack_14,s_Also_on_the_bottom_are_text_wind_0049410c);
    uStack_4 = 0x17;
    (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    iVar4 = iVar4 + iVar3;
    FUN_0046bf33(&pCStack_14,s_Player_1_has_control_buttons__gr_004940b4);
    uStack_4 = 0x18;
    (*pcVar2)(param_1,0x14,iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
    FUN_0046bf33(&pCStack_14,s_show_the_key_to_be_pressed_to_gi_00494084);
    uStack_4 = 0x19;
    (*pcVar2)(param_1,0x14,iVar3 + iVar4,pCStack_14,*(int *)(pCStack_14 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_14);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(iVar1 + 0x38))(param_1,0xff);
  }
  FUN_0046bf33(&pCStack_14,s_Press_Spacebar_or_Click_Mouse_to_004936e8);
  uStack_4 = 0x1a;
  (*pcVar2)(param_1,0x1e,DAT_004a72d0 / 3 - iVar3,pCStack_14,*(int *)(pCStack_14 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_14);
  (**(code **)(iVar1 + 0x38))(param_1,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

