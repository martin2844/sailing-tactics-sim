
void __cdecl
FUN_0040b130(CDC *param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  CDC *pCVar2;
  code *unaff_EBX;
  int unaff_EBP;
  int iVar3;
  code *unaff_ESI;
  int unaff_EDI;
  code *pcVar4;
  int *unaff_FS_OFFSET;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  code *pcVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  code *pcVar13;
  int iVar14;
  code *pcVar15;
  code *pcVar16;
  int iVar17;
  int iVar18;
  code *pcVar19;
  int iStack_2c;
  code *pcStack_28;
  int iStack_24;
  code *pcStack_1c;
  undefined4 uStack_18;
  code *pcStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047da00;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar3 = (param_4 + param_2 * 2) / 3 - DAT_004a763c / 200;
  pcVar1 = (code *)(param_3 + -2 + (param_7 * 7) / 2);
  if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  (**(code **)(*(int *)param_1 + 0x38))();
  pcVar4 = pcVar1 + param_7;
  FUN_0044d990((int *)param_1,(int)param_1,(int)pcVar1,iVar3,pcVar4,1);
  FUN_0046bf33(&iStack_2c,s_port_<_00491ce0);
  pCVar2 = param_1 + 1;
  pcStack_8 = (code *)0x0;
  iVar17 = *(int *)(iStack_2c + -8);
  pcVar5 = pcVar1;
  (**(code **)(*(int *)param_1 + 100))();
  uStack_18 = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffffc4);
  FUN_0044d990((int *)param_1,iStack_c,(int)pcVar1,iVar3,pcVar4,0);
  if (DAT_004ac92c == 0) {
    iVar18 = 0xffff;
  }
  else {
    iVar18 = 0xffffff;
  }
  (*pcStack_8)();
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar1,iVar17,pcVar4,1);
  FUN_0046bf33(&stack0xffffffc0,s_star_>_00491cd8);
  iVar6 = iVar3 + 1;
  pcStack_1c = (code *)0x1;
  iVar14 = *(int *)(unaff_EDI + -8);
  pcVar13 = pcVar1;
  (*pcStack_14)();
  iStack_2c = -1;
  FUN_0046bec5((int *)&stack0xffffffb0);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar1,iVar18,pcVar4,0);
  if ((DAT_004a8918 == 1) || (DAT_004a4e00 == -1)) {
    iVar18 = 0;
  }
  else if (DAT_004ac92c == 0) {
    iVar18 = 0xffff;
  }
  else {
    iVar18 = 0xffffff;
  }
  (*pcStack_1c)();
  FUN_0044d990((int *)param_1,iVar14,(int)pcVar1,(int)pcStack_1c,pcVar4,1);
  FUN_0046bf33(&stack0xffffffac,s_beat_C_00491cd0);
  pcVar16 = *(code **)(pCVar2 + -8);
  pcVar15 = pcVar1;
  (*pcStack_28)();
  FUN_0046bec5((int *)&stack0xffffff9c);
  FUN_0044d990((int *)param_1,iVar18,(int)pcVar1,iStack_2c,pcVar4,0);
  iVar14 = 6;
  (**(code **)(*(int *)param_1 + 0x2c))();
  FUN_004706bd(param_1,(int *)&stack0xffffffac,iVar18,(int)pcVar4);
  CDC::LineTo(param_1,1,(int)pcVar4);
  pcVar4 = pcVar4 + 1;
  pcVar1 = pcVar4 + iStack_24;
  FUN_0044d990((int *)param_1,unaff_EBP,(int)pcVar4,iVar3,pcVar1,1);
  pcVar11 = pcVar4;
  if ((DAT_004a4e00 == 1) || (DAT_004abfa0 == 1)) {
LAB_0040b438:
    (*unaff_EBX)();
LAB_0040b43e:
    if (DAT_004a7bd0 < 0x5a) goto LAB_0040b447;
    FUN_0046bf33(&stack0xffffff98,s_jibe_J_00491cc0);
    pcVar19 = (code *)0x4;
    (*unaff_ESI)();
  }
  else {
    (*unaff_EBX)();
    if (DAT_004ac92c != 0) goto LAB_0040b43e;
    if (0x59 < DAT_004a7bd0) goto LAB_0040b438;
LAB_0040b447:
    FUN_0046bf33(&stack0xffffff98,s_tack_T_00491cc8);
    pcVar19 = (code *)0x3;
    (*unaff_ESI)();
  }
  iVar8 = -1;
  FUN_0046bec5((int *)&stack0xffffff88);
  FUN_0044d990((int *)param_1,iVar17,(int)pcVar4,iVar3,pcVar1,0);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar4,iVar14,pcVar1,1);
  if (DAT_004a6850 < 2) {
    if (DAT_004ac92c == 0) {
      pcVar9 = (code *)0xffff00;
    }
    else {
      pcVar9 = (code *)0xffffff;
    }
  }
  else {
    pcVar9 = (code *)0x0;
  }
  (*pcVar19)();
  FUN_0046bf33(&stack0xffffff84,s_rech_H_00491cb8);
  pcVar19 = (code *)&DAT_00000005;
  (*pcVar5)();
  iVar17 = -1;
  FUN_0046bec5((int *)&stack0xffffff74);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar4,(int)pcVar9,pcVar1,0);
  FUN_0044d990((int *)param_1,(int)pcVar9,(int)pcVar4,iVar8,pcVar1,1);
  if ((DAT_004a6850 == 1) || (DAT_004a4970 == 1)) {
    iVar8 = 0;
  }
  else if (DAT_004ac92c == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar19)();
  FUN_0046bf33(&stack0xffffff70,s_run_D_00491cb0);
  uVar7 = *(undefined4 *)(iVar18 + -8);
  iVar10 = iVar18;
  iVar12 = iVar6;
  (*pcVar13)();
  pcVar19 = (code *)0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff60);
  FUN_0044d990((int *)param_1,iVar8,(int)pcVar4,iVar17,pcVar1,0);
  pcVar5 = (code *)&DAT_00000006;
  (*pcVar9)();
  FUN_004706bd(param_1,(int *)&stack0xffffff5c,iVar8,(int)pcVar1);
  CDC::LineTo(param_1,iVar10,(int)pcVar1);
  pcVar1 = pcVar1 + 1;
  if (DAT_004ac92c == 0) {
    (*pcVar16)();
  }
  if ((0 < DAT_004a438c) || (iVar17 = 0, 0x5a < DAT_004a7bd0)) {
    iVar17 = 1;
  }
  pcVar4 = pcVar1 + unaff_EDI;
  FUN_0044d990((int *)param_1,(int)pCVar2,(int)pcVar1,iVar3,pcVar4,1);
  if ((iVar17 == 0) || (DAT_004a5b80 < 1)) {
    if (DAT_004a85d8 < 0x32) {
      if (DAT_004ac92c == 0) {
        iVar17 = 0x7f;
      }
      else {
        iVar17 = 0xffffff;
      }
      (*pcVar16)();
      FUN_0046bf33(&stack0xffffff9c,s_luff_S_00491c98);
      (*pcVar19)(uVar7,pcVar1,pcVar13,*(undefined4 *)(pcVar13 + -8));
    }
    else {
      if (DAT_004ac92c == 0) {
        iVar17 = 0xff00;
      }
      else {
        iVar17 = 0xffffff;
      }
      (*pcVar16)();
      if (DAT_004a763c < 0x2bd) {
        FUN_0046bf33(&stack0xffffff9c,s_max_A_00491c90);
        (*pcVar19)(pcVar15,pcVar1,pcVar13,*(undefined4 *)(pcVar13 + -8));
      }
      else {
        FUN_0046bf33(&stack0xffffff9c,s_max_A_00491c90);
        (*pcVar19)(uVar7,pcVar1,pcVar13,*(undefined4 *)(pcVar13 + -8));
      }
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      iVar17 = 0xffff;
    }
    else {
      iVar17 = 0xffffff;
    }
    (*pcVar16)();
    if (0 < DAT_004abb78) {
      (*(code *)pCVar2)(0);
    }
    if (2 < DAT_00491188) {
      FUN_0046bf33(&stack0xffffff9c,s_spn_P_00491ca8);
      (*pcVar19)(uVar7,pcVar1,pcVar13,*(undefined4 *)(pcVar13 + -8));
      FUN_0046bec5((int *)&stack0xffffff9c);
    }
    if (DAT_00491188 != 2) goto LAB_0040b843;
    FUN_0046bf33(&stack0xffffff9c,s_wng_P_00491ca0);
    (*pcVar19)(uVar7,pcVar1,pcVar13,*(undefined4 *)(pcVar13 + -8));
  }
  FUN_0046bec5((int *)&stack0xffffff9c);
LAB_0040b843:
  FUN_0044d990((int *)param_1,(int)pcVar15,(int)pcVar1,iVar3,pcVar4,0);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar1,iVar18,pcVar4,1);
  if (DAT_004ac92c == 0) {
    (*(code *)pCVar2)(0xffffff);
  }
  FUN_0046bf33(&stack0xffffff88,s_shap_E_00491c88);
  pcVar13 = (code *)0xc;
  iVar8 = iVar3 + 1;
  (*pcVar19)(iVar8,pcVar1,pcVar15,*(undefined4 *)(pcVar15 + -8));
  FUN_0046bec5((int *)&stack0xffffff78);
  FUN_0044d990((int *)param_1,iVar3,(int)pcVar1,iVar17,pcVar4,0);
  FUN_0044d990((int *)param_1,iVar17,(int)pcVar1,iVar14,pcVar4,1);
  if (DAT_004ac92c == 0) {
    (*pcVar13)(0xffff00);
  }
  FUN_0046bf33(&stack0xffffff78,s_view_V_00491c80);
  (*pcVar11)(iVar18,pcVar1,iVar12,*(undefined4 *)(iVar12 + -8));
  FUN_0046bec5((int *)&stack0xffffff68);
  FUN_0044d990((int *)param_1,iVar8,(int)pcVar1,iVar14,pcVar4,0);
  (*pcVar5)(6);
  FUN_004706bd(param_1,(int *)&stack0xffffff40,iVar8,(int)pcVar4);
  CDC::LineTo(param_1,iVar6,(int)pcVar4);
  *unaff_FS_OFFSET = iVar18;
  return;
}

