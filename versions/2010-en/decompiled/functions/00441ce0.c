
void __cdecl FUN_00441ce0(int *param_1,int param_2,int param_3)

{
  int top;
  int iVar1;
  
  if ((DAT_004da148 + 1 <= param_3) || (DAT_004f8b78 != 0)) {
    iVar1 = (param_3 - DAT_004da148) * 9;
    iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + 0x14;
    if (1000 < iVar1) {
      iVar1 = 1000;
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    top = param_3 - ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
    Rectangle((HDC)param_1[1],param_2 - iVar1,top,iVar1 + param_2,param_3);
    if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    Rectangle((HDC)param_1[1],param_2 - iVar1,top,iVar1 + param_2,param_3 - iVar1 / 9);
  }
  return;
}

