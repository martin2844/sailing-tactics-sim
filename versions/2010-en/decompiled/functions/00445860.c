
void __cdecl FUN_00445860(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString local_18;
  int local_14;
  Tact2010CString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c34b0;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b4a1f(param_1,2);
  if (DAT_004fe624 < 0x385) {
    param_1 = (int *)0xe;
    local_14 = 0x11;
    iVar2 = 5;
  }
  else {
    param_1 = (int *)0x10;
    local_14 = 0x14;
    iVar2 = 0xf;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0x7f0000);
  }
  FUN_004b0613(&local_18,s___SIMULATOR_OPERATION___004de238);
  uStack_4 = 0;
  pcVar1 = *(code **)(*original_dc + 100);
  (*pcVar1)(original_dc,iVar2,2,local_18.data,*(int *)(local_18.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_18);
  iVar3 = local_14 + 2;
  if (DAT_005363e4 == 0) {
    (**(code **)(*original_dc + 0x38))(original_dc,0xff0000);
  }
  local_18.data = *(char **)(*original_dc + 0x38);
  (*(code *)local_18.data)(original_dc,0x7f0000);
  FUN_004b0613(&TStack_10,s_A_good_choice_for_screen_resolut_004dcc98);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_work_well_1280x768_or_1680x1050_w_004dcc28);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  if (1000 < DAT_004fe624) {
    (*(code *)local_18.data)(original_dc,0xff0000);
    FUN_004b0613(&TStack_10,s_However__resolution_selection_ma_004dcbb4);
    uStack_4 = 3;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    iVar3 = iVar3 + (int)param_1;
    FUN_004b0613(&TStack_10,s_circle_in_the_upper_right_corner_004dcb3c);
    uStack_4 = 4;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    iVar3 = iVar3 + (int)param_1;
    FUN_004b0613(&TStack_10,s_want_a_different_screen_resoluti_004dcae4);
    uStack_4 = 5;
    (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_10);
    iVar3 = iVar3 + (int)param_1;
  }
  (*(code *)local_18.data)(original_dc,0x7f0000);
  FUN_004b0613(&TStack_10,s_In_rare_cases__Graphics_Accelera_004dca6c);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_changed_with_the_Windows_Control_004dca00);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  (*(code *)local_18.data)(original_dc,0x7f7f00);
  FUN_004b0613(&TStack_10,s_2__If_you_use_large_fonts_or_800_004de1d4);
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_explanations_unless_you_unselect_004dc938);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_Then_click_Properties_and_unsele_004dc8dc);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  (*(code *)local_18.data)(original_dc,0x7f0000);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_You_can_also_increase_viewing_ar_004dc884);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_3__If_you_want_to_change_Options_004de178);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_select__Another_Race___Control_M_004de130);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_4__Important__Choose_a_good_simu_004de0d4);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_Your_primary_control_of_simulato_004de078);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_as_when_rounding_a_mark__press_t_004de020);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_Other_factors_affect_simulator_s_004ddfc4);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_A__Reduce_Fleet_Size__B__Don_t_d_004ddf5c);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,iVar2 + 8,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_C__Select_Simplify_Graphics__Con_004ddef8);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,iVar2 + 8,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff);
  }
  FUN_004b0613(&TStack_10,s_5__If_movement_is_stopped__a_red_004dde98);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f);
  }
  FUN_004b0613(&TStack_10,s_If__Slow_Simulator_if_Foul_Likel_004dde24);
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_will_be_set_to_1__Resume_simulat_004dddb8);
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_6__You_can_control_your_boat_s__a_004ddd58);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s__Num_Lock_off___by_clicks_on_Con_004ddcf8);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_Zone__The_menus_have_all_command_004ddc9c);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_Move_the_pointer_to_a_menu_item_a_004ddc38);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff0000);
  }
  FUN_004b0613(&TStack_10,s_7__Control_Buttons_are_frequentl_004ddbcc);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  FUN_004b0613(&TStack_10,s_pointer_to_a_Control_Button__Don_004ddb60);
  uStack_4 = 0x1c;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + (int)param_1;
  (*(code *)local_18.data)(original_dc,0);
  FUN_004b0613((Tact2010CString *)&param_1,s_A_selected_Control_Button_has_bl_004ddb34);
  uStack_4 = 0x1d;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff0000);
  }
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_8__Many_commands_reverse_effect_w_004ddad4);
  uStack_4 = 0x1e;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0x7f00);
  }
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_9__When_there_are_2_players__pla_004dda7c);
  uStack_4 = 0x1f;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff00ff);
  }
  iVar3 = iVar3 + local_14;
  FUN_004b0613((Tact2010CString *)&param_1,s_10__To_quit_the_simulator__selec_004dda20);
  uStack_4 = 0x20;
  (*pcVar1)(original_dc,iVar2,iVar3,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  if (DAT_005363e4 == 0) {
    (*(code *)local_18.data)(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x21;
  (*pcVar1)(original_dc,iVar2,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

