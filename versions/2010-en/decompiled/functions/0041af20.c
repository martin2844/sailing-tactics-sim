
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041af20(double param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  double local_18;
  double local_8;
  
  if ((DAT_004da140 < param_2) && (DAT_005363e0 == 1)) {
    return;
  }
  DAT_005364dc = 0;
  if ((DAT_004da190 < 7) || (8 < DAT_004da190)) {
    iVar1 = (&DAT_004fb380)[param_2];
    if ((8 < iVar1) ||
       (((DAT_005363cc == 1 || (DAT_005363bc == 1)) ||
        (SQRT((double)DAT_004faa48) * _DAT_004cc580 * _DAT_004cc6f8 <=
         *(double *)(&DAT_004fe180 + param_2 * 8))))) {
      DAT_005364dc = 0;
    }
    else {
      DAT_005364dc = -1;
    }
    if ((0x11 < iVar1) && (0x5a < *(int *)(&DAT_004fecc8 + param_2 * 4))) {
      DAT_005364dc = 1;
    }
    if (((1 < *(int *)(&DAT_00535e40 + param_2 * 4)) &&
        (*(int *)(&DAT_004fecc8 + param_2 * 4) < 0x5b)) &&
       ((DAT_005363b8 == 0 && (DAT_005363bc == 0)))) {
      DAT_005364dc = 1;
    }
    if ((((DAT_005363b8 == 1) || (DAT_005363c4 == 1)) || (DAT_005363bc == 1)) &&
       ((0xc < iVar1 && (0x5a < *(int *)(&DAT_004fecc8 + param_2 * 4))))) {
      DAT_005364dc = 1;
    }
  }
  if ((DAT_004da190 < 4) && (DAT_005363bc == 0)) {
    DAT_005364dc = DAT_005364dc + -2;
  }
  if (DAT_00536528 == 1) {
    DAT_005364dc = DAT_005364dc + -2;
  }
  dVar3 = (DAT_004f3a38 - DAT_004f3a40) * _DAT_004cc520;
  if (((DAT_004da140 < param_2) ||
      (((6 < DAT_004da190 && (DAT_005363b8 != 1)) ||
       (DAT_004f8cd0 < *(int *)(&DAT_004f3998 + param_2 * 4))))) ||
     (*(int *)(&DAT_004f4350 + param_2 * 4) + DAT_00536494 <= DAT_004f8cd0)) {
    iVar1 = *(int *)(&DAT_004fc2c0 + param_2 * 4);
    iVar9 = 1;
    iVar5 = (int)(DAT_004f4200 + (DAT_004f4200 >> 0x1f & 3U)) >> 2;
    if ((iVar5 < iVar1) && (iVar5 < *(int *)(&DAT_00522f28 + param_2 * 4))) {
      iVar9 = 2;
    }
    if (((param_2 <= DAT_004da140) && (DAT_004da190 < 7)) &&
       (DAT_004f8cd0 < *(int *)(&DAT_004f4350 + param_2 * 4) + DAT_00536494)) {
      iVar9 = 2;
    }
    if (((DAT_005364cc == 1) && (0x78 < *(int *)(&DAT_004fecc8 + param_2 * 4))) &&
       (*(int *)(&DAT_00512278 + param_2 * 4) == 0)) {
      if (iVar1 < 9) {
        iVar9 = 1;
      }
      if (iVar1 < 5) {
        iVar9 = 0;
      }
    }
    if (DAT_005363c4 == 1) {
      iVar9 = 2;
    }
    if ((DAT_004da190 == 1) && (param_2 <= DAT_004da140)) {
      *(undefined4 *)(&DAT_004f3998 + param_2 * 4) = 20000;
    }
    if ((DAT_0053652c == 1) && (iVar1 < 9)) {
      iVar9 = ((8 < (int)(&DAT_004fb380)[param_2]) - 1 & 0xfffffffe) + 1;
    }
  }
  else {
    iVar9 = -1;
  }
  if ((0 < *(int *)(&DAT_004fe638 + param_2 * 4)) || (*(int *)(&DAT_00512278 + param_2 * 4) == 0x5a)
     ) {
    iVar9 = 1;
  }
  fVar10 = (float10)FUN_0041b920(iVar9);
  if ((DAT_004da14c == 1) && ((DAT_004da190 == 7 || (DAT_005363c0 == 3)))) {
    fVar10 = (float10)_DAT_004cc650;
  }
  iVar1 = *(int *)(&DAT_00522ff0 + param_2 * 4);
  if (DAT_005363b8 == 0) {
    dVar4 = _DAT_00535ce0;
    if (0 < iVar9 * iVar1) {
      dVar4 = _DAT_00535ca0;
    }
    local_18 = (double)((fVar10 * (float10)dVar4 + (float10)DAT_00535c70) /
                       (fVar10 - (float10)_DAT_004cc700));
    if (((DAT_005363c4 == 1) && (*(int *)(&DAT_00512278 + param_2 * 4) < 0x5a)) &&
       (*(int *)(&DAT_004fe638 + param_2 * 4) == 0)) {
      local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_004cc588;
    }
    if (((DAT_005363bc == 1) && (*(int *)(&DAT_00512278 + param_2 * 4) < 0x50)) &&
       (uVar6 = (int)(longlong)_DAT_005355f8 + param_2, uVar8 = (int)uVar6 >> 0x1f,
       ((uVar6 ^ uVar8) - uVar8 & 3 ^ uVar8) == uVar8)) {
      local_18 = local_18 - _DAT_004cc5c8;
    }
    local_8 = (DAT_004f3a40 - (double)DAT_005364dc * dVar3 * _DAT_004cc5c8) - dVar3;
    if (((DAT_004da190 < 4) || (DAT_005364bc == 1)) && ((DAT_005363bc == 0 && (DAT_005363cc == 0))))
    {
      local_8 = local_8 - (dVar3 + dVar3);
    }
    if (DAT_004da190 == 1) {
      local_8 = local_8 - dVar3 * _DAT_004cc710;
    }
    if ((DAT_005363bc == 1) && (DAT_005364dc == 1)) {
      local_8 = dVar3 + DAT_004f3a40;
    }
    if (DAT_005363c4 == 1) {
      local_8 = local_8 - dVar3 * _DAT_004cc710;
    }
  }
  if (DAT_005363b8 == 1) {
    dVar4 = _DAT_00535ce8;
    if (0 < iVar9 * iVar1) {
      dVar4 = _DAT_00535ca0;
    }
    fVar10 = (fVar10 * (float10)dVar4 + (float10)DAT_00535c70) / (fVar10 - (float10)_DAT_004cc700);
    local_18 = (double)fVar10;
    if (iVar9 == 2) {
      if (DAT_004da190 == 10) {
        fVar10 = fVar10 - (float10)iVar1 * (float10)dVar3 * (float10)_DAT_004cc718;
        local_18 = (double)fVar10;
      }
      if (DAT_005364cc == 1) {
        fVar10 = fVar10 - (float10)iVar1 * (float10)dVar3 * (float10)_DAT_004cc5c0;
        local_18 = (double)fVar10;
      }
      if (DAT_004da190 == 9) {
        local_18 = (double)(fVar10 - (float10)iVar1 * (float10)dVar3 * (float10)_DAT_004cc5c8);
      }
    }
    local_8 = ((DAT_004f3a40 + _DAT_004f3a48) * _DAT_004cc4f8 -
              (double)DAT_005364dc * dVar3 * _DAT_004cc5c8) - dVar3;
  }
  FUN_0041b970(local_18,local_8,dVar3,param_1,0x27,param_2,1,param_3,iVar9);
  iVar9 = DAT_004f8cd0;
  iVar5 = DAT_004da190;
  iVar1 = DAT_004da140;
  if (DAT_004da190 < 2) {
    return;
  }
  if (DAT_005364cc == 1) {
    return;
  }
  if ((DAT_004da140 < param_2) ||
     ((((6 < DAT_004da190 && (DAT_005363b8 != 1)) ||
       (DAT_004f8cd0 < *(int *)(&DAT_004f3998 + param_2 * 4))) ||
      (*(int *)(&DAT_004f4350 + param_2 * 4) + (DAT_00536494 * 2) / 3 <= DAT_004f8cd0)))) {
    if (((1 < DAT_004da190) && (DAT_004da190 < 4)) && (param_2 <= DAT_004da140)) {
      *(undefined4 *)(&DAT_004f3998 + param_2 * 4) = 20000;
    }
    iVar2 = *(int *)(&DAT_004fc2c0 + param_2 * 4);
    uVar6 = 1;
    iVar7 = (int)(DAT_004f4200 + (DAT_004f4200 >> 0x1f & 3U)) >> 2;
    if ((iVar7 < iVar2) && (iVar7 < *(int *)(&DAT_00522f28 + param_2 * 4))) {
      uVar6 = 2;
    }
    if (((param_2 <= iVar1) && (iVar5 < 7)) &&
       (iVar9 < *(int *)(&DAT_004f4350 + param_2 * 4) + DAT_00536494)) {
      uVar6 = 2;
    }
    if (((iVar2 < 5) && (uVar6 = (uint)(iVar5 == 7), iVar2 < 5)) &&
       ((iVar5 == 9 && (0x78 < *(int *)(&DAT_004fecc8 + param_2 * 4))))) {
      uVar6 = 0xfffffffe;
    }
    if ((DAT_0053652c == 1) && (iVar2 < 10)) goto LAB_0041b531;
  }
  else {
LAB_0041b531:
    uVar6 = 0xffffffff;
  }
  if ((0 < *(int *)(&DAT_004fe638 + param_2 * 4)) || (*(int *)(&DAT_00512278 + param_2 * 4) == 0x5a)
     ) {
    uVar6 = 1;
  }
  fVar10 = (float10)FUN_0041b920(uVar6);
  iVar1 = *(int *)(&DAT_00522ff0 + param_2 * 4);
  if (DAT_005363b8 == 0) {
    dVar4 = _DAT_00535cd8;
    if (0 < (int)(uVar6 * iVar1)) {
      dVar4 = _DAT_00535ca8;
    }
    local_18 = (double)((fVar10 * (float10)dVar4 + (float10)_DAT_00535c78) /
                       (fVar10 - (float10)_DAT_004cc700));
    if ((uVar6 == 2) && (DAT_004da190 == 3)) {
      local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_004cc5c0;
    }
    if ((uVar6 == 2) && (DAT_005363c4 == 1)) {
      local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_004cc718;
    }
    local_8 = _DAT_004f3a48 -
              (_DAT_004cc700 - ((double)DAT_005364dc + (double)DAT_005364dc)) * dVar3;
    if (DAT_005363c4 == 1) {
      local_8 = local_8 - dVar3 * _DAT_004cc710;
    }
    if ((DAT_004da190 < 4) || (DAT_005364bc == 1)) {
      local_8 = local_8 - (dVar3 + dVar3);
    }
  }
  uVar8 = uVar6;
  if (DAT_005363b8 == 1) {
    dVar4 = _DAT_00535cd8;
    if (0 < (int)(uVar6 * iVar1)) {
      dVar4 = _DAT_00535cb0;
    }
    local_18 = (double)((fVar10 * (float10)dVar4 + (float10)_DAT_00535c80) /
                       (fVar10 - (float10)_DAT_004cc700));
    if ((((DAT_004da190 == 10) && (0xc < (int)(&DAT_004fb380)[param_2])) && (0x5a < DAT_004feccc))
       && ((*(int *)(&DAT_005356b0 + param_2 * 4) == 0 &&
           (5 < *(int *)(&DAT_004fc2c0 + param_2 * 4))))) {
      DAT_005364dc = 1;
      uVar8 = 2;
    }
    if (uVar8 == 2) {
      local_18 = local_18 - (double)iVar1 * dVar3 * _DAT_004cc718;
    }
    if (((DAT_004da190 == 10) && (DAT_005364dc == 1)) &&
       ((uVar8 == 2 &&
        (((0x5a < DAT_004feccc && (*(int *)(&DAT_005356b0 + param_2 * 4) == 0)) &&
         (5 < *(int *)(&DAT_004fc2c0 + param_2 * 4))))))) {
      local_8 = (_DAT_004f3a48 + _DAT_004f3a50) * _DAT_004cc4f8 - dVar3 * _DAT_004cc720;
    }
    else {
      local_8 = (_DAT_004f3a48 + _DAT_004f3a50) * _DAT_004cc4f8 -
                (_DAT_004cc700 - ((double)DAT_005364dc + (double)DAT_005364dc)) * dVar3;
    }
  }
  DAT_00523198 = uVar6;
  FUN_0041b970(local_18,local_8,dVar3,param_1,0x2d,param_2,2,param_3,uVar8);
  iVar9 = DAT_004f8cd0;
  iVar5 = DAT_004da190;
  iVar1 = DAT_004da140;
  if (DAT_004da190 < 4) {
    return;
  }
  if (DAT_005363b8 == 1) {
    return;
  }
  if (DAT_004da140 < param_2) {
LAB_0041b7e5:
    if ((DAT_004da190 < 7) && (param_2 <= DAT_004da140)) {
      *(undefined4 *)(&DAT_004f3998 + param_2 * 4) = 20000;
    }
  }
  else if (DAT_004da190 < 7) {
    if ((*(int *)(&DAT_004f3998 + param_2 * 4) <= DAT_004f8cd0) &&
       (DAT_004f8cd0 < *(int *)(&DAT_004f4350 + param_2 * 4) + DAT_00536494)) {
      iVar7 = -1;
      goto LAB_0041b863;
    }
    goto LAB_0041b7e5;
  }
  iVar2 = *(int *)(&DAT_004fc2c0 + param_2 * 4);
  iVar7 = 2;
  if ((iVar2 < 1) && (*(int *)(&DAT_00522f28 + param_2 * 4) < 1)) {
    iVar7 = 1;
  }
  if (((param_2 <= iVar1) && (iVar5 < 7)) &&
     (iVar9 < *(int *)(&DAT_004f4350 + param_2 * 4) + DAT_00536494)) {
    iVar7 = 2;
  }
  if ((iVar2 < 7) && (iVar5 != 7)) {
    iVar7 = 0;
  }
  if ((DAT_0053652c == 1) && (iVar2 < 10)) {
    iVar7 = (*(int *)(&DAT_004fecc8 + param_2 * 4) < 0x65) - 1;
  }
LAB_0041b863:
  if ((0 < *(int *)(&DAT_004fe638 + param_2 * 4)) || (*(int *)(&DAT_00512278 + param_2 * 4) == 0x5a)
     ) {
    iVar7 = 1;
  }
  fVar10 = (float10)FUN_0041b920(iVar7);
  dVar4 = _DAT_00535cd0;
  if (0 < iVar7 * *(int *)(&DAT_00522ff0 + param_2 * 4)) {
    dVar4 = _DAT_00535cb0;
  }
  FUN_0041b970((double)((fVar10 * (float10)dVar4 + (float10)_DAT_00535c80) /
                       (fVar10 - (float10)_DAT_004cc700)),
               _DAT_004f3a50 -
               (_DAT_004cc5c0 - ((double)DAT_005364dc + (double)DAT_005364dc)) * dVar3,dVar3,param_1
               ,0x33,param_2,3,param_3,iVar7);
  return;
}

