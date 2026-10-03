
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */

int __cdecl FUN_0043ccf0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  local_8 = 1;
  iVar2 = (int)(longlong)*(double *)(&DAT_004f6af8 + param_2 * 8);
  iVar1 = (int)(longlong)*(double *)(&DAT_004f6c10 + param_2 * 8);
  uVar3 = iVar1 - DAT_00536414 >> 0x1f;
  uVar4 = iVar2 - DAT_00536410 >> 0x1f;
  iVar5 = ((iVar1 - DAT_00536414 ^ uVar3) - uVar3) + ((iVar2 - DAT_00536410 ^ uVar4) - uVar4);
  uVar3 = iVar2 - DAT_005229d4 >> 0x1f;
  uVar4 = iVar1 - DAT_00522ac8 >> 0x1f;
  iVar6 = ((iVar2 - DAT_005229d4 ^ uVar3) - uVar3) + ((iVar1 - DAT_00522ac8 ^ uVar4) - uVar4);
  uVar3 = iVar1 - DAT_00522ae0 >> 0x1f;
  uVar4 = iVar2 - DAT_00522acc >> 0x1f;
  iVar7 = ((iVar1 - DAT_00522ae0 ^ uVar3) - uVar3) + ((iVar2 - DAT_00522acc ^ uVar4) - uVar4);
  uVar3 = iVar2 - DAT_005229c8 >> 0x1f;
  uVar4 = iVar1 - DAT_00522ac4 >> 0x1f;
  iVar8 = ((iVar2 - DAT_005229c8 ^ uVar3) - uVar3) + ((iVar1 - DAT_00522ac4 ^ uVar4) - uVar4);
  uVar3 = iVar1 - DAT_004fe2a0 >> 0x1f;
  uVar4 = iVar2 - DAT_004fe094 >> 0x1f;
  iVar2 = ((iVar1 - DAT_004fe2a0 ^ uVar3) - uVar3) + ((iVar2 - DAT_004fe094 ^ uVar4) - uVar4);
  if ((0xaa - *(int *)(&DAT_004fae60 + param_2 * 4) < *(int *)(&DAT_004fecc8 + param_2 * 4)) &&
     (0x1e < DAT_004f8cd0)) {
    iVar2 = 1000;
    iVar5 = 1000;
  }
  if (DAT_004f8cd0 < 0x1e) {
    iVar8 = 1000;
  }
  if (((((DAT_0053527c == 0) || (*(int *)(&DAT_004f8538 + param_2 * 4) != DAT_004da1e4)) &&
       (param_1 < iVar5)) && ((param_1 < iVar6 && (param_1 < iVar7)))) &&
     ((param_1 < iVar8 && (param_1 + 3 < iVar2)))) {
    local_8 = 0;
  }
  if (((DAT_0053527c == 0) && (10 < DAT_004f8cd0)) &&
     ((*(int *)(&DAT_004f8538 + param_2 * 4) != DAT_004da1e4 &&
      (((param_1 < iVar6 && (param_1 < iVar7)) && (param_1 < iVar8)))))) {
    local_8 = 0;
  }
  if (((DAT_0053527c == 1) && (param_1 < iVar5)) &&
     ((param_1 < iVar6 && ((param_1 < iVar7 && (param_1 + 3 < iVar2)))))) {
    local_8 = 0;
  }
  return local_8;
}

