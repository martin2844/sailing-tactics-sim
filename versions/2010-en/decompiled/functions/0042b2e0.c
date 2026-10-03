
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042b2e0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  bool bVar9;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  int local_c;
  
  iVar2 = DAT_004da1f8;
  puVar8 = &DAT_005135a0;
  for (iVar3 = 0x3cab; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0xffffd8f0;
    puVar8 = puVar8 + 1;
  }
  puVar8 = &DAT_00525ab8;
  for (iVar3 = 0x3cab; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0xffffd8f0;
    puVar8 = puVar8 + 1;
  }
  puVar8 = &DAT_00500420;
  for (iVar3 = 0x3cab; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0xffffffff;
    puVar8 = puVar8 + 1;
  }
  DAT_004f8dbc = 0xffffffff;
  DAT_004f7f90 = 0xffffffff;
  DAT_00534ea8 = 0;
  DAT_00536394 = 0;
  _DAT_00536230 = (double)CONCAT44(DAT_005359f4,DAT_005359f0);
  DAT_004fb9ac = 0;
  DAT_004fb9b0 = 0;
  if (iVar2 != 999) {
    DAT_00536524 = 0;
  }
  DAT_004da220 = 0xffff8ad0;
  DAT_004da228 = 0xffff8ad0;
  DAT_004da21c = 30000;
  DAT_004da224 = 30000;
  DAT_004fe770 = ((DAT_004f69b8 < 2) - 1 & 0xffffffc0) + 0x80;
  DAT_00536418 = 0;
  if ((((DAT_004fb5d4 == 1) || (iVar2 == 2)) || (iVar2 == 3)) || ((iVar2 == 0xb || (iVar2 == 9)))) {
    DAT_004fe770 = 0x200;
  }
  piVar4 = &DAT_004f8d84;
  iVar3 = 0x28;
  do {
    *piVar4 = iVar3;
    iVar3 = iVar3 + 10;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 0x83);
  if (iVar2 == 0) {
    DAT_004da208 = (-(uint)(DAT_004da19c != 8) & 0x1a9) + 0x4b;
  }
  else {
    DAT_004da208 = 2000;
  }
  if (iVar2 == 1) {
    DAT_004da208 = 2000;
  }
  if (iVar2 == 2) {
    DAT_004da208 = 2000;
  }
  if ((iVar2 == 4) || (iVar2 == 5)) {
    DAT_004da208 = 0x708;
  }
  if (iVar2 == 7) {
    DAT_004da208 = 3000;
  }
  if (iVar2 == 10) {
    DAT_004da208 = 0x9c4;
  }
  if (iVar2 == 100) {
    DAT_004da208 = 0x5dc;
  }
  if (iVar2 == 0x65) {
    DAT_004da208 = 0x9c4;
  }
  if (iVar2 == 0x67) {
    DAT_004da208 = 3000;
  }
  if (iVar2 == 0x69) {
    DAT_004da208 = 0x44c;
  }
  DAT_004fe630 = 0xfffffd44;
  if ((DAT_004da1e8 == 1) && ((DAT_004da194 < 0xb || (DAT_004da19c == 8)))) {
    DAT_004da1e8 = 0;
  }
  DAT_004da1cc = 0xffffffff;
  DAT_004da1e0 = 0xfffffe0c;
  DAT_004f3f64 = 0;
  DAT_004f3f68 = 0;
  DAT_00536428 = 0;
  _DAT_004da1a0 = 1000;
  _DAT_004da1a4 = 0xfffffed4;
  if (DAT_00536470 == 1) {
    DAT_004da194 = 2;
    DAT_004fe9d8 = 0;
    DAT_004da190 = 7;
  }
  iVar2 = FUN_0041e000(0x19);
  DAT_004da170 = iVar2 + -0x66;
  iVar2 = (DAT_004da19c == 8) + 0x59;
  _DAT_004f3f60 = 0;
  DAT_004f3f64 = 0;
  _DAT_004f71c0 = 2;
  DAT_004f3f68 = 0;
  _DAT_005359e0 = 0;
  DAT_004f71c4 = 2;
  DAT_005359e4 = 0;
  _DAT_004f71c8 = 2;
  _DAT_0050f6d0 = 4;
  DAT_005359e8 = 0;
  DAT_0050f6d4 = 4;
  _DAT_004f49a0 = 0;
  _DAT_00512d60 = 0;
  DAT_0050f6d8 = 4;
  DAT_004f49a4 = 0;
  DAT_00512d64 = 0;
  DAT_004f49a8 = 0;
  DAT_00512d68 = 0;
  _DAT_004f3998 = 20000;
  _DAT_004faf80 = 0;
  _DAT_004fbab0 = 0;
  _DAT_004f399c = 20000;
  _DAT_004faf84 = 0;
  DAT_004fbab4 = 0;
  _DAT_004f39a0 = 20000;
  _DAT_004faf88 = 0;
  _DAT_004fbab8 = 0;
  iVar3 = 0;
  DAT_004fc3e4 = iVar2;
  do {
    if ((*(int *)((int)&DAT_00525a78 + iVar3) < 0) || (2 < *(int *)((int)&DAT_00525a78 + iVar3))) {
      *(undefined4 *)((int)&DAT_00525a78 + iVar3) = 1;
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 9);
  local_c = 1;
  iVar3 = DAT_004da194;
  if (0 < DAT_004da194) {
    local_10 = &DAT_004fbf38;
    local_18 = &DAT_004fe188;
    local_14 = &DAT_00536244;
    iVar7 = 0;
    do {
      iVar2 = DAT_004f42b8;
      *(undefined4 *)((int)&DAT_004fe8ac + iVar7) = 0;
      *(int *)((int)&DAT_004fad44 + iVar7) = iVar2;
      *local_14 = 0;
      iVar2 = FUN_0041e000(6);
      *(int *)((int)&DAT_005232ec + iVar7) = iVar2 + 0xc;
      if (DAT_004fb5d4 == 1) {
        iVar2 = FUN_0041e000(6);
        *(int *)((int)&DAT_005232ec + iVar7) = iVar2 + 0xf + DAT_004da1fc;
      }
      iVar2 = DAT_004da1f8;
      if ((0 < DAT_004da1f8) && (DAT_004da1f8 != 5)) {
        *(undefined4 *)((int)&DAT_005232ec + iVar7) = 8;
      }
      if ((iVar2 == 999) && (DAT_004da248 == 2)) {
        iVar2 = FUN_0041e000(4);
        *(int *)((int)&DAT_005232ec + iVar7) = iVar2 + -1 + DAT_004da1fc;
      }
      iVar2 = DAT_005363f8;
      *(undefined4 *)((int)&DAT_004f447c + iVar7) = 0;
      if (iVar2 == 1) {
        DAT_004da168 = 0;
      }
      *(undefined4 *)((int)&DAT_004faef4 + iVar7) = 0xffffffff;
      *(undefined4 *)((int)&DAT_004f4534 + iVar7) = 0;
      *(undefined4 *)((int)&DAT_00522e6c + iVar7) = 0;
      *local_18 = 0;
      local_18[1] = 0;
      iVar2 = DAT_005363fc;
      *(undefined4 *)((int)&DAT_00522ff4 + iVar7) = 1;
      *(undefined4 *)((int)&DAT_004f4a74 + iVar7) = 0;
      *(undefined4 *)((int)&DAT_004fe6d4 + iVar7) = 0;
      if (iVar2 == 0) {
        iVar2 = FUN_0041e000(499);
        *(int *)((int)&DAT_004f49bc + iVar7) = iVar2 / 200 + -1;
      }
      iVar3 = DAT_005363c0;
      *(undefined4 *)((int)&DAT_00522dd4 + iVar7) = 0xfffffd44;
      *(undefined4 *)((int)&DAT_005230f4 + iVar7) = 0xfffffc18;
      *(undefined4 *)((int)&DAT_00522c24 + iVar7) = 0xfffffc18;
      iVar2 = DAT_004da198;
      if ((int)DAT_004da140 < local_c) {
        iVar6 = *(int *)((int)&DAT_004f49bc + iVar7) + (DAT_004da198 + -7) / 2 + -1 + DAT_004fc3e4;
        *(int *)((int)&DAT_004fc3e4 + iVar7) = iVar6;
        if (9 < iVar2) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = iVar6 + 1;
        }
        if (iVar3 == 1) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = *(int *)((int)&DAT_004fc3e4 + iVar7) + -2;
        }
        if (DAT_004da194 == 2) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = *(int *)((int)&DAT_004fc3e4 + iVar7) + -2;
        }
        if (0xb < iVar2) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = *(int *)((int)&DAT_004fc3e4 + iVar7) + 1;
        }
        if (0xd < iVar2) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = *(int *)((int)&DAT_004fc3e4 + iVar7) + 1;
        }
        if (iVar2 == 1) {
          *(int *)((int)&DAT_004fc3e4 + iVar7) = (*(int *)((int)&DAT_004fc3e4 + iVar7) * 0x55) / 100
          ;
        }
      }
      if ((((DAT_004da190 == 10) || (DAT_005363c4 == 1)) || (0 < iVar3)) ||
         ((DAT_004da190 == 8 || (DAT_0053652c == 1)))) {
        *(undefined4 *)((int)&DAT_004f42c4 + iVar7) = 3;
      }
      else {
        *(undefined4 *)((int)&DAT_004f42c4 + iVar7) = 2;
      }
      iVar2 = FUN_0041e000(0x19);
      iVar3 = DAT_004da194;
      bVar9 = DAT_004da194 == 2;
      *(int *)((int)&DAT_004fadd4 + iVar7) = iVar2;
      if (bVar9) {
        *(undefined4 *)((int)&DAT_004fadd4 + iVar7) = 0;
      }
      *(undefined4 *)((int)&DAT_005350dc + iVar7) = 0;
      *(undefined4 *)((int)&DAT_004f4354 + iVar7) = 0xfffff830;
      *(undefined4 *)((int)&DAT_004fe9d4 + iVar7) = 0xfffff830;
      *(undefined4 *)((int)&DAT_00535624 + iVar7) = 0xfffff830;
      bVar9 = DAT_005363fc == 0;
      *(undefined4 *)((int)&DAT_004fe63c + iVar7) = 0;
      if (bVar9) {
        local_10[-1] = 0;
        *local_10 = 0;
        local_10[1] = 0;
      }
      local_c = local_c + 1;
      local_18 = local_18 + 2;
      iVar7 = iVar7 + 4;
      local_14 = local_14 + 1;
      local_10 = local_10 + 4;
      iVar2 = DAT_004fc3e4;
    } while (local_c <= iVar3);
  }
  uVar1 = DAT_004da140;
  if (0 < (int)DAT_004da140) {
    puVar8 = &DAT_004f6a6c;
    for (uVar5 = DAT_004da140 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &DAT_004fbbac;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &DAT_004f7124;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &DAT_005116e4;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    DAT_004f4520 = 0;
    DAT_004f4524 = 0;
    puVar8 = &DAT_004f7ee4;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 1;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &DAT_004fe77c;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 1;
      puVar8 = puVar8 + 1;
    }
    puVar8 = &DAT_00500384;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = 0xffffffff;
      puVar8 = puVar8 + 1;
    }
  }
  _DAT_00536230 = (double)DAT_004f42b8;
  iVar7 = 1;
  DAT_00534d64 = 30000;
  DAT_005233a8 = 1;
  DAT_00536460 = 0;
  DAT_00536464 = 0;
  DAT_00536394 = 0;
  if (DAT_00536470 == 1) {
    _DAT_00536230 = 0.0;
  }
  if ((iVar3 == 2) && (_DAT_004fc3e8 = DAT_004da198 + -10 + iVar2, DAT_005363c0 == 1)) {
    _DAT_004fc3e8 = _DAT_004fc3e8 + -1;
  }
  if (uVar1 == 2) {
    _DAT_004fc3e8 = DAT_00536400 + iVar2;
  }
  _DAT_004faf90 = 1;
  DAT_00534fdc = DAT_004f42b8 + 10;
  DAT_004f6d64 = 0;
  DAT_00536404 = 0;
  DAT_00534ea8 = 0;
  DAT_004f6d2c = 0;
  DAT_00534e94 = 0;
  DAT_00534ea4 = 0;
  DAT_004fe768 = 0;
  DAT_004fafa0 = 0;
  DAT_005350d4 = 0;
  DAT_00525a64 = 0;
  if (0 < iVar3) {
    puVar8 = &DAT_004f853c;
    do {
      if (DAT_00536470 == 0) {
        FUN_00431960(iVar7);
        iVar3 = DAT_004da194;
      }
      else {
        *puVar8 = 1;
      }
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar7 <= iVar3);
  }
  iVar2 = 1;
  if (0 < iVar3) {
    iVar3 = 0;
    do {
      FUN_00431960(iVar2);
      if (DAT_0053527c == 1) {
        iVar7 = FUN_0041e000(200);
        *(int *)((int)&DAT_004fb54c + iVar3) = iVar7 + -100 + DAT_004f6d38;
        iVar7 = FUN_0041e000(200);
        iVar7 = iVar7 + -100 + DAT_004f7f88;
LAB_0042bc3d:
        *(int *)((int)&DAT_00522af4 + iVar3) = iVar7;
      }
      else {
        if ((DAT_005364c8 != 0) || (DAT_0053640c != 0)) {
          iVar7 = FUN_0041e000(100);
          *(int *)((int)&DAT_004fb54c + iVar3) =
               (DAT_005229d4 + DAT_00536410 * 2) / 3 + iVar7 + -0x32;
          iVar7 = FUN_0041e000(100);
          iVar7 = (DAT_00522ac8 + DAT_00536414 * 2) / 3 + iVar7 + -0x32;
          goto LAB_0042bc3d;
        }
        if ((DAT_004da19c == 8) || (DAT_004da1f8 == 5)) {
          iVar7 = FUN_0041e000(300);
          *(int *)((int)&DAT_004fb54c + iVar3) =
               (DAT_005229d4 + DAT_00536410 * 8) / 9 + iVar7 + -0x96;
          iVar7 = FUN_0041e000(300);
          iVar7 = (DAT_00522ac8 + DAT_00536414 * 8) / 9 + iVar7 + -0x96;
          goto LAB_0042bc3d;
        }
        iVar6 = FUN_0041e000(300);
        iVar7 = DAT_005229d4 + DAT_00536410 * 3;
        *(int *)((int)&DAT_004fb54c + iVar3) =
             iVar6 + -0x96 + ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
        iVar6 = FUN_0041e000(300);
        iVar7 = DAT_00522ac8 + DAT_00536414 * 3;
        *(int *)((int)&DAT_00522af4 + iVar3) =
             iVar6 + -0x96 + ((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 <= DAT_004da194);
  }
  FUN_0042f530();
  puVar8 = &DAT_0053601c;
  for (iVar2 = 0x7b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  if ((DAT_004da1d8 < 3) && (DAT_00511624 = 1, DAT_004da140 == 2)) {
    DAT_00511628 = 1;
  }
  if ((DAT_0053527c == 1) && (DAT_00536408 == 0)) {
    DAT_004da1e4 = ((DAT_004da194 < 0x10) - 1 & 2) + 4;
  }
  else {
    DAT_004da1e4 = 8;
  }
  iVar2 = 0;
  DAT_005233a4 = 0;
  iVar3 = DAT_004da194;
  if (0 < DAT_004da194) {
    do {
      iVar6 = 0x16;
      iVar7 = iVar2 + 8;
      do {
        *(undefined4 *)(iVar7 + 0x511108) = *(undefined4 *)((int)&DAT_004f1618 + iVar2);
        *(undefined4 *)(iVar7 + 0x51110c) = *(undefined4 *)((int)&DAT_004f161c + iVar2);
        *(undefined4 *)(iVar7 + 0x525770) = *(undefined4 *)((int)&DAT_004f3870 + iVar2);
        *(undefined4 *)(iVar7 + 0x525774) = *(undefined4 *)((int)&DAT_004f3874 + iVar2);
        iVar7 = iVar7 + -0x130;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + 8;
    } while (iVar3 != 0);
  }
  if (DAT_005364c8 == 1) {
    DAT_00512d64 = 1;
    DAT_00512d68 = 1;
    DAT_004da14c = 1;
  }
  FUN_004b06ed((Tact2010CString *)&DAT_004fec38,&DAT_004dd6f0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec3c,s_Betty_004dd6e8);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec40,s_Fuzzy_004dd6e0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec44,&DAT_004dd6d8);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec48,s_Flyer_004dd6d0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec4c,s_Alice_004dd6c8);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec50,&DAT_004dd6c0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec54,s_Snake_004dd6b8);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec58,s_Ticket_004dd6b0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec5c,s_Moose_004dd6a8);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec60,&DAT_004dd6a0);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec64,s_Blitz_004dd698);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec68,s_Hammer_004dd690);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec6c,s_Squall_004dd688);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec70,s_Power_004dd680);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec74,s_Dragon_004dd678);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec78,s_Magic_004dd670);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec7c,s_Force_004dd668);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec80,s_Flash_004dd660);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec84,s_Vixen_004dd658);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec88,s_Tango_004dd650);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec8c,s_Condor_004dd648);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec90,s_Eagle_004dd640);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec94,s_Equation_004dd634);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec98,s_Tsunami_004dd62c);
  FUN_004b06ed((Tact2010CString *)&DAT_004fec9c,s_Pizzazz_004dd624);
  FUN_004b06ed((Tact2010CString *)&DAT_004feca0,s_Pirate_004dd61c);
  FUN_004b06ed((Tact2010CString *)&DAT_004feca4,s_Hootowl_004dd614);
  FUN_004b06ed((Tact2010CString *)&DAT_004feca8,s_Comet_004dd60c);
  if (DAT_004da1f0 == 1) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Apollo_004db774);
  }
  if (DAT_004da1f0 == 2) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Apple_004db76c);
  }
  if (DAT_004da1f0 == 3) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db764);
  }
  if (DAT_004da1f0 == 4) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db75c);
  }
  if (DAT_004da1f0 == 5) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Flame_004db754);
  }
  if (DAT_004da1f0 == 6) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db750);
  }
  if (DAT_004da1f0 == 7) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Hot_Flash_004db744);
  }
  if (DAT_004da1f0 == 8) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Hotrod_004db73c);
  }
  if (DAT_004da1f0 == 9) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Red_Dog_004db734);
  }
  if (DAT_004da1f0 == 10) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Robin_004db72c);
  }
  if (DAT_004da1f0 == 0xb) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,&DAT_004db724);
  }
  if (DAT_004da1f0 == 0xc) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Rover_004db71c);
  }
  if (DAT_004da1f0 == 0xd) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Scarlett_004db700);
  }
  if (DAT_004da1f0 == 0xe) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Sunrise_004db714);
  }
  if (DAT_004da1f0 == 0xf) {
    FUN_004b06ed((Tact2010CString *)&DAT_004fec34,s_Thunder_004db70c);
  }
  return;
}

