
void __cdecl FUN_0044b0e0(int *param_1)

{
  code *pcVar1;
  int *original_dc;
  int iVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
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
  pcStack_8 = FUN_004c3ec8;
  *unaff_FS_OFFSET = &uStack_c;
  if (iVar2 < 900) {
    local_18 = 0xe;
    local_14 = 0x16;
    iVar2 = 5;
  }
  else {
    local_18 = 0x11;
    local_14 = 0x18;
    iVar2 = 0x14;
  }
  iVar3 = *param_1;
  param_1 = *(int **)(iVar3 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar4 = 0x7f0000;
  }
  else {
    iVar4 = 0;
  }
  (*(code *)param_1)(original_dc,iVar4);
  FUN_004b0613(&TStack_10,s___CREATING_A_PERSONAL_RACE_AREA___004e3a68);
  pcVar1 = *(code **)(iVar3 + 100);
  uStack_4 = 0;
  (*pcVar1)(original_dc,iVar2,5,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f7f00);
  }
  FUN_004b0613(&TStack_10,s_The_Options_Menu_offers_many_rac_004e3a10);
  uStack_4 = 1;
  (*pcVar1)(original_dc,iVar2,local_14 + 5,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = local_14 + 5 + local_18;
  FUN_004b0613(&TStack_10,s__004e3a08);
  uStack_4 = 2;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_If_you_select__Create_Personal_R_004e39b0);
  uStack_4 = 3;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_will_be_displayed__Also_the_Crea_004e3958);
  uStack_4 = 4;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_Menu_define_the_race_area__004e393c);
  uStack_4 = 5;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f7f00);
  }
  FUN_004b0613(&TStack_10,s_The_race_area_can_be_large_for_b_004e38e0);
  uStack_4 = 6;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_The_race_area_can_have_up_to_two_004e387c);
  uStack_4 = 7;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,
               "Choose the direction to this shore from the race area, its shoreline shape, and whether the land is hilly or flat."
              );
  uStack_4 = 8;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s__004e37ec);
  uStack_4 = 9;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_If_you_select__Primary_Shore_Nea_004e3798);
  uStack_4 = 10;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f007f);
  }
  FUN_004b0613(&TStack_10,s_If_you_select__Primary_Shore_Ver_004e3734);
  uStack_4 = 0xb;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_the_distance_to_the_first_mark_a_004e36c4);
  uStack_4 = 0xc;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_from_the_Options_Menu__the_race_w_004e365c);
  uStack_4 = 0xd;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_possible__For_this_very_near_sho_004e35ec);
  uStack_4 = 0xe;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_boat_types_have_depth_informatio_004e357c);
  uStack_4 = 0xf;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f7f00);
  }
  FUN_004b0613(&TStack_10,s_The_optional_secondary_land_can_b_004e3518);
  uStack_4 = 0x10;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_other_side_of_a_river_or_bay__If_004e34b4);
  uStack_4 = 0x11;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_Other_options_for_the_secondary_l_004e3464);
  uStack_4 = 0x12;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_It_is_OK_if_the_secondary_land_o_004e3400);
  uStack_4 = 0x13;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_If_you_want_a_sea_or_lake_breeze_004e33b0);
  uStack_4 = 0x14;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f7f00);
  }
  FUN_004b0613(&TStack_10,
               "For current, choose tidal current that changes direction with time, or a steady river current."
              );
  uStack_4 = 0x15;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,
               "A current from the right flows from your right as you face the primary shore from the race area."
              );
  uStack_4 = 0x16;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_Ebb_currents_flow_in_the_opposit_004e3298);
  uStack_4 = 0x17;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s__004e3280);
  uStack_4 = 0x18;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_14;
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0xff7f00);
  }
  FUN_004b0613(&TStack_10,s_If_you_select__Tropical_Waters__t_004e3220);
  uStack_4 = 0x19;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  iVar3 = iVar3 + local_18;
  FUN_004b0613(&TStack_10,s_because_the_warm_water_increases_004e31dc);
  uStack_4 = 0x1a;
  (*pcVar1)(original_dc,iVar2,iVar3,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0x7f0000);
  }
  FUN_004b0613(&TStack_10,s_Race_area_selections_must_be_mad_004e31a0);
  uStack_4 = 0x1b;
  (*pcVar1)(original_dc,iVar2,iVar3 + local_14,TStack_10.data,*(int *)(TStack_10.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_10);
  if (DAT_005363e4 == 0) {
    (*(code *)param_1)(original_dc,0xff);
  }
  FUN_004b0613((Tact2010CString *)&param_1,s_Press_Spacebar_or_Click_Mouse_to_004dd9ec);
  uStack_4 = 0x1c;
  (*pcVar1)(original_dc,iVar2,(DAT_004fe2a8 * 9) / 10 + -0x1e,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

