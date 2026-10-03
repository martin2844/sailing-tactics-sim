
undefined4 * __thiscall FUN_004ac489(undefined4 *param_1,undefined4 param_2)

{
  FUN_004af62b();
  *param_1 = &PTR_FUN_004cd734;
  _memset(param_1 + 7,0,0x20);
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[7] = param_2;
  return param_1;
}

