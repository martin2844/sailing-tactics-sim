
undefined4 * __fastcall FUN_0047a1c8(undefined4 *param_1)

{
  FUN_0047c246(param_1);
  *param_1 = &PTR_FUN_004863fc;
  param_1[0x12] = 2;
  if (DAT_004ae694 == 0) {
    param_1[0x10] = 2;
    param_1[0x11] = 2;
    param_1[0x13] = 1;
  }
  else {
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x13] = 0;
  }
  param_1[0x1e] = 0;
  return param_1;
}

