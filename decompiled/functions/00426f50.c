
float10 __cdecl FUN_00426f50(int param_1)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  
  dVar1 = *(double *)(&DAT_004a49e8 + param_1 * 8) - (double)DAT_004aa294;
  dVar2 = (double)((DAT_004aa594 + DAT_004a70f8) / 2) - (double)DAT_004aa294;
  fVar3 = (float10)((DAT_004a72c8 + DAT_004aa59c) / 2) - (float10)DAT_004aa388;
  return (float10)SQRT((*(double *)(&DAT_004a4ae0 + param_1 * 8) - (double)DAT_004aa388) *
                       (*(double *)(&DAT_004a4ae0 + param_1 * 8) - (double)DAT_004aa388) +
                       dVar1 * dVar1) - SQRT(fVar3 * fVar3 + (float10)dVar2 * (float10)dVar2);
}

