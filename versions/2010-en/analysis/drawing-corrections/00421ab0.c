
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00421ab0(int *param_1,double param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  int iStack_28;
  int iStack_24;
  int iStack_14;
  
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  FUN_0041ed90(param_1,param_3);
  iVar6 = (int)(longlong)(param_2 * _DAT_004cc8a0);
  iVar3 = (int)(longlong)(param_2 * _DAT_004cc660);
  _DAT_004f6e28 = DAT_00522920;
  iVar4 = (DAT_00522920 + DAT_0052291c) / 2;
  _DAT_004f6e2c = DAT_00522a20;
  _DAT_004f6e34 = DAT_00522a1c;
  _DAT_004f6e3c = DAT_00522a1c + iVar6;
  _DAT_004f6e30 = DAT_0052291c;
  _DAT_004f6e38 = DAT_0052291c;
  iVar7 = (DAT_00522a20 + DAT_00522a1c) / 2 + iVar3;
  _DAT_004f6e4c = iVar6 + DAT_00522a20;
  _DAT_004f6e48 = DAT_00522920;
  _DAT_004f6e40 = iVar4;
  _DAT_004f6e44 = iVar7;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  iVar5 = (DAT_005228fc + DAT_005228f8) / 2;
  iVar3 = (DAT_005229f8 + DAT_005229fc) / 2 + iVar3;
  _DAT_004f6e2c = DAT_005229fc;
  _DAT_004f6e30 = DAT_005228f8;
  _DAT_004f6e34 = DAT_005229f8;
  _DAT_004f6e28 = DAT_005228fc;
  _DAT_004f6e38 = DAT_005228f8;
  _DAT_004f6e3c = DAT_005229f8 + iVar6;
  _DAT_004f6e4c = iVar6 + DAT_005229fc;
  _DAT_004f6e48 = DAT_005228fc;
  _DAT_004f6e40 = iVar5;
  _DAT_004f6e44 = iVar3;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  if (param_3 < 2) {
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    (*pcVar1)(param_1,4);
    iStack_24 = 1;
    fVar10 = (float10)fsin((float10)param_4 * (float10)_DAT_004cc568);
    iVar6 = param_3;
    iVar8 = param_3;
    iVar9 = param_3;
    do {
      fVar11 = (float10)_DAT_004cc578;
      if (iStack_24 == 1) {
        iVar8 = (DAT_0052291c + DAT_00522920) / 2;
        iVar9 = (DAT_00522a20 + DAT_00522a1c) / 2;
        iStack_14 = iVar4 - iVar8;
        iStack_28 = iVar7 - iVar9;
        iVar6 = iVar4;
        param_4 = iVar7;
        if (*(int *)(&DAT_00522ff0 + param_3 * 4) == -1) {
          iVar2 = *(int *)(&DAT_004fc2c0 + param_3 * 4);
          if (iVar2 < 7) {
            if (0 < iVar2) {
              iVar6 = (iStack_14 * iVar2) / 6 + iVar4;
              param_4 = (iStack_28 * iVar2) / 6 + iVar7;
            }
            if (6 < iVar2) goto LAB_00421d6d;
          }
          else {
LAB_00421d6d:
            iVar6 = iVar4 + iStack_14;
            param_4 = iStack_28 + iVar7;
          }
          fVar11 = ((float10)(iVar2 / 6) - (float10)_DAT_004cc700) * (float10)_DAT_004cc578;
        }
      }
      if (iStack_24 == 2) {
        iVar8 = (DAT_005228f8 + DAT_005228fc) / 2;
        iVar9 = (DAT_005229fc + DAT_005229f8) / 2;
        iVar6 = iVar5;
        param_4 = iVar3;
        if (*(int *)(&DAT_00522ff0 + param_3 * 4) == 1) {
          iVar2 = *(int *)(&DAT_004fc2c0 + param_3 * 4);
          if (iVar2 < 7) {
            if (0 < iVar2) {
              iVar6 = (iStack_14 * iVar2) / 6 + iVar5;
              param_4 = (iStack_28 * iVar2) / 6 + iVar3;
            }
            if (6 < iVar2) goto LAB_00421e3b;
          }
          else {
LAB_00421e3b:
            iVar6 = iStack_14 + iVar5;
            param_4 = iStack_28 + iVar3;
          }
          fVar11 = ((float10)(iVar2 / 6) - (float10)_DAT_004cc700) * (float10)_DAT_004cc578;
        }
      }
      if ((float10)_DAT_004cc8a8 < fVar11) {
        fVar11 = (float10)_DAT_004cc8a8;
      }
      _DAT_004f6e34 = param_4;
      fVar12 = (float10)fsin((float10)DAT_004fdfd0 * (float10)_DAT_004cc568);
      _DAT_004f6e38 =
           ((int)(longlong)(fVar12 * fVar11 * (float10)param_2) -
           (int)(longlong)(fVar11 * (float10)param_2 * (float10)(double)fVar10)) + iVar6;
      _DAT_004f6e3c = param_4;
      _DAT_004f6e28 = iVar8;
      _DAT_004f6e2c = iVar9;
      _DAT_004f6e30 = iVar6;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
      iStack_24 = iStack_24 + 1;
    } while (iStack_24 < 3);
  }
  return;
}

