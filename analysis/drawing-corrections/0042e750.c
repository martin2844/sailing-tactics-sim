
void __cdecl FUN_0042e750(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ h;
  
  if ((param_3 < DAT_00491148 + 1) && (DAT_004a5a4c == 0)) {
    return;
  }
  iVar1 = (param_3 - DAT_00491148) * 9;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + 0x14;
  if (1000 < iVar1) {
    iVar1 = 1000;
  }
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  if ((DAT_004ac98c == 1) || (DAT_004ac92c == 1)) {
    if (DAT_004a70e4 == (HGDIOBJ)0x0) goto LAB_0042e7f4;
    hdc = (HDC)param_1[1];
    h = DAT_004a70e4;
  }
  else {
    if (DAT_004a4f7c == (HGDIOBJ)0x0) goto LAB_0042e7f4;
    hdc = (HDC)param_1[1];
    h = DAT_004a4f7c;
  }
  SelectObject(hdc,h);
LAB_0042e7f4:
  iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  Ellipse((HDC)param_1[1],param_2 - iVar2,param_3 - iVar1 / 2,param_2 + iVar2,param_3);
  if (DAT_004a3efc != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004a3efc);
  }
  Rectangle((HDC)param_1[1],param_2 - iVar2,param_3 - iVar2,param_2 + iVar2,param_3);
  return;
}

