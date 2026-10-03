
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042eb40(CDC *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  int local_8 [2];
  
  if (param_3 < DAT_00491148 + 1) {
    return;
  }
  if ((DAT_00491194 == 8) && (DAT_004a5a4c == 1)) {
    param_3 = DAT_00491148;
  }
  iVar3 = (-(uint)(DAT_004a4378 != 1) & 0xfffffffa) + 6;
  if (param_4 == 1) {
    DAT_004aca10 = param_2;
    DAT_004aca14 = param_3;
  }
  if (param_4 != 2) goto LAB_0042ecbd;
  if (DAT_004a4378 == 0) {
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(param_1 + 4);
      h = DAT_004a4ee4;
LAB_0042ebe4:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004aa634 != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004aa634;
    goto LAB_0042ebe4;
  }
  if ((10 < DAT_004aca10) && (DAT_004aca10 < DAT_004a763c + -10)) {
    FUN_004706bd(param_1,local_8,DAT_004aca10,DAT_004aca14 - iVar3);
    CDC::LineTo(param_1,param_2,param_3 - iVar3);
  }
  if (DAT_004a4378 == 1) {
    iVar1 = param_2 - DAT_004aca10;
    iVar2 = param_3 - DAT_004aca14;
    FUN_004706bd(param_1,local_8,param_2,param_3 - iVar3);
    CDC::LineTo(param_1,iVar1 * 2 + param_2,iVar2 * 2 + param_3);
    FUN_004706bd(param_1,local_8,DAT_004aca10,DAT_004aca14 - iVar3);
    CDC::LineTo(param_1,DAT_004aca10 + iVar1 * -2,DAT_004aca14 + iVar2 * -2);
  }
LAB_0042ecbd:
  iVar3 = (param_3 - DAT_00491148) * 9;
  iVar3 = ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2) + 0x1e;
  if (1000 < iVar3) {
    iVar3 = 1000;
  }
  if ((DAT_004ac98c == 0) && (DAT_004a4378 == 0)) {
    (**(code **)(*(int *)param_1 + 0x2c))(0);
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  (**(code **)(*(int *)param_1 + 0x2c))(7);
  _DAT_004a4ca8 = param_2 - iVar3 / 0x14;
  _DAT_004a4cac = iVar3 / 0x28 + param_3;
  _DAT_004a4cb0 = param_2 - iVar3 / 0x1e;
  _DAT_004a4cb4 = param_3 - iVar3 / 2;
  _DAT_004a4cb8 = param_2 + iVar3 / 0x1e;
  _DAT_004a4cc0 = param_2 + iVar3 / 0x14;
  _DAT_004a4cbc = _DAT_004a4cb4;
  _DAT_004a4cc4 = _DAT_004a4cac;
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
  return;
}

