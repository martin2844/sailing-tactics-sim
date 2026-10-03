
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041eb80(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  DAT_004911c0 = 0xffffffff;
  puVar6 = &DAT_004aa398;
  for (iVar4 = 0x79; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  DAT_004911d4 = 0xfffffe0c;
  DAT_004ac964 = 0;
  DAT_00491198 = 1000;
  DAT_0049119c = 0xfffffed4;
  if (DAT_004ac9ac == 1) {
    DAT_0049118c = 2;
    DAT_004a7978 = 0;
    DAT_00491188 = 7;
  }
  iVar4 = FUN_00415a20(0x19);
  DAT_00491168 = iVar4 + -0x87;
  _DAT_004a4e88 = 2;
  _DAT_004a8660 = 4;
  DAT_004a4e8c = 2;
  DAT_004a8664 = 4;
  _DAT_004a4608 = 0;
  _DAT_004a4e90 = 2;
  DAT_004a8668 = 4;
  DAT_004a460c = 0;
  iVar4 = 0;
  DAT_004a4610 = 0;
  _DAT_004a9440 = 0;
  _DAT_004a3a18 = 20000;
  _DAT_004a6090 = 0;
  DAT_004a9444 = 0;
  _DAT_004a3a1c = 20000;
  _DAT_004a6094 = 0;
  DAT_004a6fcc = 0x5f;
  DAT_004a9448 = 0;
  _DAT_004a3a20 = 20000;
  _DAT_004a6098 = 0;
  do {
    if ((*(int *)((int)&DAT_004ab160 + iVar4) < 0) || (2 < *(int *)((int)&DAT_004ab160 + iVar4))) {
      *(undefined4 *)((int)&DAT_004ab160 + iVar4) = 1;
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 < 9);
  local_10 = 1;
  iVar4 = DAT_0049118c;
  iVar3 = 0x5f;
  if (0 < DAT_0049118c) {
    local_4 = &DAT_004a6bc8;
    local_8 = &DAT_004a764c;
    puVar6 = &DAT_004a71d0;
    local_c = &DAT_004a439c;
    iVar7 = 0;
    iVar2 = DAT_004ac944;
    do {
      bVar8 = DAT_004ac940 == 1;
      *(undefined4 *)((int)&DAT_004a42f4 + iVar7) = 0;
      if (bVar8) {
        DAT_00491160 = 0;
      }
      *puVar6 = 0;
      *(undefined4 *)((int)&DAT_004a5f94 + iVar7) = 0xffffffff;
      *local_c = 0;
      *(undefined4 *)((int)&DAT_004aa664 + iVar7) = 0;
      puVar6[1] = 0;
      *(undefined4 *)((int)&DAT_004aa734 + iVar7) = 1;
      *(undefined4 *)((int)&DAT_004a46ac + iVar7) = 0;
      *(undefined4 *)((int)&DAT_004a76d4 + iVar7) = 0;
      if (iVar2 == 0) {
        iVar4 = FUN_00415a20(0x31);
        iVar3 = DAT_004a6fcc;
        *(int *)((int)&DAT_004a461c + iVar7) = iVar4 / 10 + -2;
      }
      iVar4 = DAT_00491190;
      if ((int)DAT_00491140 < local_10) {
        if (DAT_00491194 == 8) {
          *(int *)((int)&DAT_004a6fcc + iVar7) =
               *(int *)((int)&DAT_004a461c + iVar7) + (DAT_00491190 + -7) / 2 + -1 + iVar3;
        }
        else {
          *(int *)((int)&DAT_004a6fcc + iVar7) =
               *(int *)((int)&DAT_004a461c + iVar7) + DAT_00491190 + -8 + iVar3;
        }
        if (DAT_004ac908 == 1) {
          *(int *)((int)&DAT_004a6fcc + iVar7) = *(int *)((int)&DAT_004a6fcc + iVar7) + -2;
        }
        if (iVar4 == 1) {
          *(int *)((int)&DAT_004a6fcc + iVar7) = (*(int *)((int)&DAT_004a6fcc + iVar7) * 0x55) / 100
          ;
        }
        if (0xb < iVar4) {
          *(int *)((int)&DAT_004a6fcc + iVar7) = *(int *)((int)&DAT_004a6fcc + iVar7) + 1;
        }
        if (0xd < iVar4) {
          *(int *)((int)&DAT_004a6fcc + iVar7) = *(int *)((int)&DAT_004a6fcc + iVar7) + 1;
        }
      }
      if ((((DAT_00491188 == 10) || (DAT_004ac90c == 1)) || (DAT_004ac908 == 1)) ||
         (DAT_00491188 == 8)) {
        *(undefined4 *)((int)&DAT_004a4174 + iVar7) = 3;
      }
      else {
        *(undefined4 *)((int)&DAT_004a4174 + iVar7) = 2;
      }
      iVar3 = FUN_00415a20(0x19);
      iVar4 = DAT_0049118c;
      bVar8 = DAT_0049118c == 2;
      *(int *)((int)&DAT_004a5e94 + iVar7) = iVar3;
      if (bVar8) {
        *(undefined4 *)((int)&DAT_004a5e94 + iVar7) = 0;
      }
      *(undefined4 *)((int)&DAT_004a41f4 + iVar7) = 0xfffff830;
      *(undefined4 *)((int)&DAT_004a7974 + iVar7) = 0xfffff830;
      *(undefined4 *)((int)&DAT_004abf1c + iVar7) = 0xfffff830;
      iVar2 = DAT_004ac944;
      bVar8 = DAT_004ac944 == 0;
      *(undefined4 *)((int)&DAT_004abb74 + iVar7) = 0;
      *local_8 = 0;
      if (bVar8) {
        local_4[-1] = 0;
        *local_4 = 0;
        local_4[1] = 0;
      }
      local_c = local_c + 1;
      local_10 = local_10 + 1;
      local_8 = local_8 + 1;
      puVar6 = puVar6 + 2;
      local_4 = local_4 + 4;
      iVar7 = iVar7 + 4;
      iVar3 = DAT_004a6fcc;
    } while (local_10 <= iVar4);
  }
  uVar1 = DAT_00491140;
  if (0 < (int)DAT_00491140) {
    DAT_004a4388 = 0;
    DAT_004a438c = 0;
    puVar6 = &DAT_004a496c;
    for (uVar5 = DAT_00491140 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a684c;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a4e7c;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a89c4;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a4efc;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 1;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a776c;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 1;
      puVar6 = puVar6 + 1;
    }
    puVar6 = &DAT_004a85d4;
    for (uVar5 = uVar1 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0xffffffff;
      puVar6 = puVar6 + 1;
    }
  }
  _DAT_004ac828 = (double)DAT_004a4168;
  DAT_004ab8b4 = 30000;
  DAT_004aa980 = 1;
  DAT_004ac99c = 0;
  DAT_004ac9a0 = 0;
  DAT_004ac8dc = 0;
  if (DAT_004ac9ac == 1) {
    _DAT_004ac828 = 0.0;
  }
  if (iVar4 == 2) {
    _DAT_004a6fd0 = DAT_00491190 + -10;
    if (DAT_004ac9ac == 1) {
      _DAT_004a6fd0 = DAT_00491190 + -0xc;
    }
    _DAT_004a6fd0 = _DAT_004a6fd0 + iVar3;
    if (DAT_004ac908 == 1) {
      _DAT_004a6fd0 = _DAT_004a6fd0 + -1;
    }
  }
  if (uVar1 == 2) {
    _DAT_004a6fd0 = DAT_004ac948 + iVar3;
  }
  iVar3 = 1;
  DAT_004abae4 = DAT_004a4168 + 10;
  DAT_004a60a0 = 1;
  DAT_004a4be8 = 0;
  DAT_004ac94c = 0;
  DAT_004ab9d8 = 0;
  DAT_004a4bd8 = 0;
  DAT_004ab9c4 = 0;
  DAT_004ab9d4 = 0;
  DAT_004a7754 = 0;
  DAT_004a60a8 = 0;
  DAT_004abb6c = 0;
  DAT_004ab14c = 0;
  if (0 < iVar4) {
    puVar6 = &DAT_004a5424;
    iVar2 = DAT_004ac9ac;
    do {
      if (iVar2 == 0) {
        FUN_00421c40(iVar3);
        iVar2 = DAT_004ac9ac;
        iVar4 = DAT_0049118c;
      }
      else {
        *puVar6 = 1;
      }
      iVar3 = iVar3 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar3 <= iVar4);
  }
  FUN_00420dd0();
  puVar6 = &DAT_004ac694;
  for (iVar4 = 100; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if ((DAT_004911cc < 3) && (DAT_004a8914 = 1, DAT_00491140 == 2)) {
    DAT_004a8918 = 1;
  }
  return;
}

