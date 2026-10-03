
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043e730(int param_1,double param_2,double param_3,int param_4,int param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  
  if (*(int *)(&DAT_004f71c0 + param_4 * 4) == 3) {
    FUN_0043eb00(0.7,param_1,param_2,param_3,param_4);
    return;
  }
  dVar2 = (double)DAT_004da148;
  fVar8 = FUN_0043ea10(param_2,param_3,param_4);
  dVar1 = (double)(int)(longlong)(fVar8 * (float10)_DAT_004cc3e8);
  iVar7 = (-(uint)(param_5 != 99) & 0x3c) + 0x46;
  if ((dVar1 <= (double)iVar7) && ((double)-iVar7 <= dVar1)) {
    fVar9 = (float10)fcos(fVar8);
    param_2 = (double)((float10)_DAT_004fbb88 * fVar9);
    if ((float10)_DAT_004fbb88 * fVar9 < (float10)_DAT_004cc580) {
      param_2 = 10.0;
    }
    dVar6 = (double)DAT_004da148;
    dVar3 = (double)DAT_004f4b48 - dVar2;
    if (fVar9 < (float10)_DAT_004cc658) {
      dVar5 = (double)(DAT_004fe2a8 / 9) * dVar3;
      dVar4 = dVar6 - dVar5 * _DAT_004cc8b0;
      dVar4 = dVar4 - (dVar4 - (dVar6 - dVar5 * _DAT_004cc908)) * param_2 * _DAT_004cc8b0;
    }
    else {
      dVar4 = dVar6 + ((double)(DAT_004fe2a8 / 9) * dVar3) / param_2;
    }
    if (param_5 == 5) {
      if ((_DAT_004cc4f0 < dVar1) || (dVar1 < _DAT_004ccb50)) {
        dVar4 = dVar2 + dVar2;
      }
      if ((_DAT_004cc960 < dVar1) || (dVar1 < _DAT_004ccb58)) {
        dVar4 = dVar2 * _DAT_004cc538;
      }
      if ((_DAT_004cc4d0 < dVar1) || (dVar1 < _DAT_004cc8f8)) {
        dVar4 = dVar2;
      }
    }
    iVar7 = *(int *)(&DAT_004f71c0 + param_4 * 4);
    (&DAT_00523660)[param_1] = (int)(longlong)dVar4;
    if (iVar7 == 1) {
      param_2 = (_DAT_004cc418 - ((dVar4 - dVar2) * _DAT_004cc5c0) / dVar3) * _DAT_005259d0;
    }
    if (iVar7 == 2) {
      param_2 = (_DAT_004cc418 - ((dVar4 - dVar2) * _DAT_004ccb60) / dVar3) * _DAT_005259d0;
    }
    (&DAT_004fed58)[param_1] =
         (int)(longlong)(fVar8 * (float10)param_2 * (float10)_DAT_004ccb68) + DAT_004f40a8;
    return;
  }
  FUN_0043eb00(0.4,param_1,param_2,param_3,param_4);
  if ((int)(&DAT_00523660)[param_1] < DAT_004da148) {
    (&DAT_00523660)[param_1] = DAT_004da148;
  }
  return;
}

