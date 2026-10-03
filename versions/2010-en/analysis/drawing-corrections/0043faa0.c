
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043faa0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ h;
  
  if (((((DAT_004da1f8 == 5) && (2 < param_4)) && (param_4 < 6)) &&
      ((3 < DAT_004fad38 && (DAT_00536444 == 0)))) && (DAT_00536458 == 0)) {
    if (param_4 == 3) goto LAB_0043fb44;
    if (param_4 == 4) {
      FUN_00487020(param_1,param_2,param_3,param_5);
      return;
    }
    if (param_4 == 5) goto LAB_0043fb96;
  }
  if (((DAT_004da1f8 == 5) && (2 < param_4)) &&
     ((param_4 < 6 && (((DAT_004fad38 < 3 && (DAT_00536444 == 0)) && (DAT_00536458 == 0)))))) {
    if (param_4 == 5) {
LAB_0043fb44:
      FUN_00484720(param_1,param_2,param_3,2,0,param_5);
      return;
    }
    if (param_4 == 4) {
      FUN_00487020(param_1,param_2,param_3,param_5);
      return;
    }
    if (param_4 == 3) {
LAB_0043fb96:
      FUN_00484720(param_1,param_2,param_3,3,0,param_5);
      return;
    }
  }
  if (((DAT_0053527c == 1) && (DAT_00536408 == 0)) && ((param_4 == 4 && (DAT_004da194 < 0xf)))) {
    return;
  }
  if (DAT_0053527c == 1) {
    if ((DAT_00536408 == 0) && (param_4 == 5)) {
      return;
    }
    if (((DAT_00536408 == 1) && (0 < DAT_005364e0)) && (param_4 == 5)) {
      return;
    }
  }
  if (((param_4 == DAT_004da194 + 7) || (param_4 == DAT_004da194 + 6)) && (DAT_004f452c == 0)) {
    return;
  }
  if (DAT_004f452c == 1) {
    if (param_4 == 5) {
      return;
    }
    if (((param_4 == 1) && (DAT_00536408 == 1)) && ((DAT_004da188 != 2 && (DAT_005363f8 == 0)))) {
      return;
    }
  }
  if (((DAT_004da194 < 0xb) && (param_4 == 4)) && (DAT_004da168 == 1)) {
    return;
  }
  if ((DAT_004da19c == 8) && (param_3 < (DAT_004da148 * 3) / 2)) {
    return;
  }
  if ((DAT_00536450 == 1) && (param_3 < DAT_004da148 * 2)) {
    return;
  }
  dVar2 = _DAT_004ccb88;
  if (*(int *)(&DAT_004f71c0 + param_5 * 4) == 2) {
    dVar2 = _DAT_004cc7a0;
  }
  dVar3 = _DAT_004cc730;
  if (*(int *)(&DAT_004f71c0 + param_5 * 4) < 3) {
    dVar3 = ((double)(param_3 - DAT_004da148) * dVar2) / (double)(DAT_004fe2a8 - DAT_004da148) -
            _DAT_004cc9d8;
  }
  iVar4 = (int)(longlong)dVar3;
  if (DAT_005363e4 == 1) {
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,6);
    (*pcVar1)(param_1,0);
    goto LAB_0043fe0f;
  }
  if ((param_4 == 3) || (param_4 == 5)) {
    if (DAT_004ff034 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004ff034);
    }
    if (DAT_005125e4 != (HGDIOBJ)0x0) {
      hdc = (HDC)param_1[1];
      h = DAT_005125e4;
      goto override_prt_43fdbe_6059bb06;
    }
  }
  else {
    if (DAT_004fb25c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb25c);
    }
    if (DAT_004fba14 != (HGDIOBJ)0x0) {
      hdc = (HDC)param_1[1];
      h = DAT_004fba14;
override_prt_43fdbe_6059bb06:
      SelectObject(hdc,h);
    }
  }
  if ((param_4 == DAT_004da194 + 7) || (param_4 == DAT_004da194 + 6)) {
    if (DAT_004f41ec != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f41ec);
    }
    if (DAT_00522f1c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00522f1c);
    }
  }
LAB_0043fe0f:
  if ((DAT_00536450 == 1) &&
     ((**(code **)(*param_1 + 0x2c))(param_1,4), DAT_004f7084 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f7084);
  }
  _DAT_004f6e2c = param_3;
  _DAT_004f6e3c = param_3;
  _DAT_004f6e28 = param_2 - iVar4;
  _DAT_004f6e34 = param_3 - ((*(int *)(&DAT_004f71c0 + param_5 * 4) != 3) + 1) * iVar4;
  _DAT_004f6e38 = iVar4 + param_2;
  _DAT_004f6e30 = param_2;
  iVar4 = iVar4 / 2;
  _DAT_004f6e40 = param_2 + iVar4;
  _DAT_004f6e48 = param_2 - iVar4;
  _DAT_004f6e44 = param_3 + iVar4;
  _DAT_004f6e4c = _DAT_004f6e44;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,5);
  return;
}

