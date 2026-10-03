
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

int __cdecl FUN_00425600(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  DAT_004ac9b8 = 0;
  uVar1 = *(undefined4 *)(&DAT_004aa730 + param_3 * 4);
  iVar8 = *(int *)(&DAT_004ac018 + param_3 * 4);
  uVar7 = *(int *)(&DAT_004aa5b0 + param_3 * 4) - param_1 >> 0x1f;
  iVar3 = FUN_00413cb0((*(int *)(&DAT_004aa5b0 + param_3 * 4) - param_1 ^ uVar7) - uVar7);
  iVar3 = FUN_00413cb0(iVar3);
  if (0xb4 < iVar3) {
    iVar3 = 0x168 - iVar3;
  }
  *(int *)(&DAT_004abc00 + param_3 * 4) = iVar3;
  if ((((0 < *(int *)(&DAT_004a6010 + param_3 * 4)) && (*(int *)(&DAT_004aa730 + param_3 * 4) == 1))
      && (*(int *)(&DAT_004a7bc8 + param_3 * 4) < param_2 + 5)) &&
     (uVar7 = (int)*(uint *)(&DAT_004aba68 + param_3 * 4) >> 0x1f,
     0x3c < (int)((*(uint *)(&DAT_004aba68 + param_3 * 4) ^ uVar7) - uVar7))) {
    *(int *)(&DAT_004ac018 + param_3 * 4) = iVar8;
    return iVar3;
  }
  if ((iVar3 < 0x47) || (DAT_004a5b80 < 10)) {
    if (param_2 < iVar3) {
      *(int *)(&DAT_004ac018 + param_3 * 4) = param_1;
    }
  }
  else {
    iVar4 = FUN_00425910(iVar3,param_1,param_3);
    if (iVar4 < 0) {
      iVar6 = *(int *)(&DAT_004a5f10 + param_3 * 4);
      iVar5 = *(int *)(&DAT_004a5e90 + param_3 * 4);
      if (iVar6 < 0x14) {
        iVar5 = iVar5 / 2;
      }
      else {
        iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + -3;
      }
      iVar5 = iVar5 + iVar6;
      if (DAT_0049118c == 2) {
        iVar5 = iVar6;
      }
      if (iVar5 < 2) {
        iVar5 = 1;
      }
      if (iVar4 == -10) {
        iVar5 = iVar5 + 10;
      }
      if (*(int *)(&DAT_004a4398 + param_3 * 4) == 1) {
        iVar5 = 3;
      }
      iVar4 = FUN_00413cb0(iVar5 * *(int *)(&DAT_004aa730 + param_3 * 4) + 0xb4 +
                           *(int *)(&DAT_004aa5b0 + param_3 * 4));
      *(int *)(&DAT_004ac018 + param_3 * 4) = iVar4;
    }
    else {
      *(int *)(&DAT_004ac018 + param_3 * 4) =
           iVar4 * *(int *)(&DAT_004aa730 + param_3 * 4) + param_1;
    }
  }
  iVar6 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_3 * 4));
  iVar5 = DAT_004a5b80;
  iVar4 = DAT_00491168;
  *(int *)(&DAT_004ac018 + param_3 * 4) = iVar6;
  if ((iVar4 < iVar5) || (DAT_0049118c != 2)) {
    iVar4 = *(int *)(&DAT_004a7bc8 + param_3 * 4);
    if (((iVar4 < 0x46) &&
        (((uVar7 = iVar6 - iVar8 >> 0x1f, iVar6 = (iVar6 - iVar8 ^ uVar7) - uVar7, 0x41 < iVar6 &&
          (iVar6 < 0xb4)) && (*(int *)(&DAT_004aa660 + param_3 * 4) == 0)))) &&
       (*(int *)(&DAT_004a41f0 + param_3 * 4) + 8 < iVar5)) {
      *(undefined4 *)(&DAT_004aa660 + param_3 * 4) = *(undefined4 *)(&DAT_004aa730 + param_3 * 4);
      *(undefined4 *)(&DAT_004a4510 + param_3 * 8) = *(undefined4 *)(&DAT_004a7f28 + param_3 * 8);
      iVar6 = DAT_004ac9ac;
      *(undefined4 *)(&DAT_004aa730 + param_3 * 4) = uVar1;
      uVar1 = *(undefined4 *)(&DAT_004a7f2c + param_3 * 8);
      *(int *)(&DAT_004a41f0 + param_3 * 4) = iVar5;
      *(int *)(&DAT_004ac018 + param_3 * 4) = iVar8;
      *(undefined4 *)(&DAT_004a4514 + param_3 * 8) = uVar1;
      if ((iVar6 == 1) && (param_3 == 2)) {
        DAT_00491198 = 0xffffffff;
        DAT_0049119c = iVar5;
      }
    }
    iVar8 = (-(uint)(DAT_004a5a4c != 1) & 0xfffffffe) + 1;
    dVar2 = (double)(int)(((DAT_004a4958 < 2) - 1 & 0xffffffe7) + 0x28);
    if ((*(double *)(&DAT_004a7f28 + param_3 * 8) < dVar2) && (param_2 + 5 < iVar4)) {
      *(int *)(&DAT_004ac018 + param_3 * 4) =
           *(int *)(&DAT_004ac018 + param_3 * 4) +
           (int)(longlong)(dVar2 - *(double *)(&DAT_004a7f28 + param_3 * 8)) * iVar8 * 2;
    }
    if ((*(double *)(&DAT_004a4510 + param_3 * 8) < dVar2) && (param_2 + 5 < iVar4)) {
      *(int *)(&DAT_004ac018 + param_3 * 4) =
           *(int *)(&DAT_004ac018 + param_3 * 4) +
           (int)(longlong)(dVar2 - *(double *)(&DAT_004a4510 + param_3 * 8)) * iVar8 * 2;
      return iVar3;
    }
  }
  return iVar3;
}

