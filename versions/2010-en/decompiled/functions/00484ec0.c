
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484ec0(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int aiStack_10 [2];
  int aiStack_8 [2];
  
  if (DAT_004fe2a8 / 0x96 + DAT_004da148 <= param_3) {
    fVar5 = (float10)FUN_00406220(param_3,param_5);
    iVar1 = (int)(longlong)(fVar5 * (float10)_DAT_004cc7a0);
    FUN_0046a700(param_1);
    if (param_4 == 3) {
      FUN_0046a730(param_1);
    }
    if (3 < iVar1) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    if (DAT_00536450 == 1) {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    _DAT_004f6e2c = param_3;
    _DAT_004f6e28 = param_2 - iVar1;
    iVar4 = iVar1 / 2;
    iVar2 = param_2 - iVar4;
    iVar3 = param_3 - iVar4;
    _DAT_004f6e3c = (param_3 - iVar1 / 2) - iVar1 / 3;
    _DAT_004f6e40 = param_2 + iVar4;
    _DAT_004f6e48 = iVar1 + param_2;
    _DAT_004f6e54 = param_3;
    _DAT_004f6e5c = param_3 + iVar4;
    _DAT_004f6e30 = _DAT_004f6e28;
    _DAT_004f6e34 = iVar3;
    _DAT_004f6e38 = iVar2;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e4c = iVar3;
    _DAT_004f6e50 = _DAT_004f6e48;
    _DAT_004f6e58 = _DAT_004f6e40;
    _DAT_004f6e60 = iVar2;
    _DAT_004f6e64 = _DAT_004f6e5c;
    aiStack_10[0] = _DAT_004f6e28;
    aiStack_8[0] = _DAT_004f6e40;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,8);
    if (3 < iVar1) {
      FUN_004b4d9d(param_1,aiStack_10,aiStack_10[0],iVar3);
      iVar4 = (param_3 + iVar1 / 3) - iVar4;
      CDC::LineTo(param_1,iVar2,iVar4);
      CDC::LineTo(param_1,aiStack_8[0],iVar4);
      CDC::LineTo(param_1,iVar1 + param_2,iVar3);
    }
    if (DAT_00536450 == 0) {
      if ((param_4 == 2) && (DAT_004fb6ac != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fb6ac);
      }
      if (((DAT_00536450 == 0) && (param_4 == 3)) && (DAT_004fb244 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004fb244);
      }
    }
    FUN_00433a70(param_1,(int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2,param_2,param_3 - iVar1);
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    iVar2 = (iVar1 * 2) / 3;
    FUN_004b4d9d(param_1,aiStack_8,param_2 - iVar2,iVar3);
    param_3 = param_3 + iVar1 * -2;
    CDC::LineTo(param_1,param_2,param_3);
    FUN_004b4d9d(param_1,aiStack_8,param_2 + iVar2,iVar3);
    CDC::LineTo(param_1,param_2,param_3);
    FUN_004b4d9d(param_1,aiStack_8,param_2,iVar3);
    CDC::LineTo(param_1,param_2,param_3);
  }
  return;
}

