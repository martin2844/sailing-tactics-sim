
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004391f0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  float10 fVar9;
  float10 fVar10;
  longlong lVar11;
  double local_10;
  
  iVar1 = param_3;
  if ((DAT_004f8cd0 < 3) && (DAT_004da1d8 < 3)) {
    return;
  }
  if (DAT_004f8cd0 < *(int *)(&DAT_004fe9d0 + param_3 * 4) + 3) {
    return;
  }
  if ((*(int *)(&DAT_004f4208 + param_3 * 4) == 1) &&
     (*(int *)(&DAT_00522ff0 + param_3 * 4) == *(int *)(&DAT_00522ff0 + param_2 * 4))) {
    uVar4 = *(int *)(&DAT_004fdfe8 + param_2 * 4) / 2 >> 0x1f;
    *(uint *)(&DAT_004faef0 + param_3 * 4) =
         (*(int *)(&DAT_004fdfe8 + param_2 * 4) / 2 ^ uVar4) - uVar4;
    return;
  }
  lVar11 = 0x40490000;
  if (DAT_004da194 != 2) {
    lVar11 = 0x4052c000;
  }
  local_10 = (double)(lVar11 << 0x20);
  lVar11 = FUN_00464050(param_3,param_2);
  iVar6 = (int)lVar11;
  fVar9 = FUN_00439e80(param_3,(double)DAT_00522acc,(double)DAT_00522ae0);
  if (((fVar9 < (float10)local_10) ||
      (fVar9 = FUN_00439e80(param_3,(double)DAT_005229c8,(double)DAT_00522ac4),
      fVar9 < (float10)local_10)) && (DAT_004f452c == 0)) {
    if (DAT_0053527c != 0) {
      return;
    }
    fVar9 = FUN_00439e80(param_3,(double)DAT_004fe094,(double)DAT_004fe2a0);
    fVar10 = FUN_00439e80(param_2,(double)DAT_004fe094,(double)DAT_004fe2a0);
    if ((float10)(double)fVar9 <= fVar10) {
      return;
    }
    if (0x15 < param_1) {
      return;
    }
    if (DAT_004f8cd0 < 0x1f) {
      return;
    }
    bVar8 = SBORROW4(iVar6,-6);
    iVar5 = iVar6 + 6;
    bVar7 = iVar6 == -6;
LAB_00439447:
    if (bVar7 || bVar8 != iVar5 < 0) {
      return;
    }
    *(int *)(&DAT_004fe9d0 + param_3 * 4) = DAT_004f8cd0;
    *(int *)(&DAT_00535740 + param_3 * 4) =
         *(int *)(&DAT_00535740 + param_2 * 4) + param_4 * DAT_004da214 * 7;
    return;
  }
  fVar9 = FUN_00439e80(param_3,(double)DAT_005229c8,(double)DAT_00522ac4);
  if ((fVar9 < (float10)local_10) && (DAT_0053527c == 1)) {
    fVar9 = FUN_00439e80(param_3,(double)DAT_005229c8,(double)DAT_005229c8);
    fVar10 = FUN_00439e80(param_2,(double)DAT_005229c8,(double)DAT_00522ac4);
    if ((float10)(double)fVar9 <= fVar10) {
      return;
    }
    if (0xf < param_1) {
      return;
    }
    if (DAT_004f8cd0 < 0x1f) {
      return;
    }
    if (iVar6 < -5) {
      return;
    }
    iVar1 = *(int *)(&DAT_004fecc8 + param_3 * 4);
    bVar8 = SBORROW4(iVar1,0x37);
    iVar5 = iVar1 + -0x37;
    bVar7 = iVar1 == 0x37;
    goto LAB_00439447;
  }
  fVar9 = FUN_00439e80(param_3,(double)DAT_004f4a68,(double)DAT_004f6d34);
  if (fVar9 < (float10)local_10) {
LAB_004394f7:
    if ((DAT_004f452c == 1) &&
       (fVar9 = FUN_00439e80(iVar1,(double)DAT_005229c8,(double)DAT_00522ac4),
       fVar9 < (float10)_DAT_004cc498)) {
      dVar3 = (double)DAT_005229c8;
      fVar9 = FUN_00439e80(iVar1,(double)DAT_005229c8,(double)DAT_00522ac4);
      fVar10 = FUN_00439e80(param_2,dVar3,dVar3);
      if (fVar10 <= (float10)(double)fVar9) {
        return;
      }
      fVar9 = FUN_00439e80(iVar1,(double)DAT_00523248,(double)DAT_0052359c);
      fVar10 = FUN_00439e80(iVar1,(double)DAT_004f4a68,(double)DAT_004f6d34);
      iVar6 = DAT_004f8cd0;
      if (fVar10 <= (float10)(double)fVar9) {
        iVar5 = *(int *)(&DAT_00535740 + param_2 * 4) + param_4 * -7;
      }
      else {
        iVar5 = *(int *)(&DAT_00535740 + param_2 * 4) + param_4 * 7;
      }
      *(int *)(&DAT_00535740 + iVar1 * 4) = iVar5;
      *(int *)(&DAT_004fe9d0 + iVar1 * 4) = iVar6;
      return;
    }
  }
  else {
    param_3 = (int)((double)DAT_0052359c < local_10);
    fVar9 = FUN_00439e80(iVar1,(double)DAT_00523248,(double)param_3);
    if (fVar9 != (float10)_DAT_004cc658) goto LAB_004394f7;
  }
  if (((DAT_005363bc == 1) || (DAT_005363b8 == 1)) || (iVar6 = -5, DAT_005363c4 == 1)) {
    iVar6 = -2;
  }
  if (*(int *)(&DAT_004f8300 + iVar1 * 4) < 200) {
    iVar6 = iVar6 + 2;
  }
  iVar5 = iVar6 + 5;
  if (DAT_004f8cd0 < 1) {
    iVar5 = -5;
  }
  else {
    uVar4 = (int)*(uint *)(&DAT_00534f50 + iVar1 * 4) >> 0x1f;
    if ((int)((*(uint *)(&DAT_00534f50 + iVar1 * 4) ^ uVar4) - uVar4) < 0xf) {
      iVar5 = iVar6 + 0xf;
    }
  }
  if (*(int *)(&DAT_00522ff0 + iVar1 * 4) == -1) {
    if (((*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) &&
        (lVar11 = FUN_00439ec0(param_2,0,iVar1), iVar2 = DAT_00536470, iVar6 = DAT_004f8cd0,
        iVar5 <= (int)lVar11)) &&
       ((*(int *)(&DAT_004fecc8 + iVar1 * 4) < 0x38 &&
        ((*(int *)(&DAT_004f4350 + iVar1 * 4) + 10 < DAT_004f8cd0 &&
         (*(int *)(&DAT_004fe6d0 + iVar1 * 4) == 0)))))) {
      bVar7 = DAT_00536470 == 0;
      *(undefined4 *)(&DAT_00522ff0 + iVar1 * 4) = 1;
      if ((bVar7) || (DAT_00536474 == 1)) {
        iVar5 = (&DAT_00522b90)[iVar1] + -0xf;
      }
      else {
        iVar5 = (&DAT_00522b90)[iVar1] - DAT_004f7200;
      }
      *(int *)(&DAT_00535740 + iVar1 * 4) = iVar5;
      *(int *)(&DAT_004fe9d0 + iVar1 * 4) = iVar6;
      *(undefined4 *)(&DAT_00522e68 + iVar1 * 4) = 0;
      *(int *)(&DAT_004f4350 + iVar1 * 4) = iVar6 + -5;
      *(undefined4 *)(&DAT_004f4a70 + iVar1 * 4) = 1;
      if (iVar2 != 1) {
        return;
      }
      if (iVar1 != 2) {
        return;
      }
      if (param_2 != 1) {
        return;
      }
      _DAT_004da1a0 = 0xfffffff9;
      _DAT_004da1a4 = iVar6;
      DAT_004f6de4 = 1000;
      return;
    }
    if (*(int *)(&DAT_00522ff0 + iVar1 * 4) == -1) {
      if ((((*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) &&
           (lVar11 = FUN_00439ec0(param_2,0,iVar1), (int)lVar11 < iVar5)) &&
          (lVar11 = FUN_00439ec0(param_2,0,iVar1), iVar5 + -3 <= (int)lVar11)) &&
         (*(int *)(&DAT_004fecc8 + iVar1 * 4) < 0x38)) {
        iVar6 = *(int *)(&DAT_00535740 + iVar1 * 4) + 0x4b;
      }
      else {
        if (((*(int *)(&DAT_00522ff0 + iVar1 * 4) != -1) ||
            (*(int *)(&DAT_00522ff0 + param_2 * 4) != 1)) ||
           ((lVar11 = FUN_00439ec0(param_2,0,iVar1), iVar5 + -3 <= (int)lVar11 ||
            (0x37 < *(int *)(&DAT_004fecc8 + iVar1 * 4))))) goto LAB_00439867;
        iVar6 = *(int *)(&DAT_00535740 + iVar1 * 4) + 0x2d;
      }
      iVar2 = DAT_00536470;
      iVar5 = DAT_004f8cd0;
      *(int *)(&DAT_00535740 + iVar1 * 4) = iVar6;
      *(int *)(&DAT_004fe9d0 + iVar1 * 4) = iVar5;
      *(undefined4 *)(&DAT_00522e68 + iVar1 * 4) = 0;
      *(undefined4 *)(&DAT_004fe6d0 + iVar1 * 4) = 1;
      if (iVar2 != 1) {
        return;
      }
      if (iVar1 != 2) {
        return;
      }
      _DAT_004da1a0 = 0xfffffffe;
      _DAT_004da1a4 = iVar5;
      return;
    }
  }
LAB_00439867:
  lVar11 = FUN_00439ec0(param_2,1,iVar1);
  iVar6 = DAT_004f8cd0;
  if ((DAT_004da19c != 8) || (iVar5 = 10, 99 < DAT_004f8cd0)) {
    iVar5 = 0xf;
  }
  iVar2 = *(int *)(&DAT_00522ff0 + iVar1 * 4);
  if ((((iVar2 == *(int *)(&DAT_00522ff0 + param_2 * 4)) && (0 < (int)lVar11)) &&
      (*(int *)(&DAT_004fecc8 + param_2 * 4) <= *(int *)(&DAT_004fecc8 + iVar1 * 4))) &&
     (param_1 < iVar5)) {
    if (DAT_004f8cd0 < 0x1e) {
      *(int *)(&DAT_00535740 + iVar1 * 4) = *(int *)(&DAT_00535740 + iVar1 * 4) + iVar2 * 10;
    }
    else {
      *(int *)(&DAT_00535740 + iVar1 * 4) = *(int *)(&DAT_00535740 + param_2 * 4) + iVar2 * 10;
    }
    iVar5 = DAT_00536470;
    *(int *)(&DAT_004fe9d0 + iVar1 * 4) = iVar6;
    if (iVar5 != 1) {
      return;
    }
    if (iVar1 != 2) {
      return;
    }
    _DAT_004da1a0 = 0xfffffffc;
    _DAT_004da1a4 = iVar6;
    return;
  }
  if (*(int *)(&DAT_004fecc8 + iVar1 * 4) < 0x38) {
    return;
  }
  if (iVar2 != -1) {
    return;
  }
  if (*(int *)(&DAT_00522ff0 + param_2 * 4) != 1) {
    return;
  }
  lVar11 = FUN_00464050(iVar1,param_2);
  if (*(int *)(&DAT_004fecc8 + param_2 * 4) < 0x5b) {
    _DAT_004da1a0 = 0xfffffffc;
    *(int *)(&DAT_004fe9d0 + iVar1 * 4) = DAT_004f8cd0;
    *(int *)(&DAT_00535740 + iVar1 * 4) =
         *(int *)(&DAT_00535740 + iVar1 * 4) + *(int *)(&DAT_00522ff0 + iVar1 * 4) * 0x28;
    return;
  }
  if ((int)lVar11 < 1) {
    iVar6 = FUN_0041bc20(*(int *)(&DAT_004fae60 + iVar1 * 4) + 0xb4 + (&DAT_00522b90)[iVar1]);
    *(int *)(&DAT_00535740 + iVar1 * 4) = iVar6;
    _DAT_004da1a0 = 0xfffffff0;
    *(int *)(&DAT_004fe9d0 + iVar1 * 4) = DAT_004f8cd0;
    return;
  }
  _DAT_004da1a0 = 0xfffffffc;
  *(int *)(&DAT_00535740 + iVar1 * 4) =
       *(int *)(&DAT_00535740 + iVar1 * 4) + *(int *)(&DAT_00522ff0 + iVar1 * 4) * 0x28;
  *(int *)(&DAT_004fe9d0 + iVar1 * 4) = DAT_004f8cd0;
  return;
}

