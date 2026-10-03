
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00409760(CDC *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  code *unaff_ESI;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  code *unaff_retaddr;
  code *pcVar8;
  int iVar9;
  undefined4 uVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  code *pcVar15;
  code *pcVar16;
  char *pcVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcStack_50;
  undefined4 uStack_4c;
  code *pcVar20;
  code *pcStack_30;
  int local_2c;
  int iStack_28;
  code *pcStack_24;
  code *local_20;
  int iStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  code *pcStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_c = (code *)*unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d8b8;
  *unaff_FS_OFFSET = (int)&pcStack_c;
  uStack_4c = 0x409789;
  FUN_0047033f(param_1,1);
  if ((DAT_004a763c < 700) || ((DAT_004a763c < 900 && (0 < DAT_004a5264)))) {
    local_2c = 1;
  }
  else {
    local_2c = 0;
  }
  iVar9 = (int)(longlong)((double)DAT_004a763c * _DAT_00484d50);
  local_20 = (code *)(param_7 + param_3);
  iVar3 = *(int *)param_1;
  pcVar20 = (code *)0x7f7f7f;
  uStack_4c = 0x4097f6;
  (**(code **)(iVar3 + 0x34))();
  pcVar6 = *(code **)(iVar3 + 0x38);
  uStack_4c = 0;
  pcStack_50 = (code *)0x409803;
  (*pcVar6)();
  pcStack_50 = (code *)0x0;
  iStack_1c = (int)pcVar6 - iVar9;
  pcVar2 = (code *)(iStack_1c + -2);
  FUN_0044d990((int *)param_1,(int)pcVar2,param_3,(int)pcVar6,iStack_28,1);
  pcVar6 = *(code **)(iVar3 + 0x2c);
  pcStack_50 = (code *)0x7;
  (*pcVar6)();
  pcStack_30 = (code *)0x1;
  do {
    if (pcStack_30 == (code *)0x1) {
      iVar3 = iVar9 * 4 + (int)pcStack_8 * -3;
    }
    else {
      iVar3 = iVar9 * 4 - (int)pcStack_8;
    }
    iVar3 = ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2) + -2;
    if (DAT_00491140 == 2) {
      if (DAT_004a9444 == 1) {
        iVar7 = (int)(param_4 + (param_4 >> 0x1f & 3U)) >> 2;
      }
      else {
LAB_004098ea:
        iVar7 = param_4 / 3;
      }
    }
    else {
      if (DAT_004a9444 != 1) goto LAB_004098ea;
      iVar7 = (int)(param_4 + (param_4 >> 0x1f & 3U)) >> 2;
    }
    iVar4 = iVar7 * 3 + (iVar7 * 3 >> 0x1f & 3U);
    iStack_28 = iVar4 >> 2;
    pcStack_24 = (code *)(iStack_28 - (iVar4 >> 0x1f) >> 1);
    iVar4 = iVar3;
    if ((0 < DAT_004a460c) && (DAT_004a9444 == 0)) {
      iVar4 = iVar3 - param_4 / 3;
    }
    if ((DAT_004a460c < 0) && (DAT_004a9444 == 0)) {
      iVar4 = iVar4 + param_4 / 3;
    }
    (*pcVar2)();
    if (DAT_004a9444 == 1) {
      iVar5 = iVar7 * 3;
    }
    else {
      iVar5 = iVar7 * 2;
    }
    Ellipse(*(HDC *)(param_1 + 4),iVar3 - iVar5,(int)pcVar6 - iVar7,iVar3 + iVar5,
            (int)(pcVar6 + iVar7));
    if (DAT_004ac92c == 0) {
      if (DAT_004a469c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a469c);
      }
    }
    else {
      (*unaff_ESI)();
    }
    Ellipse(*(HDC *)(param_1 + 4),iVar4 - local_2c,(int)pcVar6 - local_2c,local_2c + iVar4,
            (int)(pcVar6 + local_2c));
    (*unaff_ESI)();
    Ellipse(*(HDC *)(param_1 + 4),iVar4 - (int)pcStack_24,(int)pcVar6 - (int)pcStack_24,
            (int)pcStack_24 + iVar4,(int)(pcVar6 + (int)pcStack_24));
    pcStack_30 = pcStack_30 + 1;
    if (2 < (int)pcStack_30) {
      (*unaff_retaddr)();
      pcVar2 = pcStack_30;
      pcStack_c = pcStack_30 + param_3;
      FUN_0044d990((int *)param_1,unaff_EDI,(int)pcStack_30,(int)unaff_retaddr,pcStack_c,1);
      FUN_0046bf33(&pcStack_30,s_ahead_00491c18);
      pcVar1 = pcStack_24;
      uStack_14 = 0;
      iVar3 = *(int *)(pcStack_30 + -8);
      pcVar8 = pcVar2;
      pcVar14 = pcStack_30;
      (**(code **)(*(int *)param_1 + 100))();
      pcStack_24 = (code *)0xffffffff;
      FUN_0046bec5((int *)&stack0xffffffc0);
      pcVar18 = (code *)&DAT_00000006;
      (*pcStack_50)();
      FUN_004706bd(param_1,(int *)&stack0xffffffc8,(int)pcVar1,(int)pcVar2);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar2);
      FUN_0044d990((int *)param_1,iVar3,(int)pcVar2,(int)unaff_retaddr,local_20,0);
      if (((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
          (DAT_004ac9e4 < (int)local_20)) && ((int)pcVar2 < DAT_004ac9e4)) {
        if (pcStack_50 == (code *)0x0) {
          pcVar17 = s_Sets_your_line_of_sight_over_the_00491bf0;
        }
        else {
          pcVar17 = s_Sets_line_of_sight_over_the_bow__00491bcc;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar17);
        DAT_004ac9dc = 1;
      }
      pcVar2 = local_20;
      if ((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
         ((DAT_004aa97c < (int)local_20 && ((int)local_20 - (int)pcStack_8 < DAT_004aa97c)))) {
        DAT_004a460c = 0;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      (*pcStack_18)();
      pcStack_24 = pcStack_c + (int)pcVar2;
      FUN_0044d990((int *)param_1,(int)pcVar14,(int)pcVar2,(int)unaff_retaddr,pcStack_24,1);
      FUN_0046bf33(&stack0xffffffb8,&DAT_00491bc4);
      local_2c = 1;
      iVar3 = *(int *)(pcVar20 + -8);
      pcVar14 = pcVar2;
      pcVar13 = pcVar20;
      (*pcStack_18)();
      FUN_0046bec5((int *)&stack0xffffffa8);
      pcVar16 = (code *)&DAT_00000006;
      (*pcVar18)();
      FUN_004706bd(param_1,(int *)&pcStack_50,(int)pcVar1,(int)pcVar2);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar2);
      FUN_0044d990((int *)param_1,iVar3,(int)pcVar2,(int)unaff_retaddr,pcVar6,0);
      if ((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
         ((DAT_004ac9e4 < (int)pcVar6 && ((int)pcVar2 < DAT_004ac9e4)))) {
        if (pcVar18 == (code *)0x0) {
          pcVar17 = s_Moves_line_of_sight_30_deg_left_p_00491b98;
        }
        else {
          pcVar17 = s_Line_of_sight_30_deg_left_per_cl_00491b74;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar17);
        DAT_004ac9dc = 1;
      }
      if (((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
          (DAT_004aa97c < (int)pcVar6)) && ((int)pcVar6 - (int)local_20 < DAT_004aa97c)) {
        DAT_004a460c = DAT_004a460c + 0x1e;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      (*pcStack_30)();
      pcVar2 = pcVar6 + (int)pcStack_24;
      FUN_0044d990((int *)param_1,(int)pcVar20,(int)pcVar6,(int)unaff_retaddr,pcVar2,1);
      FUN_0046bf33(&stack0xffffffa0,s_right_00491b6c);
      iVar3 = *(int *)(pcVar8 + -8);
      pcVar20 = pcVar1;
      pcVar12 = pcVar6;
      pcVar11 = pcVar8;
      (*pcStack_30)();
      FUN_0046bec5((int *)&stack0xffffff90);
      pcVar15 = (code *)&DAT_00000006;
      (*pcVar16)();
      FUN_004706bd(param_1,(int *)&stack0xffffff98,(int)pcVar1,(int)pcVar6);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar6);
      FUN_0044d990((int *)param_1,iVar3,(int)pcVar6,(int)unaff_retaddr,pcStack_50,0);
      if ((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
         ((DAT_004ac9e4 < (int)pcStack_50 && ((int)pcVar6 < DAT_004ac9e4)))) {
        if (pcVar16 == (code *)0x0) {
          pcVar17 = s_Line_of_sight_30_deg_right_per_c_00491b44;
        }
        else {
          pcVar17 = s_Sight_30_deg_right_per_click_00491b24;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar17);
        DAT_004ac9dc = 1;
      }
      pcVar19 = pcStack_50;
      if ((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
         ((DAT_004aa97c < (int)pcStack_50 && ((int)pcStack_50 - (int)pcVar6 < DAT_004aa97c)))) {
        DAT_004a460c = DAT_004a460c + -0x1e;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      (*pcVar13)();
      pcVar2 = pcVar2 + (int)pcVar19;
      FUN_0044d990((int *)param_1,(int)pcVar8,(int)pcVar19,(int)unaff_retaddr,pcVar2,1);
      FUN_0046bf33(&stack0xffffff88,s_astern_00491b1c);
      iVar9 = *(int *)(pcVar14 + -8);
      pcVar6 = pcVar19;
      pcVar8 = pcVar14;
      (*pcVar13)();
      FUN_0046bec5((int *)&stack0xffffff78);
      pcVar13 = (code *)&DAT_00000006;
      (*pcVar15)();
      FUN_004706bd(param_1,(int *)&stack0xffffff80,(int)pcVar1,(int)pcVar19);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar19);
      FUN_0044d990((int *)param_1,iVar9,(int)pcVar19,(int)unaff_retaddr,pcVar18,0);
      if (((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
          (DAT_004ac9e4 < (int)pcVar18)) && ((int)pcVar19 < DAT_004ac9e4)) {
        if (pcVar15 == (code *)0x0) {
          pcVar17 = s_Sets_your_line_of_sight_over_the_00491af4;
        }
        else {
          pcVar17 = s_Line_of_sight_over_the_stern__00491ad4;
        }
        FUN_0046c00d(&DAT_004a7048,pcVar17);
        DAT_004ac9dc = 1;
      }
      if ((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
         ((DAT_004aa97c < (int)pcVar18 && ((int)pcVar18 - (int)pcStack_50 < DAT_004aa97c)))) {
        DAT_004a460c = 0xb4;
        DAT_004a9444 = 0;
        DAT_004aa97c = 0;
      }
      pcVar19 = pcVar18;
      (*pcVar11)();
      pcVar2 = pcVar18 + (int)pcVar2;
      FUN_0044d990((int *)param_1,(int)pcVar14,(int)pcVar18,(int)unaff_retaddr,pcVar2,1);
      FUN_0046bf33(&stack0xffffff70,s_upwind_00491acc);
      iVar9 = *(int *)(pcVar12 + -8);
      pcVar14 = pcVar12;
      (*pcVar11)(pcVar1,pcVar18);
      FUN_0046bec5((int *)&stack0xffffff60);
      pcVar11 = (code *)&DAT_00000006;
      (*pcVar13)();
      FUN_004706bd(param_1,(int *)&stack0xffffff68,(int)pcVar1,(int)pcVar18);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar18);
      FUN_0044d990((int *)param_1,iVar9,(int)pcVar18,(int)unaff_retaddr,pcVar16,0);
      if ((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
         ((DAT_004ac9e4 < (int)pcVar16 && ((int)pcVar18 < DAT_004ac9e4)))) {
        FUN_0046c00d(&DAT_004a7048,s_You_will_look_directly_upwind__00491aac);
        DAT_004ac9dc = 1;
      }
      if (((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
          (DAT_004aa97c < (int)pcVar16)) && ((int)pcVar16 - (int)pcVar19 < DAT_004aa97c)) {
        DAT_004a9444 = 1;
        DAT_004aa97c = 0;
        DAT_004a460c = 0;
      }
      if (DAT_004a9444 == -1) {
        uVar10 = 0;
      }
      else if (DAT_004ac92c == 0) {
        uVar10 = 0xffff;
      }
      else {
        uVar10 = 0xffffff;
      }
      pcVar13 = pcVar16;
      (*pcVar8)(uVar10);
      pcVar2 = pcVar2 + (int)pcVar16;
      FUN_0044d990((int *)param_1,(int)pcVar12,(int)pcVar16,(int)unaff_retaddr,pcVar2,1);
      FUN_0046bf33(&stack0xffffff58,s_dnwind_00491aa4);
      iVar9 = *(int *)(pcVar6 + -8);
      pcVar18 = pcVar6;
      (*pcVar8)(pcVar1,pcVar16);
      FUN_0046bec5((int *)&stack0xffffff48);
      pcVar8 = (code *)&DAT_00000006;
      (*pcVar11)();
      FUN_004706bd(param_1,(int *)&stack0xffffff50,(int)pcVar1,(int)pcVar16);
      CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar16);
      FUN_0044d990((int *)param_1,iVar9,(int)pcVar16,(int)unaff_retaddr,pcVar15,0);
      if ((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
         ((DAT_004ac9e4 < (int)pcVar15 && ((int)pcVar16 < DAT_004ac9e4)))) {
        FUN_0046c00d(&DAT_004a7048,s_You_will_look_directly_downwind__00491a80);
        DAT_004ac9dc = 1;
      }
      if ((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
         ((DAT_004aa97c < (int)pcVar15 && ((int)pcVar15 - (int)pcVar13 < DAT_004aa97c)))) {
        DAT_004a9444 = -1;
        DAT_004aa97c = 0;
        DAT_004a460c = 0;
      }
      if ((DAT_00491140 == 2) || (DAT_0049118c == 2)) {
        if (DAT_004a9444 == 100) {
          uVar10 = 0;
        }
        else if (DAT_004ac92c == 0) {
          uVar10 = 0xffff00;
        }
        else {
          uVar10 = 0xffffff;
        }
        pcVar16 = pcVar15;
        (*pcVar14)(uVar10);
        FUN_0044d990((int *)param_1,(int)pcVar6,(int)pcVar15,(int)unaff_retaddr,
                     pcVar15 + (int)pcVar2,1);
        FUN_0046bf33(&stack0xffffff6c,s_boat_2_00491a78);
        (*pcVar14)(pcVar1,pcVar15,pcVar20,*(undefined4 *)((int)pcVar20 + -8));
        FUN_0046bec5((int *)&stack0xffffff5c);
        (*pcVar8)(6);
        FUN_004706bd(param_1,(int *)&stack0xffffff50,(int)pcVar1,(int)pcVar15);
        CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar15);
        pcVar6 = pcVar16 + 1;
        FUN_004706bd(param_1,(int *)&stack0xffffff50,(int)pcVar1,(int)pcVar6);
        CDC::LineTo(param_1,(int)(unaff_retaddr + -2),(int)pcVar6);
        FUN_0044d990((int *)param_1,iVar9,(int)pcVar15,(int)unaff_retaddr,pcVar16,0);
        if (((((int)pcVar1 < DAT_004ac9e0) && (DAT_004ac9e0 < (int)unaff_retaddr)) &&
            (DAT_004ac9e4 < (int)pcVar16)) && ((int)pcVar15 < DAT_004ac9e4)) {
          FUN_0046c00d(&DAT_004a7048,s_You_will_look_at_the_other_boat__00491a54);
          DAT_004ac9dc = 1;
        }
        pcVar15 = pcVar16;
        if ((((int)pcVar1 < DAT_004a774c) && (DAT_004a774c < (int)unaff_retaddr)) &&
           ((DAT_004aa97c < (int)pcVar15 && ((int)pcVar15 - (int)pcVar13 < DAT_004aa97c)))) {
          DAT_004a9444 = 100;
          DAT_004aa97c = 0;
          DAT_004a460c = 0;
        }
      }
      if (DAT_00491140 == 2) {
        FUN_0040a360(param_1,(int)pcVar20,(int)pcVar15 - (int)pcVar13,(int)unaff_retaddr,iVar3,
                     (int)pcVar2,(int)pcVar13);
      }
      *unaff_FS_OFFSET = (int)pcVar18;
      return;
    }
  } while( true );
}

