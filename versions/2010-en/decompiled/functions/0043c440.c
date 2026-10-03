
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043c440(int param_1,int param_2,int param_3)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  longlong lVar10;
  double local_10;
  
  if (0 < *(int *)(&DAT_004fe638 + param_2 * 4)) {
    return;
  }
  if (DAT_004f8cd0 < *(int *)(&DAT_00535620 + param_1 * 4) + 0x32) {
    return;
  }
  lVar10 = 0x403e0000;
  if (DAT_004da194 != 2) {
    lVar10 = 0x40440000;
  }
  local_10 = (double)(lVar10 << 0x20);
  lVar10 = FUN_00464050(param_2,param_1);
  fVar8 = FUN_00439e80(param_2,(double)DAT_00522acc,(double)DAT_00522ae0);
  if ((((fVar8 < (float10)local_10) ||
       (fVar8 = FUN_00439e80(param_2,(double)DAT_005229c8,(double)DAT_00522ac4),
       fVar8 < (float10)local_10)) && (DAT_004f452c == 0)) && (DAT_0053527c == 0)) {
    fVar8 = FUN_00439e80(param_2,(double)DAT_004fe094,(double)DAT_004fe2a0);
    fVar9 = FUN_00439e80(param_1,(double)DAT_004fe094,(double)DAT_004fe2a0);
    if (((fVar9 < (float10)(double)fVar8) && (param_3 < 0x10)) &&
       ((0x1e < DAT_004f8cd0 &&
        ((-6 < (int)lVar10 && (0x37 < *(int *)(&DAT_004fecc8 + param_2 * 4))))))) {
      *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
      if (param_2 <= DAT_004da140) {
        *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 3;
      }
      FUN_0043ca40(param_2);
    }
  }
  fVar8 = FUN_00439e80(param_2,(double)DAT_005229c8,(double)DAT_00522ac4);
  if (((float10)local_10 <= fVar8) || (DAT_0053527c != 1)) {
    fVar8 = FUN_00439e80(param_2,(double)DAT_004f4a68,(double)DAT_004f6d34);
    if ((((float10)local_10 <= fVar8) &&
        (fVar8 = FUN_00439e80(param_2,(double)DAT_00523248,(double)DAT_0052359c),
        (float10)local_10 <= fVar8)) || (DAT_004f452c != 1)) {
      iVar4 = DAT_004f8cd0;
      iVar3 = DAT_004da140;
      iVar1 = *(int *)(&DAT_00522ff0 + param_2 * 4);
      if ((iVar1 == -1) && (*(int *)(&DAT_00522ff0 + param_1 * 4) == 1)) {
        *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
        if (iVar3 < param_2) {
LAB_0043c8ac:
          bVar7 = SBORROW4(iVar4,0x14);
          bVar6 = iVar4 + -0x14 < 0;
        }
        else {
          *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 4;
          bVar7 = SBORROW4(iVar4,0x14);
          bVar6 = iVar4 + -0x14 < 0;
        }
      }
      else {
        if ((*(int *)(&DAT_004f4208 + param_2 * 4) == 1) &&
           ((iVar1 == *(int *)(&DAT_00522ff0 + param_1 * 4) &&
            (uVar5 = *(int *)(&DAT_004f8538 + param_2 * 4) - *(int *)(&DAT_004f8538 + param_1 * 4)
                     >> 0x1f,
            (int)((*(int *)(&DAT_004f8538 + param_2 * 4) - *(int *)(&DAT_004f8538 + param_1 * 4) ^
                  uVar5) - uVar5) < 2)))) {
          *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 6;
          *(int *)(&DAT_00535620 + param_2 * 4) = iVar4;
          bVar7 = SBORROW4(iVar4,0x14);
          bVar6 = iVar4 + -0x14 < 0;
          goto LAB_0043c8ec;
        }
        if ((*(int *)(&DAT_004f4208 + param_2 * 4) == 1) && (DAT_004da140 < param_2)) {
          if (iVar1 == *(int *)(&DAT_00522ff0 + param_1 * 4)) {
            if (DAT_004f8cd0 < 4) {
              *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
              FUN_00431960(param_2);
              FUN_0043c980(param_2);
              return;
            }
            goto LAB_0043c84d;
          }
        }
        else {
LAB_0043c84d:
          if ((((iVar1 == *(int *)(&DAT_00522ff0 + param_1 * 4)) &&
               (lVar10 = FUN_00439ec0(param_1,1,param_2), iVar4 = DAT_004f8cd0, iVar1 = DAT_004da140
               , -1 < (int)lVar10)) && (param_3 <= DAT_005363b8 + 5)) &&
             (*(int *)(&DAT_004fecc8 + param_1 * 4) + -0x1e < *(int *)(&DAT_004fecc8 + param_2 * 4))
             ) {
            *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
            if (param_2 <= iVar1) {
              *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 5;
            }
            goto LAB_0043c8ac;
          }
        }
        iVar1 = DAT_004f8cd0;
        if (DAT_004da140 < param_2) {
          return;
        }
        if ((*(int *)(&DAT_004f7090 + param_2 * 4) != 1) ||
           (0x36 < *(int *)(&DAT_004fecc8 + param_2 * 4))) {
          if (DAT_004da140 < param_2) {
            return;
          }
          fVar8 = FUN_00439e80(param_2,(double)DAT_005229d4,(double)DAT_00522ac8);
          if ((float10)_DAT_004cc4c0 <= fVar8) {
            return;
          }
          if (5 < DAT_004f8cd0 - *(int *)(&DAT_004f4350 + param_2 * 4)) {
            return;
          }
          if (0x36 < *(int *)(&DAT_004fecc8 + param_2 * 4)) {
            return;
          }
          *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
          *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 7;
          goto LAB_0043c96c;
        }
        *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
        *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 7;
        bVar7 = SBORROW4(iVar1,0x14);
        bVar6 = iVar1 + -0x14 < 0;
      }
LAB_0043c8ec:
      if (bVar7 != bVar6) {
        FUN_00431960(param_2);
        FUN_0043c980(param_2);
        return;
      }
      goto LAB_0043c96c;
    }
    dVar2 = (double)DAT_005229c8;
    fVar8 = FUN_00439e80(param_2,(double)DAT_005229c8,(double)DAT_00522ac4);
    fVar9 = FUN_00439e80(param_1,dVar2,dVar2);
    if (fVar9 <= (float10)(double)fVar8) {
      return;
    }
    *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
  }
  else {
    fVar8 = FUN_00439e80(param_2,(double)DAT_005229c8,(double)DAT_005229c8);
    fVar9 = FUN_00439e80(param_1,(double)DAT_005229c8,(double)DAT_00522ac4);
    if ((float10)(double)fVar8 <= fVar9) {
      return;
    }
    if (0xf < param_3) {
      return;
    }
    if (DAT_004f8cd0 < 0x1f) {
      return;
    }
    if ((int)lVar10 < -5) {
      return;
    }
    if (*(int *)(&DAT_004fecc8 + param_2 * 4) < 0x38) {
      return;
    }
    *(int *)(&DAT_00535620 + param_2 * 4) = DAT_004f8cd0;
  }
  if (param_2 <= DAT_004da140) {
    *(undefined4 *)(&DAT_005116e0 + param_2 * 4) = 3;
    FUN_0043ca40(param_2);
    return;
  }
LAB_0043c96c:
  FUN_0043ca40(param_2);
  return;
}

