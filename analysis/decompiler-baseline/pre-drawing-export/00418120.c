
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418120(int *param_1,int param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int unaff_EBP;
  code *pcVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  undefined4 unaff_retaddr;
  int iVar11;
  int iStack_28;
  int iStack_1c;
  code *pcStack_14;
  int iStack_4;
  
  (**(code **)(*param_1 + 0x2c))(7);
  FUN_00416420(param_1,(int)param_3);
  iVar4 = (int)(longlong)((double)CONCAT44(param_2,param_1) * _DAT_00485050);
  iStack_1c = (int)(longlong)((double)CONCAT44(param_2,param_1) * _DAT_00484d90);
  _DAT_004a4ca8 = DAT_004aa1e0;
  iVar2 = (DAT_004aa1e0 + DAT_004aa1dc) / 2;
  _DAT_004a4cac = DAT_004aa2e0;
  _DAT_004a4cb4 = (undefined *)DAT_004aa2dc;
  _DAT_004a4cbc = (undefined *)(DAT_004aa2dc + iVar4);
  _DAT_004a4cb0 = DAT_004aa1dc;
  _DAT_004a4cb8 = DAT_004aa1dc;
  pcVar5 = (code *)((DAT_004aa2e0 + DAT_004aa2dc) / 2 + iStack_1c);
  _DAT_004a4ccc = iVar4 + DAT_004aa2e0;
  _DAT_004a4cc8 = DAT_004aa1e0;
  _DAT_004a4cc0 = (undefined *)iVar2;
  _DAT_004a4cc4 = pcVar5;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  puVar3 = (undefined *)((DAT_004aa1bc + DAT_004aa1b8) / 2);
  iStack_1c = (int)(DAT_004aa2b8 + DAT_004aa2bc) / 2 + iStack_1c;
  _DAT_004a4cac = DAT_004aa2bc;
  _DAT_004a4cb0 = DAT_004aa1b8;
  _DAT_004a4cb4 = DAT_004aa2b8;
  _DAT_004a4ca8 = DAT_004aa1bc;
  _DAT_004a4cb8 = DAT_004aa1b8;
  _DAT_004a4cbc = DAT_004aa2b8 + iVar4;
  _DAT_004a4ccc = iVar4 + DAT_004aa2bc;
  _DAT_004a4cc8 = DAT_004aa1bc;
  _DAT_004a4cc0 = puVar3;
  _DAT_004a4cc4 = (code *)iStack_1c;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  if ((int)param_3 < 2) {
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a4dec);
    }
    (*pcStack_14)(4);
    iVar11 = 1;
    fVar8 = (float10)fsin((float10)(int)param_3 * (float10)_DAT_00484d40);
    iVar4 = param_2;
    iVar6 = param_2;
    iVar7 = param_2;
    do {
      fVar9 = (float10)_DAT_00484d50;
      if (iVar11 == 1) {
        iVar6 = (DAT_004aa1dc + DAT_004aa1e0) / 2;
        iVar7 = (DAT_004aa2e0 + DAT_004aa2dc) / 2;
        iStack_1c = iStack_28 - iVar6;
        unaff_EBP = (int)pcVar5 - iVar7;
        iVar4 = iStack_28;
        param_3 = pcVar5;
        if (*(int *)(&DAT_004aa730 + param_2 * 4) == -1) {
          iVar1 = *(int *)(&DAT_004a6ec8 + param_2 * 4);
          if (iVar1 < 7) {
            if (0 < iVar1) {
              iVar4 = (iStack_1c * iVar1) / 6 + iStack_28;
              param_3 = pcVar5 + (unaff_EBP * iVar1) / 6;
            }
            if (6 < iVar1) goto LAB_004183dd;
          }
          else {
LAB_004183dd:
            iVar4 = iStack_28 + iStack_1c;
            param_3 = pcVar5 + unaff_EBP;
          }
          fVar9 = ((float10)(iVar1 / 6) - (float10)_DAT_00484e78) * (float10)_DAT_00484d50;
        }
      }
      if (iVar11 == 2) {
        iVar6 = (DAT_004aa1b8 + DAT_004aa1bc) / 2;
        iVar7 = (int)(DAT_004aa2b8 + DAT_004aa2bc) / 2;
        iVar4 = iVar2;
        param_3 = puVar3;
        if (*(int *)(&DAT_004aa730 + param_2 * 4) == 1) {
          iVar1 = *(int *)(&DAT_004a6ec8 + param_2 * 4);
          if (iVar1 < 7) {
            if (0 < iVar1) {
              iVar4 = (iStack_1c * iVar1) / 6 + iVar2;
              param_3 = puVar3 + (unaff_EBP * iVar1) / 6;
            }
            if (6 < iVar1) goto LAB_004184ab;
          }
          else {
LAB_004184ab:
            iVar4 = iStack_1c + iVar2;
            param_3 = puVar3 + unaff_EBP;
          }
          fVar9 = ((float10)(iVar1 / 6) - (float10)_DAT_00484e78) * (float10)_DAT_00484d50;
        }
      }
      if ((float10)_DAT_00485058 < fVar9) {
        fVar9 = (float10)_DAT_00485058;
      }
      _DAT_004a4cb4 = param_3;
      fVar10 = (float10)fsin((float10)DAT_004a7044 * (float10)_DAT_00484d40);
      _DAT_004a4cb8 =
           ((int)(longlong)(fVar10 * fVar9 * (float10)(double)CONCAT44(param_1,unaff_retaddr)) -
           (int)(longlong)
                (fVar9 * (float10)(double)CONCAT44(param_1,unaff_retaddr) * (float10)(double)fVar8))
           + iVar4;
      _DAT_004a4cbc = param_3;
      _DAT_004a4ca8 = iVar6;
      _DAT_004a4cac = iVar7;
      _DAT_004a4cb0 = iVar4;
      Polygon(*(HDC *)(iStack_4 + 4),(POINT *)&DAT_004a4ca8,3);
      iVar11 = iVar11 + 1;
      pcVar5 = pcStack_14;
    } while (iVar11 < 3);
  }
  return;
}

