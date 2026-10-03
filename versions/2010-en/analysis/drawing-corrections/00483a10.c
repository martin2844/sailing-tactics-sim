
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00483a10(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  float10 fVar2;
  
  if (((-1 < param_2) && (param_2 <= DAT_004fe624)) && (param_3 <= DAT_00535564)) {
    param_3 = param_3 + -1;
    fVar2 = (float10)FUN_00406220(param_3,param_4);
    iVar1 = (int)(longlong)(fVar2 * (float10)_DAT_004cc5d0);
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    if (DAT_004f7f74 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
    Rectangle((HDC)param_1[1],param_2 - iVar1,param_3 - (iVar1 * 2) / 3,iVar1 + param_2,param_3);
  }
  return;
}

