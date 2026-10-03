
void __cdecl
FUN_004118b0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  bool bVar2;
  int *original_dc;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  char *pcVar6;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_2;
  original_dc = param_1;
  iVar3 = DAT_004fe624;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2608;
  *unaff_FS_OFFSET = &uStack_c;
  if ((iVar3 < 700) || ((iVar3 < 900 && (0 < DAT_004f82fc)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  iVar3 = param_5;
  if ((DAT_004da1a8 == 1) && (*(int *)(&DAT_004f71c0 + param_6 * 4) < 3)) {
    iVar3 = (param_4 + param_2 * 6) / 7;
  }
  (**(code **)(*param_1 + 0x34))(param_1,0x7f7f7f);
  iVar4 = param_3 + 1;
  if ((DAT_00511624 == 1) || (DAT_004f7094 == -1)) {
    iVar5 = 0;
    param_6 = *(int *)(*original_dc + 0x38);
  }
  else {
    param_6 = *(int *)(*original_dc + 0x38);
    if (DAT_005363e4 == 0) {
      iVar5 = 0xffff;
    }
    else {
      iVar5 = 0xffffff;
    }
  }
  (*(code *)param_6)(original_dc,iVar5);
  param_2 = iVar4 + param_7;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  FUN_004b0613((Tact2010CString *)&param_5,&DAT_004daf5c);
  uStack_4 = 0;
  param_4 = *(undefined4 *)(*original_dc + 100);
  (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_5,*(int *)(param_5 + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_5);
  param_5 = *(undefined4 *)(*original_dc + 0x2c);
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  if ((((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar4 < DAT_005233a4)) &&
     (DAT_005233a4 < param_2)) {
    DAT_004f7094 = -1;
    DAT_005356b4 = 0;
    DAT_005359e4 = 0;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004fbbac = 0;
    DAT_005233a4 = 0;
  }
  if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
     ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
    if (bVar2) {
      pcVar6 = s_Sail_closehauled__004db5bc;
    }
    else {
      pcVar6 = s_Sail_a_closehauled_angle_to_the_w_004db5d0;
    }
    FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
    DAT_0053649c = 1;
  }
  iVar4 = param_2;
  if ((DAT_004f7094 == 1) || (DAT_005356b4 == 1)) {
    iVar5 = 0;
LAB_00411b1f:
    (*(code *)param_6)(original_dc,iVar5);
  }
  else {
    if ((DAT_005363e4 == 0) && (DAT_004feccc < 0x5a)) {
      iVar5 = 0xffff;
    }
    else {
      iVar5 = 0xffffff;
    }
    (*(code *)param_6)(original_dc,iVar5);
    if ((DAT_005363e4 == 0) && (0x59 < DAT_004feccc)) {
      iVar5 = 0xff00;
      goto LAB_00411b1f;
    }
  }
  param_2 = iVar4 + param_7;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  if (DAT_004feccc < 0x5a) {
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daf54);
    uStack_4 = 1;
    (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
       ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
      DAT_004f7094 = 1;
      DAT_005356b4 = 0;
      DAT_004f4a74 = 1;
      DAT_00511624 = 0;
      DAT_004f6a6c = 0;
      DAT_004f4354 = DAT_004f8cd0;
      DAT_004fbbac = 0;
      DAT_005233a4 = 0;
    }
    if ((((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) && (iVar4 < DAT_005364a4)) &&
       (DAT_005364a4 < param_2)) {
      if (bVar2) {
        pcVar6 = s_Tack_and_sail_closehauled__004db578;
      }
      else {
        pcVar6 = s_Tack_and_follow_a_closehauled_co_004db594;
      }
LAB_00411cde:
      FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
      DAT_0053649c = 1;
    }
  }
  else {
    FUN_004b0613((Tact2010CString *)&param_1,s_jibe_004daf4c);
    uStack_4 = 2;
    (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    if ((((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar4 < DAT_005233a4)) &&
       (DAT_005233a4 < param_2)) {
      DAT_005356b4 = 1;
      DAT_004f7094 = 0;
      DAT_00511624 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
      DAT_005233a4 = 0;
    }
    if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
       ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
      if (bVar2) {
        pcVar6 = s_Jibe_and_sail_a_downwind_angle__004db530;
      }
      else {
        pcVar6 = s_Jibe_and_sail_a_good_downwind_an_004db550;
      }
      goto LAB_00411cde;
    }
  }
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  iVar4 = param_2;
  if (DAT_004fbbac < 2) {
    if (DAT_005363e4 == 0) {
      iVar5 = 0xffff00;
    }
    else {
      iVar5 = 0xffffff;
    }
  }
  else {
    iVar5 = 0;
  }
  (*(code *)param_6)(original_dc,iVar5);
  param_2 = iVar4 + param_7;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  FUN_004b0613((Tact2010CString *)&param_1,s_reach_004daf44);
  uStack_4 = 3;
  (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
     ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
    DAT_004fbbac = (0x59 < DAT_004feccc) + 2;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_005233a4 = 0;
  }
  if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
     ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Turn_to_a_beam_reach__004db518);
    DAT_0053649c = 1;
  }
  iVar4 = param_2;
  if ((DAT_004fbbac == 1) || (DAT_004f6a6c == 1)) {
    iVar5 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar5 = 0xffff00;
  }
  else {
    iVar5 = 0xffffff;
  }
  (*(code *)param_6)(original_dc,iVar5);
  param_2 = param_7 + iVar4;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daf40);
  uStack_4 = 4;
  (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  if ((((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar4 < DAT_005233a4)) &&
     (DAT_005233a4 < param_2)) {
    DAT_004fbbac = 1;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_005233a4 = 0;
    DAT_004f3f64 = 0;
  }
  if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
     ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
    if (bVar2) {
      pcVar6 = s_Sail_fast_downwind_angle__004db4e0;
    }
    else {
      pcVar6 = s_Sail_a_fast_downwind_angle__004db4fc;
    }
    FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
    DAT_0053649c = 1;
  }
  iVar4 = iVar4 + ((int)(param_7 * 5 + (param_7 * 5 >> 0x1f & 3U)) >> 2);
  if (((DAT_004f4520 < 1) && (DAT_004feccc < 0x5b)) || (param_1 = (int *)0x1, DAT_004da190 == 9)) {
    param_1 = (int *)0x0;
  }
  param_2 = iVar4 + param_7;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  if ((param_1 == (int *)0x0) || (DAT_004f8cd0 < 1)) {
    if (DAT_00500384 == -1) {
      (*(code *)param_6)(original_dc,0);
      FUN_004b0613((Tact2010CString *)&param_1,s_sheet_004daf28);
      uStack_4 = 5;
      (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
         ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
        DAT_00500384 = 0x5a;
        if (DAT_005363e4 == 0) {
          iVar5 = 0xff00;
        }
        else {
          iVar5 = 0xffffff;
        }
        (*(code *)param_6)(original_dc,iVar5);
        FUN_004b0613((Tact2010CString *)&param_1,s_sheet_004daf28);
        uStack_4 = 6;
        (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_005233a4 = 0;
      }
      if ((((DAT_005364a0 <= iVar1) || (iVar3 <= DAT_005364a0)) || (DAT_005364a4 <= iVar4)) ||
         (param_2 <= DAT_005364a4)) goto LAB_00412445;
      pcVar6 = s_Let_sheets_way_out__Kill_speed__004db488;
    }
    else {
      if (DAT_005363e4 == 0) {
        iVar5 = 0xff00;
      }
      else {
        iVar5 = 0xffffff;
      }
      (*(code *)param_6)(original_dc,iVar5);
      FUN_004b0613((Tact2010CString *)&param_1,s_sheet_004daf28);
      uStack_4 = 7;
      (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      if ((((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar4 < DAT_005233a4)) &&
         (DAT_005233a4 < param_2)) {
        DAT_00500384 = -1;
        (*(code *)param_6)(original_dc,0);
        FUN_004b0613((Tact2010CString *)&param_1,s_sheet_004daf28);
        uStack_4 = 8;
        (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
        DAT_005233a4 = 0;
      }
      if (((DAT_005364a0 <= iVar1) || (iVar3 <= DAT_005364a0)) ||
         ((DAT_005364a4 <= iVar4 || (param_2 <= DAT_005364a4)))) goto LAB_00412445;
      if (bVar2) {
        pcVar6 = s_Auto_sheet_for_best_speed__004db44c;
      }
      else {
        pcVar6 = s_Automatic_sheet_for_best_speed__004db468;
      }
    }
  }
  else {
    if (DAT_005350dc == 1) {
      iVar5 = 0;
    }
    else if (DAT_005363e4 == 0) {
      iVar5 = 0xffff;
    }
    else {
      iVar5 = 0xffffff;
    }
    (*(code *)param_6)(original_dc,iVar5);
    if (((2 < DAT_004da190) && (DAT_005364bc == 0)) && ((DAT_005364c4 == 0 && (DAT_005364cc == 0))))
    {
      FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daf38);
      uStack_4 = 9;
      (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (((DAT_004da190 == 2) || (DAT_005364bc == 1)) || (DAT_005364c4 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daf30);
      uStack_4 = 10;
      (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if ((((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar4 < DAT_005233a4)) &&
       ((DAT_005233a4 < param_2 && (1 < DAT_004da190)))) {
      DAT_004f4520 = DAT_004f4520 + 1;
      if (1 < DAT_004f4520) {
        DAT_004f4520 = 0;
      }
      DAT_005233a4 = 0;
    }
    if (((DAT_005364a0 <= iVar1) || (iVar3 <= DAT_005364a0)) ||
       ((DAT_005364a4 <= iVar4 || (param_2 <= DAT_005364a4)))) goto LAB_00412445;
    if (((2 < DAT_004da190) && (DAT_005364c4 == 1)) && (DAT_005364bc == 1)) {
      if (DAT_005350dc == 0) {
        pcVar6 = s_Set_spinnaker__004db4d0;
      }
      else {
        pcVar6 = s_Drop_spinnaker__004db4c0;
      }
      FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
      DAT_0053649c = 1;
    }
    if (((DAT_004da190 != 2) && (DAT_005364c4 != 1)) && (DAT_005364bc != 1)) goto LAB_00412445;
    if (DAT_005350dc == 0) {
      pcVar6 = s_Wing_jib__004db4b4;
    }
    else {
      pcVar6 = s_Unwing_jib__004db4a8;
    }
  }
  FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
  DAT_0053649c = 1;
LAB_00412445:
  if (DAT_005363e4 == 0) {
    (*(code *)param_6)(original_dc,0xffffff);
  }
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  iVar4 = param_2;
  if (DAT_005364c8 == 0) {
    param_2 = param_2 + param_7;
    FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
    FUN_004b0613((Tact2010CString *)&param_1,s_shape_004daf20);
    uStack_4 = 0xb;
    (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    (*(code *)param_5)(original_dc,6);
    FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
    CDC::LineTo(original_dc,iVar3,iVar4);
    FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
    if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
       ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
      DAT_004fe77c = DAT_004fe77c + 1;
      if (3 < DAT_004fe77c) {
        DAT_004fe77c = 1;
      }
      DAT_005233a4 = 0;
      (*(code *)param_6)(original_dc,0);
      FUN_004b0613((Tact2010CString *)&param_1,s_shape_004daf20);
      uStack_4 = 0xc;
      (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if ((((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) && (iVar4 < DAT_005364a4)) &&
       (DAT_005364a4 < param_2)) {
      if (DAT_004fe77c == 1) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_draft_to_medium_004db434);
      }
      if (DAT_004fe77c == 2) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_draft_to_baggy_004db41c);
      }
      if (DAT_004fe77c == 3) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_draft_to_flat_004db404);
      }
      DAT_0053649c = 1;
    }
    if (DAT_005364c8 == 1) {
      FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
    }
  }
  iVar4 = iVar4 + param_7;
  if (DAT_005363e4 == 0) {
    (*(code *)param_6)(original_dc,0xffff00);
  }
  param_2 = iVar4 + param_7;
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
  FUN_004b0613((Tact2010CString *)&param_1,&DAT_004daf18);
  uStack_4 = 0xd;
  (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  (*(code *)param_5)(original_dc,6);
  FUN_004b4d9d(original_dc,aiStack_14,iVar1 + 1,iVar4);
  CDC::LineTo(original_dc,iVar3,iVar4);
  FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,0,1);
  if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
     ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
    DAT_004f71c4 = DAT_004f71c4 + 1;
    if (3 < DAT_004f71c4) {
      DAT_004f71c4 = 1;
    }
    DAT_00523a5c = 0;
    (*(code *)param_6)(original_dc,0);
    FUN_004b0613((Tact2010CString *)&param_5,&DAT_004daf18);
    uStack_4 = 0xe;
    (*(code *)param_4)(original_dc,iVar1 + 4,iVar4,(char *)param_5,*(int *)(param_5 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_5);
    DAT_005233a4 = 0;
  }
  if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
     ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
    if (DAT_004f71c4 == 1) {
      FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_3D_view_to_wide__004db3ec);
    }
    if (DAT_004f71c4 == 2) {
      FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_3D_view_to_high__004db3d4);
    }
    if (DAT_004f71c4 == 3) {
      FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Change_3D_view_to_close_in__004db3b8);
    }
    DAT_0053649c = 1;
  }
  if ((DAT_00511624 != 0) || (DAT_004f6a6c != 0)) {
    if (DAT_00511624 == 1) {
      iVar4 = iVar4 + (param_7 * 3) / 2;
      if (DAT_005363e4 == 0) {
        (*(code *)param_6)(original_dc,0xffff);
      }
      param_2 = param_7 + iVar4;
      FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
      FUN_004b0613((Tact2010CString *)&param_5,s_pinch_004daf10);
      uStack_4 = 0xf;
      (*(code *)param_4)(original_dc,iVar1 + 7,iVar4,(char *)param_5,*(int *)(param_5 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_5);
      if ((((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) && (iVar4 < DAT_005364a4)) &&
         (DAT_005364a4 < param_2)) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Sail_5_deg_higher_than_normal_be_004db390);
        DAT_0053649c = 1;
      }
      if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
         ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
        DAT_005359e4 = -5;
        DAT_005233a4 = 0;
        DAT_004f6a6c = 0;
        DAT_004fbbac = 0;
        DAT_004f7094 = 0;
        DAT_005356b4 = 0;
      }
      if (DAT_005359e4 == -5) {
        (*(code *)param_6)(original_dc,0);
        FUN_004b0613((Tact2010CString *)&param_5,s_pinch_004daf10);
        uStack_4 = 0x10;
        (*(code *)param_4)(original_dc,iVar1 + 7,iVar4,(char *)param_5,*(int *)(param_5 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_5);
      }
      if (DAT_005363e4 == 0) {
        (*(code *)param_6)(original_dc,0xffff);
      }
      param_5 = iVar3 * 2 - iVar1;
      FUN_00463f50(original_dc,iVar3 + 5,iVar4,param_5,param_2,1,1);
      FUN_004b0613((Tact2010CString *)&param_1,&DAT_004db388);
      uStack_4 = 0x11;
      (*(code *)param_4)(original_dc,iVar3 + 0xc,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
      if (((iVar3 + 5 < DAT_005364a0) && (DAT_005364a0 < param_5)) &&
         ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_Sail_5_deg_lower_than_normal_bea_004db360);
        DAT_0053649c = 1;
      }
      if ((((iVar3 + 5 < DAT_004fe75c) && (DAT_004fe75c < param_5)) && (iVar4 < DAT_005233a4)) &&
         (DAT_005233a4 < param_2)) {
        DAT_005359e4 = 5;
        DAT_005233a4 = 0;
        DAT_004f6a6c = 0;
        DAT_004fbbac = 0;
        DAT_004f7094 = 0;
        DAT_005356b4 = 0;
      }
      if (DAT_005359e4 == 5) {
        (*(code *)param_6)(original_dc,0);
        FUN_004b0613((Tact2010CString *)&param_2,&DAT_004db388);
        uStack_4 = 0x12;
        (*(code *)param_4)(original_dc,iVar3 + 0xc,iVar4,(char *)param_2,*(int *)(param_2 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
    }
    if (DAT_004f6a6c == 1) {
      iVar4 = iVar4 + (param_7 * 3) / 2;
      if (DAT_005363e4 == 0) {
        (*(code *)param_6)(original_dc,0xffff);
      }
      param_2 = iVar4 + param_7;
      FUN_00463f50(original_dc,iVar1,iVar4,iVar3,param_2,1,1);
      FUN_004b0613((Tact2010CString *)&param_7,&DAT_004daf00);
      uStack_4 = 0x13;
      (*(code *)param_4)(original_dc,iVar1 + 7,iVar4,(char *)param_7,*(int *)(param_7 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_7);
      if (((iVar1 < DAT_005364a0) && (DAT_005364a0 < iVar3)) &&
         ((iVar4 < DAT_005364a4 && (DAT_005364a4 < param_2)))) {
        if (DAT_004fe624 < 0x3e9) {
          pcVar6 = s_7_higher_than_normal_tacking_dow_004db30c;
        }
        else {
          pcVar6 = s_7_deg_higher_than_normal_tacking_004db334;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
        DAT_0053649c = 1;
      }
      if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
         ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
        DAT_004f3f64 = -7;
        DAT_005233a4 = 0;
        DAT_004f7094 = 0;
        DAT_005356b4 = 0;
      }
      if (DAT_004f3f64 == -7) {
        (*(code *)param_6)(original_dc,0);
        FUN_004b0613((Tact2010CString *)&param_7,&DAT_004daf00);
        uStack_4 = 0x14;
        (*(code *)param_4)(original_dc,iVar1 + 7,iVar4,(char *)param_7,*(int *)(param_7 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_7);
      }
      if (DAT_005363e4 == 0) {
        (*(code *)param_6)(original_dc,0xffff);
      }
      param_5 = iVar3 * 2 - iVar1;
      iVar1 = iVar3 + 5;
      FUN_00463f50(original_dc,iVar1,iVar4,param_5,param_2,1,1);
      FUN_004b0613((Tact2010CString *)&param_7,&DAT_004db308);
      uStack_4 = 0x15;
      (*(code *)param_4)(original_dc,iVar3 + 0xc,iVar4,(char *)param_7,*(int *)(param_7 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_7);
      if ((((iVar1 < DAT_005364a0) && (DAT_005364a0 < param_5)) && (iVar4 < DAT_005364a4)) &&
         (DAT_005364a4 < param_2)) {
        if (DAT_004fe624 < 0x3e9) {
          pcVar6 = s_7_lower_than_normal_tacking_down_004db2b4;
        }
        else {
          pcVar6 = s_7_deg_lower_than_normal_tacking_d_004db2dc;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar6);
        DAT_0053649c = 1;
      }
      if (((iVar1 < DAT_004fe75c) && (DAT_004fe75c < param_5)) &&
         ((iVar4 < DAT_005233a4 && (DAT_005233a4 < param_2)))) {
        DAT_004f3f64 = 7;
        DAT_005233a4 = 0;
        DAT_004f7094 = 0;
        DAT_005356b4 = 0;
      }
      if (DAT_004f3f64 == 7) {
        (*(code *)param_6)(original_dc,0);
        FUN_004b0613((Tact2010CString *)&param_7,&DAT_004db308);
        uStack_4 = 0x16;
        (*(code *)param_4)(original_dc,iVar3 + 0xc,iVar4,(char *)param_7,*(int *)(param_7 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_7);
      }
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

