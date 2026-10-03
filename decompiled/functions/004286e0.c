
void __cdecl FUN_004286e0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  longlong lVar6;
  double local_8;
  
  if (DAT_004a5b80 <= DAT_004a4168 + 1) {
    return;
  }
  if ((*(int *)(&DAT_004a40d0 + param_3 * 4) != 1) ||
     (*(int *)(&DAT_004aa730 + param_3 * 4) != *(int *)(&DAT_004aa730 + param_2 * 4))) {
    lVar6 = 0x40490000;
    if (DAT_0049118c != 2) {
      lVar6 = 0x4052c000;
    }
    local_8 = (double)(lVar6 << 0x20);
    lVar6 = FUN_0044da90(param_3,param_2);
    fVar4 = FUN_00428ab0(param_3,(double)DAT_004aa38c,(double)DAT_004aa588);
    if (((float10)local_8 <= fVar4) &&
       (fVar4 = FUN_00428ab0(param_3,(double)DAT_004aa288,(double)DAT_004aa384),
       (float10)local_8 <= fVar4)) {
      if ((DAT_004ac904 == 1) || (iVar2 = -5, DAT_004ac900 == 1)) {
        iVar2 = -3;
      }
      if (*(int *)(&DAT_004a5268 + param_3 * 4) < 200) {
        iVar2 = iVar2 + 2;
      }
      iVar3 = iVar2 + 5;
      if (DAT_004a5b80 < 1) {
        iVar3 = -5;
      }
      else {
        uVar1 = (int)*(uint *)(&DAT_004aba68 + param_3 * 4) >> 0x1f;
        if ((int)((*(uint *)(&DAT_004aba68 + param_3 * 4) ^ uVar1) - uVar1) < 0xf) {
          iVar3 = iVar2 + 0xf;
        }
      }
      if ((*(int *)(&DAT_004aa730 + param_3 * 4) == -1) &&
         (((((*(int *)(&DAT_004aa730 + param_2 * 4) == 1 &&
             (lVar6 = FUN_00428af0(param_2,0,param_3), iVar3 <= (int)lVar6)) &&
            (*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38)) &&
           ((*(int *)(&DAT_004a41f0 + param_3 * 4) + 10 < DAT_004a5b80 &&
            (*(int *)(&DAT_004a76d0 + param_3 * 4) == 0)))) ||
          ((*(int *)(&DAT_004aa730 + param_3 * 4) == -1 &&
           ((((*(int *)(&DAT_004aa730 + param_2 * 4) == 1 &&
              (lVar6 = FUN_00428af0(param_2,0,param_3), (int)lVar6 < iVar3)) &&
             ((lVar6 = FUN_00428af0(param_2,0,param_3), iVar3 + -3 <= (int)lVar6 &&
              (*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38)))) ||
            ((((*(int *)(&DAT_004aa730 + param_3 * 4) == -1 &&
               (*(int *)(&DAT_004aa730 + param_2 * 4) == 1)) &&
              (lVar6 = FUN_00428af0(param_2,0,param_3), (int)lVar6 < iVar3 + -3)) &&
             (*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38)))))))))) {
        *(undefined4 *)(&DAT_004a4e78 + param_3 * 4) = 1;
        FUN_00428a30(1);
        return;
      }
      lVar6 = FUN_00428af0(param_2,1,param_3);
      iVar2 = *(int *)(&DAT_004aa730 + param_3 * 4);
      iVar3 = *(int *)(&DAT_004aa730 + param_2 * 4);
      if ((iVar2 == iVar3) &&
         ((((0 < (int)lVar6 &&
            (*(int *)(&DAT_004a7bc8 + param_2 * 4) <= *(int *)(&DAT_004a7bc8 + param_3 * 4))) &&
           (param_1 < 5)) ||
          (((iVar2 == iVar3 && (0 < (int)lVar6)) &&
           (*(int *)(&DAT_004a7bc8 + param_2 * 4) < *(int *)(&DAT_004a7bc8 + param_3 * 4))))))) {
        *(undefined4 *)(&DAT_004a4e78 + param_3 * 4) = 1;
        FUN_00428a30(2);
        return;
      }
      if (*(int *)(&DAT_004a7bc8 + param_3 * 4) < 0x38) {
        return;
      }
      if (iVar2 != -1) {
        return;
      }
      if (iVar3 != 1) {
        return;
      }
      FUN_0044da90(param_3,param_2);
      *(undefined4 *)(&DAT_004a4e78 + param_3 * 4) = 1;
      FUN_00428a30(1);
      return;
    }
    fVar4 = FUN_00428ab0(param_3,(double)DAT_004a70f8,(double)DAT_004a72c8);
    fVar5 = FUN_00428ab0(param_2,(double)DAT_004a70f8,(double)DAT_004a72c8);
    if ((float10)(double)fVar4 <= fVar5) {
      return;
    }
    if (0x15 < param_1) {
      return;
    }
    if (DAT_004a5b80 < 0x1f) {
      return;
    }
    if ((int)lVar6 < -5) {
      return;
    }
  }
  *(undefined4 *)(&DAT_004a4e78 + param_3 * 4) = 1;
  return;
}

