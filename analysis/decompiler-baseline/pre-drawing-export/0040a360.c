
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040a360(CDC *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7)

{
  CDC *pCVar1;
  bool bVar2;
  int unaff_EBX;
  code *pcVar3;
  int unaff_EBP;
  int iVar4;
  int unaff_ESI;
  code *pcVar5;
  int *unaff_FS_OFFSET;
  code *pcVar6;
  code *pcVar7;
  undefined4 uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  code *pcVar13;
  int iVar14;
  code *pcVar15;
  code *pcVar16;
  CDC *pCVar17;
  int iVar18;
  code *pcVar19;
  int iVar20;
  code *pcVar21;
  int iVar22;
  code *pcVar23;
  int iStack_2c;
  code *pcStack_28;
  code *pcStack_1c;
  undefined4 uStack_18;
  code *pcStack_14;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d978;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  iVar4 = (param_4 + param_2 * 2) / 3 - DAT_004a763c / 200;
  pcVar7 = (code *)(param_3 + -2 + (param_7 * 7) / 2);
  if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  (**(code **)(*(int *)param_1 + 0x38))();
  pcVar3 = pcVar7 + param_6;
  FUN_0044d990((int *)param_1,(int)param_1,(int)pcVar7,iVar4,pcVar3,1);
  FUN_0046bf33(&iStack_2c,&DAT_00491c78);
  pcStack_8 = (code *)0x0;
  pCVar1 = param_1 + 3;
  iVar10 = *(int *)(iStack_2c + -8);
  pCVar17 = pCVar1;
  (**(code **)(*(int *)param_1 + 100))();
  uStack_18 = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffffc4);
  FUN_0044d990((int *)param_1,iStack_c,(int)pcVar7,iVar4,pcVar3,0);
  if ((((iStack_c < DAT_004a774c) && (DAT_004a774c < iVar4)) && ((int)pcVar7 < DAT_004aa97c)) &&
     (DAT_004aa97c < (int)pcVar3)) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d58;
    DAT_004a8914 = 0;
    DAT_004a774c = 0;
    DAT_004aa97c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
    (*pcStack_8)();
    FUN_0046bf33(&stack0xffffffc0,&DAT_00491c78);
    pcStack_1c = (code *)0x1;
    (*pcStack_14)();
    uStack_18 = 0xffffffff;
    FUN_0046bec5((int *)&stack0xffffffc4);
  }
  if (DAT_004ac92c == 0) {
    iVar20 = 0xffff;
  }
  else {
    iVar20 = 0xffffff;
  }
  (*pcStack_8)();
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar7,iVar10,pcVar3,1);
  FUN_0046bf33(&stack0xffffffc0,&DAT_00491c70);
  pcStack_1c = (code *)0x2;
  iVar14 = *(int *)(unaff_ESI + -8);
  pcVar6 = pcVar7;
  (*pcStack_14)();
  iStack_2c = -1;
  FUN_0046bec5((int *)&stack0xffffffb0);
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar7,iVar20,pcVar3,0);
  if (((iVar4 < DAT_004a774c) && (DAT_004a774c < iVar20)) &&
     (((int)pcVar7 < DAT_004aa97c && (DAT_004aa97c < (int)pcVar3)))) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d60;
    DAT_004a8914 = 0;
    DAT_004a774c = 0;
    DAT_004aa97c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
    (*pcStack_1c)();
    FUN_0046bf33(&stack0xffffffac,&DAT_00491c70);
    (*pcStack_28)();
    iStack_2c = -1;
    FUN_0046bec5((int *)&stack0xffffffb0);
  }
  if ((DAT_004a8914 == 1) || (DAT_004a4dfc == -1)) {
    iVar20 = 0;
  }
  else if (DAT_004ac92c == 0) {
    iVar20 = 0xffff;
  }
  else {
    iVar20 = 0xffffff;
  }
  (*pcStack_1c)();
  FUN_0044d990((int *)param_1,iVar14,(int)pcVar7,(int)pcStack_1c,pcVar3,1);
  FUN_0046bf33(&stack0xffffffa8,&DAT_00491c68);
  pcVar9 = *(code **)(pCVar17 + -8);
  pcVar16 = pcVar7;
  (*pcStack_28)();
  FUN_0046bec5((int *)&stack0xffffff98);
  FUN_0044d990((int *)param_1,iVar20,(int)pcVar7,iStack_2c,pcVar3,0);
  if ((((iVar20 < DAT_004a774c) && (DAT_004a774c < iStack_2c)) && ((int)pcVar7 < DAT_004aa97c)) &&
     (DAT_004aa97c < (int)pcVar3)) {
    DAT_004a4dfc = -1;
    DAT_004abf9c = 0;
    DAT_004ac1ec = 0;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a684c = 0;
  }
  iVar20 = 6;
  (**(code **)(*(int *)param_1 + 0x2c))();
  FUN_004706bd(param_1,(int *)&stack0xffffffac,unaff_EBX + 1,(int)pcVar3);
  pcVar7 = (code *)0x3;
  CDC::LineTo(param_1,3,(int)pcVar3);
  pcVar3 = pcVar3 + 1;
  if ((DAT_004a4dfc == 1) || (DAT_004abf9c == 1)) {
    iVar14 = 0;
    (*(code *)pCVar1)();
  }
  else {
    if ((DAT_004ac92c == 0) && (DAT_004a7bcc < 0x5a)) {
      iVar14 = 0xffff00;
    }
    else {
      iVar14 = 0xffffff;
    }
    (*(code *)pCVar1)();
    if ((DAT_004ac92c == 0) && (0x59 < DAT_004a7bcc)) {
      (*(code *)pCVar1)();
    }
  }
  pcVar5 = pcStack_28 + (int)pcVar3;
  FUN_0044d990((int *)param_1,unaff_EBP,(int)pcVar3,iVar4,pcVar5,1);
  pcVar12 = pcVar3;
  if (DAT_004a7bcc < 0x5a) {
    FUN_0046bf33(&stack0xffffff98,&DAT_00491c60);
    pcVar23 = (code *)&DAT_00000005;
    iVar11 = *(int *)(pcVar6 + -8);
    pcVar13 = pcVar9;
    pcVar19 = pcVar6;
    (*(code *)0xffffffff)();
    iVar22 = -1;
    FUN_0046bec5((int *)&stack0xffffff88);
    if (((iVar10 < DAT_004a774c) && (DAT_004a774c < iVar4)) &&
       (((int)pcVar3 < DAT_004aa97c && (DAT_004aa97c < (int)pcVar5)))) {
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
    FUN_0046bf33(&stack0xffffff98,&DAT_00491c58);
    pcVar23 = (code *)&DAT_00000006;
    iVar11 = *(int *)(pcVar6 + -8);
    pcVar13 = pcVar9;
    pcVar19 = pcVar6;
    (*(code *)0xffffffff)();
    iVar22 = -1;
    FUN_0046bec5((int *)&stack0xffffff88);
    if ((((iVar10 < DAT_004a774c) && (DAT_004a774c < iVar4)) && ((int)pcVar3 < DAT_004aa97c)) &&
       (DAT_004aa97c < (int)pcVar5)) {
      DAT_004abf9c = 1;
      DAT_004a4dfc = 0;
      DAT_004a8914 = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
  }
  FUN_0044d990((int *)param_1,iVar10,(int)pcVar3,iVar4,pcVar5,0);
  if (DAT_004a684c < 2) {
    if (DAT_004ac92c == 0) {
      iVar10 = 0xffff00;
    }
    else {
      iVar10 = 0xffffff;
    }
  }
  else {
    iVar10 = 0;
  }
  (*pcVar23)();
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar3,iVar11,pcVar5,1);
  FUN_0046bf33(&stack0xffffff84,s_reach_00491c50);
  iVar11 = iVar4 + 2;
  pcVar21 = (code *)0x7;
  pcVar23 = pcVar3;
  (*pcVar7)();
  iVar18 = -1;
  FUN_0046bec5((int *)&stack0xffffff74);
  if (((iVar4 < DAT_004a774c) && (DAT_004a774c < iVar10)) &&
     (((int)pcVar3 < DAT_004aa97c && (DAT_004aa97c < (int)pcVar5)))) {
    DAT_004a684c = (0x59 < DAT_004a7bcc) + 2;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar3,iVar10,pcVar5,0);
  FUN_0044d990((int *)param_1,iVar10,(int)pcVar3,iVar22,pcVar5,1);
  if ((DAT_004a684c == 1) || (DAT_004a496c == 1)) {
    iVar10 = 0;
  }
  else if (DAT_004ac92c == 0) {
    iVar10 = 0xffff00;
  }
  else {
    iVar10 = 0xffffff;
  }
  (*pcVar21)();
  FUN_0046bf33(&stack0xffffff70,&DAT_00491c4c);
  uVar8 = *(undefined4 *)(pcVar6 + -8);
  pcVar7 = pcVar3;
  pcVar21 = pcVar6;
  (*pcVar19)();
  pcVar15 = (code *)0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff60);
  FUN_0044d990((int *)param_1,iVar10,(int)pcVar3,iVar18,pcVar5,0);
  if ((((iVar10 < DAT_004a774c) && (DAT_004a774c < iVar18)) && ((int)pcVar3 < DAT_004aa97c)) &&
     (DAT_004aa97c < (int)pcVar5)) {
    DAT_004a684c = 1;
    DAT_004a8914 = 0;
    DAT_004a496c = 0;
    DAT_004a4dfc = 0;
    DAT_004abf9c = 0;
  }
  iVar22 = 6;
  (*pcVar9)();
  FUN_004706bd(param_1,(int *)&stack0xffffff5c,iVar11,(int)pcVar5);
  CDC::LineTo(param_1,(int)pcVar12,(int)pcVar5);
  pcVar5 = pcVar5 + 1;
  if (DAT_004ac92c == 0) {
    (*pcVar13)();
  }
  if ((DAT_004a4388 < 1) && (DAT_004a7bcc < 0x5b)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  FUN_0044d990((int *)param_1,(int)pCVar17,(int)pcVar5,iVar4,pcVar5 + unaff_ESI,1);
  if ((bVar2) && (0 < DAT_004a5b80)) {
    if (DAT_004ac92c == 0) {
      pcVar3 = (code *)0xffff;
    }
    else {
      pcVar3 = (code *)0xffffff;
    }
    (*pcVar13)();
    if (0 < DAT_004abb74) {
      (*pcVar13)();
    }
    pcVar9 = pcVar15;
    if (2 < DAT_00491188) {
      FUN_0046bf33(&stack0xffffff58,&DAT_00491c44);
      pcVar9 = pcVar15;
      (*pcVar15)(uVar8,pcVar5,pcVar23);
      iVar14 = -1;
      FUN_0046bec5((int *)&stack0xffffff58);
    }
    if (DAT_00491188 == 2) {
      FUN_0046bf33(&stack0xffffff80,&DAT_00491c3c);
      (*pcVar15)(uVar8,pcVar5,pcVar9);
      iVar14 = -1;
      FUN_0046bec5((int *)&stack0xffffff80);
    }
    if (((DAT_004a774c <= (int)pcVar16) || (iVar4 <= DAT_004a774c)) ||
       ((DAT_004aa97c <= (int)pcVar5 || (((int)pcVar19 <= DAT_004aa97c || (DAT_00491188 < 2))))))
    goto LAB_0040aec8;
    DAT_004a4388 = DAT_004a4388 + 1;
    if (1 < DAT_004a4388) {
      DAT_004a4388 = 0;
    }
    (*(code *)pCVar17)();
    if (2 < DAT_00491188) {
      FUN_0046bf33(&stack0xffffff80,&DAT_00491c44);
      (*pcVar15)(uVar8,pcVar5,pcVar9);
      iVar14 = -1;
      FUN_0046bec5((int *)&stack0xffffff80);
    }
    if (DAT_00491188 != 2) goto LAB_0040aec8;
    FUN_0046bf33(&stack0xffffff80,&DAT_00491c3c);
    (*pcVar15)(uVar8,pcVar5,pcVar9);
  }
  else if (DAT_004a85d4 < 0x32) {
    if (DAT_004ac92c == 0) {
      pcVar3 = (code *)0x7f;
    }
    else {
      pcVar3 = (code *)0xffffff;
    }
    (*pcVar13)();
    FUN_0046bf33(&stack0xffffff58,&DAT_00491c34);
    pcVar9 = pcVar15;
    (*pcVar15)(uVar8,pcVar5,pcVar23);
    iVar14 = -1;
    FUN_0046bec5((int *)&stack0xffffff58);
    if (((DAT_004a774c <= (int)pcVar16) || (iVar4 <= DAT_004a774c)) ||
       ((DAT_004aa97c <= (int)pcVar5 || ((int)pcVar19 <= DAT_004aa97c)))) goto LAB_0040aec8;
    DAT_004a85d4 = 0x5a;
    (*(code *)pCVar17)();
    FUN_0046bf33(&stack0xffffff7c,&DAT_00491c34);
    (*pcVar15)(pcVar6,pcVar5,iVar20,*(undefined4 *)(iVar20 + -8));
  }
  else {
    if (DAT_004ac92c == 0) {
      pcVar3 = (code *)0xff00;
    }
    else {
      pcVar3 = (code *)0xffffff;
    }
    (*pcVar13)();
    FUN_0046bf33(&stack0xffffff58,&DAT_00491c30);
    pcVar9 = pcVar15;
    (*pcVar15)(iVar10,pcVar5,pcVar23);
    iVar14 = -1;
    FUN_0046bec5((int *)&stack0xffffff58);
    if ((((DAT_004a774c <= (int)pcVar16) || (iVar4 <= DAT_004a774c)) ||
        (DAT_004aa97c <= (int)pcVar5)) || ((int)pcVar19 <= DAT_004aa97c)) goto LAB_0040aec8;
    DAT_004a85d4 = -1;
    (*(code *)pCVar17)();
    FUN_0046bf33(&stack0xffffff7c,&DAT_00491c30);
    (*pcVar15)(uVar8,pcVar5,iVar20,*(undefined4 *)(iVar20 + -8));
  }
  iVar14 = -1;
  FUN_0046bec5((int *)&stack0xffffff80);
LAB_0040aec8:
  FUN_0044d990((int *)param_1,(int)pcVar16,(int)pcVar5,iVar4,pcVar19,0);
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar5,(int)pcVar6,pcVar19,1);
  iVar20 = 0xffffff;
  (*(code *)pCVar17)();
  FUN_0046bf33(&stack0xffffff80,s_shape_00491c28);
  pcVar13 = (code *)0x11;
  iVar10 = iVar4 + 2;
  pcVar6 = pcVar5;
  (*pcVar15)(iVar10,pcVar5,pcVar9,*(undefined4 *)(pcVar9 + -8));
  iVar11 = -1;
  FUN_0046bec5((int *)&stack0xffffff70);
  if ((((iVar4 < DAT_004a774c) && (DAT_004a774c < iVar20)) && ((int)pcVar5 < DAT_004aa97c)) &&
     (DAT_004aa97c < (int)pcVar16)) {
    DAT_004a776c = DAT_004a776c + 1;
    if (3 < DAT_004a776c) {
      DAT_004a776c = 1;
    }
    (*pcVar13)(0);
    FUN_0046bf33(&stack0xffffff6c,s_shape_00491c28);
    (*pcVar15)(iVar4 + 2,pcVar5,pcVar12,*(undefined4 *)(pcVar12 + -8));
    iVar11 = -1;
    FUN_0046bec5((int *)&stack0xffffff70);
  }
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar5,iVar20,pcVar16,0);
  FUN_0044d990((int *)param_1,iVar20,(int)pcVar5,iVar14,pcVar16,1);
  if (DAT_004ac92c == 0) {
    iVar4 = 0xffff00;
  }
  else {
    iVar4 = 0xffffff;
  }
  (*pcVar13)();
  FUN_0046bf33(&stack0xffffff6c,&DAT_00491c20);
  pcVar9 = (code *)0x13;
  (*pcVar15)(iVar22,pcVar5,pcVar12,*(undefined4 *)(pcVar12 + -8));
  FUN_0046bec5((int *)&stack0xffffff5c);
  FUN_0044d990((int *)param_1,iVar4,(int)pcVar5,iVar11,pcVar21,0);
  if (((iVar4 < DAT_004a774c) && (DAT_004a774c < iVar11)) &&
     (((int)pcVar5 < DAT_004aa97c && (DAT_004aa97c < (int)pcVar21)))) {
    DAT_004a4e8c = DAT_004a4e8c + 1;
    if (3 < DAT_004a4e8c) {
      DAT_004a4e8c = 1;
    }
    DAT_004aae24 = 0;
    (*pcVar9)(0);
    FUN_0046bf33(&stack0xffffff58,&DAT_00491c20);
    (*pcVar15)(pcVar6,pcVar5,pcVar23,*(undefined4 *)(pcVar23 + -8));
    FUN_0046bec5((int *)&stack0xffffff5c);
  }
  (*pcVar3)(6);
  FUN_004706bd(param_1,(int *)&stack0xffffff34,iVar10,(int)pcVar21);
  CDC::LineTo(param_1,iVar22,(int)pcVar21);
  DAT_004aa97c = 0;
  *unaff_FS_OFFSET = (int)pcVar7;
  return;
}

