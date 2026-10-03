
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004298f0(int *param_1)

{
  char cVar1;
  char **ppcVar2;
  int c;
  Tact2010CString *pTVar3;
  Tact2010CString *pTVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  HDC hdc;
  code *pcVar9;
  int iVar10;
  Tact2010CString TVar11;
  char *pcVar12;
  code **ppcVar13;
  code **ppcVar14;
  char *pcVar15;
  char *pcVar16;
  int *piVar17;
  undefined4 *unaff_FS_OFFSET;
  bool bVar18;
  bool bVar19;
  Tact2010CString local_b4;
  Tact2010CString TStack_b0;
  Tact2010CString local_ac;
  Tact2010CString local_a8;
  char local_a4 [4];
  Tact2010CString local_a0;
  undefined1 local_9c;
  Tact2010CString local_98;
  undefined1 local_94;
  Tact2010CString local_90;
  HDC local_8c;
  code *local_88;
  char local_84 [4];
  char acStack_80 [52];
  code *local_4c;
  double dStack_48;
  char acStack_40 [52];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c311a;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_a8.data = (char *)s_north_00619fd0._0_4_;
  local_9c = DAT_00619fcc;
  local_a4[0] = s_north_00619fd0[4];
  local_a4[1] = s_north_00619fd0[5];
  hdc = (HDC)param_1[1];
  local_98.data = DAT_00619fc0;
  local_ac.data = (char *)*param_1;
  local_88 = (code *)s_south_00619fb8._0_4_;
  pcVar9 = *(code **)(local_ac.data + 0x2c);
  local_a0.data = _DAT_00619fc8;
  local_94 = DAT_00619fc4;
  local_90.data = (char *)0x11;
  local_b4.data = (char *)0xf;
  local_84[0] = s_south_00619fb8[4];
  local_84[1] = s_south_00619fb8[5];
  local_8c = hdc;
  local_4c = pcVar9;
  (*pcVar9)(param_1,6);
  (*pcVar9)(param_1,0);
  Rectangle((HDC)param_1[1],0,0,DAT_004fe624,DAT_004fe2a8);
  if (700 < DAT_004fe624) {
    local_90.data = (char *)0x13;
    local_b4.data = (char *)0x11;
  }
  if (900 < DAT_004fe624) {
    local_90.data = (char *)0x16;
    local_b4.data = (char *)0x14;
  }
  if (DAT_005363e4 == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  TextOutA(hdc,0x14,0x19,s_Pre_Race_Forecast__004dd5d8,0x12);
  if (DAT_004f8d78 == 1) {
    uVar5 = 0xffffffff;
    pcVar8 = "Sunshine, ";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  bVar19 = SBORROW4(DAT_004f8d78,2);
  bVar18 = false;
  if (DAT_004f8d78 == 2) {
    uVar5 = 0xffffffff;
    pcVar8 = "Partly cloudy, ";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  if (!bVar18 && bVar19 == DAT_004f8d78 + -2 < 0) {
    uVar5 = 0xffffffff;
    pcVar8 = "Cloudy, ";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  if (DAT_00511cf8 == 1) {
    uVar5 = 0xffffffff;
    pcVar8 = "low humidity.";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_40;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  bVar19 = SBORROW4(DAT_00511cf8,2);
  bVar18 = false;
  if (DAT_00511cf8 == 2) {
    uVar5 = 0xffffffff;
    pcVar8 = "moderate humidity.";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_40;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  if (!bVar18 && bVar19 == DAT_00511cf8 + -2 < 0) {
    uVar5 = 0xffffffff;
    pcVar8 = "";
    do {
      pcVar12 = pcVar8;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar12 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar12;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar12 + -uVar5;
    pcVar12 = acStack_40;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  uVar5 = 0xffffffff;
  pcVar8 = acStack_40;
  do {
    pcVar12 = pcVar8;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar12 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar12;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar8 = acStack_80;
  do {
    pcVar16 = pcVar8;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar16 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar16;
  } while (cVar1 != '\0');
  pcVar8 = pcVar12 + -uVar5;
  pcVar12 = pcVar16 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar12 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar12 = pcVar12 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar8 = acStack_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,0x3c,acStack_80,~uVar5 - 1);
  pcVar8 = local_b4.data + 0x3c;
  iVar7 = wsprintfA(acStack_80,"Maximum temperature of %d.",DAT_004fe76c);
  TextOutA(hdc,0x14,(int)pcVar8,acStack_80,iVar7);
  pcVar12 = "High ";
  TStack_b0.data = local_b4.data * 2;
  pcVar8 = pcVar8 + TStack_b0.data;
  if (DAT_00523244 != 1) {
    pcVar12 = "Low ";
  }
  uVar5 = 0xffffffff;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = acStack_80;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar12 = "pressure to the ";
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar12 = acStack_80;
  do {
    pcVar15 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar15 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar1 != '\0');
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = pcVar15 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  if (DAT_005116b0 == 1) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 2) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 3) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 4) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 5) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 6) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 7) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_005116b0 == 8) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  uVar5 = 0xffffffff;
  pcVar12 = (char *)&DAT_004dd054;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar12 = acStack_80;
  do {
    pcVar15 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar15 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar1 != '\0');
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = pcVar15 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar12 = acStack_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  if (DAT_0053645c == 0) {
    TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
  }
  pcVar8 = pcVar8 + local_b4.data;
  uVar5 = 0xffffffff;
  pcVar12 = "Wind from the ";
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = acStack_80;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  if (DAT_004fad38 == 1) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 2) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 3) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 4) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_a0;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 5) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 6) {
    uVar5 = 0xffffffff;
    ppcVar13 = &local_88;
    do {
      ppcVar14 = ppcVar13;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 7) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  if (DAT_004fad38 == 8) {
    uVar5 = 0xffffffff;
    pTVar3 = &local_a8;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pTVar3 = &local_98;
    do {
      pTVar4 = pTVar3;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pTVar4 = (Tact2010CString *)((int)&pTVar3->data + 1);
      ppcVar2 = &pTVar3->data;
      pTVar3 = pTVar4;
    } while (*(char *)ppcVar2 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar16 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    pcVar12 = (char *)((int)pTVar4 - uVar5);
    pcVar16 = pcVar16 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  wsprintfA(acStack_40,s_at__d_to__d_knots__004dd514,DAT_004fe074 + -2,DAT_004fe074 + 3);
  uVar5 = 0xffffffff;
  pcVar12 = acStack_40;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar12 = acStack_80;
  do {
    pcVar15 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar15 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar1 != '\0');
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = pcVar15 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar12 = acStack_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
  pcVar8 = pcVar8 + TStack_b0.data;
  pcVar9 = TextOutA_exref;
  if (DAT_004da1f8 == 0) {
    iVar7 = wsprintfA(acStack_80,"Water temperature is %d.",DAT_004faf8c);
    pcVar9 = TextOutA_exref;
    TextOutA(hdc,0x14,(int)pcVar8,acStack_80,iVar7);
    pcVar8 = pcVar8 + local_b4.data;
  }
  if (4 < DAT_004fea5c) {
    if ((DAT_004da1f8 == 10) || (DAT_004da1f8 == 0xc)) {
      iVar7 = 0x12;
      pcVar12 = s_Lakebreeze_likely__004dd4b4;
    }
    else if (DAT_004da19c == 6) {
      iVar7 = 0x1b;
      pcVar12 = s_Southerly_Seabreeze_likely__004dd4dc;
    }
    else {
      iVar7 = 0x11;
      pcVar12 = s_Seabreeze_likely__004dd4c8;
    }
    (*pcVar9)(hdc,0x14,(int)pcVar8,pcVar12,iVar7);
  }
  if (DAT_005363e4 == 0) {
    SetTextColor(hdc,0x7f);
  }
  pcVar8 = pcVar8 + TStack_b0.data;
  uVar5 = 0xffffffff;
  pcVar12 = s_Time_is_now_004dd4a4;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = acStack_80;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  wsprintfA(acStack_40,s__d_hours__d_min_004dd490,DAT_004f6d60,DAT_004fad34);
  uVar5 = 0xffffffff;
  pcVar12 = acStack_40;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar12 = acStack_80;
  do {
    pcVar15 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar15 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar1 != '\0');
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = pcVar15 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar12 = acStack_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
  if (DAT_005363e4 == 0) {
    SetTextColor(hdc,0x7f00);
  }
  pcVar8 = pcVar8 + local_b4.data;
  uVar5 = 0xffffffff;
  pcVar12 = s_True_wind_at_committee_boat_is_n_004dd46c;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = acStack_80;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  wsprintfA(acStack_40,s__d_knots_004dd460,DAT_00522ad0);
  uVar5 = 0xffffffff;
  pcVar12 = acStack_40;
  do {
    pcVar16 = pcVar12;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar16 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar16;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar7 = -1;
  pcVar12 = acStack_80;
  do {
    pcVar15 = pcVar12;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar15 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar15;
  } while (cVar1 != '\0');
  pcVar12 = pcVar16 + -uVar5;
  pcVar16 = pcVar15 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar16 = pcVar16 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar16 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar16 = pcVar16 + 1;
  }
  uVar5 = 0xffffffff;
  pcVar12 = acStack_80;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar12 + 1;
  } while (cVar1 != '\0');
  TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
  pcVar8 = pcVar8 + TStack_b0.data;
  if (DAT_004da1f8 < 999) {
    if (DAT_005359d8 == 1) {
      if (DAT_005363e4 == 0) {
        SetTextColor(hdc,0x7f7f7f);
      }
      if (DAT_004da1f8 == 0xc) {
        iVar7 = 0x19;
        pcVar12 = s_High_shoreline_buildings__004dd444;
      }
      else {
        iVar7 = 0xf;
        pcVar12 = s_High_shoreline__004dd434;
      }
    }
    else {
      if (DAT_005363e4 == 0) {
        SetTextColor(hdc,0x7f7f);
      }
      iVar7 = 0xe;
      pcVar12 = s_Low_shoreline__004dd424;
    }
    TextOutA(hdc,0x14,(int)pcVar8,pcVar12,iVar7);
  }
  if (DAT_005363e4 == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  if ((0 < DAT_005359d0) && (DAT_00536510 == 0)) {
    pcVar8 = pcVar8 + TStack_b0.data;
    uVar5 = 0xffffffff;
    pcVar12 = "High tides at ";
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    iVar7 = DAT_004fe9cc + 0xc;
    if (0x17 < iVar7) {
      iVar7 = DAT_004fe9cc + -0xc;
    }
    wsprintfA(acStack_40,s__d_00_and__d_00__004dd400,DAT_004fe9cc,iVar7);
    uVar5 = 0xffffffff;
    pcVar12 = acStack_40;
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar15 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar15 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar15;
    } while (cVar1 != '\0');
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = pcVar15 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar12 = acStack_80;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
    pcVar8 = pcVar8 + local_b4.data;
    uVar5 = 0xffffffff;
    pcVar12 = "Low tides at ";
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    iVar7 = DAT_004ffdd0 + 0xc;
    if (0x17 < iVar7) {
      iVar7 = DAT_004ffdd0 + -0xc;
    }
    wsprintfA(acStack_40,s__d_00_and__d_00__004dd400,DAT_004ffdd0,iVar7);
    uVar5 = 0xffffffff;
    pcVar12 = acStack_40;
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar15 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar15 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar15;
    } while (cVar1 != '\0');
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = pcVar15 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar12 = acStack_80;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    TextOutA(hdc,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
    uVar5 = 0xffffffff;
    pcVar8 = pcVar8 + local_b4.data;
    pcVar12 = s_Tidal_current_floods_from_the_004dd3d0;
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    if (DAT_005230dc == 4) {
      uVar5 = 0xffffffff;
      pcVar12 = "north.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_005230dc == 1) {
      uVar5 = 0xffffffff;
      pcVar12 = "east.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_005230dc == 2) {
      uVar5 = 0xffffffff;
      pcVar12 = "south.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_005230dc == 3) {
      uVar5 = 0xffffffff;
      pcVar12 = "west.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 1) {
      uVar5 = 0xffffffff;
      pcVar12 = s_south_and_east__004dd3a0;
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 2) {
      uVar5 = 0xffffffff;
      pcVar12 = s_east_northeast__004dd390;
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 3) {
      uVar5 = 0xffffffff;
      pcVar12 = "south.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004fb5d4 == 1) {
      uVar5 = 0xffffffff;
      pcVar12 = "east";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if ((DAT_004da1f8 == 7) || (DAT_004da1f8 == 6)) {
      uVar5 = 0xffffffff;
      pcVar12 = "south.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 9) {
      uVar5 = 0xffffffff;
      pcVar12 = s_south_and_east__004dd3a0;
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 0xb) {
      uVar5 = 0xffffffff;
      pcVar12 = "east.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    if (DAT_004da1f8 == 0x69) {
      uVar5 = 0xffffffff;
      pcVar12 = "south.";
      do {
        pcVar16 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar16 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar16;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar7 = -1;
      pcVar12 = acStack_80;
      do {
        pcVar15 = pcVar12;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pcVar15 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar15;
      } while (cVar1 != '\0');
      pcVar12 = pcVar16 + -uVar5;
      pcVar16 = pcVar15 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar16 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar16 = pcVar16 + 1;
      }
    }
    uVar5 = 0xffffffff;
    pcVar12 = acStack_80;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    TextOutA(local_8c,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
    pcVar8 = pcVar8 + local_b4.data;
    iVar7 = DAT_005359d0;
    if (DAT_004da1f8 == 1) {
      iVar7 = (DAT_005359d0 * 0x50) / 100;
    }
    if (DAT_004da1f8 == 2) {
      iVar7 = (DAT_005359d0 * 0x5a) / 100;
    }
    if (DAT_004da1f8 == 3) {
      iVar7 = (DAT_005359d0 * 0x46) / 100;
    }
    if (DAT_004da1f8 == 4) {
      iVar7 = (DAT_005359d0 * 9) / 0xf;
    }
    if (DAT_004da1f8 == 5) {
      iVar7 = (DAT_005359d0 * 0x1c) / 0x11;
    }
    if (DAT_004da1f8 == 6) {
      iVar7 = (DAT_005359d0 * 0x37) / 100;
    }
    if (DAT_004da1f8 == 7) {
      iVar7 = (DAT_005359d0 * 0x55) / 100;
    }
    if (DAT_004da1f8 == 9) {
      iVar7 = (DAT_005359d0 * 10) / 0xd;
    }
    if (DAT_004da1f8 == 0xb) {
      iVar7 = (DAT_005359d0 * 0x19) / 100;
    }
    if (DAT_004da1f8 == 0x68) {
      iVar7 = DAT_005359d0 / 2;
    }
    if (DAT_004da1f8 == 0x69) {
      iVar7 = (DAT_005359d0 * 0x32) / 100;
    }
    if (DAT_004da1f8 == 0x6a) {
      iVar7 = (DAT_005359d0 * 5) / 0x22;
    }
    if (DAT_004da1f8 == 100) {
      iVar7 = (DAT_005359d0 * 0x5f) / 100;
    }
    if (DAT_004da1f8 == 0x65) {
      iVar7 = (DAT_005359d0 * 9) / 10;
    }
    uVar5 = 0xffffffff;
    pcVar12 = s_Maximum_race_area_current_is_004dd370;
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = acStack_80;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    wsprintfA(acStack_40,s__d__d_knots__004dd360,iVar7 / 10,iVar7 % 10);
    uVar5 = 0xffffffff;
    pcVar12 = acStack_40;
    do {
      pcVar16 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar16 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar16;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar7 = -1;
    pcVar12 = acStack_80;
    do {
      pcVar15 = pcVar12;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar15 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar15;
    } while (cVar1 != '\0');
    pcVar12 = pcVar16 + -uVar5;
    pcVar16 = pcVar15 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar16 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar16 = pcVar16 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar12 = acStack_80;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    TextOutA(local_8c,0x14,(int)pcVar8,acStack_80,~uVar5 - 1);
    hdc = local_8c;
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(local_ac.data + 0x38))(param_1,0xff);
  }
  TVar11.data = local_b4.data;
  if (899 < DAT_004fe624) {
    TVar11.data = local_b4.data * 3;
  }
  FUN_004b0613(&TStack_b0,s_Movement_suspended__Click_mouse_o_004dd318);
  uStack_4 = 0;
  pcVar9 = *(code **)(local_ac.data + 100);
  local_88 = pcVar9;
  (*pcVar9)(param_1,0x14,(int)(TVar11.data + (int)pcVar8),TStack_b0.data,
            *(int *)(TStack_b0.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&TStack_b0);
  pcVar8 = TVar11.data + (int)pcVar8 + -2 + local_b4.data;
  FUN_004b0613(&local_ac,s_Press_R_for_course_chart__004dd2fc);
  uStack_4 = 1;
  (*pcVar9)(param_1,0x14,(int)pcVar8,local_ac.data,*(int *)(local_ac.data + -8));
  uStack_4 = 0xffffffff;
  FUN_004b05a5(&local_ac);
  if (DAT_005363e4 == 0) {
    SetTextColor(hdc,0xff0000);
  }
  TextOutA(local_8c,0x17c,0x19,s_Wind_history_at_the_committee_bo_004dd2d8,0x23);
  iVar7 = 2;
  TStack_b0.data = (char *)0xa;
  piVar17 = &DAT_00512d78;
  pcVar8 = (char *)((int)local_90.data * 2 + 0x28);
  local_b4.data = (char *)0x0;
  do {
    local_ac.data =
         (char *)((DAT_005364f8 - ((DAT_005364f8 + DAT_00535204) * iVar7) / 0xc) + DAT_00535204);
    local_a8.data = DAT_004fe08c;
    iVar10 = (((DAT_00522ae8 * *piVar17) / 400 -
              ((int)(DAT_00522ae8 + (DAT_00522ae8 >> 0x1f & 7U)) >> 3)) - (int)local_ac.data) +
             DAT_004f7f94;
    pcVar12 = DAT_004fe08c;
    if (iVar7 % 3 == 0) {
      pcVar12 = DAT_004fe08c + *(int *)(local_b4.data + 0x4f71dc);
      iVar10 = *(int *)(local_b4.data + 0x5357dc) - (int)local_ac.data;
      local_b4.data = local_b4.data + 4;
    }
    c = wsprintfA(acStack_80,s__d__d__d_knots_004dd2c4,DAT_004faa58 + -1,TStack_b0.data,pcVar12);
    TextOutA(local_8c,0x17c,(int)pcVar8,acStack_80,c);
    iVar10 = FUN_0041bc20(iVar10);
    iVar10 = wsprintfA(acStack_80,s__d_deg_004dd2bc,iVar10);
    TextOutA(local_8c,0x1fe,(int)pcVar8,acStack_80,iVar10);
    piVar17 = piVar17 + 1;
    iVar7 = iVar7 + 1;
    TStack_b0.data = TStack_b0.data + 5;
    pcVar8 = pcVar8 + local_90.data;
  } while ((int)piVar17 < 0x512d9d);
  local_a8.data = (char *)((DAT_0051158c != 1) + 1);
  TVar11.data = local_90.data;
  if (DAT_004da19c != 8) {
    dStack_48 = (double)(int)local_a8.data;
    pTVar3 = FUN_0041bc70(&local_a0,
                          (int)(longlong)
                               (((double)(int)local_a8.data - _DAT_004cc5c8) * _DAT_004da160));
    uStack_4 = 2;
    pTVar4 = FUN_0041bc70(&local_98,(int)(longlong)(_DAT_004da160 * dStack_48));
    uStack_4._0_1_ = 3;
    pTVar4 = FUN_004b082f(&local_b4,s_Time_between_shifts_is_004dd2a4,pTVar4);
    uStack_4._0_1_ = 4;
    pTVar4 = FUN_004b07bb(&TStack_b0,pTVar4,&DAT_004dd29c);
    uStack_4._0_1_ = 5;
    pTVar3 = FUN_004b0755(&local_ac,pTVar4,pTVar3);
    uStack_4._0_1_ = 6;
    pTVar3 = FUN_004b07bb(&local_a8,pTVar3,s_min__004dd294);
    TVar11.data = local_90.data;
    uStack_4._0_1_ = 7;
    (*local_88)(param_1,0x17c,(int)local_90.data * 0xc + 0x28,pTVar3->data,
                *(int *)(pTVar3->data + -8));
    uStack_4._0_1_ = 6;
    FUN_004b05a5(&local_a8);
    uStack_4._0_1_ = 5;
    FUN_004b05a5(&local_ac);
    uStack_4._0_1_ = 4;
    FUN_004b05a5(&TStack_b0);
    uStack_4._0_1_ = 3;
    FUN_004b05a5(&local_b4);
    uStack_4 = CONCAT31(uStack_4._1_3_,2);
    FUN_004b05a5(&local_98);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_a0);
  }
  DAT_005231b0 = DAT_005357dc - DAT_004f7f94;
  SetTextColor(local_8c,0x7f00);
  if (0 < DAT_004f8cd0) {
    pTVar3 = FUN_0041bc70(&local_90,DAT_00522b94);
    uStack_4 = 8;
    pTVar4 = FUN_0041bc70(&TStack_b0,DAT_004fb384);
    uStack_4._0_1_ = 9;
    pTVar4 = FUN_004b082f(&local_ac,s_True_wind_at_boat_1_is_now__004dd274,pTVar4);
    uStack_4._0_1_ = 10;
    pTVar4 = FUN_004b07bb(&local_a8,pTVar4,s_knots_004dd268);
    uStack_4._0_1_ = 0xb;
    pTVar3 = FUN_004b0755(&local_98,pTVar4,pTVar3);
    uStack_4._0_1_ = 0xc;
    pTVar3 = FUN_004b07bb(&local_a0,pTVar3,&DAT_004daa64);
    uStack_4._0_1_ = 0xd;
    (*local_88)(param_1,0x17c,(int)TVar11.data * 0xd + 0x28,pTVar3->data,*(int *)(pTVar3->data + -8)
               );
    uStack_4._0_1_ = 0xc;
    FUN_004b05a5(&local_a0);
    uStack_4._0_1_ = 0xb;
    FUN_004b05a5(&local_98);
    uStack_4._0_1_ = 10;
    FUN_004b05a5(&local_a8);
    uStack_4._0_1_ = 9;
    FUN_004b05a5(&local_ac);
    uStack_4 = CONCAT31(uStack_4._1_3_,8);
    FUN_004b05a5(&TStack_b0);
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&local_90);
  }
  FUN_004148f0(param_1,(DAT_004fe2a8 * 4) / 5 -
                       ((int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 7U)) >> 3));
  if (DAT_004fe624 < 1000) {
    iVar7 = (DAT_004fe2a8 << 2) / 5 + -10;
  }
  else {
    iVar7 = (DAT_004fe2a8 << 2) / 5 + 10;
  }
  if (DAT_004da1f8 == 999) {
    if (DAT_005363e4 == 0) {
      (*local_4c)(param_1,7);
      if (DAT_004fc15c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fc15c);
      }
      Rectangle((HDC)param_1[1],0,iVar7 + -5,DAT_004fe624,DAT_004fe2a8);
    }
    FUN_004b4a1f(param_1,1);
    FUN_0048cf50(param_1,iVar7);
    FUN_004b4a1f(param_1,2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

