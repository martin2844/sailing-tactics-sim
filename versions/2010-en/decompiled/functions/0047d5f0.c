
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0047d5f0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  double dVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  int local_2c;
  uint uStack_14;
  double local_10;
  
  uStack_14 = 0x405b8000;
  if (DAT_004da1f8 == 2) {
    uStack_14 = 0x40518000;
  }
  if (DAT_004da1f8 == 3) {
    uStack_14 = 0x40568000;
  }
  if (DAT_004da1f8 == 999) {
    uStack_14 = 0x40568000;
  }
  if (DAT_004da1f8 == 6) {
    uStack_14 = 0x40568000;
    iVar3 = FUN_0047dfa0(-6000,0x16f8,-5000,-3000,0xe96,0x744,param_2,param_3);
    if (iVar3 == 1) {
      uStack_14 = 0x40440000;
    }
    iVar3 = FUN_0047dfa0(-6000,0x16f8,-5000,-3000,0xaae,0x35c,param_2,param_3);
    if (iVar3 == 1) {
      uStack_14 = 0x403e0000;
    }
  }
  if (DAT_004da1f8 == 7) {
    uStack_14 = 0x402e0000;
  }
  if (DAT_004da1f8 == 9) {
    uStack_14 = 0x40320000;
  }
  if (DAT_004da1f8 == 10) {
    uStack_14 = 0x40440000;
  }
  if (DAT_004da1f8 == 0xb) {
    uStack_14 = 0x40260000;
  }
  if (DAT_004da1f8 == 0xc) {
    uStack_14 = 0x40468000;
  }
  if (DAT_004da1f8 == 0x69) {
    uStack_14 = 0x40390000;
  }
  if (DAT_004da1f8 == 0x68) {
    uStack_14 = 0x40310000;
  }
  if (DAT_004da1f8 == 100) {
    uStack_14 = 0x40518000;
  }
  if (DAT_004da1f8 == 0x65) {
    uStack_14 = 0x404b8000;
  }
  if (DAT_004da1f8 == 0x6a) {
    uStack_14 = 0x402e0000;
  }
  if (DAT_004da1f8 == 0x66) {
    uStack_14 = 0x40400000;
  }
  if (DAT_004da1f8 == 999) {
    uStack_14 = 0x40568000;
  }
  local_10 = (double)((ulonglong)uStack_14 << 0x20);
  if (param_5 == 0) {
    iVar3 = DAT_00535498;
    local_2c = DAT_00522f08 + DAT_00511374;
    if (DAT_00511374 != 0) goto LAB_0047d855;
  }
  else {
    iVar3 = DAT_00511374 + DAT_00535e3c + DAT_00522f08;
  }
  local_2c = iVar3;
LAB_0047d855:
  if (param_4 == 2) {
    local_2c = DAT_00535498;
  }
  iVar3 = 1;
  if (0 < local_2c) {
    do {
      if (((iVar3 <= DAT_00535498) || (local_2c - DAT_00511374 <= iVar3)) || (param_5 != 0)) {
        fVar4 = (float10)fcos(-(float10)*(double *)(&DAT_004fafa8 + iVar3 * 8));
        iVar2 = *(int *)(&DAT_00522cb0 + iVar3 * 4);
        fVar5 = (float10)fsin(-(float10)*(double *)(&DAT_004fafa8 + iVar3 * 8));
        fVar6 = fVar4 * (float10)(param_2 - *(int *)(&DAT_00535218 + iVar3 * 4)) -
                fVar5 * (float10)(param_3 - *(int *)(&DAT_004f4b58 + iVar3 * 4));
        dVar1 = (double)(fVar4 * (float10)(param_3 - *(int *)(&DAT_004f4b58 + iVar3 * 4)) +
                        (float10)(double)fVar5 *
                        (float10)(param_2 - *(int *)(&DAT_00535218 + iVar3 * 4)));
        if (((0 < iVar2) && (iVar2 < 0x24)) && ((float10)_DAT_004cc658 < fVar6)) {
          fVar6 = fVar6 * (float10)_DAT_004cc468;
        }
        if (((0 < iVar2) && (0x24 < iVar2)) && (fVar6 < (float10)_DAT_004cc658)) {
          fVar6 = fVar6 * (float10)_DAT_004cc468;
        }
        fVar4 = (float10)dVar1 * (float10)dVar1 +
                (fVar6 / (float10)*(double *)(&DAT_004fb5e0 + iVar3 * 8)) *
                (fVar6 / (float10)*(double *)(&DAT_004fb5e0 + iVar3 * 8));
        if ((fVar4 < (float10)_DAT_004cc658) || ((float10)_DAT_004cccc8 < fVar4)) {
          fVar4 = (float10)_DAT_004cccc0;
        }
        else {
          fVar4 = SQRT(fVar4) / (float10)*(int *)(&DAT_00534fe0 + iVar3 * 4);
        }
        dVar1 = _DAT_004cc4f8;
        if (DAT_004da1f8 == 1) {
          dVar1 = _DAT_004cc650;
        }
        if ((DAT_004da1f8 == 2) || (DAT_004da1f8 == 3)) {
          dVar1 = _DAT_004cc650;
        }
        if (DAT_004da1f8 == 7) {
          dVar1 = _DAT_004cc770;
        }
        if (DAT_004da1f8 == 9) {
          dVar1 = _DAT_004cc518;
        }
        if (DAT_004da1f8 == 10) {
          dVar1 = _DAT_004cc660;
        }
        if (DAT_004da1f8 == 0xb) {
          dVar1 = _DAT_004cc6d8;
        }
        if (DAT_004da1f8 == 0xc) {
          dVar1 = _DAT_004cc6d8;
        }
        if (DAT_004da1f8 == 0x67) {
          dVar1 = _DAT_004cc508;
        }
        if (DAT_004da1f8 == 0x69) {
          dVar1 = _DAT_004cc5f0;
        }
        if (DAT_004da1f8 == 0x68) {
          dVar1 = _DAT_004cc638;
        }
        if (DAT_004da1f8 == 100) {
          dVar1 = _DAT_004cc770;
        }
        if (DAT_004da1f8 == 0x65) {
          dVar1 = _DAT_004cc668;
        }
        if (DAT_004da1f8 == 0x6a) {
          dVar1 = _DAT_004cc570;
        }
        if (DAT_004da1f8 == 0x66) {
          dVar1 = _DAT_004cc570;
        }
        fVar5 = (float10)dVar1;
        if (DAT_004da1f8 == 999) {
          if (DAT_004da248 == 2) {
            if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
              fVar5 = (float10)_DAT_004ccfc0;
            }
            else {
              fVar5 = (float10)_DAT_004cc630;
            }
          }
          else {
            fVar5 = (float10)_DAT_004cc650;
          }
        }
        fVar5 = (fVar4 * (float10)_DAT_004cc920 - (float10)_DAT_004cc920) * fVar5;
        if (fVar5 < (float10)_DAT_004cc658) {
          fVar5 = (float10)_DAT_004cc658;
        }
        if ((((DAT_004da1f8 == 7) && (iVar3 == 3)) && (-0xa8c < param_3)) &&
           (((param_3 < -300 && (param_2 < 0x870)) && (0x514 < param_2)))) {
          fVar5 = (float10)_DAT_004cc730;
        }
        if (DAT_00522f08 < iVar3) {
          fVar5 = fVar5 - (float10)_DAT_004cc788;
        }
        if (fVar5 < (float10)local_10) {
          local_10 = (double)fVar5;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= local_2c);
  }
  if (DAT_004da1f8 == 7) {
    iVar3 = FUN_0047dfa0(500,0,900,-0x960,2000,2000,param_2,param_3);
    if ((iVar3 == 1) && (local_10 < _DAT_004cc418)) {
      local_10 = 9.0;
    }
    if (DAT_004da1f8 == 7) {
      iVar3 = FUN_0047dfa0(0x640,0x834,500,0,3000,3000,param_2,param_3);
      if ((iVar3 == 1) && (local_10 < _DAT_004cc418)) {
        local_10 = 9.0;
      }
      if (((((DAT_004da1f8 == 7) && (param_2 < -0x4b0)) && (-0x6b3 < param_2)) &&
          ((param_3 < 300 && (-600 < param_3)))) && (local_10 < _DAT_004cc418)) {
        local_10 = 9.0;
      }
    }
  }
  if (((DAT_004fb5d4 == 1) && (param_2 < 0xe29)) &&
     ((param_3 < 0x187e && (local_10 < (double)((ulonglong)uStack_14 << 0x20))))) {
    local_10 = 50.0;
  }
  if (((DAT_004da1f8 == 10) && (local_10 < _DAT_004cc838)) &&
     (iVar3 = FUN_0047def0(-7000,0xa8c,0x352,0x992,-0xd7a,-0x6a4,param_2,param_3), iVar3 == 1)) {
    local_10 = 15.0;
  }
  if (DAT_004da1f8 == 9) {
    iVar3 = FUN_0047def0(-0x5a,-0x1838,-8000,0x2945,0x299,0x2828,param_2,param_3);
    if (iVar3 == 1) {
      local_10 = 30.0;
    }
    if (((-700 < param_2) && (param_2 < 0x26ac)) && ((param_3 < 0x390 && (-0x7d < param_3)))) {
      local_10 = 19.0;
    }
    iVar3 = FUN_0047def0(-0x17c0,-0x2d0,-0x57c,-700,-0x7d,0x390,param_2,param_3);
    if (iVar3 == 1) {
      local_10 = 22.0;
    }
  }
  if (DAT_004da1f8 == 0xb) {
    if (((0x19fa < param_2) && (param_2 < 0x2ac6)) &&
       ((0x7da < param_3 && ((param_3 < 0x927 && (local_10 < _DAT_004cc418)))))) {
      local_10 = 9.0;
    }
    iVar3 = FUN_0047def0(0x18a9,0x1152,0xde3,0x280a,0xfe6,0x129f,param_2,param_3);
    if ((iVar3 == 1) && (local_10 < _DAT_004cc580)) {
      local_10 = 10.0;
    }
  }
  if ((((DAT_004da1f8 == 0x68) && (-0x929 < param_2)) && (param_2 < -0x4fc)) &&
     ((-0x640 < param_3 && (local_10 < _DAT_004cc5d0)))) {
    local_10 = 25.0;
  }
  if (((DAT_004da1f8 == 0x69) &&
      (iVar3 = FUN_0047dfa0(-0xd34,-0x4db,-0xdfc,-0x9a6,-0xc30,-0xab4,param_2,param_3), iVar3 == 1))
     && (local_10 < _DAT_004cc5a0)) {
    local_10 = 30.0;
  }
  if (((DAT_004da1f8 == 0x66) &&
      (iVar3 = FUN_0047dfa0(-0x578,-0x6a4,-0x157c,-0xd48,-0x10e,0x317,param_2,param_3), iVar3 == 1))
     && (local_10 < _DAT_004cc5a0)) {
    local_10 = 30.0;
  }
  return (float10)local_10;
}

