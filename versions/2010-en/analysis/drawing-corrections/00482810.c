
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00482810(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int top;
  float10 fVar2;
  
  if ((((DAT_004da148 + 2 <= param_3) && (param_3 <= DAT_004fe2a8)) && (-1 < param_2)) &&
     (param_2 <= DAT_004fe624)) {
    fVar2 = (float10)FUN_00406220(param_3,param_5);
    iVar1 = (int)(longlong)(fVar2 * (float10)_DAT_004cc828);
    if (((param_4 == 10) &&
        (iVar1 = (int)(longlong)(fVar2 * (float10)_DAT_004cc980), DAT_00536450 == 0)) &&
       (DAT_004da1f8 != 0x68)) {
      FUN_00471160(param_1);
      Ellipse((HDC)param_1[1],param_2 + iVar1 * -3,param_3 - iVar1,param_2 + iVar1 * 3,
              iVar1 + param_3);
    }
    FUN_00471160(param_1);
    if ((DAT_00536450 == 1) && (DAT_005230cc != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    if (3 < iVar1) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    if ((DAT_00536450 == 1) && (DAT_004da210 == 0)) {
      FUN_00469650(param_1);
    }
    top = param_3 + iVar1 * -5;
    Rectangle((HDC)param_1[1],param_2 - iVar1 / 2,top,param_2 + iVar1 / 2,param_3);
    if ((param_4 == 2) && (DAT_00536450 == 0)) {
      if (DAT_004f3864 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3864);
      }
      _DAT_004f6e28 = param_2 - iVar1;
      _DAT_004f6e2c = param_3 + iVar1 * -3;
      _DAT_004f6e38 = iVar1 + param_2;
      _DAT_004f6e30 = param_2;
      _DAT_004f6e34 = top;
      _DAT_004f6e3c = _DAT_004f6e2c;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
    }
    if ((param_4 == 1) && (DAT_00536450 == 0)) {
      if (DAT_005233b4 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005233b4);
      }
      Rectangle((HDC)param_1[1],param_2 - iVar1,top,iVar1 + param_2,top + iVar1 * 2);
    }
    FUN_00469650(param_1);
    if ((DAT_004fb9b8 + param_4 * 10) % 10 == 0) {
      if (((DAT_005363e4 == 1) || (param_4 == 0)) || (param_4 == 10)) {
        FUN_00469670(param_1);
      }
      else {
        if (param_4 == 1) {
          FUN_0046a730(param_1);
        }
        if (param_4 == 2) {
          FUN_0046a700(param_1);
        }
      }
    }
    FUN_00433a70(param_1,(iVar1 + 2) / 2,param_2,param_3 + (2 - (iVar1 + 2)) * 5);
  }
  return;
}

