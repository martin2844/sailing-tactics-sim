
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042cf70(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (-1 < DAT_004a5b80) {
    if (DAT_004a5b80 < 0x1e) {
      *(undefined4 *)(&DAT_004a6ba0 + param_1 * 4) = 1;
    }
    FUN_0042c400((double)DAT_004aa594,(double)DAT_004aa59c,0,param_1);
    iVar6 = 1;
    do {
      iVar2 = FUN_00413cb0(DAT_004a4758 + 0xb4);
      iVar3 = FUN_00413cb0(*(int *)((int)&DAT_004a6444 + iVar7));
      if ((((iVar2 == iVar3) ||
           (uVar5 = iVar2 - iVar3 >> 0x1f, iVar4 = (iVar2 - iVar3 ^ uVar5) - uVar5, iVar4 == 0x168))
          || (iVar4 == 0x167)) || ((iVar2 == iVar3 + -1 || (iVar2 == iVar3 + 1)))) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (((iVar6 == *(int *)(&DAT_004a6ba0 + param_1 * 4)) && (bVar1)) &&
         (*(int *)((int)&DAT_004a645c + iVar7) + -0x14 <= (int)(longlong)_DAT_004a6828)) {
        *(int *)(&DAT_004a6ba0 + param_1 * 4) = *(int *)(&DAT_004a6ba0 + param_1 * 4) + 1;
      }
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar7 < 9);
    if (*(int *)(&DAT_004a6ba0 + param_1 * 4) == 4) {
      if ((DAT_004ac950 == 1) && (*(int *)(&DAT_004a72d8 + param_1 * 4) == 1)) {
        *(undefined4 *)(&DAT_004a6ba0 + param_1 * 4) = 1;
      }
      if (*(int *)(&DAT_004a6ba0 + param_1 * 4) == 4) {
        *(undefined4 *)(&DAT_004a6ba0 + param_1 * 4) = 0;
      }
    }
    return;
  }
  *(undefined4 *)(&DAT_004a6ba0 + param_1 * 4) = 0;
  return;
}

