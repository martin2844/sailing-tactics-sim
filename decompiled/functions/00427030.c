
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427030(int param_1,int param_2)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  bool bVar12;
  longlong lVar13;
  int local_18;
  int local_14;
  uint local_c;
  int local_4;
  
  local_c = 0;
  if (DAT_004ac9ac == 1) {
    _DAT_004a7f38 = 0;
    _DAT_004a7f3c = 0x40590000;
    _DAT_004a4520 = 0;
    _DAT_004a4524 = 0x40590000;
  }
  iVar7 = *(int *)(&DAT_004ac018 + param_2 * 4);
  DAT_004ac9b8 = 0;
  puVar11 = &DAT_004a4bf0;
  for (iVar3 = 0x28; iVar8 = DAT_0049118c, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  uVar5 = param_1 - iVar7 >> 0x1f;
  iVar7 = (param_1 - iVar7 ^ uVar5) - uVar5;
  if (0xb4 < iVar7) {
    iVar7 = 0x168 - iVar7;
  }
  *(int *)(&DAT_004aba68 + param_2 * 4) = iVar7;
  if (iVar8 == 2) {
    local_4 = FUN_0041bb10(DAT_004a488c - (int)(longlong)_DAT_004a49f0,
                           (int)(longlong)_DAT_004a4ae8 - DAT_004a6f4c);
    if (DAT_004a7bcc < 0x5a) {
      lVar13 = FUN_0044da90(2,1);
      local_14 = (int)lVar13;
    }
    else {
      local_14 = 200;
    }
    iVar8 = DAT_0049118c;
    if (((DAT_004a6014 < 1) || (local_c = 1, DAT_004aa738 != 1)) || (DAT_0049118c != 2)) {
      local_c = 0;
    }
  }
  if (((double)(int)(((DAT_004a4958 < 2) - 1 & 0xffffffe7) + 0x28) <
       *(double *)(&DAT_004a7f28 + param_2 * 8)) || (DAT_004ac9ac == 1)) {
    if (*(int *)(&DAT_004a7868 + param_2 * 4) == 0xc) {
      DAT_004a4bf0 = 8;
      return;
    }
    if (0x2d < iVar7) {
      if (((*(int *)(&DAT_004a5268 + param_2 * 4) < 0xc9) &&
          (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) && (DAT_004ac9a8 == 1)) {
        DAT_004a4bf0 = 9;
        return;
      }
      if ((((0x2d < iVar7) && (*(int *)(&DAT_004a5268 + param_2 * 4) < 0xc9)) &&
          (*(int *)(&DAT_004aa730 + param_2 * 4) == -1)) && (DAT_004ac9a8 == 0)) {
        DAT_004a4bf0 = 9;
        return;
      }
    }
    if ((2 < iVar8) && (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_2 * 4) + 0x25)) {
      DAT_004a4bf0 = 1;
      return;
    }
    if (iVar8 == 2) {
      if ((DAT_004a5b80 < DAT_004911b8 + *(int *)(&DAT_004a41f0 + param_2 * 4)) &&
         (0 < DAT_004a5b80)) {
        DAT_004a4bf0 = 1;
        return;
      }
      if ((DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_2 * 4) + 4) && (DAT_004a5b80 < 1)) {
        DAT_004a4bf0 = 1;
        return;
      }
      if (DAT_004a5b80 < DAT_00491168) {
        DAT_004a4bf0 = 2;
        return;
      }
      if (local_c != 0) {
        DAT_004a4bf0 = 7;
        return;
      }
    }
    if (*(int *)(&DAT_004a76d0 + param_2 * 4) == 1) {
      DAT_004a4bf0 = 3;
      return;
    }
    if ((0 < *(int *)(&DAT_004a6010 + param_2 * 4)) && (200 < *(int *)(&DAT_004a5268 + param_2 * 4))
       ) {
      DAT_004a4bf0 = 4;
      if (local_14 < 1) {
        DAT_004a4bf0 = 4;
        return;
      }
      if (iVar8 != 2) {
        DAT_004a4bf0 = 4;
        return;
      }
      DAT_004ac9b8 = 1;
      return;
    }
  }
  if (((iVar7 < 0x1a) && (*(int *)(&DAT_004aa730 + param_2 * 4) == -1)) && (2 < iVar8)) {
    DAT_004a4bf0 = 5;
    return;
  }
  if (((iVar7 < 0xb) && (*(int *)(&DAT_004aa730 + param_2 * 4) == -1)) && (iVar8 == 2)) {
    DAT_004a4bf0 = 5;
    return;
  }
  if ((iVar7 < 4) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) {
    DAT_004a4bf0 = 6;
    return;
  }
  iVar3 = 0;
  local_18 = 0;
  if (iVar7 < 10) {
    iVar3 = -200;
    local_18 = -200;
    DAT_004a4bf4 = 0xffffff38;
  }
  iVar8 = iVar3;
  if (((0x37 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) && (local_c == 0)) {
    local_18 = iVar3 + (iVar7 + -0x37) * 0x14;
    DAT_004a4bf8 = local_18 - iVar3;
    iVar8 = local_18;
  }
  if (((0x37 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) &&
     ((*(int *)(&DAT_004a5268 + param_2 * 4) < 300 && (local_c == 0)))) {
    iVar8 = iVar8 + 1000;
    DAT_004a4bf8 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if (((0x41 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) && (local_c == 0)) {
    iVar8 = iVar8 + (iVar7 + -0x37) * 0x28;
    DAT_004a4bf8 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if ((0x2d < iVar7) && (DAT_00491194 == 8)) {
    iVar8 = iVar8 + (iVar7 + -0x2d) * 0x50;
    DAT_004a4bf8 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if ((((0x37 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) &&
      (*(int *)(&DAT_004a5420 + param_2 * 4) == 1)) && (local_c == 0)) {
    iVar8 = iVar8 + (iVar7 + -0x37) * 0x28;
    DAT_004a4bf8 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if (((0x46 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) && (local_c == 0)) {
    iVar8 = iVar8 + 4000;
    DAT_004a4bf8 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if (((DAT_004a4eb0 * 9) / 5 < iVar7) && (*(int *)(&DAT_004aa730 + param_2 * 4) == -1)) {
    iVar8 = iVar8 + 600;
    DAT_004a4c64 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  bVar12 = iVar7 + -0x41 < 0;
  iVar3 = iVar8;
  if (0x41 < iVar7) {
    if (((*(int *)(&DAT_004aa730 + param_2 * 4) == 1) &&
        (200 < *(int *)(&DAT_004a5268 + param_2 * 4))) && (local_c == 0)) {
      iVar3 = (0x41 - iVar7) * 3 + iVar8;
      DAT_004a4bfc = iVar3 - iVar8;
      local_18 = iVar3;
    }
    bVar12 = iVar7 + -0x41 < 0;
    if (0x41 < iVar7) {
      if ((*(int *)(&DAT_004aa730 + param_2 * 4) == -1) &&
         (400 < *(int *)(&DAT_004a5268 + param_2 * 4))) {
        iVar3 = iVar3 + (iVar7 + -0x41) * (DAT_004ac9a8 * 0x12 + 3);
        DAT_004a4bfc = iVar3 - iVar8;
        local_18 = iVar3;
      }
      bVar12 = iVar7 + -0x41 < 0;
    }
  }
  if ((SBORROW4(iVar7,0x41) != bVar12) || (*(int *)(&DAT_004a5268 + param_2 * 4) < 0xc9)) {
    DAT_004a4bfc = 0;
  }
  if ((iVar7 < 0x42) && (200 < *(int *)(&DAT_004a5268 + param_2 * 4))) {
    local_c = FUN_00413cb0(*(int *)(&DAT_004aa5b0 + param_2 * 4) - DAT_004a4f8c);
    if (0xb4 < (int)local_c) {
      local_c = local_c - 0x168;
    }
    iVar8 = local_c * *(int *)(&DAT_004aa730 + param_2 * 4);
    uVar5 = (int)local_c >> 0x1f;
    if (iVar8 < 0) {
      local_18 = iVar3 + ((local_c ^ uVar5) - uVar5);
      DAT_004a4c00 = local_18 - iVar3;
      iVar3 = local_18;
      if ((iVar8 < 0) && (9 < DAT_00491190)) {
        iVar3 = local_18 + ((local_c ^ uVar5) - uVar5) * 6;
        DAT_004a4c00 = iVar3 - local_18;
        local_18 = iVar3;
      }
    }
    iVar9 = iVar3;
    if ((0 < iVar8) && (9 < DAT_00491190)) {
      iVar9 = iVar3 + ((local_c ^ uVar5) - uVar5) * -6;
      DAT_004a4c04 = iVar9 - iVar3;
      local_18 = iVar9;
    }
    if ((DAT_004ac9ac == 0) || (DAT_004ac9b0 == 1)) {
      iVar3 = iVar9;
      if (((*(double *)(&DAT_004a7f28 + param_2 * 8) < *(double *)(&DAT_004a4510 + param_2 * 8)) &&
          (((*(int *)(&DAT_004a6338 + param_2 * 4) < DAT_004aa390 && (7 < DAT_00491190)) &&
           (0x96 < *(int *)(&DAT_004a5268 + param_2 * 4))))) &&
         ((DAT_004a4ee8 == 1 && (0xf < iVar7)))) {
        iVar3 = iVar9 + 100;
        DAT_004a4c08 = iVar3 - iVar9;
        local_18 = iVar3;
      }
      iVar9 = iVar3;
      if (((*(double *)(&DAT_004a4510 + param_2 * 8) < *(double *)(&DAT_004a7f28 + param_2 * 8)) &&
          (*(int *)(&DAT_004a6338 + param_2 * 4) < DAT_004aa390)) &&
         ((7 < DAT_00491190 &&
          (((0x96 < *(int *)(&DAT_004a5268 + param_2 * 4) && (DAT_004a4ee8 == 1)) && (0xf < iVar7)))
          ))) {
        iVar9 = iVar3 + -100;
        DAT_004a4c0c = iVar9 - iVar3;
        local_18 = iVar9;
      }
    }
    if ((DAT_004ac9ac == 0) || (DAT_004ac9b0 == 1)) {
      iVar3 = *(int *)(&DAT_004a6e48 + param_2 * 4);
      iVar8 = *(int *)(&DAT_004a7060 + param_2 * 4);
      uVar5 = iVar3 - iVar8 >> 0x1f;
      iVar4 = (iVar3 - iVar8 ^ uVar5) - uVar5;
      uVar5 = (int)DAT_004aa298 >> 0x1f;
      if (iVar3 < iVar8) {
        iVar2 = *(int *)(&DAT_004a4778 + param_2 * 4);
        iVar10 = iVar9;
        if (iVar2 < *(int *)(&DAT_004ac208 + param_2 * 4)) {
          if (((8 < DAT_00491190) && (3 < iVar4)) && (500 < *(int *)(&DAT_004a5268 + param_2 * 4)))
          {
            iVar10 = iVar9 + iVar4 * 0x14;
            DAT_004a4c24 = iVar10 - iVar9;
            local_18 = iVar10;
          }
          iVar2 = *(int *)(&DAT_004a4778 + param_2 * 4);
        }
        iVar9 = iVar10;
        if ((((*(int *)(&DAT_004ac208 + param_2 * 4) < iVar2) && (8 < DAT_00491190)) &&
            (iVar2 = (DAT_004aa298 ^ uVar5) - uVar5, 3 < iVar2)) &&
           (500 < *(int *)(&DAT_004a5268 + param_2 * 4))) {
          iVar9 = iVar10 + iVar2 * -10;
          DAT_004a4c28 = iVar9 - iVar10;
          local_18 = iVar9;
        }
      }
      if (iVar8 < iVar3) {
        iVar3 = iVar9;
        if (((*(int *)(&DAT_004ac208 + param_2 * 4) < *(int *)(&DAT_004a4778 + param_2 * 4)) &&
            (8 < DAT_00491190)) && ((3 < iVar4 && (500 < *(int *)(&DAT_004a5268 + param_2 * 4))))) {
          iVar3 = iVar9 + iVar4 * 10;
          DAT_004a4c2c = iVar3 - iVar9;
          local_18 = iVar3;
        }
        iVar9 = iVar3;
        if (((*(int *)(&DAT_004a4778 + param_2 * 4) < *(int *)(&DAT_004ac208 + param_2 * 4)) &&
            (8 < DAT_00491190)) &&
           ((iVar8 = (DAT_004aa298 ^ uVar5) - uVar5, 3 < iVar8 &&
            (500 < *(int *)(&DAT_004a5268 + param_2 * 4))))) {
          iVar9 = iVar3 + iVar8 * -10;
          DAT_004a4c30 = iVar9 - iVar3;
          local_18 = iVar9;
        }
      }
    }
    uVar5 = (int)DAT_004abc7c >> 0x1f;
    iVar3 = iVar9;
    if ((((0 < (int)(DAT_004abc7c * *(int *)(&DAT_004aa730 + param_2 * 4))) && (7 < DAT_00491190))
        && (300 < *(int *)(&DAT_004a5268 + param_2 * 4))) && (iVar7 < 0x46)) {
      iVar8 = (DAT_004abc7c ^ uVar5) - uVar5;
      iVar3 = iVar8 * 5 + iVar9;
      if (DAT_004a5a48 == 1) {
        iVar3 = iVar3 + iVar8 * 10;
      }
      DAT_004a4c20 = iVar3 - iVar9;
      local_18 = iVar3;
    }
    iVar8 = iVar3;
    if ((((int)(DAT_004abc7c * *(int *)(&DAT_004aa730 + param_2 * 4)) < 0) && (7 < DAT_00491190)) &&
       ((300 < *(int *)(&DAT_004a5268 + param_2 * 4) && (iVar7 < 0x46)))) {
      iVar9 = (DAT_004abc7c ^ uVar5) - uVar5;
      iVar8 = iVar3 + iVar9 * -5;
      if (DAT_004a5a48 == 1) {
        iVar8 = iVar8 + iVar9 * -10;
      }
      DAT_004a4c20 = iVar8 - iVar3;
      local_18 = iVar8;
    }
    iVar3 = iVar8;
    if (DAT_004a5b80 < *(int *)(&DAT_004a41f0 + param_2 * 4) + DAT_004911bc) {
      if ((5 < DAT_00491188) || (DAT_004ac904 == 1)) {
        iVar3 = iVar8 + -0x28;
        local_18 = iVar3;
      }
      DAT_004a4c34 = iVar3 - iVar8;
    }
    if (DAT_00491190 < 8) {
      iVar8 = FUN_00415a20(0x32);
      iVar3 = iVar3 + iVar8;
      local_18 = iVar3;
    }
  }
  iVar8 = iVar3;
  if ((*(int *)(&DAT_004a40d0 + param_2 * 4) == 1) && (5 < DAT_00491190)) {
    iVar8 = iVar3 + 500;
    DAT_004a4c38 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  if ((3 < DAT_00491190) && (2 < DAT_0049118c)) {
    if ((*(int *)(&DAT_004a7868 + param_2 * 4) == 2) || (*(int *)(&DAT_004a7868 + param_2 * 4) == 3)
       ) {
      iVar8 = iVar8 + 500;
      local_18 = iVar8;
    }
    DAT_004a4c38 = iVar8 - iVar3;
  }
  dVar1 = (double)(int)(((DAT_004a4958 < 2) - 1 & 0xffffffe2) + 0x32);
  if (((*(double *)(&DAT_004a7f28 + param_2 * 8) < dVar1) && (DAT_004ac9ac == 0)) &&
     (DAT_004a5a4c == 0)) {
    if (*(double *)(&DAT_004a7f28 + param_2 * 8) < *(double *)(&DAT_004a4510 + param_2 * 8)) {
      iVar8 = 5000;
      local_18 = 5000;
    }
    if (*(double *)(&DAT_004a4510 + param_2 * 8) < *(double *)(&DAT_004a7f28 + param_2 * 8)) {
      iVar8 = iVar8 + -500;
      local_18 = iVar8;
    }
  }
  if (((*(double *)(&DAT_004a7f28 + param_2 * 8) < dVar1) && (DAT_004ac9ac == 0)) &&
     (DAT_004a5a4c == 1)) {
    if (*(int *)(&DAT_004aa730 + param_2 * 4) == 1) {
      iVar8 = iVar8 + 500;
      local_18 = iVar8;
    }
    else {
      iVar8 = iVar8 + -500;
      local_18 = iVar8;
    }
  }
  if ((DAT_0049118c != 2) || (param_2 != 2)) goto LAB_00427ead;
  if ((DAT_004a7870 == 2) || (iVar3 = iVar8, DAT_004a7870 == 3)) {
    iVar3 = iVar8 + 5000;
    DAT_004a4c38 = iVar3 - iVar8;
    local_18 = iVar3;
  }
  iVar8 = iVar3;
  if ((local_14 < 0) && (DAT_004a71a4 == 1)) {
    uVar5 = (int)local_c >> 0x1f;
    if (((int)(local_c * DAT_004aa738) < 0) && (9 < DAT_00491190)) {
      iVar8 = iVar3 + ((local_c ^ uVar5) - uVar5) * 2;
      DAT_004a4c3c = iVar8 - iVar3;
      local_18 = iVar8;
    }
    if ((10 < (int)(local_c * DAT_004aa738)) && (9 < DAT_00491190)) {
      iVar8 = iVar8 + ((local_c ^ uVar5) - uVar5) * -2;
      DAT_004a4c3c = iVar8 - iVar3;
      local_18 = iVar8;
    }
    iVar3 = iVar8 - iVar3;
    if (0 < iVar3) {
      _DAT_004a4c40 = iVar3;
    }
    if (iVar3 < 0) {
      _DAT_004a4c44 = iVar3;
    }
  }
  iVar3 = iVar8;
  if (((((200 < DAT_004a5270) && (DAT_004aa734 != DAT_004aa738)) && (iVar7 < 0x4b)) &&
      ((iVar8 < 200 && (0 < local_14)))) && ((DAT_004a786c == 0xc || (DAT_004aa830 == 0xc)))) {
    iVar3 = iVar8 + 20000;
    DAT_004a4c50 = iVar3 - iVar8;
    local_18 = iVar3;
  }
  iVar8 = iVar3;
  if (((200 < DAT_004a5270) && (DAT_004aa734 == DAT_004aa738)) &&
     ((iVar7 < 0x4b && (DAT_004a786c == 2)))) {
    iVar8 = iVar3 + -500;
    DAT_004a4c54 = iVar8 - iVar3;
    local_18 = iVar8;
  }
  uVar5 = FUN_00415dc0(param_1 - local_4);
  if (DAT_004a4c50 + DAT_004a4c54 == 0) {
    uVar6 = (int)uVar5 >> 0x1f;
    if (((10 < local_14) && (200 < DAT_004a5270)) && (DAT_004aa734 != DAT_004aa738)) {
      if ((int)((uVar5 ^ uVar6) - uVar6) < 4) {
        local_18 = iVar8 + 300;
      }
      else {
        iVar7 = iVar8;
        if (((DAT_004aa734 == 1) && (3 < (int)uVar5)) && (((int)uVar5 < 0x5a && (0xf < local_14))))
        {
          iVar7 = iVar8 + -0x7d;
          DAT_004a4c4c = iVar7 - iVar8;
          local_18 = iVar7;
        }
        iVar8 = iVar7;
        if (DAT_004aa734 == -1) {
          iVar3 = iVar7;
          if ((3 < (int)uVar5) && ((int)uVar5 < 0x5a)) {
            iVar3 = iVar7 + 0x7d;
            DAT_004a4c48 = iVar3 - iVar7;
            local_18 = iVar3;
          }
          iVar8 = iVar3;
          if (((int)uVar5 < -3) && (-0x5a < (int)uVar5)) {
            iVar8 = iVar3 + -0x7d;
            DAT_004a4c4c = iVar8 - iVar3;
            local_18 = iVar8;
          }
        }
        if (((DAT_004aa734 != 1) || (-4 < (int)uVar5)) || ((int)uVar5 < -0x59)) goto LAB_00427ce1;
        local_18 = iVar8 + 0x7d;
      }
      DAT_004a4c48 = local_18 - iVar8;
      iVar8 = local_18;
    }
LAB_00427ce1:
    if (((7 < local_14) && (200 < DAT_004a5270)) && (DAT_004aa734 == DAT_004aa738)) {
      if ((int)((uVar5 ^ uVar6) - uVar6) < 4) {
        local_18 = iVar8 + -300;
        DAT_004a4c58 = local_18 - iVar8;
        iVar8 = local_18;
      }
      else {
        iVar7 = iVar8;
        if (((DAT_004aa734 == 1) && (3 < (int)uVar5)) && (((int)uVar5 < 0x5a && (0x14 < local_14))))
        {
          iVar7 = iVar8 + 0x7d;
          DAT_004a4c5c = iVar7 - iVar8;
          local_18 = iVar7;
        }
        iVar8 = iVar7;
        if ((((DAT_004aa734 == -1) && ((int)uVar5 < -3)) && (-0x5a < (int)uVar5)) &&
           (0xf < local_14)) {
          iVar8 = iVar7 + 0x7d;
          DAT_004a4c5c = iVar8 - iVar7;
          local_18 = iVar8;
        }
      }
    }
  }
  uVar5 = FUN_00415dc0(param_1 - local_4);
  DAT_004a4c68 = 0;
  if (((local_14 < 0x15) && (300 < DAT_004a5270)) &&
     ((2 < (int)uVar5 && (((int)uVar5 < 0x5a && (DAT_004aa734 == 1)))))) {
    iVar7 = iVar8;
    if (DAT_004aa738 == 1) {
      iVar7 = iVar8 + -0x7d;
      DAT_004a4c68 = iVar7 - iVar8;
      local_18 = iVar7;
    }
    iVar8 = iVar7;
    if (DAT_004aa738 != -1) goto LAB_00427df4;
    if (local_14 < 0x10) {
      iVar8 = iVar7 + 0x7d;
      DAT_004a4c68 = iVar8 - iVar7;
      local_18 = iVar8;
      goto LAB_00427df4;
    }
  }
  else {
LAB_00427df4:
    iVar7 = iVar8;
    if ((((local_14 < 0x10) && (300 < DAT_004a5270)) && ((int)uVar5 < -2)) &&
       ((-0x5a < (int)uVar5 && (DAT_004aa734 == -1)))) {
      iVar3 = iVar8;
      if (DAT_004aa738 == -1) {
        iVar3 = iVar8 + -0x7d;
        DAT_004a4c68 = iVar3 - iVar8;
        local_18 = iVar3;
      }
      iVar7 = iVar3;
      if (DAT_004aa738 == 1) {
        iVar7 = iVar3 + 0x7d;
        DAT_004a4c68 = iVar7 - iVar3;
        local_18 = iVar7;
      }
    }
  }
  iVar8 = iVar7;
  if (local_14 < -0x14) {
    uVar6 = (int)uVar5 >> 0x1f;
    if (((200 < DAT_004a5270) && (DAT_004aa734 == DAT_004aa738)) &&
       ((int)((uVar5 ^ uVar6) - uVar6) < 3)) {
      iVar8 = iVar7 + 0x46;
      DAT_004a4c60 = iVar8 - iVar7;
      local_18 = iVar8;
    }
    if ((((local_14 < -0x14) && (200 < DAT_004a5270)) && (DAT_004aa734 != DAT_004aa738)) &&
       ((int)((uVar5 ^ uVar6) - uVar6) < 3)) {
      iVar8 = iVar8 + -0x46;
      DAT_004a4c60 = iVar8 - iVar7;
      local_18 = iVar8;
    }
  }
LAB_00427ead:
  if (((DAT_004ac900 == 0) && (DAT_004ac904 == 0)) && (DAT_004ac90c == 0)) {
    DAT_004911b0 = (int)(DAT_004911b0 << 2) / 5;
  }
  if ((0 < DAT_004a5b80) && (DAT_00491194 == 8)) {
    DAT_004911b0 = DAT_004911b0 << 2;
  }
  dVar1 = _DAT_004aa948 * _DAT_00485160 * (double)local_18 * _DAT_00484d48;
  DAT_004a4c8c = iVar8;
  iVar3 = FUN_00415a20(DAT_004911b0);
  iVar7 = DAT_004a5b80;
  if (iVar3 < (int)(longlong)dVar1) {
    *(int *)(&DAT_004a41f0 + param_2 * 4) = DAT_004a5b80;
    dVar1 = *(double *)(&DAT_004a71c8 + param_2 * 8);
    *(undefined4 *)(&DAT_004aa660 + param_2 * 4) = *(undefined4 *)(&DAT_004aa730 + param_2 * 4);
    dVar1 = dVar1 * _DAT_00484ec8;
    *(undefined4 *)(&DAT_004a4778 + param_2 * 4) = *(undefined4 *)(&DAT_004ac208 + param_2 * 4);
    *(undefined4 *)(&DAT_004a4510 + param_2 * 8) = *(undefined4 *)(&DAT_004a7f28 + param_2 * 8);
    *(undefined4 *)(&DAT_004a4514 + param_2 * 8) = *(undefined4 *)(&DAT_004a7f2c + param_2 * 8);
    iVar3 = DAT_004ac9ac;
    *(double *)(&DAT_004a71c8 + param_2 * 8) = dVar1;
    *(undefined4 *)(&DAT_004a6ec8 + param_2 * 4) = 0;
    if ((iVar3 == 1) && (param_2 == 2)) {
      DAT_00491198 = 0xffffffff;
      DAT_0049119c = iVar7;
    }
  }
  return;
}

