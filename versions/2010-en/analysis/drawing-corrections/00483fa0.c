
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00483fa0(int *param_1,int param_2,int param_3,double param_4,int param_5)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if ((((DAT_004da148 + 1 <= param_3) && (-1 < param_2)) && (param_2 <= DAT_004fe624)) &&
     (param_3 <= DAT_00535564)) {
    fVar3 = (float10)FUN_00406220(param_3,param_5);
    iVar1 = (int)(longlong)(fVar3 * (float10)param_4 * (float10)_DAT_004cc580);
    if (DAT_004da1f8 == 0x6a) {
      iVar1 = (int)(iVar1 * 5 + (iVar1 * 5 >> 0x1f & 3U)) >> 2;
    }
    if (DAT_004da1f8 == 100) {
      iVar1 = (iVar1 * 3) / 2;
    }
    if (1000 < iVar1) {
      iVar1 = 1000;
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    if (param_4 < _DAT_004cc5a8) {
      iVar2 = 0x55555556;
    }
    else {
      iVar2 = 0x2aaaaaab;
    }
    iVar2 = (int)((ulonglong)((longlong)iVar2 * (longlong)iVar1) >> 0x20);
    Rectangle((HDC)param_1[1],param_2 - iVar1 / 2,(param_3 - (iVar2 - (iVar2 >> 0x1f))) + 2,
              param_2 + iVar1 / 2,param_3 + 2);
  }
  return;
}

