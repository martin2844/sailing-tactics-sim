
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00417eb0(CDC *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  HGDIOBJ h;
  
  iVar3 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00484e30);
  iVar2 = FUN_00415a20(10);
  iVar1 = param_4;
  if (iVar2 < 5) {
    iVar2 = ((&DAT_004aa1a0)[param_6] + param_4) / 2;
    iVar3 = ((&DAT_004aa2a0)[param_6] + iVar3 + param_5) / 2;
  }
  else {
    iVar2 = ((&DAT_004aa1a0)[param_6] + param_4 * 2) / 3;
    iVar3 = ((&DAT_004aa2a0)[param_6] + param_5 * 2 + iVar3) / 3;
  }
  if (DAT_004a7354 < param_7) {
    if (DAT_004a46a4 == (HGDIOBJ)0x0) goto LAB_00417f84;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a46a4;
  }
  else {
    if (DAT_004a4ee4 == (HGDIOBJ)0x0) goto LAB_00417f84;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a4ee4;
  }
  SelectObject(hdc,h);
LAB_00417f84:
  FUN_004706bd(param_1,&param_2,iVar1,param_5);
  CDC::LineTo(param_1,iVar2,iVar3);
  (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
  return;
}

