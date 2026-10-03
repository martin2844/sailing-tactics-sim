
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426550(int *param_1,int param_2,int param_3,int param_4,int param_5,double param_6,
                 int param_7)

{
  int iVar1;
  int aiStack_8 [2];
  
  if (DAT_00536444 < 0x65) {
    if (param_5 == 1) {
      if (DAT_005363e4 == 0) {
        if ((*(int *)(&DAT_00522ff0 + param_7 * 4) == 1) && (DAT_004fdfe4 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004fdfe4);
        }
        if (((DAT_005363e4 == 0) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == -1)) &&
           (DAT_004fb994 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004fb994);
        }
      }
      if ((DAT_005363e4 == 1) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == 1)) {
        (**(code **)(*param_1 + 0x2c))(param_1,7);
      }
      if (((DAT_005363e4 == 1) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == -1)) &&
         (DAT_004f7084 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
    }
    if (param_5 == 2) {
      if (DAT_005363e4 == 0) {
        if ((*(int *)(&DAT_00522ff0 + param_7 * 4) == 1) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004f1cec);
        }
        if (((DAT_005363e4 == 0) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == -1)) &&
           (DAT_005362e4 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_005362e4);
        }
      }
      if (((DAT_005363e4 == 1) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == 1)) &&
         (DAT_004f7084 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
      if ((DAT_005363e4 == 1) && (*(int *)(&DAT_00522ff0 + param_7 * 4) == -1)) {
        (**(code **)(*param_1 + 0x2c))(param_1,7);
      }
    }
    if (param_4 == 1) {
      FUN_004b4d9d(param_1,aiStack_8,param_2,param_3);
      param_3 = param_3 - (int)(longlong)(param_6 * _DAT_004cc5f0);
      iVar1 = FUN_0041e000(5);
      CDC::LineTo(param_1,iVar1 + param_2,param_3);
      return;
    }
    FUN_00426750(param_1,param_2,param_3,0xffffffff,param_7);
  }
  return;
}

