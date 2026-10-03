
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_00420d10(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  
  uVar1 = FUN_0041bb10(param_1,-param_2);
  uVar3 = (int)uVar1 >> 0x1f;
  iVar2 = (int)uVar1 / 2;
  if ((iVar2 < 0) || (0xb4 < iVar2)) {
    iVar2 = 0;
  }
  if ((((uVar1 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3) || (0xb2 < iVar2)) {
    fVar4 = (float10)(double)(&DAT_004a8028)[iVar2];
  }
  else {
    fVar4 = ((float10)(double)(&DAT_004a8028)[iVar2] + (float10)(double)(&DAT_004a8030)[iVar2]) *
            (float10)_DAT_00484da8;
  }
  fVar4 = (float10)_DAT_00484e88 -
          ((float10)_DAT_00484e10 - SQRT((float10)(param_1 * param_1 + param_2 * param_2)) / fVar4)
          * (float10)_DAT_004850e0;
  if (fVar4 < (float10)_DAT_00484e18) {
    fVar4 = (float10)_DAT_00484e18;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = (double)fVar4;
  }
  return fVar4;
}

