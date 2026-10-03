
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040c980(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  int iVar6;
  int iVar7;
  int iVar8;
  Tact2010CString TStack_28;
  Tact2010CString aTStack_24 [2];
  code *apcStack_1c [2];
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2158;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar4 = (param_4 + param_2 * 2) / 3 - DAT_004fe624 / 200;
  iVar3 = (param_2 + param_4 * 2) / 3;
  iVar5 = param_3 + -2 + ((int)(param_7 * 5 + (param_7 * 5 >> 0x1f & 3U)) >> 2);
  if (DAT_004fe07c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  pcVar1 = *(code **)(*param_1 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar6 = 0xffff;
  }
  else {
    iVar6 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar6);
  iVar6 = param_2;
  param_3 = param_7 + iVar5;
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
  FUN_004b0613(&TStack_28,&DAT_004daf6c);
  iVar6 = iVar6 + 3;
  uStack_4 = 0;
  pcVar2 = *(code **)(*param_1 + 100);
  (*pcVar2)(param_1,iVar6,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,0,-1);
  if ((((param_2 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (iVar5 < DAT_005233a4)) &&
     (DAT_005233a4 < param_3)) {
    _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc580;
    DAT_00511624 = 0;
    DAT_004fe75c = 0;
    DAT_005233a4 = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_004f6a6c = 0;
    DAT_004fbbac = 0;
    (*pcVar1)(param_1,0);
    FUN_004b0613(&TStack_28,&DAT_004daf6c);
    uStack_4 = 1;
    (*pcVar2)(param_1,iVar6,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_28);
  }
  if (DAT_005363e4 == 0) {
    iVar7 = 0xffff;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
  FUN_004b0613(&TStack_28,&DAT_004daf64);
  uStack_4 = 2;
  (*pcVar2)(param_1,iVar4 + 3,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,0,-1);
  if (((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
     ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
    _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc588;
    DAT_00511624 = 0;
    DAT_004fe75c = 0;
    DAT_005233a4 = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_004f6a6c = 0;
    DAT_004fbbac = 0;
    (*pcVar1)(param_1,0);
    FUN_004b0613(&TStack_28,&DAT_004daf64);
    uStack_4 = 3;
    (*pcVar2)(param_1,iVar4 + 3,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_28);
  }
  if ((DAT_00511624 == 1) || (DAT_004f7094 == -1)) {
    iVar7 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar7 = 0xffff;
  }
  else {
    iVar7 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar7);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,1,-1);
  FUN_004b0613(&TStack_28,&DAT_004daf5c);
  uStack_4 = 4;
  iVar7 = iVar3 + 3;
  (*pcVar2)(param_1,iVar7,iVar5,TStack_28.data,*(int *)(TStack_28.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_28);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,0,-1);
  if ((((iVar3 < DAT_004fe75c) && (DAT_004fe75c < param_4)) && (iVar5 < DAT_005233a4)) &&
     (DAT_005233a4 < param_3)) {
    DAT_004f7094 = -1;
    DAT_005356b4 = 0;
    DAT_005359e4 = 0;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004fbbac = 0;
  }
  apcStack_1c[0] = *(code **)(*param_1 + 0x2c);
  (*apcStack_1c[0])(param_1,6);
  iVar5 = param_3;
  TStack_28.data = (char *)(param_2 + 1);
  FUN_004b4d9d(param_1,aiStack_14,(int)TStack_28.data,param_3);
  aiStack_14[0] = param_4 + -1;
  CDC::LineTo(param_1,aiStack_14[0],iVar5);
  iVar5 = iVar5 + 1;
  if ((DAT_004f7094 == 1) || (DAT_005356b4 == 1)) {
    iVar8 = 0;
LAB_0040ce04:
    (*pcVar1)(param_1,iVar8);
  }
  else {
    if ((DAT_005363e4 == 0) && (DAT_004feccc < 0x5a)) {
      iVar8 = 0xffff00;
    }
    else {
      iVar8 = 0xffffff;
    }
    (*pcVar1)(param_1,iVar8);
    if ((DAT_005363e4 == 0) && (0x59 < DAT_004feccc)) {
      iVar8 = 0xff00;
      goto LAB_0040ce04;
    }
  }
  param_3 = param_7 + iVar5;
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
  if (DAT_004feccc < 0x5a) {
    FUN_004b0613(aTStack_24,&DAT_004daf54);
    uStack_4 = 5;
    (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_24);
    if (((param_2 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) &&
       ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
      DAT_004f7094 = 1;
      DAT_004f4a74 = 1;
      DAT_004f4354 = DAT_004f8cd0;
      DAT_00511624 = 0;
      DAT_004fbbac = 0;
      DAT_005356b4 = 0;
      DAT_004f6a6c = 0;
    }
  }
  else {
    FUN_004b0613(aTStack_24,s_jibe_004daf4c);
    uStack_4 = 6;
    (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_24);
    if ((((param_2 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) && (iVar5 < DAT_005233a4)) &&
       (DAT_005233a4 < param_3)) {
      DAT_005356b4 = 1;
      DAT_004f7094 = 0;
      DAT_00511624 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
    }
  }
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,0,-1);
  if (DAT_004fbbac < 2) {
    if (DAT_005363e4 == 0) {
      iVar8 = 0xffff00;
    }
    else {
      iVar8 = 0xffffff;
    }
  }
  else {
    iVar8 = 0;
  }
  (*pcVar1)(param_1,iVar8);
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
  FUN_004b0613(aTStack_24,s_reach_004daf44);
  uStack_4 = 7;
  (*pcVar2)(param_1,iVar4 + 2,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_24);
  if (((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
     ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
    DAT_004fbbac = (0x59 < DAT_004feccc) + 2;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
  }
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,0,-1);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,1,-1);
  if ((DAT_004fbbac == 1) || (DAT_004f6a6c == 1)) {
    iVar8 = 0;
  }
  else if (DAT_005363e4 == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  FUN_004b0613(aTStack_24,&DAT_004daf40);
  uStack_4 = 8;
  (*pcVar2)(param_1,iVar7,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_24);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,0,-1);
  if ((((iVar3 < DAT_004fe75c) && (DAT_004fe75c < param_4)) && (iVar5 < DAT_005233a4)) &&
     (DAT_005233a4 < param_3)) {
    DAT_004fbbac = 1;
    DAT_00511624 = 0;
    DAT_004f6a6c = 0;
    DAT_004f7094 = 0;
    DAT_005356b4 = 0;
    DAT_004f3f64 = 0;
  }
  (*apcStack_1c[0])(param_1,6);
  iVar5 = param_3;
  FUN_004b4d9d(param_1,(int *)aTStack_24,(int)TStack_28.data,param_3);
  CDC::LineTo(param_1,aiStack_14[0],iVar5);
  iVar5 = iVar5 + 1;
  if (DAT_005363e4 == 0) {
    (*pcVar1)(param_1,0xffff);
  }
  if (((DAT_004f4520 < 1) && (DAT_004feccc < 0x5b)) ||
     (aTStack_24[0].data = (char *)0x1, DAT_004da190 == 9)) {
    aTStack_24[0].data = (char *)0x0;
  }
  param_3 = param_7 + iVar5;
  FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
  if ((aTStack_24[0].data == (char *)0x0) || (DAT_004f8cd0 < 1)) {
    if (DAT_00500384 == -1) {
      (*pcVar1)(param_1,0);
      FUN_004b0613(aTStack_24,s_sheet_004daf28);
      uStack_4 = 9;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
      if (((DAT_004fe75c <= param_2) || (iVar4 <= DAT_004fe75c)) ||
         ((DAT_005233a4 <= iVar5 || (param_3 <= DAT_005233a4)))) goto LAB_0040d519;
      DAT_00500384 = 0x5a;
      (*pcVar1)(param_1,0xffffff);
      FUN_004b0613(aTStack_24,s_sheet_004daf28);
      uStack_4 = 10;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
    }
    else {
      (*pcVar1)(param_1,0xffffff);
      FUN_004b0613(aTStack_24,s_sheet_004daf28);
      uStack_4 = 0xb;
      (*pcVar2)(param_1,(int)TStack_28.data,iVar5,aTStack_24[0].data,
                *(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
      if ((((DAT_004fe75c <= param_2) || (iVar4 <= DAT_004fe75c)) || (DAT_005233a4 <= iVar5)) ||
         (param_3 <= DAT_005233a4)) goto LAB_0040d519;
      DAT_00500384 = -1;
      (*pcVar1)(param_1,0);
      FUN_004b0613(aTStack_24,s_sheet_004daf28);
      uStack_4 = 0xc;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
    }
  }
  else {
    if (DAT_005363e4 == 0) {
      iVar8 = 0xffff;
    }
    else {
      iVar8 = 0xffffff;
    }
    (*pcVar1)(param_1,iVar8);
    if (0 < DAT_005350dc) {
      (*pcVar1)(param_1,0);
    }
    if (((2 < DAT_004da190) && (DAT_005364c4 == 0)) && (DAT_005364bc == 0)) {
      FUN_004b0613(aTStack_24,&DAT_004daf38);
      uStack_4 = 0xd;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
    }
    if (((DAT_004da190 == 2) || (DAT_005364c4 == 1)) || (DAT_005364bc == 1)) {
      FUN_004b0613(aTStack_24,&DAT_004daf30);
      uStack_4 = 0xe;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
    }
    if (((DAT_004fe75c <= param_2) || (iVar4 <= DAT_004fe75c)) ||
       ((DAT_005233a4 <= iVar5 || ((param_3 <= DAT_005233a4 || (DAT_004da190 < 2))))))
    goto LAB_0040d519;
    DAT_004f4520 = DAT_004f4520 + 1;
    if (1 < DAT_004f4520) {
      DAT_004f4520 = 0;
    }
    (*pcVar1)(param_1,0);
    if (2 < DAT_004da190) {
      FUN_004b0613(aTStack_24,&DAT_004daf38);
      uStack_4 = 0xf;
      (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
    }
    if (DAT_004da190 != 2) goto LAB_0040d519;
    FUN_004b0613(aTStack_24,&DAT_004daf30);
    uStack_4 = 0x10;
    (*pcVar2)(param_1,iVar6,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_24);
LAB_0040d519:
  if (DAT_005364c8 == 0) {
    FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,0,-1);
    FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
    (*pcVar1)(param_1,0xffffff);
    FUN_004b0613(aTStack_24,s_shape_004daf20);
    uStack_4 = 0x11;
    (*pcVar2)(param_1,iVar4 + 2,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(aTStack_24);
    if ((((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar5 < DAT_005233a4)) &&
       (DAT_005233a4 < param_3)) {
      DAT_004fe77c = DAT_004fe77c + 1;
      if (3 < DAT_004fe77c) {
        DAT_004fe77c = 1;
      }
      (*pcVar1)(param_1,0);
      FUN_004b0613(aTStack_24,s_shape_004daf20);
      uStack_4 = 0x12;
      (*pcVar2)(param_1,iVar4 + 2,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(aTStack_24);
    }
  }
  FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,0,-1);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,1,-1);
  if (DAT_005363e4 == 0) {
    iVar8 = 0xffff00;
  }
  else {
    iVar8 = 0xffffff;
  }
  (*pcVar1)(param_1,iVar8);
  FUN_004b0613(aTStack_24,&DAT_004daf18);
  uStack_4 = 0x13;
  (*pcVar2)(param_1,iVar7,iVar5,aTStack_24[0].data,*(int *)(aTStack_24[0].data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(aTStack_24);
  FUN_00463f50(param_1,iVar3,iVar5,param_4,param_3,0,-1);
  if (((iVar3 < DAT_004fe75c) && (DAT_004fe75c < param_4)) &&
     ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
    DAT_004f71c4 = DAT_004f71c4 + 1;
    if (3 < DAT_004f71c4) {
      DAT_004f71c4 = 1;
    }
    DAT_00523a5c = 0;
    (*pcVar1)(param_1,0);
    FUN_004b0613((Tact2010CString *)&param_4,&DAT_004daf18);
    uStack_4 = 0x14;
    (*pcVar2)(param_1,iVar7,iVar5,(char *)param_4,*(int *)(param_4 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_4);
  }
  (*apcStack_1c[0])(param_1,6);
  iVar5 = param_3;
  FUN_004b4d9d(param_1,(int *)apcStack_1c,(int)TStack_28.data,param_3);
  CDC::LineTo(param_1,aiStack_14[0],iVar5);
  if (DAT_00511624 == 1) {
    param_3 = param_7 + iVar5;
    FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_4,s_pinch_004daf10);
    uStack_4 = 0x15;
    (*pcVar2)(param_1,iVar6,iVar5,(char *)param_4,*(int *)(param_4 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_4);
    if (((param_2 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) &&
       ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
      DAT_005359e4 = -5;
      DAT_005233a4 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
    }
    if (DAT_005359e4 == -5) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_4,s_pinch_004daf10);
      uStack_4 = 0x16;
      (*pcVar2)(param_1,iVar6,iVar5,(char *)param_4,*(int *)(param_4 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_4);
    }
    FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_4,s_foot_004daf08);
    uStack_4 = 0x17;
    (*pcVar2)(param_1,iVar4 + 2,iVar5,(char *)param_4,*(int *)(param_4 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_4);
    if ((((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) && (iVar5 < DAT_005233a4)) &&
       (DAT_005233a4 < param_3)) {
      DAT_005359e4 = 5;
      DAT_005233a4 = 0;
      DAT_004f6a6c = 0;
      DAT_004fbbac = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
    }
    if (DAT_005359e4 == 5) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_4,s_foot_004daf08);
      uStack_4 = 0x18;
      (*pcVar2)(param_1,iVar4 + 2,iVar5,(char *)param_4,*(int *)(param_4 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_4);
    }
  }
  iVar5 = param_3;
  if (DAT_004f6a6c == 1) {
    param_3 = param_7 + param_3;
    FUN_00463f50(param_1,param_2,iVar5,iVar4,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_4,&DAT_004daf00);
    uStack_4 = 0x19;
    (*pcVar2)(param_1,iVar6,iVar5,(char *)param_4,*(int *)(param_4 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_4);
    if (((param_2 < DAT_004fe75c) && (DAT_004fe75c < iVar4)) &&
       ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
      DAT_004f3f64 = -7;
      DAT_005233a4 = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
    }
    if (DAT_004f3f64 == -7) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_2,&DAT_004daf00);
      uStack_4 = 0x1a;
      (*pcVar2)(param_1,iVar6,iVar5,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    FUN_00463f50(param_1,iVar4,iVar5,iVar3,param_3,1,-1);
    (*pcVar1)(param_1,0xffff);
    FUN_004b0613((Tact2010CString *)&param_2,&DAT_004daef8);
    uStack_4 = 0x1b;
    param_4 = iVar4 + 2;
    (*pcVar2)(param_1,param_4,iVar5,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    if (((iVar4 < DAT_004fe75c) && (DAT_004fe75c < iVar3)) &&
       ((iVar5 < DAT_005233a4 && (DAT_005233a4 < param_3)))) {
      DAT_004f3f64 = 7;
      DAT_005233a4 = 0;
      DAT_004f7094 = 0;
      DAT_005356b4 = 0;
    }
    if (DAT_004f3f64 == 7) {
      (*pcVar1)(param_1,0);
      FUN_004b0613((Tact2010CString *)&param_2,&DAT_004daef8);
      uStack_4 = 0x1c;
      (*pcVar2)(param_1,param_4,iVar5,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
  }
  DAT_005233a4 = 0;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

