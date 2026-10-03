
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_00420b70(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = (param_1 - DAT_004a6498) / 0xfa + 2;
  if (iVar3 < 2) {
    iVar3 = 2;
  }
  iVar1 = (int)(longlong)
               ((double)(int)((&DAT_004a68cc)[iVar3] - (&DAT_004a68c8)[iVar3]) *
               (double)(param_1 - (&DAT_004a6490)[iVar3]) * _DAT_004850d0) + (&DAT_004a68c8)[iVar3];
  if (iVar3 < 3) {
    iVar1 = DAT_004a68d0;
  }
  uVar2 = iVar1 - param_2 >> 0x1f;
  fVar4 = (float10)(int)((iVar1 - param_2 ^ uVar2) - uVar2) * (float10)_DAT_00485058;
  if ((DAT_004aa804 == 1) && (param_2 < iVar1)) {
    fVar4 = (float10)_DAT_00484e18;
  }
  if ((DAT_004aa804 == 3) && (iVar1 < param_2)) {
    fVar4 = (float10)_DAT_00484e18;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = (double)fVar4;
  }
  return fVar4;
}

