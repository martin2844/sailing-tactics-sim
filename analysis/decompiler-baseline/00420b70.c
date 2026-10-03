
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00420b70(int param_1,int param_2,int param_3)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (param_1 - DAT_004a6498) / 0xfa + 2;
  if (iVar4 < 2) {
    iVar4 = 2;
  }
  iVar2 = (int)(longlong)
               ((double)(int)((&DAT_004a68cc)[iVar4] - (&DAT_004a68c8)[iVar4]) *
               (double)(param_1 - (&DAT_004a6490)[iVar4]) * _DAT_004850d0) + (&DAT_004a68c8)[iVar4];
  if (iVar4 < 3) {
    iVar2 = DAT_004a68d0;
  }
  uVar3 = iVar2 - param_2 >> 0x1f;
  dVar1 = (double)(int)((iVar2 - param_2 ^ uVar3) - uVar3) * _DAT_00485058;
  if ((DAT_004aa804 == 1) && (param_2 < iVar2)) {
    dVar1 = _DAT_00484e18;
  }
  if ((DAT_004aa804 == 3) && (iVar2 < param_2)) {
    dVar1 = _DAT_00484e18;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = dVar1;
  }
  return;
}

