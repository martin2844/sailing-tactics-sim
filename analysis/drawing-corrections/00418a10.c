
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418a10(CDC *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int in_stack_00000014;
  
  (**(code **)(*(int *)param_1 + 0x2c))(param_1,8);
  FUN_00416420((int *)param_1,param_4);
  iVar1 = (DAT_004aa1c0 + DAT_004aa1c8 * 0xc + DAT_004aa1c4) / 0xe;
  iVar2 = (DAT_004aa2c0 + DAT_004aa2c8 * 0xc + DAT_004aa2c4) / 0xe -
          (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485038);
  _DAT_004a4ca8 = DAT_004aa1c8;
  _DAT_004a4cac = DAT_004aa2c8;
  _DAT_004a4cb8 = DAT_004aa1c4;
  _DAT_004a4cbc = DAT_004aa2c4 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485040);
  _DAT_004a4cc0 = DAT_004aa1bc;
  _DAT_004a4cc8 = DAT_004aa1bc;
  _DAT_004a4ccc = DAT_004aa2bc;
  _DAT_004a4cc4 = DAT_004aa2bc - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485048);
  _DAT_004a4cd0 = DAT_004aa1c4;
  _DAT_004a4cd4 = DAT_004aa2c4;
  _DAT_004a4cb0 = iVar1;
  _DAT_004a4cb4 = iVar2;
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,6);
  if (((*(int *)(&DAT_004aa730 + param_4 * 4) != 1) || (*(int *)(&DAT_004a6ec8 + param_4 * 4) < 8))
     && (0x28 < *(int *)(&DAT_004a7060 + param_4 * 4))) {
    FUN_00417eb0(param_1,param_2,param_3,iVar1,iVar2,9,in_stack_00000014);
  }
  return;
}

