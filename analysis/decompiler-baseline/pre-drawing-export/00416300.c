
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00416300(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  FUN_00416420((int *)param_1,param_4);
  _DAT_004a4ca8 = DAT_004aa1e0;
  _DAT_004a4cac = DAT_004aa2e0;
  _DAT_004a4cb4 = DAT_004aa2b8;
  _DAT_004a4cb0 = DAT_004aa1b8;
  _DAT_004a4cb8 = DAT_004a4380;
  _DAT_004a4cc0 = DAT_004a437c;
  _DAT_004a4cbc = DAT_004a6784;
  _DAT_004a4cc4 = DAT_004a678c;
  _DAT_004a4ccc = DAT_004a6788;
  _DAT_004a4cc8 = DAT_004a4384;
  (**(code **)(*(int *)param_1 + 0x2c))(7);
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,5);
  if ((((DAT_00491188 < 6) && (DAT_004ac13c < param_5)) && (param_4 == 0)) && (DAT_004ac904 == 0)) {
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,(int *)&stack0xfffffff4,DAT_004aa1a0,DAT_004aa2a0);
    CDC::LineTo(param_1,DAT_004a437c,DAT_004a678c);
  }
  return;
}

