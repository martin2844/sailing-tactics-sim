
void __cdecl
FUN_0040db60(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  int iVar7;
  Tact2010CString aTStack_28 [2];
  int iStack_20;
  code *apcStack_1c [2];
  Tact2010CString aTStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar5 = param_7;
  iVar6 = param_2;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2218;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = (param_4 + param_2 * 2) / 3 - DAT_004fe624 / 200;
  iVar3 = (param_2 + param_4 * 2) / 3;
  param_3 = param_3 + ((int)(param_7 * 5 + (param_7 * 5 >> 0x1f & 3U)) >> 2);
  if (DAT_004fe07c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  pcVar1 = *(code **)(*param_1 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar7 = 0xffff;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  iVar5 = iVar5 + param_3;
  FUN_00463f50(param_1,iVar6,param_3,iVar4,iVar5,1,-1);
  FUN_004b0613(aTStack_28,s_port_<_004daff4);
  iVar6 = iVar6 + 1;
  uStack_4 = 0;
  pcVar2 = *(code **)(*param_1 + 100);
  (*pcVar2)(param_1,iVar6,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,param_2,param_3,iVar4,iVar5,0,-1);
  if (DAT_005363e4 == 0) {
    iVar7 = 0xffff;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_00463f50(param_1,iVar4,param_3,iVar3,iVar5,1,-1);
  FUN_004b0613(aTStack_28,s_star_>_004dafec);
  uStack_4 = 1;
  (*pcVar2)(param_1,iVar4 + 1,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,iVar4,param_3,iVar3,iVar5,0,-1);
  if ((DAT_00511628 == 1) || (DAT_004f7098 == -1)) {
    iVar7 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar7 = 0xffff;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_00463f50(param_1,iVar3,param_3,param_4,iVar5,1,-1);
  FUN_004b0613(aTStack_28,s_beat_C_004dafe4);
  uStack_4 = 2;
  iStack_20 = iVar3 + 1;
  (*pcVar2)(param_1,iStack_20,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,iVar3,param_3,param_4,iVar5,0,-1);
  apcStack_1c[0] = *(code **)(*param_1 + 0x2c);
  (*apcStack_1c[0])(param_1,6);
  FUN_004b4d9d(param_1,(int *)aTStack_14,iVar6,iVar5);
  aTStack_14[0].data = (char *)(param_4 + -1);
  CDC::LineTo(param_1,(int)aTStack_14[0].data,iVar5);
  iVar5 = iVar5 + 1;
  param_3 = param_7 + iVar5;
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
  if ((DAT_004f7098 == 1) || (DAT_005356b8 == 1)) {
    iVar7 = 0;
LAB_0040de80:
    (*pcVar1)(param_1,iVar7);
LAB_0040de86:
    if (DAT_004fecd0 < 0x5a) goto LAB_0040de8f;
    FUN_004b0613(aTStack_28,s_jibe_J_004dafd4);
    uStack_4 = 4;
    (*pcVar2)(param_1,iVar6,iVar5,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  }
  else {
    if ((DAT_005363e4 == 0) && (DAT_004fecd0 < 0x5a)) {
      iVar7 = 0xffff00;
    }
    else {
      iVar7 = 0xffffff;
    }
    (*pcVar1)(param_1,iVar7);
    if (DAT_005363e4 != 0) goto LAB_0040de86;
    if (0x59 < DAT_004fecd0) {
      iVar7 = 0xff00;
      goto LAB_0040de80;
    }
LAB_0040de8f:
    FUN_004b0613(aTStack_28,s_tack_T_004dafdc);
    uStack_4 = 3;
    (*pcVar2)(param_1,iVar6,iVar5,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,0,-1);
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
  if (DAT_004fbbb0 < 2) {
    if (DAT_005363e4 == 0) {
      iVar7 = 0xffff00;
    }
    else {
      iVar7 = 0xffffff;
    }
  }
  else {
    iVar7 = 0;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_004b0613(aTStack_28,s_reach_H_004dafcc);
  uStack_4 = 5;
  (*pcVar2)(param_1,iVar4 + 1,iVar5,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,0,-1);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,1,-1);
  if ((DAT_004fbbb0 == 1) || (DAT_004f6a70 == 1)) {
    iVar7 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar7 = 0xffff00;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_004b0613(aTStack_28,s_run_D_004dafc4);
  uStack_4 = 6;
  (*pcVar2)(param_1,iStack_20,iVar5,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,0,-1);
  (*apcStack_1c[0])(param_1,6);
  iVar5 = param_3;
  FUN_004b4d9d(param_1,(int *)aTStack_28,iVar6,param_3);
  CDC::LineTo(param_1,(int)aTStack_14[0].data,iVar5);
  iVar5 = iVar5 + 1;
  param_3 = iVar5;
  if (DAT_005363e4 == 0) {
    (*pcVar1)(param_1,0xffff);
  }
  if (((DAT_004f4524 < 1) && (DAT_004fecd0 < 0x5b)) ||
     (aTStack_28[0].data = (char *)0x1, DAT_004da190 == 9)) {
    aTStack_28[0].data = (char *)0x0;
  }
  iVar5 = iVar5 + param_7;
  FUN_00463f50(param_1,param_2,param_3,iVar4,iVar5,1,-1);
  if ((aTStack_28[0].data == (char *)0x0) || (DAT_004f8cd0 < 1)) {
    if (DAT_00500388 == -1) {
      (*pcVar1)(param_1,0);
      FUN_004b0613(aTStack_28,s_sheet_S_004dafac);
      uStack_4 = 7;
      (*pcVar2)(param_1,iVar6,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
    }
    else {
      if (DAT_005363e4 == 0) {
        iVar7 = 0xff00;
      }
      else {
        iVar7 = 0xffffff;
      }
      (*pcVar1)(param_1,iVar7);
      FUN_004b0613(aTStack_28,s_sheet_A_004dafa4);
      uStack_4 = 8;
      (*pcVar2)(param_1,iVar6,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
    }
  }
  else {
    if (DAT_005363e4 == 0) {
      iVar7 = 0xffff;
    }
    else {
      iVar7 = 0xffffff;
    }
    (*pcVar1)(param_1,iVar7);
    if (0 < DAT_005350e0) {
      (*pcVar1)(param_1,0);
    }
    if (((2 < DAT_004da190) && (DAT_005364c4 == 0)) && (DAT_005364bc == 0)) {
      FUN_004b0613(aTStack_28,s_spin_P_004dafbc);
      uStack_4 = 9;
      (*pcVar2)(param_1,iVar6,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_28);
    }
    if (((DAT_004da190 != 2) && (DAT_005364c4 != 1)) && (DAT_005364bc != 1)) goto LAB_0040e28b;
    FUN_004b0613(aTStack_28,s_wing_P_004dafb4);
    uStack_4 = 10;
    (*pcVar2)(param_1,iVar6,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
LAB_0040e28b:
  FUN_00463f50(param_1,param_2,param_3,iVar4,iVar5,0,-1);
  if (DAT_005364c8 == 0) {
    FUN_00463f50(param_1,iVar4,param_3,iVar3,iVar5,1,-1);
    if (DAT_005363e4 == 0) {
      (*pcVar1)(param_1,0xffffff);
    }
    FUN_004b0613(aTStack_28,s_shape_E_004daf9c);
    uStack_4 = 0xb;
    (*pcVar2)(param_1,iVar4 + 1,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_28);
  }
  FUN_00463f50(param_1,iVar4,param_3,iVar3,iVar5,0,-1);
  FUN_00463f50(param_1,iVar3,param_3,param_4,iVar5,1,-1);
  if (DAT_005363e4 == 0) {
    (*pcVar1)(param_1,0xffff00);
  }
  FUN_004b0613(aTStack_28,s_view_V_004daf94);
  uStack_4 = 0xc;
  (*pcVar2)(param_1,iStack_20,param_3,aTStack_28[0].data,*(int *)(aTStack_28[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_28);
  FUN_00463f50(param_1,iVar3,param_3,param_4,iVar5,0,-1);
  (*apcStack_1c[0])(param_1,6);
  FUN_004b4d9d(param_1,(int *)apcStack_1c,iVar6,iVar5);
  CDC::LineTo(param_1,(int)aTStack_14[0].data,iVar5);
  iVar6 = iVar5;
  if (DAT_00511628 == 1) {
    iVar6 = param_7 + iVar5;
    param_3 = iVar5;
    FUN_00463f50(param_1,param_2,iVar5,iVar4,iVar6,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613(aTStack_14,s_pinch___004daf8c);
    uStack_4 = 0xd;
    param_4 = param_2 + 3;
    (*pcVar2)(param_1,param_4,param_3,aTStack_14[0].data,*(int *)(aTStack_14[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_14);
    if (DAT_005359e8 == -5) {
      (*pcVar1)(param_1,0);
      FUN_004b0613(aTStack_14,s_pinch___004daf8c);
      uStack_4 = 0xe;
      (*pcVar2)(param_1,param_4,param_3,aTStack_14[0].data,*(int *)(aTStack_14[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_14);
    }
    FUN_00463f50(param_1,iVar4,param_3,iVar3,iVar6,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_4,s_foot___004daf84);
    uStack_4 = 0xf;
    (*pcVar2)(param_1,iVar4 + 2,param_3,(char *)param_4,*(int *)(param_4 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_4);
    if (DAT_005359e8 == 5) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_4,s_foot___004daf84);
      uStack_4 = 0x10;
      (*pcVar2)(param_1,iVar4 + 2,param_3,(char *)param_4,*(int *)(param_4 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_4);
    }
  }
  if (DAT_004f6a70 == 1) {
    param_3 = param_7 + iVar6;
    FUN_00463f50(param_1,param_2,iVar6,iVar4,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_7,s_high___004daf7c);
    uStack_4 = 0x11;
    param_4 = param_2 + 3;
    (*pcVar2)(param_1,param_4,iVar6,(char *)param_7,*(int *)(param_7 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_7);
    if (DAT_004f3f68 == -7) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_2,s_high___004daf7c);
      uStack_4 = 0x12;
      (*pcVar2)(param_1,param_4,iVar6,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    FUN_00463f50(param_1,iVar4,iVar6,iVar3,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_3,s_low___004daf74);
    uStack_4 = 0x13;
    (*pcVar2)(param_1,iVar4 + 2,iVar6,(char *)param_3,*(int *)(param_3 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
    if (DAT_004f3f68 == 7) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_3,s_low___004daf74);
      uStack_4 = 0x14;
      (*pcVar2)(param_1,iVar4 + 2,iVar6,(char *)param_3,*(int *)(param_3 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
    }
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

