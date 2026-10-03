
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004060f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  code *unaff_EBX;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  code *pcVar7;
  int *unaff_retaddr;
  HDC pHVar8;
  HGDIOBJ pvVar9;
  code *local_58 [7];
  int iStack_3c;
  int aiStack_30 [12];
  
  pcVar7 = (code *)(longlong)(_DAT_004ab0c8 * _DAT_00484ce8);
  pcVar6 = *(code **)(*param_1 + 0x2c);
  local_58[0] = pcVar6;
  local_58[1] = pcVar7;
  (*pcVar6)(8);
  if (DAT_004ac98c == 0) {
    unaff_retaddr = &DAT_004a4928;
    iVar3 = 0;
    do {
      iVar5 = *(int *)(&DAT_004a6830 + (int)param_1 * 4);
      if ((iVar5 < 0xb4) || (0x10e < iVar5)) {
        iVar5 = FUN_00415dc0(iVar5);
        iVar5 = *(int *)((int)&DAT_004a8870 + iVar3) - iVar5;
        FUN_00415dc0(iVar5);
      }
      else {
        iVar5 = *(int *)((int)&DAT_004a8870 + iVar3) - iVar5;
      }
      iVar1 = *(int *)((int)&DAT_004a44f0 + iVar3);
      iVar5 = iVar5 * (int)pcVar7 + DAT_004a3fa0;
      if (DAT_004a5b98 < 3) {
        if (DAT_004a3efc != (HGDIOBJ)0x0) {
          pHVar8 = (HDC)param_1[1];
          pvVar9 = DAT_004a3efc;
LAB_004061cd:
          SelectObject(pHVar8,pvVar9);
        }
      }
      else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
        pHVar8 = (HDC)param_1[1];
        pvVar9 = DAT_004aa7f4;
        goto LAB_004061cd;
      }
      Ellipse((HDC)param_1[1],iVar5,iVar1 + 1,iVar5 + *unaff_retaddr,iVar1 + 9);
      if (DAT_004a5b98 < 3) {
        (*unaff_EBX)(0);
      }
      else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a70e4);
      }
      Pie((HDC)param_1[1],iVar5,iVar1,iVar5 + *unaff_retaddr,iVar1 + 0xb,iVar5 + *unaff_retaddr + 1,
          iVar1 + 5,iVar5 + -1,iVar1 + 5);
      iVar3 = iVar3 + 4;
      unaff_retaddr = unaff_retaddr + 1;
      pcVar6 = unaff_EBX;
      pcVar7 = local_58[0];
    } while (iVar3 < 0x19);
  }
  (*pcVar6)(8);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004ac8ec == (HGDIOBJ)0x0) goto LAB_004062be;
    pHVar8 = (HDC)param_1[1];
    pvVar9 = DAT_004ac8ec;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004062be;
    pHVar8 = (HDC)param_1[1];
    pvVar9 = DAT_004aa7f4;
  }
  SelectObject(pHVar8,pvVar9);
LAB_004062be:
  if (DAT_004ac98c == 1) {
    (*pcVar6)(4);
  }
  iVar5 = 3;
  iVar3 = DAT_00491148;
  piVar4 = unaff_retaddr;
  do {
    iVar1 = *(int *)(&DAT_004a6830 + (int)unaff_retaddr * 4);
    if ((iVar1 < 0xb4) || (0x10e < iVar1)) {
      iVar3 = FUN_00415dc0(iVar1);
      piVar2 = (int *)FUN_00415dc0(*(int *)(iVar5 * 4 + 0x4a8850) - iVar3);
      iVar3 = DAT_00491148;
    }
    else {
      piVar2 = (int *)(*(int *)(iVar5 * 4 + 0x4a8850) - iVar1);
    }
    if (iVar5 == 5) {
      piVar4 = piVar2;
    }
    iVar1 = *(int *)(iVar5 * 4 + 0x4a44d0);
    local_58[iVar5] = (code *)((int)piVar2 * (int)pcVar7 + DAT_004a3fa0);
    aiStack_30[iVar5] = (iVar3 - iVar1) + -1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  _DAT_004a4cb0 = local_58[4];
  _DAT_004a4cb8 = local_58[5];
  _DAT_004a4cc0 = local_58[6];
  _DAT_004a4cc8 = iStack_3c;
  _DAT_004a4cd0 = iStack_3c + 100;
  _DAT_004a4ca8 = local_58[3];
  _DAT_004a4cb4 = aiStack_30[4];
  _DAT_004a4cbc = aiStack_30[5];
  _DAT_004a4cc4 = aiStack_30[6];
  _DAT_004a4ccc = aiStack_30[7];
  _DAT_004a4cac = iVar3;
  _DAT_004a4cd4 = iVar3;
  if ((int)(((uint)piVar4 ^ (int)piVar4 >> 0x1f) - ((int)piVar4 >> 0x1f)) < 0x6e) {
    Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,6);
  }
  return;
}

