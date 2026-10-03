
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004304d0(void)

{
  int in_ECX;
  float10 fVar1;
  undefined4 local_4;
  
  DAT_004ac96c = DAT_004ac96c + 1;
  if (DAT_00491170 / 3 < DAT_004ac96c) {
    DAT_004ac96c = 0;
  }
  local_4 = in_ECX;
  if (DAT_004a7bcc < 0x5a) {
    local_4 = DAT_004ac4ec + 2;
  }
  if (DAT_004a7bcc < 0x3c) {
    local_4 = DAT_004ac4ec * 2 + 2;
  }
  if (0x59 < DAT_004a7bcc) {
    local_4 = (0xc < DAT_004a633c) + 1;
  }
  fVar1 = (float10)fsin(((float10)DAT_004ac96c * (float10)_DAT_004852c8) / (float10)DAT_00491170);
  DAT_004a5b7c = (int)(longlong)((float10)local_4 * fVar1);
  return;
}

