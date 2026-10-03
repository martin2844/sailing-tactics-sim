
void __cdecl FUN_00406c90(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  TactCString *pTVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uStack_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d640;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = param_2 + param_4;
  FUN_0046bf33(&param_2,s___Motivation_Factors_for_Tacking_0049187c);
  local_4 = 0;
  iVar1 = param_3 + 5;
  pcVar2 = *(code **)(*param_1 + 100);
  (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
  local_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  iVar4 = iVar4 + param_4 / 2;
  if (0 < DAT_004aa668) {
    iVar4 = iVar4 + param_4;
    FUN_0046bf33(&param_2,s_Tacking_now__0049186c);
    local_4 = 1;
    (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
    local_4 = 0xffffffff;
    FUN_0046bec5(&param_2);
  }
  if (DAT_004a4eb0 + 5 < DAT_004a7bd0) {
    FUN_0046bf33(&param_2,s_Not_beating_or_running__00491854);
    local_4 = 2;
    (*pcVar2)(param_1,iVar1,param_4 + iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
  }
  else {
    if ((0 < DAT_004a4bf0) && (iVar4 = iVar4 + param_4, DAT_004a4bf0 == 1)) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Just_tacked__00491838);
      local_4 = 3;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 2) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Prestart_maneuvering_00491814);
      local_4 = 4;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 3) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Ducking_other_boat__004917f4);
      local_4 = 5;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 4) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Other_boat_too_close_004917d0);
      local_4 = 6;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 5) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Near_port_tack_layli_004917ac);
      local_4 = 7;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 6) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Very_near_layline__0049178c);
      local_4 = 8;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 7) {
      FUN_0046bf33(&param_2,s_Don_t_tack__Push_Red_to_layline__00491768);
      local_4 = 9;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 8) {
      FUN_0046bf33(&param_2,s_Don_t_tack_into_bad_air__0049174c);
      local_4 = 10;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (DAT_004a4bf0 == 9) {
      FUN_0046bf33(&param_2,s_Go_just_beyond_layline__00491734);
      local_4 = 0xb;
      (*pcVar2)(param_1,iVar1,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_2);
    }
    if (0 < DAT_004a4bf0) goto LAB_00407cb1;
    if (DAT_004a4bf4 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4bf4);
      local_4 = 0xc;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Near_a_layline__00491720,pTVar3);
      local_4._0_1_ = 0xd;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0xc);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c64 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c64);
      local_4 = 0xe;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Very_near_layline__0049170c,pTVar3);
      local_4._0_1_ = 0xf;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0xe);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4bf8 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4bf8);
      local_4 = 0x10;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Fairly_close_to_port_tack_laylin_004916e8,
                            pTVar3);
      local_4._0_1_ = 0x11;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x10);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4bfc != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4bfc);
      local_4 = 0x12;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Nearing_layline__004916d4,pTVar3);
      local_4._0_1_ = 0x13;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x12);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c00 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c00);
      local_4 = 0x14;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Headed_rel_to_ave_wind__004916b8,pTVar3);
      local_4._0_1_ = 0x15;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x14);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c04 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c04);
      local_4 = 0x16;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Lifted_rel_to_ave_wind__0049169c,pTVar3);
      local_4._0_1_ = 0x17;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x16);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c08 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c08);
      local_4 = 0x18;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Stronger_wind__00491688,pTVar3);
      local_4._0_1_ = 0x19;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x18);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c0c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c0c);
      local_4 = 0x1a;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Stronger_wind__00491688,pTVar3);
      local_4._0_1_ = 0x1b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1a);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c10 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c10);
      local_4 = 0x1c;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Stronger_wind__00491688,pTVar3);
      local_4._0_1_ = 0x1d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1c);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c14 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c14);
      local_4 = 0x1e;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Stronger_wind__00491688,pTVar3);
      local_4._0_1_ = 0x1f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1e);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c18 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c18);
      local_4 = 0x20;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Better_tide__00491678,pTVar3);
      local_4._0_1_ = 0x21;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x20);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c1c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c1c);
      local_4 = 0x22;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Better_tide__00491678,pTVar3);
      local_4._0_1_ = 0x23;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x22);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c20 != 0) {
      iVar4 = iVar4 + param_4;
      if (DAT_004abc7c < 1) {
        pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c20);
        local_4 = 0x26;
        pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Backing_expected__00491650,pTVar3);
        local_4._0_1_ = 0x27;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x26);
        FUN_0046bec5(&param_2);
      }
      else {
        pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c20);
        local_4 = 0x24;
        pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Veering_expected__00491664,pTVar3);
        local_4._0_1_ = 0x25;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x24);
        FUN_0046bec5(&param_2);
      }
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c24 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c24);
      local_4 = 0x28;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Increasing_adverse_current__00491630,pTVar3);
      local_4._0_1_ = 0x29;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x28);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c28 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c28);
      local_4 = 0x2a;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Decreasing_adverse_current__00491610,pTVar3);
      local_4._0_1_ = 0x2b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2a);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c2c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c2c);
      local_4 = 0x2c;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Increasing_favorable_current__004915f0,pTVar3)
      ;
      local_4._0_1_ = 0x2d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2c);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c30 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c30);
      local_4 = 0x2e;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Decreasing_favorable_current__004915d0,pTVar3)
      ;
      local_4._0_1_ = 0x2f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2e);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c34 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c34);
      local_4 = 0x30;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Tacked_recently__004915bc,pTVar3);
      local_4._0_1_ = 0x31;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x30);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c38 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c38);
      local_4 = 0x32;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Tack_for_clear_air__004915a4,pTVar3);
      local_4._0_1_ = 0x33;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x32);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c3c != 0) {
      iVar4 = iVar4 + param_4;
      if (DAT_004a4c3c < 1) {
        pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c3c);
        local_4 = 0x36;
        pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Lifted_and_not_ahead__00491574,pTVar3);
        local_4._0_1_ = 0x37;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x36);
        FUN_0046bec5(&param_2);
      }
      else {
        pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c3c);
        local_4 = 0x34;
        pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Headed_and_not_ahead__0049158c,pTVar3);
        local_4._0_1_ = 0x35;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x34);
        FUN_0046bec5(&param_2);
      }
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c50 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c50);
      local_4 = 0x38;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Use_tight_Cover__00491560,pTVar3);
      local_4._0_1_ = 0x39;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x38);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c54 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c54);
      local_4 = 0x3a;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Use_tight_Cover__00491560,pTVar3);
      local_4._0_1_ = 0x3b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3a);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c48 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c48);
      local_4 = 0x3c;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Tack_for_loose_Cover__00491548,pTVar3);
      local_4._0_1_ = 0x3d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3c);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c4c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c4c);
      local_4 = 0x3e;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Get_into_loose_cover_position__00491524,pTVar3
                           );
      local_4._0_1_ = 0x3f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3e);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c58 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c58);
      local_4 = 0x40;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Use_loose_Cover__00491510,pTVar3);
      local_4._0_1_ = 0x41;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x40);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c5c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c5c);
      local_4 = 0x42;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Tack_to_cross__004914fc,pTVar3);
      local_4._0_1_ = 0x43;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x42);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c60 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c60);
      local_4 = 0x44;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Split_tacks_if_behind__004914e0,pTVar3);
      local_4._0_1_ = 0x45;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x44);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c68 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c68);
      local_4 = 0x46;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Not_well_ahead__Delay_crossing__004914bc,
                            pTVar3);
      local_4._0_1_ = 0x47;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x46);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    if (DAT_004a4c6c != 0) {
      pTVar3 = FUN_00413d00((TactCString *)&param_3,DAT_004a4c6c);
      local_4 = 0x48;
      pTVar3 = FUN_0046c14f((TactCString *)&param_2,s_Avoid_starboard_tack_boat__004914a0,pTVar3);
      local_4._0_1_ = 0x49;
      (*pcVar2)(param_1,iVar1,param_4 + iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x48);
      FUN_0046bec5(&param_2);
      local_4 = 0xffffffff;
      FUN_0046bec5(&param_3);
    }
    pTVar3 = FUN_00413d00((TactCString *)&param_2,DAT_004a4c8c);
    local_4 = 0x4a;
    pTVar3 = FUN_0046c14f((TactCString *)&param_4,s_Total_motivation_points__004912d4,pTVar3);
    local_4._0_1_ = 0x4b;
    (*pcVar2)(param_1,iVar1,(DAT_004a72d0 * 6) / 7,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x4a);
    FUN_0046bec5(&param_4);
  }
  local_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
LAB_00407cb1:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

