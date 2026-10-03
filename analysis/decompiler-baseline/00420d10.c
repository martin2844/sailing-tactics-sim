
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00420d10(int param_1,int param_2,int param_3)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = FUN_0041bb10(param_1,-param_2);
  uVar4 = (int)uVar2 >> 0x1f;
  iVar3 = (int)uVar2 / 2;
  if ((iVar3 < 0) || (0xb4 < iVar3)) {
    iVar3 = 0;
  }
  if ((((uVar2 ^ uVar4) - uVar4 & 1 ^ uVar4) == uVar4) || (0xb2 < iVar3)) {
    dVar1 = (double)(&DAT_004a8028)[iVar3];
  }
  else {
    dVar1 = ((double)(&DAT_004a8028)[iVar3] + (double)(&DAT_004a8030)[iVar3]) * _DAT_00484da8;
  }
  dVar1 = _DAT_00484e88 -
          (_DAT_00484e10 - SQRT((double)(param_1 * param_1 + param_2 * param_2)) / dVar1) *
          _DAT_004850e0;
  if (dVar1 < _DAT_00484e18) {
    dVar1 = _DAT_00484e18;
  }
  if (0 < param_3) {
    *(double *)(&DAT_004a7f28 + param_3 * 8) = dVar1;
  }
  return;
}

