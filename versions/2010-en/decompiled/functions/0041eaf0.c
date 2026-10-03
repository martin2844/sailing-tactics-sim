
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041eaf0(int *param_1,double param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int aiStack_8 [2];
  
  FUN_0041ed90(param_1,param_3);
  _DAT_004f6e28 = DAT_00522920;
  _DAT_004f6e2c = DAT_00522a20;
  _DAT_004f6e34 = DAT_005229f8;
  _DAT_004f6e30 = DAT_005228f8;
  _DAT_004f6e38 = DAT_004f4518;
  _DAT_004f6e40 = DAT_004f4514;
  _DAT_004f6e3c = DAT_004fb9c4;
  _DAT_004f6e44 = DAT_004fb9cc;
  _DAT_004f6e4c = DAT_004fb9c8;
  _DAT_004f6e48 = DAT_004f451c;
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  if (((((DAT_004da190 < 6) && (DAT_00535884 < param_5)) && (param_4 == 0)) &&
      ((DAT_005363bc == 0 && (DAT_005364bc == 0)))) && (DAT_0053652c == 0)) {
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,aiStack_8,DAT_005228e0,DAT_005229e0);
    CDC::LineTo(param_1,DAT_004f4514,DAT_004fb9cc);
  }
  if ((((DAT_005364d4 == 1) || (0 < DAT_005363c0)) || ((DAT_004da190 == 8 || (DAT_004fb410 == 1))))
     && (param_4 == 0)) {
    if (DAT_005362fc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005362fc);
    }
    if (DAT_005230cc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    if ((DAT_004fb410 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    iVar1 = DAT_00522920 + DAT_005228f8 * 3;
    _DAT_004f6e28 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
    iVar1 = DAT_00522a20 + DAT_005229f8 * 3;
    iVar2 = DAT_005228f8 + DAT_00522920 * 3;
    _DAT_004f6e30 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    iVar2 = DAT_005229f8 + DAT_00522a20 * 3;
    _DAT_004f6e34 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    _DAT_004f6e38 = (DAT_004f4514 + _DAT_004f6e30) / 2;
    _DAT_004f6e3c = (_DAT_004f6e34 + DAT_004fb9cc) / 2;
    _DAT_004f6e2c = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
    _DAT_004f6e40 = (_DAT_004f6e28 + DAT_004f4514) / 2;
    _DAT_004f6e44 = (_DAT_004f6e2c + DAT_004fb9cc) / 2;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
  }
  return;
}

