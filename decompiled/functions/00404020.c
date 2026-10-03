
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00404020(CDC *param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  CDC *pCVar3;
  int *piVar4;
  CDC *pCVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  tagPOINT local_8;
  
  if (DAT_004ac9ec == 2) {
    MessageBeep(0);
    DAT_004ac8fc = 1;
    DAT_004ac9ec = 0;
    DAT_004ac968 = 1;
  }
  if (DAT_004ac9ec == 1) {
    FUN_0044dbc0();
    DAT_004ac9ec = 2;
  }
  DVar1 = GetTickCount();
  GetCursorPos(&local_8);
  DAT_004a5ba0 = local_8.y;
  DAT_004a4f80 = local_8.x;
  FUN_0041b5d0();
  iVar6 = 1;
  piVar4 = &DAT_004aaa24;
  do {
    if (*piVar4 < DAT_004a5b80) {
      FUN_0041e9c0(iVar6);
    }
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + 1;
  } while ((int)piVar4 < 0x4aaa35);
  iVar6 = 1;
  if (0 < DAT_0049118c) {
    do {
      FUN_004249a0(iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 <= DAT_0049118c);
  }
  FUN_0042b7f0();
  if (DAT_00491140 == 2) {
    FUN_0042bda0();
  }
  iVar6 = 1;
  if (0 < DAT_0049118c) {
    do {
      FUN_00428c60(iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 <= DAT_0049118c);
  }
  if (DAT_004ac980 == 0) {
    FUN_0042adb0();
  }
  if (DAT_004a76c8 == DAT_004a4168) {
    FUN_0044dfe0();
    DAT_004911c0 = 0;
  }
  if ((0 < DAT_004a5b80) && (DAT_004a76c8 < 1)) {
    FUN_0044dfe0();
    DAT_004911c0 = 1;
  }
  if ((DAT_004911c0 == 1) &&
     (fVar8 = FUN_00428ab0(1,(double)DAT_004aa294,(double)DAT_004aa388),
     fVar8 < (float10)_DAT_00484cc0)) {
    DAT_004ac9fc = DAT_004a5b80;
  }
  if (((DAT_004911c0 == 1) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
    FUN_0044dfe0();
    DAT_004911c0 = 2;
    DAT_004ac9fc = 0;
  }
  if ((DAT_004911c0 == 2) &&
     (fVar8 = FUN_00428ab0(1,(double)DAT_004aa38c,(double)DAT_004aa588),
     fVar8 < (float10)_DAT_00484cc0)) {
    DAT_004ac9fc = DAT_004a5b80;
  }
  if (((DAT_004911c0 == 2) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
    FUN_0044dfe0();
    DAT_004911c0 = 3;
    DAT_004ac9fc = 0;
  }
  if ((DAT_004911c0 == 3) &&
     (fVar8 = FUN_00428ab0(1,(double)DAT_004aa288,(double)DAT_004aa384),
     fVar8 < (float10)_DAT_00484cc0)) {
    DAT_004ac9fc = DAT_004a5b80;
  }
  if (((DAT_004911c0 == 3) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
    FUN_0044dfe0();
    DAT_004911c0 = 4;
    DAT_004ac9fc = 0;
  }
  if (((DAT_00491180 == 2) || (DAT_00491180 == 4)) || (DAT_00491180 == 5)) {
    if ((DAT_004911c0 == 4) &&
       (fVar8 = FUN_00428ab0(1,(double)DAT_004aa294,(double)DAT_004aa388),
       fVar8 < (float10)_DAT_00484cc0)) {
      DAT_004ac9fc = DAT_004a5b80;
    }
    if (((DAT_004911c0 == 4) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
      FUN_0044dfe0();
      DAT_004911c0 = 5;
      DAT_004ac9fc = 0;
    }
    if ((DAT_004911c0 == 5) &&
       (fVar8 = FUN_00428ab0(1,(double)DAT_004aa38c,(double)DAT_004aa588),
       fVar8 < (float10)_DAT_00484cc0)) {
      DAT_004ac9fc = DAT_004a5b80;
    }
    if (((DAT_004911c0 == 5) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
      FUN_0044dfe0();
      DAT_004911c0 = 6;
      DAT_004ac9fc = 0;
    }
    if ((DAT_004911c0 == 6) &&
       (fVar8 = FUN_00428ab0(1,(double)DAT_004aa288,(double)DAT_004aa384),
       fVar8 < (float10)_DAT_00484cc0)) {
      DAT_004ac9fc = DAT_004a5b80;
    }
    if (((DAT_004911c0 == 6) && (DAT_004ac9fc + 5 < DAT_004a5b80)) && (0 < DAT_004ac9fc)) {
      FUN_0044dfe0();
      DAT_004911c0 = 7;
      DAT_004ac9fc = 0;
    }
  }
  if ((DAT_00491140 == 1) && (DAT_004a4e8c < 3)) {
    FUN_00404880((int)param_1,0,0,DAT_004a763c,DAT_004a72d0 / 2,1);
    if ((DAT_004ac980 == 2) || (DAT_004ac980 == 300)) {
      FUN_0041bb40(param_1);
    }
    if (DAT_004ac9c8 == 0) {
      if (DAT_004ac9b4 == 0) {
        FUN_00407e40((int)param_1,0,DAT_004a72d0 / 2,DAT_004a763c / 3,DAT_004a72d0,1,2);
      }
      else {
        FUN_004063e0((int)param_1,0,DAT_004a72d0 / 2,DAT_004a763c / 3,DAT_004a72d0,1,2);
      }
    }
    if (DAT_004ac9c8 == 1) {
      iVar6 = 0;
      iVar7 = DAT_004a763c / 2;
    }
    else {
      iVar6 = DAT_004a763c / 3;
      iVar7 = (DAT_004a763c * 2) / 3;
    }
    FUN_00407e40((int)param_1,iVar7,DAT_004a72d0 / 2,DAT_004a763c,DAT_004a72d0,1,1);
    FUN_0040c3b0(param_1,iVar6,DAT_004a72d0 / 2,iVar7,DAT_004a72d0,1);
    DAT_004aa808 = iVar6;
    DAT_004ab150 = iVar7;
  }
  if ((DAT_00491140 == 1) && (DAT_004a4e8c == 3)) {
    FUN_00404880((int)param_1,DAT_004a763c / 3,0,DAT_004a763c,DAT_004a72d0,1);
    if ((DAT_004ac980 == 2) || (DAT_004ac980 == 300)) {
      FUN_0041bb40(param_1);
    }
    FUN_00407e40((int)param_1,0,0,DAT_004a763c / 3,DAT_004a72d0 / 2,1,1);
    if ((DAT_004ac980 == 2) || (DAT_004ac980 == 300)) {
      FUN_0041bb40(param_1);
    }
    FUN_0040c3b0(param_1,0,DAT_004a72d0 / 2,DAT_004a763c / 3,DAT_004a72d0,1);
    DAT_004ab150 = DAT_004a763c / 3;
    DAT_004aa808 = 0;
  }
  if (DAT_00491140 == 2) {
    FUN_00404880((int)param_1,0,0,DAT_004a763c / 2,DAT_004a72d0 / 2,2);
    if ((DAT_004ac980 == 2) || (DAT_004ac980 == 300)) {
      FUN_0041bb40(param_1);
    }
    FUN_00404880((int)param_1,DAT_004a763c / 2,0,DAT_004a763c,DAT_004a72d0 / 2,1);
    if ((DAT_004ac980 == 2) || (DAT_004ac980 == 300)) {
      FUN_0041bb40(param_1);
    }
    iVar6 = DAT_004a763c / 0x1e;
    FUN_00407e40((int)param_1,0,DAT_004a72d0 / 2,DAT_004a763c / 3 - iVar6,DAT_004a72d0,2,1);
    FUN_0040e9a0(param_1,DAT_004a763c / 3 - iVar6,DAT_004a72d0 / 2,DAT_004a763c / 2,DAT_004a72d0,2);
    FUN_00407e40((int)param_1,DAT_004a763c / 2,DAT_004a72d0 / 2,(DAT_004a763c * 5) / 6 - iVar6 / 2,
                 DAT_004a72d0,1,1);
    FUN_0040e9a0(param_1,(DAT_004a763c * 5) / 6 - iVar6 / 2,DAT_004a72d0 / 2,DAT_004a763c,
                 DAT_004a72d0,1);
  }
  if (DAT_0049116c < 7) {
    pCVar5 = (CDC *)0x1e;
    if (DAT_0049116c != 6) {
      pCVar5 = param_1;
    }
    if (DAT_0049116c == 5) {
      pCVar5 = (CDC *)0x3c;
    }
    if (DAT_0049116c < 5) {
      pCVar5 = (CDC *)0x50;
    }
    if (DAT_004ac9a4 == 1) {
      pCVar5 = pCVar5 + 100;
    }
    DVar2 = GetTickCount();
    pCVar3 = (CDC *)(DVar2 - DVar1);
    while (pCVar3 < pCVar5) {
      DVar2 = GetTickCount();
      pCVar3 = (CDC *)(DVar2 - DVar1);
    }
  }
  DAT_004a4e7c = 0;
  DAT_004a4e80 = 0;
  return;
}

