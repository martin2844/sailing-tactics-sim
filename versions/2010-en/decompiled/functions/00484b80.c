
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484b80(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int aiStack_8 [2];
  
  if (DAT_004da148 + 4 <= param_3) {
    fVar7 = (float10)FUN_00406220(param_3,param_4);
    iVar6 = (int)(longlong)(fVar7 * (float10)_DAT_004cc9d0);
    FUN_0046a730(param_1);
    if (3 < iVar6) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    if (DAT_00536450 == 1) {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    iVar5 = param_3 + iVar6 * -2;
    iVar3 = param_2 - iVar6 / 2;
    iVar1 = iVar6 / 3;
    _DAT_004f6e3c = (param_3 + iVar6 * -2) - iVar1;
    iVar4 = iVar6 / 2 + param_2;
    iVar2 = param_2 + iVar6;
    param_2 = param_2 - iVar6;
    _DAT_004f6e5c = iVar1 + param_3;
    _DAT_004f6e2c = param_3;
    _DAT_004f6e54 = param_3;
    _DAT_004f6e28 = param_2;
    _DAT_004f6e30 = param_2;
    _DAT_004f6e34 = iVar5;
    _DAT_004f6e38 = iVar3;
    _DAT_004f6e40 = iVar4;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e48 = iVar2;
    _DAT_004f6e4c = iVar5;
    _DAT_004f6e50 = iVar2;
    _DAT_004f6e58 = iVar4;
    _DAT_004f6e60 = iVar3;
    _DAT_004f6e64 = _DAT_004f6e5c;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,8);
    if (3 < iVar6) {
      FUN_004b4d9d(param_1,aiStack_8,param_2,iVar5);
      iVar6 = param_3 + iVar1 + iVar6 * -2;
      CDC::LineTo(param_1,iVar3,iVar6);
      CDC::LineTo(param_1,iVar4,iVar6);
      CDC::LineTo(param_1,iVar2,iVar5);
    }
  }
  return;
}

