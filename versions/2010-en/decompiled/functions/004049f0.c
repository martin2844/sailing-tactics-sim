
void __cdecl FUN_004049f0(int *param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int local_10;
  tagPOINT local_8;
  
  if (DAT_005364ac == 2) {
    MessageBeep(0);
    DAT_005363b4 = 1;
    DAT_005364ac = 0;
    DAT_0053642c = 1;
  }
  if (DAT_005364ac == 1) {
    FUN_00464180();
    DAT_005364ac = 2;
  }
  DVar1 = GetTickCount();
  GetCursorPos(&local_8);
  DAT_004f8ee4 = local_8.y;
  DAT_004f7f78 = local_8.x;
  FUN_00427540();
  iVar6 = 1;
  piVar4 = &DAT_00523634;
  do {
    if (*piVar4 < DAT_004f8cd0) {
      FUN_0042b0b0(iVar6);
    }
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + 1;
  } while ((int)piVar4 < 0x523645);
  iVar6 = 1;
  if (0 < DAT_004da194) {
    do {
      FUN_00434f70(iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 <= DAT_004da194);
  }
  FUN_0043df50();
  if (DAT_004da140 == 2) {
    FUN_0043e510();
  }
  iVar6 = 1;
  if (0 < DAT_004da194) {
    do {
      FUN_0043a030(iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 <= DAT_004da194);
  }
  if (DAT_00536444 == 0) {
    FUN_0043cf60();
  }
  if (DAT_004fe6c8 == DAT_004f42b8) {
    FUN_004645a0();
    DAT_004da1cc = 0;
  }
  if ((0 < DAT_004f8cd0) && (DAT_004fe6c8 < 1)) {
    FUN_004645a0();
    DAT_004da1cc = 1;
  }
  local_10 = 0x3c;
  if (DAT_004da1e8 == 1) {
    local_10 = 0x6e;
  }
  if ((DAT_004da1cc == 1) &&
     (fVar8 = FUN_00439e80(1,(double)DAT_005229d4,(double)DAT_00522ac8), fVar8 < (float10)local_10))
  {
    DAT_00536538 = DAT_004f8cd0;
  }
  if (((DAT_004da1cc == 1) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
    FUN_004645a0();
    DAT_004da1cc = 2;
    DAT_00536538 = 0;
  }
  if ((DAT_004da1cc == 2) &&
     (fVar8 = FUN_00439e80(1,(double)DAT_00522acc,(double)DAT_00522ae0), fVar8 < (float10)local_10))
  {
    DAT_00536538 = DAT_004f8cd0;
  }
  if (((DAT_004da1cc == 2) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
    FUN_004645a0();
    DAT_004da1cc = 3;
    DAT_00536538 = 0;
  }
  if ((DAT_004da1cc == 3) &&
     (fVar8 = FUN_00439e80(1,(double)DAT_005229c8,(double)DAT_00522ac4), fVar8 < (float10)local_10))
  {
    DAT_00536538 = DAT_004f8cd0;
  }
  if (((DAT_004da1cc == 3) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
    FUN_004645a0();
    DAT_004da1cc = 4;
    DAT_00536538 = 0;
  }
  if (((DAT_004da188 == 2) || (DAT_004da188 == 4)) ||
     ((DAT_004da188 == 5 || ((DAT_004da188 == 6 || (DAT_004da188 == 7)))))) {
    if ((DAT_004da1cc == 4) &&
       (fVar8 = FUN_00439e80(1,(double)DAT_005229d4,(double)DAT_00522ac8), fVar8 < (float10)local_10
       )) {
      DAT_00536538 = DAT_004f8cd0;
    }
    if (((DAT_004da1cc == 4) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
      FUN_004645a0();
      DAT_004da1cc = 5;
      DAT_00536538 = 0;
    }
    if ((DAT_004da1cc == 5) &&
       (fVar8 = FUN_00439e80(1,(double)DAT_00522acc,(double)DAT_00522ae0), fVar8 < (float10)local_10
       )) {
      DAT_00536538 = DAT_004f8cd0;
    }
    if (((DAT_004da1cc == 5) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
      FUN_004645a0();
      DAT_004da1cc = 6;
      DAT_00536538 = 0;
    }
    if ((DAT_004da1cc == 6) &&
       (fVar8 = FUN_00439e80(1,(double)DAT_005229c8,(double)DAT_00522ac4), fVar8 < (float10)local_10
       )) {
      DAT_00536538 = DAT_004f8cd0;
    }
    if (((DAT_004da1cc == 6) && (DAT_00536538 + 5 < DAT_004f8cd0)) && (0 < DAT_00536538)) {
      FUN_004645a0();
      DAT_004da1cc = 7;
      DAT_00536538 = 0;
    }
  }
  if (DAT_004da1e8 == 1) {
    DAT_004f452c = 1;
    if (DAT_004da188 == 5) {
      DAT_004f452c = (uint)(4 < DAT_004da1cc);
    }
    if (((DAT_004da188 == 6) || (DAT_004da188 == 3)) || (DAT_004da188 == 4)) {
      DAT_004f452c = 0;
    }
    if (DAT_004da188 == 7) {
      if (((DAT_004f853c < 2) || (7 < DAT_004f853c)) && ((DAT_004fe2b4 == 0 && (DAT_00536408 == 1)))
         ) {
        DAT_004f452c = 0;
      }
      if ((1 < DAT_004f853c) && (0 < DAT_004fe2b4)) {
        DAT_004f452c = 0;
      }
    }
    if (DAT_004fe63c < 1) goto LAB_00404eda;
  }
  DAT_004f452c = 0;
LAB_00404eda:
  if ((DAT_004da140 == 1) && (DAT_004f71c4 < 3)) {
    FUN_00405320(param_1,0,0,DAT_004fe624,DAT_004fe2a8 / 2,1);
    DAT_00535564 = DAT_004fe2a8 / 2;
    if ((DAT_00536444 == 2) || (DAT_00536444 == 300)) {
      FUN_00427f10(param_1);
    }
    if (DAT_004da1a8 == 0) {
      if (DAT_00536478 == 0) {
        FUN_00407ff0(param_1,0,DAT_004fe2a8 / 2,DAT_004fe624 / 3,DAT_004fe2a8,1,2);
      }
      else {
        FUN_00406590(param_1,0,DAT_004fe2a8 / 2,DAT_004fe624 / 3,DAT_004fe2a8,1,2);
      }
    }
    if (DAT_004da1a8 == 1) {
      iVar6 = 0;
      iVar7 = DAT_004fe624 / 2;
    }
    else {
      iVar6 = DAT_004fe624 / 3;
      iVar7 = (DAT_004fe624 * 2) / 3;
    }
    FUN_00407ff0(param_1,iVar7,DAT_004fe2a8 / 2,DAT_004fe624,DAT_004fe2a8,1,1);
    FUN_0040f240(param_1,iVar6,DAT_004fe2a8 / 2,iVar7,DAT_004fe2a8,1);
    DAT_005230e0 = iVar6;
    DAT_00525a68 = iVar7;
  }
  if ((DAT_004da140 == 1) && (DAT_004f71c4 == 3)) {
    FUN_00405320(param_1,DAT_004fe624 / 3,0,DAT_004fe624,DAT_004fe2a8,1);
    DAT_00535564 = DAT_004fe2a8;
    if ((DAT_00536444 == 2) || (DAT_00536444 == 300)) {
      FUN_00427f10(param_1);
    }
    FUN_00407ff0(param_1,0,0,DAT_004fe624 / 3,DAT_004fe2a8 / 2,1,1);
    if ((DAT_00536444 == 2) || (DAT_00536444 == 300)) {
      FUN_00427f10(param_1);
    }
    FUN_0040f240(param_1,0,DAT_004fe2a8 / 2,DAT_004fe624 / 3,DAT_004fe2a8,1);
    DAT_00525a68 = DAT_004fe624 / 3;
    DAT_005230e0 = 0;
  }
  if (DAT_004da140 == 2) {
    FUN_00405320(param_1,0,0,DAT_004fe624 / 2,DAT_004fe2a8 / 2,2);
    if ((DAT_00536444 == 2) || (DAT_00536444 == 300)) {
      FUN_00427f10(param_1);
    }
    FUN_00405320(param_1,DAT_004fe624 / 2,0,DAT_004fe624,DAT_004fe2a8 / 2,1);
    DAT_00535564 = DAT_004fe2a8 / 2;
    if ((DAT_00536444 == 2) || (DAT_00536444 == 300)) {
      FUN_00427f10(param_1);
    }
    iVar6 = DAT_004fe624 / 0x1e;
    FUN_00407ff0(param_1,0,DAT_004fe2a8 / 2,DAT_004fe624 / 3 - iVar6,DAT_004fe2a8,2,1);
    FUN_00412d30(param_1,DAT_004fe624 / 3 - iVar6,DAT_004fe2a8 / 2,DAT_004fe624 / 2,DAT_004fe2a8,2);
    FUN_00407ff0(param_1,DAT_004fe624 / 2,DAT_004fe2a8 / 2,(DAT_004fe624 * 5) / 6 - iVar6 / 2,
                 DAT_004fe2a8,1,1);
    FUN_00412d30(param_1,(DAT_004fe624 * 5) / 6 - iVar6 / 2,DAT_004fe2a8 / 2,DAT_004fe624,
                 DAT_004fe2a8,1);
  }
  uVar5 = 0;
  if (DAT_004da174 < 7) {
    if (DAT_004da174 == 6) {
      uVar5 = 0x1e;
    }
    if (DAT_004da174 == 5) {
      uVar5 = 0x3c;
    }
    if (DAT_004da174 < 5) {
      uVar5 = 0x50;
    }
    DVar2 = GetTickCount();
    uVar3 = DVar2 - DVar1;
    while (uVar3 < uVar5) {
      DVar2 = GetTickCount();
      uVar3 = DVar2 - DVar1;
    }
  }
  DAT_004f7124 = 0;
  DAT_004f7128 = 0;
  return;
}

