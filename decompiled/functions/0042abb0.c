
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

undefined4 __cdecl FUN_0042abb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  iVar1 = (int)(longlong)*(double *)(&DAT_004a49e8 + param_2 * 8);
  iVar2 = (int)(longlong)*(double *)(&DAT_004a4ae0 + param_2 * 8);
  uVar4 = iVar2 - DAT_004aa59c >> 0x1f;
  uVar5 = iVar1 - DAT_004aa594 >> 0x1f;
  iVar12 = ((iVar2 - DAT_004aa59c ^ uVar4) - uVar4) + ((iVar1 - DAT_004aa594 ^ uVar5) - uVar5);
  uVar4 = iVar1 - DAT_004aa294 >> 0x1f;
  uVar5 = iVar2 - DAT_004aa388 >> 0x1f;
  uVar6 = iVar1 - DAT_004aa38c >> 0x1f;
  uVar7 = iVar2 - DAT_004aa588 >> 0x1f;
  uVar8 = iVar1 - DAT_004aa288 >> 0x1f;
  uVar9 = iVar2 - DAT_004aa384 >> 0x1f;
  uVar10 = iVar2 - DAT_004a72c8 >> 0x1f;
  uVar11 = iVar1 - DAT_004a70f8 >> 0x1f;
  iVar3 = ((iVar2 - DAT_004a72c8 ^ uVar10) - uVar10) + ((iVar1 - DAT_004a70f8 ^ uVar11) - uVar11);
  if ((0xaa - *(int *)(&DAT_004a5f10 + param_2 * 4) < *(int *)(&DAT_004a7bc8 + param_2 * 4)) &&
     (0x1e < DAT_004a5b80)) {
    iVar3 = 1000;
    iVar12 = 1000;
  }
  if ((((param_1 < iVar12) &&
       (param_1 < (int)(((iVar1 - DAT_004aa294 ^ uVar4) - uVar4) +
                       ((iVar2 - DAT_004aa388 ^ uVar5) - uVar5)))) &&
      (param_1 < (int)(((iVar1 - DAT_004aa38c ^ uVar6) - uVar6) +
                      ((iVar2 - DAT_004aa588 ^ uVar7) - uVar7)))) &&
     ((param_1 < (int)(((iVar1 - DAT_004aa288 ^ uVar8) - uVar8) +
                      ((iVar2 - DAT_004aa384 ^ uVar9) - uVar9)) && (param_1 + 2 < iVar3)))) {
    return 0;
  }
  return 1;
}

