
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041e040(void)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  int local_4;
  
  local_4 = 0;
  do {
    fVar2 = (float10)fsin((float10)local_4 * (float10)_DAT_004cc568);
    fVar3 = (float10)fcos((float10)local_4 * (float10)_DAT_004cc568);
    (&DAT_004f85c8)[local_4] = (int)(longlong)(fVar2 * (float10)_DAT_004cc488);
    iVar1 = local_4 + 1;
    (&DAT_004f1740)[local_4] = (int)(longlong)(fVar3 * (float10)_DAT_004cc488);
    local_4 = iVar1;
  } while (iVar1 < 0x16a);
  return;
}

