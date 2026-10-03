
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00423c30(int *param_1,double param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int y1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_6;
  if ((DAT_00535884 < param_6) && (param_3 * DAT_005363e0 < 2)) {
    param_6 = FUN_0041bc20(param_5);
    if (DAT_004fe33c < iVar3) {
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
    }
    else {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    iVar5 = 1 - (int)(longlong)(param_2 * _DAT_004cc8b8);
    iVar3 = param_4;
    iVar4 = param_4;
    if (param_4 == 0) {
      iVar3 = DAT_005228e4;
      iVar4 = DAT_005229e4 - iVar5 / 2;
    }
    if (param_4 == 1) {
      iVar3 = (DAT_005228e4 + DAT_0052291c) / 2;
      iVar4 = (DAT_00522a1c + DAT_005229e4) / 2 - iVar5 / 2;
    }
    if (param_4 == -1) {
      iVar3 = (DAT_005228fc + DAT_005228e4) / 2;
      iVar4 = (DAT_005229e4 + DAT_005229fc) / 2 - iVar5 / 2;
    }
    param_4 = iVar3 - iVar5;
    y1 = iVar4 - iVar5;
    iVar1 = (iVar5 * (&DAT_004f1740)[param_6]) / 100;
    Arc((HDC)param_1[1],iVar3 - iVar1,y1,iVar3 + iVar1,iVar4 + iVar5,param_4,y1,param_4,y1);
    if (param_3 == 1) {
      iVar1 = DAT_004fdfd0 * -2 - (DAT_004fc2c4 * DAT_00522ff4) / 2;
    }
    else {
      iVar1 = -((*(int *)(&DAT_00522ff0 + param_3 * 4) * *(int *)(&DAT_004fc2c0 + param_3 * 4)) / 2)
      ;
    }
    param_4 = FUN_0041bc20(iVar1);
    uVar2 = (int)(&DAT_004f1740)[param_6] >> 0x1f;
    param_3 = (int)((((&DAT_004f1740)[param_6] ^ uVar2) - uVar2) *
                   (((&DAT_004f85c8)[param_4] * iVar5) / 100)) / 100 + iVar3;
    iVar1 = (&DAT_004f1740)[param_4];
    FUN_004b4d9d(param_1,(int *)&param_2,iVar3,iVar4);
    CDC::LineTo(param_1,param_3,iVar4 - (iVar1 * iVar5) / 100);
    (**(code **)(*param_1 + 0x2c))(param_1,7);
  }
  return;
}

