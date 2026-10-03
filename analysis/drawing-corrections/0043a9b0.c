
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043a9b0(int *param_1)

{
  code *pcVar1;
  int *this;
  int iVar2;
  TactCString *pTVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  TactCString TStack_14;
  TactCString TStack_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047f2b0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = DAT_004a72d0 / 3;
  iVar4 = ((699 < DAT_004a763c) - 1 & 0xfffffffc) + 0x14;
  iVar6 = 2;
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  if ((DAT_004ac93c != 1) && (DAT_004a764c < 1)) {
    if (DAT_00491190 < 0xb) {
      FUN_0046bf33(&param_1,s_Sailing_OK__Better_may_be_possib_004990dc);
      uStack_4 = 0x12;
      pcVar1 = *(code **)(*this + 100);
      (*pcVar1)(this,0x1e,2,(LPCSTR)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
      if ((DAT_004a60a8 == 0) && (DAT_004a5b80 < 0x14)) {
        FUN_0046bf33(&param_1,s_The_Weather_forecast_has_informa_004990a4);
        uStack_4 = 0x13;
        (*pcVar1)(this,0x1e,2,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = 0x16;
      }
      if ((DAT_004a61f4 == 1) && (-1 < DAT_004a85d4)) {
        FUN_0046bf33(&param_1,s_Heeling_too_much__00499070);
        uStack_4 = 0x14;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_004a620c == 1) {
        FUN_0046bf33(&param_1,s_You_are_taking_the_headed_tack_a_00499034);
        uStack_4 = 0x15;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_004a620c == 2) {
        FUN_0046bf33(&param_1,s_You_are_approaching_the_layline_t_00499008);
        uStack_4 = 0x16;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_004a620c == 3) {
        FUN_0046bf33(&param_1,s_You_have_overstood_the_mark__00498fd4);
        uStack_4 = 0x17;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004ac99c = 1;
      }
      if (DAT_004a620c == -1) {
        FUN_0046bf33(&param_1,s_You_are_taking_the_lifted_jibe_a_00498f98);
        uStack_4 = 0x18;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_004a620c == -2) {
        FUN_0046bf33(&param_1,s_You_are_approaching_the_downwind_00498f64);
        uStack_4 = 0x19;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_004a620c == -3) {
        FUN_0046bf33(&param_1,s_You_passed_the_downwind_layline_t_00498f38);
        uStack_4 = 0x1a;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004ac9a0 = 1;
      }
      if (DAT_004a61f8 == 1) {
        FUN_0046bf33(&param_1,s_You_are_sailing_in_bad_air__00498f04);
        uStack_4 = 0x1b;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if ((DAT_004a776c == 3) && (DAT_004a7bcc < 0x3c)) {
        FUN_0046bf33(&param_1,s_Mainsail_too_baggy_for_beating__00498ed0);
        uStack_4 = 0x1c;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (((DAT_004a776c == 2) && (DAT_004a7bcc < 0x3c)) && (0xd < DAT_004a633c)) {
        FUN_0046bf33(&param_1,s_Mainsail_probably_too_baggy_for_b_00498e94);
        uStack_4 = 0x1d;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (((DAT_004a776c == 1) && (DAT_004a633c < 0xe)) && (DAT_004a7bcc < 0x51)) {
        FUN_0046bf33(&param_1,s_Mainsail_may_be_too_flat__00498e60);
        uStack_4 = 0x1e;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (((DAT_004a776c < 3) && (0x50 < DAT_004a7bcc)) && (DAT_004a8aac < 0x14)) {
        FUN_0046bf33(&param_1,s_Mainsail_too_flat__00498e2c);
        uStack_4 = 0x1f;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      bVar7 = false;
      if (DAT_004a4efc == 1) {
        if ((((6 < DAT_00491188) && (DAT_00491188 < 9)) && (0x14 < DAT_004a8aac)) &&
           ((0 < DAT_004a5b80 && (DAT_004abb74 == 0)))) {
          FUN_0046bf33(&param_1,s_Jib_may_be_too_big__00498df8);
          uStack_4 = 0x20;
          (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&param_1);
          iVar6 = iVar6 + 0x14;
          DAT_004a61e8 = 1;
        }
        bVar7 = DAT_004a4efc == 1;
      }
      if (((!bVar7 && 0 < DAT_004a4efc) && (6 < DAT_00491188)) &&
         (((DAT_00491188 < 9 && (((DAT_004a8aac == 0 && (0 < DAT_004a5b80)) && (DAT_004abb74 == 0)))
           ) && (DAT_004a6ecc < 0x12)))) {
        FUN_0046bf33(&param_1,s_Jib_may_be_too_small__00498dc4);
        uStack_4 = 0x21;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if ((DAT_004ac20c < DAT_004aa800) && (DAT_004aa720 == 1)) {
        FUN_0046bf33(&param_1,s_Tidal_current_is_reduced_by_shal_00498d90);
        uStack_4 = 0x22;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if ((DAT_004ac20c < DAT_004aa800) && (DAT_004aa720 == 2)) {
        FUN_0046bf33(&param_1,s_Tidal_current_is_reduced_by_land_00498d5c);
        uStack_4 = 0x23;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if ((DAT_004aa800 < DAT_004ac20c) && (DAT_004aa720 == -1)) {
        FUN_0046bf33(&param_1,s_Tidal_current_is_increased_due_t_00498d28);
        uStack_4 = 0x24;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (DAT_004a633c < DAT_004aa390 + -1) {
        FUN_0046bf33(&param_1,s_There_is_more_wind_away_from_sho_00498cfc);
        uStack_4 = 0x25;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if ((((0 < DAT_004a4958) && (0 < DAT_004abd84)) &&
          (uVar5 = DAT_004aa5b4 - DAT_004ac840 >> 0x1f,
          iVar2 = (DAT_004aa5b4 - DAT_004ac840 ^ uVar5) - uVar5, 5 < iVar2)) && (iVar2 < 0x163)) {
        FUN_0046bf33(&param_1,s_Your_wind_direction_has_been_cha_00498cc4);
        uStack_4 = 0x26;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + iVar4;
      }
      if (((DAT_00491188 == 8) && (100 < DAT_004a7bcc)) &&
         ((DAT_004aa390 < 0xd && ((DAT_004a4174 < 3 && (0 < DAT_004a5b80)))))) {
        FUN_0046bf33(&param_1,s_You_should_tack_downwind_with_th_00498c8c);
        uStack_4 = 0x27;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (DAT_004a4388 == 1) {
        if (((0 < DAT_004ac5f4) && (2 < DAT_00491188)) && (DAT_00491188 != 9)) {
          FUN_0046bf33(&param_1,s_Spinnaker_is_breaking__00498c58);
          uStack_4 = 0x28;
          (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&param_1);
          iVar6 = iVar6 + 0x14;
          DAT_004a61e8 = 1;
        }
        if (((DAT_004a4388 == 1) && (0 < DAT_004ac5f4)) && (DAT_00491188 == 2)) {
          FUN_0046bf33(&param_1,s_Jib_is_backing__Don_t_wing_jib__00498c24);
          uStack_4 = 0x29;
          (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&param_1);
          iVar6 = iVar6 + 0x14;
          DAT_004a61e8 = 1;
        }
      }
      if (((0x69 < DAT_004a7bcc) && (2 < DAT_00491188)) &&
         ((DAT_00491188 != 9 && ((0x14 < DAT_004a5b80 && (DAT_004a4388 == 0)))))) {
        FUN_0046bf33(&param_1,s_Set_spinnaker__00498bf0);
        uStack_4 = 0x2a;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if ((((0x9b < DAT_004a7bcc) && (DAT_00491188 == 2)) && (0x14 < DAT_004a5b80)) &&
         (DAT_004a4388 == 0)) {
        FUN_0046bf33(&param_1,s_Wing_jib__00498bbc);
        uStack_4 = 0x2b;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (((DAT_004aa62c == 1) && (0x46 < DAT_004a7bcc)) &&
         ((DAT_004a7bcc < 0xb4 - DAT_004a5f14 && (0 < DAT_004a6770)))) {
        FUN_0046bf33(&param_1,s_Head_down_in_the_puffs__00498b88);
        uStack_4 = 0x2c;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
        DAT_004a61e8 = 1;
      }
      if (DAT_004ac964 == 1) {
        if (DAT_004ac92c == 0) {
          (**(code **)(*this + 0x38))(this,0x7f0000);
        }
        FUN_0046bf33(&param_1,s_There_has_been_a_major_wind_shif_00498b48);
        uStack_4 = 0x2d;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
        iVar6 = iVar6 + 0x14;
      }
      if (DAT_0049116c == 1) {
        if (DAT_004ac92c == 0) {
          (**(code **)(*this + 0x38))(this,0x7f);
        }
        FUN_0046bf33(&param_1,s_Simulation_is_much_faster_with_a_00498b10);
        uStack_4 = 0x2e;
        (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&param_1);
      }
      if (DAT_004ac92c == 0) {
        (**(code **)(*this + 0x38))(this,0xff);
      }
      FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_00499100);
      uStack_4 = 0x2f;
      (*pcVar1)(this,0x1e,DAT_004a600c - iVar4,(LPCSTR)param_1,param_1[-2]);
    }
    else {
      FUN_0046bf33(&param_1,s_The_coach_is_not_available_while_00499184);
      iVar6 = *this;
      uStack_4 = 0xf;
      pcVar1 = *(code **)(iVar6 + 100);
      (*pcVar1)(this,0x1e,2,(LPCSTR)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
      FUN_0046bf33(&param_1,s_greater_than_10__However__the_po_00499144);
      uStack_4 = 0x10;
      (*pcVar1)(this,0x1e,0x16,(LPCSTR)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
      if (DAT_004ac92c == 0) {
        (**(code **)(iVar6 + 0x38))(this,0xff);
      }
      FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_00499100);
      uStack_4 = 0x11;
      (*pcVar1)(this,0x1e,DAT_004a600c - iVar4,(LPCSTR)param_1,param_1[-2]);
    }
    goto LAB_0043b8f3;
  }
  FUN_0046bf33(&param_1,s_____Post_Race_Comments_____00498af4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*this + 100);
  (*pcVar1)(this,0x1e,2,(LPCSTR)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  param_1 = (int *)(longlong)(((double)DAT_004a4bd8 * _DAT_00485020) / (double)DAT_004ab9c4);
  pTVar3 = FUN_00413d00(&TStack_10,(int)param_1);
  uStack_4 = 1;
  pTVar3 = FUN_0046c14f(&TStack_14,s_Percent_beating_time_on_lifted_t_00498acc,pTVar3);
  uStack_4._0_1_ = 2;
  (*pcVar1)(this,0x1e,0x2a,pTVar3->data,*(int *)(pTVar3->data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_0046bec5((int *)&TStack_14);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&TStack_10);
  iVar6 = 0x3e;
  if ((int)param_1 < 0x3d) {
LAB_0043b60b:
    if (0x4b < (int)param_1) goto LAB_0043b612;
  }
  else {
    if ((int)param_1 < 0x4c) {
      FUN_0046bf33(&TStack_14,s_Fairly_good_use_of_wind_shifts__00498aac);
      uStack_4 = 3;
      (*pcVar1)(this,0x1e,0x3e,TStack_14.data,*(int *)(TStack_14.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_14);
      iVar6 = 0x52;
      goto LAB_0043b60b;
    }
LAB_0043b612:
    FUN_0046bf33(&TStack_14,s_Excellent_use_of_wind_shifts__00498a8c);
    uStack_4 = 4;
    (*pcVar1)(this,0x1e,iVar6,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_14);
    iVar6 = iVar6 + 0x14;
  }
  if ((0 < DAT_004a888c) && ((int)param_1 < 0x3d)) {
    FUN_0046bf33(&TStack_14,s_Wind_from_the_shore__oscillation_00498a5c);
    uStack_4 = 5;
    (*pcVar1)(this,0x1e,iVar6,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_14);
    iVar6 = iVar6 + 0x14;
  }
  if (((4 < (int)((DAT_004aa838 ^ (int)DAT_004aa838 >> 0x1f) - ((int)DAT_004aa838 >> 0x1f))) &&
      (DAT_004a888c == 0)) && ((int)param_1 < 0x3d)) {
    FUN_0046bf33(&TStack_14,s_Wind_direction_prior_to_the_star_00498a24);
    uStack_4 = 6;
    (*pcVar1)(this,0x1e,iVar6,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_14);
    iVar6 = iVar6 + 0x14;
  }
  if ((10 < DAT_004abc7c) && ((int)param_1 < 0x4c)) {
    FUN_0046bf33(&TStack_14,s_On_average__veering_wind_was_lik_004989fc);
    uStack_4 = 7;
    (*pcVar1)(this,0x1e,iVar6,TStack_14.data,*(int *)(TStack_14.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_14);
    iVar6 = iVar6 + 0x14;
  }
  if ((DAT_004abc7c < -10) && ((int)param_1 < 0x4c)) {
    FUN_0046bf33(&param_1,s_On_average__backing_wind_was_lik_004989d4);
    uStack_4 = 8;
    (*pcVar1)(this,0x1e,iVar6,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = iVar6 + 0x14;
  }
  pTVar3 = FUN_00413d00(&TStack_10,
                        (int)(longlong)
                             (((double)DAT_004a7754 * _DAT_00485020) / (double)DAT_004ab9d4));
  uStack_4 = 9;
  pTVar3 = FUN_0046c14f((TactCString *)&param_1,s_Percent_time_in_bad_air__004989b8,pTVar3);
  uStack_4._0_1_ = 10;
  (*pcVar1)(this,0x1e,iVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
  uStack_4 = CONCAT31(uStack_4._1_3_,9);
  FUN_0046bec5((int *)&param_1);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&TStack_10);
  iVar2 = iVar6 + 0x14;
  if (DAT_004ac99c == 1) {
    FUN_0046bf33(&param_1,s_While_beating__you_overstood_the_00498990);
    uStack_4 = 0xb;
    (*pcVar1)(this,0x1e,iVar2,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar2 = iVar6 + 0x28;
  }
  if (DAT_004ac9a0 == 1) {
    FUN_0046bf33(&param_1,s_While_tacking_downwind__you_over_00498960);
    uStack_4 = 0xc;
    (*pcVar1)(this,0x1e,iVar2,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar2 = iVar2 + 0x14;
  }
  if ((DAT_004ac960 < 1) && (DAT_004ac93c == 0)) {
    FUN_0046bf33(&param_1,s_You_should_wait_until_the_last_b_00498924);
    uStack_4 = 0xd;
    (*pcVar1)(this,0x1e,iVar2 + 0x14,(LPCSTR)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*this + 0x38))(this,0xff);
  }
  FUN_0046bf33(&param_1,s_Press_Spacebar_or_Click_Mouse_to_00499100);
  uStack_4 = 0xe;
  (*pcVar1)(this,0x1e,DAT_004a600c - iVar4,(LPCSTR)param_1,param_1[-2]);
LAB_0043b8f3:
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

