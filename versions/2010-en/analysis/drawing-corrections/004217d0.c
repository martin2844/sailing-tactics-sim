
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004217d0(int *param_1,double param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  
  iVar3 = (int)(longlong)(param_2 * _DAT_004cc680);
  iVar2 = FUN_0041e000(10);
  iVar1 = param_3;
  if (iVar2 < 5) {
    iVar2 = ((&DAT_005228e0)[param_5] + param_3) / 2;
    iVar3 = ((&DAT_005229e0)[param_5] + iVar3 + param_4) / 2;
  }
  else {
    iVar2 = ((&DAT_005228e0)[param_5] + param_3 * 2) / 3;
    iVar3 = ((&DAT_005229e0)[param_5] + param_4 * 2 + iVar3) / 3;
  }
  if (DAT_004fe33c < param_6) {
    if (DAT_004f4a64 == (HGDIOBJ)0x0) goto LAB_004218a4;
    hdc = (HDC)param_1[1];
    h = DAT_004f4a64;
  }
  else {
    if (DAT_004f7ec4 == (HGDIOBJ)0x0) goto LAB_004218a4;
    hdc = (HDC)param_1[1];
    h = DAT_004f7ec4;
  }
  SelectObject(hdc,h);
LAB_004218a4:
  FUN_004b4d9d(param_1,(int *)&param_2,iVar1,param_4);
  CDC::LineTo(param_1,iVar2,iVar3);
  (**(code **)(*param_1 + 0x2c))(param_1,7);
  return;
}

