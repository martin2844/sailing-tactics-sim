
void __cdecl FUN_0041d890(int *param_1)

{
  char cVar1;
  HDC hdc;
  char **ppcVar2;
  TactCString TVar3;
  int c;
  TactCString *pTVar4;
  TactCString *pTVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  code *pcVar11;
  int iVar12;
  char *pcVar13;
  code **ppcVar14;
  code **ppcVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 *unaff_FS_OFFSET;
  bool bVar18;
  bool bVar19;
  TactCString local_a8;
  TactCString TStack_a4;
  TactCString TStack_a0;
  TactCString local_9c;
  char local_98 [4];
  code *local_94;
  undefined1 local_90;
  TactCString local_8c;
  undefined1 local_88;
  TactCString local_84;
  int local_80;
  char acStack_7c [52];
  char local_48 [4];
  char local_44 [4];
  char acStack_40 [52];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e41d;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_48[0] = s_north_0049343c[0];
  local_48[1] = s_north_0049343c[1];
  local_48[2] = s_north_0049343c[2];
  local_48[3] = s_north_0049343c[3];
  local_44[0] = s_north_0049343c[4];
  local_44[1] = s_north_0049343c[5];
  local_88 = DAT_00493438;
  hdc = (HDC)param_1[1];
  local_9c.data = (char *)s_south_0049342c._0_4_;
  local_94 = DAT_00493424;
  local_84.data = (char *)*param_1;
  local_8c.data = DAT_00493434;
  pcVar11 = *(code **)(local_84.data + 0x2c);
  local_90 = DAT_00493428;
  local_80 = 0x11;
  local_a8.data = (char *)0xf;
  local_98[0] = s_south_0049342c[4];
  local_98[1] = s_south_0049342c[5];
  (*pcVar11)(param_1,6);
  (*pcVar11)(param_1,0);
  Rectangle((HDC)param_1[1],0,0,DAT_004a763c,DAT_004a72d0);
  if (700 < DAT_004a763c) {
    local_80 = 0x13;
    local_a8.data = (char *)0x11;
  }
  if (900 < DAT_004a763c) {
    local_80 = 0x16;
    local_a8.data = (char *)0x14;
  }
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  TextOutA(hdc,0x14,0x19,s_Pre_Race_Forecast__00493410,0x12);
  iVar8 = DAT_004a5b98;
  if (DAT_004a5b98 == 1) {
    uVar6 = 0xffffffff;
    TStack_a4.data = acStack_7c;
    pcVar9 = s_Sunshine__00493404;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = TStack_a4.data;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  bVar19 = SBORROW4(iVar8,2);
  bVar18 = false;
  if (iVar8 == 2) {
    uVar6 = 0xffffffff;
    TStack_a4.data = acStack_7c;
    pcVar9 = s_Partly_cloudy__004933f4;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = TStack_a4.data;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  iVar12 = DAT_004a8a78;
  if (!bVar18 && bVar19 == iVar8 + -2 < 0) {
    uVar6 = 0xffffffff;
    pcVar9 = &DAT_004933e8;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = acStack_7c;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  if (DAT_004a8a78 == 1) {
    uVar6 = 0xffffffff;
    TStack_a4.data = acStack_40;
    pcVar9 = s_low_humidity__004933d8;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = TStack_a4.data;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  bVar19 = SBORROW4(iVar12,2);
  bVar18 = false;
  if (iVar12 == 2) {
    uVar6 = 0xffffffff;
    TStack_a4.data = acStack_40;
    pcVar9 = s_moderate_humidity__004933c4;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = TStack_a4.data;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  if (!bVar18 && bVar19 == iVar12 + -2 < 0) {
    uVar6 = 0xffffffff;
    pcVar9 = s_high_humidity__004933b4;
    do {
      pcVar13 = pcVar9;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar13 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar13;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar13 + -uVar6;
    pcVar13 = acStack_40;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar13 = pcVar13 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar13 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar13 = pcVar13 + 1;
    }
  }
  uVar6 = 0xffffffff;
  pcVar9 = acStack_40;
  do {
    pcVar13 = pcVar9;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar13 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar13;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar9 = acStack_7c;
  do {
    pcVar17 = pcVar9;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar17 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar17;
  } while (cVar1 != '\0');
  pcVar9 = pcVar13 + -uVar6;
  pcVar13 = pcVar17 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar13 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar13 = pcVar13 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar13 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar13 = pcVar13 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar9 = acStack_7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,0x3c,acStack_7c,~uVar6 - 1);
  pcVar9 = local_a8.data + 0x3c;
  iVar8 = wsprintfA(acStack_7c,s_Maximum_temperature_of__d__00493398,DAT_004a7758);
  TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,iVar8);
  pcVar13 = s_High_00493390;
  TStack_a0.data = local_a8.data * 2;
  pcVar9 = pcVar9 + TStack_a0.data;
  if (DAT_004aa8bc != 1) {
    pcVar13 = &DAT_00493388;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = acStack_7c;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar13 = s_pressure_to_the_00493374;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar13 = acStack_7c;
  do {
    pcVar16 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar16 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar16;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = pcVar16 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (DAT_004a8990 == 1) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 2) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 3) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 4) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 5) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 6) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 7) {
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 8) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  uVar6 = 0xffffffff;
  pcVar13 = (char *)&DAT_0049300c;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar13 = acStack_7c;
  do {
    pcVar16 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar16 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar16;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = pcVar16 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar13 = acStack_7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  if (DAT_004ac998 == 0) {
    TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
  }
  pcVar9 = pcVar9 + local_a8.data;
  uVar6 = 0xffffffff;
  pcVar13 = s_Wind_from_the_00493364;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = acStack_7c;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (DAT_004a5e88 == 1) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 2) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 3) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 4) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pTVar4 = &local_8c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 5) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 6) {
    uVar6 = 0xffffffff;
    pTVar4 = &local_9c;
    do {
      pTVar5 = pTVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pTVar5 = (TactCString *)((int)&pTVar4->data + 1);
      ppcVar2 = &pTVar4->data;
      pTVar4 = pTVar5;
    } while (*(char *)ppcVar2 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)pTVar5 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 7) {
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 8) {
    uVar6 = 0xffffffff;
    pcVar13 = local_48;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    ppcVar14 = &local_94;
    do {
      ppcVar15 = ppcVar14;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      ppcVar15 = (code **)((int)ppcVar14 + 1);
      cVar1 = *(char *)ppcVar14;
      ppcVar14 = ppcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar17 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    pcVar13 = (char *)((int)ppcVar15 - uVar6);
    pcVar17 = pcVar17 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  wsprintfA(acStack_40,s_at__d_to__d_knots__0049334c,DAT_004a70dc + -2,DAT_004a70dc + 3);
  uVar6 = 0xffffffff;
  pcVar13 = acStack_40;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar13 = acStack_7c;
  do {
    pcVar16 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar16 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar16;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = pcVar16 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar13 = acStack_7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
  TVar3.data = TStack_a0.data;
  pcVar9 = pcVar9 + TStack_a0.data;
  iVar8 = wsprintfA(acStack_7c,s_Water_temperature_is__d__00493330,DAT_004a609c);
  TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,iVar8);
  pcVar9 = pcVar9 + local_a8.data;
  if (4 < DAT_004a79ec) {
    TextOutA(hdc,0x14,(int)pcVar9,s_Seabreeze_likely_0049331c,0x10);
  }
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f);
  }
  pcVar9 = pcVar9 + TVar3.data;
  uVar6 = 0xffffffff;
  pcVar13 = s_Time_is_now_0049330c;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = acStack_7c;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  wsprintfA(acStack_40,s__d_hours__d_min_004932f8,DAT_004a4be4,DAT_004a5e84);
  uVar6 = 0xffffffff;
  pcVar13 = acStack_40;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar13 = acStack_7c;
  do {
    pcVar16 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar16 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar16;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = pcVar16 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar13 = acStack_7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f00);
  }
  pcVar9 = pcVar9 + local_a8.data;
  uVar6 = 0xffffffff;
  pcVar13 = s_True_wind_at_committee_boat_is_n_004932d4;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = acStack_7c;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  wsprintfA(acStack_40,s__d_knots_004932c8,DAT_004aa390);
  pcVar11 = TextOutA_exref;
  uVar6 = 0xffffffff;
  pcVar13 = acStack_40;
  do {
    pcVar17 = pcVar13;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar8 = -1;
  pcVar13 = acStack_7c;
  do {
    pcVar16 = pcVar13;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar16 = pcVar13 + 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar16;
  } while (cVar1 != '\0');
  pcVar13 = pcVar17 + -uVar6;
  pcVar17 = pcVar16 + -1;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
    pcVar13 = pcVar13 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar13;
    pcVar13 = pcVar13 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar6 = 0xffffffff;
  pcVar13 = acStack_7c;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
  TVar3.data = TStack_a0.data;
  pcVar9 = pcVar9 + TStack_a0.data;
  if (DAT_004ac1e0 == 1) {
    if (DAT_004ac92c == 0) {
      SetTextColor(hdc,0x7f7f7f);
    }
    iVar8 = 0xf;
    pcVar13 = s_High_shoreline__004932b8;
  }
  else {
    if (DAT_004ac92c == 0) {
      SetTextColor(hdc,0x7f7f);
    }
    iVar8 = 0xe;
    pcVar13 = s_Low_shoreline__004932a8;
  }
  TextOutA(hdc,0x14,(int)pcVar9,pcVar13,iVar8);
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  if (0 < DAT_004ac1dc) {
    pcVar9 = pcVar9 + TVar3.data;
    uVar6 = 0xffffffff;
    pcVar13 = s_High_tides_at_00493298;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = acStack_7c;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    iVar8 = DAT_004a796c + 0xc;
    if (0x17 < iVar8) {
      iVar8 = DAT_004a796c + -0xc;
    }
    wsprintfA(acStack_40,s__d_00_and__d_00__00493284,DAT_004a796c,iVar8);
    uVar6 = 0xffffffff;
    pcVar13 = acStack_40;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pcVar13 = acStack_7c;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
    pcVar9 = pcVar9 + local_a8.data;
    uVar6 = 0xffffffff;
    pcVar13 = s_Low_tides_at_00493274;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = acStack_7c;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    iVar8 = DAT_004a8020 + 0xc;
    if (0x17 < iVar8) {
      iVar8 = DAT_004a8020 + -0xc;
    }
    wsprintfA(acStack_40,s__d_00_and__d_00__00493284,DAT_004a8020,iVar8);
    uVar6 = 0xffffffff;
    pcVar13 = acStack_40;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pcVar13 = acStack_7c;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
    pcVar9 = pcVar9 + local_a8.data;
    uVar6 = 0xffffffff;
    pcVar13 = s_Tidal_current_floods_from_the_00493254;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = acStack_7c;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    if (DAT_004aa804 == 4) {
      uVar6 = 0xffffffff;
      pcVar13 = s_north__0049324c;
      do {
        pcVar17 = pcVar13;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar13 = acStack_7c;
      do {
        pcVar16 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar16 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar16;
      } while (cVar1 != '\0');
      pcVar13 = pcVar17 + -uVar6;
      pcVar17 = pcVar16 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 1) {
      uVar6 = 0xffffffff;
      pcVar13 = s_east__00493244;
      do {
        pcVar17 = pcVar13;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar13 = acStack_7c;
      do {
        pcVar16 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar16 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar16;
      } while (cVar1 != '\0');
      pcVar13 = pcVar17 + -uVar6;
      pcVar17 = pcVar16 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 2) {
      uVar6 = 0xffffffff;
      pcVar13 = s_south__0049323c;
      do {
        pcVar17 = pcVar13;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar13 = acStack_7c;
      do {
        pcVar16 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar16 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar16;
      } while (cVar1 != '\0');
      pcVar13 = pcVar17 + -uVar6;
      pcVar17 = pcVar16 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 3) {
      uVar6 = 0xffffffff;
      pcVar13 = s_west__00493234;
      do {
        pcVar17 = pcVar13;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar13 = acStack_7c;
      do {
        pcVar16 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar16 = pcVar13 + 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar16;
      } while (cVar1 != '\0');
      pcVar13 = pcVar17 + -uVar6;
      pcVar17 = pcVar16 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    uVar6 = 0xffffffff;
    pcVar13 = acStack_7c;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
    pcVar9 = pcVar9 + local_a8.data;
    uVar6 = 0xffffffff;
    pcVar13 = s_Maximum_current_is_00493220;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = acStack_7c;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    wsprintfA(acStack_40,s__d__d_knots__00493210,DAT_004ac1dc / 10,DAT_004ac1dc % 10);
    uVar6 = 0xffffffff;
    pcVar13 = acStack_40;
    do {
      pcVar17 = pcVar13;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar8 = -1;
    pcVar13 = acStack_7c;
    do {
      pcVar16 = pcVar13;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar16 = pcVar13 + 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar16;
    } while (cVar1 != '\0');
    pcVar13 = pcVar17 + -uVar6;
    pcVar17 = pcVar16 + -1;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar13;
      pcVar13 = pcVar13 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar13;
      pcVar13 = pcVar13 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar6 = 0xffffffff;
    pcVar13 = acStack_7c;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar9,acStack_7c,~uVar6 - 1);
    pcVar11 = TextOutA_exref;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(local_84.data + 0x38))(param_1,0xff);
  }
  FUN_0046bf33(&TStack_a0,s_Movement_suspended__Click_mouse_o_004918bc);
  uStack_4 = 0;
  local_94 = *(code **)(local_84.data + 100);
  (*local_94)(param_1,0x14,(int)(pcVar9 + (int)local_a8.data * 3),TStack_a0.data,
              *(int *)(TStack_a0.data + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&TStack_a0);
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0xff0000);
  }
  (*pcVar11)(hdc,0x17c,0x19,s_Wind_history_at_the_committee_bo_004931ec,0x23);
  local_a8.data = (char *)0x2;
  TStack_a0.data = (char *)0xa;
  piVar10 = &DAT_004a9458;
  iVar8 = local_80 * 2 + 0x28;
  local_9c.data = (char *)0x0;
  do {
    local_84.data = (char *)(DAT_004abc7c - ((int)local_a8.data * DAT_004abc7c) / 0xc);
    TStack_a4.data = DAT_004a70f0;
    iVar12 = (((DAT_004aa590 * *piVar10) / 400 -
              ((int)(DAT_004aa590 + (DAT_004aa590 >> 0x1f & 7U)) >> 3)) - (int)local_84.data) +
             DAT_004a4f8c;
    pcVar9 = DAT_004a70f0;
    if ((int)local_a8.data % 3 == 0) {
      pcVar9 = DAT_004a70f0 + *(int *)(local_9c.data + 0x4a4e9c);
      iVar12 = *(int *)(local_9c.data + 0x4ac0a4) - (int)local_84.data;
      local_9c.data = local_9c.data + 4;
    }
    c = wsprintfA(acStack_7c,s__d__d__d_knots_004931d8,DAT_004a5bac + -1,TStack_a0.data,pcVar9);
    TextOutA(hdc,0x17c,iVar8,acStack_7c,c);
    iVar12 = FUN_00413cb0(iVar12);
    iVar12 = wsprintfA(acStack_7c,s__d_deg_004931d0,iVar12);
    TextOutA(hdc,0x1fe,iVar8,acStack_7c,iVar12);
    piVar10 = piVar10 + 1;
    local_a8.data = local_a8.data + 1;
    TStack_a0.data = TStack_a0.data + 5;
    iVar8 = iVar8 + local_80;
  } while ((int)piVar10 < 0x4a947d);
  bVar18 = DAT_004a888c != 1;
  pTVar4 = FUN_00413d00(&local_8c,(bVar18 + 3) * DAT_0049115c);
  uStack_4 = 1;
  pTVar5 = FUN_00413d00(&local_a8,(bVar18 + 1) * DAT_0049115c);
  uStack_4._0_1_ = 2;
  pTVar5 = FUN_0046c14f(&TStack_a0,s_Time_between_shifts_is_004931b8,pTVar5);
  uStack_4._0_1_ = 3;
  pTVar5 = FUN_0046c0db(&local_84,pTVar5,&DAT_004931b0);
  uStack_4._0_1_ = 4;
  pTVar4 = FUN_0046c075(&local_9c,pTVar5,pTVar4);
  uStack_4._0_1_ = 5;
  pTVar4 = FUN_0046c0db(&TStack_a4,pTVar4,s_min__004931a8);
  uStack_4._0_1_ = 6;
  (*local_94)(param_1,0x17c,local_80 * 0xd + 0x28,pTVar4->data,*(int *)(pTVar4->data + -8));
  uStack_4._0_1_ = 5;
  FUN_0046bec5((int *)&TStack_a4);
  uStack_4._0_1_ = 4;
  FUN_0046bec5((int *)&local_9c);
  uStack_4._0_1_ = 3;
  FUN_0046bec5((int *)&local_84);
  uStack_4._0_1_ = 2;
  FUN_0046bec5((int *)&TStack_a0);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  FUN_0046bec5((int *)&local_a8);
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_8c);
  DAT_004aa838 = DAT_004ac0a4 - DAT_004a4f8c;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

