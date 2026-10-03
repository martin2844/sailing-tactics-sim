
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

int __cdecl FUN_00435fe0(int param_1,int param_2,int param_3)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar2 = *(undefined4 *)(&DAT_00522ff0 + param_3 * 4);
  iVar3 = *(int *)(&DAT_00535740 + param_3 * 4);
  uVar10 = (&DAT_00522b90)[param_3] - param_1 >> 0x1f;
  iVar6 = FUN_0041bc20(((&DAT_00522b90)[param_3] - param_1 ^ uVar10) - uVar10);
  iVar6 = FUN_0041bc20(iVar6);
  if (0xb4 < iVar6) {
    iVar6 = 0x168 - iVar6;
  }
  *(int *)(&DAT_00535178 + param_3 * 4) = iVar6;
  if (((0 < *(int *)(&DAT_004f7f98 + param_3 * 4)) && (*(int *)(&DAT_00522ff0 + param_3 * 4) == 1))
     && (*(int *)(&DAT_004fecc8 + param_3 * 4) < param_2 + 5)) {
    *(int *)(&DAT_00535740 + param_3 * 4) = iVar3;
    return iVar6;
  }
  if ((iVar6 < 0x47) || (DAT_004f8cd0 < 10)) {
    if (param_2 < iVar6) {
      *(int *)(&DAT_00535740 + param_3 * 4) = param_1;
    }
  }
  else {
    iVar7 = FUN_00436400(iVar6,param_1,param_3);
    if (iVar7 < 0) {
      if (((DAT_005363b8 == 0) && (DAT_005363c4 == 0)) &&
         ((DAT_005363c0 == 0 &&
          (((DAT_004da190 != 8 && (DAT_005363bc == 0)) && (DAT_0053652c == 0)))))) {
        iVar8 = *(int *)(&DAT_004fae60 + param_3 * 4) + -2 +
                *(int *)(&DAT_004fadd0 + param_3 * 4) / 2;
      }
      else {
        iVar8 = *(int *)(&DAT_004fae60 + param_3 * 4) + -3 +
                ((int)(*(int *)(&DAT_004fadd0 + param_3 * 4) +
                      (*(int *)(&DAT_004fadd0 + param_3 * 4) >> 0x1f & 3U)) >> 2);
      }
      if (iVar8 < 2) {
        iVar8 = 1;
      }
      if ((iVar7 == -10) && (DAT_004f8cd0 - *(int *)(&DAT_00522dd0 + param_3 * 4) < 10)) {
        iVar8 = iVar8 + 10;
      }
      if (*(int *)(&DAT_004f4530 + param_3 * 4) == 1) {
        iVar8 = 3;
      }
      iVar7 = FUN_0041bc20(iVar8 * *(int *)(&DAT_00522ff0 + param_3 * 4) + 0xb4 +
                           (&DAT_00522b90)[param_3]);
      *(int *)(&DAT_00535740 + param_3 * 4) = iVar7;
    }
    else {
      *(int *)(&DAT_00535740 + param_3 * 4) =
           iVar7 * *(int *)(&DAT_00522ff0 + param_3 * 4) + param_1;
    }
  }
  iVar9 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_3 * 4));
  iVar8 = DAT_004f8cd0;
  iVar7 = DAT_004da170;
  *(int *)(&DAT_00535740 + param_3 * 4) = iVar9;
  if ((iVar8 <= iVar7) && (DAT_004da194 == 2)) {
    return iVar6;
  }
  iVar7 = *(int *)(&DAT_004fecc8 + param_3 * 4);
  if ((((iVar7 < 0x46) &&
       (uVar10 = iVar9 - iVar3 >> 0x1f, iVar9 = (iVar9 - iVar3 ^ uVar10) - uVar10, 0x41 < iVar9)) &&
      (iVar9 < 0xb4)) &&
     ((*(int *)(&DAT_00522e68 + param_3 * 4) == 0 &&
      (*(int *)(&DAT_004f4350 + param_3 * 4) + 8 < iVar8)))) {
    *(undefined4 *)(&DAT_00522e68 + param_3 * 4) = *(undefined4 *)(&DAT_00522ff0 + param_3 * 4);
    uVar4 = *(undefined4 *)(&DAT_004ffcb8 + param_3 * 8);
    *(undefined4 *)(&DAT_00522ff0 + param_3 * 4) = uVar2;
    *(undefined4 *)(&DAT_004f4888 + param_3 * 8) = uVar4;
    *(undefined4 *)(&DAT_004f488c + param_3 * 8) = *(undefined4 *)(&DAT_004ffcbc + param_3 * 8);
    uVar2 = *(undefined4 *)(&DAT_005125fc + param_3 * 8);
    *(undefined4 *)(&DAT_00523478 + param_3 * 8) = *(undefined4 *)(&DAT_005125f8 + param_3 * 8);
    *(int *)(&DAT_004f4350 + param_3 * 4) = iVar8;
    *(int *)(&DAT_00535740 + param_3 * 4) = iVar3;
    *(undefined4 *)(&DAT_0052347c + param_3 * 8) = uVar2;
  }
  iVar3 = DAT_004da1f8;
  if (DAT_004da1f8 == 0) {
    iVar9 = (-(uint)(DAT_004f8b78 != 1) & 0xfffffffe) + 1;
    dVar5 = (double)(int)(((DAT_004f69b8 < 2) - 1 & 0xffffffe7) + 0x28);
    if ((*(double *)(&DAT_004ffcb8 + param_3 * 8) < dVar5) && (param_2 + 5 < iVar7)) {
      *(int *)(&DAT_00535740 + param_3 * 4) =
           *(int *)(&DAT_00535740 + param_3 * 4) +
           (int)(longlong)(dVar5 - *(double *)(&DAT_004ffcb8 + param_3 * 8)) * iVar9 * 2;
    }
    if ((*(double *)(&DAT_004f4888 + param_3 * 8) < dVar5) &&
       (param_2 + 5 < *(int *)(&DAT_004fecc8 + param_3 * 4))) {
      *(int *)(&DAT_00535740 + param_3 * 4) =
           *(int *)(&DAT_00535740 + param_3 * 4) +
           (int)(longlong)(dVar5 - *(double *)(&DAT_004f4888 + param_3 * 8)) * iVar9 * 2;
    }
  }
  if (0 < iVar3) {
    iVar7 = DAT_004da214;
    if (iVar3 != 5) {
      iVar7 = -1;
    }
    dVar5 = (double)*(int *)(&DAT_005232e8 + param_3 * 4);
    if ((*(double *)(&DAT_005125f8 + param_3 * 8) < dVar5) &&
       (param_2 + 5 < *(int *)(&DAT_004fecc8 + param_3 * 4))) {
      dVar1 = *(double *)(&DAT_005125f8 + param_3 * 8);
      *(int *)(&DAT_004fad40 + param_3 * 4) = param_3 + 10 + iVar8;
      *(int *)(&DAT_00535740 + param_3 * 4) =
           *(int *)(&DAT_00535740 + param_3 * 4) + (int)(longlong)(dVar5 - dVar1) * iVar7 * 2;
    }
    if ((*(double *)(&DAT_00523478 + param_3 * 8) < dVar5) &&
       (param_2 + 5 < *(int *)(&DAT_004fecc8 + param_3 * 4))) {
      *(int *)(&DAT_00535740 + param_3 * 4) =
           *(int *)(&DAT_00535740 + param_3 * 4) +
           (int)(longlong)(dVar5 - *(double *)(&DAT_00523478 + param_3 * 8)) * iVar7 * 2;
      *(int *)(&DAT_004fad40 + param_3 * 4) = param_3 + 10 + iVar8;
      return iVar6;
    }
  }
  return iVar6;
}

