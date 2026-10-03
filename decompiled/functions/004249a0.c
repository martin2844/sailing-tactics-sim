
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_004249a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  bool bVar13;
  float10 fVar14;
  
  iVar2 = param_1;
  if (((DAT_0049119c + 7 < DAT_004a5b80) && (DAT_004ac9ac == 1)) && (param_1 == 2)) {
    DAT_00491198 = 1000;
  }
  iVar5 = *(int *)(&DAT_004ac018 + param_1 * 4);
  if ((DAT_0049118c == 2) && (param_1 == 2)) {
    FUN_0044da90(2,1);
  }
  iVar4 = DAT_00491188;
  iVar3 = *(int *)(&DAT_004a6338 + param_1 * 4);
  if ((iVar3 < 0xc) && (2 < DAT_00491188)) {
    *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x21;
  }
  else {
    *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x14;
  }
  if (iVar4 == 1) {
    *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 5;
  }
  if (iVar4 == 2) {
    *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0xc;
  }
  iVar11 = DAT_004ac90c;
  if ((iVar4 == 3) && (DAT_004ac90c == 0)) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((0xb < iVar3) - 1 & 0x11) + 0x19;
  }
  if ((iVar4 == 4) || (iVar4 == 5)) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((0xd < iVar3) - 1 & 7) + 8;
  }
  if (iVar4 == 6) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((0xd < iVar3) - 1 & 10) + 10;
  }
  if ((DAT_004ac900 == 1) || (iVar11 == 1)) {
    if (((iVar3 < 10) && (*(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x2d, iVar3 < 10)) ||
       (0xd < iVar3)) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x24;
    }
    else {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x29;
    }
    if (iVar4 == 10) {
      *(int *)(&DAT_004a5f10 + param_1 * 4) = *(int *)(&DAT_004a5f10 + param_1 * 4) + 1;
    }
  }
  iVar11 = DAT_004ac908;
  if ((iVar4 == 7) && (DAT_004ac908 == 0)) {
    if (iVar3 < 0xc) {
      iVar7 = *(int *)(&DAT_004a5f10 + param_1 * 4) + -3;
    }
    else {
      iVar7 = *(int *)(&DAT_004a5f10 + param_1 * 4) + -5;
    }
    *(int *)(&DAT_004a5f10 + param_1 * 4) = iVar7;
  }
  if (0x10 < iVar3) {
    *(int *)(&DAT_004a5f10 + param_1 * 4) = *(int *)(&DAT_004a5f10 + param_1 * 4) + -3;
  }
  if (iVar4 == 8) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((0xd < iVar3) - 1 & 5) + 0x21;
  }
  if (iVar11 == 1) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((0xd < iVar3) - 1 & 9) + 0x1f;
  }
  if (DAT_004ac904 == 1) {
    *(uint *)(&DAT_004a5f10 + param_1 * 4) = ((10 < iVar3) - 1 & 0xfffffff6) + 0x32;
    if (iVar3 < 8) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x23;
    }
    if (0xd < iVar3) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x28;
    }
    if (0x12 < iVar3) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x23;
    }
  }
  iVar11 = DAT_004ac9ac;
  if ((DAT_004ac9ac == 1) && (iVar4 == 7)) {
    if (iVar3 < 9) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x25;
    }
    if ((iVar3 < 0xb) && (8 < iVar3)) {
      *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x22;
    }
    if (iVar3 < 0xe) {
      if (10 < iVar3) {
        *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 0x16;
      }
      if (iVar3 < 0xe) goto LAB_00424c0b;
    }
    *(undefined4 *)(&DAT_004a5f10 + param_1 * 4) = 10;
  }
LAB_00424c0b:
  DAT_004aa834 = ((0 < DAT_004a5b80) - 1 & 0x104) + 0x28;
  if (((DAT_004a60a0 == 1) || (DAT_004a5b80 < DAT_004a4168 + 0x14)) || (iVar11 == 1)) {
    iVar3 = FUN_00426150((int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8),
                         (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8),param_1);
    uVar1 = DAT_004ac4d8;
    iVar4 = DAT_00491188;
    *(int *)(&DAT_004a6338 + param_1 * 4) = iVar3;
    *(undefined4 *)(&DAT_004aa5b0 + param_1 * 4) = DAT_004aaeac;
    *(undefined4 *)(&DAT_004ac4e8 + param_1 * 4) = uVar1;
  }
  if ((DAT_004a8914 == 1) && (param_1 == 1)) {
    FUN_004269d0(1);
    _DAT_004a78e8 = (double)DAT_004ac01c;
    iVar4 = DAT_00491188;
  }
  if (DAT_004a8918 == 1) {
    if (param_1 == 2) {
      if (DAT_00491140 == 2) {
        FUN_004269d0(2);
        iVar4 = DAT_00491188;
      }
      goto LAB_00424cdc;
    }
  }
  else {
LAB_00424cdc:
    if (((param_1 == 2) && (DAT_004a4970 == 1)) && (DAT_00491140 == 2)) {
      DAT_004ac020 = FUN_00413cb0(DAT_004aa5b8 - (0xb4 - DAT_004a5f18) * DAT_004aa738);
      iVar4 = DAT_00491188;
    }
  }
  if (param_1 <= DAT_00491140) {
    *(undefined4 *)(&DAT_004abe70 + param_1 * 4) = *(undefined4 *)(&DAT_004aa730 + param_1 * 4);
    FUN_004255b0(param_1);
    iVar4 = DAT_00491188;
  }
  iVar3 = *(int *)(&DAT_004a6338 + param_1 * 4);
  bVar13 = DAT_004ac900 == 0;
  *(undefined4 *)(&DAT_004a4398 + param_1 * 4) = 0;
  iVar11 = DAT_00491140;
  if (bVar13) {
    iVar7 = (int)((ulonglong)((longlong)iVar3 * 0x55555555) >> 0x20) - iVar3;
    DAT_004a4eb0 = (((iVar7 >> 1) - (iVar7 >> 0x1f)) - iVar4 / 6) + 0x2d;
  }
  else {
    DAT_004a4eb0 = 0x2e - ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3);
  }
  if (iVar4 == 3) {
    DAT_004a4eb0 = DAT_004a4eb0 + 2;
  }
  if (iVar4 == 7) {
    DAT_004a4eb0 = DAT_004a4eb0 + -2;
  }
  if (iVar4 == 8) {
    DAT_004a4eb0 = DAT_004a4eb0 + -6;
  }
  if (DAT_004ac904 == 1) {
    DAT_004a4eb0 = 0x37;
  }
  if (((iVar4 < 7) || (DAT_004ac900 == 1)) || (DAT_004ac908 == 1)) {
    if (iVar3 < 0xb) {
      DAT_004a4eb0 = DAT_004a4eb0 + 3;
    }
    if (iVar3 < 8) {
      DAT_004a4eb0 = DAT_004a4eb0 + 3;
    }
  }
  if ((((DAT_00491164 == 1) || (DAT_00491164 == 4)) || (DAT_00491164 == 2)) && (10 < DAT_004ac95c))
  {
    DAT_004ac93c = 10;
  }
  if ((0 < DAT_00491164) && (0x104 < DAT_004a5b80)) {
    DAT_004ac93c = 1;
  }
  uVar6 = *(int *)(&DAT_004a4888 + param_1 * 4) -
          (int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8);
  uVar8 = (int)uVar6 >> 0x1f;
  uVar9 = *(int *)(&DAT_004a6f48 + param_1 * 4) -
          (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8);
  uVar10 = (int)uVar9 >> 0x1f;
  *(uint *)(&DAT_004a5268 + param_1 * 4) = ((uVar6 ^ uVar8) - uVar8) + ((uVar9 ^ uVar10) - uVar10);
  if ((param_1 <= iVar11) || (iVar3 = DAT_004aa834, DAT_004a5b80 < 1)) {
    iVar3 = 300;
  }
  if (((((DAT_004a5b80 < 0x1f) && (-4 < DAT_004a5b80)) &&
       (*(int *)(&DAT_004a5420 + param_1 * 4) == 0)) &&
      ((DAT_004ac9ac == 0 &&
       (FUN_0042c400((double)((DAT_004a70f8 + DAT_004aa594) / 2),
                     (double)((DAT_004aa59c + DAT_004a72c8) / 2),0,param_1),
       *(int *)(&DAT_004a5268 + param_1 * 4) < iVar3)))) &&
     ((int)(longlong)_DAT_004a6828 < DAT_004aa998 / 2)) {
    DAT_004a495c = 0;
    FUN_00426ad0(param_1);
  }
  if ((DAT_004a5b80 < 0x1f) || (iVar3 <= *(int *)(&DAT_004a5268 + param_1 * 4))) {
LAB_00424f9a:
    iVar3 = *(int *)(&DAT_004a5420 + param_1 * 4);
  }
  else {
    iVar3 = *(int *)(&DAT_004a5420 + param_1 * 4);
    if (iVar3 < 8) {
      DAT_004a495c = 0;
      FUN_00426ad0(param_1);
      goto LAB_00424f9a;
    }
  }
  if (((iVar3 == 8) &&
      (*(int *)(&DAT_004a5268 + param_1 * 4) <
       (int)(DAT_004aa998 * 3 + (DAT_004aa998 * 3 >> 0x1f & 3U)) >> 2)) &&
     (fVar14 = FUN_00426f50(param_1), fVar14 <= (float10)_DAT_00484ea8)) {
    DAT_004a495c = 0;
    FUN_00426ad0(param_1);
  }
  iVar3 = DAT_004a5b80 * 0x66666667;
  if ((DAT_004a5b80 / 5 < DAT_004a5b80 - DAT_004ab8b4) &&
     (iVar3 = 8, *(int *)(&DAT_004a5420 + param_1 * 4) < 9)) {
    *(undefined4 *)(&DAT_004a5420 + param_1 * 4) = 8;
    DAT_004a495c = 1;
    iVar3 = FUN_00426ad0(param_1);
  }
  if (0 < DAT_004911a0) {
    if (DAT_00491140 < param_1) goto LAB_00425059;
    iVar3 = FUN_00427fd0(param_1);
  }
  if (param_1 <= DAT_00491140) {
    return iVar3;
  }
LAB_00425059:
  iVar4 = FUN_0041bb10(*(int *)(&DAT_004a4888 + param_1 * 4) -
                       (int)(longlong)*(double *)(&DAT_004a49e8 + param_1 * 8),
                       (int)(longlong)*(double *)(&DAT_004a4ae0 + param_1 * 8) -
                       *(int *)(&DAT_004a6f48 + param_1 * 4));
  iVar3 = iVar5;
  if ((*(int *)(&DAT_004aa660 + param_1 * 4) == 0) && (*(int *)(&DAT_004a76d0 + param_1 * 4) == 0))
  {
    iVar3 = FUN_00425600(iVar4,DAT_004a4eb0,param_1);
  }
  iVar7 = DAT_004a5b80;
  iVar11 = DAT_004a4eb0;
  if (((DAT_004a4eb0 < iVar3) || (*(int *)(&DAT_004aa660 + param_1 * 4) != 0)) ||
     (*(int *)(&DAT_004a76d0 + param_1 * 4) != 0)) {
    if ((param_1 == 2) && (DAT_0049118c == 2)) {
      DAT_004ac9b8 = 0;
      puVar12 = &DAT_004a4bf0;
      for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
    }
  }
  else {
    bVar13 = DAT_004ac9ac == 1;
    *(int *)(&DAT_004ac018 + param_1 * 4) =
         *(int *)(&DAT_004aa5b0 + param_1 * 4) -
         *(int *)(&DAT_004aa730 + param_1 * 4) * DAT_004a4eb0;
    if (((bVar13) && (param_1 == 2)) && (DAT_0049119c + 7 < iVar7)) {
      DAT_00491198 = -10;
    }
    if (DAT_004a4168 + 10 < iVar7) {
      FUN_00427030(iVar4,param_1);
      iVar11 = DAT_004a4eb0;
    }
  }
  if (((param_1 == 2) && (DAT_004ac9b8 == 1)) && (DAT_0049118c == 2)) {
    DAT_004ac020 = DAT_004aa5b8 - (iVar11 + -5) * DAT_004aa738;
    DAT_00491198 = -9;
  }
  if (((DAT_00491140 == 1) && (DAT_004a5b80 < DAT_00491168)) &&
     ((DAT_0049118c == 2 && (param_1 == 2)))) {
    if (DAT_004a5b80 < DAT_004a4168 + 10) {
      DAT_004ac020 = DAT_004a414c;
      return DAT_004a414c;
    }
    if ((DAT_004aa738 == 1) && ((DAT_004a4168 + 10 + DAT_00491168) / 2 < DAT_004a5b80)) {
      if (DAT_004aada8 == 0) {
        DAT_004ac020 = FUN_00413cb0(DAT_004aa5b8 + 0x91);
        DAT_004aa738 = -1;
      }
      else {
        DAT_004ac020 = FUN_00413cb0(DAT_004aa5b8 - iVar11);
        DAT_004aa738 = 1;
      }
    }
    if (DAT_004a5b80 < DAT_00491168 + -5) {
      DAT_004ac020 = FUN_00413cb0(DAT_004aa5b8 + DAT_004aa738 * -0x91);
    }
    if (DAT_00491168 + -5 <= DAT_004a5b80) {
      DAT_004ac020 = FUN_00413cb0(DAT_004aa5b8 + DAT_004aa738 * -0x32);
    }
  }
  if ((((DAT_004a5b80 < *(int *)(&DAT_004a7970 + param_1 * 4) + 3) &&
       (*(int *)(&DAT_004a4398 + param_1 * 4) == 0)) && (*(int *)(&DAT_004aa660 + param_1 * 4) == 0)
      ) && (DAT_004a4168 + 10 < DAT_004a5b80)) {
    *(int *)(&DAT_004ac018 + param_1 * 4) = iVar5;
  }
  if ((((DAT_00491140 < param_1) && (*(int *)(&DAT_004aa660 + param_1 * 4) == 0)) &&
      ((*(int *)(&DAT_004a4398 + param_1 * 4) == 0 && (*(int *)(&DAT_004a76d0 + param_1 * 4) == 0)))
      ) && (((iVar3 = *(int *)(&DAT_004a5420 + param_1 * 4), iVar3 == 1 || (iVar3 == 4)) ||
            (iVar3 == 8)))) {
    iVar3 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4));
    iVar4 = FUN_00413cb0(iVar5 + 0x1e);
    if (iVar4 < iVar3) {
      iVar3 = FUN_00413cb0(iVar5 + 0xb4);
      iVar4 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4));
      if ((iVar4 < iVar3) && (DAT_004ac9a8 == 1)) {
        iVar3 = FUN_00413cb0(iVar5 + 0x1e);
        *(int *)(&DAT_004ac018 + param_1 * 4) = iVar3;
      }
    }
    iVar3 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4));
    iVar4 = FUN_00413cb0(iVar5 + -0x1e);
    if (iVar3 < iVar4) {
      iVar3 = FUN_00413cb0(iVar5 + -0xb4);
      iVar4 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4));
      if ((iVar3 < iVar4) && (DAT_004ac9a8 == 0)) {
        iVar5 = FUN_00413cb0(iVar5 + -0x1e);
        *(int *)(&DAT_004ac018 + param_1 * 4) = iVar5;
      }
    }
  }
  *(undefined4 *)(&DAT_004a4398 + param_1 * 4) = 0;
  FUN_00427fd0(param_1);
  iVar3 = DAT_004a5b80;
  iVar5 = DAT_004a4eb0;
  if ((DAT_004ac904 != 1) || (iVar4 = param_1 * 4, param_1 = 5, 9 < *(int *)(&DAT_004a6338 + iVar4))
     ) {
    param_1 = 0;
  }
  iVar4 = *(int *)(&DAT_004aa660 + iVar2 * 4);
  if ((iVar4 != 0) && (DAT_00491140 < iVar2)) {
    iVar11 = *(int *)(&DAT_004a41f0 + iVar2 * 4);
    if (DAT_004a5b80 == iVar11) {
      *(int *)(&DAT_004ac018 + iVar2 * 4) =
           *(int *)(&DAT_004aa5b0 + iVar2 * 4) - DAT_004a4eb0 * iVar4;
    }
    if (iVar3 == iVar11 + 1) {
      *(int *)(&DAT_004ac018 + iVar2 * 4) = *(int *)(&DAT_004aa5b0 + iVar2 * 4) + iVar4 * -0x1e;
    }
    if (iVar3 == iVar11 + 2) {
      *(undefined4 *)(&DAT_004a46a8 + iVar2 * 4) = 1;
      *(int *)(&DAT_004ac018 + iVar2 * 4) = *(int *)(&DAT_004aa5b0 + iVar2 * 4) + iVar4 * -0xf;
    }
    if (iVar3 == iVar11 + 3) {
      *(int *)(&DAT_004ac018 + iVar2 * 4) = *(int *)(&DAT_004aa5b0 + iVar2 * 4) + iVar4 * 0xf;
    }
    if (iVar3 == iVar11 + 4) {
      *(int *)(&DAT_004ac018 + iVar2 * 4) = *(int *)(&DAT_004aa5b0 + iVar2 * 4) + iVar4 * 0x1e;
    }
    if (iVar11 + 5 < iVar3) {
      iVar3 = *(int *)(&DAT_004aa5b0 + iVar2 * 4);
      *(undefined4 *)(&DAT_004a71c8 + iVar2 * 8) = 0;
      *(int *)(&DAT_004aa730 + iVar2 * 4) = -iVar4;
      *(int *)(&DAT_004ac018 + iVar2 * 4) = iVar3 - (param_1 + iVar5) * -iVar4;
      *(undefined4 *)(&DAT_004aa660 + iVar2 * 4) = 0;
      *(undefined4 *)(&DAT_004a71cc + iVar2 * 8) = 0;
    }
  }
  iVar5 = FUN_00413cb0(*(int *)(&DAT_004ac018 + iVar2 * 4));
  *(int *)(&DAT_004ac018 + iVar2 * 4) = iVar5;
  FUN_004255b0(iVar2);
  iVar5 = DAT_00491198;
  iVar3 = DAT_004ac9ac;
  if ((((DAT_004ac9ac == 1) && (iVar2 == 2)) &&
      (iVar3 = DAT_004a5b80, DAT_0049119c + 7 < DAT_004a5b80)) &&
     ((iVar3 = iVar5, DAT_00491198 != -10 && (DAT_00491198 != -9)))) {
    DAT_00491198 = DAT_004ac020;
  }
  return iVar3;
}

