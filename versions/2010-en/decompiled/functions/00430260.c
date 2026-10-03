
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00430260(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  float10 fVar10;
  double local_8;
  
  iVar3 = param_2;
  iVar6 = DAT_004f8cd0;
  if (DAT_005359d0 == 0) {
    return 0;
  }
  iVar4 = DAT_004f42b8 + 1;
  *(double *)(&DAT_004f4bc0 + param_3 * 8) =
       *(double *)(&DAT_004f4bc0 + param_3 * 8) * _DAT_004cc930 -
       (double)*(int *)(&DAT_00535a08 + param_3 * 4) * _DAT_004cc678;
  if ((iVar4 < iVar6) && (0 < param_3)) {
    fVar10 = (float10)*(double *)(&DAT_004ffcb8 + param_3 * 8);
  }
  else {
    fVar10 = FUN_0042f330(param_1,param_2,0);
  }
  iVar6 = (int)(longlong)fVar10;
  if ((iVar6 < 0x1e) && (DAT_004da1f8 != 7)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  fVar10 = (float10)fsin((float10)(((iVar4 + DAT_00536404 + DAT_004f6d60) - DAT_004ffdd0) * 0x1e) *
                         (float10)_DAT_004cc568);
  param_2 = (int)(longlong)(fVar10 * (float10)DAT_005359d0);
  if (DAT_00536510 == 1) {
    param_2 = DAT_005359d0;
  }
  if (param_3 == 1) {
    DAT_00522fd8 = 0;
  }
  DAT_005230d8 = param_2;
  iVar4 = param_3;
  if (DAT_004da1f8 == 1) {
    if (iVar3 < -0x8fc) {
      iVar4 = 0x96;
      local_8 = _DAT_004cc538;
    }
    if ((iVar3 < -0x5db) && (-0x8fd < iVar3)) {
      iVar4 = 0xa0;
      local_8 = _DAT_004cc6b0;
    }
    if (iVar3 < 0x2bd) {
      if (-0x5dd < iVar3) {
        iVar4 = 0xaa;
        local_8 = _DAT_004cc4f8;
      }
      if (700 < iVar3) goto LAB_004303c3;
    }
    else {
LAB_004303c3:
      iVar4 = 0xb4;
      local_8 = _DAT_004cc668;
    }
    if (0x640 < iVar3) {
      iVar4 = 0xb4;
      local_8 = _DAT_004cc400;
    }
    if (((iVar3 < 0xfb) && (-0x5dd < iVar3)) && (param_1 < -0x8fc)) {
      iVar4 = 0x5a;
      local_8 = _DAT_004cc600;
    }
    if (0x514 < param_1) {
      iVar4 = 0x5a;
      local_8 = _DAT_004cc468;
    }
    if ((0x88e < param_1) && (0x3d4 < iVar3)) {
      iVar4 = 100;
      local_8 = _DAT_004cc570;
    }
    if (param_1 < -0xe10) {
      local_8 = _DAT_004cc570;
    }
    if (((iVar3 < 300) && (-0x5aa < iVar3)) && ((param_1 < -0x708 && (-0xaf0 < param_1)))) {
      iVar4 = 0x87;
    }
    if ((((iVar3 < 0) && (-900 < iVar3)) && (param_1 < 0x8ca)) && (0x366 < param_1)) {
      iVar4 = 0x7d;
      local_8 = _DAT_004cc650;
    }
  }
  if (DAT_004da1f8 == 2) {
    iVar4 = 0x46;
    local_8 = 1.0;
    iVar5 = FUN_0047def0(-0x52d,0x20d,-4000,2000,-5000,-0x316,param_1,iVar3);
    if (iVar5 == 1) {
      iVar4 = 0x6e;
    }
    iVar5 = FUN_0047def0(-0x474,-0x6c2,-4000,100,-5000,-0x8fc,param_1,iVar3);
    if (iVar5 == 1) {
      iVar4 = 0xaa;
    }
  }
  if (DAT_004da1f8 == 3) {
    iVar4 = 0xb4;
    if (param_1 < 0x48) {
      if (iVar3 < -3000) {
        iVar4 = 200;
        local_8 = _DAT_004cc650;
      }
      else {
        iVar4 = 200;
        local_8 = _DAT_004cc738;
      }
    }
    else {
      if ((iVar3 < -3000) && (iVar4 = 0xd2, local_8 = _DAT_004cc650, iVar3 < -3000)) {
LAB_00430588:
        if (iVar3 < -0x577) goto LAB_004305c8;
      }
      else if (iVar3 < -0x577) {
        local_8 = _DAT_004cc650;
        if (param_1 < 0xd48) {
          iVar4 = 0xc3;
          local_8 = _DAT_004cc600;
        }
        goto LAB_00430588;
      }
      iVar4 = 0xb4;
      local_8 = _DAT_004cc4f8;
      if (0x708 < param_1) {
        iVar4 = 0xa5;
      }
    }
  }
LAB_004305c8:
  if (DAT_004fb5d4 == 1) {
    iVar4 = 0x5a;
    local_8 = _DAT_004cc650;
    if (0x40fc < param_1) {
      local_8 = _DAT_004cc660;
    }
    if (iVar3 < 0x866) {
      if ((param_1 < 0x40fe) && (0x3961 < param_1)) {
        iVar4 = 0x6e;
        local_8 = _DAT_004cc4f8;
      }
      if (0x865 < iVar3) goto LAB_00430624;
LAB_00430649:
      if ((0x289f < param_1) && (param_1 < 0x3962)) {
        iVar4 = 100;
        local_8 = _DAT_004cc668;
      }
      if (0x865 < iVar3) goto LAB_0043066e;
    }
    else {
LAB_00430624:
      if ((param_1 < 0x40fe) && (0x3961 < param_1)) {
        iVar4 = 0x4b;
        local_8 = _DAT_004cc4f8;
      }
      if (iVar3 < 0x866) goto LAB_00430649;
LAB_0043066e:
      if ((0x262e < param_1) && (param_1 < 0x3962)) {
        iVar4 = 0x50;
        local_8 = _DAT_004cc668;
      }
    }
    if (iVar3 < 0x840) {
      if ((param_1 < 0x28a0) && (8999 < param_1)) {
        iVar4 = 0x3c;
        local_8 = _DAT_004cc468;
      }
      if (0x83f < iVar3) goto LAB_004306fa;
      if ((param_1 < 9000) && (0x1765 < param_1)) {
        iVar4 = 0x3c;
        local_8 = _DAT_004cc668;
      }
      if (0x83f < iVar3) goto LAB_004306fa;
      if (-0x186b < iVar3) {
        if (param_1 < 0x1766) {
          iVar4 = 0x46;
          local_8 = _DAT_004cc668;
        }
        goto LAB_004306fa;
      }
LAB_00430702:
      if (param_1 < 0x1766) {
        iVar4 = 0x50;
        local_8 = _DAT_004cc668;
      }
    }
    else {
LAB_004306fa:
      if (iVar3 < -0x186a) goto LAB_00430702;
    }
    if (iVar3 < 0x840) {
      if ((param_1 < 0x2864) && (0x1d88 < param_1)) {
        local_8 = _DAT_004cc538;
      }
      if (0x83f < iVar3) goto LAB_00430743;
    }
    else {
LAB_00430743:
      if ((param_1 < 0x26f7) && (0x1995 < param_1)) {
        iVar4 = 0x5a;
        local_8 = _DAT_004cc650;
      }
      if (0x83f < iVar3) {
        if ((param_1 < 0x1996) && (4999 < param_1)) {
          iVar4 = 0x82;
          local_8 = _DAT_004cc400;
        }
        if (0x83f < iVar3) {
          if ((param_1 < 5000) && (0xdab < param_1)) {
            iVar4 = 0x82;
            local_8 = _DAT_004cc650;
          }
          if (0x83f < iVar3) {
            if ((param_1 < 5000) && (-0x2329 < param_1)) {
              iVar4 = 0x82;
              local_8 = _DAT_004cc650;
            }
            if (((0x83f < iVar3) && (param_1 < 0x307)) && (-0x2329 < param_1)) {
              iVar4 = 0x82;
              local_8 = _DAT_004cc738;
            }
          }
        }
      }
    }
    if (((0x1099 < iVar3) && (iVar3 < 0x1c84)) && ((param_1 < 0x194b && (-1 < param_1)))) {
      iVar4 = 0x82;
      local_8 = _DAT_004cc3f8;
    }
    if (((-0x3e9 < iVar3) && (iVar3 < 0x44c)) && ((param_1 < 0x29cc && (0x1c1f < param_1)))) {
      iVar4 = 0x122;
      local_8 = _DAT_004cc5f0;
    }
    if ((((0x780 < iVar3) && (iVar3 < 0xdac)) && (param_1 < -0x474)) && (-9000 < param_1)) {
      iVar4 = 0x5a;
    }
    if (((-1 < param_2) && (-0x22aa < iVar3)) &&
       ((iVar3 < -0xe74 && ((param_1 < 0x27f1 && (0x1df6 < param_1)))))) {
      local_8 = _DAT_004cc5f0;
    }
  }
  if (DAT_004da1f8 == 6) {
    iVar4 = 0xbe;
    if (param_1 < 300) {
      iVar4 = 0xb4;
    }
    local_8 = _DAT_004cc508;
    if (iVar3 < 0x5d2) {
      if (param_1 < -0x370) {
        iVar4 = 0xa5;
      }
      if (param_1 < -0x9c4) {
        iVar4 = 0x8c;
      }
    }
  }
  if (DAT_004da1f8 == 7) {
    if ((iVar3 < -0x514) && (iVar4 = 0xb4, iVar3 < -0x514)) {
LAB_00430917:
      if (-0x2ef < iVar3) goto LAB_0043091f;
LAB_0043092c:
      if (0x564 < iVar3) goto LAB_00430934;
    }
    else {
      if (iVar3 < -0x2ee) {
        iVar4 = 0xaa;
        goto LAB_00430917;
      }
LAB_0043091f:
      if (iVar3 < 0x565) {
        iVar4 = 0xa0;
        goto LAB_0043092c;
      }
LAB_00430934:
      iVar4 = 0x96;
    }
    local_8 = _DAT_004cc730;
    if (-1 < param_2) {
      local_8 = _DAT_004cc938;
    }
    uVar8 = (uint)(-1 < param_2);
    uVar7 = (uint)(iVar6 < 0xf);
    if (((param_1 < -0x1c2) && (iVar3 < 0)) && (uVar8 == 1)) {
      uVar7 = uVar8;
    }
    if (((param_1 < -400) && (-1 < iVar3)) && (uVar8 == 1)) {
      uVar7 = uVar8;
    }
    if (((param_1 < -0x15e) && (599 < iVar3)) && (uVar8 == 1)) {
      uVar7 = uVar8;
    }
    fVar10 = (float10)fsin((float10)(int)(((uVar7 + DAT_00536404 + DAT_004f6d60) - DAT_004ffdd0) *
                                         0x1e) * (float10)_DAT_004cc568);
    param_2 = (int)(longlong)(fVar10 * (float10)DAT_005359d0);
  }
  if (DAT_004da1f8 == 9) {
    iVar4 = 0x8c;
    lVar1 = 0x3ff00000;
    if (((param_1 < 0x1234) && (iVar3 < 0xce4)) && (-0x488 < iVar3)) {
      iVar4 = 0x78;
    }
    iVar5 = FUN_0047def0(-0x5a,-0x1838,-8000,0x2945,0x299,0x25d0,param_1,iVar3);
    if (iVar5 == 1) {
      lVar1 = 0x40000000;
    }
    local_8 = (double)(lVar1 << 0x20);
    if (((-700 < param_1) && (param_1 < 6000)) && ((iVar3 < 0x840 && (0x4b < iVar3)))) {
      local_8 = 2.0;
      iVar4 = 100;
    }
    iVar5 = FUN_0047def0(-0x17c0,0x50,-0x3ec,-700,0x4b,0x840,param_1,iVar3);
    if (iVar5 == 1) {
      iVar4 = 0x69;
      local_8 = _DAT_004cc708;
    }
  }
  if (DAT_004da1f8 == 0xb) {
    local_8 = 1.5;
    if (param_1 < 0) {
      local_8 = 0.8;
    }
    iVar4 = ((0x833 < iVar3) - 1 & 0xf) + 0x5a;
    if (iVar3 < 0) {
      iVar4 = 0x78;
    }
    if (iVar3 < -0x10cc) {
      iVar4 = 0x4b;
    }
    if (((0x1612 < param_1) && (param_1 < 0x2ac6)) && ((0x776 < iVar3 && (iVar3 < 0x98b)))) {
      local_8 = 4.0;
      iVar4 = 100;
    }
    iVar5 = FUN_0047def0(0x14c1,0x1152,0xde3,0x280a,0xfe6,0x129f,param_1,iVar3);
    if (iVar5 == 1) {
      iVar4 = 100;
      local_8 = _DAT_004cc710;
    }
  }
  if (DAT_004da1f8 != 100) goto LAB_00430dbd;
  bVar9 = -1 < param_2;
  local_8 = _DAT_004cc650;
  iVar4 = 0x50;
  if ((param_1 < -0x514) && (iVar3 < -0x708)) {
    iVar4 = 0xbe;
    local_8 = _DAT_004cc668;
    if (bVar9) {
      local_8 = _DAT_004cc680;
    }
  }
  if ((param_1 < -500) && (-0x709 < iVar3)) {
    iVar4 = 0x46;
    local_8 = _DAT_004cc650;
    if (bVar9) {
      local_8 = _DAT_004cc600;
    }
  }
  if (param_1 < 0x1130) {
    if (-0x709 < iVar3) {
      iVar4 = 0x46;
      local_8 = _DAT_004cc650;
      if (bVar9) {
        local_8 = _DAT_004cc600;
      }
    }
    if (0x112f < param_1) goto LAB_00430c5f;
  }
  else {
LAB_00430c5f:
    if (-0x709 < iVar3) {
      iVar4 = 0x50;
      local_8 = _DAT_004cc468;
      if (bVar9) {
        local_8 = _DAT_004cc940;
      }
    }
  }
  if ((!bVar9) &&
     (iVar5 = FUN_0047dfa0(-0xe42,0xfd2,0x4f6,-0xee,0x140a,0x802,param_1,iVar3), iVar5 == 1)) {
    iVar4 = 0x32;
  }
  if (((param_1 < 0x8ca) && (-0x9c4 < param_1)) && (0x14fa < iVar3)) {
    iVar4 = 0x78;
    local_8 = _DAT_004cc730;
    if (bVar9) {
      local_8 = _DAT_004cc948;
    }
    fVar10 = (float10)fsin((float10)(((DAT_00536404 + DAT_004f6d60) - DAT_004ffdd0) * 0x1e + -0x1e)
                           * (float10)_DAT_004cc568);
    param_2 = (int)(longlong)(fVar10 * (float10)DAT_005359d0);
  }
  if ((param_1 < -0x9c4) && (0x14fa < iVar3)) {
    iVar4 = 0x6e;
    local_8 = _DAT_004cc708;
    if (bVar9) {
      local_8 = _DAT_004cc548;
    }
    fVar10 = (float10)fsin((float10)(((DAT_00536404 + DAT_004f6d60) - DAT_004ffdd0) * 0x1e + -0x1e)
                           * (float10)_DAT_004cc568);
    param_2 = (int)(longlong)(fVar10 * (float10)DAT_005359d0);
  }
  if (((param_1 < 500) && (iVar3 < 0x578)) && (-0x578 < iVar3)) {
    local_8 = local_8 * _DAT_004cc668;
  }
LAB_00430dbd:
  dVar2 = _DAT_004cc650;
  if (DAT_004da1f8 == 0x65) {
    iVar4 = 0x46;
    local_8 = _DAT_004cc650;
    if (param_1 < -0x12c0) {
      local_8 = _DAT_004cc658;
    }
    if ((param_1 < -300) && (iVar3 < -500)) {
      local_8 = local_8 * _DAT_004cc668;
    }
  }
  if (DAT_004da1f8 == 0x68) {
    iVar4 = 0xb4;
    if ((0 < param_1) || (iVar3 < -0x708)) {
      iVar4 = 200;
    }
    local_8 = _DAT_004cc400;
    if ((iVar3 < 0) && (local_8 = _DAT_004cc950, param_1 < 0)) {
      local_8 = _DAT_004cc820;
    }
    if (-1 < param_2) {
      local_8 = local_8 * _DAT_004cc600;
    }
  }
  if (DAT_004da1f8 == 0x69) {
    iVar4 = 0xb4;
    if ((iVar3 < -0x8fc) || (local_8 = _DAT_004cc708, 0x578 < iVar3)) {
      local_8 = _DAT_004cc658;
    }
    if (iVar3 < -0x545) {
      iVar4 = 0xa0;
    }
    if (((iVar3 < -1000) && (-0x546 < iVar3)) && (param_1 < -0xabe)) {
      iVar4 = 0xb4;
    }
    if (-2000 < param_1) {
      iVar4 = 0xa0;
    }
    if ((param_1 < -0xabe) && (-1000 < iVar3)) {
      iVar4 = 200;
    }
    if (-0x4ec < param_1) {
      local_8 = local_8 * _DAT_004cc668;
    }
    if (600 < param_1) {
      local_8 = local_8 * _DAT_004cc668;
    }
    if (-600 < iVar3) {
      local_8 = local_8 * _DAT_004cc668;
    }
    if (((iVar3 < -600) && (-0x992 < param_1)) && (param_1 < -0x4eb)) {
      local_8 = local_8 * _DAT_004cc668;
    }
    if (-1 < param_2) {
      local_8 = local_8 * _DAT_004cc668;
    }
  }
  if ((DAT_004da1f8 == 0x6a) &&
     (((iVar4 = 300, local_8 = _DAT_004cc668, 0 < param_1 &&
       (local_8 = _DAT_004cc778, 1000 < param_1)) || (1000 < param_1)))) {
    local_8 = _DAT_004cc660;
  }
  if (DAT_004da1f8 == 0x66) {
    iVar4 = 300;
    fVar10 = (float10)fsin((float10)(((DAT_004f6d60 + DAT_00536404) - DAT_004ffdd0) * 0x1e) *
                           (float10)_DAT_004cc568);
    param_2 = (int)(longlong)(fVar10 * (float10)DAT_005359d0);
    if (param_1 < -1000) {
      iVar4 = 0x145;
    }
    local_8 = _DAT_004cc708;
    if ((200 < iVar3) && (param_2 < 0)) {
      iVar4 = 0x10e;
      local_8 = _DAT_004cc4f8;
    }
  }
  if (DAT_004da1f8 == 999) {
    iVar4 = (int)(longlong)(DAT_004fafb0 * _DAT_004cc3e8);
    if ((0x82 < DAT_004f4afc) && (6 < DAT_00522f08)) {
      if (DAT_004fafb0 < _DAT_004fafd8) {
        iVar4 = FUN_0041bc20((((int)(longlong)(DAT_004fafb0 * _DAT_004cc3e8) -
                              (int)(longlong)(_DAT_004fafd8 * _DAT_004cc910)) + -0xb4) / 2);
      }
      if (_DAT_004fafd8 < DAT_004fafb0) {
        iVar4 = FUN_0041bc20(-0xb4 - (int)(longlong)(DAT_004fafb0 * _DAT_004cc910));
        iVar4 = FUN_0041bc20((iVar4 - (int)(longlong)(_DAT_004fafd8 * _DAT_004cc910)) / 2 + 0xb4);
      }
    }
    local_8 = dVar2;
    if (DAT_004da26c != 1) {
      iVar4 = FUN_0041bc20(iVar4 + 0xb4);
    }
  }
  if (iVar6 < 0x32) {
    param_2 = (int)(longlong)((double)iVar6 * (double)param_2 * _DAT_004cc958);
  }
  if ((param_3 == 1) && (iVar6 < 0xb)) {
    DAT_00522fd8 = 0xffffffff;
  }
  uVar7 = (uint)(longlong)((double)param_2 * local_8);
  iVar5 = iVar4;
  if ((int)uVar7 < 0) {
    iVar5 = iVar4 + 0xb4;
  }
  DAT_00523a54 = iVar4;
  DAT_00536418 = FUN_0041bc20(iVar5);
  *(int *)(&DAT_00522d30 + param_3 * 4) = DAT_00536418;
  if ((iVar6 < 0x51) || (iVar6 = DAT_004da218, DAT_004da1f8 != 0)) {
    iVar6 = FUN_00488b90(0,param_1,iVar3,param_3);
  }
  if ((iVar6 < DAT_004da218) && (uVar7 = (int)(iVar6 * uVar7) / DAT_004da218, param_3 == 1)) {
    DAT_00522fd8 = 2;
  }
  if (iVar6 < DAT_004da218) {
    uVar7 = (int)(iVar6 * uVar7) / DAT_004da218;
  }
  uVar8 = (int)uVar7 >> 0x1f;
  if (0 < param_3) {
    *(uint *)(&DAT_00535a08 + param_3 * 4) = (uVar7 ^ uVar8) - uVar8;
  }
  return (uVar7 ^ uVar8) - uVar8;
}

