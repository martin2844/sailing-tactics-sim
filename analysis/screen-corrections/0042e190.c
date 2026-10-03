
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042e190(CDC *param_1,undefined *param_2,CDC *param_3)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  CDC *this;
  CDC *pCVar4;
  int iVar5;
  int iVar6;
  CDC *bottom;
  int iVar7;
  int in_stack_00000010;
  HDC hdc;
  HGDIOBJ h;
  int aiStack_8 [2];
  
  this = param_1;
  if ((int)param_3 < DAT_00491148 + 1) {
    return;
  }
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  dVar2 = _DAT_00484dd8 -
          ((double)(int)(param_3 + -0x1e) * _DAT_00485280) / (double)(DAT_004a72d0 / 2 + -0x1e);
  dVar3 = _DAT_00485290;
  if (DAT_004a5a4c == 1) {
    dVar3 = _DAT_00485288;
  }
  iVar7 = (int)(longlong)(dVar2 * dVar3);
  if (in_stack_00000010 == 1) {
    iVar7 = (int)(longlong)(dVar2 * _DAT_00485298);
  }
  if (DAT_004a5a4c == 0) {
    if (DAT_004a70e4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
    }
    iVar6 = (iVar7 * 3) / 10;
    Ellipse(*(HDC *)(param_1 + 4),(int)param_2 - iVar6,(int)param_3,(int)(param_2 + iVar6),
            (int)(param_3 + iVar7 / 10));
  }
  pCVar4 = param_3;
  if (DAT_004a5a4c != 1) goto LAB_0042e3a7;
  (*pcVar1)(param_1,8);
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
  _DAT_004a4cac = param_3;
  _DAT_004a4cb0 = param_2;
  _DAT_004a4cbc = param_3;
  pCVar4 = param_3 + -(iVar7 / 2);
  _DAT_004a4ca8 = param_2 + iVar7 * -3;
  _DAT_004a4cb4 = pCVar4;
  _DAT_004a4cb8 = (CDC *)(param_2 + iVar7 * 3);
  Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,3);
  (*pcVar1)(param_1,7);
  FUN_004706bd(param_1,aiStack_8,(int)(param_2 + iVar7 * -3),(int)param_3);
  CDC::LineTo(param_1,(int)param_2,(int)pCVar4);
  CDC::LineTo(param_1,(int)(param_2 + iVar7 * 3),(int)param_3);
LAB_0042e3a7:
  if (DAT_004ac98c == 0) {
    (*pcVar1)(param_1,0);
  }
  else if (DAT_004a70e4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a70e4);
  }
  _DAT_004a4ca8 = param_2 + -(iVar7 / 7);
  _DAT_004a4cc0 = param_2 + iVar7 / 7;
  iVar6 = (int)((ulonglong)((longlong)(iVar7 * 2) * -0x77777777) >> 0x20) + iVar7 * 2;
  iVar6 = (iVar6 >> 4) - (iVar6 >> 0x1f);
  if (in_stack_00000010 == 1) {
    iVar6 = (int)((ulonglong)((longlong)(iVar7 * 4) * -0x77777777) >> 0x20) + iVar7 * 4;
    iVar6 = (iVar6 >> 4) - (iVar6 >> 0x1f);
  }
  param_1 = (CDC *)(param_2 + iVar6);
  iVar5 = iVar7 / (in_stack_00000010 + 1);
  _DAT_004a4cb8 = param_1;
  bottom = pCVar4 + -iVar5;
  _DAT_004a4cac = pCVar4;
  _DAT_004a4cb0 = param_2 + -iVar6;
  _DAT_004a4cb4 = bottom;
  _DAT_004a4cbc = bottom;
  _DAT_004a4cc4 = pCVar4;
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,4);
  (*pcVar1)(this,4);
  if (DAT_004ac92c == 0) {
    if (DAT_004a3a14 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a3a14);
    }
    if (DAT_004a676c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a676c);
    }
  }
  else {
    (*pcVar1)(this,0);
    (*pcVar1)(this,6);
  }
  Rectangle(*(HDC *)(this + 4),(int)(param_2 + -iVar6 + 1),(int)(pCVar4 + (-iVar5 - iVar7 / 10)),
            (int)(param_1 + 1),(int)bottom);
  return;
}

