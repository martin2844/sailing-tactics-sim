
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00487020(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int aiStack_14 [2];
  int iStack_c;
  int aiStack_8 [2];
  
  if (DAT_004da148 + 3 <= param_3) {
    fVar6 = (float10)FUN_00406220(param_3,param_4);
    iVar5 = (int)(longlong)(fVar6 * (float10)_DAT_004cc580);
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,0);
    (*pcVar1)(param_1,7);
    if ((DAT_00536450 == 1) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    _DAT_004f6e2c = param_3;
    _DAT_004f6e54 = param_3;
    _DAT_004f6e28 = param_2 - iVar5;
    iVar4 = iVar5 / 2;
    iVar2 = param_3 - iVar4;
    iVar3 = param_2 - iVar4;
    _DAT_004f6e40 = param_2 + iVar4;
    _DAT_004f6e3c = (param_3 - iVar5 / 3) - iVar4;
    _DAT_004f6e48 = param_2 + iVar5;
    _DAT_004f6e5c = param_3 + iVar4;
    _DAT_004f6e30 = _DAT_004f6e28;
    _DAT_004f6e34 = iVar2;
    _DAT_004f6e38 = iVar3;
    _DAT_004f6e44 = _DAT_004f6e3c;
    _DAT_004f6e4c = iVar2;
    _DAT_004f6e50 = _DAT_004f6e48;
    _DAT_004f6e58 = _DAT_004f6e40;
    _DAT_004f6e60 = iVar3;
    _DAT_004f6e64 = _DAT_004f6e5c;
    aiStack_14[0] = _DAT_004f6e28;
    iStack_c = _DAT_004f6e40;
    aiStack_8[0] = _DAT_004f6e48;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,8);
    if (3 < iVar5) {
      if (DAT_00536450 == 0) {
        if (DAT_005362ec != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005362ec);
        }
      }
      else {
        (*pcVar1)(param_1,7);
      }
      FUN_004b4d9d(param_1,aiStack_14,aiStack_14[0],iVar2);
      aiStack_14[0] = (iVar5 / 3 + param_3) - iVar4;
      CDC::LineTo(param_1,iVar3,aiStack_14[0]);
      CDC::LineTo(param_1,iStack_c,aiStack_14[0]);
      CDC::LineTo(param_1,aiStack_8[0],iVar2);
    }
    iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    FUN_004b4d9d(param_1,aiStack_8,param_2,param_3 - iVar2);
    iVar5 = param_3 + iVar5 * -2;
    CDC::LineTo(param_1,param_2,iVar5);
    if (DAT_00536450 == 0) {
      (*pcVar1)(param_1,0);
    }
    Rectangle((HDC)param_1[1],param_2 - iVar2,iVar5,param_2 + iVar2,param_3 - iVar2);
    if (((DAT_005364e8 < 0x1e) || (DAT_005364e8 == 0x2d)) || (DAT_005364e8 == 0x2e)) {
      FUN_00469670(param_1);
    }
    else {
      (*pcVar1)(param_1,4);
    }
    FUN_00433a70(param_1,iVar4 + 1,param_2,iVar5);
  }
  return;
}

