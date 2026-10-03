
void __cdecl FUN_0041beb0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  TactCString *pTVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  LPCSTR pCVar8;
  undefined4 *unaff_FS_OFFSET;
  LPCSTR pCStack_d8;
  LPCSTR local_d4;
  int local_d0;
  TactCString local_cc;
  TactCString *local_c8;
  code *local_c4;
  int local_c0;
  int local_bc;
  TactCString TStack_b8;
  int local_b4;
  TactCString TStack_b0;
  TactCString TStack_ac;
  int iStack_a8;
  TactCString TStack_a4;
  LPCSTR pCStack_a0;
  TactCString TStack_9c;
  TactCString TStack_98;
  TactCString TStack_94;
  TactCString TStack_90;
  LPCSTR pCStack_8c;
  int aiStack_88 [31];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e213;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_c0 = 0xf;
  local_d0 = 0;
  pcVar6 = (code *)(((699 < DAT_004a763c) - 1 & 0xfffffff1) + 0x32);
  if (900 < DAT_004a763c) {
    local_c0 = 0x14;
    pcVar6 = (code *)0x41;
  }
  local_cc.data = (char *)(DAT_004a763c / 10 + -10);
  local_bc = (DAT_004a763c * 2) / 10 + -10;
  local_b4 = (DAT_004a763c * 3) / 10 + -10;
  local_c8 = (TactCString *)((DAT_004a763c << 2) / 10 + -10);
  local_c4 = pcVar6;
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0x7f0000);
  }
  FUN_0046bf33(&local_d4,s____Results_of_Previous_Races_in_T_004930b4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*param_1 + 100);
  (*pcVar1)(param_1,10,1,local_d4,*(int *)(local_d4 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_d4);
  if (DAT_004ac960 == 0) {
    if (0 < DAT_0049118c) {
      piVar4 = &DAT_004a6bc4;
      iVar2 = 0;
      iVar5 = DAT_0049118c;
      do {
        if (DAT_004ac944 == 1) {
          iVar7 = *piVar4;
        }
        else {
          iVar7 = piVar4[1] + *piVar4;
        }
        *(int *)((int)aiStack_88 + iVar2 + 4) = iVar7;
        *(int *)((int)&DAT_004a6db4 + iVar2) = iVar7;
        piVar4 = piVar4 + 4;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    FUN_0042cca0(1);
    FUN_0046bf33(&pCStack_d8,s_Place_004930ac);
    pCVar8 = (LPCSTR)((int)pcVar6 - local_c0);
    uStack_4 = 1;
    local_d4 = pCVar8;
    (*pcVar1)(param_1,5,(int)pCVar8,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    FUN_0046bf33(&pCStack_d8,s_Race_1_004930a4);
    uStack_4 = 2;
    (*pcVar1)(param_1,(int)(local_cc.data + DAT_004a763c / 0x1e),(int)pCVar8,pCStack_d8,
              *(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    if (DAT_004ac944 == 2) {
      FUN_0046bf33(&pCStack_d8,s_Race_2_0049309c);
      uStack_4 = 3;
      (*pcVar1)(param_1,DAT_004a763c / 0x32 + local_bc,(int)pCVar8,pCStack_d8,
                *(int *)(pCStack_d8 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_d8);
    }
    FUN_0046bf33(&pCStack_d8,s_Total_points_0049308c);
    uStack_4 = 4;
    (*pcVar1)(param_1,(int)local_c8 - DAT_004a763c / 0x32,(int)pCVar8,pCStack_d8,
              *(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    iVar5 = DAT_004a763c / 2;
    iVar2 = iVar5 + -10;
    if (0xf < DAT_0049118c) {
      FUN_0046bf33(&pCStack_d8,s_Place_004930ac);
      uStack_4 = 5;
      (*pcVar1)(param_1,iVar5 + -5,(int)local_d4,pCStack_d8,*(int *)(pCStack_d8 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_d8);
      FUN_0046bf33(&pCStack_d8,s_Race_1_004930a4);
      uStack_4 = 6;
      (*pcVar1)(param_1,(int)(local_cc.data + DAT_004a763c / 0x1e + iVar2),(int)local_d4,pCStack_d8,
                *(int *)(pCStack_d8 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_d8);
      if (DAT_004ac944 == 2) {
        FUN_0046bf33(&pCStack_d8,s_Race_2_0049309c);
        uStack_4 = 7;
        (*pcVar1)(param_1,DAT_004a763c / 0x32 + iVar2 + local_bc,(int)local_d4,pCStack_d8,
                  *(int *)(pCStack_d8 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&pCStack_d8);
      }
      FUN_0046bf33(&pCStack_d8,s_Total_points_0049308c);
      uStack_4 = 8;
      (*pcVar1)(param_1,(iVar2 - DAT_004a763c / 0x32) + (int)local_c8,(int)local_d4,pCStack_d8,
                *(int *)(pCStack_d8 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&pCStack_d8);
    }
    pCStack_d8 = (LPCSTR)(DAT_004a763c / 0x12);
    local_d4 = (LPCSTR)0x1;
    if (0 < DAT_0049118c) {
      pCStack_8c = pCStack_d8 + (int)local_cc.data;
      pCStack_a0 = pCStack_d8 + (int)local_c8;
      do {
        iVar5 = *(int *)(&DAT_004a4438 + (int)local_d4 * 4);
        FUN_00416990(param_1,iVar5);
        iStack_a8 = iVar5 * 4;
        *(LPCSTR *)(&DAT_004ac0c0 + iStack_a8) = local_d4;
        local_c8 = FUN_00413d00(&TStack_b8,iVar5);
        uStack_4 = 9;
        pTVar3 = FUN_00413d00(&TStack_9c,(int)local_d4);
        uStack_4._0_1_ = 10;
        pTVar3 = FUN_0046c0db(&TStack_90,pTVar3,s___boat_00493080);
        uStack_4._0_1_ = 0xb;
        pTVar3 = FUN_0046c075(&TStack_ac,pTVar3,local_c8);
        uStack_4._0_1_ = 0xc;
        pTVar3 = FUN_0046c0db(&local_cc,pTVar3,&DAT_00491d20);
        uStack_4._0_1_ = 0xd;
        (*pcVar1)(param_1,local_d0 + 5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
        uStack_4._0_1_ = 0xc;
        FUN_0046bec5((int *)&local_cc);
        uStack_4._0_1_ = 0xb;
        FUN_0046bec5((int *)&TStack_ac);
        uStack_4._0_1_ = 10;
        FUN_0046bec5((int *)&TStack_90);
        uStack_4 = CONCAT31(uStack_4._1_3_,9);
        FUN_0046bec5((int *)&TStack_9c);
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_b8);
        iVar5 = iVar5 * 0x10;
        pTVar3 = FUN_00413d00(&TStack_a4,*(int *)(&DAT_004a6bb4 + iVar5) / 100);
        uStack_4 = 0xe;
        (*pcVar1)(param_1,(int)(pCStack_8c + local_d0),(int)pcVar6,pTVar3->data,
                  *(int *)(pTVar3->data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_a4);
        if ((0 < *(int *)(&DAT_004a6bb8 + iVar5)) && (1 < DAT_004ac944)) {
          pTVar3 = FUN_00413d00(&TStack_94,*(int *)(&DAT_004a6bb8 + iVar5) / 100);
          uStack_4 = 0xf;
          (*pcVar1)(param_1,(int)(pCStack_d8 + local_d0 + local_bc),(int)pcVar6,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_94);
        }
        if (0 < *(int *)(&DAT_004a6bbc + iVar5)) {
          pTVar3 = FUN_00413d00(&TStack_b0,*(int *)(&DAT_004a6bbc + iVar5) / 100);
          uStack_4 = 0x10;
          (*pcVar1)(param_1,(int)(pCStack_d8 + local_d0 + local_b4),(int)pcVar6,pTVar3->data,
                    *(int *)(pTVar3->data + -8));
          uStack_4 = 0xffffffff;
          FUN_0046bec5((int *)&TStack_b0);
        }
        pTVar3 = FUN_00413d00(&TStack_98,*(int *)((int)aiStack_88 + iStack_a8) / 100);
        uStack_4 = 0x11;
        (*pcVar1)(param_1,(int)(pCStack_a0 + local_d0),(int)pcVar6,pTVar3->data,
                  *(int *)(pTVar3->data + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5((int *)&TStack_98);
        pcVar6 = (code *)((int)pcVar6 + local_c0);
        if (local_d4 == (LPCSTR)0xf) {
          local_d0 = DAT_004a763c / 2 + -10;
          pcVar6 = local_c4;
        }
        local_d4 = local_d4 + 1;
      } while ((int)local_d4 <= DAT_0049118c);
    }
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))(param_1,0xff);
  }
  iVar2 = local_c0;
  local_c4 = (code *)(local_c0 * 8);
  iVar5 = (DAT_004a72d0 * 6) / 7 + local_c0 * -8 + 10;
  FUN_0046bf33(&pCStack_d8,s_Movement_suspended__Click_mouse_o_004918bc);
  uStack_4 = 0x12;
  (*pcVar1)(param_1,10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_d8);
  iVar5 = iVar5 + iVar2 * 2;
  if (DAT_004ac9bc == 1) {
    if (DAT_004a6dac != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a6dac);
    }
    Rectangle((HDC)param_1[1],0,iVar5 + -4,DAT_004a763c,DAT_004a72d0);
    iVar2 = *param_1;
    local_c4 = *(code **)(iVar2 + 0x34);
    (*local_c4)(param_1,0x7f7f00);
    pcVar6 = *(code **)(iVar2 + 0x38);
    (*pcVar6)(param_1,0);
    FUN_0046bf33(&pCStack_d8,s_Mainsail_colors__0049306c);
    uStack_4 = 0x13;
    (*pcVar1)(param_1,10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    iVar5 = iVar5 + local_c0;
    (*pcVar6)(param_1,0xffff);
    FUN_0046bf33(&pCStack_d8,s_Boat_1__yellow_0049305c);
    uStack_4 = 0x14;
    (*pcVar1)(param_1,10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    (*pcVar6)(param_1,0xff00);
    FUN_0046bf33(&pCStack_d8,s_Boat_2__green_0049304c);
    uStack_4 = 0x15;
    (*pcVar1)(param_1,DAT_004a763c / 5 + 10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    (*pcVar6)(param_1,0xffffff);
    FUN_0046bf33(&pCStack_d8,s_Boats_3_10___white_00493038);
    uStack_4 = 0x16;
    (*pcVar1)(param_1,(DAT_004a763c * 2) / 5 + 10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    (*pcVar6)(param_1,0x7f7f7f);
    FUN_0046bf33(&pCStack_d8,s_Boats_11_20__gray_00493024);
    uStack_4 = 0x17;
    (*pcVar1)(param_1,(DAT_004a763c * 3) / 5 + 10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    (*pcVar6)(param_1,0xff0000);
    FUN_0046bf33(&pCStack_d8,s_Boats_21_30__blue_00493010);
    uStack_4 = 0x18;
    (*pcVar1)(param_1,(DAT_004a763c * 4) / 5 + 10,iVar5,pCStack_d8,*(int *)(pCStack_d8 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_d8);
    (*local_c4)(param_1,0xffffff);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

