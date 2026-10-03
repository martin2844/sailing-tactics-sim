
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441fb0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ pvVar5;
  int local_8 [2];
  
  if ((DAT_004da19c != 8) || (iVar3 = DAT_004da148, DAT_004f8b78 != 1)) {
    iVar3 = param_3;
  }
  iVar4 = (-(uint)(DAT_004f4510 != 1) & 0xfffffffa) + 6;
  if (param_4 == 1) {
    DAT_00536548 = param_2;
    DAT_0053654c = iVar3;
  }
  if (param_4 != 2) goto LAB_00442124;
  if (DAT_004f4510 == 0) {
    if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
      hdc = (HDC)param_1[1];
      pvVar5 = DAT_004f7ec4;
override_prt_442048_6059bb06:
      SelectObject(hdc,pvVar5);
    }
  }
  else if (DAT_00522d14 != (HGDIOBJ)0x0) {
    hdc = (HDC)param_1[1];
    pvVar5 = DAT_00522d14;
    goto override_prt_442048_6059bb06;
  }
  if ((10 < DAT_00536548) && (DAT_00536548 < DAT_004fe624 + -10)) {
    FUN_004b4d9d(param_1,local_8,DAT_00536548,DAT_0053654c - iVar4);
    CDC::LineTo(param_1,param_2,iVar3 - iVar4);
  }
  if (DAT_004f4510 == 1) {
    iVar1 = param_2 - DAT_00536548;
    iVar2 = iVar3 - DAT_0053654c;
    FUN_004b4d9d(param_1,local_8,param_2,iVar3 - iVar4);
    CDC::LineTo(param_1,param_2 + iVar1 * 2,iVar3 + iVar2 * 2);
    FUN_004b4d9d(param_1,local_8,DAT_00536548,DAT_0053654c - iVar4);
    CDC::LineTo(param_1,DAT_00536548 + iVar1 * -2,DAT_0053654c + iVar2 * -2);
  }
LAB_00442124:
  iVar4 = (iVar3 - DAT_004da148) * 9;
  iVar4 = ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + 0x1e;
  if (DAT_004da1f8 == 0xb) {
    iVar4 = (iVar4 * 3) / 2;
  }
  if (1000 < iVar4) {
    iVar4 = 1000;
  }
  pvVar5 = DAT_004fe07c;
  if (((DAT_00536450 == 0) && (DAT_004f4510 == 0)) && (pvVar5 = DAT_004fb6ac, DAT_004da1f8 != 0xb))
  {
    (**(code **)(*param_1 + 0x2c))(param_1,0);
  }
  else if (pvVar5 != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],pvVar5);
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  _DAT_004f6e28 = param_2 - iVar4 / 0x14;
  _DAT_004f6e2c = iVar4 / 0x28 + iVar3;
  _DAT_004f6e30 = param_2 - iVar4 / 0x1e;
  _DAT_004f6e34 = iVar3 - iVar4 / 2;
  _DAT_004f6e38 = param_2 + iVar4 / 0x1e;
  _DAT_004f6e40 = param_2 + iVar4 / 0x14;
  _DAT_004f6e3c = _DAT_004f6e34;
  _DAT_004f6e44 = _DAT_004f6e2c;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  return;
}

