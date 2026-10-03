
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004849e0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int aiStack_8 [2];
  
  if (DAT_004da148 + 4 <= param_3) {
    fVar6 = (float10)FUN_00406220(param_3,param_4);
    if (0 < DAT_00536444) {
      fVar6 = fVar6 * (float10)_DAT_004cc4f8;
    }
    iVar5 = (int)(longlong)(fVar6 * (float10)_DAT_004cc9d0);
    FUN_0046a700(param_1);
    if (DAT_00536450 == 1) {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    if (3 < iVar5) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    iVar3 = param_3 + iVar5 * -2;
    _DAT_004f6e3c = param_3 + iVar5 * -5;
    iVar1 = iVar5 + param_2;
    _DAT_004f6e38 = param_2;
    iVar4 = param_2 - iVar5;
    iVar2 = iVar5 / 2 + param_2;
    _DAT_004f6e2c = param_3;
    _DAT_004f6e54 = param_3 + iVar5 / 3;
    param_2 = param_2 - iVar5 / 2;
    _DAT_004f6e4c = param_3;
    _DAT_004f6e28 = iVar4;
    _DAT_004f6e30 = iVar4;
    _DAT_004f6e34 = iVar3;
    _DAT_004f6e40 = iVar1;
    _DAT_004f6e44 = iVar3;
    _DAT_004f6e48 = iVar1;
    _DAT_004f6e50 = iVar2;
    _DAT_004f6e58 = param_2;
    _DAT_004f6e5c = _DAT_004f6e54;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,7);
    if (3 < iVar5) {
      FUN_004b4d9d(param_1,aiStack_8,iVar4,iVar3);
      iVar5 = param_3 + iVar5 * -2 + iVar5 / 3;
      CDC::LineTo(param_1,param_2,iVar5);
      CDC::LineTo(param_1,iVar2,iVar5);
      CDC::LineTo(param_1,iVar1,iVar3);
    }
  }
  return;
}

