
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042e970(CDC *param_1,int param_2,int param_3,int param_4)

{
  double dVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_8 [2];
  
  if ((DAT_00491148 + 1 <= param_3) || (DAT_004a5a4c != 0)) {
    iVar4 = (param_3 - DAT_00491148) * 2 + 0x1b;
    if (1000 < iVar4) {
      iVar4 = 1000;
    }
    pcVar2 = (code *)(param_2 - iVar4 / 6);
    iVar6 = param_3 - (iVar4 * 2) / 3;
    dVar1 = _DAT_004852a8;
    if (DAT_00491194 == 8) {
      dVar1 = _DAT_004852a0;
    }
    uVar3 = (int)(longlong)(_DAT_004abef0 / dVar1) + param_4;
    uVar5 = (int)uVar3 >> 0x1f;
    if (((uVar3 ^ uVar5) - uVar5 & 1 ^ uVar5) == uVar5) {
      if (DAT_004ac92c == 0) {
        if (DAT_004a3a14 != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a3a14);
        }
        if (DAT_004a676c != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
        }
      }
      else {
        (**(code **)(*(int *)param_1 + 0x2c))(0);
        (*pcVar2)(6);
      }
      FUN_00423640((int)param_1,1,param_2 + 1,iVar6 + -1);
    }
    if (DAT_004a71bc != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
    }
    FUN_004706bd(param_1,local_8,(int)pcVar2,param_3);
    CDC::LineTo(param_1,param_2 + -1,iVar6);
    CDC::LineTo(param_1,param_2 + 1,iVar6);
    CDC::LineTo(param_1,iVar4 / 6 + param_2,param_3);
    FUN_004706bd(param_1,local_8,param_2,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004706bd(param_1,local_8,param_2 + -1,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
    FUN_004706bd(param_1,local_8,param_2 + 1,param_3);
    CDC::LineTo(param_1,param_2,iVar6);
  }
  return;
}

