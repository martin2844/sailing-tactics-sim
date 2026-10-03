
void __cdecl FUN_00441bc0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  if ((param_3 < DAT_004da148 + 1) && (DAT_004f8b78 == 0)) {
    return;
  }
  iVar1 = (param_3 - DAT_004da148) * 9;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + 0x14;
  if (1000 < iVar1) {
    iVar1 = 1000;
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if ((DAT_00536450 == 1) || (DAT_005363e4 == 1)) {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00441c64;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  else {
    if (DAT_004f7f74 == (HGDIOBJ)0x0) goto LAB_00441c64;
    hdc = (HDC)param_1[1];
    h = DAT_004f7f74;
  }
  SelectObject(hdc,h);
LAB_00441c64:
  iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  Ellipse((HDC)param_1[1],param_2 - iVar2,param_3 - iVar1 / 2,param_2 + iVar2,param_3);
  if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  Rectangle((HDC)param_1[1],param_2 - iVar2,param_3 - iVar2,param_2 + iVar2,param_3);
  return;
}

