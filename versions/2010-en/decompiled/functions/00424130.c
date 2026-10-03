
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00424130(int *param_1,int param_2,double param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((((DAT_00535884 < param_5) && (0x19 < *(int *)(&DAT_004fdfe8 + param_2 * 4))) &&
      (DAT_004da174 < 0xc)) && (((DAT_005363b4 == 0 && (DAT_0053642c == 0)) && (0 < DAT_005363b0))))
  {
    iVar1 = (DAT_005228f8 + DAT_005228fc) / 2;
    iVar4 = (int)(longlong)(param_3 * _DAT_004cc690);
    iVar8 = 0x14;
    iVar7 = param_2 * 8;
    iVar2 = (DAT_005229f8 + DAT_005229fc) / 2 - iVar4;
    iVar3 = (DAT_00522920 + DAT_0052291c) / 2;
    iVar4 = (DAT_00522a20 + DAT_00522a1c) / 2 - iVar4;
    do {
      FUN_0043e730(0,*(double *)(&DAT_00510ea8 + iVar7),*(double *)(&DAT_00525510 + iVar7),param_6,0
                  );
      if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
        iVar5 = iVar3 - DAT_005228ec;
        iVar6 = iVar4;
      }
      else {
        iVar5 = iVar1 - DAT_005228ec;
        iVar6 = iVar2;
      }
      FUN_00423fe0(param_1,param_2,param_3,iVar5 + DAT_004fed58,
                   (iVar6 - DAT_005229ec) + DAT_00523660,iVar8,param_5);
      if (*(int *)(&DAT_004fc2c0 + param_2 * 4) < 7) {
        if (*(int *)(&DAT_00522ff0 + param_2 * 4) == 1) {
          iVar5 = iVar1 - DAT_005228ec;
          iVar6 = iVar2;
        }
        else {
          iVar5 = iVar3 - DAT_005228ec;
          iVar6 = iVar4;
        }
        FUN_00423fe0(param_1,param_2,param_3,iVar5 + DAT_004fed58,
                     (iVar6 - DAT_005229ec) + DAT_00523660,iVar8,param_5);
      }
      iVar8 = iVar8 + -1;
      iVar7 = iVar7 + -0x130;
    } while (1 < iVar8);
  }
  return;
}

