
/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_0041d890(int *param_1)

{
  char cVar1;
  HDC hdc;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_EBX;
  int *piVar9;
  int unaff_EBP;
  code *pcVar10;
  int iVar11;
  char *pcVar12;
  code **ppcVar13;
  code **ppcVar14;
  int *piVar15;
  int *piVar16;
  char *pcVar17;
  int *unaff_FS_OFFSET;
  bool bVar18;
  bool bVar19;
  HDC pHStack_e4;
  int aiStack_e0 [2];
  code *pcStack_c0;
  undefined4 uStack_bc;
  int local_a8;
  char acStack_a4 [8];
  code *local_9c;
  char local_98 [4];
  undefined4 local_94;
  undefined1 local_90;
  int local_8c;
  undefined4 local_88;
  int local_84 [13];
  char acStack_50 [8];
  int local_48;
  char local_44 [4];
  undefined4 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_1c;
  int iStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047e41d;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  local_48._0_1_ = s_north_0049343c[0];
  local_48._1_1_ = s_north_0049343c[1];
  local_48._2_1_ = s_north_0049343c[2];
  local_48._3_1_ = s_north_0049343c[3];
  local_44[0] = s_north_0049343c[4];
  local_44[1] = s_north_0049343c[5];
  local_88 = CONCAT31(local_88._1_3_,DAT_00493438);
  hdc = (HDC)param_1[1];
  local_9c = (code *)s_south_0049342c._0_4_;
  local_94 = DAT_00493424;
  local_84[0] = *param_1;
  local_8c = DAT_00493434;
  pcVar10 = *(code **)(local_84[0] + 0x2c);
  local_90 = DAT_00493428;
  uStack_bc = 6;
  local_84[1] = 0x11;
  local_a8 = 0xf;
  local_98[0] = s_south_0049342c[4];
  local_98[1] = s_south_0049342c[5];
  pcStack_c0 = (code *)0x41d92a;
  (*pcVar10)();
  pcStack_c0 = (code *)0x0;
  (*pcVar10)();
  Rectangle((HDC)param_1[1],0,0,DAT_004a763c,DAT_004a72d0);
  if (700 < DAT_004a763c) {
    local_88 = 0x13;
    unaff_EBP = 0x11;
  }
  if (900 < DAT_004a763c) {
    local_88 = 0x16;
    unaff_EBP = 0x14;
  }
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  TextOutA(hdc,0x14,0x19,s_Pre_Race_Forecast__00493410,0x12);
  iVar6 = DAT_004a5b98;
  if (DAT_004a5b98 == 1) {
    uVar4 = 0xffffffff;
    unaff_EBX = local_84;
    pcVar12 = s_Sunshine__00493404;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = unaff_EBX;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  bVar19 = SBORROW4(iVar6,2);
  bVar18 = false;
  if (iVar6 == 2) {
    uVar4 = 0xffffffff;
    unaff_EBX = local_84;
    pcVar12 = s_Partly_cloudy__004933f4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = unaff_EBX;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  iVar7 = DAT_004a8a78;
  if (!bVar18 && bVar19 == iVar6 + -2 < 0) {
    uVar4 = 0xffffffff;
    pcVar12 = &DAT_004933e8;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = local_84;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  if (DAT_004a8a78 == 1) {
    uVar4 = 0xffffffff;
    unaff_EBX = &local_48;
    pcVar12 = s_low_humidity__004933d8;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = unaff_EBX;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  bVar19 = SBORROW4(iVar7,2);
  bVar18 = false;
  if (iVar7 == 2) {
    uVar4 = 0xffffffff;
    unaff_EBX = &local_48;
    pcVar12 = s_moderate_humidity__004933c4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = unaff_EBX;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    bVar19 = false;
    bVar18 = true;
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  if (!bVar18 && bVar19 == iVar7 + -2 < 0) {
    uVar4 = 0xffffffff;
    pcVar12 = s_high_humidity__004933b4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = &local_48;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
  }
  uVar4 = 0xffffffff;
  piVar9 = &local_48;
  do {
    piVar15 = piVar9;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar6 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar6 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  piVar9 = local_84;
  do {
    piVar16 = piVar9;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    piVar16 = (int *)((int)piVar9 + 1);
    iVar7 = *piVar9;
    piVar9 = piVar16;
  } while ((char)iVar7 != '\0');
  pcVar12 = (char *)((int)piVar15 - uVar4);
  pcVar17 = (char *)((int)piVar16 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar4 = 0xffffffff;
  piVar9 = local_84;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    iVar6 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar6 != '\0');
  TextOutA(hdc,0x14,0x3c,(LPCSTR)local_84,~uVar4 - 1);
  iVar6 = wsprintfA((LPSTR)local_84,s_Maximum_temperature_of__d__00493398);
  TextOutA(hdc,0x14,unaff_EBP + 0x3c,(LPCSTR)local_84,iVar6);
  pcVar12 = s_High_00493390;
  local_a8 = unaff_EBP * 2;
  iVar6 = unaff_EBP + 0x3c + local_a8;
  if (DAT_004aa8bc != 1) {
    pcVar12 = &DAT_00493388;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  piVar9 = (int *)(pcVar17 + -uVar4);
  piVar15 = local_84;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar15 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar15 = piVar15 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)piVar15 = (char)*piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
    piVar15 = (int *)((int)piVar15 + 1);
  }
  uVar4 = 0xffffffff;
  pcVar12 = s_pressure_to_the_00493374;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar7 = -1;
  piVar9 = local_84;
  do {
    piVar15 = piVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar2 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar2 != '\0');
  pcVar12 = pcVar17 + -uVar4;
  pcVar17 = (char *)((int)piVar15 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  if (DAT_004a8990 == 1) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 2) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 3) {
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 4) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 5) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 6) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 7) {
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a8990 == 8) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  uVar4 = 0xffffffff;
  pcVar12 = (char *)&DAT_0049300c;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar7 = -1;
  piVar9 = local_84;
  do {
    piVar15 = piVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar2 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar2 != '\0');
  pcVar12 = pcVar17 + -uVar4;
  pcVar17 = (char *)((int)piVar15 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar4 = 0xffffffff;
  piVar9 = local_84;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    iVar7 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar7 != '\0');
  if (DAT_004ac998 == 0) {
    TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
  }
  iVar6 = iVar6 + unaff_EBP;
  uVar4 = 0xffffffff;
  pcVar12 = s_Wind_from_the_00493364;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  piVar9 = (int *)(pcVar17 + -uVar4);
  piVar15 = local_84;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar15 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar15 = piVar15 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)piVar15 = (char)*piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
    piVar15 = (int *)((int)piVar15 + 1);
  }
  if (DAT_004a5e88 == 1) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 2) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 3) {
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 4) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar12 = (char *)&local_94;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 5) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 6) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_a4;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 7) {
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (DAT_004a5e88 == 8) {
    uVar4 = 0xffffffff;
    pcVar12 = acStack_50;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = pcVar17 + -uVar4;
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    ppcVar13 = &local_9c;
    do {
      ppcVar14 = ppcVar13;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      ppcVar14 = (code **)((int)ppcVar13 + 1);
      cVar1 = *(char *)ppcVar13;
      ppcVar13 = ppcVar14;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar15 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)ppcVar14 - uVar4);
    pcVar17 = (char *)((int)piVar15 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  wsprintfA((LPSTR)&local_48,s_at__d_to__d_knots__0049334c);
  uVar4 = 0xffffffff;
  piVar9 = &local_48;
  do {
    piVar15 = piVar9;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar7 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar7 != '\0');
  uVar4 = ~uVar4;
  iVar7 = -1;
  piVar9 = local_84;
  do {
    piVar16 = piVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    piVar16 = (int *)((int)piVar9 + 1);
    iVar2 = *piVar9;
    piVar9 = piVar16;
  } while ((char)iVar2 != '\0');
  pcVar12 = (char *)((int)piVar15 - uVar4);
  pcVar17 = (char *)((int)piVar16 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar4 = 0xffffffff;
  piVar9 = local_84;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    iVar7 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar7 != '\0');
  TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
  iVar7 = local_a8;
  iVar6 = iVar6 + local_a8;
  iVar2 = wsprintfA((LPSTR)local_84,s_Water_temperature_is__d__00493330);
  TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,iVar2);
  iVar6 = iVar6 + unaff_EBP;
  if (4 < DAT_004a79ec) {
    TextOutA(hdc,0x14,iVar6,s_Seabreeze_likely_0049331c,0x10);
  }
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f);
  }
  iVar6 = iVar6 + iVar7;
  uVar4 = 0xffffffff;
  pcVar12 = s_Time_is_now_0049330c;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  piVar9 = (int *)(pcVar17 + -uVar4);
  piVar15 = local_84;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar15 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar15 = piVar15 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)piVar15 = (char)*piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
    piVar15 = (int *)((int)piVar15 + 1);
  }
  wsprintfA((LPSTR)&local_48,s__d_hours__d_min_004932f8);
  uVar4 = 0xffffffff;
  piVar9 = &local_48;
  do {
    piVar15 = piVar9;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar7 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar7 != '\0');
  uVar4 = ~uVar4;
  iVar7 = -1;
  piVar9 = local_84;
  do {
    piVar16 = piVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    piVar16 = (int *)((int)piVar9 + 1);
    iVar2 = *piVar9;
    piVar9 = piVar16;
  } while ((char)iVar2 != '\0');
  pcVar12 = (char *)((int)piVar15 - uVar4);
  pcVar17 = (char *)((int)piVar16 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar4 = 0xffffffff;
  piVar9 = local_84;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    iVar7 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar7 != '\0');
  TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f00);
  }
  iVar6 = iVar6 + unaff_EBP;
  uVar4 = 0xffffffff;
  pcVar12 = s_True_wind_at_committee_boat_is_n_004932d4;
  do {
    pcVar17 = pcVar12;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar17 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar17;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  piVar9 = (int *)(pcVar17 + -uVar4);
  piVar15 = local_84;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar15 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar15 = piVar15 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)piVar15 = (char)*piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
    piVar15 = (int *)((int)piVar15 + 1);
  }
  wsprintfA((LPSTR)&local_48,s__d_knots_004932c8);
  pcVar10 = TextOutA_exref;
  uVar4 = 0xffffffff;
  piVar9 = &local_48;
  do {
    piVar15 = piVar9;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    piVar15 = (int *)((int)piVar9 + 1);
    iVar7 = *piVar9;
    piVar9 = piVar15;
  } while ((char)iVar7 != '\0');
  uVar4 = ~uVar4;
  iVar7 = -1;
  piVar9 = local_84;
  do {
    piVar16 = piVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    piVar16 = (int *)((int)piVar9 + 1);
    iVar2 = *piVar9;
    piVar9 = piVar16;
  } while ((char)iVar2 != '\0');
  pcVar12 = (char *)((int)piVar15 - uVar4);
  pcVar17 = (char *)((int)piVar16 + -1);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
    pcVar12 = pcVar12 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar17 = *pcVar12;
    pcVar12 = pcVar12 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar4 = 0xffffffff;
  piVar9 = local_84;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    iVar7 = *piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
  } while ((char)iVar7 != '\0');
  TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
  iVar7 = local_a8;
  iVar6 = iVar6 + local_a8;
  if (DAT_004ac1e0 == 1) {
    if (DAT_004ac92c == 0) {
      SetTextColor(hdc,0x7f7f7f);
    }
    iVar2 = 0xf;
    pcVar12 = s_High_shoreline__004932b8;
  }
  else {
    if (DAT_004ac92c == 0) {
      SetTextColor(hdc,0x7f7f);
    }
    iVar2 = 0xe;
    pcVar12 = s_Low_shoreline__004932a8;
  }
  TextOutA(hdc,0x14,iVar6,pcVar12,iVar2);
  if (DAT_004ac92c == 0) {
    SetTextColor(hdc,0x7f0000);
  }
  if (0 < DAT_004ac1dc) {
    iVar6 = iVar6 + iVar7;
    uVar4 = 0xffffffff;
    pcVar12 = s_High_tides_at_00493298;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = local_84;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
    wsprintfA((LPSTR)&local_48,s__d_00_and__d_00__00493284);
    uVar4 = 0xffffffff;
    piVar9 = &local_48;
    do {
      piVar15 = piVar9;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar7 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar7 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar16 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar16 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar16;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)piVar15 - uVar4);
    pcVar17 = (char *)((int)piVar16 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    piVar9 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      iVar7 = *piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    } while ((char)iVar7 != '\0');
    TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
    iVar6 = iVar6 + unaff_EBP;
    uVar4 = 0xffffffff;
    pcVar12 = s_Low_tides_at_00493274;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = local_84;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
    wsprintfA((LPSTR)&local_48,s__d_00_and__d_00__00493284);
    uVar4 = 0xffffffff;
    piVar9 = &local_48;
    do {
      piVar15 = piVar9;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar7 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar7 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar16 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar16 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar16;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)piVar15 - uVar4);
    pcVar17 = (char *)((int)piVar16 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    piVar9 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      iVar7 = *piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    } while ((char)iVar7 != '\0');
    TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
    iVar6 = iVar6 + unaff_EBP;
    uVar4 = 0xffffffff;
    pcVar12 = s_Tidal_current_floods_from_the_00493254;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = local_84;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
    if (DAT_004aa804 == 4) {
      uVar4 = 0xffffffff;
      pcVar12 = s_north__0049324c;
      do {
        pcVar17 = pcVar12;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar17 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar17;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      piVar9 = local_84;
      do {
        piVar15 = piVar9;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        piVar15 = (int *)((int)piVar9 + 1);
        iVar2 = *piVar9;
        piVar9 = piVar15;
      } while ((char)iVar2 != '\0');
      pcVar12 = pcVar17 + -uVar4;
      pcVar17 = (char *)((int)piVar15 + -1);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar17 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 1) {
      uVar4 = 0xffffffff;
      pcVar12 = s_east__00493244;
      do {
        pcVar17 = pcVar12;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar17 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar17;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      piVar9 = local_84;
      do {
        piVar15 = piVar9;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        piVar15 = (int *)((int)piVar9 + 1);
        iVar2 = *piVar9;
        piVar9 = piVar15;
      } while ((char)iVar2 != '\0');
      pcVar12 = pcVar17 + -uVar4;
      pcVar17 = (char *)((int)piVar15 + -1);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar17 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 2) {
      uVar4 = 0xffffffff;
      pcVar12 = s_south__0049323c;
      do {
        pcVar17 = pcVar12;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar17 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar17;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      piVar9 = local_84;
      do {
        piVar15 = piVar9;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        piVar15 = (int *)((int)piVar9 + 1);
        iVar2 = *piVar9;
        piVar9 = piVar15;
      } while ((char)iVar2 != '\0');
      pcVar12 = pcVar17 + -uVar4;
      pcVar17 = (char *)((int)piVar15 + -1);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar17 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (DAT_004aa804 == 3) {
      uVar4 = 0xffffffff;
      pcVar12 = s_west__00493234;
      do {
        pcVar17 = pcVar12;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar17 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar17;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar7 = -1;
      piVar9 = local_84;
      do {
        piVar15 = piVar9;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        piVar15 = (int *)((int)piVar9 + 1);
        iVar2 = *piVar9;
        piVar9 = piVar15;
      } while ((char)iVar2 != '\0');
      pcVar12 = pcVar17 + -uVar4;
      pcVar17 = (char *)((int)piVar15 + -1);
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar17 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    uVar4 = 0xffffffff;
    piVar9 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      iVar7 = *piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    } while ((char)iVar7 != '\0');
    TextOutA(hdc,0x14,iVar6,(LPCSTR)local_84,~uVar4 - 1);
    uVar4 = 0xffffffff;
    pcVar12 = s_Maximum_current_is_00493220;
    do {
      pcVar17 = pcVar12;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar17 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    piVar9 = (int *)(pcVar17 + -uVar4);
    piVar15 = local_84;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *piVar15 = *piVar9;
      piVar9 = piVar9 + 1;
      piVar15 = piVar15 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)piVar15 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      piVar15 = (int *)((int)piVar15 + 1);
    }
    wsprintfA((LPSTR)&local_48,s__d__d_knots__00493210);
    uVar4 = 0xffffffff;
    piVar9 = &local_48;
    do {
      piVar15 = piVar9;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      piVar15 = (int *)((int)piVar9 + 1);
      iVar7 = *piVar9;
      piVar9 = piVar15;
    } while ((char)iVar7 != '\0');
    uVar4 = ~uVar4;
    iVar7 = -1;
    piVar9 = local_84;
    do {
      piVar16 = piVar9;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      piVar16 = (int *)((int)piVar9 + 1);
      iVar2 = *piVar9;
      piVar9 = piVar16;
    } while ((char)iVar2 != '\0');
    pcVar12 = (char *)((int)piVar15 - uVar4);
    pcVar17 = (char *)((int)piVar16 + -1);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
    uVar4 = 0xffffffff;
    piVar9 = local_84;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      iVar7 = *piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    } while ((char)iVar7 != '\0');
    TextOutA(hdc,0x14,iVar6 + unaff_EBP,(LPCSTR)local_84,~uVar4 - 1);
    pcVar10 = TextOutA_exref;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(local_8c + 0x38))();
  }
  FUN_0046bf33(&local_a8,s_Movement_suspended__Click_mouse_o_004918bc);
  iStack_c = 0;
  local_9c = *(code **)(local_8c + 100);
  (*local_9c)();
  uStack_1c = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff48);
  if (DAT_004ac92c == 0) {
    aiStack_e0[1] = 0x41e6fd;
    SetTextColor(hdc,0xff0000);
  }
  aiStack_e0[1] = 0x19;
  aiStack_e0[0] = 0x17c;
  pHStack_e4 = hdc;
  (*pcVar10)();
  iVar6 = 2;
  iVar2 = 10;
  piVar9 = &DAT_004a9458;
  pcVar12 = (char *)((int)unaff_EBX * 2 + 0x28);
  iVar7 = 0;
  do {
    iVar8 = DAT_004abc7c - (iVar6 * DAT_004abc7c) / 0xc;
    iVar11 = (((DAT_004aa590 * *piVar9) / 400 -
              ((int)(DAT_004aa590 + (DAT_004aa590 >> 0x1f & 7U)) >> 3)) - iVar8) + DAT_004a4f8c;
    iVar3 = DAT_004a70f0;
    if (iVar6 % 3 == 0) {
      iVar3 = DAT_004a70f0 + *(int *)((int)&DAT_004a4e9c + iVar7);
      iVar11 = *(int *)((int)&DAT_004ac0a4 + iVar7) - iVar8;
      iVar7 = iVar7 + 4;
    }
    iVar3 = wsprintfA((LPSTR)&local_a8,s__d__d__d_knots_004931d8,DAT_004a5bac + -1,iVar2,iVar3);
    TextOutA(hdc,0x17c,(int)pcVar12,(LPCSTR)&local_a8,iVar3);
    iVar3 = FUN_00413cb0(iVar11);
    iVar3 = wsprintfA((LPSTR)&local_a8,s__d_deg_004931d0,iVar3);
    TextOutA(hdc,0x1fe,(int)pcVar12,(LPCSTR)&local_a8,iVar3);
    piVar9 = piVar9 + 1;
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 5;
    pcVar12 = pcVar12 + (int)unaff_EBX;
  } while ((int)piVar9 < 0x4a947d);
  bVar18 = DAT_004a888c != 1;
  FUN_00413d00(&stack0xffffff48,(bVar18 + 3) * DAT_0049115c);
  uStack_30 = 1;
  FUN_00413d00(&stack0xffffff2c,(bVar18 + 1) * DAT_0049115c);
  uStack_30._0_1_ = 2;
  FUN_0046c14f();
  uStack_30._0_1_ = 3;
  FUN_0046c0db();
  uStack_30._0_1_ = 4;
  FUN_0046c075();
  uStack_30._0_1_ = 5;
  piVar9 = (int *)FUN_0046c0db();
  uStack_30 = CONCAT31(uStack_30._1_3_,6);
  (*pcStack_c0)(0x17c,(int)unaff_EBX * 0xd + 0x28,*piVar9,*(undefined4 *)(*piVar9 + -8));
  uStack_40._0_1_ = 5;
  FUN_0046bec5(aiStack_e0);
  uStack_40._0_1_ = 4;
  FUN_0046bec5((int *)&stack0xffffff28);
  uStack_40._0_1_ = 3;
  FUN_0046bec5((int *)&pcStack_c0);
  uStack_40._0_1_ = 2;
  FUN_0046bec5(aiStack_e0 + 1);
  uStack_40 = CONCAT31(uStack_40._1_3_,1);
  FUN_0046bec5((int *)&pHStack_e4);
  uStack_40 = 0xffffffff;
  FUN_0046bec5((int *)&stack0xffffff38);
  DAT_004aa838 = DAT_004ac0a4 - DAT_004a4f8c;
  *unaff_FS_OFFSET = local_48;
  return;
}

