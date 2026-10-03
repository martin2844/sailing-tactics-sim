
void __cdecl
FUN_0040db30(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  bool bVar2;
  int this;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar5;
  char *pcVar6;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = param_2;
  this = param_1;
  iVar4 = DAT_004a763c;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047dca8;
  *unaff_FS_OFFSET = &uStack_c;
  if ((iVar4 < 700) || ((iVar4 < 900 && (0 < DAT_004a5264)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  iVar4 = param_5;
  if ((DAT_004ac9c8 == 1) && (*(int *)(&DAT_004a4e88 + param_6 * 4) < 3)) {
    iVar4 = (param_4 + param_2 * 6) / 7;
  }
  (**(code **)(*(int *)param_1 + 0x34))((void *)param_1,0x7f7f7f);
  iVar1 = param_3 + 1;
  if ((DAT_004a8914 == 1) || (DAT_004a4dfc == -1)) {
    CVar5 = 0;
    param_6 = *(int *)(*(int *)this + 0x38);
  }
  else {
    param_6 = *(int *)(*(int *)this + 0x38);
    if (DAT_004ac92c == 0) {
      CVar5 = 0xffff;
    }
    else {
      CVar5 = 0xffffff;
    }
  }
  (*(code *)param_6)((void *)this,CVar5);
  param_2 = iVar1 + param_7;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  FUN_0046bf33(&param_5,&DAT_00491c68);
  uStack_4 = 0;
  param_4 = *(undefined4 *)(*(int *)this + 100);
  (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_5,*(int *)(param_5 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_5);
  param_5 = *(undefined4 *)(*(int *)this + 0x2c);
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) && (iVar1 < DAT_004aa97c)) &&
     (DAT_004aa97c < param_2)) {
    DAT_004a4dfc = -1;
    DAT_004abf9c = 0;
    DAT_004ac1ec = 0;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
  }
  if (((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) &&
     ((iVar1 < DAT_004ac9e4 && (DAT_004ac9e4 < param_2)))) {
    if (bVar2) {
      pcVar6 = s_Sail_closehauled__004920c0;
    }
    else {
      pcVar6 = s_Sail_a_closehauled_angle_to_the_w_004920d4;
    }
    FUN_0046c00d(&DAT_004a7048,pcVar6);
    DAT_004ac9dc = 1;
  }
  iVar1 = param_2;
  if ((DAT_004a4dfc == 1) || (DAT_004abf9c == 1)) {
    CVar5 = 0;
LAB_0040dd9a:
    (*(code *)param_6)((void *)this,CVar5);
  }
  else {
    if ((DAT_004ac92c == 0) && (DAT_004a7bcc < 0x5a)) {
      CVar5 = 0xffff;
    }
    else {
      CVar5 = 0xffffff;
    }
    (*(code *)param_6)((void *)this,CVar5);
    if ((DAT_004ac92c == 0) && (0x59 < DAT_004a7bcc)) {
      CVar5 = 0xff00;
      goto LAB_0040dd9a;
    }
  }
  param_2 = iVar1 + param_7;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  if (DAT_004a7bcc < 0x5a) {
    FUN_0046bf33(&param_1,&DAT_00491c60);
    uStack_4 = 1;
    (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    if (((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
       ((iVar1 < DAT_004aa97c && (DAT_004aa97c < param_2)))) {
      DAT_004a4dfc = 1;
      DAT_004abf9c = 0;
      DAT_004a46ac = 1;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a41f4 = DAT_004a5b80;
      DAT_004a684c = 0;
    }
    if ((((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) && (iVar1 < DAT_004ac9e4)) &&
       (DAT_004ac9e4 < param_2)) {
      if (bVar2) {
        pcVar6 = s_Tack_and_sail_closehauled__0049207c;
      }
      else {
        pcVar6 = s_Tack_and_follow_a_closehauled_co_00492098;
      }
LAB_0040df4e:
      FUN_0046c00d(&DAT_004a7048,pcVar6);
      DAT_004ac9dc = 1;
    }
  }
  else {
    FUN_0046bf33(&param_1,&DAT_00491c58);
    uStack_4 = 2;
    (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
    if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) && (iVar1 < DAT_004aa97c)) &&
       (DAT_004aa97c < param_2)) {
      DAT_004abf9c = 1;
      DAT_004a4dfc = 0;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
    if (((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) &&
       ((iVar1 < DAT_004ac9e4 && (DAT_004ac9e4 < param_2)))) {
      if (bVar2) {
        pcVar6 = s_Jibe_and_sail_a_downwind_angle__00492034;
      }
      else {
        pcVar6 = s_Jibe_and_sail_a_good_downwind_an_00492054;
      }
      goto LAB_0040df4e;
    }
  }
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  iVar1 = param_2;
  if (DAT_004a684c < 2) {
    if (DAT_004ac92c == 0) {
      CVar5 = 0xffff00;
    }
    else {
      CVar5 = 0xffffff;
    }
  }
  else {
    CVar5 = 0;
  }
  (*(code *)param_6)((void *)this,CVar5);
  param_2 = iVar1 + param_7;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  FUN_0046bf33(&param_1,s_reach_00491c50);
  uStack_4 = 3;
  (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  if (((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
     ((iVar1 < DAT_004aa97c && (DAT_004aa97c < param_2)))) {
    DAT_004a684c = (0x59 < DAT_004a7bcc) + 2;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  if (((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) &&
     ((iVar1 < DAT_004ac9e4 && (DAT_004ac9e4 < param_2)))) {
    FUN_0046c00d(&DAT_004a7048,s_Turn_to_a_beam_reach__0049201c);
    DAT_004ac9dc = 1;
  }
  iVar1 = param_2;
  if ((DAT_004a684c == 1) || (DAT_004a496c == 1)) {
    CVar5 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar5 = 0xffff00;
  }
  else {
    CVar5 = 0xffffff;
  }
  (*(code *)param_6)((void *)this,CVar5);
  param_2 = param_7 + iVar1;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  FUN_0046bf33(&param_1,&DAT_00491c4c);
  uStack_4 = 4;
  (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) && (iVar1 < DAT_004aa97c)) &&
     (DAT_004aa97c < param_2)) {
    DAT_004a684c = 1;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  if (((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) &&
     ((iVar1 < DAT_004ac9e4 && (DAT_004ac9e4 < param_2)))) {
    if (bVar2) {
      pcVar6 = s_Sail_fast_downwind_angle__00491fe4;
    }
    else {
      pcVar6 = s_Sail_a_fast_downwind_angle__00492000;
    }
    FUN_0046c00d(&DAT_004a7048,pcVar6);
    DAT_004ac9dc = 1;
  }
  iVar1 = param_2;
  if ((0 < DAT_004a4388) || (param_1 = 0, 0x5a < DAT_004a7bcc)) {
    param_1 = 1;
  }
  param_2 = param_2 + param_7;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  if ((param_1 == 0) || (DAT_004a5b80 < 1)) {
    if (DAT_004a85d4 < 0x32) {
      if (DAT_004ac92c == 0) {
        CVar5 = 0x7f;
      }
      else {
        CVar5 = 0xffffff;
      }
      (*(code *)param_6)((void *)this,CVar5);
      FUN_0046bf33(&param_1,&DAT_00491c34);
      uStack_4 = 5;
      (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
      if (((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
         ((iVar1 < DAT_004aa97c && (DAT_004aa97c < param_2)))) {
        DAT_004a85d4 = 0x5a;
        (*(code *)param_6)((void *)this,0);
        FUN_0046bf33(&param_1,&DAT_00491c34);
        uStack_4 = 6;
        (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_1);
      }
      if ((((DAT_004ac9e0 <= iVar3) || (iVar4 <= DAT_004ac9e0)) || (DAT_004ac9e4 <= iVar1)) ||
         (param_2 <= DAT_004ac9e4)) goto LAB_0040e61a;
      pcVar6 = s_Sheets_way_out__Kill_speed__00491f90;
    }
    else {
      if (DAT_004ac92c == 0) {
        CVar5 = 0xff00;
      }
      else {
        CVar5 = 0xffffff;
      }
      (*(code *)param_6)((void *)this,CVar5);
      FUN_0046bf33(&param_1,&DAT_00491c30);
      uStack_4 = 7;
      (*(code *)param_4)((void *)this,iVar3 + 1,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
      if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) && (iVar1 < DAT_004aa97c)) &&
         (DAT_004aa97c < param_2)) {
        DAT_004a85d4 = -1;
        (*(code *)param_6)((void *)this,0);
        FUN_0046bf33(&param_1,&DAT_00491c30);
        uStack_4 = 8;
        (*(code *)param_4)((void *)this,iVar3 + 1,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_1);
      }
      if (((DAT_004ac9e0 <= iVar3) || (iVar4 <= DAT_004ac9e0)) ||
         ((DAT_004ac9e4 <= iVar1 || (param_2 <= DAT_004ac9e4)))) goto LAB_0040e61a;
      if (bVar2) {
        pcVar6 = s_Auto_sheet_for_best_speed__00491f54;
      }
      else {
        pcVar6 = s_Automatic_sheet_for_best_speed__00491f70;
      }
    }
  }
  else {
    if (DAT_004abb74 == 1) {
      CVar5 = 0;
    }
    else if (DAT_004ac92c == 0) {
      CVar5 = 0xffff;
    }
    else {
      CVar5 = 0xffffff;
    }
    (*(code *)param_6)((void *)this,CVar5);
    if (2 < DAT_00491188) {
      FUN_0046bf33(&param_1,&DAT_00491c44);
      uStack_4 = 9;
      (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
    }
    if (DAT_00491188 == 2) {
      FUN_0046bf33(&param_1,&DAT_00491c3c);
      uStack_4 = 10;
      (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
    }
    if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
        ((iVar1 < DAT_004aa97c && ((DAT_004aa97c < param_2 && (1 < DAT_00491188)))))) &&
       (DAT_004a4388 = DAT_004a4388 + 1, 1 < DAT_004a4388)) {
      DAT_004a4388 = 0;
    }
    if ((((DAT_004ac9e0 <= iVar3) || (iVar4 <= DAT_004ac9e0)) || (DAT_004ac9e4 <= iVar1)) ||
       (param_2 <= DAT_004ac9e4)) goto LAB_0040e61a;
    if ((2 < DAT_00491188) && (DAT_00491188 != 9)) {
      if (DAT_004abb74 == 0) {
        pcVar6 = s_Set_spinnaker__00491fd4;
      }
      else {
        pcVar6 = s_Drop_spinnaker__00491fc4;
      }
      FUN_0046c00d(&DAT_004a7048,pcVar6);
      DAT_004ac9dc = 1;
    }
    if ((DAT_00491188 != 2) && (DAT_00491188 != 9)) goto LAB_0040e61a;
    if (DAT_004abb74 == 0) {
      pcVar6 = s_Wing_jib__00491fb8;
    }
    else {
      pcVar6 = s_Unwing_jib__00491fac;
    }
  }
  FUN_0046c00d(&DAT_004a7048,pcVar6);
  DAT_004ac9dc = 1;
LAB_0040e61a:
  if (DAT_004ac92c == 0) {
    (*(code *)param_6)((void *)this,0xffffff);
  }
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  iVar1 = param_2;
  param_2 = param_2 + param_7;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  FUN_0046bf33(&param_1,s_shape_00491c28);
  uStack_4 = 0xb;
  (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_1);
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  if ((((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) && (iVar1 < DAT_004aa97c)) &&
     (DAT_004aa97c < param_2)) {
    DAT_004a776c = DAT_004a776c + 1;
    if (3 < DAT_004a776c) {
      DAT_004a776c = 1;
    }
    (*(code *)param_6)((void *)this,0);
    FUN_0046bf33(&param_1,s_shape_00491c28);
    uStack_4 = 0xc;
    (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_1,*(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_1);
  }
  if (((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) &&
     ((iVar1 < DAT_004ac9e4 && (DAT_004ac9e4 < param_2)))) {
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
  iVar1 = param_2;
  if (DAT_004ac92c == 0) {
    (*(code *)param_6)((void *)this,0xffff00);
  }
  param_2 = param_7 + iVar1;
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,1,1);
  FUN_0046bf33(&param_7,&DAT_00491c20);
  uStack_4 = 0xd;
  (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_7);
  (*(code *)param_5)((void *)this,6);
  FUN_004706bd((void *)this,aiStack_14,iVar3 + 1,iVar1);
  CDC::LineTo((CDC *)this,iVar4,iVar1);
  FUN_0044d990(this,iVar3,iVar1,iVar4,param_2,0,1);
  if (((iVar3 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
     ((iVar1 < DAT_004aa97c && (DAT_004aa97c < param_2)))) {
    DAT_004a4e8c = DAT_004a4e8c + 1;
    if (3 < DAT_004a4e8c) {
      DAT_004a4e8c = 1;
    }
    DAT_004aae24 = 0;
    (*(code *)param_6)((void *)this,0);
    FUN_0046bf33(&param_7,&DAT_00491c20);
    uStack_4 = 0xe;
    (*(code *)param_4)((void *)this,iVar3 + 4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_7);
  }
  if ((((iVar3 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar4)) && (iVar1 < DAT_004ac9e4)) &&
     (DAT_004ac9e4 < param_2)) {
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
  *unaff_FS_OFFSET = uStack_c;
  return;
}

