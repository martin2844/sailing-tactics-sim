
void __cdecl FUN_0042e870(int *param_1,undefined4 param_2,int param_3)

{
  int top;
  int iVar1;
  
  if ((DAT_00491148 + 1 <= param_3) || (DAT_004a5a4c != 0)) {
    iVar1 = (param_3 - DAT_00491148) * 9;
    iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + 0x14;
    if (1000 < iVar1) {
      iVar1 = 1000;
    }
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a70e4);
    }
    (**(code **)(*param_1 + 0x2c))(7);
    top = param_3 - ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2);
    Rectangle((HDC)param_1[1],(int)param_1 - iVar1,top,iVar1 + (int)param_1,param_3);
    if (DAT_004a3efc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004a3efc);
    }
    Rectangle((HDC)param_1[1],(int)param_1 - iVar1,top,iVar1 + (int)param_1,param_3 - iVar1 / 9);
  }
  return;
}

