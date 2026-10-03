
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042cd40(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  HDC hdc;
  HGDIOBJ h;
  
  if ((DAT_00491194 == 8) && (param_3 < (DAT_00491148 * 3) / 2)) {
    return;
  }
  if ((DAT_004ac98c == 1) && (param_3 < DAT_00491148 * 2)) {
    return;
  }
  dVar2 = _DAT_00485270;
  if (*(int *)(&DAT_004a4e88 + param_5 * 4) == 2) {
    dVar2 = _DAT_00484f48;
  }
  dVar3 = _DAT_00484eb8;
  if (*(int *)(&DAT_004a4e88 + param_5 * 4) < 3) {
    dVar3 = ((double)(param_3 - DAT_00491148) * dVar2) / (double)(DAT_004a72d0 - DAT_00491148) -
            _DAT_00485278;
  }
  iVar4 = (int)(longlong)dVar3;
  if (DAT_004ac92c == 1) {
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(6);
    (*pcVar1)(0);
  }
  else {
    if ((param_4 == 3) || (param_4 == 5)) {
      if (DAT_004a3a14 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a3a14);
      }
      if (DAT_004a676c == (HGDIOBJ)0x0) goto LAB_0042ce95;
      hdc = (HDC)param_1[1];
      h = DAT_004a676c;
    }
    else {
      if (DAT_004a6234 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004a6234);
      }
      if (DAT_004a67ac == (HGDIOBJ)0x0) goto LAB_0042ce95;
      hdc = (HDC)param_1[1];
      h = DAT_004a67ac;
    }
    SelectObject(hdc,h);
  }
LAB_0042ce95:
  if ((DAT_004ac98c == 1) && ((**(code **)(*param_1 + 0x2c))(4), DAT_004a4dec != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a4dec);
  }
  _DAT_004a4cac = param_3;
  _DAT_004a4cbc = param_3;
  _DAT_004a4ca8 = param_2 - iVar4;
  _DAT_004a4cb4 = param_3 - ((*(int *)(&DAT_004a4e88 + param_5 * 4) != 3) + 1) * iVar4;
  _DAT_004a4cb8 = iVar4 + param_2;
  _DAT_004a4cb0 = param_2;
  iVar4 = iVar4 / 2;
  _DAT_004a4cc0 = param_2 + iVar4;
  _DAT_004a4cc8 = param_2 - iVar4;
  _DAT_004a4cc4 = param_3 + iVar4;
  _DAT_004a4ccc = _DAT_004a4cc4;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,5);
  return;
}

