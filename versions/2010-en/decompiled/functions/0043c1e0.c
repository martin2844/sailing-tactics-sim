
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043c1e0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_0043ccf0((DAT_004fe624 < 0x385) + 1,param_1);
  if (iVar1 == 1) {
    if (param_1 <= DAT_004da140) {
      *(undefined4 *)(&DAT_005116e0 + param_1 * 4) = 1;
    }
    if (DAT_004f8cd0 < 0x14) {
      FUN_00431960(param_1);
      FUN_0043c980(param_1);
    }
    else {
      FUN_0043ca40(param_1);
    }
    *(int *)(&DAT_00535620 + param_1 * 4) = DAT_004f8cd0;
  }
  if (DAT_004f8cd0 < 0x33) {
    fVar2 = FUN_00437d40(param_1);
    if ((((fVar2 <= (float10)_DAT_004cc658) && (-3 < DAT_004f8cd0)) && (DAT_004f8cd0 < 1)) &&
       (2 < DAT_004da1d8)) {
      if (param_1 <= DAT_004da140) {
        *(undefined4 *)(&DAT_005116e0 + param_1 * 4) = 2;
      }
      FUN_00431960(param_1);
      FUN_0043c980(param_1);
      *(int *)(&DAT_00535620 + param_1 * 4) = DAT_004f8cd0;
    }
  }
  return;
}

