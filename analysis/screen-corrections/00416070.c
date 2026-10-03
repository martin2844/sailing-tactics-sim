
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00416070(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000014;
  
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  FUN_00416420(param_1,in_stack_00000014);
  iVar3 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484da8);
  if (param_4 == 1) {
    iVar3 = (iVar3 * 3) / 2;
  }
  iVar1 = (DAT_004aa1a8 + DAT_004aa1d8 * 2) / 3;
  iVar4 = (DAT_004aa2a8 + DAT_004aa2d8 * 2) / 3 + iVar3;
  iVar2 = (DAT_004aa1ac + DAT_004aa1d4 * 2) / 3;
  iVar3 = (DAT_004aa2ac + DAT_004aa2d4 * 2) / 3 + iVar3;
  _DAT_004a4ca8 = DAT_004aa1e0;
  _DAT_004a4cac = DAT_004aa2e0;
  _DAT_004a4cb0 = DAT_004aa1dc;
  _DAT_004a4cb4 = DAT_004aa2dc;
  _DAT_004a4cb8 = DAT_004aa1d8;
  _DAT_004a4cbc = DAT_004aa2d8;
  _DAT_004a4cc8 = DAT_004a4384;
  _DAT_004a4ccc = DAT_004a6788;
  _DAT_004a4cc0 = iVar1;
  _DAT_004a4cc4 = iVar4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  _DAT_004a4ca8 = DAT_004aa1d8;
  _DAT_004a4cac = DAT_004aa2d8;
  _DAT_004a4cb0 = DAT_004aa1d4;
  _DAT_004a4cb4 = DAT_004aa2d4;
  _DAT_004a4cb8 = iVar2;
  _DAT_004a4cbc = iVar3;
  _DAT_004a4cc0 = iVar1;
  _DAT_004a4cc4 = iVar4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,4);
  _DAT_004a4ca8 = DAT_004aa1d4;
  _DAT_004a4cac = DAT_004aa2d4;
  _DAT_004a4cb0 = DAT_004aa1d0;
  _DAT_004a4cb4 = DAT_004aa2d0;
  _DAT_004a4cb8 = DAT_004aa1b4;
  _DAT_004a4cbc = DAT_004aa2b4;
  _DAT_004a4cc0 = DAT_004ac838;
  _DAT_004a4cc4 = DAT_004a3f88;
  _DAT_004a4cc8 = iVar2;
  _DAT_004a4ccc = iVar3;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  if (((DAT_004ac98c == 1) && (0 < in_stack_00000014)) && (DAT_004ac92c == 0)) {
    if (DAT_004a3a14 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a3a14);
    }
    if (DAT_004a676c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a676c);
    }
    FUN_00423640((int)param_1,2,DAT_004aa1b4,DAT_004aa2b4);
  }
  return;
}

