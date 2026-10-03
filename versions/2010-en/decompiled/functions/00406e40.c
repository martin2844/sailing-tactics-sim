
void __cdecl FUN_00406e40(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  Tact2010CString *pTVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 local_4;
  
  uStack_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c1cf0;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = param_2 + param_4;
  FUN_004b0613((Tact2010CString *)&param_2,s___Motivation_Factors_for_Tacking_004da868);
  local_4 = 0;
  iVar1 = param_3 + 5;
  pcVar2 = *(code **)(*param_1 + 100);
  (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
  local_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
  iVar4 = iVar4 + param_4 / 2;
  if (0 < DAT_00522e70) {
    iVar4 = iVar4 + param_4;
    FUN_004b0613((Tact2010CString *)&param_2,s_Tacking_now__004da858);
    local_4 = 1;
    (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    local_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (DAT_004f7200 + 5 < DAT_004fecd0) {
    FUN_004b0613((Tact2010CString *)&param_2,s_Not_beating_or_running__004da840);
    local_4 = 2;
    (*pcVar2)(param_1,iVar1,param_4 + iVar4,(char *)param_2,*(int *)(param_2 + -8));
  }
  else {
    if ((0 < DAT_004f6d68) && (iVar4 = iVar4 + param_4, DAT_004f6d68 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Just_tacked__004da824);
      local_4 = 3;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 2) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Prestart_maneuvering_004da800);
      local_4 = 4;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 3) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Ducking_other_boat__004da7e0);
      local_4 = 5;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 4) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Other_boat_too_close_004da7bc);
      local_4 = 6;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 5) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Near_port_tack_layli_004da798);
      local_4 = 7;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 6) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Very_near_layline__004da778);
      local_4 = 8;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 7) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack__Push_Red_to_layline__004da754);
      local_4 = 9;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 8) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Don_t_tack_into_bad_air__004da738);
      local_4 = 10;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_004f6d68 == 9) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Go_just_beyond_layline__004da720);
      local_4 = 0xb;
      (*pcVar2)(param_1,iVar1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (0 < DAT_004f6d68) goto LAB_00407e61;
    if (DAT_004f6d6c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d6c);
      local_4 = 0xc;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Near_a_layline__004da70c,pTVar3);
      local_4._0_1_ = 0xd;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0xc);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6ddc != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6ddc);
      local_4 = 0xe;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Very_near_layline__004da6f8,pTVar3);
      local_4._0_1_ = 0xf;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0xe);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d70 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d70);
      local_4 = 0x10;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Fairly_close_to_port_tack_laylin_004da6d4,
                            pTVar3);
      local_4._0_1_ = 0x11;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x10);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d74 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d74);
      local_4 = 0x12;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Nearing_layline__004da6c0,pTVar3);
      local_4._0_1_ = 0x13;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x12);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d78 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d78);
      local_4 = 0x14;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Headed_rel_to_ave_wind__004da6a4,pTVar3);
      local_4._0_1_ = 0x15;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x14);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d7c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d7c);
      local_4 = 0x16;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Lifted_rel_to_ave_wind__004da688,pTVar3);
      local_4._0_1_ = 0x17;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x16);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d80 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d80);
      local_4 = 0x18;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Stronger_wind__004da674,pTVar3);
      local_4._0_1_ = 0x19;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x18);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d84 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d84);
      local_4 = 0x1a;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Stronger_wind__004da674,pTVar3);
      local_4._0_1_ = 0x1b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1a);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d88 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d88);
      local_4 = 0x1c;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Stronger_wind__004da674,pTVar3);
      local_4._0_1_ = 0x1d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1c);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d8c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d8c);
      local_4 = 0x1e;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Stronger_wind__004da674,pTVar3);
      local_4._0_1_ = 0x1f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x1e);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d90 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d90);
      local_4 = 0x20;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Better_tide__004da664,pTVar3);
      local_4._0_1_ = 0x21;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x20);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d94 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d94);
      local_4 = 0x22;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Better_tide__004da664,pTVar3);
      local_4._0_1_ = 0x23;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x22);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d98 != 0) {
      iVar4 = iVar4 + param_4;
      if (DAT_00535204 < 1) {
        pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d98);
        local_4 = 0x26;
        pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Backing_expected__004da63c,pTVar3);
        local_4._0_1_ = 0x27;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x26);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      else {
        pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d98);
        local_4 = 0x24;
        pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Veering_expected__004da650,pTVar3);
        local_4._0_1_ = 0x25;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x24);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6d9c != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6d9c);
      local_4 = 0x28;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Increasing_adverse_current__004da61c,
                            pTVar3);
      local_4._0_1_ = 0x29;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x28);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6da0 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6da0);
      local_4 = 0x2a;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Decreasing_adverse_current__004da5fc,
                            pTVar3);
      local_4._0_1_ = 0x2b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2a);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6da4 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6da4);
      local_4 = 0x2c;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Increasing_favorable_current__004da5dc,
                            pTVar3);
      local_4._0_1_ = 0x2d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2c);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6da8 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6da8);
      local_4 = 0x2e;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Decreasing_favorable_current__004da5bc,
                            pTVar3);
      local_4._0_1_ = 0x2f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x2e);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dac != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dac);
      local_4 = 0x30;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Tacked_recently__004da5a8,pTVar3);
      local_4._0_1_ = 0x31;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x30);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6db0 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6db0);
      local_4 = 0x32;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Tack_for_clear_air__004da590,pTVar3);
      local_4._0_1_ = 0x33;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x32);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6db4 != 0) {
      iVar4 = iVar4 + param_4;
      if (DAT_004f6db4 < 1) {
        pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6db4);
        local_4 = 0x36;
        pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Lifted_and_not_ahead__004da560,pTVar3);
        local_4._0_1_ = 0x37;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x36);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      else {
        pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6db4);
        local_4 = 0x34;
        pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Headed_and_not_ahead__004da578,pTVar3);
        local_4._0_1_ = 0x35;
        (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
        local_4 = CONCAT31(local_4._1_3_,0x34);
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dc8 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dc8);
      local_4 = 0x38;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Use_tight_Cover__004da54c,pTVar3);
      local_4._0_1_ = 0x39;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x38);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dcc != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dcc);
      local_4 = 0x3a;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Use_tight_Cover__004da54c,pTVar3);
      local_4._0_1_ = 0x3b;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3a);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dc0 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dc0);
      local_4 = 0x3c;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Tack_for_loose_Cover__004da534,pTVar3);
      local_4._0_1_ = 0x3d;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3c);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dc4 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dc4);
      local_4 = 0x3e;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Get_into_loose_cover_position__004da510,
                            pTVar3);
      local_4._0_1_ = 0x3f;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x3e);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dd0 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dd0);
      local_4 = 0x40;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Use_loose_Cover__004da4fc,pTVar3);
      local_4._0_1_ = 0x41;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x40);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dd4 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dd4);
      local_4 = 0x42;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Tack_to_cross__004da4e8,pTVar3);
      local_4._0_1_ = 0x43;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x42);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6dd8 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6dd8);
      local_4 = 0x44;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Split_tacks_if_behind__004da4cc,pTVar3);
      local_4._0_1_ = 0x45;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x44);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6de0 != 0) {
      iVar4 = iVar4 + param_4;
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6de0);
      local_4 = 0x46;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Not_well_ahead__Delay_crossing__004da4a8,
                            pTVar3);
      local_4._0_1_ = 0x47;
      (*pcVar2)(param_1,iVar1,iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x46);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    if (DAT_004f6de4 != 0) {
      pTVar3 = FUN_0041bc70((Tact2010CString *)&param_3,DAT_004f6de4);
      local_4 = 0x48;
      pTVar3 = FUN_004b082f((Tact2010CString *)&param_2,s_Avoid_starboard_tack_boat__004da48c,pTVar3
                           );
      local_4._0_1_ = 0x49;
      (*pcVar2)(param_1,iVar1,param_4 + iVar4,pTVar3->data,*(int *)(pTVar3->data + -8));
      local_4 = CONCAT31(local_4._1_3_,0x48);
      FUN_004b05a5((Tact2010CString *)&param_2);
      local_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
    pTVar3 = FUN_0041bc70((Tact2010CString *)&param_2,DAT_004f6e04);
    local_4 = 0x4a;
    pTVar3 = FUN_004b082f((Tact2010CString *)&param_4,s_Total_motivation_points__004da2c0,pTVar3);
    local_4._0_1_ = 0x4b;
    (*pcVar2)(param_1,iVar1,(DAT_004fe2a8 * 6) / 7,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4 = CONCAT31(local_4._1_3_,0x4a);
    FUN_004b05a5((Tact2010CString *)&param_4);
  }
  local_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
LAB_00407e61:
  *unaff_FS_OFFSET = uStack_c;
  return;
}

