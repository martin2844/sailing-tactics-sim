
void __cdecl FUN_00446250(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int local_18;
  Tact2010CString TStack_14;
  code *local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c35a0;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar3 < 700) {
    iVar3 = 0x10;
    local_18 = 0x16;
  }
  else {
    iVar3 = 0x14;
    local_18 = 0x1e;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  iVar1 = *param_1;
  local_10 = *(code **)(iVar1 + 0x34);
  (*local_10)(param_1,0xffffff);
  FUN_004b0613(&TStack_14,s___WHAT_YOU_SEE___Note__This_scre_004deaf4);
  pcVar2 = *(code **)(iVar1 + 100);
  uStack_4 = 0;
  (*pcVar2)(param_1,0x14,2,TStack_14.data,*(int *)(TStack_14.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_14);
  iVar4 = local_18 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar1 + 0x38))(param_1,0xff0000);
  }
  if (DAT_004da140 == 1) {
    if (DAT_004f71c4 < 3) {
      FUN_004b0613(&TStack_14,s_The_3D_Sailing_view_fills_the_to_004dea94);
      uStack_4 = 1;
      (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + iVar3;
      if (DAT_00536498 == 0) {
        FUN_004b0613(&TStack_14,s_Apparent_wind__tidal_current__ma_004dea38);
        uStack_4 = 2;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      }
      else {
        FUN_004b0613(&TStack_14,s_True_wind__tidal_current__mark_d_004de9e0);
        uStack_4 = 3;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + local_18;
      if (DAT_005363e4 == 0) {
        (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
      }
      if (DAT_004da1a8 == 0) {
        FUN_004b0613(&TStack_14,
                     "Top Views fill the lower half of the screen: a zoomable Tactical View on the right and a Strategic View on the left."
                    );
        uStack_4 = 4;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        FUN_004b0613(&TStack_14,
                     "Your boat is a red boat shape or cross. Between the two views is a Text Window with performance data on a white background"
                    );
        uStack_4 = 5;
        (*pcVar2)(param_1,0x14,iVar4 + iVar3,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3 + iVar3;
        FUN_004b0613(&TStack_14,
                     "and control buttons on a gray background, plus a Steering Zone that, when controlled with the pointer, shows"
                    );
        uStack_4 = 6;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3;
        FUN_004b0613(&TStack_14,s_a_Steering_Zone_that_changes_col_004de870);
        uStack_4 = 7;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3;
      }
      else {
        FUN_004b0613(&TStack_14,
                     "A zoomable Tactical View is at the lower left of the screen. Your boat is a red cross or a boat shape."
                    );
        uStack_4 = 8;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        FUN_004b0613(&TStack_14,
                     "On the left are performance data on a white background and control buttons on a gray background,"
                    );
        uStack_4 = 9;
        (*pcVar2)(param_1,0x14,iVar4 + iVar3,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3 + iVar3;
        FUN_004b0613(&TStack_14,s_a_Text_Window_and_a_Steering_Zon_004de75c);
        uStack_4 = 10;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3;
        FUN_004b0613(&TStack_14,s_To_show_the_Strategic_View__clea_004de6fc);
        uStack_4 = 0xb;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
        iVar4 = iVar4 + iVar3;
        if (DAT_005363e4 == 0) {
          (**(code **)(iVar1 + 0x38))(param_1,0xff0000);
        }
        FUN_004b0613(&TStack_14,s_Tracks_are_dotted_when_the_wind_c_004de6a8);
        uStack_4 = 0xc;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_14);
      }
    }
    if ((DAT_004da140 == 1) && (DAT_004f71c4 == 3)) {
      if (DAT_005363e4 == 0) {
        (*local_10)(param_1,0xffffff);
      }
      FUN_004b0613(&TStack_14,s_The_3D_sailing_view_occupies_the_004de644);
      uStack_4 = 0xd;
      (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + iVar3;
      if (DAT_00536498 == 0) {
        FUN_004b0613(&TStack_14,s_Apparent_wind__current__bearing_t_004de5ec);
        uStack_4 = 0xe;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      }
      else {
        FUN_004b0613(&TStack_14,s_True_wind__current__bearing_to_t_004de598);
        uStack_4 = 0xf;
        (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      if (DAT_005363e4 == 0) {
        (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
      }
      FUN_004b0613(&TStack_14,s_The_zoomable_tactical_view_is_on_004de544);
      uStack_4 = 0x10;
      (*pcVar2)(param_1,0x14,iVar4 + local_18,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + local_18 + iVar3;
      FUN_004b0613(&TStack_14,s_The_left_side_also_has_performan_004de4f4);
      uStack_4 = 0x11;
      (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + iVar3;
      FUN_004b0613(&TStack_14,s_The_button_text_window_and_a_ste_004de4a8);
      uStack_4 = 0x12;
      (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + iVar3;
      FUN_004b0613(&TStack_14,s_are_also_displayed__004de474);
      uStack_4 = 0x13;
      (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_14);
      iVar4 = iVar4 + iVar3;
    }
  }
  if (DAT_004da140 == 2) {
    FUN_004b0613(&TStack_14,s_Player_1_s_views_are_on_the_righ_004de41c);
    uStack_4 = 0x14;
    (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_The_upper_3D_sailing_views_show_e_004de3c8);
    uStack_4 = 0x15;
    (*pcVar2)(param_1,0x14,iVar4 + iVar3,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar4 = iVar4 + iVar3 + iVar3;
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0xff0000);
    }
    FUN_004b0613(&TStack_14,s_Zoomable_tactical_views_occupy_t_004de374);
    uStack_4 = 0x16;
    (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar4 = iVar4 + iVar3;
    FUN_004b0613(&TStack_14,s_Player_2_s_boat_appears_as_a_gre_004de328);
    uStack_4 = 0x17;
    (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar4 = iVar4 + iVar3;
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar1 + 0x38))(param_1,0x7f0000);
    }
    FUN_004b0613(&TStack_14,s_Performance_data_also_appear_bel_004de2d8);
    uStack_4 = 0x18;
    (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    iVar4 = iVar4 + iVar3;
    FUN_004b0613(&TStack_14,s_Player_1_has_gray_control_button_004de280);
    uStack_4 = 0x19;
    (*pcVar2)(param_1,0x14,iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
    FUN_004b0613(&TStack_14,s_similar_buttons_showing_the_key_c_004de250);
    uStack_4 = 0x1a;
    (*pcVar2)(param_1,0x14,iVar3 + iVar4,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_14);
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(iVar1 + 0x38))(param_1,0xff);
  }
  FUN_004b0613(&TStack_14,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x1b;
  (*pcVar2)(param_1,0x1e,DAT_004fe2a8 / 3 - iVar3,TStack_14.data,*(int *)(TStack_14.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_14);
  (**(code **)(iVar1 + 0x38))(param_1,0);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

