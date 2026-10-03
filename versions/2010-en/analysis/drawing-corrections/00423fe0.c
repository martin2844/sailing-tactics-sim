
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
FUN_00423fe0(int *param_1,int param_2,double param_3,int param_4,int param_5,int param_6,int param_7
            )

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_6 >> 0x1f;
  if ((((param_2 < 2) || (((param_6 ^ uVar5) - uVar5 & 1 ^ uVar5) != uVar5)) ||
      (iVar1 = 0, DAT_005363b8 != 0)) &&
     (((iVar3 = (-(uint)(DAT_005363b8 != 1) & 3) + 1, param_2 < 2 ||
       (DAT_00535884 - DAT_004fe2a8 / 10 <= param_7)) ||
      (iVar1 = param_6 / iVar3, param_6 % iVar3 != 0)))) {
    iVar3 = (int)(longlong)(param_3 * _DAT_004cc8d0);
    if (DAT_005363b8 == 1) {
      iVar3 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    }
    if ((((param_2 < 2) || (DAT_005363b8 != 0)) && (DAT_005364c8 != 1)) ||
       (iVar3 = iVar3 / 2, DAT_005364c8 != 1)) {
      iVar2 = *(int *)(&DAT_004fdfe8 + param_2 * 4);
      iVar1 = iVar2 + (iVar2 >> 0x1f & 0xfU);
      iVar4 = iVar1 >> 4;
    }
    else {
      iVar2 = *(int *)(&DAT_004fdfe8 + param_2 * 4);
      iVar1 = iVar2 + (iVar2 >> 0x1f & 7U);
      iVar4 = iVar1 >> 3;
    }
    if (DAT_005363b8 == 1) {
      iVar1 = iVar2 + (iVar2 >> 0x1f & 0x1fU);
      iVar4 = iVar1 >> 5;
    }
    if (1 < iVar4) {
      param_2 = iVar4 + -1;
      do {
        iVar1 = FUN_0041e000(iVar3);
        iVar2 = FUN_0041e000(iVar3);
        FUN_00424320(param_1,iVar1 + (param_4 - iVar3 / 2),iVar2 + (param_5 - iVar3 / 2),0);
        param_2 = param_2 + -1;
        iVar1 = 0;
      } while (param_2 != 0);
    }
  }
  return iVar1;
}

