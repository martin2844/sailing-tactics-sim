
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00419ca0(CDC *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
  }
  uVar1 = (uint)(longlong)((double)CONCAT44(param_4,param_3) * _DAT_00484f10);
  iVar4 = 1;
  if (1 < (int)(*(int *)(&DAT_004a7060 + param_2 * 4) +
               (*(int *)(&DAT_004a7060 + param_2 * 4) >> 0x1f & 7U)) >> 3) {
    do {
      iVar2 = FUN_00415a20(uVar1);
      iVar3 = FUN_00415a20(uVar1);
      FUN_00419d50(param_1,iVar2 + (param_5 - (int)uVar1 / 2),iVar3 + param_6,0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(*(int *)(&DAT_004a7060 + param_2 * 4) +
                          (*(int *)(&DAT_004a7060 + param_2 * 4) >> 0x1f & 7U)) >> 3);
  }
  return;
}

