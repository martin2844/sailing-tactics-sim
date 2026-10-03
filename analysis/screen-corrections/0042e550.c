
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042e550(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_00491148 + 1 <= param_3) || (DAT_004a5a4c != 0)) {
    iVar3 = (param_3 - DAT_00491148) * 9;
    iVar3 = (((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2) * 4 + 0x50) / 5;
    if (1000 < iVar3) {
      iVar3 = 1000;
    }
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,7);
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a3efc);
    }
    _DAT_004a4cac = param_3;
    _DAT_004a4ca8 = param_2 - iVar3 / 10;
    _DAT_004a4cc4 = param_3;
    _DAT_004a4cb0 = param_2 - iVar3 / 0x14;
    _DAT_004a4cb4 = param_3 - iVar3 / 2;
    _DAT_004a4cb8 = iVar3 / 0x14 + param_2;
    _DAT_004a4cc0 = param_2 + iVar3 / 10;
    _DAT_004a4cbc = _DAT_004a4cb4;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,4);
    if (DAT_004ac92c == 0) {
      if ((DAT_004a5b9c == 1) || (DAT_004a4958 == 1)) {
        if (DAT_004a8e04 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004a8e04);
        }
      }
      else if (DAT_004a6484 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a6484);
      }
    }
    else {
      (*pcVar1)(param_1,0);
    }
    if ((DAT_004ac98c == 1) && (DAT_004a70e4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004a70e4);
    }
    iVar2 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
    Ellipse((HDC)param_1[1],param_2 - iVar2,(param_3 - iVar3 / 2) - iVar3 / 6,param_2 + iVar2,
            (param_3 - iVar3 / 2) + iVar3 / 6);
  }
  return;
}

