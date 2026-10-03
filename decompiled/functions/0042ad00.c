
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

undefined4 __cdecl FUN_0042ad00(int param_1)

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
  int in_stack_00000008;
  
  uVar9 = 1;
  iVar1 = (int)(longlong)*(double *)(&DAT_004a4ae0 + in_stack_00000008 * 8);
  iVar2 = (int)(longlong)*(double *)(&DAT_004a49e8 + in_stack_00000008 * 8);
  uVar3 = iVar1 - DAT_004aa588 >> 0x1f;
  uVar4 = iVar2 - DAT_004aa38c >> 0x1f;
  uVar5 = iVar1 - DAT_004aa384 >> 0x1f;
  uVar6 = iVar2 - DAT_004aa288 >> 0x1f;
  uVar7 = iVar1 - DAT_004aa388 >> 0x1f;
  uVar8 = iVar2 - DAT_004aa294 >> 0x1f;
  if (((param_1 < (int)(((iVar1 - DAT_004aa388 ^ uVar7) - uVar7) +
                       ((iVar2 - DAT_004aa294 ^ uVar8) - uVar8))) &&
      (param_1 < (int)(((iVar1 - DAT_004aa588 ^ uVar3) - uVar3) +
                      ((iVar2 - DAT_004aa38c ^ uVar4) - uVar4)))) &&
     (param_1 < (int)(((iVar1 - DAT_004aa384 ^ uVar5) - uVar5) +
                     ((iVar2 - DAT_004aa288 ^ uVar6) - uVar6)))) {
    uVar9 = 0;
  }
  return uVar9;
}

