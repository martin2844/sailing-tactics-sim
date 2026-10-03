
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004419a0(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if (((DAT_004da148 + 1 <= param_3) || (DAT_004f8b78 != 0)) || (DAT_004da1f8 == 100)) {
    iVar3 = (param_3 - DAT_004da148) * 9;
    iVar3 = (((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2) * 4 + 0x50) / 5;
    if (1000 < iVar3) {
      iVar3 = 1000;
    }
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,7);
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    _DAT_004f6e2c = param_3;
    _DAT_004f6e28 = param_2 - iVar3 / 10;
    _DAT_004f6e44 = param_3;
    _DAT_004f6e30 = param_2 - iVar3 / 0x14;
    _DAT_004f6e34 = param_3 - iVar3 / 2;
    _DAT_004f6e38 = iVar3 / 0x14 + param_2;
    _DAT_004f6e40 = param_2 + iVar3 / 10;
    _DAT_004f6e3c = _DAT_004f6e34;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
    if (DAT_005363e4 == 0) {
      if (((DAT_004f8db8 == 1) || (DAT_004f69b8 == 1)) || (DAT_004da1f8 == 100)) {
        if (DAT_005125f4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005125f4);
        }
      }
      else if (DAT_004fb6ac != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fb6ac);
      }
    }
    else {
      (*pcVar1)(param_1,0);
    }
    if ((DAT_00536450 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    iVar2 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    Ellipse((HDC)param_1[1],param_2 - iVar2,(param_3 - iVar3 / 2) - iVar3 / 6,param_2 + iVar2,
            (param_3 - iVar3 / 2) + iVar3 / 6);
  }
  return;
}

