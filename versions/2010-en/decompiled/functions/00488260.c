
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00488260(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  HDC hdc;
  HGDIOBJ h;
  int local_8 [2];
  
  iVar2 = param_3;
  if (param_3 <= DAT_004da148) {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (DAT_004fe624 < param_2) {
    return;
  }
  if (DAT_00535564 < param_3) {
    return;
  }
  fVar7 = (float10)FUN_00406220(param_3,param_5);
  iVar3 = (int)(longlong)(fVar7 * (float10)_DAT_004ccad8);
  if ((DAT_004da1f8 == 0x69) || (DAT_004da1f8 == 100)) {
    fVar7 = (float10)FUN_00406220(param_3,param_5);
    iVar3 = (int)(longlong)(fVar7 * (float10)_DAT_004cc478);
  }
  param_3 = iVar3;
  if (1000 < iVar3) {
    param_3 = 1000;
  }
  iVar3 = (int)(param_3 + (param_3 >> 0x1f & 7U)) >> 3;
  iVar5 = param_2 - iVar3;
  iVar4 = iVar3 + param_2;
  iVar6 = iVar2 - param_3 / 3;
  if ((param_4 + DAT_004fb9b8) % 10 == 0) {
    if ((DAT_005363e4 == 0) && (DAT_004da1f8 != 100)) {
      if (DAT_005233b4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005233b4);
      }
      if (DAT_004f1cec != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f1cec);
      }
    }
    else {
      pcVar1 = *(code **)(*param_1 + 0x2c);
      (*pcVar1)(param_1,0);
      (*pcVar1)(param_1,6);
    }
    FUN_00433a70(param_1,2,param_2,iVar6 + -2);
  }
  if (DAT_00536450 == 0) {
    if ((DAT_004da1f8 == 0x69) || (DAT_004da1f8 == 100)) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
      goto LAB_00488422;
    }
    if (DAT_005362e4 == (HGDIOBJ)0x0) goto LAB_00488422;
    hdc = (HDC)param_1[1];
    h = DAT_005362e4;
  }
  else {
    if (DAT_004fe174 == (HGDIOBJ)0x0) goto LAB_00488422;
    hdc = (HDC)param_1[1];
    h = DAT_004fe174;
  }
  SelectObject(hdc,h);
LAB_00488422:
  FUN_004b4d9d(param_1,local_8,iVar5,iVar2);
  CDC::LineTo(param_1,param_2 + -1,iVar6);
  CDC::LineTo(param_1,param_2,iVar6);
  CDC::LineTo(param_1,iVar4,iVar2);
  FUN_004b4d9d(param_1,local_8,param_2,iVar2);
  CDC::LineTo(param_1,param_2,iVar6);
  FUN_004b4d9d(param_1,local_8,param_2 + -1,iVar2);
  CDC::LineTo(param_1,param_2,iVar6);
  FUN_004b4d9d(param_1,local_8,param_2 + 1,iVar2);
  CDC::LineTo(param_1,param_2,iVar6);
  if (DAT_004da1f8 != 0x69) {
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    if (DAT_005230cc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    _DAT_004f6e28 = iVar5 - iVar3;
    _DAT_004f6e34 = iVar2;
    _DAT_004f6e3c = iVar2;
    _DAT_004f6e2c = param_3 / 10 + iVar2;
    _DAT_004f6e40 = iVar4 + iVar3;
    _DAT_004f6e30 = iVar5;
    _DAT_004f6e38 = iVar4;
    _DAT_004f6e44 = _DAT_004f6e2c;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  }
  return;
}

