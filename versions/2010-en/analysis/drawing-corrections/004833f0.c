
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004833f0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  float10 fVar2;
  HDC hdc;
  HGDIOBJ h;
  
  if (param_3 < DAT_004da148 + 1) {
    return;
  }
  fVar2 = (float10)FUN_00406220(param_3,param_4);
  iVar1 = (int)(longlong)(fVar2 * (float10)_DAT_004cc838);
  if (1000 < iVar1) {
    iVar1 = 1000;
  }
  if (DAT_00536450 == 0) {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00483476;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  else {
    if (DAT_005230cc == (HGDIOBJ)0x0) goto LAB_00483476;
    hdc = (HDC)param_1[1];
    h = DAT_005230cc;
  }
  SelectObject(hdc,h);
LAB_00483476:
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  Rectangle((HDC)param_1[1],param_2 - iVar1,param_3 + iVar1 * -7 + 2,iVar1 + param_2,param_3 + 2);
  return;
}

