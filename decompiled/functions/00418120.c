
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418120(int *param_1,int param_2,undefined *param_3)

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
  int in_stack_00000010;
  int in_stack_00000014;
  int iStack_28;
  int iStack_24;
  int iStack_14;
  
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  FUN_00416420(param_1,in_stack_00000010);
  iVar6 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485050);
  iVar3 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484d90);
  _DAT_004a4ca8 = DAT_004aa1e0;
  iVar4 = (DAT_004aa1e0 + DAT_004aa1dc) / 2;
  _DAT_004a4cac = DAT_004aa2e0;
  _DAT_004a4cb4 = DAT_004aa2dc;
  _DAT_004a4cbc = DAT_004aa2dc + iVar6;
  _DAT_004a4cb0 = DAT_004aa1dc;
  _DAT_004a4cb8 = DAT_004aa1dc;
  iVar7 = (DAT_004aa2e0 + DAT_004aa2dc) / 2 + iVar3;
  _DAT_004a4ccc = iVar6 + DAT_004aa2e0;
  _DAT_004a4cc8 = DAT_004aa1e0;
  _DAT_004a4cc0 = iVar4;
  _DAT_004a4cc4 = iVar7;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  iVar5 = (DAT_004aa1bc + DAT_004aa1b8) / 2;
  iVar3 = (DAT_004aa2b8 + DAT_004aa2bc) / 2 + iVar3;
  _DAT_004a4cac = DAT_004aa2bc;
  _DAT_004a4cb0 = DAT_004aa1b8;
  _DAT_004a4cb4 = DAT_004aa2b8;
  _DAT_004a4ca8 = DAT_004aa1bc;
  _DAT_004a4cb8 = DAT_004aa1b8;
  _DAT_004a4cbc = DAT_004aa2b8 + iVar6;
  _DAT_004a4ccc = iVar6 + DAT_004aa2bc;
  _DAT_004a4cc8 = DAT_004aa1bc;
  _DAT_004a4cc0 = iVar5;
  _DAT_004a4cc4 = iVar3;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  if (in_stack_00000010 < 2) {
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a4dec);
    }
    (*pcVar1)(param_1,4);
    iStack_24 = 1;
    fVar10 = (float10)fsin((float10)in_stack_00000014 * (float10)_DAT_00484d40);
    iVar6 = in_stack_00000010;
    iVar8 = in_stack_00000010;
    iVar9 = in_stack_00000010;
    do {
      fVar11 = (float10)_DAT_00484d50;
      if (iStack_24 == 1) {
        iVar8 = (DAT_004aa1dc + DAT_004aa1e0) / 2;
        iVar9 = (DAT_004aa2e0 + DAT_004aa2dc) / 2;
        iStack_14 = iVar4 - iVar8;
        iStack_28 = iVar7 - iVar9;
        iVar6 = iVar4;
        in_stack_00000014 = iVar7;
        if (*(int *)(&DAT_004aa730 + in_stack_00000010 * 4) == -1) {
          iVar2 = *(int *)(&DAT_004a6ec8 + in_stack_00000010 * 4);
          if (iVar2 < 7) {
            if (0 < iVar2) {
              iVar6 = (iStack_14 * iVar2) / 6 + iVar4;
              in_stack_00000014 = (iStack_28 * iVar2) / 6 + iVar7;
            }
            if (6 < iVar2) goto LAB_004183dd;
          }
          else {
LAB_004183dd:
            iVar6 = iVar4 + iStack_14;
            in_stack_00000014 = iStack_28 + iVar7;
          }
          fVar11 = ((float10)(iVar2 / 6) - (float10)_DAT_00484e78) * (float10)_DAT_00484d50;
        }
      }
      if (iStack_24 == 2) {
        iVar8 = (DAT_004aa1b8 + DAT_004aa1bc) / 2;
        iVar9 = (DAT_004aa2bc + DAT_004aa2b8) / 2;
        iVar6 = iVar5;
        in_stack_00000014 = iVar3;
        if (*(int *)(&DAT_004aa730 + in_stack_00000010 * 4) == 1) {
          iVar2 = *(int *)(&DAT_004a6ec8 + in_stack_00000010 * 4);
          if (iVar2 < 7) {
            if (0 < iVar2) {
              iVar6 = (iStack_14 * iVar2) / 6 + iVar5;
              in_stack_00000014 = (iStack_28 * iVar2) / 6 + iVar3;
            }
            if (6 < iVar2) goto LAB_004184ab;
          }
          else {
LAB_004184ab:
            iVar6 = iStack_14 + iVar5;
            in_stack_00000014 = iStack_28 + iVar3;
          }
          fVar11 = ((float10)(iVar2 / 6) - (float10)_DAT_00484e78) * (float10)_DAT_00484d50;
        }
      }
      if ((float10)_DAT_00485058 < fVar11) {
        fVar11 = (float10)_DAT_00485058;
      }
      _DAT_004a4cb4 = in_stack_00000014;
      fVar12 = (float10)fsin((float10)DAT_004a7044 * (float10)_DAT_00484d40);
      _DAT_004a4cb8 =
           ((int)(longlong)(fVar12 * fVar11 * (float10)(double)CONCAT44(param_3,param_2)) -
           (int)(longlong)
                (fVar11 * (float10)(double)CONCAT44(param_3,param_2) * (float10)(double)fVar10)) +
           iVar6;
      _DAT_004a4cbc = in_stack_00000014;
      _DAT_004a4ca8 = iVar8;
      _DAT_004a4cac = iVar9;
      _DAT_004a4cb0 = iVar6;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,3);
      iStack_24 = iStack_24 + 1;
    } while (iStack_24 < 3);
  }
  return;
}

