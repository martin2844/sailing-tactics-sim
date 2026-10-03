
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

void __cdecl FUN_00427fd0(int param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (*(int *)(&DAT_004a7970 + param_1 * 4) + 5 <= DAT_004a5b80) {
    *(undefined4 *)(&DAT_004a76d0 + param_1 * 4) = 0;
  }
  iVar5 = 1;
  if (0 < DAT_0049118c) {
    do {
      if (param_1 != iVar5) {
        dVar2 = (double)(*(int *)(&DAT_004a9988 + param_1 * 4) -
                        *(int *)((int)&DAT_004a998c + iVar4));
        dVar1 = (double)(*(int *)(&DAT_004a9908 + param_1 * 4) -
                        *(int *)((int)&DAT_004a990c + iVar4));
        iVar3 = (int)(longlong)SQRT(dVar2 * dVar2 + dVar1 * dVar1);
        if (iVar3 < 9) {
          if (DAT_00491140 < param_1) {
            FUN_004280c0(iVar3,iVar5,param_1,2);
          }
          else {
            FUN_004286e0(iVar3,iVar5,param_1);
          }
          iVar3 = FUN_00413cb0(*(int *)(&DAT_004ac018 + param_1 * 4));
          *(int *)(&DAT_004ac018 + param_1 * 4) = iVar3;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar5 <= DAT_0049118c);
  }
  return;
}

