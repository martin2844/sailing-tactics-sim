
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00419b40(CDC *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,
            uint param_7)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HDC hdc;
  HGDIOBJ h;
  
  if ((param_6 <= DAT_004a7354) && (1 < param_2)) {
    return;
  }
  if (1 < param_2 * DAT_004ac928) {
    return;
  }
  iVar5 = (-(uint)(param_5 != 1) & 0xfffffffc) + 0xd;
  if (DAT_004a7354 < param_6) {
    if (DAT_004a46a4 == (HGDIOBJ)0x0) goto LAB_00419bc2;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a46a4;
  }
  else {
    if (DAT_004a4ee4 == (HGDIOBJ)0x0) goto LAB_00419bc2;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a4ee4;
  }
  SelectObject(hdc,h);
LAB_00419bc2:
  dVar1 = _DAT_00484db0;
  if ((int)((param_7 ^ (int)param_7 >> 0x1f) - ((int)param_7 >> 0x1f)) < 0xf) {
    dVar1 = _DAT_00485070;
  }
  uVar2 = (uint)(longlong)((double)CONCAT44(param_4,param_3) * dVar1);
  if (DAT_004a5b7c < 1) {
    param_6 = 5;
  }
  else {
    param_6 = 2;
    uVar2 = (int)uVar2 / 2;
  }
  if (param_6 != 0) {
    dVar1 = (double)CONCAT44(param_4,param_3) * _DAT_00485078;
    do {
      FUN_004706bd(param_1,&param_3,DAT_004ac838,DAT_004a3f88 + -1);
      iVar3 = FUN_00415a20(uVar2);
      iVar3 = iVar3 + (((&DAT_004aa2a0)[iVar5] - (int)uVar2 / 2) - (int)(longlong)dVar1);
      iVar4 = FUN_00415a20(uVar2);
      CDC::LineTo(param_1,iVar4 + ((&DAT_004aa1a0)[iVar5] - (int)uVar2 / 2),iVar3);
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

