
void __cdecl FUN_004280c0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  float10 fVar7;
  float10 fVar8;
  longlong lVar9;
  double local_8;
  
  if ((0 < DAT_004ac9ac) && (DAT_004a5b80 < 3)) {
    return;
  }
  if ((DAT_004a5b80 < 3) && (DAT_004911cc < 3)) {
    return;
  }
  bVar5 = DAT_004ac9a8 != 1;
  if (DAT_004a5b80 < *(int *)(&DAT_004a7970 + param_3 * 4) + 3) {
    return;
  }
  if ((*(int *)(&DAT_004a40d0 + param_3 * 4) == 1) &&
     (*(int *)(&DAT_004aa730 + param_3 * 4) == *(int *)(&DAT_004aa730 + param_2 * 4))) {
    uVar2 = *(int *)(&DAT_004a7060 + param_2 * 4) / 2 >> 0x1f;
    bVar5 = DAT_004ac9ac != 1;
    *(uint *)(&DAT_004a5f90 + param_3 * 4) =
         (*(int *)(&DAT_004a7060 + param_2 * 4) / 2 ^ uVar2) - uVar2;
    if (bVar5) {
      return;
    }
    if (param_3 != 2) {
      return;
    }
    DAT_00491198 = 0xfffffff8;
    return;
  }
  lVar9 = 0x40490000;
  if (DAT_0049118c != 2) {
    lVar9 = 0x4052c000;
  }
  local_8 = (double)(lVar9 << 0x20);
  lVar9 = FUN_0044da90(param_3,param_2);
  fVar7 = FUN_00428ab0(param_3,(double)DAT_004aa38c,(double)DAT_004aa588);
  if ((fVar7 < (float10)local_8) ||
     (fVar7 = FUN_00428ab0(param_3,(double)DAT_004aa288,(double)DAT_004aa384),
     fVar7 < (float10)local_8)) {
    fVar7 = FUN_00428ab0(param_3,(double)DAT_004a70f8,(double)DAT_004a72c8);
    fVar8 = FUN_00428ab0(param_2,(double)DAT_004a70f8,(double)DAT_004a72c8);
    iVar3 = DAT_004a5b80;
    if ((float10)(double)fVar7 <= fVar8) {
      return;
    }
    if (0x15 < param_1) {
      return;
    }
    if (DAT_004a5b80 < 0x1f) {
      return;
    }
    if ((int)lVar9 < -5) {
      return;
    }
    iVar4 = *(int *)(&DAT_004ac018 + param_2 * 4);
    *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
    bVar6 = DAT_004ac9ac != 1;
    *(uint *)(&DAT_004ac018 + param_3 * 4) = iVar4 + ((-(uint)bVar5 & 2) - 1) * param_4 * 7;
    if (bVar6) {
      return;
    }
    if (param_3 != 2) {
      return;
    }
    DAT_00491198 = 0xfffffffd;
    DAT_0049119c = iVar3;
    return;
  }
  if (((DAT_004ac904 == 1) || (DAT_004ac900 == 1)) || (iVar3 = -5, DAT_004ac90c == 1)) {
    iVar3 = -2;
  }
  if (*(int *)(&DAT_004a5268 + param_3 * 4) < 200) {
    iVar3 = iVar3 + 2;
  }
  iVar4 = iVar3 + 5;
  if (DAT_004a5b80 < 1) {
    iVar4 = -5;
  }
  else {
    uVar2 = (int)*(uint *)(&DAT_004aba68 + param_3 * 4) >> 0x1f;
    if ((int)((*(uint *)(&DAT_004aba68 + param_3 * 4) ^ uVar2) - uVar2) < 0xf) {
      iVar4 = iVar3 + 0xf;
    }
  }
  if ((((*(int *)(&DAT_004aa730 + param_3 * 4) == -1) &&
       (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) &&
      ((lVar9 = FUN_00428af0(param_2,0,param_3), iVar1 = DAT_004ac9ac, iVar3 = DAT_004a5b80,
       iVar4 <= (int)lVar9 &&
       ((*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38 &&
        (*(int *)(&DAT_004a41f0 + param_3 * 4) + 10 < DAT_004a5b80)))))) &&
     (*(int *)(&DAT_004a76d0 + param_3 * 4) == 0)) {
    bVar5 = DAT_004ac9ac == 0;
    *(undefined4 *)(&DAT_004aa730 + param_3 * 4) = 1;
    if ((bVar5) || (DAT_004ac9b0 == 1)) {
      iVar4 = *(int *)(&DAT_004aa5b0 + param_3 * 4) + -0xf;
    }
    else {
      iVar4 = *(int *)(&DAT_004aa5b0 + param_3 * 4) - DAT_004a4eb0;
    }
    *(int *)(&DAT_004ac018 + param_3 * 4) = iVar4;
    *(int *)(&DAT_004a7970 + param_3 * 4) = iVar3;
    *(undefined4 *)(&DAT_004aa660 + param_3 * 4) = 0;
    *(int *)(&DAT_004a41f0 + param_3 * 4) = iVar3 + -5;
    *(undefined4 *)(&DAT_004a46a8 + param_3 * 4) = 1;
    if (iVar1 != 1) {
      return;
    }
    if (param_3 != 2) {
      return;
    }
    if (param_2 != 1) {
      return;
    }
    DAT_00491198 = 0xfffffff9;
    DAT_0049119c = iVar3;
    DAT_004a4c6c = 1000;
    return;
  }
  if (*(int *)(&DAT_004aa730 + param_3 * 4) == -1) {
    if ((((*(int *)(&DAT_004aa730 + param_2 * 4) == 1) &&
         (lVar9 = FUN_00428af0(param_2,0,param_3), (int)lVar9 < iVar4)) &&
        (lVar9 = FUN_00428af0(param_2,0,param_3), iVar4 + -3 <= (int)lVar9)) &&
       (*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38)) {
      iVar3 = *(int *)(&DAT_004ac018 + param_3 * 4) + 0x55;
    }
    else {
      if (((*(int *)(&DAT_004aa730 + param_3 * 4) != -1) ||
          (*(int *)(&DAT_004aa730 + param_2 * 4) != 1)) ||
         ((lVar9 = FUN_00428af0(param_2,0,param_3), iVar4 + -3 <= (int)lVar9 ||
          (0x37 < *(int *)(&DAT_004a7bc8 + param_3 * 4))))) goto LAB_0042846b;
      iVar3 = *(int *)(&DAT_004ac018 + param_3 * 4) + 0x37;
    }
    iVar1 = DAT_004ac9ac;
    iVar4 = DAT_004a5b80;
    *(int *)(&DAT_004ac018 + param_3 * 4) = iVar3;
    *(int *)(&DAT_004a7970 + param_3 * 4) = iVar4;
    *(undefined4 *)(&DAT_004aa660 + param_3 * 4) = 0;
    *(undefined4 *)(&DAT_004a76d0 + param_3 * 4) = 1;
    if ((iVar1 == 1) && (param_3 == 2)) {
      DAT_00491198 = 0xfffffffe;
      DAT_0049119c = iVar4;
      return;
    }
  }
  else {
LAB_0042846b:
    lVar9 = FUN_00428af0(param_2,1,param_3);
    iVar3 = DAT_004a5b80;
    if ((DAT_00491194 != 8) || (iVar4 = 10, 99 < DAT_004a5b80)) {
      iVar4 = 0xf;
    }
    iVar1 = *(int *)(&DAT_004aa730 + param_3 * 4);
    if ((((iVar1 == *(int *)(&DAT_004aa730 + param_2 * 4)) && (0 < (int)lVar9)) &&
        (*(int *)(&DAT_004a7bc8 + param_2 * 4) <= *(int *)(&DAT_004a7bc8 + param_3 * 4))) &&
       (param_1 < iVar4)) {
      if (DAT_004a5b80 < 0x1e) {
        *(int *)(&DAT_004ac018 + param_3 * 4) = *(int *)(&DAT_004ac018 + param_3 * 4) + iVar1 * 10;
      }
      else {
        *(int *)(&DAT_004ac018 + param_3 * 4) = *(int *)(&DAT_004ac018 + param_2 * 4) + iVar1 * 10;
      }
      iVar4 = DAT_004ac9ac;
      *(int *)(&DAT_004a7970 + param_3 * 4) = iVar3;
      if ((iVar4 == 1) && (param_3 == 2)) {
        DAT_00491198 = 0xfffffffc;
        DAT_0049119c = iVar3;
        return;
      }
    }
    else if (((0x37 < *(int *)(&DAT_004a7bc8 + param_3 * 4)) && (iVar1 == -1)) &&
            (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) {
      lVar9 = FUN_0044da90(param_3,param_2);
      if (*(int *)(&DAT_004a7bc8 + param_2 * 4) < 0x5b) {
        DAT_00491198 = 0xfffffffc;
        *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
        *(int *)(&DAT_004ac018 + param_3 * 4) =
             *(int *)(&DAT_004ac018 + param_3 * 4) + *(int *)(&DAT_004aa730 + param_3 * 4) * 0x28;
        return;
      }
      if (0 < (int)lVar9) {
        DAT_00491198 = 0xfffffffc;
        *(int *)(&DAT_004ac018 + param_3 * 4) =
             *(int *)(&DAT_004ac018 + param_3 * 4) + *(int *)(&DAT_004aa730 + param_3 * 4) * 0x28;
        *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
        return;
      }
      iVar3 = FUN_00413cb0(*(int *)(&DAT_004a5f10 + param_3 * 4) + 0xb4 +
                           *(int *)(&DAT_004aa5b0 + param_3 * 4));
      *(int *)(&DAT_004ac018 + param_3 * 4) = iVar3;
      DAT_00491198 = 0xfffffff0;
      *(int *)(&DAT_004a7970 + param_3 * 4) = DAT_004a5b80;
      return;
    }
  }
  return;
}

