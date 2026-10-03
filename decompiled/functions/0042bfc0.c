
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042bfc0(int param_1,double param_2,double param_3,int param_4,int param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  
  if (*(int *)(&DAT_004a4e88 + param_4 * 4) == 3) {
    FUN_0042c2e0(0x66666666,0x3fe66666,param_1,param_2._0_4_,param_2._4_4_,param_3,param_4);
    return;
  }
  dVar1 = (double)DAT_00491148;
  fVar7 = FUN_0042c210(param_2,param_3,param_4);
  fVar8 = (float10)(int)(longlong)(fVar7 * (float10)_DAT_00484d78);
  iVar6 = (-(uint)(param_5 != 99) & 0x3c) + 0x46;
  if ((fVar8 <= (float10)iVar6) && ((float10)-iVar6 <= fVar8)) {
    fVar8 = (float10)fcos(fVar7);
    param_2 = (double)((float10)_DAT_004a6828 * fVar8);
    if ((float10)_DAT_004a6828 * fVar8 < (float10)_DAT_00484d58) {
      param_2 = 10.0;
    }
    dVar4 = (double)DAT_00491148;
    dVar5 = (double)DAT_004a4760 - dVar1;
    if (fVar8 < (float10)_DAT_00484e18) {
      dVar2 = (double)(DAT_004a72d0 / 9) * dVar5;
      dVar3 = dVar4 - dVar2 * _DAT_00485060;
      dVar3 = dVar3 - (dVar3 - (dVar4 - dVar2 * _DAT_004850b0)) * param_2 * _DAT_00485060;
    }
    else {
      dVar3 = dVar4 + ((double)(DAT_004a72d0 / 9) * dVar5) / param_2;
    }
    iVar6 = *(int *)(&DAT_004a4e88 + param_4 * 4);
    (&DAT_004aaa48)[param_1] = (int)(longlong)dVar3;
    if (iVar6 == 1) {
      param_2 = (_DAT_00484f48 - ((dVar3 - dVar1) * _DAT_00485248) / dVar5) * _DAT_004ab0c8;
    }
    if (iVar6 == 2) {
      param_2 = (_DAT_00484cf0 - ((dVar3 - dVar1) * _DAT_00484e80) / dVar5) * _DAT_004ab0c8;
    }
    (&DAT_004a7c48)[param_1] =
         (int)(longlong)(fVar7 * (float10)param_2 * (float10)_DAT_00485250) + DAT_004a3fa0;
    return;
  }
  FUN_0042c2e0(0x9999999a,0x3fd99999,param_1,param_2._0_4_,param_2._4_4_,param_3,param_4);
  if ((int)(&DAT_004aaa48)[param_1] < DAT_00491148) {
    (&DAT_004aaa48)[param_1] = DAT_00491148;
  }
  return;
}

