
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0042f930(CDC *param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  HDC hdc;
  HGDIOBJ h;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar8 = DAT_004a475c;
  if (param_2 != 1) {
    iVar8 = DAT_004a4770;
  }
  DAT_004aca18 = DAT_004aca18 + 1;
  local_34 = *(int *)(&DAT_004ac4e8 + param_2 * 4) * 0x1e;
  if (99 < local_34) {
    local_34 = 99;
  }
  dVar6 = _DAT_004852b0 / (double)DAT_00491170;
  dVar5 = (*(double *)(&DAT_004a71c8 + param_2 * 8) * _DAT_004852b8) / (double)DAT_00491170;
  iVar7 = FUN_00413cb0(-(*(int *)(&DAT_004a7bc8 + param_2 * 4) *
                         *(int *)(&DAT_004aa730 + param_2 * 4) + iVar8));
  fVar13 = (float10)DAT_004aca18;
  fVar14 = (float10)fsin((float10)iVar7 * (float10)_DAT_00484d40);
  fVar15 = (float10)fsin((float10)iVar8 * (float10)_DAT_00484d40);
  uVar1 = (uint)(longlong)(fVar14 * (float10)dVar6 * fVar13 - fVar15 * (float10)dVar5 * fVar13);
  fVar14 = (float10)fcos((float10)iVar7 * (float10)_DAT_00484d40);
  fVar15 = (float10)fcos((float10)iVar8 * (float10)_DAT_00484d40);
  uVar2 = (uint)(longlong)
                ((fVar15 * (float10)dVar5 + fVar14 * (float10)dVar6) * fVar13 *
                (float10)_DAT_004852c0);
  if ((DAT_004a763c / 5 < (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f))) ||
     ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 7U)) >> 3 <
      (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)))) {
    DAT_004aca18 = 0;
  }
  iVar8 = FUN_00413cb0(iVar7 + 0x5a);
  fVar13 = (float10)fsin((float10)iVar8 * (float10)_DAT_00484d40);
  local_2c = (int)(longlong)(fVar13 * (float10)_DAT_00484eb8);
  fVar13 = (float10)fcos((float10)iVar8 * (float10)_DAT_00484d40);
  iVar8 = (int)(longlong)(fVar13 * (float10)_DAT_00484eb8);
  iVar7 = local_2c * 2;
  iVar3 = iVar8 * 2;
  iVar4 = (param_5 - param_3) / 0x32;
  if (*(int *)(&DAT_004a4e88 + param_2 * 4) < 3) {
    local_30 = param_6 / 2;
  }
  else {
    local_30 = 0;
  }
  if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
  }
  fVar13 = (float10)DAT_00491170;
  iVar11 = 1;
  if (0 < local_34) {
    iVar12 = 0;
    do {
      iVar9 = FUN_00415a20(100);
      if (iVar9 < 3) {
        *(int *)((int)&DAT_004ac694 + iVar12) = (int)(longlong)SQRT(fVar13);
      }
      if (0 < *(int *)((int)&DAT_004ac694 + iVar12)) {
        *(int *)((int)&DAT_004ac694 + iVar12) = *(int *)((int)&DAT_004ac694 + iVar12) + -1;
      }
      iVar10 = (param_6 / 0x50) * *(int *)((int)&DAT_004a9458 + iVar12) + uVar2;
      iVar9 = (*(int *)((int)&DAT_004a9454 + iVar12) * iVar4 + uVar1) - (param_5 - param_3) / 2;
      if (local_34 / 2 < iVar11) {
        iVar8 = iVar3;
        local_2c = iVar7;
      }
      if (((((int)(param_6 + (param_6 >> 0x1f & 3U)) >> 2 < iVar10) && (iVar10 < param_6)) &&
          (param_3 < iVar9)) && (iVar9 < param_5)) {
        if (local_30 < iVar10) {
          if (*(int *)((int)&DAT_004ac694 + iVar12) == 0) {
            FUN_0042fe00(param_1,iVar9,iVar10,iVar8,local_2c);
          }
        }
        else if (*(int *)((int)&DAT_004ac694 + iVar12) == 0) {
          FUN_00419d50(param_1,iVar9,iVar10,1);
        }
      }
      iVar11 = iVar11 + 1;
      iVar12 = iVar12 + 4;
    } while (iVar11 <= local_34);
  }
  if ((DAT_004aa62c == 0) && (param_2 == 1)) {
    return;
  }
  if ((DAT_004aa638 == 0) && (param_2 == 2)) {
    return;
  }
  if (DAT_004ac8f8 == 0) {
    return;
  }
  if (DAT_004ac98c == 1) {
    return;
  }
  if (DAT_004ac92c == 0) {
    if (DAT_004ab9cc == (HGDIOBJ)0x0) goto LAB_0042fcf0;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004ab9cc;
  }
  else {
    if (DAT_004a4dec == (HGDIOBJ)0x0) goto LAB_0042fcf0;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a4dec;
  }
  SelectObject(hdc,h);
LAB_0042fcf0:
  iVar8 = 0;
  do {
    iVar7 = FUN_00415a20(100);
    if (iVar7 < 3) {
      *(int *)((int)&DAT_004ac694 + iVar8) = (int)(longlong)SQRT(fVar13);
    }
    if (0 < *(int *)((int)&DAT_004ac694 + iVar8)) {
      *(int *)((int)&DAT_004ac694 + iVar8) = *(int *)((int)&DAT_004ac694 + iVar8) + -1;
    }
    iVar7 = (DAT_004a4760 * 2) / 3 +
            (int)(uVar2 * 2) / 3 +
            ((*(int *)((int)&DAT_004a9454 + iVar8) + -0x32) * (param_6 / 0x28)) / 3;
    if ((local_30 < iVar7) && (*(int *)((int)&DAT_004ac694 + iVar8) == 0)) {
      FUN_00419d50(param_1,((*(int *)((int)&DAT_004a9458 + iVar8) + -0x32) * iVar4 * 2) / 3 +
                           (int)(uVar1 * 2) / 3 + DAT_004a3fa0,iVar7,1);
    }
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18d);
  return;
}

