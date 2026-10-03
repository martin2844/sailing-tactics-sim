
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00412f60(double param_1,double param_2)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  int local_4;
  
  iVar5 = DAT_004ac914;
  dVar4 = _DAT_00484e10;
  if (DAT_004ac914 == 1) {
    dVar4 = _DAT_00484dc0;
  }
  dVar2 = param_1 * _DAT_00484d48;
  iVar6 = 0;
  do {
    iVar8 = iVar6 + -2;
    (&DAT_004ac310)[iVar6] = _DAT_004ac320;
    iVar6 = iVar6 + 1;
    *(double *)(&DAT_004a3a30 + iVar6 * 8) = _DAT_004a3a48 - (double)iVar8 * dVar2;
  } while (iVar6 < 6);
  _DAT_004a3a90 = DAT_004a3a38 - dVar2 * _DAT_00484e48;
  _DAT_004ac368 = DAT_004ac310;
  param_1._0_4_ = 1;
  local_4 = 0x1d;
  iVar6 = 0;
  pdVar9 = (double *)&DAT_004ac360;
  do {
    dVar3 = (double)param_1._0_4_;
    fVar11 = (float10)_DAT_004ac338;
    fVar12 = (float10)fsin((float10)local_4 * (float10)dVar4 * (float10)_DAT_00484d40);
    local_4 = local_4 + 0x1d;
    param_1._0_4_ = param_1._0_4_ + 1;
    *(double *)((int)&DAT_004a3a88 + iVar6) =
         dVar3 * dVar2 + (double)CONCAT44(_DAT_004a3a64,_DAT_004a3a60);
    fVar12 = fVar12 * (float10)param_2 * (float10)_DAT_00484e50;
    *(double *)((int)&DAT_004a7a48 + iVar6) = (double)fVar12;
    *pdVar9 = (double)(fVar11 + fVar12);
    iVar6 = iVar6 + -8;
    pdVar9 = pdVar9 + -1;
  } while (local_4 < 0x92);
  iVar8 = 0xc;
  iVar10 = 0x15c;
  iVar6 = 0;
  pdVar9 = (double *)&DAT_004ac370;
  do {
    iVar1 = iVar8 + -0xb;
    fVar11 = (float10)_DAT_004ac338;
    fVar12 = (float10)fsin((float10)(iVar10 + -0x13f) * (float10)dVar4 * (float10)_DAT_00484d40);
    iVar7 = iVar6 + 8;
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + 0x1d;
    *(double *)((int)&DAT_004a3a98 + iVar6) =
         (double)iVar1 * dVar2 + (double)CONCAT44(_DAT_004a3a64,_DAT_004a3a60);
    fVar12 = fVar12 * (float10)param_2 * (float10)_DAT_00484e58;
    *(double *)((int)&DAT_004a7a58 + iVar6) = (double)fVar12;
    *pdVar9 = (double)(fVar11 + fVar12);
    iVar6 = iVar7;
    pdVar9 = pdVar9 + 1;
  } while (iVar7 < 0x21);
  if (iVar5 == 1) {
    _DAT_004a3a60 = DAT_004a3a58;
    _DAT_004a3a64 = DAT_004a3a5c;
  }
  return;
}

