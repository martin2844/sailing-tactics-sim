
void __cdecl
FUN_0040db30(CDC *param_1,int param_2,int param_3,int param_4,undefined *param_5,int param_6)

{
  code *pcVar1;
  undefined *puVar2;
  code *unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  code *pcVar13;
  char *pcVar14;
  code *pcVar15;
  code *pcVar16;
  int iVar17;
  code *pcVar18;
  code *pcStack_30;
  code *pcStack_2c;
  code *local_18;
  code *pcStack_14;
  code *pcStack_c;
  code *pcStack_8;
  code *pcStack_4;
  
  iVar11 = DAT_004a763c;
  pcStack_c = (code *)*unaff_FS_OFFSET;
  pcStack_4 = (code *)0xffffffff;
  pcStack_8 = FUN_0047dca8;
  *unaff_FS_OFFSET = (int)&pcStack_c;
  if ((iVar11 < 700) || ((iVar11 < 900 && (0 < DAT_004a5264)))) {
    local_18 = (code *)0x1;
  }
  else {
    local_18 = (code *)0x0;
  }
  puVar2 = param_5;
  if ((DAT_004ac9c8 == 1) && (*(int *)(&DAT_004a4e88 + param_6 * 4) < 3)) {
    puVar2 = (undefined *)((param_4 + param_2 * 6) / 7);
  }
  pcStack_2c = (code *)0x7f7f7f;
  pcStack_30 = (code *)0x40dbcb;
  (**(code **)(*(int *)param_1 + 0x34))();
  pcVar8 = (code *)(param_2 + 1);
  if ((DAT_004a8914 == 1) || (DAT_004a4dfc == -1)) {
    pcStack_30 = (code *)0x0;
    param_5 = *(undefined **)(*(int *)param_1 + 0x38);
  }
  else {
    param_5 = *(undefined **)(*(int *)param_1 + 0x38);
    if (DAT_004ac92c == 0) {
      pcStack_30 = (code *)0xffff;
    }
    else {
      pcStack_30 = (code *)0xffffff;
    }
  }
  (*(code *)param_5)();
  pcVar7 = pcVar8 + (int)param_5;
  FUN_0044d990((int *)param_1,param_2,(int)pcVar8,(int)puVar2,pcVar7,1);
  FUN_0046bf33(&param_3,&DAT_00491c68);
  iVar11 = param_2 + 4;
  pcStack_c = (code *)0x0;
  iVar12 = *(int *)(param_3 + -8);
  pcVar18 = pcVar8;
  (**(code **)(*(int *)param_1 + 100))();
  FUN_0046bec5((int *)&pcStack_4);
  iVar17 = 6;
  pcStack_4 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcStack_4)();
  FUN_004706bd(param_1,(int *)&pcStack_30,param_2 + 1,(int)pcVar8);
  CDC::LineTo(param_1,(int)puVar2,(int)pcVar8);
  FUN_0044d990((int *)param_1,param_2,(int)pcVar8,(int)puVar2,pcStack_14,0);
  if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) && ((int)pcVar8 < DAT_004aa97c))
     && (DAT_004aa97c < (int)pcStack_14)) {
    DAT_004a4dfc = -1;
    DAT_004abf9c = 0;
    DAT_004ac1ec = 0;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
  }
  if (((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) &&
     (((int)pcVar8 < DAT_004ac9e4 && (DAT_004ac9e4 < (int)pcStack_14)))) {
    if (iVar12 == 0) {
      pcVar14 = s_Sail_a_closehauled_angle_to_the_w_004920d4;
    }
    else {
      pcVar14 = s_Sail_closehauled__004920c0;
    }
    FUN_0046c00d(&DAT_004a7048,pcVar14);
    DAT_004ac9dc = 1;
  }
  pcVar8 = pcStack_14;
  if (((DAT_004a4dfc == 1) || (DAT_004abf9c == 1)) ||
     (((*pcStack_4)(), DAT_004ac92c == 0 && (0x59 < DAT_004a7bcc)))) {
    (*pcStack_4)();
  }
  pcStack_14 = pcVar7 + (int)pcStack_14;
  FUN_0044d990((int *)param_1,param_2,(int)pcVar8,(int)puVar2,pcStack_14,1);
  if (DAT_004a7bcc < 0x5a) {
    FUN_0046bf33(&local_18,&DAT_00491c60);
    pcVar7 = (code *)(param_2 + 4);
    pcVar10 = local_18;
    (*pcStack_c)();
    pcStack_30 = (code *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffd8);
    if (((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) &&
       (((int)pcVar8 < DAT_004aa97c && (DAT_004aa97c < (int)unaff_ESI)))) {
      DAT_004a4dfc = 1;
      DAT_004abf9c = 0;
      DAT_004a46ac = 1;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a41f4 = DAT_004a5b80;
      DAT_004a684c = 0;
    }
    if ((((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) && ((int)pcVar8 < DAT_004ac9e4))
       && (DAT_004ac9e4 < (int)unaff_ESI)) {
      if (iVar17 == 0) {
        pcVar14 = s_Tack_and_follow_a_closehauled_co_00492098;
      }
      else {
        pcVar14 = s_Tack_and_sail_closehauled__0049207c;
      }
LAB_0040df4e:
      FUN_0046c00d(&DAT_004a7048,pcVar14);
      DAT_004ac9dc = 1;
    }
  }
  else {
    FUN_0046bf33(&local_18,&DAT_00491c58);
    pcVar7 = (code *)(param_2 + 4);
    pcVar10 = local_18;
    (*pcStack_c)();
    pcStack_30 = (code *)0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffd8);
    if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) && ((int)pcVar8 < DAT_004aa97c))
       && (DAT_004aa97c < (int)unaff_ESI)) {
      DAT_004abf9c = 1;
      DAT_004a4dfc = 0;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
    if (((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) &&
       (((int)pcVar8 < DAT_004ac9e4 && (DAT_004ac9e4 < (int)unaff_ESI)))) {
      if (iVar17 == 0) {
        pcVar14 = s_Jibe_and_sail_a_good_downwind_an_00492054;
      }
      else {
        pcVar14 = s_Jibe_and_sail_a_downwind_angle__00492034;
      }
      goto LAB_0040df4e;
    }
  }
  iVar12 = 6;
  (*local_18)();
  FUN_004706bd(param_1,(int *)&stack0xffffffbc,param_2 + 1,(int)pcVar8);
  CDC::LineTo(param_1,(int)puVar2,(int)pcVar8);
  FUN_0044d990((int *)param_1,param_2,(int)pcVar8,(int)puVar2,unaff_EDI,0);
  (*local_18)();
  pcStack_2c = local_18 + unaff_EDI;
  FUN_0044d990((int *)param_1,param_2,unaff_EDI,(int)puVar2,pcStack_2c,1);
  FUN_0046bf33(&pcStack_30,s_reach_00491c50);
  pcVar8 = pcStack_30;
  (*unaff_ESI)();
  pcVar15 = (code *)0xffffffff;
  FUN_0046bec5((int *)&stack0xffffffc0);
  pcVar6 = (code *)&DAT_00000006;
  (*pcStack_30)();
  FUN_004706bd(param_1,(int *)&stack0xffffffa4,param_2 + 1,unaff_EDI);
  CDC::LineTo(param_1,(int)puVar2,unaff_EDI);
  FUN_0044d990((int *)param_1,param_2,unaff_EDI,(int)puVar2,iVar11,0);
  if (((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) &&
     ((unaff_EDI < DAT_004aa97c && (DAT_004aa97c < iVar11)))) {
    DAT_004a684c = (0x59 < DAT_004a7bcc) + 2;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  if (((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) &&
     ((unaff_EDI < DAT_004ac9e4 && (DAT_004ac9e4 < iVar11)))) {
    FUN_0046c00d(&DAT_004a7048,s_Turn_to_a_beam_reach__0049201c);
    DAT_004ac9dc = 1;
  }
  if ((DAT_004a684c == 1) || (DAT_004a496c == 1)) {
    iVar17 = 0;
  }
  else if (DAT_004ac92c == 0) {
    iVar17 = 0xffff00;
  }
  else {
    iVar17 = 0xffffff;
  }
  (*pcStack_30)();
  pcVar1 = pcStack_30 + iVar11;
  FUN_0044d990((int *)param_1,param_2,iVar11,(int)puVar2,pcVar1,1);
  FUN_0046bf33(&stack0xffffffb8,&DAT_00491c4c);
  pcVar13 = (code *)0x4;
  pcVar5 = *(code **)(pcVar15 + -8);
  pcVar4 = (code *)(param_2 + 4);
  pcVar16 = pcVar15;
  (*pcVar18)();
  iVar9 = -1;
  FUN_0046bec5((int *)&stack0xffffffa8);
  iVar3 = 6;
  (*pcVar16)();
  FUN_004706bd(param_1,(int *)&stack0xffffff8c,param_2 + 1,iVar11);
  CDC::LineTo(param_1,(int)puVar2,iVar11);
  FUN_0044d990((int *)param_1,param_2,iVar11,(int)puVar2,iVar12,0);
  if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) && (iVar11 < DAT_004aa97c)) &&
     (DAT_004aa97c < iVar12)) {
    DAT_004a684c = 1;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  if (((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) &&
     ((iVar11 < DAT_004ac9e4 && (DAT_004ac9e4 < iVar12)))) {
    if (pcVar5 == (code *)0x0) {
      pcVar14 = s_Sail_a_fast_downwind_angle__00492000;
    }
    else {
      pcVar14 = s_Sail_fast_downwind_angle__00491fe4;
    }
    FUN_0046c00d(&DAT_004a7048,pcVar14);
    DAT_004ac9dc = 1;
  }
  if ((0 < DAT_004a4388) || (iVar11 = 0, 0x5a < DAT_004a7bcc)) {
    iVar11 = 1;
  }
  pcVar1 = pcVar1 + iVar12;
  FUN_0044d990((int *)param_1,param_2,iVar12,(int)puVar2,pcVar1,1);
  if ((iVar11 == 0) || (DAT_004a5b80 < 1)) {
    if (DAT_004a85d4 < 0x32) {
      (*pcVar16)();
      FUN_0046bf33(&stack0xffffffa0,&DAT_00491c34);
      (*pcVar7)();
      FUN_0046bec5((int *)&stack0xffffffa0);
      if (((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) &&
         ((iVar12 < DAT_004aa97c && (DAT_004aa97c < iVar11)))) {
        DAT_004a85d4 = 0x5a;
        (*pcVar10)();
        FUN_0046bf33(&stack0xffffff9c,&DAT_00491c34);
        (*pcVar1)();
        FUN_0046bec5((int *)&stack0xffffffa0);
      }
      if ((((DAT_004ac9e0 <= param_2) || ((int)puVar2 <= DAT_004ac9e0)) || (DAT_004ac9e4 <= iVar12))
         || (iVar11 <= DAT_004ac9e4)) goto LAB_0040e61a;
      pcVar14 = s_Sheets_way_out__Kill_speed__00491f90;
    }
    else {
      (*pcVar16)();
      FUN_0046bf33(&stack0xffffffa0,&DAT_00491c30);
      (*pcVar7)();
      FUN_0046bec5((int *)&stack0xffffffa0);
      if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) && (iVar12 < DAT_004aa97c)) &&
         (DAT_004aa97c < iVar11)) {
        DAT_004a85d4 = -1;
        (*pcVar10)();
        FUN_0046bf33(&stack0xffffff9c,&DAT_00491c30);
        (*pcVar1)();
        FUN_0046bec5((int *)&stack0xffffffa0);
      }
      if (((DAT_004ac9e0 <= param_2) || ((int)puVar2 <= DAT_004ac9e0)) ||
         ((DAT_004ac9e4 <= iVar12 || (iVar11 <= DAT_004ac9e4)))) goto LAB_0040e61a;
      if (pcVar15 == (code *)0x0) {
        pcVar14 = s_Automatic_sheet_for_best_speed__00491f70;
      }
      else {
        pcVar14 = s_Auto_sheet_for_best_speed__00491f54;
      }
    }
  }
  else {
    (*pcVar16)();
    if (2 < DAT_00491188) {
      FUN_0046bf33(&stack0xffffffa0,&DAT_00491c44);
      (*pcVar7)();
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if (DAT_00491188 == 2) {
      FUN_0046bf33(&stack0xffffffa0,&DAT_00491c3c);
      (*pcVar7)();
      FUN_0046bec5((int *)&stack0xffffffa0);
    }
    if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) &&
        ((iVar12 < DAT_004aa97c && ((DAT_004aa97c < iVar11 && (1 < DAT_00491188)))))) &&
       (DAT_004a4388 = DAT_004a4388 + 1, 1 < DAT_004a4388)) {
      DAT_004a4388 = 0;
    }
    if ((((DAT_004ac9e0 <= param_2) || ((int)puVar2 <= DAT_004ac9e0)) || (DAT_004ac9e4 <= iVar12))
       || (iVar11 <= DAT_004ac9e4)) goto LAB_0040e61a;
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      if (DAT_004abb74 == 0) {
        pcVar14 = s_Set_spinnaker__00491fd4;
      }
      else {
        pcVar14 = s_Drop_spinnaker__00491fc4;
      }
      FUN_0046c00d(&DAT_004a7048,pcVar14);
      DAT_004ac9dc = 1;
    }
    if ((DAT_00491188 != 2) && (DAT_00491188 != 9)) goto LAB_0040e61a;
    if (DAT_004abb74 == 0) {
      pcVar14 = s_Wing_jib__00491fb8;
    }
    else {
      pcVar14 = s_Unwing_jib__00491fac;
    }
  }
  FUN_0046c00d(&DAT_004a7048,pcVar14);
  DAT_004ac9dc = 1;
LAB_0040e61a:
  if (DAT_004ac92c == 0) {
    (*pcVar10)();
  }
  (*pcVar13)();
  FUN_004706bd(param_1,(int *)&stack0xffffff84,param_2 + 1,iVar12);
  CDC::LineTo(param_1,(int)puVar2,iVar12);
  FUN_0044d990((int *)param_1,param_2,iVar12,(int)puVar2,iVar9,0);
  pcVar10 = pcVar10 + iVar9;
  FUN_0044d990((int *)param_1,param_2,iVar9,(int)puVar2,pcVar10,1);
  FUN_0046bf33(&stack0xffffff9c,s_shape_00491c28);
  pcVar7 = (code *)0xb;
  iVar11 = iVar9;
  (*pcVar1)();
  iVar12 = -1;
  FUN_0046bec5((int *)&stack0xffffff8c);
  (*pcVar8)();
  FUN_004706bd(param_1,(int *)&stack0xffffff70,param_2 + 1,iVar9);
  CDC::LineTo(param_1,(int)puVar2,iVar9);
  FUN_0044d990((int *)param_1,param_2,iVar9,(int)puVar2,iVar17,0);
  if ((((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) && (iVar9 < DAT_004aa97c)) &&
     (DAT_004aa97c < iVar17)) {
    DAT_004a776c = DAT_004a776c + 1;
    if (3 < DAT_004a776c) {
      DAT_004a776c = 1;
    }
    (*pcVar8)(0);
    FUN_0046bf33(&stack0xffffff84,s_shape_00491c28);
    pcVar4 = (code *)0xc;
    (*pcVar6)(param_2 + 4,iVar9,iVar12,*(undefined4 *)(iVar12 + -8));
    FUN_0046bec5((int *)&stack0xffffff88);
  }
  if (((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) &&
     ((iVar9 < DAT_004ac9e4 && (DAT_004ac9e4 < iVar17)))) {
    if (DAT_004a776c == 1) {
      FUN_0046c00d(&DAT_004a7048,s_Change_draft_to_medium_00491f3c);
    }
    if (DAT_004a776c == 2) {
      FUN_0046c00d(&DAT_004a7048,s_Change_draft_to_baggy_00491f24);
    }
    if (DAT_004a776c == 3) {
      FUN_0046c00d(&DAT_004a7048,s_Change_draft_to_flat_00491f0c);
    }
    DAT_004ac9dc = 1;
  }
  if (DAT_004ac92c == 0) {
    (*pcVar8)(0xffff00);
  }
  FUN_0044d990((int *)param_1,param_2,iVar17,(int)puVar2,pcVar10 + iVar17,1);
  FUN_0046bf33(&stack0xffffffa0,&DAT_00491c20);
  (*pcVar7)(param_2 + 4,iVar17,pcVar10,*(undefined4 *)(pcVar10 + -8));
  FUN_0046bec5((int *)&stack0xffffff90);
  (*pcVar5)(6);
  FUN_004706bd(param_1,(int *)&stack0xffffff5c,param_2 + 1,iVar17);
  CDC::LineTo(param_1,(int)puVar2,iVar17);
  FUN_0044d990((int *)param_1,param_2,iVar17,(int)puVar2,iVar3,0);
  if (((param_2 < DAT_004a774c) && (DAT_004a774c < (int)puVar2)) &&
     ((iVar17 < DAT_004aa97c && (DAT_004aa97c < iVar3)))) {
    DAT_004a4e8c = DAT_004a4e8c + 1;
    if (3 < DAT_004a4e8c) {
      DAT_004a4e8c = 1;
    }
    DAT_004aae24 = 0;
    (*pcVar5)(0);
    FUN_0046bf33(&stack0xffffff88,&DAT_00491c20);
    (*pcVar4)(param_2 + 4,iVar17,pcVar5,*(undefined4 *)(pcVar5 + -8));
    FUN_0046bec5((int *)&stack0xffffff8c);
  }
  if ((((param_2 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)puVar2)) && (iVar17 < DAT_004ac9e4)) &&
     (DAT_004ac9e4 < iVar3)) {
    if (DAT_004a4e8c == 1) {
      FUN_0046c00d(&DAT_004a7048,s_Change_3D_view_to_wide__00491ef4);
    }
    if (DAT_004a4e8c == 2) {
      FUN_0046c00d(&DAT_004a7048,s_Change_3D_view_to_high__00491edc);
    }
    if (DAT_004a4e8c == 3) {
      FUN_0046c00d(&DAT_004a7048,s_Change_3D_view_to_close_in__00491ec0);
    }
    DAT_004ac9dc = 1;
  }
  DAT_004aa97c = 0;
  *unaff_FS_OFFSET = iVar11;
  return;
}

