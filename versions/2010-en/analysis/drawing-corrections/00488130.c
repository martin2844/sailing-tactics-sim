
void __cdecl FUN_00488130(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int left;
  int right;
  int top;
  
  if ((((DAT_004da148 + 1 <= param_3) && (-1 < param_2)) && (param_2 <= DAT_004fe624)) &&
     (param_3 <= DAT_00535564)) {
    iVar1 = (param_3 - DAT_004da148) * 8;
    iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + 8;
    if (1000 < iVar1) {
      iVar1 = 1000;
    }
    if (param_4 == 1) {
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
    else {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    right = param_2 + iVar1 / 2;
    top = param_3 - ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
    left = param_2 - iVar1 / 2;
    Rectangle((HDC)param_1[1],left,top,right,param_3);
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    Rectangle((HDC)param_1[1],left,top,right,param_3 - iVar1 / 9);
  }
  return;
}

