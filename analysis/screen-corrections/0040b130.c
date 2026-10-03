
void __cdecl
FUN_0040b130(CDC *param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar7;
  undefined4 uVar8;
  LPCSTR apCStack_28 [2];
  int iStack_20;
  code *apcStack_1c [2];
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar6 = param_7;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047da00;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar5 = (param_4 + param_2 * 2) / 3 - DAT_004a763c / 200;
  iVar3 = (param_2 + param_4 * 2) / 3;
  iVar1 = param_3 + -2 + (param_7 * 7) / 2;
  if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  param_3 = *(undefined4 *)(*(int *)param_1 + 0x38);
  if (DAT_004ac92c == 0) {
    CVar7 = 0xffff;
  }
  else {
    CVar7 = 0xffffff;
  }
  (*(code *)param_3)(param_1,CVar7);
  iVar6 = iVar6 + iVar1;
  FUN_0044d990((int)param_1,param_2,iVar1,iVar5,iVar6,1,-1);
  FUN_0046bf33(apCStack_28,s_port_<_00491ce0);
  iVar4 = param_2 + 1;
  uStack_4 = 0;
  pcVar2 = *(code **)(*(int *)param_1 + 100);
  (*pcVar2)(param_1,iVar4,iVar1,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,param_2,iVar1,iVar5,iVar6,0,-1);
  if (DAT_004ac92c == 0) {
    CVar7 = 0xffff;
  }
  else {
    CVar7 = 0xffffff;
  }
  (*(code *)param_3)(param_1,CVar7);
  FUN_0044d990((int)param_1,iVar5,iVar1,iVar3,iVar6,1,-1);
  FUN_0046bf33(apCStack_28,s_star_>_00491cd8);
  uStack_4 = 1;
  (*pcVar2)(param_1,iVar5 + 1,iVar1,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,iVar5,iVar1,iVar3,iVar6,0,-1);
  if ((DAT_004a8918 == 1) || (DAT_004a4e00 == -1)) {
    CVar7 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar7 = 0xffff;
  }
  else {
    CVar7 = 0xffffff;
  }
  (*(code *)param_3)(param_1,CVar7);
  FUN_0044d990((int)param_1,iVar3,iVar1,param_4,iVar6,1,-1);
  FUN_0046bf33(apCStack_28,s_beat_C_00491cd0);
  uStack_4 = 2;
  iStack_20 = iVar3 + 1;
  (*pcVar2)(param_1,iStack_20,iVar1,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,iVar3,iVar1,param_4,iVar6,0,-1);
  apcStack_1c[0] = *(code **)(*(int *)param_1 + 0x2c);
  (*apcStack_1c[0])(param_1,6);
  FUN_004706bd(param_1,aiStack_14,iVar4,iVar6);
  aiStack_14[0] = param_4 + -1;
  CDC::LineTo(param_1,aiStack_14[0],iVar6);
  iVar6 = iVar6 + 1;
  iVar1 = param_7 + iVar6;
  FUN_0044d990((int)param_1,param_2,iVar6,iVar5,iVar1,1,-1);
  if ((DAT_004a4e00 == 1) || (DAT_004abfa0 == 1)) {
    uVar8 = 0;
LAB_0040b438:
    (*(code *)param_3)(uVar8);
LAB_0040b43e:
    if (DAT_004a7bd0 < 0x5a) goto LAB_0040b447;
    FUN_0046bf33(apCStack_28,s_jibe_J_00491cc0);
    uStack_4 = 4;
    (*pcVar2)(param_1,iVar4,iVar6,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  }
  else {
    if ((DAT_004ac92c == 0) && (DAT_004a7bd0 < 0x5a)) {
      CVar7 = 0xffff00;
    }
    else {
      CVar7 = 0xffffff;
    }
    (*(code *)param_3)(param_1,CVar7);
    if (DAT_004ac92c != 0) goto LAB_0040b43e;
    if (0x59 < DAT_004a7bd0) {
      uVar8 = 0xff00;
      goto LAB_0040b438;
    }
LAB_0040b447:
    FUN_0046bf33(apCStack_28,s_tack_T_00491cc8);
    uStack_4 = 3;
    (*pcVar2)(param_1,iVar4,iVar6,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,param_2,iVar6,iVar5,iVar1,0,-1);
  FUN_0044d990((int)param_1,iVar5,iVar6,iVar3,iVar1,1,-1);
  if (DAT_004a6850 < 2) {
    if (DAT_004ac92c == 0) {
      CVar7 = 0xffff00;
    }
    else {
      CVar7 = 0xffffff;
    }
  }
  else {
    CVar7 = 0;
  }
  (*(code *)param_3)(param_1,CVar7);
  FUN_0046bf33(apCStack_28,s_rech_H_00491cb8);
  uStack_4 = 5;
  (*pcVar2)(param_1,iVar5 + 1,iVar6,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,iVar5,iVar6,iVar3,iVar1,0,-1);
  FUN_0044d990((int)param_1,iVar3,iVar6,param_4,iVar1,1,-1);
  if ((DAT_004a6850 == 1) || (DAT_004a4970 == 1)) {
    CVar7 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar7 = 0xffff00;
  }
  else {
    CVar7 = 0xffffff;
  }
  (*(code *)param_3)(param_1,CVar7);
  FUN_0046bf33(apCStack_28,s_run_D_00491cb0);
  uStack_4 = 6;
  (*pcVar2)(param_1,iStack_20,iVar6,apCStack_28[0],*(int *)(apCStack_28[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_28);
  FUN_0044d990((int)param_1,iVar3,iVar6,param_4,iVar1,0,-1);
  (*apcStack_1c[0])(param_1,6);
  FUN_004706bd(param_1,(int *)apCStack_28,iVar4,iVar1);
  CDC::LineTo(param_1,aiStack_14[0],iVar1);
  iVar1 = iVar1 + 1;
  if (DAT_004ac92c == 0) {
    (*(code *)param_3)(param_1,0xffff);
  }
  if ((0 < DAT_004a438c) || (apCStack_28[0] = (LPCSTR)0x0, 0x5a < DAT_004a7bd0)) {
    apCStack_28[0] = (LPCSTR)0x1;
  }
  iVar6 = param_7 + iVar1;
  FUN_0044d990((int)param_1,param_2,iVar1,iVar5,iVar6,1,-1);
  if ((apCStack_28[0] == (LPCSTR)0x0) || (DAT_004a5b80 < 1)) {
    if (DAT_004a85d8 < 0x32) {
      if (DAT_004ac92c == 0) {
        CVar7 = 0x7f;
      }
      else {
        CVar7 = 0xffffff;
      }
      (*(code *)param_3)(param_1,CVar7);
      FUN_0046bf33(&param_7,s_luff_S_00491c98);
      uStack_4 = 7;
      (*pcVar2)(param_1,iVar4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
    }
    else {
      if (DAT_004ac92c == 0) {
        CVar7 = 0xff00;
      }
      else {
        CVar7 = 0xffffff;
      }
      (*(code *)param_3)(param_1,CVar7);
      if (DAT_004a763c < 0x2bd) {
        FUN_0046bf33(&param_7,s_max_A_00491c90);
        uStack_4 = 9;
        (*pcVar2)(param_1,param_2,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
      }
      else {
        FUN_0046bf33(&param_7,s_max_A_00491c90);
        uStack_4 = 8;
        (*pcVar2)(param_1,iVar4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
      }
    }
  }
  else {
    if (DAT_004ac92c == 0) {
      CVar7 = 0xffff;
    }
    else {
      CVar7 = 0xffffff;
    }
    (*(code *)param_3)(param_1,CVar7);
    if (0 < DAT_004abb78) {
      (*(code *)param_3)(param_1,0);
    }
    if (2 < DAT_00491188) {
      FUN_0046bf33(&param_7,s_spn_P_00491ca8);
      uStack_4 = 10;
      (*pcVar2)(param_1,iVar4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_7);
    }
    if (DAT_00491188 != 2) goto LAB_0040b843;
    FUN_0046bf33(&param_7,s_wng_P_00491ca0);
    uStack_4 = 0xb;
    (*pcVar2)(param_1,iVar4,iVar1,(LPCSTR)param_7,*(int *)(param_7 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_7);
LAB_0040b843:
  FUN_0044d990((int)param_1,param_2,iVar1,iVar5,iVar6,0,-1);
  FUN_0044d990((int)param_1,iVar5,iVar1,iVar3,iVar6,1,-1);
  if (DAT_004ac92c == 0) {
    (*(code *)param_3)(param_1,0xffffff);
  }
  FUN_0046bf33(&param_2,s_shap_E_00491c88);
  uStack_4 = 0xc;
  (*pcVar2)(param_1,iVar5 + 1,iVar1,(LPCSTR)param_2,*(int *)(param_2 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  FUN_0044d990((int)param_1,iVar5,iVar1,iVar3,iVar6,0,-1);
  iVar5 = param_4;
  FUN_0044d990((int)param_1,iVar3,iVar1,param_4,iVar6,1,-1);
  if (DAT_004ac92c == 0) {
    (*(code *)param_3)(param_1,0xffff00);
  }
  FUN_0046bf33(&param_2,s_view_V_00491c80);
  uStack_4 = 0xd;
  (*pcVar2)(param_1,iStack_20,iVar1,(LPCSTR)param_2,*(int *)(param_2 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  FUN_0044d990((int)param_1,iVar3,iVar1,iVar5,iVar6,0,-1);
  (*apcStack_1c[0])(param_1,6);
  FUN_004706bd(param_1,(int *)apcStack_1c,iVar4,iVar6);
  CDC::LineTo(param_1,aiStack_14[0],iVar6);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

