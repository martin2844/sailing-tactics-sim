
void __cdecl FUN_0041c940(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  TactCString *pTVar3;
  TactCString *pTVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  TactCString TVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  TactCString TStack_d8;
  int *piStack_d4;
  int *piStack_d0;
  TactCString local_cc;
  int local_c8;
  TactCString TStack_c4;
  TactCString TStack_c0;
  TactCString TStack_bc;
  int iStack_b8;
  TactCString TStack_b4;
  TactCString TStack_b0;
  TactCString TStack_ac;
  TactCString TStack_a8;
  int iStack_a4;
  LPCSTR pCStack_a0;
  TactCString TStack_9c;
  TactCString TStack_98;
  LPCSTR pCStack_94;
  TactCString TStack_90;
  TactCString TStack_8c;
  int aiStack_88 [31];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e3c2;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TVar8.data = (char *)(((699 < DAT_004a763c) - 1 & 0xfffffff1) + 0x32);
  local_c8 = 0xf;
  if (699 < DAT_004a763c) {
    local_c8 = 0x11;
  }
  if (900 < DAT_004a763c) {
    local_c8 = 0x14;
    TVar8.data = (char *)0x41;
  }
  iVar9 = *param_1;
  pcVar1 = *(code **)(iVar9 + 0x2c);
  local_cc.data = TVar8.data;
  (*pcVar1)(param_1,0);
  (*pcVar1)(param_1,6);
  Rectangle((HDC)param_1[1],0,0,DAT_004a763c,DAT_004a72d0);
  if ((DAT_00491164 < 1) || (DAT_004ac93c < 1)) {
    DAT_0049116c = DAT_004aa6f8;
    DAT_00491170 = DAT_004ac858;
    iStack_b8 = 0;
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar9 + 0x38))(param_1,0x7f0000);
      (**(code **)(iVar9 + 0x34))(param_1,0xffffff);
    }
    FUN_0046bf33(&piStack_d0,s_____Results_____00493198);
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0;
    (*pcVar1)(param_1,DAT_004a763c / 5,1,(LPCSTR)piStack_d0,piStack_d0[-2]);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&piStack_d0);
    pTVar3 = FUN_00413d00(&TStack_c4,DAT_00491190);
    uStack_4 = 1;
    pTVar3 = FUN_0046c14f(&TStack_d8,s_Difficulty_level__00493184,pTVar3);
    uStack_4._0_1_ = 2;
    (*pcVar1)(param_1,(DAT_004a763c * 3) / 5,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    FUN_0046bec5((int *)&TStack_d8);
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_c4);
    if ((DAT_004ac960 == 1) && (piStack_d4 = (int *)0x1, 0 < DAT_00491140)) {
      piStack_d0 = &DAT_004a764c;
      do {
        piVar5 = piStack_d0;
        if (DAT_00491140 == 2) {
          pTVar3 = FUN_00413d00(&TStack_bc,*piStack_d0);
          uStack_4 = 3;
          pTVar4 = FUN_00413d00(&TStack_c0,(int)piStack_d4);
          uStack_4._0_1_ = 4;
          pTVar4 = FUN_0046c14f(&TStack_b4,s_Boat_0049317c,pTVar4);
          uStack_4._0_1_ = 5;
          pTVar4 = FUN_0046c0db(&TStack_c4,pTVar4,s_finish___00493170);
          uStack_4._0_1_ = 6;
          pTVar3 = FUN_0046c075(&TStack_d8,pTVar4,pTVar3);
          uStack_4._0_1_ = 7;
          (*pcVar1)(param_1,10,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4._0_1_ = 6;
          FUN_0046bec5((int *)&TStack_d8);
          uStack_4._0_1_ = 5;
          FUN_0046bec5((int *)&TStack_c4);
          uStack_4._0_1_ = 4;
          FUN_0046bec5((int *)&TStack_b4);
          uStack_4 = CONCAT31(uStack_4._1_3_,3);
          FUN_0046bec5((int *)&TStack_c0);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_bc);
          TVar8.data = TVar8.data + local_c8;
          piVar5 = piStack_d0;
        }
        else {
          pTVar3 = FUN_00413d00(&TStack_ac,*piStack_d0);
          uStack_4 = 8;
          pTVar3 = FUN_0046c14f(&TStack_a8,s_Your_finish_position__00493158,pTVar3);
          uStack_4._0_1_ = 9;
          (*pcVar1)(param_1,10,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4 = CONCAT31(uStack_4._1_3_,8);
          FUN_0046bec5((int *)&TStack_a8);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_ac);
        }
        piStack_d4 = (int *)((int)piStack_d4 + 1);
        piStack_d0 = piVar5 + 1;
      } while ((int)piStack_d4 <= DAT_00491140);
    }
    TStack_bc.data = (char *)(DAT_004a763c / 10 + -10);
    TStack_b4.data = (char *)((DAT_004a763c * 2) / 10 + -10);
    piStack_d0 = (int *)((DAT_004a763c * 3) / 10 + -10);
    TStack_c0.data = (char *)((DAT_004a763c << 2) / 10 + -10);
    if (DAT_004ac960 == 0) {
      if (0 < (int)DAT_0049118c) {
        TStack_c4.data = (char *)&DAT_004a6db4;
        piVar5 = &DAT_004a6bc4;
        iVar9 = 0;
        piStack_d4 = (int *)(&DAT_004a6bc0 + DAT_004ac944 * 4);
        TStack_d8.data = DAT_0049118c;
        do {
          iVar6 = *(int *)((int)&DAT_004a764c + iVar9) * 0x65;
          *piStack_d4 = iVar6;
          if (iVar6 == 0x65) {
            *piStack_d4 = 100;
          }
          iVar6 = DAT_004ac944;
          if ((*piVar5 == 0) && (1 < DAT_004ac944)) {
            *piVar5 = 0xc1c;
          }
          if ((piVar5[1] == 0) && (2 < iVar6)) {
            piVar5[1] = 0xc1c;
          }
          if ((piVar5[2] == 0) && (iVar6 == 3)) {
            *piVar5 = 0xc1c;
          }
          iVar6 = piVar5[2] + piVar5[1] + *piVar5;
          *(int *)((int)aiStack_88 + iVar9 + 4) = iVar6;
          piVar5 = piVar5 + 4;
          *(int *)TStack_c4.data = iVar6;
          piStack_d4 = piStack_d4 + 4;
          iVar9 = iVar9 + 4;
          TStack_c4.data = TStack_c4.data + 4;
          TStack_d8.data = TStack_d8.data + -1;
        } while (TStack_d8.data != (LPCSTR)0x0);
      }
      FUN_0042cca0(1);
      FUN_0046bf33(&TStack_d8,s_Place_004930ac);
      iVar9 = (int)TVar8.data - local_c8;
      uStack_4 = 10;
      (*pcVar1)(param_1,5,iVar9,TStack_d8.data,*(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      FUN_0046bf33(&TStack_d8,s_Race_1_004930a4);
      uStack_4 = 0xb;
      (*pcVar1)(param_1,(int)(TStack_bc.data + DAT_004a763c / 0x1e),iVar9,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      FUN_0046bf33(&TStack_d8,s_Race_2_0049309c);
      uStack_4 = 0xc;
      (*pcVar1)(param_1,(int)(TStack_b4.data + DAT_004a763c / 0x32),iVar9,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      FUN_0046bf33(&TStack_d8,s_Race_3_00493150);
      uStack_4 = 0xd;
      (*pcVar1)(param_1,(int)piStack_d0,iVar9,TStack_d8.data,*(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      FUN_0046bf33(&TStack_d8,s_Total_points_0049308c);
      uStack_4 = 0xe;
      (*pcVar1)(param_1,(int)TStack_c0.data - DAT_004a763c / 0x32,iVar9,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      piStack_d4 = (int *)(DAT_004a763c / 2 + -10);
      if (0xf < (int)DAT_0049118c) {
        FUN_0046bf33(&TStack_d8,s_Place_004930ac);
        uStack_4 = 0xf;
        (*pcVar1)(param_1,(int)piStack_d4 + 5,iVar9,TStack_d8.data,*(int *)(TStack_d8.data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_d8);
        FUN_0046bf33(&TStack_d8,s_Race_1_004930a4);
        uStack_4 = 0x10;
        (*pcVar1)(param_1,(int)(TStack_bc.data + DAT_004a763c / 0x1e + (int)piStack_d4),iVar9,
                  TStack_d8.data,*(int *)(TStack_d8.data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_d8);
        FUN_0046bf33(&TStack_d8,s_Race_2_0049309c);
        uStack_4 = 0x11;
        (*pcVar1)(param_1,(int)(TStack_b4.data + DAT_004a763c / 0x32 + (int)piStack_d4),iVar9,
                  TStack_d8.data,*(int *)(TStack_d8.data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_d8);
        FUN_0046bf33(&TStack_d8,s_Race_3_00493150);
        uStack_4 = 0x12;
        (*pcVar1)(param_1,(int)piStack_d4 + (int)piStack_d0,iVar9,TStack_d8.data,
                  *(int *)(TStack_d8.data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_d8);
        FUN_0046bf33(&TStack_d8,s_Total_points_0049308c);
        uStack_4 = 0x13;
        (*pcVar1)(param_1,(int)(TStack_c0.data + ((int)piStack_d4 - DAT_004a763c / 0x32)),iVar9,
                  TStack_d8.data,*(int *)(TStack_d8.data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_d8);
      }
      TStack_d8.data = (char *)(DAT_004a763c / 0x12);
      piStack_d4 = (int *)0x1;
      if (0 < (int)DAT_0049118c) {
        pCStack_94 = TStack_d8.data + (int)TStack_bc.data;
        pCStack_a0 = TStack_d8.data + (int)TStack_c0.data;
        do {
          iVar9 = *(int *)(&DAT_004a4438 + (int)piStack_d4 * 4);
          FUN_00416990(param_1,iVar9);
          iStack_a4 = iVar9 * 4;
          *(int **)(&DAT_004ac0c0 + iStack_a4) = piStack_d4;
          TStack_ac.data = (char *)FUN_00413d00(&TStack_90,iVar9);
          uStack_4 = 0x14;
          pTVar3 = FUN_00413d00(&TStack_bc,(int)piStack_d4);
          uStack_4._0_1_ = 0x15;
          pTVar3 = FUN_0046c0db(&TStack_c0,pTVar3,s___boat_00493080);
          uStack_4._0_1_ = 0x16;
          pTVar3 = FUN_0046c075(&TStack_c4,pTVar3,(TactCString *)TStack_ac.data);
          uStack_4._0_1_ = 0x17;
          pTVar3 = FUN_0046c0db(&TStack_a8,pTVar3,&DAT_00491d20);
          uStack_4._0_1_ = 0x18;
          (*pcVar1)(param_1,iStack_b8 + 5,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4._0_1_ = 0x17;
          FUN_0046bec5((int *)&TStack_a8);
          uStack_4._0_1_ = 0x16;
          FUN_0046bec5((int *)&TStack_c4);
          uStack_4._0_1_ = 0x15;
          FUN_0046bec5((int *)&TStack_c0);
          uStack_4 = CONCAT31(uStack_4._1_3_,0x14);
          FUN_0046bec5((int *)&TStack_bc);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_90);
          iVar9 = iVar9 * 0x10;
          pTVar3 = FUN_00413d00(&TStack_98,*(int *)(&DAT_004a6bb4 + iVar9) / 100);
          uStack_4 = 0x19;
          (*pcVar1)(param_1,(int)(pCStack_94 + iStack_b8),(int)TVar8.data,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_98);
          if (0 < *(int *)(&DAT_004a6bb8 + iVar9)) {
            pTVar3 = FUN_00413d00(&TStack_9c,*(int *)(&DAT_004a6bb8 + iVar9) / 100);
            uStack_4 = 0x1a;
            (*pcVar1)(param_1,(int)(TStack_d8.data + (int)TStack_b4.data + iStack_b8),
                      (int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
            uStack_4 = 0xffffffff;
            FUN_0046bec5((int *)&TStack_9c);
          }
          if (0 < *(int *)(&DAT_004a6bbc + iVar9)) {
            pTVar3 = FUN_00413d00(&TStack_8c,*(int *)(&DAT_004a6bbc + iVar9) / 100);
            uStack_4 = 0x1b;
            (*pcVar1)(param_1,(int)(TStack_d8.data + iStack_b8 + (int)piStack_d0),(int)TVar8.data,
                      pTVar3->data,*(int *)(pTVar3->data + -8));
            uStack_4 = 0xffffffff;
            FUN_0046bec5((int *)&TStack_8c);
          }
          pTVar3 = FUN_00413d00(&TStack_b0,*(int *)((int)aiStack_88 + iStack_a4) / 100);
          uStack_4 = 0x1c;
          (*pcVar1)(param_1,(int)(pCStack_a0 + iStack_b8),(int)TVar8.data,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_b0);
          TVar8.data = TVar8.data + local_c8;
          if (piStack_d4 == (int *)0xf) {
            iStack_b8 = DAT_004a763c / 2 + -10;
            TVar8.data = local_cc.data;
          }
          piStack_d4 = (int *)((int)piStack_d4 + 1);
        } while ((int)piStack_d4 <= (int)DAT_0049118c);
      }
      if (((DAT_004ac960 == 0) && (DAT_004ac944 == 3)) && (DAT_00491140 == 1)) {
        (**(code **)(*param_1 + 0x38))(param_1,0);
        TStack_b0.data = (char *)(((int)(DAT_0049118c + (1 - DAT_004ac0c4)) * DAT_00491190) / 0x1e);
        local_cc.data = (char *)(local_c8 / 2 + local_c8 * -9);
        pcVar7 = local_cc.data + (DAT_004a72d0 * 6) / 7;
        if (0 < (int)TStack_b0.data) {
          pTVar3 = FUN_00413d00(&TStack_b0,(int)TStack_b0.data);
          uStack_4 = 0x1d;
          pTVar3 = FUN_0046c14f(&local_cc,s_You_have_achieved_skill_level__00493130,pTVar3);
          uStack_4._0_1_ = 0x1e;
          (*pcVar1)(param_1,10,(int)pcVar7,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4 = CONCAT31(uStack_4._1_3_,0x1d);
          FUN_0046bec5((int *)&local_cc);
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_b0);
        }
      }
    }
    iVar9 = local_c8;
    local_cc.data = (char *)(local_c8 / 2 + local_c8 * -8);
    pcVar7 = local_cc.data + (DAT_004a72d0 * 6) / 7 + 10;
    if (DAT_004ac92c == 0) {
      (**(code **)(*param_1 + 0x38))(param_1,0xff);
    }
    FUN_0046bf33(&TStack_d8,s_For_another_race_press_N__To_qui_004930e4);
    uStack_4 = 0x1f;
    (*pcVar1)(param_1,10,(int)pcVar7,TStack_d8.data,*(int *)(TStack_d8.data + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&TStack_d8);
    pcVar7 = pcVar7 + iVar9 * 2;
    if (DAT_004ac9bc == 1) {
      if (DAT_004a6dac != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a6dac);
      }
      Rectangle((HDC)param_1[1],0,(int)(pcVar7 + -4),DAT_004a763c,DAT_004a72d0);
      iVar9 = *param_1;
      local_cc.data = *(char **)(iVar9 + 0x34);
      (*(code *)local_cc.data)(param_1,0x7f7f00);
      pcVar2 = *(code **)(iVar9 + 0x38);
      (*pcVar2)(param_1,0);
      FUN_0046bf33(&TStack_d8,s_Mainsail_colors__0049306c);
      uStack_4 = 0x20;
      (*pcVar1)(param_1,10,(int)pcVar7,TStack_d8.data,*(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      pcVar7 = pcVar7 + local_c8;
      (*pcVar2)(param_1,0xffff);
      FUN_0046bf33(&TStack_d8,s_Boat_1__yellow_0049305c);
      uStack_4 = 0x21;
      (*pcVar1)(param_1,10,(int)pcVar7,TStack_d8.data,*(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      (*pcVar2)(param_1,0xff00);
      FUN_0046bf33(&TStack_d8,s_Boat_2__green_0049304c);
      uStack_4 = 0x22;
      (*pcVar1)(param_1,DAT_004a763c / 5 + 10,(int)pcVar7,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      (*pcVar2)(param_1,0xffffff);
      FUN_0046bf33(&TStack_d8,s_Boats_3_10___white_00493038);
      uStack_4 = 0x23;
      (*pcVar1)(param_1,(DAT_004a763c * 2) / 5 + 10,(int)pcVar7,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      (*pcVar2)(param_1,0x7f7f7f);
      FUN_0046bf33(&TStack_d8,s_Boats_11_20__gray_00493024);
      uStack_4 = 0x24;
      (*pcVar1)(param_1,(DAT_004a763c * 3) / 5 + 10,(int)pcVar7,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      (*pcVar2)(param_1,0xff0000);
      FUN_0046bf33(&TStack_d8,s_Boats_21_30__blue_00493010);
      uStack_4 = 0x25;
      (*pcVar1)(param_1,(DAT_004a763c * 4) / 5 + 10,(int)pcVar7,TStack_d8.data,
                *(int *)(TStack_d8.data + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&TStack_d8);
      (*(code *)local_cc.data)(param_1,0xffffff);
    }
  }
  else {
    FUN_00410090((undefined *)param_1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

