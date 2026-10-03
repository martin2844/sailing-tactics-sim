
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double __cdecl FUN_00429df0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  int iVar4;
  float10 fVar5;
  
  iVar1 = *(int *)(&DAT_004a7bc8 + param_2 * 4);
  iVar4 = ((&DAT_004a3450)[iVar1] * *(int *)(&DAT_004a6338 + param_2 * 4)) / 10 + param_1;
  iVar2 = ((&DAT_004a54a0)[iVar1] * *(int *)(&DAT_004a6338 + param_2 * 4)) / 10;
  dVar3 = ((double)iVar2 * (double)iVar2 + (double)iVar4 * (double)iVar4) * _DAT_004851e0;
  *(int *)(&DAT_004ab9e8 + param_2 * 4) = (int)(longlong)SQRT(dVar3 * _DAT_004851e8);
  if (iVar4 == 0) {
    *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0x5a;
    return dVar3;
  }
  if (iVar2 == 0) {
    if (iVar1 < 5) {
      *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0;
      return dVar3;
    }
    if (-1 < iVar1) goto LAB_00429f23;
  }
  if (0 < iVar4) {
    fVar5 = (float10)fpatan((float10)iVar2 / (float10)iVar4,(float10)1);
    *(int *)(&DAT_004a47f8 + param_2 * 4) = (int)(longlong)(fVar5 * (float10)_DAT_00484d78);
  }
  if (iVar4 < 0) {
    fVar5 = (float10)fpatan(-((float10)iVar4 / (float10)iVar2),(float10)1);
    *(int *)(&DAT_004a47f8 + param_2 * 4) = 0x5a - (int)(longlong)(fVar5 * (float10)_DAT_004850b8);
  }
  if (iVar1 < 0xb4) {
    return dVar3;
  }
LAB_00429f23:
  *(undefined4 *)(&DAT_004a47f8 + param_2 * 4) = 0xb3;
  return dVar3;
}

