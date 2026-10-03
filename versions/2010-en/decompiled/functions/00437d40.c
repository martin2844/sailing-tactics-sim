
float10 __cdecl FUN_00437d40(int param_1)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  
  if ((DAT_004da1f8 == 5) && (DAT_004f8cd0 < 10)) {
    local_18 = 0xba5e353f;
    uStack_14 = 0x3ff00c49;
  }
  else {
    local_18 = 0;
    uStack_14 = 0x3ff00000;
  }
  dVar1 = *(double *)(&DAT_004f6af8 + param_1 * 8) - (double)DAT_005229d4;
  dVar2 = (double)((DAT_00536410 + DAT_004fe094) / 2) - (double)DAT_005229d4;
  fVar3 = (float10)((DAT_004fe2a0 + DAT_00536414) / 2) - (float10)DAT_00522ac8;
  return (float10)(SQRT((*(double *)(&DAT_004f6c10 + param_1 * 8) - (double)DAT_00522ac8) *
                        (*(double *)(&DAT_004f6c10 + param_1 * 8) - (double)DAT_00522ac8) +
                        dVar1 * dVar1) * (double)CONCAT44(uStack_14,local_18)) -
         SQRT(fVar3 * fVar3 + (float10)dVar2 * (float10)dVar2);
}

