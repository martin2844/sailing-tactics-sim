
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_004198f0(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  int iVar1;
  int y1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_7;
  if ((DAT_004ac13c < param_7) && (param_4 * DAT_004ac928 < 2)) {
    param_7 = FUN_00413cb0(param_6);
    if (DAT_004a7354 < iVar3) {
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
    }
    else {
      (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
    }
    iVar5 = 1 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485068);
    iVar3 = param_5;
    iVar4 = param_5;
    if (param_5 == 0) {
      iVar3 = DAT_004aa1a4;
      iVar4 = DAT_004aa2a4 - iVar5 / 2;
    }
    if (param_5 == 1) {
      iVar3 = (DAT_004aa1a4 + DAT_004aa1dc) / 2;
      iVar4 = (DAT_004aa2dc + DAT_004aa2a4) / 2 - iVar5 / 2;
    }
    if (param_5 == -1) {
      iVar3 = (DAT_004aa1bc + DAT_004aa1a4) / 2;
      iVar4 = (DAT_004aa2a4 + DAT_004aa2bc) / 2 - iVar5 / 2;
    }
    param_5 = iVar3 - iVar5;
    y1 = iVar4 - iVar5;
    iVar1 = (iVar5 * (&DAT_004a3450)[param_7]) / 100;
    Arc(*(HDC *)(param_1 + 4),iVar3 - iVar1,y1,iVar3 + iVar1,iVar4 + iVar5,param_5,y1,param_5,y1);
    if (param_4 == 1) {
      iVar1 = DAT_004a7044 * -2 - (DAT_004a6ecc * DAT_004aa734) / 2;
    }
    else {
      iVar1 = -((*(int *)(&DAT_004aa730 + param_4 * 4) * *(int *)(&DAT_004a6ec8 + param_4 * 4)) / 2)
      ;
    }
    param_5 = FUN_00413cb0(iVar1);
    uVar2 = (int)(&DAT_004a3450)[param_7] >> 0x1f;
    param_4 = (int)((((&DAT_004a3450)[param_7] ^ uVar2) - uVar2) *
                   (((&DAT_004a54a0)[param_5] * iVar5) / 100)) / 100 + iVar3;
    iVar1 = (&DAT_004a3450)[param_5];
    FUN_004706bd(param_1,&param_2,iVar3,iVar4);
    CDC::LineTo(param_1,param_4,iVar4 - (iVar1 * iVar5) / 100);
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
  }
  return;
}

