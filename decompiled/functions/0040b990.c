
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040b990(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  LPCSTR pCVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar10;
  LPCSTR pCStack_2c;
  LPCSTR pCStack_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int local_18;
  int local_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047da48;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_0047033f((void *)param_1,1);
  iVar3 = DAT_004a72d0 / 0x1f;
  iVar6 = iVar3 + param_3;
  iVar8 = 2 - (int)(longlong)((double)DAT_004a763c * _DAT_00484d68);
  local_14[0] = param_4 - iVar8;
  local_18 = local_14[0] + -2;
  local_24 = iVar8;
  FUN_0044d990(param_1,local_18,param_3,param_4,iVar6,1,0);
  iVar9 = *(int *)param_1;
  (**(code **)(iVar9 + 0x34))((void *)param_1,0x7f7f7f);
  pcVar1 = *(code **)(iVar9 + 0x38);
  (*pcVar1)((void *)param_1,0);
  pcVar2 = *(code **)(iVar9 + 0x2c);
  (*pcVar2)((void *)param_1,7);
  pCStack_2c = (LPCSTR)0x1;
  pCVar4 = (LPCSTR)(iVar3 / 2);
  pCStack_28 = pCVar4;
  do {
    if (pCStack_2c == (LPCSTR)0x1) {
      iVar8 = param_4 * 4 + iVar8 * -3;
    }
    else {
      iVar8 = param_4 * 4 - iVar8;
    }
    iVar9 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
    if (DAT_004a9448 == 1) {
      iVar8 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    }
    else {
      iVar8 = iVar3 / 3;
    }
    iVar5 = iVar8 * 3 + (iVar8 * 3 >> 0x1f & 3U);
    iStack_20 = iVar5 >> 2;
    iStack_1c = iStack_20 - (iVar5 >> 0x1f) >> 1;
    iVar5 = iVar9;
    if ((0 < DAT_004a4610) && (DAT_004a9448 == 0)) {
      iVar5 = iVar9 - iVar3 / 3;
    }
    if ((DAT_004a4610 < 0) && (DAT_004a9448 == 0)) {
      iVar5 = iVar5 + iVar3 / 3;
    }
    (*pcVar2)((void *)param_1,0);
    pcVar7 = Ellipse_exref;
    if (DAT_004a9448 == 1) {
      Ellipse(*(HDC *)(param_1 + 4),iVar9 + iVar8 * -4,(int)(pCVar4 + (param_3 - iVar8)),
              iVar9 + iVar8 * 4,(int)(pCVar4 + iVar8 + param_3));
    }
    else {
      Ellipse(*(HDC *)(param_1 + 4),iVar9 + iVar8 * -2,(int)(pCVar4 + (param_3 - iVar8)),
              iVar9 + iVar8 * 2,(int)(pCVar4 + iVar8 + param_3));
      pcVar7 = Ellipse_exref;
    }
    if (DAT_004ac92c == 0) {
      if (DAT_004a469c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a469c);
      }
    }
    else {
      (*pcVar2)((void *)param_1,4);
    }
    (*pcVar7)(*(HDC *)(param_1 + 4),iVar5 - iStack_20,(int)(pCVar4 + (param_3 - iStack_20)),
              iStack_20 + iVar5,(int)(pCVar4 + iStack_20 + param_3));
    (*pcVar2)((void *)param_1,4);
    (*pcVar7)(*(HDC *)(param_1 + 4),iVar5 - iStack_1c,(int)(pCVar4 + (param_3 - iStack_1c)),
              iStack_1c + iVar5,(int)(pCVar4 + iStack_1c + param_3));
    pCStack_2c = pCStack_2c + 1;
    iVar8 = local_24;
  } while ((int)pCStack_2c < 3);
  if ((DAT_004a4610 == 0) && (DAT_004a9448 == 0)) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff00;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar8 = local_18;
  iVar9 = iVar6 + iVar3;
  FUN_0044d990(param_1,local_18,iVar6,param_4,iVar9,1,0);
  FUN_0046bf33(&pCStack_2c,s_ahead_00491c18);
  iVar5 = local_14[0];
  uStack_4 = 0;
  pcVar7 = *(code **)(*(int *)param_1 + 100);
  (*pcVar7)((void *)param_1,local_14[0],iVar6,pCStack_2c,*(int *)(pCStack_2c + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_2c);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar6);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar6);
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,0,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0((CDC *)param_1,(param_4 - DAT_004a763c / 0x82) + -2,iVar6 + 2,0xb4,10);
  (*pcVar2)((void *)param_1,7);
  if (((DAT_004a4610 < 1) || (DAT_004a4610 == 0xb4)) || (DAT_004a9448 != 0)) {
    if (DAT_004ac92c == 0) {
      CVar10 = 0xffff00;
    }
    else {
      CVar10 = 0xffffff;
    }
  }
  else {
    CVar10 = 0;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar6 = iVar3 + iVar9;
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,1,0);
  FUN_0046bf33(&pCStack_2c,&DAT_00491bc4);
  uStack_4 = 1;
  (*pcVar7)((void *)param_1,iVar5,iVar9,pCStack_2c,*(int *)(pCStack_2c + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_2c);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar9);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar9);
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,0,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0((CDC *)param_1,(param_4 - DAT_004a763c / 0x32) + -2,(int)(pCStack_28 + iVar9),0x5a,10
              );
  (*pcVar2)((void *)param_1,7);
  if ((DAT_004a4610 < 0) && (DAT_004a9448 == 0)) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff00;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar9 = iVar3 + iVar6;
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,1,0);
  FUN_0046bf33(&pCStack_2c,s_right_00491b6c);
  uStack_4 = 2;
  (*pcVar7)((void *)param_1,iVar5,iVar6,pCStack_2c,*(int *)(pCStack_2c + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_2c);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar6);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar6);
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,0,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0((CDC *)param_1,param_4 + -3,(int)(pCStack_28 + iVar6),0x10e,10);
  (*pcVar2)((void *)param_1,7);
  if ((DAT_004a4610 == 0xb4) && (DAT_004a9448 == 0)) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff00;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar6 = iVar9 + iVar3;
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,1,0);
  FUN_0046bf33(&pCStack_28,s_astern_00491b1c);
  uStack_4 = 3;
  (*pcVar7)((void *)param_1,iVar5,iVar9,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar9);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar9);
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,0,0);
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  FUN_00430eb0((CDC *)param_1,(param_4 - DAT_004a763c / 0x82) + -2,iVar6 + -1,0,10);
  (*pcVar2)((void *)param_1,7);
  if (DAT_004a9448 == 1) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar9 = iVar6 + iVar3;
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,1,0);
  FUN_0046bf33(&pCStack_28,s_upwn_5_00491cfc);
  uStack_4 = 4;
  (*pcVar7)((void *)param_1,iVar5,iVar6,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar6);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar6);
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,0,0);
  if (DAT_004a9448 == -1) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar6 = iVar3 + iVar9;
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,1,0);
  FUN_0046bf33(&pCStack_28,s_dnwn_7_00491cf4);
  uStack_4 = 5;
  (*pcVar7)((void *)param_1,iVar5,iVar9,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar9);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar9);
  FUN_0044d990(param_1,iVar8,iVar9,param_4,iVar6,0,0);
  if (DAT_004a9448 == 100) {
    CVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar10 = 0xffff00;
  }
  else {
    CVar10 = 0xffffff;
  }
  (*pcVar1)((void *)param_1,CVar10);
  iVar9 = iVar3 + iVar6;
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,1,0);
  FUN_0046bf33(&pCStack_28,s_boat1_9_00491ce8);
  uStack_4 = 6;
  (*pcVar7)((void *)param_1,iVar5,iVar6,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  (*pcVar2)((void *)param_1,6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar6);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar6);
  FUN_004706bd((void *)param_1,local_14,iVar5,iVar9 + 1);
  CDC::LineTo((CDC *)param_1,param_4 + -2,iVar9 + 1);
  FUN_0044d990(param_1,iVar8,iVar6,param_4,iVar9,0,0);
  FUN_0040b130((CDC *)param_1,param_2,iVar6,param_4,param_5,param_6,iVar3);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

