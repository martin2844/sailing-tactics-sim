
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00436ba0(int param_1,int param_2,int param_3)

{
  char cVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  float10 fVar12;
  int local_1c;
  int local_14;
  int local_c;
  
  if (DAT_004da1f8 < 1) {
    if (0 < param_3) {
      local_c = (&DAT_00522b90)[param_3];
    }
    DAT_004fae5c = 0;
    if (param_3 == 1) {
      DAT_00522cac = 0;
      _DAT_004f7ec8 = 0;
    }
    if (param_3 == 2) {
      DAT_00522d18 = 0;
    }
    if ((param_3 < 1) ||
       (local_14 = DAT_004da218, *(double *)(&DAT_004ffcb8 + param_3 * 8) <= _DAT_004cc960)) {
      local_14 = FUN_00488b90(1,param_1,param_2,param_3);
    }
    DAT_00523af4 = DAT_005362d4;
    iVar5 = DAT_004da218;
    if (((DAT_004da19c == 9) && (0x78 < DAT_005362d4)) && (DAT_005362d4 < 0xf0)) {
      local_14 = DAT_004da218;
    }
    if ((DAT_004da19c == 10) && ((0x14a < DAT_005362d4 || (DAT_005362d4 < 0x1e)))) {
      local_14 = DAT_004da218;
    }
    if (param_3 < 3) {
      *(int *)(&DAT_00511378 + param_3 * 4) = local_14;
    }
    local_1c = DAT_00522ad0;
    if (local_14 < iVar5) {
      local_1c = (int)(longlong)
                      (((float10)local_14 / (float10)DAT_004da218) * (float10)(DAT_00522ad0 / 2)) +
                 DAT_00522ad0 / 2;
    }
    if (((DAT_004faf8c < DAT_00535ed0 + -10) && (local_14 < iVar5)) && (DAT_00536450 == 0)) {
      DAT_004fae5c = 1;
      local_1c = (local_1c * 0xd) / 10;
    }
    if ((DAT_005359d8 == 1) && (local_14 < iVar5 / 3)) {
      local_1c = (local_1c * 9) / 10;
    }
    DAT_004f8d74 = 0;
    DAT_004f4528 = 0;
    fVar12 = FUN_0042f330(param_1,param_2,0);
    if ((int)(longlong)fVar12 < (int)(((DAT_004f69b8 < 2) - 1 & 0xffffffc5) + 99)) {
      if ((4 < DAT_004da19c) && (DAT_004da19c < 9)) {
        FUN_00431200(param_1,param_2);
      }
      iVar5 = DAT_005362d4;
      if (DAT_005362d4 < 0x3c) {
        iVar5 = DAT_005362d4 + 0x168;
      }
      uVar9 = iVar5 - DAT_005229c4 >> 0x1f;
      if ((int)((iVar5 - DAT_005229c4 ^ uVar9) - uVar9) < 0x1e) {
        local_1c = (local_1c * 0xc) / 10;
        DAT_004f4528 = 1;
      }
      uVar9 = iVar5 - DAT_004fe160 >> 0x1f;
      if ((int)((iVar5 - DAT_004fe160 ^ uVar9) - uVar9) < 0x1e) {
        local_1c = (local_1c * 8) / 10;
        DAT_004f4528 = -1;
      }
      if ((param_3 == 1) && (DAT_004f4528 != 0)) {
        _DAT_004f7ec8 = 1;
      }
    }
    DAT_0053545c = 0;
    DAT_00534f44 = 0;
    if ((1 < DAT_004f69b8) && (DAT_004f69b8 != 5)) {
      dVar2 = SQRT((double)(param_1 * param_1 + param_2 * param_2));
      iVar5 = FUN_00427ee0(param_1,-param_2);
      uVar9 = iVar5 - DAT_005362d4 >> 0x1f;
      iVar6 = (iVar5 - DAT_005362d4 ^ uVar9) - uVar9;
      cVar1 = iVar6 < 0x5a;
      if (0x10e < iVar6) {
        cVar1 = '\x02';
      }
      DAT_0053545c = 0;
      if (0 < DAT_005364b4) {
        piVar10 = &DAT_004fbac4;
        iVar11 = 0;
        iVar6 = DAT_005364b4;
        do {
          iVar7 = *piVar10;
          uVar9 = DAT_005362d4 - iVar7 >> 0x1f;
          iVar8 = (DAT_005362d4 - iVar7 ^ uVar9) - uVar9;
          if (((((iVar8 < 0x1e) && (cVar1 != '\0')) && (_DAT_004cc9e8 < dVar2)) &&
              ((*(int *)((int)&DAT_004fe134 + iVar11) * 2 + 5 < iVar5 &&
               (iVar5 < *(int *)((int)&DAT_004f8b84 + iVar11) * 2 + -5)))) &&
             (DAT_0053545c = 1, DAT_00523af4 = iVar7, param_3 == 1)) {
            DAT_00534f44 = 1;
          }
          if (((0x14a < iVar8) && (cVar1 != '\0')) &&
             ((_DAT_004cc9e8 < dVar2 &&
              (((*(int *)((int)&DAT_004fe134 + iVar11) * 2 + 5 < iVar5 &&
                (iVar5 < *(int *)((int)&DAT_004f8b84 + iVar11) * 2 + -5)) &&
               (DAT_0053545c = 1, DAT_00523af4 = iVar7, param_3 == 1)))))) {
            DAT_00534f44 = 1;
          }
          iVar11 = iVar11 + 4;
          piVar10 = piVar10 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar6 = 1;
      if (0 < DAT_005364b4) {
        piVar10 = &DAT_004fbac4;
        iVar11 = 0;
        do {
          iVar7 = FUN_0041bc20(*piVar10 + -0xb4);
          uVar9 = DAT_005362d4 - iVar7 >> 0x1f;
          if ((((int)((DAT_005362d4 - iVar7 ^ uVar9) - uVar9) < 0x1e) && (cVar1 == '\0')) &&
             ((_DAT_004cc9f0 < dVar2 &&
              ((*(int *)((int)&DAT_004fe134 + iVar11) * 2 + 5 < iVar5 &&
               (iVar5 < *(int *)((int)&DAT_004f8b84 + iVar11) * 2 + -5)))))) {
            DAT_00523af4 = FUN_0041bc20(*piVar10 + -0xb4);
            DAT_0053545c = 1;
            if (param_3 == 1) {
              DAT_00534f44 = 1;
            }
          }
          iVar7 = FUN_0041bc20(*piVar10 + -0xb4);
          uVar9 = DAT_005362d4 - iVar7 >> 0x1f;
          if ((((0x14a < (int)((DAT_005362d4 - iVar7 ^ uVar9) - uVar9)) && (cVar1 == '\0')) &&
              (_DAT_004cc9f0 < dVar2)) &&
             ((*(int *)((int)&DAT_004fe134 + iVar11) * 2 + 5 < iVar5 &&
              (iVar5 < *(int *)((int)&DAT_004f8b84 + iVar11) * 2 + -5)))) {
            DAT_00523af4 = FUN_0041bc20(*piVar10 + -0xb4);
            DAT_0053545c = 1;
            if (param_3 == 1) {
              DAT_00534f44 = 1;
            }
          }
          iVar6 = iVar6 + 1;
          iVar11 = iVar11 + 4;
          piVar10 = piVar10 + 1;
        } while (iVar6 <= DAT_005364b4);
      }
      if (DAT_004f69b8 == 6) {
        if (((DAT_005362d4 < 0x14) || (0x140 < DAT_005362d4)) &&
           ((param_1 < 0x28a && ((-0x28a < param_1 && (param_2 < -500)))))) {
          DAT_0053545c = 1;
          DAT_00523af4 = 0x15e;
          if (param_3 == 1) {
            DAT_00534f44 = 1;
          }
        }
        else {
          DAT_0053545c = 0;
        }
        if ((((0x8c < DAT_005362d4) && (DAT_005362d4 < 200)) && (param_1 < 0x28a)) &&
           ((-900 < param_1 && (param_2 < -800)))) {
          DAT_0053545c = 1;
          DAT_00523af4 = 0xaa;
          if (param_3 == 1) {
            DAT_00534f44 = 1;
          }
        }
      }
      if (DAT_004f69b8 == 7) {
        if (((DAT_005362d4 < 0xe1) && (0xa5 < DAT_005362d4)) &&
           ((param_1 < 500 && ((-900 < param_1 && (500 < param_2)))))) {
          DAT_0053545c = 1;
          DAT_00523af4 = 0xc3;
          if (param_3 == 1) {
            DAT_00534f44 = 1;
          }
        }
        else {
          DAT_0053545c = 0;
        }
        if ((((-1 < DAT_005362d4) && (DAT_005362d4 < 0x1e)) && (param_1 < 500)) &&
           ((-900 < param_1 && (800 < param_2)))) {
          DAT_0053545c = 1;
          DAT_00523af4 = 0xf;
          if (param_3 == 1) {
            DAT_00534f44 = 1;
          }
        }
      }
    }
    if (local_1c < 7) {
      local_1c = 7;
    }
    DAT_00535e30 = local_1c / 10 + 1;
    if (local_14 < DAT_004da218) {
      DAT_00535e30 = local_1c / 10;
    }
    iVar5 = 0;
    if (DAT_00535e30 < 0) {
      DAT_00535e30 = 0;
    }
    iVar6 = DAT_00535e30;
    if (0 < param_3) {
      uVar9 = *(int *)(&DAT_004fb420 + param_3 * 4) - (&DAT_00522b90)[param_3] >> 0x1f;
      iVar11 = (*(int *)(&DAT_004fb420 + param_3 * 4) - (&DAT_00522b90)[param_3] ^ uVar9) - uVar9;
      if ((iVar11 < 0x5b) || (0x10d < iVar11)) {
        *(undefined4 *)(&DAT_004f69c0 + param_3 * 4) = 0;
      }
      else {
        *(undefined4 *)(&DAT_004f69c0 + param_3 * 4) = 1;
      }
      uVar9 = (int)*(uint *)(&DAT_00535a08 + param_3 * 4) >> 0x1f;
      if (7 < (int)((*(uint *)(&DAT_00535a08 + param_3 * 4) ^ uVar9) - uVar9)) {
        DAT_00535e30 = iVar6 + *(int *)(&DAT_004f69c0 + param_3 * 4);
      }
    }
    dVar2 = (double)param_1;
    iVar6 = 1;
    iVar11 = 0;
    do {
      dVar3 = dVar2 - *(double *)((int)&DAT_00535468 + iVar5);
      dVar4 = (double)param_2 - *(double *)((int)&DAT_004f4b10 + iVar5);
      if ((int)(longlong)SQRT(dVar4 * dVar4 + dVar3 * dVar3) < *(int *)((int)&DAT_004f7ea4 + iVar11)
         ) {
        local_1c = local_1c + *(int *)((int)&DAT_004f71dc + iVar11);
        DAT_004f8d74 = 1;
        if (param_3 == 1) {
          DAT_00522cac = 1;
        }
        param_1 = iVar6;
        if (param_3 == 2) {
          DAT_00522d18 = 1;
        }
      }
      iVar5 = iVar5 + 8;
      iVar6 = iVar6 + 1;
      iVar11 = iVar11 + 4;
    } while (iVar5 < 0x21);
    if (DAT_0053545c == 0) {
      if (DAT_004f8d74 == 1) {
        DAT_00523af4 = *(int *)(&DAT_005357d8 + param_1 * 4);
      }
      else {
        iVar5 = DAT_00522ad0;
        iVar6 = local_1c;
        if (DAT_0053645c == 0) {
          iVar5 = local_1c;
          iVar6 = DAT_00522ad0;
        }
        DAT_00523af4 = DAT_005362d4 + (iVar5 - iVar6) * 3;
      }
      if ((DAT_004f8b78 == 1) && (DAT_00523af4 < 0x7d)) {
        DAT_00523af4 = 0x7d;
      }
    }
    DAT_00523af4 = FUN_0041bc20(DAT_00523af4);
    if ((param_3 == 1) && (local_1c < DAT_00522ad0 + -1)) {
      _DAT_004fb224 = param_3;
    }
    if ((0 < param_3) && (DAT_004f42b8 + 1 < DAT_004f8cd0)) {
      uVar9 = local_c - DAT_00523af4 >> 0x1f;
      if ((int)((local_c - DAT_00523af4 ^ uVar9) - uVar9) < 0xb4) {
        DAT_00523af4 = (DAT_00523af4 + local_c * 4) / 5;
      }
      else {
        if ((0x10e < local_c) && (DAT_00523af4 < 0x5a)) {
          DAT_00523af4 = FUN_0041bc20((DAT_00523af4 + -0x5a0 + local_c * 4) / 5);
        }
        if ((local_c < 0x5a) && (DAT_00523af4 < 0x10e)) {
          DAT_00523af4 = FUN_0041bc20((DAT_00523af4 + -0x168 + local_c * 4) / 5);
        }
      }
    }
    iVar5 = DAT_00523af4;
    (&DAT_004fb380)[param_3] = local_1c;
    (&DAT_00522b90)[param_3] = iVar5;
    return local_1c;
  }
  iVar5 = FUN_00488d70(param_1,param_2,param_3);
  return iVar5;
}

