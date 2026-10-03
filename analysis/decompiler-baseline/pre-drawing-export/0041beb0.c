
void __cdecl FUN_0041beb0(int *param_1)

{
  code *pcVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int unaff_EBX;
  int iVar7;
  int unaff_EBP;
  int unaff_EDI;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  code *pcStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  int aiStack_138 [3];
  int iStack_12c;
  int iStack_124;
  int iStack_108;
  int *piStack_104;
  int aiStack_f8 [3];
  uint uVar9;
  void *pvStack_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4 [3];
  int aiStack_b8 [3];
  undefined1 auStack_ac [4];
  int aiStack_a8 [2];
  undefined4 uStack_a0;
  int iStack_9c;
  int aiStack_94 [6];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e213;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_c4[1] = 0xf;
  local_d0 = 0;
  iVar7 = ((699 < DAT_004a763c) - 1 & 0xfffffff1) + 0x32;
  if (900 < DAT_004a763c) {
    local_c4[1] = 0x14;
    iVar7 = 0x41;
  }
  local_cc = DAT_004a763c / 10 + -10;
  local_c4[2] = (DAT_004a763c * 2) / 10 + -10;
  aiStack_b8[1] = (DAT_004a763c * 3) / 10 + -10;
  local_c8 = (DAT_004a763c << 2) / 10 + -10;
  local_c4[0] = iVar7;
  if (DAT_004ac92c == 0) {
    aiStack_f8[2] = 0x41bf8f;
    (**(code **)(*param_1 + 0x38))();
  }
  aiStack_f8[2] = 0x41bf9d;
  FUN_0046bf33(&local_d4,s____Results_of_Previous_Races_in_T_004930b4);
  uStack_4 = 0;
  pcVar1 = *(code **)(*param_1 + 100);
  aiStack_f8[2] = local_d4;
  aiStack_f8[1] = 1;
  aiStack_f8[0] = 10;
  (*pcVar1)();
  uStack_14 = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff1c);
  if (DAT_004ac960 == 0) {
    if (0 < DAT_0049118c) {
      piVar5 = &DAT_004a6bc4;
      iVar4 = 0;
      iVar6 = DAT_0049118c;
      do {
        if (DAT_004ac944 == 1) {
          iVar8 = *piVar5;
        }
        else {
          iVar8 = piVar5[1] + *piVar5;
        }
        *(int *)((int)aiStack_94 + iVar4) = iVar8;
        *(int *)((int)&DAT_004a6db4 + iVar4) = iVar8;
        piVar5 = piVar5 + 4;
        iVar4 = iVar4 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_0042cca0(1);
    FUN_0046bf33(&stack0xffffff18,s_Place_004930ac);
    iVar6 = iVar7 - local_d0;
    iStack_108 = 5;
    uStack_14 = 1;
    piStack_104 = (int *)iVar6;
    (*pcVar1)();
    uStack_24 = 0xffffffff;
    FUN_0046bec5(aiStack_f8);
    FUN_0046bf33(aiStack_f8,s_Race_1_004930a4);
    uStack_24 = 2;
    (*pcVar1)();
    uStack_34 = 0xffffffff;
    FUN_0046bec5(&iStack_108);
    if (DAT_004ac944 == 2) {
      FUN_0046bf33(&iStack_108,s_Race_2_0049309c);
      uStack_34 = 3;
      iStack_12c = 0x41c10d;
      iStack_124 = iVar6;
      (*pcVar1)();
      uStack_34 = 0xffffffff;
      FUN_0046bec5(&iStack_108);
    }
    FUN_0046bf33(&iStack_108,s_Total_points_0049308c);
    uStack_34 = 4;
    iStack_12c = 0x41c166;
    iStack_124 = iVar6;
    (*pcVar1)();
    uStack_14 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffff18);
    iVar4 = DAT_004a763c / 2;
    if (0xf < DAT_0049118c) {
      FUN_0046bf33(&stack0xffffff18,s_Place_004930ac);
      iStack_108 = iVar4 + -5;
      uStack_14 = 5;
      piStack_104 = (int *)iVar6;
      (*pcVar1)();
      uStack_24 = 0xffffffff;
      FUN_0046bec5(aiStack_f8);
      FUN_0046bf33(aiStack_f8,s_Race_1_004930a4);
      uStack_24 = 6;
      (*pcVar1)();
      uStack_34 = 0xffffffff;
      FUN_0046bec5(&iStack_108);
      if (DAT_004ac944 == 2) {
        FUN_0046bf33(&iStack_108,s_Race_2_0049309c);
        uStack_34 = 7;
        iStack_124 = (int)piStack_104;
        iStack_12c = 0x41c28f;
        (*pcVar1)();
        uStack_34 = 0xffffffff;
        FUN_0046bec5(&iStack_108);
      }
      FUN_0046bf33(&iStack_108,s_Total_points_0049308c);
      uStack_34 = 8;
      iStack_124 = (int)piStack_104;
      iStack_12c = 0x41c2ee;
      (*pcVar1)();
      uStack_14 = 0xffffffff;
      FUN_0046bec5((int *)&stack0xffffff18);
    }
    unaff_EDI = DAT_004a763c / 0x12;
    uVar9 = 1;
    if (0 < DAT_0049118c) {
      iStack_9c = unaff_EDI + unaff_EBX;
      aiStack_b8[2] = unaff_EDI + (int)pvStack_d8;
      do {
        uVar2 = *(uint *)(&DAT_004a4438 + uVar9 * 4);
        piStack_104 = (int *)0x41c359;
        FUN_00416990(param_1,uVar2);
        aiStack_b8[0] = uVar2 * 4;
        *(uint *)(&DAT_004ac0c0 + aiStack_b8[0]) = uVar9;
        piStack_104 = (int *)0x41c37c;
        pvStack_d8 = FUN_00413d00(&local_c8,uVar2);
        uStack_14 = 9;
        piStack_104 = (int *)0x41c39d;
        FUN_00413d00(auStack_ac,uVar9);
        piStack_104 = &uStack_a0;
        uStack_14._0_1_ = 10;
        iStack_108 = 0x41c3b8;
        FUN_0046c0db();
        piStack_104 = local_c4 + 2;
        uStack_14._0_1_ = 0xb;
        iStack_108 = 0x41c3d0;
        FUN_0046c075();
        piStack_104 = (int *)&stack0xffffff24;
        uStack_14._0_1_ = 0xc;
        iStack_108 = 0x41c3e8;
        FUN_0046c0db();
        iStack_108 = unaff_EBP + 5;
        uStack_14 = CONCAT31(uStack_14._1_3_,0xd);
        piStack_104 = (int *)iVar7;
        (*pcVar1)();
        uStack_24._0_1_ = 0xc;
        FUN_0046bec5((int *)&stack0xffffff14);
        uStack_24._0_1_ = 0xb;
        FUN_0046bec5(&local_cc);
        uStack_24._0_1_ = 10;
        FUN_0046bec5(aiStack_b8 + 2);
        uStack_24 = CONCAT31(uStack_24._1_3_,9);
        FUN_0046bec5(local_c4 + 2);
        uStack_24 = 0xffffffff;
        FUN_0046bec5((int *)&pvStack_d8);
        iVar6 = uVar2 * 0x10;
        FUN_00413d00(local_c4,*(int *)(&DAT_004a6bb4 + iVar6) / 100);
        uStack_24 = 0xe;
        (*pcVar1)();
        uStack_34 = 0xffffffff;
        FUN_0046bec5(&local_d4);
        if ((0 < *(int *)(&DAT_004a6bb8 + iVar6)) && (1 < DAT_004ac944)) {
          iStack_124 = 0x41c4e9;
          FUN_00413d00(local_c4,*(int *)(&DAT_004a6bb8 + iVar6) / 100);
          uStack_34 = 0xf;
          iStack_12c = 0x41c514;
          iStack_124 = iVar7;
          (*pcVar1)();
          uStack_34 = 0xffffffff;
          FUN_0046bec5(local_c4);
        }
        if (0 < *(int *)(&DAT_004a6bbc + iVar6)) {
          iStack_124 = 0x41c54e;
          FUN_00413d00(&stack0xffffff20,*(int *)(&DAT_004a6bbc + iVar6) / 100);
          uStack_34 = 0x10;
          iStack_12c = 0x41c579;
          iStack_124 = iVar7;
          (*pcVar1)();
          uStack_34 = 0xffffffff;
          FUN_0046bec5((int *)&stack0xffffff20);
        }
        iStack_124 = 0x41c5b1;
        FUN_00413d00(&local_c8,*(int *)((int)aiStack_b8 + (int)pvStack_d8) / 100);
        uStack_34 = 0x11;
        iStack_12c = 0x41c5d6;
        iStack_124 = iVar7;
        (*pcVar1)();
        uStack_14 = 0xffffffff;
        FUN_0046bec5(aiStack_a8);
        iVar7 = iVar7 + local_d0;
        if (uVar9 == 0xf) {
          unaff_EBP = DAT_004a763c / 2 + -10;
          iVar7 = local_d4;
        }
        uVar9 = uVar9 + 1;
      } while ((int)uVar9 <= DAT_0049118c);
    }
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*param_1 + 0x38))();
  }
  iVar6 = local_d0;
  local_d4 = local_d0 * 8;
  iVar7 = (DAT_004a72d0 * 6) / 7 + local_d0 * -8 + 10;
  FUN_0046bf33(&stack0xffffff18,s_Movement_suspended__Click_mouse_o_004918bc);
  uStack_14 = 0x12;
  iStack_108 = 10;
  piStack_104 = (int *)iVar7;
  (*pcVar1)();
  uStack_24 = 0xffffffff;
  FUN_0046bec5(aiStack_f8);
  iVar7 = iVar7 + iVar6 * 2;
  if (DAT_004ac9bc == 1) {
    if (DAT_004a6dac != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a6dac);
    }
    Rectangle((HDC)param_1[1],0,iVar7 + -4,DAT_004a763c,DAT_004a72d0);
    iVar6 = *param_1;
    (**(code **)(iVar6 + 0x34))();
    pcVar3 = *(code **)(iVar6 + 0x38);
    (*pcVar3)();
    FUN_0046bf33(&stack0xffffff00,s_Mainsail_colors__0049306c);
    uStack_2c = 0x13;
    iVar6 = *(int *)(unaff_EDI + -8);
    iStack_124 = 0x41c73d;
    (*pcVar1)();
    uStack_3c = 0xffffffff;
    iStack_124 = 0x41c751;
    FUN_0046bec5((int *)&stack0xfffffef0);
    iStack_124 = 0xffff;
    iVar7 = iVar7 + aiStack_f8[0];
    (*pcVar3)();
    iStack_12c = 0x41c76e;
    FUN_0046bf33(&stack0xfffffeec,s_Boat_1__yellow_0049305c);
    iStack_12c = iVar6;
    uStack_40 = 0x14;
    iVar6 = *(int *)(iStack_12c + -8);
    aiStack_138[1] = 10;
    aiStack_138[0] = 0x41c789;
    aiStack_138[2] = iVar7;
    (*pcVar1)();
    uStack_50 = 0xffffffff;
    aiStack_138[0] = 0x41c79d;
    FUN_0046bec5(&iStack_124);
    aiStack_138[0] = 0xff00;
    (*pcVar3)();
    iStack_140 = 0x41c7b4;
    FUN_0046bf33(&stack0xfffffed8,s_Boat_2__green_0049304c);
    iStack_140 = iVar6;
    uStack_54 = 0x15;
    iVar6 = *(int *)(iStack_140 + -8);
    iStack_148 = DAT_004a763c / 5 + 10;
    iStack_14c = 0x41c7e6;
    iStack_144 = iVar7;
    (*pcVar1)();
    uStack_64 = 0xffffffff;
    iStack_14c = 0x41c7fa;
    FUN_0046bec5(aiStack_138);
    iStack_14c = 0xffffff;
    (*pcVar3)();
    iStack_154 = 0x41c811;
    FUN_0046bf33(&stack0xfffffec4,s_Boats_3_10___white_00493038);
    iStack_154 = iVar6;
    uStack_68 = 0x16;
    iVar6 = *(int *)(iStack_154 + -8);
    iStack_15c = (DAT_004a763c * 2) / 5 + 10;
    pcStack_160 = (code *)0x41c845;
    iStack_158 = iVar7;
    (*pcVar1)();
    uStack_78 = 0xffffffff;
    pcStack_160 = (code *)0x41c859;
    FUN_0046bec5(&iStack_14c);
    pcStack_160 = (code *)0x7f7f7f;
    (*pcVar3)();
    iStack_168 = 0x41c870;
    FUN_0046bf33(&stack0xfffffeb0,s_Boats_11_20__gray_00493024);
    iStack_168 = iVar6;
    uStack_7c = 0x17;
    iVar6 = *(int *)(iStack_168 + -8);
    iStack_170 = (DAT_004a763c * 3) / 5 + 10;
    iStack_174 = 0x41c8a4;
    iStack_16c = iVar7;
    (*pcVar1)();
    aiStack_94[2] = 0xffffffff;
    iStack_174 = 0x41c8b8;
    FUN_0046bec5((int *)&pcStack_160);
    iStack_174 = 0xff0000;
    (*pcVar3)();
    FUN_0046bf33(&stack0xfffffe9c,s_Boats_21_30__blue_00493010);
    aiStack_94[1] = 0x18;
    (*pcVar1)((DAT_004a763c * 4) / 5 + 10,iVar7,iVar6,*(undefined4 *)(iVar6 + -8));
    uStack_a0 = 0xffffffff;
    FUN_0046bec5(&iStack_174);
    (*pcStack_160)(0xffffff);
  }
  *unaff_FS_OFFSET = uStack_2c;
  return;
}

