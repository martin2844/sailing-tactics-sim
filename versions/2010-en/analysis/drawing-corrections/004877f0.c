
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004877f0(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int left;
  float10 fVar6;
  int iStack_14;
  int aiStack_8 [2];
  
  iVar2 = param_2;
  fVar6 = (float10)FUN_00406220(param_3,param_4);
  param_4 = (int)(longlong)(fVar6 * (float10)_DAT_004cc458);
  if (1000 < param_4) {
    param_4 = 1000;
  }
  if (DAT_004da204 < 0x33) {
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    if ((DAT_00536450 == 1) && (DAT_005362fc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005362fc);
    }
  }
  else {
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,5);
  iVar3 = param_4 / 3;
  iVar4 = 4;
  if (DAT_004da1f8 == 0x69) {
    iVar3 = (int)(param_4 + (param_4 >> 0x1f & 3U)) >> 2;
    iVar4 = 5;
  }
  iStack_14 = param_2 + iVar3;
  param_2 = param_2 - iVar3;
  iVar4 = param_4 / iVar4;
  iVar5 = param_3 - iVar4;
  left = iVar2 - iVar4;
  iVar3 = iVar2 + iVar4;
  iVar4 = iVar5 - iVar4;
  FUN_004b4d9d(param_1,aiStack_8,left,iVar5);
  CDC::LineTo(param_1,param_2,param_3);
  FUN_004b4d9d(param_1,aiStack_8,iVar3,iVar5);
  CDC::LineTo(param_1,iStack_14,param_3);
  FUN_004b4d9d(param_1,aiStack_8,iVar2,iVar5);
  CDC::LineTo(param_1,iVar2,param_3);
  FUN_004b4d9d(param_1,aiStack_8,(left + iVar2) / 2,iVar5);
  CDC::LineTo(param_1,(param_2 + iVar2) / 2,param_3);
  FUN_004b4d9d(param_1,aiStack_8,(iVar3 + iVar2) / 2,iVar5);
  CDC::LineTo(param_1,(iStack_14 + iVar2) / 2,param_3);
  (*pcVar1)(param_1,7);
  if (DAT_00536450 == 0) {
    (*pcVar1)(param_1,0);
  }
  else if (DAT_005230cc != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_005230cc);
  }
  Rectangle((HDC)param_1[1],left,iVar5,iVar3,iVar4);
  if (DAT_004da1f8 == 0x69) {
    (*pcVar1)(param_1,0);
  }
  else if (DAT_004fb6ac != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004fb6ac);
  }
  if ((DAT_00536450 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  _DAT_004f6e38 = (int)(param_4 + (param_4 >> 0x1f & 7U)) >> 3;
  _DAT_004f6e30 = left + _DAT_004f6e38;
  iVar5 = iVar4 - param_4 / 6;
  _DAT_004f6e38 = iVar3 - _DAT_004f6e38;
  _DAT_004f6e28 = left;
  _DAT_004f6e2c = iVar4;
  _DAT_004f6e34 = iVar5;
  _DAT_004f6e3c = iVar5;
  _DAT_004f6e40 = iVar3;
  _DAT_004f6e44 = iVar4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  param_4 = param_4 / 0x14;
  if (param_4 < 2) {
    param_4 = 2;
  }
  if ((DAT_004fb9b8 + 5) % 0x14 == 0) {
    FUN_00469670(param_1);
  }
  else {
    FUN_00469650(param_1);
  }
  FUN_00433a70(param_1,param_4,iVar2,iVar5 - param_4);
  return;
}

