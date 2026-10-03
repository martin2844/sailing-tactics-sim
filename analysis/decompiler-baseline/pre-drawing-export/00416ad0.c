
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00416ad0(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  code *pcVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  dVar2 = (double)CONCAT44(param_3,param_2) * _DAT_00484fc0;
  if (DAT_00491188 == 8) {
    dVar2 = dVar2 * _DAT_00484fc8;
  }
  if (DAT_004ac900 == 1) {
    dVar2 = dVar2 * _DAT_00484fd0;
  }
  if (DAT_00491150 == 100) {
    local_8 = DAT_004aa1f4;
    iVar3 = (int)(longlong)(dVar2 * _DAT_00484fe0);
    iVar4 = DAT_004aa2f4;
  }
  else {
    local_8 = DAT_004aa1f0;
    iVar3 = (int)(longlong)(dVar2 * _DAT_00484ec8);
    iVar4 = DAT_004aa2f0;
  }
  _DAT_004a4cbc = DAT_004aa308 - (int)(longlong)(dVar2 * _DAT_00485028);
  _DAT_004a4cc4 = (int)(longlong)(dVar2 * _DAT_00485030);
  if (param_6 == 1) {
    _DAT_004a4cc4 = -_DAT_004a4cc4;
  }
  if ((((*(int *)(&DAT_004abb70 + param_4 * 4) == 1) && (DAT_00491188 == 2)) &&
      (param_4 <= DAT_00491140)) && (*(int *)(&DAT_004a7bc8 + param_4 * 4) < 0x84)) {
    _DAT_004a4cc4 = (_DAT_004a4cc4 * -3) / 2;
  }
  _DAT_004a4cc0 = (DAT_004aa208 + DAT_004aa1b4) / 2;
  _DAT_004a4cc4 = (_DAT_004a4cbc + DAT_004aa2b4) / 2 + _DAT_004a4cc4;
  if (DAT_004ac900 == 1) {
    _DAT_004a4cb4 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484db0);
  }
  else {
    _DAT_004a4cb4 = 0;
  }
  _DAT_004a4ca8 = DAT_004aa1b4;
  _DAT_004a4cac = DAT_004aa2b4 - _DAT_004a4cb4;
  _DAT_004a4cb4 = (iVar4 - iVar3) - _DAT_004a4cb4;
  pcVar1 = *(code **)(*param_1 + 0x2c);
  _DAT_004a4cb8 = DAT_004aa208;
  _DAT_004a4cb0 = local_8;
  (*pcVar1)(7);
  if (((DAT_00491188 < 7) || (DAT_004ac92c != 0)) || (8 < DAT_00491188)) {
    (*pcVar1)(0);
  }
  else if (DAT_004ab17c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004ab17c);
  }
  if ((DAT_004ac98c == 1) && (DAT_004a70e4 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004a70e4);
  }
  if ((param_3 == 1) && (DAT_004a40c4 == 1)) {
    (*pcVar1)(5);
  }
  if (((param_3 == 2) && (DAT_004a40c8 == 1)) && (DAT_00491140 == 2)) {
    (*pcVar1)(5);
  }
  Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,4);
  return;
}

