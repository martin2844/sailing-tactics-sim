
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004223c0(int *param_1,double param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_4;
  
  piVar1 = param_1;
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  FUN_0041ed90(param_1,param_3);
  iStack_4 = (DAT_00522900 + DAT_00522908 * 0xc + DAT_00522904) / 0xe;
  if ((DAT_005364cc == 1) ||
     (iVar3 = (DAT_00522a00 + DAT_00522a08 * 0xc + DAT_00522a04) / 0xe, DAT_004da190 == 9)) {
    iStack_4 = DAT_00522908;
    iVar3 = DAT_00522a08;
  }
  param_1 = (int *)(iVar3 + (int)(longlong)(param_2 * _DAT_004cc778));
  _DAT_004f6e2c = DAT_00522a08;
  _DAT_004f6e28 = DAT_00522908;
  _DAT_004f6e30 = iStack_4;
  _DAT_004f6e34 = param_1;
  _DAT_004f6e38 = DAT_00522904;
  _DAT_004f6e40 = DAT_005228fc;
  _DAT_004f6e3c = DAT_00522a04 - (int)(longlong)(param_2 * _DAT_004cc890);
  _DAT_004f6e48 = DAT_005228fc;
  _DAT_004f6e4c = DAT_005229fc;
  _DAT_004f6e44 = DAT_005229fc - (int)(longlong)(param_2 * _DAT_004cc898);
  _DAT_004f6e50 = DAT_00522904;
  _DAT_004f6e54 = DAT_00522a04;
  Polygon((HDC)piVar1[1],(POINT *)&DAT_004f6e28,6);
  if (DAT_00536450 == 1) {
    FUN_0046a730(piVar1);
    if (DAT_004da204 < 0x32) {
      uVar2 = 3;
      iVar3 = DAT_00522a08 + -1;
    }
    else {
      uVar2 = 2;
      iVar3 = DAT_00522a08;
    }
    FUN_00433a70(piVar1,uVar2,DAT_00522908,iVar3);
  }
  if (((*(int *)(&DAT_00522ff0 + param_3 * 4) != 1) || (*(int *)(&DAT_004fc2c0 + param_3 * 4) < 8))
     && (0x28 < *(int *)(&DAT_004fdfe8 + param_3 * 4))) {
    FUN_004217d0(piVar1,param_2,iStack_4,param_1,9,param_4);
  }
  return;
}

