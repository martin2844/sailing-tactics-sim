
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_0042f480(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  
  uVar1 = FUN_00427ee0(param_1,-param_2);
  uVar3 = (int)uVar1 >> 0x1f;
  iVar2 = (int)uVar1 / 2;
  if ((iVar2 < 0) || (0xb4 < iVar2)) {
    iVar2 = 0;
  }
  if ((((uVar1 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3) || (0xb2 < iVar2)) {
    fVar4 = (float10)(double)(&DAT_004ffdd8)[iVar2];
  }
  else {
    fVar4 = ((float10)(double)(&DAT_004ffdd8)[iVar2] + (float10)(double)(&DAT_004ffde0)[iVar2]) *
            (float10)_DAT_004cc4f8;
  }
  fVar4 = (float10)_DAT_004cc710 -
          ((float10)_DAT_004cc650 - SQRT((float10)(param_1 * param_1 + param_2 * param_2)) / fVar4)
          * (float10)_DAT_004cc928;
  if (fVar4 < (float10)_DAT_004cc658) {
    fVar4 = (float10)_DAT_004cc658;
  }
  return fVar4;
}

