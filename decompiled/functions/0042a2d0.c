
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042a2d0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_0042abb0((DAT_004a763c < 0x385) + 1,param_1);
  if (iVar1 == 1) {
    if (param_1 <= DAT_00491140) {
      *(undefined4 *)(&DAT_004a89c0 + param_1 * 4) = 1;
    }
    if (DAT_004a5b80 < 0x14) {
      FUN_00421c40(param_1);
      FUN_0042a8a0(param_1);
    }
    else {
      FUN_0042a950(param_1);
    }
    *(int *)(&DAT_004abf18 + param_1 * 4) = DAT_004a5b80;
  }
  if ((DAT_004a5b80 < 0x33) && (DAT_004ac9ac != 1)) {
    fVar2 = FUN_00426f50(param_1);
    if ((fVar2 <= (float10)_DAT_00484e18) &&
       (((-3 < DAT_004a5b80 && (DAT_004a5b80 < 1)) && (2 < DAT_004911cc)))) {
      if (param_1 <= DAT_00491140) {
        *(undefined4 *)(&DAT_004a89c0 + param_1 * 4) = 2;
      }
      FUN_00421c40(param_1);
      FUN_0042a8a0(param_1);
      *(int *)(&DAT_004abf18 + param_1 * 4) = DAT_004a5b80;
    }
  }
  return;
}

