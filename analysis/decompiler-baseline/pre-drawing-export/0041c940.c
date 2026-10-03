
void __cdecl FUN_0041c940(int *param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  int unaff_EBP;
  int iVar13;
  undefined4 *unaff_FS_OFFSET;
  int iStack_15c;
  undefined *puStack_158;
  int iStack_148;
  undefined *puStack_140;
  int iStack_13c;
  code *pcVar14;
  int iStack_130;
  undefined *puStack_12c;
  int iStack_120;
  int **ppiStack_11c;
  int iVar15;
  int *piStack_10c;
  int *piVar16;
  uint uVar17;
  uint *puVar18;
  int iStack_f0;
  int *piStack_ec;
  uint uStack_d8;
  code *pcStack_d4;
  int aiStack_d0 [4];
  undefined4 uStack_c0;
  int iStack_bc;
  undefined1 auStack_b8 [12];
  int aiStack_ac [9];
  undefined4 uStack_88;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e3c2;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar11 = ((699 < DAT_004a763c) - 1 & 0xfffffff1) + 0x32;
  aiStack_d0[2] = 0xf;
  if (699 < DAT_004a763c) {
    aiStack_d0[2] = 0x11;
  }
  if (900 < DAT_004a763c) {
    aiStack_d0[2] = 0x14;
    iVar11 = 0x41;
  }
  piStack_ec = (int *)0x0;
  iVar10 = *param_1;
  pcVar2 = *(code **)(iVar10 + 0x2c);
  iStack_f0 = 0x41c9b6;
  aiStack_d0[1] = iVar11;
  (*pcVar2)();
  iStack_f0 = 6;
  (*pcVar2)();
  Rectangle((HDC)param_1[1],0,0,DAT_004a763c,DAT_004a72d0);
  if ((DAT_00491164 < 1) || (DAT_004ac93c < 1)) {
    DAT_0049116c = DAT_004aa6f8;
    DAT_00491170 = DAT_004ac858;
    uStack_c0 = 0;
    if (DAT_004ac92c == 0) {
      (**(code **)(iVar10 + 0x38))();
      (**(code **)(iVar10 + 0x34))();
    }
    FUN_0046bf33(&uStack_d8,s_____Results_____00493198);
    pcVar2 = *(code **)(iVar10 + 100);
    uStack_c = 0;
    iVar10 = *(int *)(uStack_d8 - 8);
    piVar16 = (int *)0x1;
    (*pcVar2)();
    uStack_1c = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffff18);
    piStack_10c = (int *)0x41ca90;
    FUN_00413d00(&stack0xffffff24,DAT_00491190);
    piStack_10c = &iStack_f0;
    uStack_1c = 1;
    FUN_0046c14f();
    uStack_1c = CONCAT31(uStack_1c._1_3_,2);
    piStack_10c = (int *)0x1;
    iVar7 = (DAT_004a763c * 3) / 5;
    (*pcVar2)();
    uStack_2c = CONCAT31(uStack_2c._1_3_,1);
    FUN_0046bec5((int *)&stack0xffffff00);
    uStack_2c = 0xffffffff;
    FUN_0046bec5((int *)&piStack_ec);
    if ((DAT_004ac960 == 1) && (piVar16 = (int *)0x1, 0 < DAT_00491140)) {
      puVar18 = &DAT_004a764c;
      do {
        if (DAT_00491140 == 2) {
          ppiStack_11c = (int **)0x41cb42;
          FUN_00413d00(&stack0xffffff1c,*puVar18);
          uStack_2c = 3;
          ppiStack_11c = (int **)0x41cb61;
          FUN_00413d00(&stack0xffffff18,(uint)piVar16);
          ppiStack_11c = (int **)&stack0xffffff24;
          uStack_2c._0_1_ = 4;
          iStack_120 = 0x41cb7c;
          FUN_0046c14f();
          ppiStack_11c = &piStack_ec;
          uStack_2c._0_1_ = 5;
          iStack_120 = 0x41cb94;
          FUN_0046c0db();
          ppiStack_11c = (int **)&stack0xffffff00;
          uStack_2c._0_1_ = 6;
          iStack_120 = 0x41cba8;
          FUN_0046c075();
          uStack_2c._0_1_ = 7;
          iStack_120 = 10;
          ppiStack_11c = (int **)iVar11;
          (*pcVar2)();
          uStack_2c._0_1_ = 6;
          FUN_0046bec5((int *)&stack0xffffff00);
          uStack_2c._0_1_ = 5;
          FUN_0046bec5((int *)&piStack_ec);
          uStack_2c._0_1_ = 4;
          FUN_0046bec5((int *)&stack0xffffff24);
          uStack_2c = CONCAT31(uStack_2c._1_3_,3);
          FUN_0046bec5((int *)&stack0xffffff18);
          uStack_2c = 0xffffffff;
          FUN_0046bec5((int *)&stack0xffffff1c);
          iVar11 = iVar11 + iStack_f0;
        }
        else {
          ppiStack_11c = (int **)0x41cc30;
          FUN_00413d00(&pcStack_d4,*puVar18);
          ppiStack_11c = (int **)aiStack_d0;
          uStack_2c = 8;
          iStack_120 = 0x41cc4e;
          FUN_0046c14f();
          uStack_2c._0_1_ = 9;
          iStack_120 = 10;
          ppiStack_11c = (int **)iVar11;
          (*pcVar2)();
          uStack_2c = CONCAT31(uStack_2c._1_3_,8);
          FUN_0046bec5(aiStack_d0);
          uStack_2c = 0xffffffff;
          FUN_0046bec5((int *)&pcStack_d4);
        }
        piVar16 = (int *)((int)piVar16 + 1);
        puVar18 = puVar18 + 1;
      } while ((int)piVar16 <= DAT_00491140);
    }
    iVar15 = DAT_004a763c / 10;
    iVar5 = (DAT_004a763c << 2) / 10;
    iVar1 = iVar5 + -10;
    if (DAT_004ac960 == 0) {
      if (0 < DAT_0049118c) {
        piStack_ec = &DAT_004a6db4;
        piVar6 = &DAT_004a6bc4;
        iVar13 = 0;
        piVar16 = (int *)(&DAT_004a6bc0 + DAT_004ac944 * 4);
        iVar9 = DAT_0049118c;
        do {
          iVar8 = *(int *)((int)&DAT_004a764c + iVar13) * 0x65;
          *piVar16 = iVar8;
          if (iVar8 == 0x65) {
            *piVar16 = 100;
          }
          iVar8 = DAT_004ac944;
          if ((*piVar6 == 0) && (1 < DAT_004ac944)) {
            *piVar6 = 0xc1c;
          }
          if ((piVar6[1] == 0) && (2 < iVar8)) {
            piVar6[1] = 0xc1c;
          }
          if ((piVar6[2] == 0) && (iVar8 == 3)) {
            *piVar6 = 0xc1c;
          }
          iVar8 = piVar6[2] + piVar6[1] + *piVar6;
          *(int *)((int)aiStack_ac + iVar13) = iVar8;
          piVar6 = piVar6 + 4;
          *piStack_ec = iVar8;
          piVar16 = piVar16 + 4;
          iVar13 = iVar13 + 4;
          piStack_ec = piStack_ec + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      FUN_0042cca0(1);
      FUN_0046bf33(&stack0xffffff00,s_Place_004930ac);
      iVar13 = iVar11 - iStack_f0;
      uStack_2c = 10;
      iStack_120 = 5;
      ppiStack_11c = (int **)iVar13;
      (*pcVar2)();
      uStack_3c = 0xffffffff;
      FUN_0046bec5((int *)&stack0xfffffef0);
      FUN_0046bf33(&stack0xfffffef0,s_Race_1_004930a4);
      uStack_3c = 0xb;
      iStack_130 = DAT_004a763c / 0x1e + iVar10;
      puStack_12c = (undefined *)iVar13;
      iVar9 = iVar7;
      (*pcVar2)();
      uStack_4c = 0xffffffff;
      FUN_0046bec5(&iStack_120);
      FUN_0046bf33(&iStack_120,s_Race_2_0049309c);
      uStack_4c = 0xc;
      puStack_140 = (undefined *)(DAT_004a763c / 0x32 + (int)piVar16);
      iStack_13c = iVar13;
      (*pcVar2)();
      uStack_5c = 0xffffffff;
      FUN_0046bec5(&iStack_130);
      iStack_148 = 0x41cefb;
      FUN_0046bf33(&iStack_130,s_Race_3_00493150);
      uStack_5c = 0xd;
      iStack_148 = iStack_130;
      (*pcVar2)();
      uStack_6c = 0xffffffff;
      FUN_0046bec5((int *)&puStack_140);
      puStack_158 = (undefined *)0x41cf3b;
      FUN_0046bf33(&puStack_140,s_Total_points_0049308c);
      uStack_6c = 0xe;
      puStack_158 = puStack_140;
      iStack_15c = iVar13;
      (*pcVar2)(iVar7 - DAT_004a763c / 0x32);
      uStack_2c = 0xffffffff;
      FUN_0046bec5((int *)&stack0xffffff00);
      iVar7 = DAT_004a763c / 2 + -10;
      if (0xf < DAT_0049118c) {
        FUN_0046bf33(&stack0xffffff00,s_Place_004930ac);
        uStack_2c = 0xf;
        iStack_120 = iVar7 + 5;
        ppiStack_11c = (int **)iVar13;
        (*pcVar2)();
        uStack_3c = 0xffffffff;
        FUN_0046bec5((int *)&stack0xfffffef0);
        FUN_0046bf33(&stack0xfffffef0,s_Race_1_004930a4);
        uStack_3c = 0x10;
        iStack_130 = (int)piStack_10c + iVar10 + DAT_004a763c / 0x1e;
        puStack_12c = (undefined *)iVar13;
        (*pcVar2)();
        uStack_4c = 0xffffffff;
        FUN_0046bec5(&iStack_120);
        FUN_0046bf33(&iStack_120,s_Race_2_0049309c);
        uStack_4c = 0x11;
        puStack_140 = (undefined *)(DAT_004a763c / 0x32 + (int)ppiStack_11c + iVar7);
        iStack_13c = iVar13;
        (*pcVar2)();
        uStack_5c = 0xffffffff;
        FUN_0046bec5(&iStack_130);
        iStack_148 = 0x41d0b6;
        FUN_0046bf33(&iStack_130,s_Race_3_00493150);
        uStack_5c = 0x12;
        iStack_148 = iStack_130;
        (*pcVar2)();
        uStack_6c = 0xffffffff;
        FUN_0046bec5((int *)&puStack_140);
        puStack_158 = (undefined *)0x41d0fc;
        FUN_0046bf33(&puStack_140,s_Total_points_0049308c);
        uStack_6c = 0x13;
        puStack_158 = puStack_140;
        iStack_15c = iVar13;
        (*pcVar2)((iStack_13c - DAT_004a763c / 0x32) + iVar9);
        uStack_2c = 0xffffffff;
        FUN_0046bec5((int *)&stack0xffffff00);
      }
      iVar7 = DAT_004a763c / 0x12;
      uVar17 = 1;
      if (0 < DAT_0049118c) {
        iStack_bc = iVar7 + iVar15 + -10;
        aiStack_d0[2] = iVar7 + iVar1;
        do {
          uVar3 = *(uint *)(&DAT_004a4438 + uVar17 * 4);
          ppiStack_11c = (int **)0x41d1a4;
          FUN_00416990(param_1,uVar3);
          aiStack_d0[1] = uVar3 * 4;
          *(uint *)(&DAT_004ac0c0 + aiStack_d0[1]) = uVar17;
          ppiStack_11c = (int **)0x41d1c7;
          pcStack_d4 = FUN_00413d00(auStack_b8,uVar3);
          uStack_2c = 0x14;
          ppiStack_11c = (int **)0x41d1e8;
          FUN_00413d00(&stack0xffffff1c,uVar17);
          ppiStack_11c = (int **)&stack0xffffff18;
          uStack_2c._0_1_ = 0x15;
          iStack_120 = 0x41d203;
          FUN_0046c0db();
          ppiStack_11c = &piStack_ec;
          uStack_2c._0_1_ = 0x16;
          iStack_120 = 0x41d21b;
          FUN_0046c075();
          ppiStack_11c = (int **)aiStack_d0;
          uStack_2c._0_1_ = 0x17;
          iStack_120 = 0x41d233;
          piVar16 = (int *)FUN_0046c0db();
          iVar15 = *piVar16;
          iStack_120 = unaff_EBP + 5;
          uStack_2c = CONCAT31(uStack_2c._1_3_,0x18);
          ppiStack_11c = (int **)iVar11;
          (*pcVar2)();
          uStack_3c._0_1_ = 0x17;
          FUN_0046bec5((int *)&stack0xffffff20);
          uStack_3c._0_1_ = 0x16;
          FUN_0046bec5((int *)&stack0xffffff04);
          uStack_3c._0_1_ = 0x15;
          FUN_0046bec5((int *)&stack0xffffff08);
          uStack_3c = CONCAT31(uStack_3c._1_3_,0x14);
          FUN_0046bec5((int *)&stack0xffffff0c);
          uStack_3c = 0xffffffff;
          FUN_0046bec5(aiStack_d0 + 2);
          iVar9 = uVar3 * 0x10;
          puStack_12c = (undefined *)0x41d2cc;
          FUN_00413d00(aiStack_d0,*(int *)(&DAT_004a6bb4 + iVar9) / 100);
          uStack_3c = 0x19;
          iStack_130 = iStack_f0 + aiStack_d0[1];
          puStack_12c = (undefined *)iVar11;
          (*pcVar2)();
          uStack_4c = 0xffffffff;
          FUN_0046bec5((int *)&stack0xffffff20);
          if (0 < *(int *)(&DAT_004a6bb8 + iVar9)) {
            iStack_13c = 0x41d32b;
            FUN_00413d00(&stack0xffffff1c,*(int *)(&DAT_004a6bb8 + iVar9) / 100);
            uStack_4c = 0x1a;
            puStack_140 = (undefined *)(iStack_120 + uVar17 + iVar7);
            iStack_13c = iVar11;
            (*pcVar2)();
            uStack_4c = 0xffffffff;
            FUN_0046bec5((int *)&stack0xffffff1c);
          }
          if (0 < *(int *)(&DAT_004a6bbc + iVar9)) {
            iStack_13c = 0x41d390;
            FUN_00413d00(&pcStack_d4,*(int *)(&DAT_004a6bbc + iVar9) / 100);
            uStack_4c = 0x1b;
            puStack_140 = (undefined *)(iStack_120 + iVar15 + iVar7);
            iStack_13c = iVar11;
            (*pcVar2)();
            uStack_4c = 0xffffffff;
            FUN_0046bec5((int *)&pcStack_d4);
          }
          iStack_13c = 0x41d3f3;
          FUN_00413d00(&stack0xffffff08,*(int *)((int)aiStack_d0 + (int)piStack_ec) / 100);
          uStack_4c = 0x1c;
          puStack_140 = (undefined *)(iVar7 + iVar1);
          iStack_13c = iVar11;
          (*pcVar2)();
          uStack_2c = 0xffffffff;
          FUN_0046bec5((int *)&uStack_d8);
          iVar11 = iVar11 + iStack_f0;
          if (uVar17 == 0xf) {
            unaff_EBP = DAT_004a763c / 2 + -10;
            iVar11 = iVar10;
          }
          uVar17 = uVar17 + 1;
        } while ((int)uVar17 <= DAT_0049118c);
      }
      if (((DAT_004ac960 == 0) && (DAT_004ac944 == 3)) && (DAT_00491140 == 1)) {
        (**(code **)(*param_1 + 0x38))();
        uStack_d8 = (int)(((DAT_0049118c - DAT_004ac0c4) + 1) * DAT_00491190) / 0x1e;
        iVar7 = iStack_f0 / 2;
        iVar11 = iStack_f0 * -9;
        iVar10 = DAT_004a72d0 * 6;
        if (0 < (int)uStack_d8) {
          ppiStack_11c = (int **)0x41d50a;
          FUN_00413d00(&uStack_d8,uStack_d8);
          ppiStack_11c = (int **)&stack0xffffff0c;
          uStack_2c = 0x1d;
          iStack_120 = 0x41d529;
          FUN_0046c14f();
          uStack_2c._0_1_ = 0x1e;
          iStack_120 = 10;
          ppiStack_11c = (int **)(iVar10 / 7 + iVar7 + iVar11);
          (*pcVar2)();
          uStack_2c = CONCAT31(uStack_2c._1_3_,0x1d);
          FUN_0046bec5((int *)&stack0xffffff0c);
          uStack_2c = 0xffffffff;
          FUN_0046bec5((int *)&uStack_d8);
        }
      }
    }
    iVar10 = iStack_f0;
    iVar11 = (DAT_004a72d0 * 6) / 7 + iStack_f0 / 2 + iStack_f0 * -8 + 10;
    if (DAT_004ac92c == 0) {
      (**(code **)(*param_1 + 0x38))();
    }
    FUN_0046bf33(&stack0xffffff00,s_For_another_race_press_N__To_qui_004930e4);
    uStack_2c = 0x1f;
    iStack_120 = 10;
    ppiStack_11c = (int **)iVar11;
    (*pcVar2)();
    uStack_c = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffff20);
    iVar11 = iVar11 + iVar10 * 2;
    if (DAT_004ac9bc == 1) {
      if (DAT_004a6dac != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a6dac);
      }
      Rectangle((HDC)param_1[1],0,iVar11 + -4,DAT_004a763c,DAT_004a72d0);
      iVar10 = *param_1;
      pcStack_d4 = *(code **)(iVar10 + 0x34);
      (*pcStack_d4)();
      pcVar4 = *(code **)(iVar10 + 0x38);
      (*pcVar4)();
      FUN_0046bf33(&stack0xffffff18,s_Mainsail_colors__0049306c);
      uStack_14 = 0x20;
      iVar10 = *(int *)(iVar5 + -0x12);
      piStack_10c = (int *)0x41d687;
      (*pcVar2)();
      uStack_24 = 0xffffffff;
      piStack_10c = (int *)0x41d69b;
      FUN_0046bec5((int *)&stack0xffffff08);
      piStack_10c = (int *)0xffff;
      puVar12 = (undefined *)(iVar11 + iVar1);
      (*pcVar4)();
      FUN_0046bf33(&stack0xffffff04,s_Boat_1__yellow_0049305c);
      uStack_28 = 0x21;
      iVar11 = *(int *)(iVar10 + -8);
      ppiStack_11c = (int **)0xa;
      iStack_120 = 0x41d6d3;
      (*pcVar2)();
      uStack_38 = 0xffffffff;
      iStack_120 = 0x41d6e7;
      FUN_0046bec5((int *)&piStack_10c);
      iStack_120 = 0xff00;
      (*pcVar4)();
      FUN_0046bf33(&stack0xfffffef0,s_Boat_2__green_0049304c);
      uStack_3c = 0x22;
      iVar11 = *(int *)(iVar11 + -8);
      iStack_130 = DAT_004a763c / 5 + 10;
      puStack_12c = puVar12;
      (*pcVar2)();
      uStack_4c = 0xffffffff;
      FUN_0046bec5(&iStack_120);
      (*pcVar4)();
      iStack_13c = 0x41d75b;
      FUN_0046bf33(&stack0xfffffedc,s_Boats_3_10___white_00493038);
      iStack_13c = iVar11;
      uStack_50 = 0x23;
      pcVar14 = *(code **)(iStack_13c + -8);
      iStack_148 = 0x41d78f;
      puStack_140 = puVar12;
      (*pcVar2)();
      uStack_60 = 0xffffffff;
      iStack_148 = 0x41d7a3;
      FUN_0046bec5((int *)&stack0xfffffecc);
      iStack_148 = 0x7f7f7f;
      (*pcVar4)();
      FUN_0046bf33(&stack0xfffffec8,s_Boats_11_20__gray_00493024);
      uStack_64 = 0x24;
      iVar11 = *(int *)(pcVar14 + -8);
      puStack_158 = (undefined *)((DAT_004a763c * 3) / 5 + 10);
      iStack_15c = 0x41d7ee;
      (*pcVar2)();
      uStack_74 = 0xffffffff;
      iStack_15c = 0x41d802;
      FUN_0046bec5(&iStack_148);
      iStack_15c = 0xff0000;
      (*pcVar4)();
      FUN_0046bf33(&stack0xfffffeb4,s_Boats_21_30__blue_00493010);
      uStack_78 = 0x25;
      (*pcVar2)((DAT_004a763c * 4) / 5 + 10,puVar12,iVar11,*(undefined4 *)(iVar11 + -8));
      uStack_88 = 0xffffffff;
      FUN_0046bec5(&iStack_15c);
      (*pcVar14)(0xffffff);
    }
  }
  else {
    FUN_00410090((undefined *)param_1);
  }
  *unaff_FS_OFFSET = uStack_14;
  return;
}

