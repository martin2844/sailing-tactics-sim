
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00421630(int *param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iStack_4;
  
  piVar2 = param_1;
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  FUN_0041ed90(param_1,param_3);
  iStack_4 = (DAT_00522914 + DAT_00522910 * 0xc + DAT_00522918) / 0xe;
  if ((DAT_005364cc == 1) ||
     (iVar1 = (DAT_00522a14 + DAT_00522a10 * 0xc + DAT_00522a18) / 0xe, DAT_004da190 == 9)) {
    iStack_4 = DAT_00522910;
    iVar1 = DAT_00522a10;
  }
  param_1 = (int *)(iVar1 + (int)(longlong)(param_2 * _DAT_004cc778));
  _DAT_004f6e2c = DAT_00522a10;
  _DAT_004f6e28 = DAT_00522910;
  _DAT_004f6e30 = iStack_4;
  _DAT_004f6e34 = param_1;
  _DAT_004f6e38 = DAT_00522914;
  _DAT_004f6e40 = DAT_0052291c;
  _DAT_004f6e3c = DAT_00522a14 - (int)(longlong)(param_2 * _DAT_004cc890);
  _DAT_004f6e48 = DAT_0052291c;
  _DAT_004f6e4c = DAT_00522a1c;
  _DAT_004f6e44 = DAT_00522a1c - (int)(longlong)(param_2 * _DAT_004cc898);
  _DAT_004f6e50 = DAT_00522914;
  _DAT_004f6e54 = DAT_00522a14;
  Polygon((HDC)piVar2[1],(POINT *)&DAT_004f6e28,6);
  if (((*(int *)(&DAT_00522ff0 + param_3 * 4) != -1) || (*(int *)(&DAT_004fc2c0 + param_3 * 4) < 8))
     && (0x28 < *(int *)(&DAT_004fdfe8 + param_3 * 4))) {
    FUN_004217d0(piVar2,param_2,iStack_4,param_1,0xd,param_4);
  }
  return;
}

