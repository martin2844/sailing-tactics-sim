
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040a360(CDC *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  CDC *this;
  int iVar4;
  CDC *pCVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  COLORREF CVar8;
  LPCSTR pCStack_2c;
  LPCSTR pCStack_28;
  LPCSTR apCStack_24 [2];
  code *apcStack_1c [2];
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d978;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = (param_4 + param_2 * 2) / 3 - DAT_004a763c / 200;
  iVar2 = (param_2 + param_4 * 2) / 3;
  iVar7 = param_3 + -2 + (param_7 * 7) / 2;
  if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  param_3 = *(undefined4 *)(*(int *)this + 0x38);
  if (DAT_004ac92c == 0) {
    CVar8 = 0xffff;
  }
  else {
    CVar8 = 0xffffff;
  }
  (*(code *)param_3)(this,CVar8);
  iVar4 = param_7 + iVar7;
  FUN_0044d990((int)this,param_2,iVar7,iVar6,iVar4,1,-1);
  FUN_0046bf33(&pCStack_28,&DAT_00491c78);
  uStack_4 = 0;
  param_1 = *(CDC **)(*(int *)this + 100);
  iVar1 = param_2 + 3;
  (*(code *)param_1)(this,iVar1,iVar7,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  FUN_0044d990((int)this,param_2,iVar7,iVar6,iVar4,0,-1);
  if ((((param_2 < DAT_004a774c) && (DAT_004a774c < iVar6)) && (iVar7 < DAT_004aa97c)) &&
     (DAT_004aa97c < iVar4)) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d58;
    DAT_004a8914 = 0;
    DAT_004a774c = 0;
    DAT_004aa97c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
    (*(code *)param_3)(this,0);
    FUN_0046bf33(&pCStack_28,&DAT_00491c78);
    uStack_4 = 1;
    (*(code *)param_1)(this,iVar1,iVar7,pCStack_28,*(int *)(pCStack_28 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_28);
  }
  if (DAT_004ac92c == 0) {
    CVar8 = 0xffff;
  }
  else {
    CVar8 = 0xffffff;
  }
  (*(code *)param_3)(this,CVar8);
  FUN_0044d990((int)this,iVar6,iVar7,iVar2,iVar4,1,-1);
  FUN_0046bf33(&pCStack_28,&DAT_00491c70);
  uStack_4 = 2;
  (*(code *)param_1)(this,iVar6 + 3,iVar7,pCStack_28,*(int *)(pCStack_28 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_28);
  FUN_0044d990((int)this,iVar6,iVar7,iVar2,iVar4,0,-1);
  if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar2)) &&
     ((iVar7 < DAT_004aa97c && (DAT_004aa97c < iVar4)))) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d60;
    DAT_004a8914 = 0;
    DAT_004a774c = 0;
    DAT_004aa97c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
    (*(code *)param_3)(this,0);
    FUN_0046bf33(&pCStack_28,&DAT_00491c70);
    uStack_4 = 3;
    (*(code *)param_1)(this,iVar6 + 3,iVar7,pCStack_28,*(int *)(pCStack_28 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&pCStack_28);
  }
  if ((DAT_004a8914 == 1) || (DAT_004a4dfc == -1)) {
    CVar8 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar8 = 0xffff;
  }
  else {
    CVar8 = 0xffffff;
  }
  (*(code *)param_3)(this,CVar8);
  FUN_0044d990((int)this,iVar2,iVar7,param_4,iVar4,1,-1);
  FUN_0046bf33(&pCStack_2c,&DAT_00491c68);
  pCStack_28 = (LPCSTR)(iVar2 + 3);
  uStack_4 = 4;
  (*(code *)param_1)(this,(int)pCStack_28,iVar7,pCStack_2c,*(int *)(pCStack_2c + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&pCStack_2c);
  FUN_0044d990((int)this,iVar2,iVar7,param_4,iVar4,0,-1);
  if ((((iVar2 < DAT_004a774c) && (DAT_004a774c < param_4)) && (iVar7 < DAT_004aa97c)) &&
     (DAT_004aa97c < iVar4)) {
    DAT_004a4dfc = -1;
    DAT_004abf9c = 0;
    DAT_004ac1ec = 0;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
  }
  apcStack_1c[0] = *(code **)(*(int *)this + 0x2c);
  (*apcStack_1c[0])(this,6);
  pCStack_2c = (LPCSTR)(param_2 + 1);
  FUN_004706bd(this,aiStack_14,(int)pCStack_2c,iVar4);
  aiStack_14[0] = param_4 + -1;
  CDC::LineTo(this,aiStack_14[0],iVar4);
  iVar7 = param_3;
  iVar4 = iVar4 + 1;
  if ((DAT_004a4dfc == 1) || (DAT_004abf9c == 1)) {
    (*(code *)param_3)(this,0);
  }
  else {
    if ((DAT_004ac92c == 0) && (DAT_004a7bcc < 0x5a)) {
      CVar8 = 0xffff00;
    }
    else {
      CVar8 = 0xffffff;
    }
    (*(code *)param_3)(this,CVar8);
    if ((DAT_004ac92c == 0) && (0x59 < DAT_004a7bcc)) {
      (*(code *)iVar7)(this,0xff00);
    }
  }
  iVar7 = param_7 + iVar4;
  FUN_0044d990((int)this,param_2,iVar4,iVar6,iVar7,1,-1);
  if (DAT_004a7bcc < 0x5a) {
    FUN_0046bf33(apCStack_24,&DAT_00491c60);
    uStack_4 = 5;
    (*(code *)param_1)(this,iVar1,iVar4,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_24);
    if (((param_2 < DAT_004a774c) && (DAT_004a774c < iVar6)) &&
       ((iVar4 < DAT_004aa97c && (DAT_004aa97c < iVar7)))) {
      DAT_004a4dfc = 1;
      DAT_004a46ac = 1;
      DAT_004a8914 = 0;
      DAT_004a684c = 0;
      DAT_004abf9c = 0;
      DAT_004a496c = 0;
      DAT_004a41f4 = DAT_004a5b80;
    }
  }
  else {
    FUN_0046bf33(apCStack_24,&DAT_00491c58);
    uStack_4 = 6;
    (*(code *)param_1)(this,iVar1,iVar4,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_24);
    if ((((param_2 < DAT_004a774c) && (DAT_004a774c < iVar6)) && (iVar4 < DAT_004aa97c)) &&
       (DAT_004aa97c < iVar7)) {
      DAT_004abf9c = 1;
      DAT_004a4dfc = 0;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
  }
  FUN_0044d990((int)this,param_2,iVar4,iVar6,iVar7,0,-1);
  if (DAT_004a684c < 2) {
    if (DAT_004ac92c == 0) {
      CVar8 = 0xffff00;
    }
    else {
      CVar8 = 0xffffff;
    }
  }
  else {
    CVar8 = 0;
  }
  (*(code *)param_3)(this,CVar8);
  FUN_0044d990((int)this,iVar6,iVar4,iVar2,iVar7,1,-1);
  FUN_0046bf33(apCStack_24,s_reach_00491c50);
  uStack_4 = 7;
  (*(code *)param_1)(this,iVar6 + 2,iVar4,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_24);
  if (((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar2)) &&
     ((iVar4 < DAT_004aa97c && (DAT_004aa97c < iVar7)))) {
    DAT_004a684c = (0x59 < DAT_004a7bcc) + 2;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  FUN_0044d990((int)this,iVar6,iVar4,iVar2,iVar7,0,-1);
  FUN_0044d990((int)this,iVar2,iVar4,param_4,iVar7,1,-1);
  if ((DAT_004a684c == 1) || (DAT_004a496c == 1)) {
    CVar8 = 0;
  }
  else if (DAT_004ac92c == 0) {
    CVar8 = 0xffff00;
  }
  else {
    CVar8 = 0xffffff;
  }
  (*(code *)param_3)(this,CVar8);
  FUN_0046bf33(apCStack_24,&DAT_00491c4c);
  uStack_4 = 8;
  (*(code *)param_1)(this,(int)pCStack_28,iVar4,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)apCStack_24);
  FUN_0044d990((int)this,iVar2,iVar4,param_4,iVar7,0,-1);
  if ((((iVar2 < DAT_004a774c) && (DAT_004a774c < param_4)) && (iVar4 < DAT_004aa97c)) &&
     (DAT_004aa97c < iVar7)) {
    DAT_004a684c = 1;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  (*apcStack_1c[0])(this,6);
  FUN_004706bd(this,(int *)apCStack_24,(int)pCStack_2c,iVar7);
  CDC::LineTo(this,aiStack_14[0],iVar7);
  iVar7 = iVar7 + 1;
  if (DAT_004ac92c == 0) {
    (*(code *)param_3)(this,0xffff);
  }
  if ((DAT_004a4388 < 1) && (DAT_004a7bcc < 0x5b)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  param_7 = param_7 + iVar7;
  FUN_0044d990((int)this,param_2,iVar7,iVar6,param_7,1,-1);
  iVar4 = param_3;
  if ((bVar3) && (0 < DAT_004a5b80)) {
    if (DAT_004ac92c == 0) {
      CVar8 = 0xffff;
    }
    else {
      CVar8 = 0xffffff;
    }
    (*(code *)param_3)(this,CVar8);
    if (0 < DAT_004abb74) {
      (*(code *)iVar4)(this,0);
    }
    pCVar5 = param_1;
    if (2 < DAT_00491188) {
      FUN_0046bf33(apCStack_24,&DAT_00491c44);
      pCVar5 = param_1;
      uStack_4 = 0xd;
      (*(code *)param_1)(this,iVar1,iVar7,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)apCStack_24);
    }
    if (DAT_00491188 == 2) {
      FUN_0046bf33(&param_1,&DAT_00491c3c);
      uStack_4 = 0xe;
      (*(code *)pCVar5)(this,iVar1,iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
    }
    if (((DAT_004a774c <= param_2) || (iVar6 <= DAT_004a774c)) ||
       ((DAT_004aa97c <= iVar7 || ((param_7 <= DAT_004aa97c || (DAT_00491188 < 2))))))
    goto LAB_0040aec8;
    DAT_004a4388 = DAT_004a4388 + 1;
    if (1 < DAT_004a4388) {
      DAT_004a4388 = 0;
    }
    (*(code *)param_3)(this,0);
    if (2 < DAT_00491188) {
      FUN_0046bf33(&param_1,&DAT_00491c44);
      uStack_4 = 0xf;
      (*(code *)pCVar5)(this,iVar1,iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_00491188 != 2) goto LAB_0040aec8;
    FUN_0046bf33(&param_1,&DAT_00491c3c);
    uStack_4 = 0x10;
    (*(code *)pCVar5)(this,iVar1,iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  else if (DAT_004a85d4 < 0x32) {
    if (DAT_004ac92c == 0) {
      CVar8 = 0x7f;
    }
    else {
      CVar8 = 0xffffff;
    }
    (*(code *)param_3)(this,CVar8);
    FUN_0046bf33(apCStack_24,&DAT_00491c34);
    pCVar5 = param_1;
    uStack_4 = 9;
    (*(code *)param_1)(this,iVar1,iVar7,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_24);
    if (((DAT_004a774c <= param_2) || (iVar6 <= DAT_004a774c)) ||
       ((DAT_004aa97c <= iVar7 || (param_7 <= DAT_004aa97c)))) goto LAB_0040aec8;
    DAT_004a85d4 = 0x5a;
    (*(code *)param_3)(this,0xffffff);
    FUN_0046bf33(&param_1,&DAT_00491c34);
    uStack_4 = 10;
    (*(code *)pCVar5)(this,iVar1,iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  else {
    if (DAT_004ac92c == 0) {
      CVar8 = 0xff00;
    }
    else {
      CVar8 = 0xffffff;
    }
    (*(code *)param_3)(this,CVar8);
    FUN_0046bf33(apCStack_24,&DAT_00491c30);
    pCVar5 = param_1;
    uStack_4 = 0xb;
    (*(code *)param_1)(this,(int)pCStack_2c,iVar7,apCStack_24[0],*(int *)(apCStack_24[0] + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)apCStack_24);
    if ((((DAT_004a774c <= param_2) || (iVar6 <= DAT_004a774c)) || (DAT_004aa97c <= iVar7)) ||
       (param_7 <= DAT_004aa97c)) goto LAB_0040aec8;
    DAT_004a85d4 = -1;
    (*(code *)param_3)(this,0xffffff);
    FUN_0046bf33(&param_1,&DAT_00491c30);
    uStack_4 = 0xc;
    (*(code *)pCVar5)(this,(int)pCStack_2c,iVar7,(LPCSTR)param_1,*(int *)(param_1 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
LAB_0040aec8:
  FUN_0044d990((int)this,param_2,iVar7,iVar6,param_7,0,-1);
  FUN_0044d990((int)this,iVar6,iVar7,iVar2,param_7,1,-1);
  (*(code *)param_3)(this,0xffffff);
  FUN_0046bf33(&param_2,s_shape_00491c28);
  uStack_4 = 0x11;
  (*(code *)pCVar5)(this,iVar6 + 2,iVar7,(LPCSTR)param_2,*(int *)(param_2 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  if ((((iVar6 < DAT_004a774c) && (DAT_004a774c < iVar2)) && (iVar7 < DAT_004aa97c)) &&
     (DAT_004aa97c < param_7)) {
    DAT_004a776c = DAT_004a776c + 1;
    if (3 < DAT_004a776c) {
      DAT_004a776c = 1;
    }
    (*(code *)param_3)(this,0);
    FUN_0046bf33(&param_2,s_shape_00491c28);
    uStack_4 = 0x12;
    (*(code *)pCVar5)(this,iVar6 + 2,iVar7,(LPCSTR)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_2);
  }
  FUN_0044d990((int)this,iVar6,iVar7,iVar2,param_7,0,-1);
  FUN_0044d990((int)this,iVar2,iVar7,param_4,param_7,1,-1);
  if (DAT_004ac92c == 0) {
    CVar8 = 0xffff00;
  }
  else {
    CVar8 = 0xffffff;
  }
  (*(code *)param_3)(this,CVar8);
  FUN_0046bf33(&param_2,&DAT_00491c20);
  uStack_4 = 0x13;
  (*(code *)pCVar5)(this,(int)pCStack_28,iVar7,(LPCSTR)param_2,*(int *)(param_2 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5(&param_2);
  FUN_0044d990((int)this,iVar2,iVar7,param_4,param_7,0,-1);
  iVar6 = param_7;
  if (((iVar2 < DAT_004a774c) && (DAT_004a774c < param_4)) &&
     ((iVar7 < DAT_004aa97c && (DAT_004aa97c < param_7)))) {
    DAT_004a4e8c = DAT_004a4e8c + 1;
    if (3 < DAT_004a4e8c) {
      DAT_004a4e8c = 1;
    }
    DAT_004aae24 = 0;
    (*(code *)param_3)(this,0);
    FUN_0046bf33(&param_2,&DAT_00491c20);
    uStack_4 = 0x14;
    (*(code *)pCVar5)(this,(int)pCStack_28,iVar7,(LPCSTR)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5(&param_2);
  }
  (*apcStack_1c[0])(this,6);
  FUN_004706bd(this,(int *)apcStack_1c,(int)pCStack_2c,iVar6);
  CDC::LineTo(this,aiStack_14[0],iVar6);
  DAT_004aa97c = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

