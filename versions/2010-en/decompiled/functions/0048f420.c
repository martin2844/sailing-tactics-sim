
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048f420(int *param_1,double param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int y1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((DAT_005363b8 != 1) || (param_4 != 0)) {
    param_7 = FUN_0041bc20(param_7);
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    iVar4 = (int)(longlong)(param_2 * _DAT_004cc690);
    if (DAT_005363b8 == 1) {
      iVar4 = (int)(longlong)(param_2 * _DAT_004cd0a8);
    }
    iVar4 = 1 - iVar4;
    iVar3 = param_4;
    iVar5 = param_4;
    if (param_4 == 0) {
      iVar3 = DAT_005228e4;
      iVar5 = DAT_005229e4 - iVar4 / 2;
    }
    if (param_4 == 1) {
      iVar5 = param_6 - iVar4 / 3;
      iVar3 = param_5;
    }
    if (param_4 == -1) {
      iVar5 = param_6 - iVar4 / 3;
      iVar3 = param_5;
    }
    param_4 = iVar3 - iVar4;
    y1 = iVar5 - iVar4;
    iVar1 = (iVar4 * (&DAT_004f1740)[param_7]) / 100;
    Arc((HDC)param_1[1],iVar3 - iVar1,y1,iVar3 + iVar1,iVar5 + iVar4,param_4,y1,param_4,y1);
    if (param_3 == 1) {
      iVar1 = DAT_004fdfd0 * -2 - (DAT_004fc2c4 * DAT_00522ff4) / 2;
    }
    else {
      iVar1 = -((*(int *)(&DAT_004fc2c0 + param_3 * 4) * *(int *)(&DAT_00522ff0 + param_3 * 4)) / 2)
      ;
    }
    iVar1 = FUN_0041bc20(iVar1);
    param_4 = FUN_0041bc20(iVar1);
    uVar2 = (int)(&DAT_004f1740)[param_7] >> 0x1f;
    param_5 = (int)((((&DAT_004f1740)[param_7] ^ uVar2) - uVar2) *
                   (((&DAT_004f85c8)[param_4] * iVar4) / 100)) / 100 + iVar3;
    iVar1 = (&DAT_004f1740)[param_4];
    FUN_004b4d9d(param_1,(int *)&param_2,iVar3,iVar5);
    CDC::LineTo(param_1,param_5,iVar5 - (iVar1 * iVar4) / 100);
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  return;
}

