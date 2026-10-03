
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042e190(CDC *param_1,undefined *param_2,CDC *param_3)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  CDC *pCVar4;
  int iVar5;
  CDC *bottom;
  int iVar6;
  int unaff_ESI;
  CDC *pCVar7;
  HDC hdc;
  HGDIOBJ h;
  int aiStack_c [2];
  CDC *pCStack_4;
  
  if ((int)param_3 < DAT_00491148 + 1) {
    return;
  }
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(7);
  dVar2 = _DAT_00484dd8 -
          ((double)(int)(param_3 + -0x1e) * _DAT_00485280) / (double)(DAT_004a72d0 / 2 + -0x1e);
  dVar3 = _DAT_00485290;
  if (DAT_004a5a4c == 1) {
    dVar3 = _DAT_00485288;
  }
  iVar6 = (int)(longlong)(dVar2 * dVar3);
  if (pcVar1 == (code *)0x1) {
    iVar6 = (int)(longlong)(dVar2 * _DAT_00485298);
  }
  if (DAT_004a5a4c == 0) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
    }
    iVar5 = (iVar6 * 3) / 10;
    Ellipse(*(HDC *)(param_1 + 4),(int)param_1 - iVar5,(int)param_3,(int)(param_1 + iVar5),
            (int)(param_3 + iVar6 / 10));
  }
  pCVar4 = param_3;
  if (DAT_004a5a4c != 1) goto LAB_0042e3a7;
  (*(code *)param_2)(8);
  if ((DAT_004ac98c == 0) && (DAT_004ac92c == 0)) {
    if (DAT_004a621c != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(param_1 + 4);
      h = DAT_004a621c;
LAB_0042e2ea:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a70e4;
    goto LAB_0042e2ea;
  }
  if ((DAT_004ac98c == 1) && (DAT_004aa7f4 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa7f4);
  }
  pCVar4 = param_1 + iVar6 * -3;
  _DAT_004a4cac = param_3;
  _DAT_004a4cb0 = param_1;
  _DAT_004a4cbc = param_3;
  _DAT_004a4cb4 = param_3 + -(iVar6 / 2);
  _DAT_004a4cb8 = param_1 + iVar6 * 3;
  _DAT_004a4ca8 = pCVar4;
  pCStack_4 = _DAT_004a4cb4;
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
  (*(code *)param_1)(7);
  FUN_004706bd(param_1,aiStack_c,(int)param_1,(int)param_3);
  CDC::LineTo(param_1,(int)param_1,(int)pCVar4);
  CDC::LineTo(param_1,unaff_ESI,(int)param_3);
LAB_0042e3a7:
  if (DAT_004ac98c == 0) {
    (*(code *)param_2)(0);
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  _DAT_004a4ca8 = param_1 + -(iVar6 / 7);
  _DAT_004a4cc0 = param_1 + iVar6 / 7;
  iVar5 = (int)((ulonglong)((longlong)(iVar6 * 2) * -0x77777777) >> 0x20) + iVar6 * 2;
  iVar5 = (iVar5 >> 4) - (iVar5 >> 0x1f);
  if (pcVar1 == (code *)0x1) {
    iVar5 = (int)((ulonglong)((longlong)(iVar6 * 4) * -0x77777777) >> 0x20) + iVar6 * 4;
    iVar5 = (iVar5 >> 4) - (iVar5 >> 0x1f);
  }
  pCVar7 = param_1 + iVar5;
  bottom = pCVar4 + -(iVar6 / (int)(pcVar1 + 1));
  _DAT_004a4cac = pCVar4;
  _DAT_004a4cb0 = param_1 + -iVar5;
  _DAT_004a4cb4 = bottom;
  _DAT_004a4cb8 = pCVar7;
  _DAT_004a4cbc = bottom;
  _DAT_004a4cc4 = pCVar4;
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,4);
  (*(code *)param_2)(4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a3a14 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a14);
    }
    if (DAT_004a676c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
    }
  }
  else {
    (*(code *)(param_1 + -iVar5))(0);
    (*(code *)pCVar7)(6);
  }
  Rectangle(*(HDC *)(param_1 + 4),(int)(pCVar7 + 1),(int)(pCVar4 + (-(int)param_2 - iVar6 / 10)),
            (int)(pCStack_4 + 1),(int)bottom);
  return;
}

