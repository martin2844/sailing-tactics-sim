
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042a3b0(int param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (((DAT_0049118c != 2) || (param_1 != 2)) || (DAT_00491168 <= DAT_004a5b80)) {
    iVar1 = param_1 * 4;
    dVar2 = ((double)*(int *)(&DAT_004a6f48 + iVar1) - *(double *)(&DAT_004a4ae0 + param_1 * 8)) *
            ((double)*(int *)(&DAT_004a6f48 + iVar1) - *(double *)(&DAT_004a4ae0 + param_1 * 8)) +
            ((double)*(int *)(&DAT_004a4888 + iVar1) - *(double *)(&DAT_004a49e8 + param_1 * 8)) *
            ((double)*(int *)(&DAT_004a4888 + iVar1) - *(double *)(&DAT_004a49e8 + param_1 * 8));
    iVar7 = 0xc;
    if (DAT_00491190 < 0xd) {
      iVar7 = DAT_00491190;
    }
    if ((DAT_00491194 == 8) && (DAT_004a5a4c == 0)) {
      iVar7 = 0;
    }
    if (DAT_00491190 == 2) {
      iVar7 = -5;
    }
    if (DAT_00491190 == 1) {
      iVar7 = -10;
    }
    dVar3 = _DAT_00484e18;
    if (2 < DAT_0049118c) {
      iVar5 = FUN_00415a20(0x11);
      dVar3 = (double)iVar5;
    }
    dVar4 = _DAT_00484e18;
    if (_DAT_00484e18 < dVar2) {
      dVar4 = (SQRT(dVar2) - (double)((0xf - iVar7) * 4)) - dVar3;
    }
    dVar2 = (double)*(int *)(&DAT_004a6e48 + iVar1) * _DAT_00484dd8;
    if ((double)*(int *)(&DAT_004a6e48 + iVar1) * _DAT_00484dd8 <= _DAT_00484eb8) {
      dVar2 = _DAT_00484eb8;
    }
    if (0 < *(int *)(&DAT_004a7868 + iVar1)) {
      dVar2 = _DAT_00484da8;
    }
    dVar2 = -((dVar2 * _DAT_004ac1f8) / _DAT_004ab0c0);
    if ((dVar2 <= _DAT_00484e18) || (dVar2 <= dVar4)) {
      uVar6 = 100;
    }
    else {
      uVar6 = (undefined4)(longlong)((dVar4 * _DAT_00485020) / dVar2);
    }
    if (*(int *)(&DAT_004a7868 + iVar1) < 1) {
      return uVar6;
    }
  }
  return 100;
}

