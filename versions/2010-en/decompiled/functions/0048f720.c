
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0048f720(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8 [2];
  
  iVar1 = param_5 / 5 + 1;
  if ((param_4 == 1) && (DAT_00535174 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00535174);
  }
  if ((param_4 == 2) && (DAT_005116dc != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_005116dc);
  }
  if (((DAT_00536450 == 1) || (DAT_005363e4 == 1)) && (DAT_00535494 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00535494);
  }
  iVar3 = param_2 - iVar1;
  FUN_004b4d9d(param_1,local_8,iVar3,param_3);
  CDC::LineTo(param_1,iVar3,param_3 - param_5);
  iVar4 = param_2 + iVar1;
  CDC::LineTo(param_1,iVar4,param_3 - param_5);
  CDC::LineTo(param_1,iVar4,param_3);
  if ((param_4 == 1) && (DAT_004f450c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f450c);
  }
  if ((param_4 == 2) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f1cec);
  }
  if (((DAT_00536450 == 1) || (DAT_005363e4 == 1)) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00522d14);
  }
  FUN_004b4d9d(param_1,local_8,iVar3,param_3);
  iVar2 = param_5 / 2 + param_3;
  CDC::LineTo(param_1,iVar3,iVar2);
  FUN_004b4d9d(param_1,local_8,iVar4,param_3);
  CDC::LineTo(param_1,iVar4,iVar2);
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  iVar1 = (int)(longlong)((double)iVar1 * _DAT_004cd068);
  iVar3 = (param_3 - (iVar1 * 3) / 2) - param_5;
  if (DAT_00525a94 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_00525a94);
  }
  Ellipse((HDC)param_1[1],param_2 - iVar1,iVar3 - iVar1,iVar1 + param_2,iVar1 + iVar3);
  return;
}

