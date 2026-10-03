
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484720(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int aiStack_8 [2];
  
  if (DAT_004da148 + 3 <= param_3) {
    fVar8 = (float10)FUN_00406220(param_3,param_6);
    iVar6 = (int)(longlong)(fVar8 * (float10)_DAT_004cc730 * (float10)_DAT_004cd000);
    FUN_0046a700(param_1);
    if (param_4 == 3) {
      FUN_0046a730(param_1);
    }
    if (param_4 == 2) {
      FUN_0046a700(param_1);
    }
    if (3 < iVar6) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    if (DAT_00536450 == 1) {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    _DAT_004f6e2c = param_3;
    _DAT_004f6e54 = param_3;
    iVar1 = param_2 - iVar6;
    iVar7 = iVar6 / 2;
    iVar2 = param_3 - iVar7;
    iVar3 = param_2 - iVar7;
    iVar4 = param_2 + iVar7;
    _DAT_004f6e3c = (param_3 - iVar6 / 3) - iVar7;
    iVar5 = param_2 + iVar6;
    _DAT_004f6e5c = param_3 + iVar7;
    _DAT_004f6e28 = iVar1;
    _DAT_004f6e30 = iVar1;
    _DAT_004f6e34 = iVar2;
    _DAT_004f6e38 = iVar3;
    _DAT_004f6e40 = iVar4;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e48 = iVar5;
    _DAT_004f6e4c = iVar2;
    _DAT_004f6e50 = iVar5;
    _DAT_004f6e58 = iVar4;
    _DAT_004f6e60 = iVar3;
    _DAT_004f6e64 = _DAT_004f6e5c;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,8);
    if (3 < iVar6) {
      FUN_004b4d9d(param_1,aiStack_8,iVar1,iVar2);
      iVar7 = (iVar6 / 3 + param_3) - iVar7;
      CDC::LineTo(param_1,iVar3,iVar7);
      CDC::LineTo(param_1,iVar4,iVar7);
      CDC::LineTo(param_1,iVar5,iVar2);
    }
    iVar1 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
    FUN_004b4d9d(param_1,aiStack_8,param_2,param_3 - iVar1);
    iVar4 = param_3 + iVar6 * -2;
    CDC::LineTo(param_1,param_2,iVar4);
    Rectangle((HDC)param_1[1],param_2 - iVar1,iVar4,param_2 + iVar1,param_3 - iVar1);
    FUN_00469650(param_1);
    if (param_5 == 1) {
      iVar4 = (DAT_004fb9b8 + param_4) % 5;
    }
    else {
      iVar4 = (param_4 + DAT_004fb9b8) % 10;
    }
    if (iVar4 == 0) {
      if (param_4 < 2) {
        FUN_00469670(param_1);
      }
      else {
        if (param_4 == 3) {
          FUN_0046a730(param_1);
        }
        if (param_4 == 2) {
          FUN_0046a700(param_1);
        }
      }
      iVar6 = iVar6 + 1;
    }
    iVar4 = iVar6 / 2;
    if (iVar4 < 2) {
      iVar4 = 2;
    }
    FUN_00433a70(param_1,iVar4,param_2,param_3 + iVar6 * -2);
  }
  return;
}

