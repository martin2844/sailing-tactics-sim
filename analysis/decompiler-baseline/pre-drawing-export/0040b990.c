
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040b990(CDC *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *unaff_EBP;
  code *unaff_ESI;
  int unaff_EDI;
  int iVar7;
  int iVar8;
  int *unaff_FS_OFFSET;
  int unaff_retaddr;
  int iStack0000001c;
  undefined4 uVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  int iVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  int iVar20;
  code *pcVar21;
  int iStack_30;
  int iStack_20;
  code *pcStack_1c;
  int iStack_10;
  int iStack_c;
  code *pcStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  pcStack_8 = FUN_0047da48;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  FUN_0047033f(param_1,1);
  iStack0000001c = DAT_004a72d0 / 0x1f;
  iVar5 = iStack0000001c + param_3;
  iVar7 = 2 - (int)(longlong)((double)DAT_004a763c * _DAT_00484d68);
  iVar1 = (param_4 - iVar7) + -2;
  FUN_0044d990((int *)param_1,iVar1,param_3,param_4,iVar5,1);
  iVar8 = *(int *)param_1;
  iVar20 = 0x7f7f7f;
  (**(code **)(iVar8 + 0x34))();
  (**(code **)(iVar8 + 0x38))();
  pcVar19 = (code *)0x7;
  (**(code **)(iVar8 + 0x2c))();
  pcVar21 = (code *)0x1;
  iVar6 = unaff_retaddr + param_4 / 2;
  iVar8 = param_4;
  iVar2 = iVar7;
  do {
    if (pcVar21 == (code *)0x1) {
      iVar2 = iVar8 * 4 + iVar2 * -3;
    }
    else {
      iVar2 = iVar8 * 4 - iVar2;
    }
    iVar8 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    if (DAT_004a9448 == 1) {
      iVar2 = (int)(param_4 + (param_4 >> 0x1f & 3U)) >> 2;
    }
    else {
      iVar2 = param_4 / 3;
    }
    iVar3 = iVar2 * 3 + (iVar2 * 3 >> 0x1f & 3U);
    iVar4 = iVar3 >> 2;
    iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
    pcVar17 = (code *)0x0;
    (*unaff_EBP)();
    pcVar18 = Ellipse_exref;
    if (DAT_004a9448 == 1) {
      Ellipse(*(HDC *)(param_1 + 4),iVar8 + iVar2 * -4,iStack_4 - iVar2,iVar8 + iVar2 * 4,
              iVar2 + iStack_4);
    }
    else {
      Ellipse(*(HDC *)(param_1 + 4),iVar8 + iVar2 * -2,iStack_4 - iVar2,iVar8 + iVar2 * 2,
              iVar2 + iStack_4);
      pcVar18 = Ellipse_exref;
    }
    if (DAT_004ac92c == 0) {
      if (DAT_004a469c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a469c);
      }
    }
    else {
      (*unaff_ESI)();
    }
    (*pcVar18)();
    (*pcVar17)();
    (*pcVar18)();
    pcVar21 = pcVar21 + 1;
    iVar8 = iVar5;
    iVar2 = iStack_30;
  } while ((int)pcVar21 < 3);
  if ((DAT_004a4610 == 0) && (DAT_004a9448 == 0)) {
    pcVar18 = (code *)0x0;
  }
  else if (DAT_004ac92c == 0) {
    pcVar18 = (code *)0xffff00;
  }
  else {
    pcVar18 = (code *)0xffffff;
  }
  (*unaff_ESI)();
  iVar8 = iStack_c;
  iStack_4 = iStack_c + param_3;
  FUN_0044d990((int *)param_1,iVar3,iStack_c,iVar6,iStack_4,1);
  FUN_0046bf33(&stack0xffffffc4,s_ahead_00491c18);
  pcVar17 = *(code **)(unaff_EBP + -8);
  iVar2 = iVar7;
  pcVar10 = unaff_EBP;
  (**(code **)(*(int *)param_1 + 100))();
  FUN_0046bec5((int *)&stack0xffffffb4);
  iVar5 = 6;
  (*pcVar19)();
  FUN_004706bd(param_1,(int *)&stack0xffffffc8,iVar7,iStack_20);
  CDC::LineTo(param_1,iVar6 + -2,iStack_20);
  FUN_0044d990((int *)param_1,iVar3,iStack_20,iVar6,iVar1,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0(param_1,(iVar6 - DAT_004a763c / 0x82) + -2,iStack_20 + 2,0xb4,10);
  pcVar16 = (code *)0x7;
  (*pcVar18)();
  if (((DAT_004a4610 < 1) || (DAT_004a4610 == 0xb4)) || (DAT_004a9448 != 0)) {
    if (DAT_004ac92c == 0) {
      pcVar15 = (code *)0xffff00;
    }
    else {
      pcVar15 = (code *)0xffffff;
    }
  }
  else {
    pcVar15 = (code *)0x0;
  }
  (*pcVar10)();
  FUN_0044d990((int *)param_1,iVar3,iVar3,iVar6,iStack_10 + iVar3,1);
  FUN_0046bf33(&stack0xffffffa8,&DAT_00491bc4);
  pcVar10 = *(code **)(pcVar17 + -8);
  iVar1 = iVar3;
  pcVar11 = pcVar17;
  (*pcStack_1c)();
  FUN_0046bec5((int *)&stack0xffffff98);
  iVar14 = 6;
  (*pcVar16)();
  FUN_004706bd(param_1,(int *)&stack0xffffffac,iVar7,(int)unaff_EBP);
  CDC::LineTo(param_1,iVar6 + -2,(int)unaff_EBP);
  FUN_0044d990((int *)param_1,iVar3,(int)unaff_EBP,iVar6,param_4 / 2,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0(param_1,(iVar6 - DAT_004a763c / 0x32) + -2,(int)(unaff_EBP + iVar5),0x5a,10);
  pcVar13 = (code *)0x7;
  (*pcVar15)();
  if ((DAT_004a4610 < 0) && (DAT_004a9448 == 0)) {
    pcVar12 = (code *)0x0;
  }
  else if (DAT_004ac92c == 0) {
    pcVar12 = (code *)0xffff00;
  }
  else {
    pcVar12 = (code *)0xffffff;
  }
  (*pcVar17)();
  FUN_0044d990((int *)param_1,iVar3,unaff_EDI,iVar6,iVar4 + unaff_EDI,1);
  FUN_0046bf33(&stack0xffffff8c,s_right_00491b6c);
  iVar5 = *(int *)(pcVar10 + -8);
  pcVar17 = pcVar10;
  (*pcVar21)();
  FUN_0046bec5((int *)&stack0xffffff7c);
  pcVar21 = (code *)&DAT_00000006;
  (*pcVar13)();
  FUN_004706bd(param_1,(int *)&stack0xffffff90,iVar7,(int)pcVar11);
  CDC::LineTo(param_1,iVar6 + -2,(int)pcVar11);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar11,iVar6,pcVar19,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0(param_1,iVar6 + -3,(int)(pcVar11 + iVar14),0x10e,10);
  pcVar19 = (code *)0x7;
  (*pcVar12)();
  if ((DAT_004a4610 == 0xb4) && (DAT_004a9448 == 0)) {
    pcVar11 = (code *)0x0;
  }
  else if (DAT_004ac92c == 0) {
    pcVar11 = (code *)0xffff00;
  }
  else {
    pcVar11 = (code *)0xffffff;
  }
  (*pcVar10)();
  FUN_0044d990((int *)param_1,iVar3,iVar8,iVar6,iVar8 + iVar20,1);
  FUN_0046bf33(&stack0xffffff74,s_astern_00491b1c);
  iVar8 = iVar7;
  (*pcVar18)();
  FUN_0046bec5((int *)&stack0xffffff64);
  iVar20 = 6;
  (*pcVar19)();
  FUN_004706bd(param_1,(int *)&stack0xffffff74,iVar7,(int)pcVar17);
  CDC::LineTo(param_1,iVar6 + -2,(int)pcVar17);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar17,iVar6,pcVar16,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0(param_1,(iVar6 - DAT_004a763c / 0x82) + -2,(int)(pcVar16 + -1),0,10);
  pcVar10 = (code *)0x7;
  (*pcVar11)();
  (*pcVar12)();
  FUN_0044d990((int *)param_1,iVar3,iVar1,iVar6,iVar1 + iVar2,1);
  FUN_0046bf33(&stack0xffffff58,s_upwn_5_00491cfc);
  pcVar19 = *(code **)(pcVar11 + -8);
  iVar2 = iVar1;
  (*pcVar15)();
  iVar4 = -1;
  FUN_0046bec5((int *)&stack0xffffff48);
  pcVar17 = (code *)&DAT_00000006;
  (*pcVar10)();
  FUN_004706bd(param_1,(int *)&stack0xffffff58,iVar7,iVar5);
  CDC::LineTo(param_1,iVar6 + -2,iVar5);
  FUN_0044d990((int *)param_1,iVar3,iVar5,iVar6,pcVar13,0);
  (*pcVar19)();
  FUN_0044d990((int *)param_1,iVar3,iVar4,iVar6,iVar2 + iVar4,1);
  FUN_0046bf33(&stack0xffffff40,s_dnwn_7_00491cf4);
  pcVar19 = *(code **)(pcVar10 + -8);
  (*pcVar13)(iVar7);
  iVar2 = -1;
  FUN_0046bec5((int *)&stack0xffffff30);
  pcVar18 = (code *)&DAT_00000006;
  (*pcVar17)();
  FUN_004706bd(param_1,(int *)&stack0xffffff40,iVar7,(int)pcVar11);
  CDC::LineTo(param_1,iVar6 + -2,(int)pcVar11);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar11,iVar6,pcVar21,0);
  if (DAT_004a9448 == 100) {
    uVar9 = 0;
  }
  else if (DAT_004ac92c == 0) {
    uVar9 = 0xffff00;
  }
  else {
    uVar9 = 0xffffff;
  }
  pcVar16 = pcVar21;
  (*pcVar19)(uVar9);
  FUN_0044d990((int *)param_1,iVar3,iVar2,iVar6,iVar4 + iVar2,1);
  FUN_0046bf33(&stack0xffffff28,s_boat1_9_00491ce8);
  (*pcVar16)(iVar7,iVar2,pcVar17,*(undefined4 *)(pcVar17 + -8));
  FUN_0046bec5((int *)&stack0xffffff18);
  (*pcVar18)(6);
  FUN_004706bd(param_1,(int *)&stack0xffffff28,iVar7,(int)pcVar10);
  CDC::LineTo(param_1,iVar6 + -2,(int)pcVar10);
  iVar5 = iVar8 + 1;
  FUN_004706bd(param_1,(int *)&stack0xffffff28,iVar7,iVar5);
  CDC::LineTo(param_1,iVar6 + -2,iVar5);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar10,iVar6,iVar8,0);
  FUN_0040b130(param_1,iVar20,(int)pcVar10,iVar6,pcVar12,iVar2,(int)pcVar21);
  *unaff_FS_OFFSET = iVar1;
  return;
}

