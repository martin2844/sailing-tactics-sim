
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00437e60(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  longlong lVar14;
  int local_24;
  int local_1c;
  uint local_18;
  int local_4;
  
  iVar4 = DAT_004da194;
  uVar9 = (int)DAT_005364e8 >> 0x1f;
  local_18 = 0;
  if (((DAT_005364e8 ^ uVar9) - uVar9 & 1 ^ uVar9) != uVar9) {
    DAT_0053647c = 0;
    uVar9 = (-(uint)(DAT_004da194 != 2) & 500) + 0x5dc;
    uVar10 = param_1 - *(int *)(&DAT_00535740 + param_2 * 4) >> 0x1f;
    iVar12 = (param_1 - *(int *)(&DAT_00535740 + param_2 * 4) ^ uVar10) - uVar10;
    if (0xb4 < iVar12) {
      iVar12 = 0x168 - iVar12;
    }
    bVar13 = DAT_004da194 == 2;
    *(int *)(&DAT_00534f50 + param_2 * 4) = iVar12;
    if (bVar13) {
      local_4 = FUN_00427ee0(DAT_004f4d7c - (int)(longlong)DAT_004f6b00,
                             (int)(longlong)DAT_004f6c18 - DAT_004fc354);
      if (DAT_004feccc < 0x5a) {
        lVar14 = FUN_00464050(2,1);
        local_1c = (int)lVar14;
      }
      else {
        local_1c = 200;
      }
      iVar4 = DAT_004da194;
      if (((DAT_004f7f9c < 1) || (DAT_00522ff8 != 1)) || (local_18 = 1, DAT_004da194 != 2)) {
        local_18 = 0;
      }
    }
    if ((((((*(int *)(&DAT_004fe8a8 + param_2 * 4) != 0xc) &&
           (((iVar12 < 0x2e || (200 < *(int *)(&DAT_004f8300 + param_2 * 4))) ||
            ((*(int *)(&DAT_00522ff0 + param_2 * 4) != 1 || (DAT_0053646c != 1)))))) &&
          ((((iVar12 < 0x2e || (200 < *(int *)(&DAT_004f8300 + param_2 * 4))) ||
            (*(int *)(&DAT_00522ff0 + param_2 * 4) != -1)) || (DAT_0053646c != 0)))) &&
         ((iVar4 < 3 ||
          (((*(int *)(&DAT_004f4350 + param_2 * 4) + param_2 + 0x32 <= DAT_004f8cd0 ||
            (DAT_004fe15c != 0)) &&
           ((*(int *)(&DAT_004f4350 + param_2 * 4) + param_2 + 0x19 <= DAT_004f8cd0 ||
            (DAT_004fe15c != 1)))))))) &&
        ((iVar4 != 2 ||
         (((DAT_004da1c4 + *(int *)(&DAT_004f4350 + param_2 * 4) <= DAT_004f8cd0 ||
           (DAT_004f8cd0 < 1)) &&
          (((((*(int *)(&DAT_004f4350 + param_2 * 4) + 4 <= DAT_004f8cd0 || (0 < DAT_004f8cd0)) &&
             ((DAT_004da170 <= DAT_004f8cd0 && (local_18 == 0)))) &&
            ((400 < *(int *)(&DAT_004f8300 + param_2 * 4) ||
             ((*(int *)(&DAT_00522ff0 + param_2 * 4) != 1 || (DAT_0053646c != 1)))))) &&
           ((400 < *(int *)(&DAT_004f8300 + param_2 * 4) ||
            ((*(int *)(&DAT_00522ff0 + param_2 * 4) != -1 || (DAT_0053646c != -1)))))))))))) &&
       (*(int *)(&DAT_004fe6d0 + param_2 * 4) != 1)) {
      if ((*(int *)(&DAT_004f7f98 + param_2 * 4) < 1) ||
         (*(int *)(&DAT_004f8300 + param_2 * 4) < 0x65)) {
        if (((((0x19 < iVar12) || (*(int *)(&DAT_00522ff0 + param_2 * 4) != -1)) || (iVar4 < 3)) &&
            (((10 < iVar12 || (*(int *)(&DAT_00522ff0 + param_2 * 4) != -1)) || (iVar4 != 2)))) &&
           ((3 < iVar12 || (*(int *)(&DAT_00522ff0 + param_2 * 4) != 1)))) {
          iVar8 = 0;
          local_24 = 0;
          if (iVar12 < 10) {
            if (2 < iVar4) {
              iVar8 = -200;
              local_24 = -200;
            }
            if ((iVar12 < 10) && (iVar4 == 2)) {
              iVar8 = iVar8 + -400;
              local_24 = iVar8;
            }
          }
          if ((((0x37 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) && (local_18 == 0))
             && (DAT_004fe15c != 1)) {
            iVar8 = iVar8 + (iVar12 + -0x37) * 0x14;
            local_24 = iVar8;
          }
          if (((0x2d < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) &&
             ((local_18 == 0 && (DAT_004fe15c == 1)))) {
            iVar8 = iVar8 + (iVar12 + -0x2d) * 0x14;
            local_24 = iVar8;
          }
          if (((0x3c - param_2 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == DAT_004da214))
             && ((*(int *)(&DAT_004f8300 + param_2 * 4) < 300 && (local_18 == 0)))) {
            local_24 = iVar8 + 1000;
          }
          iVar4 = FUN_0041bc20(*(int *)(&DAT_00522d30 + param_2 * 4) + 0xb4);
          iVar8 = 0x46 - param_2;
          if (iVar8 < iVar12) {
            if ((*(int *)(&DAT_00522ff0 + param_2 * 4) == -DAT_004da214) &&
               (300 < *(int *)(&DAT_004f8300 + param_2 * 4))) {
              iVar5 = (&DAT_00522b90)[param_2];
              if (((0x1e < iVar4 - iVar5) &&
                  (((iVar4 - iVar5 < 0x96 && (6 < *(int *)(&DAT_00535a08 + param_2 * 4))) &&
                   (0x59 < iVar5)))) && (iVar5 < 0x10f)) {
                local_24 = local_24 + 500;
              }
            }
            if (((iVar8 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == -DAT_004da214)) &&
               (300 < *(int *)(&DAT_004f8300 + param_2 * 4))) {
              iVar5 = FUN_0041e3a0((&DAT_00522b90)[param_2]);
              iVar6 = FUN_0041e3a0(iVar4);
              if (0x1e < iVar6 - iVar5) {
                iVar5 = FUN_0041e3a0((&DAT_00522b90)[param_2]);
                iVar4 = FUN_0041e3a0(iVar4);
                if (((iVar4 - iVar5 < 0x96) && (6 < *(int *)(&DAT_00535a08 + param_2 * 4))) &&
                   ((0x10e < (int)(&DAT_00522b90)[param_2] || ((int)(&DAT_00522b90)[param_2] < 0x5a)
                    ))) {
                  local_24 = local_24 + 500;
                }
              }
            }
          }
          if ((((0x4b - param_2 < iVar12) && (300 < *(int *)(&DAT_004f8300 + param_2 * 4))) &&
              (0x87 < *(int *)(&DAT_004f8cd8 + param_2 * 4))) &&
             (9 < *(int *)(&DAT_00535a08 + param_2 * 4))) {
            local_24 = local_24 + (*(int *)(&DAT_00535a08 + param_2 * 4) + 0x19) * 0x14;
          }
          if (((iVar8 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) && (local_18 == 0))
          {
            local_24 = local_24 + (iVar12 + -0x37) * 0x28;
          }
          if ((0x2d < iVar12) && (DAT_004da19c == 8)) {
            local_24 = local_24 + (iVar12 + -0x2d) * 0x50;
          }
          if ((((0x3c - param_2 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) &&
              (*(int *)(&DAT_004f8538 + param_2 * 4) == 1)) && (local_18 == 0)) {
            local_24 = local_24 + (iVar12 + -0x37) * 0x28;
          }
          uVar10 = param_2 >> 0x1f;
          iVar4 = param_2 / 2;
          if (((0x4b - iVar4 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) &&
             (local_18 == 0)) {
            local_24 = local_24 + 1000;
          }
          if (((*(int *)(&DAT_004f8538 + param_2 * 4) == DAT_004da1e4) && (0x46 < iVar12)) &&
             ((*(int *)(&DAT_00522ff0 + param_2 * 4) == -1 && (local_18 == 0)))) {
            local_24 = local_24 + 4000;
          }
          if (((DAT_004f7200 * 9) / 5 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == -1)) {
            local_24 = local_24 + 600;
          }
          if (iVar8 < iVar12) {
            if (((*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) &&
                (200 < *(int *)(&DAT_004f8300 + param_2 * 4))) && (local_18 == 0)) {
              local_24 = (0x41 - iVar12) * 3 + local_24;
            }
            if (((iVar8 < iVar12) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == -1)) &&
               (400 < *(int *)(&DAT_004f8300 + param_2 * 4))) {
              local_24 = local_24 + (iVar12 + -0x41) * (DAT_0053646c * 0x12 + 3);
            }
          }
          if ((iVar12 < 0x42) && (200 < *(int *)(&DAT_004f8300 + param_2 * 4))) {
            local_18 = FUN_0041bc20((&DAT_00522b90)[param_2] - DAT_005359d4);
            if (0xb4 < (int)local_18) {
              local_18 = local_18 - 0x168;
            }
            iVar8 = local_18 * *(int *)(&DAT_00522ff0 + param_2 * 4);
            uVar7 = (int)local_18 >> 0x1f;
            if ((((iVar8 < 0) && (local_24 = local_24 + ((local_18 ^ uVar7) - uVar7), iVar8 < 0)) &&
                (8 < DAT_004da198)) && (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)) {
              local_24 = ((local_18 ^ uVar7) - uVar7) * 9 + local_24;
            }
            if (((iVar8 < 0) && (8 < DAT_004da198)) &&
               ((DAT_004fe15c == 1 && (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))) {
              local_24 = ((local_18 ^ uVar7) - uVar7) * 9 + local_24;
            }
            if (0 < iVar8) {
              if ((8 < DAT_004da198) && (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)) {
                local_24 = local_24 + ((local_18 ^ uVar7) - uVar7) * -9;
              }
              if ((((0 < iVar8) && (8 < DAT_004da198)) && (DAT_004fe15c == 1)) &&
                 (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)) {
                local_24 = local_24 + ((local_18 ^ uVar7) - uVar7) * -9;
              }
            }
            if (((4 < DAT_004f8b7c) && (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1)) &&
               (DAT_0053645c == 0)) {
              local_24 = local_24 + 100;
            }
            if (((*(double *)(&DAT_004ffcb8 + param_2 * 8) <
                  *(double *)(&DAT_004f4888 + param_2 * 8)) &&
                (*(int *)(&DAT_00536240 + param_2 * 4) == 1)) &&
               ((6 < DAT_004da198 &&
                (((0x96 < *(int *)(&DAT_004f8300 + param_2 * 4) && (0xf < iVar12)) &&
                 (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))))) {
              local_24 = local_24 + 500;
            }
            if (((*(double *)(&DAT_004f4888 + param_2 * 8) <
                  *(double *)(&DAT_004ffcb8 + param_2 * 8)) &&
                (*(int *)(&DAT_00536240 + param_2 * 4) == 1)) &&
               (((6 < DAT_004da198 &&
                 ((0x96 < *(int *)(&DAT_004f8300 + param_2 * 4) && (0xf < iVar12)))) &&
                (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))) {
              local_24 = local_24 + -500;
            }
            iVar8 = *(int *)(&DAT_004fc230 + param_2 * 4);
            uVar7 = iVar8 - *(int *)(&DAT_004fdfe8 + param_2 * 4);
            uVar11 = (int)uVar7 >> 0x1f;
            iVar5 = (uVar7 ^ uVar11) - uVar11;
            if (iVar8 < *(int *)(&DAT_004fdfe8 + param_2 * 4)) {
              if ((((*(double *)(&DAT_004f4bc0 + param_2 * 8) <
                     (double)*(int *)(&DAT_00535a08 + param_2 * 4)) && (8 < DAT_004da198)) &&
                  (3 < iVar5)) &&
                 ((500 < *(int *)(&DAT_004f8300 + param_2 * 4) && (DAT_004da1f8 != 5)))) {
                local_24 = local_24 + iVar5 * 0x14;
              }
              if ((((double)*(int *)(&DAT_00535a08 + param_2 * 4) <
                    *(double *)(&DAT_004f4bc0 + param_2 * 8)) && (8 < DAT_004da198)) &&
                 ((3 < iVar5 &&
                  ((500 < *(int *)(&DAT_004f8300 + param_2 * 4) && (DAT_004da1f8 != 5)))))) {
                local_24 = local_24 + iVar5 * -10;
              }
            }
            if ((((((DAT_004da1f8 == 999) && (4 < *(int *)(&DAT_00535a08 + param_2 * 4))) &&
                  (*(int *)(&DAT_004f8cd8 + param_2 * 4) < 0x5a)) &&
                 ((*(int *)(&DAT_00522ff0 + param_2 * 4) == DAT_004da214 && (DAT_004da248 == 2))))
                && (DAT_004da1fc * 2 < (int)(longlong)*(double *)(&DAT_004ffcb8 + param_2 * 8))) &&
               (iVar12 < 0x50)) {
              local_24 = local_24 + ((*(int *)(&DAT_00535a08 + param_2 * 4) - param_2) + 0x46) * 10;
            }
            if ((((DAT_004da1f8 == 999) && (4 < *(int *)(&DAT_00535a08 + param_2 * 4))) &&
                ((*(int *)(&DAT_004f8cd8 + param_2 * 4) < 0x5a &&
                 (((*(int *)(&DAT_00522ff0 + param_2 * 4) == DAT_004da214 && (DAT_004da248 == 2)) &&
                  (*(int *)(&DAT_005232e8 + param_2 * 4) <=
                   (int)(longlong)*(double *)(&DAT_004ffcb8 + param_2 * 8))))))) && (iVar12 < 0x5a))
            {
              local_24 = (-0x14 - *(int *)(&DAT_00535a08 + param_2 * 4)) * 0xf + local_24;
            }
            if (*(int *)(&DAT_004fdfe8 + param_2 * 4) < iVar8) {
              if ((((double)*(int *)(&DAT_00535a08 + param_2 * 4) <
                    *(double *)(&DAT_004f4bc0 + param_2 * 8)) && (8 < DAT_004da198)) &&
                 ((3 < iVar5 &&
                  ((500 < *(int *)(&DAT_004f8300 + param_2 * 4) && (DAT_004da1f8 != 5)))))) {
                local_24 = local_24 + iVar5 * 10;
              }
              if ((((*(double *)(&DAT_004f4bc0 + param_2 * 8) <
                     (double)*(int *)(&DAT_00535a08 + param_2 * 4)) && (8 < DAT_004da198)) &&
                  (3 < iVar5)) &&
                 ((500 < *(int *)(&DAT_004f8300 + param_2 * 4) && (DAT_004da1f8 != 5)))) {
                local_24 = local_24 + iVar5 * -10;
              }
            }
            uVar7 = DAT_005364f8 + DAT_00535204;
            iVar8 = uVar7 * *(int *)(&DAT_00522ff0 + param_2 * 4);
            uVar11 = (int)uVar7 >> 0x1f;
            if (((0 < iVar8) && (7 < DAT_004da198)) &&
               ((300 < *(int *)(&DAT_004f8300 + param_2 * 4) &&
                (((iVar12 < (DAT_004f8b74 * -10 + 0x4b) - iVar4 && (DAT_004fe15c == 0)) &&
                 (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))))) {
              iVar5 = (uVar7 ^ uVar11) - uVar11;
              local_24 = local_24 + iVar5 * 0x1e;
              if ((DAT_004f8b74 == 1) && (((param_2 ^ uVar10) - uVar10 & 3 ^ uVar10) == uVar10)) {
                local_24 = local_24 + iVar5 * 0x3c;
              }
            }
            if (((0 < iVar8) && (7 < DAT_004da198)) &&
               ((300 < *(int *)(&DAT_004f8300 + param_2 * 4) &&
                (((iVar12 < (DAT_004f8b74 * -10 + 0x4b) - iVar4 && (DAT_004fe15c == 1)) &&
                 (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10)))))) {
              local_24 = local_24 + ((uVar7 ^ uVar11) - uVar11) * 10;
            }
            if (((iVar8 < 0) && (7 < DAT_004da198)) &&
               ((300 < *(int *)(&DAT_004f8300 + param_2 * 4) &&
                ((iVar12 < 0x4b - iVar4 && (((param_2 ^ uVar10) - uVar10 & 1 ^ uVar10) == uVar10))))
               )) {
              iVar4 = (uVar7 ^ uVar11) - uVar11;
              local_24 = local_24 + iVar4 * -0x14;
              if ((DAT_004f8b74 == 1) && (DAT_004fe15c == 0)) {
                local_24 = local_24 + iVar4 * -0x28;
              }
            }
            if (DAT_004f8cd0 < *(int *)(&DAT_004f4350 + param_2 * 4) + DAT_004da1c8) {
              if ((5 < DAT_004da190) || (DAT_005363bc == 1)) {
                local_24 = local_24 + -0x28;
              }
              if (DAT_004da1f8 == 5) {
                local_24 = local_24 + -0x28;
              }
            }
            if ((2 < DAT_004da194) || (DAT_004da198 < 9)) {
              iVar4 = FUN_0041e000(0x32);
              local_24 = local_24 + iVar4;
            }
          }
          iVar5 = DAT_004fb5d4;
          iVar8 = DAT_004da214;
          iVar4 = DAT_004da1f8;
          if ((*(int *)(&DAT_004f4208 + param_2 * 4) == 1) && (5 < DAT_004da198)) {
            local_24 = local_24 + 500;
          }
          if (((3 < DAT_004da198) && (2 < DAT_004da194)) &&
             ((*(int *)(&DAT_004fe8a8 + param_2 * 4) == 2 ||
              (*(int *)(&DAT_004fe8a8 + param_2 * 4) == 3)))) {
            local_24 = local_24 + 500;
          }
          if (0 < DAT_004da1f8) {
            if (((*(double *)(&DAT_005125f8 + param_2 * 8) <
                  (double)*(int *)(&DAT_005232e8 + param_2 * 4)) &&
                (*(double *)(&DAT_005125f8 + param_2 * 8) < *(double *)(&DAT_00523478 + param_2 * 8)
                )) && (DAT_004fb5d4 == 0)) {
              local_24 = 10000;
              *(int *)(&DAT_004fad40 + param_2 * 4) = param_2 + 10 + DAT_004f8cd0;
            }
            iVar6 = 0x9c4;
            dVar3 = (double)(*(int *)(&DAT_005232e8 + param_2 * 4) + 5);
            if ((*(double *)(&DAT_005125f8 + param_2 * 8) < dVar3) && (iVar5 == 1)) {
              iVar5 = iVar6;
              if (*(int *)(&DAT_00522ff0 + param_2 * 4) != iVar8) {
                iVar5 = -0x9c4;
              }
              local_24 = local_24 + iVar5;
            }
            if (((*(double *)(&DAT_005125f8 + param_2 * 8) < dVar3) && (iVar4 == 999)) &&
               (DAT_004da248 == 2)) {
              if (*(int *)(&DAT_00522ff0 + param_2 * 4) != -iVar8) {
                iVar6 = -0x9c4;
              }
              local_24 = local_24 + iVar6;
            }
          }
          if (iVar4 == 0) {
            dVar3 = _DAT_004cc4c0;
            if (1 < DAT_004f69b8) {
              dVar3 = _DAT_004cc5a8;
            }
            if ((*(double *)(&DAT_004ffcb8 + param_2 * 8) < dVar3) && (DAT_004f8b78 == 0)) {
              if (*(double *)(&DAT_004ffcb8 + param_2 * 8) <
                  *(double *)(&DAT_004f4888 + param_2 * 8)) {
                local_24 = 5000;
              }
              if (*(double *)(&DAT_004f4888 + param_2 * 8) <
                  *(double *)(&DAT_004ffcb8 + param_2 * 8)) {
                local_24 = local_24 + -500;
              }
            }
            if ((*(double *)(&DAT_004ffcb8 + param_2 * 8) < dVar3 * _DAT_004cca00) &&
               (DAT_004f8b78 == 1)) {
              if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
                local_24 = local_24 + 1000;
              }
              else {
                local_24 = local_24 + -1000;
              }
            }
          }
          if ((DAT_004da194 == 2) && (param_2 == 2)) {
            if ((DAT_004fe8b0 == 2) || (DAT_004fe8b0 == 3)) {
              local_24 = local_24 + 5000;
            }
            if ((local_1c < 0) && (DAT_004fe15c == 1)) {
              uVar10 = (int)local_18 >> 0x1f;
              if (((int)(local_18 * DAT_00522ff8) < 0) && (9 < DAT_004da198)) {
                local_24 = local_24 + ((local_18 ^ uVar10) - uVar10) * 2;
              }
              if ((10 < (int)(local_18 * DAT_00522ff8)) && (9 < DAT_004da198)) {
                local_24 = local_24 + ((local_18 ^ uVar10) - uVar10) * -2;
              }
            }
            if (((((200 < DAT_004f8308) && (DAT_00522ff4 != DAT_00522ff8)) && (iVar12 < 0x4b)) &&
                ((local_24 < 200 && (0 < local_1c)))) &&
               ((DAT_004fe8ac == 0xc || (DAT_005231a8 == 0xc)))) {
              local_24 = local_24 + 20000;
            }
            if (((200 < DAT_004f8308) && (DAT_00522ff4 == DAT_00522ff8)) &&
               ((iVar12 < 0x4b && (DAT_004fe8ac == 2)))) {
              local_24 = local_24 + -500;
            }
            uVar10 = FUN_0041e3a0(param_1 - local_4);
            if (DAT_004fe8ac == 0) {
              uVar7 = (int)uVar10 >> 0x1f;
              if (((10 < local_1c) && (200 < DAT_004f8308)) && (DAT_00522ff4 != DAT_00522ff8)) {
                if ((int)((uVar10 ^ uVar7) - uVar7) < 4) {
                  local_24 = local_24 + 300;
                }
                else {
                  if (((DAT_00522ff4 == 1) && (3 < (int)uVar10)) &&
                     (((int)uVar10 < 0x5a && (0xf < local_1c)))) {
                    local_24 = local_24 + -0x7d;
                  }
                  if (((DAT_00522ff4 == -1) && (3 < (int)uVar10)) && ((int)uVar10 < 0x5a)) {
                    local_24 = local_24 + 0x7d;
                  }
                  if (((DAT_00522ff4 == -1) && ((int)uVar10 < -3)) && (-0x5a < (int)uVar10)) {
                    local_24 = local_24 + -0x7d;
                  }
                  if (((DAT_00522ff4 == 1) && ((int)uVar10 < -3)) && (-0x5a < (int)uVar10)) {
                    local_24 = local_24 + 0x7d;
                  }
                }
              }
              if (((7 < local_1c) && (200 < DAT_004f8308)) && (DAT_00522ff4 == DAT_00522ff8)) {
                if ((int)((uVar10 ^ uVar7) - uVar7) < 4) {
                  local_24 = local_24 + -300;
                }
                else {
                  if ((((DAT_00522ff4 == 1) && (3 < (int)uVar10)) && ((int)uVar10 < 0x5a)) &&
                     (0x14 < local_1c)) {
                    local_24 = local_24 + 0x7d;
                  }
                  if (((DAT_00522ff4 == -1) && ((int)uVar10 < -3)) &&
                     ((-0x5a < (int)uVar10 && (0xf < local_1c)))) {
                    local_24 = local_24 + 0x7d;
                  }
                }
              }
            }
            uVar10 = FUN_0041e3a0(param_1 - local_4);
            if (((local_1c < 0x15) && (300 < DAT_004f8308)) &&
               ((2 < (int)uVar10 && (((int)uVar10 < 0x5a && (DAT_00522ff4 == 1)))))) {
              if (DAT_00522ff8 == 1) {
                local_24 = local_24 + -0x7d;
              }
              if ((DAT_00522ff8 == -1) && (local_1c < 0x10)) {
                local_24 = local_24 + 0x7d;
              }
            }
            if ((((local_1c < 0x10) && (300 < DAT_004f8308)) && ((int)uVar10 < -2)) &&
               ((-0x5a < (int)uVar10 && (DAT_00522ff4 == -1)))) {
              if (DAT_00522ff8 == -1) {
                local_24 = local_24 + -0x7d;
              }
              if (DAT_00522ff8 == 1) {
                local_24 = local_24 + 0x7d;
              }
            }
            uVar7 = (int)uVar10 >> 0x1f;
            if (((local_1c < -0x14) && (200 < DAT_004f8308)) &&
               ((DAT_00522ff4 == DAT_00522ff8 && ((int)((uVar10 ^ uVar7) - uVar7) < 3)))) {
              local_24 = local_24 + 0x46;
            }
            if ((((local_1c < -0x14) && (200 < DAT_004f8308)) && (DAT_00522ff4 != DAT_00522ff8)) &&
               ((int)((uVar10 ^ uVar7) - uVar7) < 3)) {
              local_24 = local_24 + -0x46;
            }
          }
          if (((DAT_005363b8 == 0) && (DAT_005363bc == 0)) && (DAT_005363c4 == 0)) {
            uVar9 = (uVar9 * 4) / 5;
          }
          if (DAT_005363bc == 1) {
            uVar9 = uVar9 * 2;
          }
          if (((DAT_004da194 == 2) && (DAT_004fe8ac == 0)) && (DAT_004fe8b0 == 0)) {
            uVar9 = (uVar9 * 3) / 2;
          }
          if ((2 < DAT_004da194) && (*(int *)(&DAT_004fe8a8 + param_2 * 4) == 0)) {
            uVar9 = (uVar9 * 4) / 3;
          }
          dVar3 = (double)local_24 * _DAT_00523378 * _DAT_004cca08 * _DAT_004cc570;
          if (DAT_004da1f8 == 5) {
            uVar9 = (uVar9 * 3) / 2;
          }
          iVar12 = FUN_0041e000(uVar9);
          iVar4 = DAT_004f8cd0;
          if (iVar12 < (int)(longlong)dVar3) {
            dVar3 = *(double *)(&DAT_004fe180 + param_2 * 8) * _DAT_004cc738;
            uVar1 = *(undefined4 *)(&DAT_004ffcb8 + param_2 * 8);
            *(undefined4 *)(&DAT_00522e68 + param_2 * 4) =
                 *(undefined4 *)(&DAT_00522ff0 + param_2 * 4);
            uVar2 = *(undefined4 *)(&DAT_004ffcbc + param_2 * 8);
            *(undefined4 *)(&DAT_004f4888 + param_2 * 8) = uVar1;
            *(double *)(&DAT_004fe180 + param_2 * 8) = dVar3;
            iVar12 = *(int *)(&DAT_00535a08 + param_2 * 4);
            *(int *)(&DAT_004f4350 + param_2 * 4) = iVar4;
            *(undefined4 *)(&DAT_004fc2c0 + param_2 * 4) = 0;
            *(undefined4 *)(&DAT_004f488c + param_2 * 8) = uVar2;
            *(double *)(&DAT_004f4bc0 + param_2 * 8) = (double)iVar12;
          }
        }
      }
      else if ((0 < local_1c) && (iVar4 == 2)) {
        DAT_0053647c = 1;
        return;
      }
    }
  }
  return;
}

