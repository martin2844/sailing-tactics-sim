
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00464a30(void)

{
  int iVar1;
  float10 fVar2;
  double dVar3;
  bool bVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  uint local_3c;
  undefined4 *local_30;
  undefined4 *local_2c;
  int aiStack_20 [5];
  uint local_c;
  
  uVar10 = 0x4b0;
  local_3c = 0x4b0;
  if ((DAT_004f69b8 == 5) || (DAT_004f69b8 == 6)) {
    uVar10 = 0x5dc;
    local_3c = 0x5dc;
  }
  if (DAT_004f69b8 == 5) {
    uVar10 = 0x5dc;
    local_3c = 0x5dc;
  }
  if (DAT_004f69b8 == 7) {
    uVar10 = 0x640;
    local_3c = 0x640;
  }
  if (DAT_0053527c == 1) {
    uVar10 = (uVar10 * 4) / 3;
    local_3c = uVar10;
  }
  if (DAT_005364c8 == 1) {
    uVar10 = (int)(uVar10 * 3) >> 2;
    local_3c = uVar10;
  }
  iVar7 = FUN_0041e000(100);
  DAT_00536300 = (iVar7 < 0x32) + 1;
  if (DAT_004f69b8 == 2) {
    iVar7 = FUN_0041e000(100);
    DAT_00536300 = (iVar7 < 0x21) + 1;
    iVar7 = FUN_0041e000(100);
    if (0x42 < iVar7) {
      DAT_00536300 = 3;
    }
  }
  if ((DAT_004f69b8 == 6) || (DAT_004f69b8 == 7)) {
    DAT_00536300 = 1;
  }
  if ((DAT_004f69b8 == 2) && (DAT_00536300 == 1)) {
    aiStack_20[1] = uVar10;
    DAT_004fe134 = 0;
    DAT_004f8b84 = 0x32;
    DAT_004fbac4 = 0x32;
    aiStack_20[2] = (uVar10 * 2) / 3;
    DAT_004fe138 = 0x46;
    DAT_004f8b88 = 0x82;
    DAT_004fbac8 = 200;
    DAT_005364b4 = DAT_004f69b8;
  }
  if (DAT_004f69b8 == 2) {
    if (DAT_00536300 == 2) {
      DAT_004fe134 = 0x8c;
      aiStack_20[1] = uVar10 / 2;
      DAT_004f8b84 = 0xb4;
      DAT_004fbac4 = 0x140;
      aiStack_20[2] = uVar10 / 2;
      DAT_004fe138 = 0x3c;
      DAT_004f8b88 = 0x78;
      DAT_004fbac8 = 0xb4;
      DAT_005364b4 = DAT_004f69b8;
    }
    if (DAT_00536300 == 3) {
      aiStack_20[1] = uVar10 / 2;
      DAT_004f8b84 = 0x32;
      DAT_004fbac4 = 0x32;
      DAT_004fe134 = 0;
      DAT_004fe138 = 0x3c;
      DAT_004f8b88 = 0x69;
      aiStack_20[2] = (uVar10 * 2) / 3;
      DAT_004fbac8 = 0xa4;
      DAT_005364b4 = DAT_004f69b8;
    }
  }
  if ((DAT_004f69b8 == 3) && (DAT_00536300 == 1)) {
    DAT_005364b4 = 5;
    DAT_004fe134 = 0;
    DAT_004f8b84 = 0x1e;
    aiStack_20[1] = uVar10 / 2;
    aiStack_20[2] = uVar10 / 3;
    DAT_004fbac4 = 0x1e;
    DAT_004fe138 = 0x46;
    DAT_004f8b88 = 0x6e;
    DAT_004fbac8 = 0xb4;
    aiStack_20[3] = aiStack_20[1];
    _DAT_004fe13c = 0x96;
    _DAT_004f8b8c = 0xb4;
    DAT_004fbacc = 0x14a;
    aiStack_20[4] = aiStack_20[1];
    _DAT_004fe140 = 0x82;
    _DAT_004f8b90 = 0x96;
    _DAT_004fbad0 = 0x118;
    local_c = uVar10;
    _DAT_004fe144 = 0x1e;
    _DAT_004f8b94 = 0x46;
    _DAT_004fbad4 = 100;
  }
  if ((DAT_004f69b8 == 3) && (DAT_00536300 == 2)) {
    DAT_005364b4 = 5;
    aiStack_20[1] = uVar10 / 2;
    DAT_004f8b84 = 0x1e;
    DAT_004fbac4 = 0x1e;
    DAT_004fe134 = 0;
    aiStack_20[2] = (uVar10 * 2) / 3;
    DAT_004fe138 = 0x28;
    DAT_004f8b88 = 0x50;
    aiStack_20[4] = uVar10 / 3;
    DAT_004fbac8 = 0x78;
    aiStack_20[3] = uVar10;
    _DAT_004fe13c = 0x50;
    _DAT_004f8b8c = 0x8c;
    DAT_004fbacc = 0xdc;
    _DAT_004fe140 = 0x96;
    _DAT_004f8b90 = 0xb4;
    _DAT_004fbad0 = 0x14a;
    local_c = uVar10;
    _DAT_004fe144 = 0x78;
    _DAT_004f8b94 = 0x8c;
    _DAT_004fbad4 = 0x104;
  }
  if (DAT_004f69b8 == 4) {
    if (DAT_00536300 == 1) {
      aiStack_20[1] = uVar10 * 2;
      DAT_005364b4 = 3;
      DAT_004fe134 = 0;
      DAT_004f8b84 = 0x28;
      DAT_004fbac4 = 0x28;
      aiStack_20[2] = aiStack_20[1];
      DAT_004fe138 = 0x32;
      DAT_004f8b88 = 0x78;
      DAT_004fbac8 = 0xaa;
      aiStack_20[3] = aiStack_20[1];
      _DAT_004fe13c = 0x8c;
      _DAT_004f8b8c = 0xaa;
      DAT_004fbacc = 0x136;
    }
    if (DAT_00536300 == 2) {
      aiStack_20[1] = uVar10 * 2;
      DAT_005364b4 = 3;
      DAT_004fe134 = 0x82;
      DAT_004f8b84 = 0xaa;
      DAT_004fbac4 = 300;
      aiStack_20[2] = aiStack_20[1];
      DAT_004fe138 = 10;
      DAT_004f8b88 = 0x46;
      DAT_004fbac8 = 0x50;
      aiStack_20[3] = aiStack_20[1];
      _DAT_004fe13c = 0x5a;
      _DAT_004f8b8c = 0x82;
      DAT_004fbacc = 0xdc;
    }
  }
  if (DAT_004f69b8 == 5) {
    DAT_005364b4 = 2;
    if (DAT_00536300 == 1) {
      aiStack_20[1] = uVar10 * 2;
      DAT_004fe134 = 0;
      DAT_004f8b84 = 0x5a;
      DAT_004fbac4 = 0x5a;
      aiStack_20[2] = (uVar10 * 3) / 2;
      DAT_004fe138 = 0x5a;
      DAT_004f8b88 = 0xaa;
      DAT_004fbac8 = 0x104;
    }
    else {
      DAT_004fe134 = 0;
      aiStack_20[1] = (uVar10 * 3) / 2;
      DAT_004f8b84 = 0x5a;
      DAT_004fbac4 = 0x5a;
      aiStack_20[2] = aiStack_20[1];
      DAT_004fe138 = 100;
      DAT_004f8b88 = 0xb4;
      DAT_004fbac8 = 0x118;
    }
  }
  if (DAT_004f69b8 == 5) {
    DAT_005364b4 = 2;
    if (DAT_00536300 == 1) {
      aiStack_20[1] = uVar10 * 2;
      DAT_004fe134 = 0;
      DAT_004f8b84 = 0x5a;
      DAT_004fbac4 = 0x5a;
      aiStack_20[2] = uVar10 * 2;
      DAT_004fe138 = 0x5a;
      DAT_004f8b88 = 0xaa;
      DAT_004fbac8 = 0x104;
    }
    else {
      DAT_004fe138 = 100;
      aiStack_20[1] = (uVar10 * 5) / 2;
      DAT_004fe134 = 0;
      DAT_004f8b84 = 0x5a;
      DAT_004fbac4 = 0x5a;
      aiStack_20[2] = aiStack_20[1];
      DAT_004f8b88 = 0xb4;
      DAT_004fbac8 = 0x118;
    }
  }
  iVar7 = 0;
  if (DAT_004f69b8 == 6) {
    aiStack_20[1] = uVar10 * 2;
    DAT_005364b4 = 3;
    DAT_004fe134 = 0x9b;
    DAT_004f8b84 = 0xf;
    DAT_004fbac4 = 0x15e;
    aiStack_20[2] = uVar10 * 4;
    DAT_004fe138 = 0x14;
    DAT_004f8b88 = 0x5a;
    DAT_004fbac8 = 0x6e;
    aiStack_20[3] = uVar10 * 3;
    _DAT_004fe13c = 0x5a;
    _DAT_004f8b8c = 0xa0;
    DAT_004fbacc = 0xfa;
  }
  if (DAT_004f69b8 == 7) {
    aiStack_20[1] = uVar10 * 2;
    DAT_004f8b88 = 0x46;
    DAT_004fbac8 = 0x46;
    DAT_005364b4 = 3;
    DAT_004fe134 = 0x4b;
    DAT_004f8b84 = 0x73;
    DAT_004fbac4 = 0;
    aiStack_20[2] = uVar10 * 4;
    DAT_004fe138 = 0;
    aiStack_20[3] = uVar10 * 3;
    _DAT_004fe13c = 0x73;
    _DAT_004f8b8c = 0xb4;
    DAT_004fbacc = 0x126;
  }
  dVar3 = (double)local_3c;
  iVar11 = 0;
  local_2c = &DAT_00512a80;
  local_30 = &DAT_005127a8;
  pdVar9 = (double *)&DAT_004ffdd8;
  do {
    iVar8 = DAT_004f69b8;
    *pdVar9 = dVar3;
    iVar12 = 1;
    if (0 < DAT_005364b4) {
      do {
        iVar6 = DAT_005364b4;
        iVar1 = *(int *)(iVar12 * 4 + 0x4fe130);
        bVar4 = true;
        local_3c = 1;
        if ((iVar11 < iVar1) || (*(int *)(iVar12 * 4 + 0x4f8b80) < iVar11)) {
          if (iVar8 != 6) {
            bVar4 = false;
            local_3c = 0;
            goto LAB_004651ce;
          }
LAB_004651d3:
          if (((iVar11 < iVar1) || (*(int *)(iVar12 * 4 + 0x4f8b80) < iVar11)) && (1 < iVar12)) {
            bVar4 = false;
            local_3c = 0;
          }
          if (iVar7 < -0x1e) {
            if (-0xb5 < iVar7) {
              if (iVar12 == 1) {
                bVar4 = false;
                local_3c = 0;
              }
              goto LAB_00465203;
            }
          }
          else {
LAB_00465203:
            if (-0xb5 < iVar7) goto LAB_0046521e;
          }
          if ((-0x136 < iVar7) && (iVar12 == 1)) {
            bVar4 = false;
            local_3c = 0;
          }
        }
        else {
LAB_004651ce:
          if (iVar8 == 6) goto LAB_004651d3;
        }
LAB_0046521e:
        if (bVar4) {
          local_3c = (uint)(longlong)
                           (((double)(iVar11 - iVar1) /
                            (double)(*(int *)(iVar12 * 4 + 0x4f8b80) - iVar1)) * _DAT_004cc478);
          if ((DAT_004f69b8 == 6) && (iVar12 == 1)) {
            if (iVar7 < -0x135) {
              local_3c = 0x5a - (int)(longlong)((double)(iVar7 + 0x168) * _DAT_004ccca8);
            }
            if (-0x1f < iVar7) {
              local_3c = 0x5a - (int)(longlong)((double)(iVar11 * 2) * _DAT_004cccb0);
            }
          }
          fVar13 = (float10)fsin((float10)(int)local_3c * (float10)_DAT_004cc568);
          local_3c = (uint)(longlong)
                           ((float10)aiStack_20[iVar12] * fVar13 * fVar13 * fVar13 * fVar13);
          iVar8 = DAT_004f69b8;
        }
        iVar12 = iVar12 + 1;
        *pdVar9 = (double)(int)local_3c + *pdVar9;
      } while (iVar12 <= iVar6);
    }
    iVar8 = FUN_0041e000(0xf);
    fVar13 = (float10)(iVar11 * 2) * (float10)_DAT_004cc568;
    dVar5 = (double)iVar8 + *pdVar9;
    fVar14 = (float10)fsin(fVar13);
    fVar15 = (float10)fcos(fVar13);
    *pdVar9 = dVar5;
    (&DAT_004fb6b8)[iVar11] = (int)(longlong)(fVar14 * (float10)dVar5);
    fVar13 = (float10)_DAT_004cc730;
    fVar2 = (float10)_DAT_004cc788;
    (&DAT_004fbc38)[iVar11] = (int)(longlong)-(fVar15 * (float10)dVar5);
    *local_30 = (int)(longlong)(fVar14 * (float10)dVar5 * fVar13);
    iVar7 = iVar7 + -2;
    iVar11 = iVar11 + 1;
    pdVar9 = pdVar9 + 1;
    *local_2c = (int)(longlong)(fVar15 * (float10)dVar5 * fVar2);
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    if (iVar7 < -0x166) {
      _DAT_00500378 = (undefined4)DAT_004ffdd8;
      _DAT_0050037c = DAT_004ffdd8._4_4_;
      _DAT_004fb988 = DAT_004fb6b8;
      _DAT_004fbf08 = DAT_004fbc38;
      iVar7 = 1;
      do {
        iVar11 = DAT_004f69b8;
        if (DAT_004f69b8 < 5) {
          if (iVar7 == 1) {
            local_2c = (undefined4 *)0x64;
          }
          if (iVar7 == 2) {
            local_2c = (undefined4 *)0x6c;
          }
          if (iVar7 == 3) {
            local_2c = (undefined4 *)0x7a;
          }
          if (iVar7 == 4) {
            local_2c = (undefined4 *)0x85;
          }
          if (iVar7 == 5) {
            local_2c = (undefined4 *)0x96;
          }
          if (iVar7 == 6) {
            local_2c = (undefined4 *)0x23;
          }
          if (iVar7 == 7) {
            local_2c = (undefined4 *)0x32;
          }
          if (iVar7 < 6) {
            *(int *)(iVar7 * 4 + 0x5116b8) = (&DAT_004fb6b8)[(int)local_2c] + -4000;
          }
          else {
            *(int *)(iVar7 * 4 + 0x5116b8) = (&DAT_004fb6b8)[(int)local_2c] + 4000;
          }
          *(undefined4 *)(iVar7 * 4 + 0x535ff8) = (&DAT_004fbc38)[(int)local_2c];
        }
        if (iVar11 == 5) {
          if (iVar7 == 1) {
            local_2c = (undefined4 *)0x9b;
          }
          if (iVar7 == 2) {
            local_2c = (undefined4 *)0xae;
          }
          if (iVar7 == 3) {
            local_2c = (undefined4 *)&DAT_00000005;
          }
          if (iVar7 == 4) {
            local_2c = (undefined4 *)0x12;
          }
          if (iVar7 == 5) {
            local_2c = (undefined4 *)0x1e;
          }
          if (iVar7 == 6) {
            local_2c = (undefined4 *)0x55;
          }
          if (iVar7 == 7) {
            local_2c = (undefined4 *)0x61;
          }
          *(undefined4 *)(iVar7 * 4 + 0x5116b8) = (&DAT_004fb6b8)[(int)local_2c];
          if (iVar7 < 6) {
            *(int *)(iVar7 * 4 + 0x535ff8) = (&DAT_004fbc38)[(int)local_2c] + -3000;
          }
          else {
            *(int *)(iVar7 * 4 + 0x535ff8) = (&DAT_004fbc38)[(int)local_2c] + 3000;
          }
        }
        if (iVar11 == 6) {
          if (iVar7 == 1) {
            local_2c = (undefined4 *)0x87;
          }
          if (iVar7 == 2) {
            local_2c = (undefined4 *)0x91;
          }
          if (iVar7 == 3) {
            local_2c = (undefined4 *)0x98;
          }
          if (iVar7 == 4) {
            local_2c = (undefined4 *)0x14;
          }
          if (iVar7 == 5) {
            local_2c = (undefined4 *)0x19;
          }
          if (iVar7 == 6) {
            local_2c = (undefined4 *)0x21;
          }
          if (iVar7 == 7) {
            local_2c = (undefined4 *)0x28;
          }
          iVar8 = (&DAT_004fbc38)[(int)local_2c];
          *(undefined4 *)(iVar7 * 4 + 0x5116b8) = (&DAT_004fb6b8)[(int)local_2c];
          *(int *)(iVar7 * 4 + 0x535ff8) = iVar8 + -3000;
        }
        if (iVar11 == 7) {
          if (iVar7 == 1) {
            local_2c = (undefined4 *)0x2b;
          }
          if (iVar7 == 2) {
            local_2c = (undefined4 *)0x34;
          }
          if (iVar7 == 3) {
            local_2c = (undefined4 *)0x3c;
          }
          if (iVar7 == 4) {
            local_2c = (undefined4 *)0x46;
          }
          if (iVar7 == 5) {
            local_2c = (undefined4 *)0x78;
          }
          if (iVar7 == 6) {
            local_2c = (undefined4 *)0x82;
          }
          if (iVar7 == 7) {
            local_2c = (undefined4 *)0x87;
          }
          iVar11 = (&DAT_004fbc38)[(int)local_2c];
          *(undefined4 *)(iVar7 * 4 + 0x5116b8) = (&DAT_004fb6b8)[(int)local_2c];
          *(int *)(iVar7 * 4 + 0x535ff8) = iVar11 + 3000;
        }
        iVar11 = FUN_0041e000(0x3c);
        *(int *)(iVar7 * 4 + 0x523080) = iVar11 + 0x32;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8);
      _DAT_00534ea0 = (&DAT_004fbcd8)[DAT_00536300 * 5];
      _DAT_005229cc = (&DAT_004fb758)[DAT_00536300 * 5] + 2000;
      if (DAT_004f69b8 == 5) {
        _DAT_00534ea0 = DAT_004fbea4 + -1000;
        _DAT_005229cc = DAT_004fb924;
      }
      if (DAT_004f69b8 < 6) {
        if (DAT_00536300 == 1) {
          _DAT_00522e5c = DAT_004fb6bc;
          _DAT_00522e60 = DAT_004fb6c0;
          _DAT_00535278 = DAT_004fbc3c + -2000;
          _DAT_00535ecc = DAT_004fbd3c + 2000;
          _DAT_0052338c = DAT_004fb7bc + 3000;
          _DAT_00523594 = DAT_004fb85c + -2000;
          _DAT_00536398 = DAT_004fbddc + 1000;
          _DAT_00535554 = _DAT_00535278;
        }
        else {
          _DAT_00522e5c = DAT_004fb824;
          _DAT_00535278 = DAT_004fbda4 + 2000;
          _DAT_00522e60 = DAT_004fb828;
          _DAT_00535ecc = DAT_004fbc44 + -3000;
          _DAT_0052338c = DAT_004fb6c4;
          _DAT_00523594 = DAT_004fb85c + -2000;
          _DAT_00536398 = DAT_004fbddc + 1000;
          _DAT_00535554 = _DAT_00535278;
        }
      }
      if (DAT_004f69b8 == 5) {
        DAT_004f4690 = DAT_004fb760 + 1000;
        DAT_004fb418 = DAT_004fbce0;
        DAT_004fb4ac = DAT_004fbcec;
        DAT_004f4698 = DAT_004fb76c + 1000;
        _DAT_004fe810 = DAT_004fbe68 + -1000;
        _DAT_004fe29c = DAT_004fb8e8 + -2000;
      }
      if ((DAT_004f69b8 == 4) && (DAT_00536300 == 1)) {
        DAT_004f4690 = DAT_004fb7f4;
        DAT_004fb418 = DAT_004fbd74 + 3000;
        DAT_004f4698 = DAT_004fb800;
        DAT_004fb4ac = DAT_004fbd80 + 3000;
        _DAT_004fe29c = DAT_004fb8e8 + -2000;
        _DAT_004fe810 = DAT_004fbe68 + -1000;
      }
      if ((DAT_004f69b8 == 4) && (DAT_00536300 == 2)) {
        DAT_004f4690 = DAT_004fb740 + 3000;
        DAT_004fb418 = DAT_004fbcc0;
        DAT_004f4698 = DAT_004fb750 + 3000;
        DAT_004fb4ac = DAT_004fbcd0;
        _DAT_004fe29c = DAT_004fb898 + -2000;
        _DAT_004fe810 = DAT_004fbe18 + -2000;
        _DAT_00523594 = DAT_004fb870 + -2000;
        _DAT_00536398 = DAT_004fbdf0 + 1000;
        _DAT_00534ea0 = DAT_004fbd28 + 2000;
        _DAT_005229cc = DAT_004fb7a8 + 2000;
      }
      if (DAT_004f69b8 == 6) {
        _DAT_0052338c = DAT_004fb8e8;
        _DAT_00534ea0 = DAT_004fbcd8 + -1000;
        _DAT_00522e5c = DAT_004fb6d0;
        _DAT_00522e60 = DAT_004fb6d4;
        _DAT_005229cc = DAT_004fb758;
        _DAT_00535278 = DAT_004fbc50 + -2000;
        _DAT_004fe29c = DAT_004fb938;
        _DAT_004fe810 = DAT_004fbeb8 + -1000;
        _DAT_00535ecc = DAT_004fbe68 + -1000;
        _DAT_00535554 = DAT_004fbc54 + -2000;
      }
      if (DAT_004f69b8 == 7) {
        _DAT_005229cc = DAT_004fb7a8;
        _DAT_00534ea0 = DAT_004fbd28 + 1000;
        _DAT_004fe810 = DAT_004fbd64 + 1000;
        _DAT_0052338c = DAT_004fb898;
        _DAT_00522e5c = DAT_004fb834;
        _DAT_004fe29c = DAT_004fb7e4;
        _DAT_00535ecc = DAT_004fbe18 + 1000;
        _DAT_00535278 = DAT_004fbdb4 + 2000;
        _DAT_00535554 = DAT_004fbdbc + 2000;
        _DAT_00522e60 = DAT_004fb83c;
      }
      return;
    }
  } while( true );
}

