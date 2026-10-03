
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00415a60(void)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  int local_4;
  
  local_4 = 0;
  do {
    fVar2 = (float10)fsin((float10)local_4 * (float10)_DAT_00484d40);
    fVar3 = (float10)fcos((float10)local_4 * (float10)_DAT_00484d40);
    (&DAT_004a54a0)[local_4] = (int)(longlong)(fVar2 * (float10)_DAT_00485020);
    iVar1 = local_4 + 1;
    (&DAT_004a3450)[local_4] = (int)(longlong)(fVar3 * (float10)_DAT_00485020);
    local_4 = iVar1;
  } while (iVar1 < 0x16a);
  return;
}

