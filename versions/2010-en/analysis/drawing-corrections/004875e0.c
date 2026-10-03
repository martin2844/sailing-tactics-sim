
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004875e0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  int aiStack_8 [2];
  
  fVar4 = (float10)FUN_00406220(param_3,param_5);
  param_5 = (int)(longlong)(fVar4 * (float10)_DAT_004cc458);
  if (1000 < param_5) {
    param_5 = 1000;
  }
  if (param_3 < DAT_004fe2a8 / 0x28 + DAT_004da148) {
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  else {
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    if ((DAT_00536450 == 1) && (DAT_005362fc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005362fc);
    }
  }
  (**(code **)(*param_1 + 0x2c))(param_1,5);
  iVar1 = (int)(param_5 + (param_5 >> 0x1f & 7U)) >> 3;
  iVar2 = param_2 - iVar1;
  iVar1 = iVar1 + param_2;
  iVar3 = param_3 - param_5 / 5;
  FUN_004b4d9d(param_1,aiStack_8,iVar2,iVar3);
  CDC::LineTo(param_1,param_2 - param_5 / 7,param_3);
  FUN_004b4d9d(param_1,aiStack_8,iVar1,iVar3);
  CDC::LineTo(param_1,param_2 + param_5 / 7,param_3);
  FUN_004b4d9d(param_1,aiStack_8,param_2,iVar3);
  CDC::LineTo(param_1,param_2,param_3);
  FUN_004b4d9d(param_1,aiStack_8,iVar2,iVar3);
  CDC::LineTo(param_1,iVar1,iVar3);
  if (param_4 == 1) {
    FUN_00469670(param_1);
  }
  param_5 = param_5 / 0x14;
  if (param_5 < 2) {
    param_5 = 2;
  }
  if ((DAT_004fb9b8 + 5) % 10 == 0) {
    FUN_00433a70(param_1,param_5 + 1,param_2,iVar3 - param_5);
    return;
  }
  FUN_00469650(param_1);
  FUN_00433a70(param_1,param_5,param_2,iVar3 - param_5);
  return;
}

