
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004813f0(int *param_1,int param_2,int *param_3,int param_4,int *param_5,undefined4 param_6,
                 int param_7)

{
  int *original_dc;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  code *apcStack_18 [2];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  original_dc = param_1;
  if ((((DAT_004da1f8 != 999) || (DAT_004da24c != 0)) || (5 < (int)param_5)) &&
     ((((DAT_004da1f8 != 999 || (DAT_004da264 != 0)) || ((int)param_5 < 6)) &&
      ((DAT_004da1f8 != 2 || (799 < *(int *)(&DAT_00534fe0 + (int)param_5 * 4))))))) {
    FUN_00484270(param_1);
    if ((DAT_00536450 == 0) && (DAT_004fb244 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fb244);
    }
    if ((((DAT_00536450 == 0) && (DAT_004da1f8 == 0x66)) && (param_5 == (int *)0x5)) &&
       (DAT_005363a4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005363a4);
    }
    if ((DAT_005363e4 == 1) &&
       ((**(code **)(*param_1 + 0x2c))(param_1,8), DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    iVar4 = (int)param_3;
    if (DAT_004da1f8 == 100) {
      iVar4 = (int)param_3 + -1;
    }
    fVar5 = (float10)FUN_00406220(iVar4,param_7);
    param_1 = (int *)(longlong)
                     ((float10)*(int *)(&DAT_004f8d80 + param_4 * 4) *
                     fVar5 * (float10)_DAT_004ccff0);
    if (DAT_004fb5d4 == 1) {
      param_1 = (int *)((int)param_1 * 2);
    }
    if ((DAT_004da1f8 == 0x66) && (param_5 == (int *)0x5)) {
      param_1 = (int *)((int)param_1 * 2);
    }
    if ((DAT_004da1f8 == 999) && ((int)param_5 < 6)) {
      param_1 = (int *)((int)param_1 * 4);
    }
    if (((DAT_004da1f8 == 999) && (5 < (int)param_5)) && (DAT_00536504 == 0)) {
      param_1 = (int *)((int)param_1 << 2);
    }
    if (((DAT_004da1f8 == 999) && (5 < (int)param_5)) && (0 < DAT_00536504)) {
      param_1 = (int *)((int)param_1 * 3);
    }
    apcStack_18[0] = *(code **)(*original_dc + 0x2c);
    (*apcStack_18[0])(original_dc,8);
    iVar1 = param_2 + (int)param_1 * -4;
    _DAT_004f6e30 = param_2 + (int)param_1 * -2;
    _DAT_004f6e38 = param_2;
    iVar2 = iVar4 - ((int)((int)param_1 * 3 + ((int)param_1 * 3 >> 0x1f & 7U)) >> 3);
    iStack_4 = (int)param_1 / 2;
    iVar3 = iVar4 - iStack_4;
    _DAT_004f6e40 = param_2 + (int)param_1 * 2;
    _DAT_004f6e48 = param_2 + (int)param_1 * 4;
    _DAT_004f6e28 = iVar1;
    _DAT_004f6e2c = iVar4;
    _DAT_004f6e34 = iVar2;
    _DAT_004f6e3c = iVar3;
    _DAT_004f6e44 = iVar2;
    _DAT_004f6e4c = iVar4;
    iStack_10 = _DAT_004f6e30;
    iStack_c = _DAT_004f6e40;
    iStack_8 = _DAT_004f6e48;
    Polygon((HDC)original_dc[1],(POINT *)&DAT_004f6e28,5);
    (*apcStack_18[0])(original_dc,7);
    FUN_004b4d9d(original_dc,(int *)apcStack_18,iVar1,iVar4);
    CDC::LineTo(original_dc,iStack_10,iVar2);
    CDC::LineTo(original_dc,param_2,iVar3);
    CDC::LineTo(original_dc,iStack_c,iVar2);
    CDC::LineTo(original_dc,iStack_8,iVar4);
    param_7 = 0x13;
    param_3 = &DAT_00512d78 + (int)param_5;
    DAT_005233ac = iVar3;
    param_5 = &DAT_00512d74 + (int)param_5;
    do {
      iVar1 = *param_5;
      iVar2 = iStack_4 * *param_3;
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004f7084);
      }
      FUN_00424320(original_dc,((int)param_1 * iVar1 * 4) / 100 + param_2 + (int)param_1 * -2,
                   iVar4 - iVar2 / 0x78,1);
      param_5 = param_5 + 1;
      param_3 = param_3 + 2;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
  }
  return;
}

