
void __cdecl FUN_00428b70(int *param_1)

{
  code *pcVar1;
  int iVar2;
  Tact2010CString *pTVar3;
  Tact2010CString *pTVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  Tact2010CString TVar8;
  Tact2010CString TVar9;
  undefined4 *unaff_FS_OFFSET;
  Tact2010CString TStack_e0;
  int *piStack_dc;
  Tact2010CString TStack_d8;
  Tact2010CString TStack_d4;
  Tact2010CString TStack_d0;
  Tact2010CString TStack_cc;
  int local_c8;
  int iStack_c4;
  Tact2010CString TStack_c0;
  Tact2010CString local_bc;
  Tact2010CString TStack_b8;
  Tact2010CString TStack_b4;
  Tact2010CString TStack_b0;
  Tact2010CString TStack_ac;
  Tact2010CString TStack_a8;
  char *pcStack_a4;
  Tact2010CString TStack_a0;
  char *pcStack_9c;
  int aiStack_98 [35];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c306b;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TVar8.data = (char *)(((699 < DAT_004fe624) - 1 & 0xfffffff1) + 0x32);
  local_c8 = 0xf;
  if (699 < DAT_004fe624) {
    local_c8 = 0x11;
  }
  if (900 < DAT_004fe624) {
    local_c8 = 0x14;
    TVar8.data = (char *)0x41;
  }
  iVar2 = *param_1;
  pcVar1 = *(code **)(iVar2 + 0x2c);
  local_bc.data = TVar8.data;
  (*pcVar1)(param_1,0);
  (*pcVar1)(param_1,6);
  Rectangle((HDC)param_1[1],0,0,DAT_004fe624,DAT_004fe2a8);
  if ((DAT_004da16c < 1) || (DAT_005363f4 < 1)) {
    DAT_004da174 = DAT_00522f20;
    DAT_004da178 = DAT_005362f0;
    iStack_c4 = 0;
    if (DAT_005363e4 == 0) {
      (**(code **)(iVar2 + 0x38))(param_1,0x7f0000);
      (**(code **)(iVar2 + 0x34))(param_1,0xffffff);
    }
    iVar2 = 1;
    if (0 < (int)DAT_004da194) {
      piVar5 = &DAT_004fe63c;
      do {
        if (*piVar5 == 1) {
          DAT_004f8dbc = iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 <= (int)DAT_004da194);
    }
    FUN_004b0613(&TStack_d8,s_____Results_____004dd258);
    uStack_4 = 0;
    pcVar1 = *(code **)(*param_1 + 100);
    (*pcVar1)(param_1,DAT_004fe624 / 5,1,TStack_d8.data,*(int *)(TStack_d8.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_d8);
    pTVar3 = FUN_0041bc70(&TStack_d4,DAT_004da198);
    uStack_4 = 1;
    pTVar3 = FUN_004b082f(&TStack_e0,s_Difficulty_level__004dd244,pTVar3);
    uStack_4._0_1_ = 2;
    (*pcVar1)(param_1,(DAT_004fe624 * 3) / 5,1,pTVar3->data,*(int *)(pTVar3->data + -8));
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    FUN_004b05a5(&TStack_e0);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_d4);
    if ((DAT_00536424 == 1) && (piStack_dc = (int *)0x1, 0 < DAT_004da140)) {
      TStack_d8.data = (char *)&DAT_004fe63c;
      do {
        TVar9.data = TStack_d8.data;
        if (DAT_004da140 == 2) {
          pTVar3 = FUN_0041bc70(&TStack_cc,*(int *)TStack_d8.data);
          uStack_4 = 3;
          pTVar4 = FUN_0041bc70(&TStack_d0,(int)piStack_dc);
          uStack_4._0_1_ = 4;
          pTVar4 = FUN_004b082f(&TStack_c0,s_Boat_004dd23c,pTVar4);
          uStack_4._0_1_ = 5;
          pTVar4 = FUN_004b07bb(&TStack_d4,pTVar4,s_finish___004dd230);
          uStack_4._0_1_ = 6;
          pTVar3 = FUN_004b0755(&TStack_e0,pTVar4,pTVar3);
          uStack_4._0_1_ = 7;
          (*pcVar1)(param_1,10,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4._0_1_ = 6;
          FUN_004b05a5(&TStack_e0);
          uStack_4._0_1_ = 5;
          FUN_004b05a5(&TStack_d4);
          uStack_4._0_1_ = 4;
          FUN_004b05a5(&TStack_c0);
          uStack_4 = CONCAT31(uStack_4._1_3_,3);
          FUN_004b05a5(&TStack_d0);
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_cc);
          TVar8.data = TVar8.data + local_c8;
          TVar9.data = TStack_d8.data;
        }
        else {
          pTVar3 = FUN_0041bc70(&TStack_b4,*(int *)TStack_d8.data);
          uStack_4 = 8;
          pTVar3 = FUN_004b082f(&TStack_b8,s_Your_finish_position__004dd218,pTVar3);
          uStack_4._0_1_ = 9;
          (*pcVar1)(param_1,10,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4 = CONCAT31(uStack_4._1_3_,8);
          FUN_004b05a5(&TStack_b8);
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_b4);
        }
        piStack_dc = (int *)((int)piStack_dc + 1);
        TStack_d8.data = TVar9.data + 4;
      } while ((int)piStack_dc <= DAT_004da140);
    }
    TStack_cc.data = (char *)(DAT_004fe624 / 10 + -10);
    TStack_c0.data = (char *)((DAT_004fe624 * 2) / 10 + -10);
    TStack_d8.data = (char *)((DAT_004fe624 * 3) / 10 + -10);
    TStack_d0.data = (char *)((DAT_004fe624 << 2) / 10 + -10);
    if (DAT_00536424 == 0) {
      if (0 < (int)DAT_004da194) {
        TStack_d4.data = (char *)&DAT_004fc164;
        piVar5 = &DAT_004fbf34;
        iVar2 = 0;
        piStack_dc = (int *)(&DAT_004fbf30 + DAT_005363fc * 4);
        TStack_e0.data = DAT_004da194;
        do {
          iVar6 = *(int *)((int)&DAT_004fe63c + iVar2) * 0x65;
          *piStack_dc = iVar6;
          if (iVar6 == 0x65) {
            *piStack_dc = 100;
          }
          iVar6 = DAT_005363fc;
          if ((*piVar5 == 0) && (1 < DAT_005363fc)) {
            *piVar5 = 0xc1c;
          }
          if ((piVar5[1] == 0) && (2 < iVar6)) {
            piVar5[1] = 0xc1c;
          }
          if ((piVar5[2] == 0) && (iVar6 == 3)) {
            *piVar5 = 0xc1c;
          }
          iVar6 = piVar5[2] + piVar5[1] + *piVar5;
          *(int *)((int)aiStack_98 + iVar2 + 4) = iVar6;
          piVar5 = piVar5 + 4;
          *(int *)TStack_d4.data = iVar6;
          piStack_dc = piStack_dc + 4;
          iVar2 = iVar2 + 4;
          TStack_d4.data = TStack_d4.data + 4;
          TStack_e0.data = TStack_e0.data + -1;
        } while (TStack_e0.data != (char *)0x0);
      }
      FUN_0043f9f0(1);
      FUN_004b0613(&TStack_e0,s_Place_004dd0b4);
      iVar2 = (int)TVar8.data - local_c8;
      uStack_4 = 10;
      (*pcVar1)(param_1,5,iVar2,TStack_e0.data,*(int *)(TStack_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_e0);
      FUN_004b0613(&TStack_e0,s_Race_1_004dd0ac);
      uStack_4 = 0xb;
      (*pcVar1)(param_1,(int)(TStack_cc.data + DAT_004fe624 / 0x1e),iVar2,TStack_e0.data,
                *(int *)(TStack_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_e0);
      FUN_004b0613(&TStack_e0,s_Race_2_004dd0a4);
      uStack_4 = 0xc;
      (*pcVar1)(param_1,(int)(TStack_c0.data + DAT_004fe624 / 0x32),iVar2,TStack_e0.data,
                *(int *)(TStack_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_e0);
      FUN_004b0613(&TStack_e0,s_Race_3_004dd210);
      uStack_4 = 0xd;
      (*pcVar1)(param_1,(int)TStack_d8.data,iVar2,TStack_e0.data,*(int *)(TStack_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_e0);
      FUN_004b0613(&TStack_e0,s_Total_points_004dd094);
      uStack_4 = 0xe;
      (*pcVar1)(param_1,(int)TStack_d0.data - DAT_004fe624 / 0x32,iVar2,TStack_e0.data,
                *(int *)(TStack_e0.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&TStack_e0);
      piStack_dc = (int *)(DAT_004fe624 / 2 + -10);
      if (0xf < (int)DAT_004da194) {
        FUN_004b0613(&TStack_e0,s_Place_004dd0b4);
        uStack_4 = 0xf;
        (*pcVar1)(param_1,(int)piStack_dc + 5,iVar2,TStack_e0.data,*(int *)(TStack_e0.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_e0);
        FUN_004b0613(&TStack_e0,s_Race_1_004dd0ac);
        uStack_4 = 0x10;
        (*pcVar1)(param_1,(int)(TStack_cc.data + DAT_004fe624 / 0x1e + (int)piStack_dc),iVar2,
                  TStack_e0.data,*(int *)(TStack_e0.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_e0);
        FUN_004b0613(&TStack_e0,s_Race_2_004dd0a4);
        uStack_4 = 0x11;
        (*pcVar1)(param_1,(int)(TStack_c0.data + DAT_004fe624 / 0x32 + (int)piStack_dc),iVar2,
                  TStack_e0.data,*(int *)(TStack_e0.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_e0);
        FUN_004b0613(&TStack_e0,s_Race_3_004dd210);
        uStack_4 = 0x12;
        (*pcVar1)(param_1,(int)(TStack_d8.data + (int)piStack_dc),iVar2,TStack_e0.data,
                  *(int *)(TStack_e0.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_e0);
        FUN_004b0613(&TStack_e0,s_Total_points_004dd094);
        uStack_4 = 0x13;
        (*pcVar1)(param_1,(int)(TStack_d0.data + ((int)piStack_dc - DAT_004fe624 / 0x32)),iVar2,
                  TStack_e0.data,*(int *)(TStack_e0.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&TStack_e0);
      }
      TStack_e0.data = (char *)(DAT_004fe624 / 0x12);
      piStack_dc = (int *)0x1;
      if (0 < (int)DAT_004da194) {
        pcStack_a4 = TStack_e0.data + TStack_cc.data;
        pcStack_9c = TStack_e0.data + TStack_d0.data;
        do {
          iVar2 = *(int *)(&DAT_004f4778 + (int)piStack_dc * 4);
          FUN_0041f3e0(param_1,iVar2);
          TStack_d4.data = (char *)(iVar2 * 4);
          *(int **)((int)TStack_d4.data + 0x5357f8) = piStack_dc;
          pTVar3 = FUN_0041bc70(&TStack_cc,(int)piStack_dc);
          uStack_4 = 0x14;
          pTVar3 = FUN_004b07bb(&TStack_d0,pTVar3,&DAT_004dd090);
          uStack_4._0_1_ = 0x15;
          pTVar3 = FUN_004b0755(&TStack_b8,pTVar3,(Tact2010CString *)(TStack_d4.data + 0x4fec30));
          uStack_4._0_1_ = 0x16;
          pTVar3 = FUN_004b07bb(&TStack_b4,pTVar3,&DAT_004db060);
          uStack_4._0_1_ = 0x17;
          (*pcVar1)(param_1,iStack_c4 + 5,(int)TVar8.data,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4._0_1_ = 0x16;
          FUN_004b05a5(&TStack_b4);
          uStack_4._0_1_ = 0x15;
          FUN_004b05a5(&TStack_b8);
          uStack_4 = CONCAT31(uStack_4._1_3_,0x14);
          FUN_004b05a5(&TStack_d0);
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_cc);
          iVar2 = iVar2 * 0x10;
          pTVar3 = FUN_0041bc70(&TStack_a8,*(int *)(&DAT_004fbf24 + iVar2) / 100);
          uStack_4 = 0x18;
          (*pcVar1)(param_1,(int)(pcStack_a4 + iStack_c4),(int)TVar8.data,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_a8);
          if (0 < *(int *)(&DAT_004fbf28 + iVar2)) {
            pTVar3 = FUN_0041bc70(&TStack_a0,*(int *)(&DAT_004fbf28 + iVar2) / 100);
            uStack_4 = 0x19;
            (*pcVar1)(param_1,(int)(TStack_e0.data + TStack_c0.data + iStack_c4),(int)TVar8.data,
                      pTVar3->data,*(int *)(pTVar3->data + -8));
            uStack_4 = 0xffffffff;
            FUN_004b05a5(&TStack_a0);
          }
          if (0 < *(int *)(&DAT_004fbf2c + iVar2)) {
            pTVar3 = FUN_0041bc70(&TStack_ac,*(int *)(&DAT_004fbf2c + iVar2) / 100);
            uStack_4 = 0x1a;
            (*pcVar1)(param_1,(int)(TStack_e0.data + TStack_d8.data + iStack_c4),(int)TVar8.data,
                      pTVar3->data,*(int *)(pTVar3->data + -8));
            uStack_4 = 0xffffffff;
            FUN_004b05a5(&TStack_ac);
          }
          pTVar3 = FUN_0041bc70(&TStack_b0,*(int *)((int)aiStack_98 + (int)TStack_d4.data) / 100);
          uStack_4 = 0x1b;
          (*pcVar1)(param_1,(int)(pcStack_9c + iStack_c4),(int)TVar8.data,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_b0);
          TVar8.data = TVar8.data + local_c8;
          if (piStack_dc == (int *)0xf) {
            iStack_c4 = DAT_004fe624 / 2 + -10;
            TVar8.data = local_bc.data;
          }
          piStack_dc = (int *)((int)piStack_dc + 1);
        } while ((int)piStack_dc <= (int)DAT_004da194);
      }
      if (((DAT_00536424 == 0) && (DAT_005363fc == 3)) && (DAT_004da140 == 1)) {
        (**(code **)(*param_1 + 0x38))(param_1,0);
        if ((int)DAT_004da194 < 3) {
          iVar2 = (2 - DAT_005357fc) * DAT_004da198;
        }
        else {
          iVar2 = ((int)(DAT_004da194 + (1 - DAT_005357fc)) * DAT_004da198) / 0x1e;
        }
        local_bc.data = (char *)(local_c8 / 2 + local_c8 * -9);
        pcVar7 = local_bc.data + (DAT_004fe2a8 * 6) / 7;
        if (0 < iVar2) {
          pTVar3 = FUN_0041bc70(&TStack_b0,iVar2);
          uStack_4 = 0x1c;
          pTVar3 = FUN_004b082f(&local_bc,s_You_have_achieved_skill_level__004dd1f0,pTVar3);
          uStack_4._0_1_ = 0x1d;
          (*pcVar1)(param_1,10,(int)pcVar7,pTVar3->data,*(int *)(pTVar3->data + -8));
          uStack_4 = CONCAT31(uStack_4._1_3_,0x1c);
          FUN_004b05a5(&local_bc);
          uStack_4 = 0xffffffff;
          FUN_004b05a5(&TStack_b0);
        }
      }
    }
    iVar6 = local_c8;
    iVar2 = (DAT_004fe2a8 * 6) / 7 + local_c8 / 2 + local_c8 * -8 + 10;
    if (DAT_005363e4 == 0) {
      (**(code **)(*param_1 + 0x38))(param_1,0x7f007f);
    }
    if (DAT_004da140 == 1) {
      FUN_004b0613(&TStack_e0,s_Press_R_to_see_your_tracks_and_t_004dd190);
      uStack_4 = 0x1e;
      (*pcVar1)(param_1,10,iVar2,TStack_e0.data,*(int *)(TStack_e0.data + -8));
    }
    else {
      FUN_004b0613(&TStack_e0,s_Press_R_to_see_your_tracks_and_t_004dd138);
      uStack_4 = 0x1f;
      (*pcVar1)(param_1,10,iVar2,TStack_e0.data,*(int *)(TStack_e0.data + -8));
    }
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_e0);
    if (DAT_005363e4 == 0) {
      (**(code **)(*param_1 + 0x38))(param_1,0xff);
    }
    FUN_004b0613(&TStack_e0,s_Press_N_for_another_race__Select_004dd0ec);
    uStack_4 = 0x20;
    (*pcVar1)(param_1,10,iVar2 + iVar6,TStack_e0.data,*(int *)(TStack_e0.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_e0);
  }
  else {
    FUN_00416910(param_1);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

