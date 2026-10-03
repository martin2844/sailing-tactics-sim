
void __cdecl FUN_004834b0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int right;
  int top;
  int iVar2;
  
  if ((((DAT_004da148 <= param_3) && (-1 < param_2)) && (param_2 <= DAT_004fe624)) &&
     (param_3 <= DAT_00535564)) {
    iVar2 = (param_3 - DAT_004da148) * 9;
    iVar2 = ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + 10;
    if (1000 < iVar2) {
      iVar2 = 1000;
    }
    if (DAT_004da1f8 == 6) {
      iVar2 = (iVar2 * 3) / 2;
    }
    if (param_4 == 1) {
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
    else {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    if ((DAT_004da1f8 == 6) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    if (DAT_004fb5d4 == 1) {
      right = param_2 + iVar2 / 2;
      top = param_3 - ((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2);
      iVar1 = param_2 - iVar2 / 2;
      Rectangle((HDC)param_1[1],iVar1,top,right,param_3);
      if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
      Rectangle((HDC)param_1[1],iVar1,top,right,param_3 - iVar2 / 9);
      return;
    }
    iVar1 = param_3 - iVar2 / 3;
    Rectangle((HDC)param_1[1],param_2 - iVar2,iVar1,iVar2 + param_2,param_3);
    if ((DAT_004da1f8 == 6) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    Rectangle((HDC)param_1[1],param_2 - iVar2,iVar1,iVar2 + param_2,param_3 - iVar2 / 7);
  }
  return;
}

