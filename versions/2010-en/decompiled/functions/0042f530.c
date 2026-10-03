
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_0042f530(void)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  undefined8 *puVar11;
  int iVar12;
  int local_124;
  int local_120;
  int local_11c;
  int local_114 [35];
  int aiStack_88 [34];
  
  iVar3 = FUN_0041e000(10);
  local_124 = 1;
  uVar7 = 1;
  if (0 < (int)DAT_004da194) {
    piVar9 = local_114;
    local_11c = 0;
    local_120 = 0;
    do {
      *(undefined4 *)((int)aiStack_88 + local_11c) = 1;
      if (DAT_004da19c == 8) {
        *piVar9 = 0xb4;
      }
      else {
        iVar4 = FUN_0041e000(0x28);
        *piVar9 = iVar4 + 0x6e;
        iVar4 = FUN_0041e000(100);
        if ((0x50 < iVar4) && (DAT_004da140 < local_124)) {
          iVar4 = FUN_0041e000(0x28);
          *(undefined4 *)((int)aiStack_88 + local_11c) = 0xffffffff;
          *piVar9 = -0x6e - iVar4;
        }
      }
      iVar4 = DAT_00535208;
      iVar10 = 2;
      if ((DAT_004da194 == 2) && (DAT_00536470 == 0)) {
        if (iVar3 < 6) {
          local_114[0] = 0x140;
          local_114[1] = 0x28;
          iVar12 = 1;
        }
        else {
          iVar12 = 2;
          local_114[0] = 0x28;
          local_114[1] = 0x140;
          iVar10 = 1;
        }
        *(undefined4 *)(&DAT_00522ff0 + iVar12 * 4) = 0xffffffff;
        iVar4 = FUN_0041bc20(iVar4 + 0x91);
        *(int *)(&DAT_00535740 + iVar12 * 4) = iVar4;
        iVar4 = DAT_00535208 + -0x82;
        *(undefined4 *)(&DAT_00522ff0 + iVar10 * 4) = 1;
        iVar4 = FUN_0041bc20(iVar4);
        *(int *)(&DAT_00535740 + iVar10 * 4) = iVar4;
        if (iVar10 == 1) {
          DAT_00535744 = FUN_0041bc20(DAT_00535208 + -0x98);
        }
        if (iVar12 == 1) {
          DAT_00535744 = FUN_0041bc20(DAT_00535208 + 0xa7);
        }
      }
      if (DAT_004da194 == 2) {
        DAT_00511624 = 0;
      }
      DAT_004f4298 = DAT_00535748;
      if (((DAT_005363b8 == 0) && (DAT_005363c4 == 0)) && (DAT_0053652c == 0)) {
        iVar4 = (int)((ulonglong)((longlong)DAT_00522ad0 * 0x55555555) >> 0x20) - DAT_00522ad0;
        DAT_004f7200 = (((iVar4 >> 1) - (iVar4 >> 0x1f)) - DAT_004da190 / 6) + 0x31;
      }
      else {
        DAT_004f7200 = 0x2e - ((int)((DAT_00522ad0 >> 0x1f & 7U) + DAT_00522ad0) >> 3);
      }
      if (DAT_005364bc == 1) {
        DAT_004f7200 = 0x30 - DAT_00522ad0 / 3;
      }
      if ((DAT_004da190 == 3) && (DAT_005363c4 == 0)) {
        DAT_004f7200 = DAT_004f7200 + 2;
      }
      if (((DAT_005363c4 == 1) || (DAT_0053652c == 1)) && (DAT_00522ad0 < 10)) {
        DAT_004f7200 = DAT_004f7200 + 4;
      }
      if (DAT_005363c0 == 1) {
        DAT_004f7200 = DAT_004f7200 + 2;
      }
      if ((DAT_004da190 == 1) && (DAT_00522ad0 < 10)) {
        DAT_004f7200 = DAT_004f7200 + 5;
      }
      if (DAT_004da190 == 8) {
        DAT_004f7200 = DAT_004f7200 + -4;
      }
      if (DAT_005363bc == 1) {
        DAT_004f7200 = ((DAT_00522ad0 < 10) - 1 & 0xfffffffd) + 0x3c;
      }
      if (DAT_004da190 == 1) {
        DAT_004f7200 = DAT_004f7200 + -1 + DAT_004fe77c;
      }
      if ((DAT_00536528 == 1) && (DAT_00522ad0 < 10)) {
        DAT_004f7200 = DAT_004f7200 + 4;
      }
      if ((DAT_0053652c == 1) && (DAT_00522ad0 < 10)) {
        DAT_004f7200 = DAT_004f7200 + 4;
      }
      if ((2 < (int)DAT_004da194) || (iVar4 = DAT_00522ad0, DAT_004da19c == 8)) {
        iVar4 = DAT_00535208;
        if (DAT_004da19c != 8) {
          iVar4 = DAT_004f7200 * *(int *)((int)aiStack_88 + local_11c) + DAT_00535208;
        }
        iVar4 = FUN_0041bc20(iVar4);
        *(int *)((int)&DAT_00535744 + local_11c) = iVar4;
        iVar4 = DAT_00522ad0;
        if (DAT_004da140 < local_124) {
          iVar10 = FUN_0041e000(0x168);
          iVar4 = DAT_00522ad0;
          *(int *)((int)&DAT_00535744 + local_11c) = iVar10;
        }
      }
      iVar10 = (iVar4 < 0xb) + 4;
      _DAT_004fe938 = (double)DAT_00535744;
      iVar4 = FUN_0041e000((DAT_00523598 * 2) / 3);
      iVar4 = iVar4 + DAT_00523598 / iVar10;
      if (*(int *)((int)aiStack_88 + local_11c) < 0) {
        iVar4 = FUN_0041e000(DAT_00523598 / 2);
        iVar4 = iVar4 + DAT_00523598 / iVar10;
      }
      if (DAT_004da194 == 2) {
        iVar4 = DAT_00523598 / 2;
      }
      if (DAT_004da1d8 == 10) {
        iVar4 = iVar4 * 2;
      }
      iVar10 = FUN_0041bc20(DAT_00535208 + *piVar9);
      if (DAT_004da194 == 2) {
        iVar4 = (iVar4 << 3) / 3;
      }
      FUN_0042f220(*(int *)((int)&DAT_004f4d7c + local_11c),*(int *)((int)&DAT_004fc354 + local_11c)
                   ,iVar4,iVar10);
      iVar4 = DAT_005359d0;
      dVar1 = (double)DAT_004fe080;
      *(double *)((int)&DAT_004f6b00 + local_120) = dVar1;
      dVar2 = (double)DAT_00523180;
      *(double *)((int)&DAT_004f6c18 + local_120) = dVar2;
      if (0 < iVar4) {
        iVar4 = FUN_0042fca0((int)(longlong)dVar1,(int)(longlong)dVar2,local_124);
        iVar10 = FUN_0041bc20(DAT_00536418);
        uVar7 = iVar4 / 3 >> 0x1f;
        FUN_0042f220((int)(longlong)*(double *)((int)&DAT_004f6b00 + local_120),
                     (int)(longlong)*(double *)((int)&DAT_004f6c18 + local_120),
                     (int)(((iVar4 / 3 ^ uVar7) - uVar7) * DAT_00523598) / 0x1e,iVar10);
        *(double *)((int)&DAT_004f6b00 + local_120) = (double)DAT_004fe080;
        *(double *)((int)&DAT_004f6c18 + local_120) = (double)DAT_00523180;
      }
      local_124 = local_124 + 1;
      local_11c = local_11c + 4;
      piVar9 = piVar9 + 1;
      local_120 = local_120 + 8;
      uVar7 = DAT_004da194;
    } while (local_124 <= (int)DAT_004da194);
  }
  if ((2 < (int)DAT_004da194) && (DAT_004da19c != 8)) {
    iVar3 = FUN_0041e000(0x10);
    DAT_004f6b00 = (double)((iVar3 * DAT_004fe094 + DAT_005229c8 + DAT_00536410 * (0x10 - iVar3)) /
                           0x11);
    DAT_004f6c18 = (double)((iVar3 * DAT_004fe2a0 + DAT_00522ac4 + DAT_00536414 * (0x10 - iVar3)) /
                           0x11);
    uVar7 = DAT_004da1f8;
    if (DAT_004da1f8 == 5) {
      DAT_004f6b00 = (double)((DAT_005229c8 + (DAT_004fe094 + DAT_00536410) * 0x32) / 0x65);
      iVar3 = DAT_00522ac4 + (DAT_004fe2a0 + DAT_00536414) * 0x32;
      uVar7 = iVar3 * 0x288df0cb;
      DAT_004f6c18 = (double)(iVar3 / 0x65);
    }
  }
  if (DAT_004da1d8 < 3) {
    iVar3 = 1;
    if (0 < (int)DAT_004da194) {
      iVar10 = 0;
      puVar8 = &DAT_00522ff4;
      iVar4 = 0;
      do {
        *(double *)((int)&DAT_004f6b00 + iVar4) = (double)*(int *)((int)&DAT_004f4d7c + iVar10);
        *(double *)((int)&DAT_004f6c18 + iVar4) = (double)*(int *)((int)&DAT_004fc354 + iVar10);
        FUN_00437570(iVar3);
        uVar7 = DAT_004da194;
        *puVar8 = 1;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 8;
        iVar10 = iVar10 + 4;
        puVar8 = puVar8 + 1;
      } while (iVar3 <= (int)uVar7);
    }
    if (DAT_004da19c == 8) {
      uVar7 = 0;
      DAT_00511624 = 0;
      DAT_00511628 = 0;
    }
    else {
      iVar3 = FUN_0041bc20(DAT_005362d4 - DAT_004f7200);
      _DAT_004fe938 = (double)iVar3;
      uVar7 = FUN_0041bc20(DAT_005362d4 - DAT_004f7200);
      DAT_00535748 = uVar7;
    }
  }
  uVar6 = DAT_004da194;
  if (0 < (int)DAT_004da194) {
    uVar7 = DAT_004da194 * 8;
    puVar11 = &DAT_004f6c18;
    puVar8 = &DAT_004fb098;
    for (uVar5 = uVar7 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *(undefined4 *)puVar11;
      puVar11 = (undefined8 *)((int)puVar11 + 4);
      puVar8 = puVar8 + 1;
    }
    puVar11 = &DAT_004f6b00;
    puVar8 = &DAT_004f83c8;
    for (uVar5 = uVar7 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar8 = *(undefined4 *)puVar11;
      puVar11 = (undefined8 *)((int)puVar11 + 4);
      puVar8 = puVar8 + 1;
    }
    if (0 < (int)uVar6) {
      uVar7 = uVar6 * 8;
      puVar11 = &DAT_004f6c18;
      puVar8 = &DAT_004f3870;
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar8 = *(undefined4 *)puVar11;
        puVar11 = (undefined8 *)((int)puVar11 + 4);
        puVar8 = puVar8 + 1;
      }
      puVar11 = &DAT_004f6b00;
      puVar8 = &DAT_004f1618;
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar8 = *(undefined4 *)puVar11;
        puVar11 = (undefined8 *)((int)puVar11 + 4);
        puVar8 = puVar8 + 1;
      }
    }
  }
  return uVar7;
}

