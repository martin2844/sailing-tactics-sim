
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

void __cdecl FUN_00439100(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (*(int *)(&DAT_004fe9d0 + param_1 * 4) + 5 <= DAT_004f8cd0) {
    *(undefined4 *)(&DAT_004fe6d0 + param_1 * 4) = 0;
  }
  iVar5 = 1;
  if (0 < DAT_004da194) {
    do {
      if (param_1 != iVar5) {
        dVar2 = (double)(*(int *)(&DAT_00513510 + param_1 * 4) -
                        *(int *)((int)&DAT_00513514 + iVar4));
        dVar1 = (double)(*(int *)(&DAT_00513480 + param_1 * 4) -
                        *(int *)((int)&DAT_00513484 + iVar4));
        iVar3 = (int)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
        if (iVar3 < 9) {
          if (DAT_004da140 < param_1) {
            FUN_004391f0(iVar3,iVar5,param_1,2);
          }
          else {
            FUN_00439a30(iVar3,iVar5,param_1);
          }
          iVar3 = FUN_0041bc20(*(int *)(&DAT_00535740 + param_1 * 4));
          *(int *)(&DAT_00535740 + param_1 * 4) = iVar3;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar5 <= DAT_004da194);
  }
  return;
}

