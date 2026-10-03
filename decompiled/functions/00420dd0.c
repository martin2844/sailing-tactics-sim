
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420dd0(void)

{
  int iVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  int local_104;
  int local_fc;
  int local_f4 [31];
  int aiStack_78 [30];
  
  iVar6 = FUN_00415a20(10);
  local_104 = 1;
  if (0 < (int)DAT_0049118c) {
    piVar12 = local_f4;
    local_fc = 0;
    iVar10 = 0;
    do {
      *(undefined4 *)((int)aiStack_78 + local_fc) = 1;
      if (DAT_00491194 == 8) {
        *piVar12 = 0xb4;
      }
      else {
        iVar7 = FUN_00415a20(0x28);
        *piVar12 = iVar7 + 0x6e;
        iVar7 = FUN_00415a20(100);
        if ((0x50 < iVar7) && (DAT_00491140 < local_104)) {
          iVar7 = FUN_00415a20(0x28);
          *(undefined4 *)((int)aiStack_78 + local_fc) = 0xffffffff;
          *piVar12 = -0x6e - iVar7;
        }
      }
      iVar7 = DAT_004abc80;
      iVar14 = 2;
      if ((DAT_0049118c == 2) && (DAT_004ac9ac == 0)) {
        if (iVar6 < 6) {
          local_f4[0] = 0x122;
          local_f4[1] = 0x46;
          iVar13 = 1;
        }
        else {
          iVar13 = 2;
          local_f4[0] = 0x46;
          local_f4[1] = 0x122;
          iVar14 = 1;
        }
        *(undefined4 *)(&DAT_004aa730 + iVar13 * 4) = 0xffffffff;
        iVar7 = FUN_00413cb0(iVar7 + 0x91);
        *(int *)(&DAT_004ac018 + iVar13 * 4) = iVar7;
        iVar7 = DAT_004abc80 + -0x82;
        *(undefined4 *)(&DAT_004aa730 + iVar14 * 4) = 1;
        iVar7 = FUN_00413cb0(iVar7);
        *(int *)(&DAT_004ac018 + iVar14 * 4) = iVar7;
      }
      iVar7 = DAT_004abc80;
      if (DAT_0049118c == 2) {
        iVar14 = 1;
        if (DAT_004ac9ac == 1) {
          if (iVar6 < 6) {
            iVar6 = 1;
            iVar14 = 2;
          }
          else {
            iVar6 = 2;
          }
          *(undefined4 *)(&DAT_004aa730 + iVar6 * 4) = 1;
          iVar10 = FUN_00413cb0(iVar7 + -0x2d);
          iVar7 = DAT_004abc80 + 0x2d;
          *(int *)(&DAT_004ac018 + iVar6 * 4) = iVar10;
          *(undefined4 *)(&DAT_004aa730 + iVar14 * 4) = 0xffffffff;
          iVar13 = FUN_00413cb0(iVar7);
          iVar10 = DAT_004aa594;
          iVar7 = DAT_004a70f8;
          *(int *)(&DAT_004ac018 + iVar14 * 4) = iVar13;
          iVar13 = DAT_004aa59c;
          iVar1 = iVar7 + iVar10 * 3;
          iVar10 = iVar10 + iVar7 * 3;
          _DAT_004a78e8 = (double)DAT_004ac01c;
          iVar7 = DAT_004a72c8 + DAT_004aa59c * 3;
          *(double *)(&DAT_004a49e8 + iVar6 * 8) =
               (double)((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
          iVar1 = DAT_004a72c8;
          *(double *)(&DAT_004a4ae0 + iVar6 * 8) =
               (double)((int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
          iVar13 = iVar13 + iVar1 * 3;
          *(double *)(&DAT_004a49e8 + iVar14 * 8) =
               (double)((int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2);
          uVar9 = DAT_0049118c;
          *(double *)(&DAT_004a4ae0 + iVar14 * 8) =
               (double)((int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2);
          uVar5 = DAT_004a8a84;
          if (0 < (int)uVar9) {
            puVar11 = &DAT_004a6f4c;
            for (uVar8 = uVar9 & 0x3fffffff; uVar4 = DAT_004a8a54, uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = uVar5;
              puVar11 = puVar11 + 1;
            }
            puVar11 = &DAT_004a488c;
            for (uVar8 = uVar9 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = uVar4;
              puVar11 = puVar11 + 1;
            }
            puVar11 = &DAT_004a5424;
            for (uVar8 = uVar9 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = 1;
              puVar11 = puVar11 + 1;
            }
            puVar11 = &DAT_004a4ae8;
            puVar15 = &DAT_004a60e0;
            for (uVar8 = uVar9 * 8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar15 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar15 = puVar15 + 1;
            }
            puVar11 = &DAT_004a49f0;
            puVar15 = &DAT_004a5320;
            for (uVar9 = uVar9 * 8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar15 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar15 = puVar15 + 1;
            }
          }
          DAT_004a8914 = 1;
          return;
        }
        if (DAT_004ac9ac == 0) {
          DAT_004a8914 = 0;
        }
      }
      DAT_004a414c = DAT_004ac020;
      if (DAT_004ac900 == 0) {
        iVar7 = (int)((ulonglong)((longlong)DAT_004aa390 * 0x55555555) >> 0x20) - DAT_004aa390;
        DAT_004a4eb0 = (((iVar7 >> 1) - (iVar7 >> 0x1f)) - DAT_00491188 / 6) + 0x2d;
      }
      else {
        DAT_004a4eb0 = 0x2e - ((int)(DAT_004aa390 + (DAT_004aa390 >> 0x1f & 7U)) >> 3);
      }
      if (DAT_00491188 == 3) {
        DAT_004a4eb0 = DAT_004a4eb0 + 3;
      }
      if (DAT_00491188 == 7) {
        DAT_004a4eb0 = DAT_004a4eb0 + -2;
      }
      if (DAT_00491188 == 8) {
        DAT_004a4eb0 = DAT_004a4eb0 + -6;
      }
      if (DAT_004ac904 == 1) {
        DAT_004a4eb0 = 0x37;
      }
      if (((DAT_00491188 < 7) || (DAT_004ac900 == 1)) || (DAT_004ac908 == 1)) {
        if (DAT_004aa390 < 0xb) {
          DAT_004a4eb0 = DAT_004a4eb0 + 3;
        }
        if (DAT_004aa390 < 8) {
          DAT_004a4eb0 = DAT_004a4eb0 + 3;
        }
      }
      if ((2 < (int)DAT_0049118c) || (DAT_00491194 == 8)) {
        iVar7 = DAT_004abc80;
        if (DAT_00491194 != 8) {
          iVar7 = DAT_004a4eb0 * *(int *)((int)aiStack_78 + local_fc) + DAT_004abc80;
        }
        iVar7 = FUN_00413cb0(iVar7);
        *(int *)((int)&DAT_004ac01c + local_fc) = iVar7;
        if (DAT_00491140 < local_104) {
          iVar7 = FUN_00415a20(0x168);
          *(int *)((int)&DAT_004ac01c + local_fc) = iVar7;
        }
      }
      iVar14 = (DAT_004aa390 < 0xb) + 4;
      _DAT_004a78e8 = (double)DAT_004ac01c;
      iVar7 = FUN_00415a20((DAT_004aa998 * 2) / 3);
      iVar7 = iVar7 + DAT_004aa998 / iVar14;
      if (*(int *)((int)aiStack_78 + local_fc) < 0) {
        iVar7 = FUN_00415a20(DAT_004aa998 / 2);
        iVar7 = iVar7 + DAT_004aa998 / iVar14;
      }
      if (DAT_0049118c == 2) {
        iVar7 = DAT_004aa998 / 2;
      }
      if (DAT_004911cc == 10) {
        iVar7 = iVar7 * 2;
      }
      iVar14 = FUN_00413cb0(DAT_004abc80 + *piVar12);
      FUN_00420b20(*(int *)((int)&DAT_004a488c + local_fc),*(int *)((int)&DAT_004a6f4c + local_fc),
                   iVar7,iVar14);
      iVar7 = DAT_004ac1dc;
      dVar2 = (double)DAT_004a70e8;
      *(double *)((int)&DAT_004a49f0 + iVar10) = dVar2;
      dVar3 = (double)DAT_004aa81c;
      *(double *)((int)&DAT_004a4ae8 + iVar10) = dVar3;
      if (0 < iVar7) {
        iVar7 = FUN_00421560((int)(longlong)dVar2,(uint)(longlong)dVar3,local_104);
        iVar14 = FUN_00413cb0(DAT_004aa960);
        uVar9 = iVar7 / 3 >> 0x1f;
        FUN_00420b20((int)(longlong)*(double *)((int)&DAT_004a49f0 + iVar10),
                     (int)(longlong)*(double *)((int)&DAT_004a4ae8 + iVar10),
                     (int)(((iVar7 / 3 ^ uVar9) - uVar9) * DAT_004aa998) / 0x1e,iVar14);
        *(double *)((int)&DAT_004a49f0 + iVar10) = (double)DAT_004a70e8;
        *(double *)((int)&DAT_004a4ae8 + iVar10) = (double)DAT_004aa81c;
      }
      local_104 = local_104 + 1;
      local_fc = local_fc + 4;
      piVar12 = piVar12 + 1;
      iVar10 = iVar10 + 8;
    } while (local_104 <= (int)DAT_0049118c);
  }
  if ((2 < (int)DAT_0049118c) && (DAT_00491194 != 8)) {
    iVar6 = FUN_00415a20(0x10);
    _DAT_004a49f0 =
         (double)((iVar6 * DAT_004a70f8 + DAT_004aa288 + DAT_004aa594 * (0x10 - iVar6)) / 0x11);
    _DAT_004a4ae8 =
         (double)((iVar6 * DAT_004a72c8 + DAT_004aa384 + DAT_004aa59c * (0x10 - iVar6)) / 0x11);
  }
  if (DAT_004911cc < 3) {
    iVar6 = 1;
    if (0 < (int)DAT_0049118c) {
      iVar7 = 0;
      puVar11 = &DAT_004aa734;
      iVar10 = 0;
      do {
        *(double *)((int)&DAT_004a49f0 + iVar10) = (double)*(int *)((int)&DAT_004a488c + iVar7);
        *(double *)((int)&DAT_004a4ae8 + iVar10) = (double)*(int *)((int)&DAT_004a6f4c + iVar7);
        FUN_00426ad0(iVar6);
        uVar9 = DAT_0049118c;
        *puVar11 = 1;
        iVar6 = iVar6 + 1;
        iVar10 = iVar10 + 8;
        iVar7 = iVar7 + 4;
        puVar11 = puVar11 + 1;
      } while (iVar6 <= (int)uVar9);
    }
    if (DAT_00491194 == 8) {
      DAT_004a8914 = 0;
      DAT_004a8918 = 0;
    }
    else {
      iVar6 = FUN_00413cb0(DAT_004ac840 - DAT_004a4eb0);
      _DAT_004a78e8 = (double)iVar6;
      DAT_004ac020 = FUN_00413cb0(DAT_004ac840 - DAT_004a4eb0);
    }
  }
  if (0 < (int)DAT_0049118c) {
    uVar9 = DAT_0049118c << 3;
    puVar11 = &DAT_004a4ae8;
    puVar15 = &DAT_004a60e0;
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar15 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar15 = puVar15 + 1;
    }
    puVar11 = &DAT_004a49f0;
    puVar15 = &DAT_004a5320;
    for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar15 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar15 = puVar15 + 1;
    }
  }
  return;
}

