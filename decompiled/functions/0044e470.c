
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044e470(void)

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
  int local_3c;
  undefined4 *local_30;
  undefined4 *local_2c;
  int aiStack_20 [5];
  uint local_c;
  
  uVar10 = 0x4b0;
  local_3c = 0x4b0;
  if ((DAT_004a4958 == 5) || (DAT_004a4958 == 6)) {
    uVar10 = 0x5dc;
    local_3c = 0x5dc;
  }
  if (DAT_004a4958 == 5) {
    uVar10 = 0x514;
    local_3c = 0x514;
  }
  if (DAT_004a4958 == 7) {
    uVar10 = 0x640;
    local_3c = 0x640;
  }
  iVar7 = FUN_00415a20(100);
  DAT_004ac85c = (iVar7 < 0x32) + 1;
  if (DAT_004a4958 == 2) {
    iVar7 = FUN_00415a20(100);
    DAT_004ac85c = (iVar7 < 0x21) + 1;
    iVar7 = FUN_00415a20(100);
    if (0x42 < iVar7) {
      DAT_004ac85c = 3;
    }
  }
  if ((DAT_004a4958 == 6) || (DAT_004a4958 == 7)) {
    DAT_004ac85c = 1;
  }
  if ((DAT_004a4958 == 2) && (DAT_004ac85c == 1)) {
    aiStack_20[1] = uVar10;
    DAT_004a7184 = 0;
    DAT_004a5a54 = 0x32;
    DAT_004a67bc = 0x32;
    aiStack_20[2] = (uVar10 * 2) / 3;
    DAT_004a7188 = 0x46;
    DAT_004a5a58 = 0x82;
    DAT_004a67c0 = 200;
    DAT_004ac9f4 = DAT_004a4958;
  }
  if (DAT_004a4958 == 2) {
    if (DAT_004ac85c == 2) {
      DAT_004a7184 = 0x8c;
      aiStack_20[1] = uVar10 / 2;
      DAT_004a5a54 = 0xb4;
      DAT_004a67bc = 0x140;
      aiStack_20[2] = uVar10 / 2;
      DAT_004a7188 = 0x3c;
      DAT_004a5a58 = 0x78;
      DAT_004a67c0 = 0xb4;
      DAT_004ac9f4 = DAT_004a4958;
    }
    if (DAT_004ac85c == 3) {
      aiStack_20[1] = uVar10 / 2;
      DAT_004a5a54 = 0x32;
      DAT_004a67bc = 0x32;
      DAT_004a7184 = 0;
      DAT_004a7188 = 0x3c;
      DAT_004a5a58 = 0x69;
      aiStack_20[2] = (uVar10 * 2) / 3;
      DAT_004a67c0 = 0xa4;
      DAT_004ac9f4 = DAT_004a4958;
    }
  }
  if ((DAT_004a4958 == 3) && (DAT_004ac85c == 1)) {
    DAT_004ac9f4 = 5;
    DAT_004a7184 = 0;
    aiStack_20[1] = uVar10 / 2;
    aiStack_20[2] = uVar10 / 3;
    DAT_004a5a54 = 0x1e;
    DAT_004a67bc = 0x1e;
    DAT_004a7188 = 0x46;
    DAT_004a5a58 = 0x6e;
    DAT_004a67c0 = 0xb4;
    aiStack_20[3] = aiStack_20[1];
    _DAT_004a718c = 0x96;
    _DAT_004a5a5c = 0xb4;
    DAT_004a67c4 = 0x14a;
    aiStack_20[4] = aiStack_20[1];
    _DAT_004a7190 = 0x82;
    _DAT_004a5a60 = 0x96;
    _DAT_004a67c8 = 0x118;
    local_c = uVar10;
    _DAT_004a7194 = 0x1e;
    _DAT_004a5a64 = 0x46;
    _DAT_004a67cc = 100;
  }
  if ((DAT_004a4958 == 3) && (DAT_004ac85c == 2)) {
    DAT_004ac9f4 = 5;
    aiStack_20[1] = uVar10 / 2;
    DAT_004a5a54 = 0x1e;
    DAT_004a67bc = 0x1e;
    DAT_004a7184 = 0;
    aiStack_20[2] = (uVar10 * 2) / 3;
    DAT_004a7188 = 0x28;
    DAT_004a5a58 = 0x50;
    aiStack_20[4] = uVar10 / 3;
    DAT_004a67c0 = 0x78;
    aiStack_20[3] = uVar10;
    _DAT_004a718c = 0x50;
    _DAT_004a5a5c = 0x8c;
    DAT_004a67c4 = 0xdc;
    _DAT_004a7190 = 0x96;
    _DAT_004a5a60 = 0xb4;
    _DAT_004a67c8 = 0x14a;
    local_c = uVar10;
    _DAT_004a7194 = 0x78;
    _DAT_004a5a64 = 0x8c;
    _DAT_004a67cc = 0x104;
  }
  if (DAT_004a4958 == 4) {
    if (DAT_004ac85c == 1) {
      aiStack_20[1] = uVar10 * 2;
      DAT_004ac9f4 = 3;
      DAT_004a7184 = 0;
      DAT_004a5a54 = 0x28;
      DAT_004a67bc = 0x28;
      aiStack_20[2] = aiStack_20[1];
      DAT_004a7188 = 0x32;
      DAT_004a5a58 = 0x78;
      DAT_004a67c0 = 0xaa;
      aiStack_20[3] = aiStack_20[1];
      _DAT_004a718c = 0x8c;
      _DAT_004a5a5c = 0xaa;
      DAT_004a67c4 = 0x136;
    }
    if (DAT_004ac85c == 2) {
      aiStack_20[1] = uVar10 * 2;
      DAT_004ac9f4 = 3;
      DAT_004a7184 = 0x82;
      DAT_004a5a54 = 0xaa;
      DAT_004a67bc = 300;
      aiStack_20[2] = aiStack_20[1];
      DAT_004a7188 = 10;
      DAT_004a5a58 = 0x46;
      DAT_004a67c0 = 0x50;
      aiStack_20[3] = aiStack_20[1];
      _DAT_004a718c = 0x5a;
      _DAT_004a5a5c = 0x82;
      DAT_004a67c4 = 0xdc;
    }
  }
  if (DAT_004a4958 == 5) {
    DAT_004ac9f4 = 2;
    if (DAT_004ac85c == 1) {
      aiStack_20[1] = uVar10 * 2;
      DAT_004a7184 = 0;
      DAT_004a5a54 = 0x5a;
      DAT_004a67bc = 0x5a;
      aiStack_20[2] = (uVar10 * 3) / 2;
      DAT_004a7188 = 0x5a;
      DAT_004a5a58 = 0xaa;
      DAT_004a67c0 = 0x104;
    }
    else {
      DAT_004a7184 = 0;
      aiStack_20[1] = (uVar10 * 3) / 2;
      DAT_004a5a54 = 0x5a;
      DAT_004a67bc = 0x5a;
      aiStack_20[2] = aiStack_20[1];
      DAT_004a7188 = 100;
      DAT_004a5a58 = 0xb4;
      DAT_004a67c0 = 0x118;
    }
  }
  if (DAT_004a4958 == 6) {
    aiStack_20[1] = uVar10 * 2;
    aiStack_20[2] = uVar10 * 4;
    DAT_004ac9f4 = 3;
    DAT_004a7184 = 0x9b;
    DAT_004a5a54 = 0xf;
    DAT_004a67bc = 0x15e;
    DAT_004a7188 = 0x14;
    DAT_004a5a58 = 0x5a;
    DAT_004a67c0 = 0x6e;
    aiStack_20[3] = uVar10 * 3;
    _DAT_004a718c = 0x5a;
    _DAT_004a5a5c = 0xa0;
    DAT_004a67c4 = 0xfa;
  }
  if (DAT_004a4958 == 7) {
    DAT_004a67bc = 0;
    DAT_004a7188 = 0;
    aiStack_20[1] = uVar10 * 2;
    DAT_004a5a58 = 0x46;
    DAT_004a67c0 = 0x46;
    DAT_004ac9f4 = 3;
    DAT_004a7184 = 0x4b;
    DAT_004a5a54 = 0x73;
    aiStack_20[2] = uVar10 * 4;
    aiStack_20[3] = uVar10 * 3;
    _DAT_004a718c = 0x73;
    _DAT_004a5a5c = 0xb4;
    DAT_004a67c4 = 0x126;
  }
  dVar3 = (double)local_3c;
  iVar11 = 0;
  local_2c = &DAT_004a9168;
  local_30 = &DAT_004a8e90;
  pdVar9 = (double *)&DAT_004a8028;
  iVar7 = 0;
  do {
    iVar8 = DAT_004a4958;
    *pdVar9 = dVar3;
    iVar12 = 1;
    if (0 < DAT_004ac9f4) {
      do {
        iVar6 = DAT_004ac9f4;
        iVar1 = *(int *)(iVar12 * 4 + 0x4a7180);
        bVar4 = true;
        local_3c = 1;
        if ((iVar11 < iVar1) || (*(int *)(iVar12 * 4 + 0x4a5a50) < iVar11)) {
          if (iVar8 != 6) {
            bVar4 = false;
            local_3c = 0;
            goto LAB_0044eb22;
          }
LAB_0044eb27:
          if (((iVar11 < iVar1) || (*(int *)(iVar12 * 4 + 0x4a5a50) < iVar11)) && (1 < iVar12)) {
            bVar4 = false;
            local_3c = 0;
          }
          if (iVar7 < -0x1e) {
            if (-0xb5 < iVar7) {
              if (iVar12 == 1) {
                bVar4 = false;
                local_3c = 0;
              }
              goto LAB_0044eb57;
            }
          }
          else {
LAB_0044eb57:
            if (-0xb5 < iVar7) goto LAB_0044eb72;
          }
          if ((-0x136 < iVar7) && (iVar12 == 1)) {
            bVar4 = false;
            local_3c = 0;
          }
        }
        else {
LAB_0044eb22:
          if (iVar8 == 6) goto LAB_0044eb27;
        }
LAB_0044eb72:
        if (bVar4) {
          local_3c = (int)(longlong)
                          (((double)(iVar11 - iVar1) /
                           (double)(*(int *)(iVar12 * 4 + 0x4a5a50) - iVar1)) * _DAT_00484d28);
          if ((DAT_004a4958 == 6) && (iVar12 == 1)) {
            if (iVar7 < -0x135) {
              local_3c = 0x5a - (int)(longlong)((double)(iVar7 + 0x168) * _DAT_00485400);
            }
            if (-0x1f < iVar7) {
              local_3c = 0x5a - (int)(longlong)((double)(iVar11 * 2) * _DAT_00485408);
            }
          }
          fVar13 = (float10)fsin((float10)local_3c * (float10)_DAT_00484d40);
          local_3c = (int)(longlong)
                          ((float10)aiStack_20[iVar12] * fVar13 * fVar13 * fVar13 * fVar13);
          iVar8 = DAT_004a4958;
        }
        iVar12 = iVar12 + 1;
        *pdVar9 = (double)local_3c + *pdVar9;
      } while (iVar12 <= iVar6);
    }
    iVar8 = FUN_00415a20(0xf);
    fVar13 = (float10)(iVar11 * 2) * (float10)_DAT_00484d40;
    dVar5 = (double)iVar8 + *pdVar9;
    fVar14 = (float10)fsin(fVar13);
    fVar15 = (float10)fcos(fVar13);
    *pdVar9 = dVar5;
    (&DAT_004a6490)[iVar11] = (int)(longlong)(fVar14 * (float10)dVar5);
    fVar13 = (float10)_DAT_00484eb8;
    fVar2 = (float10)_DAT_00484f30;
    (&DAT_004a68c8)[iVar11] = (int)(longlong)-(fVar15 * (float10)dVar5);
    *local_30 = (int)(longlong)(fVar14 * (float10)dVar5 * fVar13);
    iVar7 = iVar7 + -2;
    iVar11 = iVar11 + 1;
    pdVar9 = pdVar9 + 1;
    *local_2c = (int)(longlong)(fVar15 * (float10)dVar5 * fVar2);
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    if (iVar7 < -0x166) {
      _DAT_004a85c8 = (undefined4)DAT_004a8028;
      _DAT_004a85cc = DAT_004a8028._4_4_;
      _DAT_004a6760 = DAT_004a6490;
      _DAT_004a6b98 = DAT_004a68c8;
      iVar7 = 1;
      do {
        iVar11 = DAT_004a4958;
        if (DAT_004a4958 < 5) {
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
            *(int *)(iVar7 * 4 + 0x4a8998) = (&DAT_004a6490)[(int)local_2c] + -4000;
          }
          else {
            *(int *)(iVar7 * 4 + 0x4a8998) = (&DAT_004a6490)[(int)local_2c] + 4000;
          }
          *(undefined4 *)(iVar7 * 4 + 0x4ac670) = (&DAT_004a68c8)[(int)local_2c];
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
          *(undefined4 *)(iVar7 * 4 + 0x4a8998) = (&DAT_004a6490)[(int)local_2c];
          if (iVar7 < 6) {
            *(int *)(iVar7 * 4 + 0x4ac670) = (&DAT_004a68c8)[(int)local_2c] + -3000;
          }
          else {
            *(int *)(iVar7 * 4 + 0x4ac670) = (&DAT_004a68c8)[(int)local_2c] + 3000;
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
          iVar8 = (&DAT_004a68c8)[(int)local_2c];
          *(undefined4 *)(iVar7 * 4 + 0x4a8998) = (&DAT_004a6490)[(int)local_2c];
          *(int *)(iVar7 * 4 + 0x4ac670) = iVar8 + -3000;
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
          iVar11 = (&DAT_004a68c8)[(int)local_2c];
          *(undefined4 *)(iVar7 * 4 + 0x4a8998) = (&DAT_004a6490)[(int)local_2c];
          *(int *)(iVar7 * 4 + 0x4ac670) = iVar11 + 3000;
        }
        iVar11 = FUN_00415a20(0x3c);
        *(int *)(iVar7 * 4 + 0x4aa7b0) = iVar11 + 0x32;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8);
      _DAT_004ab9d0 = (&DAT_004a6968)[DAT_004ac85c * 5];
      _DAT_004aa28c = (&DAT_004a6530)[DAT_004ac85c * 5] + 2000;
      if (DAT_004a4958 == 5) {
        _DAT_004ab9d0 = DAT_004a6b34 + -1000;
        _DAT_004aa28c = DAT_004a66fc;
      }
      if (DAT_004a4958 < 6) {
        if (DAT_004ac85c == 1) {
          _DAT_004aa654 = DAT_004a6494;
          _DAT_004aa658 = DAT_004a6498;
          _DAT_004abc84 = DAT_004a68cc + -2000;
          _DAT_004ac564 = DAT_004a69cc + 2000;
          _DAT_004aa95c = DAT_004a6594 + 3000;
          _DAT_004aa994 = DAT_004a6634 + -2000;
          _DAT_004ac8e0 = DAT_004a6a6c + 1000;
          _DAT_004abe5c = _DAT_004abc84;
        }
        else {
          _DAT_004aa654 = DAT_004a65fc;
          _DAT_004abc84 = DAT_004a6a34 + 2000;
          _DAT_004aa658 = DAT_004a6600;
          _DAT_004ac564 = DAT_004a68d4 + -3000;
          _DAT_004aa95c = DAT_004a649c;
          _DAT_004aa994 = DAT_004a6634 + -2000;
          _DAT_004ac8e0 = DAT_004a6a6c + 1000;
          _DAT_004abe5c = _DAT_004abc84;
        }
      }
      if (DAT_004a4958 == 5) {
        _DAT_004a4418 = DAT_004a6538 + 1000;
        _DAT_004a63b8 = DAT_004a6970;
        _DAT_004a643c = DAT_004a697c;
        _DAT_004a4420 = DAT_004a6544 + 1000;
        _DAT_004a77e4 = DAT_004a6af8 + -1000;
        _DAT_004a72c4 = DAT_004a66c0 + -2000;
      }
      if ((DAT_004a4958 == 4) && (DAT_004ac85c == 1)) {
        _DAT_004a4418 = DAT_004a65cc;
        _DAT_004a63b8 = DAT_004a6a04 + 3000;
        _DAT_004a4420 = DAT_004a65d8;
        _DAT_004a643c = DAT_004a6a10 + 3000;
        _DAT_004a72c4 = DAT_004a66c0 + -2000;
        _DAT_004a77e4 = DAT_004a6af8 + -1000;
      }
      if ((DAT_004a4958 == 4) && (DAT_004ac85c == 2)) {
        _DAT_004a4418 = DAT_004a6518 + 3000;
        _DAT_004a63b8 = DAT_004a6950;
        _DAT_004a4420 = DAT_004a6528 + 3000;
        _DAT_004a643c = DAT_004a6960;
        _DAT_004a72c4 = DAT_004a6670 + -2000;
        _DAT_004a77e4 = DAT_004a6aa8 + -2000;
        _DAT_004aa994 = DAT_004a6648 + -2000;
        _DAT_004ac8e0 = DAT_004a6a80 + 1000;
        _DAT_004ab9d0 = DAT_004a69b8 + 2000;
        _DAT_004aa28c = DAT_004a6580 + 2000;
      }
      if (DAT_004a4958 == 6) {
        _DAT_004aa95c = DAT_004a66c0;
        _DAT_004ab9d0 = DAT_004a6968 + -1000;
        _DAT_004aa654 = DAT_004a64a8;
        _DAT_004aa658 = DAT_004a64ac;
        _DAT_004aa28c = DAT_004a6530;
        _DAT_004abc84 = DAT_004a68e0 + -2000;
        _DAT_004a72c4 = DAT_004a6710;
        _DAT_004a77e4 = DAT_004a6b48 + -1000;
        _DAT_004ac564 = DAT_004a6af8 + -1000;
        _DAT_004abe5c = DAT_004a68e4 + -2000;
      }
      if (DAT_004a4958 == 7) {
        _DAT_004aa28c = DAT_004a6580;
        _DAT_004ab9d0 = DAT_004a69b8 + 1000;
        _DAT_004a77e4 = DAT_004a69f4 + 1000;
        _DAT_004aa95c = DAT_004a6670;
        _DAT_004aa654 = DAT_004a660c;
        _DAT_004a72c4 = DAT_004a65bc;
        _DAT_004ac564 = DAT_004a6aa8 + 1000;
        _DAT_004abc84 = DAT_004a6a44 + 2000;
        _DAT_004abe5c = DAT_004a6a4c + 2000;
        _DAT_004aa658 = DAT_004a6614;
      }
      return;
    }
  } while( true );
}

