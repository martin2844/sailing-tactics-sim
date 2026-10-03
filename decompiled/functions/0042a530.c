
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042a530(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  float10 fVar7;
  float10 fVar8;
  longlong lVar9;
  double local_8;
  
  if (8 < *(int *)(&DAT_004a5420 + param_2 * 4)) {
    return;
  }
  if (DAT_004a5b80 < *(int *)(&DAT_004abf18 + param_1 * 4) + 0x32) {
    return;
  }
  lVar9 = 0x403e0000;
  if (DAT_0049118c != 2) {
    lVar9 = 0x40440000;
  }
  local_8 = (double)(lVar9 << 0x20);
  fVar7 = FUN_00428ab0(param_2,(double)DAT_004aa38c,(double)DAT_004aa588);
  if ((fVar7 < (float10)local_8) ||
     (fVar7 = FUN_00428ab0(param_2,(double)DAT_004aa288,(double)DAT_004aa384), iVar3 = DAT_004a5b80,
     iVar2 = DAT_00491140, fVar7 < (float10)local_8)) {
    fVar7 = FUN_00428ab0(param_2,(double)DAT_004a70f8,(double)DAT_004a72c8);
    fVar8 = FUN_00428ab0(param_1,(double)DAT_004a70f8,(double)DAT_004a72c8);
    iVar2 = DAT_00491140;
    if ((float10)(double)fVar7 <= fVar8) {
      return;
    }
    if (0xf < *(int *)(&DAT_004a5420 + param_1 * 4) + *(int *)(&DAT_004a5420 + param_2 * 4)) {
      return;
    }
    if (*(int *)(&DAT_004a7bc8 + param_2 * 4) < 0x38) {
      return;
    }
    *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
    if (param_2 <= iVar2) {
      *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 3;
    }
    goto LAB_0042a888;
  }
  iVar1 = *(int *)(&DAT_004aa730 + param_2 * 4);
  if ((iVar1 == -1) && (*(int *)(&DAT_004aa730 + param_1 * 4) == 1)) {
    *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
    if (iVar2 < param_2) {
LAB_0042a708:
      bVar6 = SBORROW4(iVar3,0x14);
      bVar5 = iVar3 + -0x14 < 0;
    }
    else {
      *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 4;
      bVar6 = SBORROW4(iVar3,0x14);
      bVar5 = iVar3 + -0x14 < 0;
    }
  }
  else {
    if ((*(int *)(&DAT_004a40d0 + param_2 * 4) == 1) &&
       ((iVar1 == *(int *)(&DAT_004aa730 + param_1 * 4) &&
        (uVar4 = *(int *)(&DAT_004a5420 + param_2 * 4) - *(int *)(&DAT_004a5420 + param_1 * 4) >>
                 0x1f,
        (int)((*(int *)(&DAT_004a5420 + param_2 * 4) - *(int *)(&DAT_004a5420 + param_1 * 4) ^ uVar4
              ) - uVar4) < 2)))) {
      *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 6;
      *(int *)(&DAT_004abf18 + param_2 * 4) = iVar3;
      bVar6 = SBORROW4(iVar3,0x14);
      bVar5 = iVar3 + -0x14 < 0;
      goto LAB_0042a74d;
    }
    if ((*(int *)(&DAT_004a40d0 + param_2 * 4) == 1) && (DAT_00491140 < param_2)) {
      if (iVar1 == *(int *)(&DAT_004aa730 + param_1 * 4)) {
        if (DAT_004a5b80 < 4) {
          *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
          FUN_00421c40(param_2);
          FUN_0042a8a0(param_2);
          return;
        }
        goto LAB_0042a6bd;
      }
    }
    else {
LAB_0042a6bd:
      if (((iVar1 == *(int *)(&DAT_004aa730 + param_1 * 4)) &&
          (lVar9 = FUN_00428af0(param_1,1,param_2), iVar3 = DAT_004a5b80, iVar2 = DAT_00491140,
          -1 < (int)lVar9)) && (param_3 <= DAT_004ac900 + 5)) {
        *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
        if (param_2 <= iVar2) {
          *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 5;
        }
        goto LAB_0042a708;
      }
    }
    iVar2 = DAT_004a5b80;
    if (DAT_00491140 < param_2) {
      return;
    }
    if ((*(int *)(&DAT_004a4df8 + param_2 * 4) != 1) ||
       (0x36 < *(int *)(&DAT_004a7bc8 + param_2 * 4))) {
      if (DAT_00491140 < param_2) {
        return;
      }
      fVar7 = FUN_00428ab0(param_2,(double)DAT_004aa294,(double)DAT_004aa388);
      if ((float10)_DAT_004850c8 <= fVar7) {
        return;
      }
      if (5 < DAT_004a5b80 - *(int *)(&DAT_004a41f0 + param_2 * 4)) {
        return;
      }
      if (0x36 < *(int *)(&DAT_004a7bc8 + param_2 * 4)) {
        return;
      }
      *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
      *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 7;
      FUN_0042a950(param_2);
      return;
    }
    *(int *)(&DAT_004abf18 + param_2 * 4) = DAT_004a5b80;
    *(undefined4 *)(&DAT_004a89c0 + param_2 * 4) = 7;
    bVar6 = SBORROW4(iVar2,0x14);
    bVar5 = iVar2 + -0x14 < 0;
  }
LAB_0042a74d:
  if (bVar6 != bVar5) {
    FUN_00421c40(param_2);
    FUN_0042a8a0(param_2);
    return;
  }
LAB_0042a888:
  FUN_0042a950(param_2);
  return;
}

