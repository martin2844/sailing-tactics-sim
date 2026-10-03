
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0042fe40(CDC *param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  HDC hdc;
  HGDIOBJ h;
  int local_44;
  int local_40;
  int local_20 [2];
  int local_18 [2];
  int local_10 [2];
  int local_8 [2];
  
  uVar4 = DAT_004a475c;
  iVar1 = param_2 * 4;
  iVar5 = FUN_00413cb0(-(*(int *)(&DAT_004a7bc8 + iVar1) * *(int *)(&DAT_004aa730 + iVar1) +
                        DAT_004a475c));
  iVar5 = (iVar5 / 2) * 2;
  fVar13 = (float10)iVar5 * (float10)_DAT_00484d40;
  fVar14 = (float10)fsin((float10)(int)uVar4 * (float10)_DAT_00484d40);
  fVar15 = (float10)fsin(fVar13);
  dVar3 = (*(double *)(&DAT_004a71c8 + param_2 * 8) * _DAT_004852b8) / (double)DAT_00491170;
  uVar2 = (uint)(longlong)
                (((float10)_DAT_004852b0 / (float10)DAT_00491170) * (float10)DAT_004aca20 *
                 (float10)(double)fVar15 - fVar14 * (float10)dVar3 * (float10)DAT_004aca20);
  fVar13 = (float10)fcos(fVar13);
  fVar14 = (float10)fcos((float10)(int)uVar4 * (float10)_DAT_00484d40);
  uVar6 = (uint)(longlong)
                ((((float10)_DAT_004852b0 / (float10)DAT_00491170) * fVar13 +
                 fVar14 * (float10)dVar3) * (float10)DAT_004aca20 * (float10)_DAT_004852c0);
  if (((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2 <
       (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f))) ||
     (DAT_004a72d0 / 6 < (int)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)))) {
    DAT_004aca20 = 0;
  }
  uVar8 = (int)uVar4 >> 0x1f;
  if (DAT_004aca20 == 0) {
    if ((int)((uVar4 ^ uVar8) - uVar8) < 0x14) {
      if (*(int *)(&DAT_004aa730 + iVar1) == -1) {
        DAT_004aca24 = DAT_004a763c / 3 + param_3;
      }
      else {
        DAT_004aca24 = param_5 - DAT_004a763c / 3;
      }
    }
    else {
      DAT_004aca24 = (param_5 + param_3) / 2;
    }
    uVar6 = DAT_00491148 + param_6 * 2;
    iVar9 = (int)uVar6 / 3 + ((int)uVar6 >> 0x1f);
    uVar6 = uVar6 >> 0x1f;
  }
  else {
    if ((int)((uVar4 ^ uVar8) - uVar8) < 0x14) {
      if (*(int *)(&DAT_004aa730 + iVar1) == -1) {
        DAT_004aca24 = DAT_004a763c / 3 + uVar2 + param_3;
      }
      else {
        DAT_004aca24 = (uVar2 - DAT_004a763c / 3) + param_5;
      }
    }
    else {
      DAT_004aca24 = (param_3 + param_5) / 2 + uVar2;
    }
    iVar9 = (DAT_00491148 + param_6 * 2) / 3;
  }
  DAT_004aca28 = iVar9 + uVar6;
  DAT_004aca20 = DAT_004aca20 + 1;
  dVar3 = _DAT_00484e88;
  if (1 < *(int *)(&DAT_004ac4e8 + iVar1)) {
    dVar3 = _DAT_00484ea8;
  }
  iVar5 = FUN_00413cb0(iVar5 + 0x5a);
  fVar14 = (float10)fsin((float10)iVar5 * (float10)_DAT_00484d40);
  iVar1 = (int)(longlong)(fVar14 * (float10)DAT_004a763c);
  fVar14 = (float10)fcos((float10)iVar5 * (float10)_DAT_00484d40);
  uVar6 = (uint)(longlong)(fVar14 * (float10)DAT_004a763c);
  iVar5 = param_6 - DAT_00491148;
  local_40 = 0;
  local_44 = 0;
  param_3 = 0;
  do {
    iVar9 = FUN_00415a20(100);
    if (iVar9 < 2) {
      *(int *)((int)&DAT_004aa398 + param_3) =
           (int)(DAT_00491170 + (DAT_00491170 >> 0x1f & 3U)) >> 2;
    }
    if (0 < *(int *)((int)&DAT_004aa398 + param_3)) {
      *(int *)((int)&DAT_004aa398 + param_3) = *(int *)((int)&DAT_004aa398 + param_3) + -1;
    }
    if (*(int *)((int)&DAT_004aa398 + param_3) < 1) {
      iVar11 = DAT_004aca28 + *(int *)((int)&DAT_004a9450 + param_3) * -3 + 100;
      iVar10 = ((iVar5 / 0x28 + ((*(int *)((int)&DAT_004a9454 + param_3) / 0x1e) * iVar5) / 200) *
               iVar11) / iVar5 + iVar11;
      iVar9 = FUN_00415a20(100);
      if ((iVar5 * 4) / 5 < iVar11) {
        h = DAT_004a622c;
        if (iVar9 < 0x32) {
joined_r0x00430260:
          if (h == (HGDIOBJ)0x0) goto LAB_0043026d;
          hdc = *(HDC *)(param_1 + 4);
        }
        else {
          if (DAT_004a442c == (HGDIOBJ)0x0) goto LAB_0043026d;
          hdc = *(HDC *)(param_1 + 4);
          h = DAT_004a442c;
        }
LAB_00430267:
        SelectObject(hdc,h);
      }
      else {
        h = DAT_004aa954;
        if (0x31 < iVar9) goto joined_r0x00430260;
        if (DAT_004aa644 != (HGDIOBJ)0x0) {
          hdc = *(HDC *)(param_1 + 4);
          h = DAT_004aa644;
          goto LAB_00430267;
        }
      }
LAB_0043026d:
      iVar9 = DAT_004aca28 + local_40;
      iVar7 = (uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f);
      if ((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2 < iVar7) {
        iVar12 = ((iVar10 - iVar9) * iVar1) / (int)uVar6 + DAT_004aca24 + local_44;
        if (param_6 / 2 < iVar11) {
          FUN_004706bd(param_1,local_20,
                       ((iVar11 - iVar9) * iVar1) / (int)uVar6 + DAT_004aca24 + local_44,iVar11);
          iVar9 = iVar10;
LAB_00430382:
          CDC::LineTo(param_1,iVar12,iVar9);
        }
      }
      else if ((param_6 - DAT_00491148) / 2 + DAT_00491148 < iVar9) {
        iVar12 = (DAT_004a763c * *(int *)((int)&DAT_004a9450 + param_3)) / 100;
        FUN_004706bd(param_1,local_18,iVar12,iVar9);
        iVar9 = iVar9 - (int)uVar6 / 0x28;
        iVar12 = DAT_004a763c / 0x28 + iVar12;
        goto LAB_00430382;
      }
      iVar9 = DAT_004aca28 - local_40;
      if ((int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 3U)) >> 2 < iVar7) {
        iVar7 = ((iVar10 - iVar9) * iVar1) / (int)uVar6 + (DAT_004aca24 - local_44);
        if (param_6 / 2 < iVar11) {
          FUN_004706bd(param_1,local_10,
                       ((iVar11 - iVar9) * iVar1) / (int)uVar6 + (DAT_004aca24 - local_44),iVar11);
LAB_0043047f:
          CDC::LineTo(param_1,iVar7,iVar10);
        }
      }
      else if ((param_6 - DAT_00491148) / 2 + DAT_00491148 < iVar9) {
        iVar7 = (DAT_004a763c * *(int *)((int)&DAT_004a9450 + param_3)) / 100;
        FUN_004706bd(param_1,local_8,iVar7,iVar9);
        iVar10 = iVar9 - (int)uVar6 / 0x28;
        iVar7 = DAT_004a763c / 0x28 + iVar7;
        goto LAB_0043047f;
      }
    }
    local_44 = local_44 + (int)(longlong)((float10)dVar3 * (float10)(double)fVar15);
    param_3 = param_3 + 4;
    local_40 = local_40 + (int)(longlong)((float10)dVar3 * fVar13);
    if (0x1e0 < param_3) {
      return;
    }
  } while( true );
}

