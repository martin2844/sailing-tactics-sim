
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00409760(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  LPCSTR pCVar9;
  int iVar10;
  LPCSTR pCVar11;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar12;
  char *pcVar13;
  int iStack_24;
  LPCSTR local_20;
  int iStack_1c;
  int iStack_18;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d8b8;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_0047033f((void *)param_1,1);
  iVar5 = param_3;
  if ((DAT_004a763c < 700) || ((DAT_004a763c < 900 && (0 < DAT_004a5264)))) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  iVar2 = (int)(longlong)((double)DAT_004a763c * _DAT_00484d50);
  local_20 = (LPCSTR)(param_7 + param_3);
  iVar6 = *(int *)param_1;
  (**(code **)(iVar6 + 0x34))((void *)param_1,0x7f7f7f);
  param_3 = *(undefined4 *)(iVar6 + 0x38);
  (*(code *)param_3)((void *)param_1,0);
  aiStack_14[0] = param_4 - iVar2;
  iVar4 = aiStack_14[0] + -2;
  FUN_0044d990(param_1,iVar4,iVar5,param_4,(int)local_20,1,0);
  pcVar1 = *(code **)(iVar6 + 0x2c);
  (*pcVar1)((void *)param_1,7);
  iStack_24 = 1;
  iVar5 = param_7 / 2 + iVar5;
  do {
    if (iStack_24 == 1) {
      iVar6 = param_4 * 4 + iVar2 * -3;
    }
    else {
      iVar6 = param_4 * 4 - iVar2;
    }
    iVar6 = ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) + -2;
    if (DAT_00491140 == 2) {
      if (DAT_004a9444 == 1) {
        iVar10 = (int)(param_7 + (param_7 >> 0x1f & 3U)) >> 2;
      }
      else {
LAB_004098ea:
        iVar10 = param_7 / 3;
      }
    }
    else {
      if (DAT_004a9444 != 1) goto LAB_004098ea;
      iVar10 = (int)(param_7 + (param_7 >> 0x1f & 3U)) >> 2;
    }
    iVar7 = iVar10 * 3 + (iVar10 * 3 >> 0x1f & 3U);
    iStack_1c = iVar7 >> 2;
    iStack_18 = iStack_1c - (iVar7 >> 0x1f) >> 1;
    iVar7 = iVar6;
    if ((0 < DAT_004a460c) && (DAT_004a9444 == 0)) {
      iVar7 = iVar6 - param_7 / 3;
    }
    if ((DAT_004a460c < 0) && (DAT_004a9444 == 0)) {
      iVar7 = iVar7 + param_7 / 3;
    }
    (*pcVar1)((void *)param_1,0);
    if (DAT_004a9444 == 1) {
      iVar8 = iVar10 * 3;
    }
    else {
      iVar8 = iVar10 * 2;
    }
    Ellipse(*(HDC *)(param_1 + 4),iVar6 - iVar8,iVar5 - iVar10,iVar6 + iVar8,iVar10 + iVar5);
    if (DAT_004ac92c == 0) {
      if (DAT_004a469c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a469c);
      }
    }
    else {
      (*pcVar1)((void *)param_1,4);
    }
    Ellipse(*(HDC *)(param_1 + 4),iVar7 - iStack_1c,iVar5 - iStack_1c,iStack_1c + iVar7,
            iStack_1c + iVar5);
    (*pcVar1)((void *)param_1,4);
    Ellipse(*(HDC *)(param_1 + 4),iVar7 - iStack_18,iVar5 - iStack_18,iStack_18 + iVar7,
            iStack_18 + iVar5);
    iStack_24 = iStack_24 + 1;
    if (2 < iStack_24) {
      if ((DAT_004a460c == 0) && (DAT_004a9444 == 0)) {
        CVar12 = 0;
      }
      else if (DAT_004ac92c == 0) {
        CVar12 = 0xffff00;
      }
      else {
        CVar12 = 0xffffff;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar9 = local_20;
      iVar5 = param_4;
      pCVar11 = local_20 + param_7;
      FUN_0044d990(param_1,iVar4,(int)local_20,param_4,(int)pCVar11,1,0);
      FUN_0046bf33(&local_20,s_ahead_00491c18);
      iVar6 = aiStack_14[0];
      uStack_4 = 0;
      param_4 = *(undefined4 *)(*(int *)param_1 + 100);
      (*(code *)param_4)((void *)param_1,aiStack_14[0],(int)pCVar9,local_20,*(int *)(local_20 + -8))
      ;
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar9);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar9);
      FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,0,0);
      if ((((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) && (DAT_004ac9e4 < (int)pCVar11)) &&
         ((int)pCVar9 < DAT_004ac9e4)) {
        if (bVar3) {
          pcVar13 = s_Sets_line_of_sight_over_the_bow__00491bcc;
        }
        else {
          pcVar13 = s_Sets_your_line_of_sight_over_the_00491bf0;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar13);
        DAT_004ac9dc = 1;
      }
      if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
         ((DAT_004aa97c < (int)pCVar11 && ((int)pCVar11 - param_7 < DAT_004aa97c)))) {
        DAT_004a460c = 0;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      if (((DAT_004a460c < 1) || (DAT_004a460c == 0xb4)) || (DAT_004a9444 != 0)) {
        if (DAT_004ac92c == 0) {
          CVar12 = 0xffff00;
        }
        else {
          CVar12 = 0xffffff;
        }
      }
      else {
        CVar12 = 0;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar9 = pCVar11 + param_7;
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,1,0);
      FUN_0046bf33(&local_20,&DAT_00491bc4);
      uStack_4 = 1;
      (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar11,local_20,*(int *)(local_20 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar11);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar11);
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,0,0);
      if ((((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) && (DAT_004ac9e4 < (int)pCVar9)) &&
         ((int)pCVar11 < DAT_004ac9e4)) {
        if (bVar3) {
          pcVar13 = s_Line_of_sight_30_deg_left_per_cl_00491b74;
        }
        else {
          pcVar13 = s_Moves_line_of_sight_30_deg_left_p_00491b98;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar13);
        DAT_004ac9dc = 1;
      }
      if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
         ((DAT_004aa97c < (int)pCVar9 && ((int)pCVar9 - param_7 < DAT_004aa97c)))) {
        DAT_004a460c = DAT_004a460c + 0x1e;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      if ((DAT_004a460c < 0) && (DAT_004a9444 == 0)) {
        CVar12 = 0;
      }
      else if (DAT_004ac92c == 0) {
        CVar12 = 0xffff00;
      }
      else {
        CVar12 = 0xffffff;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar11 = pCVar9 + param_7;
      FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,1,0);
      FUN_0046bf33(&local_20,s_right_00491b6c);
      uStack_4 = 2;
      (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar9,local_20,*(int *)(local_20 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar9);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar9);
      FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,0,0);
      if ((((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) && (DAT_004ac9e4 < (int)pCVar11)) &&
         ((int)pCVar9 < DAT_004ac9e4)) {
        if (bVar3) {
          pcVar13 = s_Sight_30_deg_right_per_click_00491b24;
        }
        else {
          pcVar13 = s_Line_of_sight_30_deg_right_per_c_00491b44;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar13);
        DAT_004ac9dc = 1;
      }
      if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
         ((DAT_004aa97c < (int)pCVar11 && ((int)pCVar11 - param_7 < DAT_004aa97c)))) {
        DAT_004a460c = DAT_004a460c + -0x1e;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      if ((DAT_004a460c == 0xb4) && (DAT_004a9444 == 0)) {
        CVar12 = 0;
      }
      else if (DAT_004ac92c == 0) {
        CVar12 = 0xffff00;
      }
      else {
        CVar12 = 0xffffff;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar9 = pCVar11 + param_7;
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,1,0);
      FUN_0046bf33(&local_20,s_astern_00491b1c);
      uStack_4 = 3;
      (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar11,local_20,*(int *)(local_20 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar11);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar11);
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,0,0);
      if ((((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) && (DAT_004ac9e4 < (int)pCVar9)) &&
         ((int)pCVar11 < DAT_004ac9e4)) {
        if (bVar3) {
          pcVar13 = s_Line_of_sight_over_the_stern__00491ad4;
        }
        else {
          pcVar13 = s_Sets_your_line_of_sight_over_the_00491af4;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar13);
        DAT_004ac9dc = 1;
      }
      if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
         ((DAT_004aa97c < (int)pCVar9 && ((int)pCVar9 - param_7 < DAT_004aa97c)))) {
        DAT_004a460c = 0xb4;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      if (DAT_004a9444 == 1) {
        CVar12 = 0;
      }
      else if (DAT_004ac92c == 0) {
        CVar12 = 0xffff;
      }
      else {
        CVar12 = 0xffffff;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar11 = pCVar9 + param_7;
      FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,1,0);
      FUN_0046bf33(&local_20,s_upwind_00491acc);
      uStack_4 = 4;
      (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar9,local_20,*(int *)(local_20 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar9);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar9);
      FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,0,0);
      if (((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) &&
         ((DAT_004ac9e4 < (int)pCVar11 && ((int)pCVar9 < DAT_004ac9e4)))) {
        FUN_0046c00d(&DAT_004a7048,s_You_will_look_directly_upwind__00491aac);
        DAT_004ac9dc = 1;
      }
      if ((((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) && (DAT_004aa97c < (int)pCVar11)) &&
         ((int)pCVar11 - param_7 < DAT_004aa97c)) {
        DAT_004a9444 = 1;
        DAT_004aa97c = 0;
        DAT_004a460c = 0;
      }
      if (DAT_004a9444 == -1) {
        CVar12 = 0;
      }
      else if (DAT_004ac92c == 0) {
        CVar12 = 0xffff;
      }
      else {
        CVar12 = 0xffffff;
      }
      (*(code *)param_3)((void *)param_1,CVar12);
      pCVar9 = pCVar11 + param_7;
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,1,0);
      FUN_0046bf33(&local_20,s_dnwind_00491aa4);
      uStack_4 = 5;
      (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar11,local_20,*(int *)(local_20 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&local_20);
      (*pcVar1)((void *)param_1,6);
      FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar11);
      CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar11);
      FUN_0044d990(param_1,iVar4,(int)pCVar11,iVar5,(int)pCVar9,0,0);
      if (((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) &&
         ((DAT_004ac9e4 < (int)pCVar9 && ((int)pCVar11 < DAT_004ac9e4)))) {
        FUN_0046c00d(&DAT_004a7048,s_You_will_look_directly_downwind__00491a80);
        DAT_004ac9dc = 1;
      }
      if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
         ((DAT_004aa97c < (int)pCVar9 && ((int)pCVar9 - param_7 < DAT_004aa97c)))) {
        DAT_004a9444 = -1;
        DAT_004aa97c = 0;
        DAT_004a460c = 0;
      }
      if ((DAT_00491140 == 2) || (pCVar11 = pCVar9, DAT_0049118c == 2)) {
        if (DAT_004a9444 == 100) {
          CVar12 = 0;
        }
        else if (DAT_004ac92c == 0) {
          CVar12 = 0xffff00;
        }
        else {
          CVar12 = 0xffffff;
        }
        (*(code *)param_3)((void *)param_1,CVar12);
        pCVar11 = pCVar9 + param_7;
        FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,1,0);
        FUN_0046bf33(&param_3,s_boat_2_00491a78);
        uStack_4 = 6;
        (*(code *)param_4)((void *)param_1,iVar6,(int)pCVar9,(LPCSTR)param_3,*(int *)(param_3 + -8))
        ;
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_3);
        (*pcVar1)((void *)param_1,6);
        FUN_004706bd((void *)param_1,aiStack_14,iVar6,(int)pCVar9);
        CDC::LineTo((CDC *)param_1,iVar5 + -2,(int)pCVar9);
        param_4 = (int)(pCVar11 + 1);
        FUN_004706bd((void *)param_1,aiStack_14,iVar6,param_4);
        CDC::LineTo((CDC *)param_1,iVar5 + -2,param_4);
        FUN_0044d990(param_1,iVar4,(int)pCVar9,iVar5,(int)pCVar11,0,0);
        if ((((iVar6 < DAT_004ac9e0) && (DAT_004ac9e0 < iVar5)) && (DAT_004ac9e4 < (int)pCVar11)) &&
           ((int)pCVar9 < DAT_004ac9e4)) {
          FUN_0046c00d(&DAT_004a7048,s_You_will_look_at_the_other_boat__00491a54);
          DAT_004ac9dc = 1;
        }
        if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar5)) &&
           ((DAT_004aa97c < (int)pCVar11 && ((int)pCVar11 - param_7 < DAT_004aa97c)))) {
          DAT_004a9444 = 100;
          DAT_004aa97c = 0;
          DAT_004a460c = 0;
        }
      }
      if (DAT_00491140 == 2) {
        FUN_0040a360((CDC *)param_1,param_2,(int)pCVar11 - param_7,iVar5,param_5,param_6,param_7);
      }
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  } while( true );
}

