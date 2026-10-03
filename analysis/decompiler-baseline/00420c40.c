
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00420c40(int param_1,int param_2,int param_3)

{
  double dVar1;
  double dVar2;
  
  if (1 < DAT_004a4958) {
    FUN_00420d10(param_1,param_2,param_3);
    return;
  }
  dVar1 = (double)(param_1 - DAT_004ac284) / _DAT_004a6470;
  dVar2 = (double)(param_2 - DAT_004a3a08) / _DAT_004abe60;
  dVar1 = _DAT_004850d8 -
          (SQRT(dVar2 * dVar2 + dVar1 * dVar1) / (double)DAT_004abae8) * _DAT_004850d8;
  if (DAT_004a5a4c == 0) {
    dVar1 = dVar1 + dVar1;
  }
  else {
    dVar1 = -dVar1;
  }
  if (DAT_004a4378 == 1) {
    dVar1 = dVar1 + dVar1;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = dVar1;
  }
  return;
}

