
undefined4 * __thiscall FUN_004abe98(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  FUN_004ac443();
  *param_1 = &PTR_FUN_004cd2e4;
  _memset(param_1 + 0xf,0,0x20);
  param_1[0x14] = param_3;
  param_1[0xf] = param_2;
  param_1[0x10] = param_2 & 0xffff;
  return param_1;
}

