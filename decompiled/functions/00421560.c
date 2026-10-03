
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00421560(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if (DAT_004a60a0 == 1) {
    *(undefined4 *)(&DAT_004a4778 + param_3 * 4) = *(undefined4 *)(&DAT_004ac208 + param_3 * 4);
  }
  if (param_3 == 1) {
    DAT_004aa720 = 0;
  }
  if ((DAT_004a4168 + 10 < DAT_004a5b80) && (0 < param_3)) {
    fVar6 = (float10)*(double *)(&DAT_004a7f28 + param_3 * 8);
  }
  else if (DAT_004a864c == 1) {
    fVar6 = FUN_00420b70(param_1,param_2,0);
  }
  else {
    fVar6 = FUN_00420c40(param_1,param_2,0);
  }
  iVar3 = (int)(longlong)fVar6;
  fVar6 = (float10)fsin((float10)(int)(((((0x1d < iVar3) - 1) - DAT_004a8020) + DAT_004ac94c +
                                       DAT_004a4be4) * 0x1e) * (float10)_DAT_00484d40);
  DAT_004aa800 = (int)(longlong)(fVar6 * (float10)DAT_004ac1dc);
  iVar2 = DAT_004aa800;
  if (((DAT_004a5a4c == 1) &&
      (uVar4 = param_1 - DAT_004ac284 >> 0x1f, (int)((param_1 - DAT_004ac284 ^ uVar4) - uVar4) < 200
      )) && (iVar2 = (DAT_004aa800 * 0xe) / 10, param_3 == 1)) {
    DAT_004aa720 = -1;
  }
  if (((iVar3 < 0x46) && (DAT_004a4958 != 4)) && (iVar2 = (iVar2 * iVar3) / 0x46, param_3 == 1)) {
    DAT_004aa720 = param_3;
  }
  iVar1 = DAT_004aae1c;
  if (iVar2 < 0) {
    iVar1 = DAT_004aae1c + 0xb4;
  }
  iVar1 = FUN_00413cb0(iVar1);
  if (((DAT_00491194 == 2) || (DAT_00491194 == 4)) &&
     ((iVar3 < 0x46 && (FUN_00421ae0(param_1,param_2), iVar1 = DAT_004aa284, iVar2 < 0)))) {
    iVar1 = FUN_00413cb0(DAT_004aa284 + 0xb4);
  }
  if ((iVar3 < 0x5a) && (DAT_004a5a4c == 1)) {
    iVar1 = (((((param_1 - DAT_004ac284) / 100) * ((int)(param_2 - DAT_004a3a08) / 100) < 1) - 1 & 2
             ) - 1) * (((DAT_004aae1c < 0xb5) - 1 & 0xfffffffe) + 1) * -0x2d + iVar1;
  }
  if ((DAT_004a864c == 1) &&
     ((int)(((DAT_004aa290 ^ (int)DAT_004aa290 >> 0x1f) - ((int)DAT_004aa290 >> 0x1f)) * 8) / 10 <
      (int)((param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f)))) {
    if (((int)param_2 < 0) && (DAT_004aa804 == 1)) {
      iVar1 = iVar1 + 0x5a;
    }
    if ((0 < (int)param_2) && (DAT_004aa804 == 3)) {
      iVar1 = iVar1 + -0x5a;
    }
  }
  iVar1 = FUN_00413cb0(iVar1);
  iVar5 = 1;
  if (DAT_004a4958 != 4) goto LAB_00421964;
  uVar4 = param_2;
  if ((DAT_004ac85c == 1) && (uVar4 = DAT_004a67c0, (int)param_2 < -400)) {
    if (param_1 < 0) {
      iVar5 = 2;
      uVar4 = FUN_00413cb0(DAT_004a67c4 + -0xb4);
    }
    else {
      uVar4 = FUN_00413cb0(DAT_004a67bc + -0xb4);
    }
  }
  if (DAT_004ac85c == 2) {
    if (param_1 < -599) {
      iVar1 = DAT_004a67c4;
      if ((int)param_2 < 0) {
        iVar5 = 2;
        iVar1 = DAT_004a67bc;
      }
      uVar4 = FUN_00413cb0(iVar1 + -0xb4);
      if (-600 < param_1) goto LAB_004218b4;
    }
    else {
LAB_004218b4:
      if (param_1 < -0x96) {
        iVar1 = DAT_004a67c4;
        if ((int)param_2 < 0) {
          iVar1 = DAT_004a67bc;
        }
        uVar4 = FUN_00413cb0((int)(iVar1 + -0xb4 + DAT_004a67c0) / 2);
      }
    }
    if (-0x96 < param_1) {
      uVar4 = DAT_004a67c0;
    }
  }
  if (DAT_00491158 == 0) {
    iVar2 = DAT_004ac1dc;
  }
  if (iVar3 < 0x32) {
    iVar2 = (iVar2 * iVar3) / 100;
  }
  if (iVar5 == 2) {
    iVar2 = (int)(iVar2 * 3 + (iVar2 * 3 >> 0x1f & 3U)) >> 2;
  }
  if ((iVar2 < 0) || (DAT_00491158 == 0)) {
    uVar4 = uVar4 + 0xb4;
  }
  iVar1 = FUN_00413cb0(uVar4);
LAB_00421964:
  if (DAT_004a4958 == 5) {
    if (DAT_004ac85c == 1) {
      iVar1 = ((param_1 < 1) - 1 & 0xf) + 0x4b;
    }
    else {
      iVar1 = ((param_1 < 1) - 1 & 0xfffffff1) + 0x69;
    }
    if ((iVar2 < 0) || (DAT_00491158 == 0)) {
      iVar1 = iVar1 + 0xb4;
    }
    iVar1 = FUN_00413cb0(iVar1);
  }
  if (DAT_004a4958 == 6) {
    if ((int)param_2 < -999) {
      iVar1 = 0xb4;
    }
    else {
      iVar1 = ((param_1 < 1) - 1 & 0xffffffec) + 0x9b;
    }
    if (-0x259 < (int)param_2) {
      iVar1 = 0x5a;
    }
    if ((iVar2 < 0) || (DAT_00491158 == 0)) {
      iVar1 = iVar1 + 0xb4;
    }
    iVar1 = FUN_00413cb0(iVar1);
  }
  if (DAT_004a4958 == 7) {
    if ((int)param_2 < 0x3e9) {
      iVar1 = ((param_1 < 1) - 1 & 0xfffffff1) + 0x11d;
    }
    else {
      iVar1 = 10;
    }
    if ((600 < (int)param_2) && ((int)param_2 < 0x3e9)) {
      iVar1 = ((param_1 < 1) - 1 & 0xffffffec) + 0x14a;
    }
    if ((iVar2 < 0) || (DAT_00491158 == 0)) {
      iVar1 = iVar1 + 0xb4;
    }
    iVar1 = FUN_00413cb0(iVar1);
  }
  if (iVar3 < 0x51) {
    iVar3 = FUN_00421b80(0,param_1,param_2);
  }
  else {
    iVar3 = 900;
  }
  if ((iVar3 < 900) && (iVar2 = (iVar2 * iVar3) / 900, param_3 == 1)) {
    DAT_004aa720 = 2;
  }
  DAT_004aa960 = iVar1;
  *(int *)(&DAT_004ac208 + param_3 * 4) = iVar2;
  return iVar2;
}

