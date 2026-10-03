
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441de0(int *param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_8 [2];
  
  if ((DAT_004da148 + 1 <= param_3) || (DAT_004f8b78 != 0)) {
    iVar4 = (param_3 - DAT_004da148) * 2 + 0x1b;
    if (1000 < iVar4) {
      iVar4 = 1000;
    }
    iVar6 = param_3 - (iVar4 * 2) / 3;
    dVar2 = _DAT_004cc9d0;
    if (DAT_004da19c == 8) {
      dVar2 = _DAT_004ccba8;
    }
    uVar3 = (int)(longlong)(_DAT_005355f8 / dVar2) + param_4;
    uVar5 = (int)uVar3 >> 0x1f;
    if (((uVar3 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) {
      if (DAT_005363e4 == 0) {
        if (DAT_004f3864 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f3864);
        }
        if (DAT_004fb994 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fb994);
        }
      }
      else {
        pcVar1 = *(code **)(*param_1 + 0x2c);
        (*pcVar1)(param_1,0);
        (*pcVar1)(param_1,6);
      }
      FUN_00433a70(param_1,1,param_2 + 1,iVar6 + -1);
    }
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    FUN_004b4d9d(param_1,local_8,param_2 - iVar4 / 6,param_3);
    CDC::LineTo(param_1,param_2 + -1,iVar6);
    CDC::LineTo(param_1,param_2 + 1,iVar6);
    CDC::LineTo(param_1,iVar4 / 6 + param_2,param_3);
    FUN_004b4d9d(param_1,local_8,param_2,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004b4d9d(param_1,local_8,param_2 + -1,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004b4d9d(param_1,local_8,param_2 + 1,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
  }
  return;
}

