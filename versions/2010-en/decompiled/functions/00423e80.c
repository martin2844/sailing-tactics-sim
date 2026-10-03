
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00423e80(int *param_1,int param_2,double param_3,int param_4,int param_5,int param_6)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HDC hdc;
  HGDIOBJ h;
  
  if ((param_5 <= DAT_004fe33c) && (1 < param_2)) {
    return;
  }
  if (1 < param_2 * DAT_005363e0) {
    return;
  }
  iVar5 = (-(uint)(param_4 != 1) & 0xfffffffc) + 0xd;
  if (DAT_004fe33c < param_5) {
    if (DAT_004f4a64 == (HGDIOBJ)0x0) goto LAB_00423f02;
    hdc = (HDC)param_1[1];
    h = DAT_004f4a64;
  }
  else {
    if (DAT_004f7ec4 == (HGDIOBJ)0x0) goto LAB_00423f02;
    hdc = (HDC)param_1[1];
    h = DAT_004f7ec4;
  }
  SelectObject(hdc,h);
LAB_00423f02:
  dVar1 = _DAT_004cc5f0;
  if ((param_6 ^ param_6 >> 0x1f) - (param_6 >> 0x1f) < 0xf) {
    dVar1 = _DAT_004cc8c0;
  }
  iVar2 = (int)(longlong)(param_3 * dVar1);
  if (DAT_004f8ccc < 1) {
    param_5 = 5;
  }
  else {
    param_5 = 2;
    iVar2 = iVar2 / 2;
  }
  if (param_5 != 0) {
    dVar1 = param_3 * _DAT_004cc8c8;
    do {
      FUN_004b4d9d(param_1,(int *)&param_3,DAT_005362cc,DAT_004f4090 + -1);
      iVar3 = FUN_0041e000(iVar2);
      iVar3 = iVar3 + (((&DAT_005229e0)[iVar5] - iVar2 / 2) - (int)(longlong)dVar1);
      iVar4 = FUN_0041e000(iVar2);
      CDC::LineTo(param_1,iVar4 + ((&DAT_005228e0)[iVar5] - iVar2 / 2),iVar3);
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  return;
}

