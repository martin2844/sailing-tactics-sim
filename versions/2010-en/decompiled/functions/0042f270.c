
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0042f270(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = (param_1 - DAT_004fb6c0) / 0xfa + 2;
  if (iVar3 < 2) {
    iVar3 = 2;
  }
  iVar1 = (int)(longlong)
               ((double)(int)((&DAT_004fbc3c)[iVar3] - (&DAT_004fbc38)[iVar3]) *
               (double)(param_1 - (&DAT_004fb6b8)[iVar3]) * _DAT_004cc918) + (&DAT_004fbc38)[iVar3];
  if (iVar3 < 3) {
    iVar1 = DAT_004fbc40;
  }
  uVar2 = iVar1 - param_2 >> 0x1f;
  fVar4 = (float10)(int)((iVar1 - param_2 ^ uVar2) - uVar2) * (float10)_DAT_004cc8a8;
  if ((DAT_005230dc == 1) && (param_2 < iVar1)) {
    fVar4 = (float10)_DAT_004cc658;
  }
  if ((DAT_005230dc == 3) && (iVar1 < param_2)) {
    fVar4 = (float10)_DAT_004cc658;
  }
  return fVar4;
}

