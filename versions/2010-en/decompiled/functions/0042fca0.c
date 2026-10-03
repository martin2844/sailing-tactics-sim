
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0042fca0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if (DAT_005359d0 == 0) {
    return 0;
  }
  *(double *)(&DAT_004f4bc0 + param_3 * 8) =
       *(double *)(&DAT_004f4bc0 + param_3 * 8) * _DAT_004cc930 -
       (double)*(int *)(&DAT_00535a08 + param_3 * 4) * _DAT_004cc678;
  if (param_3 == 1) {
    DAT_00522fd8 = 0;
  }
  if ((DAT_004f42b8 + 10 < DAT_004f8cd0) && (0 < param_3)) {
    fVar6 = (float10)*(double *)(&DAT_004ffcb8 + param_3 * 8);
  }
  else {
    fVar6 = FUN_0042f330(param_1,param_2,0);
  }
  iVar3 = (int)(longlong)fVar6;
  fVar6 = (float10)fsin((float10)(int)((((uint)(iVar3 < 0x1e) + DAT_00536404 + DAT_004f6d60) -
                                       DAT_004ffdd0) * 0x1e) * (float10)_DAT_004cc568);
  DAT_005230d8 = (uint)(longlong)(fVar6 * (float10)(int)DAT_005359d0);
  uVar2 = DAT_005230d8;
  if (((DAT_004f8b78 == 1) &&
      (uVar4 = param_1 - DAT_00535bc8 >> 0x1f, (int)((param_1 - DAT_00535bc8 ^ uVar4) - uVar4) < 200
      )) && (uVar2 = (int)(DAT_005230d8 * 0xe) / 10, param_3 == 1)) {
    DAT_00522fd8 = -1;
  }
  if (((iVar3 < 0x46) && (DAT_004f69b8 != 4)) && (uVar2 = (int)(uVar2 * iVar3) / 0x46, param_3 == 1)
     ) {
    DAT_00522fd8 = param_3;
  }
  iVar1 = DAT_00523a54;
  if ((int)uVar2 < 0) {
    iVar1 = DAT_00523a54 + 0xb4;
  }
  iVar1 = FUN_0041bc20(iVar1);
  if (((DAT_004da19c == 2) || (DAT_004da19c == 4)) &&
     ((iVar3 < 0x46 && (FUN_00431200(param_1,param_2), iVar1 = DAT_005229c4, (int)uVar2 < 0)))) {
    iVar1 = FUN_0041bc20(DAT_005229c4 + 0xb4);
  }
  if ((iVar3 < 0x5a) && (DAT_004f8b78 == 1)) {
    iVar1 = (((((param_1 - DAT_00535bc8) / 100) * ((param_2 - DAT_004f3858) / 100) < 1) - 1 & 2) - 1
            ) * (((DAT_00523a54 < 0xb5) - 1 & 0xfffffffe) + 1) * -0x2d + iVar1;
  }
  if ((DAT_0050040c == 1) &&
     ((int)(((DAT_005229d0 ^ (int)DAT_005229d0 >> 0x1f) - ((int)DAT_005229d0 >> 0x1f)) * 8) / 10 <
      (param_2 ^ param_2 >> 0x1f) - (param_2 >> 0x1f))) {
    if ((param_2 < 0) && (DAT_005230dc == 1)) {
      iVar1 = iVar1 + 0x5a;
    }
    if ((0 < param_2) && (DAT_005230dc == 3)) {
      iVar1 = iVar1 + -0x5a;
    }
  }
  iVar1 = FUN_0041bc20(iVar1);
  iVar5 = 1;
  if (DAT_004f69b8 != 4) goto LAB_004300bd;
  if (DAT_00536300 == 1) {
    if (param_2 < -400) {
      iVar1 = DAT_004fbac4;
      if (param_1 < 0) {
        iVar5 = 2;
        iVar1 = DAT_004fbacc;
      }
      DAT_00522d28 = FUN_0041bc20(iVar1 + -0xb4);
    }
    else {
      DAT_00522d28 = DAT_004fbac8;
    }
  }
  if (DAT_00536300 == 2) {
    if (param_1 < -599) {
      iVar1 = DAT_004fbacc;
      if (param_2 < 0) {
        iVar5 = 2;
        iVar1 = DAT_004fbac4;
      }
      DAT_00522d28 = FUN_0041bc20(iVar1 + -0xb4);
      if (-600 < param_1) goto LAB_00430001;
    }
    else {
LAB_00430001:
      if (param_1 < -0x96) {
        iVar1 = DAT_004fbacc;
        if (param_2 < 0) {
          iVar1 = DAT_004fbac4;
        }
        DAT_00522d28 = FUN_0041bc20((iVar1 + -0xb4 + DAT_004fbac8) / 2);
      }
    }
    if (-0x96 < param_1) {
      DAT_00522d28 = DAT_004fbac8;
    }
  }
  if (DAT_004da158 == 0) {
    uVar2 = DAT_005359d0;
  }
  if (iVar3 < 0x32) {
    uVar2 = (int)(uVar2 * iVar3) / 100;
  }
  if (iVar5 == 2) {
    uVar2 = (int)(uVar2 * 3 + ((int)(uVar2 * 3) >> 0x1f & 3U)) >> 2;
  }
  if (((int)uVar2 < 0) || (iVar1 = DAT_00522d28, DAT_004da158 == 0)) {
    iVar1 = DAT_00522d28 + 0xb4;
  }
  iVar1 = FUN_0041bc20(iVar1);
LAB_004300bd:
  if (DAT_004f69b8 == 5) {
    if (DAT_00536300 == 1) {
      DAT_00522d28 = ((param_1 < 1) - 1 & 0xf) + 0x4b;
    }
    else {
      DAT_00522d28 = ((param_1 < 1) - 1 & 0xfffffff1) + 0x69;
    }
    if (((int)uVar2 < 0) || (iVar1 = DAT_00522d28, DAT_004da158 == 0)) {
      iVar1 = DAT_00522d28 + 0xb4;
    }
    iVar1 = FUN_0041bc20(iVar1);
  }
  if (DAT_004f69b8 == 6) {
    if (param_2 < -999) {
      DAT_00522d28 = 0xb4;
    }
    else {
      DAT_00522d28 = ((param_1 < 1) - 1 & 0xffffffec) + 0x9b;
    }
    if (-0x259 < param_2) {
      DAT_00522d28 = 0x5a;
    }
    if (((int)uVar2 < 0) || (iVar1 = DAT_00522d28, DAT_004da158 == 0)) {
      iVar1 = DAT_00522d28 + 0xb4;
    }
    iVar1 = FUN_0041bc20(iVar1);
  }
  if (DAT_004f69b8 == 7) {
    if (param_2 < 0x3e9) {
      DAT_00522d28 = ((param_1 < 1) - 1 & 0xfffffff1) + 0x11d;
    }
    else {
      DAT_00522d28 = 10;
    }
    if ((600 < param_2) && (param_2 < 0x3e9)) {
      DAT_00522d28 = ((param_1 < 1) - 1 & 0xffffffec) + 0x14a;
    }
    if (((int)uVar2 < 0) || (iVar1 = DAT_00522d28, DAT_004da158 == 0)) {
      iVar1 = DAT_00522d28 + 0xb4;
    }
    iVar1 = FUN_0041bc20(iVar1);
  }
  iVar5 = DAT_004da218;
  if (iVar3 < 0x12d) {
    iVar5 = FUN_00488b90(0,param_1,param_2,param_3);
  }
  if ((iVar5 < DAT_004da218) && (uVar2 = (int)(uVar2 * iVar5) / DAT_004da218, param_3 == 1)) {
    DAT_00522fd8 = 2;
  }
  DAT_00536418 = iVar1;
  *(int *)(&DAT_00522d30 + param_3 * 4) = iVar1;
  iVar3 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
  *(int *)(&DAT_00535a08 + param_3 * 4) = iVar3;
  return iVar3;
}

