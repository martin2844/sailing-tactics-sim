
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

undefined4 FUN_0043ceb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  uVar9 = 1;
  iVar1 = (int)(longlong)*(double *)(&DAT_004f6af8 + param_2 * 8);
  iVar2 = (int)(longlong)*(double *)(&DAT_004f6c10 + param_2 * 8);
  uVar3 = iVar1 - DAT_00522acc >> 0x1f;
  uVar4 = iVar2 - DAT_00522ae0 >> 0x1f;
  uVar5 = iVar2 - DAT_00522ac4 >> 0x1f;
  uVar6 = iVar1 - DAT_005229c8 >> 0x1f;
  uVar7 = iVar2 - DAT_00522ac8 >> 0x1f;
  uVar8 = iVar1 - DAT_005229d4 >> 0x1f;
  if (((param_1 < (int)(((iVar2 - DAT_00522ac8 ^ uVar7) - uVar7) +
                       ((iVar1 - DAT_005229d4 ^ uVar8) - uVar8))) &&
      (param_1 < (int)(((iVar1 - DAT_00522acc ^ uVar3) - uVar3) +
                      ((iVar2 - DAT_00522ae0 ^ uVar4) - uVar4)))) &&
     (param_1 < (int)(((iVar2 - DAT_00522ac4 ^ uVar5) - uVar5) +
                     ((iVar1 - DAT_005229c8 ^ uVar6) - uVar6)))) {
    uVar9 = 0;
  }
  return uVar9;
}

