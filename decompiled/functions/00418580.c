
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00418580(CDC *param_1,undefined4 param_2,undefined4 param_3,double param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ h;
  
  _DAT_004a4cb0 = DAT_004aa1c0;
  _DAT_004a4cb8 = (DAT_004aa1c0 + DAT_004aa1b8 * 2) / 3;
  _DAT_004a4ca8 = DAT_004aa1d4;
  _DAT_004a4cbc = (DAT_004aa2c0 + DAT_004aa2b8 * 2) / 3;
  _DAT_004a4cb4 = DAT_004aa2c0;
  _DAT_004a4cac = DAT_004aa2d4;
  _DAT_004a4cc0 = (DAT_004aa1d4 + DAT_004aa1dc * 2) / 3;
  _DAT_004a4cc4 = (DAT_004aa2d4 + DAT_004aa2dc * 2) / 3;
  iVar1 = (DAT_004aa1c4 + DAT_004aa1bc * 2) / 3;
  iVar2 = (DAT_004aa2c4 + DAT_004aa2bc * 2) / 3;
  iVar3 = (DAT_004aa1d8 + DAT_004aa1e0 * 2) / 3;
  iVar4 = (DAT_004aa2d8 + DAT_004aa2e0 * 2) / 3;
  if (DAT_004a3efc != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a3efc);
  }
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
  if (param_4 <= _DAT_00484ec8) {
    if (DAT_004a71bc == (HGDIOBJ)0x0) goto LAB_00418727;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a71bc;
  }
  else {
    if (DAT_004aa634 == (HGDIOBJ)0x0) goto LAB_00418727;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa634;
  }
  SelectObject(hdc,h);
LAB_00418727:
  FUN_004706bd(param_1,(int *)&param_4,DAT_004aa1c4,DAT_004aa2c4);
  CDC::LineTo(param_1,DAT_004aa1d8,DAT_004aa2d8);
  FUN_004706bd(param_1,(int *)&param_4,iVar1,iVar2);
  CDC::LineTo(param_1,iVar3,iVar4);
  DAT_004a4880 = iVar1;
  DAT_004a4884 = iVar4;
  DAT_004a4950 = iVar3;
  DAT_004a4df0 = iVar2;
  (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
  FUN_004706bd(param_1,(int *)&param_4,DAT_004aa1d0,DAT_004aa2d0);
  CDC::LineTo(param_1,DAT_004aa1b4,
              DAT_004aa2b4 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484d48));
  CDC::LineTo(param_1,DAT_004aa1c8,DAT_004aa2c8);
  if (DAT_00491188 == 10) {
    iVar1 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484db0);
    DAT_004aaeb0 = (DAT_004aa1b4 - DAT_004aa1ac) / 3 + DAT_004aa1b4;
    DAT_004ab8c0 = (((DAT_004aa2b4 - iVar1) - DAT_004aa2ac) / 3 - iVar1) + DAT_004aa2b4;
    FUN_004706bd(param_1,&param_2,DAT_004aa1ac,DAT_004aa2ac);
    CDC::LineTo(param_1,DAT_004aaeb0,DAT_004ab8c0);
  }
  return;
}

