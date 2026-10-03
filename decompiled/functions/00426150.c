
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00426150(int param_1,int param_2,int param_3)

{
  char cVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_20;
  int local_14;
  int local_10;
  int local_c;
  
  if (0 < param_3) {
    local_c = *(int *)(&DAT_004aa5b0 + param_3 * 4);
  }
  DAT_004a5f0c = 0;
  if (param_3 == 1) {
    DAT_004aa62c = 0;
    DAT_004a4ee8 = 0;
  }
  if (param_3 == 2) {
    DAT_004aa638 = 0;
  }
  if ((param_3 < 1) || (*(double *)(&DAT_004a7f28 + param_3 * 8) <= _DAT_004850e8)) {
    local_14 = FUN_00421b80(1,param_1,param_2);
  }
  else {
    local_14 = 900;
  }
  DAT_004aaeac = DAT_004ac840;
  if (((DAT_00491194 == 9) && (0x78 < DAT_004ac840)) && (DAT_004ac840 < 0xf0)) {
    local_14 = 900;
  }
  if ((DAT_00491194 == 10) && ((0x14a < DAT_004ac840 || (DAT_004ac840 < 0x1e)))) {
    local_14 = 900;
  }
  if (param_3 < 3) {
    *(int *)(&DAT_004a8678 + param_3 * 4) = local_14;
  }
  local_20 = DAT_004aa390;
  if (local_14 < 900) {
    local_10 = DAT_004aa390 / 2;
    local_20 = (int)(longlong)((double)local_14 * _DAT_00485168 * (double)local_10) + local_10;
  }
  if ((DAT_004a609c < DAT_004ac568 + -10) && (local_14 < 900)) {
    DAT_004a5f0c = 1;
    local_20 = (local_20 * 0xd) / 10;
  }
  if ((DAT_004ac1e0 == 1) && (local_14 < 300)) {
    local_20 = (local_20 * 9) / 10;
  }
  iVar8 = 0;
  DAT_004a5b94 = 0;
  iVar6 = 1;
  iVar9 = 0;
  do {
    dVar2 = (double)param_1 - *(double *)((int)&DAT_004abd90 + iVar9);
    dVar3 = (double)param_2 - *(double *)((int)&DAT_004a4730 + iVar9);
    if ((int)(longlong)SQRT(dVar3 * dVar3 + dVar2 * dVar2) < *(int *)((int)&DAT_004a4ec4 + iVar8)) {
      DAT_004a5b94 = 1;
      local_20 = local_20 + *(int *)((int)&DAT_004a4e9c + iVar8);
      if (param_3 == 1) {
        DAT_004aa62c = 1;
      }
      local_10 = iVar6;
      if (param_3 == 2) {
        DAT_004aa638 = 1;
      }
    }
    iVar9 = iVar9 + 8;
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar9 < 0x21);
  DAT_004a4390 = 0;
  if (DAT_004a864c == 1) {
    fVar10 = FUN_00420b70(param_1,param_2,0);
  }
  else {
    fVar10 = FUN_00420c40(param_1,param_2,0);
  }
  if ((int)(longlong)fVar10 < (int)(((DAT_004a4958 < 2) - 1 & 0xffffffc5) + 99)) {
    if ((4 < DAT_00491194) && (DAT_00491194 < 9)) {
      FUN_00421ae0(param_1,param_2);
    }
    iVar6 = DAT_004ac840;
    if (DAT_004ac840 < 0x3c) {
      iVar6 = DAT_004ac840 + 0x168;
    }
    uVar5 = iVar6 - DAT_004aa284 >> 0x1f;
    if ((int)((iVar6 - DAT_004aa284 ^ uVar5) - uVar5) < 0x1e) {
      local_20 = (local_20 * 0xc) / 10;
      DAT_004a4390 = 1;
    }
    uVar5 = iVar6 - DAT_004a71a8 >> 0x1f;
    if ((int)((iVar6 - DAT_004a71a8 ^ uVar5) - uVar5) < 0x1e) {
      local_20 = (local_20 * 8) / 10;
      DAT_004a4390 = -1;
    }
    if ((param_3 == 1) && (DAT_004a4390 != 0)) {
      DAT_004a4ee8 = 1;
    }
  }
  if (DAT_004a5b94 == 1) {
    DAT_004aaeac = *(int *)(&DAT_004ac0a0 + local_10 * 4);
  }
  else if (DAT_004ac998 == 0) {
    DAT_004aaeac = DAT_004ac840 + (local_20 - DAT_004aa390) * 3;
  }
  else {
    DAT_004aaeac = DAT_004ac840 + (DAT_004aa390 - local_20) * 3;
  }
  if ((DAT_004a5a4c == 1) && (DAT_004aaeac < 0x7d)) {
    DAT_004aaeac = 0x7d;
  }
  DAT_004aaeac = FUN_00413cb0(DAT_004aaeac);
  DAT_004abd84 = 0;
  if ((1 < DAT_004a4958) && (DAT_004a4958 != 5)) {
    dVar2 = SQRT((double)(param_1 * param_1 + param_2 * param_2));
    iVar6 = FUN_0041bb10(param_1,-param_2);
    uVar5 = iVar6 - DAT_004ac840 >> 0x1f;
    iVar8 = (iVar6 - DAT_004ac840 ^ uVar5) - uVar5;
    cVar1 = iVar8 < 0x5a;
    if (0x10e < iVar8) {
      cVar1 = '\x02';
    }
    iVar8 = 0;
    DAT_004abd84 = 0;
    if (0 < DAT_004ac9f4) {
      piVar7 = &DAT_004a67bc;
      local_10 = DAT_004ac9f4;
      do {
        iVar9 = *piVar7;
        uVar5 = DAT_004ac840 - iVar9 >> 0x1f;
        iVar4 = (DAT_004ac840 - iVar9 ^ uVar5) - uVar5;
        if ((((iVar4 < 0x1e) && (cVar1 != '\0')) && (_DAT_00485170 < dVar2)) &&
           ((*(int *)((int)&DAT_004a7184 + iVar8) * 2 + 5 < iVar6 &&
            (iVar6 < *(int *)((int)&DAT_004a5a54 + iVar8) * 2 + -5)))) {
          DAT_004abd84 = 1;
          DAT_004aaeac = iVar9;
        }
        if (((0x14a < iVar4) && (cVar1 != '\0')) &&
           ((_DAT_00485170 < dVar2 &&
            ((*(int *)((int)&DAT_004a7184 + iVar8) * 2 + 5 < iVar6 &&
             (iVar6 < *(int *)((int)&DAT_004a5a54 + iVar8) * 2 + -5)))))) {
          DAT_004abd84 = 1;
          DAT_004aaeac = iVar9;
        }
        iVar8 = iVar8 + 4;
        piVar7 = piVar7 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    iVar8 = 1;
    if (0 < DAT_004ac9f4) {
      piVar7 = &DAT_004a67bc;
      iVar9 = 0;
      do {
        iVar4 = FUN_00413cb0(*piVar7 + -0xb4);
        uVar5 = DAT_004ac840 - iVar4 >> 0x1f;
        if (((((int)((DAT_004ac840 - iVar4 ^ uVar5) - uVar5) < 0x1e) && (cVar1 == '\0')) &&
            (_DAT_00485178 < dVar2)) &&
           ((*(int *)((int)&DAT_004a7184 + iVar9) * 2 + 5 < iVar6 &&
            (iVar6 < *(int *)((int)&DAT_004a5a54 + iVar9) * 2 + -5)))) {
          DAT_004aaeac = FUN_00413cb0(*piVar7 + -0xb4);
          DAT_004abd84 = 1;
        }
        iVar4 = FUN_00413cb0(*piVar7 + -0xb4);
        uVar5 = DAT_004ac840 - iVar4 >> 0x1f;
        if (((0x14a < (int)((DAT_004ac840 - iVar4 ^ uVar5) - uVar5)) && (cVar1 == '\0')) &&
           ((_DAT_00485178 < dVar2 &&
            ((*(int *)((int)&DAT_004a7184 + iVar9) * 2 + 5 < iVar6 &&
             (iVar6 < *(int *)((int)&DAT_004a5a54 + iVar9) * 2 + -5)))))) {
          DAT_004aaeac = FUN_00413cb0(*piVar7 + -0xb4);
          DAT_004abd84 = 1;
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 4;
        piVar7 = piVar7 + 1;
      } while (iVar8 <= DAT_004ac9f4);
    }
    if (DAT_004a4958 == 6) {
      if ((((DAT_004ac840 < 0x14) || (0x140 < DAT_004ac840)) && (param_1 < 0x28a)) &&
         ((-0x28a < param_1 && (param_2 < -500)))) {
        DAT_004abd84 = 1;
        DAT_004aaeac = 0x15e;
      }
      else {
        DAT_004abd84 = 0;
      }
      if (((0x8c < DAT_004ac840) && (DAT_004ac840 < 200)) &&
         ((param_1 < 0x28a && ((-900 < param_1 && (param_2 < -800)))))) {
        DAT_004abd84 = 1;
        DAT_004aaeac = 0xaa;
      }
    }
    if (DAT_004a4958 == 7) {
      if ((((DAT_004ac840 < 0xe1) && (0xa5 < DAT_004ac840)) && (param_1 < 500)) &&
         ((-900 < param_1 && (500 < param_2)))) {
        DAT_004abd84 = 1;
        DAT_004aaeac = 0xc3;
      }
      else {
        DAT_004abd84 = 0;
      }
      if (((-1 < DAT_004ac840) && (DAT_004ac840 < 0x1e)) &&
         ((param_1 < 500 && ((-900 < param_1 && (800 < param_2)))))) {
        DAT_004abd84 = 1;
        DAT_004aaeac = 0xf;
      }
    }
  }
  if (local_20 < 6) {
    local_20 = 6;
  }
  DAT_004ac4d8 = local_20 / 10 + 1;
  if (local_14 < 900) {
    DAT_004ac4d8 = (local_14 * DAT_004ac4d8) / 900;
  }
  if ((param_3 == 1) && (local_20 < DAT_004aa390 + -1)) {
    _DAT_004a61fc = param_3;
  }
  if (0 < param_3) {
    uVar5 = local_c - DAT_004aaeac >> 0x1f;
    if ((int)((local_c - DAT_004aaeac ^ uVar5) - uVar5) < 0xb4) {
      DAT_004aaeac = (DAT_004aaeac + local_c * 2) / 3;
      return local_20;
    }
    if ((0x10e < local_c) && (DAT_004aaeac < 0x5a)) {
      DAT_004aaeac = FUN_00413cb0((DAT_004aaeac + -0x2d0 + local_c * 2) / 3);
    }
    if ((local_c < 0x5a) && (DAT_004aaeac < 0x10e)) {
      DAT_004aaeac = FUN_00413cb0((DAT_004aaeac + -0x168 + local_c * 2) / 3);
    }
  }
  return local_20;
}

