
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0043c2c0(int param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  
  if (((DAT_004da194 != 2) || (param_1 != 2)) || (DAT_004da170 <= DAT_004f8cd0)) {
    iVar1 = param_1 * 4;
    dVar2 = ((double)*(int *)(&DAT_004fc350 + iVar1) - *(double *)(&DAT_004f6c10 + param_1 * 8)) *
            ((double)*(int *)(&DAT_004fc350 + iVar1) - *(double *)(&DAT_004f6c10 + param_1 * 8)) +
            ((double)*(int *)(&DAT_004f4d78 + iVar1) - *(double *)(&DAT_004f6af8 + param_1 * 8)) *
            ((double)*(int *)(&DAT_004f4d78 + iVar1) - *(double *)(&DAT_004f6af8 + param_1 * 8));
    iVar6 = 0xc;
    if (DAT_004da198 < 0xd) {
      iVar6 = DAT_004da198;
    }
    if ((DAT_004da19c == 8) && (DAT_004f8b78 == 0)) {
      iVar6 = 0;
    }
    if (DAT_004da198 == 2) {
      iVar6 = -5;
    }
    if (DAT_004da198 == 1) {
      iVar6 = -10;
    }
    dVar3 = _DAT_004cc658;
    if (2 < DAT_004da194) {
      iVar5 = FUN_0041e000(0x11);
      dVar3 = (double)iVar5;
    }
    dVar4 = _DAT_004cc658;
    if (_DAT_004cc658 < dVar2) {
      dVar4 = (SQRT(dVar2) - (double)((0xf - iVar6) * 4)) - dVar3;
    }
    dVar2 = (double)*(int *)(&DAT_004fc230 + iVar1) * _DAT_004cc618;
    if ((double)*(int *)(&DAT_004fc230 + iVar1) * _DAT_004cc618 <= _DAT_004cc730) {
      dVar2 = _DAT_004cc730;
    }
    if (0 < *(int *)(&DAT_004fe8a8 + iVar1)) {
      dVar2 = _DAT_004cc4f8;
    }
    dVar2 = -((dVar2 * _DAT_005359f0) / _DAT_00523d48);
    if ((dVar2 <= _DAT_004cc658) || (dVar2 <= dVar4)) {
      iVar6 = 100;
    }
    else {
      iVar6 = (int)(longlong)((dVar4 * _DAT_004cc488) / dVar2);
    }
    if (*(int *)(&DAT_004fe8a8 + iVar1) < 1) {
      return iVar6;
    }
  }
  return 100;
}

